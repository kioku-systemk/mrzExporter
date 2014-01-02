/*
 * C++ wrapper for lxschematic.h
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
#ifndef LXW_SCHEMATIC_HPP
#define LXW_SCHEMATIC_HPP

#include <lxschematic.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_SchematicConnection = {0x5AC0A075,0x72B7,0x4935,0x8D,0xA5,0x58,0x8D,0xF7,0x99,0x90,0x69};
};

class CLxImpl_SchematicConnection {
  public:
    virtual ~CLxImpl_SchematicConnection() {}
    virtual LxResult
      schm_ItemFlags (ILxUnknownID item, unsigned *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_AllowConnect (ILxUnknownID from, ILxUnknownID to)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_GraphName (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_Count (ILxUnknownID item, unsigned *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      schm_Disconnect (ILxUnknownID from, ILxUnknownID to)
        { return LXe_NOTIMPL; }
    virtual int
      schm_BaseFlags (void)
        { return 0; }
};
#define LXxD_SchematicConnection_ItemFlags LxResult schm_ItemFlags (ILxUnknownID item, unsigned *flags)
#define LXxO_SchematicConnection_ItemFlags LXxD_SchematicConnection_ItemFlags LXx_OVERRIDE
#define LXxD_SchematicConnection_AllowConnect LxResult schm_AllowConnect (ILxUnknownID from, ILxUnknownID to)
#define LXxO_SchematicConnection_AllowConnect LXxD_SchematicConnection_AllowConnect LXx_OVERRIDE
#define LXxD_SchematicConnection_GraphName LxResult schm_GraphName (const char **name)
#define LXxO_SchematicConnection_GraphName LXxD_SchematicConnection_GraphName LXx_OVERRIDE
#define LXxD_SchematicConnection_Count LxResult schm_Count (ILxUnknownID item, unsigned *count)
#define LXxO_SchematicConnection_Count LXxD_SchematicConnection_Count LXx_OVERRIDE
#define LXxD_SchematicConnection_ByIndex LxResult schm_ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
#define LXxO_SchematicConnection_ByIndex LXxD_SchematicConnection_ByIndex LXx_OVERRIDE
#define LXxD_SchematicConnection_Connect LxResult schm_Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
#define LXxO_SchematicConnection_Connect LXxD_SchematicConnection_Connect LXx_OVERRIDE
#define LXxD_SchematicConnection_Disconnect LxResult schm_Disconnect (ILxUnknownID from, ILxUnknownID to)
#define LXxO_SchematicConnection_Disconnect LXxD_SchematicConnection_Disconnect LXx_OVERRIDE
#define LXxD_SchematicConnection_BaseFlags int schm_BaseFlags (void)
#define LXxO_SchematicConnection_BaseFlags LXxD_SchematicConnection_BaseFlags LXx_OVERRIDE
template <class T>
class CLxIfc_SchematicConnection : public CLxInterface
{
    static LxResult
  ItemFlags (LXtObjectID wcom, LXtObjectID item, unsigned *flags)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_ItemFlags ((ILxUnknownID)item,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AllowConnect (LXtObjectID wcom, LXtObjectID from, LXtObjectID to)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_AllowConnect ((ILxUnknownID)from,(ILxUnknownID)to);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GraphName (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_GraphName (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Count (LXtObjectID wcom, LXtObjectID item, unsigned *count)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_Count ((ILxUnknownID)item,count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ByIndex (LXtObjectID wcom, LXtObjectID item, unsigned index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_ByIndex ((ILxUnknownID)item,index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Connect (LXtObjectID wcom, LXtObjectID from, LXtObjectID to, int toIndex)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_Connect ((ILxUnknownID)from,(ILxUnknownID)to,toIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Disconnect (LXtObjectID wcom, LXtObjectID from, LXtObjectID to)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    try {
      return loc->schm_Disconnect ((ILxUnknownID)from,(ILxUnknownID)to);
    } catch (LxResult rc) { return rc; }
  }
    static int
  BaseFlags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SchematicConnection, loc);
    return loc->schm_BaseFlags ();
  }
  ILxSchematicConnection vt;
public:
  CLxIfc_SchematicConnection ()
  {
    vt.ItemFlags = ItemFlags;
    vt.AllowConnect = AllowConnect;
    vt.GraphName = GraphName;
    vt.Count = Count;
    vt.ByIndex = ByIndex;
    vt.Connect = Connect;
    vt.Disconnect = Disconnect;
    vt.BaseFlags = BaseFlags;
    vTable = &vt.iunk;
    iid = &lx::guid_SchematicConnection;
  }
};
class CLxLoc_SchematicConnection : public CLxLocalize<ILxSchematicConnectionID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SchematicConnection() {_init();}
  CLxLoc_SchematicConnection(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SchematicConnection(const CLxLoc_SchematicConnection &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SchematicConnection;}
    LxResult
  ItemFlags (ILxUnknownID item, unsigned *flags)
  {
    return m_loc[0]->ItemFlags (m_loc,(ILxUnknownID)item,flags);
  }
    LxResult
  AllowConnect (ILxUnknownID from, ILxUnknownID to)
  {
    return m_loc[0]->AllowConnect (m_loc,(ILxUnknownID)from,(ILxUnknownID)to);
  }
    LxResult
  GraphName (const char **name)
  {
    return m_loc[0]->GraphName (m_loc,name);
  }
    LxResult
  Count (ILxUnknownID item, unsigned *count)
  {
    return m_loc[0]->Count (m_loc,(ILxUnknownID)item,count);
  }
    LxResult
  ByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
  {
    return m_loc[0]->ByIndex (m_loc,(ILxUnknownID)item,index,ppvObj);
  }
    bool
  ByIndex (ILxUnknownID item, unsigned index, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->ByIndex (m_loc,(ILxUnknownID)item,index,&obj)) && dest.take(obj);
  }
    LxResult
  Connect (ILxUnknownID from, ILxUnknownID to, int toIndex)
  {
    return m_loc[0]->Connect (m_loc,(ILxUnknownID)from,(ILxUnknownID)to,toIndex);
  }
    LxResult
  Disconnect (ILxUnknownID from, ILxUnknownID to)
  {
    return m_loc[0]->Disconnect (m_loc,(ILxUnknownID)from,(ILxUnknownID)to);
  }
    int
  BaseFlags (void)
  {
    return m_loc[0]->BaseFlags (m_loc);
  }
};

#endif

