/*
 * LX IO module
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
 */
#ifndef LX_IO_H
#define LX_IO_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxBlockRead ** ILxBlockReadID;
typedef struct vt_ILxBlockWrite ** ILxBlockWriteID;
typedef struct vt_ILxLoader ** ILxLoaderID;
typedef struct vt_ILxSaver ** ILxSaverID;
typedef struct vt_ILxMonitor ** ILxMonitorID;
typedef struct vt_ILxStreamIO ** ILxStreamIOID;
typedef struct vt_ILxIOService ** ILxIOServiceID;
#include <lxcom.h>


typedef struct st_LXtBlockHeader {
        LXtID4                   id;
        const char              *token;
} LXtBlockHeader;
typedef struct st_LXtLoadAccess {
        const char              *filename;
        const LXtGUID          **types;
        LXtObjectID              monitor;
        const LXtGUID           *found;
        int                      opaque;
        void                    *target;
        const char              *format;
        int                      options;
} LXtLoadAccess;
typedef struct vt_ILxBlockRead {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        FindBlock) (
                LXtObjectID              self,
                const LXtBlockHeader    *head,
                int                      flags,
                LXtID4                  *blkId);

                LXxMETHOD( void,
        End) (
                LXtObjectID              self);

                LXxMETHOD( int,
        Depth) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        ReadI1) (
                LXtObjectID              self,
                char                    *data,
                int                      count,
                int                     *ocount);

                LXxMETHOD( LxResult,
        ReadI2) (
                LXtObjectID              self,
                short                   *data,
                int                      count,
                int                     *ocount);

                LXxMETHOD( LxResult,
        ReadI4) (
                LXtObjectID              self,
                int                     *data,
                int                      count,
                int                     *ocount);

                LXxMETHOD( LxResult,
        ReadU1) (
                LXtObjectID              self,
                unsigned char           *data,
                int                      count,
                int                     *ocount);

                LXxMETHOD( LxResult,
        ReadU2) (
                LXtObjectID              self,
                unsigned short          *data,
                int                      count,
                int                     *ocount);

                LXxMETHOD( LxResult,
        ReadU4) (
                LXtObjectID              self,
                unsigned int            *data,
                int                      count,
                int                     *ocount);

                LXxMETHOD( LxResult,
        ReadFP) (
                LXtObjectID              self,
                float                   *data,
                int                      count,
                int                     *ocount);

                LXxMETHOD( LxResult,
        ReadFP8) (
                LXtObjectID              self,
                double                  *data,
                int                      count,
                int                     *ocount);
                LXxMETHOD( LxResult,
        ReadString) (
                LXtObjectID              self,
                char                    *buf,
                int                      max,
                int                      flags,
                int                     *ocount);
                LXxMETHOD( LxResult,
        ReadIDCode) (
                LXtObjectID              self,
                const LXtBlockHeader    *list,
                LXtID4                  *idCode);

                LXxMETHOD( LxResult,
        ReadVX) (
                LXtObjectID              self,
                unsigned                *data,
                int                      count,
                int                     *ocount);
} ILxBlockRead;
typedef struct vt_ILxBlockWrite {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        WriteBlock) (
                LXtObjectID              self,
                const LXtBlockHeader    *head,
                int                      flags);

                LXxMETHOD( void,
        End) (
                LXtObjectID              self);

                LXxMETHOD( int,
        Depth) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        WriteI1) (
                LXtObjectID              self,
                const char              *data,
                int                      count);

                LXxMETHOD( LxResult,
        WriteI2) (
                LXtObjectID              self,
                const short             *data,
                int                      count);

                LXxMETHOD( LxResult,
        WriteI4) (
                LXtObjectID              self,
                const int               *data,
                int                      count);

                LXxMETHOD( LxResult,
        WriteU1) (
                LXtObjectID              self,
                const unsigned char     *data,
                int                      count);

                LXxMETHOD( LxResult,
        WriteU2) (
                LXtObjectID              self,
                const unsigned short    *data,
                int                      count);

                LXxMETHOD( LxResult,
        WriteU4) (
                LXtObjectID              self,
                const unsigned int      *data,
                int                      count);

                LXxMETHOD( LxResult,
        WriteFP) (
                LXtObjectID              self,
                const float             *data,
                int                      count);

                LXxMETHOD( LxResult,
        WriteFP8) (
                LXtObjectID              self,
                const double            *data,
                int                      count);

                LXxMETHOD( LxResult,
        WriteString) (
                LXtObjectID              self,
                const char              *str);

                LXxMETHOD( LxResult,
        WriteIDCode) (
                LXtObjectID              self,
                const LXtBlockHeader    *ident);

                LXxMETHOD( LxResult,
        WriteVX) (
                LXtObjectID              self,
                const unsigned int      *data,
                int                      count);
} ILxBlockWrite;
typedef struct vt_ILxLoader {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Recognize) (
                LXtObjectID              self,
                LXtLoadAccess           *load);
                LXxMETHOD( LxResult,
        LoadInstance) (
                LXtObjectID              self,
                LXtLoadAccess           *load,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        LoadObject) (
                LXtObjectID              self,
                LXtLoadAccess           *load,
                LXtObjectID              dest);
                LXxMETHOD( LxResult,
        Cleanup) (
                LXtObjectID              self,
                LXtLoadAccess           *load);
                LXxMETHOD( LxResult,
        SpawnOptions) (
                LXtObjectID              self,
                void                   **ppvObj);
} ILxLoader;
typedef struct vt_ILxSaver {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Verify) (
                LXtObjectID              self,
                LXtObjectID              source,
                LXtObjectID              message);

                LXxMETHOD( LxResult,
        Save) (
                LXtObjectID              self,
                LXtObjectID              source,
                const char              *filename,
                LXtObjectID              monitor);
} ILxSaver;
typedef struct vt_ILxMonitor {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Initialize) (
                LXtObjectID              self,
                unsigned int             count);

                LXxMETHOD( LxResult,
        Increment) (
                LXtObjectID              self,
                unsigned int             count);
} ILxMonitor;
typedef struct vt_ILxStreamIO {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Write) (
                LXtObjectID              self,
                LXtObjectID              stream);

                LXxMETHOD( LxResult,
        Read) (
                LXtObjectID              self,
                LXtObjectID              stream);
} ILxStreamIO;
typedef struct vt_ILxIOService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD( LxResult,
        SetOptions) (
                LXtObjectID              self,
                LXtObjectID              options);

                LXxMETHOD( LXtObjectID,
        PeekOptions) (
                LXtObjectID              self);
} ILxIOService;

