/*
 * LX cache module
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
#ifndef LX_cache_H
#define LX_cache_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxEvaluationStack ** ILxEvaluationStackID;
typedef struct vt_ILxStackFilter ** ILxStackFilterID;
#include <lxcom.h>



typedef struct vt_ILxEvaluationStack {
        ILxUnknown       iunk;
                LXxMETHOD( const char *,
        Type) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Branch) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        AddFilter) (
                LXtObjectID              self,
                LXtObjectID              filter);
} ILxEvaluationStack;
typedef struct vt_ILxStackFilter {
        ILxUnknown       iunk;
                LXxMETHOD( const char *,
        Type) (
                LXtObjectID                      self);

                LXxMETHOD( unsigned,
        Compare) (
                LXtObjectID                      self,
                LXtObjectID                      other);

                LXxMETHOD( LxResult,
        Convert) (
                LXtObjectID                      self,
                LXtObjectID                      other);
} ILxStackFilter;

#define LXsSTACK_IMAGE           "imageStack"
#define LXsSTACK_MESH            "meshStack"
#define LXsSTACK_SHADER          "shaderStack"
#define LXsSTACK_TEXTURE         "textureStack"
#define LXsSTACK_TXTRLOC         "txtrlocStack"
#define LXsSTACK_GRADIENT        "gradientStack"
#define LXsSTACK_PARTICLE        "particleStack"
#define LXu_EVALUATIONSTACK     "47F3BF05-B64A-49D9-A2C1-08B0D36AB787"
// [local]  ILxEvaluationStack
#define LXiSTACK_DIFFERENT       0
#define LXiSTACK_COMPATIBLE      1
#define LXiSTACK_IDENTICAL       2

#define LXu_STACKFILTER         "B79CF5D3-C630-401B-82A5-AD866BC05B6F"
// [local]   ILxStackFilter
// [export]  ILxStackFilter filt
// [default] ILxStackFilter:Compare = LXiSTACK_DIFFERENT

 #ifdef __cplusplus
  }
 #endif
#endif

