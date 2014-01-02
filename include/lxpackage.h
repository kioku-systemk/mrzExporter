/*
 * LX package module
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
#ifndef LX_package_H
#define LX_package_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxSceneItemListener1 ** ILxSceneItemListener1ID;
typedef struct vt_ILxSceneItemListener ** ILxSceneItemListenerID;
typedef struct vt_ILxSceneLoaderTarget ** ILxSceneLoaderTargetID;
typedef struct vt_ILxScene1 ** ILxScene1ID;
typedef struct vt_ILxItem1 ** ILxItem1ID;
typedef struct vt_ILxPackage ** ILxPackageID;
typedef struct vt_ILxAddChannel ** ILxAddChannelID;
typedef struct vt_ILxPackageInstance ** ILxPackageInstanceID;
#include <lxcom.h>
#include <lxvalue.h>
#include <lxvertex.h>


typedef struct st_LXtSceneTarget {
        int                      itemType;
        int                      flags;
} LXtSceneTarget;
typedef struct vt_ILxSceneItemListener1 {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        SceneCreate) (
                LXtObjectID              self,
                LXtObjectID              scene);

                LXxMETHOD( void,
        SceneDestroy) (
                LXtObjectID              self,
                LXtObjectID              scene);

                LXxMETHOD( void,
        SceneFilename) (
                LXtObjectID              self,
                LXtObjectID              scene,
                const char              *filename);

                LXxMETHOD( void,
        SceneClear) (
                LXtObjectID              self,
                LXtObjectID              scene);

                LXxMETHOD( void,
        ItemPreChange) (
                LXtObjectID              self,
                LXtObjectID              scene);

                LXxMETHOD( void,
        ItemPostDelete) (
                LXtObjectID              self,
                LXtObjectID              scene);

                LXxMETHOD( void,
        ItemAdd) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemRemove) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemParent) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemChild) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemAddChannel) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemLocal) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemName) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemSource) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemPackage) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ChannelValue) (
                LXtObjectID              self,
                const char               *action,
                LXtObjectID              item,
                unsigned                 index);
} ILxSceneItemListener1;
typedef struct vt_ILxSceneItemListener {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        SceneCreate) (
                LXtObjectID              self,
                LXtObjectID              scene);

                LXxMETHOD( void,
        SceneDestroy) (
                LXtObjectID              self,
                LXtObjectID              scene);

                LXxMETHOD( void,
        SceneFilename) (
                LXtObjectID              self,
                LXtObjectID              scene,
                const char              *filename);

                LXxMETHOD( void,
        SceneClear) (
                LXtObjectID              self,
                LXtObjectID              scene);

                LXxMETHOD( void,
        ItemPreChange) (
                LXtObjectID              self,
                LXtObjectID              scene);

                LXxMETHOD( void,
        ItemPostDelete) (
                LXtObjectID              self,
                LXtObjectID              scene);

                LXxMETHOD( void,
        ItemAdd) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemRemove) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemParent) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemChild) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemAddChannel) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemLocal) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemName) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemSource) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ItemPackage) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( void,
        ChannelValue) (
                LXtObjectID              self,
                const char               *action,
                LXtObjectID              item,
                unsigned                 index);
                LXxMETHOD( void,
        LinkAdd) (
                LXtObjectID              self,
                const char              *graph,
                LXtObjectID              itemFrom,
                LXtObjectID              itemTo);

                LXxMETHOD( void,
        LinkRemBefore) (
                LXtObjectID              self,
                const char              *graph,
                LXtObjectID              itemFrom,
                LXtObjectID              itemTo);

                LXxMETHOD( void,
        LinkRemAfter) (
                LXtObjectID              self,
                const char              *graph,
                LXtObjectID              itemFrom,
                LXtObjectID              itemTo);

                LXxMETHOD( void,
        LinkSet) (
                LXtObjectID              self,
                const char              *graph,
                LXtObjectID              itemFrom,
                LXtObjectID              itemTo);

                LXxMETHOD( void,
        ChanLinkAdd) (
                LXtObjectID              self,
                const char              *graph,
                LXtObjectID              itemFrom,
                unsigned                 chanFrom,
                LXtObjectID              itemTo,
                unsigned                 chanTo);

                LXxMETHOD( void,
        ChanLinkRemBefore) (
                LXtObjectID              self,
                const char              *graph,
                LXtObjectID              itemFrom,
                unsigned                 chanFrom,
                LXtObjectID              itemTo,
                unsigned                 chanTo);

                LXxMETHOD( void,
        ChanLinkRemAfter) (
                LXtObjectID              self,
                const char              *graph,
                LXtObjectID              itemFrom,
                unsigned                 chanFrom,
                LXtObjectID              itemTo,
                unsigned                 chanTo);

                LXxMETHOD( void,
        ChanLinkSet) (
                LXtObjectID              self,
                const char              *graph,
                LXtObjectID              itemFrom,
                unsigned                 chanFrom,
                LXtObjectID              itemTo,
                unsigned                 chanTo);
} ILxSceneItemListener;
typedef struct vt_ILxSceneLoaderTarget {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        SetRootType) (
                LXtObjectID              self,
                const char              *typeName);

                LXxMETHOD( LxResult,
        SetFlags) (
                LXtObjectID              self,
                unsigned                 flags);

                LXxMETHOD( LxResult,
        ClearFlags) (
                LXtObjectID              self,
                unsigned                 flags);
} ILxSceneLoaderTarget;
typedef struct vt_ILxScene1 {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Lookup) (
                LXtObjectID              self,
                const char              *id,
                void                   **ppvObj);

                LXxMETHOD( int,
        ItemCount) (
                LXtObjectID              self,
                const char              *type);

                LXxMETHOD( LxResult,
        ItemByIndex) (
                LXtObjectID              self,
                const char              *type,
                unsigned int             index,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        ItemByName) (
                LXtObjectID              self,
                const char              *type_is_ignored,
                const char              *name,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        NewItem) (
                LXtObjectID              self,
                const char              *type,
                void                   **ppvObj);
                LXxMETHOD( void,
        GetMeta) (
                LXtObjectID              self,
                void                    **xobj);

                LXxMETHOD( void,
        SetMeta) (
                LXtObjectID              self,
                LXtObjectID              xobj);
                LXxMETHOD( const char *,
        GetTag) (
                LXtObjectID              self,
                LXtID4                   type);

                LXxMETHOD( void,
        SetTag) (
                LXtObjectID              self,
                LXtID4                   type,
                const char              *tag);
                LXxMETHOD( LxResult,
        Setup) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        Edit) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        Action) (
                LXtObjectID              self,
                double                   time,
                void                   **ppvObj);

                LXxMETHOD( void,
        ListenAction) (
                LXtObjectID              self,
                LXtObjectID              xobj);
                LXxMETHOD( LxResult,
        LoadImage) (
                LXtObjectID              self,
                const char              *name,
                int                     *flags,
                LXtObjectID              monitor,
                void                   **ppvObj);

} ILxScene1;
typedef struct vt_ILxItem1 {
        ILxUnknown       iunk;
                LXxMETHOD( const char *,
        Type) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        TestType) (
                LXtObjectID              self,
                const char              *type);

                LXxMETHOD( const char *,
        Ident) (
                LXtObjectID              self);

                LXxMETHOD( const char *,
        GetTag) (
                LXtObjectID              self,
                unsigned int             tag);

                LXxMETHOD( void,
        SetTag) (
                LXtObjectID              self,
                unsigned int             type,
                const char              *tag);

                LXxMETHOD( int,
        SubItemCount) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        SubItemByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **ppvObj);

                LXxMETHOD( const char *,
        Name) (
                LXtObjectID              self);

                LXxMETHOD( void,
        SetName) (
                LXtObjectID              self,
                const char              *name);

                LXxMETHOD( void,
        Root) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        Parent) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( void,
        SetParent) (
                LXtObjectID              self,
                LXtObjectID              parent,
                int                      pos);

                LXxMETHOD( int,
        ChannelCount) (
                LXtObjectID              self);

                LXxMETHOD( const char *,
        ChannelName) (
                LXtObjectID              self,
                unsigned int             index);

                LXxMETHOD( LxResult,
        ChannelIndex) (
                LXtObjectID              self,
                const char              *name,
                unsigned int            *index);

                LXxMETHOD( LxResult,
        FindXfrmChannel) (
                LXtObjectID               self,
                const char               *name,
                unsigned int             *index,
                void                    **ppvObj);
} ILxItem1;
typedef struct vt_ILxPackage {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        SetupChannels) (
                LXtObjectID              self,
                LXtObjectID              addChan);

                LXxMETHOD( LxResult,
        Attach) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        TestInterface) (
                LXtObjectID              self,
                const LXtGUID           *guid);

                LXxMETHOD( LxResult,
        PostLoad) (
                LXtObjectID              self,
                LXtObjectID              scene);
} ILxPackage;
typedef struct vt_ILxAddChannel {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        NewChannel) (
                LXtObjectID              self,
                const char              *name,
                const char              *type);
                LXxMETHOD( LxResult,
        SetGradient) (
                LXtObjectID              self,
                const char              *inType);
                LXxMETHOD( LxResult,
        SetStorage) (
                LXtObjectID              self,
                const char              *stType);
                LXxMETHOD( LxResult,
        SetVector) (
                LXtObjectID              self,
                const char              *vecType);
                LXxMETHOD( LxResult,
        SetDefault) (
                LXtObjectID              self,
                double                   defFlt,
                int                      defInt);

                LXxMETHOD( LxResult,
        SetDefaultVec) (
                LXtObjectID              self,
                const double            *defVec);
                LXxMETHOD( LxResult,
        SetHint) (
                LXtObjectID              self,
                const LXtTextValueHint  *hint);
                LXxMETHOD( LxResult,
        SetDefaultObj) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD( void,
        SetInternal) (
                LXtObjectID              self);
} ILxAddChannel;
typedef struct vt_ILxPackageInstance {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Initialize) (
                LXtObjectID              self,
                LXtObjectID              item,
                LXtObjectID              super);

                LXxMETHOD( void,
        Cleanup) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        SynthName) (
                LXtObjectID              self,
                char                    *buf,
                unsigned                 len);

                LXxMETHOD( unsigned,
        DupType) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        TestParent) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD( LxResult,
        Newborn) (
                LXtObjectID              self,
                LXtObjectID              original);

                LXxMETHOD( LxResult,
        Loading) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        AfterLoad) (
                LXtObjectID              self);

                LXxMETHOD( void,
        Doomed) (
                LXtObjectID              self);
} ILxPackageInstance;

#define LXu_SCENEITEMLISTENER1  "BCCD05F8-E560-11D7-B3B8-000393CE9680"
#define LXu_SCENEITEMLISTENER   "C72C641E-CDCD-431B-ADD9-D75554D656E1"
// [export] ILxSceneItemListener sil
// [local]  ILxSceneItemListener
#define LXu_SCENELOADERTARGET   "A914B4F9-947C-4334-9D89-64BB8DC26BF6"
// [local]  ILxSceneLoaderTarget
#define LXf_SCENETARG_SUBCINE           1
#define LXf_SCENETARG_NODEFAULTS        2
#define LXf_SCENETARG_CINECHANGED       4
#define LXf_SCENETARG_GONATIVE          8
#define LXf_LOADIMG_SEARCH_PATHS        1
#define LXf_LOADIMG_USER_REPLACE        2
#define LXu_SCENE1      "4340A8FC-F984-4E04-A4BB-83931A6335AF"
#define LXa_SCENE1      "scene"
#define LXu_ITEM1       "5B14C8B6-29EF-473A-B1B3-568DFD9AE8D7"
#define LXu_PACKAGE     "6383211E-2624-492e-8C4B-D06BB43886A7"
#define LXa_PACKAGE     "package"
// [export] ILxPackage pkg
// [local]  ILxPackage
// [python] ILxPackage:TestInterface    bool
#define LXsPKG_SUPERTYPE        "super"
#define LXsPKG_GRAPHS           "pkg.graphs"
#define LXsPKG_CREATECMD        "pkg.createCmd"
#define LXs_PKG_NODIRECTCREATE  "-"
#define LXsPKG_CONVERTCMD       "pkg.convertCmd"
#define LXs_PKG_DIRECTCONVERTOK "-"
#define LXsPKG_IS_MASK          "isMaskItem"
#define LXsPKG_SHADER_CONTEXT           "shaderContext"
#define LXsPKG_CREATE_INDIRECT  "createIndirect"
#define LXu_ADDCHANNEL          "6E732ACC-AAA5-4695-B5DE-8059A2800554"
// [local]  ILxAddChannel
// [python] ILxAddChannel:SetDefaultObj         obj Unknown

#define LXsCHANVEC_SCALAR       "V"
#define LXsCHANVEC_XY            LXsVECTYPE_XY
#define LXsCHANVEC_XYZ           LXsVECTYPE_XYZ
#define LXsCHANVEC_RGB           LXsVECTYPE_RGB
#define LXsCHANVEC_RGBA          LXsVECTYPE_RGBA
#define LXu_PACKAGEINSTANCE     "09D603F7-CCF6-4A5C-B41C-021AC6C17A94"
#define LXa_PACKAGEINSTANCE     "packageInstance"
// [export]  ILxPackageInstance pins
// [local]   ILxPackageInstance
// [default] ILxPackageInstance:DupType    = 0
// [default] ILxPackageInstance:TestParent = LXe_TRUE
// [python]  ILxPackageInstance:TestParent      bool
#define LXi_CIT_GROUP            1
#define LXi_CIT_CLIP             2
#define LXi_CIT_LOCATOR          3
#define LXi_CIT_MESH             4
#define LXi_CIT_LIGHT            5
#define LXi_CIT_CAMERA           6
#define LXi_CIT_INSTANCE         7
#define LXi_CIT_T_LOC            8
#define LXi_CIT_RENDER           9
#define LXi_CIT_ENVIRON          10
#define LXi_CIT_BACKDROP         11
#define LXi_CIT_TLAYER           12

 #ifdef __cplusplus
  }
 #endif
#endif

