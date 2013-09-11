/*
 * LX scripts module
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
#ifndef LX_scripts_H
#define LX_scripts_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxScriptSysService ** ILxScriptSysServiceID;
typedef struct vt_ILxScriptManager ** ILxScriptManagerID;
typedef struct vt_ILxTextScriptInterpreter ** ILxTextScriptInterpreterID;
typedef struct vt_ILxScript ** ILxScriptID;
typedef struct vt_ILxPlatformService ** ILxPlatformServiceID;
typedef struct vt_ILxScriptLineEvent ** ILxScriptLineEventID;
#include <lxserver.h>



typedef struct vt_ILxScriptSysService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        Count) (
                LXtObjectID              self,
                unsigned int            *count);
                LXxMETHOD(  LxResult,
        ByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        NameByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                const char             **name);
                LXxMETHOD(  LxResult,
        Lookup) (
                LXtObjectID              self,
                const char              *name,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        UserName) (
                LXtObjectID              self,
                LXtObjectID              manager,
                const char             **name);
                LXxMETHOD(  LxResult,
        Desc) (
                LXtObjectID              self,
                LXtObjectID              manager,
                const char             **name);
                LXxMETHOD(  LxResult,
        ResolveAlias) (
                LXtObjectID               self,
                const char               *alias,
                const char              **path);
} ILxScriptSysService;
typedef struct vt_ILxScriptManager {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Name) (
                LXtObjectID              self,
                const char             **name);
                LXxMETHOD(  LxResult,
        Flags) (
                LXtObjectID              self,
                int                     *flags);
                LXxMETHOD(  LxResult,
        Count) (
                LXtObjectID              self,
                unsigned int            *count);
                LXxMETHOD(  LxResult,
        ByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **ppvObj,
                int                      write);
                LXxMETHOD(  LxResult,
        Lookup) (
                LXtObjectID              self,
                const char              *hash,
                void                   **ppvObj,
                int                      write,
                int                      tryAsUserName);
                LXxMETHOD(  LxResult,
        ReadWrite) (
                LXtObjectID              self,
                const char              *hash,
                int                      index);
                LXxMETHOD(  LxResult,
        New) (
                LXtObjectID              self,
                const char              *name,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        Remove) (
                LXtObjectID              self,
                LXtObjectID              script);
                LXxMETHOD (LxResult, 
        Validate) (
                LXtObjectID              self,
                LXtObjectID              script,
                LXtObjectID              msg);
                LXxMETHOD (LxResult, 
        Run) (
                LXtObjectID              self,
                LXtObjectID              script,
                int                      execFlags,
                const char              *args,
                LXtObjectID              msg);
} ILxScriptManager;
typedef struct vt_ILxTextScriptInterpreter {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ValidateFileType) (
                LXtObjectID              self,
                LXtObjectID              script,
                const char              *firstLine);
                LXxMETHOD(  LxResult,
        Validate) (
                LXtObjectID              self,
                LXtObjectID              script,
                LXtObjectID              msg);
                LXxMETHOD (LxResult, 
        Run) (
                LXtObjectID              self,
                LXtObjectID              script,
                int                      execFlags,
                const char              *args,
                LXtObjectID              msg);
} ILxTextScriptInterpreter;
typedef struct vt_ILxScript {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Hash) (
                LXtObjectID              self,
                const char             **hash);
                LXxMETHOD(  LxResult,
        UserName) (
                LXtObjectID              self,
                const char             **userName);
                LXxMETHOD(  LxResult,
        SetUserName) (
                LXtObjectID              self,
                const char              *userName);
                LXxMETHOD(  LxResult,
        Desc) (
                LXtObjectID              self,
                const char             **desc);
                LXxMETHOD(  LxResult,
        SetDesc) (
                LXtObjectID              self,
                const char              *desc);
                LXxMETHOD(  LxResult,
        Icon) (
                LXtObjectID              self,
                const char             **icon);
                LXxMETHOD(  LxResult,
        HelpKey) (
                LXtObjectID              self,
                const char              *args,
                const char             **key);
                LXxMETHOD (LxResult, 
        Manager) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD (LxResult, 
        GetBuffer) (
                LXtObjectID              self,
                const char             **buffer,
                unsigned int            *bufferLength);
                LXxMETHOD (LxResult, 
        SetBuffer) (
                LXtObjectID              self,
                const char              *buffer,
                unsigned int             bufferLength);
} ILxScript;
typedef struct vt_ILxPlatformService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        LicensedTo) (
                LXtObjectID               self,
                const char              **licensee);
                LXxMETHOD(  LxResult,
        ExpiresIn) (
                LXtObjectID              self,
                int                     *daysLeft);
                LXxMETHOD(  LxResult,
        SerialNumber) (
                LXtObjectID               self,
                const char              **serial);
                LXxMETHOD(  LxResult,
        NumLicenses) (
                LXtObjectID               self,
                int                      *licenses);
                LXxMETHOD(  LxResult,
        AppName) (
                LXtObjectID               self,
                const char              **name);
                LXxMETHOD(  LxResult,
        AppVersion) (
                LXtObjectID              self,
                int                     *version);

                LXxMETHOD(  LxResult,
        AppBuild) (
                LXtObjectID              self,
                int                     *build);
                LXxMETHOD(  LxResult,
        IsHeadless) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        OSType) (
                LXtObjectID              self,
                int                     *type);
                LXxMETHOD(  LxResult,
        OSName) (
                LXtObjectID               self,
                const char              **name);
                LXxMETHOD(  LxResult,
        OSVersion) (
                LXtObjectID               self,
                const char              **version);
                LXxMETHOD(  LxResult,
        PathCount) (
                LXtObjectID               self,
                int                      *count);

                LXxMETHOD(  LxResult,
        PathByIndex) (
                LXtObjectID               self,
                int                       index,
                const char              **path);
                LXxMETHOD(  LxResult,
        PathNameByIndex) (
                LXtObjectID               self,
                int                       index,
                const char              **name);
                LXxMETHOD(  LxResult,
        ImportPathCount) (
                LXtObjectID               self,
                int                      *index);

                LXxMETHOD(  LxResult,
        ImportPathByIndex) (
                LXtObjectID               self,
                int                       index,
                const char              **path);
                LXxMETHOD(  LxResult,
        IsApp64Bit) (
                LXtObjectID               self);
} ILxPlatformService;
typedef struct vt_ILxScriptLineEvent {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Index) (
                LXtObjectID              self,
                unsigned int            *index);

                LXxMETHOD(  LxResult,
        Script) (
                LXtObjectID              self,
                void                   **ppvObj);
} ILxScriptLineEvent;

#define LXe_SCRIPT_UNKNOWN              LXxFAILCODE( LXeSYS_SCRIPT,   1)
#define LXe_SCRIPT_ERROR                LXxFAILCODE( LXeSYS_SCRIPT,   2)
#define LXe_SCRIPT_OPAQUE               LXxFAILCODE( LXeSYS_SCRIPT,   3)
#define LXe_SCRIPT_READONLY             LXxFAILCODE( LXeSYS_SCRIPT,   4)
#define LXe_SCRIPT_ALREADY_EXISTS       LXxFAILCODE( LXeSYS_SCRIPT,   5)
#define LXe_SCRIPT_NOT_ENOUGH_ARGS      LXxFAILCODE( LXeSYS_SCRIPT,   6)
#define LXe_SCRIPT_TOO_MANY_ARGS        LXxFAILCODE( LXeSYS_SCRIPT,   7)
#define LXe_SCRIPT_RECOGNIZED_INVALID   LXxFAILCODE( LXeSYS_SCRIPT,   8)

#define LXe_SCRIPT_WARNING              LXxGOODCODE( LXeSYS_SCRIPT,   8)        // OK, not FAIL
#define LXsLOG_SCRIPTSYS         "scripts"
#define LXu_SCRIPTSYSSERVICE    "5046C663-7990-44d5-84CB-A859101B1C59"
#define LXa_SCRIPTSYSSERVICE    "scriptsysservice"
#define LXu_SCRIPTMANAGER       "3699E7C5-44B8-4e07-B8CA-E26899CD7B3B"
#define LXa_SCRIPTMANAGER       "scriptservice"
#define LXfSCRIPTSRV_CREATE             0x0001
#define LXfSCRIPTSRV_REMOVE             0x0002
#define LXfSCRIPTSRV_LINE_ACTION        0x0003
#define LXu_TEXTSCRIPTINTERPRETER       "D612FFCE-4B94-4823-A0A7-CC7CA2DDC3D6"
#define LXa_TEXTSCRIPTINTERPRETER       "textscriptinterpreter"
// [export]  ILxTextScriptInterpreter tsi
// [local]   ILxTextScriptInterpreter
// [default] ILxTextScriptInterpreter:Validate = LXe_OK
#define LXu_SCRIPT              "33C03F3F-A692-4bf4-8AB4-C5A95CA7930C"
#define LXa_SCRIPT              "script"
// [export] ILxScript
// [local]  ILxScript
#define LXu_PLATFORMSERVICE     "B9596D64-8CB3-4943-8415-7EDF527AE513"
#define LXa_PLATFORMSERVICE     "platformservice"
#define LXiOSTYPE_WIN32         1
#define LXiOSTYPE_MACOSX        2
#define LXiOSTYPE_LINUX         3
#define LXu_SCRIPTLINEEVENT     "DABF6619-A4B5-4919-8389-8C54B39422E4"
#define LXa_SCRIPTLINEEVENT     "scriptlineevent"
// [export] ILxScriptLineEvent slev
// [local]  ILxScriptLineEvent

 #ifdef __cplusplus
  }
 #endif
#endif

