/*
 * C++ wrapper for lxvolume.h
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
#ifndef LXW_VOLUME_HPP
#define LXW_VOLUME_HPP

#include <lxvolume.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_Raymarch = {0x1E84C5A8,0xC002,0x4120,0xBA,0xB0,0x9E,0xEB,0x17,0x22,0x68,0x8B};
};

class CLxImpl_Raymarch {
  public:
    virtual ~CLxImpl_Raymarch() {}
    virtual LxResult
      rmrch_AddVolume (ILxUnknownID vector, LXtVolumeSample *vs)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rmrch_AddSurface (ILxUnknownID vector, LXtSurfFragment *ss)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rmrch_GetOpacity (ILxUnknownID vector, double dist, double *opa)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rmrch_ShaderEvaluate (ILxUnknownID vector, ILxUnknownID shader)
        { return LXe_NOTIMPL; }
    virtual LxResult
      rmrch_Jitter1D (ILxUnknownID vector, float *offset)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_Raymarch : public CLxInterface
{
    static LxResult
  AddVolume (LXtObjectID wcom, LXtObjectID vector, LXtVolumeSample *vs)
  {
    LXCWxINST (CLxImpl_Raymarch, loc);
    try {
      return loc->rmrch_AddVolume ((ILxUnknownID)vector,vs);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddSurface (LXtObjectID wcom, LXtObjectID vector, LXtSurfFragment *ss)
  {
    LXCWxINST (CLxImpl_Raymarch, loc);
    try {
      return loc->rmrch_AddSurface ((ILxUnknownID)vector,ss);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetOpacity (LXtObjectID wcom, LXtObjectID vector, double dist, double *opa)
  {
    LXCWxINST (CLxImpl_Raymarch, loc);
    try {
      return loc->rmrch_GetOpacity ((ILxUnknownID)vector,dist,opa);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ShaderEvaluate (LXtObjectID wcom, LXtObjectID vector, LXtObjectID shader)
  {
    LXCWxINST (CLxImpl_Raymarch, loc);
    try {
      return loc->rmrch_ShaderEvaluate ((ILxUnknownID)vector,(ILxUnknownID)shader);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Jitter1D (LXtObjectID wcom, LXtObjectID vector, float *offset)
  {
    LXCWxINST (CLxImpl_Raymarch, loc);
    try {
      return loc->rmrch_Jitter1D ((ILxUnknownID)vector,offset);
    } catch (LxResult rc) { return rc; }
  }
  ILxRaymarch vt;
public:
  CLxIfc_Raymarch ()
  {
    vt.AddVolume = AddVolume;
    vt.AddSurface = AddSurface;
    vt.GetOpacity = GetOpacity;
    vt.ShaderEvaluate = ShaderEvaluate;
    vt.Jitter1D = Jitter1D;
    vTable = &vt.iunk;
    iid = &lx::guid_Raymarch;
  }
};
class CLxLoc_Raymarch : public CLxLocalize<ILxRaymarchID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Raymarch() {_init();}
  CLxLoc_Raymarch(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Raymarch(const CLxLoc_Raymarch &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Raymarch;}
    LxResult
  AddVolume (ILxUnknownID vector, LXtVolumeSample *vs)
  {
    return m_loc[0]->AddVolume (m_loc,(ILxUnknownID)vector,vs);
  }
    LxResult
  AddSurface (ILxUnknownID vector, LXtSurfFragment *ss)
  {
    return m_loc[0]->AddSurface (m_loc,(ILxUnknownID)vector,ss);
  }
    LxResult
  GetOpacity (ILxUnknownID vector, double dist, double *opa)
  {
    return m_loc[0]->GetOpacity (m_loc,(ILxUnknownID)vector,dist,opa);
  }
    LxResult
  ShaderEvaluate (ILxUnknownID vector, ILxUnknownID shader)
  {
    return m_loc[0]->ShaderEvaluate (m_loc,(ILxUnknownID)vector,(ILxUnknownID)shader);
  }
    LxResult
  Jitter1D (ILxUnknownID vector, float *offset)
  {
    return m_loc[0]->Jitter1D (m_loc,(ILxUnknownID)vector,offset);
  }
};

#endif

