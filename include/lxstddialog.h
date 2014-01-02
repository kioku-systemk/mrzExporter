/*
 * LX comp module
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
 */
#ifndef LX_comp_H
#define LX_comp_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxColorDialog ** ILxColorDialogID;
typedef struct vt_ILxStdDialogService ** ILxStdDialogServiceID;
#include <lxserver.h>
#include <lxvalue.h>



typedef struct vt_ILxColorDialog {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        DoDialog) (
                LXtObjectID               self,
                const char               *title,
                double                    stops,
                double                    gamma,
                double                   *rgb);
} ILxColorDialog;
typedef struct vt_ILxStdDialogService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        MonitorAllocate) (
                LXtObjectID               self,
                const char               *title,
                void                    **ppvObj);

                LXxMETHOD(  LxResult,
        MonitorRelease) (
                LXtObjectID               self);
                LXxMETHOD(  LxResult,
        MessageAllocate) (
                LXtObjectID               self,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        MessageOpen) (
                LXtObjectID               self,
                LXtObjectID               message,
                const char               *title,
                const char               *helpURL,
                const char               *cookie);
} ILxStdDialogService;

#define LXu_COLORDIALOG                 "2AB01AAE-110B-11DF-BFD0-0AC756D89593"
#define LXa_COLORDIALOG                 "colordialog"
// [local] ILxColorDialog
// [export] ILxColorDialog colordlg
#define LXa_STDDIALOGSERVICE    "stddialogservice"
#define LXu_STDDIALOGSERVICE    "A78FA063-6C8D-471f-8981-6BAEFF62BEE3"
// [python]  ILxStdDialogService:MonitorAllocate        obj Monitor (io)
// [python]  ILxStdDialogService:MessageAllocate        obj Message (value)
#define LXeMSGDIALOG_AS_OKCANCEL        LXxGOODCODE( LXeSYS_COMP, 50 )
#define LXeMSGDIALOG_AS_YESNO           LXxGOODCODE( LXeSYS_COMP, 51 )
#define LXeMSGDIALOG_AS_YESNOCANCEL     LXxGOODCODE( LXeSYS_COMP, 52 )
#define LXeMSGDIALOG_AS_SAVEOK          LXxGOODCODE( LXeSYS_COMP, 53 )
#define LXeMSGDIALOG_AS_YESNOALL        LXxGOODCODE( LXeSYS_COMP, 54 )
#define LXeMSGDIALOG_AS_YESNOTOALL      LXxGOODCODE( LXeSYS_COMP, 55 )
#define LXeMSGDIALOG_AS_YESTOALLCANCEL  LXxGOODCODE( LXeSYS_COMP, 56 )
#define LXeMSGDIALOG_EMPTY              LXxFAILCODE( LXeSYS_COMP, 60 )
#define LXeMSGDIALOG_INVALID            LXxFAILCODE( LXeSYS_COMP, 61 )
#define LXeMSGDIALOG_OK                  LXe_OK
#define LXeMSGDIALOG_YES                 LXe_OK                                 // Also for "Save" in the SAVEOK dialog
#define LXeMSGDIALOG_YESTOALL            LXxGOODCODE( LXeSYS_COMP, 70 )
#define LXeMSGDIALOG_NO                  LXxFAILCODE( LXeSYS_COMP, 71 )         // Also for "Don't Save" in the SAVEOK dialog
#define LXeMSGDIALOG_NOTOALL             LXxGOODCODE( LXeSYS_COMP, 72 )
#define LXeMSGDIALOG_CANCEL              LXxFAILCODE( LXeSYS_COMP, 73 )

 #ifdef __cplusplus
  }
 #endif
#endif

