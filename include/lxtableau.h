/*
 * LX tableau module
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
#ifndef LX_tableau_H
#define LX_tableau_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxTableau ** ILxTableauID;
typedef struct vt_ILxTableauElement ** ILxTableauElementID;
typedef struct vt_ILxTableauSurface ** ILxTableauSurfaceID;
typedef struct vt_ILxTriangleSoup ** ILxTriangleSoupID;
typedef struct vt_ILxTableauVolume ** ILxTableauVolumeID;
typedef struct vt_ILxTableauLight ** ILxTableauLightID;
typedef struct vt_ILxLightSample ** ILxLightSampleID;
typedef struct vt_ILxTableauProxy ** ILxTableauProxyID;
typedef struct vt_ILxTableauInstance ** ILxTableauInstanceID;
typedef struct vt_ILxTableauShader ** ILxTableauShaderID;
typedef struct vt_ILxShaderSlice ** ILxShaderSliceID;
typedef struct vt_ILxTableauFilter ** ILxTableauFilterID;
typedef struct vt_ILxTableauSource ** ILxTableauSourceID;
typedef struct vt_ILxTableauSource1 ** ILxTableauSource1ID;
typedef struct vt_ILxTableauService ** ILxTableauServiceID;
typedef struct vt_ILxTableauListener ** ILxTableauListenerID;
#include <lxvector.h>

typedef float            LXtTableauBox[6];
typedef struct st_LXpLightQuality {
        LXtFVector               center;
        float                    radius;
        float                    intensity;
        float                    power;
        unsigned int             infinite;
        unsigned int             indirect;
        unsigned int             fallType;
        unsigned int             shadType;
        unsigned int             samples;
        unsigned int             fast;
        unsigned int             linkMode;
        void                    *linkGroup;
        void                    *item;
} LXpLightQuality;
typedef struct st_LXpLightShadowing {
        LXtFVector               pos;
        LXtFVector               ray, up;
        float                    angle;
        unsigned int             mapRes;
        void                    *exclude;
} LXpLightShadowing;
typedef struct st_LXpLightSource {
        LXtFVector               wPos, oPos;
        LXtFVector               dir;
        float                    len;
        float                    nDotWi;
        int                      sampleIndex;
        void                    *lightSource;
} LXpLightSource;
typedef struct st_LXpLightColor {
        LXtFVector               color;
        LXtFVector               shadow;
        LXtFVector               unshad;
        float                    diffuse;
        float                    specular;
        float                    caustics;
        float                    subsurface;
        float                    brightness;
} LXpLightColor;
typedef struct st_LXpCameraRay {
        LXtFVector               dir;
        LXtFVector               origin;
        float                    spread;
} LXpCameraRay;
typedef struct st_LXpEnvInfiniteColor {
        LXtFVector               rgb;
        float                    intensity;
} LXpEnvInfiniteColor;
typedef struct st_LXpEnvVisibility {
        unsigned int             camera;
        unsigned int             indirect;
        unsigned int             reflection;
        unsigned int             refraction;
} LXpEnvVisibility;
typedef struct st_LXpEnvShape {
        unsigned int             sphereVis;
        float                    size;
        float                    height;
        unsigned int             flatten;
        LXtVector                pos;
        LXtMatrix                xfrmInv;
} LXpEnvShape;
typedef struct st_LXpEnvFog {
        LXtFVector               color;
        LXtFVector               opacity;
} LXpEnvFog;
typedef struct st_LXpGlobalLighting {
        LXtFVector               ambientColor;
        float                    ambientIntensity;
        float                    rayThresh;
        unsigned int             shadDepth;
        unsigned int             reflDepth;
        unsigned int             refrDepth;
        unsigned int             unbiased;
        unsigned int             specSmps;
        unsigned int             animNoise;
        unsigned int             rayAccel;
        unsigned int             batchSize;
} LXpGlobalLighting;
typedef struct st_LXpGlobalDisplacement {
        float                    rate;
        float                    ratio;
        float                    jitter;
        float                    edgeMin;
        unsigned int             enable;
        unsigned int             smooth;
        unsigned int             useBump;
} LXpGlobalDisplacement;
typedef struct st_LXpGlobalIndirect {
        float                    range;
        float                    irrRays2;
        float                    irrRate;
        float                    irrRatio;
        float                    irrSmooth;
        unsigned int             enable;
        unsigned int             scope;
        unsigned int             limit;
        unsigned int             rays;
        unsigned int             subs;
        unsigned int             vols;
        unsigned int             bump;
        unsigned int             super;
        unsigned int             reject;
        unsigned int             caus;
        unsigned int             giBack;
        unsigned int             irrCache;
        unsigned int             irrDirect2;
        unsigned int             irrRays;
        unsigned int             irrVals;
        unsigned int             irrGrads;
        unsigned int             irrStart;
        unsigned int             irrEnd;
        unsigned int             irrWalk;
        unsigned int             irrLEnable;
        unsigned int             irrSEnable;
        unsigned int             radCache;
        unsigned int             envSample;
        unsigned int             envRays;
        char                    *irrLName;
        char                    *irrSName;
} LXpGlobalIndirect;
typedef struct st_LXpGlobalCaustics {
        float                    multiplier;
        unsigned int             total;
        unsigned int             local;
        unsigned int             walk;
} LXpGlobalCaustics;
typedef struct st_LXpGlobalRendering {
        float                    subdRate;
        float                    coarseRate;
        float                    fineRate;
        float                    fineThresh;
        float                    aaImpMin;
        unsigned int             multiGeo;
        unsigned int             mergeFur;
        unsigned int             subdAdapt;
        unsigned int             renderType;
        unsigned int             aa;
        unsigned int             aaFilter;
        unsigned int             motionBlur;
        unsigned int             field;
        unsigned int             frmPasses;
        unsigned int             dof;
        unsigned int             stereo;
        unsigned int             stereoEye;
        unsigned int             stereoComp;
        unsigned int             upAxis;
        unsigned int             bucketX;
        unsigned int             bucketY;
        unsigned int             bktOrder;
        unsigned int             bktReverse;
        unsigned int             bktWrite;
        unsigned int             bktSkip;
        unsigned int             bktRefine;
        unsigned int             aRefine;
        unsigned int             mergeRad;
        unsigned int             fullBuff;
} LXpGlobalRendering;
typedef struct st_LXpCameraResolution {
                unsigned int             width;
                unsigned int             height;
                float                    pixelAspect;
                float                    dpi;
        //      float                    samples;
        //      float                    rate;
                float                    regX0, regX1, regY0, regY1;
} LXpCameraResolution;
typedef struct st_LXpCameraFrustum {
        LXtFVector               eyePos;
        LXtMatrix                xfrm, invXfrm;
        float                    focalLength;
        float                    focusDist, fStop;
        float                    irisRot, irisBias, distort;
        float                    ioDist, convDist;
        float                    blurLength, blurOffset;
        float                    apertureX, apertureY;
        float                    offsetX, offsetY;
        float                    squeeze;
        float                    target;
        float                    clipDist;
        int                      clipping;
        int                      filmFit;
        int                      projType;
        int                      irisBlades;
        void                    *item;
} LXpCameraFrustum;
typedef struct st_LXpCameraPixel {
        float                    x, y;
} LXpCameraPixel;
typedef struct st_LXpCameraUVBake {
        const char              *name;
} LXpCameraUVBake;
typedef struct vt_ILxTableau {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Time) (
                LXtObjectID              self,
                float                   *t0,
                float                   *interval);

                LXxMETHOD(  LxResult,
        AddElement) (
                LXtObjectID              self,
                LXtObjectID              element,
                LXtObjectID              shader);

                LXxMETHOD(  LxResult,
        AddInstance) (
                LXtObjectID              self,
                LXtObjectID              inst,
                LXtObjectID              element,
                LXtObjectID              shader);

                LXxMETHOD(  LxResult,
        Channels) (
                LXtObjectID              self,
                unsigned                 type,
                void                   **ppvObj);

                LXxMETHOD (  LxResult,
        Visible) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD(  LxResult,
        FindShader) (
                LXtObjectID              self,
                LXtObjectID              item,
                LXtObjectID              tags,
                void                   **ppvObj);

                LXxMETHOD(  LXtObjectID,
        InstanceItem) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        Update) (
                LXtObjectID              self,
                LXtObjectID              visitor,
                int                      immediate);

                LXxMETHOD(  LxResult,
        UpdateAll) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        EltNotify) (
                LXtObjectID              self,
                LXtObjectID              element,
                int                      event);

                LXxMETHOD(  LxResult,
        InstNotify) (
                LXtObjectID              self,
                LXtObjectID              instance,
                int                      event);
} ILxTableau;
typedef struct vt_ILxTableauElement {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Bound) (
                LXtObjectID              self,
                LXtTableauBox            bbox);
                LXxMETHOD(  unsigned int,
        FeatureCount) (
                LXtObjectID              self,
                LXtID4                   type);

                LXxMETHOD(  LxResult,
        FeatureByIndex) (
                LXtObjectID              self,
                LXtID4                   type,
                unsigned int             index,
                const char             **name);

                LXxMETHOD(  LxResult,
        SetVertex) (
                LXtObjectID              self,
                LXtObjectID              vdesc);
} ILxTableauElement;
typedef struct vt_ILxTableauSurface {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Bound) (
                LXtObjectID              self,
                LXtTableauBox            bbox);
                LXxMETHOD(  unsigned int,
        FeatureCount) (
                LXtObjectID              self,
                LXtID4                   type);

                LXxMETHOD(  LxResult,
        FeatureByIndex) (
                LXtObjectID              self,
                LXtID4                   type,
                unsigned int             index,
                const char             **name);

                LXxMETHOD(  LxResult,
        SetVertex) (
                LXtObjectID              self,
                LXtObjectID              vdesc);

                LXxMETHOD(  LxResult,
        Sample) (
                LXtObjectID              self,
                const LXtTableauBox      bbox,
                float                    scale,
                LXtObjectID              trisoup);
                LXxMETHOD(  LxResult,
        Padding) (
                LXtObjectID              self,
                float                   *dist);
} ILxTableauSurface;
typedef struct vt_ILxTriangleSoup {
        ILxUnknown       iunk;
                LXxMETHOD(  unsigned int,
        TestBox) (
                LXtObjectID              self,
                const LXtTableauBox      bbox);

                LXxMETHOD(  LxResult,
        Segment) (
                LXtObjectID              self,
                unsigned int             segID,
                unsigned int             type);
                LXxMETHOD(  LxResult,
        Vertex) (
                LXtObjectID              self,
                const float             *vertex,
                unsigned int            *index);

                LXxMETHOD(  LxResult,
        Polygon) (
                LXtObjectID              self,
                unsigned int             v0,
                unsigned int             v1,
                unsigned int             v2);
                LXxMETHOD(  void,
        Connect) (
                LXtObjectID              self,
                unsigned int             type);
} ILxTriangleSoup;
typedef struct vt_ILxTableauVolume {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Bound) (
                LXtObjectID              self,
                LXtTableauBox            bbox);
                LXxMETHOD(  unsigned int,
        FeatureCount) (
                LXtObjectID              self,
                LXtID4                   type);

                LXxMETHOD(  LxResult,
        FeatureByIndex) (
                LXtObjectID              self,
                LXtID4                   type,
                unsigned int             index,
                const char             **name);

                LXxMETHOD(  LxResult,
        SetVertex) (
                LXtObjectID              self,
                LXtObjectID              vdesc);

                LXxMETHOD(  int,
        Type) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        RenderInit) (
                LXtObjectID              self,
                LXtObjectID              sv);

                LXxMETHOD(  LxResult,
        RaySample) (
                LXtObjectID              self,
                LXtObjectID              densitySlice,
                LXtObjectID              shadingSlice,
                LXtObjectID              sv,
                LXtObjectID              raycastObj,
                LXtObjectID              raymarchObj);

                LXxMETHOD(  LxResult,
        RayCast) (
                LXtObjectID              self,
                LXtObjectID              densitySlice,
                LXtObjectID              sv,
                LXtObjectID              raycastObj,
                double                  *dist,
                int                     *localShader);

                LXxMETHOD(  LxResult,
        Density) (
                LXtObjectID              self,
                LXtObjectID              densitySlice,
                LXtObjectID              sv,
                LXtObjectID              raycastObj,
                const LXtVector          pos,
                int                      worldPos,
                double                  *dens); 
} ILxTableauVolume;
typedef struct vt_ILxTableauLight {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Bound) (
                LXtObjectID              self,
                LXtTableauBox            bbox);
                LXxMETHOD(  unsigned int,
        FeatureCount) (
                LXtObjectID              self,
                LXtID4                   type);

                LXxMETHOD(  LxResult,
        FeatureByIndex) (
                LXtObjectID              self,
                LXtID4                   type,
                unsigned int             index,
                const char             **name);

                LXxMETHOD(  LxResult,
        SetVertex) (
                LXtObjectID              self,
                LXtObjectID              vdesc);

                LXxMETHOD(  LxResult,
        Sample) (
                LXtObjectID              self,
                int                      sample,
                float                    ju,
                float                    jv,
                const LXtFVector         dir,
                LXtFVector               wPos,
                LXtFVector               oPos,
                float                    t);

                LXxMETHOD(  int,
        Geometry) (
                LXtObjectID              self,
                void                    *gc);

                LXxMETHOD(  LxResult,
        Emit) (
                LXtObjectID              self,
                unsigned int             nPhotons,
                int                      offset,
                LXtObjectID              slice,
                LXtSampleVectorID        sv);

                LXxMETHOD(  int,
        ShadowMap) (
                LXtObjectID              self,
                void                   **ppvObj);
} ILxTableauLight;
typedef struct vt_ILxLightSample {
        ILxUnknown       iunk;
                LXxMETHOD(  void,
        Vertex) (
                LXtObjectID              self,
                const float             *vertex);
} ILxLightSample;
typedef struct vt_ILxTableauProxy {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Bound) (
                LXtObjectID              self,
                LXtTableauBox            bbox);
                LXxMETHOD(  unsigned int,
        FeatureCount) (
                LXtObjectID              self,
                LXtID4                   type);

                LXxMETHOD(  LxResult,
        FeatureByIndex) (
                LXtObjectID              self,
                LXtID4                   type,
                unsigned int             index,
                const char             **name);

                LXxMETHOD(  LxResult,
        SetVertex) (
                LXtObjectID              self,
                LXtObjectID              vdesc);

                LXxMETHOD(  LxResult,
        Sample) (
                LXtObjectID              self,
                const LXtTableauBox      bbox,
                LXtObjectID              tableau);
} ILxTableauProxy;
typedef struct vt_ILxTableauInstance {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Properties) (
                LXtObjectID              self,
                LXtObjectID              vecstack);
                LXxMETHOD(  LxResult,
        GetTransform) (
                LXtObjectID              self,
                unsigned                 endPoint,
                LXtVector                offset,
                LXtMatrix                xfrm);
} ILxTableauInstance;
typedef struct vt_ILxTableauShader {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Select) (
                LXtObjectID              self,
                LXtObjectID              teElt,
                LXtObjectID              tvDesc);

                LXxMETHOD(  LxResult,
        Slice) (
                LXtObjectID              self,
                LXtObjectID              vtOutput,  
                LXtObjectID              tvDesc,
                void                   **ppvObj);
} ILxTableauShader;
typedef struct vt_ILxShaderSlice {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Evaluate) (
                LXtObjectID              self,
                LXtObjectID              vecstack);
} ILxShaderSlice;
typedef struct vt_ILxTableauFilter {
        ILxUnknown       iunk;
                LXxMETHOD(  const char *,
        Order) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        Select) (
                LXtObjectID              self,
                LXtObjectID              framebuf);

                LXxMETHOD(  unsigned int,
        Bound) (
                LXtObjectID              self,
                float                    box[4],
                float                   *kernel);
                LXxMETHOD(  unsigned int,
        Pixel) (
                LXtObjectID              self,
                LXtObjectID              framebuf,
                const float              pos[2]);

                LXxMETHOD(  unsigned int,
        Region) (
                LXtObjectID              self,
                LXtObjectID              framebuf,
                const float              box[4]);
} ILxTableauFilter;
typedef struct vt_ILxTableauSource {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Elements) (
                LXtObjectID              self,
                LXtObjectID              tableau);

                LXxMETHOD(  LxResult,
        Preview) (
                LXtObjectID              self,
                LXtObjectID              tableau);

                LXxMETHOD(  LxResult,
        Instance) (
                LXtObjectID              self,
                LXtObjectID              tableau,
                LXtObjectID              instance);

                LXxMETHOD(  LxResult,
        SubShader) (
                LXtObjectID              self,
                LXtObjectID              tableau,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        PreviewUpdate) (
                LXtObjectID              self,
                int                      chanIndex,
                int                     *update);

                LXxMETHOD(  LxResult,
        GetCurves) (
                LXtObjectID              self,
                LXtObjectID              tableau,
                LXtObjectID              tags,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        ElementType) (
                LXtObjectID              self,
                int                      type,
                int                     *supported);
} ILxTableauSource;
typedef struct vt_ILxTableauSource1 {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Elements) (
                LXtObjectID              self,
                LXtObjectID              tableau);

                LXxMETHOD(  LxResult,
        Preview) (
                LXtObjectID              self,
                LXtObjectID              tableau);

                LXxMETHOD(  LxResult,
        Instance) (
                LXtObjectID              self,
                LXtObjectID              tableau,
                LXtObjectID              instance);

                LXxMETHOD(  LxResult,
        SubShader) (
                LXtObjectID              self,
                LXtObjectID              tableau,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        PreviewUpdate) (
                LXtObjectID              self,
                int                      chanIndex,
                int                     *update);

                LXxMETHOD(  LxResult,
        GetCurves) (
                LXtObjectID              self,
                LXtObjectID              tableau,
                LXtObjectID              tags,
                void                   **ppvObj);
} ILxTableauSource1;
typedef struct vt_ILxTableauService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        AllocVertex) (
                LXtObjectID              self,
                void                   **ppvObj);
} ILxTableauService;
typedef struct vt_ILxTableauListener {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        ChannelChange) (
                LXtObjectID              self,
                LXtObjectID              tableau,
                LXtObjectID              item,
                int                      channel);
                LXxMETHOD( void,
        FlushElements) (
                LXtObjectID              self,
                LXtObjectID              tableau);
                LXxMETHOD( void,
        TableauDestroy) (
                LXtObjectID              self,
                LXtObjectID              tableau);
} ILxTableauListener;

#define LXiTBX_SURF_ADD                 0x0
#define LXiTBX_SURF_REMOVE              (LXiTBX_SURF_ADD + 1)
#define LXiTBX_SURF_GEO                 (LXiTBX_SURF_REMOVE + 1)
#define LXiTBX_SURF_XFRM                (LXiTBX_SURF_GEO + 1)
#define LXiTBX_SURF_SHADER              (LXiTBX_SURF_XFRM + 1)  

#define LXiTBX_LGT_ADD                  (LXiTBX_SURF_SHADER + 1)
#define LXiTBX_LGT_REMOVE               (LXiTBX_LGT_ADD + 1)
#define LXiTBX_LGT_DATA                 (LXiTBX_LGT_REMOVE + 1)
#define LXiTBX_LGT_XFRM                 (LXiTBX_LGT_DATA + 1)
#define LXiTBX_LGT_SHADER               (LXiTBX_LGT_XFRM + 1)

#define LXiTBX_VOL_ADD                  (LXiTBX_LGT_SHADER + 1)
#define LXiTBX_VOL_REMOVE               (LXiTBX_VOL_ADD + 1)
#define LXiTBX_VOL_DATA                 (LXiTBX_VOL_REMOVE + 1)
#define LXiTBX_VOL_XFRM                 (LXiTBX_VOL_DATA + 1)
#define LXiTBX_VOL_SHADER               (LXiTBX_VOL_XFRM + 1)
#define LXiTBX_INST_ADD                 0x0
#define LXiTBX_INST_REMOVE              (LXiTBX_INST_ADD + 1)
#define LXiTBX_INST_XFRM                (LXiTBX_INST_REMOVE + 1)
#define LXu_TABLEAU     "76C4EDD9-5FF9-4342-BB08-EFCD0B344004"
// [local]  ILxTableau
// [python] ILxTableau:Channels         obj ChannelRead (action)
// [python] ILxTableau:FindShader       obj TableauShader
// [python] ILxTableau:Visible          bool
#define LXe_INFINITE_BOUND      LXxGOODCODE(LXeSYS_REND,1)
#define LXiTBLX_BASEFEATURE     LXxID4(' ','v','r','t')
#define LXsTBLX_FEATURE_POS     "pos"
#define LXsTBLX_FEATURE_OBJPOS  "opos"
#define LXsTBLX_FEATURE_VEL     "vel"
#define LXsTBLX_FEATURE_NORMAL  "norm"
#define LXsTBLX_FEATURE_RADIUS  "rad"
#define LXsTBLX_FEATURE_PARAM_LENGTH    "plen"
#define LXsTBLX_FEATURE_PARTID  "partID"
#define LXiTBLX_DPDU            LXxID4('d','p','d','u')
#define LXu_TABLEAUELEMENT      "71D90AD9-3E30-4CE8-9E2B-F70DA281B2DC"
#define LXa_TABLEAUELEMENT      "tableauElement"
// [local]  ILxTableauElement
#define LXeTBLXSURF_ADAPTIVE     LXxGOODCODE(LXeSYS_REND,2)
#define LXiTBLX_SEG_POINT        1
#define LXiTBLX_SEG_LINE         2
#define LXiTBLX_SEG_TRIANGLE     3
#define LXiTBLX_CONNECT_QUAD     0
#define LXiTBLX_CONNECT_BEGIN    1
#define LXiTBLX_CONNECT_END      2
#define LXu_TABLEAUSURFACE      "B5769A8B-6254-42E3-862F-0A811E716E21"
#define LXa_TABLEAUSURFACE      "tableauSurface"
#define LXu_TRIANGLESOUP        "17536C2D-07BD-49C8-8348-CEBDE4D3A856"
// [local]   ILxTableauSurface
// [export]  ILxTableauSurface tsrf
// [default] ILxTableauSurface:FeatureCount   = 0
// [default] ILxTableauSurface:FeatureByIndex = LXe_OUTOFBOUNDS
// [local]   ILxTriangleSoup
// [export]  ILxTriangleSoup soup
// [default] ILxTriangleSoup:TestBox = 1
// [default] ILxTriangleSoup:Segment = LXe_TRUE
#define LXfTBLX_VOL_VOLUME       1
#define LXfTBLX_VOL_CLIPPING     2
#define LXfTBLX_VOL_IMPSURF      4
#define LXu_TABLEAUVOLUME       "97962302-4B49-4282-B259-F347F1012818"
#define LXa_TABLEAUVOLUME       "tableauVolume"
// [local]   ILxTableauVolume
// [export]  ILxTableauVolume tvol
// [default] ILxTableauVolume:FeatureCount   = 0
// [default] ILxTableauVolume:FeatureByIndex = LXe_OUTOFBOUNDS
#define LXu_TABLEAULIGHT        "7FE816D1-4A7F-4BE5-9689-4991C03CAEE0"
#define LXa_TABLEAULIGHT        "tableauLight"
#define LXu_LIGHTSAMPLE         "43734621-9B93-4174-AC63-E2FE7DDA8794"
// [local]   ILxTableauLight
// [export]  ILxTableauLight tlgt
// [default] ILxTableauLight:FeatureCount   = 0
// [default] ILxTableauLight:FeatureByIndex = LXe_OUTOFBOUNDS
// [local]   ILxLightSample
#define LXsP_LGT_QUALITY        "light.quality"
#define LXsP_LGT_SHADOWING      "light.shadowing"
#define LXsP_LGT_SOURCE         "light.source"
#define LXsP_LGT_COLOR          "light.color"
#define LXs_FX_LIGHTCOLOR       "lightColor"
#define LXs_FX_LIGHTSHADOW      "lightShadow"
#define LXs_FX_LIGHTDIFFUSE     "lightDiffuse"
#define LXs_FX_LIGHTSPECULAR    "lightSpecular"
#define LXs_FX_LIGHTCAUSTICS    "lightCaustics"
#define LXs_FX_LIGHTDISTANCE    "lightDistance"
#define LXs_FX_LIGHTANGLE       "lightAngle"
#define LXs_FX_VOLSCATTER       "volScattering"
#define LXs_FX_VOLSCATTER_COL   "volScatteringColor"
#define LXs_FX_VOLABSORB        "volAbsorption"
#define LXs_FX_VOLABSORB_COL    "volAbsorptionColor"
#define LXs_FX_VOLDENSITY       "volDensity"
#define LXs_FX_VOLLEVEL         "volLevel"
#define LXs_FX_VOLSMPDENSITY    "volSampleDensity"
#define LXs_FX_VOLAMB_COL       "volAmbientColor"
#define LXs_FX_VOLLUMI          "volLuminosity"
#define LXs_FX_VOLLUMI_COL      "volLuminosityColor"
#define LXu_TABLEAUPROXY        "FB34BD64-099C-4B30-8EF7-2BB04CA0E92C"
#define LXa_TABLEAUPROXY        "tableauProxy"
// [local]   ILxTableauProxy
// [export]  ILxTableauProxy tpro
// [default] ILxTableauProxy:FeatureCount   = 0
// [default] ILxTableauProxy:FeatureByIndex = LXe_OUTOFBOUNDS
#define LXu_TABLEAUINSTANCE     "9B57D0DB-C0B4-435E-8CDD-E3DDCF66172D"
#define LXa_TABLEAUINSTANCE     "tableauInstance"
// [local]   ILxTableauInstance
// [export]  ILxTableauInstance tins
// [default] ILxTableauInstance:Properties = LXe_OK

#define LXiTBLX_ENDPOINT_T0      0
#define LXiTBLX_ENDPOINT_T1      1
#define LXu_TABLEAUSHADER       "A0E3B574-B0AC-4530-A43F-7CC8DA536E25"
#define LXa_TABLEAUSHADER       "tableauShader"
#define LXu_SHADERSLICE         "47B885B9-B1D9-4F86-829F-A6AABBD7FFF7"
// [export] ILxTableauShader tsha
// [local]  ILxTableauShader
// [python] ILxTableauShader:Slice      obj ShaderSlice
// [local]  ILxShaderSlice
#define LXsP_CAM_RAY            "camera.ray"
#define LXsP_CAM_RAY_T1         "camera.ray_T1"
#define LXsP_ENV_INFINITECOLOR  "environment.color"
#define LXsP_ENV_VISIBILITY     "environment.visibility"
#define LXsP_GLO_LIGHTING       "global.lighting"
#define LXsP_GLO_DISPLACEMENT   "global.displacement"
#define LXsP_GLO_INDIRECT       "global.indirect"
#define LXsP_GLO_CAUSTICS       "global.caustics"
#define LXsP_GLO_RENDERING      "global.rendering"
#define LXsP_CAM_RESOLUTION     "camera.resolution"
#define LXsP_CAM_FRUSTUM        "camera.frustum"
#define LXsP_CAM_FRUSTUM_T1     "camera.frustum_T1"
#define LXsP_CAM_PIXEL          "camera.pixel"
#define LXsP_CAM_UVBAKE         "camera.uvBake"
#define LXfTBLX_FILT_PIXEL       0x01
#define LXfTBLX_FILT_STRIP       0x02
#define LXfTBLX_FILT_RELATIVE    0x04
#define LXu_TABLEAUFILTER       "FD1326E7-EECF-4EAC-B9AD-B1D64E7503BE"
#define LXa_TABLEAUFILTER       "tableauFilter"
#define LXfTBLX_PREVIEW_UPDATE_NONE      0x00
#define LXfTBLX_PREVIEW_UPDATE_GEOMETRY  0x01
#define LXfTBLX_PREVIEW_UPDATE_SHADING   0x02
#define LXiTBXELT_SURFACE       0
#define LXiTBXELT_VOLUME        1
#define LXiTBXELT_LIGHT         2
#define LXiTBXELT_FILTER        3
#define LXiTBXELT_PROXY         4
#define LXu_TABLEAUSOURCE       "9CC7F9F4-9540-4EEA-8EE9-710D58EC68F9"
// [local]   ILxTableauSource
// [export]  ILxTableauSource tsrc
// [default] ILxTableauSource:ElementType = LXe_NOTIMPL
#define LXu_TABLEAUSOURCE1      "1121C167-F934-4421-8ABE-32F8E4659324"
// [export]  ILxTableauSource1 tsrc
#define LXu_TABLEAUSERVICE      "8DF92316-3172-465A-A199-254792D37732"
// [python] ILxTableauService:AllocVertex       obj TableauVertex
#define LXu_TABLEAULISTENER     "848C5B64-4C9F-404E-8E3F-CF725007F74D"
// [export] ILxTableauListener tli

 #ifdef __cplusplus
  }
 #endif
#endif

