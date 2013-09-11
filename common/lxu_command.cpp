/*
 * Plug-in SDK Header: Common Utility
 *
 * Copyright (c) 2008-2012 Luxology LLC
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.   Except as contained
 * in this notice, the name(s) of the above copyright holders shall not be
 * used in advertising or otherwise to promote the sale, use or other dealings
 * in this Software without prior written authorization.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * Command Wrapper
 */

/*
 * Disable deprecated function warning.
 */
#pragma warning(disable: 4996)

#include <lxu_command.hpp>
#include <lx_log.hpp>
#include <lx_wrap.hpp>
#include <vector>
#include <map>
#include <set>

using namespace std;


/*
 * ----------------------------------------------------------------
 * The basic command manages the argument flags as a vector of ints, and
 * the current result code.
 */
class pv_BasicCommand {
    public:
        CLxUser_Message		 msg;
        vector<unsigned>	 flags;
        vector<CLxUser_Notifier> notifiers;
        vector<ILxUnknownID>	 noteClients;
        string			 bname, icon;
        LxResult		 code;
        bool			 initNotifiers, hasVarArg;

//	CLxUser_LogService	 slog;
//	char			 buf[1024];
};


CLxBasicCommand::CLxBasicCommand ()
{
        pv = new pv_BasicCommand;

        CLxUser_MessageService ms;
        if (!ms.NewMessage (pv->msg))
                throw (LXe_FAILED);

        pv->initNotifiers = true;

//	sprintf (pv->buf, "cmd%p - create\n", this);
//	pv->slog.DebugLogOutput (LXi_DBLOG_NORMAL, pv->buf);
}

CLxBasicCommand::~CLxBasicCommand ()
{
//	sprintf (pv->buf, "cmd%p - destroy\n", this);
//	pv->slog.DebugLogOutput (LXi_DBLOG_NORMAL, pv->buf);

        for (unsigned i = 0; i < pv->notifiers.size (); i++)
                for (unsigned j = 0; j < pv->noteClients.size (); j++)
                        pv->notifiers[i].RemoveClient (pv->noteClients[j]);

        delete pv;
}


/*
 * The flags are kept in a dynamic array. We append zeros as the arguments are
 * added to the attributes so we match the same size. The subclass sets the
 * flags values to non-zero if necessary during init.
 */
        void
CLxBasicCommand::dyna_Add (
        const char		*name,
        const char		*type)
{
        pv->flags.push_back (0);
        CLxDynamicAttributes::dyna_Add (name, type);
}

        void
CLxBasicCommand::dyna_Add	(
        const std::string &name,
        const std::string &type)
{
        dyna_Add (name.c_str (), type.c_str ());
}

        void
CLxBasicCommand::basic_SetFlags (
        unsigned int		 index,
        unsigned int		 flags)
{
        pv->flags[index] = flags;

        if (flags & LXfCMDARG_VARIABLE)
                pv->hasVarArg = true;
}


/*
 * --------------------------------------------------------------------
 * Implementations of ILxCommand argument methods.
 */

/*
 * Enable calls the nice internal form, and hides the weirdness of result codes.
 */
        LxResult
CLxBasicCommand::cmd_Enable (
        ILxUnknownID		 msg)
{
        CLxUser_Message		 userMsg(msg);
        LxResult		 result;

        result = basic_Enable (userMsg) ? LXe_OK : LXe_CMD_DISABLED;
        userMsg.SetCode (result);
        return result;
}


/*
 * Flags come straight from the client.
 */
        LxResult
CLxBasicCommand::cmd_Flags (
        unsigned int		*flags)
{
        flags[0] = basic_CmdFlags ();
        return LXe_OK;
}


/*
 * Arg clearing resets the value in the attributes. If this is a req-for-var
 * argument then we clear all the variable args as well.
 */
        LxResult
CLxBasicCommand::cmd_ArgClear (
        unsigned int		 index)
{
        if (index >= pv->flags.size ())
                return LXe_OUTOFBOUNDS;

        dyna_SetType (index, 0);

        if (pv->hasVarArg && (pv->flags[index] & LXfCMDARG_REQFORVARIABLE)) {
                unsigned int		 i;

                for (i = 0; i < pv->flags.size (); i++) {
                        pv->flags[i] &= ~LXfCMDARG_REQFORVAR_SET;
                        if (pv->flags[i] & LXfCMDARG_VARIABLE)
                                cmd_ArgClear (i);
                }
        }

        return LXe_OK;
}

        LxResult
