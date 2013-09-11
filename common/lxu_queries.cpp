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
 * Command Query Wrapper
 */

/*
 * Disable deprecated function warning.
 */
#pragma warning(disable: 4996)

#include <lxu_queries.hpp>
#include <lxu_getstring.hpp>
#include <lx_command.hpp>


/*
 * ----------------------------------------------------------------
 * CLxCommandQuery : Implementation
 *
 * We'll create a command with the desired name and hold onto the array results
 * so the user can see them.
 */
class pv_CommandQuery {
    public:
        CLxUser_CommandService	 svc;
        CLxUser_Command		 cmd;
        CLxUser_Attributes	 arg;
        CLxUser_ValueArray	 va;
        unsigned int		 argIndex, valIndex;

        LxResult		 sgs_GetString (char *buf, unsigned len);
};


/*
 * Create the command on construction, setting the args as well if possible.
 */
CLxCommandQuery::CLxCommandQuery (
        const char		*name)
{
        pv = new pv_CommandQuery;

        if (pv->svc.NewCommand (pv->cmd, name))
                pv->arg.set (pv->cmd);
}

/*
 * Destructor just deletes the private object.
 */
CLxCommandQuery::~CLxCommandQuery ()
{
        delete pv;
}


/*
 * The client may need to set arguments, which can be done this way.
 */
        CLxUser_Attributes &
CLxCommandQuery::Arguments ()
{
        return pv->arg;
}


/*
 * Perform the actual query. On success this object will contain a value array
 * positioned at index 0.
 */
        bool
CLxCommandQuery::Query (
        unsigned int		 argIndex)
{
        if (!pv->cmd.test ())
                return false;

        pv->valIndex = 0;
        pv->argIndex = argIndex;
        pv->va.clear ();

        if (!pv->svc.QueryIndex (pv->cmd, argIndex, pv->va))
                return false;

        return pv->va.test ();
}


/*
 * Get the value's type name.
 */
        const char *
CLxCommandQuery::ValueType ()
{
        const char		*tname;

        if (!pv->arg.test ())
                return 0;

        if (LXx_FAIL (pv->arg.TypeName (pv->argIndex, &tname)))
                return 0;

        return tname;
}


/*
 * Iteration is done by getting the count and then setting the index
 * the desired element.
 */
        unsigned int
CLxCommandQuery::Count ()
{
        if (!pv->va.test ())
                return 0;

        return pv->va.Count ();
}

        void
CLxCommandQuery::SetIndex (
        unsigned int		 valIndex)
{
        pv->valIndex = valIndex;
}


/*
 * Get...() methods return the value at the current index.
 */
        int
CLxCommandQuery::GetInt ()
{
        int			 val = 0;

        if (pv->va.test ())
                pv->va.GetInt (pv->valIndex, &val);

        return val;
}

        double
CLxCommandQuery::GetFloat ()
{
        double			 val = 0.0;

        if (pv->va.test ())
                pv->va.GetFloat (pv->valIndex, &val);

        return val;
}

        const char *
CLxCommandQuery::GetString (
        char			*buf,
        unsigned		 len)
{
        if (pv->va.test ())
                pv->va.GetString (pv->valIndex, buf, len);

        return buf;
}


/*
 * Nice version of GetString() that never truncates.
 */
        LxResult
pv_CommandQuery::sgs_GetString (
        char			*buf,
        unsigned		 len)
{
        return va.GetString (valIndex, buf, len);
}

        void
CLxCommandQuery::GetString (
        std::string		&string)
{
        if (!pv->va.test ())
                return;

        CLxSafeGetString<pv_CommandQuery>	sgs;

        sgs.GetStringEx (*pv, string);
}

        LxResult
CLxCommandQuery::IntHint (
        const LXtTextValueHint **hints)
{
        if (pv->arg.test ()) {
                *hints = pv->arg.Hints (1);
                return LXe_OK;
        }

        return LXe_FAILED;
}



CLxReadUserValue::CLxReadUserValue ()
        : CLxCommandQuery ("user.value")
{
}

        bool
CLxReadUserValue::Query (
        const char		*name)
{
        if (!Arguments() . test ())
                return false;

        if (!Arguments() . Set (0, name))
                return false;

        if (!CLxCommandQuery::Query (1))
                return false;

        return (Count () > 0);
}


