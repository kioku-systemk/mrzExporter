/*
 * LX imagemon module
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
#ifndef LX_imagemon_H
#define LX_imagemon_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxImageMonitor ** ILxImageMonitorID;
typedef struct vt_ILxImageMonitorService ** ILxImageMonitorServiceID;
#include <lxcom.h>
#include <lxvmath.h>
#include <lxserver.h>
#include <lximage.h>
#include <lxrndjob.h>
#include <lxcommand.h>


typedef struct st_LXtImageMonitorPacket {
        ILxImageID               image;

        ILxFrameBufferID         frameBuffer;
        int                      bufferIndex;

        double                   x1, y1, x2, y2;

        ILxImageProcessingID     imageProc;

        ILxImageID               processedThumbnail;

        char                     imageSource[256];
} LXtImageMonitorPacket;
typedef struct vt_ILxImageMonitor {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Image) (
                LXtObjectID               self,
                LXtObjectID               imageToAnalyze,
                LXtObjectID               frameBufferToAnalyze,
                int                       bufferIndex,
                double                    x1,
                double                    y1,
                double                    x2,
                double                    y2,
                LXtObjectID               imageProcessingRead,
                LXtObjectID               processedThumbnail);
                LXxMETHOD( LxResult,
        ImageProcChanged) (
                LXtObjectID               self);
                LXxMETHOD( LxResult,
        AspectRange) (
                LXtObjectID               self,
                double                   *minAspect,
                double                   *maxAspect,
                double                   *idealAspect);
                LXxMETHOD( LxResult,
        Draw) (
                LXtObjectID               self,
                LXtObjectID               imageForDrawing);
                LXxMETHOD( LxResult,
        ImageSource) (
                LXtObjectID               self,
                const char               *source);
                LXxMETHOD( LxResult,
        MouseDown) (
                LXtObjectID               self,
                int                       startx,
                int                       starty,
                int                       w,
                int                       h );

                LXxMETHOD( LxResult,
        MouseMove) (
                LXtObjectID               self,
                int                       startx,
                int                       starty,
                int                       cx,
                int                       cy,
                int                       w,
                int                       h );

                LXxMETHOD( LxResult,
        MouseUp) (
                LXtObjectID               self,
                int                       startx,
                int                       starty,
                int                       cx,
                int                       cy,
                int                       w,
                int                       h );
                LXxMETHOD( LxResult,
        MouseTrackEnter) (
                LXtObjectID               self);

                LXxMETHOD( LxResult,
        MouseTrack) (
                LXtObjectID               self,
                int                       cx,
                int                       cy,
                int                       w,
                int                       h );

                LXxMETHOD( LxResult,
        MouseTrackExit) (
                LXtObjectID               self);
                LXxMETHOD( LxResult,
        ToolTip) (
                LXtObjectID               self,
                int                       cx,
                int                       cy,
                int                       w,
                int                       h,
                char                     *buffer,
                unsigned                  len);
} ILxImageMonitor;
typedef struct vt_ILxImageMonitorService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ServerCount) (
                LXtObjectID              self,
                int                     *count);

                LXxMETHOD(  LxResult,
        ServerByIndex) (
                LXtObjectID               self,
                int                       index,
                void                    **ppvObj);

                LXxMETHOD(  LxResult,
        ServerLookup) (
                LXtObjectID               self,
                const char               *name,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        ServerNameByIndex) (
                LXtObjectID               self,
                int                       index,
                const char              **name);

                LXxMETHOD(  LxResult,
        ServerUserNameByIndex) (
                LXtObjectID               self,
                int                       index,
                const char              **name);
                LXxMETHOD(  LxResult,
        SourceCount) (
                LXtObjectID              self,
                int                     *count);

                LXxMETHOD(  LxResult,
        SourceNameByIndex) (
                LXtObjectID               self,
                int                       index,
                const char              **name);

                LXxMETHOD(  LxResult,
        SourceUserNameByIndex) (
                LXtObjectID               self,
                const char               *name,
                const char              **username);
                LXxMETHOD(  LxResult,
        SetImage) (
                LXtObjectID              self,
                const char              *imageSource,
                LXtObjectID              image,
                LXtObjectID              frameBuffer,
                int                      bufferIndex,
                double                   x1,
                double                   y1,
                double                   x2,
                double                   y2,
                LXtObjectID              imageProc,
                LXtObjectID              processedThumbnail );
                LXxMETHOD(  LxResult,
        GetImage) (
                LXtObjectID               self,
                const char               *imageSource,
                void                    **ppvObj_image,
                void                    **ppvObj_frameBuffer,
                int                      *bufferIndex,
                double                   *x1,
                double                   *y1,
                double                   *x2,
                double                   *y2,
                void                    **ppvObj_imageProc,
                void                    **ppvObj_processedThumbnail );
                LXxMETHOD(  LxResult,
        GetImagePacket) (
                LXtObjectID                       self,
                const char                       *imageSource,
                const LXtImageMonitorPacket     **packet );
                LXxMETHOD(  LxResult,
        RefreshViews) (
                LXtObjectID              self,
                const char              *imageSource,
                int                      immediate );
} ILxImageMonitorService;

#define LXu_IMAGEMONITOR        "5ef021ed-a2e3-48d3-aba1-7cbb815f15b7"
#define LXa_IMAGEMONITOR        "imagemonitor"
//[export] ILxImageMonitor imon
//[local]  ILxImageMonitor
#define LXu_IMAGEMONITORSERVICE "f59258f8-3e86-408f-9e92-f81a21d01bde"
#define LXa_IMAGEMONITORSERVICE "imagemonitorservice"
#define LXsIMAGEMONITOR_SOURCE_NOTIFIER "notifier.imagemonitor.source"
        #define LXsIMAGEPROC_NOTIFIER   "notifier.imageproc"

static LXtTextValueHint  notifierImageProcEventHints[] = {                                      // Events as a text hints array
        /* Event */
        LXiIMAGEPROC_EVENT_CHANGED_SOURCE_IMAGE_GAMMA,                  "sourceImageGamma",
        LXiIMAGEPROC_EVENT_CHANGED_SAVE_PROCESSED,                      "saveProcessed",
        LXiIMAGEPROC_EVENT_CHANGED_BLOOM_ENABLED,                       "bloomEnabled",
        LXiIMAGEPROC_EVENT_CHANGED_BLOOM_THRESHOLD,                     "bloomThreshold",
        LXiIMAGEPROC_EVENT_CHANGED_BLOOM_RADIUS,                        "bloomRadius",
        LXiIMAGEPROC_EVENT_CHANGED_RESPECT_RENDER_VIEW_GAMMA_PREF,      "respectRenderViewGammaPref",

        LXiIMAGEPROC_EVENT_CHANGED_LEVEL_OFFSET,                        "levelOffset",

        LXiIMAGEPROC_EVENT_CHANGED_INPUT_BLACK_LEVEL,                   "inputBlackLevel",
        LXiIMAGEPROC_EVENT_CHANGED_INPUT_GRAY_LEVEL,                    "inputGrayLevel",
        LXiIMAGEPROC_EVENT_CHANGED_INPUT_WHITE_LEVEL,                   "inputWhiteLevel",

        LXiIMAGEPROC_EVENT_CHANGED_INPUT_MIN_RGB_LEVEL,                 "inputMinRGBLevel",
        LXiIMAGEPROC_EVENT_CHANGED_INPUT_GRAY_RGB_LEVEL,                "inputGrayRGBLevel",
        LXiIMAGEPROC_EVENT_CHANGED_INPUT_MAX_RGB_LEVEL,                 "inputMaxRGBLevel",

        LXiIMAGEPROC_EVENT_CHANGED_TONE_MAPPING,                        "toneMapping",
        LXiIMAGEPROC_EVENT_CHANGED_HUE_OFFSET,                          "hueOffset",
        LXiIMAGEPROC_EVENT_CHANGED_SATURATION,                          "saturation",
        LXiIMAGEPROC_EVENT_CHANGED_COLORIZATION,                        "colorization",
        LXiIMAGEPROC_EVENT_CHANGED_TARGET_COLOR,                        "targetColor",

        LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_BLACK_LEVEL,                  "outputBlackLevel",
        LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_WHITE_LEVEL,                  "outputWhiteLevel",

        LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_MIN_RGB_LEVEL,                "outputMinRGBLevel",
        LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_MAX_RGB_LEVEL,                "outputMaxRGBLevel",

        LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_GAMMA,                        "outputGamma",

        /* Invalidation flags for the event */
        LXfCMDNOTIFY_VALUE,                     "+v",
        LXfCMDNOTIFY_LABEL,                     "+l",
        LXfCMDNOTIFY_DISABLE,                   "+d",
        LXfCMDNOTIFY_DATATYPE,                  "+t",
        0,                                       NULL
};

        #define LXfIPEVENT_EVENT                 0xFFFFFFF0                     // Mask off the event
        #define LXfIPEVENT_FLAGS                 0x0000000F                     // Mask off the invalidation flags

        #define LXxIPEVENT_EVENT(e)              (LXfIPEVENT_EVENT & (e))       // Macro to mask off the event
        #define LXxIPEVENT_FLAGS(e)              (LXfIPEVENT_FLAGS & (e))       // Macro to mask off the invalidation flags

 #ifdef __cplusplus
  }
 #endif
#endif

