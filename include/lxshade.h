/*
 * LX shade module
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
#ifndef LX_shade_H
#define LX_shade_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxTextureLayer ** ILxTextureLayerID;
typedef struct vt_ILxTextureEval ** ILxTextureEvalID;
typedef struct vt_ILxTextureVMap ** ILxTextureVMapID;
typedef struct vt_ILxTextureMask ** ILxTextureMaskID;
typedef struct vt_ILxTextureGL ** ILxTextureGLID;
typedef struct vt_ILxValueTexture ** ILxValueTextureID;
typedef struct vt_ILxValueTextureCustom ** ILxValueTextureCustomID;
typedef struct vt_ILxCompShader ** ILxCompShaderID;
typedef struct vt_ILxCustomMaterial ** ILxCustomMaterialID;
typedef struct vt_ILxTexture ** ILxTextureID;
#include <lxcom.h>
#include <lximage.h>
#include <lxvector.h>
#include <lxraycast.h>    

typedef struct st_MeshBin *             LXtMeshBinID;
typedef struct st_LXtPreviewEvent {
        int              flags;
        ILxImageID       image;
        void            *item;
        void            *cine;
        void            *bin;
        int              chan;
} LXtPreviewEvent;
typedef struct vt_ILxTextureLayer {
        ILxUnknown       iunk;
                LXxMETHOD( int,
        Flags) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        VectorType) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( int,
        Preview) (
                LXtObjectID              self,
                LXtPreviewEvent         *event);

                LXxMETHOD( LxResult,
        PrepFilter) (
                LXtObjectID              self,
                LXtObjectID              eval);

                LXxMETHOD( LxResult,
        AllocFilter) (
                LXtObjectID              self,
                LXtObjectID              attr,
                int                     *offset,
                int                      chan,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        AllocTexture) (
                LXtObjectID              self,
                LXtObjectID              attr,
                int                      offset,
                void                   **ppvObj);
} ILxTextureLayer;
typedef struct vt_ILxTextureEval {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Setup) (
                LXtObjectID              self,
                int                      slice);

                LXxMETHOD( void,
        Cleanup) (
                LXtObjectID              self);

                LXxMETHOD( void,
        Evaluate) (
                LXtObjectID              self,
                LXtObjectID              vs,
                int                      slice);

                LXxMETHOD( void,
        Output) (
                LXtObjectID              self,
                LXtObjectID              vtOutput,
                LXtObjectID             *vtSubset);

                LXxMETHOD( int,
        Slice) (
                LXtObjectID              self,
                LXtObjectID              vtOutput,
                LXtObjectID              tvDesc,
                LXtMeshBinID             meshbin,
                int                      srfType);

                LXxMETHOD( void,
        Select) (
                LXtObjectID              self,
                LXtObjectID              teElt, 
                LXtObjectID              tvDesc,
                LXtMeshBinID             meshbin,
                int                      srfType);

                LXxMETHOD( int,
        Smoothing) (
                LXtObjectID              self,
                double                  *smooth,
                double                  *angle);

                LXxMETHOD( int,
        Layer) (
                LXtObjectID              self,
                double                  *opa,
                int                     *invert,
                int                     *blend);

                LXxMETHOD( int,
        Opaque) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        VType) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        Effect) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        Item) (
                LXtObjectID              self,
                void                   **item);

                LXxMETHOD( int,
        Implicit) (
                LXtObjectID              self);

                LXxMETHOD( int,
        Shader) (
                LXtObjectID              self);

                LXxMETHOD( int,
        Material) (
                LXtObjectID              self);
} ILxTextureEval;
typedef struct vt_ILxTextureVMap {
        ILxUnknown       iunk;
                LXxMETHOD( unsigned,
        Count) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Name) (
                LXtObjectID              self,
                unsigned                 index,
                const char             **name);

                LXxMETHOD( LXtID4,
        Type) (
                LXtObjectID              self,
                unsigned                 index);
} ILxTextureVMap;
typedef struct vt_ILxTextureMask {
        ILxUnknown       iunk;
                LXxMETHOD( LXtID4,
        Tag) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        String) (
                LXtObjectID              self,
                const char             **name);

                LXxMETHOD( LxResult,
        Object) (
                LXtObjectID              self,
                void                   **item);

                LXxMETHOD( unsigned,
        Type) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Stack) (
                LXtObjectID              self,
                void                   **stack);

                LXxMETHOD( int,
        ApplyToSub) (
                LXtObjectID              self);
} ILxTextureMask;
typedef struct vt_ILxTextureGL {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Evaluate) (
                LXtObjectID              self,
                LXtMeshBinID             bin,
                void                    *gls);

                LXxMETHOD( int,
        IsShader) (
                LXtObjectID              self,
                LXtMeshBinID             bin);
} ILxTextureGL;
typedef struct vt_ILxValueTexture {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        SetupChannels) (
                LXtObjectID              self,
                LXtObjectID              addChan);

                LXxMETHOD( LxResult,
        LinkChannels) (
                LXtObjectID              self,
                LXtObjectID              eval,
                LXtObjectID              item);

                LXxMETHOD( LxResult,
        ReadChannels) (
                LXtObjectID              self,
                LXtObjectID              attr,
                void                   **ppvData);

                LXxMETHOD( LxResult,
        Customize) (
                LXtObjectID              self,
                LXtObjectID              custom,
                void                   **ppvData);

                LXxMETHOD( void,
        Evaluate) (
                LXtObjectID              self,
                LXtObjectID              vector,
                LXpTextureOutput        *tOut,
                void                    *data);

                LXxMETHOD( void,
        Cleanup) (
                LXtObjectID              self,
                void                    *data);
} ILxValueTexture;
typedef struct vt_ILxValueTextureCustom {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        AddFeature) (
                LXtObjectID              self,
                LXtID4                   type,
                const char              *name);

                LXxMETHOD( LxResult,
        AddPacket) (
                LXtObjectID              self,
                const char              *name);
} ILxValueTextureCustom;
typedef struct vt_ILxCompShader {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        SetupChannels) (
                LXtObjectID              self,
                LXtObjectID              addChan);

                LXxMETHOD( LxResult,
        LinkChannels) (
                LXtObjectID              self,
                LXtObjectID              eval,
                LXtObjectID              item);

                LXxMETHOD( LxResult,
        ReadChannels) (
                LXtObjectID              self,
                LXtObjectID              attr,
                void                   **ppvData);

                LXxMETHOD( LxResult,
        Customize) (
                LXtObjectID              self,
                LXtObjectID              custom,
                void                   **ppvData);

                LXxMETHOD( void,
        Evaluate) (
                LXtObjectID              self,
                LXtObjectID              vector,
                LXtObjectID              rayObj,
                LXpShadeComponents      *sCmp,
                LXpShadeOutput          *sOut,
                void                    *data);

                LXxMETHOD( LxResult,
        SetShadeFlags) (
                LXtObjectID              self,
                LXpShadeFlags           *sFlg);

                LXxMETHOD( LxResult,
        SetOpaque) (
                LXtObjectID              self,
                int                     *opaque);

                LXxMETHOD( LxResult,
        CustomPacket) (
                LXtObjectID              self,
                const char              **packet);      

                LXxMETHOD( void,
        Cleanup) (
                LXtObjectID              self,
                void                    *data);
} ILxCompShader;
typedef struct vt_ILxCustomMaterial {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        SetupChannels) (
                LXtObjectID              self,
                LXtObjectID              addChan);

                LXxMETHOD( LxResult,
        LinkChannels) (
                LXtObjectID              self,
                LXtObjectID              eval,
                LXtObjectID              item);

                LXxMETHOD( LxResult,
        ReadChannels) (
                LXtObjectID              self,
                LXtObjectID              attr,
                void                   **ppvData);

                LXxMETHOD( LxResult,
        Customize) (
                LXtObjectID              self,
                LXtObjectID              custom,
                void                   **ppvData);

                LXxMETHOD( void,
        MaterialEvaluate) (
                LXtObjectID              self,
                LXtObjectID              vector,
                void                    *data);

                LXxMETHOD( void,
        ShaderEvaluate) (
                LXtObjectID              self,
                LXtObjectID              vector,
                LXtObjectID              rayObj,
                LXpShadeComponents      *sCmp,
                LXpShadeOutput          *sOut,
                void                    *data);

                LXxMETHOD( LxResult,
        SetShadeFlags) (
                LXtObjectID              self,
                LXpShadeFlags           *sFlg);

                LXxMETHOD( LxResult,
        SetBump) (
                LXtObjectID              self,
                float                   *bumpAmplitude,
                int                     *clearBump);

                LXxMETHOD( LxResult,
        SetDisplacement) (
                LXtObjectID              self,
                float                   *dispDist);

                LXxMETHOD( LxResult,
        SetOpaque) (
                LXtObjectID              self,
                int                     *opaque);

                LXxMETHOD( LxResult,
        SetSmoothing) (
                LXtObjectID              self,
                double                  *smooth,
                double                  *angle);

                LXxMETHOD( LxResult,
        CustomPacket) (
                LXtObjectID              self,
                const char              **packet);

                LXxMETHOD( void,
        Cleanup) (
                LXtObjectID              self,
                void                    *data);

                LXxMETHOD( LxResult,
        UpdatePreview) (
                LXtObjectID              self,
                int                      chanIdx,
                int                     *flags);
} ILxCustomMaterial;
typedef struct vt_ILxTexture {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Locator) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        SetLocator) (
                LXtObjectID              self,
                LXtObjectID              tloc);

                LXxMETHOD(  LxResult,
        Image) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        SetImage) (
                LXtObjectID              self,
                LXtObjectID              img);

                LXxMETHOD(  const char *,
        ImageName) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        EvalImage) (
                LXtObjectID              self,
                LXtObjectID              scene,
                void                   **ppvObj);

                LXxMETHOD(  int,
        LocatorProjectionMode) (
                LXtObjectID              self,
                double                   time);

                LXxMETHOD(  int,
        LocatorProjectionAxis) (
                LXtObjectID              self,
                double                   time);

                LXxMETHOD(  const char *,
        Effect) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        SetEffect) (
                LXtObjectID              self,
                const char              *effect);
} ILxTexture;

#define LXi_SURF_ALL                    0
#define LXi_SURF_TRIANGLE               1
#define LXi_SURF_FUR                    2
#define LXfPREV_EVENT_MESH              0x01
#define LXfPREV_EVENT_ITEM              0x02
#define LXfPREV_EVENT_IMAGE             0x04
#define LXfPREV_EVENT_CINE              0x08
#define LXfPREV_EVENT_MESH_FEATURE      0x10
#define LXfPREV_EVENT_MESH_BIN          0x20
#define LXfPREV_UPDATE_GEOMETRY         0x01 // geometry change on an entire item
#define LXfPREV_UPDATE_SHADING          0x02 // surface shader change
#define LXfPREV_UPDATE_BACKDROP         0x04 // environment change
#define LXfPREV_UPDATE_IMAGE            0x08 // image edit
#define LXfPREV_UPDATE_CAMERA           0x10 // camera change (liek during camera navigtion)
#define LXfPREV_UPDATE_CLIP             0x20 // clip change
#define LXfPREV_UPDATE_LIGHT            0x40 // light item change
#define LXfPREV_UPDATE_LIGHT_SHADER     0x80 // light shader change
#define LXfPREV_UPDATE_VERTEX_FEATURE   0x100 // vertex feature change in the tableau
#define LXfPREV_UPDATE_IRRCACHE         0x200 // irradiance cache change
#define LXfPREV_UPDATE_SURFACE          0x400 // geometry change limited to a surface
#define LXfPREV_UPDATE_VOLUME           0x8000 // volume item change

#define LXfPREV_UPDATE_FORCE            0XFFFF // All flags
#define LXu_TEXTURELAYER        "42369FE7-869E-4c61-8D40-AC62E529DD15"
#define LXa_TEXTURELAYER        "textureLayer"
#define LXsTLR_CATEGORY         "textureLayer.category"
#define LXu_TEXTUREEVAL         "847C1567-1725-4e98-BA09-EA1F9049D76A"
#define LXa_TEXTUREEVAL         "textureEval"
#define LXu_TEXTUREVMAP         "0C68AC79-993C-4823-97FA-EAD5EFF97B64"
#define LXa_TEXTUREVMAP         "textureVMap"
#define LXu_TEXTUREMASK         "701E81D3-FFA6-475a-A02D-ECE9AB15B4CD"
#define LXa_TEXTUREMASK         "textureMask"
#define LXu_TEXTUREGL           "55CE355E-C838-4222-ABED-CBDD808209AF"
#define LXa_TEXTUREGL           "textureGL"
#define LXu_VALUETEXTURE        "CA0E3524-6F82-44B8-AAC9-DC258F548C02"
#define LXa_VALUETEXTURE        "valueTexture"
#define LXu_VALUETEXTURECUSTOM  "DE3298A6-1607-4338-B061-185528E6FB51"
// [export]  ILxValueTexture vtx
// [local]   ILxValueTextureCustom
#define LXu_COMPSHADER          "06717e9d-610d-439f-935b-af0805827ede"
#define LXa_COMPSHADER          "compShader"
// [export]  ILxCompShader csh
#define LXu_CUSTOMMATERIAL              "d0c4106c-dfd5-4a58-ad48-45b50ae63f59"
#define LXa_CUSTOMMATERIAL              "customMaterial"
// [export]  ILxCustomMaterial cmt
#define LXa_TEXTURE     "texture"
#define LXu_TEXTURE     "6376D941-9437-4cf8-B6EC-AB50791FE60F"
// [local]  ILxTexture
#define LXi_TEXTURE_PROJ_MODE_NONE              0
#define LXi_TEXTURE_PROJ_MODE_PLANAR            1
#define LXi_TEXTURE_PROJ_MODE_CYLINDRICAL       2
#define LXi_TEXTURE_PROJ_MODE_SPHERICAL         3
#define LXi_TEXTURE_PROJ_MODE_CUBIC             4
#define LXi_TEXTURE_PROJ_MODE_FRONT             5
#define LXi_TEXTURE_PROJ_MODE_UVMAP             6
#define LXi_TEXTURE_PROJ_MODE_LIGHTPROBE        7
#define LXi_TEXTURE_PROJ_MODE_IMPLICIT          8
#define LXi_TEXTURE_PROJ_MODE_BOX               9

#define LXi_TEXTURE_PROJ_DIR_X                  0
#define LXi_TEXTURE_PROJ_DIR_Y                  1
#define LXi_TEXTURE_PROJ_DIR_Z                  2


 #ifdef __cplusplus
  }
 #endif
#endif

