/*
 * LX server module
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
#ifndef LX_server_H
#define LX_server_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxFactory ** ILxFactoryID;
typedef struct vt_ILxHostService ** ILxHostServiceID;
typedef struct vt_ILxModule ** ILxModuleID;
typedef struct vt_ILxTagDescription ** ILxTagDescriptionID;
typedef struct vt_ILxNeedContext ** ILxNeedContextID;
typedef struct vt_ILxServiceExtension ** ILxServiceExtensionID;
typedef struct vt_ILxModule1 ** ILxModule1ID;
#include <lxio.h>
#include <lxvalue.h>


typedef struct st_LXtTagInfoDesc {
        const char              *type;
        const char              *info;
        const LXtGUID           *guid;
} LXtTagInfoDesc;
typedef struct vt_ILxFactory {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Name) (
                LXtObjectID               self,
                const char              **name);
                LXxMETHOD(  LxResult,
        UserName) (
                LXtObjectID               self,
                const char              **userName);
                LXxMETHOD(  LxResult,
        ClassGUID) (
                LXtObjectID               self,
                LXtGUID                  *guid);
                LXxMETHOD(  LxResult,
        Module) (
                LXtObjectID              self,
                const char             **module);
                LXxMETHOD(  LxResult,
        InfoTag) (
                LXtObjectID              self,
                const char              *type,
                const char             **value);

                LXxMETHOD(  LxResult,
        TagCount) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        TagByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                const char             **type,
                const char             **value);
                LXxMETHOD(  LxResult,
        Spawn) (
                LXtObjectID               self,
                void                    **ppvObj);
} ILxFactory;
typedef struct vt_ILxHostService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        LookupServer) (
                LXtObjectID              self,
                const char              *className,
                const char              *name,
                unsigned                 allowLoad,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        TestServer) (
                LXtObjectID              self,
                const char              *className,
                const char              *name);
                LXxMETHOD(  unsigned,
        NumServers) (
                LXtObjectID              self,
                const char              *className);
                LXxMETHOD(  LxResult,
        ServerByIndex) (
                LXtObjectID              self,
                const char              *className,
                unsigned                 index,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ServerGetIndex) (
                LXtObjectID              self,
                const char              *className,
                const char              *name,
                unsigned                *index);
                LXxMETHOD(  LxResult,
        AddServer) (
                LXtObjectID              self,
                LXtObjectID              factory);
                LXxMETHOD(  LxResult,
        DefaultPath) (
                LXtObjectID               self,
                const char              **path);
                LXxMETHOD(  LxResult,
        SpawnForTagsOnly) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        UpdateModule) (
                LXtObjectID              self,
                const char              *name);
} ILxHostService;
typedef struct vt_ILxModule {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Generate) (
                LXtObjectID              self,
                const char              *name,
                const LXtGUID           *iid,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        GetTags) (
                LXtObjectID              self,
                const char              *name,
                const LXtGUID           *iid,
                void                   **ppvObj);
} ILxModule;
typedef struct vt_ILxTagDescription {
        ILxUnknown       iunk;
                LXxMETHOD( unsigned,
        Count) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Describe) (
                LXtObjectID              self,
                unsigned                 index,
                LXtTagInfoDesc          *desc);
} ILxTagDescription;
typedef struct vt_ILxNeedContext {
        ILxUnknown       iunk;
                LXxMETHOD ( LxResult,
        SetContext) (
                LXtObjectID              self,
                LXtObjectID              app);
} ILxNeedContext;
typedef struct vt_ILxServiceExtension {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        Dummy) (
                LXtObjectID              self);
} ILxServiceExtension;
typedef struct vt_ILxModule1 {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Generate) (
                LXtObjectID              self,
                const char              *name,
                const LXtGUID           *iid,
                void                   **ppvObj);

                LXxMETHOD( unsigned,
        IsLocked) (
                LXtObjectID              self);
} ILxModule1;

#define LXsSRV_USERNAME         "server.username"
#define LXsSRV_LICENSE          "server.license"
#define LXsSRV_OWNER            "server.owner"
#define LXsSRV_SERIAL           "server.serial"
#define LXu_FACTORY             "2431A79E-3412-4B0D-987D-875489466C58"
// [export] ILxFactory
// [local]  ILxFactory
// [python] ILxFactory:Spawn    obj Unknown
#define LXu_HOSTSERVICE         "525802A6-BF5F-46E9-9863-C03B54A3D908"
#define LXa_HOSTSERVICE         "hostservice"

// [python] ILxHostService:LookupServer         obj Factory
// [python] ILxHostService:ServerByIndex        obj Factory
// [python] ILxHostService:TestServer           bool
#define LXu_MODULE      "4DB9C543-B192-4EDD-A65D-DD012FC27416"
#define LXa_MODULE      "module2"
// [local]  ILxModule
// [export] ILxModule
// [python] ILxModule:Generate  obj Unknown
// [python] ILxModule:GetTags   obj StringTags
#define LXu_TAGDESCRIPTION      "5582E0EE-D682-47BC-BF3D-FB14D59948C1"
#define LXsMOD_SERVER           "server"
// [export] ILxTagDescription
// [local]  ILxTagDescription
#define LXu_NEEDCONTEXT         "7D30408C-74AB-4d87-B71C-C6280883863C"
// [local]  ILxNeedContext
// [export] ILxNeedContext
#define LXu_SERVICEEXTENSION    "E7C6F1A2-2F31-4FA5-B2EF-421BE159D0D8"
#define LXa_SERVICEEXTENSION    "serviceExtension"
// [export]  ILxServiceExtension

#define LXsSRVEXT_GUID          "extension.guid"
#define LXu_MODULE1     "BD6F0E53-C903-46D3-9211-758558D95CAA"
#define LXa_MODULE1     "module"

 #ifdef __cplusplus
  }
 #endif
#endif

