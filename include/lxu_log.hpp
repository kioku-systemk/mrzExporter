/*
 * Plug-in SDK Header: C++ Services
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
 * Helper class for posting warnings and catching errors and reporting
 * them to the I/O status log, with identification of the message poster.
 */
#ifndef LX_LOGUTIL_HPP
#define LX_LOGUTIL_HPP

#include <stdlib.h>
#include <lxresult.h>


class CLxLogMessage
{
    public:
                 CLxLogMessage (const char *log = "io-status");
        virtual ~CLxLogMessage ();

        virtual const char *	 GetFormat  () = 0;
        virtual const char *	 GetVersion () = 0;
        virtual const char *	 GetCopyright ();

        void			 Message (LxResult, const char *who, const char *what, const char *why);
        void			 Error   (const char *msg);
        void			 Info    (const char *msg);
        bool			 Setup   ();

        void			 SubMessage (LxResult, const char *who, const char *what, const char *why);
        void			 SubInfo    (const char *msg);

        class pv_LogMessage	*pv;
};


class CLxLuxologyLogMessage : public CLxLogMessage
{
    public:
                 CLxLuxologyLogMessage (const char *log = "io-status")
                         :
                 CLxLogMessage (log) { }

        const char *	 GetVersion ()
        {
                return "601";	// __601__
        }

        virtual const char *	 GetCopyright ()
        {
                return "Copyright 2011, Luxology LLC";
        }
};

#endif	/* LX_LOGUTIL_HPP */

