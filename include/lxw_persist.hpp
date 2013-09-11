/*
 * C++ wrapper for lxpersist.h
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
#ifndef LXW_PERSIST_HPP
#define LXW_PERSIST_HPP

#include <lxpersist.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_PersistenceService = {0x4CB5705E,0xC705,0x499D,0x95,0x61,0x6F,0xD3,0x69,0xCE,0xFE,0x99};
    static const LXtGUID guid_PersistenceClient = {0x435E3BEE,0x8317,0x4DEB,0x92,0xA8,0x74,0xE1,0x15,0x38,0x4F,0x3F};
    static const LXtGUID guid_PersistentEntry = {0xBD3F1DF5,0x967B,0x441F,0x86,0xA7,0xA0,0x91,0xF2,0xE6,0xCD,0xA5};
};

class CLxLoc_PersistenceService : public CLxLocalizedService
{
  ILxPersistenceServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_PersistenceService() {_init();set();}
 ~CLxLoc_PersistenceService() {}
  void set() {m_loc=reinterpret_cast<ILxPersistenceServiceID>(lx::GetGlobal(&lx::guid_PersistenceService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  Configure (const char *name, ILxUnknownID obj)
  {
    return m_loc[0]->Configure (m_loc,name,(ILxUnknownID)obj);
  }
    LxResult
  Start (const char *name, unsigned int type)
  {
    return m_loc[0]->Start (m_loc,name,type);
  }
    LxResult
  End (void **ppvObj)
  {
    return m_loc[0]->End (m_loc,ppvObj);
  }
    LxResult
  AddValue (const char *typeName)
  {
    return m_loc[0]->AddValue (m_loc,typeName);
  }
};

class CLxImpl_PersistenceClient {
  public:
    virtual ~CLxImpl_PersistenceClient() {}
    virtual LxResult
      cc_Setup (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cc_SyncRead (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cc_SyncWrite (void)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_PersistenceClient : public CLxInterface
{
    static LxResult
  Setup (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PersistenceClient, loc);
    try {
      return loc->cc_Setup ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SyncRead (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PersistenceClient, loc);
    try {
      return loc->cc_SyncRead ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SyncWrite (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PersistenceClient, loc);
    try {
      return loc->cc_SyncWrite ();
    } catch (LxResult rc) { return rc; }
  }
  ILxPersistenceClient vt;
public:
  CLxIfc_PersistenceClient ()
  {
    vt.Setup = Setup;
    vt.SyncRead = SyncRead;
    vt.SyncWrite = SyncWrite;
    vTable = &vt.iunk;
    iid = &lx::guid_PersistenceClient;
  }
};

class CLxLoc_PersistentEntry : public CLxLocalize<ILxPersistentEntryID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PersistentEntry() {_init();}
  CLxLoc_PersistentEntry(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PersistentEntry(const CLxLoc_PersistentEntry &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PersistentEntry;}
    LxResult
  Count (unsigned int *count)
  {
    return m_loc[0]->Count (m_loc,count);
  }
    LxResult
  Select (unsigned int index)
  {
    return m_loc[0]->Select (m_loc,index);
  }
    LxResult
  Lookup (const char *key)
  {
    return m_loc[0]->Lookup (m_loc,key);
  }
    LxResult
  Append (void)
  {
    return m_loc[0]->Append (m_loc);
  }
    LxResult
  Insert (const char *key)
  {
    return m_loc[0]->Insert (m_loc,key);
  }
    LxResult
  Delete (void)
  {
    return m_loc[0]->Delete (m_loc);
  }
    LxResult
  Clear (void)
  {
    return m_loc[0]->Clear (m_loc);
  }
};

#endif

