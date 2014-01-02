/*
 * LX color module
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
#ifndef LX_color_H
#define LX_color_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxColorModel ** ILxColorModelID;
typedef struct vt_ILxColor ** ILxColorID;
#include <lxcom.h>
#include <lxvmath.h>
#include <lxserver.h>


typedef struct st_LXtColorPickerPacket {
        char             rgbCommand[1024];
        char             alphaCommand[1024];

        char             rgbAltCommand[1024];
        char             alphaAltCommand[1024];

        char             useAltCommand[1024];
} LXtColorPickerPacket;
typedef struct vt_ILxColorModel {
        ILxUnknown       iunk;
                LXxMETHOD( int,
        NumComponents) (
                LXtObjectID               self);
                LXxMETHOD( LxResult,
        ComponentType) (
                LXtObjectID               self,
                unsigned                  component,
                const char              **type);
                LXxMETHOD( LxResult,
        ComponentRange) (
                LXtObjectID               self,
                unsigned                  component,
                float                    *min,
                float                    *max);
                LXxMETHOD( LxResult,
        ToRGB) (
                LXtObjectID               self,
                const float              *vector,
                float                    *rgb);

                LXxMETHOD( LxResult,
        FromRGB) (
                LXtObjectID               self,
                const float              *rgb,
                float                    *vector);
                LXxMETHOD( LxResult,
        DrawSlice) (
                LXtObjectID               self,
                LXtObjectID               image,
                unsigned                  xAxis,
                unsigned                  yAxis,
                const float              *vec);
                LXxMETHOD( LxResult,
        DrawSliceMarker) (
                LXtObjectID               self,
                LXtObjectID               image,
                unsigned                  xAxis,
                unsigned                  yAxis,
                const float              *downVec,
                const float              *vec);
                LXxMETHOD( LxResult,
        CanSliceBeReused) (
                LXtObjectID               self,
                unsigned                  xAxis,
                unsigned                  yAxis,
                const float              *oldVec,
                const float              *newVec);
                LXxMETHOD( LxResult,
        ToSlicePos) (
                LXtObjectID               self,
                unsigned                  xAxis,
                unsigned                  yAxis,
                unsigned                  imgW,
                unsigned                  imgH,
                const float              *vec,
                unsigned                 *imgX,
                unsigned                 *imgY);
                LXxMETHOD( LxResult,
        FromSlicePos) (
                LXtObjectID               self,
                unsigned                  xAxis,
                unsigned                  yAxis,
                unsigned                  imgW,
                unsigned                  imgH,
                unsigned                  imgX,
                unsigned                  imgY,
                float                    *downVec,
                float                    *vec );
                LXxMETHOD( LxResult,
        StripBaseVector) (
                LXtObjectID               self,
                unsigned                  axis,
                int                       dynamic,
                float                    *vec );
} ILxColorModel;
typedef struct vt_ILxColor {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Color) (
                LXtObjectID               self,
                float                    *color);
                LXxMETHOD( LxResult,
        Alpha) (
                LXtObjectID               self,
                float                    *alpha);
                LXxMETHOD( LxResult,
        ColorModel) (
                LXtObjectID               self,
                const char              **model);
                LXxMETHOD( LxResult,
        ColorInModelSpace) (
                LXtObjectID               self,
                float                    *vec);
} ILxColor;

#define ID_COLR         MK_ID('C','O','L','R')  /* Color Picker Packet */
#define LXu_COLORMODEL          "67d3d952-4ab0-49e5-8f9e-6c889b00f253"
#define LXa_COLORMODEL          "colormodel"
//[export] ILxColorModel colm
//[local]  ILxColorModel
//[python] ILxColorModel:ToRGB:rgb              vector (3)
//[python] ILxColorModel:FromRGB:rgb            vector (3)
//[python] ILxColorModel:FromRGB:vector         vector
//[python] ILxColorModel:FromSlicePos:downVec   vector
//[python] ILxColorModel:FromSlicePos:vec       vector
//[python] ILxColorModel:StripBaseVector:vec    vector
//[python] ILxColorModel:CanSliceBeReused       bool
#define LXs_NOTIFIER_COLOR_CHANGED      "notifier.colorChanged"
#define LXu_COLOR               "7c084df3-adb6-48ee-92d3-032d90efea05"
#define LXa_COLOR               "color"
//[export] ILxColor color
//[local]  ILxColor
#define LXsCOLORMODEL_VALUEPRESET       "colorModelValuePresetCookieTag"

 #ifdef __cplusplus
  }
 #endif
#endif

