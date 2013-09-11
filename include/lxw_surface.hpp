/*
 * C++ wrapper for lxsurface.h
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
#ifndef LXW_SURFACE_HPP
#define LXW_SURFACE_HPP

#include <lxsurface.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_Surface = {0x75006BDB,0x93F7,0x4a41,0x8B,0x8C,0xE7,0x10,0xD8,0x0D,0x3F,0x1A};
    static const LXtGUID guid_SurfaceItem = {0x65EC0E0E,0xFFD7,0x48a3,0x9E,0x20,0x62,0xEA,0x82,0xEF,0x47,0x28};
    static const LXtGUID guid_SurfaceBin = {0x48B534C1,0x7B7C,0x4147,0xAD,0xBC,0x15,0x48,0x50,0x89,0x8E,0x7F};
};

class CLxImpl_Surface {
  public:
    virtual ~CLxImpl_Surface() {}
    virtual LxResult
      surf_GetBBox (LXtBBox *bbox)
        { return LXe_NOTIMPL; }
    virtual LxResult
      surf_FrontBBox (LXtVector pos, LXtVector dir, LXtBBox *bbox)
        { return LXe_NOTIMPL; }
    virtual LxResult
      surf_RayCast (const LXtRayInfo *ray, LXtRayHit *hit)
        { return LXe_NOTIMPL; }
    virtual LxResult
      surf_BinCount (unsigned int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      surf_BinByIndex (unsigned int index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      surf_TagCount (LXtID4 type, unsigned int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      surf_TagByIndex (LXtID4 type, unsigned int index, const char **stag)
        { return LXe_NOTIMPL; }
    virtual LxResult
      surf_GLCount (unsigned int *count)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_Surface : public CLxInterface
{
    static LxResult
  GetBBox (LXtObjectID wcom, LXtBBox *bbox)
  {
    LXCWxINST (CLxImpl_Surface, loc);
    try {
      return loc->surf_GetBBox (bbox);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FrontBBox (LXtObjectID wcom, LXtVector pos, LXtVector dir, LXtBBox *bbox)
  {
    LXCWxINST (CLxImpl_Surface, loc);
    try {
      return loc->surf_FrontBBox (pos,dir,bbox);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RayCast (LXtObjectID wcom, const LXtRayInfo *ray, LXtRayHit *hit)
  {
    LXCWxINST (CLxImpl_Surface, loc);
    try {
      return loc->surf_RayCast (ray,hit);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BinCount (LXtObjectID wcom, unsigned int *count)
  {
    LXCWxINST (CLxImpl_Surface, loc);
    try {
      return loc->surf_BinCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  BinByIndex (LXtObjectID wcom, unsigned int index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Surface, loc);
    try {
      return loc->surf_BinByIndex (index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TagCount (LXtObjectID wcom, LXtID4 type, unsigned int *count)
  {
    LXCWxINST (CLxImpl_Surface, loc);
    try {
      return loc->surf_TagCount (type,count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TagByIndex (LXtObjectID wcom, LXtID4 type, unsigned int index, const char **stag)
  {
    LXCWxINST (CLxImpl_Surface, loc);
    try {
      return loc->surf_TagByIndex (type,index,stag);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GLCount (LXtObjectID wcom, unsigned int *count)
  {
    LXCWxINST (CLxImpl_Surface, loc);
    try {
      return loc->surf_GLCount (count);
    } catch (LxResult rc) { return rc; }
  }
  ILxSurface vt;
public:
  CLxIfc_Surface ()
  {
    vt.GetBBox = GetBBox;
    vt.FrontBBox = FrontBBox;
    vt.RayCast = RayCast;
    vt.BinCount = BinCount;
    vt.BinByIndex = BinByIndex;
    vt.TagCount = TagCount;
    vt.TagByIndex = TagByIndex;
    vt.GLCount = GLCount;
    vTable = &vt.iunk;
    iid = &lx::guid_Surface;
  }
};
class CLxLoc_Surface : public CLxLocalize<ILxSurfaceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Surface() {_init();}
  CLxLoc_Surface(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Surface(const CLxLoc_Surface &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Surface;}
    LxResult
  GetBBox (LXtBBox *bbox)
  {
    return m_loc[0]->GetBBox (m_loc,bbox);
  }
    LxResult
  FrontBBox (LXtVector pos, LXtVector dir, LXtBBox *bbox)
  {
    return m_loc[0]->FrontBBox (m_loc,pos,dir,bbox);
  }
    LxResult
  RayCast (const LXtRayInfo *ray, LXtRayHit *hit)
  {
    return m_loc[0]->RayCast (m_loc,ray,hit);
  }
    LxResult
  BinCount (unsigned int *count)
  {
    return m_loc[0]->BinCount (m_loc,count);
  }
    LxResult
  BinByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->BinByIndex (m_loc,index,ppvObj);
  }
    LxResult
  TagCount (LXtID4 type, unsigned int *count)
  {
    return m_loc[0]->TagCount (m_loc,type,count);
  }
    LxResult
  TagByIndex (LXtID4 type, unsigned int index, const char **stag)
  {
    return m_loc[0]->TagByIndex (m_loc,type,index,stag);
  }
    LxResult
  GLCount (unsigned int *count)
  {
    return m_loc[0]->GLCount (m_loc,count);
  }
};

class CLxImpl_SurfaceItem {
  public:
    virtual ~CLxImpl_SurfaceItem() {}
    virtual LxResult
      isurf_GetSurface (ILxUnknownID chanRead, unsigned morph, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      isurf_Prepare (ILxUnknownID eval, unsigned *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      isurf_Evaluate (ILxUnknownID attr, unsigned index, void **ppvObj)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_SurfaceItem : public CLxInterface
{
    static LxResult
  GetSurface (LXtObjectID wcom, LXtObjectID chanRead, unsigned morph, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SurfaceItem, loc);
    try {
      return loc->isurf_GetSurface ((ILxUnknownID)chanRead,morph,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Prepare (LXtObjectID wcom, LXtObjectID eval, unsigned *index)
  {
    LXCWxINST (CLxImpl_SurfaceItem, loc);
    try {
      return loc->isurf_Prepare ((ILxUnknownID)eval,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Evaluate (LXtObjectID wcom, LXtObjectID attr, unsigned index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SurfaceItem, loc);
    try {
      return loc->isurf_Evaluate ((ILxUnknownID)attr,index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxSurfaceItem vt;
public:
  CLxIfc_SurfaceItem ()
  {
    vt.GetSurface = GetSurface;
    vt.Prepare = Prepare;
    vt.Evaluate = Evaluate;
    vTable = &vt.iunk;
    iid = &lx::guid_SurfaceItem;
  }
};
class CLxLoc_SurfaceItem : public CLxLocalize<ILxSurfaceItemID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SurfaceItem() {_init();}
  CLxLoc_SurfaceItem(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SurfaceItem(const CLxLoc_SurfaceItem &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SurfaceItem;}
    LxResult
  GetSurface (ILxUnknownID chanRead, unsigned morph, void **ppvObj)
  {
    return m_loc[0]->GetSurface (m_loc,(ILxUnknownID)chanRead,morph,ppvObj);
  }
    LxResult
  Prepare (ILxUnknownID eval, unsigned *index)
  {
    return m_loc[0]->Prepare (m_loc,(ILxUnknownID)eval,index);
  }
    LxResult
  Evaluate (ILxUnknownID attr, unsigned index, void **ppvObj)
  {
    return m_loc[0]->Evaluate (m_loc,(ILxUnknownID)attr,index,ppvObj);
  }
};

class CLxImpl_SurfaceBin {
  public:
    virtual ~CLxImpl_SurfaceBin() {}
    virtual LxResult
      surfbin_GetBBox (LXtBBox *bbox)
        { return LXe_NOTIMPL; }
    virtual LxResult
      surfbin_FrontBBox (LXtVector pos, LXtVector dir, LXtBBox *bbox)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_SurfaceBin : public CLxInterface
{
    static LxResult
  GetBBox (LXtObjectID wcom, LXtBBox *bbox)
  {
    LXCWxINST (CLxImpl_SurfaceBin, loc);
    try {
      return loc->surfbin_GetBBox (bbox);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FrontBBox (LXtObjectID wcom, LXtVector pos, LXtVector dir, LXtBBox *bbox)
  {
    LXCWxINST (CLxImpl_SurfaceBin, loc);
    try {
      return loc->surfbin_FrontBBox (pos,dir,bbox);
    } catch (LxResult rc) { return rc; }
  }
  ILxSurfaceBin vt;
public:
  CLxIfc_SurfaceBin ()
  {
    vt.GetBBox = GetBBox;
    vt.FrontBBox = FrontBBox;
    vTable = &vt.iunk;
    iid = &lx::guid_SurfaceBin;
  }
};
class CLxLoc_SurfaceBin : public CLxLocalize<ILxSurfaceBinID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SurfaceBin() {_init();}
  CLxLoc_SurfaceBin(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SurfaceBin(const CLxLoc_SurfaceBin &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SurfaceBin;}
    LxResult
  GetBBox (LXtBBox *bbox)
  {
    return m_loc[0]->GetBBox (m_loc,bbox);
  }
    LxResult
  FrontBBox (LXtVector pos, LXtVector dir, LXtBBox *bbox)
  {
    return m_loc[0]->FrontBBox (m_loc,pos,dir,bbox);
  }
};

#endif