CLxBasicCommand::cmd_ArgResetAll ()
{
        unsigned int		 i;

        for (i = 0; i < pv->flags.size (); i++)
                cmd_ArgClear (i);

        return LXe_OK;
}


/*
 * Arg flags are stored except for the "set" bit which we get from attributes.
 */
        LxResult
CLxBasicCommand::cmd_ArgFlags (
        unsigned int		 index,
        unsigned int		*flags)
{
        flags[0] = pv->flags[index] | (dyna_IsSet (index) ? LXfCMDARG_VALUE_SET : 0);
        return LXe_OK;
}

        LxResult
CLxBasicCommand::cmd_ArgSetDatatypes ()
{
        if (!pv->hasVarArg)
                return LXe_OK;

        unsigned int		 i;

        for (i = 0; i < pv->flags.size (); i++)
                if ((pv->flags[i] & LXfCMDARG_REQFORVARIABLE) && !dyna_IsSet (i))
                        return LXe_CMD_MISSING_ARGS;

        for (i = 0; i < pv->flags.size (); i++) {
                pv->flags[i] |= LXfCMDARG_REQFORVAR_SET;
                if (pv->flags[i] & LXfCMDARG_VARIABLE)
                        dyna_SetType (i, basic_ArgType (i));
        }

        return LXe_OK;
}


/*
 * Return the button name and icon, if the client has an override.
 */
        LxResult
CLxBasicCommand::cmd_ButtonName (
        const char	       **name)
{
        if (basic_ButtonName (pv->bname)) {
                name[0] = pv->bname.c_str ();
                return LXe_OK;
        } else
                return LXe_NOTIMPL;
}

        LxResult
CLxBasicCommand::cmd_Icon (
        const char	       **name)
{
        if (basic_IconName (pv->icon)) {
                name[0] = pv->icon.c_str ();
                return LXe_OK;
        } else
                return LXe_NOTIMPL;
}


/*
 * We have a message object but no message interface. It's returned directly
 * through these methods.
 */
        CLxUser_Message &
CLxBasicCommand::basic_Message ()
{
        return pv->msg;
}

        LxResult
CLxBasicCommand::cmd_Message (
        void		       **ppvObj)
{
        return pv->msg.get (ppvObj);
}


/*
 * Notifiers are kept in a list which is initialized only when needed. Once we
 * have the list, adding and removing clients can be done by iterating. It's
 * not totally clear how to deal with errors.
 */
        LxResult
CLxBasicCommand::cmd_NotifyAddClient (
        int			 argument,
        ILxUnknownID		 object)
{
        if (pv->initNotifiers) {
                string			 name, args;
                unsigned		 i;

                /*
                 * Notifiers that are global to the command. We get these either by
                 * traversing them by index or by getting a list of name/arg pairs.
                 */
                i = 0;
                while (basic_Notifier (i++, name, args))
                        basic_AddNotify (name, args);

                basic_Notifiers ();

                // NOTE: don't think this is right. It only gets the notifiers for the
                // argument specified the first time this is called. During init we
                // should scan all the args and get their lists of notifiers.
                //
                if( argument != -1 ) {
                        /* Argument-specific notifiers */
                        LXtObjectID	 uiValueHintsObj;
                        if( LXx_OK( atrui_UIValueHints( argument, &uiValueHintsObj ) ) ) {
                                CLxLoc_UIValueHints	 uiValueHints;
                                int			 n;

                                if( uiValueHints.take( uiValueHintsObj ) ) {
                                        if( LXx_OK( uiValueHints.NotifierCount( &n ) ) ) {
                                                for( int index=0; index < n; i++ ) {
                                                        const char	*np = NULL, *ap = NULL;
                                                        if( LXx_OK( uiValueHints.NotifierByIndex( index, &np, &ap ) ) && (np != NULL) ) {
                                                                name = np;
                                                                args = ap;
                                                                basic_AddNotify (name, args);
                                                        }
                                                }
                                        }
                                }
                        }
                }

                pv->initNotifiers = false;
        }

        for (unsigned i = 0; i < pv->notifiers.size (); i++)
                pv->notifiers[i].AddClient (object);

        pv->noteClients.push_back (object);
        return LXe_OK;
}

