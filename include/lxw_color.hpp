/*
 * C++ wrapper for lxcolor.h
 *
 *	Copyright (c) 2008-2012 Luxology LLC
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
#ifndef LXW_COLOR_HPP
#define LXW_COLOR_HPP

#include <lxcolor.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_ColorModel = {0x67d3d952,0x4ab0,0x49e5,0x8f,0x9e,0x6c,0x88,0x9b,0x00,0xf2,0x53};
};

class CLxImpl_ColorModel {
  public:
    virtual ~CLxImpl_ColorModel() {}
    virtual int
      colm_NumComponents (void)
        = 0;
    virtual LxResult
      colm_ComponentType (unsigned component, const char **type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_ComponentRange (unsigned component, float *min, float *max)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_ToRGB (const float *vector, float *rgb)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_FromRGB (const float *rgb, float *vector)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_DrawSlice (ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float *vec)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_DrawSliceMarker (ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float *downVec, const float *vec)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_CanSliceBeReused (unsigned xAxis, unsigned yAxis, const float *oldVec, const float *newVec)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_ToSlicePos (unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, const float *vec, unsigned *imgX, unsigned *imgY)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_FromSlicePos (unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, unsigned imgX, unsigned imgY, float *downVec, float *vec)
        { return LXe_NOTIMPL; }
    virtual LxResult
      colm_StripBaseVector (unsigned axis, int dynamic, float *vec)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_ColorModel : public CLxInterface
{
    static int
  NumComponents (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    return loc->colm_NumComponents ();
  }
    static LxResult
  ComponentType (LXtObjectID wcom, unsigned component, const char **type)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_ComponentType (component,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ComponentRange (LXtObjectID wcom, unsigned component, float *min, float *max)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_ComponentRange (component,min,max);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToRGB (LXtObjectID wcom, const float *vector, float *rgb)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_ToRGB (vector,rgb);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FromRGB (LXtObjectID wcom, const float *rgb, float *vector)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_FromRGB (rgb,vector);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DrawSlice (LXtObjectID wcom, LXtObjectID image, unsigned xAxis, unsigned yAxis, const float *vec)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_DrawSlice ((ILxUnknownID)image,xAxis,yAxis,vec);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DrawSliceMarker (LXtObjectID wcom, LXtObjectID image, unsigned xAxis, unsigned yAxis, const float *downVec, const float *vec)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_DrawSliceMarker ((ILxUnknownID)image,xAxis,yAxis,downVec,vec);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CanSliceBeReused (LXtObjectID wcom, unsigned xAxis, unsigned yAxis, const float *oldVec, const float *newVec)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_CanSliceBeReused (xAxis,yAxis,oldVec,newVec);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ToSlicePos (LXtObjectID wcom, unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, const float *vec, unsigned *imgX, unsigned *imgY)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_ToSlicePos (xAxis,yAxis,imgW,imgH,vec,imgX,imgY);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FromSlicePos (LXtObjectID wcom, unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, unsigned imgX, unsigned imgY, float *downVec, float *vec)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_FromSlicePos (xAxis,yAxis,imgW,imgH,imgX,imgY,downVec,vec);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  StripBaseVector (LXtObjectID wcom, unsigned axis, int dynamic, float *vec)
  {
    LXCWxINST (CLxImpl_ColorModel, loc);
    try {
      return loc->colm_StripBaseVector (axis,dynamic,vec);
    } catch (LxResult rc) { return rc; }
  }
  ILxColorModel vt;
public:
  CLxIfc_ColorModel ()
  {
    vt.NumComponents = NumComponents;
    vt.ComponentType = ComponentType;
    vt.ComponentRange = ComponentRange;
    vt.ToRGB = ToRGB;
    vt.FromRGB = FromRGB;
    vt.DrawSlice = DrawSlice;
    vt.DrawSliceMarker = DrawSliceMarker;
    vt.CanSliceBeReused = CanSliceBeReused;
    vt.ToSlicePos = ToSlicePos;
    vt.FromSlicePos = FromSlicePos;
    vt.StripBaseVector = StripBaseVector;
    vTable = &vt.iunk;
    iid = &lx::guid_ColorModel;
  }
};
class CLxLoc_ColorModel : public CLxLocalize<ILxColorModelID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ColorModel() {_init();}
  CLxLoc_ColorModel(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ColorModel(const CLxLoc_ColorModel &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ColorModel;}
    int
  NumComponents (void)
  {
    return m_loc[0]->NumComponents (m_loc);
  }
    LxResult
  ComponentType (unsigned component, const char **type)
  {
    return m_loc[0]->ComponentType (m_loc,component,type);
  }
    LxResult
  ComponentRange (unsigned component, float *min, float *max)
  {
    return m_loc[0]->ComponentRange (m_loc,component,min,max);
  }
    LxResult
  ToRGB (const float *vector, float *rgb)
  {
    return m_loc[0]->ToRGB (m_loc,vector,rgb);
  }
    LxResult
  FromRGB (const float *rgb, float *vector)
  {
    return m_loc[0]->FromRGB (m_loc,rgb,vector);
  }
    LxResult
  DrawSlice (ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float *vec)
  {
    return m_loc[0]->DrawSlice (m_loc,(ILxUnknownID)image,xAxis,yAxis,vec);
  }
    LxResult
  DrawSliceMarker (ILxUnknownID image, unsigned xAxis, unsigned yAxis, const float *downVec, const float *vec)
  {
    return m_loc[0]->DrawSliceMarker (m_loc,(ILxUnknownID)image,xAxis,yAxis,downVec,vec);
  }
    LxResult
  CanSliceBeReused (unsigned xAxis, unsigned yAxis, const float *oldVec, const float *newVec)
  {
    return m_loc[0]->CanSliceBeReused (m_loc,xAxis,yAxis,oldVec,newVec);
  }
    LxResult
  ToSlicePos (unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, const float *vec, unsigned *imgX, unsigned *imgY)
  {
    return m_loc[0]->ToSlicePos (m_loc,xAxis,yAxis,imgW,imgH,vec,imgX,imgY);
  }
    LxResult
  FromSlicePos (unsigned xAxis, unsigned yAxis, unsigned imgW, unsigned imgH, unsigned imgX, unsigned imgY, float *downVec, float *vec)
  {
    return m_loc[0]->FromSlicePos (m_loc,xAxis,yAxis,imgW,imgH,imgX,imgY,downVec,vec);
  }
    LxResult
  StripBaseVector (unsigned axis, int dynamic, float *vec)
  {
    return m_loc[0]->StripBaseVector (m_loc,axis,dynamic,vec);
  }
};

#endif

