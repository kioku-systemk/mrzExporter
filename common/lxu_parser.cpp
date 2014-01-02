/*
 * Plug-in SDK Header: Common Utility
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
 * General I/O
 */
#include <lxu_parser.hpp>
#include <lx_io.hpp>
#include <lx_wrap.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string>

/*
 * Suppress warnings for deprecated functions.
 */
#ifdef _MSC_VER
        #define _CRT_SECURE_NO_WARNINGS 1
        #define _CRT_SECURE_NO_DEPRECATE 1
        #pragma warning(disable: 4996)
#endif

using namespace std;


/*
 * ----------------------------------------------------------------
 * CLxLineParser : Implementation
 *
 * Private data is the filename string and the file stream. Since streams
 * have problems being closed and re-opened we allocate a new one for each
 * file.
 */
class pv_LineParser {
    public:
        pv_LineParser ();
        bool			 Open     (const char *name);
        void			 Close    ();
        void			 InitMon  ();
        void			 ReadLine (string &);

        string			 filename;	// filename for reading
        FILE			*file;		// file stream, when open
        CLxUser_Monitor		 mon;		// read progress monitor
        bool			 moninit;	// true if monitor needs init
        LxResult		 error;		// last error, if any
        unsigned int		 length;	// total file length
        unsigned int		 pos, monPos;	// current position, monitor position
        size_t			 bufLen;	// size of line_buf
};


pv_LineParser::pv_LineParser ()
{
        filename = "";
        file     = 0;
        moninit  = false;
        error    = LXe_FALSE;
        bufLen   = 0;
}

        bool
pv_LineParser::Open (
        const char		*name)
{
        FILE			*tempFile;

        filename = name;

        // Need to get the filesize in binary mode
        tempFile = fopen (filename.c_str (), "rb");
        if (tempFile == NULL) {
                error = LXe_NOTFOUND;
                return false;
        }

        fseek (tempFile, 0, SEEK_END);
        length = ftell (tempFile);
        fclose (tempFile);

        file = fopen (filename.c_str (), "r");
        if (!file) {
                error = LXe_NOTFOUND;
                return false;
        }

        if (ferror (file)) {
                error = LXe_IO_ERROR;
                return false;
        }

        pos     = 0;
        moninit = true;
        error   = LXe_OK;
        return true;
}

        void
pv_LineParser::InitMon ()
{
        if (mon.test () && moninit) {
                mon.Initialize (length);
                monPos	= pos;
                moninit = false;
        }
}

/*
 * Read a line from the input stream. Characters are appended to the dest
 * string, and we don't return until we get some kind of end-of-line
 * indicator.
 */
        void
pv_LineParser::ReadLine (
        string			&dest)
{
        int			 c;

        while (1) {
                c = getc (file);
                pos++;

                if (!c || c == EOF || c == '\n' || c == 10 || c == 13)
                        return;

                dest += c;
        }
}

        void
pv_LineParser::Close ()
{
        error = LXe_FALSE;
        filename = "";
        mon.clear ();
        moninit  = false;

        if (file) {
                fclose (file);
                file = 0;
        }
}


CLxLineParser::CLxLineParser ()
{
        pv = new pv_LineParser;

        cur_pos  = 0;
        line_buf = 0;
}

CLxLineParser::~CLxLineParser ()
{
        fp_Cleanup ();

        if (pv->bufLen)
        {
                delete[] line_buf;
                line_buf = 0;
        }

        delete pv;
}

        bool
CLxLineParser::fp_Open (
        const char		*filename)
{
        fp_Cleanup ();

        if (!pv->Open (filename))
                return false;

        file_name = pv->filename.c_str ();

        pv->InitMon ();
        return true;
}

        void
CLxLineParser::fp_SetMonitor (
        LXtObjectID		 monObj)
{
        pv->mon.set (monObj);
        pv->InitMon ();
}

        bool
CLxLineParser::fp_HasError ()
{
        return LXx_FAIL (pv->error);
}

        LxResult
CLxLineParser::fp_ErrorCode ()
{
        return pv->error;
}

        void
CLxLineParser::fp_Cleanup ()
{
        pv->Close ();
        cur_pos = 0;

}

        void
CLxLineParser::set_line (
        const char		*buf)
{
        size_t			 len = strlen (buf) + 24;

        if (pv->bufLen < len)
        {
                if (pv->bufLen)
                        delete [] line_buf;

                line_buf = new char [len];
                pv->bufLen = len;
        }

        strcpy (line_buf, buf);
}

        bool
