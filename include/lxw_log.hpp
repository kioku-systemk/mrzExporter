/*
 * C++ wrapper for lxlog.h
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
#ifndef LXW_LOG_HPP
#define LXW_LOG_HPP

#include <lxlog.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_Log = {0x1890538F,0xD64C,0x478c,0x84,0x72,0x22,0x8B,0x7C,0x9A,0xB1,0xDF};
    static const LXtGUID guid_LogEntry = {0xE83679B2,0xDB4D,0x4D90,0xB8,0x1B,0x5F,0x78,0x6D,0x21,0x2F,0xB3};
    static const LXtGUID guid_LogInfoBlock = {0xB9AEE11A,0x3501,0x4dc2,0x90,0xA6,0x41,0xF2,0x43,0x58,0x56,0xC6};
    static const LXtGUID guid_LogService = {0x0BC355C2,0x5E6B,0x49EF,0xB3,0x68,0x60,0x0D,0x9F,0x26,0xF5,0x43};
};

class CLxLoc_Log : public CLxLocalize<ILxLogID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Log() {_init();}
  CLxLoc_Log(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Log(const CLxLoc_Log &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Log;}
    LxResult
  AddEntry (ILxUnknownID entry)
  {
    return m_loc[0]->AddEntry (m_loc,(ILxUnknownID)entry);
  }
    LxResult
  RollEntry (ILxUnknownID entry)
  {
    return m_loc[0]->RollEntry (m_loc,(ILxUnknownID)entry);
  }
    LxResult
  RollClear (void)
  {
    return m_loc[0]->RollClear (m_loc);
  }
    LxResult
  EntryCount (unsigned int *count)
  {
    return m_loc[0]->EntryCount (m_loc,count);
  }
    LxResult
  EntryByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->EntryByIndex (m_loc,index,ppvObj);
  }
    ILxLogEntryID
  PeekEntryByIndex (unsigned int index)
  {
    return m_loc[0]->PeekEntryByIndex (m_loc,index);
  }
    LxResult
  GetCurrentEntry (void **ppvObj)
  {
    return m_loc[0]->GetCurrentEntry (m_loc,ppvObj);
  }
    LxResult
  SetMaxEntries (unsigned int max)
  {
    return m_loc[0]->SetMaxEntries (m_loc,max);
  }
    LxResult
  GetMaxEntries (unsigned int *max)
  {
    return m_loc[0]->GetMaxEntries (m_loc,max);
  }
    LxResult
  GetRolling (void **ppvObj)
  {
    return m_loc[0]->GetRolling (m_loc,ppvObj);
  }
    LxResult
  ClearAll (void)
  {
    return m_loc[0]->ClearAll (m_loc);
  }
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
};

class CLxLoc_LogEntry : public CLxLocalize<ILxLogEntryID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_LogEntry() {_init();}
  CLxLoc_LogEntry(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_LogEntry(const CLxLoc_LogEntry &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_LogEntry;}
    LxResult
  AddEntry (ILxUnknownID entry)
  {
    return m_loc[0]->AddEntry (m_loc,(ILxUnknownID)entry);
  }
    LxResult
  SetTitle (const char *title)
  {
    return m_loc[0]->SetTitle (m_loc,title);
  }
    LxResult
  SetDesc (const char *desc)
  {
    return m_loc[0]->SetDesc (m_loc,desc);
  }
    LxResult
  SetValue (const char *name, unsigned int index, ILxUnknownID value)
  {
    return m_loc[0]->SetValue (m_loc,name,index,(ILxUnknownID)value);
  }
    LxResult
  AddPair (const char *name, const char *value)
  {
    return m_loc[0]->AddPair (m_loc,name,value);
  }
    LxResult
  Class (unsigned int *classType)
  {
    return m_loc[0]->Class (m_loc,classType);
  }
    LxResult
  Type (LxResult *type)
  {
    return m_loc[0]->Type (m_loc,type);
  }
    LxResult
  Time (time_t *time)
  {
    return m_loc[0]->Time (m_loc,time);
  }
    LxResult
  TimeString (const char **string)
  {
    return m_loc[0]->TimeString (m_loc,string);
  }
    LxResult
  ChildCount (unsigned int *count)
  {
    return m_loc[0]->ChildCount (m_loc,count);
  }
    LxResult
  ChildByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->ChildByIndex (m_loc,index,ppvObj);
  }
    ILxLogEntryID
  PeekChildByIndex (unsigned int index)
  {
    return m_loc[0]->PeekChildByIndex (m_loc,index);
  }
    LxResult
  SubSystemCount (unsigned int *count)
  {
    return m_loc[0]->SubSystemCount (m_loc,count);
  }
    LxResult
  SubSystemByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->SubSystemByIndex (m_loc,index,ppvObj);
  }
    LxResult
  Message (const char **message)
  {
    return m_loc[0]->Message (m_loc,message);
  }
    LxResult
  Title (const char **title)
  {
    return m_loc[0]->Title (m_loc,title);
  }
    LxResult
  Desc (const char **desc)
  {
    return m_loc[0]->Desc (m_loc,desc);
  }
    LxResult
  InfoBlock (void **ppvObj)
  {
    return m_loc[0]->InfoBlock (m_loc,ppvObj);
  }
    LxResult
  InfoBlockValue (const char *name, unsigned int index, void **ppvObj)
  {
    return m_loc[0]->InfoBlockValue (m_loc,name,index,ppvObj);
  }
    LxResult
  PairCount (unsigned int *count)
  {
    return m_loc[0]->PairCount (m_loc,count);
  }
    LxResult
  PairName (unsigned int index, const char **name)
  {
    return m_loc[0]->PairName (m_loc,index,name);
  }
    LxResult
  PairValue (unsigned int index, const char **value)
  {
    return m_loc[0]->PairValue (m_loc,index,value);
  }
};

class CLxImpl_LogInfoBlock {
  public:
    virtual ~CLxImpl_LogInfoBlock() {}
    virtual LxResult
      lb_Name (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      lb_FieldCount (unsigned int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      lb_FieldName (unsigned int index, const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      lb_FieldType (unsigned int index, const char **type)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_LogInfoBlock : public CLxInterface
{
    static LxResult
  Name (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_LogInfoBlock, loc);
    try {
      return loc->lb_Name (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FieldCount (LXtObjectID wcom, unsigned int *count)
  {
    LXCWxINST (CLxImpl_LogInfoBlock, loc);
    try {
      return loc->lb_FieldCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FieldName (LXtObjectID wcom, unsigned int index, const char **name)
  {
    LXCWxINST (CLxImpl_LogInfoBlock, loc);
    try {
      return loc->lb_FieldName (index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FieldType (LXtObjectID wcom, unsigned int index, const char **type)
  {
    LXCWxINST (CLxImpl_LogInfoBlock, loc);
    try {
      return loc->lb_FieldType (index,type);
    } catch (LxResult rc) { return rc; }
  }
  ILxLogInfoBlock vt;
public:
  CLxIfc_LogInfoBlock ()
  {
    vt.Name = Name;
    vt.FieldCount = FieldCount;
    vt.FieldName = FieldName;
    vt.FieldType = FieldType;
    vTable = &vt.iunk;
    iid = &lx::guid_LogInfoBlock;
  }
};
class CLxLoc_LogInfoBlock : public CLxLocalize<ILxLogInfoBlockID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_LogInfoBlock() {_init();}
  CLxLoc_LogInfoBlock(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_LogInfoBlock(const CLxLoc_LogInfoBlock &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_LogInfoBlock;}
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  FieldCount (unsigned int *count)
  {
    return m_loc[0]->FieldCount (m_loc,count);
  }
    LxResult
  FieldName (unsigned int index, const char **name)
  {
    return m_loc[0]->FieldName (m_loc,index,name);
  }
    LxResult
  FieldType (unsigned int index, const char **type)
  {
    return m_loc[0]->FieldType (m_loc,index,type);
  }
};

class CLxLoc_LogService : public CLxLocalizedService
{
  ILxLogServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_LogService() {_init();set();}
 ~CLxLoc_LogService() {}
  void set() {m_loc=reinterpret_cast<ILxLogServiceID>(lx::GetGlobal(&lx::guid_LogService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  SubSystemCount (unsigned int *count)
  {
    return m_loc[0]->SubSystemCount (m_loc,count);
  }
    LxResult
  SubSystemByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->SubSystemByIndex (m_loc,index,ppvObj);
  }
    LxResult
  SubSystemLookup (const char *name, void **ppvObj)
  {
    return m_loc[0]->SubSystemLookup (m_loc,name,ppvObj);
  }
    LxResult
  MasterSubSystem (void **ppvObj)
  {
    return m_loc[0]->MasterSubSystem (m_loc,ppvObj);
  }
    LxResult
  InfoBlockCount (unsigned int *count)
  {
    return m_loc[0]->InfoBlockCount (m_loc,count);
  }
    LxResult
  InfoBlockByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->InfoBlockByIndex (m_loc,index,ppvObj);
  }
    LxResult
  InfoBlockLookup (const char *name, void **ppvObj)
  {
    return m_loc[0]->InfoBlockLookup (m_loc,name,ppvObj);
  }
    LxResult
  InfoBlockFieldsAreSameGroup (const char *name1, const char *name2)
  {
    return m_loc[0]->InfoBlockFieldsAreSameGroup (m_loc,name1,name2);
  }
    LxResult
  InfoBlockFieldGetParts (const char *name, const char **group, const char **sub)
  {
    return m_loc[0]->InfoBlockFieldGetParts (m_loc,name,group,sub);
  }
    LxResult
  CreateEntryMessage (LxResult type, const char *message, void **ppvObj)
  {
    return m_loc[0]->CreateEntryMessage (m_loc,type,message,ppvObj);
  }
    LxResult
  CreateEntryInfoBlock (LxResult type, const char *blockName, void **ppvObj)
  {
    return m_loc[0]->CreateEntryInfoBlock (m_loc,type,blockName,ppvObj);
  }
    LxResult
  CreateEntryPaired (LxResult type, void **ppvObj)
  {
    return m_loc[0]->CreateEntryPaired (m_loc,type,ppvObj);
  }
    LxResult
  SetMonitor (ILxUnknownID monitor)
  {
    return m_loc[0]->SetMonitor (m_loc,(ILxUnknownID)monitor);
  }
    ILxUnknownID
  AcquireMonitor (void)
  {
    return (ILxUnknownID) m_loc[0]->AcquireMonitor (m_loc);
  }
    LxResult
  EnableLogging (const char *systemName, unsigned int state)
  {
    return m_loc[0]->EnableLogging (m_loc,systemName,state);
  }
    LxResult
  IsLoggingEnabled (const char *systemName)
  {
    return m_loc[0]->IsLoggingEnabled (m_loc,systemName);
  }
    LxResult
  CreateEntryMessageFromMsgObj (ILxUnknownID msgObj, void **ppvObj)
  {
    return m_loc[0]->CreateEntryMessageFromMsgObj (m_loc,(ILxUnknownID)msgObj,ppvObj);
  }
    LxResult
  DebugLogOutput (unsigned int level, const char *line)
  {
    return m_loc[0]->DebugLogOutput (m_loc,level,line);
  }
    LxResult
  DebugLogOutputSys (unsigned int level, const char *logSystem, const char *line)
  {
    return m_loc[0]->DebugLogOutputSys (m_loc,level,logSystem,line);
  }
};

#endif

