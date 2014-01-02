/*
 * LX notify module
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
#ifndef LX_notify_H
#define LX_notify_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxNotifySysService ** ILxNotifySysServiceID;
typedef struct vt_ILxNotifier ** ILxNotifierID;
typedef struct vt_ILxNotify ** ILxNotifyID;
#include <lxserver.h>



typedef struct vt_ILxNotifySysService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        Spawn) (
                LXtObjectID              self,
                const char              *name,
                const char              *args,
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
                const char              *args,
                void                   **ppvObj);
} ILxNotifySysService;
typedef struct vt_ILxNotifier {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Name) (
                LXtObjectID              self,
                const char             **name);
                LXxMETHOD(  LxResult,
        SetArgs) (
                LXtObjectID              self,
                const char              *args);
                LXxMETHOD(  LxResult,
        Args) (
                LXtObjectID              self,
                const char             **args);
                LXxMETHOD(  LxResult,
        AddClient) (
                LXtObjectID              self,
                LXtObjectID              object);
                LXxMETHOD(  LxResult,
        RemoveClient) (
                LXtObjectID              self,
                LXtObjectID              object);
} ILxNotifier;
typedef struct vt_ILxNotify {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Notifier) (
                LXtObjectID              self,
                void                   **ppvObj);
} ILxNotify;

#define LXu_NOTIFYSYSSERVICE    "4A3B31B0-A8F8-430A-9611-9D30E51CBBBA"
// [python] ILxNotifySysService:ByIndex obj Notifier
// [python] ILxNotifySysService:Lookup  obj Notifier
// [python] ILxNotifySysService:Spawn   obj Notifier
#define LXsNOTIFIER_SELECT      "select.event"
#define LXsNOTIFIER_MESHES      "meshes.event"
#define LXsNOTIFIER_GRAPHS      "graphs.event"
#define LXsNOTIFIER_CHANNEL     "channel.event"
#define LXsNOTIFIER_ACTION      "action.event"
#define LXu_NOTIFIER    "68725BA4-8EF9-4de4-8792-74CF090799C3"
#define LXa_NOTIFIER    "notifier"
// [local]  ILxNotifier
// [export] ILxNotifier noti
#define LXu_NOTIFY      "15C9BFC0-A0A7-448c-8CD5-A8FCA2CB145B"

 #ifdef __cplusplus
  }
 #endif
#endif

