/*
 * LX predest module
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
#ifndef LX_predest_H
#define LX_predest_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxShaderPreDest ** ILxShaderPreDestID;
typedef struct vt_ILxMeshLayerPreDest ** ILxMeshLayerPreDestID;
typedef struct vt_ILxSceneItemPreDest ** ILxSceneItemPreDestID;
typedef struct vt_ILxProfile1DPreDest ** ILxProfile1DPreDestID;
typedef struct vt_ILxProfile2DPreDest ** ILxProfile2DPreDestID;
typedef struct vt_ILxColorPreDest ** ILxColorPreDestID;
typedef struct vt_ILxFileSysDest ** ILxFileSysDestID;
#include <lxcom.h>
#include <lxresult.h>
#include <lxvalue.h>
#include <lxvector.h>
#include <lxitem.h>



typedef struct vt_ILxShaderPreDest {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Scene) (
                LXtObjectID               self,
                void                    **ppvObj);
                LXxMETHOD( LxResult,
        Item) (
                LXtObjectID               self,
                int                      *mode,
                void                    **ppvObj);
                LXxMETHOD( LxResult,
        ContainerItem) (
                LXtObjectID               self,
                void                    **ppvObj);
                LXxMETHOD( LxResult,
        HitItem) (
                LXtObjectID               self,
                void                    **ppvObj);
                LXxMETHOD( LxResult,
        GetTag) (
                LXtObjectID              self,
                LXtID4                   type,
                const char             **tag);
                LXxMETHOD( LxResult,
        Mode) (
                LXtObjectID              self,
                int                     *mode);
} ILxShaderPreDest;
typedef struct vt_ILxMeshLayerPreDest {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Mesh) (
                LXtObjectID               self,
                void                    **ppvObj);
                LXxMETHOD( LxResult,
        Transform) (
                LXtObjectID              self,
                LXtMatrix4               xform);
                LXxMETHOD( LxResult,
        ShaderDest) (
                LXtObjectID               self,
                void                    **ppvObj);
} ILxMeshLayerPreDest;
typedef struct vt_ILxSceneItemPreDest {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Scene) (
                LXtObjectID               self,
                void                    **ppvObj);
                LXxMETHOD( LxResult,
        Item) (
                LXtObjectID               self,
                int                      *mode,
                void                    **ppvObj);
                LXxMETHOD( LxResult,
        ContainerItem) (
                LXtObjectID               self,
                void                    **ppvObj);
                LXxMETHOD( LxResult,
        Position) (
                LXtObjectID               self,
                LXtVector                 pos);
                LXxMETHOD( LxResult,
        Orientation) (
                LXtObjectID               self,
                LXtMatrix                 xfrm);
} ILxSceneItemPreDest;
typedef struct vt_ILxProfile1DPreDest {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        MoveTo) (
                LXtObjectID              self,
                double                   x,
                double                   y);
                LXxMETHOD( LxResult,
        LineTo) (
                LXtObjectID              self,
                double                   x,
                double                   y);
                LXxMETHOD( LxResult,
        CurveTo) (
                LXtObjectID              self,
                double                   x0,
                double                   y0,
                double                   x1,
                double                   y1,
                double                   x2,
                double                   y2);
                LXxMETHOD( double,
        Evaluate) (
                LXtObjectID              self,
                double                   t,
                int                      flags,
                int                      axis);
                LXxMETHOD( int,
        PathSteps) (
                LXtObjectID              self,
                double                   tol,
                int                      flags,
                double                  *x,
                double                  *y,
                int                      nstep);
                LXxMETHOD( LxResult,
        Box) (
                LXtObjectID              self,
                LXtBBox                 *box);
} ILxProfile1DPreDest;
typedef struct vt_ILxProfile2DPreDest {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        MoveTo) (
                LXtObjectID              self,
                double                   x,
                double                   y);
                LXxMETHOD( LxResult,
        LineTo) (
                LXtObjectID              self,
                double                   x,
                double                   y);
                LXxMETHOD( LxResult,
        CurveTo) (
                LXtObjectID              self,
                double                   x0,
                double                   y0,
                double                   x1,
                double                   y1,
                double                   x2,
                double                   y2);
                LXxMETHOD( LxResult,
        NewPath) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Closed) (
                LXtObjectID              self,
                int                      closed);
                LXxMETHOD( LxResult,
        Box) (
                LXtObjectID              self,
                LXtBBox                 *box);
} ILxProfile2DPreDest;
typedef struct vt_ILxColorPreDest {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        SetColor) (
                LXtObjectID              self,
                const double            *rgb);
                LXxMETHOD( LxResult,
        SetColorModel) (
                LXtObjectID              self,
                const char              *name,
                const double            *vec);
                LXxMETHOD( LxResult,
        Apply) (
                LXtObjectID              self);
} ILxColorPreDest;
typedef struct vt_ILxFileSysDest {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Path) (
                LXtObjectID               self,
                const char              **path);
                LXxMETHOD( LxResult,
        IsDir) (
                LXtObjectID               self);
                LXxMETHOD( LxResult,
        AsDir) (
                LXtObjectID               self,
                const char              **dir);
} ILxFileSysDest;

#define LXu_SHADERPREDEST               "51CE68B9-BDED-41FC-BD33-37BBAFFD180B"
#define LXa_SHADERPREDEST               "shaderPresetDestination"
// [local]  ILxShaderPreDest
// [export] ILxShaderPreDest spd
// [python] ILxShaderPreDest:ContainerItem      obj Item
// [python] ILxShaderPreDest:HitItem            obj Item
// [python] ILxShaderPreDest:Item               obj Item
// [python] ILxShaderPreDest:Scene              obj Scene
#define LXu_MESHLAYERPREDEST    "052B08CD-F2F2-4C0F-9D32-1AAFEF494D36"
#define LXa_MESHLAYERPREDEST    "meshPresetDestination"
// [local]  ILxMeshLayerPreDest
// [export] ILxMeshLayerPreDest mlpd
// [python] ILxMeshLayerPreDest:Mesh            obj Mesh
// [python] ILxMeshLayerPreDest:ShaderDest      obj ShaderPreDest
#define         LXSHPRE_MODEi_ADD       0
#define         LXSHPRE_MODEi_APPLY     1
#define LXu_SCENEITEMPREDEST            "F81AD9DB-6068-4782-B1BB-7F45233682DC"
#define LXa_SCENEITEMPREDEST            "sceneItemPresetDestination"
// [local]  ILxSceneItemPreDest
// [export] ILxSceneItemPreDest sipd
// [python] ILxSceneItemPreDest:ContainerItem   obj Item
// [python] ILxSceneItemPreDest:Item            obj Item
// [python] ILxSceneItemPreDest:Scene           obj Scene
#define LXu_PHOTOMETRYPREDEST           "C64CB56A-16EA-4B4D-96EC-B6911459103A"
#define LXa_PHOTOMETRYPREDEST           "photometryPresetDestination"
#define LXu_PROFILE1DPREDEST            "A4E5FAD3-E3A7-4ed9-A1E3-4EB0D31A4187"
#define LXa_PROFILE1DPREDEST            "profile1DPresetDestination"
// [local]  ILxProfile1DPreDest
// [export] ILxProfile1DPreDest p1pd

#define LXu_PROFILE2DPREDEST            "F845F4AD-7DFC-4a41-98D1-0FFB2CA744FB"
#define LXa_PROFILE2DPREDEST            "profile2DPresetDestination"
// [local]  ILxProfile2DPreDest
// [export] ILxProfile2DPreDest p2pd
#define         LXPROFILEf_NORMALIZE    0x1
#define         LXPROFILEf_RESETZERO    0x2
#define LXu_COLORPREDEST                "307b5aab-f8df-4c5b-b916-223172ea921e"
#define LXa_COLORPREDEST                "colorPresetDestination"
//[local]  ILxColorPreDest
//[export] ILxColorPreDest colpd
#define LXu_FILESYSDEST         "79d4f661-3249-4455-bfb9-486120c18f24"
#define LXa_FILESYSDEST         "fileSystemDestination"
//[local]  ILxFileSysDest
//[export] ILxFileSysDest fsysd
#define LXu_BRUSHTOOLPRESET             "D03E22CE-970E-4CC1-BF76-A74639624647"
#define LXa_BRUSHTOOLPRESET             "brushToolPreset"

 #ifdef __cplusplus
  }
 #endif
#endif

