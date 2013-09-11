/*
 * LX surface module
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
#ifndef LX_surface_H
#define LX_surface_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxSurfaceItem ** ILxSurfaceItemID;
typedef struct vt_ILxSurface ** ILxSurfaceID;
typedef struct vt_ILxSurfaceBin ** ILxSurfaceBinID;
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
                LXtVector                pos,
                LXtVector                dir,
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
                LXtVector                pos,
                LXtVector                dir,
                LXtBBox                 *bbox);
} ILxSurfaceBin;

#define LXa_SURFACEITEM "surfaceItem"
#define LXu_SURFACEITEM "65EC0E0E-FFD7-48a3-9E20-62EA82EF4728"
// [export] ILxSurfaceItem isurf
// [local]  ILxSurfaceItem
#define LXa_SURFACE     "surface"
#define LXu_SURFACE     "75006BDB-93F7-4a41-8B8C-E710D80D3F1A"
// [export] ILxSurface surf
// [local]  ILxSurface
#define LXa_SURFACEBIN  "surfaceBin"
#define LXu_SURFACEBIN  "48B534C1-7B7C-4147-ADBC-154850898E7F"
// [export] ILxSurfaceBin surfBin
// [local]  ILxSurfaceBin

 #ifdef __cplusplus
  }
 #endif
#endif

