/*
 * C++ wrapper for lxsurface.h
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
#ifndef LXW_SURFACE_HPP
#define LXW_SURFACE_HPP

#include <lxsurface.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_Surface = {0x75006BDB,0x93F7,0x4a41,0x8B,0x8C,0xE7,0x10,0xD8,0x0D,0x3F,0x1A};
    static const LXtGUID guid_Curve = {0x9DDF4A43,0x691F,0x4F30,0x89,0x86,0xB5,0x2F,0xD1,0xD9,0x6E,0x34};
    static const LXtGUID guid_SurfaceItem = {0x65EC0E0E,0xFFD7,0x48a3,0x9E,0x20,0x62,0xEA,0x82,0xEF,0x47,0x28};
    static const LXtGUID guid_CurveGroup = {0x20F1B298,0x84E2,0x4DA2,0xBA,0x66,0x88,0x83,0xB4,0xB0,0xD7,0xFF};
    static const LXtGUID guid_SurfaceBin = {0x48B534C1,0x7B7C,0x4147,0xAD,0xBC,0x15,0x48,0x50,0x89,0x8E,0x7F};
};

class CLxImpl_Surface {
  public:
    virtual ~CLxImpl_Surface() {}
    virtual LxResult
      surf_GetBBox (LXtBBox *bbox)
        { return LXe_NOTIMPL; }
    virtual LxResult
      surf_FrontBBox (const LXtVector pos, const LXtVector dir, LXtBBox *bbox)
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
#define LXxD_Surface_GetBBox LxResult surf_GetBBox (LXtBBox *bbox)
#define LXxO_Surface_GetBBox LXxD_Surface_GetBBox LXx_OVERRIDE
#define LXxD_Surface_FrontBBox LxResult surf_FrontBBox (const LXtVector pos, const LXtVector dir, LXtBBox *bbox)
#define LXxO_Surface_FrontBBox LXxD_Surface_FrontBBox LXx_OVERRIDE
#define LXxD_Surface_RayCast LxResult surf_RayCast (const LXtRayInfo *ray, LXtRayHit *hit)
#define LXxO_Surface_RayCast LXxD_Surface_RayCast LXx_OVERRIDE
#define LXxD_Surface_BinCount LxResult surf_BinCount (unsigned int *count)
#define LXxO_Surface_BinCount LXxD_Surface_BinCount LXx_OVERRIDE
#define LXxD_Surface_BinByIndex LxResult surf_BinByIndex (unsigned int index, void **ppvObj)
#define LXxO_Surface_BinByIndex LXxD_Surface_BinByIndex LXx_OVERRIDE
#define LXxD_Surface_TagCount LxResult surf_TagCount (LXtID4 type, unsigned int *count)
#define LXxO_Surface_TagCount LXxD_Surface_TagCount LXx_OVERRIDE
#define LXxD_Surface_TagByIndex LxResult surf_TagByIndex (LXtID4 type, unsigned int index, const char **stag)
#define LXxO_Surface_TagByIndex LXxD_Surface_TagByIndex LXx_OVERRIDE
#define LXxD_Surface_GLCount LxResult surf_GLCount (unsigned int *count)
#define LXxO_Surface_GLCount LXxD_Surface_GLCount LXx_OVERRIDE
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
  FrontBBox (LXtObjectID wcom, const LXtVector pos, const LXtVector dir, LXtBBox *bbox)
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
  FrontBBox (const LXtVector pos, const LXtVector dir, LXtBBox *bbox)
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
    bool
  BinByIndex (unsigned int index, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->BinByIndex (m_loc,index,&obj)) && dest.take(obj);
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

class CLxImpl_Curve {
  public:
    virtual ~CLxImpl_Curve() {}
    virtual LxResult
      curve_GetBBox (LXtBBox *bbox)
        { return LXe_NOTIMPL; }
    virtual double
      curve_Length (void)
        = 0;
    virtual LxResult
      curve_SplineCount (unsigned *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      curve_SplineByIndex (unsigned index, LXtVector b0, LXtVector b1, LXtVector b2, LXtVector b3)
        { return LXe_NOTIMPL; }
    virtual unsigned
      curve_BendCount (void)
        = 0;
    virtual double
      curve_Param (void)
        = 0;
    virtual LxResult
      curve_SetParam (double param)
        { return LXe_NOTIMPL; }
    virtual LxResult
      curve_SetLenFraction (double frac)
        { return LXe_NOTIMPL; }
    virtual LxResult
      curve_Position (LXtVector pos)
        { return LXe_NOTIMPL; }
    virtual LxResult
      curve_Tangent (LXtVector tan)
        { return LXe_NOTIMPL; }
    virtual LxResult
      curve_Closest (const LXtVector probe, double *param, LXtVector pos, LXtVector norm)
        { return LXe_NOTIMPL; }
};
#define LXxD_Curve_GetBBox LxResult curve_GetBBox (LXtBBox *bbox)
#define LXxO_Curve_GetBBox LXxD_Curve_GetBBox LXx_OVERRIDE
#define LXxD_Curve_Length double curve_Length (void)
#define LXxO_Curve_Length LXxD_Curve_Length LXx_OVERRIDE
#define LXxD_Curve_SplineCount LxResult curve_SplineCount (unsigned *count)
#define LXxO_Curve_SplineCount LXxD_Curve_SplineCount LXx_OVERRIDE
#define LXxD_Curve_SplineByIndex LxResult curve_SplineByIndex (unsigned index, LXtVector b0, LXtVector b1, LXtVector b2, LXtVector b3)
#define LXxO_Curve_SplineByIndex LXxD_Curve_SplineByIndex LXx_OVERRIDE
#define LXxD_Curve_BendCount unsigned curve_BendCount (void)
#define LXxO_Curve_BendCount LXxD_Curve_BendCount LXx_OVERRIDE
#define LXxD_Curve_Param double curve_Param (void)
#define LXxO_Curve_Param LXxD_Curve_Param LXx_OVERRIDE
#define LXxD_Curve_SetParam LxResult curve_SetParam (double param)
#define LXxO_Curve_SetParam LXxD_Curve_SetParam LXx_OVERRIDE
#define LXxD_Curve_SetLenFraction LxResult curve_SetLenFraction (double frac)
#define LXxO_Curve_SetLenFraction LXxD_Curve_SetLenFraction LXx_OVERRIDE
#define LXxD_Curve_Position LxResult curve_Position (LXtVector pos)
#define LXxO_Curve_Position LXxD_Curve_Position LXx_OVERRIDE
#define LXxD_Curve_Tangent LxResult curve_Tangent (LXtVector tan)
#define LXxO_Curve_Tangent LXxD_Curve_Tangent LXx_OVERRIDE
#define LXxD_Curve_Closest LxResult curve_Closest (const LXtVector probe, double *param, LXtVector pos, LXtVector norm)
#define LXxO_Curve_Closest LXxD_Curve_Closest LXx_OVERRIDE
template <class T>
class CLxIfc_Curve : public CLxInterface
{
    static LxResult
  GetBBox (LXtObjectID wcom, LXtBBox *bbox)
  {
    LXCWxINST (CLxImpl_Curve, loc);
    try {
      return loc->curve_GetBBox (bbox);
    } catch (LxResult rc) { return rc; }
  }
    static double
  Length (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Curve, loc);
    return loc->curve_Length ();
  }
    static LxResult
  SplineCount (LXtObjectID wcom, unsigned *count)
  {
    LXCWxINST (CLxImpl_Curve, loc);
    try {
      return loc->curve_SplineCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SplineByIndex (LXtObjectID wcom, unsigned index, LXtVector b0, LXtVector b1, LXtVector b2, LXtVector b3)
  {
    LXCWxINST (CLxImpl_Curve, loc);
    try {
      return loc->curve_SplineByIndex (index,b0,b1,b2,b3);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned
  BendCount (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Curve, loc);
    return loc->curve_BendCount ();
  }
    static double
  Param (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Curve, loc);
    return loc->curve_Param ();
  }
    static LxResult
  SetParam (LXtObjectID wcom, double param)
  {
    LXCWxINST (CLxImpl_Curve, loc);
    try {
      return loc->curve_SetParam (param);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetLenFraction (LXtObjectID wcom, double frac)
  {
    LXCWxINST (CLxImpl_Curve, loc);
    try {
      return loc->curve_SetLenFraction (frac);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Position (LXtObjectID wcom, LXtVector pos)
  {
    LXCWxINST (CLxImpl_Curve, loc);
    try {
      return loc->curve_Position (pos);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Tangent (LXtObjectID wcom, LXtVector tan)
  {
    LXCWxINST (CLxImpl_Curve, loc);
    try {
      return loc->curve_Tangent (tan);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Closest (LXtObjectID wcom, const LXtVector probe, double *param, LXtVector pos, LXtVector norm)
  {
    LXCWxINST (CLxImpl_Curve, loc);
    try {
      return loc->curve_Closest (probe,param,pos,norm);
    } catch (LxResult rc) { return rc; }
  }
  ILxCurve vt;
public:
  CLxIfc_Curve ()
  {
    vt.GetBBox = GetBBox;
    vt.Length = Length;
    vt.SplineCount = SplineCount;
    vt.SplineByIndex = SplineByIndex;
    vt.BendCount = BendCount;
    vt.Param = Param;
    vt.SetParam = SetParam;
    vt.SetLenFraction = SetLenFraction;
    vt.Position = Position;
    vt.Tangent = Tangent;
    vt.Closest = Closest;
    vTable = &vt.iunk;
    iid = &lx::guid_Curve;
  }
};
class CLxLoc_Curve : public CLxLocalize<ILxCurveID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Curve() {_init();}
  CLxLoc_Curve(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Curve(const CLxLoc_Curve &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Curve;}
    LxResult
  GetBBox (LXtBBox *bbox)
  {
    return m_loc[0]->GetBBox (m_loc,bbox);
  }
    double
  Length (void)
  {
    return m_loc[0]->Length (m_loc);
  }
    LxResult
  SplineCount (unsigned *count)
  {
    return m_loc[0]->SplineCount (m_loc,count);
  }
    LxResult
  SplineByIndex (unsigned index, LXtVector b0, LXtVector b1, LXtVector b2, LXtVector b3)
  {
    return m_loc[0]->SplineByIndex (m_loc,index,b0,b1,b2,b3);
  }
    unsigned
  BendCount (void)
  {
    return m_loc[0]->BendCount (m_loc);
  }
    double
  Param (void)
  {
    return m_loc[0]->Param (m_loc);
  }
    LxResult
  SetParam (double param)
  {
    return m_loc[0]->SetParam (m_loc,param);
  }
    LxResult
  SetLenFraction (double frac)
  {
    return m_loc[0]->SetLenFraction (m_loc,frac);
  }
    LxResult
  Position (LXtVector pos)
  {
    return m_loc[0]->Position (m_loc,pos);
  }
    LxResult
  Tangent (LXtVector tan)
  {
    return m_loc[0]->Tangent (m_loc,tan);
  }
    LxResult
  Closest (const LXtVector probe, double *param, LXtVector pos, LXtVector norm)
  {
    return m_loc[0]->Closest (m_loc,probe,param,pos,norm);
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
#define LXxD_SurfaceItem_GetSurface LxResult isurf_GetSurface (ILxUnknownID chanRead, unsigned morph, void **ppvObj)
#define LXxO_SurfaceItem_GetSurface LXxD_SurfaceItem_GetSurface LXx_OVERRIDE
#define LXxD_SurfaceItem_Prepare LxResult isurf_Prepare (ILxUnknownID eval, unsigned *index)
#define LXxO_SurfaceItem_Prepare LXxD_SurfaceItem_Prepare LXx_OVERRIDE
#define LXxD_SurfaceItem_Evaluate LxResult isurf_Evaluate (ILxUnknownID attr, unsigned index, void **ppvObj)
#define LXxO_SurfaceItem_Evaluate LXxD_SurfaceItem_Evaluate LXx_OVERRIDE
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
    bool
  GetSurface (ILxUnknownID chanRead, unsigned morph, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->GetSurface (m_loc,(ILxUnknownID)chanRead,morph,&obj)) && dest.take(obj);
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
    bool
  Evaluate (ILxUnknownID attr, unsigned index, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Evaluate (m_loc,(ILxUnknownID)attr,index,&obj)) && dest.take(obj);
  }
};

class CLxImpl_CurveGroup {
  public:
    virtual ~CLxImpl_CurveGroup() {}
    virtual LxResult
      cgrp_GetBBox (LXtBBox *bbox)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cgrp_Count (unsigned *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cgrp_ByIndex (unsigned index, void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_CurveGroup_GetBBox LxResult cgrp_GetBBox (LXtBBox *bbox)
#define LXxO_CurveGroup_GetBBox LXxD_CurveGroup_GetBBox LXx_OVERRIDE
#define LXxD_CurveGroup_Count LxResult cgrp_Count (unsigned *count)
#define LXxO_CurveGroup_Count LXxD_CurveGroup_Count LXx_OVERRIDE
#define LXxD_CurveGroup_ByIndex LxResult cgrp_ByIndex (unsigned index, void **ppvObj)
#define LXxO_CurveGroup_ByIndex LXxD_CurveGroup_ByIndex LXx_OVERRIDE
template <class T>
class CLxIfc_CurveGroup : public CLxInterface
{
    static LxResult
  GetBBox (LXtObjectID wcom, LXtBBox *bbox)
  {
    LXCWxINST (CLxImpl_CurveGroup, loc);
    try {
      return loc->cgrp_GetBBox (bbox);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Count (LXtObjectID wcom, unsigned *count)
  {
    LXCWxINST (CLxImpl_CurveGroup, loc);
    try {
      return loc->cgrp_Count (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ByIndex (LXtObjectID wcom, unsigned index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_CurveGroup, loc);
    try {
      return loc->cgrp_ByIndex (index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxCurveGroup vt;
public:
  CLxIfc_CurveGroup ()
  {
    vt.GetBBox = GetBBox;
    vt.Count = Count;
    vt.ByIndex = ByIndex;
    vTable = &vt.iunk;
    iid = &lx::guid_CurveGroup;
  }
};
class CLxLoc_CurveGroup : public CLxLocalize<ILxCurveGroupID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_CurveGroup() {_init();}
  CLxLoc_CurveGroup(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_CurveGroup(const CLxLoc_CurveGroup &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_CurveGroup;}
    LxResult
  GetBBox (LXtBBox *bbox)
  {
    return m_loc[0]->GetBBox (m_loc,bbox);
  }
    LxResult
  Count (unsigned *count)
  {
    return m_loc[0]->Count (m_loc,count);
  }
    LxResult
  ByIndex (unsigned index, void **ppvObj)
  {
    return m_loc[0]->ByIndex (m_loc,index,ppvObj);
  }
    bool
  ByIndex (unsigned index, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->ByIndex (m_loc,index,&obj)) && dest.take(obj);
  }
};

class CLxImpl_SurfaceBin {
  public:
    virtual ~CLxImpl_SurfaceBin() {}
    virtual LxResult
      surfbin_GetBBox (LXtBBox *bbox)
        { return LXe_NOTIMPL; }
    virtual LxResult
      surfbin_FrontBBox (const LXtVector pos, const LXtVector dir, LXtBBox *bbox)
        { return LXe_NOTIMPL; }
};
#define LXxD_SurfaceBin_GetBBox LxResult surfbin_GetBBox (LXtBBox *bbox)
#define LXxO_SurfaceBin_GetBBox LXxD_SurfaceBin_GetBBox LXx_OVERRIDE
#define LXxD_SurfaceBin_FrontBBox LxResult surfbin_FrontBBox (const LXtVector pos, const LXtVector dir, LXtBBox *bbox)
#define LXxO_SurfaceBin_FrontBBox LXxD_SurfaceBin_FrontBBox LXx_OVERRIDE
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
  FrontBBox (LXtObjectID wcom, const LXtVector pos, const LXtVector dir, LXtBBox *bbox)
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
  FrontBBox (const LXtVector pos, const LXtVector dir, LXtBBox *bbox)
  {
    return m_loc[0]->FrontBBox (m_loc,pos,dir,bbox);
  }
};

#endif

