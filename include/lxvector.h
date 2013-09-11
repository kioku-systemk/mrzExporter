/*
 * LX vector module
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
#ifndef LX_vector_H
#define LX_vector_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxVectorPacket ** ILxVectorPacketID;
typedef struct vt_ILxPacketService ** ILxPacketServiceID;
typedef struct vt_ILxVectorType ** ILxVectorTypeID;
typedef struct vt_ILxVectorStack ** ILxVectorStackID;
typedef struct vt_ILxVectorList ** ILxVectorListID;
typedef struct vt_ILxTextureEffect ** ILxTextureEffectID;
typedef struct vt_ILxPacketEffect ** ILxPacketEffectID;
#include <lxcom.h>
#include <lxvmath.h>
#include <lxmeshOLD.h>

typedef struct st_GenVector *   LXtGenVectorID;
typedef struct st_GenVector *    LXtSampleVectorID;
typedef struct st_LXpSamplePosition {
        LXtVector        wPos;          // position in world space
        LXtVector        wVel;          // velocity in world space (meters traveled during exposure)
        LXtVector        oPos;          // position in object space
        LXtVector        uPos;          // undisplaced position in object space
        float            spot;          // spot size (width of sample perpendicular to incoming ray)
        float            bias;          // distance by which wPos is adjusted to prevent self-shadowing
        int              infinite;      // indicates an environment sample
        float           *uv;            // variable-length UV array
        float           *duv;           // variable-length UV delta array (like RenderMan's du and dv)
        LXtFVector      *dpduv;         // variable-length UV derivative array (like RenderMan's dPdu and dPdv)
        int             *offset;        // variable-length feature offsets
} LXpSamplePosition;
typedef struct st_LXpSampleTransform {
        LXtMatrix        transform;     // direct transformation
        LXtMatrix        invert;        // inverse transformation
        LXtVector        scale;         // object scale
        LXtVector        wpos;          // object world position
} LXpSampleTransform;
typedef struct st_LXpSampleRay {
        LXtVector        origin;        // origin of the ray (position)
        LXtFVector       dir;           // direction of the ray
        LXtFVector       color;         // color seen by the ray
        LXtFVector       abc;           // absorption coefficients
        float            dist;          // distance travelled by the ray
        float            prevDist;      // total distance travelled by previous segments of the ray
        float            nearClip;      // near and far clipping distances
        float            farClip;
        float            importance;    // starts at one, then diminishes as the ray tree splits
        float            prevSpot;      // spot size of ray at its origin
        float            cone;          // cone angle of the ray (spot = prevSpot + dist * cone)
        float            eta;           // refractive index of the material in which the ray is traveling
        float            wavelength;    // wavelength in nanometers for monochromatic dispersion rays
        int              bounces;       // number of bounces
        int              thread;        // thread number
        unsigned int     flags;         // ray evaluation flags (see REf_xxx in rays.qq)
        int              rayID;         // number of this ray (as a uniqueness identifier)
} LXpSampleRay;
typedef struct st_LXpSampleClip {
        void            *elt;   // clipping element ID
        float            dist;  // clip distance on the ray
        float            delta; // difference between original and modified sample position on the ray
} LXpSampleClip;
typedef struct st_LXpSampleParms {
        LXtFVector       diffCol;       // diffuse color
        LXtFVector       specCol;       // specular color
        LXtFVector       reflCol;       // mirror reflection color
        LXtFVector       tranCol;       // transparency color
        LXtFVector       subsCol;       // subsurface scattering color
        LXtFVector       lumiCol;       // luminous color
        LXtFVector       exitCol;       // exit color
        LXtFVector       clipCol;       // clipping color
        LXtFVector       anisoDir;      // anisotropy direction (raw color)
        LXtFVector       anisoDpdu;     // anisotropy U derivative
        LXtFVector       anisoDpdv;     // anisotropy V derivative
        float            diffAmt;       // diffuse amount
        float            specAmt;       // specular amount
        float            reflAmt;       // mirror reflection amount
        float            tranAmt;       // transparency amount
        float            subsAmt;       // subsurface scattering amount
        float            lumiAmt;       // luminous amount
        float            coatAmt;       // clearcoat amount
        float            dissAmt;       // dissolve amount
        float            bumpAmt;       // bump strength
        float            bumpAmp;       // bump amplitude
        float            diffRough;     // diffuse roughness (for Oren-Nayar BRDF)
        float            clipVal;       // clipping value associated to material
        float            rough;         // roughness value before it is converted into specular exponents
        float            aniso;         // anisotropy strength (variation of U and V specular exponents)
        float            anisoCos;      // anisotropy direction cosine
        float            anisoSin;      // anisotropy direction sine
        float            specExpU;      // specular exponent in U direction
        float            specExpV;      // specular exponent in V direction
        float            specFres;      // specular fresnel amount
        float            reflFres;      // reflection fresnel amount
        float            refIndex;      // refractive index
        float            disperse;      // dispersion (variation of refractive index with wavelength)
        float            tranRough;     // transparency roughness
        float            tranDist;      // absorption distance
        float            subsDist;      // scattering distance
        float            subsDepth;     // scattering max depth
        float            subsPhase;     // scattering phase function (forward/backward balance)
        int              reflType;      // reflection type
        int              reflRays;      // reflection rays
        int              tranRays;      // refraction rays
        int              subsRays;      // subsurface scattering rays
        int              flags;         // give shaders access to LXfSURF_* flags
        int              uvOffset;      // offset used to get u,v derivatives
        int              clearBump;     // clear pre existing bumps
        int              clipEnable;    // enable render clipping on surface
        int              clipMatte;     // render clip surface as matte color
        int              clipped;       // surface sample is clipped
} LXpSampleParms;
typedef struct st_LXpSampleMask {
        float            groupOpacity;  // the opacity for a shader group
        float            layerOpacity;  // the opacity for a layer
        int              layerOverride; // true if the layer evaluation should use the layerOpacity
} LXpSampleMask;
typedef struct st_LXpSampleGroupMask {
        float            groupOpacity;  // the opacity for a shader group
} LXpSampleGroupMask;
typedef struct st_LXpSampleDriver {
        float            a, b, c, d;
} LXpSampleDriver;
typedef struct st_LXpSampleStencil {
        float            value; 
        int              textureCount;
        int              texturePass;
} LXpSampleStencil;
typedef struct st_LXpSampleVolume {
        LXtFVector       scatter;
        LXtFVector       absorb;
        float            scatterAmt;
        float            absorbAmt;
        float            attenuate;
        float            shift;
} LXpSampleVolume;
typedef struct st_LXpSampleDensity {
        float            density, density0;
        float            level;
} LXpSampleDensity;
typedef struct st_LXpSampleDissolve {
        float            dissolve;
} LXpSampleDissolve;
typedef struct st_LXpSampleFacet {
        LXtVector        wPos[3];               // position in world space (note that we have to use double precision)
        LXtVector        oPos[3];               // position in object space
        LXtVector        uPos[3];               // undisplaced position in object space
        int              flags;                 // facet flags
} LXpSampleFacet;
typedef struct st_LXpSampleBump {
        LXtVector        dp;                    // position delta during bump map evaluation
        LXtVector        bump;                  // this is the result of bump map evaluation: the bumped normal
        float            bumpAmplitude;         // bump amplitude as set by the material
        float            bumpHeight;            // bump height at sample position
        int              bumpMapping;           // flag set to true during bump mapping texture evaluation
        int              texturePass;           // flag set to true during bump texture count pass
        int              textureCount;          // bump texture count
        int              shadeCount;            // shader counter
        int              shadeIndex;            // current shader evaluation index
} LXpSampleBump;
typedef struct st_LXpTextureInput {
        LXtFVector       tPos;          // position in texture space
        LXtFVector       uvw;           // UVW coordinates computed from projection
        LXtFVector       uvw0;          // raw UVW coordinates (before wrapping, repeat options, etc)
        LXtFVector       scale;         // texture scale
        LXtFVector       dpdu, dpdv;    // U,V derivatives
        float            tSize[2], tSpot;       // texture spot size
        float            octaveMult;    // multiplier on the number octaves for fractal textures, always between (0,1). Similar to importance but for textures
        int              adaptiveFreq;  // enables the adpative frequencies on fractal textures.
        int              context;       // eval context
        int              axis;          // texture axis (from the locator)
        int              uvOffset;      // offset of the uvs to use for evaluation
        int              uvTile[2];     // UV tiling options.
        float            uvWrap[2];     // UV wrapping sizes
        LXtMatrix        uvXfrm;        // UV transformation matrix
        int              noTile;        // should be set to ignore UV tiling options (used in GL context)
        int              projOnly;      // true when the texture requires a projection, like image maps
        int              sampleMesh;    // flag which should be set when doing sample mesh previews
        int              ignoreAlpha;   // flag which should be set when doing sample mesh previews
        float            sampleScale;   // scale of the sample mesh
        int              offRange;      // some projections may decide to render nothing outside the [0,1] UV range. In that case 'offRange' will be true
        float            idParm;        // texture particle ID parameter as set during texture replication (note that it is not the same as the surface particle ID)
        int              particleIdx;   // texture particle index in the particle array
        int              particleEval;  // particle context flag set to true when evaluating particles, this can trigger specialised evaluations modes
        float            particleRadius;// particle radius      
} LXpTextureInput;
typedef struct st_LXpTextureOutput {
        int              direct;
        double           value[2];
        LXtVector        color[2];
        double           alpha[2];
        double           range[2];
        double           blend;
} LXpTextureOutput;
typedef struct st_LXpTextureValue {
        double           value;
        double           alpha;
        LXtVector        color;
} LXpTextureValue;
typedef struct st_LXpTextureLocator {
        LXtVector        wPos;
        LXtVector        oPos;
        LXtMatrix        xfrm;
        LXtMatrix        iXfrm;
        LXtMatrix        irXfrm;
} LXpTextureLocator;
typedef struct st_LXpSampleSurfNormal {
        LXtFVector       gNorm;         // geometric normal (without smoothing)
        LXtFVector       uNorm;         // undisplaced normal (with smoothing but no displacement)
        LXtFVector       wNorm0;        // initial shading normal (with smoothing but no bump textures)
        LXtFVector       wNorm;         // final shading normal (with smoothing and bump textures)
        LXtFVector       tangent;       // tangent vector, used by hair rendering
        LXtFVector       normalMap;     // normal vector evaluated by normal map textures
        int              oAxis, wAxis;  // dominant axis in object and world space
        int              back;          // true if surface is backfacing
} LXpSampleSurfNormal;
typedef struct st_LXpSampleSurfSmooth {
        float            smooth, csa;   // smooth amount, cos(smooth angle)
        int              dblSided;
} LXpSampleSurfSmooth;
typedef struct st_LXpDisplace {
        LXtFVector       dPos;          // displaced position
        LXtFVector       vDsp;          // vector displacement (set by textures)
        float            max;           // max displacement
        float            amplitude;     // displacement amplitude (set by the material)
        float            dist;          // displacement height (set by textures)
        int              enable;        // enable flag set to true by displacement textures (so 0 means no displacement textures).
        int              maxPass;       // true during the 'max' evaluation pass
} LXpDisplace;
typedef struct st_LXpShaderType {
        int              type, hidden;
        int              layerIndex;
} LXpShaderType;
typedef struct st_LXpGroupLayer {
        int              layerEnum;     // layer enumeration flag
        int              layerScope;    // enumeration scope
        int              layerCount;    // number of layers
        int              layerIndex;    // current layer evaluation index
        int              layerTotal;    // total number of groups with scope
} LXpGroupLayer;
typedef struct st_LXpFurParms {
        float            minDist;       // minimum distance between hairs at 100% density
        float            length;        // hair length
        float            width;         // hair width at root (percent of distance parameter)
        float            flex;          // how much hair flexes
        float            density;       // hair density
        float            display;       // display density (percen of main density)
        float            bumpAmp;       // bump amplitude for fur bump effects
        float            curles;        // curles amplitude
        float            clumps;        // clumps amplitude
        float            clumpDens;     // clumps density
        float            clumpSize;     // clump range (m)
        float            clumpStray;    // clump stray hair probability
        float            clumpStrayAmp; // clump stray strength
        float            taper;         // taper
        float            yOffset;       // vertical offset (m)
        float            stripRot;      // strip random rotation (%)     
        float            rootBend;      // root bending (%)      
        float            rate;          // fur rate for adaptive sampling        
        float            blendAngle;    // the limit angle for guide blending    
        float            blendAmount;   // the amount of guide blending  
        float            posJitter, sclJitter, nrmJitter, grwJitter; // jittering for position scale and orientation and growth
        float            kinkAmp, kinkAmpTip, kinkScl, kinkYScl, kinkOff; // kink aplitude at the root, amplitude at the tip, scale, y scale, offset
        float            frizAmp, frizAmpTip, frizScl, frizOff; // frizz amplitude at the root, amplitude at the tip, scale and offset  
        int              maxSegment;    // maximum number of segments long one hair
        int              type;          // geometry type
        int              furOnly;       // remove base surface polygons when true
        int              randomSeed;    // seed for fur random sequence
        int              adaptive;      // adaptive fur flag
        int              autoFade;      // automatic fading (for adaptive fur) flag
        int              culling;       // view frustrum culling flag
        int              billboard;     // true for billboard type geometry, can be either tree or leaf. The difference is the direction: trees grow up and facing the camera and leaves grow horizontal, not facing the camera.
        int              glColorOverride;// true if GL should use color below
        int              useIC;    // true if IC should be enabled on fur (OFF by default)
        LXtFVector       glColor;       // GL color for hair strands
        // guide settings
        int              guides;        // how to use guides for fur geometry
        int              guideSurf;     // true if the guides are located in the same surface (as the fur)
        int              guideBound;    // true if surface guides need to be included in surface bounding box
        float            guideSize;     // guide range (m)
        float            guideLen;      // guide parametric length (%)
        char            *guideTag;      // guide polygon tag
        LXtID4           guideType;     // guide polygon tag type
        void            *guideItem;     // guide mesh item
        // eval data
        LXtFVector       bump;          // fur bump vector
        float            bumpHeight;    // evaluated bump height
        float            max;           // max fur size
        float            dist;          // fur height (set by textures)
        int              enable;        // enable flag set to true by fur materials (so 0 means no fur material).
        int              cylinders;     // true if hairs are made of cylinders
        int              tgtShade;      // true if fur uses tangent shading
        int              maxPass;       // true during the 'max' evaluation pass
        int              bumpPass;      // true during the 'fur bump' evaluation pass
} LXpFurParms;
typedef struct st_LXpParticleSample {
        LXtFVector       vel;           // instant velocity
        LXtFVector       normal;        // hair normal
        LXtFVector       bump;          // hair bump
        float            idParm;
        float            lenParm;
        float            minDist;
        float            density;
        float            size;
        float            dissolve;
        float            age;
        int              useLen;
        // Particle implicit UVs
        float            uv[2];
        float            duv[2];
        float            dpdu[3];
        float            dpdv[3];
} LXpParticleSample;
typedef struct st_LXpShadeOpacity {
        LXtFVector       opa;
} LXpShadeOpacity;
typedef struct st_LXpShadeComponents {
        LXtFVector       diff;          // diffuse reflection
        LXtFVector       diffDir;       // diffuse (direct illumination only)
        LXtFVector       diffInd;       // diffuse (indirect illumination only)
        LXtFVector       diffUns;       // diffuse (unshadowed direct illumination)
        LXtFVector       spec;          // specular reflection
        LXtFVector       refl;          // mirror reflection
        LXtFVector       tran;          // transparency
        LXtFVector       subs;          // subsurface scattering
        LXtFVector       lumi;          // luminosity
        LXtFVector       illum;         // total illumination
        LXtFVector       illumDir;      // direct illumination only
        LXtFVector       illumInd;      // indirect illumination only
        LXtFVector       illumUns;      // unshadowed direct illumination
        LXtFVector       volLum;        // volumetic scattering
        LXtFVector       volOpa;        // volumetric absorption
} LXpShadeComponents;
typedef struct st_LXpShadeOutput {
        LXtFVector       color;         // final color
        LXtFVector       mVec;          // motion vector
        LXtFVector       sNorm;         // shading normal
        LXtFVector       gNorm;         // geometric normal
        LXtFVector       uv;            // UV coordinates
        LXtFVector       dpdu;          // dPdu vector
        LXtFVector       dpdv;          // dPdv vector
        LXtFVector       icVal;         // nearest IC value
        float            alpha;         // alpha channel
        float            depth;         // depth from camera
        float            volDepth;      // depth from camera for volume samples
        float            shadow;        // shadow density
        float            occlAmb;       // ambient occlusion
        float            occlRef;       // reflection occlusion
        float            sInc;          // incidence based on shading normal
} LXpShadeOutput;
typedef struct st_LXpShadeDiffuse {
        LXtFVector       val;
} LXpShadeDiffuse;
typedef struct st_LXpShadeSpecular {
        LXtFVector       val;
} LXpShadeSpecular;
typedef struct st_LXpShadeMirror {
        LXtFVector       val;
} LXpShadeMirror;
typedef struct st_LXpShadeTransparency {
        LXtFVector       val;
} LXpShadeTransparency;
typedef struct st_LXpShadeSubsurface {
        LXtFVector       val;
} LXpShadeSubsurface;
typedef struct st_LXpShadeLuminosity {
        LXtFVector       val;
} LXpShadeLuminosity;
typedef struct st_LXpShadeFlags {
        void            *lightGroup;
        float            shadeRate, dirMult, indMult, indSat, alphaVal, eta, rndWidth;
        unsigned int     indType, alphaType, lightLink;
        unsigned int     flags;
        char             shadeEffect[32];
} LXpShadeFlags;
typedef struct st_LXpShadeFog {
        LXtFVector       fogCol;
        float            fogStart;
        float            fogEnd;
        float            fogDensity;
        unsigned int     fogType;
        unsigned int     fogEnv;
} LXpShadeFog;
typedef struct vt_ILxVectorPacket {
        ILxUnknown       iunk;
                LXxMETHOD(  unsigned int,
        Size) (
                LXtObjectID              self);

                LXxMETHOD(  const LXtGUID *,
        Interface) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        Initialize) (
                LXtObjectID              self,
                void                    *packet);

                LXxMETHOD(  void,
        Reset) (
                LXtObjectID              self,
                void                    *packet);

                LXxMETHOD(  LxResult,
        Copy) (
                LXtObjectID              self,
                void                    *packet,
                void                    *from);

                LXxMETHOD(  void,
        Cleanup) (
                LXtObjectID              self,
                void                    *packet);
                LXxMETHOD(  LxResult,
        Save) (
                LXtObjectID              self,
                void                    *packet,
                unsigned int             n,
                LXtObjectID              writestream);

                LXxMETHOD(  LxResult,
        Load) (
                LXtObjectID              self,
                void                    *packet,
                unsigned int             n,
                LXtObjectID              readstream);

                LXxMETHOD(  LxResult,
        Interpolate) (
                LXtObjectID              self,
                void                    *packet,
                void                    *p0,
                void                    *p1,
                float                    t);

                LXxMETHOD(  LxResult,
        Blend) (
                LXtObjectID              self,
                void                    *packet,
                void                    *p0,
                void                    *p1,
                float                    t,
                int                      mode);

                LXxMETHOD(  LxResult,
        Invert) (
                LXtObjectID              self,
                void                    *packet);
} ILxVectorPacket;
typedef struct vt_ILxPacketService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        Lookup) (
                LXtObjectID              self,
                const char              *category,
                const char              *name,
                unsigned int            *offset);

                LXxMETHOD(  LxResult,
        Name) (
                LXtObjectID              self,
                const char              *category,
                unsigned int             offset,
                const char             **name);

                LXxMETHOD(  void *,
        FastPacket) (
                LXtObjectID              self,
                LXtObjectID              vector,
                unsigned int             offset);
                LXxMETHOD( LxResult,
        CreateVectorType) (
                LXtObjectID              self,
                const char              *category,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        AddPacket) (
                LXtObjectID              self,
                LXtObjectID              vtype,
                const char              *name,
                unsigned int             flags);
} ILxPacketService;
typedef struct vt_ILxVectorType {
        ILxUnknown       iunk;
                LXxMETHOD(  const char *,
        Category) (
                LXtObjectID              self);

                LXxMETHOD(  unsigned int,
        Test) (
                LXtObjectID              self,
                unsigned int             offset);

                LXxMETHOD(  unsigned int,
        Count) (
                LXtObjectID              self,
                unsigned int             type);

                LXxMETHOD(  unsigned int,
        ByIndex) (
                LXtObjectID              self,
                unsigned int             type,
                unsigned int             index,
                unsigned int            *flags);
} ILxVectorType;
typedef struct vt_ILxVectorStack {
        ILxUnknown       iunk;
                LXxMETHOD(  void *,
        Optional) (
                LXtObjectID              self,
                unsigned int             offset);
                LXxMETHOD(  LxResult,
        Readable) (
                LXtObjectID              self,
                unsigned int             offset,
                void                   **packet);
                LXxMETHOD(  LxResult,
        Writable) (
                LXtObjectID              self,
                unsigned int             offset,
                void                   **packet);
                LXxMETHOD(  LxResult,
        SetPacket) (
                LXtObjectID              self,
                unsigned int             offset,
                void                    *pdat);

                LXxMETHOD(  LxResult,
        Push) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        Pop) (
                LXtObjectID              self);
} ILxVectorStack;
typedef struct vt_ILxVectorList {
        ILxUnknown       iunk;
                LXxMETHOD(  void *,
        Optional) (
                LXtObjectID              self,
                unsigned int             offset);
                LXxMETHOD(  LxResult,
        Readable) (
                LXtObjectID              self,
                unsigned int             offset,
                void                   **packet);
                LXxMETHOD(  LxResult,
        Writable) (
                LXtObjectID              self,
                unsigned int             offset,
                void                   **packet);
                LXxMETHOD(  LxResult,
        SetPacket) (
                LXtObjectID              self,
                unsigned int             offset,
                void                    *pdat);

                LXxMETHOD(  LxResult,
        Append) (
                LXtObjectID              self,
                unsigned int            *index);

                LXxMETHOD(  unsigned int,
        Current) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        SetCurrent) (
                LXtObjectID              self,
                unsigned int             index);

                LXxMETHOD(  unsigned int,
        Count) (
                LXtObjectID              self);

                LXxMETHOD(  void,
        Clear) (
                LXtObjectID              self);
} ILxVectorList;
typedef struct vt_ILxTextureEffect {
        ILxUnknown       iunk;
                LXxMETHOD(  unsigned int,
        Type) (
                LXtObjectID              self);

                LXxMETHOD(  const char *,
        TypeName) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        Get) (
                LXtObjectID              self,
                LXtObjectID              sv,
                float                   *val,
                void                    *item);

                LXxMETHOD(  LxResult,
        Set) (
                LXtObjectID              self,
                LXtObjectID              sv,
                const float             *val,
                void                    *item);
} ILxTextureEffect;
typedef struct vt_ILxPacketEffect {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Packet) (
                LXtObjectID              self,
                const char              **packet);

                LXxMETHOD(  unsigned int,
        Count) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        ByIndex) (
                LXtObjectID              self,
                int                      index,
                const char              **name,
                const char              **typeName,
                int                      *type);

                LXxMETHOD(  LxResult,
        Get) (
                LXtObjectID              self,
                int                      index,
                void                    *packet,
                float                   *val,
                void                    *item);

                LXxMETHOD(  LxResult,
        Set) (
                LXtObjectID              self,
                int                      index,
                void                    *packet,
                const float             *val,
                void                    *item);
} ILxPacketEffect;

#define LXu_VECTORPACKET        "F74C2B0E-4BC5-4E76-8F7D-1D64DA86FD28"
#define LXa_VECTORPACKET        "vectorPacket"
#define LXsVPK_CATEGORY         "vpacket.category"
// [export] ILxVectorPacket vpkt
#define LXu_PACKETSERVICE       "2B8D8867-4EFC-4A1D-8F6A-B5F103A90A9B"
#define LXfVT_SET        (1<<0)
#define LXfVT_GET        (1<<1)
#define LXfVT_OPTIONAL   (1<<2)
#define LXu_VECTORTYPE  "791B288F-DD69-11D7-857A-000A9593D716"
// [local]  ILxVectorType
// [export] ILxVectorType vtyp
#define LXu_VECTORSTACK "7915D133-4272-498B-A691-C98118F40FD5"
#define LXu_VECTORLIST  "F091C272-C770-42C3-B314-62EE90D34C57"
// [local]  ILxVectorList
// [local]  ILxVectorStack
#define LXsCATEGORY_SAMPLE       "sample"
#define LXfRAY_SCOPE_POLYGONS    0x00000001
#define LXfRAY_SCOPE_VOLUMETRICS 0x00000002
#define LXfRAY_SCOPE_ENVIRONMENT 0x00000004
#define LXfRAY_SCOPE_BACKFACE    0x00000010
#define LXfRAY_SCOPE_BACKONLY    0x00000020
#define LXfRAY_SCOPE_SAMESURF    0x00000040
#define LXfRAY_SCOPE_IMPLICITSURF        0x00000080

#define LXfRAY_EVAL_NORMAL       0x00000100
#define LXfRAY_EVAL_MATERIAL     0x00000200
#define LXfRAY_EVAL_OPACITY      0x00000400
#define LXfRAY_EVAL_SHADING      0x00000800
#define LXfRAY_EVAL_IRRADIANCE   0x00001000
#define LXfRAY_EVAL_PERSPENV     0x00002000

#define LXfRAY_TYPE_CAMERA       0x00010000
#define LXfRAY_TYPE_SHADOW       0x00020000
#define LXfRAY_TYPE_REFLECT      0x00040000
#define LXfRAY_TYPE_REFRACT      0x00080000
#define LXfRAY_TYPE_INDIRECT     0x00100000
#define LXfRAY_TYPE_CAUSTIC      0x00200000
#define LXfRAY_TYPE_SUBSURFACE   0x00400000
#define LXfRAY_TYPE_SHADOWMAP    0x00800000
#define LXfRAY_TYPE_TEXTURE      0x01000000
#define LXfRAY_TYPE_OCCLUSION    0x02000000
#define LXfRAY_TYPE_SHADOWVOL    0x04000000
#define LXfRAY_TYPE_CLIPPING     0x08000000
#define LXfRAY_TYPE_SHADOW_INFO  0x10000000
#define LXfFACET_OBJECT_POSITION        0x00000001
#define LXfFACET_DISPLACED              0x00000002
#define LXfFACET_NORMALIZED             0x00000004
#define LXsP_SAMPLE_POSITION    "sample.position"
#define LXsP_SAMPLE_XFRM        "sample.xfrm"
#define LXsP_SAMPLE_RAY         "sample.ray"
#define LXsP_SAMPLE_CLIP        "sample.clip"
#define LXsP_SAMPLE_PARMS       "sample.parms"
#define LXsP_SAMPLE_MASK        "sample.mask"
#define LXsP_SAMPLE_DRIVER      "sample.driver"
#define LXsP_SAMPLE_STENCIL     "sample.stencil"
#define LXsP_SAMPLE_VOLUME      "sample.volume"
#define LXsP_SAMPLE_DENSITY     "sample.density"
#define LXsP_SAMPLE_DISSOLVE    "sample.dissolve"
#define LXsP_SAMPLE_FACET       "sample.facet"
#define LXsP_SAMPLE_BUMP        "sample.bump"
#define LXiTILE_RESET           0
#define LXiTILE_REPEAT          1
#define LXiTILE_MIRROR          2
#define LXiTILE_EDGE            3
#define LXsP_TEXTURE_INPUT      "texture.input"
#define LXsP_TEXTURE_OUTPUT     "texture.output"
#define LXsP_TEXTURE_VALUE      "texture.value"
#define LXsP_TEXTURE_LOCATOR    "texture.locator"
#define LXsP_SURF_NORMAL        "surface.normal"
#define LXsP_SURF_SMOOTH        "surface.smoothing"
#define LXsP_DISPLACE    "displace"
#define LXsP_SHADER_TYPE         "shaderType"
#define LXsP_GROUP_LAYER         "groupLayer"
#define LXi_FUR_GUIDE_NONE               0
#define LXi_FUR_GUIDE_CLUMP              1
#define LXi_FUR_GUIDE_NORMAL             2
#define LXi_FUR_GUIDE_DIRLEN             3
#define LXi_FUR_GUIDE_SHAPE              4
#define LXi_FUR_GUIDE_INTERPOLATE        5
#define LXi_FUR_BILLBOARD_OFF            0
#define LXi_FUR_BILLBOARD_TREE           1
#define LXi_FUR_BILLBOARD_LEAF           2
#define LXsP_FUR_PARMS   "fur"
#define LXsP_PARTICLE_SAMPLE     "particleSample"
#define LXsP_SHADE_OPACITY      "shade.opacity"
#define LXsP_SHADE_COMPONENTS   "shade.components"
#define LXsP_SHADE_OUTPUT       "shade.output"
#define LXsP_SHADE_DIFFUSE      "shade.diffuse"
#define LXsP_SHADE_SPECULAR     "shade.specular"
#define LXsP_SHADE_MIRROR       "shade.mirror"
#define LXsP_SHADE_TRANSPARENCY "shade.transparency"
#define LXsP_SHADE_SUBSURFACE   "shade.subsurface"
#define LXsP_SHADE_LUMINOSITY   "shade.luminosity"
#define LXfSURF_DOUBLE           0x00000001
#define LXfSURF_TRANSP           0x00000002

#define LXfSURF_SHADCAST         0x00000010
#define LXfSURF_SHADRECV         0x00000020

#define LXfSURF_VISCAM           0x00000100
#define LXfSURF_VISIND           0x00000200
#define LXfSURF_VISREFL          0x00000400
#define LXfSURF_VISREFR          0x00000800
#define LXfSURF_VISSUBS          0x00001000
#define LXfSURF_VISOCCL          0x00002000

#define LXfSURF_PHYSICAL         0x00010000
#define LXfSURF_REFLSPEC         0x00020000
#define LXfSURF_REFLBLUR         0x00040000
#define LXfSURF_SAMESURF         0x00080000

#define LXfSURF_TANSHADE         0x00100000
#define LXfSURF_CLIPPING         0x00200000
#define LXfSURF_CMPSHADE         0x00400000
#define LXfSURF_IMPSHADE         0x00800000
#define LXfSURF_CLPMATTE         0x01000000

#define LXsP_SHADE_FLAGS         "surfFlags"
#define LXsP_SHADE_FOG   "surfFog"
#define SVPs_SURF_FOG    LXsP_SHADE_FOG
#define LXs_FX_ANISODIR         "anisoDir"
#define LXs_FX_BUMP             "bump"
#define LXs_FX_COATAMOUNT       "coatAmount"
#define LXs_FX_DIFFAMOUNT       "diffAmount"
#define LXs_FX_DIFFCOLOR        "diffColor"
#define LXs_FX_DIFFROUGH        "diffRough"
#define LXs_FX_DISPLACE         "displace"
#define LXs_FX_DRIVERA          "driverA"
#define LXs_FX_DRIVERB          "driverB"
#define LXs_FX_DRIVERC          "driverC"
#define LXs_FX_DRIVERD          "driverD"
#define LXs_FX_ENVALTITUDE      "envAltitude"
#define LXs_FX_ENVCOLOR         "envColor"
#define LXs_FX_GROUPMASK        "groupMask"
#define LXs_FX_LAYERMASK        "layerMask"
#define LXs_FX_LUMIAMOUNT       "lumiAmount"
#define LXs_FX_LUMICOLOR        "lumiColor"
#define LXs_FX_NORMAL           "normal"
#define LXs_FX_SPECAMOUNT       "specAmount"
#define LXs_FX_SPECCOLOR        "specColor"
#define LXs_FX_SPECFRESNEL      "specFresnel"
#define LXs_FX_STENCIL          "stencil"
#define LXs_FX_REFLAMOUNT       "reflAmount"
#define LXs_FX_REFLCOLOR        "reflColor"
#define LXs_FX_REFLFRESNEL      "reflFresnel"
#define LXs_FX_ROUGH            "rough"
#define LXs_FX_SUBSAMOUNT       "subsAmount"
#define LXs_FX_SUBSCOLOR        "subsColor"
#define LXs_FX_SP_DENSITY       "surfParticleDensity"
#define LXs_FX_SP_NORMAL        "surfParticleNormal"
#define LXs_FX_SP_HEADING       "surfParticleHeading"
#define LXs_FX_SP_SIZE          "surfParticleSize"
#define LXs_FX_PART_DENS        "particleDensity"
#define LXs_FX_PART_DISS        "particleDissolve"
#define LXs_FX_PART_SIZE        "particleSize"
#define LXs_FX_TRANAMOUNT       "tranAmount"
#define LXs_FX_TRANCOLOR        "tranColor"
#define LXs_FX_TRANROUGH        "tranRough"
#define LXs_FX_VECDISP          "vectorDisplace"
#define LXs_FX_RGBA             "RGBA"
#define LXs_FX_DISSOLVE         "dissolve"

#define LXs_FX_FUR_BEND         "furBend"
#define LXs_FX_FUR_BUMP         "furBump"
#define LXs_FX_FUR_CLDENS       "furClumpDensity"
#define LXs_FX_FUR_CLUMPS       "furClumps"
#define LXs_FX_FUR_CURLS        "furCurls"
#define LXs_FX_FUR_CYLINDERS    "cylinders"
#define LXs_FX_FUR_DENSITY      "furDensity"
#define LXs_FX_FUR_DIRECTION    "furDirection"
#define LXs_FX_FUR_FLEX         "furFlex"
#define LXs_FX_FUR_GROWJIT      "furGrowthJitter"
#define LXs_FX_FUR_KINK         "furKink"
#define LXs_FX_FUR_FRIZZ        "furFrizz"
#define LXs_FX_FUR_KINK_TIP     "furKinkTip"
#define LXs_FX_FUR_FRIZZ_TIP    "furFrizzTip"
#define LXs_FX_FUR_STRAYS       "furStrays"

#define LXs_FX_FUR_GUIDE_NONE       "none"
#define LXs_FX_FUR_GUIDE_DIRLENGTH  "dirlen"
#define LXs_FX_FUR_GUIDE_SHAPE      "shape"
#define LXs_FX_FUR_GUIDE_RANGE      "range"
#define LXs_FX_FUR_GUIDE_DIRECTION  "normal"
#define LXs_FX_FUR_GUIDE_CLUMP      "clump"

#define LXs_FX_FUR_LENGTH       "furLength"
#define LXs_FX_FUR_STRIPS       "strips"
#define LXs_FX_FUR_VECTOR       "furVector"
#define LXs_FX_OUTPUT_FINAL_COLOR                      "shade.color"
#define LXs_FX_OUTPUT_ALPHA                            "shade.alpha"
#define LXs_FX_OUTPUT_DIFFUSE_SHADING_TOTAL            "shade.diffuse"
#define LXs_FX_OUTPUT_DIFFUSE_SHADING_DIRECT           "shade.diffDir"
#define LXs_FX_OUTPUT_DIFFUSE_SHADING_INDIRECT         "shade.diffInd"
#define LXs_FX_OUTPUT_DIFFUSE_SHADING_UNSHADOWED       "shade.diffUns"
#define LXs_FX_OUTPUT_SPECULAR_SHADING                 "shade.specular"
#define LXs_FX_OUTPUT_REFLECTION_SHADING               "shade.reflection"
#define LXs_FX_OUTPUT_TRANSPARENT_SHADING              "shade.transparency"
#define LXs_FX_OUTPUT_SUBSURFACE_SHADING               "shade.subsurface"
#define LXs_FX_OUTPUT_LUMINOUS_SHADING                 "shade.luminosity"
#define LXs_FX_OUTPUT_VOL_SCATTERING                   "volume.scattering"
#define LXs_FX_OUTPUT_VOL_OPACITY                      "volume.opacity"
#define LXs_FX_OUTPUT_VOL_DEPTH                        "volume.depth"
#define LXs_FX_OUTPUT_DEPTH                            "depth"
#define LXs_FX_OUTPUT_MOTION                           "motion"
#define LXs_FX_OUTPUT_SHADOW_DENSITY                   "shadow"
#define LXs_FX_OUTPUT_AMBIENT_OCCLUSION                "occl.ambient"
#define LXs_FX_OUTPUT_REFLECTION_OCCLUSION             "occl.reflect"
#define LXs_FX_OUTPUT_SHADING_NORMAL                   "shade.normal"
#define LXs_FX_OUTPUT_SHADING_INCIDENCE                "shade.incidence"
#define LXs_FX_OUTPUT_GEOMETRIC_NORMAL                 "geo.normal"
#define LXs_FX_OUTPUT_SURFACE_ID                       "geo.surface"
#define LXs_FX_OUTPUT_SEGMENT_ID                       "geo.segment"
#define LXs_FX_OUTPUT_OBJECT_COORDINATES               "geo.object"
#define LXs_FX_OUTPUT_WORLD_COORDINATES                "geo.world"
#define LXs_FX_OUTPUT_UV_COORDINATES                   "geo.uv"
#define LXs_FX_OUTPUT_DPDU_VECTOR                      "geo.dpdu"
#define LXs_FX_OUTPUT_DPDV_VECTOR                      "geo.dpdv"
#define LXs_FX_OUTPUT_IC_POSITIONS                     "ic.position"
#define LXs_FX_OUTPUT_IC_VALUES                        "ic.value"
#define LXs_FX_OUTPUT_DIFFUSE_COEFFICIENT              "mat.diffuse"
#define LXs_FX_OUTPUT_SPECULAR_COEFFICIENT             "mat.specular"
#define LXs_FX_OUTPUT_REFLECTION_COEFFICIENT           "mat.reflection"
#define LXs_FX_OUTPUT_ILLUMINATION_SHADING_TOTAL       "shade.illum"
#define LXs_FX_OUTPUT_ILLUMINATION_SHADING_DIRECT      "shade.illumDir"
#define LXs_FX_OUTPUT_ILLUMINATION_SHADING_INDIRECT    "shade.illumInd"
#define LXs_FX_OUTPUT_ILLUMINATION_SHADING_UNSHADOWED  "shade.illumUns"
#define LXs_FX_OUTPUT_SHADING_SAMPLES                  "shade.samples"
#define LXs_FX_SHADER_FULL_SHADING          "fullShade"
#define LXs_FX_SHADER_DIFFUSE_SHADING       "diffShade"
#define LXs_FX_SHADER_SPECULAR_SHADING      "specShade"
#define LXs_FX_SHADER_REFLECTION_SHADING    "reflShade"
#define LXs_FX_SHADER_TRANSPARENT_SHADING   "tranShade"
#define LXs_FX_SHADER_SUBSURFACE_SHADING    "subsShade"
#define LXs_FX_SHADER_LUMINOUS_SHADING      "lumiShade"
#define LXs_FX_SHADER_FOG_SHADING           "fogShade"
#define LXsSHADE_SURFACE        "surface"
#define LXsSHADE_LIGHT          "light"
#define LXsSHADE_ENVIRONMENT    "environment"
#define LXsSHADE_PROCEDURAL     "procedural"
#define LXsSHADE_OUTPUT         "output"
#define LXsSHADE_CAMERA         "camera"
#define LXsSHADE_SCENE          "scene" 
#define LXi_TFX_SCALAR          0
#define LXi_TFX_COLOR           1

#define LXf_TFX_READ            0x10
#define LXf_TFX_WRITE           0x20
#define LXf_TFX_INPUT           0x40
#define LXf_TFX_BW              0x80
#define LXu_TEXTUREEFFECT       "CA13032E-3855-4744-B77A-59530EC3E260"
#define LXa_TEXTUREEFFECT       "textureEffect"
#define LXsTFX_CATEGORY         "textureFX.category"
// [export] ILxTextureEffect tfx
// [local]  ILxTextureEffect
#define LXu_PACKETEFFECT        "7e8a37ce-618b-4ae4-a429-01317ac40eb0"
#define LXa_PACKETEFFECT        "packetEffect"
// [export] ILxPacketEffect pfx
// [local]  ILxPacketEffect

 #ifdef __cplusplus
  }
 #endif
#endif

