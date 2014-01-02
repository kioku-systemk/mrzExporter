/*
 * LX ilxitem module
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
#ifndef LX_ilxitem_H
#define LX_ilxitem_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxSceneService ** ILxSceneServiceID;
typedef struct vt_ILxScene2Service ** ILxScene2ServiceID;
typedef struct vt_ILxScene ** ILxSceneID;
typedef struct vt_ILxItem ** ILxItemID;
typedef struct vt_ILxSceneGraph ** ILxSceneGraphID;
typedef struct vt_ILxItemGraph ** ILxItemGraphID;
typedef struct vt_ILxChannelGraph ** ILxChannelGraphID;
#include <lxvalue.h>
#include <lxvmath.h>

typedef int              LXtItemType;
#define LXiTYPE_ANY      -1
#define LXiTYPE_NONE      0
typedef unsigned        LXtTransformType;

#define LXiXFRM_SCALE           0
#define LXiXFRM_ROTATION        1
#define LXiXFRM_POSITION        2
#define LXiXFRM_PIVOT           3
#define LXiXFRM_PIVOT_C         4
#define LXiXFRM_SHEAR           5
#define LXiXFRM_PIVOT_ROT       6
#define LXiXFRM_PIVOT_ROT_C     7

typedef struct vt_ILxSceneService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        Root) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD( unsigned,
        ItemTypeCount) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        ItemTypeByIndex) (
                LXtObjectID              self,
                unsigned                 index,
                LXtItemType             *type);
                LXxMETHOD( LxResult,
        ItemTypeLookup) (
                LXtObjectID              self,
                const char              *name,
                LXtItemType             *type);
                LXxMETHOD( LxResult,
        ItemTypeName) (
                LXtObjectID              self,
                LXtItemType              type,
                const char             **name);
                LXxMETHOD( LxResult,
        ItemTypeTest) (
                LXtObjectID              self,
                LXtItemType              what,
                LXtItemType              isA);
                LXxMETHOD( LxResult,
        ItemTypeSuper) (
                LXtObjectID              self,
                LXtItemType              type,
                LXtItemType             *super);
                LXxMETHOD( LxResult,
        ItemTypeCommonChannels) (
                LXtObjectID              self,
                LXtObjectID              item1,
                LXtObjectID              item2,
                unsigned                *count);
                LXxMETHOD( LxResult,
        ItemSubTypeCount) (
                LXtObjectID              self,
                LXtItemType              type,
                unsigned int            *count);

                LXxMETHOD( LxResult,
        ItemSubTypeByIndex) (
                LXtObjectID              self,
                LXtItemType              type,
                unsigned int             index,
                const char             **subtype);
                LXxMETHOD( LxResult,
        ChannelVectorSize) (
                LXtObjectID              self,
                unsigned int             mode,
                unsigned int            *size);
                LXxMETHOD( LxResult,
        ChannelVectorTextHints) (
                LXtObjectID              self,
                const LXtTextValueHint **hints);
                LXxMETHOD(  LxResult,
        CreateScene) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        DestroyScene) (
                LXtObjectID              self,
                LXtObjectID              scene);
                LXxMETHOD(  LxResult,
        SubSceneAdd) (
                LXtObjectID              self,
                LXtObjectID              scene,
                LXtObjectID              other,
                unsigned                 refItems);
                LXxMETHOD(  LxResult,
        SubSceneLoad) (
                LXtObjectID              self,
                LXtObjectID              scene,
                const char              *path,
                LXtObjectID              monitor,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        GetMeshInstSourceItem) (
                LXtObjectID              self,
                LXtObjectID              inst,
                void                   **ppvObj);
                LXxMETHOD(  int,
        MeshInstanceCount) (
                LXtObjectID              self,
                LXtObjectID              mesh);
                LXxMETHOD(  LxResult,
        MeshInstanceByIndex) (
                LXtObjectID              self,
                LXtObjectID              mesh,
                int                      index,
                void                   **ppvObj);
                LXxMETHOD( LxResult,
        LoadImage) (
                LXtObjectID              self,
                LXtObjectID              scene,
                const char              *name,
                unsigned                *flags,
                LXtObjectID              monitor,
                void                   **ppvObj);
                LXxMETHOD( LxResult,
        GetReplicatorEnumerator) (
                LXtObjectID              self,
                LXtObjectID              replicatorItem,
                void                   **ppvObj);
                LXxMETHOD( LxResult,
        ItemTypeGetTag) (
                LXtObjectID              self,
                LXtItemType              type,
                const char              *tag,
                unsigned                 super,
                const char             **value);
} ILxSceneService;
typedef struct vt_ILxScene2Service {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        Root) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        LoadImage) (
                LXtObjectID              self,
                LXtObjectID              scene,
                const char              *name,
                unsigned                *flags,
                LXtObjectID              monitor,
                void                   **ppvObj);

                LXxMETHOD( unsigned,
        ItemTypeCount) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        ItemTypeByIndex) (
                LXtObjectID              self,
                unsigned                 index,
                LXtItemType             *type);

                LXxMETHOD( LxResult,
        ItemTypeLookup) (
                LXtObjectID              self,
                const char              *name,
                LXtItemType             *type);

                LXxMETHOD( LxResult,
        ItemTypeName) (
                LXtObjectID              self,
                LXtItemType              type,
                const char             **name);

                LXxMETHOD( LxResult,
        ItemTypeTest) (
                LXtObjectID              self,
                LXtItemType              what,
                LXtItemType              isA);

                LXxMETHOD( LxResult,
        ItemTypeSuper) (
                LXtObjectID              self,
                LXtItemType              type,
                LXtItemType             *super);

                LXxMETHOD( LxResult,
        ItemTypeCommonChannels) (
                LXtObjectID              self,
                LXtObjectID              item1,
                LXtObjectID              item2,
                unsigned                *count);

                LXxMETHOD( LxResult,
        ItemSubTypeCount) (
                LXtObjectID              self,
                LXtItemType              type,
                unsigned int            *count);

                LXxMETHOD( LxResult,
        ItemSubTypeByIndex) (
                LXtObjectID              self,
                LXtItemType              type,
                unsigned int             index,
                const char             **subtype);

                LXxMETHOD( LxResult,
        ChannelVectorSize) (
                LXtObjectID              self,
                unsigned int             mode,
                unsigned int            *size);

                LXxMETHOD( LxResult,
        ChannelVectorTextHints) (
                LXtObjectID              self,
                const LXtTextValueHint **hints);

                LXxMETHOD(  LxResult,
        SubSceneAdd) (
                LXtObjectID              self,
                LXtObjectID              scene,
                LXtObjectID              other,
                unsigned                 refItems);

                LXxMETHOD(  LxResult,
        SubSceneLoad) (
                LXtObjectID              self,
                LXtObjectID              scene,
                const char              *path,
                LXtObjectID              monitor,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        Import) (
                LXtObjectID              self,
                LXtObjectID              scene,
                const char              *path,
                LXtObjectID              monitor);

                LXxMETHOD(  LxResult,
        WorldTransform) (
                LXtObjectID              self,
                LXtObjectID              locator,
                double                   time,
                LXtMatrix                xfrm,
                LXtVector                pos);

                LXxMETHOD(  LxResult,
        GetTransformItem) (
                LXtObjectID              self,
                LXtObjectID              locator,
                LXtTransformType         type,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        AddTransformItem) (
                LXtObjectID              self,
                LXtObjectID              locator,
                LXtTransformType         type,
                void                   **ppvObj,
                unsigned                *index);

                LXxMETHOD(  LxResult,
        SetTransformVector) (
                LXtObjectID              self,
                LXtObjectID              locator,
                LXtObjectID              chanWrite,
                LXtTransformType         type,
                LXtVector                value);

                LXxMETHOD(  LxResult,
        AddPreTransformItem) (
                LXtObjectID              self,
                LXtObjectID              locator,
                LXtObjectID              chanWrite,
                LXtTransformType         type,
                LXtVector                value,
                void                   **ppvObj,
                unsigned                *index);

                LXxMETHOD(  LxResult,
        AddPostTransformItem) (
                LXtObjectID              self,
                LXtObjectID              locator,
                LXtObjectID              chanWrite,
                LXtTransformType         type,
                LXtVector                value,
                void                   **ppvObj,
                unsigned                *index);

                LXxMETHOD(  LxResult,
        GetMeshInstSourceItem) (
                LXtObjectID              self,
                LXtObjectID              inst,
                void                   **ppvObj);

                LXxMETHOD(  int,
        MeshInstanceCount) (
                LXtObjectID              self,
                LXtObjectID              mesh);

                LXxMETHOD(  LxResult,
        MeshInstanceByIndex) (
                LXtObjectID              self,
                LXtObjectID              mesh,
                int                      index,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        SetTarget) (
                LXtObjectID              self,
                LXtObjectID              locator,
                LXtObjectID              target,
                void                    **ppvObj);

                LXxMETHOD(  LxResult,
        PrependTransformItem) (
                LXtObjectID              self,
                LXtObjectID              locator,
                LXtObjectID              chanWrite,
                LXtTransformType         type,
                LXtVector                value,
                void                   **ppvObj,
                unsigned                *index);

                LXxMETHOD(  LxResult,
        AppendTransformItem) (
                LXtObjectID              self,
                LXtObjectID              locator,
                LXtObjectID              chanWrite,
                LXtTransformType         type,
                LXtVector                value,
                void                   **ppvObj,
                unsigned                *index);
} ILxScene2Service;
typedef struct vt_ILxScene {
        ILxUnknown       iunk;
                LXxMETHOD(  LXtItemType,
        ItemRootType) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        Filename) (
                LXtObjectID              self,
                const char             **filename);
                LXxMETHOD(  LxResult,
        FriendlyFilename) (
                LXtObjectID              self,
                unsigned                 flags,
                const char             **filename);
                LXxMETHOD(  LxResult,
        FileFormat) (
                LXtObjectID              self,
                const char             **format);
                LXxMETHOD(  LxResult,
        Changed) (
                LXtObjectID              self,
                unsigned                 changed);
                LXxMETHOD(  LxResult,
        HasChanged) (
                LXtObjectID              self,
                unsigned int            *numChanges);
                LXxMETHOD(  LxResult,
        Parent) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        SubSceneCount) (
                LXtObjectID              self,
                LXtItemType              type,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        SubSceneByIndex) (
                LXtObjectID              self,
                LXtItemType              type,
                unsigned int             index,
                void                   **ppvObj);
                LXxMETHOD(  unsigned,
        LoadFlags) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        Channels) (
                LXtObjectID              self,
                const char              *name,
                double                   time,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ItemCount) (
                LXtObjectID              self,
                LXtItemType              type,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        ItemByIndex) (
                LXtObjectID              self,
                LXtItemType              type,
                unsigned int             index,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ItemLookup) (
                LXtObjectID              self,
                const char              *id,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ItemCountByTypes) (
                LXtObjectID              self,
                const LXtItemType       *types,
                unsigned                *count);

                LXxMETHOD(  LxResult,
        ItemByIndexByTypes) (
                LXtObjectID              self,
                const LXtItemType       *types,
                unsigned                 index,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        AnyItemOfType) (
                LXtObjectID              self,
                LXtItemType              type,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ItemLocalize) (
                LXtObjectID              self,
                LXtObjectID              item,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ItemAdd) (
                LXtObjectID              self,
                LXtItemType              type,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ItemDuplicate) (
                LXtObjectID              self,
                LXtObjectID              item,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ItemAddReference) (
                LXtObjectID              self,
                LXtObjectID              item,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        GraphLookup) (
                LXtObjectID              self,
                const char              *name,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        GraphCount) (
                LXtObjectID              self,
                int                     *count);

                LXxMETHOD(  LxResult,
        GraphByIndex) (
                LXtObjectID              self,
                unsigned                 index,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ItemRemove) (
                LXtObjectID              self,
                LXtObjectID              item);
                LXxMETHOD(  LxResult,
        Import) (
                LXtObjectID              self,
                const char              *path,
                LXtObjectID              monitor);
                LXxMETHOD(  LxResult,
        EvalModInvalidate) (
                LXtObjectID              self,
                const char              *modName);
                LXxMETHOD(  LxResult,
        EvalModReset) (
                LXtObjectID              self,
                const char              *modName);
                LXxMETHOD(  LxResult,
        ItemReplace) (
                LXtObjectID              self,
                LXtObjectID              item,
                int                      type,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        SetupMode) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        SetupChannels) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ItemLookupIdent) (
                LXtObjectID              self,
                const char              *id,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ItemLookupImported) (
                LXtObjectID              self,
                const char              *id,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        RenderCameraCount) (
                LXtObjectID              self,
                int                     *count);
                LXxMETHOD(  LxResult,
        RenderCameraByIndex) (
                LXtObjectID              self,
                int                      index,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        RenderCameraIndex) (
                LXtObjectID              self,
                LXtObjectID              eval,
                int                     *index);
} ILxScene;
typedef struct vt_ILxItem {
        ILxUnknown       iunk;
                LXxMETHOD(  LXtItemType,
        Type) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        TestType) (
                LXtObjectID              self,
                LXtItemType              type);

                LXxMETHOD(  LxResult,
        TestTypes) (
                LXtObjectID              self,
                const LXtItemType       *types);
                LXxMETHOD(  LxResult,
        Ident) (
                LXtObjectID              self,
                const char             **ident);
                LXxMETHOD(  LxResult,
        SetIdent) (
                LXtObjectID              self,
                const char              *ident);
                LXxMETHOD(  LxResult,
        Name) (
                LXtObjectID              self,
                const char             **name);

                LXxMETHOD(  LxResult,
        SetName) (
                LXtObjectID              self,
                const char              *name);
                LXxMETHOD(  LxResult,
        UniqueName) (
                LXtObjectID              self,
                const char             **name);
                LXxMETHOD(  LxResult,
        UniqueIndex) (
                LXtObjectID              self,
                unsigned                *index);
                LXxMETHOD(  LxResult,
        SetUniqueIndex) (
                LXtObjectID              self,
                unsigned                 index);
                LXxMETHOD( LxResult,
        Parent) (
                LXtObjectID              self,
                void                    **ppvObj);
                LXxMETHOD( LxResult,
        SetParent) (
                LXtObjectID              self,
                LXtObjectID              parent);
                LXxMETHOD(  LxResult,
        SubCount) (
                LXtObjectID              self,
                unsigned                *count);

                LXxMETHOD(  LxResult,
        SubByIndex) (
                LXtObjectID              self,
                unsigned                 index,
                void                   **ppvObj);
                LXxMETHOD( LxResult,
        Root) (
                LXtObjectID              self,
                void                    **ppvObj);
                LXxMETHOD( LxResult,
        Context) (
                LXtObjectID              self,
                void                    **ppvObj);
                LXxMETHOD( LxResult,
        Reference) (
                LXtObjectID              self,
                void                    **ppvObj);
                LXxMETHOD( LxResult,
        IsReferenced) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Source) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        SetSource) (
                LXtObjectID              self,
                LXtObjectID              source);
                LXxMETHOD(  LxResult,
        ChannelCount) (
                LXtObjectID              self,
                unsigned                *count);
                LXxMETHOD(  LxResult,
        ChannelLookup) (
                LXtObjectID              self,
                const char              *name,
                unsigned                *index);
                LXxMETHOD(  LxResult,
        ChannelName) (
                LXtObjectID              self,
                unsigned                 index,
                const char              **name);
                LXxMETHOD(  LxResult,
        ChannelType) (
                LXtObjectID              self,
                unsigned                 index,
                unsigned                *type);
                LXxMETHOD(  LxResult,
        ChannelVectorMode) (
                LXtObjectID              self,
                unsigned                 index,
                unsigned                *mode,
                unsigned                *components);
                LXxMETHOD(  LxResult,
        ChannelStorageType) (
                LXtObjectID              self,
                unsigned                 index,
                const char              **type);
                LXxMETHOD(  LxResult,
        ChannelEvalType) (
                LXtObjectID              self,
                unsigned                 index,
                const char              **type);
                LXxMETHOD(  LxResult,
        ChannelGradient) (
                LXtObjectID              self,
                unsigned                 index,
                const char             **input,
                const char             **output);
                LXxMETHOD(  LxResult,
        ChannelIntHint) (
                LXtObjectID              self,
                unsigned                 index,
                const LXtTextValueHint **hints);
                LXxMETHOD(  LxResult,
        ChannelPackage) (
                LXtObjectID              self,
                unsigned                 index,
                const char             **package);
                LXxMETHOD(  LxResult,
        PackageAdd) (
                LXtObjectID              self,
                const char              *package);
                LXxMETHOD(  LxResult,
        PackageTest) (
                LXtObjectID              self,
                const char              *package);
                LXxMETHOD(  LxResult,
        PackageStartIndex) (
                LXtObjectID              self,
                const char              *package,
                unsigned                *index);
                LXxMETHOD(  LxResult,
        PackageRemove) (
                LXtObjectID              self,
                const char              *package);
                LXxMETHOD(  LxResult,
        ChannelAdd) (
                LXtObjectID              self,
                int                      whatever);
                LXxMETHOD(  const char *,
        GetTag) (
                LXtObjectID              self,
                LXtID4                   type);
                LXxMETHOD(  LxResult,
        SetTag) (
                LXtObjectID              self,
                LXtID4                   type,
                const char              *tag);
                LXxMETHOD(  void,
        InvalidateName) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        WasLoaded) (
                LXtObjectID              self,
                unsigned                 test);
} ILxItem;
typedef struct vt_ILxSceneGraph {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Name) (
                LXtObjectID              self,
                const char             **name);
                LXxMETHOD(  LxResult,
        Context) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        RootCount) (
                LXtObjectID              self,
                int                     *count);

                LXxMETHOD(  LxResult,
        RootByIndex) (
                LXtObjectID              self,
                int                      index,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        RootFirst) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        RootNext) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        RootSetPos) (
                LXtObjectID              self,
                LXtObjectID              item,
                int                      pos);
                LXxMETHOD(  LxResult,
        RootRemove) (
                LXtObjectID              self,
                LXtObjectID              item);
} ILxSceneGraph;
typedef struct vt_ILxItemGraph {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        AddLink) (
                LXtObjectID              self,
                LXtObjectID              from,
                LXtObjectID              to);
                LXxMETHOD( LxResult,
        SetLink) (
                LXtObjectID              self,
                LXtObjectID              from,
                int                      fromIndex,
                LXtObjectID              to,
                int                      toIndex);
                LXxMETHOD( LxResult,
        DeleteLink) (
                LXtObjectID              self,
                LXtObjectID              from,
                LXtObjectID              to);
                LXxMETHOD( LxResult,
        FwdCount) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                *count);

                LXxMETHOD( LxResult,
        FwdByIndex) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                 index,
                void                   **ppvObj);
                LXxMETHOD( LxResult,
        RevCount) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                *count);

                LXxMETHOD( LxResult,
        RevByIndex) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                 index,
                void                   **ppvObj);
} ILxItemGraph;
typedef struct vt_ILxChannelGraph {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        AddLink) (
                LXtObjectID              self,
                LXtObjectID              from,
                int                      fromChan,
                LXtObjectID              to,
                int                      toChan);

                LXxMETHOD( LxResult,
        SetLink) (
                LXtObjectID              self,
                LXtObjectID              from,
                int                      fromChan,
                int                      fromIndex,
                LXtObjectID              to,
                int                      toChan,
                int                      toIndex);

                LXxMETHOD( LxResult,
        DeleteLink) (
                LXtObjectID              self,
                LXtObjectID              from,
                int                      fromChan,
                LXtObjectID              to,
                int                      toChan);

                LXxMETHOD( LxResult,
        FwdCount) (
                LXtObjectID              self,
                LXtObjectID              item,
                int                      channel,
                unsigned                *count);

                LXxMETHOD( LxResult,
        FwdByIndex) (
                LXtObjectID              self,
                LXtObjectID              item,
                int                      channel,
                unsigned                 index,
                void                   **ppvObj,
                int                     *objChan);

                LXxMETHOD( LxResult,
        RevCount) (
                LXtObjectID              self,
                LXtObjectID              item,
                int                      channel,
                unsigned                *count);

                LXxMETHOD( LxResult,
        RevByIndex) (
                LXtObjectID              self,
                LXtObjectID              item,
                int                      channel,
                unsigned                 index,
                void                   **ppvObj,
                int                     *objChan);
} ILxChannelGraph;

#define LXa_SCENESERVICE        "sceneservice3"
#define LXu_SCENESERVICE        "50190141-0059-48FE-B27D-6C98E1348D7B"
// [python] ILxSceneService:CreateScene                 obj Scene
// [python] ILxSceneService:GetMeshInstSourceItem       obj Item
// [python] ILxSceneService:GetReplicatorEnumerator     obj ReplicatorEnumerator (particle)
// [python] ILxSceneService:LoadImage                   obj Unknown
// [python] ILxSceneService:MeshInstanceByIndex         obj Item
// [python] ILxSceneService:Root                        obj Scene
// [python] ILxSceneService:SubSceneLoad                obj Scene
// [python] ILxSceneService:ItemTypeTest                bool
// [python] ILxSceneService:LoadImage:flags             vector
#define LXf_LOADIMG_SEARCH_PATHS        1
#define LXf_LOADIMG_USER_REPLACE        2
#define LXa_SCENE2SERVICE       "sceneservice2"
#define LXu_SCENE2SERVICE       "3B1E02DD-8ACA-4f30-99C4-F87B626D4FA3"
// [const] ILxScene2Service:Root
// [const] ILxScene2Service:ItemTypeCount
// [const] ILxScene2Service:ItemTypeByIndex
// [const] ILxScene2Service:ItemTypeLookup
// [const] ILxScene2Service:ItemTypeName
// [const] ILxScene2Service:ItemTypeTest
// [const] ILxScene2Service:ItemTypeSuper
// [const] ILxScene2Service:ItemTypeCommonChannels
// [const] ILxScene2Service:ItemSubTypeCount
// [const] ILxScene2Service:ItemSubTypeByIndex
// [const] ILxScene2Service:ChannelVectorSize
// [const] ILxScene2Service:ChannelVectorTextHints
// [const] ILxScene2Service:WorldTransform
// [const] ILxScene2Service:MeshInstanceCount
// [const] ILxScene2Service:MeshInstanceByIndex
#define LXu_SCENE               "FF870F44-FED9-4dbc-95BA-2972A43FC936"
#define LXa_SCENE               "scene2"
// [local]  ILxScene
// [const]  ILxScene:Channels
// [const]  ILxScene:SetupChannels
// [const]  ILxScene:ItemCount
// [const]  ILxScene:ItemByIndex
// [const]  ILxScene:ItemLookup
// [const]  ILxScene:ItemCountByTypes
// [const]  ILxScene:ItemByIndexByTypes
// [const]  ILxScene:AnyItemOfType
// [const]  ILxScene:GraphLookup
// [const]  ILxScene:GraphCount
// [const]  ILxScene:GraphByIndex
// [const]  ILxScene:RenderCameraCount
// [const]  ILxScene:RenderCameraByIndex
// [const]  ILxScene:RenderCameraIndex
// [python] ILxScene:SubSceneByIndex            obj Scene
// [python] ILxScene:Channels                   obj ChannelRead (action)
// [python] ILxScene:SetupChannels              obj ChannelRead
// [python] ILxScene:GraphByIndex               obj SceneGraph
// [python] ILxScene:GraphLookup                obj SceneGraph
// [python] ILxScene:AnyItemOfType              obj Item
// [python] ILxScene:ItemAdd                    obj Item
// [python] ILxScene:ItemAddReference           obj Item
// [python] ILxScene:ItemByIndex                obj Item
// [python] ILxScene:RenderCameraByIndex        obj Item
// [python] ILxScene:ItemDuplicate              obj Item
// [python] ILxScene:ItemLocalize               obj Item
// [python] ILxScene:ItemLookup                 obj Item
// [python] ILxScene:ItemLookupIdent            obj Item
// [python] ILxScene:ItemLookupImported         obj Item
// [python] ILxScene:ItemByIndexByTypes         obj Item
// [python] ILxScene:ItemReplace                obj Item
// [python] ILxScene:Parent                     obj Item
// [python] ILxScene:SetupMode                  bool
#define LXfSCENENAME_STAR        1
#define LXfSCENENAME_SHORT       2
#define LXa_ITEM                "item"
#define LXu_ITEM                "7FF2D6D5-5E28-4650-93ED-89FF257F9629"
// [local]  ILxItem
// [const]  ILxItem:PackageTest
// [const]  ILxItem:ChannelCount
// [const]  ILxItem:ChannelLookup
// [const]  ILxItem:ChannelName
// [const]  ILxItem:ChannelIntHint
// [const]  ILxItem:Ident
// [python] ILxItem:TestType            bool
// [python] ILxItem:TestTypes           bool
// [python] ILxItem:IsReferenced        bool
// [python] ILxItem:PackageTest         bool
// [python] ILxItem:WasLoaded           bool
// [python] ILxItem:Context     obj Scene
// [python] ILxItem:Parent      obj Item
// [python] ILxItem:Reference   obj Item
// [python] ILxItem:Root        obj Item
// [python] ILxItem:Source      obj Item
// [python] ILxItem:SubByIndex  obj Item
#define LXiCHANTYPE_NONE         0
#define LXiCHANTYPE_INTEGER      1
#define LXiCHANTYPE_FLOAT        2
#define LXiCHANTYPE_GRADIENT     3
#define LXiCHANTYPE_STORAGE      4
#define LXiCHANTYPE_EVAL         5
#define LXiCHANMODE_SCALAR       0
#define LXiCHANMODE_XY           1
#define LXiCHANMODE_XYZ          2
#define LXiCHANMODE_RGB          3
#define LXiCHANMODE_RGBA         4
#define LXfITEMLOAD_IMPORT      0x01
#define LXfITEMLOAD_CURRENT     0x02
#define LXa_SCENEGRAPH          "scenegraph"
#define LXu_SCENEGRAPH          "FE07D3C5-C7E4-46af-8F0A-5AB173D48445"
// [local]  ILxSceneGraph
// [python] ILxSceneGraph:Context       obj Scene
// [python] ILxSceneGraph:RootByIndex   obj Item
// [python] ILxSceneGraph:RootFirst     obj Item
// [python] ILxSceneGraph:RootNext      obj Item
#define LXa_ITEMGRAPH           "itemgraph"
#define LXu_ITEMGRAPH           "C34D7C65-031A-4c9d-8C01-3187D383937B"
// [local]  ILxItemGraph
// [python] ILxItemGraph:FwdByIndex     obj Item
// [python] ILxItemGraph:RevByIndex     obj Item
#define LXa_CHANNELGRAPH        "channelgraph"
#define LXu_CHANNELGRAPH        "F70C8AD7-C15F-42e7-98F6-4C4C7F6D577E"
// [local]  ILxChannelGraph
// [python] ILxChannelGraph:FwdByIndex  obj Item
// [python] ILxChannelGraph:RevByIndex  obj Item

 #ifdef __cplusplus
  }
 #endif
#endif

