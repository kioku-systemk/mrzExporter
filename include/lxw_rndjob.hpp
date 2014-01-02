/*
 * C++ wrapper for lxrndjob.h
 *
 *	Copyright (c) 2008-2013 Luxology LLC
 *	
 *	Permission is hereby granted, free of charge, to any person obtaining a
 *	copy of this software and associated documentation files (the "Software"),
 *	to deal in the Software without restriction, including without limitation
 *	the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *	and/or sell copies of the Software, and to permit persons to whom the
 *	Software is furnished to do so, subject to the following conditions:
 *	
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.   Except as contained
 *	in this notice, the name(s) of the above copyright holders shall not be
 *	used in advertising or otherwise to promote the sale, use or other dealings
 *	in this Software without prior written authorization.
 *	
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *	DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef LXW_RNDJOB_HPP
#define LXW_RNDJOB_HPP

#include <lxrndjob.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ImageProcessingRead = {0x154307c9,0x5fa3,0x4749,0x88,0x53,0x08,0x8e,0x2c,0xc1,0xf5,0xed};
    static const LXtGUID guid_Buffer = {0x088D0A6B,0x7A83,0x4774,0xAA,0x56,0x47,0x3F,0x6C,0x24,0x1F,0x40};
    static const LXtGUID guid_RenderJob = {0x091C8EB2,0x5DC1,0x4d01,0xAF,0x9B,0x3C,0x73,0x5F,0x2F,0xFB,0x1D};
    static const LXtGUID guid_ImageProcessing = {0x1a89cc09,0x5326,0x44d6,0x96,0x05,0x3b,0x66,0xbf,0x9c,0x03,0xf5};
    static const LXtGUID guid_RenderService = {0x8D1710CE,0x7AF4,0x46cd,0xB6,0xB1,0x22,0x2A,0x7D,0xC4,0xC5,0x3F};
    static const LXtGUID guid_RenderProgressListener = {0xdb045a41,0x0ed0,0x4372,0xa5,0x1a,0x09,0xb2,0x13,0x87,0xc4,0xae};
    static const LXtGUID guid_FrameBuffer = {0x90B060B4,0x1EC2,0x45F4,0xA6,0xA8,0x9A,0x38,0x22,0xB9,0xB3,0x9C};
    static const LXtGUID guid_ImageProcessingService = {0x2f403a5c,0xa6aa,0x4d5a,0x88,0xf6,0xa2,0xdf,0xf2,0x3d,0xa5,0x23};
    static const LXtGUID guid_ImageProcessingListener = {0x4a4ca8b2,0xdf07,0x4156,0xb1,0xc3,0xa5,0xfc,0x63,0x31,0x8e,0xa8};
    static const LXtGUID guid_RenderStats = {0x091C8EB2,0x5DC1,0x4d01,0xAF,0x9B,0x3C,0x73,0x5F,0x2F,0xFB,0x1D};
};

class CLxLoc_ImageProcessingRead : public CLxLocalize<ILxImageProcessingReadID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ImageProcessingRead() {_init();}
  CLxLoc_ImageProcessingRead(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ImageProcessingRead(const CLxLoc_ImageProcessingRead &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ImageProcessingRead;}
    LxResult
  GetIdentifier (const char **string) const
  {
    return m_loc[0]->GetIdentifier (m_loc,string);
  }
    LxResult
  CopyToRenderProcess (LXtRenderOutputProcess *rop)
  {
    return m_loc[0]->CopyToRenderProcess (m_loc,rop);
  }
    LxResult
  CopySettingsToFrameBuffer (ILxUnknownID frameBuffer, int bufferIndex) const
  {
    return m_loc[0]->CopySettingsToFrameBuffer (m_loc,(ILxUnknownID)frameBuffer,bufferIndex);
  }
    LxResult
  ApplyToImageFromFrameBuffer (ILxUnknownID frameBuffer, int bufferIndex, ILxUnknownID image, float xOffset, float yOffset, float zoom)
  {
    return m_loc[0]->ApplyToImageFromFrameBuffer (m_loc,(ILxUnknownID)frameBuffer,bufferIndex,(ILxUnknownID)image,xOffset,yOffset,zoom);
  }
    LxResult
  ApplyToImageFromFrameBufferOverride (ILxUnknownID frameBuffer, int bufferIndex, ILxUnknownID image, float xOffset, float yOffset, float zoom, LXtImageProcessingOperators opOverride)
  {
    return m_loc[0]->ApplyToImageFromFrameBufferOverride (m_loc,(ILxUnknownID)frameBuffer,bufferIndex,(ILxUnknownID)image,xOffset,yOffset,zoom,opOverride);
  }
    LxResult
  ApplyToFrameBuffer (ILxUnknownID frameBuffer, int bufferIndex)
  {
    return m_loc[0]->ApplyToFrameBuffer (m_loc,(ILxUnknownID)frameBuffer,bufferIndex);
  }
    LxResult
  ApplyToFrameBufferOverride (ILxUnknownID frameBuffer, int bufferIndex, LXtImageProcessingOperators opOverride)
  {
    return m_loc[0]->ApplyToFrameBufferOverride (m_loc,(ILxUnknownID)frameBuffer,bufferIndex,opOverride);
  }
    LxResult
  ApplyToImage (ILxUnknownID srcImage, ILxUnknownID dstImage)
  {
    return m_loc[0]->ApplyToImage (m_loc,(ILxUnknownID)srcImage,(ILxUnknownID)dstImage);
  }
    LxResult
  ApplyToImageOverride (ILxUnknownID srcImage, ILxUnknownID dstImage, LXtImageProcessingOperators opOverride)
  {
    return m_loc[0]->ApplyToImageOverride (m_loc,(ILxUnknownID)srcImage,(ILxUnknownID)dstImage,opOverride);
  }
    LxResult
  GetImageProcessingOperators (LXtImageProcessingOperators *ops)
  {
    return m_loc[0]->GetImageProcessingOperators (m_loc,ops);
  }
    LxResult
  AreaProcessingActive (int *active)
  {
    return m_loc[0]->AreaProcessingActive (m_loc,active);
  }
    LxResult
  GetSourceImageGamma (double *gamma)
  {
    return m_loc[0]->GetSourceImageGamma (m_loc,gamma);
  }
    LxResult
  GetSourceImageIsStereoSideBySide (int *isStereo)
  {
    return m_loc[0]->GetSourceImageIsStereoSideBySide (m_loc,isStereo);
  }
    LxResult
  GetSaveProcessed (int *enabled)
  {
    return m_loc[0]->GetSaveProcessed (m_loc,enabled);
  }
    LxResult
  GetStereoEye (int *eye)
  {
    return m_loc[0]->GetStereoEye (m_loc,eye);
  }
    LxResult
  GetStereoComposite (int *mode)
  {
    return m_loc[0]->GetStereoComposite (m_loc,mode);
  }
    LxResult
  GetBloomEnabled (int *enabled)
  {
    return m_loc[0]->GetBloomEnabled (m_loc,enabled);
  }
    LxResult
  GetBloomThreshold (double *threshold)
  {
    return m_loc[0]->GetBloomThreshold (m_loc,threshold);
  }
    LxResult
  GetBloomRadius (double *radius)
  {
    return m_loc[0]->GetBloomRadius (m_loc,radius);
  }
    LxResult
  GetLevelOffset (double *offset)
  {
    return m_loc[0]->GetLevelOffset (m_loc,offset);
  }
    LxResult
  GetRedLevelOffset (double *offset)
  {
    return m_loc[0]->GetRedLevelOffset (m_loc,offset);
  }
    LxResult
  GetGreenLevelOffset (double *offset)
  {
    return m_loc[0]->GetGreenLevelOffset (m_loc,offset);
  }
    LxResult
  GetBlueLevelOffset (double *offset)
  {
    return m_loc[0]->GetBlueLevelOffset (m_loc,offset);
  }
    LxResult
  GetInputBlackLevel (double *inputLevel)
  {
    return m_loc[0]->GetInputBlackLevel (m_loc,inputLevel);
  }
    LxResult
  GetInputGrayLevel (double *gamma)
  {
    return m_loc[0]->GetInputGrayLevel (m_loc,gamma);
  }
    LxResult
  GetInvInputGrayLevel (double *invGamma)
  {
    return m_loc[0]->GetInvInputGrayLevel (m_loc,invGamma);
  }
    LxResult
  GetInputWhiteLevel (double *inputLevel)
  {
    return m_loc[0]->GetInputWhiteLevel (m_loc,inputLevel);
  }
    LxResult
  GetInputMinRedLevel (double *inputLevel)
  {
    return m_loc[0]->GetInputMinRedLevel (m_loc,inputLevel);
  }
    LxResult
  GetInputRedGrayLevel (double *gamma)
  {
    return m_loc[0]->GetInputRedGrayLevel (m_loc,gamma);
  }
    LxResult
  GetInvInputRedGrayLevel (double *invGamma)
  {
    return m_loc[0]->GetInvInputRedGrayLevel (m_loc,invGamma);
  }
    LxResult
  GetInputMaxRedLevel (double *inputLevel)
  {
    return m_loc[0]->GetInputMaxRedLevel (m_loc,inputLevel);
  }
    LxResult
  GetInputMinGreenLevel (double *inputLevel)
  {
    return m_loc[0]->GetInputMinGreenLevel (m_loc,inputLevel);
  }
    LxResult
  GetInputGreenGrayLevel (double *gamma)
  {
    return m_loc[0]->GetInputGreenGrayLevel (m_loc,gamma);
  }
    LxResult
  GetInvInputGreenGrayLevel (double *invGamma)
  {
    return m_loc[0]->GetInvInputGreenGrayLevel (m_loc,invGamma);
  }
    LxResult
  GetInputMaxGreenLevel (double *inputLevel)
  {
    return m_loc[0]->GetInputMaxGreenLevel (m_loc,inputLevel);
  }
    LxResult
  GetInputMinBlueLevel (double *inputLevel)
  {
    return m_loc[0]->GetInputMinBlueLevel (m_loc,inputLevel);
  }
    LxResult
  GetInputBlueGrayLevel (double *gamma)
  {
    return m_loc[0]->GetInputBlueGrayLevel (m_loc,gamma);
  }
    LxResult
  GetInvInputBlueGrayLevel (double *invGamma)
  {
    return m_loc[0]->GetInvInputBlueGrayLevel (m_loc,invGamma);
  }
    LxResult
  GetInputMaxBlueLevel (double *inputLevel)
  {
    return m_loc[0]->GetInputMaxBlueLevel (m_loc,inputLevel);
  }
    LxResult
  GetToneMapping (double *toneMapping)
  {
    return m_loc[0]->GetToneMapping (m_loc,toneMapping);
  }
    LxResult
  GetHueOffset (double *hueOffset)
  {
    return m_loc[0]->GetHueOffset (m_loc,hueOffset);
  }
    LxResult
  GetSaturation (double *saturation)
  {
    return m_loc[0]->GetSaturation (m_loc,saturation);
  }
    LxResult
  GetColorization (double *colorization)
  {
    return m_loc[0]->GetColorization (m_loc,colorization);
  }
    LxResult
  GetTargetColor (double *color)
  {
    return m_loc[0]->GetTargetColor (m_loc,color);
  }
    LxResult
  GetOutputBlackLevel (double *outputLevel)
  {
    return m_loc[0]->GetOutputBlackLevel (m_loc,outputLevel);
  }
    LxResult
  GetOutputWhiteLevel (double *outputLevel)
  {
    return m_loc[0]->GetOutputWhiteLevel (m_loc,outputLevel);
  }
    LxResult
  GetOutputMinRedLevel (double *outputLevel)
  {
    return m_loc[0]->GetOutputMinRedLevel (m_loc,outputLevel);
  }
    LxResult
  GetOutputMaxRedLevel (double *outputLevel)
  {
    return m_loc[0]->GetOutputMaxRedLevel (m_loc,outputLevel);
  }
    LxResult
  GetOutputMinGreenLevel (double *outputLevel)
  {
    return m_loc[0]->GetOutputMinGreenLevel (m_loc,outputLevel);
  }
    LxResult
  GetOutputMaxGreenLevel (double *outputLevel)
  {
    return m_loc[0]->GetOutputMaxGreenLevel (m_loc,outputLevel);
  }
    LxResult
  GetOutputMinBlueLevel (double *outputLevel)
  {
    return m_loc[0]->GetOutputMinBlueLevel (m_loc,outputLevel);
  }
    LxResult
  GetOutputMaxBlueLevel (double *outputLevel)
  {
    return m_loc[0]->GetOutputMaxBlueLevel (m_loc,outputLevel);
  }
    LxResult
  GetOutputGamma (double *outputGamma)
  {
    return m_loc[0]->GetOutputGamma (m_loc,outputGamma);
  }
    LxResult
  GetOutputInvGamma (double *outputInvGamma)
  {
    return m_loc[0]->GetOutputInvGamma (m_loc,outputInvGamma);
  }
};

class CLxImpl_Buffer {
  public:
    virtual ~CLxImpl_Buffer() {}
    virtual void
      buff_SetFlags (int flags)
        { }
    virtual int
      buff_Flags (void)
        = 0;
    virtual unsigned
      buff_DataType (void)
        = 0;
    virtual LXtObjectID
      buff_VectorType (void)
        = 0;
    virtual void
      buff_SetSize (int width, int height, int writeBucketsToDisk, int isStereo)
        { }
    virtual void
      buff_GetSize (int *width, int *height)
        { }
    virtual LxResult
      buff_SetEyeSide (int eyeSide)
        { return LXe_NOTIMPL; }
    virtual void
      buff_Clear (int x, int y)
        { }
    virtual LxResult
      buff_Convert (LXtGenVectorID gv, int x, int y, float blend)
        { return LXe_NOTIMPL; }
    virtual void *
      buff_Pixel (int x, int y)
        = 0;
    virtual void *
      buff_Line (int y)
        = 0;
    virtual LxResult
      buff_Name (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      buff_SetUserName (const char *name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      buff_UserName (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      buff_CreateImageTileTree (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      buff_DestroyImageTileTree (void)
        { return LXe_NOTIMPL; }
    virtual LXtTileTreeID
      buff_GetImageTileTree (void)
        = 0;
    virtual size_t
      buff_GetImageTileTreeSize (void)
        = 0;
    virtual LxResult
      buff_ResetImageTileTree (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      buff_IncrementTileTreeSize (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      buff_DecrementTileTreeSize (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_Buffer_SetFlags void buff_SetFlags (int flags)
#define LXxO_Buffer_SetFlags LXxD_Buffer_SetFlags LXx_OVERRIDE
#define LXxD_Buffer_Flags int buff_Flags (void)
#define LXxO_Buffer_Flags LXxD_Buffer_Flags LXx_OVERRIDE
#define LXxD_Buffer_DataType unsigned buff_DataType (void)
#define LXxO_Buffer_DataType LXxD_Buffer_DataType LXx_OVERRIDE
#define LXxD_Buffer_VectorType LXtObjectID buff_VectorType (void)
#define LXxO_Buffer_VectorType LXxD_Buffer_VectorType LXx_OVERRIDE
#define LXxD_Buffer_SetSize void buff_SetSize (int width, int height, int writeBucketsToDisk, int isStereo)
#define LXxO_Buffer_SetSize LXxD_Buffer_SetSize LXx_OVERRIDE
#define LXxD_Buffer_GetSize void buff_GetSize (int *width, int *height)
#define LXxO_Buffer_GetSize LXxD_Buffer_GetSize LXx_OVERRIDE
#define LXxD_Buffer_SetEyeSide LxResult buff_SetEyeSide (int eyeSide)
#define LXxO_Buffer_SetEyeSide LXxD_Buffer_SetEyeSide LXx_OVERRIDE
#define LXxD_Buffer_Clear void buff_Clear (int x, int y)
#define LXxO_Buffer_Clear LXxD_Buffer_Clear LXx_OVERRIDE
#define LXxD_Buffer_Convert LxResult buff_Convert (LXtGenVectorID gv, int x, int y, float blend)
#define LXxO_Buffer_Convert LXxD_Buffer_Convert LXx_OVERRIDE
#define LXxD_Buffer_Pixel void * buff_Pixel (int x, int y)
#define LXxO_Buffer_Pixel LXxD_Buffer_Pixel LXx_OVERRIDE
#define LXxD_Buffer_Line void * buff_Line (int y)
#define LXxO_Buffer_Line LXxD_Buffer_Line LXx_OVERRIDE
#define LXxD_Buffer_Name LxResult buff_Name (const char **name)
#define LXxO_Buffer_Name LXxD_Buffer_Name LXx_OVERRIDE
#define LXxD_Buffer_SetUserName LxResult buff_SetUserName (const char *name)
#define LXxO_Buffer_SetUserName LXxD_Buffer_SetUserName LXx_OVERRIDE
#define LXxD_Buffer_UserName LxResult buff_UserName (const char **name)
#define LXxO_Buffer_UserName LXxD_Buffer_UserName LXx_OVERRIDE
#define LXxD_Buffer_CreateImageTileTree LxResult buff_CreateImageTileTree (void)
#define LXxO_Buffer_CreateImageTileTree LXxD_Buffer_CreateImageTileTree LXx_OVERRIDE
#define LXxD_Buffer_DestroyImageTileTree LxResult buff_DestroyImageTileTree (void)
#define LXxO_Buffer_DestroyImageTileTree LXxD_Buffer_DestroyImageTileTree LXx_OVERRIDE
#define LXxD_Buffer_GetImageTileTree LXtTileTreeID buff_GetImageTileTree (void)
#define LXxO_Buffer_GetImageTileTree LXxD_Buffer_GetImageTileTree LXx_OVERRIDE
#define LXxD_Buffer_GetImageTileTreeSize size_t buff_GetImageTileTreeSize (void)
#define LXxO_Buffer_GetImageTileTreeSize LXxD_Buffer_GetImageTileTreeSize LXx_OVERRIDE
#define LXxD_Buffer_ResetImageTileTree LxResult buff_ResetImageTileTree (void)
#define LXxO_Buffer_ResetImageTileTree LXxD_Buffer_ResetImageTileTree LXx_OVERRIDE
#define LXxD_Buffer_IncrementTileTreeSize LxResult buff_IncrementTileTreeSize (void)
#define LXxO_Buffer_IncrementTileTreeSize LXxD_Buffer_IncrementTileTreeSize LXx_OVERRIDE
#define LXxD_Buffer_DecrementTileTreeSize LxResult buff_DecrementTileTreeSize (void)
#define LXxO_Buffer_DecrementTileTreeSize LXxD_Buffer_DecrementTileTreeSize LXx_OVERRIDE
template <class T>
class CLxIfc_Buffer : public CLxInterface
{
    static void
  SetFlags (LXtObjectID wcom, int flags)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    loc->buff_SetFlags (flags);
  }
    static int
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    return loc->buff_Flags ();
  }
    static unsigned
  DataType (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    return loc->buff_DataType ();
  }
    static LXtObjectID
  VectorType (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    return loc->buff_VectorType ();
  }
    static void
  SetSize (LXtObjectID wcom, int width, int height, int writeBucketsToDisk, int isStereo)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    loc->buff_SetSize (width,height,writeBucketsToDisk,isStereo);
  }
    static void
  GetSize (LXtObjectID wcom, int *width, int *height)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    loc->buff_GetSize (width,height);
  }
    static LxResult
  SetEyeSide (LXtObjectID wcom, int eyeSide)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    try {
      return loc->buff_SetEyeSide (eyeSide);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Clear (LXtObjectID wcom, int x, int y)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    loc->buff_Clear (x,y);
  }
    static LxResult
  Convert (LXtObjectID wcom, LXtGenVectorID gv, int x, int y, float blend)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    try {
      return loc->buff_Convert (gv,x,y,blend);
    } catch (LxResult rc) { return rc; }
  }
    static void *
  Pixel (LXtObjectID wcom, int x, int y)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    return loc->buff_Pixel (x,y);
  }
    static void *
  Line (LXtObjectID wcom, int y)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    return loc->buff_Line (y);
  }
    static LxResult
  Name (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    try {
      return loc->buff_Name (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetUserName (LXtObjectID wcom, const char *name)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    try {
      return loc->buff_SetUserName (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UserName (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    try {
      return loc->buff_UserName (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CreateImageTileTree (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    try {
      return loc->buff_CreateImageTileTree ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DestroyImageTileTree (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    try {
      return loc->buff_DestroyImageTileTree ();
    } catch (LxResult rc) { return rc; }
  }
    static LXtTileTreeID
  GetImageTileTree (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    return loc->buff_GetImageTileTree ();
  }
    static size_t
  GetImageTileTreeSize (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    return loc->buff_GetImageTileTreeSize ();
  }
    static LxResult
  ResetImageTileTree (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    try {
      return loc->buff_ResetImageTileTree ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  IncrementTileTreeSize (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    try {
      return loc->buff_IncrementTileTreeSize ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DecrementTileTreeSize (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Buffer, loc);
    try {
      return loc->buff_DecrementTileTreeSize ();
    } catch (LxResult rc) { return rc; }
  }
  ILxBuffer vt;
public:
  CLxIfc_Buffer ()
  {
    vt.SetFlags = SetFlags;
    vt.Flags = Flags;
    vt.DataType = DataType;
    vt.VectorType = VectorType;
    vt.SetSize = SetSize;
    vt.GetSize = GetSize;
    vt.SetEyeSide = SetEyeSide;
    vt.Clear = Clear;
    vt.Convert = Convert;
    vt.Pixel = Pixel;
    vt.Line = Line;
    vt.Name = Name;
    vt.SetUserName = SetUserName;
    vt.UserName = UserName;
    vt.CreateImageTileTree = CreateImageTileTree;
    vt.DestroyImageTileTree = DestroyImageTileTree;
    vt.GetImageTileTree = GetImageTileTree;
    vt.GetImageTileTreeSize = GetImageTileTreeSize;
    vt.ResetImageTileTree = ResetImageTileTree;
    vt.IncrementTileTreeSize = IncrementTileTreeSize;
    vt.DecrementTileTreeSize = DecrementTileTreeSize;
    vTable = &vt.iunk;
    iid = &lx::guid_Buffer;
  }
};
class CLxLoc_Buffer : public CLxLocalize<ILxBufferID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Buffer() {_init();}
  CLxLoc_Buffer(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Buffer(const CLxLoc_Buffer &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Buffer;}
    void
  SetFlags (int flags)
  {
    m_loc[0]->SetFlags (m_loc,flags);
  }
    int
  Flags (void) const
  {
    return m_loc[0]->Flags (m_loc);
  }
    unsigned
  DataType (void) const
  {
    return m_loc[0]->DataType (m_loc);
  }
    ILxUnknownID
  VectorType (void) const
  {
    return (ILxUnknownID) m_loc[0]->VectorType (m_loc);
  }
    void
  SetSize (int width, int height, int writeBucketsToDisk, int isStereo)
  {
    m_loc[0]->SetSize (m_loc,width,height,writeBucketsToDisk,isStereo);
  }
    void
  GetSize (int *width, int *height) const
  {
    m_loc[0]->GetSize (m_loc,width,height);
  }
    LxResult
  SetEyeSide (int eyeSide)
  {
    return m_loc[0]->SetEyeSide (m_loc,eyeSide);
  }
    void
  Clear (int x, int y)
  {
    m_loc[0]->Clear (m_loc,x,y);
  }
    LxResult
  Convert (LXtGenVectorID gv, int x, int y, float blend)
  {
    return m_loc[0]->Convert (m_loc,gv,x,y,blend);
  }
    void *
  Pixel (int x, int y) const
  {
    return m_loc[0]->Pixel (m_loc,x,y);
  }
    void *
  Line (int y) const
  {
    return m_loc[0]->Line (m_loc,y);
  }
    LxResult
  Name (const char **name) const
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  SetUserName (const char *name)
  {
    return m_loc[0]->SetUserName (m_loc,name);
  }
    LxResult
  UserName (const char **name) const
  {
    return m_loc[0]->UserName (m_loc,name);
  }
    LxResult
  CreateImageTileTree (void)
  {
    return m_loc[0]->CreateImageTileTree (m_loc);
  }
    LxResult
  DestroyImageTileTree (void)
  {
    return m_loc[0]->DestroyImageTileTree (m_loc);
  }
    LXtTileTreeID
  GetImageTileTree (void) const
  {
    return m_loc[0]->GetImageTileTree (m_loc);
  }
    size_t
  GetImageTileTreeSize (void) const
  {
    return m_loc[0]->GetImageTileTreeSize (m_loc);
  }
    LxResult
  ResetImageTileTree (void)
  {
    return m_loc[0]->ResetImageTileTree (m_loc);
  }
    LxResult
  IncrementTileTreeSize (void)
  {
    return m_loc[0]->IncrementTileTreeSize (m_loc);
  }
    LxResult
  DecrementTileTreeSize (void)
  {
    return m_loc[0]->DecrementTileTreeSize (m_loc);
  }
};

class CLxImpl_RenderJob {
  public:
    virtual ~CLxImpl_RenderJob() {}
    virtual LxResult
      rjob_RenderItem (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ActionName (const char **action)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_GroupName (const char **group)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_RenderAs (int *mode)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_RenderAtTime (double *time)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_RenderTurntableNumFrames (int *numFrames)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_RenderTurntableFPS (int *fps)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_RenderBakeVMap (const char **vmap)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_RenderBakeLookDistance (double *distance)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_RenderBakeItem (int *include, void **item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_RenderBakeEffect (const char **effect)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_RenderBakeImage (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_TestItem (ILxUnknownID item, ILxUnknownID eval)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_FrameBufferSlot (int *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_FrameBufferRegionBackgroundSlot (int *slotIndex, int *passIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_OutputFormat (const char **format)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_OutputFilename (const char **filename)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_Options (int *options)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressAborted (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressBegin (ILxUnknownID renderStats)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressEnd (ILxUnknownID finalFrameBuffer, ILxUnknownID finalStats)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressPercentDone (double progressScene, double progressFrame, double progressRenderPass)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressImageMetrics (int resX, int resH, int *w, int *h, double *zoom, int *panX, int *panY, int *output)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressFrameBegin (int frame, int w, int h)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressFrameEnd (int frame, ILxUnknownID stats)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressRenderPassBegin (int frameIndex, int renderPassIndex, const char *renderPassName, int eye)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressRenderPassEnd (int frame, int renderPassIndex, const char *renderPassName, int eye, ILxUnknownID frameBuffer, ILxUnknownID stats)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressFramePassBegin (int frame, int renderPass, int eye, int pass)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressFramePassEnd (int frame, int renderPass, int eye, int pass)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressBucketBegin (int row, int col)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressBucketEnd (int row, int col, LxResult code)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressString (const char *infoString, const char *userString)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressImage (ILxUnknownID img)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressImageUpdated (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rjob_ProgressTickle (void)
        { return LXe_NOTIMPL; }
};
#define LXxD_RenderJob_RenderItem LxResult rjob_RenderItem (void **ppvObj)
#define LXxO_RenderJob_RenderItem LXxD_RenderJob_RenderItem LXx_OVERRIDE
#define LXxD_RenderJob_ActionName LxResult rjob_ActionName (const char **action)
#define LXxO_RenderJob_ActionName LXxD_RenderJob_ActionName LXx_OVERRIDE
#define LXxD_RenderJob_GroupName LxResult rjob_GroupName (const char **group)
#define LXxO_RenderJob_GroupName LXxD_RenderJob_GroupName LXx_OVERRIDE
#define LXxD_RenderJob_RenderAs LxResult rjob_RenderAs (int *mode)
#define LXxO_RenderJob_RenderAs LXxD_RenderJob_RenderAs LXx_OVERRIDE
#define LXxD_RenderJob_RenderAtTime LxResult rjob_RenderAtTime (double *time)
#define LXxO_RenderJob_RenderAtTime LXxD_RenderJob_RenderAtTime LXx_OVERRIDE
#define LXxD_RenderJob_RenderTurntableNumFrames LxResult rjob_RenderTurntableNumFrames (int *numFrames)
#define LXxO_RenderJob_RenderTurntableNumFrames LXxD_RenderJob_RenderTurntableNumFrames LXx_OVERRIDE
#define LXxD_RenderJob_RenderTurntableFPS LxResult rjob_RenderTurntableFPS (int *fps)
#define LXxO_RenderJob_RenderTurntableFPS LXxD_RenderJob_RenderTurntableFPS LXx_OVERRIDE
#define LXxD_RenderJob_RenderBakeVMap LxResult rjob_RenderBakeVMap (const char **vmap)
#define LXxO_RenderJob_RenderBakeVMap LXxD_RenderJob_RenderBakeVMap LXx_OVERRIDE
#define LXxD_RenderJob_RenderBakeLookDistance LxResult rjob_RenderBakeLookDistance (double *distance)
#define LXxO_RenderJob_RenderBakeLookDistance LXxD_RenderJob_RenderBakeLookDistance LXx_OVERRIDE
#define LXxD_RenderJob_RenderBakeItem LxResult rjob_RenderBakeItem (int *include, void **item)
#define LXxO_RenderJob_RenderBakeItem LXxD_RenderJob_RenderBakeItem LXx_OVERRIDE
#define LXxD_RenderJob_RenderBakeEffect LxResult rjob_RenderBakeEffect (const char **effect)
#define LXxO_RenderJob_RenderBakeEffect LXxD_RenderJob_RenderBakeEffect LXx_OVERRIDE
#define LXxD_RenderJob_RenderBakeImage LxResult rjob_RenderBakeImage (void **ppvObj)
#define LXxO_RenderJob_RenderBakeImage LXxD_RenderJob_RenderBakeImage LXx_OVERRIDE
#define LXxD_RenderJob_TestItem LxResult rjob_TestItem (ILxUnknownID item, ILxUnknownID eval)
#define LXxO_RenderJob_TestItem LXxD_RenderJob_TestItem LXx_OVERRIDE
#define LXxD_RenderJob_FrameBufferSlot LxResult rjob_FrameBufferSlot (int *index)
#define LXxO_RenderJob_FrameBufferSlot LXxD_RenderJob_FrameBufferSlot LXx_OVERRIDE
#define LXxD_RenderJob_FrameBufferRegionBackgroundSlot LxResult rjob_FrameBufferRegionBackgroundSlot (int *slotIndex, int *passIndex)
#define LXxO_RenderJob_FrameBufferRegionBackgroundSlot LXxD_RenderJob_FrameBufferRegionBackgroundSlot LXx_OVERRIDE
#define LXxD_RenderJob_OutputFormat LxResult rjob_OutputFormat (const char **format)
#define LXxO_RenderJob_OutputFormat LXxD_RenderJob_OutputFormat LXx_OVERRIDE
#define LXxD_RenderJob_OutputFilename LxResult rjob_OutputFilename (const char **filename)
#define LXxO_RenderJob_OutputFilename LXxD_RenderJob_OutputFilename LXx_OVERRIDE
#define LXxD_RenderJob_Options LxResult rjob_Options (int *options)
#define LXxO_RenderJob_Options LXxD_RenderJob_Options LXx_OVERRIDE
#define LXxD_RenderJob_ProgressAborted LxResult rjob_ProgressAborted (void)
#define LXxO_RenderJob_ProgressAborted LXxD_RenderJob_ProgressAborted LXx_OVERRIDE
#define LXxD_RenderJob_ProgressBegin LxResult rjob_ProgressBegin (ILxUnknownID renderStats)
#define LXxO_RenderJob_ProgressBegin LXxD_RenderJob_ProgressBegin LXx_OVERRIDE
#define LXxD_RenderJob_ProgressEnd LxResult rjob_ProgressEnd (ILxUnknownID finalFrameBuffer, ILxUnknownID finalStats)
#define LXxO_RenderJob_ProgressEnd LXxD_RenderJob_ProgressEnd LXx_OVERRIDE
#define LXxD_RenderJob_ProgressPercentDone LxResult rjob_ProgressPercentDone (double progressScene, double progressFrame, double progressRenderPass)
#define LXxO_RenderJob_ProgressPercentDone LXxD_RenderJob_ProgressPercentDone LXx_OVERRIDE
#define LXxD_RenderJob_ProgressImageMetrics LxResult rjob_ProgressImageMetrics (int resX, int resH, int *w, int *h, double *zoom, int *panX, int *panY, int *output)
#define LXxO_RenderJob_ProgressImageMetrics LXxD_RenderJob_ProgressImageMetrics LXx_OVERRIDE
#define LXxD_RenderJob_ProgressFrameBegin LxResult rjob_ProgressFrameBegin (int frame, int w, int h)
#define LXxO_RenderJob_ProgressFrameBegin LXxD_RenderJob_ProgressFrameBegin LXx_OVERRIDE
#define LXxD_RenderJob_ProgressFrameEnd LxResult rjob_ProgressFrameEnd (int frame, ILxUnknownID stats)
#define LXxO_RenderJob_ProgressFrameEnd LXxD_RenderJob_ProgressFrameEnd LXx_OVERRIDE
#define LXxD_RenderJob_ProgressRenderPassBegin LxResult rjob_ProgressRenderPassBegin (int frameIndex, int renderPassIndex, const char *renderPassName, int eye)
#define LXxO_RenderJob_ProgressRenderPassBegin LXxD_RenderJob_ProgressRenderPassBegin LXx_OVERRIDE
#define LXxD_RenderJob_ProgressRenderPassEnd LxResult rjob_ProgressRenderPassEnd (int frame, int renderPassIndex, const char *renderPassName, int eye, ILxUnknownID frameBuffer, ILxUnknownID stats)
#define LXxO_RenderJob_ProgressRenderPassEnd LXxD_RenderJob_ProgressRenderPassEnd LXx_OVERRIDE
#define LXxD_RenderJob_ProgressFramePassBegin LxResult rjob_ProgressFramePassBegin (int frame, int renderPass, int eye, int pass)
#define LXxO_RenderJob_ProgressFramePassBegin LXxD_RenderJob_ProgressFramePassBegin LXx_OVERRIDE
#define LXxD_RenderJob_ProgressFramePassEnd LxResult rjob_ProgressFramePassEnd (int frame, int renderPass, int eye, int pass)
#define LXxO_RenderJob_ProgressFramePassEnd LXxD_RenderJob_ProgressFramePassEnd LXx_OVERRIDE
#define LXxD_RenderJob_ProgressBucketBegin LxResult rjob_ProgressBucketBegin (int row, int col)
#define LXxO_RenderJob_ProgressBucketBegin LXxD_RenderJob_ProgressBucketBegin LXx_OVERRIDE
#define LXxD_RenderJob_ProgressBucketEnd LxResult rjob_ProgressBucketEnd (int row, int col, LxResult code)
#define LXxO_RenderJob_ProgressBucketEnd LXxD_RenderJob_ProgressBucketEnd LXx_OVERRIDE
#define LXxD_RenderJob_ProgressString LxResult rjob_ProgressString (const char *infoString, const char *userString)
#define LXxO_RenderJob_ProgressString LXxD_RenderJob_ProgressString LXx_OVERRIDE
#define LXxD_RenderJob_ProgressImage LxResult rjob_ProgressImage (ILxUnknownID img)
#define LXxO_RenderJob_ProgressImage LXxD_RenderJob_ProgressImage LXx_OVERRIDE
#define LXxD_RenderJob_ProgressImageUpdated LxResult rjob_ProgressImageUpdated (void)
#define LXxO_RenderJob_ProgressImageUpdated LXxD_RenderJob_ProgressImageUpdated LXx_OVERRIDE
#define LXxD_RenderJob_ProgressTickle LxResult rjob_ProgressTickle (void)
#define LXxO_RenderJob_ProgressTickle LXxD_RenderJob_ProgressTickle LXx_OVERRIDE
template <class T>
class CLxIfc_RenderJob : public CLxInterface
{
    static LxResult
  RenderItem (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_RenderItem (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ActionName (LXtObjectID wcom, const char **action)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ActionName (action);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GroupName (LXtObjectID wcom, const char **group)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_GroupName (group);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RenderAs (LXtObjectID wcom, int *mode)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_RenderAs (mode);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RenderAtTime (LXtObjectID wcom, double *time)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_RenderAtTime (time);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RenderTurntableNumFrames (LXtObjectID wcom, int *numFrames)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_RenderTurntableNumFrames (numFrames);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RenderTurntableFPS (LXtObjectID wcom, int *fps)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_RenderTurntableFPS (fps);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RenderBakeVMap (LXtObjectID wcom, const char **vmap)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_RenderBakeVMap (vmap);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RenderBakeLookDistance (LXtObjectID wcom, double *distance)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_RenderBakeLookDistance (distance);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RenderBakeItem (LXtObjectID wcom, int *include, void **item)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_RenderBakeItem (include,item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RenderBakeEffect (LXtObjectID wcom, const char **effect)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_RenderBakeEffect (effect);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RenderBakeImage (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_RenderBakeImage (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TestItem (LXtObjectID wcom, LXtObjectID item, LXtObjectID eval)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_TestItem ((ILxUnknownID)item,(ILxUnknownID)eval);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FrameBufferSlot (LXtObjectID wcom, int *index)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_FrameBufferSlot (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FrameBufferRegionBackgroundSlot (LXtObjectID wcom, int *slotIndex, int *passIndex)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_FrameBufferRegionBackgroundSlot (slotIndex,passIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  OutputFormat (LXtObjectID wcom, const char **format)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_OutputFormat (format);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  OutputFilename (LXtObjectID wcom, const char **filename)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_OutputFilename (filename);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Options (LXtObjectID wcom, int *options)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_Options (options);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressAborted (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressAborted ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressBegin (LXtObjectID wcom, LXtObjectID renderStats)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressBegin ((ILxUnknownID)renderStats);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressEnd (LXtObjectID wcom, LXtObjectID finalFrameBuffer, LXtObjectID finalStats)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressEnd ((ILxUnknownID)finalFrameBuffer,(ILxUnknownID)finalStats);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressPercentDone (LXtObjectID wcom, double progressScene, double progressFrame, double progressRenderPass)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressPercentDone (progressScene,progressFrame,progressRenderPass);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressImageMetrics (LXtObjectID wcom, int resX, int resH, int *w, int *h, double *zoom, int *panX, int *panY, int *output)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressImageMetrics (resX,resH,w,h,zoom,panX,panY,output);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressFrameBegin (LXtObjectID wcom, int frame, int w, int h)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressFrameBegin (frame,w,h);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressFrameEnd (LXtObjectID wcom, int frame, LXtObjectID stats)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressFrameEnd (frame,(ILxUnknownID)stats);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressRenderPassBegin (LXtObjectID wcom, int frameIndex, int renderPassIndex, const char *renderPassName, int eye)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressRenderPassBegin (frameIndex,renderPassIndex,renderPassName,eye);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressRenderPassEnd (LXtObjectID wcom, int frame, int renderPassIndex, const char *renderPassName, int eye, LXtObjectID frameBuffer, LXtObjectID stats)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressRenderPassEnd (frame,renderPassIndex,renderPassName,eye,(ILxUnknownID)frameBuffer,(ILxUnknownID)stats);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressFramePassBegin (LXtObjectID wcom, int frame, int renderPass, int eye, int pass)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressFramePassBegin (frame,renderPass,eye,pass);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressFramePassEnd (LXtObjectID wcom, int frame, int renderPass, int eye, int pass)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressFramePassEnd (frame,renderPass,eye,pass);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressBucketBegin (LXtObjectID wcom, int row, int col)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressBucketBegin (row,col);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressBucketEnd (LXtObjectID wcom, int row, int col, LxResult code)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressBucketEnd (row,col,code);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressString (LXtObjectID wcom, const char *infoString, const char *userString)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressString (infoString,userString);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressImage (LXtObjectID wcom, LXtObjectID img)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressImage ((ILxUnknownID)img);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressImageUpdated (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressImageUpdated ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ProgressTickle (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_RenderJob, loc);
    try {
      return loc->rjob_ProgressTickle ();
    } catch (LxResult rc) { return rc; }
  }
  ILxRenderJob vt;
public:
  CLxIfc_RenderJob ()
  {
    vt.RenderItem = RenderItem;
    vt.ActionName = ActionName;
    vt.GroupName = GroupName;
    vt.RenderAs = RenderAs;
    vt.RenderAtTime = RenderAtTime;
    vt.RenderTurntableNumFrames = RenderTurntableNumFrames;
    vt.RenderTurntableFPS = RenderTurntableFPS;
    vt.RenderBakeVMap = RenderBakeVMap;
    vt.RenderBakeLookDistance = RenderBakeLookDistance;
    vt.RenderBakeItem = RenderBakeItem;
    vt.RenderBakeEffect = RenderBakeEffect;
    vt.RenderBakeImage = RenderBakeImage;
    vt.TestItem = TestItem;
    vt.FrameBufferSlot = FrameBufferSlot;
    vt.FrameBufferRegionBackgroundSlot = FrameBufferRegionBackgroundSlot;
    vt.OutputFormat = OutputFormat;
    vt.OutputFilename = OutputFilename;
    vt.Options = Options;
    vt.ProgressAborted = ProgressAborted;
    vt.ProgressBegin = ProgressBegin;
    vt.ProgressEnd = ProgressEnd;
    vt.ProgressPercentDone = ProgressPercentDone;
    vt.ProgressImageMetrics = ProgressImageMetrics;
    vt.ProgressFrameBegin = ProgressFrameBegin;
    vt.ProgressFrameEnd = ProgressFrameEnd;
    vt.ProgressRenderPassBegin = ProgressRenderPassBegin;
    vt.ProgressRenderPassEnd = ProgressRenderPassEnd;
    vt.ProgressFramePassBegin = ProgressFramePassBegin;
    vt.ProgressFramePassEnd = ProgressFramePassEnd;
    vt.ProgressBucketBegin = ProgressBucketBegin;
    vt.ProgressBucketEnd = ProgressBucketEnd;
    vt.ProgressString = ProgressString;
    vt.ProgressImage = ProgressImage;
    vt.ProgressImageUpdated = ProgressImageUpdated;
    vt.ProgressTickle = ProgressTickle;
    vTable = &vt.iunk;
    iid = &lx::guid_RenderJob;
  }
};
class CLxLoc_RenderJob : public CLxLocalize<ILxRenderJobID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_RenderJob() {_init();}
  CLxLoc_RenderJob(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_RenderJob(const CLxLoc_RenderJob &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_RenderJob;}
    LxResult
  RenderItem (void **ppvObj) const
  {
    return m_loc[0]->RenderItem (m_loc,ppvObj);
  }
    bool
  RenderItem (CLxLocalizedObject &dest) const
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->RenderItem (m_loc,&obj)) && dest.take(obj);
  }
    LxResult
  ActionName (const char **action) const
  {
    return m_loc[0]->ActionName (m_loc,action);
  }
    LxResult
  GroupName (const char **group) const
  {
    return m_loc[0]->GroupName (m_loc,group);
  }
    LxResult
  RenderAs (int *mode) const
  {
    return m_loc[0]->RenderAs (m_loc,mode);
  }
    LxResult
  RenderAtTime (double *time) const
  {
    return m_loc[0]->RenderAtTime (m_loc,time);
  }
    LxResult
  RenderTurntableNumFrames (int *numFrames) const
  {
    return m_loc[0]->RenderTurntableNumFrames (m_loc,numFrames);
  }
    LxResult
  RenderTurntableFPS (int *fps) const
  {
    return m_loc[0]->RenderTurntableFPS (m_loc,fps);
  }
    LxResult
  RenderBakeVMap (const char **vmap) const
  {
    return m_loc[0]->RenderBakeVMap (m_loc,vmap);
  }
    LxResult
  RenderBakeLookDistance (double *distance) const
  {
    return m_loc[0]->RenderBakeLookDistance (m_loc,distance);
  }
    LxResult
  RenderBakeItem (int *include, void **item) const
  {
    return m_loc[0]->RenderBakeItem (m_loc,include,item);
  }
    LxResult
  RenderBakeEffect (const char **effect) const
  {
    return m_loc[0]->RenderBakeEffect (m_loc,effect);
  }
    LxResult
  RenderBakeImage (void **ppvObj) const
  {
    return m_loc[0]->RenderBakeImage (m_loc,ppvObj);
  }
    bool
  RenderBakeImage (CLxLocalizedObject &dest) const
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->RenderBakeImage (m_loc,&obj)) && dest.take(obj);
  }
    LxResult
  TestItem (ILxUnknownID item, ILxUnknownID eval)
  {
    return m_loc[0]->TestItem (m_loc,(ILxUnknownID)item,(ILxUnknownID)eval);
  }
    LxResult
  FrameBufferSlot (int *index) const
  {
    return m_loc[0]->FrameBufferSlot (m_loc,index);
  }
    LxResult
  FrameBufferRegionBackgroundSlot (int *slotIndex, int *passIndex) const
  {
    return m_loc[0]->FrameBufferRegionBackgroundSlot (m_loc,slotIndex,passIndex);
  }
    LxResult
  OutputFormat (const char **format) const
  {
    return m_loc[0]->OutputFormat (m_loc,format);
  }
    LxResult
  OutputFilename (const char **filename) const
  {
    return m_loc[0]->OutputFilename (m_loc,filename);
  }
    LxResult
  Options (int *options) const
  {
    return m_loc[0]->Options (m_loc,options);
  }
    LxResult
  ProgressAborted (void)
  {
    return m_loc[0]->ProgressAborted (m_loc);
  }
    LxResult
  ProgressBegin (ILxUnknownID renderStats)
  {
    return m_loc[0]->ProgressBegin (m_loc,(ILxUnknownID)renderStats);
  }
    LxResult
  ProgressEnd (ILxUnknownID finalFrameBuffer, ILxUnknownID finalStats)
  {
    return m_loc[0]->ProgressEnd (m_loc,(ILxUnknownID)finalFrameBuffer,(ILxUnknownID)finalStats);
  }
    LxResult
  ProgressPercentDone (double progressScene, double progressFrame, double progressRenderPass)
  {
    return m_loc[0]->ProgressPercentDone (m_loc,progressScene,progressFrame,progressRenderPass);
  }
    LxResult
  ProgressImageMetrics (int resX, int resH, int *w, int *h, double *zoom, int *panX, int *panY, int *output)
  {
    return m_loc[0]->ProgressImageMetrics (m_loc,resX,resH,w,h,zoom,panX,panY,output);
  }
    LxResult
  ProgressFrameBegin (int frame, int w, int h)
  {
    return m_loc[0]->ProgressFrameBegin (m_loc,frame,w,h);
  }
    LxResult
  ProgressFrameEnd (int frame, ILxUnknownID stats)
  {
    return m_loc[0]->ProgressFrameEnd (m_loc,frame,(ILxUnknownID)stats);
  }
    LxResult
  ProgressRenderPassBegin (int frameIndex, int renderPassIndex, const char *renderPassName, int eye)
  {
    return m_loc[0]->ProgressRenderPassBegin (m_loc,frameIndex,renderPassIndex,renderPassName,eye);
  }
    LxResult
  ProgressRenderPassEnd (int frame, int renderPassIndex, const char *renderPassName, int eye, ILxUnknownID frameBuffer, ILxUnknownID stats)
  {
    return m_loc[0]->ProgressRenderPassEnd (m_loc,frame,renderPassIndex,renderPassName,eye,(ILxUnknownID)frameBuffer,(ILxUnknownID)stats);
  }
    LxResult
  ProgressFramePassBegin (int frame, int renderPass, int eye, int pass)
  {
    return m_loc[0]->ProgressFramePassBegin (m_loc,frame,renderPass,eye,pass);
  }
    LxResult
  ProgressFramePassEnd (int frame, int renderPass, int eye, int pass)
  {
    return m_loc[0]->ProgressFramePassEnd (m_loc,frame,renderPass,eye,pass);
  }
    LxResult
  ProgressBucketBegin (int row, int col)
  {
    return m_loc[0]->ProgressBucketBegin (m_loc,row,col);
  }
    LxResult
  ProgressBucketEnd (int row, int col, LxResult code)
  {
    return m_loc[0]->ProgressBucketEnd (m_loc,row,col,code);
  }
    LxResult
  ProgressString (const char *infoString, const char *userString)
  {
    return m_loc[0]->ProgressString (m_loc,infoString,userString);
  }
    LxResult
  ProgressImage (ILxUnknownID img)
  {
    return m_loc[0]->ProgressImage (m_loc,(ILxUnknownID)img);
  }
    LxResult
  ProgressImageUpdated (void)
  {
    return m_loc[0]->ProgressImageUpdated (m_loc);
  }
    LxResult
  ProgressTickle (void)
  {
    return m_loc[0]->ProgressTickle (m_loc);
  }
};

class CLxLoc_ImageProcessing : public CLxLocalize<ILxImageProcessingID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ImageProcessing() {_init();}
  CLxLoc_ImageProcessing(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ImageProcessing(const CLxLoc_ImageProcessing &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ImageProcessing;}
    LxResult
  GetAsReadOnly (void **ppvObj)
  {
    return m_loc[0]->GetAsReadOnly (m_loc,ppvObj);
  }
    bool
  GetAsReadOnly (CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->GetAsReadOnly (m_loc,&obj)) && dest.take(obj);
  }
    LxResult
  SetIdentifier (const char *string)
  {
    return m_loc[0]->SetIdentifier (m_loc,string);
  }
    LxResult
  GetIdentifier (const char **string) const
  {
    return m_loc[0]->GetIdentifier (m_loc,string);
  }
    LxResult
  Reset (void)
  {
    return m_loc[0]->Reset (m_loc);
  }
    LxResult
  CopyToRenderProcess (LXtRenderOutputProcess *rop)
  {
    return m_loc[0]->CopyToRenderProcess (m_loc,rop);
  }
    LxResult
  CopyFromRenderProcess (const LXtRenderOutputProcess *rop)
  {
    return m_loc[0]->CopyFromRenderProcess (m_loc,rop);
  }
    LxResult
  CopySettingsFromFrameBuffer (ILxUnknownID frameBuffer, int bufferIndex)
  {
    return m_loc[0]->CopySettingsFromFrameBuffer (m_loc,(ILxUnknownID)frameBuffer,bufferIndex);
  }
    LxResult
  CopySettingsToFrameBuffer (ILxUnknownID frameBuffer, int bufferIndex)
  {
    return m_loc[0]->CopySettingsToFrameBuffer (m_loc,(ILxUnknownID)frameBuffer,bufferIndex);
  }
    LxResult
  ApplyToImageFromFrameBuffer (ILxUnknownID frameBuffer, int bufferIndex, ILxUnknownID image, float xOffset, float yOffset, float zoom)
  {
    return m_loc[0]->ApplyToImageFromFrameBuffer (m_loc,(ILxUnknownID)frameBuffer,bufferIndex,(ILxUnknownID)image,xOffset,yOffset,zoom);
  }
    LxResult
  ApplyToImageFromFrameBufferOverride (ILxUnknownID frameBuffer, int bufferIndex, ILxUnknownID image, float xOffset, float yOffset, float zoom, LXtImageProcessingOperators opOverride)
  {
    return m_loc[0]->ApplyToImageFromFrameBufferOverride (m_loc,(ILxUnknownID)frameBuffer,bufferIndex,(ILxUnknownID)image,xOffset,yOffset,zoom,opOverride);
  }
    LxResult
  ApplyToFrameBuffer (ILxUnknownID frameBuffer, int bufferIndex)
  {
    return m_loc[0]->ApplyToFrameBuffer (m_loc,(ILxUnknownID)frameBuffer,bufferIndex);
  }
    LxResult
  ApplyToFrameBufferOverride (ILxUnknownID frameBuffer, int bufferIndex, LXtImageProcessingOperators opOverride)
  {
    return m_loc[0]->ApplyToFrameBufferOverride (m_loc,(ILxUnknownID)frameBuffer,bufferIndex,opOverride);
  }
    LxResult
  ApplyToImage (ILxUnknownID srcImage, ILxUnknownID dstImage)
  {
    return m_loc[0]->ApplyToImage (m_loc,(ILxUnknownID)srcImage,(ILxUnknownID)dstImage);
  }
    LxResult
  ApplyToImageOverride (ILxUnknownID srcImage, ILxUnknownID dstImage, LXtImageProcessingOperators opOverride)
  {
    return m_loc[0]->ApplyToImageOverride (m_loc,(ILxUnknownID)srcImage,(ILxUnknownID)dstImage,opOverride);
  }
    LxResult
  GetImageProcessingOperators (LXtImageProcessingOperators *ops)
  {
    return m_loc[0]->GetImageProcessingOperators (m_loc,ops);
  }
    LxResult
  SetImageProcessingOperators (LXtImageProcessingOperators ops)
  {
    return m_loc[0]->SetImageProcessingOperators (m_loc,ops);
  }
    LxResult
  AreaProcessingActive (int *active)
  {
    return m_loc[0]->AreaProcessingActive (m_loc,active);
  }
    LxResult
  GetSourceImageGamma (double *gamma)
  {
    return m_loc[0]->GetSourceImageGamma (m_loc,gamma);
  }
    LxResult
  SetSourceImageGamma (double gamma)
  {
    return m_loc[0]->SetSourceImageGamma (m_loc,gamma);
  }
    LxResult
  GetSourceImageIsStereoSideBySide (int *isStereo)
  {
    return m_loc[0]->GetSourceImageIsStereoSideBySide (m_loc,isStereo);
  }
    LxResult
  SetSourceImageIsStereoSideBySide (int isStereo)
  {
    return m_loc[0]->SetSourceImageIsStereoSideBySide (m_loc,isStereo);
  }
    LxResult
  GetSaveProcessed (int *enabled)
  {
    return m_loc[0]->GetSaveProcessed (m_loc,enabled);
  }
    LxResult
  SetSaveProcessed (int enabled)
  {
    return m_loc[0]->SetSaveProcessed (m_loc,enabled);
  }
    LxResult
  GetStereoEye (LXtStereoEye *eye)
  {
    return m_loc[0]->GetStereoEye (m_loc,eye);
  }
    LxResult
  SetStereoEye (LXtStereoEye eye)
  {
    return m_loc[0]->SetStereoEye (m_loc,eye);
  }
    LxResult
  GetStereoComposite (LXtStereoComposite *mode)
  {
    return m_loc[0]->GetStereoComposite (m_loc,mode);
  }
    LxResult
  SetStereoComposite (LXtStereoComposite mode)
  {
    return m_loc[0]->SetStereoComposite (m_loc,mode);
  }
    LxResult
  GetBloomEnabled (int *enabled) const
  {
    return m_loc[0]->GetBloomEnabled (m_loc,enabled);
  }
    LxResult
  SetBloomEnabled (int enabled)
  {
    return m_loc[0]->SetBloomEnabled (m_loc,enabled);
  }
    LxResult
  GetBloomThreshold (double *threshold)
  {
    return m_loc[0]->GetBloomThreshold (m_loc,threshold);
  }
    LxResult
  SetBloomThreshold (double threshold)
  {
    return m_loc[0]->SetBloomThreshold (m_loc,threshold);
  }
    LxResult
  GetBloomRadius (double *radius)
  {
    return m_loc[0]->GetBloomRadius (m_loc,radius);
  }
    LxResult
  SetBloomRadius (double radius)
  {
    return m_loc[0]->SetBloomRadius (m_loc,radius);
  }
    LxResult
  GetVignetteAmount (double *amount)
  {
    return m_loc[0]->GetVignetteAmount (m_loc,amount);
  }
    LxResult
  SetVignetteAmount (double amount)
  {
    return m_loc[0]->SetVignetteAmount (m_loc,amount);
  }
    LxResult
  GetLevelOffset (double *offset)
  {
    return m_loc[0]->GetLevelOffset (m_loc,offset);
  }
    LxResult
  SetLevelOffset (double offset)
  {
    return m_loc[0]->SetLevelOffset (m_loc,offset);
  }
    LxResult
  GetRedLevelOffset (double *offset)
  {
    return m_loc[0]->GetRedLevelOffset (m_loc,offset);
  }
    LxResult
  SetRedLevelOffset (double offset)
  {
    return m_loc[0]->SetRedLevelOffset (m_loc,offset);
  }
    LxResult
  GetGreenLevelOffset (double *offset)
  {
    return m_loc[0]->GetGreenLevelOffset (m_loc,offset);
  }
    LxResult
  SetGreenLevelOffset (double offset)
  {
    return m_loc[0]->SetGreenLevelOffset (m_loc,offset);
  }
    LxResult
  GetBlueLevelOffset (double *offset)
  {
    return m_loc[0]->GetBlueLevelOffset (m_loc,offset);
  }
    LxResult
  SetBlueLevelOffset (double offset)
  {
    return m_loc[0]->SetBlueLevelOffset (m_loc,offset);
  }
    LxResult
  GetInputBlackLevel (double *inputBlackLevel)
  {
    return m_loc[0]->GetInputBlackLevel (m_loc,inputBlackLevel);
  }
    LxResult
  SetInputBlackLevel (double blackLevel)
  {
    return m_loc[0]->SetInputBlackLevel (m_loc,blackLevel);
  }
    LxResult
  GetInputGrayLevel (double *gamma)
  {
    return m_loc[0]->GetInputGrayLevel (m_loc,gamma);
  }
    LxResult
  GetInvInputGrayLevel (double *invGamma)
  {
    return m_loc[0]->GetInvInputGrayLevel (m_loc,invGamma);
  }
    LxResult
  SetInputGrayLevel (double gamma)
  {
    return m_loc[0]->SetInputGrayLevel (m_loc,gamma);
  }
    LxResult
  GetInputWhiteLevel (double *inputWhiteLevel)
  {
    return m_loc[0]->GetInputWhiteLevel (m_loc,inputWhiteLevel);
  }
    LxResult
  SetInputWhiteLevel (double whiteLevel)
  {
    return m_loc[0]->SetInputWhiteLevel (m_loc,whiteLevel);
  }
    LxResult
  GetInputMinRedLevel (double *inputLevel)
  {
    return m_loc[0]->GetInputMinRedLevel (m_loc,inputLevel);
  }
    LxResult
  SetInputMinRedLevel (double level)
  {
    return m_loc[0]->SetInputMinRedLevel (m_loc,level);
  }
    LxResult
  GetInputRedGrayLevel (double *gamma)
  {
    return m_loc[0]->GetInputRedGrayLevel (m_loc,gamma);
  }
    LxResult
  GetInvInputRedGrayLevel (double *invGamma)
  {
    return m_loc[0]->GetInvInputRedGrayLevel (m_loc,invGamma);
  }
    LxResult
  SetInputRedGrayLevel (double gamma)
  {
    return m_loc[0]->SetInputRedGrayLevel (m_loc,gamma);
  }
    LxResult
  GetInputMaxRedLevel (double *inputLevel)
  {
    return m_loc[0]->GetInputMaxRedLevel (m_loc,inputLevel);
  }
    LxResult
  SetInputMaxRedLevel (double level)
  {
    return m_loc[0]->SetInputMaxRedLevel (m_loc,level);
  }
    LxResult
  GetInputMinGreenLevel (double *inputLevel)
  {
    return m_loc[0]->GetInputMinGreenLevel (m_loc,inputLevel);
  }
    LxResult
  SetInputMinGreenLevel (double level)
  {
    return m_loc[0]->SetInputMinGreenLevel (m_loc,level);
  }
    LxResult
  GetInputGreenGrayLevel (double *gamma)
  {
    return m_loc[0]->GetInputGreenGrayLevel (m_loc,gamma);
  }
    LxResult
  GetInvInputGreenGrayLevel (double *invGamma)
  {
    return m_loc[0]->GetInvInputGreenGrayLevel (m_loc,invGamma);
  }
    LxResult
  SetInputGreenGrayLevel (double gamma)
  {
    return m_loc[0]->SetInputGreenGrayLevel (m_loc,gamma);
  }
    LxResult
  GetInputMaxGreenLevel (double *inputLevel)
  {
    return m_loc[0]->GetInputMaxGreenLevel (m_loc,inputLevel);
  }
    LxResult
  SetInputMaxGreenLevel (double level)
  {
    return m_loc[0]->SetInputMaxGreenLevel (m_loc,level);
  }
    LxResult
  GetInputMinBlueLevel (double *inputLevel)
  {
    return m_loc[0]->GetInputMinBlueLevel (m_loc,inputLevel);
  }
    LxResult
  SetInputMinBlueLevel (double level)
  {
    return m_loc[0]->SetInputMinBlueLevel (m_loc,level);
  }
    LxResult
  GetInputBlueGrayLevel (double *gamma)
  {
    return m_loc[0]->GetInputBlueGrayLevel (m_loc,gamma);
  }
    LxResult
  GetInvInputBlueGrayLevel (double *invGamma)
  {
    return m_loc[0]->GetInvInputBlueGrayLevel (m_loc,invGamma);
  }
    LxResult
  SetInputBlueGrayLevel (double gamma)
  {
    return m_loc[0]->SetInputBlueGrayLevel (m_loc,gamma);
  }
    LxResult
  GetInputMaxBlueLevel (double *inputLevel)
  {
    return m_loc[0]->GetInputMaxBlueLevel (m_loc,inputLevel);
  }
    LxResult
  SetInputMaxBlueLevel (double level)
  {
    return m_loc[0]->SetInputMaxBlueLevel (m_loc,level);
  }
    LxResult
  GetToneMapping (double *toneMapping)
  {
    return m_loc[0]->GetToneMapping (m_loc,toneMapping);
  }
    LxResult
  SetToneMapping (double toneMapping)
  {
    return m_loc[0]->SetToneMapping (m_loc,toneMapping);
  }
    LxResult
  GetHueOffset (double *hueOffset)
  {
    return m_loc[0]->GetHueOffset (m_loc,hueOffset);
  }
    LxResult
  SetHueOffset (double hueOffset)
  {
    return m_loc[0]->SetHueOffset (m_loc,hueOffset);
  }
    LxResult
  GetSaturation (double *saturation)
  {
    return m_loc[0]->GetSaturation (m_loc,saturation);
  }
    LxResult
  SetSaturation (double saturation)
  {
    return m_loc[0]->SetSaturation (m_loc,saturation);
  }
    LxResult
  GetColorization (double *colorization)
  {
    return m_loc[0]->GetColorization (m_loc,colorization);
  }
    LxResult
  SetColorization (double colorization)
  {
    return m_loc[0]->SetColorization (m_loc,colorization);
  }
    LxResult
  GetTargetColor (double *color)
  {
    return m_loc[0]->GetTargetColor (m_loc,color);
  }
    LxResult
  SetTargetColor (const double *color)
  {
    return m_loc[0]->SetTargetColor (m_loc,color);
  }
    LxResult
  GetOutputBlackLevel (double *outputBlackLevel)
  {
    return m_loc[0]->GetOutputBlackLevel (m_loc,outputBlackLevel);
  }
    LxResult
  SetOutputBlackLevel (double blackLevel)
  {
    return m_loc[0]->SetOutputBlackLevel (m_loc,blackLevel);
  }
    LxResult
  GetOutputWhiteLevel (double *outputWhiteLevel)
  {
    return m_loc[0]->GetOutputWhiteLevel (m_loc,outputWhiteLevel);
  }
    LxResult
  SetOutputWhiteLevel (double whiteLevel)
  {
    return m_loc[0]->SetOutputWhiteLevel (m_loc,whiteLevel);
  }
    LxResult
  GetOutputMinRedLevel (double *outputLevel)
  {
    return m_loc[0]->GetOutputMinRedLevel (m_loc,outputLevel);
  }
    LxResult
  SetOutputMinRedLevel (double outputLevel)
  {
    return m_loc[0]->SetOutputMinRedLevel (m_loc,outputLevel);
  }
    LxResult
  GetOutputMaxRedLevel (double *outputLevel)
  {
    return m_loc[0]->GetOutputMaxRedLevel (m_loc,outputLevel);
  }
    LxResult
  SetOutputMaxRedLevel (double outputLevel)
  {
    return m_loc[0]->SetOutputMaxRedLevel (m_loc,outputLevel);
  }
    LxResult
  GetOutputMinGreenLevel (double *outputLevel)
  {
    return m_loc[0]->GetOutputMinGreenLevel (m_loc,outputLevel);
  }
    LxResult
  SetOutputMinGreenLevel (double outputLevel)
  {
    return m_loc[0]->SetOutputMinGreenLevel (m_loc,outputLevel);
  }
    LxResult
  GetOutputMaxGreenLevel (double *outputLevel)
  {
    return m_loc[0]->GetOutputMaxGreenLevel (m_loc,outputLevel);
  }
    LxResult
  SetOutputMaxGreenLevel (double outputLevel)
  {
    return m_loc[0]->SetOutputMaxGreenLevel (m_loc,outputLevel);
  }
    LxResult
  GetOutputMinBlueLevel (double *outputLevel)
  {
    return m_loc[0]->GetOutputMinBlueLevel (m_loc,outputLevel);
  }
    LxResult
  SetOutputMinBlueLevel (double outputLevel)
  {
    return m_loc[0]->SetOutputMinBlueLevel (m_loc,outputLevel);
  }
    LxResult
  GetOutputMaxBlueLevel (double *outputLevel)
  {
    return m_loc[0]->GetOutputMaxBlueLevel (m_loc,outputLevel);
  }
    LxResult
  SetOutputMaxBlueLevel (double outputLevel)
  {
    return m_loc[0]->SetOutputMaxBlueLevel (m_loc,outputLevel);
  }
    LxResult
  GetOutputGamma (double *outputGamma)
  {
    return m_loc[0]->GetOutputGamma (m_loc,outputGamma);
  }
    LxResult
  GetOutputInvGamma (double *outputInvGamma)
  {
    return m_loc[0]->GetOutputInvGamma (m_loc,outputInvGamma);
  }
    LxResult
  SetOutputGamma (double gamma)
  {
    return m_loc[0]->SetOutputGamma (m_loc,gamma);
  }
};

class CLxLoc_RenderService : public CLxLocalizedService
{
  ILxRenderServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_RenderService() {_init();set();}
 ~CLxLoc_RenderService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxRenderServiceID>(lx::GetGlobal(&lx::guid_RenderService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  JobSetCurrent (ILxUnknownID job)
  {
    return m_loc[0]->JobSetCurrent (m_loc,(ILxUnknownID)job);
  }
    LxResult
  JobCurrent (void **ppvObj) const
  {
    return m_loc[0]->JobCurrent (m_loc,ppvObj);
  }
    bool
  JobCurrent (CLxLocalizedObject &dest) const
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->JobCurrent (m_loc,&obj)) && dest.take(obj);
  }
    LxResult
  JobStart (void)
  {
    return m_loc[0]->JobStart (m_loc);
  }
    LxResult
  JobAbort (void)
  {
    return m_loc[0]->JobAbort (m_loc);
  }
    LxResult
  JobStatus (void) const
  {
    return m_loc[0]->JobStatus (m_loc);
  }
    ILxUnknownID
  JobStats (void)
  {
    return (ILxUnknownID) m_loc[0]->JobStats (m_loc);
  }
    int
  JobIsSlave (void) const
  {
    return m_loc[0]->JobIsSlave (m_loc);
  }
    LxResult
  JobCleanup (int clearJob)
  {
    return m_loc[0]->JobCleanup (m_loc,clearJob);
  }
    LxResult
  JobRenderOutputCount (int *count) const
  {
    return m_loc[0]->JobRenderOutputCount (m_loc,count);
  }
    LxResult
  JobRenderOutputName (int index, const char **name) const
  {
    return m_loc[0]->JobRenderOutputName (m_loc,index,name);
  }
    LxResult
  JobRenderOutputType (int index, int *type) const
  {
    return m_loc[0]->JobRenderOutputType (m_loc,index,type);
  }
    LxResult
  UpdateProgressImage (void)
  {
    return m_loc[0]->UpdateProgressImage (m_loc);
  }
    LxResult
  RefreshProgressImageMetrics (void)
  {
    return m_loc[0]->RefreshProgressImageMetrics (m_loc);
  }
    LxResult
  FrameStore (ILxUnknownID frameBuffer, int writePixels)
  {
    return m_loc[0]->FrameStore (m_loc,(ILxUnknownID)frameBuffer,writePixels);
  }
    LxResult
  FrameRecall (int slotIndex, int passIndex, ILxUnknownID monitor, void **ppvObj)
  {
    return m_loc[0]->FrameRecall (m_loc,slotIndex,passIndex,(ILxUnknownID)monitor,ppvObj);
  }
    bool
  FrameRecall (int slotIndex, int passIndex, ILxUnknownID monitor, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->FrameRecall (m_loc,slotIndex,passIndex,(ILxUnknownID)monitor,&obj)) && dest.take(obj);
  }
    LxResult
  FrameTestRecall (int slotIndex, int passIndex)
  {
    return m_loc[0]->FrameTestRecall (m_loc,slotIndex,passIndex);
  }
    LxResult
  FrameRenderPassCount (int slotIndex, int *numPasses)
  {
    return m_loc[0]->FrameRenderPassCount (m_loc,slotIndex,numPasses);
  }
    LxResult
  FrameRenderPassInfo (int slotIndex, int passIndex, char *name, unsigned *width, unsigned *height, unsigned *outputCount, int *isStereo, LXtStereoEye *eyeDisplay, LXtStereoComposite *stereoComposite)
  {
    return m_loc[0]->FrameRenderPassInfo (m_loc,slotIndex,passIndex,name,width,height,outputCount,isStereo,eyeDisplay,stereoComposite);
  }
    LxResult
  FrameRenderPassOutputInfo (int slotIndex, int passIndex, char *renderPassName, unsigned *width, unsigned *height, LXtRenderOutputProcessList *outputs)
  {
    return m_loc[0]->FrameRenderPassOutputInfo (m_loc,slotIndex,passIndex,renderPassName,width,height,outputs);
  }
    LxResult
  FrameSaveImage (ILxUnknownID framebuffer, int bufferIndex, const char *filename, const char *format, ILxUnknownID message, ILxUnknownID monitor)
  {
    return m_loc[0]->FrameSaveImage (m_loc,(ILxUnknownID)framebuffer,bufferIndex,filename,format,(ILxUnknownID)message,(ILxUnknownID)monitor);
  }
    LxResult
  FrameSaveLayered (ILxUnknownID framebuffer, const char *filename, const char *format, ILxUnknownID message, ILxUnknownID monitor)
  {
    return m_loc[0]->FrameSaveLayered (m_loc,(ILxUnknownID)framebuffer,filename,format,(ILxUnknownID)message,(ILxUnknownID)monitor);
  }
    LxResult
  FrameSavePassLayered (ILxUnknownID framebuffer, const char *filename, const char *format, ILxUnknownID message, ILxUnknownID monitor)
  {
    return m_loc[0]->FrameSavePassLayered (m_loc,(ILxUnknownID)framebuffer,filename,format,(ILxUnknownID)message,(ILxUnknownID)monitor);
  }
    LxResult
  FrameSavePassesAsImages (int slotIndex, const char *filename, const char *format, ILxUnknownID message, ILxUnknownID monitor)
  {
    return m_loc[0]->FrameSavePassesAsImages (m_loc,slotIndex,filename,format,(ILxUnknownID)message,(ILxUnknownID)monitor);
  }
    LxResult
  FrameSavePassesAsLayeredImages (int slotIndex, const char *filename, const char *format, ILxUnknownID message, ILxUnknownID monitor)
  {
    return m_loc[0]->FrameSavePassesAsLayeredImages (m_loc,slotIndex,filename,format,(ILxUnknownID)message,(ILxUnknownID)monitor);
  }
    LxResult
  FrameStoreStats (int slotIndex, ILxUnknownID stats)
  {
    return m_loc[0]->FrameStoreStats (m_loc,slotIndex,(ILxUnknownID)stats);
  }
    LxResult
  FrameRecallStats (int slotIndex, void **ppvObj)
  {
    return m_loc[0]->FrameRecallStats (m_loc,slotIndex,ppvObj);
  }
    bool
  FrameRecallStats (int slotIndex, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->FrameRecallStats (m_loc,slotIndex,&obj)) && dest.take(obj);
  }
    LxResult
  FrameStoreThumbnail (int slotIndex, ILxUnknownID image)
  {
    return m_loc[0]->FrameStoreThumbnail (m_loc,slotIndex,(ILxUnknownID)image);
  }
    LxResult
  FrameRecallThumbnail (int slotIndex, void **ppvObj)
  {
    return m_loc[0]->FrameRecallThumbnail (m_loc,slotIndex,ppvObj);
  }
    bool
  FrameRecallThumbnail (int slotIndex, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->FrameRecallThumbnail (m_loc,slotIndex,&obj)) && dest.take(obj);
  }
    LxResult
  FrameDelete (int slotIndex)
  {
    return m_loc[0]->FrameDelete (m_loc,slotIndex);
  }
};

class CLxImpl_RenderProgressListener {
  public:
    virtual ~CLxImpl_RenderProgressListener() {}
    virtual void
      rndprog_Begin (void)
        { }
    virtual void
      rndprog_End (ILxUnknownID stats)
        { }
};
#define LXxD_RenderProgressListener_Begin void rndprog_Begin (void)
#define LXxO_RenderProgressListener_Begin LXxD_RenderProgressListener_Begin LXx_OVERRIDE
#define LXxD_RenderProgressListener_End void rndprog_End (ILxUnknownID stats)
#define LXxO_RenderProgressListener_End LXxD_RenderProgressListener_End LXx_OVERRIDE
template <class T>
class CLxIfc_RenderProgressListener : public CLxInterface
{
    static void
  Begin (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_RenderProgressListener, loc);
    loc->rndprog_Begin ();
  }
    static void
  End (LXtObjectID wcom, LXtObjectID stats)
  {
    LXCWxINST (CLxImpl_RenderProgressListener, loc);
    loc->rndprog_End ((ILxUnknownID)stats);
  }
  ILxRenderProgressListener vt;
public:
  CLxIfc_RenderProgressListener ()
  {
    vt.Begin = Begin;
    vt.End = End;
    vTable = &vt.iunk;
    iid = &lx::guid_RenderProgressListener;
  }
};
class CLxLoc_RenderProgressListener : public CLxLocalize<ILxRenderProgressListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_RenderProgressListener() {_init();}
  CLxLoc_RenderProgressListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_RenderProgressListener(const CLxLoc_RenderProgressListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_RenderProgressListener;}
    void
  Begin (void)
  {
    m_loc[0]->Begin (m_loc);
  }
    void
  End (ILxUnknownID stats)
  {
    m_loc[0]->End (m_loc,(ILxUnknownID)stats);
  }
};

class CLxImpl_FrameBuffer {
  public:
    virtual ~CLxImpl_FrameBuffer() {}
    virtual ILxBufferID
      fbuf_Allocate (const char *name, ILxUnknownID item, const char *identity, const char *userName, int isFactoryName, int writeBucketsToDisk)
        = 0;
    virtual LxResult
      fbuf_IsStereo (int *isStereo)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fbuf_GetStereoEyeDisplay (LXtStereoEye *eyeDisplay)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fbuf_SetStereoEyeDisplay (LXtStereoEye eyeDisplay)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fbuf_GetStereoComposite (LXtStereoComposite *composite)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fbuf_SetStereoComposite (LXtStereoComposite composite)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fbuf_SetEyeSide (int eyeSide)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fbuf_GetLineBuffer (float **buf)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fbuf_CreateFrameBufferTargetImage (LXtPixelFormat type, int w, int h, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fbuf_GetRenderPassName (char *name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fbuf_SetRenderPassName (const char *name)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      fbuf_BucketsOnDisk (int index)
        = 0;
    virtual LXtObjectID
      fbuf_Lookup (const char *name, ILxUnknownID item)
        = 0;
    virtual LXtObjectID
      fbuf_LookupByIdentity (const char *identity)
        = 0;
    virtual unsigned int
      fbuf_Count (void)
        = 0;
    virtual LXtObjectID
      fbuf_ByIndex (int index)
        = 0;
    virtual LXtObjectID
      fbuf_Alpha (int index)
        = 0;
    virtual int
      fbuf_AlphaIndex (int index)
        = 0;
    virtual LxResult
      fbuf_Size (int index, int *width, int *height)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fbuf_AreaProcessingActive (int bufferIndex, int *active)
        { return LXe_NOTIMPL; }
    virtual int
      fbuf_GetSaveProcessed (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetSaveProcessed (int bufferIndex, int enabled)
        { return LXe_NOTIMPL; }
    virtual int
      fbuf_GetBloomEnabled (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetBloomEnabled (int bufferIndex, int enabled)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetBloomThreshold (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetBloomThreshold (int bufferIndex, double threshold)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetBloomRadius (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetBloomRadius (int bufferIndex, double radius)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetVignetteAmount (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetVignetteAmount (int bufferIndex, double radius)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetLevelOffset (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetLevelOffset (int bufferIndex, double offset)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetRedLevelOffset (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetRedLevelOffset (int bufferIndex, double offset)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetGreenLevelOffset (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetGreenLevelOffset (int bufferIndex, double offset)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetBlueLevelOffset (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetBlueLevelOffset (int bufferIndex, double offset)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetInputBlackLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetInputBlackLevel (int bufferIndex, double blackLevel)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetInputGrayLevel (int bufferIndex)
        = 0;
    virtual double
      fbuf_GetInvInputGrayLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetInputGrayLevel (int bufferIndex, double gamma)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetInputWhiteLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetInputWhiteLevel (int bufferIndex, double whiteLevel)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetInputMinRedLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetInputMinRedLevel (int bufferIndex, double level)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetInputRedGrayLevel (int bufferIndex)
        = 0;
    virtual double
      fbuf_GetInvInputRedGrayLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetInputRedGrayLevel (int bufferIndex, double gamma)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetInputMaxRedLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetInputMaxRedLevel (int bufferIndex, double level)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetInputMinGreenLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetInputMinGreenLevel (int bufferIndex, double level)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetInputGreenGrayLevel (int bufferIndex)
        = 0;
    virtual double
      fbuf_GetInvInputGreenGrayLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetInputGreenGrayLevel (int bufferIndex, double gamma)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetInputMaxGreenLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetInputMaxGreenLevel (int bufferIndex, double level)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetInputMinBlueLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetInputMinBlueLevel (int bufferIndex, double level)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetInputBlueGrayLevel (int bufferIndex)
        = 0;
    virtual double
      fbuf_GetInvInputBlueGrayLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetInputBlueGrayLevel (int bufferIndex, double gamma)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetInputMaxBlueLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetInputMaxBlueLevel (int bufferIndex, double level)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetToneMapping (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetToneMapping (int bufferIndex, double toneMapping)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetHueOffset (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetHueOffset (int bufferIndex, double hueOffset)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetSaturation (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetSaturation (int bufferIndex, double saturation)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetColorization (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetColorization (int bufferIndex, double colorization)
        { return LXe_NOTIMPL; }
    virtual void
      fbuf_GetTargetColor (int bufferIndex, double *color)
        { }
    virtual LxResult
      fbuf_SetTargetColor (int bufferIndex, const double *color)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetOutputBlackLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetOutputBlackLevel (int bufferIndex, double blackLevel)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetOutputWhiteLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetOutputWhiteLevel (int bufferIndex, double whiteLevel)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetOutputMinRedLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetOutputMinRedLevel (int bufferIndex, double blackLevel)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetOutputMaxRedLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetOutputMaxRedLevel (int bufferIndex, double whiteLevel)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetOutputMinGreenLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetOutputMinGreenLevel (int bufferIndex, double blackLevel)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetOutputMaxGreenLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetOutputMaxGreenLevel (int bufferIndex, double whiteLevel)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetOutputMinBlueLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetOutputMinBlueLevel (int bufferIndex, double blackLevel)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetOutputMaxBlueLevel (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetOutputMaxBlueLevel (int bufferIndex, double whiteLevel)
        { return LXe_NOTIMPL; }
    virtual double
      fbuf_GetOutputGamma (int bufferIndex)
        = 0;
    virtual double
      fbuf_GetOutputInvGamma (int bufferIndex)
        = 0;
    virtual LxResult
      fbuf_SetOutputGamma (int bufferIndex, double gamma)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fbuf_AddAttribute (const char *name, const char *type, unsigned *index)
        { return LXe_NOTIMPL; }
};
#define LXxD_FrameBuffer_Allocate ILxBufferID fbuf_Allocate (const char *name, ILxUnknownID item, const char *identity, const char *userName, int isFactoryName, int writeBucketsToDisk)
#define LXxO_FrameBuffer_Allocate LXxD_FrameBuffer_Allocate LXx_OVERRIDE
#define LXxD_FrameBuffer_IsStereo LxResult fbuf_IsStereo (int *isStereo)
#define LXxO_FrameBuffer_IsStereo LXxD_FrameBuffer_IsStereo LXx_OVERRIDE
#define LXxD_FrameBuffer_GetStereoEyeDisplay LxResult fbuf_GetStereoEyeDisplay (LXtStereoEye *eyeDisplay)
#define LXxO_FrameBuffer_GetStereoEyeDisplay LXxD_FrameBuffer_GetStereoEyeDisplay LXx_OVERRIDE
#define LXxD_FrameBuffer_SetStereoEyeDisplay LxResult fbuf_SetStereoEyeDisplay (LXtStereoEye eyeDisplay)
#define LXxO_FrameBuffer_SetStereoEyeDisplay LXxD_FrameBuffer_SetStereoEyeDisplay LXx_OVERRIDE
#define LXxD_FrameBuffer_GetStereoComposite LxResult fbuf_GetStereoComposite (LXtStereoComposite *composite)
#define LXxO_FrameBuffer_GetStereoComposite LXxD_FrameBuffer_GetStereoComposite LXx_OVERRIDE
#define LXxD_FrameBuffer_SetStereoComposite LxResult fbuf_SetStereoComposite (LXtStereoComposite composite)
#define LXxO_FrameBuffer_SetStereoComposite LXxD_FrameBuffer_SetStereoComposite LXx_OVERRIDE
#define LXxD_FrameBuffer_SetEyeSide LxResult fbuf_SetEyeSide (int eyeSide)
#define LXxO_FrameBuffer_SetEyeSide LXxD_FrameBuffer_SetEyeSide LXx_OVERRIDE
#define LXxD_FrameBuffer_GetLineBuffer LxResult fbuf_GetLineBuffer (float **buf)
#define LXxO_FrameBuffer_GetLineBuffer LXxD_FrameBuffer_GetLineBuffer LXx_OVERRIDE
#define LXxD_FrameBuffer_CreateFrameBufferTargetImage LxResult fbuf_CreateFrameBufferTargetImage (LXtPixelFormat type, int w, int h, void **ppvObj)
#define LXxO_FrameBuffer_CreateFrameBufferTargetImage LXxD_FrameBuffer_CreateFrameBufferTargetImage LXx_OVERRIDE
#define LXxD_FrameBuffer_GetRenderPassName LxResult fbuf_GetRenderPassName (char *name)
#define LXxO_FrameBuffer_GetRenderPassName LXxD_FrameBuffer_GetRenderPassName LXx_OVERRIDE
#define LXxD_FrameBuffer_SetRenderPassName LxResult fbuf_SetRenderPassName (const char *name)
#define LXxO_FrameBuffer_SetRenderPassName LXxD_FrameBuffer_SetRenderPassName LXx_OVERRIDE
#define LXxD_FrameBuffer_BucketsOnDisk unsigned int fbuf_BucketsOnDisk (int index)
#define LXxO_FrameBuffer_BucketsOnDisk LXxD_FrameBuffer_BucketsOnDisk LXx_OVERRIDE
#define LXxD_FrameBuffer_Lookup LXtObjectID fbuf_Lookup (const char *name, ILxUnknownID item)
#define LXxO_FrameBuffer_Lookup LXxD_FrameBuffer_Lookup LXx_OVERRIDE
#define LXxD_FrameBuffer_LookupByIdentity LXtObjectID fbuf_LookupByIdentity (const char *identity)
#define LXxO_FrameBuffer_LookupByIdentity LXxD_FrameBuffer_LookupByIdentity LXx_OVERRIDE
#define LXxD_FrameBuffer_Count unsigned int fbuf_Count (void)
#define LXxO_FrameBuffer_Count LXxD_FrameBuffer_Count LXx_OVERRIDE
#define LXxD_FrameBuffer_ByIndex LXtObjectID fbuf_ByIndex (int index)
#define LXxO_FrameBuffer_ByIndex LXxD_FrameBuffer_ByIndex LXx_OVERRIDE
#define LXxD_FrameBuffer_Alpha LXtObjectID fbuf_Alpha (int index)
#define LXxO_FrameBuffer_Alpha LXxD_FrameBuffer_Alpha LXx_OVERRIDE
#define LXxD_FrameBuffer_AlphaIndex int fbuf_AlphaIndex (int index)
#define LXxO_FrameBuffer_AlphaIndex LXxD_FrameBuffer_AlphaIndex LXx_OVERRIDE
#define LXxD_FrameBuffer_Size LxResult fbuf_Size (int index, int *width, int *height)
#define LXxO_FrameBuffer_Size LXxD_FrameBuffer_Size LXx_OVERRIDE
#define LXxD_FrameBuffer_AreaProcessingActive LxResult fbuf_AreaProcessingActive (int bufferIndex, int *active)
#define LXxO_FrameBuffer_AreaProcessingActive LXxD_FrameBuffer_AreaProcessingActive LXx_OVERRIDE
#define LXxD_FrameBuffer_GetSaveProcessed int fbuf_GetSaveProcessed (int bufferIndex)
#define LXxO_FrameBuffer_GetSaveProcessed LXxD_FrameBuffer_GetSaveProcessed LXx_OVERRIDE
#define LXxD_FrameBuffer_SetSaveProcessed LxResult fbuf_SetSaveProcessed (int bufferIndex, int enabled)
#define LXxO_FrameBuffer_SetSaveProcessed LXxD_FrameBuffer_SetSaveProcessed LXx_OVERRIDE
#define LXxD_FrameBuffer_GetBloomEnabled int fbuf_GetBloomEnabled (int bufferIndex)
#define LXxO_FrameBuffer_GetBloomEnabled LXxD_FrameBuffer_GetBloomEnabled LXx_OVERRIDE
#define LXxD_FrameBuffer_SetBloomEnabled LxResult fbuf_SetBloomEnabled (int bufferIndex, int enabled)
#define LXxO_FrameBuffer_SetBloomEnabled LXxD_FrameBuffer_SetBloomEnabled LXx_OVERRIDE
#define LXxD_FrameBuffer_GetBloomThreshold double fbuf_GetBloomThreshold (int bufferIndex)
#define LXxO_FrameBuffer_GetBloomThreshold LXxD_FrameBuffer_GetBloomThreshold LXx_OVERRIDE
#define LXxD_FrameBuffer_SetBloomThreshold LxResult fbuf_SetBloomThreshold (int bufferIndex, double threshold)
#define LXxO_FrameBuffer_SetBloomThreshold LXxD_FrameBuffer_SetBloomThreshold LXx_OVERRIDE
#define LXxD_FrameBuffer_GetBloomRadius double fbuf_GetBloomRadius (int bufferIndex)
#define LXxO_FrameBuffer_GetBloomRadius LXxD_FrameBuffer_GetBloomRadius LXx_OVERRIDE
#define LXxD_FrameBuffer_SetBloomRadius LxResult fbuf_SetBloomRadius (int bufferIndex, double radius)
#define LXxO_FrameBuffer_SetBloomRadius LXxD_FrameBuffer_SetBloomRadius LXx_OVERRIDE
#define LXxD_FrameBuffer_GetVignetteAmount double fbuf_GetVignetteAmount (int bufferIndex)
#define LXxO_FrameBuffer_GetVignetteAmount LXxD_FrameBuffer_GetVignetteAmount LXx_OVERRIDE
#define LXxD_FrameBuffer_SetVignetteAmount LxResult fbuf_SetVignetteAmount (int bufferIndex, double radius)
#define LXxO_FrameBuffer_SetVignetteAmount LXxD_FrameBuffer_SetVignetteAmount LXx_OVERRIDE
#define LXxD_FrameBuffer_GetLevelOffset double fbuf_GetLevelOffset (int bufferIndex)
#define LXxO_FrameBuffer_GetLevelOffset LXxD_FrameBuffer_GetLevelOffset LXx_OVERRIDE
#define LXxD_FrameBuffer_SetLevelOffset LxResult fbuf_SetLevelOffset (int bufferIndex, double offset)
#define LXxO_FrameBuffer_SetLevelOffset LXxD_FrameBuffer_SetLevelOffset LXx_OVERRIDE
#define LXxD_FrameBuffer_GetRedLevelOffset double fbuf_GetRedLevelOffset (int bufferIndex)
#define LXxO_FrameBuffer_GetRedLevelOffset LXxD_FrameBuffer_GetRedLevelOffset LXx_OVERRIDE
#define LXxD_FrameBuffer_SetRedLevelOffset LxResult fbuf_SetRedLevelOffset (int bufferIndex, double offset)
#define LXxO_FrameBuffer_SetRedLevelOffset LXxD_FrameBuffer_SetRedLevelOffset LXx_OVERRIDE
#define LXxD_FrameBuffer_GetGreenLevelOffset double fbuf_GetGreenLevelOffset (int bufferIndex)
#define LXxO_FrameBuffer_GetGreenLevelOffset LXxD_FrameBuffer_GetGreenLevelOffset LXx_OVERRIDE
#define LXxD_FrameBuffer_SetGreenLevelOffset LxResult fbuf_SetGreenLevelOffset (int bufferIndex, double offset)
#define LXxO_FrameBuffer_SetGreenLevelOffset LXxD_FrameBuffer_SetGreenLevelOffset LXx_OVERRIDE
#define LXxD_FrameBuffer_GetBlueLevelOffset double fbuf_GetBlueLevelOffset (int bufferIndex)
#define LXxO_FrameBuffer_GetBlueLevelOffset LXxD_FrameBuffer_GetBlueLevelOffset LXx_OVERRIDE
#define LXxD_FrameBuffer_SetBlueLevelOffset LxResult fbuf_SetBlueLevelOffset (int bufferIndex, double offset)
#define LXxO_FrameBuffer_SetBlueLevelOffset LXxD_FrameBuffer_SetBlueLevelOffset LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInputBlackLevel double fbuf_GetInputBlackLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInputBlackLevel LXxD_FrameBuffer_GetInputBlackLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetInputBlackLevel LxResult fbuf_SetInputBlackLevel (int bufferIndex, double blackLevel)
#define LXxO_FrameBuffer_SetInputBlackLevel LXxD_FrameBuffer_SetInputBlackLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInputGrayLevel double fbuf_GetInputGrayLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInputGrayLevel LXxD_FrameBuffer_GetInputGrayLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInvInputGrayLevel double fbuf_GetInvInputGrayLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInvInputGrayLevel LXxD_FrameBuffer_GetInvInputGrayLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetInputGrayLevel LxResult fbuf_SetInputGrayLevel (int bufferIndex, double gamma)
#define LXxO_FrameBuffer_SetInputGrayLevel LXxD_FrameBuffer_SetInputGrayLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInputWhiteLevel double fbuf_GetInputWhiteLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInputWhiteLevel LXxD_FrameBuffer_GetInputWhiteLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetInputWhiteLevel LxResult fbuf_SetInputWhiteLevel (int bufferIndex, double whiteLevel)
#define LXxO_FrameBuffer_SetInputWhiteLevel LXxD_FrameBuffer_SetInputWhiteLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInputMinRedLevel double fbuf_GetInputMinRedLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInputMinRedLevel LXxD_FrameBuffer_GetInputMinRedLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetInputMinRedLevel LxResult fbuf_SetInputMinRedLevel (int bufferIndex, double level)
#define LXxO_FrameBuffer_SetInputMinRedLevel LXxD_FrameBuffer_SetInputMinRedLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInputRedGrayLevel double fbuf_GetInputRedGrayLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInputRedGrayLevel LXxD_FrameBuffer_GetInputRedGrayLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInvInputRedGrayLevel double fbuf_GetInvInputRedGrayLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInvInputRedGrayLevel LXxD_FrameBuffer_GetInvInputRedGrayLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetInputRedGrayLevel LxResult fbuf_SetInputRedGrayLevel (int bufferIndex, double gamma)
#define LXxO_FrameBuffer_SetInputRedGrayLevel LXxD_FrameBuffer_SetInputRedGrayLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInputMaxRedLevel double fbuf_GetInputMaxRedLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInputMaxRedLevel LXxD_FrameBuffer_GetInputMaxRedLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetInputMaxRedLevel LxResult fbuf_SetInputMaxRedLevel (int bufferIndex, double level)
#define LXxO_FrameBuffer_SetInputMaxRedLevel LXxD_FrameBuffer_SetInputMaxRedLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInputMinGreenLevel double fbuf_GetInputMinGreenLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInputMinGreenLevel LXxD_FrameBuffer_GetInputMinGreenLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetInputMinGreenLevel LxResult fbuf_SetInputMinGreenLevel (int bufferIndex, double level)
#define LXxO_FrameBuffer_SetInputMinGreenLevel LXxD_FrameBuffer_SetInputMinGreenLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInputGreenGrayLevel double fbuf_GetInputGreenGrayLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInputGreenGrayLevel LXxD_FrameBuffer_GetInputGreenGrayLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInvInputGreenGrayLevel double fbuf_GetInvInputGreenGrayLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInvInputGreenGrayLevel LXxD_FrameBuffer_GetInvInputGreenGrayLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetInputGreenGrayLevel LxResult fbuf_SetInputGreenGrayLevel (int bufferIndex, double gamma)
#define LXxO_FrameBuffer_SetInputGreenGrayLevel LXxD_FrameBuffer_SetInputGreenGrayLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInputMaxGreenLevel double fbuf_GetInputMaxGreenLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInputMaxGreenLevel LXxD_FrameBuffer_GetInputMaxGreenLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetInputMaxGreenLevel LxResult fbuf_SetInputMaxGreenLevel (int bufferIndex, double level)
#define LXxO_FrameBuffer_SetInputMaxGreenLevel LXxD_FrameBuffer_SetInputMaxGreenLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInputMinBlueLevel double fbuf_GetInputMinBlueLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInputMinBlueLevel LXxD_FrameBuffer_GetInputMinBlueLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetInputMinBlueLevel LxResult fbuf_SetInputMinBlueLevel (int bufferIndex, double level)
#define LXxO_FrameBuffer_SetInputMinBlueLevel LXxD_FrameBuffer_SetInputMinBlueLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInputBlueGrayLevel double fbuf_GetInputBlueGrayLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInputBlueGrayLevel LXxD_FrameBuffer_GetInputBlueGrayLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInvInputBlueGrayLevel double fbuf_GetInvInputBlueGrayLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInvInputBlueGrayLevel LXxD_FrameBuffer_GetInvInputBlueGrayLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetInputBlueGrayLevel LxResult fbuf_SetInputBlueGrayLevel (int bufferIndex, double gamma)
#define LXxO_FrameBuffer_SetInputBlueGrayLevel LXxD_FrameBuffer_SetInputBlueGrayLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetInputMaxBlueLevel double fbuf_GetInputMaxBlueLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetInputMaxBlueLevel LXxD_FrameBuffer_GetInputMaxBlueLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetInputMaxBlueLevel LxResult fbuf_SetInputMaxBlueLevel (int bufferIndex, double level)
#define LXxO_FrameBuffer_SetInputMaxBlueLevel LXxD_FrameBuffer_SetInputMaxBlueLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetToneMapping double fbuf_GetToneMapping (int bufferIndex)
#define LXxO_FrameBuffer_GetToneMapping LXxD_FrameBuffer_GetToneMapping LXx_OVERRIDE
#define LXxD_FrameBuffer_SetToneMapping LxResult fbuf_SetToneMapping (int bufferIndex, double toneMapping)
#define LXxO_FrameBuffer_SetToneMapping LXxD_FrameBuffer_SetToneMapping LXx_OVERRIDE
#define LXxD_FrameBuffer_GetHueOffset double fbuf_GetHueOffset (int bufferIndex)
#define LXxO_FrameBuffer_GetHueOffset LXxD_FrameBuffer_GetHueOffset LXx_OVERRIDE
#define LXxD_FrameBuffer_SetHueOffset LxResult fbuf_SetHueOffset (int bufferIndex, double hueOffset)
#define LXxO_FrameBuffer_SetHueOffset LXxD_FrameBuffer_SetHueOffset LXx_OVERRIDE
#define LXxD_FrameBuffer_GetSaturation double fbuf_GetSaturation (int bufferIndex)
#define LXxO_FrameBuffer_GetSaturation LXxD_FrameBuffer_GetSaturation LXx_OVERRIDE
#define LXxD_FrameBuffer_SetSaturation LxResult fbuf_SetSaturation (int bufferIndex, double saturation)
#define LXxO_FrameBuffer_SetSaturation LXxD_FrameBuffer_SetSaturation LXx_OVERRIDE
#define LXxD_FrameBuffer_GetColorization double fbuf_GetColorization (int bufferIndex)
#define LXxO_FrameBuffer_GetColorization LXxD_FrameBuffer_GetColorization LXx_OVERRIDE
#define LXxD_FrameBuffer_SetColorization LxResult fbuf_SetColorization (int bufferIndex, double colorization)
#define LXxO_FrameBuffer_SetColorization LXxD_FrameBuffer_SetColorization LXx_OVERRIDE
#define LXxD_FrameBuffer_GetTargetColor void fbuf_GetTargetColor (int bufferIndex, double *color)
#define LXxO_FrameBuffer_GetTargetColor LXxD_FrameBuffer_GetTargetColor LXx_OVERRIDE
#define LXxD_FrameBuffer_SetTargetColor LxResult fbuf_SetTargetColor (int bufferIndex, const double *color)
#define LXxO_FrameBuffer_SetTargetColor LXxD_FrameBuffer_SetTargetColor LXx_OVERRIDE
#define LXxD_FrameBuffer_GetOutputBlackLevel double fbuf_GetOutputBlackLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetOutputBlackLevel LXxD_FrameBuffer_GetOutputBlackLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetOutputBlackLevel LxResult fbuf_SetOutputBlackLevel (int bufferIndex, double blackLevel)
#define LXxO_FrameBuffer_SetOutputBlackLevel LXxD_FrameBuffer_SetOutputBlackLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetOutputWhiteLevel double fbuf_GetOutputWhiteLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetOutputWhiteLevel LXxD_FrameBuffer_GetOutputWhiteLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetOutputWhiteLevel LxResult fbuf_SetOutputWhiteLevel (int bufferIndex, double whiteLevel)
#define LXxO_FrameBuffer_SetOutputWhiteLevel LXxD_FrameBuffer_SetOutputWhiteLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetOutputMinRedLevel double fbuf_GetOutputMinRedLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetOutputMinRedLevel LXxD_FrameBuffer_GetOutputMinRedLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetOutputMinRedLevel LxResult fbuf_SetOutputMinRedLevel (int bufferIndex, double blackLevel)
#define LXxO_FrameBuffer_SetOutputMinRedLevel LXxD_FrameBuffer_SetOutputMinRedLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetOutputMaxRedLevel double fbuf_GetOutputMaxRedLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetOutputMaxRedLevel LXxD_FrameBuffer_GetOutputMaxRedLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetOutputMaxRedLevel LxResult fbuf_SetOutputMaxRedLevel (int bufferIndex, double whiteLevel)
#define LXxO_FrameBuffer_SetOutputMaxRedLevel LXxD_FrameBuffer_SetOutputMaxRedLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetOutputMinGreenLevel double fbuf_GetOutputMinGreenLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetOutputMinGreenLevel LXxD_FrameBuffer_GetOutputMinGreenLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetOutputMinGreenLevel LxResult fbuf_SetOutputMinGreenLevel (int bufferIndex, double blackLevel)
#define LXxO_FrameBuffer_SetOutputMinGreenLevel LXxD_FrameBuffer_SetOutputMinGreenLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetOutputMaxGreenLevel double fbuf_GetOutputMaxGreenLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetOutputMaxGreenLevel LXxD_FrameBuffer_GetOutputMaxGreenLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetOutputMaxGreenLevel LxResult fbuf_SetOutputMaxGreenLevel (int bufferIndex, double whiteLevel)
#define LXxO_FrameBuffer_SetOutputMaxGreenLevel LXxD_FrameBuffer_SetOutputMaxGreenLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetOutputMinBlueLevel double fbuf_GetOutputMinBlueLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetOutputMinBlueLevel LXxD_FrameBuffer_GetOutputMinBlueLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetOutputMinBlueLevel LxResult fbuf_SetOutputMinBlueLevel (int bufferIndex, double blackLevel)
#define LXxO_FrameBuffer_SetOutputMinBlueLevel LXxD_FrameBuffer_SetOutputMinBlueLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetOutputMaxBlueLevel double fbuf_GetOutputMaxBlueLevel (int bufferIndex)
#define LXxO_FrameBuffer_GetOutputMaxBlueLevel LXxD_FrameBuffer_GetOutputMaxBlueLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_SetOutputMaxBlueLevel LxResult fbuf_SetOutputMaxBlueLevel (int bufferIndex, double whiteLevel)
#define LXxO_FrameBuffer_SetOutputMaxBlueLevel LXxD_FrameBuffer_SetOutputMaxBlueLevel LXx_OVERRIDE
#define LXxD_FrameBuffer_GetOutputGamma double fbuf_GetOutputGamma (int bufferIndex)
#define LXxO_FrameBuffer_GetOutputGamma LXxD_FrameBuffer_GetOutputGamma LXx_OVERRIDE
#define LXxD_FrameBuffer_GetOutputInvGamma double fbuf_GetOutputInvGamma (int bufferIndex)
#define LXxO_FrameBuffer_GetOutputInvGamma LXxD_FrameBuffer_GetOutputInvGamma LXx_OVERRIDE
#define LXxD_FrameBuffer_SetOutputGamma LxResult fbuf_SetOutputGamma (int bufferIndex, double gamma)
#define LXxO_FrameBuffer_SetOutputGamma LXxD_FrameBuffer_SetOutputGamma LXx_OVERRIDE
#define LXxD_FrameBuffer_AddAttribute LxResult fbuf_AddAttribute (const char *name, const char *type, unsigned *index)
#define LXxO_FrameBuffer_AddAttribute LXxD_FrameBuffer_AddAttribute LXx_OVERRIDE
template <class T>
class CLxIfc_FrameBuffer : public CLxInterface
{
    static ILxBufferID
  Allocate (LXtObjectID wcom, const char *name, LXtObjectID item, const char *identity, const char *userName, int isFactoryName, int writeBucketsToDisk)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_Allocate (name,(ILxUnknownID)item,identity,userName,isFactoryName,writeBucketsToDisk);
  }
    static LxResult
  IsStereo (LXtObjectID wcom, int *isStereo)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_IsStereo (isStereo);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetStereoEyeDisplay (LXtObjectID wcom, LXtStereoEye *eyeDisplay)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_GetStereoEyeDisplay (eyeDisplay);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetStereoEyeDisplay (LXtObjectID wcom, LXtStereoEye eyeDisplay)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetStereoEyeDisplay (eyeDisplay);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetStereoComposite (LXtObjectID wcom, LXtStereoComposite *composite)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_GetStereoComposite (composite);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetStereoComposite (LXtObjectID wcom, LXtStereoComposite composite)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetStereoComposite (composite);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetEyeSide (LXtObjectID wcom, int eyeSide)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetEyeSide (eyeSide);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetLineBuffer (LXtObjectID wcom, float **buf)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_GetLineBuffer (buf);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CreateFrameBufferTargetImage (LXtObjectID wcom, LXtPixelFormat type, int w, int h, void **ppvObj)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_CreateFrameBufferTargetImage (type,w,h,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetRenderPassName (LXtObjectID wcom, char *name)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_GetRenderPassName (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetRenderPassName (LXtObjectID wcom, const char *name)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetRenderPassName (name);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  BucketsOnDisk (LXtObjectID wcom, int index)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_BucketsOnDisk (index);
  }
    static LXtObjectID
  Lookup (LXtObjectID wcom, const char *name, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_Lookup (name,(ILxUnknownID)item);
  }
    static LXtObjectID
  LookupByIdentity (LXtObjectID wcom, const char *identity)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_LookupByIdentity (identity);
  }
    static unsigned int
  Count (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_Count ();
  }
    static LXtObjectID
  ByIndex (LXtObjectID wcom, int index)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_ByIndex (index);
  }
    static LXtObjectID
  Alpha (LXtObjectID wcom, int index)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_Alpha (index);
  }
    static int
  AlphaIndex (LXtObjectID wcom, int index)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_AlphaIndex (index);
  }
    static LxResult
  Size (LXtObjectID wcom, int index, int *width, int *height)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_Size (index,width,height);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AreaProcessingActive (LXtObjectID wcom, int bufferIndex, int *active)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_AreaProcessingActive (bufferIndex,active);
    } catch (LxResult rc) { return rc; }
  }
    static int
  GetSaveProcessed (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetSaveProcessed (bufferIndex);
  }
    static LxResult
  SetSaveProcessed (LXtObjectID wcom, int bufferIndex, int enabled)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetSaveProcessed (bufferIndex,enabled);
    } catch (LxResult rc) { return rc; }
  }
    static int
  GetBloomEnabled (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetBloomEnabled (bufferIndex);
  }
    static LxResult
  SetBloomEnabled (LXtObjectID wcom, int bufferIndex, int enabled)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetBloomEnabled (bufferIndex,enabled);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetBloomThreshold (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetBloomThreshold (bufferIndex);
  }
    static LxResult
  SetBloomThreshold (LXtObjectID wcom, int bufferIndex, double threshold)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetBloomThreshold (bufferIndex,threshold);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetBloomRadius (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetBloomRadius (bufferIndex);
  }
    static LxResult
  SetBloomRadius (LXtObjectID wcom, int bufferIndex, double radius)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetBloomRadius (bufferIndex,radius);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetVignetteAmount (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetVignetteAmount (bufferIndex);
  }
    static LxResult
  SetVignetteAmount (LXtObjectID wcom, int bufferIndex, double radius)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetVignetteAmount (bufferIndex,radius);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetLevelOffset (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetLevelOffset (bufferIndex);
  }
    static LxResult
  SetLevelOffset (LXtObjectID wcom, int bufferIndex, double offset)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetLevelOffset (bufferIndex,offset);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetRedLevelOffset (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetRedLevelOffset (bufferIndex);
  }
    static LxResult
  SetRedLevelOffset (LXtObjectID wcom, int bufferIndex, double offset)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetRedLevelOffset (bufferIndex,offset);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetGreenLevelOffset (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetGreenLevelOffset (bufferIndex);
  }
    static LxResult
  SetGreenLevelOffset (LXtObjectID wcom, int bufferIndex, double offset)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetGreenLevelOffset (bufferIndex,offset);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetBlueLevelOffset (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetBlueLevelOffset (bufferIndex);
  }
    static LxResult
  SetBlueLevelOffset (LXtObjectID wcom, int bufferIndex, double offset)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetBlueLevelOffset (bufferIndex,offset);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetInputBlackLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInputBlackLevel (bufferIndex);
  }
    static LxResult
  SetInputBlackLevel (LXtObjectID wcom, int bufferIndex, double blackLevel)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetInputBlackLevel (bufferIndex,blackLevel);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetInputGrayLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInputGrayLevel (bufferIndex);
  }
    static double
  GetInvInputGrayLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInvInputGrayLevel (bufferIndex);
  }
    static LxResult
  SetInputGrayLevel (LXtObjectID wcom, int bufferIndex, double gamma)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetInputGrayLevel (bufferIndex,gamma);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetInputWhiteLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInputWhiteLevel (bufferIndex);
  }
    static LxResult
  SetInputWhiteLevel (LXtObjectID wcom, int bufferIndex, double whiteLevel)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetInputWhiteLevel (bufferIndex,whiteLevel);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetInputMinRedLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInputMinRedLevel (bufferIndex);
  }
    static LxResult
  SetInputMinRedLevel (LXtObjectID wcom, int bufferIndex, double level)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetInputMinRedLevel (bufferIndex,level);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetInputRedGrayLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInputRedGrayLevel (bufferIndex);
  }
    static double
  GetInvInputRedGrayLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInvInputRedGrayLevel (bufferIndex);
  }
    static LxResult
  SetInputRedGrayLevel (LXtObjectID wcom, int bufferIndex, double gamma)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetInputRedGrayLevel (bufferIndex,gamma);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetInputMaxRedLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInputMaxRedLevel (bufferIndex);
  }
    static LxResult
  SetInputMaxRedLevel (LXtObjectID wcom, int bufferIndex, double level)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetInputMaxRedLevel (bufferIndex,level);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetInputMinGreenLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInputMinGreenLevel (bufferIndex);
  }
    static LxResult
  SetInputMinGreenLevel (LXtObjectID wcom, int bufferIndex, double level)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetInputMinGreenLevel (bufferIndex,level);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetInputGreenGrayLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInputGreenGrayLevel (bufferIndex);
  }
    static double
  GetInvInputGreenGrayLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInvInputGreenGrayLevel (bufferIndex);
  }
    static LxResult
  SetInputGreenGrayLevel (LXtObjectID wcom, int bufferIndex, double gamma)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetInputGreenGrayLevel (bufferIndex,gamma);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetInputMaxGreenLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInputMaxGreenLevel (bufferIndex);
  }
    static LxResult
  SetInputMaxGreenLevel (LXtObjectID wcom, int bufferIndex, double level)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetInputMaxGreenLevel (bufferIndex,level);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetInputMinBlueLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInputMinBlueLevel (bufferIndex);
  }
    static LxResult
  SetInputMinBlueLevel (LXtObjectID wcom, int bufferIndex, double level)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetInputMinBlueLevel (bufferIndex,level);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetInputBlueGrayLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInputBlueGrayLevel (bufferIndex);
  }
    static double
  GetInvInputBlueGrayLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInvInputBlueGrayLevel (bufferIndex);
  }
    static LxResult
  SetInputBlueGrayLevel (LXtObjectID wcom, int bufferIndex, double gamma)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetInputBlueGrayLevel (bufferIndex,gamma);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetInputMaxBlueLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetInputMaxBlueLevel (bufferIndex);
  }
    static LxResult
  SetInputMaxBlueLevel (LXtObjectID wcom, int bufferIndex, double level)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetInputMaxBlueLevel (bufferIndex,level);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetToneMapping (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetToneMapping (bufferIndex);
  }
    static LxResult
  SetToneMapping (LXtObjectID wcom, int bufferIndex, double toneMapping)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetToneMapping (bufferIndex,toneMapping);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetHueOffset (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetHueOffset (bufferIndex);
  }
    static LxResult
  SetHueOffset (LXtObjectID wcom, int bufferIndex, double hueOffset)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetHueOffset (bufferIndex,hueOffset);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetSaturation (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetSaturation (bufferIndex);
  }
    static LxResult
  SetSaturation (LXtObjectID wcom, int bufferIndex, double saturation)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetSaturation (bufferIndex,saturation);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetColorization (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetColorization (bufferIndex);
  }
    static LxResult
  SetColorization (LXtObjectID wcom, int bufferIndex, double colorization)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetColorization (bufferIndex,colorization);
    } catch (LxResult rc) { return rc; }
  }
    static void
  GetTargetColor (LXtObjectID wcom, int bufferIndex, double *color)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    loc->fbuf_GetTargetColor (bufferIndex,color);
  }
    static LxResult
  SetTargetColor (LXtObjectID wcom, int bufferIndex, const double *color)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetTargetColor (bufferIndex,color);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetOutputBlackLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetOutputBlackLevel (bufferIndex);
  }
    static LxResult
  SetOutputBlackLevel (LXtObjectID wcom, int bufferIndex, double blackLevel)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetOutputBlackLevel (bufferIndex,blackLevel);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetOutputWhiteLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetOutputWhiteLevel (bufferIndex);
  }
    static LxResult
  SetOutputWhiteLevel (LXtObjectID wcom, int bufferIndex, double whiteLevel)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetOutputWhiteLevel (bufferIndex,whiteLevel);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetOutputMinRedLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetOutputMinRedLevel (bufferIndex);
  }
    static LxResult
  SetOutputMinRedLevel (LXtObjectID wcom, int bufferIndex, double blackLevel)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetOutputMinRedLevel (bufferIndex,blackLevel);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetOutputMaxRedLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetOutputMaxRedLevel (bufferIndex);
  }
    static LxResult
  SetOutputMaxRedLevel (LXtObjectID wcom, int bufferIndex, double whiteLevel)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetOutputMaxRedLevel (bufferIndex,whiteLevel);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetOutputMinGreenLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetOutputMinGreenLevel (bufferIndex);
  }
    static LxResult
  SetOutputMinGreenLevel (LXtObjectID wcom, int bufferIndex, double blackLevel)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetOutputMinGreenLevel (bufferIndex,blackLevel);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetOutputMaxGreenLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetOutputMaxGreenLevel (bufferIndex);
  }
    static LxResult
  SetOutputMaxGreenLevel (LXtObjectID wcom, int bufferIndex, double whiteLevel)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetOutputMaxGreenLevel (bufferIndex,whiteLevel);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetOutputMinBlueLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetOutputMinBlueLevel (bufferIndex);
  }
    static LxResult
  SetOutputMinBlueLevel (LXtObjectID wcom, int bufferIndex, double blackLevel)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetOutputMinBlueLevel (bufferIndex,blackLevel);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetOutputMaxBlueLevel (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetOutputMaxBlueLevel (bufferIndex);
  }
    static LxResult
  SetOutputMaxBlueLevel (LXtObjectID wcom, int bufferIndex, double whiteLevel)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetOutputMaxBlueLevel (bufferIndex,whiteLevel);
    } catch (LxResult rc) { return rc; }
  }
    static double
  GetOutputGamma (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetOutputGamma (bufferIndex);
  }
    static double
  GetOutputInvGamma (LXtObjectID wcom, int bufferIndex)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    return loc->fbuf_GetOutputInvGamma (bufferIndex);
  }
    static LxResult
  SetOutputGamma (LXtObjectID wcom, int bufferIndex, double gamma)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_SetOutputGamma (bufferIndex,gamma);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddAttribute (LXtObjectID wcom, const char *name, const char *type, unsigned *index)
  {
    LXCWxINST (CLxImpl_FrameBuffer, loc);
    try {
      return loc->fbuf_AddAttribute (name,type,index);
    } catch (LxResult rc) { return rc; }
  }
  ILxFrameBuffer vt;
public:
  CLxIfc_FrameBuffer ()
  {
    vt.Allocate = Allocate;
    vt.IsStereo = IsStereo;
    vt.GetStereoEyeDisplay = GetStereoEyeDisplay;
    vt.SetStereoEyeDisplay = SetStereoEyeDisplay;
    vt.GetStereoComposite = GetStereoComposite;
    vt.SetStereoComposite = SetStereoComposite;
    vt.SetEyeSide = SetEyeSide;
    vt.GetLineBuffer = GetLineBuffer;
    vt.CreateFrameBufferTargetImage = CreateFrameBufferTargetImage;
    vt.GetRenderPassName = GetRenderPassName;
    vt.SetRenderPassName = SetRenderPassName;
    vt.BucketsOnDisk = BucketsOnDisk;
    vt.Lookup = Lookup;
    vt.LookupByIdentity = LookupByIdentity;
    vt.Count = Count;
    vt.ByIndex = ByIndex;
    vt.Alpha = Alpha;
    vt.AlphaIndex = AlphaIndex;
    vt.Size = Size;
    vt.AreaProcessingActive = AreaProcessingActive;
    vt.GetSaveProcessed = GetSaveProcessed;
    vt.SetSaveProcessed = SetSaveProcessed;
    vt.GetBloomEnabled = GetBloomEnabled;
    vt.SetBloomEnabled = SetBloomEnabled;
    vt.GetBloomThreshold = GetBloomThreshold;
    vt.SetBloomThreshold = SetBloomThreshold;
    vt.GetBloomRadius = GetBloomRadius;
    vt.SetBloomRadius = SetBloomRadius;
    vt.GetVignetteAmount = GetVignetteAmount;
    vt.SetVignetteAmount = SetVignetteAmount;
    vt.GetLevelOffset = GetLevelOffset;
    vt.SetLevelOffset = SetLevelOffset;
    vt.GetRedLevelOffset = GetRedLevelOffset;
    vt.SetRedLevelOffset = SetRedLevelOffset;
    vt.GetGreenLevelOffset = GetGreenLevelOffset;
    vt.SetGreenLevelOffset = SetGreenLevelOffset;
    vt.GetBlueLevelOffset = GetBlueLevelOffset;
    vt.SetBlueLevelOffset = SetBlueLevelOffset;
    vt.GetInputBlackLevel = GetInputBlackLevel;
    vt.SetInputBlackLevel = SetInputBlackLevel;
    vt.GetInputGrayLevel = GetInputGrayLevel;
    vt.GetInvInputGrayLevel = GetInvInputGrayLevel;
    vt.SetInputGrayLevel = SetInputGrayLevel;
    vt.GetInputWhiteLevel = GetInputWhiteLevel;
    vt.SetInputWhiteLevel = SetInputWhiteLevel;
    vt.GetInputMinRedLevel = GetInputMinRedLevel;
    vt.SetInputMinRedLevel = SetInputMinRedLevel;
    vt.GetInputRedGrayLevel = GetInputRedGrayLevel;
    vt.GetInvInputRedGrayLevel = GetInvInputRedGrayLevel;
    vt.SetInputRedGrayLevel = SetInputRedGrayLevel;
    vt.GetInputMaxRedLevel = GetInputMaxRedLevel;
    vt.SetInputMaxRedLevel = SetInputMaxRedLevel;
    vt.GetInputMinGreenLevel = GetInputMinGreenLevel;
    vt.SetInputMinGreenLevel = SetInputMinGreenLevel;
    vt.GetInputGreenGrayLevel = GetInputGreenGrayLevel;
    vt.GetInvInputGreenGrayLevel = GetInvInputGreenGrayLevel;
    vt.SetInputGreenGrayLevel = SetInputGreenGrayLevel;
    vt.GetInputMaxGreenLevel = GetInputMaxGreenLevel;
    vt.SetInputMaxGreenLevel = SetInputMaxGreenLevel;
    vt.GetInputMinBlueLevel = GetInputMinBlueLevel;
    vt.SetInputMinBlueLevel = SetInputMinBlueLevel;
    vt.GetInputBlueGrayLevel = GetInputBlueGrayLevel;
    vt.GetInvInputBlueGrayLevel = GetInvInputBlueGrayLevel;
    vt.SetInputBlueGrayLevel = SetInputBlueGrayLevel;
    vt.GetInputMaxBlueLevel = GetInputMaxBlueLevel;
    vt.SetInputMaxBlueLevel = SetInputMaxBlueLevel;
    vt.GetToneMapping = GetToneMapping;
    vt.SetToneMapping = SetToneMapping;
    vt.GetHueOffset = GetHueOffset;
    vt.SetHueOffset = SetHueOffset;
    vt.GetSaturation = GetSaturation;
    vt.SetSaturation = SetSaturation;
    vt.GetColorization = GetColorization;
    vt.SetColorization = SetColorization;
    vt.GetTargetColor = GetTargetColor;
    vt.SetTargetColor = SetTargetColor;
    vt.GetOutputBlackLevel = GetOutputBlackLevel;
    vt.SetOutputBlackLevel = SetOutputBlackLevel;
    vt.GetOutputWhiteLevel = GetOutputWhiteLevel;
    vt.SetOutputWhiteLevel = SetOutputWhiteLevel;
    vt.GetOutputMinRedLevel = GetOutputMinRedLevel;
    vt.SetOutputMinRedLevel = SetOutputMinRedLevel;
    vt.GetOutputMaxRedLevel = GetOutputMaxRedLevel;
    vt.SetOutputMaxRedLevel = SetOutputMaxRedLevel;
    vt.GetOutputMinGreenLevel = GetOutputMinGreenLevel;
    vt.SetOutputMinGreenLevel = SetOutputMinGreenLevel;
    vt.GetOutputMaxGreenLevel = GetOutputMaxGreenLevel;
    vt.SetOutputMaxGreenLevel = SetOutputMaxGreenLevel;
    vt.GetOutputMinBlueLevel = GetOutputMinBlueLevel;
    vt.SetOutputMinBlueLevel = SetOutputMinBlueLevel;
    vt.GetOutputMaxBlueLevel = GetOutputMaxBlueLevel;
    vt.SetOutputMaxBlueLevel = SetOutputMaxBlueLevel;
    vt.GetOutputGamma = GetOutputGamma;
    vt.GetOutputInvGamma = GetOutputInvGamma;
    vt.SetOutputGamma = SetOutputGamma;
    vt.AddAttribute = AddAttribute;
    vTable = &vt.iunk;
    iid = &lx::guid_FrameBuffer;
  }
};
class CLxLoc_FrameBuffer : public CLxLocalize<ILxFrameBufferID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_FrameBuffer() {_init();}
  CLxLoc_FrameBuffer(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_FrameBuffer(const CLxLoc_FrameBuffer &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_FrameBuffer;}
    ILxBufferID
  Allocate (const char *name, ILxUnknownID item, const char *identity, const char *userName, int isFactoryName, int writeBucketsToDisk)
  {
    return m_loc[0]->Allocate (m_loc,name,(ILxUnknownID)item,identity,userName,isFactoryName,writeBucketsToDisk);
  }
    LxResult
  IsStereo (int *isStereo) const
  {
    return m_loc[0]->IsStereo (m_loc,isStereo);
  }
    LxResult
  GetStereoEyeDisplay (LXtStereoEye *eyeDisplay) const
  {
    return m_loc[0]->GetStereoEyeDisplay (m_loc,eyeDisplay);
  }
    LxResult
  SetStereoEyeDisplay (LXtStereoEye eyeDisplay)
  {
    return m_loc[0]->SetStereoEyeDisplay (m_loc,eyeDisplay);
  }
    LxResult
  GetStereoComposite (LXtStereoComposite *composite) const
  {
    return m_loc[0]->GetStereoComposite (m_loc,composite);
  }
    LxResult
  SetStereoComposite (LXtStereoComposite composite)
  {
    return m_loc[0]->SetStereoComposite (m_loc,composite);
  }
    LxResult
  SetEyeSide (int eyeSide)
  {
    return m_loc[0]->SetEyeSide (m_loc,eyeSide);
  }
    LxResult
  GetLineBuffer (float **buf)
  {
    return m_loc[0]->GetLineBuffer (m_loc,buf);
  }
    LxResult
  CreateFrameBufferTargetImage (LXtPixelFormat type, int w, int h, void **ppvObj)
  {
    return m_loc[0]->CreateFrameBufferTargetImage (m_loc,type,w,h,ppvObj);
  }
    LxResult
  GetRenderPassName (char *name)
  {
    return m_loc[0]->GetRenderPassName (m_loc,name);
  }
    LxResult
  SetRenderPassName (const char *name)
  {
    return m_loc[0]->SetRenderPassName (m_loc,name);
  }
    unsigned int
  BucketsOnDisk (int index)
  {
    return m_loc[0]->BucketsOnDisk (m_loc,index);
  }
    ILxUnknownID
  Lookup (const char *name, ILxUnknownID item) const
  {
    return (ILxUnknownID) m_loc[0]->Lookup (m_loc,name,(ILxUnknownID)item);
  }
    ILxUnknownID
  LookupByIdentity (const char *identity)
  {
    return (ILxUnknownID) m_loc[0]->LookupByIdentity (m_loc,identity);
  }
    unsigned int
  Count (void) const
  {
    return m_loc[0]->Count (m_loc);
  }
    ILxUnknownID
  ByIndex (int index) const
  {
    return (ILxUnknownID) m_loc[0]->ByIndex (m_loc,index);
  }
    ILxUnknownID
  Alpha (int index) const
  {
    return (ILxUnknownID) m_loc[0]->Alpha (m_loc,index);
  }
    int
  AlphaIndex (int index)
  {
    return m_loc[0]->AlphaIndex (m_loc,index);
  }
    LxResult
  Size (int index, int *width, int *height)
  {
    return m_loc[0]->Size (m_loc,index,width,height);
  }
    LxResult
  AreaProcessingActive (int bufferIndex, int *active)
  {
    return m_loc[0]->AreaProcessingActive (m_loc,bufferIndex,active);
  }
    int
  GetSaveProcessed (int bufferIndex)
  {
    return m_loc[0]->GetSaveProcessed (m_loc,bufferIndex);
  }
    LxResult
  SetSaveProcessed (int bufferIndex, int enabled)
  {
    return m_loc[0]->SetSaveProcessed (m_loc,bufferIndex,enabled);
  }
    int
  GetBloomEnabled (int bufferIndex)
  {
    return m_loc[0]->GetBloomEnabled (m_loc,bufferIndex);
  }
    LxResult
  SetBloomEnabled (int bufferIndex, int enabled)
  {
    return m_loc[0]->SetBloomEnabled (m_loc,bufferIndex,enabled);
  }
    double
  GetBloomThreshold (int bufferIndex)
  {
    return m_loc[0]->GetBloomThreshold (m_loc,bufferIndex);
  }
    LxResult
  SetBloomThreshold (int bufferIndex, double threshold)
  {
    return m_loc[0]->SetBloomThreshold (m_loc,bufferIndex,threshold);
  }
    double
  GetBloomRadius (int bufferIndex)
  {
    return m_loc[0]->GetBloomRadius (m_loc,bufferIndex);
  }
    LxResult
  SetBloomRadius (int bufferIndex, double radius)
  {
    return m_loc[0]->SetBloomRadius (m_loc,bufferIndex,radius);
  }
    double
  GetVignetteAmount (int bufferIndex)
  {
    return m_loc[0]->GetVignetteAmount (m_loc,bufferIndex);
  }
    LxResult
  SetVignetteAmount (int bufferIndex, double radius)
  {
    return m_loc[0]->SetVignetteAmount (m_loc,bufferIndex,radius);
  }
    double
  GetLevelOffset (int bufferIndex)
  {
    return m_loc[0]->GetLevelOffset (m_loc,bufferIndex);
  }
    LxResult
  SetLevelOffset (int bufferIndex, double offset)
  {
    return m_loc[0]->SetLevelOffset (m_loc,bufferIndex,offset);
  }
    double
  GetRedLevelOffset (int bufferIndex)
  {
    return m_loc[0]->GetRedLevelOffset (m_loc,bufferIndex);
  }
    LxResult
  SetRedLevelOffset (int bufferIndex, double offset)
  {
    return m_loc[0]->SetRedLevelOffset (m_loc,bufferIndex,offset);
  }
    double
  GetGreenLevelOffset (int bufferIndex)
  {
    return m_loc[0]->GetGreenLevelOffset (m_loc,bufferIndex);
  }
    LxResult
  SetGreenLevelOffset (int bufferIndex, double offset)
  {
    return m_loc[0]->SetGreenLevelOffset (m_loc,bufferIndex,offset);
  }
    double
  GetBlueLevelOffset (int bufferIndex)
  {
    return m_loc[0]->GetBlueLevelOffset (m_loc,bufferIndex);
  }
    LxResult
  SetBlueLevelOffset (int bufferIndex, double offset)
  {
    return m_loc[0]->SetBlueLevelOffset (m_loc,bufferIndex,offset);
  }
    double
  GetInputBlackLevel (int bufferIndex)
  {
    return m_loc[0]->GetInputBlackLevel (m_loc,bufferIndex);
  }
    LxResult
  SetInputBlackLevel (int bufferIndex, double blackLevel)
  {
    return m_loc[0]->SetInputBlackLevel (m_loc,bufferIndex,blackLevel);
  }
    double
  GetInputGrayLevel (int bufferIndex)
  {
    return m_loc[0]->GetInputGrayLevel (m_loc,bufferIndex);
  }
    double
  GetInvInputGrayLevel (int bufferIndex)
  {
    return m_loc[0]->GetInvInputGrayLevel (m_loc,bufferIndex);
  }
    LxResult
  SetInputGrayLevel (int bufferIndex, double gamma)
  {
    return m_loc[0]->SetInputGrayLevel (m_loc,bufferIndex,gamma);
  }
    double
  GetInputWhiteLevel (int bufferIndex)
  {
    return m_loc[0]->GetInputWhiteLevel (m_loc,bufferIndex);
  }
    LxResult
  SetInputWhiteLevel (int bufferIndex, double whiteLevel)
  {
    return m_loc[0]->SetInputWhiteLevel (m_loc,bufferIndex,whiteLevel);
  }
    double
  GetInputMinRedLevel (int bufferIndex)
  {
    return m_loc[0]->GetInputMinRedLevel (m_loc,bufferIndex);
  }
    LxResult
  SetInputMinRedLevel (int bufferIndex, double level)
  {
    return m_loc[0]->SetInputMinRedLevel (m_loc,bufferIndex,level);
  }
    double
  GetInputRedGrayLevel (int bufferIndex)
  {
    return m_loc[0]->GetInputRedGrayLevel (m_loc,bufferIndex);
  }
    double
  GetInvInputRedGrayLevel (int bufferIndex)
  {
    return m_loc[0]->GetInvInputRedGrayLevel (m_loc,bufferIndex);
  }
    LxResult
  SetInputRedGrayLevel (int bufferIndex, double gamma)
  {
    return m_loc[0]->SetInputRedGrayLevel (m_loc,bufferIndex,gamma);
  }
    double
  GetInputMaxRedLevel (int bufferIndex)
  {
    return m_loc[0]->GetInputMaxRedLevel (m_loc,bufferIndex);
  }
    LxResult
  SetInputMaxRedLevel (int bufferIndex, double level)
  {
    return m_loc[0]->SetInputMaxRedLevel (m_loc,bufferIndex,level);
  }
    double
  GetInputMinGreenLevel (int bufferIndex)
  {
    return m_loc[0]->GetInputMinGreenLevel (m_loc,bufferIndex);
  }
    LxResult
  SetInputMinGreenLevel (int bufferIndex, double level)
  {
    return m_loc[0]->SetInputMinGreenLevel (m_loc,bufferIndex,level);
  }
    double
  GetInputGreenGrayLevel (int bufferIndex)
  {
    return m_loc[0]->GetInputGreenGrayLevel (m_loc,bufferIndex);
  }
    double
  GetInvInputGreenGrayLevel (int bufferIndex)
  {
    return m_loc[0]->GetInvInputGreenGrayLevel (m_loc,bufferIndex);
  }
    LxResult
  SetInputGreenGrayLevel (int bufferIndex, double gamma)
  {
    return m_loc[0]->SetInputGreenGrayLevel (m_loc,bufferIndex,gamma);
  }
    double
  GetInputMaxGreenLevel (int bufferIndex)
  {
    return m_loc[0]->GetInputMaxGreenLevel (m_loc,bufferIndex);
  }
    LxResult
  SetInputMaxGreenLevel (int bufferIndex, double level)
  {
    return m_loc[0]->SetInputMaxGreenLevel (m_loc,bufferIndex,level);
  }
    double
  GetInputMinBlueLevel (int bufferIndex)
  {
    return m_loc[0]->GetInputMinBlueLevel (m_loc,bufferIndex);
  }
    LxResult
  SetInputMinBlueLevel (int bufferIndex, double level)
  {
    return m_loc[0]->SetInputMinBlueLevel (m_loc,bufferIndex,level);
  }
    double
  GetInputBlueGrayLevel (int bufferIndex)
  {
    return m_loc[0]->GetInputBlueGrayLevel (m_loc,bufferIndex);
  }
    double
  GetInvInputBlueGrayLevel (int bufferIndex)
  {
    return m_loc[0]->GetInvInputBlueGrayLevel (m_loc,bufferIndex);
  }
    LxResult
  SetInputBlueGrayLevel (int bufferIndex, double gamma)
  {
    return m_loc[0]->SetInputBlueGrayLevel (m_loc,bufferIndex,gamma);
  }
    double
  GetInputMaxBlueLevel (int bufferIndex)
  {
    return m_loc[0]->GetInputMaxBlueLevel (m_loc,bufferIndex);
  }
    LxResult
  SetInputMaxBlueLevel (int bufferIndex, double level)
  {
    return m_loc[0]->SetInputMaxBlueLevel (m_loc,bufferIndex,level);
  }
    double
  GetToneMapping (int bufferIndex)
  {
    return m_loc[0]->GetToneMapping (m_loc,bufferIndex);
  }
    LxResult
  SetToneMapping (int bufferIndex, double toneMapping)
  {
    return m_loc[0]->SetToneMapping (m_loc,bufferIndex,toneMapping);
  }
    double
  GetHueOffset (int bufferIndex)
  {
    return m_loc[0]->GetHueOffset (m_loc,bufferIndex);
  }
    LxResult
  SetHueOffset (int bufferIndex, double hueOffset)
  {
    return m_loc[0]->SetHueOffset (m_loc,bufferIndex,hueOffset);
  }
    double
  GetSaturation (int bufferIndex)
  {
    return m_loc[0]->GetSaturation (m_loc,bufferIndex);
  }
    LxResult
  SetSaturation (int bufferIndex, double saturation)
  {
    return m_loc[0]->SetSaturation (m_loc,bufferIndex,saturation);
  }
    double
  GetColorization (int bufferIndex)
  {
    return m_loc[0]->GetColorization (m_loc,bufferIndex);
  }
    LxResult
  SetColorization (int bufferIndex, double colorization)
  {
    return m_loc[0]->SetColorization (m_loc,bufferIndex,colorization);
  }
    void
  GetTargetColor (int bufferIndex, double *color)
  {
    m_loc[0]->GetTargetColor (m_loc,bufferIndex,color);
  }
    LxResult
  SetTargetColor (int bufferIndex, const double *color)
  {
    return m_loc[0]->SetTargetColor (m_loc,bufferIndex,color);
  }
    double
  GetOutputBlackLevel (int bufferIndex)
  {
    return m_loc[0]->GetOutputBlackLevel (m_loc,bufferIndex);
  }
    LxResult
  SetOutputBlackLevel (int bufferIndex, double blackLevel)
  {
    return m_loc[0]->SetOutputBlackLevel (m_loc,bufferIndex,blackLevel);
  }
    double
  GetOutputWhiteLevel (int bufferIndex)
  {
    return m_loc[0]->GetOutputWhiteLevel (m_loc,bufferIndex);
  }
    LxResult
  SetOutputWhiteLevel (int bufferIndex, double whiteLevel)
  {
    return m_loc[0]->SetOutputWhiteLevel (m_loc,bufferIndex,whiteLevel);
  }
    double
  GetOutputMinRedLevel (int bufferIndex)
  {
    return m_loc[0]->GetOutputMinRedLevel (m_loc,bufferIndex);
  }
    LxResult
  SetOutputMinRedLevel (int bufferIndex, double blackLevel)
  {
    return m_loc[0]->SetOutputMinRedLevel (m_loc,bufferIndex,blackLevel);
  }
    double
  GetOutputMaxRedLevel (int bufferIndex)
  {
    return m_loc[0]->GetOutputMaxRedLevel (m_loc,bufferIndex);
  }
    LxResult
  SetOutputMaxRedLevel (int bufferIndex, double whiteLevel)
  {
    return m_loc[0]->SetOutputMaxRedLevel (m_loc,bufferIndex,whiteLevel);
  }
    double
  GetOutputMinGreenLevel (int bufferIndex)
  {
    return m_loc[0]->GetOutputMinGreenLevel (m_loc,bufferIndex);
  }
    LxResult
  SetOutputMinGreenLevel (int bufferIndex, double blackLevel)
  {
    return m_loc[0]->SetOutputMinGreenLevel (m_loc,bufferIndex,blackLevel);
  }
    double
  GetOutputMaxGreenLevel (int bufferIndex)
  {
    return m_loc[0]->GetOutputMaxGreenLevel (m_loc,bufferIndex);
  }
    LxResult
  SetOutputMaxGreenLevel (int bufferIndex, double whiteLevel)
  {
    return m_loc[0]->SetOutputMaxGreenLevel (m_loc,bufferIndex,whiteLevel);
  }
    double
  GetOutputMinBlueLevel (int bufferIndex)
  {
    return m_loc[0]->GetOutputMinBlueLevel (m_loc,bufferIndex);
  }
    LxResult
  SetOutputMinBlueLevel (int bufferIndex, double blackLevel)
  {
    return m_loc[0]->SetOutputMinBlueLevel (m_loc,bufferIndex,blackLevel);
  }
    double
  GetOutputMaxBlueLevel (int bufferIndex)
  {
    return m_loc[0]->GetOutputMaxBlueLevel (m_loc,bufferIndex);
  }
    LxResult
  SetOutputMaxBlueLevel (int bufferIndex, double whiteLevel)
  {
    return m_loc[0]->SetOutputMaxBlueLevel (m_loc,bufferIndex,whiteLevel);
  }
    double
  GetOutputGamma (int bufferIndex)
  {
    return m_loc[0]->GetOutputGamma (m_loc,bufferIndex);
  }
    double
  GetOutputInvGamma (int bufferIndex)
  {
    return m_loc[0]->GetOutputInvGamma (m_loc,bufferIndex);
  }
    LxResult
  SetOutputGamma (int bufferIndex, double gamma)
  {
    return m_loc[0]->SetOutputGamma (m_loc,bufferIndex,gamma);
  }
    LxResult
  AddAttribute (const char *name, const char *type, unsigned *index)
  {
    return m_loc[0]->AddAttribute (m_loc,name,type,index);
  }
};

class CLxLoc_ImageProcessingService : public CLxLocalizedService
{
  ILxImageProcessingServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_ImageProcessingService() {_init();set();}
 ~CLxLoc_ImageProcessingService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxImageProcessingServiceID>(lx::GetGlobal(&lx::guid_ImageProcessingService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  Create (void **ppvObj)
  {
    return m_loc[0]->Create (m_loc,ppvObj);
  }
    bool
  Create (CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Create (m_loc,&obj)) && dest.take(obj);
  }
};

class CLxImpl_ImageProcessingListener {
  public:
    virtual ~CLxImpl_ImageProcessingListener() {}
    virtual LxResult
      improl_Changed (const char *identifier, int eventCode)
        { return LXe_NOTIMPL; }
    virtual LxResult
      improl_Reset (const char *identifier)
        { return LXe_NOTIMPL; }
};
#define LXxD_ImageProcessingListener_Changed LxResult improl_Changed (const char *identifier, int eventCode)
#define LXxO_ImageProcessingListener_Changed LXxD_ImageProcessingListener_Changed LXx_OVERRIDE
#define LXxD_ImageProcessingListener_Reset LxResult improl_Reset (const char *identifier)
#define LXxO_ImageProcessingListener_Reset LXxD_ImageProcessingListener_Reset LXx_OVERRIDE
template <class T>
class CLxIfc_ImageProcessingListener : public CLxInterface
{
    static LxResult
  Changed (LXtObjectID wcom, const char *identifier, int eventCode)
  {
    LXCWxINST (CLxImpl_ImageProcessingListener, loc);
    try {
      return loc->improl_Changed (identifier,eventCode);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Reset (LXtObjectID wcom, const char *identifier)
  {
    LXCWxINST (CLxImpl_ImageProcessingListener, loc);
    try {
      return loc->improl_Reset (identifier);
    } catch (LxResult rc) { return rc; }
  }
  ILxImageProcessingListener vt;
public:
  CLxIfc_ImageProcessingListener ()
  {
    vt.Changed = Changed;
    vt.Reset = Reset;
    vTable = &vt.iunk;
    iid = &lx::guid_ImageProcessingListener;
  }
};
class CLxLoc_ImageProcessingListener : public CLxLocalize<ILxImageProcessingListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ImageProcessingListener() {_init();}
  CLxLoc_ImageProcessingListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ImageProcessingListener(const CLxLoc_ImageProcessingListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ImageProcessingListener;}
    LxResult
  Changed (const char *identifier, int eventCode)
  {
    return m_loc[0]->Changed (m_loc,identifier,eventCode);
  }
    LxResult
  Reset (const char *identifier)
  {
    return m_loc[0]->Reset (m_loc,identifier);
  }
};

class CLxLoc_RenderStats : public CLxLocalize<ILxRenderStatsID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_RenderStats() {_init();}
  CLxLoc_RenderStats(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_RenderStats(const CLxLoc_RenderStats &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_RenderStats;}
    LxResult
  NumFrames (int *count)
  {
    return m_loc[0]->NumFrames (m_loc,count);
  }
    LxResult
  NumPasses (int frameIndex, int *count)
  {
    return m_loc[0]->NumPasses (m_loc,frameIndex,count);
  }
    LxResult
  GetPassStats (int frameIndex, int passIndex, void **ppvObj)
  {
    return m_loc[0]->GetPassStats (m_loc,frameIndex,passIndex,ppvObj);
  }
    LxResult
  GetFrameStats (int frameIndex, void **ppvObj)
  {
    return m_loc[0]->GetFrameStats (m_loc,frameIndex,ppvObj);
  }
    LxResult
  GetSceneStats (void **ppvObj)
  {
    return m_loc[0]->GetSceneStats (m_loc,ppvObj);
  }
};

#endif

