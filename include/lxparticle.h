/*
 * LX psys module
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
#ifndef LX_psys_H
#define LX_psys_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxParticleItem ** ILxParticleItemID;
typedef struct vt_ILxReplicatorEnumerator ** ILxReplicatorEnumeratorID;
typedef struct vt_ILxParticleEvalFrame ** ILxParticleEvalFrameID;
typedef struct vt_ILxParticleFilter ** ILxParticleFilterID;
typedef struct vt_ILxParticleFilterItem ** ILxParticleFilterItemID;



typedef struct st_LXpDynaForce {
        LXtFVector       dir;
        float            amplitude;
        float            drag;
} LXpDynaForce;
typedef struct st_LXpAnimDeform {
        LXtFVector       dir;
        float            amplitude;
} LXpAnimDeform;
typedef struct st_LXpSampleFalloff {
        float            value;
} LXpSampleFalloff;
typedef struct vt_ILxParticleItem {
        ILxUnknown       iunk;
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
} ILxParticleItem;
typedef struct vt_ILxReplicatorEnumerator {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Enumerate) (
                LXtObjectID              self,
                LXtObjectID              visitor,
                LXtObjectID              chan,
                int                      localXform);

                LXxMETHOD(  LxResult,
        Item) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  void,
        Position) (
                LXtObjectID              self,
                LXtVector                pos);

                LXxMETHOD(  void,
        Orientation) (
                LXtObjectID              self,
                LXtMatrix                mx);

                LXxMETHOD(  float,
        Id) (
                LXtObjectID              self);

                LXxMETHOD(  float,
        Dissolve) (
                LXtObjectID              self);
} ILxReplicatorEnumerator;
typedef struct vt_ILxParticleEvalFrame {
        ILxUnknown       iunk;
                LXxMETHOD( LXtObjectID,
        VertexDescription) (
                LXtObjectID              self);
                LXxMETHOD( unsigned,
        MaxCount) (
                LXtObjectID              self);

                LXxMETHOD( unsigned,
        AliveCount) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        AddParticle) (
                LXtObjectID              self,
                const float             *state,
                unsigned                *index);
                LXxMETHOD( LxResult,
        KillParticle) (
                LXtObjectID              self,
                unsigned                 index);
                LXxMETHOD( unsigned,
        IsAlive) (
                LXtObjectID              self,
                unsigned                 index);
                LXxMETHOD( LxResult,
        GetVector) (
                LXtObjectID              self,
                unsigned                 index,
                float                   *vector);

                LXxMETHOD( LxResult,
        SetVector) (
                LXtObjectID              self,
                unsigned                 index,
                const float             *vector);
                LXxMETHOD( LxResult,
        AliveRun) (
                LXtObjectID              self,
                unsigned                 first,
                const unsigned         **alive,
                unsigned                *count);

                LXxMETHOD( LxResult,
        VectorRun) (
                LXtObjectID              self,
                unsigned                 first,
                float                  **values,
                unsigned                *count);
} ILxParticleEvalFrame;
typedef struct vt_ILxParticleFilter {
        ILxUnknown       iunk;
                LXxMETHOD( LXtObjectID,
        Vertex) (
                LXtObjectID              self);
                LXxMETHOD( unsigned,
        Type) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Initialize) (
                LXtObjectID              self,
                LXtObjectID              vertex,
                LXtObjectID              frame,
                double                   time);
                LXxMETHOD( LxResult,
        Step) (
                LXtObjectID              self,
                LXtObjectID              other,
                double                   dt);
                LXxMETHOD( void,
        Cleanup) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Frame) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Run) (
                LXtObjectID              self,
                float                  **values,
                unsigned                 count);
                LXxMETHOD( LxResult,
        Particle) (
                LXtObjectID              self,
                float                   *vertex);
} ILxParticleFilter;
typedef struct vt_ILxParticleFilterItem {
        ILxUnknown       iunk;
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
} ILxParticleFilterItem;

#define LXu_PARTICLEITEM        "BA13DD5D-5093-4D0D-BEFE-119AD4F1FACB"
// [export] ILxParticleItem prti
// [local]  ILxParticleItem
#define LXsPARTICLEATTR_SEED    "seed"
#define LXsPARTICLEATTR_USEPOL  "usePol"
#define LXsPARTICLEATTR_UPAXIS  "upAxis"
#define LXsPARTICLEATTR_DEFORM  "deform"
#define LXu_REPLICATORENUMERATOR        "01EC90A9-924F-4475-BA6A-FFF8A2691CD5"
//[local]  ILxReplicatorEnumerator
#define LXu_PARTICLEEVALFRAME   "1AC26263-A422-4B17-A929-2F616037754F"
// [local]  ILxParticleEvalFrame
#define LXi_PFILT_FRAME          0
#define LXi_PFILT_RUN            1
#define LXi_PFILT_PARTICLE       2
#define LXi_PFILT_NEW_PARTICLE   3
#define LXu_PARTICLEFILTER      "04A3C0C5-1C5C-43F5-8559-ACF3BAE79C0B"
// [export] ILxParticleFilter pfilt
// [local]  ILxParticleFilter
#define LXu_PARTICLEFILTERITEM  "EF31BA82-8EC4-46C5-9A28-2785BE78D861"
// [export] ILxParticleFilterItem pfi
// [local]  ILxParticleFilterItem
#define LXsP_DYNA_FORCE         "dynaForce"
#define LXs_FX_FORCE_AMP        "forceAmplitude"
#define LXs_FX_FORCE_DIR        "forceDirection"
#define LXs_FX_FORCE_DRAG       "forceDrag"
#define LXsP_ANIM_DEFORM        "animDeform"
#define LXs_FX_DEFORM_AMP       "deformAmplitude"
#define LXsP_SAMPLE_FALLOFF     "sampleFalloff"
#define LXs_FX_FALLOFF_VALUE    "falloffValue"
#define LXsPKG_REPLICATOR       "pkg.replicator"
#define LXs_PKG_IS_REPLICATOR   "-"

 #ifdef __cplusplus
  }
 #endif
#endif

