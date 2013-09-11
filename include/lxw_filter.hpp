/*
 * C++ wrapper for lxfilter.h
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
#ifndef LXW_FILTER_HPP
#define LXW_FILTER_HPP

#include <lxfilter.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_EvaluationStack = {0x47F3BF05,0xB64A,0x49D9,0xA2,0xC1,0x08,0xB0,0xD3,0x6A,0xB7,0x87};
    static const LXtGUID guid_StackFilter = {0xB79CF5D3,0xC630,0x401B,0x82,0xA5,0xAD,0x86,0x6B,0xC0,0x5B,0x6F};
};

class CLxLoc_EvaluationStack : public CLxLocalize<ILxEvaluationStackID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_EvaluationStack() {_init();}
  CLxLoc_EvaluationStack(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_EvaluationStack(const CLxLoc_EvaluationStack &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_EvaluationStack;}
    const char *
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    LxResult
  Branch (void **ppvObj)
  {
    return m_loc[0]->Branch (m_loc,ppvObj);
  }
    LxResult
  AddFilter (ILxUnknownID filter)
  {
    return m_loc[0]->AddFilter (m_loc,(ILxUnknownID)filter);
  }
};

class CLxImpl_StackFilter {
  public:
    virtual ~CLxImpl_StackFilter() {}
    virtual const char *
      filt_Type (void)
        = 0;
    virtual unsigned
      filt_Compare (ILxUnknownID other)
        { return LXiSTACK_DIFFERENT; }
    virtual LxResult
      filt_Convert (ILxUnknownID other)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_StackFilter : public CLxInterface
{
    static const char *
  Type (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_StackFilter, loc);
    return loc->filt_Type ();
  }
    static unsigned
  Compare (LXtObjectID wcom, LXtObjectID other)
  {
    LXCWxINST (CLxImpl_StackFilter, loc);
    return loc->filt_Compare ((ILxUnknownID)other);
  }
    static LxResult
  Convert (LXtObjectID wcom, LXtObjectID other)
  {
    LXCWxINST (CLxImpl_StackFilter, loc);
    try {
      return loc->filt_Convert ((ILxUnknownID)other);
    } catch (LxResult rc) { return rc; }
  }
  ILxStackFilter vt;
public:
  CLxIfc_StackFilter ()
  {
    vt.Type = Type;
    vt.Compare = Compare;
    vt.Convert = Convert;
    vTable = &vt.iunk;
    iid = &lx::guid_StackFilter;
  }
};
class CLxLoc_StackFilter : public CLxLocalize<ILxStackFilterID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_StackFilter() {_init();}
  CLxLoc_StackFilter(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_StackFilter(const CLxLoc_StackFilter &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_StackFilter;}
    const char *
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    unsigned
  Compare (ILxUnknownID other)
  {
    return m_loc[0]->Compare (m_loc,(ILxUnknownID)other);
  }
    LxResult
  Convert (ILxUnknownID other)
  {
    return m_loc[0]->Convert (m_loc,(ILxUnknownID)other);
  }
};

#endif

