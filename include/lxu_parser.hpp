/*
 * Plug-in SDK Header: C++ Wrapper Classes
 *
 * Copyright (c) 2008-2013 Luxology LLC
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
 * General I/O Wrappers
 */
#ifndef LX_PARSER_HPP
#define LX_PARSER_HPP

#include <lxw_io.hpp>

#include <string.h>
#include <string>


/*
 * ----------------------------------------------------------------
 * Abstract file parser class. Used as a framework for loader wrappers.
 * The details of the format should be specified by the client.
 */
class CLxFileParser
{
    public:
        virtual			~CLxFileParser () {}

        virtual bool		 fp_Open       (const char *)	= 0;
        virtual void		 fp_SetMonitor (LXtObjectID)	= 0;
        virtual bool		 fp_HasError   ()		= 0;
        virtual LxResult	 fp_ErrorCode  ()		= 0;
        virtual void		 fp_Cleanup    ()		= 0;

        const char		*file_name;
};

/*
 * ----------------------------------------------------------------
 * Parser for general line-based text formats. Can be easily subclassed
 * to alter the maximum line size, and how to handle whitespace, blank
 * lines and comments.
 */
class CLxLineParser : public CLxFileParser
{
    public:
                                 CLxLineParser ();
        virtual			~CLxLineParser ();

        virtual bool		 fp_Open       (const char *)	LXx_OVERRIDE;
        virtual void		 fp_SetMonitor (LXtObjectID)	LXx_OVERRIDE;
        virtual bool		 fp_HasError   ()		LXx_OVERRIDE;
        virtual LxResult	 fp_ErrorCode  ()		LXx_OVERRIDE;
        virtual void		 fp_Cleanup    ()		LXx_OVERRIDE;

        virtual bool		 lp_ReadLine   ();
        virtual bool		 lp_IsComment  ()	{ return false; }
        virtual bool		 lp_Continue   ()	{ return false; }
        virtual bool		 lp_StripWhite ()	{ return false; }
        virtual bool		 lp_SkipBlank  ()	{ return false; }

        void			 PullWhite     ();
        void			 PullNonWhite  ();
        void			 PullNonWhite  (std::string &dest);
        bool			 PullNum       (float *);
        bool			 PullNum       (double *);
        bool			 PullNum       (unsigned *);
        bool			 PullNum       (int *);
        bool			 PullExpected  (char);

        static bool		 IsBlank (char);
        static bool		 IsDigit (char);
        static char		 Upper   (char);
        static char		 Lower   (char);

        char			*line_buf;
        char			*cur_pos;

    private:
        void			 set_line (const char *);
        class pv_LineParser	*pv;
};

/*
 * ----------------------------------------------------------------
 * Parser for general binary formats.
 */
class CLxBinaryParser : public CLxFileParser
{
    public:
                                 CLxBinaryParser ();
        virtual			~CLxBinaryParser ();

        virtual bool		 fp_Open       (const char *)	LXx_OVERRIDE;
        virtual void		 fp_SetMonitor (LXtObjectID)	LXx_OVERRIDE;
        virtual bool		 fp_HasError   ()		LXx_OVERRIDE;
        virtual LxResult	 fp_ErrorCode  ()		LXx_OVERRIDE;
        virtual void		 fp_Cleanup    ()		LXx_OVERRIDE;

        bool			 PullBlock (void *buf, size_t size);

        size_t			 StringLen ();
        bool			 PullString (char *text, size_t maxSize = 0);
        bool			 PullNum (float *value);
        bool			 PullNum (double *value);
        bool			 PullNum (unsigned *value);
        bool			 PullNum (int *value);

        unsigned		 cur_pos;

    private:
        class pv_BinaryParser	*pv;
};

#endif /* LX_PARSER_HPP */

