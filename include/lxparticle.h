/*
 * LX psys module
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
#ifndef LX_psys_H
#define LX_psys_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxParticleItem ** ILxParticleItemID;
typedef struct vt_ILxReplicatorEnumerator ** ILxReplicatorEnumeratorID;
typedef struct vt_ILxParticleEvalFrame ** ILxParticleEvalFrameID;
typedef struct vt_ILxParticleFilter ** ILxParticleFilterID;
typedef struct vt_ILxParticleCoOperator ** ILxParticleCoOperatorID;
typedef struct vt_ILxPointCacheItem ** ILxPointCacheItemID;
typedef struct vt_ILxParticleService ** ILxParticleServiceID;



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
                LXxMETHOD( LxResult,
        Neighbors) (
                LXtObjectID              self,
                LXtFVector               pos,
                double                   maxDist,
                int                      maxCount,
                unsigned                *index,
                double                  *dist,
                unsigned                *count);
} ILxParticleEvalFrame;
typedef struct vt_ILxParticleFilter {
        ILxUnknown       iunk;
                LXxMETHOD( LXtObjectID,
        Vertex) (
                LXtObjectID              self,
                LXtObjectID              full);
                LXxMETHOD( unsigned,
        Flags) (
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
                LXtObjectID              self,
                unsigned                 stage);
                LXxMETHOD( LxResult,
        Run) (
                LXtObjectID              self,
                unsigned                 stage,
                float                  **values,
                const unsigned          *alive,
                unsigned                 base,
                unsigned                 count);
                LXxMETHOD( LxResult,
        Particle) (
                LXtObjectID              self,
                unsigned                 stage,
                float                   *vertex);
} ILxParticleFilter;
typedef struct vt_ILxParticleCoOperator {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Initialize) (
                LXtObjectID              self,
                LXtObjectID              eval);

                LXxMETHOD( LxResult,
        Cleanup) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Step) (
                LXtObjectID              self,
                double                   dT);

                LXxMETHOD( LxResult,
        Particle) (
                LXtObjectID              self);
} ILxParticleCoOperator;
typedef struct vt_ILxPointCacheItem {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Prepare) (
                LXtObjectID              self,
                LXtObjectID              eval,
                unsigned                *index);

                LXxMETHOD( LxResult,
        Initialize) (
                LXtObjectID              self,
                LXtObjectID              vdesc,
                LXtObjectID              attr,
                unsigned                 index,
                double                   time,
                double                   sample);

                LXxMETHOD( LxResult,
        SaveFrame) (
                LXtObjectID              self,
                LXtObjectID              pobj,
                double                   time);

                LXxMETHOD( LxResult,
        Cleanup) (
                LXtObjectID              self);
} ILxPointCacheItem;
typedef struct vt_ILxParticleService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD( LxResult,
        GetReplicatorEnumerator) (
                LXtObjectID              self,
                LXtObjectID              replicatorItem,
                void                   **ppvObj);
                LXxMETHOD( LxResult,
        EnumParticleFeatures) (
                LXtObjectID              self,
                LXtObjectID              item,
                LXtObjectID              visitor);
                LXxMETHOD( LxResult,
        FeatureIdent) (
                LXtObjectID              self,
                const char             **ident);
                LXxMETHOD( LxResult,
        FeatureOffset) (
                LXtObjectID              self,
                unsigned                *offset);
} ILxParticleService;

#define LXu_PARTICLEITEM        "BA13DD5D-5093-4D0D-BEFE-119AD4F1FACB"
// [export] ILxParticleItem prti
// [local]  ILxParticleItem
// [python] ILxParticleItem:Evaluate    obj Unknown
#define LXsPKG_READPARTICLES            "readsParticles"
#define LXsITYPE_SINGLEPARTICLE         "1"
#define LXsITYPE_MULTIPARTICLE          "*"
#define LXsITYPE_ORDEREDPARTICLE        "o"
#define LXsPARTICLEATTR_SEED    "seed"
#define LXsPARTICLEATTR_USEPOL  "usePol"
#define LXsPARTICLEATTR_UPAXIS  "upAxis"
#define LXsPARTICLEATTR_DEFORM  "deform"
#define LXiTBLX_PARTICLES        LXxID4('p','r','t','i')
#define LXsTBLX_PARTICLE_POS    "pos"
#define LXsTBLX_PARTICLE_XFRM   "xfrm"
#define LXsTBLX_PARTICLE_ID     "id"
#define LXsTBLX_PARTICLE_SIZE   "size"
#define LXsTBLX_PARTICLE_VEL    "vel"
#define LXsTBLX_PARTICLE_MASS   "mass"
#define LXsTBLX_PARTICLE_FORCE  "force"
#define LXsTBLX_PARTICLE_AGE    "age"
#define LXsTBLX_PARTICLE_PATH   "pathLength"
#define LXsTBLX_PARTICLE_DISS   "dissolve"
#define LXsTBLX_PARTICLE_RATE   "rate"
#define LXsTBLX_PARTICLE_ITEM   "item"
#define LXsTBLX_PARTICLE_ANGVEL "angVel"
#define LXsTBLX_PARTICLE_TORQUE "torque"
#define LXsTBLX_PARTICLE_PPREV  "posPrev"
#define LXsTBLX_PARTICLE_LUM    "lum"
#define LXsTBLX_PARTICLE_RGB    "rgb"

#define LXiTBLX_COLLISION        LXxID4('c','o','l','l')
#define LXsTBLX_COLLISION_VAL   "val"
#define LXsTBLX_COLLISION_POS   "pos"
#define LXsTBLX_COLLISION_NORM  "norm"
#define LXsTBLX_COLLISION_COUNT "count"
#define LXsTBLX_COLLISION_TIME  "time"
#define LXu_REPLICATORENUMERATOR        "01EC90A9-924F-4475-BA6A-FFF8A2691CD5"
// [local]  ILxReplicatorEnumerator
// [python] ILxReplicatorEnumerator:Item        obj Item
#define LXfFRAME_ALIVE           0x01
#define LXfFRAME_CHANGED         0x02
#define LXu_PARTICLEEVALFRAME   "1AC26263-A422-4B17-A929-2F616037754F"
// [local]  ILxParticleEvalFrame
#define LXiPFILT_FRAME          0x00
#define LXiPFILT_RUN            0x01
#define LXiPFILT_PARTICLE       0x02
#define LXiPFILT_NEW_PARTICLE   0x03
#define LXmPFILT_TYPE           0x0F
#define LXfPFILT_PRESTAGE       0x10
#define LXfPFILT_DERIVSTAGE     0x20
#define LXfPFILT_POSTSTAGE      0x40
#define LXfPFILT_ALIVERUN       0x80
#define LXu_PARTICLEFILTER      "04A3C0C5-1C5C-43F5-8559-ACF3BAE79C0B"
// [export] ILxParticleFilter pfilt
// [local]  ILxParticleFilter
// [python] ILxParticleFilter:Particle:vertex   vector

#define LXsPKG_PFILT_CHANNEL    "particleFilter.channel"

#define LXsPFILT_ENABLECHANNEL  "pfiltEnable"

#define LXePARTICLE_KILL        LXxGOODCODE(LXeSYS_PSYS,1)
#define LXu_PARTICLECOOPERATOR  "DFBCF67B-C327-496E-8A30-20B64C31A9BB"
// [export] ILxParticleCoOperator pcoi
// [local]  ILxParticleCoOperator

#define LXsPKG_PCOOP_CHANNEL    "particleCoop.channel"
#define LXsGRAPH_PARTICLEOP     "particleOp"
#define LXu_POINTCACHEITEM      "10930C44-62D3-42D1-BD6B-8FE015D9C566"
// [export] ILxPointCacheItem pcache
// [local]  ILxPointCacheItem

#define LXsGRAPH_POINTCACHE     "pointCache"
#define LXsITYPE_PSIM            "particleSim"
#define LXsICHAN_PSIM_ENABLE     "enable"
#define LXsICHAN_PSIM_SAMPLES    "samples"
#define LXsICHAN_PSIM_ADDAGE     "addAge"
#define LXsICHAN_PSIM_ADDPATH    "addPath"
#define LXsICHAN_PSIM_STOREFORCE "storeForce"
#define LXsICHAN_PSIM_STOREMASS  "storeMass"
#define LXsICHAN_PSIM_AGEKILL    "ageKill"
#define LXsICHAN_PSIM_AGEMAX     "ageMax"
#define LXsICHAN_PSIM_AGEEXTEND  "ageExtend"
#define LXsICHAN_PSIM_GRAVENABLE "gravEnable"
#define LXsICHAN_PSIM_GRAVAXIS   "gravAxis"
#define LXsICHAN_PSIM_GRAVITY    "gravity"
#define LXsICHAN_PSIM_DRAGENABLE "dragEnable"
#define LXsICHAN_PSIM_DRAG       "drag"
#define LXsICHAN_PSIM_COLOR      "color"
#define LXsICHAN_PSIM_TGROUP     "tgroup"
#define LXsICHAN_PSIM_PCOUNT     "pCount"
#define LXsICHAN_PSIM_NTHREAD    "nThread"

#define LXsGRAPH_PSIM            "particleSim"
#define LXa_PARTICLESERVICE     "particleservice"
#define LXu_PARTICLESERVICE     "34928BF8-3917-47EF-8350-DD3A3DDED7EE"
// [python] ILxParticleService:GetReplicatorEnumerator  obj ReplicatorEnumerator
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

