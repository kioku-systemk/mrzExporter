/*
 * LX raycast module
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
#ifndef LX_raycast_H
#define LX_raycast_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxRaycast ** ILxRaycastID;
#include <lxtableau.h>


typedef struct st_LXpPixelGeometry {
        LXtFVector               nrm;
        LXtFVector               wpos;
        LXtFVector               opos;
        float                    dist;
        void                    *gsrf;
} LXpPixelGeometry;
typedef struct vt_ILxRaycast {
        ILxUnknown       iunk;
                LXxMETHOD(  ILxUnknownID,
        RayPush) (
                LXtObjectID              self,
                LXtObjectID              vector);

                LXxMETHOD(  LxResult,
        RayPop) (
                LXtObjectID              self,
                LXtObjectID              vector);

                LXxMETHOD(  float,
        Raycast) (
                LXtObjectID              self,
                LXtObjectID              vector,
                const LXtVector          pos,
                const LXtFVector         dir);

                LXxMETHOD(  float,
        Raytrace) (
                LXtObjectID              self,
                LXtObjectID              vector,
                const LXtVector          pos,
                const LXtFVector         dir,
                int                      flags);

                LXxMETHOD( LxResult,
        InternalShade) (
                LXtObjectID              self,
                LXtObjectID              vector);

                LXxMETHOD(  int,
        LightCount) (
                LXtObjectID              self,
                LXtObjectID              vector);

                LXxMETHOD(  LxResult,
        LightSampleCount) (
                LXtObjectID              self,
                LXtObjectID              vector,
                const LXtVector          pos,
                const LXtFVector         nrm,
                int                     *num);

                LXxMETHOD(  int,
        LightShadowType) (
                LXtObjectID              self,
                LXtObjectID              vector,
                int                      lgtIndex);

                LXxMETHOD(  int,
        LightSampleCountByLight) (
                LXtObjectID              self,
                LXtObjectID              vector,
                int                      lgtIndex);

                LXxMETHOD(  LxResult,
        LightSampleByIndex) (
                LXtObjectID              self,
                LXtObjectID              vector,
                int                      index,
                LXpLightColor           *lCol,
                float                   *dot);

                LXxMETHOD(  LxResult,
        LightValue) (
                LXtObjectID              self,
                LXtObjectID              vector,
                int                      lgtIndex,
                LXtFVector              *color,
                float                   *intensity);

                LXxMETHOD(  LxResult,
        GetNextShadowRay) (
                LXtObjectID              self,
                LXtObjectID              vector,
                int                      lgtIndex,
                LXtVector                pos,
                LXtFVector              *dir,
                int                     *flags);

                LXxMETHOD(  LxResult,
        GetNextGIRaySphere) (
                LXtObjectID              self,
                LXtObjectID              vector,
                LXtFVector              *dir,
                int                     *flags);

                LXxMETHOD(  LxResult,
        GetNextGIRayHemisphere) (
                LXtObjectID              self,
                LXtObjectID              vector,
                LXtFVector              *dir,
                int                     *flags);

                LXxMETHOD(  LxResult,
        GetSurfaceID) (
                LXtObjectID              self,
                LXtObjectID              vector,
                void                     **id);

                LXxMETHOD(  LxResult,
        PixelToRay) (
                LXtObjectID              self,
                LXtObjectID              vector,
                int                      mode,
                float                    x,
                float                    y,
                LXpSampleRay            *sRay);

                LXxMETHOD(  LxResult,
        PixelGeometry) (
                LXtObjectID              self,
                LXtObjectID              vector,
                int                      mode,
                float                    x,
                float                    y,
                LXpPixelGeometry        *pGeo); 

                LXxMETHOD(  LxResult,
        PoissonOffset) (
                LXtObjectID              self,
                LXtObjectID              vector,
                float                   *u,
                float                   *v);    

                LXxMETHOD(  LxResult,
        Irradiance) (
                LXtObjectID              self,
                LXtObjectID              vector,
                const LXtVector          pos,
                const LXtFVector         nrm,
                LXtFVector               lum);  

                LXxMETHOD(  LxResult,
        GetBucketGlobalBounce) (
                LXtObjectID              self,
                LXtObjectID              vector,
                int                      *globBounce);

                LXxMETHOD(  LxResult,
        GetBucketPixel) (
                LXtObjectID              self,
                LXtObjectID              vector,
                int                      *x,
                int                      *y);

                LXxMETHOD(  LxResult,
        GetBucketSubPixel) (
                LXtObjectID              self,
                LXtObjectID              vector,
                float                    *x,
                float                    *y);

                LXxMETHOD(  LxResult,
        GetBucketTimeOffset) (
                LXtObjectID              self,
                LXtObjectID              vector,
                float                    *tOffset);

                LXxMETHOD(  int,
        GetSurfaceType) (
                LXtObjectID              self,
                LXtObjectID              vector);

                LXxMETHOD(  LxResult,
        GetLightSampleDirection) (
                LXtObjectID              self,
                LXtObjectID              vector,
                int                      lgtIndex,
                LXtVector                pos,
                LXtFVector              *dir);
} ILxRaycast;

#define LXi_PIXELRAY_RELATIVE   0
#define LXi_PIXELRAY_ABSOLUTE   1
#define LXu_RAYCAST             "7B13E5D2-D0D9-427A-A1D4-6DAEB192B8B0"
#define LXa_RAYCAST             "raycast"
#define LXsP_RAYCAST            "raycast"
//[local]  ILxRaycast
//[const]  ILxRaycast:LightCount
//[const]  ILxRaycast:LightSampleCountByLight
//[const]  ILxRaycast:LightShadowType
#define RAY_EPSILON      (1.0e-12)
#define RAY_BIAS         (1.0e-5)

 #ifdef __cplusplus
  }
 #endif
#endif