/*
 * This should only be called from the client's basic_Notifiers() method. We could
 * add protection for that, but it shouldn't be necessary.
 */
        void
CLxBasicCommand::basic_AddNotify (
        const std::string	&name,
        const std::string	&args)
{
        CLxUser_NotifySysService srv;
        CLxUser_Notifier	 note;
        LXtObjectID		 obj;
        LxResult		 rc;

        rc = srv.Spawn (name.c_str(), args.c_str(), &obj);
        if (LXx_FAIL (rc))
                throw (rc);

        note.take (obj);
        pv->notifiers.push_back (note);
}


        LxResult
CLxBasicCommand::cmd_NotifyRemoveClient (
        ILxUnknownID		 object)
{
        vector<ILxUnknownID>::iterator it;

        it = pv->noteClients.begin ();
        while (1) {
                if (it >= pv->noteClients.end())
                        return LXe_NOTFOUND;

                if (*it == object) {
                        pv->noteClients.erase (it);
                        break;
                }

                it++;
        }

        for (unsigned i = 0; i < pv->notifiers.size (); i++)
                pv->notifiers[i].RemoveClient (object);

        return LXe_OK;
}


/*
 * ----------------------------------------------------------------
 * The command notifier manages the table of clients and arguments. The name is
 * set in the constructor.
 */
class pv_CommandNotifier {
    public:
        map<ILxUnknownID,CLxUser_CommandEvent>
                                 l_client;
        string			 s_name, s_args;
};

/*
 * The global notifier table maps the notifier name to the set of all notifiers.
 * The notifier system should be responsible for merging notifiers with the same
 * arg strings, so these should all be unique.
 */
typedef set<CLxCommandNotifier *> CommandNotifierSet;

static map<string, CommandNotifierSet> cn_MasterTable;


CLxCommandNotifier::CLxCommandNotifier (
        const char		*name)
{
        pv = new pv_CommandNotifier;
        pv->s_name = name;
}

CLxCommandNotifier::~CLxCommandNotifier ()
{
        map<ILxUnknownID,CLxUser_CommandEvent>::iterator it;

        while (!pv->l_client.empty ()) {
                it = pv->l_client.begin ();
                noti_RemoveClient (it->first);
        }

        delete pv;
}

        LxResult
CLxCommandNotifier::noti_Name (
        const char	       **name)
{
        name[0] = pv->s_name.c_str ();
        return LXe_OK;
}

        LxResult
CLxCommandNotifier::noti_SetArgs (
        const char		*args)
{
        try {
                pv->s_args = args;
                cn_Parse (pv->s_args);

        } catch (LxResult rc) {
                return rc;
        }
        return LXe_OK;
}

        LxResult
CLxCommandNotifier::noti_Args (
        const char	       **args)
{
        args[0] = pv->s_args.c_str ();
        return LXe_OK;
}

        LxResult
CLxCommandNotifier::noti_AddClient (
        ILxUnknownID		 object)
{
        CLxUser_CommandEvent	 ce;

        ce.set (object);
        if (!ce.test ())
                return LXe_NOTFOUND;

        if (pv->l_client.empty ())
                cn_MasterTable[pv->s_name].insert (this);

        pv->l_client[object] = ce;
        return LXe_OK;
}

        LxResult
CLxCommandNotifier::noti_RemoveClient (
        ILxUnknownID		 object)
{
        pv->l_client.erase (object);
        if (!pv->l_client.empty ())
                return LXe_OK;

        cn_MasterTable[pv->s_name].erase (this);
        return LXe_OK;
}

        void
CLxCommandNotifier::Notify (
        const char		*name,
        int			 code)
{
        CommandNotifierSet::iterator	 sit;
        string				 sn  = name;
        CommandNotifierSet		&set = cn_MasterTable[sn];

        for (sit = set.begin() ; sit != set.end(); sit++) {
                CLxCommandNotifier	*note = *sit;
                unsigned int		 flags;

                flags = note->cn_Flags (code);
                if (!flags)
                        continue;

                map<ILxUnknownID,CLxUser_CommandEvent>::iterator
                                         mit;

                for (mit = note->pv->l_client.begin() ; mit != note->pv->l_client.end(); mit++)
                        mit->second.Event (flags);
        }
}