#define LXe_IO_ERROR            LXxFAILCODE(LXeSYS_IO,1)
#define LXe_REF_BADID           LXxFAILCODE(LXeSYS_IO,22)
#define LXe_REF_BADPTR          LXxFAILCODE(LXeSYS_IO,23)
#define LXe_REF_DUPLICATE       LXxFAILCODE(LXeSYS_IO,24)
#define LXe_IO_SHORTREAD        LXxFAILCODE(LXeSYS_IO,25)
#define LXe_IO_NEEDGL           LXxFAILCODE(LXeSYS_IO,26)
#define LXe_IO_TRUNCATED        LXxGOODCODE(LXeSYS_IO,27)
#define LXe_IO_PARTIALSTRING    LXxGOODCODE(LXeSYS_IO,28)
#define LXu_BLOCKREAD           "36A00A47-2664-49E0-BAFF-263E638532B5"
#define LXu_BLOCKWRITE          "ADE569E1-E9A1-4AD6-B625-634093660965"
// [local]  ILxBlockRead
// [local]  ILxBlockWrite
#define LXfBLKS_FORCE    (1<<0)
#define LXfBLKS_RAW      (1<<1)
#define LXfREADSTRING_FORCE     0x01
#define LXfREADSTRING_RAW       0x02
#define LXfREADSTRING_PARTIAL   0x04
#define LXfBLKW_LEAF     (1<<0)
#define LXfBLKW_PARAM    (1<<1)
#define LXu_LOADER      "73333A41-3C0A-4B0E-A7C5-D76609827A2D"
#define LXa_LOADER      "loader"
// [export] ILxLoader
// [local]  ILxLoader
#define LXsLOD_CLASSLIST        "loader.classList"
#define LXsLOD_DOSPATTERN       "loader.dosPattern"
#define LXsLOD_MACPATTERN       "loader.macPattern"
#define LXu_SIDEEFFECT  "3414D56B-31DE-47C7-B751-092B51591DD2"
#define LXa_SIDEEFFECT  "sideeffect"
#define LXu_SAVER       "75AD8F36-5B69-413b-A77B-5A78D39AEF51"
#define LXa_SAVER       "saver"
// [export] ILxSaver
// [local]  ILxSaver
#define LXsSAV_OUTCLASS         "saver.outClass"
#define LXsSAV_DOSTYPE          "saver.dosType"
#define LXsSAV_MACTYPE          "saver.macType"
#define LXsSAV_OVERWRITE        "saver.overwrite"
#define LXu_MONITOR             "2B514D4C-5142-4687-BCEF-B0FD44A33146"
// [export] ILxMonitor
// [local]  ILxMonitor

#define LXxMON_CALL(m,fn,k)     ((m[0]->fn)(m,k))
#define LXxMON_OCAL(m,fn,k)     (m ? LXxMON_CALL(m,fn,k) : LXe_OK)
#define LXxMON_INIT(m,n)        LXx_OK  (LXxMON_OCAL(m,Initialize,n))
#define LXxMON_INCR(m,i)        LXx_FAIL(LXxMON_OCAL(m,Increment, i))
#define LXxMON_STEP(m)          LXxMON_INCR(m,1)
#define LXu_STREAMIO    "2884D6EE-4BA7-46D6-A776-8EE22C9FD414"
// [export] ILxStreamIO io
// [local]  ILxStreamIO
#define LXu_IOSERVICE   "9970CCAD-7322-4CD6-A6BA-963A63DE57D7"
#define LXa_IOSERVICE   "ioservice"

 #ifdef __cplusplus
  }
 #endif
#endif

