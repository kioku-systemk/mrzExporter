/*
 * Plug-in SDK Header: C++ Wrapper Classes
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
#ifndef LXU_COMMAND_HPP
#define LXU_COMMAND_HPP

#include <lxu_attributes.hpp>
#include <lx_command.hpp>
#include <lx_notify.hpp>
#include <string>


/*
 * ----------------------------------------------------------------
 * The CLxBasicCommand class provides a framework for implementing simple
 * commands. Derived classes provide the command flags, arguments and argument
 * flags, and the basic command manages storing the arguments and the command
 * result message.
 */
class CLxBasicCommand :
                public CLxImpl_Command,
                public CLxDynamicAttributes
{
    public:
                         CLxBasicCommand ();
        virtual		~CLxBasicCommand ();

        virtual	int	basic_CmdFlags	() = 0;
        virtual bool	basic_Notifier	(int index, std::string &name, std::string &args)
                                { return false; }
        virtual void	basic_Notifiers	()
                                {}
        virtual bool	basic_Enable (CLxUser_Message &msg)
                                { return true; }
        virtual const char *
                        basic_ArgType (unsigned int index)
                                { return 0; }
        virtual bool	basic_ButtonName (std::string &)
                                { return false; }
        virtual bool	basic_IconName (std::string &)
                                { return false; }

        void		basic_SetFlags	(unsigned int index, unsigned int flags);
        CLxUser_Message&basic_Message	();
        void		basic_AddNotify	(const std::string &name, const std::string &args);

        void		dyna_Add	(const char *name, const char *type)		;//LXx_OVERRIDE -- should be, but only works on virtual methods
        void		dyna_Add	(const std::string &name, const std::string &type);

        LxResult	cmd_Enable	(ILxUnknownID msg)				LXx_OVERRIDE;
        LxResult	cmd_Flags	(unsigned int *flags)				LXx_OVERRIDE;
        LxResult	cmd_ArgFlags	(unsigned int index, unsigned int *flags)	LXx_OVERRIDE;
        LxResult	cmd_ArgClear	(unsigned int index)				LXx_OVERRIDE;
        LxResult	cmd_ArgResetAll	()						LXx_OVERRIDE;
        LxResult	cmd_ArgSetDatatypes ()						LXx_OVERRIDE;
        LxResult	cmd_Message	(void **ppvObj)					LXx_OVERRIDE;
        LxResult	cmd_ButtonName	(const char **name)				LXx_OVERRIDE;
        LxResult	cmd_Icon	(const char **name)				LXx_OVERRIDE;

        LxResult	cmd_NotifyAddClient	(int argument, ILxUnknownID object)	LXx_OVERRIDE;
        LxResult	cmd_NotifyRemoveClient	(ILxUnknownID object)			LXx_OVERRIDE;

    private:
        class pv_BasicCommand	*pv;
};

/*
 * Construtors on template classes can kind of work like functions with
 * parameterized types. Declaring and installing a command server derived from
 * CLxBasicCommand can be done by instantiating this object with the client's
 * subclass and the server name.
 *
 *	initialize ()
 *	{
 *		CLxExport_BasicCommand<CMyCommand> ("myCommandName");
 *	}
 */
template <class T>
class CLxExport_BasicCommand
{
    public:
        CLxExport_BasicCommand (
                const char		*name)
        {
                CLxGenericPolymorph	*srv;

                srv = new CLxPolymorph<T>;
                srv->AddInterface (new CLxIfc_Command     <T>);
                srv->AddInterface (new CLxIfc_Attributes  <T>);
                srv->AddInterface (new CLxIfc_AttributesUI<T>);
                lx::AddServer (name, srv);
        }
};


/*
 * ----------------------------------------------------------------
 * The CLxCommandNotifier class is used to create new notifier servers.
 */
class CLxCommandNotifier :
                public CLxImpl_Notifier
{
    public:
                                 CLxCommandNotifier (const char *);
        virtual			~CLxCommandNotifier ();

        virtual void		cn_Parse (std::string &args) {}
        virtual unsigned int	cn_Flags (int code) { return LXfCMDNOTIFY_VALUE; }

        LxResult		noti_Name         (const char **name)   LXx_OVERRIDE;
        LxResult		noti_SetArgs      (const char  *args)   LXx_OVERRIDE;
        LxResult		noti_Args         (const char **args)   LXx_OVERRIDE;
        LxResult		noti_AddClient    (ILxUnknownID object) LXx_OVERRIDE;
        LxResult		noti_RemoveClient (ILxUnknownID object) LXx_OVERRIDE;

        static void		Notify (const char *, int code);

    private:
        class pv_CommandNotifier	*pv;
};


#endif /* LX_COMMAND_HPP */

