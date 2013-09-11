/*
 * C++ wrapper for lxcom.h
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
#ifndef LXW_COM_HPP
#define LXW_COM_HPP

#include <lxcom.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_GUIDService = {0xB11826F1,0xA6BC,0x48B4,0x90,0x9B,0x5F,0x6D,0x01,0x93,0x83,0x27};
};

class CLxLoc_GUIDService : public CLxLocalizedService
{
  ILxGUIDServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_GUIDService() {_init();set();}
 ~CLxLoc_GUIDService() {}
  void set() {m_loc=reinterpret_cast<ILxGUIDServiceID>(lx::GetGlobal(&lx::guid_GUIDService));}
    const LXtGUID *
  Translate (const char *guidStr)
  {
    return m_loc[0]->Translate (m_loc,guidStr);
  }
    const char *
  GetName (const LXtGUID *guid)
  {
    return m_loc[0]->GetName (m_loc,guid);
  }
    int
  Compare (const LXtGUID *guid1, const LXtGUID *guid2)
  {
    return m_loc[0]->Compare (m_loc,guid1,guid2);
  }
    const LXtGUID *
  Fixed (const LXtGUID *guid)
  {
    return m_loc[0]->Fixed (m_loc,guid);
  }
    const LXtGUID *
  Class (const LXtGUID *guid)
  {
    return m_loc[0]->Class (m_loc,guid);
  }
    const char *
  ClassName (const LXtGUID *guid)
  {
    return m_loc[0]->ClassName (m_loc,guid);
  }
};


#endif