CLxLineParser::lp_ReadLine ()
{
        LxResult		 rc;
        unsigned int		 len;
        bool			 blank;

        if (fp_HasError () || !pv->file || feof (pv->file))
                return false;

        if (ferror (pv->file)) {
                pv->error = LXe_IO_ERROR;
                return false;
        }

        if (pv->mon.test () && pv->pos > pv->monPos) {
                rc = pv->mon.Increment (pv->pos - pv->monPos);
                pv->monPos = pv->pos;
                if (LXx_FAIL (rc)) {
                        pv->error = rc;
                        return false;
                }
        }

        do {
                string		 buf;
                char		*s;

                // store if we've hit a continuation on prev line
                bool		prevContinue = false;

                while (1) {
                        pv->ReadLine (buf);
                        if (ferror (pv->file)) {
                                pv->error = LXe_IO_ERROR;
                                return false;
                        }

                        if (feof (pv->file))
                                return false;

                        set_line (buf.c_str ());

                        // check for if to Continue
                        bool shouldContinue = lp_Continue();

                        // if we don't already have to continue and haven't just got a continue, break
                        if( !prevContinue && !shouldContinue )
                                break;

                        // update prevContinue
                        prevContinue = shouldContinue;

                        buf = line_buf;
                }

                if (lp_StripWhite ()) {
                        for (s = line_buf; *s && IsBlank (*s); s++)
                                ;

                        len = static_cast<unsigned int>(strlen (s));
                        if (s != line_buf)
                                memmove (line_buf, s, len + 1);

                        while (len && IsBlank (line_buf[len - 1]))
                                line_buf[--len] = 0; 
                }

                blank = lp_SkipBlank ();
                for (s = line_buf; *s && blank; s++)
                        if (!IsBlank (*s))
                                blank = false;

        } while (blank || lp_IsComment ());

        cur_pos = line_buf;
        return true;
}


/*
 * PullWhite and PullNonWhite advance the cur_pos pointer past characters of
 * their respective types.  PullNonWhite will read into an optional string.
 */
        void
CLxLineParser::PullWhite ()
{
        while (IsBlank (cur_pos[0]))
                cur_pos++;
}

        void
CLxLineParser::PullNonWhite ()
{
        while (cur_pos[0] && !IsBlank (cur_pos[0]))
                cur_pos++;
}

        void
CLxLineParser::PullNonWhite (
        string			&dest)
{
        dest = "";
        while (cur_pos[0] && !IsBlank (cur_pos[0]))
                dest += *cur_pos++;
}

/*
 * The various Pull* methods will read a values of various types from the arg
 * string, advancing past them.  There's no sanity checking on float types, 
 * so garbage will come in as a valid zero.
 */
        bool
CLxLineParser::PullNum (
        float			*value)
{
        string			 buf;

        PullWhite ();
        PullNonWhite (buf);
        if (!buf.length ())
                return false;

        value[0] = static_cast<float>(atof (buf.c_str ()));
        return true;
}

        bool
CLxLineParser::PullNum (
        double			*value)
{
        string			 buf;

        PullWhite ();
        PullNonWhite (buf);
        if (!buf.length ())
                return false;

        value[0] = atof (buf.c_str ());
        return true;
}

        bool
CLxLineParser::PullNum (
        unsigned		*value)
{
        string			 buf;

        PullWhite ();
        while (IsDigit (cur_pos[0]))
                buf += *cur_pos++;

        if (!buf.length ())
                return false;

        buf += '\0';
        value[0] = atoi (buf.c_str ());
        return true;
}

        bool
CLxLineParser::PullNum (
        int			*value)
{
        int			sign;
        unsigned		uval;

        if (PullExpected ('-'))
                sign = -1;
        else
                sign = 1;

        if (!PullNum (&uval))
                return false;

        *value = uval * sign;
        return true;
}

        bool
CLxLineParser::PullExpected (
        char			 c)
{
        PullWhite ();
        if (cur_pos[0] != c)
                return false;

        cur_pos++;
        return true;
}

        bool
CLxLineParser::IsBlank (
        char			 c)
{
        return (c == ' ' || c == '\t' || c == '\n');
}

        bool
CLxLineParser::IsDigit (
        char			 c)
{
        return (c >= '0' && c <= '9');
}

        char
CLxLineParser::Upper (
        char			 c)
{
        if (c >= 'a' && c <= 'z')
                return c - 'a' + 'A';
        else
                return c;
}

        char
CLxLineParser::Lower (
        char			 c)
{
        if (c >= 'A' && c <= 'Z')
                return c - 'A' + 'a';
        else
                return c;
}




