/*
 * LX surface module
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
#ifndef LX_surface_H
#define LX_surface_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxSurfaceItem ** ILxSurfaceItemID;
typedef struct vt_ILxSurface ** ILxSurfaceID;
typedef struct vt_ILxSurfaceBin ** ILxSurfaceBinID;
typedef struct vt_ILxCurveGroup ** ILxCurveGroupID;
typedef struct vt_ILxCurve ** ILxCurveID;
#include <lxshade.h>


typedef struct st_LXtRayInfo {
        LXtVector                pos;
        LXtVector                dir;
        unsigned                 cull;
        unsigned                 half;
        const char              *vmapName;
        LXtID4                   vmapType;
} LXtRayInfo;
typedef struct st_LXtRayHit {
        LXtVector                pos;
        LXtVector                nrm;
        LXtVector                uvw;
        double                   dist;
        void                    *bin;
} LXtRayHit;
typedef struct vt_ILxSurfaceItem {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        GetSurface) (
                LXtObjectID              self,
                LXtObjectID              chanRead,
                unsigned                 morph,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        Prepare) (
                LXtObjectID              self,
                LXtObjectID              eval,
                unsigned                *index);

                LXxMETHOD( LxResult,
        Evaluate) (
                LXtObjectID              self,
                LXtObjectID              attr,
                unsigned                 index,
                void                   **ppvObj);
} ILxSurfaceItem;
typedef struct vt_ILxSurface {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        GetBBox) (
                LXtObjectID              self,
                LXtBBox                 *bbox);

                LXxMETHOD(  LxResult,
        FrontBBox) (
                LXtObjectID              self,
                const LXtVector          pos,
                const LXtVector          dir,
                LXtBBox                 *bbox); 

                LXxMETHOD(  LxResult,
        RayCast) (
                LXtObjectID              self,
                const LXtRayInfo        *ray,
                LXtRayHit               *hit);

                LXxMETHOD(  LxResult,
        BinCount) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD( LxResult,
        BinByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        TagCount) (
                LXtObjectID              self,
                LXtID4                   type,
                unsigned int            *count);

                LXxMETHOD( LxResult,
        TagByIndex) (
                LXtObjectID              self,
                LXtID4                   type,
                unsigned int             index,
                const char              **stag);

                LXxMETHOD( LxResult,
        GLCount) (
                LXtObjectID              self,
                unsigned int            *count);        
} ILxSurface;
typedef struct vt_ILxSurfaceBin {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        GetBBox) (
                LXtObjectID              self,
                LXtBBox                 *bbox);

                LXxMETHOD(  LxResult,
        FrontBBox) (
                LXtObjectID              self,
                const LXtVector          pos,
                const LXtVector          dir,
                LXtBBox                 *bbox);
} ILxSurfaceBin;
typedef struct vt_ILxCurveGroup {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        GetBBox) (
                LXtObjectID              self,
                LXtBBox                 *bbox);

                LXxMETHOD(  LxResult,
        Count) (
                LXtObjectID              self,
                unsigned                *count);

                LXxMETHOD(  LxResult,
        ByIndex) (
                LXtObjectID              self,
                unsigned                 index,
                void                   **ppvObj);
} ILxCurveGroup;
typedef struct vt_ILxCurve {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        GetBBox) (
                LXtObjectID              self,
                LXtBBox                 *bbox);

                LXxMETHOD(  double,
        Length) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        SplineCount) (
                LXtObjectID              self,
                unsigned                *count);

                LXxMETHOD(  LxResult,
        SplineByIndex) (
                LXtObjectID              self,
                unsigned                 index,
                LXtVector                b0,
                LXtVector                b1,
                LXtVector                b2,
                LXtVector                b3);
                LXxMETHOD(  unsigned,
        BendCount) (
                LXtObjectID              self);
                LXxMETHOD(  double,
        Param) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        SetParam) (
                LXtObjectID              self,
                double                   param);

                LXxMETHOD(  LxResult,
        SetLenFraction) (
                LXtObjectID              self,
                double                   frac);
                LXxMETHOD(  LxResult,
        Position) (
                LXtObjectID              self,
                LXtVector                pos);

                LXxMETHOD(  LxResult,
        Tangent) (
                LXtObjectID              self,
                LXtVector                tan);
                LXxMETHOD(  LxResult,
        Closest) (
                LXtObjectID              self,
                const LXtVector          probe,
                double                  *param,
                LXtVector                pos,
                LXtVector                norm);
} ILxCurve;

#define LXa_SURFACEITEM "surfaceItem"
#define LXu_SURFACEITEM "65EC0E0E-FFD7-48a3-9E20-62EA82EF4728"
// [export] ILxSurfaceItem isurf
// [local]  ILxSurfaceItem
// [python] ILxSurfaceItem:Evaluate     obj Surface
// [python] ILxSurfaceItem:GetSurface   obj Surface
#define LXa_SURFACE     "surface"
#define LXu_SURFACE     "75006BDB-93F7-4a41-8B8C-E710D80D3F1A"
// [export] ILxSurface surf
// [local]  ILxSurface
// [python] ILxSurface:BinByIndex       obj SurfaceBin
#define LXa_SURFACEBIN  "surfaceBin"
#define LXu_SURFACEBIN  "48B534C1-7B7C-4147-ADBC-154850898E7F"
// [export] ILxSurfaceBin surfBin
// [local]  ILxSurfaceBin
#define LXu_CURVEGROUP          "20F1B298-84E2-4DA2-BA66-8883B4B0D7FF"
// [export] ILxCurveGroup cgrp
// [local]  ILxCurveGroup
// [python] ILxCurveGroup:ByIndex       obj Curve

#define LXsPKG_CURVES_CHANNEL   "curveGroup.channel"

#define LXu_CURVE               "9DDF4A43-691F-4F30-8986-B52FD1D96E34"
// [export] ILxCurve curve
// [local]  ILxCurve

 #ifdef __cplusplus
  }
 #endif
#endif

