/*
 * C++ wrapper for lxlistener.h
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
#ifndef LXW_LISTENER_HPP
#define LXW_LISTENER_HPP

#include <lxlistener.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_ListenerPort = {0x4FBF5E77,0x152D,0x4C4F,0xBF,0xD4,0x3F,0x60,0x62,0xCC,0xF6,0xBA};
    static const LXtGUID guid_ListenerService = {0x1966420D,0xDFED,0x11D7,0xA2,0x37,0x00,0x0A,0x95,0x93,0xD7,0x16};
};

class CLxLoc_ListenerPort : public CLxLocalize<ILxListenerPortID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ListenerPort() {_init();}
  CLxLoc_ListenerPort(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ListenerPort(const CLxLoc_ListenerPort &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ListenerPort;}
    LxResult
  AddListener (ILxUnknownID object)
  {
    return m_loc[0]->AddListener (m_loc,(ILxUnknownID)object);
  }
    LxResult
  RemoveListener (ILxUnknownID object)
  {
    return m_loc[0]->RemoveListener (m_loc,(ILxUnknownID)object);
  }
};

class CLxLoc_ListenerService : public CLxLocalizedService
{
  ILxListenerServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_ListenerService() {_init();set();}
 ~CLxLoc_ListenerService() {}
  void set() {m_loc=reinterpret_cast<ILxListenerServiceID>(lx::GetGlobal(&lx::guid_ListenerService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  AddListener (ILxUnknownID object)
  {
    return m_loc[0]->AddListener (m_loc,(ILxUnknownID)object);
  }
    LxResult
  RemoveListener (ILxUnknownID object)
  {
    return m_loc[0]->RemoveListener (m_loc,(ILxUnknownID)object);
  }
};

#endif
