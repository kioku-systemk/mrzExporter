/*
 * C++ wrapper for lxselect.h
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
#ifndef LXW_SELECT_HPP
#define LXW_SELECT_HPP

#include <lxselect.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_SelectionService = {0x6AEF6F27,0x046F,0x4C04,0x90,0xE0,0x99,0x4D,0x74,0x28,0x51,0xE7};
    static const LXtGUID guid_SelectionListener = {0x32E1B478,0xF2F6,0x41A8,0x9D,0x79,0x14,0x91,0x9B,0x79,0x3A,0xFE};
    static const LXtGUID guid_SelectionPacket1Service = {0x58D8DEAD,0x3B0C,0x41FB,0xAC,0x1E,0xB1,0x7A,0x36,0x52,0x1D,0x44};
    static const LXtGUID guid_SelectionType = {0x6f0E612B,0x4462,0x43B5,0x84,0xD3,0xA6,0xFC,0xA7,0xC8,0xEF,0x94};
};

class CLxLoc_SelectionService : public CLxLocalizedService
{
  ILxSelectionServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_SelectionService() {_init();set();}
 ~CLxLoc_SelectionService() {}
  void set() {m_loc=reinterpret_cast<ILxSelectionServiceID>(lx::GetGlobal(&lx::guid_SelectionService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    int
  Count (LXtID4 type)
  {
    return m_loc[0]->Count (m_loc,type);
  }
    void *
  ByIndex (LXtID4 type, unsigned int idx)
  {
    return m_loc[0]->ByIndex (m_loc,type,idx);
  }
    void *
  Recent (LXtID4 type)
  {
    return m_loc[0]->Recent (m_loc,type);
  }
    LxResult
  Test (LXtID4 type, void *packet)
  {
    return m_loc[0]->Test (m_loc,type,packet);
  }
    LXtScanInfoID
  ScanLoop (LXtScanInfoID scan, LXtID4 type, void **packet)
  {
    return m_loc[0]->ScanLoop (m_loc,scan,type,packet);
  }
    LXtScanInfoID
  ScanLoopCurrent (LXtScanInfoID scan, LXtID4 type, void **packet)
  {
    return m_loc[0]->ScanLoopCurrent (m_loc,scan,type,packet);
  }
    LxResult
  Select (LXtID4 type, void *packet)
  {
    return m_loc[0]->Select (m_loc,type,packet);
  }
    LxResult
  Deselect (LXtID4 type, void *packet)
  {
    return m_loc[0]->Deselect (m_loc,type,packet);
  }
    LxResult
  Remove (LXtID4 type, void *packet)
  {
    return m_loc[0]->Remove (m_loc,type,packet);
  }
    LxResult
  Toggle (LXtID4 type, void *packet)
  {
    return m_loc[0]->Toggle (m_loc,type,packet);
  }
    LxResult
  Drop (LXtID4 type)
  {
    return m_loc[0]->Drop (m_loc,type);
  }
    LxResult
  StartBatch (LXtID4 type, int desel)
  {
    return m_loc[0]->StartBatch (m_loc,type,desel);
  }
    LxResult
  EndBatch (int desel)
  {
    return m_loc[0]->EndBatch (m_loc,desel);
  }
    LxResult
  AbortBatch (void)
  {
    return m_loc[0]->AbortBatch (m_loc);
  }
    const char *
  LookupName (LXtID4 type)
  {
    return m_loc[0]->LookupName (m_loc,type);
  }
    LXtID4
  LookupType (const char *name)
  {
    return m_loc[0]->LookupType (m_loc,name);
  }
    LxResult
  Allocate (const char *name, void **ppvObj)
  {
    return m_loc[0]->Allocate (m_loc,name,ppvObj);
  }
    double
  GetTime (void)
  {
    return m_loc[0]->GetTime (m_loc);
  }
    LxResult
  SetTime (double time)
  {
    return m_loc[0]->SetTime (m_loc,time);
  }
    double
  Clear (LXtID4 type)
  {
    return m_loc[0]->Clear (m_loc,type);
  }
    int
  State (LXtID4 type, void *packet)
  {
    return m_loc[0]->State (m_loc,type,packet);
  }
    LXtID4
  CurrentType (LXtID4 *types)
  {
    return m_loc[0]->CurrentType (m_loc,types);
  }
};

class CLxImpl_SelectionListener {
  public:
    virtual ~CLxImpl_SelectionListener() {}
    virtual void
      selevent_Current (LXtID4 type)
        { }
    virtual void
      selevent_Add (LXtID4 type, unsigned int subtType)
        { }
    virtual void
      selevent_Remove (LXtID4 type, unsigned int subtType)
        { }
    virtual void
      selevent_Time (double time)
        { }
    virtual void
      selevent_TimeRange (LXtID4 type)
        { }
};
template <class T>
class CLxIfc_SelectionListener : public CLxInterface
{
    static void
  Current (LXtObjectID wcom, LXtID4 type)
  {
    LXCWxINST (CLxImpl_SelectionListener, loc);
    loc->selevent_Current (type);
  }
    static void
  Add (LXtObjectID wcom, LXtID4 type, unsigned int subtType)
  {
    LXCWxINST (CLxImpl_SelectionListener, loc);
    loc->selevent_Add (type,subtType);
  }
    static void
  Remove (LXtObjectID wcom, LXtID4 type, unsigned int subtType)
  {
    LXCWxINST (CLxImpl_SelectionListener, loc);
    loc->selevent_Remove (type,subtType);
  }
    static void
  Time (LXtObjectID wcom, double time)
  {
    LXCWxINST (CLxImpl_SelectionListener, loc);
    loc->selevent_Time (time);
  }
    static void
  TimeRange (LXtObjectID wcom, LXtID4 type)
  {
    LXCWxINST (CLxImpl_SelectionListener, loc);
    loc->selevent_TimeRange (type);
  }
  ILxSelectionListener vt;
public:
  CLxIfc_SelectionListener ()
  {
    vt.Current = Current;
    vt.Add = Add;
    vt.Remove = Remove;
    vt.Time = Time;
    vt.TimeRange = TimeRange;
    vTable = &vt.iunk;
    iid = &lx::guid_SelectionListener;
  }
};


class CLxImpl_SelectionType {
  public:
    virtual ~CLxImpl_SelectionType() {}
    virtual unsigned int
      seltyp_Size (void)
        = 0;
    virtual unsigned int
      seltyp_Flags (void)
        = 0;
    virtual const char *
      seltyp_MessageTable (void)
        = 0;
    virtual int
      seltyp_Compare (void *pkey, void *pelt)
        = 0;
    virtual unsigned int
      seltyp_SubType (void *pkt)
        { return 0; }
};
template <class T>
class CLxIfc_SelectionType : public CLxInterface
{
    static unsigned int
  Size (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SelectionType, loc);
    return loc->seltyp_Size ();
  }
    static unsigned int
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SelectionType, loc);
    return loc->seltyp_Flags ();
  }
    static const char *
  MessageTable (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_SelectionType, loc);
    return loc->seltyp_MessageTable ();
  }
    static int
  Compare (LXtObjectID wcom, void *pkey, void *pelt)
  {
    LXCWxINST (CLxImpl_SelectionType, loc);
    return loc->seltyp_Compare (pkey,pelt);
  }
    static unsigned int
  SubType (LXtObjectID wcom, void *pkt)
  {
    LXCWxINST (CLxImpl_SelectionType, loc);
    return loc->seltyp_SubType (pkt);
  }
  ILxSelectionType vt;
public:
  CLxIfc_SelectionType ()
  {
    vt.Size = Size;
    vt.Flags = Flags;
    vt.MessageTable = MessageTable;
    vt.Compare = Compare;
    vt.SubType = SubType;
    vTable = &vt.iunk;
    iid = &lx::guid_SelectionType;
  }
};
class CLxLoc_SelectionType : public CLxLocalize<ILxSelectionTypeID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SelectionType() {_init();}
  CLxLoc_SelectionType(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SelectionType(const CLxLoc_SelectionType &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SelectionType;}
    unsigned int
  Size (void)
  {
    return m_loc[0]->Size (m_loc);
  }
    unsigned int
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    const char *
  MessageTable (void)
  {
    return m_loc[0]->MessageTable (m_loc);
  }
    int
  Compare (void *pkey, void *pelt)
  {
    return m_loc[0]->Compare (m_loc,pkey,pelt);
  }
    unsigned int
  SubType (void *pkt)
  {
    return m_loc[0]->SubType (m_loc,pkt);
  }
};

#endif

