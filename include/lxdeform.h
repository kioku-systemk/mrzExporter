/*
 * LX dfrm module
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
#ifndef LX_dfrm_H
#define LX_dfrm_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxFalloff ** ILxFalloffID;
typedef struct vt_ILxDeformation ** ILxDeformationID;
typedef struct vt_ILxDeformer ** ILxDeformerID;
typedef struct vt_ILxMeshInfluence ** ILxMeshInfluenceID;
typedef struct vt_ILxItemInfluence ** ILxItemInfluenceID;
typedef struct vt_ILxGroupDeformer ** ILxGroupDeformerID;
typedef struct vt_ILxWeightMapDeformerItem ** ILxWeightMapDeformerItemID;
typedef struct vt_ILxDeformerService ** ILxDeformerServiceID;
#include <lxmesh.h>

typedef void *           LXtDeformElt;

// [python] type LXtDeformElt   id
// [python] type LXtPointID     id

typedef struct vt_ILxFalloff {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Bounds) (
                LXtObjectID              self,
                LXtBBox                 *box);

                LXxMETHOD( float,
        WeightF) (
                LXtObjectID              self,
                const LXtFVector         position);

                LXxMETHOD( LxResult,
        WeightRun) (
                LXtObjectID              self,
                const float            **pos,
                float                   *weight,
                unsigned                 num);
} ILxFalloff;
typedef struct vt_ILxDeformation {
        ILxUnknown       iunk;
                LXxMETHOD( unsigned,
        Flags) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Transform) (
                LXtObjectID              self,
                LXtMatrix4               xfrm);
                LXxMETHOD( void,
        OffsetF) (
                LXtObjectID              self,
                const LXtFVector         position,
                float                    weight,
                LXtFVector               offset);

                LXxMETHOD( void,
        OBSOLETE) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        OffsetRun) (
                LXtObjectID              self,
                const float            **pos,
                const float             *weight,
                float                  **offset,
                unsigned                 num);
} ILxDeformation;
typedef struct vt_ILxDeformer {
        ILxUnknown       iunk;
                LXxMETHOD( unsigned,
        Flags) (
                LXtObjectID              self);
                LXxMETHOD( unsigned,
        PartitionCount) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        EnumeratePartition) (
                LXtObjectID              self,
                LXtObjectID              visitor,
                unsigned                 part);
                LXxMETHOD( LXtDeformElt,
        Element) (
                LXtObjectID              self,
                unsigned                *segment);
                LXxMETHOD( LxResult,
        SetPartition) (
                LXtObjectID              self,
                unsigned                 part);
                LXxMETHOD( float,
        Weight) (
                LXtObjectID              self,
                LXtDeformElt             elt,
                const LXtFVector         pos);

                LXxMETHOD( void,
        Offset) (
                LXtObjectID              self,
                LXtDeformElt             elt,
                float                    weight,
                const LXtFVector         pos,
                LXtFVector               offset);
                LXxMETHOD( LxResult,
        WeightRun) (
                LXtObjectID              self,
                unsigned                 segment,
                const LXtDeformElt      *elt,
                const float            **pos,
                float                   *weight,
                unsigned                 num);

                LXxMETHOD( LxResult,
        OffsetRun) (
                LXtObjectID              self,
                unsigned                 segment,
                const LXtDeformElt      *elt,
                const float            **pos,
                const float             *weight,
                float                  **offset,
                unsigned                 num);
} ILxDeformer;
typedef struct vt_ILxMeshInfluence {
        ILxUnknown       iunk;
                LXxMETHOD( unsigned,
        MeshCount) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        MeshByIndex) (
                LXtObjectID              self,
                unsigned                 index,
                void                   **ppvObj);
                LXxMETHOD( unsigned,
        PartitionIndex) (
                LXtObjectID              self,
                unsigned                 index);
                LXxMETHOD( LxResult,
        SetMesh) (
                LXtObjectID              self,
                unsigned                 index,
                LXtObjectID              mesh,
                LXtObjectID              item);

                LXxMETHOD( LxResult,
        SetTransform) (
                LXtObjectID              self,
                unsigned                 index,
                LXtMatrix4               xfrm);

                LXxMETHOD( LxResult,
        MeshChange) (
                LXtObjectID              self,
                unsigned                 index,
                LxResult                 change);
} ILxMeshInfluence;
typedef struct vt_ILxItemInfluence {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        HasItems) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Enumerate) (
                LXtObjectID              self,
                LXtObjectID              visitor);

                LXxMETHOD( LxResult,
        GetItem) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        AllowTransform) (
                LXtObjectID              self,
                unsigned                 index,
                unsigned                *flags);
} ILxItemInfluence;
typedef struct vt_ILxGroupDeformer {
        ILxUnknown       iunk;
                LXxMETHOD( unsigned,
        DeformerCount) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        DeformerByIndex) (
                LXtObjectID              self,
                unsigned                 index,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        PointEffect) (
                LXtObjectID              self,
                unsigned                 meshIndex,
                LXtPointID               point,
                unsigned                *deformer,
                float                   *weight,
                unsigned                *count,
                unsigned                 max);
} ILxGroupDeformer;
typedef struct vt_ILxWeightMapDeformerItem {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        GetMapName) (
                LXtObjectID              self,
                LXtObjectID              chanRead,
                char                    *buf,
                unsigned                 len);

                LXxMETHOD( LxResult,
        GetColor) (
                LXtObjectID              self,
                LXtObjectID              chanRead,
                LXtVector                col);
} ILxWeightMapDeformerItem;
typedef struct vt_ILxDeformerService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        DeformerFlags) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                *flags);

                LXxMETHOD(  LxResult,
        DeformerChannel) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                *index);
                LXxMETHOD(  LxResult,
        MergeChangeState) (
                LXtObjectID              self,
                LxResult                 c1,
                LxResult                 c2);
                LXxMETHOD(  LxResult,
        MeshCount) (
                LXtObjectID              self,
                LXtObjectID              defItem,
                unsigned                *count);

                LXxMETHOD(  LxResult,
        MeshByIndex) (
                LXtObjectID              self,
                LXtObjectID              defItem,
                unsigned                 index,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        GroupDeformer) (
                LXtObjectID              self,
                LXtObjectID              dgroup,
                LXtObjectID              chanRead,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        DeformerDeformationItem) (
                LXtObjectID              self,
                LXtObjectID              defItem,
                void                   **ppvObj);
                LXxMETHOD(  void,
        InvalidateTargets) (
                LXtObjectID              self,
                LXtObjectID              scene);
                LXxMETHOD(  LXtDeformElt,
        ItemToDeformElt) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD(  LXtObjectID,
        DeformEltToItem) (
                LXtObjectID              self,
                LXtDeformElt             elt);
} ILxDeformerService;

#define LXu_FALLOFF             "B7D1DEF8-1F45-4924-B518-E2F2A76D0259"
// [export]  ILxFalloff fall
// [local]   ILxFalloff
#define LXsITYPE_FALLOFF                "falloff"

#define LXsICHAN_FALLOFF_FALLOFF        "falloffObj"
#define LXsICHAN_FALLOFF_DEFORMER       "deformerObj"
#define LXsICHAN_FALLOFF_FALLENAB       "enableFalloff"
#define LXsICHAN_FALLOFF_DEFORMENAB     "enableDeform"
#define LXsICHAN_FALLOFF_STRENGTH       "strength"
#define LXsICHAN_FALLOFF_INVERT         "invert"
#define LXfDEFORMATION_NONLINEAR         0x01
#define LXfDEFORMATION_RIGIDXFRM         0x02
#define LXu_DEFORMATION         "F5705327-7382-47C5-8D7B-AF2CC18B3E8A"
// [export]  ILxDeformation deform
// [local]   ILxDeformation
// [default] ILxDeformation:Flags = 0
#define LXsPKG_DEFORMATION_CHANNEL      "deformation.channel"
#define LXsPKG_DEFORMER_CHANNEL         "deformer.channel"
#define LXsPKG_DEFORMER_FLAGS           "deformer.flags"
#define LXsPKG_DEFORMER_CREATECMD       "deformer.create"
#define LXfDEFORMER_NO_WEIGHT   0x01
#define LXfDEFORMER_NO_OFFSET   0x02
#define LXfDEFORMER_REQ_WEIGHT  0x08
#define LXfDEFORMER_REQ_OFFSET  0x10
#define LXfDEFORMER_IS_FALLOFF  0x20
#define LXfDEFORMER_USE_LINEAR  0x100
#define LXu_DEFORMER            "F029A563-A937-4DB2-992E-1592081F64CC"
// [export]  ILxDeformer dinf
// [local]   ILxDeformer
// [default] ILxDeformer:Weight = 1
// [default] ILxDeformer:PartitionCount = 0
#define LXeDEFORM_IDENTICAL     LXeEVAL_IDENTICAL
#define LXeDEFORM_NEWOFFSET     LXxGOODCODE(LXeSYS_DEFORM,21)
#define LXeDEFORM_NEWWEIGHT     LXxGOODCODE(LXeSYS_DEFORM,22)
#define LXeDEFORM_DIFFERENT     LXeEVAL_DIFFERENT
#define LXu_MESHINFLUENCE       "D70AA410-75BB-480E-90E2-17E2059EB40B"
// [export]  ILxMeshInfluence minf
// [local]   ILxMeshInfluence
// [default] ILxMeshInfluence:MeshCount = 0
// [default] ILxMeshInfluence:PartitionIndex = index
// [python]  ILxMeshInfluence:MeshByIndex       obj Item
#define LXu_ITEMINFLUENCE       "2141BD0B-DEFC-4A92-A4A5-30760C09F18B"
// [export]  ILxItemInfluence iinf
// [local]   ILxItemInfluence
// [python]  ILxItemInfluence:GetItem   obj Item
// [python]  ILxItemInfluence:HasItems  bool

#define LXfITEMINF_POSITION      0x01
#define LXfITEMINF_ROTATION      0x02
#define LXfITEMINF_SCALE         0x04
#define LXfITEMINF_PROBEWEIGHTS  0x08
#define LXsITYPE_DEFORMGROUP                    "deformGroup"

#define LXsICHAN_DEFORMGROUP_DEFORMER           "deformObj"
#define LXsICHAN_DEFORMGROUP_ENABLE             "enable"
#define LXsICHAN_DEFORMGROUP_INTERPOLATION      "interpolation"
#define LXsICHAN_DEFORMGROUP_LIMITENABLE        "limitEnable"
#define LXsICHAN_DEFORMGROUP_LIMITMAX           "limitMax"
#define LXsICHAN_DEFORMGROUP_THRESHOLD          "threshold"
#define LXsICHAN_DEFORMGROUP_SHARPNESS          "sharpness"

#define LXsICVAL_DEFORMGROUP_INTERPOLATION_LOCAL        "local"
#define LXsICVAL_DEFORMGROUP_INTERPOLATION_LINEAR       "linear"
#define LXsICVAL_DEFORMGROUP_INTERPOLATION_DQS          "dqs"
#define LXu_GROUPDEFORMER       "4BC04F3F-29FC-4EA3-B090-10280331C757"
// [local]   ILxGroupDeformer
// [python]  ILxGroupDeformer:DeformerByIndex   obj Item
// [python]  ILxGroupDeformer:PointEffect:deformer      vector
// [python]  ILxGroupDeformer:PointEffect:weight        vector
#define LXsITYPE_DEFORMFOLDER           "deformFolder"

#define LXsICHAN_DEFORMFOLDER_ENABLE    "enable"
#define LXu_WEIGHTMAPDEFORMERITEM       "A9C81E0B-20F0-4D8B-838B-B593EAF3DFB8"
// [export]  ILxWeightMapDeformerItem wmd
// [local]   ILxWeightMapDeformerItem
// [default] ILxWeightMapDeformerItem:GetColor = LXeDEFORM_AUTO_COLOR

#define LXeDEFORM_AUTO_COLOR    LXxGOODCODE(LXeSYS_DEFORM, 12)
#define LXsITYPE_ITEMINFLUENCE                  "itemInfluence"

#define LXsICHAN_ITEMINFLUENCE_ITEMINF          "itemInf"
#define LXsICHAN_ITEMINFLUENCE_ENABLE           "enable"
#define LXsICHAN_ITEMINFLUENCE_INTERPOLATION    "interpolation"
#define LXsICHAN_ITEMINFLUENCE_POSENABLE        "posEnable"
#define LXsICHAN_ITEMINFLUENCE_ROTENABLE        "rotEnable"
#define LXsICHAN_ITEMINFLUENCE_SCLENABLE        "sclEnable"
#define LXsICHAN_ITEMINFLUENCE_SAMPLEWEIGHT     "sampleWeight"

#define LXsICVAL_ITEMINFLUENCE_INTERPOLATION_LOCAL      "local"
#define LXsICVAL_ITEMINFLUENCE_INTERPOLATION_LINEAR     "linear"
#define LXa_DEFORMERSERVICE     "deformerservice"
#define LXu_DEFORMERSERVICE     "8267068C-FDBB-430A-8230-BE64F72CE3E3"
// [python] ILxDeformerService:DeformerDeformationItem  obj item
// [python] ILxDeformerService:GroupDeformer    obj GroupDeformer
// [python] ILxDeformerService:MeshByIndex      obj Item (item)

 #ifdef __cplusplus
  }
 #endif
#endif

