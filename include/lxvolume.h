/*
 * LX volume module
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
#ifndef LX_volume_H
#define LX_volume_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxRaymarch ** ILxRaymarchID;
#include <lxtableau.h>


typedef struct st_LXtVolumeSample {
        double          dist;
        double          color[3];
        double          opacity[3];
        double          stride;
} LXtVolumeSample;
typedef struct st_LXtSurfFragment {
        double          dist;
        double          color[3];
        double          transparency[3];
} LXtSurfFragment;
typedef struct vt_ILxRaymarch {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        AddVolume) (
                LXtObjectID              self,
                LXtObjectID              vector,
                LXtVolumeSample         *vs);

                LXxMETHOD(  LxResult,
        AddSurface) (
                LXtObjectID              self,
                LXtObjectID              vector,
                LXtSurfFragment         *ss);

                LXxMETHOD(  LxResult,
        GetOpacity) (
                LXtObjectID              self,
                LXtObjectID              vector,
                double                   dist,
                double                  *opa);

                LXxMETHOD(  LxResult,
        ShaderEvaluate) (
                LXtObjectID              self,
                LXtObjectID              vector,
                LXtObjectID              shader);

                LXxMETHOD(  LxResult,
        Jitter1D) (
                LXtObjectID              self,
                LXtObjectID              vector,
                float                   *offset);
} ILxRaymarch;

#define LXu_RAYMARCH            "1E84C5A8-C002-4120-BAB0-9EEB1722688B"
#define LXa_RAYMARCH            "raymarch"
#define LXsP_RAYMARCH           "raymarch"
//[local]  ILxRaymarch
//[export] ILxRaymarch rmrch

 #ifdef __cplusplus
  }
 #endif
#endif

