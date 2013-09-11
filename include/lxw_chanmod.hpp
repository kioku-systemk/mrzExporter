/*
 * C++ wrapper for lxchanmod.h
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
#ifndef LXW_CHANMOD_HPP
#define LXW_CHANMOD_HPP

#include <lxchanmod.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_ChannelModItem = {0x1955CFD9,0x9E56,0x42AB,0x94,0xC8,0xBF,0x6B,0xE1,0xB0,0x69,0xD6};
    static const LXtGUID guid_ChannelModifier = {0x7D633F1B,0x41A9,0x4151,0xB9,0x4E,0xA5,0x03,0x22,0xDB,0x62,0xEB};
};

class CLxImpl_ChannelModItem {
  public:
    virtual ~CLxImpl_ChannelModItem() {}
    virtual LxResult
      cmod_Allocate (ILxUnknownID cmod, ILxUnknownID eval, ILxUnknownID item, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      cmod_Flags (ILxUnknownID item, unsigned int index)
        = 0;
    virtual LxResult
      cmod_Evaluate (ILxUnknownID cmod, ILxUnknownID attr, void *data)
        { return LXe_NOTIMPL; }
    virtual void
      cmod_Cleanup (void *data)
        { }
};
template <class T>
class CLxIfc_ChannelModItem : public CLxInterface
{
    static LxResult
  Allocate (LXtObjectID wcom, LXtObjectID cmod, LXtObjectID eval, LXtObjectID item, void **ppvData)
  {
    LXCWxINST (CLxImpl_ChannelModItem, loc);
    try {
      return loc->cmod_Allocate ((ILxUnknownID)cmod,(ILxUnknownID)eval,(ILxUnknownID)item,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  Flags (LXtObjectID wcom, LXtObjectID item, unsigned int index)
  {
    LXCWxINST (CLxImpl_ChannelModItem, loc);
    return loc->cmod_Flags ((ILxUnknownID)item,index);
  }
    static LxResult
  Evaluate (LXtObjectID wcom, LXtObjectID cmod, LXtObjectID attr, void *data)
  {
    LXCWxINST (CLxImpl_ChannelModItem, loc);
    try {
      return loc->cmod_Evaluate ((ILxUnknownID)cmod,(ILxUnknownID)attr,data);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom, void *data)
  {
    LXCWxINST (CLxImpl_ChannelModItem, loc);
    loc->cmod_Cleanup (data);
  }
  ILxChannelModItem vt;
public:
  CLxIfc_ChannelModItem ()
  {
    vt.Allocate = Allocate;
    vt.Flags = Flags;
    vt.Evaluate = Evaluate;
    vt.Cleanup = Cleanup;
    vTable = &vt.iunk;
    iid = &lx::guid_ChannelModItem;
  }
};

class CLxLoc_ChannelModifier : public CLxLocalize<ILxChannelModifierID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ChannelModifier() {_init();}
  CLxLoc_ChannelModifier(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ChannelModifier(const CLxLoc_ChannelModifier &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ChannelModifier;}
    LxResult
  AddInput (ILxUnknownID item, unsigned int index)
  {
    return m_loc[0]->AddInput (m_loc,(ILxUnknownID)item,index);
  }
    LxResult
  AddOutput (ILxUnknownID item, unsigned int index)
  {
    return m_loc[0]->AddOutput (m_loc,(ILxUnknownID)item,index);
  }
    LxResult
  AddTime (void)
  {
    return m_loc[0]->AddTime (m_loc);
  }
    LxResult
  InputCount (unsigned int index, unsigned int *nInputs)
  {
    return m_loc[0]->InputCount (m_loc,index,nInputs);
  }
    LxResult
  OutputCount (unsigned int index, unsigned int *nOutputs)
  {
    return m_loc[0]->OutputCount (m_loc,index,nOutputs);
  }
    LxResult
  ReadInputFloat (ILxUnknownID attr, unsigned int inputIndex, double *dVal)
  {
    return m_loc[0]->ReadInputFloat (m_loc,(ILxUnknownID)attr,inputIndex,dVal);
  }
    LxResult
  ReadInputFloatByIndex (ILxUnknownID attr, unsigned int inputIndex, unsigned int linkIndex, double *dVal)
  {
    return m_loc[0]->ReadInputFloatByIndex (m_loc,(ILxUnknownID)attr,inputIndex,linkIndex,dVal);
  }
    LxResult
  ReadInputAngle (ILxUnknownID attr, unsigned int inputIndex, double *dVal)
  {
    return m_loc[0]->ReadInputAngle (m_loc,(ILxUnknownID)attr,inputIndex,dVal);
  }
    LxResult
  ReadInputInt (ILxUnknownID attr, unsigned int inputIndex, int *iVal)
  {
    return m_loc[0]->ReadInputInt (m_loc,(ILxUnknownID)attr,inputIndex,iVal);
  }
    LxResult
  ReadInputIntByIndex (ILxUnknownID attr, unsigned int inputIndex, unsigned int linkIndex, int *iVal)
  {
    return m_loc[0]->ReadInputIntByIndex (m_loc,(ILxUnknownID)attr,inputIndex,linkIndex,iVal);
  }
    LxResult
  ReadInputVal (ILxUnknownID attr, unsigned int inputIndex, void **val)
  {
    return m_loc[0]->ReadInputVal (m_loc,(ILxUnknownID)attr,inputIndex,val);
  }
    LxResult
  ReadInputValByIndex (ILxUnknownID attr, unsigned int inputIndex, unsigned int linkIndex, void **val)
  {
    return m_loc[0]->ReadInputValByIndex (m_loc,(ILxUnknownID)attr,inputIndex,linkIndex,val);
  }
    LxResult
  WriteOutputFloat (ILxUnknownID attr, unsigned int outputIndex, double dVal)
  {
    return m_loc[0]->WriteOutputFloat (m_loc,(ILxUnknownID)attr,outputIndex,dVal);
  }
    LxResult
  WriteOutputInt (ILxUnknownID attr, unsigned int outputIndex, int iVal)
  {
    return m_loc[0]->WriteOutputInt (m_loc,(ILxUnknownID)attr,outputIndex,iVal);
  }
    LxResult
  WriteOutputVal (ILxUnknownID attr, unsigned int outputIndex, void **val)
  {
    return m_loc[0]->WriteOutputVal (m_loc,(ILxUnknownID)attr,outputIndex,val);
  }
    LxResult
  WriteOutputValByIndex (ILxUnknownID attr, unsigned int outputIndex, unsigned int linkIndex, void **val)
  {
    return m_loc[0]->WriteOutputValByIndex (m_loc,(ILxUnknownID)attr,outputIndex,linkIndex,val);
  }
};

#endif

