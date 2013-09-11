/*
 * LX rndr module
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
#ifndef LX_rndr_H
#define LX_rndr_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxRenderBucket ** ILxRenderBucketID;
#include <lxvector.h>



#define LXiIP_ALL_OPERATORS_ENABLED     0xFFFFFFFF
#define LXiIP_ALL_OPERATORS_DISABLED    0x00000000
#define LXiIP_NO_OPERATOR_OVERRIDE      0x80000000

#define LXiIP_STEREO                    0x00000001
#define LXiIP_COMPONENT_STEREO          0x00000002

#define LXiIP_SOURCE_IMAGE_GAMMA        0x00000004

#define LXiIP_BLOOM                     0x00000008
#define LXiIP_LEVEL_OFFSET              0x00000010
#define LXiIP_RGB_LEVEL_OFFSET          0x00000020

#define LXiIP_INPUT_BLACK_LEVEL         0x00000040
#define LXiIP_INPUT_GRAY_LEVEL          0x00000080
#define LXiIP_INPUT_WHITE_LEVEL         0x00000100

#define LXiIP_INPUT_MIN_RGB_LEVEL       0x00000200
#define LXiIP_INPUT_RGB_GRAY_LEVEL      0x00000400
#define LXiIP_INPUT_MAX_RGB_LEVEL       0x00000800

#define LXiIP_TONE_MAPPING              0x00001000
#define LXiIP_HUE_OFFSET                0x00002000
#define LXiIP_SATURATION                0x00004000
#define LXiIP_COLORIZATION              0x00008000
#define LXiIP_OUTPUT_BLACK_LEVEL        0x00010000
#define LXiIP_OUTPUT_WHITE_LEVEL        0x00020000

#define LXiIP_OUTPUT_MIN_RGB_LEVEL      0x00040000
#define LXiIP_OUTPUT_MAX_RGB_LEVEL      0x00080000

#define LXiIP_OUTPUT_GAMMA              0x00100000

#define LXiIP_DITHER                    0x00200000

typedef unsigned int                    LXtImageProcessingOperators;

#define LXiSE_LEFT                      0
#define LXiSE_RIGHT                     1
#define LXiSE_BOTH                      2

typedef unsigned int                    LXtStereoEye;

#define LXeSC_NO_COMPOSITE              0

#define LXeSC_ANAGLYPH_RED_CYAN         1
#define LXeSC_ANAGLYPH_GRAYSCALE        2
#define LXeSC_ANAGLYPH_RED_CYAN_HALF    3
#define LXeSC_ANAGLYPH_RED_CYAN_OPT     4
#define LXeSC_ANAGLYPH_RED_BLUE_LS      5
#define LXeSC_LAST_ANAGLYPH_MODE        LXeSC_ANAGLYPH_RED_BLUE_LS

#define LXeSC_SIDE_BY_SIDE              6
#define LXeSC_SIDE_BY_SIDE_FULL_WIDTH   7
#define LXeSC_SIDE_BY_SIDE_CROSSED      8
#define LXeSC_SIDE_BY_SIDE_CROSSED_FULL 9
#define LXeSC_LAST_SIDE_BY_SIDE_MODE    LXeSC_SIDE_BY_SIDE_CROSSED_FULL

#define LXeSC_DROPDOWN_COUNT            (LXeSC_LAST_SIDE_BY_SIDE_MODE + 1)

#define LXeSC_UNDEFINED                 0xFFFF

typedef unsigned int                    LXtStereoComposite;

typedef struct st_RenderOutputProcess
{
        LXtImageProcessingOperators     ops;

        int                             type;
        int                             typeSize;

        int                             unpremul;
        int                             alphaIndex;
        int                             isFactoryName;

        float                           sourceImageGamma;
        int                             sourceImageIsStereoSideBySide;

        int                             saveProcessed;

        int                             stereoEye;
        int                             stereoComposite;

        int                             bloom;
        float                           bloomThr;
        float                           bloomRad;

        float                           levelOffset;
        float                           redLevelOffset;
        float                           greenLevelOffset;
        float                           blueLevelOffset;

        float                           inputBlackLevel;
        float                           inputGrayLevel;
        float                           invInputGrayLevel;
        float                           white;
        float                           exposure;

        float                           inputMinRedLevel;
        float                           inputRedGrayLevel;
        float                           invInputRedGrayLevel;
        float                           red;
        float                           redExposure;

        float                           inputMinGreenLevel;
        float                           inputGreenGrayLevel;
        float                           invInputGreenGrayLevel;
        float                           green;
        float                           greenExposure;

        float                           inputMinBlueLevel;
        float                           inputBlueGrayLevel;
        float                           invInputBlueGrayLevel;
        float                           blue;
        float                           blueExposure;

        float                           toneAmt;

        float                           hueOffset;
        float                           saturation;
        float                           colorization;
        LXtVector                       targetColor;
        LXtVector                       targetHSV;

        float                           outputBlackLevel;
        float                           outputWhiteLevel;

        float                           outputMinRedLevel;
        float                           outputMaxRedLevel;

        float                           outputMinGreenLevel;
        float                           outputMaxGreenLevel;

        float                           outputMinBlueLevel;
        float                           outputMaxBlueLevel;

        float                           gamma;
        float                           invGamma;
        char                            userName[64];
        char                            identity[256];
} RenderOutputProcess;

#define RENDER_OUTPUT_MAX        256

typedef struct st_RenderOutputProcessList
{
        unsigned                 count;
        RenderOutputProcess      outputs[RENDER_OUTPUT_MAX];
} RenderOutputProcessList;

#define LXiRENDEROUTPUT_INVALID         -1

#define LXiRENDEROUTPUT_COLOR            0
#define LXiRENDEROUTPUT_ALPHA            1

#define LXiRENDEROUTPUT_DIFF             2
#define LXiRENDEROUTPUT_DIFFDIR          3
#define LXiRENDEROUTPUT_DIFFIND         4
#define LXiRENDEROUTPUT_DIFFUNS         5
#define LXiRENDEROUTPUT_SPEC             6
#define LXiRENDEROUTPUT_REFL             7
#define LXiRENDEROUTPUT_TRAN             8
#define LXiRENDEROUTPUT_SUBS             9
#define LXiRENDEROUTPUT_LUMI             10

#define LXiRENDEROUTPUT_DEPTH            11
#define LXiRENDEROUTPUT_MOTION           12
#define LXiRENDEROUTPUT_SHADOW           13
#define LXiRENDEROUTPUT_OCCLAMB          14
#define LXiRENDEROUTPUT_OCCLREF          15

#define LXiRENDEROUTPUT_SNORM            16
#define LXiRENDEROUTPUT_SINC             17
#define LXiRENDEROUTPUT_GNORM            18
#define LXiRENDEROUTPUT_GINC             19

#define LXiRENDEROUTPUT_SURFACE          20
#define LXiRENDEROUTPUT_SEGMENT          21

#define LXiRENDEROUTPUT_OPOS             22 
#define LXiRENDEROUTPUT_WPOS             23

#define LXiRENDEROUTPUT_UV               24 
#define LXiRENDEROUTPUT_DPDU             25
#define LXiRENDEROUTPUT_DPDV             26

#define LXiRENDEROUTPUT_ICPOS            27
#define LXiRENDEROUTPUT_ICVAL            28

#define LXiRENDEROUTPUT_MDIFF            29
#define LXiRENDEROUTPUT_MSPEC            30
#define LXiRENDEROUTPUT_MREFL            31

#define LXiRENDEROUTPUT_ILLUM            32
#define LXiRENDEROUTPUT_ILLUMDIR         33
#define LXiRENDEROUTPUT_ILLUMIND         34
#define LXiRENDEROUTPUT_ILLUMUNS         35

#define LXiRENDEROUTPUT_SAMPLES          36

#define LXiRENDEROUTPUT_VOL_LUM          37
#define LXiRENDEROUTPUT_VOL_OPA          38
#define LXiRENDEROUTPUT_VOL_DEPTH        39

typedef struct vt_ILxRenderBucket {
        ILxUnknown       iunk;


                LXxMETHOD(  unsigned int,
        Thread) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        SampleVec) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        PushRay) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        PopRay) (
                LXtObjectID              self);
} ILxRenderBucket;

#define LXe_GEO_SIZE_LIMIT       LXxFAILCODE(LXeSYS_REND,1)
#define LXu_RENDERBUCKET        "ED6F0ABE-F76F-4EED-BEF5-A30FF7F71098"
#define SVPs_RENDERBUCKET       "renderBucket"

 #ifdef __cplusplus
  }
 #endif
#endif

