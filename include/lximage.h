/*
 * LX image module
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
#ifndef LX_image_H
#define LX_image_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxImage ** ILxImageID;
typedef struct vt_ILxImageSegment ** ILxImageSegmentID;
typedef struct vt_ILxImageWrite ** ILxImageWriteID;
typedef struct vt_ILxIndexImage ** ILxIndexImageID;
typedef struct vt_ILxIndexImageWrite ** ILxIndexImageWriteID;
typedef struct vt_ILxLayeredImage ** ILxLayeredImageID;
typedef struct vt_ILxLayeredImageWrite ** ILxLayeredImageWriteID;
typedef struct vt_ILxTileImage ** ILxTileImageID;
typedef struct vt_ILxImageLoaderTarget ** ILxImageLoaderTargetID;
typedef struct vt_ILxImageLevelSample ** ILxImageLevelSampleID;
typedef struct vt_ILxImageService ** ILxImageServiceID;
typedef struct vt_ILxImageBlockCodec ** ILxImageBlockCodecID;
typedef struct vt_ILxImageFilter ** ILxImageFilterID;
typedef struct vt_ILxImageFilterSample ** ILxImageFilterSampleID;
typedef struct vt_ILxImageFilterMetrics ** ILxImageFilterMetricsID;
typedef struct vt_ILxMovie ** ILxMovieID;
#include <lxcom.h>
#include <lxio.h>
#include <lxserver.h>
#include <lxvmath.h>

typedef unsigned int     LXtPixelFormat;
typedef unsigned int     LXtProcessHint;
typedef unsigned char    LXtImageByte;
typedef float            LXtImageFloat;
typedef unsigned int     LXtImageIndex;
typedef LXtImageFloat    LXtColorRGBA[4];
typedef struct st_LXtImageTarget1 {
        LXtPixelFormat           type;
        unsigned int             w, h, ncolor;
} LXtImageTarget1;
typedef struct st_LXtImageSample {
        unsigned                 x;
        unsigned                 y;
        LXtImageFloat           *rgba;
} LXtImageSample;
typedef struct st_LXtImageMetrics {
        int              maxRes[2];
        int              pixelType;
        double           aspect;
        char             filename[512], format[512];
} LXtImageMetrics;
typedef struct vt_ILxImage {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        Size) (
                LXtObjectID              self,
                unsigned int            *w,
                unsigned int            *h);

                LXxMETHOD( LXtPixelFormat,
        Format) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        GetPixel) (
                LXtObjectID              self,
                unsigned int             x,
                unsigned int             y,
                LXtPixelFormat           type,
                void                    *pixel);

                LXxMETHOD( const void *,
        GetLine) (
                LXtObjectID              self,
                unsigned int             y,
                LXtPixelFormat           type,
                void                    *buf);
} ILxImage;
typedef struct vt_ILxImageSegment {
        ILxUnknown       iunk;


                LXxMETHOD( LxResult,
        GetSegment) (
                LXtObjectID              self,
                unsigned int             y,
                unsigned int             left,
                unsigned int             right,
                LXtImageFloat           *rgba);

                LXxMETHOD( LxResult,
        SetSegment) (
                LXtObjectID              self,
                unsigned int             y,
                unsigned int             left,
                unsigned int             right,
                LXtPixelFormat           type,
                const void              *line);
} ILxImageSegment;
typedef struct vt_ILxImageWrite {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        Size) (
                LXtObjectID              self,
                unsigned int            *w,
                unsigned int            *h);

                LXxMETHOD( LXtPixelFormat,
        Format) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        AddAttribute) (
                LXtObjectID              self,
                const char              *name,
                const char              *type,
                unsigned                *index);

                LXxMETHOD( LxResult,
        SetPixel) (
                LXtObjectID              self,
                unsigned int             x,
                unsigned int             y,
                LXtPixelFormat           type,
                const void              *pixel);

                LXxMETHOD( LxResult,
        SetLine) (
                LXtObjectID              self,
                unsigned int             y,
                LXtPixelFormat           type,
                const void              *line);

} ILxImageWrite;
typedef struct vt_ILxIndexImage {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        Size) (
                LXtObjectID              self,
                unsigned int            *w,
                unsigned int            *h);

                LXxMETHOD( LXtPixelFormat,
        Format) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        MapSize) (
                LXtObjectID              self,
                unsigned                *numColors);

                LXxMETHOD( LxResult,
        GetIndex) (
                LXtObjectID              self,
                unsigned int             x,
                unsigned int             y,
                LXtImageIndex           *index);

                LXxMETHOD( LxResult,
        GetMap) (
                LXtObjectID              self,
                LXtImageIndex            index,
                LXtPixelFormat           type,
                void                    *pixel);
} ILxIndexImage;
typedef struct vt_ILxIndexImageWrite {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        Size) (
                LXtObjectID              self,
                unsigned int            *w,
                unsigned int            *h);

                LXxMETHOD( LXtPixelFormat,
        Format) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        AddAttribute) (
                LXtObjectID              self,
                const char              *name,
                const char              *type,
                unsigned                *index);

                LXxMETHOD( LxResult,
        SetIndex) (
                LXtObjectID              self,
                unsigned int             x,
                unsigned int             y,
                LXtImageIndex            index);

                LXxMETHOD( LxResult,
        SetMap) (
                LXtObjectID              self,
                LXtImageIndex            index,
                LXtPixelFormat           type,
                const void              *pixel);

} ILxIndexImageWrite;
typedef struct vt_ILxLayeredImage {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        Size) (
                LXtObjectID              self,
                unsigned int            *w,
                unsigned int            *h);
                LXxMETHOD( unsigned int,
        Count) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Image) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        Name) (
                LXtObjectID              self,
                unsigned int             index,
                const char             **name);

                LXxMETHOD( LxResult,
        Type) (
                LXtObjectID              self,
                unsigned int             index,
                unsigned int            *flags,
                const char             **type);
                LXxMETHOD( LxResult,
        Offset) (
                LXtObjectID              self,
                unsigned int             index,
                int                     *x,
                int                     *y);

                LXxMETHOD( LxResult,
        Blend) (
                LXtObjectID              self,
                unsigned int             index,
                float                   *blend,
                const char              *mode);
                LXxMETHOD( LxResult,
        ChannelName) (
                LXtObjectID              self,
                unsigned                 layerIndex,
                unsigned                 channelIndex,
                const char              **name);
} ILxLayeredImage;
typedef struct vt_ILxLayeredImageWrite {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        AddLayer) (
                LXtObjectID              self,
                LXtObjectID              image,
                const char              *name,
                const char              **channelNames);

                LXxMETHOD( LxResult,
        SetType) (
                LXtObjectID              self,
                unsigned int             index,
                int                      flags,
                const char              *type);

                LXxMETHOD( LxResult,
        SetOffset) (
                LXtObjectID              self,
                unsigned int             index,
                int                      x,
                int                      y);

                LXxMETHOD( LxResult,
        SetBlending) (
                LXtObjectID              self,
                unsigned int             index,
                float                    blend,
                const char              *mode);

                LXxMETHOD(  LxResult,
        AddAttribute) (
                LXtObjectID              self,
                const char              *name,
                const char              *type,
                int                     *index);

} ILxLayeredImageWrite;
typedef struct vt_ILxTileImage {
        ILxUnknown       iunk;
                LXxMETHOD( unsigned,
        LevelCount) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        GetTile) (
                LXtObjectID               self,
                unsigned int              level,
                unsigned int              tileX,
                unsigned int              tileY,
                void                    **ppvObj);
                LXxMETHOD( LxResult,
        GetTileSize) (
                LXtObjectID              self,
                unsigned int             level,
                unsigned int             tileX,
                unsigned int             tileY,
                unsigned int            *width,
                unsigned int            *height);
                LXxMETHOD( LxResult,
        GetLevelSize) (
                LXtObjectID              self,
                unsigned int             level,
                unsigned int            *width,
                unsigned int            *height,
                unsigned int            *tilesWidth,
                unsigned int            *tilesHeight);
                LXxMETHOD( LxResult,
        DetermineTile) (
                LXtObjectID              self,
                unsigned int             level,
                unsigned int             x,
                unsigned int             y,
                unsigned int            *tileX,
                unsigned int            *tileY);
                LXxMETHOD( LxResult,
        DeterminePixel) (
                LXtObjectID              self,
                unsigned int             level,
                unsigned int             x,
                unsigned int             y,
                unsigned int            *adjX,
                unsigned int            *adjY);
} ILxTileImage;
typedef struct vt_ILxImageLoaderTarget {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        SetSize) (
                LXtObjectID              self,
                LXtPixelFormat           type,
                unsigned                 width,
                unsigned                 height);

                LXxMETHOD( LxResult,
        SetMap) (
                LXtObjectID              self,
                unsigned                 ncolor);
} ILxImageLoaderTarget;
typedef struct vt_ILxImageLevelSample {
        ILxUnknown       iunk;
                LXxMETHOD( unsigned,
        Count) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        GetLevelSize) (
                LXtObjectID              self,
                unsigned                 level,
                unsigned                *width,
                unsigned                *height);
                LXxMETHOD( LxResult,
        SampleLevel) (
                LXtObjectID              self,
                unsigned                 level,
                LXtImageSample          *pixel,
                unsigned                 num);
                LXxMETHOD( LxResult,
        GetPixel) (
                LXtObjectID              self,
                unsigned                 level,
                unsigned int             x,
                unsigned int             y,
                LXtPixelFormat           type,
                void                    *pixel);
                LXxMETHOD( const LXtImageFloat *,
        GetLine) (
                LXtObjectID              self,
                unsigned                 level,
                unsigned                 y,
                LXtImageFloat           *buf);
} ILxImageLevelSample;
typedef struct vt_ILxImageService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        Create) (
                LXtObjectID              self,
                unsigned int             width,
                unsigned int             height,
                LXtPixelFormat           type,
                unsigned int             maxIndex,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        Duplicate) (
                LXtObjectID              self,
                LXtObjectID              source,
                LXtPixelFormat           type,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        Load) (
                LXtObjectID              self,
                const char              *filePath,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        Save) (
                LXtObjectID              self,
                LXtObjectID              image,
                const char              *filePath,
                const char              *format,
                LXtObjectID              monitor);

                LXxMETHOD(  LxResult,
        Resample) (
                LXtObjectID              self,
                LXtObjectID              dest,
                LXtObjectID              source,
                LXtProcessHint           hint);

                LXxMETHOD(  LxResult,
        Composite) (
                LXtObjectID              self,
                LXtObjectID              dest,
                LXtObjectID              source,
                const LXtFVector2        pos);

                LXxMETHOD(  LxResult,
        DrawLine) (
                LXtObjectID              self,
                LXtObjectID              image,
                const LXtFVector2        p0,
                const LXtFVector2        p1,
                const LXtFVector         color);

                LXxMETHOD(  LxResult,
        Kelvin2RGB) (
                LXtObjectID              self,
                float                    kelvin,
                LXtFVector               rgbColor);

                LXxMETHOD(  LxResult,
        RGB2Kelvin) (
                LXtObjectID              self,
                const LXtFVector         rgbColor,
                float                   *kelvin);

                LXxMETHOD(  LxResult,
        CreateCrop) (
                LXtObjectID              self,
                LXtObjectID              sourceImage,
                double                   x,
                double                   y,
                double                   w,
                double                   h,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ImageGetBuffer) (
                LXtObjectID              self,
                LXtObjectID              sourceImage,
                LXtPixelFormat           type,
                void                    *buf);
} ILxImageService;
typedef struct vt_ILxImageBlockCodec {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Compress) (
                LXtObjectID              self,
                LXtObjectID              image,
                unsigned char          **buf,
                int                     *size);

                LXxMETHOD(  void,
        Free) (
                LXtObjectID              self,
                unsigned char           *buf,
                int                      size);

                LXxMETHOD(  LxResult,
        Decompress) (
                LXtObjectID              self,
                unsigned char           *buf,
                int                      size,
                void                   **ppvObj);
} ILxImageBlockCodec;
typedef struct vt_ILxImageFilter {
        ILxUnknown       iunk;
                LXxMETHOD(  unsigned int,
        Type) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        Generate) (
                LXtObjectID              self,
                int                      width,
                int                      height,
                LXtObjectID              monitor,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        MultiSample) (
                LXtObjectID              self,
                LXtObjectID              monitor,
                LXtObjectID              image,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        SingleSample) (
                LXtObjectID              self,
                const LXtColorRGBA       src,
                LXtColorRGBA             dest);
} ILxImageFilter;
typedef struct vt_ILxImageFilterSample {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        SpotSample) (
                LXtObjectID              self,
                float                    x,
                float                    y,
                float                    spotSize,
                float                   *rgba);
} ILxImageFilterSample;
typedef struct vt_ILxImageFilterMetrics {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Generate) (
                LXtObjectID              self,
                LXtImageMetrics         *metrics);

                LXxMETHOD(  LxResult,
        Evaluate) (
                LXtObjectID              self,
                LXtImageMetrics         *metrics);
} ILxImageFilterMetrics;
typedef struct vt_ILxMovie {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        BeginMovie) (
                LXtObjectID              self,
                const char              *fname,
                int                      w,
                int                      h,
                int                      flags);
                LXxMETHOD(  LxResult,
        SetFramerate) (
                LXtObjectID              self,
                int                      frate);
                LXxMETHOD(  LxResult,
        AddImage) (
                LXtObjectID              self,
                LXtObjectID              image);
                LXxMETHOD(  LxResult,
        EndMovie) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        AddAudio) (
                LXtObjectID              self,
                LXtObjectID              audio);
} ILxMovie;

#define LXiIMD_BYTE     0x00
#define LXiIMD_FLOAT    0x08
#define LXfIMD_MASK     0x08

#define LXxIMD_TYPE(t)  (t & LXfIMD_MASK)
#define LXiIMV_GREY     0x01
#define LXiIMV_RGB      0x03
#define LXiIMV_RGBA     0x04
#define LXfIMV_MASK     0x07

#define LXxIMV_TYPE(v)  (v & LXfIMV_MASK)
#define LXiIMT_INDEX    0x100
#define LXiIMT_MASK     0x100
#define LXiIMP_GREY8    (LXiIMD_BYTE  | LXiIMV_GREY)
#define LXiIMP_GREYFP   (LXiIMD_FLOAT | LXiIMV_GREY)
#define LXiIMP_RGB24    (LXiIMD_BYTE  | LXiIMV_RGB)
#define LXiIMP_RGBFP    (LXiIMD_FLOAT | LXiIMV_RGB)
#define LXiIMP_RGBA32   (LXiIMD_BYTE  | LXiIMV_RGBA)
#define LXiIMP_RGBAFP   (LXiIMD_FLOAT | LXiIMV_RGBA)

#define LXiIMP_IGREY8   (LXiIMD_BYTE  | LXiIMV_GREY | LXiIMT_INDEX)
#define LXiIMP_IRGB24   (LXiIMD_BYTE  | LXiIMV_RGB  | LXiIMT_INDEX)
#define LXiIMP_IRGBA32  (LXiIMD_BYTE  | LXiIMV_RGBA | LXiIMT_INDEX)
#define LXiPROCESS_FAST         0
#define LXiPROCESS_MEDIUM       1
#define LXiPROCESS_ACCURATE     2
#define LXiIMC_RED      0
#define LXiIMC_GREEN    1
#define LXiIMC_BLUE     2
#define LXiIMC_ALPHA    3
#define LXsIATTRNAME_DPI        "DPI"
#define LXsIATTRTYPE_DPI         LXsTYPE_FLOAT

#define LXsIATTRNAME_PIXASPECT  "pixelAspect"
#define LXsIATTRTYPE_PIXASPECT   LXsTYPE_FLOAT

#define LXsIATTRNAME_REGX0      "regionX0"
#define LXsIATTRTYPE_REGX0       LXsTYPE_INTEGER

#define LXsIATTRNAME_REGX1      "regionX1"
#define LXsIATTRTYPE_REGX1       LXsTYPE_INTEGER

#define LXsIATTRNAME_REGY0      "regionY0"
#define LXsIATTRTYPE_REGY0       LXsTYPE_INTEGER

#define LXsIATTRNAME_REGY1      "regionY1"
#define LXsIATTRTYPE_REGY1       LXsTYPE_INTEGER

#define LXsIATTRNAME_GAMMA      "gamma"
#define LXsIATTRTYPE_GAMMA       LXsTYPE_FLOAT

#define LXsIATTRNAME_COMMENT    "comment"
#define LXsIATTRTYPE_COMMENT     LXsTYPE_STRING
#define LXsIATTRNAME_LUMA       "luminance"
#define LXsIATTRTYPE_LUMA        LXsTYPE_FLOAT

#define LXsIATTRNAME_FOCDIST    "focusDist"
#define LXsIATTRTYPE_FOCDIST     LXsTYPE_FLOAT

#define LXsIATTRNAME_APERTURE   "aperture"
#define LXsIATTRTYPE_APERTURE    LXsTYPE_FLOAT
#define LXu_IMAGE       "469AFBB8-E6A2-4d88-9C39-5430CA72E404"
#define LXa_IMAGE       "image"
#define LXa_IMAGE_FLOAT "image_float"
#define LXsSAV_IMAGE_FLOAT "saver.imageFloat"
//[local]  ILxImage
//[export] ILxImage img
//[const]  ILxImage:Size
//[const]  ILxImage:Format
//[const]  ILxImage:GetPixel
//[const]  ILxImage:GetLine
//[python] ILxImage:GetPixel:pixel      vector
//[python] ILxImage:GetLine:buf         vector
#define LXu_IMAGESEGMENT        "370ABB2F-119E-4EEC-98F8-03388ABE7D2C"
#define LXa_IMAGESEGMENT        "imagesegment"
//[local]  ILxImageSegment
//[export] ILxImageSegment imgs
//[const]  ILxImageSegment:GetSegment
//[python] ILxImageSegment:GetSegment:rgba      vector
//[python] ILxImageSegment:SetSegment:line      vector
#define LXu_IMAGEWRITE  "8F9CF293-B6F9-498e-A124-6704E2C24662"
#define LXa_IMAGEWRITE  "imagewrite"
//[local]  ILxImageWrite
//[export] ILxImageWrite imgw
//[const]  ILxImageWrite:Size
//[const]  ILxImageWrite:Format
//[python] ILxImageWrite:SetPixel:pixel vector
//[python] ILxImageWrite:SetLine:line   vector
#define LXu_INDEXIMAGE          "08CAE3BC-ED69-4EC4-9D7D-BBDBE4E35343"
//[local]  ILxIndexImage
//[const]  ILxIndexImage:Size
//[const]  ILxIndexImage:Format
//[const]  ILxIndexImage:MapSize
//[const]  ILxIndexImage:GetIndex
//[const]  ILxIndexImage:GetMap
//[python] ILxIndexImage:GetMap:pixel   vector
#define LXu_INDEXIMAGEWRITE     "D59C5E09-779E-445b-B317-282630CB6BD5"
//[local]  ILxIndexImageWrite
//[const]  ILxIndexImageWrite:Size
//[const]  ILxIndexImageWrite:Format
//[python] ILxIndexImageWrite:SetMap:pixel      vector
#define LXu_LAYEREDIMAGE        "8523ECC4-B8B3-4C6E-8F14-A1D2D01E8038"
#define LXa_LAYEREDIMAGE        "layeredimage"
// [local]  ILxLayeredImage
// [const]  ILxLayeredImage:Size
// [const]  ILxLayeredImage:Count
// [const]  ILxLayeredImage:Name
// [const]  ILxLayeredImage:Type
// [const]  ILxLayeredImage:Offset
// [const]  ILxLayeredImage:Blend
// [const]  ILxLayeredImage:ChannelName
// [python] ILxLayeredImage:Image       obj Image
#define LXu_LAYEREDIMAGEWRITE   "79D28886-9652-4A76-9AA7-1B1E4D553DCD"
//[local]  ILxLayeredImageWrite
#define LXu_TILEIMAGE   "BD12D6C3-C08F-4AD1-A080-399F958D28C0"
#define LXa_TILEIMAGE   "tileImage"
//[local]  ILxTileImage
//[export] ILxTileImage tileimg
//[const]  ILxTileImage:LevelCount
//[const]  ILxTileImage:GetTile
//[const]  ILxTileImage:GetTileSize
//[const]  ILxTileImage:GetLevelSize
//[const]  ILxTileImage:DetermineTile
//[const]  ILxTileImage:DeterminePixel
//[python] ILxTileImage:GetTile         obj Image
#define LXu_IMAGELOADERTARGET   "9F124A7B-DFC7-42E6-977B-71AE2E33B017"
// [local]  ILxImageLoaderTarget
#define LXu_IMAGELEVELSAMPLE    "79A6EA0E-9589-4D03-880C-C06A6EC6CF7D"
#define LXa_IMAGELEVELSAMPLE    "imageLevelSample"
// [export] ILxImageLevelSample level
// [local]  ILxImageLevelSample
// [const]  ILxImageLevelSample:Count
// [const]  ILxImageLevelSample:GetLevelSize
// [const]  ILxImageLevelSample:SampleLevel
// [const]  ILxImageLevelSample:GetPixel
// [const]  ILxImageLevelSample:GetLine
// [python] ILxImageLevelSample:GetPixel:pixel  vector
// [python] ILxImageLevelSample:GetLine:buf     vector
#define LXu_IMAGESERVICE        "03A7D258-397C-4D92-B3AF-695AD676FCF9"

// [python] ILxImageService:Create              obj Image
// [python] ILxImageService:CreateCrop          obj Image
// [python] ILxImageService:Duplicate           obj Image
// [python] ILxImageService:Load                obj Image
// [python] ILxImageService:ImageGetBuffer:buf  vector
#define LXu_IMAGEBLOCKCODEC     "7960B5BA-70D3-4FAD-8CA1-BD30A7938554"
#define LXa_IMAGEBLOCKCODEC     "imageBlockCodec"
// [export] ILxImageBlockCodec ibc
#define LXi_IMAGE_GENERATOR             0
#define LXi_IMAGE_SINGLE_SAMPLE         1
#define LXi_IMAGE_MULTI_SAMPLE          2
#define LXu_IMAGEFILTER         "FB00C87C-5A34-4B45-B0E8-998926C79DC4"
// [export]  ILxImageFilter imf
// [local]   ILxImageFilter
// [python]  ILxImageFilter:Generate    obj Image
// [python]  ILxImageFilter:MultiSample obj Image
#define LXu_IMAGEFILTERSAMPLE   "9EC74AED-F86F-4105-ACE9-7BDAA6298736"
#define LXu_IMAGEFILTERMETRICS  "0D2CA8D8-66A9-45A0-AAE6-8364D903AFDA"
// [export]  ILxImageFilterMetrics imfmet
// [local]   ILxImageFilterMetrics
#define LXu_MOVIE               "B7BD9F49-9400-45F1-ADEE-BFE82A1C4A65"
#define LXa_MOVIE               "movie"
// [export]  ILxMovie

#define LXsMOVIE_SAVESTEREO     "movie.stereoscopic"
#define LXsMOVIE_OPTIONSCOMMAND "optionsCommand"

 #ifdef __cplusplus
  }
 #endif
#endif

