/*
 * LX env module
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
#ifndef LX_env_H
#define LX_env_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxEnvelope ** ILxEnvelopeID;
typedef struct vt_ILxKeyframe ** ILxKeyframeID;
typedef struct vt_ILxGradientFilter ** ILxGradientFilterID;
#include <lxcom.h>

typedef enum en_LXtEndBehavior {
        LXiENV_RESET,
        LXiENV_CONSTANT,
        LXiENV_REPEAT,
        LXiENV_OSCILLATE,
        LXiENV_OFFSETREPEAT,
        LXiENV_LINEAR,
        LXiENV_NONE
} LXtEndBehavior;
typedef enum en_LXtSlopeType {
        LXiSLOPE_DIRECT,
        LXiSLOPE_AUTO,
        LXiSLOPE_LINEAR_IN,
        LXiSLOPE_LINEAR_OUT,
        LXiSLOPE_FLAT,
        LXiSLOPE_AUTOFLAT,
        LXiSLOPE_STEPPED
} LXtSlopeType;

typedef struct vt_ILxEnvelope {
        ILxUnknown       iunk;
                LXxMETHOD( unsigned,
        IsInt) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Enumerator) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        EvaluateF) (
                LXtObjectID              self,
                double                   time,
                double                  *value);

                LXxMETHOD( LxResult,
        EvaluateI) (
                LXtObjectID              self,
                double                   time,
                int                     *value);

                LXxMETHOD( unsigned int,
        EndBehavior) (
                LXtObjectID              self,
                unsigned int             side);

                LXxMETHOD( LxResult,
        SetEndBehavior) (
                LXtObjectID              self,
                unsigned int             behavior,
                unsigned int             side);

                LXxMETHOD( LxResult,
        Clear) (
                LXtObjectID              self);

                LXxMETHOD( unsigned int,
        Interpolation) (
                LXtObjectID              self);
} ILxEnvelope;
typedef struct vt_ILxKeyframe {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        First) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Last) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Next) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Previous) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Find) (
                LXtObjectID              self,
                double                   time,
                unsigned int             side);
                LXxMETHOD( LxResult,
        GetTime) (
                LXtObjectID              self,
                double                  *time);
                LXxMETHOD( LxResult,
        GetBroken) (
                LXtObjectID              self,
                unsigned int            *breaks,
                unsigned int            *side);
                LXxMETHOD( LxResult,
        GetValueF) (
                LXtObjectID              self,
                double                  *value,
                unsigned int             side);

                LXxMETHOD( LxResult,
        GetValueI) (
                LXtObjectID              self,
                int                     *value,
                unsigned int             side);
                LXxMETHOD( LxResult,
        GetSlopeType) (
                LXtObjectID              self,
                LXtSlopeType            *type,
                unsigned int            *weighted,
                unsigned int             side);

                LXxMETHOD( LxResult,
        GetSlope) (
                LXtObjectID              self,
                double                  *slope,
                unsigned int             side);

                LXxMETHOD( LxResult,
        GetWeight) (
                LXtObjectID              self,
                double                  *weight,
                unsigned int             side);
                LXxMETHOD( LxResult,
        SetTime) (
                LXtObjectID              self,
                double                   time);
                LXxMETHOD( LxResult,
        SetValueF) (
                LXtObjectID              self,
                double                   value,
                unsigned int             side);

                LXxMETHOD( LxResult,
        SetValueI) (
                LXtObjectID              self,
                int                      value,
                unsigned int             side);

                LXxMETHOD( LxResult,
        SetSlope) (
                LXtObjectID              self,
                double                   slope,
                unsigned int             side);

                LXxMETHOD( LxResult,
        SetSlopeType) (
                LXtObjectID              self,
                LXtSlopeType             type,
                unsigned int             side);
                LXxMETHOD( LxResult,
        SetWeight) (
                LXtObjectID              self,
                double                   weight,
                unsigned int             reset,
                unsigned int             side);
                LXxMETHOD( LxResult,
        AddF) (
                LXtObjectID              self,
                double                   time,
                double                   value);

                LXxMETHOD( LxResult,
        AddI) (
                LXtObjectID              self,
                double                   time,
                int                      value);
                LXxMETHOD( LxResult,
        Delete) (
                LXtObjectID              self);
} ILxKeyframe;
typedef struct vt_ILxGradientFilter {
        ILxUnknown       iunk;
                LXxMETHOD( double,
        Evaluate) (
                LXtObjectID              self,
                double                   inVal);
} ILxGradientFilter;

#define LXu_ENVELOPE            "E39EB451-6C35-47F4-8A7D-FF96671C0DEF"
#define LXu_KEYFRAME            "D1D0261F-22CF-4E5D-822E-76B5DEC98AE4"
// [local]  ILxEnvelope
// [local]  ILxKeyframe
#define LXiENVSIDE_IN                   1
#define LXiENVSIDE_OUT                  2
#define LXiENVSIDE_BOTH                 3

#define LXiENVv_INTERP_CURVE            0
#define LXiENVv_INTERP_LINEAR           1
#define LXiENVv_INTERP_STEPPED          2

#define LXfKEYBREAK_VALUE               (1<<0)
#define LXfKEYBREAK_SLOPE               (1<<1)
#define LXfKEYBREAK_WEIGHT              (1<<2)

#define LXu_GRADIENTFILTER      "ACCD7C33-D246-4FE5-ABA0-079F225BBB34"
// [local]  ILxGradientFilter

 #ifdef __cplusplus
  }
 #endif
#endif

