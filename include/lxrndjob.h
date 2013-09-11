/*
 * LX rndjob module
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
#ifndef LX_rndjob_H
#define LX_rndjob_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxRenderService ** ILxRenderServiceID;
typedef struct vt_ILxRenderJob ** ILxRenderJobID;
typedef struct vt_ILxRenderStats ** ILxRenderStatsID;
typedef struct vt_ILxBuffer ** ILxBufferID;
typedef struct vt_ILxFrameBuffer ** ILxFrameBufferID;
typedef struct vt_ILxImageProcessing ** ILxImageProcessingID;
typedef struct vt_ILxImageProcessingListener ** ILxImageProcessingListenerID;
typedef struct vt_ILxImageProcessingRead ** ILxImageProcessingReadID;
typedef struct vt_ILxImageProcessingService ** ILxImageProcessingServiceID;
#include <lxresult.h>
#include <lxcom.h>
#include <lxvmath.h>
#include <lxitem.h>
#include <lxvector.h>
#include <lxvalue.h>
#include <lximage.h>
#include <lxrender.h>

typedef struct st_Buffer        *LXtBufferID;
typedef void                    *TileTreeID;


typedef struct vt_ILxRenderService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        JobSetCurrent) (
                LXtObjectID               self,
                LXtObjectID               job);
                LXxMETHOD(  LxResult,
        JobCurrent) (
                LXtObjectID               self,
                void                    **ppvObj);

                LXxMETHOD(  LxResult,
        JobStart) (
                LXtObjectID               self);

                LXxMETHOD(  LxResult,
        JobAbort) (
                LXtObjectID               self);

                LXxMETHOD(  LxResult,
        JobStatus) (
                LXtObjectID               self);

                LXxMETHOD(  LXtObjectID,
        JobStats) (
                LXtObjectID               self);

                LXxMETHOD(  int,
        JobIsSlave) (
                LXtObjectID               self);

                LXxMETHOD(  LxResult,
        JobCleanup) (
                LXtObjectID               self,
                int                       clearJob);

                LXxMETHOD(  LxResult,
        JobRenderOutputCount) (
                LXtObjectID               self,
                int                      *count);

                LXxMETHOD(  LxResult,
        JobRenderOutputName) (
                LXtObjectID               self,
                int                       index,
                const char              **name);

                LXxMETHOD(  LxResult,
        JobRenderOutputType) (
                LXtObjectID               self,
                int                       index,
                int                      *type);
                LXxMETHOD(  LxResult,
        UpdateProgressImage) (
                LXtObjectID               self);

                LXxMETHOD(  LxResult,
        RefreshProgressImageMetrics) (
                LXtObjectID               self);

                LXxMETHOD(  LxResult,
        FrameStore) (
                LXtObjectID              self,
                LXtObjectID              frameBuffer,
                int                      writePixels);

                LXxMETHOD(  LxResult,
        FrameRecall) (
                LXtObjectID               self,
                int                       slotIndex,
                int                       passIndex,
                LXtObjectID               monitor,
                void                    **ppvObj);

                LXxMETHOD(  LxResult,
        FrameTestRecall) (
                LXtObjectID               self,
                int                       slotIndex,
                int                       passIndex);

                LXxMETHOD(  LxResult,
        FrameRenderPassCount) (
                LXtObjectID               self,
                int                       slotIndex,
                int                      *numPasses);

                LXxMETHOD(  LxResult,
        FrameRenderPassInfo) (
                LXtObjectID              self,
                int                      slotIndex,
                int                      passIndex,
                char                    *name,
                unsigned                *width,
                unsigned                *height,
                unsigned                *outputCount,
                int                     *isStereo,
                LXtStereoEye            *eyeDisplay,
                LXtStereoComposite      *stereoComposite);

                LXxMETHOD(  LxResult,
        FrameRenderPassOutputInfo) (
                LXtObjectID              self,
                int                      slotIndex,
                int                      passIndex,
                char                    *renderPassName,
                unsigned                *width,
                unsigned                *height,
                RenderOutputProcessList *outputs);

                LXxMETHOD(  LxResult,
        FrameSaveImage) (
                LXtObjectID               self,
                LXtObjectID               framebuffer,
                int                       bufferIndex,
                const char               *filename,
                const char               *format,
                LXtObjectID               message,
                LXtObjectID               monitor);

                LXxMETHOD(  LxResult,
        FrameSaveLayered) (
                LXtObjectID               self,
                LXtObjectID               framebuffer,
                const char               *filename,
                const char               *format,
                LXtObjectID               message,
                LXtObjectID               monitor);

                LXxMETHOD(  LxResult,
        FrameSavePassLayered) (
                LXtObjectID               self,
                LXtObjectID               framebuffer,
                const char               *filename,
                const char               *format,
                LXtObjectID               message,
                LXtObjectID               monitor);

                LXxMETHOD(  LxResult,
        FrameSavePassesAsImages) (
                LXtObjectID               self,
                int                       slotIndex,
                const char               *filename,
                const char               *format,
                LXtObjectID               message,
                LXtObjectID               monitor);

                LXxMETHOD(  LxResult,
        FrameSavePassesAsLayeredImages) (
                LXtObjectID               self,
                int                       slotIndex,
                const char               *filename,
                const char               *format,
                LXtObjectID               message,
                LXtObjectID               monitor);

                LXxMETHOD(  LxResult,
        FrameStoreStats) (
                LXtObjectID               self,
                int                       slotIndex,
                LXtObjectID               stats);

                LXxMETHOD(  LxResult,
        FrameRecallStats) (
                LXtObjectID               self,
                int                       slotIndex,
                void                    **ppvObj);

                LXxMETHOD(  LxResult,
        FrameStoreThumbnail) (
                LXtObjectID               self,
                int                       slotIndex,
                LXtObjectID               image);

                LXxMETHOD(  LxResult,
        FrameRecallThumbnail) (
                LXtObjectID               self,
                int                       slotIndex,
                void                    **ppvObj);

                LXxMETHOD(  LxResult,
        FrameDelete) (
                LXtObjectID               self,
                int                       slotIndex);

} ILxRenderService;
typedef struct vt_ILxRenderJob {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        RenderItem) (
                LXtObjectID               self,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        ActionName) (
                LXtObjectID               self,
                const char              **action);
                LXxMETHOD(  LxResult,
        GroupName) (
                LXtObjectID               self,
                const char              **group);
                LXxMETHOD(  LxResult,
        RenderAs) (
                LXtObjectID               self,
                int                      *mode);
                LXxMETHOD(  LxResult,
        RenderAtTime) (
                LXtObjectID               self,
                double                   *time);
                LXxMETHOD(  LxResult,
        RenderTurntableNumFrames) (
                LXtObjectID               self,
                int                      *numFrames);
                LXxMETHOD(  LxResult,
        RenderTurntableFPS) (
                LXtObjectID               self,
                int                      *fps);
                LXxMETHOD(  LxResult,
        RenderBakeVMap) (
                LXtObjectID               self,
                const char              **vmap);
                LXxMETHOD(  LxResult,
        RenderBakeLookDistance) (
                LXtObjectID               self,
                double                   *distance);
                LXxMETHOD(  LxResult,
        RenderBakeItem) (
                LXtObjectID               self,
                int                              *include,
                void                    **item);
                LXxMETHOD(  LxResult,
        RenderBakeEffect) (
                LXtObjectID               self,
                const char              **effect);
                LXxMETHOD(  LxResult,
        RenderBakeImage) (
                LXtObjectID               self,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        TestItem) (
                LXtObjectID               self,
                LXtObjectID               item,
                LXtObjectID               eval);
                LXxMETHOD(  LxResult,
        FrameBufferSlot) (
                LXtObjectID               self,
                int                      *index);
                LXxMETHOD(  LxResult,
        FrameBufferRegionBackgroundSlot) (
                LXtObjectID               self,
                int                      *slotIndex,
                int                      *passIndex);
                LXxMETHOD(  LxResult,
        OutputFormat) (
                LXtObjectID               self,
                const char              **format);
                LXxMETHOD(  LxResult,
        OutputFilename) (
                LXtObjectID               self,
                const char              **filename);
                LXxMETHOD(  LxResult,
        Options) (
                LXtObjectID               self,
                int                      *options);
                LXxMETHOD(  LxResult,
        ProgressAborted) (
                LXtObjectID               self);
                LXxMETHOD(  LxResult,
        ProgressBegin) (
                LXtObjectID               self,
                LXtObjectID               renderStats);
                LXxMETHOD(  LxResult,
        ProgressEnd) (
                LXtObjectID               self,
                LXtObjectID               finalFrameBuffer,
                LXtObjectID               finalStats);
                LXxMETHOD(  LxResult,
        ProgressPercentDone) (
                LXtObjectID               self,
                double                    progressScene,
                double                    progressFrame,
                double                    progressRenderPass);
                LXxMETHOD(  LxResult,
        ProgressImageMetrics) (
                LXtObjectID               self,
                int                       resX,
                int                       resH,
                int                      *w,
                int                      *h,
                double                   *zoom,
                int                      *panX,
                int                      *panY,
                int                      *output);
                LXxMETHOD(  LxResult,
        ProgressFrameBegin) (
                LXtObjectID               self,
                int                       frame,
                int                       w,
                int                       h);
                LXxMETHOD(  LxResult,
        ProgressFrameEnd) (
                LXtObjectID               self,
                int                       frame,
                LXtObjectID               stats);
        #define LXiRENDEREYE_MONO       0
        #define LXiRENDEREYE_LEFT       1
        #define LXiRENDEREYE_RIGHT      2
                LXxMETHOD(  LxResult,
        ProgressRenderPassBegin) (
                LXtObjectID               self,
                int                       frameIndex,
                int                       renderPassIndex,
                const char               *renderPassName,
                int                       eye);

                LXxMETHOD(  LxResult,
        ProgressRenderPassEnd) (
                LXtObjectID               self,
                int                       frame,
                int                       renderPassIndex,
                const char               *renderPassName,
                int                       eye,
                LXtObjectID               frameBuffer,
                LXtObjectID               stats);
                LXxMETHOD(  LxResult,
        ProgressFramePassBegin) (
                LXtObjectID               self,
                int                       frame,
                int                       renderPass,
                int                       eye,
                int                       pass);

                LXxMETHOD(  LxResult,
        ProgressFramePassEnd) (
                LXtObjectID               self,
                int                       frame,
                int                       renderPass,
                int                       eye,
                int                       pass);
                LXxMETHOD(  LxResult,
        ProgressBucketBegin) (
                LXtObjectID               self,
                int                       row,
                int                       col);
                LXxMETHOD(  LxResult,
        ProgressBucketEnd) (
                LXtObjectID               self,
                int                       row,
                int                       col,
                LxResult                  code);
                LXxMETHOD(  LxResult,
        ProgressString) (
                LXtObjectID               self,
                const char               *infoString,
                const char               *userString);
                LXxMETHOD(  LxResult,
        ProgressImage) (
                LXtObjectID               self,
                LXtObjectID               img);
                LXxMETHOD(  LxResult,
        ProgressImageUpdated) (
                LXtObjectID               self);
                LXxMETHOD(  LxResult,
        ProgressTickle) (
                LXtObjectID               self);
} ILxRenderJob;
typedef struct vt_ILxRenderStats {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        NumFrames) (
                LXtObjectID               self,
                int                      *count);
                LXxMETHOD(  LxResult,
        NumPasses) (
                LXtObjectID               self,
                int                       frameIndex,
                int                      *count);
                LXxMETHOD(  LxResult,
        GetPassStats) (
                LXtObjectID               self,
                int                       frameIndex,
                int                       passIndex,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        GetFrameStats) (
                LXtObjectID               self,
                int                       frameIndex,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        GetSceneStats) (
                LXtObjectID               self,
                void                    **ppvObj);
} ILxRenderStats;
typedef struct vt_ILxBuffer {
        ILxUnknown       iunk;
                LXxMETHOD(  void,
        SetFlags) (
                LXtObjectID              self,
                int                      flags);

                LXxMETHOD(  int,
        Flags) (
                LXtObjectID              self);

                LXxMETHOD(  int,
        DataType) (
                LXtObjectID              self);

                LXxMETHOD(  ILxVectorTypeID,
        VectorType) (
                LXtObjectID              self);

                LXxMETHOD(  void,
        SetSize) (
                LXtObjectID              self,
                int                      width,
                int                      height,
                int                      writeBucketsToDisk,
                int                      isStereo);

                LXxMETHOD(  void,
        GetSize) (
                LXtObjectID              self,
                int                     *width,
                int                     *height);

                LXxMETHOD(  LxResult,
        SetEyeSide) (
                LXtObjectID              self,
                int                      eyeSide);

                LXxMETHOD(  void,
        Clear) (
                LXtObjectID              self,
                int                      x,
                int                      y);

                LXxMETHOD(  LxResult,
        Convert) (
                LXtObjectID              self,
                LXtGenVectorID           gv,
                int                      x,
                int                      y,
                float                    blend);

                LXxMETHOD(  void *,
        Pixel) (
                LXtObjectID              self,
                int                      x,
                int                      y);

                LXxMETHOD(  void *,
        Line) (
                LXtObjectID              self,
                int                      y);

                LXxMETHOD(  LxResult,
        Name) (
                LXtObjectID              self,
                char                   **name);

                LXxMETHOD(  LxResult,
        SetUserName) (
                LXtObjectID              self,
                const char              *name);

                LXxMETHOD(  LxResult,
        UserName) (
                LXtObjectID              self,
                char                   **name);

                LXxMETHOD(  LxResult,
        CreateImageTileTree) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        DestroyImageTileTree) (
                LXtObjectID              self);

                LXxMETHOD(  TileTreeID,
        GetImageTileTree) (
                LXtObjectID              self);

                LXxMETHOD(  size_t,
        GetImageTileTreeSize) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        ResetImageTileTree) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        IncrementTileTreeSize) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        DecrementTileTreeSize) (
                LXtObjectID              self);

} ILxBuffer;
typedef struct vt_ILxFrameBuffer {
        ILxUnknown       iunk;
                LXxMETHOD(  ILxBufferID,
        Allocate) (
                LXtObjectID              self,
                const char              *name,
                LXtObjectID              item,
                const char              *identity,
                const char              *userName,
                int                      isFactoryName,
                int                      writeBucketsToDisk);

                LXxMETHOD(  LxResult,
        IsStereo) (
                LXtObjectID              self,
                int                     *isStereo);

                LXxMETHOD(  LxResult,
        GetStereoEyeDisplay) (
                LXtObjectID              self,
                LXtStereoEye            *eyeDisplay);

                LXxMETHOD(  LxResult,
        SetStereoEyeDisplay) (
                LXtObjectID              self,
                LXtStereoEye             eyeDisplay);

                LXxMETHOD(  LxResult,
        GetStereoComposite) (
                LXtObjectID              self,
                LXtStereoComposite      *composite);

                LXxMETHOD(  LxResult,
        SetStereoComposite) (
                LXtObjectID              self,
                LXtStereoComposite       composite);

                LXxMETHOD(  LxResult,
        SetEyeSide) (
                LXtObjectID              self,
                int                      eyeSide);

                LXxMETHOD(  LxResult,
        GetLineBuffer) (
                LXtObjectID              self,
                float                   **buf);

                LXxMETHOD(  LxResult,
        CreateFrameBufferTargetImage) (
                LXtObjectID              self,
                LXtPixelFormat           type,
                int                      w,
                int                      h,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        GetRenderPassName) (
                LXtObjectID              self,
                char                    *name);

                LXxMETHOD(  LxResult,
        SetRenderPassName) (
                LXtObjectID              self,
                const char              *name);

                LXxMETHOD(  unsigned int,
        BucketsOnDisk) (
                LXtObjectID              self,
                int                      index);

                LXxMETHOD(  ILxBufferID,
        Lookup) (
                LXtObjectID              self,
                const char              *name,
                LXtObjectID              item);

                LXxMETHOD(  ILxBufferID,
        LookupByIdentity) (
                LXtObjectID              self,
                const char              *identity);

                LXxMETHOD(  unsigned int,
        Count) (
                LXtObjectID              self);

                LXxMETHOD(  ILxBufferID,
        ByIndex) (
                LXtObjectID              self,
                int                      index);

                LXxMETHOD(  ILxBufferID,
        Alpha) (
                LXtObjectID              self,
                int                      index);

                LXxMETHOD(  int,
        AlphaIndex) (
                LXtObjectID              self,
                int                      index);

                LXxMETHOD(  LxResult,
        Size) (
                LXtObjectID              self,
                int                      index,
                int                     *width,
                int                     *height);

                LXxMETHOD(  LxResult,
        AreaProcessingActive) (
                LXtObjectID              self,
                int                      bufferIndex,
                int                     *active);

                LXxMETHOD(  int,
        GetSaveProcessed) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetSaveProcessed) (
                LXtObjectID              self,
                int                      bufferIndex,
                int                      enabled);

                LXxMETHOD(  int,
        GetBloomEnabled) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetBloomEnabled) (
                LXtObjectID              self,
                int                      bufferIndex,
                int                      enabled);

                LXxMETHOD(  double,
        GetBloomThreshold) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetBloomThreshold) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   threshold);

                LXxMETHOD(  double,
        GetBloomRadius) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetBloomRadius) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   radius);

                LXxMETHOD(  double,
        GetLevelOffset) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetLevelOffset) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   offset);

                LXxMETHOD(  double,
        GetRedLevelOffset) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetRedLevelOffset) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   offset);

                LXxMETHOD(  double,
        GetGreenLevelOffset) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetGreenLevelOffset) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   offset);

                LXxMETHOD(  double,
        GetBlueLevelOffset) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetBlueLevelOffset) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   offset);

                LXxMETHOD(  double,
        GetInputBlackLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetInputBlackLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   blackLevel);

                LXxMETHOD(  double,
        GetInputGrayLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  double,
        GetInvInputGrayLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetInputGrayLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   gamma);

                LXxMETHOD(  double,
        GetInputWhiteLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetInputWhiteLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   whiteLevel);

                LXxMETHOD(  double,
        GetInputMinRedLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetInputMinRedLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   level);

                LXxMETHOD(  double,
        GetInputRedGrayLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  double,
        GetInvInputRedGrayLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetInputRedGrayLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   gamma);

                LXxMETHOD(  double,
        GetInputMaxRedLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetInputMaxRedLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   level);

                LXxMETHOD(  double,
        GetInputMinGreenLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetInputMinGreenLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   level);

                LXxMETHOD(  double,
        GetInputGreenGrayLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  double,
        GetInvInputGreenGrayLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetInputGreenGrayLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   gamma);

                LXxMETHOD(  double,
        GetInputMaxGreenLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetInputMaxGreenLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   level);

                LXxMETHOD(  double,
        GetInputMinBlueLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetInputMinBlueLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   level);

                LXxMETHOD(  double,
        GetInputBlueGrayLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  double,
        GetInvInputBlueGrayLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetInputBlueGrayLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   gamma);

                LXxMETHOD(  double,
        GetInputMaxBlueLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetInputMaxBlueLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   level);

                LXxMETHOD(  double,
        GetToneMapping) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetToneMapping) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   toneMapping);

                LXxMETHOD(  double,
        GetHueOffset) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetHueOffset) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   hueOffset);

                LXxMETHOD(  double,
        GetSaturation) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetSaturation) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   saturation);

                LXxMETHOD(  double,
        GetColorization) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetColorization) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   colorization);

                LXxMETHOD(  void,
        GetTargetColor) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                  *color);

                LXxMETHOD(  LxResult,
        SetTargetColor) (
                LXtObjectID              self,
                int                      bufferIndex,
                const double            *color);

                LXxMETHOD(  double,
        GetOutputBlackLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetOutputBlackLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   blackLevel);

                LXxMETHOD(  double,
        GetOutputWhiteLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetOutputWhiteLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   whiteLevel);

                LXxMETHOD(  double,
        GetOutputMinRedLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetOutputMinRedLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   blackLevel);

                LXxMETHOD(  double,
        GetOutputMaxRedLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetOutputMaxRedLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   whiteLevel);

                LXxMETHOD(  double,
        GetOutputMinGreenLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetOutputMinGreenLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   blackLevel);

                LXxMETHOD(  double,
        GetOutputMaxGreenLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetOutputMaxGreenLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   whiteLevel);

                LXxMETHOD(  double,
        GetOutputMinBlueLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetOutputMinBlueLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   blackLevel);

                LXxMETHOD(  double,
        GetOutputMaxBlueLevel) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetOutputMaxBlueLevel) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   whiteLevel);

                LXxMETHOD(  double,
        GetOutputGamma) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  double,
        GetOutputInvGamma) (
                LXtObjectID              self,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        SetOutputGamma) (
                LXtObjectID              self,
                int                      bufferIndex,
                double                   gamma);

                LXxMETHOD(  LxResult,
        AddAttribute) (
                LXtObjectID              self,
                const char              *name,
                const char              *type,
                unsigned                *index);
} ILxFrameBuffer;
typedef struct vt_ILxImageProcessing {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        GetAsReadOnly) (
                LXtObjectID               self,
                void                    **ppvObj);

                LXxMETHOD(  LxResult,
        SetIdentifier) (
                LXtObjectID              self,
                const char              *string);

                LXxMETHOD(  LxResult,
        GetIdentifier) (
                LXtObjectID               self,
                const char              **string);

                LXxMETHOD(  LxResult,
        Reset) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        CopyToRenderProcess) (
                LXtObjectID              self,
                RenderOutputProcess     *rop);

                LXxMETHOD(  LxResult,
        CopyFromRenderProcess) (
                LXtObjectID                     self,
                const RenderOutputProcess       *rop);

                LXxMETHOD(  LxResult,
        CopySettingsFromFrameBuffer) (
                LXtObjectID              self,
                LXtObjectID              frameBuffer,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        CopySettingsToFrameBuffer) (
                LXtObjectID              self,
                LXtObjectID              frameBuffer,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        ApplyToImageFromFrameBuffer) (
                LXtObjectID                      self,
                LXtObjectID                      frameBuffer,
                int                              bufferIndex,
                LXtObjectID                      image,
                float                            xOffset,
                float                            yOffset,
                float                            zoom);

                LXxMETHOD(  LxResult,
        ApplyToImageFromFrameBufferOverride) (
                LXtObjectID                      self,
                LXtObjectID                      frameBuffer,
                int                              bufferIndex,
                LXtObjectID                      image,
                float                            xOffset,
                float                            yOffset,
                float                            zoom,
                LXtImageProcessingOperators      opOverride);

                LXxMETHOD(  LxResult,
        ApplyToFrameBuffer) (
                LXtObjectID                      self,
                LXtObjectID                      frameBuffer,
                int                              bufferIndex);

                LXxMETHOD(  LxResult,
        ApplyToFrameBufferOverride) (
                LXtObjectID                      self,
                LXtObjectID                      frameBuffer,
                int                              bufferIndex,
                LXtImageProcessingOperators      opOverride);

                LXxMETHOD(  LxResult,
        ApplyToImage) (
                LXtObjectID              self,
                LXtObjectID              srcImage,
                LXtObjectID              dstImage);

                LXxMETHOD(  LxResult,
        ApplyToImageOverride) (
                LXtObjectID                      self,
                LXtObjectID                      srcImage,
                LXtObjectID                      dstImage,
                LXtImageProcessingOperators      opOverride);

                LXxMETHOD(  LxResult,
        GetImageProcessingOperators) (
                LXtObjectID                      self,
                LXtImageProcessingOperators     *ops);

                LXxMETHOD(  LxResult,
        SetImageProcessingOperators) (
                LXtObjectID                     self,
                LXtImageProcessingOperators     ops);

                LXxMETHOD(  LxResult,
        AreaProcessingActive) (
                LXtObjectID              self,
                int                     *active);

                LXxMETHOD(  LxResult,
        GetSourceImageGamma) (
                LXtObjectID              self,
                double                  *gamma);

                LXxMETHOD(  LxResult,
        SetSourceImageGamma) (
                LXtObjectID              self,
                double                   gamma);

                LXxMETHOD(  LxResult,
        GetSourceImageIsStereoSideBySide) (
                LXtObjectID              self,
                int                     *isStereo);

                LXxMETHOD(  LxResult,
        SetSourceImageIsStereoSideBySide) (
                LXtObjectID              self,
                int                      isStereo);

                LXxMETHOD(  LxResult,
        GetSaveProcessed) (
                LXtObjectID              self,
                int                     *enabled);

                LXxMETHOD(  LxResult,
        SetSaveProcessed) (
                LXtObjectID              self,
                int                      enabled);

                LXxMETHOD(  LxResult,
        GetStereoEye) (
                LXtObjectID              self,
                LXtStereoEye            *eye);

                LXxMETHOD(  LxResult,
        SetStereoEye) (
                LXtObjectID              self,
                LXtStereoEye             eye);

                LXxMETHOD(  LxResult,
        GetStereoComposite) (
                LXtObjectID              self,
                LXtStereoComposite      *mode);

                LXxMETHOD(  LxResult,
        SetStereoComposite) (
                LXtObjectID              self,
                LXtStereoComposite       mode);
                LXxMETHOD(  LxResult,
        GetBloomEnabled) (
                LXtObjectID              self,
                int                     *enabled);

                LXxMETHOD(  LxResult,
        SetBloomEnabled) (
                LXtObjectID              self,
                int                      enabled);

                LXxMETHOD(  LxResult,
        GetBloomThreshold) (
                LXtObjectID              self,
                double                  *threshold);

                LXxMETHOD(  LxResult,
        SetBloomThreshold) (
                LXtObjectID              self,
                double                   threshold);

                LXxMETHOD(  LxResult,
        GetBloomRadius) (
                LXtObjectID              self,
                double                  *radius);

                LXxMETHOD(  LxResult,
        SetBloomRadius) (
                LXtObjectID              self,
                double                   radius);

                LXxMETHOD(  LxResult,
        GetLevelOffset) (
                LXtObjectID              self,
                double                  *offset);

                LXxMETHOD(  LxResult,
        SetLevelOffset) (
                LXtObjectID              self,
                double                   offset);

                LXxMETHOD(  LxResult,
        GetRedLevelOffset) (
                LXtObjectID              self,
                double                  *offset);

                LXxMETHOD(  LxResult,
        SetRedLevelOffset) (
                LXtObjectID              self,
                double                   offset);

                LXxMETHOD(  LxResult,
        GetGreenLevelOffset) (
                LXtObjectID              self,
                double                  *offset);

                LXxMETHOD(  LxResult,
        SetGreenLevelOffset) (
                LXtObjectID              self,
                double                   offset);

                LXxMETHOD(  LxResult,
        GetBlueLevelOffset) (
                LXtObjectID              self,
                double                  *offset);

                LXxMETHOD(  LxResult,
        SetBlueLevelOffset) (
                LXtObjectID              self,
                double                   offset);

                LXxMETHOD(  LxResult,
        GetInputBlackLevel) (
                LXtObjectID              self,
                double                  *inputBlackLevel);

                LXxMETHOD(  LxResult,
        SetInputBlackLevel) (
                LXtObjectID              self,
                double                   blackLevel);

                LXxMETHOD(  LxResult,
        GetInputGrayLevel) (
                LXtObjectID              self,
                double                  *gamma);

                LXxMETHOD(  LxResult,
        GetInvInputGrayLevel) (
                LXtObjectID              self,
                double                  *invGamma);

                LXxMETHOD(  LxResult,
        SetInputGrayLevel) (
                LXtObjectID              self,
                double                   gamma);

                LXxMETHOD(  LxResult,
        GetInputWhiteLevel) (
                LXtObjectID              self,
                double                  *inputWhiteLevel);

                LXxMETHOD(  LxResult,
        SetInputWhiteLevel) (
                LXtObjectID              self,
                double                   whiteLevel);

                LXxMETHOD(  LxResult,
        GetInputMinRedLevel) (
                LXtObjectID              self,
                double                  *inputLevel);

                LXxMETHOD(  LxResult,
        SetInputMinRedLevel) (
                LXtObjectID              self,
                double                   level);

                LXxMETHOD(  LxResult,
        GetInputRedGrayLevel) (
                LXtObjectID              self,
                double                  *gamma);

                LXxMETHOD(  LxResult,
        GetInvInputRedGrayLevel) (
                LXtObjectID              self,
                double                  *invGamma);

                LXxMETHOD(  LxResult,
        SetInputRedGrayLevel) (
                LXtObjectID              self,
                double                   gamma);

                LXxMETHOD(  LxResult,
        GetInputMaxRedLevel) (
                LXtObjectID              self,
                double                  *inputLevel);

                LXxMETHOD(  LxResult,
        SetInputMaxRedLevel) (
                LXtObjectID              self,
                double                   level);

                LXxMETHOD(  LxResult,
        GetInputMinGreenLevel) (
                LXtObjectID              self,
                double                  *inputLevel);

                LXxMETHOD(  LxResult,
        SetInputMinGreenLevel) (
                LXtObjectID              self,
                double                   level);

                LXxMETHOD(  LxResult,
        GetInputGreenGrayLevel) (
                LXtObjectID              self,
                double                  *gamma);

                LXxMETHOD(  LxResult,
        GetInvInputGreenGrayLevel) (
                LXtObjectID              self,
                double                  *invGamma);

                LXxMETHOD(  LxResult,
        SetInputGreenGrayLevel) (
                LXtObjectID              self,
                double                   gamma);

                LXxMETHOD(  LxResult,
        GetInputMaxGreenLevel) (
                LXtObjectID              self,
                double                  *inputLevel);

                LXxMETHOD(  LxResult,
        SetInputMaxGreenLevel) (
                LXtObjectID              self,
                double                   level);

                LXxMETHOD(  LxResult,
        GetInputMinBlueLevel) (
                LXtObjectID              self,
                double                  *inputLevel);

                LXxMETHOD(  LxResult,
        SetInputMinBlueLevel) (
                LXtObjectID              self,
                double                   level);

                LXxMETHOD(  LxResult,
        GetInputBlueGrayLevel) (
                LXtObjectID              self,
                double                  *gamma);

                LXxMETHOD(  LxResult,
        GetInvInputBlueGrayLevel) (
                LXtObjectID              self,
                double                  *invGamma);

                LXxMETHOD(  LxResult,
        SetInputBlueGrayLevel) (
                LXtObjectID              self,
                double                   gamma);

                LXxMETHOD(  LxResult,
        GetInputMaxBlueLevel) (
                LXtObjectID              self,
                double                  *inputLevel);

                LXxMETHOD(  LxResult,
        SetInputMaxBlueLevel) (
                LXtObjectID              self,
                double                   level);

                LXxMETHOD(  LxResult,
        GetToneMapping) (
                LXtObjectID              self,
                double                  *toneMapping);

                LXxMETHOD(  LxResult,
        SetToneMapping) (
                LXtObjectID              self,
                double                   toneMapping);

                LXxMETHOD(  LxResult,
        GetHueOffset) (
                LXtObjectID              self,
                double                  *hueOffset);

                LXxMETHOD(  LxResult,
        SetHueOffset) (
                LXtObjectID              self,
                double                   hueOffset);


                LXxMETHOD(  LxResult,
        GetSaturation) (
                LXtObjectID              self,
                double                  *saturation);

                LXxMETHOD(  LxResult,
        SetSaturation) (
                LXtObjectID              self,
                double                   saturation);

                LXxMETHOD(  LxResult,
        GetColorization) (
                LXtObjectID              self,
                double                  *colorization);

                LXxMETHOD(  LxResult,
        SetColorization) (
                LXtObjectID              self,
                double                   colorization);

                LXxMETHOD(  LxResult,
        GetTargetColor) (
                LXtObjectID              self,
                double                  *color);

                LXxMETHOD(  LxResult,
        SetTargetColor) (
                LXtObjectID              self,
                const double            *color);

                LXxMETHOD(  LxResult,
        GetOutputBlackLevel) (
                LXtObjectID              self,
                double                  *outputBlackLevel);

                LXxMETHOD(  LxResult,
        SetOutputBlackLevel) (
                LXtObjectID              self,
                double                   blackLevel);

                LXxMETHOD(  LxResult,
        GetOutputWhiteLevel) (
                LXtObjectID              self,
                double                  *outputWhiteLevel);

                LXxMETHOD(  LxResult,
        SetOutputWhiteLevel) (
                LXtObjectID              self,
                double                   whiteLevel);

                LXxMETHOD(  LxResult,
        GetOutputMinRedLevel) (
                LXtObjectID              self,
                double                  *outputLevel);

                LXxMETHOD(  LxResult,
        SetOutputMinRedLevel) (
                LXtObjectID              self,
                double                   outputLevel);

                LXxMETHOD(  LxResult,
        GetOutputMaxRedLevel) (
                LXtObjectID              self,
                double                  *outputLevel);

                LXxMETHOD(  LxResult,
        SetOutputMaxRedLevel) (
                LXtObjectID              self,
                double                   outputLevel);

                LXxMETHOD(  LxResult,
        GetOutputMinGreenLevel) (
                LXtObjectID              self,
                double                  *outputLevel);

                LXxMETHOD(  LxResult,
        SetOutputMinGreenLevel) (
                LXtObjectID              self,
                double                   outputLevel);

                LXxMETHOD(  LxResult,
        GetOutputMaxGreenLevel) (
                LXtObjectID              self,
                double                  *outputLevel);

                LXxMETHOD(  LxResult,
        SetOutputMaxGreenLevel) (
                LXtObjectID              self,
                double                   outputLevel);

                LXxMETHOD(  LxResult,
        GetOutputMinBlueLevel) (
                LXtObjectID              self,
                double                  *outputLevel);

                LXxMETHOD(  LxResult,
        SetOutputMinBlueLevel) (
                LXtObjectID              self,
                double                   outputLevel);

                LXxMETHOD(  LxResult,
        GetOutputMaxBlueLevel) (
                LXtObjectID              self,
                double                  *outputLevel);

                LXxMETHOD(  LxResult,
        SetOutputMaxBlueLevel) (
                LXtObjectID              self,
                double                   outputLevel);

                LXxMETHOD(  LxResult,
        GetOutputGamma) (
                LXtObjectID              self,
                double                  *outputGamma);

                LXxMETHOD(  LxResult,
        GetOutputInvGamma) (
                LXtObjectID              self,
                double                  *outputInvGamma);

                LXxMETHOD(  LxResult,
        SetOutputGamma) (
                LXtObjectID              self,
                double                   gamma);

} ILxImageProcessing;
typedef struct vt_ILxImageProcessingListener {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Changed) (
                LXtObjectID              self,
                const char              *identifier,
                int                      eventCode);
                LXxMETHOD(  LxResult,
        Reset) (
                LXtObjectID              self,
                const char              *identifier);
} ILxImageProcessingListener;
typedef struct vt_ILxImageProcessingRead {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        GetIdentifier) (
                LXtObjectID               self,
                const char              **string);

                LXxMETHOD(  LxResult,
        CopyToRenderProcess) (
                LXtObjectID              self,
                RenderOutputProcess     *rop);

                LXxMETHOD(  LxResult,
        CopySettingsToFrameBuffer) (
                LXtObjectID              self,
                LXtObjectID              frameBuffer,
                int                      bufferIndex);

                LXxMETHOD(  LxResult,
        ApplyToImageFromFrameBuffer) (
                LXtObjectID                      self,
                LXtObjectID                      frameBuffer,
                int                              bufferIndex,
                LXtObjectID                      image,
                float                            xOffset,
                float                            yOffset,
                float                            zoom);

                LXxMETHOD(  LxResult,
        ApplyToImageFromFrameBufferOverride) (
                LXtObjectID                      self,
                LXtObjectID                      frameBuffer,
                int                              bufferIndex,
                LXtObjectID                      image,
                float                            xOffset,
                float                            yOffset,
                float                            zoom,
                LXtImageProcessingOperators      opOverride);

                LXxMETHOD(  LxResult,
        ApplyToFrameBuffer) (
                LXtObjectID                      self,
                LXtObjectID                      frameBuffer,
                int                              bufferIndex);

                LXxMETHOD(  LxResult,
        ApplyToFrameBufferOverride) (
                LXtObjectID                      self,
                LXtObjectID                      frameBuffer,
                int                              bufferIndex,
                LXtImageProcessingOperators      opOverride);

                LXxMETHOD(  LxResult,
        ApplyToImage) (
                LXtObjectID                      self,
                LXtObjectID                      srcImage,
                LXtObjectID                      dstImage);

                LXxMETHOD(  LxResult,
        ApplyToImageOverride) (
                LXtObjectID                      self,
                LXtObjectID                      srcImage,
                LXtObjectID                      dstImage,
                LXtImageProcessingOperators      opOverride);

                LXxMETHOD(  LxResult,
        GetImageProcessingOperators) (
                LXtObjectID                      self,
                LXtImageProcessingOperators     *ops);

                LXxMETHOD(  LxResult,
        AreaProcessingActive) (
                LXtObjectID              self,
                int                     *active);

                LXxMETHOD(  LxResult,
        GetSourceImageGamma) (
                LXtObjectID              self,
                double                  *gamma);

                LXxMETHOD(  LxResult,
        GetSourceImageIsStereoSideBySide) (
                LXtObjectID              self,
                int                     *isStereo);

                LXxMETHOD(  LxResult,
        GetSaveProcessed) (
                LXtObjectID              self,
                int                     *enabled);

                LXxMETHOD(  LxResult,
        GetStereoEye) (
                LXtObjectID              self,
                int                     *eye);

                LXxMETHOD(  LxResult,
        GetStereoComposite) (
                LXtObjectID              self,
                int                     *mode);

                LXxMETHOD(  LxResult,
        GetBloomEnabled) (
                LXtObjectID              self,
                int                     *enabled);

                LXxMETHOD(  LxResult,
        GetBloomThreshold) (
                LXtObjectID              self,
                double                  *threshold);

                LXxMETHOD(  LxResult,
        GetBloomRadius) (
                LXtObjectID              self,
                double                  *radius);

                LXxMETHOD(  LxResult,
        GetLevelOffset) (
                LXtObjectID              self,
                double                  *offset);

                LXxMETHOD(  LxResult,
        GetRedLevelOffset) (
                LXtObjectID              self,
                double                  *offset);

                LXxMETHOD(  LxResult,
        GetGreenLevelOffset) (
                LXtObjectID              self,
                double                  *offset);

                LXxMETHOD(  LxResult,
        GetBlueLevelOffset) (
                LXtObjectID              self,
                double                  *offset);

                LXxMETHOD(  LxResult,
        GetInputBlackLevel) (
                LXtObjectID              self,
                double                  *inputLevel);

                LXxMETHOD(  LxResult,
        GetInputGrayLevel) (
                LXtObjectID              self,
                double                  *gamma);

                LXxMETHOD(  LxResult,
        GetInvInputGrayLevel) (
                LXtObjectID              self,
                double                  *invGamma);

                LXxMETHOD(  LxResult,
        GetInputWhiteLevel) (
                LXtObjectID              self,
                double                  *inputLevel);

                LXxMETHOD(  LxResult,
        GetInputMinRedLevel) (
                LXtObjectID              self,
                double                  *inputLevel);

                LXxMETHOD(  LxResult,
        GetInputRedGrayLevel) (
                LXtObjectID              self,
                double                  *gamma);

                LXxMETHOD(  LxResult,
        GetInvInputRedGrayLevel) (
                LXtObjectID              self,
                double                  *invGamma);

                LXxMETHOD(  LxResult,
        GetInputMaxRedLevel) (
                LXtObjectID              self,
                double                  *inputLevel);

                LXxMETHOD(  LxResult,
        GetInputMinGreenLevel) (
                LXtObjectID              self,
                double                  *inputLevel);

                LXxMETHOD(  LxResult,
        GetInputGreenGrayLevel) (
                LXtObjectID              self,
                double                  *gamma);

                LXxMETHOD(  LxResult,
        GetInvInputGreenGrayLevel) (
                LXtObjectID              self,
                double                  *invGamma);

                LXxMETHOD(  LxResult,
        GetInputMaxGreenLevel) (
                LXtObjectID              self,
                double                  *inputLevel);

                LXxMETHOD(  LxResult,
        GetInputMinBlueLevel) (
                LXtObjectID              self,
                double                  *inputLevel);

                LXxMETHOD(  LxResult,
        GetInputBlueGrayLevel) (
                LXtObjectID              self,
                double                  *gamma);

                LXxMETHOD(  LxResult,
        GetInvInputBlueGrayLevel) (
                LXtObjectID              self,
                double                  *invGamma);

                LXxMETHOD(  LxResult,
        GetInputMaxBlueLevel) (
                LXtObjectID              self,
                double                  *inputLevel);

                LXxMETHOD(  LxResult,
        GetToneMapping) (
                LXtObjectID              self,
                double                  *toneMapping);

                LXxMETHOD(  LxResult,
        GetHueOffset) (
                LXtObjectID              self,
                double                  *hueOffset);

                LXxMETHOD(  LxResult,
        GetSaturation) (
                LXtObjectID              self,
                double                  *saturation);

                LXxMETHOD(  LxResult,
        GetColorization) (
                LXtObjectID              self,
                double                  *colorization);

                LXxMETHOD(  LxResult,
        GetTargetColor) (
                LXtObjectID              self,
                double                  *color);

                LXxMETHOD(  LxResult,
        GetOutputBlackLevel) (
                LXtObjectID              self,
                double                  *outputLevel);

                LXxMETHOD(  LxResult,
        GetOutputWhiteLevel) (
                LXtObjectID              self,
                double                  *outputLevel);

                LXxMETHOD(  LxResult,
        GetOutputMinRedLevel) (
                LXtObjectID              self,
                double                  *outputLevel);

                LXxMETHOD(  LxResult,
        GetOutputMaxRedLevel) (
                LXtObjectID              self,
                double                  *outputLevel);

                LXxMETHOD(  LxResult,
        GetOutputMinGreenLevel) (
                LXtObjectID              self,
                double                  *outputLevel);

                LXxMETHOD(  LxResult,
        GetOutputMaxGreenLevel) (
                LXtObjectID              self,
                double                  *outputLevel);

                LXxMETHOD(  LxResult,
        GetOutputMinBlueLevel) (
                LXtObjectID              self,
                double                  *outputLevel);

                LXxMETHOD(  LxResult,
        GetOutputMaxBlueLevel) (
                LXtObjectID              self,
                double                  *outputLevel);

                LXxMETHOD(  LxResult,
        GetOutputGamma) (
                LXtObjectID              self,
                double                  *outputGamma);

                LXxMETHOD(  LxResult,
        GetOutputInvGamma) (
                LXtObjectID              self,
                double                  *outputInvGamma);

} ILxImageProcessingRead;
typedef struct vt_ILxImageProcessingService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        Create) (
                LXtObjectID              self,
                void                    **ppvObj);
} ILxImageProcessingService;

#define LXa_RENDERSERVICE               "renderservice"
#define LXu_RENDERSERVICE               "8D1710CE-7AF4-46cd-B6B1-222A7DC4C53F"
//[const] ILxRenderService:JobCurrent
//[const] ILxRenderService:JobGetCurrent
//[const] ILxRenderService:JobStatus
//[const] ILxRenderService:JobIsSlave
//[const] ILxRenderService:JobRenderOutputCount
//[const] ILxRenderService:JobRenderOutputName
//[const] ILxRenderService:JobRenderOutputType

#define LXe_RENDER_IDLE                 LXxGOODCODE( LXeSYS_RENDER, 1)
#define LXe_RENDER_RENDERING            LXxGOODCODE( LXeSYS_RENDER, 2)
#define LXe_RENDER_USE_OUTPUT_ITEMS     LXxGOODCODE( LXeSYS_RENDER, 3)
#define LXe_RENDER_WITHOUT_SAVING       LXxGOODCODE( LXeSYS_RENDER, 4)

#define LXe_RENDER_NO_JOB               LXxFAILCODE( LXeSYS_RENDER, 1)
#define LXe_RENDER_IN_PROGRESS          LXxFAILCODE( LXeSYS_RENDER, 2)
#define LXe_RENDER_NOT_RENDERING        LXxFAILCODE( LXeSYS_RENDER, 3)

#define LXe_RENDER_ABORTING             LXe_ABORT

#define LXe_RENDER_NO_PROGRESS_IMAGE    LXxGOODCODE( LXeSYS_RENDER, 5)

#define LXa_RENDERJOB                   "renderjob"
#define LXu_RENDERJOB                   "091C8EB2-5DC1-4d01-AF9B-3C735F2FFB1D"
// [local] ILxRenderJob
// [export] ILxRenderJob rjob
// [const] ILxRenderJob:RenderItem
// [const] ILxRenderJob:ActionName
// [const] ILxRenderJob:GroupName
// [const] ILxRenderJob:RenderAs
// [const] ILxRenderJob:RenderAtTime
// [const] ILxRenderJob:RenderTurntableFPS
// [const] ILxRenderJob:RenderTurntableNumFrames
// [const] ILxRenderJob:RenderBakeVMap
// [const] ILxRenderJob:RenderBakeLookDistance
// [const] ILxRenderJob:RenderBakeItem
// [const] ILxRenderJob:RenderBakeEffect
// [const] ILxRenderJob:RenderBakeImage
// [const] ILxRenderJob:FrameBufferSlot
// [const] ILxRenderJob:FrameBufferRegionBackgroundSlot
// [const] ILxRenderJob:OutputFormat
// [const] ILxRenderJob:OutputFilename
// [const] ILxRenderJob:Options
#define LXiRENDERTYPE_FRAME                     0
#define LXiRENDERTYPE_ANIM                      1
#define LXiRENDERTYPE_TURNTABLE_CAMERA          2
#define LXiRENDERTYPE_TURNTABLE_GEOMETRY        3
#define LXiRENDERTYPE_BAKE_SCENE                4
#define LXiRENDERTYPE_BAKE_TEXTURE              5
#define LXfRENDEROPT_NO_WAITING         0x0001
#define LXfRENDEROPT_NO_IMAGE           0x0002
#define LXfRENDEROPT_NO_CLEANUP         0x0004
#define LXfRENDEROPT_IC_ONLY            0x0008
#define LXa_RENDERSTATS                 "renderstats"
#define LXu_RENDERSTATS                 "091C8EB2-5DC1-4d01-AF9B-3C735F2FFB1D"
#define LXa_BUFFER      "renderBuffer"
#define LXu_BUFFER      "088D0A6B-7A83-4774-AA56-473F6C241F40"
//[local] ILxBuffer
//[export] ILxBuffer buff
//[const] ILxBuffer:GetSize
//[const] ILxBuffer:Pixel
//[const] ILxBuffer:Line
//[const] ILxBuffer:Name
//[const] ILxBuffer:UserName
//[const] ILxBuffer:DataType
//[const] ILxBuffer:Flags
//[const] ILxBuffer:VectorType
//[const] ILxBuffer:GetImageTileTree
//[const] ILxBuffer:GetImageTileTreeSize
#define LXf_RBF_NO_AA            0x01   // render buffer is not anti-aliased
#define LXf_RBF_DITHER           0x02   // render buffer can be dithered
#define LXf_RBF_IS_FACTORY_NAME  0x08   // render buffer is factory named
#define LXiRBD_FLOAT             0
#define LXiRBD_FLOAT3            1
#define LXiRBD_OTHER             2
#define LXa_FRAMEBUFFER         "frameBuffer"
#define LXu_FRAMEBUFFER         "90B060B4-1EC2-45F4-A6A8-9A3822B9B39C"
//[local] ILxFrameBuffer
//[export] ILxFrameBuffer fbuf
//[const] ILxFrameBuffer:IsStereo
//[const] ILxFrameBuffer:GetStereoEyeDisplay
//[const] ILxFrameBuffer:GetStereoComposite
//[const] ILxFrameBuffer:Lookup
//[const] ILxFrameBuffer:Count
//[const] ILxFrameBuffer:ByIndex
//[const] ILxFrameBuffer:Alpha
#define LXa_IMAGEPROCESSING             "imageprocessing"
#define LXu_IMAGEPROCESSING             "1a89cc09-5326-44d6-9605-3b66bf9c03f5"
//[local]  ILxImageProcessing
//[const]  ILxImageProcessing:GetIdentifier
//[const]  ILxImageProcessing:GetBloomEnabled
#define LXa_IMAGEPROCESSINGLISTENER     "imageprocessinglistener"
#define LXu_IMAGEPROCESSINGLISTENER     "4a4ca8b2-df07-4156-b1c3-a5fc63318ea8"
//[local]  ILxImageProcessingListener
#define LXfIMAGEPROC_EVENT_CHANGED                                       0x10000000     // One of the image processing Set...() methods was called
#define LXfIMAGEPROC_EVENT_MAINTENANCE                                   0x20000000     // A mantenance method like Reset() was called

#define LXmIMAGEPROC_EVENT_RESERVED                                      0x0000000F     // Reserved for internal use (see above)

#define LXiIMAGEPROC_EVENT_CHANGED_OPERATORS                            (0x00000010 | LXfIMAGEPROC_EVENT_CHANGED)
#define LXiIMAGEPROC_EVENT_CHANGED_SOURCE_IMAGE_GAMMA                   (0x00000020 | LXfIMAGEPROC_EVENT_CHANGED)
#define LXiIMAGEPROC_EVENT_CHANGED_SAVE_PROCESSED                       (0x00000040 | LXfIMAGEPROC_EVENT_CHANGED)

#define LXiIMAGEPROC_EVENT_CHANGED_BLOOM_ENABLED                        (0x00000080 | LXfIMAGEPROC_EVENT_CHANGED)
#define LXiIMAGEPROC_EVENT_CHANGED_BLOOM_THRESHOLD                      (0x00000100 | LXfIMAGEPROC_EVENT_CHANGED)
#define LXiIMAGEPROC_EVENT_CHANGED_BLOOM_RADIUS                         (0x00000200 | LXfIMAGEPROC_EVENT_CHANGED)

#define LXiIMAGEPROC_EVENT_CHANGED_LEVEL_OFFSET                         (0x00000400 | LXfIMAGEPROC_EVENT_CHANGED)

#define LXiIMAGEPROC_EVENT_CHANGED_INPUT_BLACK_LEVEL                    (0x00000800 | LXfIMAGEPROC_EVENT_CHANGED)
#define LXiIMAGEPROC_EVENT_CHANGED_INPUT_GRAY_LEVEL                     (0x00001000 | LXfIMAGEPROC_EVENT_CHANGED)
#define LXiIMAGEPROC_EVENT_CHANGED_INPUT_WHITE_LEVEL                    (0x00002000 | LXfIMAGEPROC_EVENT_CHANGED)

#define LXiIMAGEPROC_EVENT_CHANGED_INPUT_MIN_RGB_LEVEL                  (0x00004000 | LXfIMAGEPROC_EVENT_CHANGED)
#define LXiIMAGEPROC_EVENT_CHANGED_INPUT_GRAY_RGB_LEVEL                 (0x00008000 | LXfIMAGEPROC_EVENT_CHANGED)
#define LXiIMAGEPROC_EVENT_CHANGED_INPUT_MAX_RGB_LEVEL                  (0x00010000 | LXfIMAGEPROC_EVENT_CHANGED)

#define LXiIMAGEPROC_EVENT_CHANGED_TONE_MAPPING                         (0x00020000 | LXfIMAGEPROC_EVENT_CHANGED)

#define LXiIMAGEPROC_EVENT_CHANGED_HUE_OFFSET                           (0x00040000 | LXfIMAGEPROC_EVENT_CHANGED)
#define LXiIMAGEPROC_EVENT_CHANGED_SATURATION                           (0x00080000 | LXfIMAGEPROC_EVENT_CHANGED)
#define LXiIMAGEPROC_EVENT_CHANGED_COLORIZATION                         (0x00100000 | LXfIMAGEPROC_EVENT_CHANGED)
#define LXiIMAGEPROC_EVENT_CHANGED_TARGET_COLOR                         (0x00200000 | LXfIMAGEPROC_EVENT_CHANGED)

#define LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_BLACK_LEVEL                   (0x00400000 | LXfIMAGEPROC_EVENT_CHANGED)
#define LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_WHITE_LEVEL                   (0x00800000 | LXfIMAGEPROC_EVENT_CHANGED)

#define LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_MIN_RGB_LEVEL                 (0x01000000 | LXfIMAGEPROC_EVENT_CHANGED)
#define LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_MAX_RGB_LEVEL                 (0x02000000 | LXfIMAGEPROC_EVENT_CHANGED)

#define LXiIMAGEPROC_EVENT_CHANGED_OUTPUT_GAMMA                         (0x04000000 | LXfIMAGEPROC_EVENT_CHANGED)
#define LXiIMAGEPROC_EVENT_CHANGED_RESPECT_RENDER_VIEW_GAMMA_PREF       (0x08000000 | LXfIMAGEPROC_EVENT_CHANGED)

#define LXiIMAGEPROC_EVENT_RESET                                        (0x00000001 | LXfIMAGEPROC_EVENT_MAINTENANCE)
#define LXa_IMAGEPROCESSINGREAD         "imageprocessingread"
#define LXu_IMAGEPROCESSINGREAD         "154307c9-5fa3-4749-8853-088e2cc1f5ed"
//[local]  ILxImageProcessingRead
//[const]  ILxImageProcessingRead:GetIdentifier
//[const]  ILxImageProcessingRead:CopySettingsToFrameBuffer
#define LXa_IMAGEPROCESSINGSERVICE      "imageprocessingservice"
#define LXu_IMAGEPROCESSINGSERVICE      "2f403a5c-a6aa-4d5a-88f6-a2dff23da523"
//[local]  ILxImageProcessingService

 #ifdef __cplusplus
  }
 #endif
#endif

