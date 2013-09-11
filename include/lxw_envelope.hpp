/*
 * C++ wrapper for lxenvelope.h
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
#ifndef LXW_ENVELOPE_HPP
#define LXW_ENVELOPE_HPP

#include <lxenvelope.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_Keyframe = {0xD1D0261F,0x22CF,0x4E5D,0x82,0x2E,0x76,0xB5,0xDE,0xC9,0x8A,0xE4};
    static const LXtGUID guid_Envelope = {0xE39EB451,0x6C35,0x47F4,0x8A,0x7D,0xFF,0x96,0x67,0x1C,0x0D,0xEF};
    static const LXtGUID guid_GradientFilter = {0xACCD7C33,0xD246,0x4FE5,0xAB,0xA0,0x07,0x9F,0x22,0x5B,0xBB,0x34};
};

class CLxLoc_Keyframe : public CLxLocalize<ILxKeyframeID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Keyframe() {_init();}
  CLxLoc_Keyframe(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Keyframe(const CLxLoc_Keyframe &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Keyframe;}
    LxResult
  First (void)
  {
    return m_loc[0]->First (m_loc);
  }
    LxResult
  Last (void)
  {
    return m_loc[0]->Last (m_loc);
  }
    LxResult
  Next (void)
  {
    return m_loc[0]->Next (m_loc);
  }
    LxResult
  Previous (void)
  {
    return m_loc[0]->Previous (m_loc);
  }
    LxResult
  Find (double time, unsigned int side)
  {
    return m_loc[0]->Find (m_loc,time,side);
  }
    LxResult
  GetTime (double *time)
  {
    return m_loc[0]->GetTime (m_loc,time);
  }
    LxResult
  GetBroken (unsigned int *breaks, unsigned int *side)
  {
    return m_loc[0]->GetBroken (m_loc,breaks,side);
  }
    LxResult
  GetValueF (double *value, unsigned int side)
  {
    return m_loc[0]->GetValueF (m_loc,value,side);
  }
    LxResult
  GetValueI (int *value, unsigned int side)
  {
    return m_loc[0]->GetValueI (m_loc,value,side);
  }
    LxResult
  GetSlopeType (LXtSlopeType *type, unsigned int *weighted, unsigned int side)
  {
    return m_loc[0]->GetSlopeType (m_loc,type,weighted,side);
  }
    LxResult
  GetSlope (double *slope, unsigned int side)
  {
    return m_loc[0]->GetSlope (m_loc,slope,side);
  }
    LxResult
  GetWeight (double *weight, unsigned int side)
  {
    return m_loc[0]->GetWeight (m_loc,weight,side);
  }
    LxResult
  SetTime (double time)
  {
    return m_loc[0]->SetTime (m_loc,time);
  }
    LxResult
  SetValueF (double value, unsigned int side)
  {
    return m_loc[0]->SetValueF (m_loc,value,side);
  }
    LxResult
  SetValueI (int value, unsigned int side)
  {
    return m_loc[0]->SetValueI (m_loc,value,side);
  }
    LxResult
  SetSlope (double slope, unsigned int side)
  {
    return m_loc[0]->SetSlope (m_loc,slope,side);
  }
    LxResult
  SetSlopeType (LXtSlopeType type, unsigned int side)
  {
    return m_loc[0]->SetSlopeType (m_loc,type,side);
  }
    LxResult
  SetWeight (double weight, unsigned int reset, unsigned int side)
  {
    return m_loc[0]->SetWeight (m_loc,weight,reset,side);
  }
    LxResult
  AddF (double time, double value)
  {
    return m_loc[0]->AddF (m_loc,time,value);
  }
    LxResult
  AddI (double time, int value)
  {
    return m_loc[0]->AddI (m_loc,time,value);
  }
    LxResult
  Delete (void)
  {
    return m_loc[0]->Delete (m_loc);
  }
};

class CLxLoc_Envelope : public CLxLocalize<ILxEnvelopeID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Envelope() {_init();}
  CLxLoc_Envelope(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Envelope(const CLxLoc_Envelope &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Envelope;}
    unsigned
  IsInt (void)
  {
    return m_loc[0]->IsInt (m_loc);
  }
    LxResult
  Enumerator (void **ppvObj)
  {
    return m_loc[0]->Enumerator (m_loc,ppvObj);
  }
    LxResult
  EvaluateF (double time, double *value)
  {
    return m_loc[0]->EvaluateF (m_loc,time,value);
  }
    LxResult
  EvaluateI (double time, int *value)
  {
    return m_loc[0]->EvaluateI (m_loc,time,value);
  }
    unsigned int
  EndBehavior (unsigned int side)
  {
    return m_loc[0]->EndBehavior (m_loc,side);
  }
    LxResult
  SetEndBehavior (unsigned int behavior, unsigned int side)
  {
    return m_loc[0]->SetEndBehavior (m_loc,behavior,side);
  }
    LxResult
  Clear (void)
  {
    return m_loc[0]->Clear (m_loc);
  }
    unsigned int
  Interpolation (void)
  {
    return m_loc[0]->Interpolation (m_loc);
  }
};

class CLxLoc_GradientFilter : public CLxLocalize<ILxGradientFilterID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_GradientFilter() {_init();}
  CLxLoc_GradientFilter(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_GradientFilter(const CLxLoc_GradientFilter &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_GradientFilter;}
    double
  Evaluate (double inVal)
  {
    return m_loc[0]->Evaluate (m_loc,inVal);
  }
};

#endif

