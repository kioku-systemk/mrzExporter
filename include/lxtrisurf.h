/*
 * LX tsurf module
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
#ifndef LX_tsurf_H
#define LX_tsurf_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxTriangleSurface ** ILxTriangleSurfaceID;
typedef struct vt_ILxTriangleGroup ** ILxTriangleGroupID;
#include <lxcom.h>



typedef struct vt_ILxTriangleSurface {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        SetSize) (
                LXtObjectID              self,
                unsigned                 nvrt,
                unsigned                 ntri);

                LXxMETHOD(  LxResult,
        AddVector) (
                LXtObjectID              self,
                LXtID4                   type,
                const char              *name,
                unsigned                *index);

                LXxMETHOD(  float *,
        SetVector) (
                LXtObjectID              self,
                unsigned                 index,
                unsigned                 vrt);

                LXxMETHOD(  unsigned *,
        SetTriangle) (
                LXtObjectID              self,
                unsigned                 tri);

                LXxMETHOD(  unsigned *,
        FixNormals) (
                LXtObjectID              self);

                LXxMETHOD(  void,
        GetSize) (
                LXtObjectID              self,
                unsigned                *nvrt,
                unsigned                *ntri);

                LXxMETHOD(  unsigned *,
        Triangles) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        VectorInfo) (
                LXtObjectID              self,
                unsigned                 index,
                LXtID4                  *type,
                const char             **name,
                unsigned                *dim);

                LXxMETHOD(  float *,
        Vector) (
                LXtObjectID              self,
                unsigned                 index);
} ILxTriangleSurface;
typedef struct vt_ILxTriangleGroup {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        AddSurface) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        GetSurface) (
                LXtObjectID              self,
                unsigned                 index,
                void                   **ppvObj);
} ILxTriangleGroup;

#define LXsTYPE_TRIGROUP        "tgroup"
#define LXu_TRIANGLESURFACE     "B1D985A7-34D6-4251-94AA-EEFB2C7527F9"
#define LXu_TRIANGLEGROUP       "6975B2A4-69E8-4ED2-9058-9C0948CBB43C"
// [local]  ILxTriangleSurface
// [local]  ILxTriangleGroup
// [python] ILxTriangleGroup:AddSurface         obj TriangleSurface
// [python] ILxTriangleGroup:GetSurface         obj TriangleSurface

 #ifdef __cplusplus
  }
 #endif
#endif

