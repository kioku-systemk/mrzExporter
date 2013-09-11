/*
 * C++ wrapper for lxvmodel.h
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
#ifndef LXW_VMODEL_HPP
#define LXW_VMODEL_HPP

#include <lxvmodel.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_ViewItem3D = {0x9BCE73B5,0x3264,0x48BB,0xB1,0x29,0x15,0xFF,0x53,0xFD,0x16,0x61};
    static const LXtGUID guid_AdjustTool = {0x26E85301,0x8165,0x4FF3,0xAF,0x26,0x39,0x2A,0x03,0xC9,0xE1,0xE7};
    static const LXtGUID guid_ToolModel = {0xEECE6570,0xAD5F,0x4190,0xAF,0xA7,0x15,0x06,0x75,0x00,0x45,0x4F};
};

class CLxImpl_ViewItem3D {
  public:
    virtual ~CLxImpl_ViewItem3D() {}
    virtual LxResult
      vitm_Draw (ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, LXtVector itemColor)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_DrawBackground (ILxUnknownID chanRead, ILxUnknownID strokeDraw, LXtVector itemColor)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_WorldSpace (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_HandleCount (int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_HandleMotion (int handleIndex, int *motionType, double *min, double *max, LXtVector plane, LXtVector offset)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_HandleChannel (int handleIndex, int *chanIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_HandleValueToPosition (int handleIndex, double chanValue, LXtVector position)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vitm_HandlePositionToValue (int handleIndex, LXtVector position, double *chanValue)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_ViewItem3D : public CLxInterface
{
    static LxResult
  Draw (LXtObjectID wcom, LXtObjectID chanRead, LXtObjectID strokeDraw, int selectionFlags, LXtVector itemColor)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_Draw ((ILxUnknownID)chanRead,(ILxUnknownID)strokeDraw,selectionFlags,itemColor);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DrawBackground (LXtObjectID wcom, LXtObjectID chanRead, LXtObjectID strokeDraw, LXtVector itemColor)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_DrawBackground ((ILxUnknownID)chanRead,(ILxUnknownID)strokeDraw,itemColor);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  WorldSpace (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_WorldSpace ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HandleCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_HandleCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HandleMotion (LXtObjectID wcom, int handleIndex, int *motionType, double *min, double *max, LXtVector plane, LXtVector offset)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_HandleMotion (handleIndex,motionType,min,max,plane,offset);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HandleChannel (LXtObjectID wcom, int handleIndex, int *chanIndex)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_HandleChannel (handleIndex,chanIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HandleValueToPosition (LXtObjectID wcom, int handleIndex, double chanValue, LXtVector position)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_HandleValueToPosition (handleIndex,chanValue,position);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HandlePositionToValue (LXtObjectID wcom, int handleIndex, LXtVector position, double *chanValue)
  {
    LXCWxINST (CLxImpl_ViewItem3D, loc);
    try {
      return loc->vitm_HandlePositionToValue (handleIndex,position,chanValue);
    } catch (LxResult rc) { return rc; }
  }
  ILxViewItem3D vt;
public:
  CLxIfc_ViewItem3D ()
  {
    vt.Draw = Draw;
    vt.DrawBackground = DrawBackground;
    vt.WorldSpace = WorldSpace;
    vt.HandleCount = HandleCount;
    vt.HandleMotion = HandleMotion;
    vt.HandleChannel = HandleChannel;
    vt.HandleValueToPosition = HandleValueToPosition;
    vt.HandlePositionToValue = HandlePositionToValue;
    vTable = &vt.iunk;
    iid = &lx::guid_ViewItem3D;
  }
};
class CLxLoc_ViewItem3D : public CLxLocalize<ILxViewItem3DID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ViewItem3D() {_init();}
  CLxLoc_ViewItem3D(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ViewItem3D(const CLxLoc_ViewItem3D &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ViewItem3D;}
    LxResult
  Draw (ILxUnknownID chanRead, ILxUnknownID strokeDraw, int selectionFlags, LXtVector itemColor)
  {
    return m_loc[0]->Draw (m_loc,(ILxUnknownID)chanRead,(ILxUnknownID)strokeDraw,selectionFlags,itemColor);
  }
    LxResult
  DrawBackground (ILxUnknownID chanRead, ILxUnknownID strokeDraw, LXtVector itemColor)
  {
    return m_loc[0]->DrawBackground (m_loc,(ILxUnknownID)chanRead,(ILxUnknownID)strokeDraw,itemColor);
  }
    LxResult
  WorldSpace (void)
  {
    return m_loc[0]->WorldSpace (m_loc);
  }
    LxResult
  HandleCount (int *count)
  {
    return m_loc[0]->HandleCount (m_loc,count);
  }
    LxResult
  HandleMotion (int handleIndex, int *motionType, double *min, double *max, LXtVector plane, LXtVector offset)
  {
    return m_loc[0]->HandleMotion (m_loc,handleIndex,motionType,min,max,plane,offset);
  }
    LxResult
  HandleChannel (int handleIndex, int *chanIndex)
  {
    return m_loc[0]->HandleChannel (m_loc,handleIndex,chanIndex);
  }
    LxResult
  HandleValueToPosition (int handleIndex, double chanValue, LXtVector position)
  {
    return m_loc[0]->HandleValueToPosition (m_loc,handleIndex,chanValue,position);
  }
    LxResult
  HandlePositionToValue (int handleIndex, LXtVector position, double *chanValue)
  {
    return m_loc[0]->HandlePositionToValue (m_loc,handleIndex,position,chanValue);
  }
};

class CLxLoc_AdjustTool : public CLxLocalize<ILxAdjustToolID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AdjustTool() {_init();}
  CLxLoc_AdjustTool(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AdjustTool(const CLxLoc_AdjustTool &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AdjustTool;}
    void
  Value (unsigned int index, ILxUnknownID val)
  {
    m_loc[0]->Value (m_loc,index,(ILxUnknownID)val);
  }
    void
  SetInt (unsigned int index, int val)
  {
    m_loc[0]->SetInt (m_loc,index,val);
  }
    void
  SetFlt (unsigned int index, double val)
  {
    m_loc[0]->SetFlt (m_loc,index,val);
  }
    void
  SetString (unsigned int index, const char *val)
  {
    m_loc[0]->SetString (m_loc,index,val);
  }
    void
  Lock (void)
  {
    m_loc[0]->Lock (m_loc);
  }
    void
  Invalidate (void)
  {
    m_loc[0]->Invalidate (m_loc);
  }
    void
  Update (void)
  {
    m_loc[0]->Update (m_loc);
  }
};

class CLxImpl_ToolModel {
  public:
    virtual ~CLxImpl_ToolModel() {}
    virtual unsigned
      tmod_Flags (void)
        { return LXfTMOD_DRAW_3D; }
    virtual void
      tmod_Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
        { }
    virtual void
      tmod_Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
        { }
    virtual void
      tmod_Filter (ILxUnknownID vts)
        { }
    virtual void
      tmod_Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
        { }
    virtual LxResult
      tmod_Down (ILxUnknownID vts, ILxUnknownID adjust)
        { return LXe_NOTIMPL; }
    virtual void
      tmod_Move (ILxUnknownID vts, ILxUnknownID adjust)
        { }
    virtual void
      tmod_Up (ILxUnknownID vts, ILxUnknownID adjust)
        { }
    virtual const char *
      tmod_Haul (unsigned int index)
        { return 0; }
    virtual const char *
      tmod_Help (ILxUnknownID vts)
        { return 0; }
    virtual LxResult
      tmod_Enable (ILxUnknownID msg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tmod_Drop (void)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_ToolModel : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    return loc->tmod_Flags ();
  }
    static void
  Draw (LXtObjectID wcom, LXtObjectID vts, LXtObjectID stroke, int flags)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    loc->tmod_Draw ((ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    static void
  Test (LXtObjectID wcom, LXtObjectID vts, LXtObjectID stroke, int flags)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    loc->tmod_Test ((ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    static void
  Filter (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    loc->tmod_Filter ((ILxUnknownID)vts);
  }
    static void
  Initialize (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust, unsigned int flags)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    loc->tmod_Initialize ((ILxUnknownID)vts,(ILxUnknownID)adjust,flags);
  }
    static LxResult
  Down (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    try {
      return loc->tmod_Down ((ILxUnknownID)vts,(ILxUnknownID)adjust);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Move (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    loc->tmod_Move ((ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    static void
  Up (LXtObjectID wcom, LXtObjectID vts, LXtObjectID adjust)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    loc->tmod_Up ((ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    static const char *
  Haul (LXtObjectID wcom, unsigned int index)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    return loc->tmod_Haul (index);
  }
    static const char *
  Help (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    return loc->tmod_Help ((ILxUnknownID)vts);
  }
    static LxResult
  Enable (LXtObjectID wcom, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    try {
      return loc->tmod_Enable ((ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Drop (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ToolModel, loc);
    try {
      return loc->tmod_Drop ();
    } catch (LxResult rc) { return rc; }
  }
  ILxToolModel vt;
public:
  CLxIfc_ToolModel ()
  {
    vt.Flags = Flags;
    vt.Draw = Draw;
    vt.Test = Test;
    vt.Filter = Filter;
    vt.Initialize = Initialize;
    vt.Down = Down;
    vt.Move = Move;
    vt.Up = Up;
    vt.Haul = Haul;
    vt.Help = Help;
    vt.Enable = Enable;
    vt.Drop = Drop;
    vTable = &vt.iunk;
    iid = &lx::guid_ToolModel;
  }
};
class CLxLoc_ToolModel : public CLxLocalize<ILxToolModelID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ToolModel() {_init();}
  CLxLoc_ToolModel(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ToolModel(const CLxLoc_ToolModel &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ToolModel;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    void
  Draw (ILxUnknownID vts, ILxUnknownID stroke, int flags)
  {
    m_loc[0]->Draw (m_loc,(ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    void
  Test (ILxUnknownID vts, ILxUnknownID stroke, int flags)
  {
    m_loc[0]->Test (m_loc,(ILxUnknownID)vts,(ILxUnknownID)stroke,flags);
  }
    void
  Filter (ILxUnknownID vts)
  {
    m_loc[0]->Filter (m_loc,(ILxUnknownID)vts);
  }
    void
  Initialize (ILxUnknownID vts, ILxUnknownID adjust, unsigned int flags)
  {
    m_loc[0]->Initialize (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust,flags);
  }
    LxResult
  Down (ILxUnknownID vts, ILxUnknownID adjust)
  {
    return m_loc[0]->Down (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    void
  Move (ILxUnknownID vts, ILxUnknownID adjust)
  {
    m_loc[0]->Move (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    void
  Up (ILxUnknownID vts, ILxUnknownID adjust)
  {
    m_loc[0]->Up (m_loc,(ILxUnknownID)vts,(ILxUnknownID)adjust);
  }
    const char *
  Haul (unsigned int index)
  {
    return m_loc[0]->Haul (m_loc,index);
  }
    const char *
  Help (ILxUnknownID vts)
  {
    return m_loc[0]->Help (m_loc,(ILxUnknownID)vts);
  }
    LxResult
  Enable (ILxUnknownID msg)
  {
    return m_loc[0]->Enable (m_loc,(ILxUnknownID)msg);
  }
    LxResult
  Drop (void)
  {
    return m_loc[0]->Drop (m_loc);
  }
};

#endif