/*
 * ----------------------------------------------------------------
 * CLxBinaryParser : Implementation
 */

class pv_BinaryParser {
    public:
                                 pv_BinaryParser ();
        void			 InitMon ();
        char *			 ReadLine (char *, unsigned &);

        string			 filename;
        FILE			*file;
        CLxUser_Monitor		 mon;
        LxResult		 error;
        unsigned int		 length, pos;
        bool			 moninit;
};

pv_BinaryParser::pv_BinaryParser ()
{
        filename = "";
        file     = 0;
        error    = LXe_FALSE;
        moninit  = 0;
}

        void
pv_BinaryParser::InitMon ()
{
        if (mon.test () && moninit) {
                mon.Initialize (length);
                pos     = 0;
                moninit = 0;
        }
}

CLxBinaryParser::CLxBinaryParser ()
{
        pv = new pv_BinaryParser;
}

CLxBinaryParser::~CLxBinaryParser ()
{
        fp_Cleanup ();
}

        bool
CLxBinaryParser::fp_Open (
        const char		*filename)
{
        fp_Cleanup ();

        pv->filename = filename;
        file_name = pv->filename.c_str ();

        /*
         * Open the file for reading in binary mode.
         */
        pv->file = fopen (filename, "rb");
        if (!pv->file) {
                pv->error = LXe_NOTFOUND;
                return false;
        }

        fseek (pv->file, 0, SEEK_END);
        pv->length = ftell (pv->file);
        fseek (pv->file, 0, SEEK_SET);

        if (ferror (pv->file)) {
                pv->error = LXe_IO_ERROR;
                return false;
        }

        pv->moninit = 1;
        pv->InitMon ();

        pv->error = LXe_OK;
        return true;
}

        void
CLxBinaryParser::fp_SetMonitor (
        LXtObjectID		 monObj)
{
        pv->mon.set (monObj);
        pv->InitMon ();
}

        bool
CLxBinaryParser::fp_HasError ()
{
        return LXx_FAIL (pv->error);
}

        LxResult
CLxBinaryParser::fp_ErrorCode ()
{
        return pv->error;
}

        void
CLxBinaryParser::fp_Cleanup ()
{
        pv->error = LXe_FALSE;
        pv->filename = "";
        pv->mon.clear ();
        pv->moninit  = 0;
        cur_pos = 0;

        if (pv->file) {
                fclose (pv->file);
                pv->file = 0;
        }
}

        bool
CLxBinaryParser::PullBlock (void *buf, size_t size)
{
        bool	pulled(false);

        if (buf) {
                size_t bytesRead = fread (
                        buf, 1, size, pv->file);

                pulled = (bytesRead == size);
        }
        else {
                fseek (pv->file, static_cast<long>(size), SEEK_CUR);
                pulled = true;
        }

        return pulled;
}

        size_t
CLxBinaryParser::StringLen ()
{
        size_t length(0);

        unsigned savPos = ftell (pv->file);

        unsigned char charBuf(0xFF);
        do {
                size_t bytesRead = fread (&charBuf, 1, 1, pv->file);
                if ((bytesRead == 1) && (charBuf != 0)) {
                        ++length;
                }
                else {
                        break;
                }
        } while (true);

        fseek (pv->file, savPos, SEEK_CUR);

        return length;
}

        bool
CLxBinaryParser::PullString (char *text, size_t maxSize)
{
        char *buf = text;

        bool haveString(true);
        size_t length(0);

        do {
                size_t bytesRead = fread (buf, 1, 1, pv->file);
                if ((bytesRead == 1) && (*buf != 0)) {
                        ++length;
                        if (maxSize && length >= maxSize) {
                                break;
                        }
                }
                else {
                        haveString = (bytesRead == 1);
                        break;
                }
                ++buf;
        } while (true);

        return haveString;
}

        bool
CLxBinaryParser::PullNum (float *value)
{
        size_t bytesRead = fread (
                value, 1, sizeof(float), pv->file);

        return (bytesRead == sizeof(float));
}

        bool
CLxBinaryParser::PullNum (double *value)
{
        size_t bytesRead = fread (
                value, 1, sizeof(double), pv->file);

        return (bytesRead == sizeof(double));
}

        bool
CLxBinaryParser::PullNum (unsigned *value)
{
        size_t bytesRead = fread (
                value, 1, sizeof(unsigned), pv->file);

        return (bytesRead == sizeof(unsigned));
}

        bool
CLxBinaryParser::PullNum (int *value)
{
        size_t bytesRead = fread (
                value, 1, sizeof(int), pv->file);

        return (bytesRead == sizeof(int));
}

