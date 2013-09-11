/*
 * C++ wrapper for lxlocator.h
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
#ifndef LXW_LOCATOR_HPP
#define LXW_LOCATOR_HPP

#include <lxlocator.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_Locator = {0x50DCCB9D,0x9856,0x4A33,0x9B,0xDA,0xDA,0xF3,0xA7,0x1B,0xBD,0x2D};
};

class CLxImpl_Locator {
  public:
    virtual ~CLxImpl_Locator() {}
    virtual LxResult
      loc_Visible (ILxUnknownID chanRead)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_WorldTransform (ILxUnknownID chanRead, LXtMatrix xfrm, LXtVector pos)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_GetTransformItem (LXtTransformType type, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_AddTransformItem (LXtTransformType type, void **ppvObj, unsigned *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_SetTransformVector (ILxUnknownID chanWrite, LXtTransformType type, LXtVector value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_AddPreTransformItem (ILxUnknownID chanWrite, LXtTransformType type, LXtVector value, void **ppvObj, unsigned *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_AddPostTransformItem (ILxUnknownID chanWrite, LXtTransformType type, LXtVector value, void **ppvObj, unsigned *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_SetTarget (ILxUnknownID target, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_PrependTransformItem (ILxUnknownID chanWrite, LXtTransformType type, LXtVector value, void **ppvObj, unsigned *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_AppendTransformItem (ILxUnknownID chanWrite, LXtTransformType type, LXtVector value, void **ppvObj, unsigned *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_SetPosition (ILxUnknownID chanRead, ILxUnknownID chanWrite, LXtVector pos, unsigned type, unsigned comp)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_SetRotation (ILxUnknownID chanRead, ILxUnknownID chanWrite, LXtMatrix m3, unsigned type, unsigned comp)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_SetScale (ILxUnknownID chanRead, ILxUnknownID chanWrite, LXtMatrix4 m4, unsigned type, unsigned comp)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_ExtractLocalPosition (ILxUnknownID chanRead, LXtVector pos)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_ExtractLocalRotation (ILxUnknownID chanRead, LXtMatrix m3)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_ZeroTransform (ILxUnknownID chanRead, ILxUnknownID chanWrite, LXtTransformType type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_WorldTransform4 (ILxUnknownID chanRead, LXtMatrix4 xfrm4)
        { return LXe_NOTIMPL; }
    virtual LxResult
      loc_WorldInvertTransform (ILxUnknownID chanRead, LXtMatrix xfrm, LXtVector pos)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_Locator : public CLxInterface
{
    static LxResult
  Visible (LXtObjectID wcom, LXtObjectID chanRead)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_Visible ((ILxUnknownID)chanRead);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  WorldTransform (LXtObjectID wcom, LXtObjectID chanRead, LXtMatrix xfrm, LXtVector pos)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_WorldTransform ((ILxUnknownID)chanRead,xfrm,pos);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetTransformItem (LXtObjectID wcom, LXtTransformType type, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_GetTransformItem (type,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddTransformItem (LXtObjectID wcom, LXtTransformType type, void **ppvObj, unsigned *index)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_AddTransformItem (type,ppvObj,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetTransformVector (LXtObjectID wcom, LXtObjectID chanWrite, LXtTransformType type, LXtVector value)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_SetTransformVector ((ILxUnknownID)chanWrite,type,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddPreTransformItem (LXtObjectID wcom, LXtObjectID chanWrite, LXtTransformType type, LXtVector value, void **ppvObj, unsigned *index)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_AddPreTransformItem ((ILxUnknownID)chanWrite,type,value,ppvObj,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddPostTransformItem (LXtObjectID wcom, LXtObjectID chanWrite, LXtTransformType type, LXtVector value, void **ppvObj, unsigned *index)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_AddPostTransformItem ((ILxUnknownID)chanWrite,type,value,ppvObj,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetTarget (LXtObjectID wcom, LXtObjectID target, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_SetTarget ((ILxUnknownID)target,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PrependTransformItem (LXtObjectID wcom, LXtObjectID chanWrite, LXtTransformType type, LXtVector value, void **ppvObj, unsigned *index)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_PrependTransformItem ((ILxUnknownID)chanWrite,type,value,ppvObj,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AppendTransformItem (LXtObjectID wcom, LXtObjectID chanWrite, LXtTransformType type, LXtVector value, void **ppvObj, unsigned *index)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_AppendTransformItem ((ILxUnknownID)chanWrite,type,value,ppvObj,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetPosition (LXtObjectID wcom, LXtObjectID chanRead, LXtObjectID chanWrite, LXtVector pos, unsigned type, unsigned comp)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_SetPosition ((ILxUnknownID)chanRead,(ILxUnknownID)chanWrite,pos,type,comp);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetRotation (LXtObjectID wcom, LXtObjectID chanRead, LXtObjectID chanWrite, LXtMatrix m3, unsigned type, unsigned comp)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_SetRotation ((ILxUnknownID)chanRead,(ILxUnknownID)chanWrite,m3,type,comp);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetScale (LXtObjectID wcom, LXtObjectID chanRead, LXtObjectID chanWrite, LXtMatrix4 m4, unsigned type, unsigned comp)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_SetScale ((ILxUnknownID)chanRead,(ILxUnknownID)chanWrite,m4,type,comp);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ExtractLocalPosition (LXtObjectID wcom, LXtObjectID chanRead, LXtVector pos)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_ExtractLocalPosition ((ILxUnknownID)chanRead,pos);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ExtractLocalRotation (LXtObjectID wcom, LXtObjectID chanRead, LXtMatrix m3)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_ExtractLocalRotation ((ILxUnknownID)chanRead,m3);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ZeroTransform (LXtObjectID wcom, LXtObjectID chanRead, LXtObjectID chanWrite, LXtTransformType type)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_ZeroTransform ((ILxUnknownID)chanRead,(ILxUnknownID)chanWrite,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  WorldTransform4 (LXtObjectID wcom, LXtObjectID chanRead, LXtMatrix4 xfrm4)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_WorldTransform4 ((ILxUnknownID)chanRead,xfrm4);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  WorldInvertTransform (LXtObjectID wcom, LXtObjectID chanRead, LXtMatrix xfrm, LXtVector pos)
  {
    LXCWxINST (CLxImpl_Locator, loc);
    try {
      return loc->loc_WorldInvertTransform ((ILxUnknownID)chanRead,xfrm,pos);
    } catch (LxResult rc) { return rc; }
  }
  ILxLocator vt;
public:
  CLxIfc_Locator ()
  {
    vt.Visible = Visible;
    vt.WorldTransform = WorldTransform;
    vt.GetTransformItem = GetTransformItem;
    vt.AddTransformItem = AddTransformItem;
    vt.SetTransformVector = SetTransformVector;
    vt.AddPreTransformItem = AddPreTransformItem;
    vt.AddPostTransformItem = AddPostTransformItem;
    vt.SetTarget = SetTarget;
    vt.PrependTransformItem = PrependTransformItem;
    vt.AppendTransformItem = AppendTransformItem;
    vt.SetPosition = SetPosition;
    vt.SetRotation = SetRotation;
    vt.SetScale = SetScale;
    vt.ExtractLocalPosition = ExtractLocalPosition;
    vt.ExtractLocalRotation = ExtractLocalRotation;
    vt.ZeroTransform = ZeroTransform;
    vt.WorldTransform4 = WorldTransform4;
    vt.WorldInvertTransform = WorldInvertTransform;
    vTable = &vt.iunk;
    iid = &lx::guid_Locator;
  }
};
class CLxLoc_Locator : public CLxLocalize<ILxLocatorID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Locator() {_init();}
  CLxLoc_Locator(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Locator(const CLxLoc_Locator &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Locator;}
    LxResult
  Visible (ILxUnknownID chanRead) const
  {
    return m_loc[0]->Visible (m_loc,(ILxUnknownID)chanRead);
  }
    LxResult
  WorldTransform (ILxUnknownID chanRead, LXtMatrix xfrm, LXtVector pos) const
  {
    return m_loc[0]->WorldTransform (m_loc,(ILxUnknownID)chanRead,xfrm,pos);
  }
    LxResult
  GetTransformItem (LXtTransformType type, void **ppvObj) const
  {
    return m_loc[0]->GetTransformItem (m_loc,type,ppvObj);
  }
    LxResult
  AddTransformItem (LXtTransformType type, void **ppvObj, unsigned *index)
  {
    return m_loc[0]->AddTransformItem (m_loc,type,ppvObj,index);
  }
    LxResult
  SetTransformVector (ILxUnknownID chanWrite, LXtTransformType type, LXtVector value)
  {
    return m_loc[0]->SetTransformVector (m_loc,(ILxUnknownID)chanWrite,type,value);
  }
    LxResult
  AddPreTransformItem (ILxUnknownID chanWrite, LXtTransformType type, LXtVector value, void **ppvObj, unsigned *index)
  {
    return m_loc[0]->AddPreTransformItem (m_loc,(ILxUnknownID)chanWrite,type,value,ppvObj,index);
  }
    LxResult
  AddPostTransformItem (ILxUnknownID chanWrite, LXtTransformType type, LXtVector value, void **ppvObj, unsigned *index)
  {
    return m_loc[0]->AddPostTransformItem (m_loc,(ILxUnknownID)chanWrite,type,value,ppvObj,index);
  }
    LxResult
  SetTarget (ILxUnknownID target, void **ppvObj)
  {
    return m_loc[0]->SetTarget (m_loc,(ILxUnknownID)target,ppvObj);
  }
    LxResult
  PrependTransformItem (ILxUnknownID chanWrite, LXtTransformType type, LXtVector value, void **ppvObj, unsigned *index)
  {
    return m_loc[0]->PrependTransformItem (m_loc,(ILxUnknownID)chanWrite,type,value,ppvObj,index);
  }
    LxResult
  AppendTransformItem (ILxUnknownID chanWrite, LXtTransformType type, LXtVector value, void **ppvObj, unsigned *index)
  {
    return m_loc[0]->AppendTransformItem (m_loc,(ILxUnknownID)chanWrite,type,value,ppvObj,index);
  }
    LxResult
  SetPosition (ILxUnknownID chanRead, ILxUnknownID chanWrite, LXtVector pos, unsigned type, unsigned comp)
  {
    return m_loc[0]->SetPosition (m_loc,(ILxUnknownID)chanRead,(ILxUnknownID)chanWrite,pos,type,comp);
  }
    LxResult
  SetRotation (ILxUnknownID chanRead, ILxUnknownID chanWrite, LXtMatrix m3, unsigned type, unsigned comp)
  {
    return m_loc[0]->SetRotation (m_loc,(ILxUnknownID)chanRead,(ILxUnknownID)chanWrite,m3,type,comp);
  }
    LxResult
  SetScale (ILxUnknownID chanRead, ILxUnknownID chanWrite, LXtMatrix4 m4, unsigned type, unsigned comp)
  {
    return m_loc[0]->SetScale (m_loc,(ILxUnknownID)chanRead,(ILxUnknownID)chanWrite,m4,type,comp);
  }
    LxResult
  ExtractLocalPosition (ILxUnknownID chanRead, LXtVector pos)
  {
    return m_loc[0]->ExtractLocalPosition (m_loc,(ILxUnknownID)chanRead,pos);
  }
    LxResult
  ExtractLocalRotation (ILxUnknownID chanRead, LXtMatrix m3)
  {
    return m_loc[0]->ExtractLocalRotation (m_loc,(ILxUnknownID)chanRead,m3);
  }
    LxResult
  ZeroTransform (ILxUnknownID chanRead, ILxUnknownID chanWrite, LXtTransformType type)
  {
    return m_loc[0]->ZeroTransform (m_loc,(ILxUnknownID)chanRead,(ILxUnknownID)chanWrite,type);
  }
    LxResult
  WorldTransform4 (ILxUnknownID chanRead, LXtMatrix4 xfrm4) const
  {
    return m_loc[0]->WorldTransform4 (m_loc,(ILxUnknownID)chanRead,xfrm4);
  }
    LxResult
  WorldInvertTransform (ILxUnknownID chanRead, LXtMatrix xfrm, LXtVector pos)
  {
    return m_loc[0]->WorldInvertTransform (m_loc,(ILxUnknownID)chanRead,xfrm,pos);
  }
};

#endif

