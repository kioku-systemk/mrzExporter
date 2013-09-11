/*
 * LX shdr module
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
#ifndef LX_shdr_H
#define LX_shdr_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxShaderService ** ILxShaderServiceID;
typedef struct vt_ILxShader ** ILxShaderID;
#include <lxvmath.h>
#include <lxcom.h>
#include <lxmesh.h>



typedef struct vt_ILxShaderService {
        ILxUnknown       iunk;
                LXxMETHOD(  float,
        ComputeFresnel) (
                LXtObjectID              self,
                LXtFVector               inRay,
                LXtFVector               normalRay,
                float                    normReflAmt);
                LXxMETHOD(  float,
        ScalarBlendValue) (
                LXtObjectID              self,
                float                    v1,
                float                    v2,
                float                    opa,
                int                      mode);

                LXxMETHOD(  void,
        ColorBlendValue) (
                LXtObjectID              self,
                LXtFVector               c,
                LXtFVector               c1,
                LXtFVector               c2,
                float                    opa,
                int                      mode);
                LXxMETHOD(  void,
        SquareToCircle) (
                LXtObjectID              self,
                float                   *x,
                float                   *y);
                LXxMETHOD(                LxResult,
        MeshShaderAccessor) (
                LXtObjectID               self,
                LXtObjectID               meshItem,
                void                    **ppvObj);

                LXxMETHOD(                LxResult,
        PolyShaderAccessor) (
                LXtObjectID               self,
                LXtObjectID               meshItem,
                LXtPolygonID              polyID,
                void                    **ppvObj);
} ILxShaderService;
typedef struct vt_ILxShader {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Enumerate) (
                LXtObjectID              self,
                LXtObjectID              visitor);
                LXxMETHOD(  LxResult,
        Spawn) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ShaderItemGet) (
                LXtObjectID               self,
                void                    **ppvObj);
} ILxShader;

#define LXu_SHADERSERVICE        "0b4e73ac-9325-4920-afcc-7814953a26b6"
#define LXa_SHADERSERVICE        "shaderservice"
//[local] ILxShaderService
//[const] ILxShaderService:ComputeFresnel
//[const] ILxShaderService:ScalarBlend
//[const] ILxShaderService:ColorBlend
//[const] ILxShaderService:SquareToCircle
#define LXa_SHADER      "shader"
#define LXu_SHADER      "051ba6d8-46ba-4722-8b07-943961c3aeda"
// [local]  ILxShader

 #ifdef __cplusplus
  }
 #endif
#endif

