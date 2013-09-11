/*
 * LX channelui module
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
#ifndef LX_channelui_H
#define LX_channelui_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxChannelUI ** ILxChannelUIID;
typedef struct vt_ILxChannelUIService ** ILxChannelUIServiceID;
#include <lxitem.h>



typedef struct vt_ILxChannelUI {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Enabled) (
                LXtObjectID              self,
                const char              *channelName,
                LXtObjectID              msg,
                LXtObjectID              item,
                LXtObjectID              chanRead);
                LXxMETHOD(  LxResult,
        DependencyCount) (
                LXtObjectID               self,
                const char               *channelName,
                unsigned                 *count);
                LXxMETHOD(  LxResult,
        DependencyByIndex) (
                LXtObjectID               self,
                const char               *channelName,
                unsigned                  index,
                LXtItemType              *depItemType,
                const char              **depChannelName);
                LXxMETHOD(  LxResult,
        ItemEnabled) (
                LXtObjectID              self,
                LXtObjectID              msg,
                LXtObjectID              item);
                LXxMETHOD(  LxResult,
        UIHints) (
                LXtObjectID               self,
                const char               *channelName,
                LXtObjectID               hints);
                LXxMETHOD(  LxResult,
        UIValueHints) (
                LXtObjectID               self,
                const char               *channelName,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        Cookie) (
                LXtObjectID               self,
                const char               *channelName,
                const char               *requestedFor,
                const char              **cookie);
} ILxChannelUI;
typedef struct vt_ILxChannelUIService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ItemTypeName) (
                LXtObjectID              self,
                LXtItemType              typeID,
                unsigned                 useSuper,
                const char             **name);

                LXxMETHOD(  LxResult,
        ItemTypeDesc) (
                LXtObjectID              self,
                LXtItemType              typeID,
                unsigned                 useSuper,
                const char             **name);

                LXxMETHOD(  LxResult,
        ItemTypeIconText) (
                LXtObjectID              self,
                LXtItemType              typeID,
                unsigned                 useSuper,
                char                    *buf,
                unsigned                 len);

                LXxMETHOD(  LxResult,
        MeshMapUserName) (
                LXtObjectID              self,
                const char              *name,
                unsigned                 addIcon,
                char                    *buf,
                unsigned                 len);
} ILxChannelUIService;

#define LXu_CHANNELUI   "BF1BFE3B-F0F5-490b-8961-721795DA57B4"
#define LXa_CHANNELUI   "channelui"
// [local]  ILxChannelUI
// [export] ILxChannelUI cui
#define LXu_CHANNELUISERVICE    "3C3A2D98-7EF1-43F4-845C-39EF2D8F6D52"
#define LXa_CHANNELUISERVICE    "channelUIservice"

 #ifdef __cplusplus
  }
 #endif
#endif

