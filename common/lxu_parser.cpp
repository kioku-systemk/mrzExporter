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
 * General I/O
 */
#include <lxu_parser.hpp>
#include <lx_io.hpp>
#include <lx_wrap.hpp>
#include <stdio.h>
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
 * Private data is the filename string and the file stream.  Since streams
 * have problems being closed and re-opened we allocate a new one for each
 * file.
 */
class pv_LineParser {
    public:
        pv_LineParser ();
        void			 InitMon ();
        char *			 ReadLine (char *, unsigned &);

        string			 filename;
        FILE			*file;
        CLxUser_Monitor		 mon;
        LxResult		 error;
        unsigned int		 length, pos, monPos;
        bool			 moninit;
};


pv_LineParser::pv_LineParser ()
{
        filename = "";
        file     = 0;
        error    = LXe_FALSE;
        moninit  = 0;
}

        void
pv_LineParser::InitMon ()
{
        if (mon.test () && moninit) {
                mon.Initialize (length);
                monPos	= pos;
                moninit = 0;
        }
}

        char *
pv_LineParser::ReadLine (
        char			*buf,
        unsigned		&len)
{
        int			 c;

        while (len > 1) {
                c = getc (file);
                this->pos++;
                if (c == EOF || c == '\n' || c == 10 || c == 13) {
                        *buf = 0;
                        return buf;
                }

                *buf++ = c;
                len--;
        }

        return 0;
}


CLxLineParser::CLxLineParser ()
{
        pv = new pv_LineParser;

        cur_pos  = 0;

        line_buf = new char[lp_MaxLine ()];
        line_buf[0] = 0;
}

CLxLineParser::CLxLineParser (unsigned maxLine)
{
        pv = new pv_LineParser;

        cur_pos  = 0;

        line_buf = new char[maxLine];
        line_buf[0] = 0;
}

CLxLineParser::~CLxLineParser ()
{
        fp_Cleanup ();
        delete[] line_buf;
}

        bool
CLxLineParser::fp_Open (
        const char		*filename)
{
        FILE *tempFile;

        fp_Cleanup ();

        pv->filename = filename;
        file_name = pv->filename.c_str ();

        // Need to get the filesize in binary
        // mode
        tempFile = fopen (filename, "rb");
        if (tempFile == NULL) {
                pv->error = LXe_NOTFOUND;
                return false;
        }
        fseek (tempFile, 0, SEEK_END);
        pv->length = ftell (tempFile);
        fclose (tempFile);

        pv->file = fopen (filename, "r");
        if (!pv->file) {
                pv->error = LXe_NOTFOUND;
                return false;
        }

        if (ferror (pv->file)) {
                pv->error = LXe_IO_ERROR;
                return false;
        }

        pv->pos     = 0;
        pv->moninit = 1;
        pv->InitMon ();

        pv->error = LXe_OK;
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
CLxLineParser::lp_ReadLine ()
{
        char			*s, *buf;
        unsigned int		 pos;
        LxResult		 rc;
        unsigned int		 len;
        bool			 blank;

        if (fp_HasError () || !pv->file || feof (pv->file))
                return false;

        if (pv->mon.test ()) {
                if (fp_HasError ())
                        return false;
                if (feof (pv->file))
                        return false;

                if (ferror (pv->file)) {
                        pv->error = LXe_IO_ERROR;
                        return false;
                }

                if (pv->pos > pv->monPos) {
                        rc = pv->mon.Increment (pv->pos - pv->monPos);
                        pv->monPos = pv->pos;
                        if (LXx_FAIL (rc)) {
                                pv->error = rc;
                                return false;
                        }
                }
        }

        do {
                len = lp_MaxLine ();
                buf = line_buf;
                while (1) {
                        buf = pv->ReadLine (buf, len);
                        if (!buf || ferror (pv->file)) {
                                pv->error = LXe_IO_ERROR;
                                return false;
                        }

                        if (feof (pv->file))
                                return false;

                        if (!lp_Continue ())
                                break;

                        while (buf >= line_buf && !buf[0]) {
                                buf--;
                                len++;
                        }
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
                                blank = 0;

        } while (blank || lp_IsComment ());

        cur_pos = line_buf;
        return true;
}


/*
 * PullWhite and PullNonWhite advance the cur_pos pointer past characters of
 * their respective types.  PullNonWhite will read into an optional buffer.
 */
        void
CLxLineParser::PullWhite ()
{
        while (IsBlank (cur_pos[0]))
                cur_pos++;
}

/*
 * [TODO] The basic design of reading an unlimited number of
 *        characters needs to be revisited, since it's too easy
 *        to overflow the buffer with malformed input.
 *
 *        Ultimately, CLxLineParser::PullNonWhite should take a max
 *        buffer size, and also return a bool result, so callers
 *        can gracefully fail the load on malformed input.
 */
        void
CLxLineParser::PullNonWhite (
        char			*dest)
{
        while (cur_pos[0] && !IsBlank (cur_pos[0])) {
                if (dest)
                        *dest++ = cur_pos[0];

                cur_pos++;
        }

        if (dest)
                *dest = 0;
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
        /*
         * [TODO] Increasing the size to decrease the chance of overflow.
         *        The basic design of PullNonWhite, which reads an unlimited
         *        number of characters, needs to be revisited, since it's too
         *        easy to overflow the buffer with malformed input.
         */
        char			 buf[1024];

        PullWhite ();
        PullNonWhite (buf);
        if (buf[0] == 0)
                return false;

        value[0] = static_cast<float>(atof (buf));
        return true;
}

        bool
CLxLineParser::PullNum (
        double			*value)
{
        /*
         * [TODO] Increasing the size here as a temporary fix.
         *        The basic design of PullNonWhite, which reads an unlimited
         *        number of characters, needs to be revisited, since it's too
         *        easy to overflow the buffer with malformed input.
         */
        char			 buf[1024];

        PullWhite ();
        PullNonWhite (buf);
        if (buf[0] == 0)
                return false;

        value[0] = atof (buf);
        return true;
}

        bool
CLxLineParser::PullNum (
        unsigned		*value)
{
        /*
         * [TODO] Increasing the size to decrease the chance of overflow.
         *        The basic design of PullNonWhite, which reads an unlimited
         *        number of characters, needs to be revisited, since it's too
         *        easy to overflow the buffer with malformed input.
         */
        char			 buf[1024];
        int			 i;

        PullWhite ();
        i = 0;
        while (IsDigit (cur_pos[0]))
                buf[i++] = *cur_pos++;

        if (i == 0)
                return false;

        buf[i] = 0;
        value[0] = atoi (buf);
        return true;
}

        bool
CLxLineParser::PullNum (
        int		*value)
{
        int		sign(1);
        bool		pulled;
        unsigned	unsignedValue;

        if (PullExpected ('-')) {
                sign = -1;
        }

        pulled = PullNum (&unsignedValue);

        *value = unsignedValue * sign;

        return pulled;
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
 * CLxLineParser : Implementation
 *
 * Private data is the filename string and the file stream.  Since streams
 * have problems being closed and re-opened we allocate a new one for each
 * file.
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

