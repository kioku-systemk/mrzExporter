/*
 * C++ wrapper for lxschematic.h
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
#ifndef LXW_SCHEMATIC_HPP
#define LXW_SCHEMATIC_HPP

#include <lxschematic.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_Schematic = {0xF656CC26,0x2580,0x4B4C,0x8C,0xBC,0x8B,0xDD,0x01,0x37,0x8B,0xFD};
};

class CLxImpl_Schematic {
  public:
    virtual ~CLxImpl_Schematic() {}
    virtual LxResult
      schm_GraphRegister (char *string)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_GraphTest (ILxUnknownID from, ILxUnknownID to)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_Schematic : public CLxInterface
{
    static LxResult
  GraphRegister (LXtObjectID wcom, char *string)
  {
    LXCWxINST (CLxImpl_Schematic, loc);
    try {
      return loc->schm_GraphRegister (string);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GraphTest (LXtObjectID wcom, LXtObjectID from, LXtObjectID to)
  {
    LXCWxINST (CLxImpl_Schematic, loc);
    try {
      return loc->schm_GraphTest ((ILxUnknownID)from,(ILxUnknownID)to);
    } catch (LxResult rc) { return rc; }
  }
  ILxSchematic vt;
public:
  CLxIfc_Schematic ()
  {
    vt.GraphRegister = GraphRegister;
    vt.GraphTest = GraphTest;
    vTable = &vt.iunk;
    iid = &lx::guid_Schematic;
  }
};
class CLxLoc_Schematic : public CLxLocalize<ILxSchematicID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Schematic() {_init();}
  CLxLoc_Schematic(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Schematic(const CLxLoc_Schematic &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Schematic;}
    LxResult
  GraphRegister (char *string)
  {
    return m_loc[0]->GraphRegister (m_loc,string);
  }
    LxResult
  GraphTest (ILxUnknownID from, ILxUnknownID to)
  {
    return m_loc[0]->GraphTest (m_loc,(ILxUnknownID)from,(ILxUnknownID)to);
  }
};

#endif

