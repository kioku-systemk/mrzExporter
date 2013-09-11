/*
 * C++ wrapper for lxscripts.h
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
#ifndef LXW_SCRIPTS_HPP
#define LXW_SCRIPTS_HPP

#include <lxscripts.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_ScriptManager = {0x3699E7C5,0x44B8,0x4e07,0xB8,0xCA,0xE2,0x68,0x99,0xCD,0x7B,0x3B};
    static const LXtGUID guid_ScriptLineEvent = {0xDABF6619,0xA4B5,0x4919,0x83,0x89,0x8C,0x54,0xB3,0x94,0x22,0xE4};
    static const LXtGUID guid_PlatformService = {0xB9596D64,0x8CB3,0x4943,0x84,0x15,0x7E,0xDF,0x52,0x7A,0xE5,0x13};
    static const LXtGUID guid_Script = {0x33C03F3F,0xA692,0x4bf4,0x8A,0xB4,0xC5,0xA9,0x5C,0xA7,0x93,0x0C};
    static const LXtGUID guid_ScriptSysService = {0x5046C663,0x7990,0x44d5,0x84,0xCB,0xA8,0x59,0x10,0x1B,0x1C,0x59};
    static const LXtGUID guid_TextScriptInterpreter = {0xD612FFCE,0x4B94,0x4823,0xA0,0xA7,0xCC,0x7C,0xA2,0xDD,0xC3,0xD6};
};


class CLxImpl_ScriptLineEvent {
  public:
    virtual ~CLxImpl_ScriptLineEvent() {}
    virtual LxResult
      slev_Index (unsigned int *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      slev_Script (void **ppvObj)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_ScriptLineEvent : public CLxInterface
{
    static LxResult
  Index (LXtObjectID wcom, unsigned int *index)
  {
    LXCWxINST (CLxImpl_ScriptLineEvent, loc);
    try {
      return loc->slev_Index (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Script (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ScriptLineEvent, loc);
    try {
      return loc->slev_Script (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxScriptLineEvent vt;
public:
  CLxIfc_ScriptLineEvent ()
  {
    vt.Index = Index;
    vt.Script = Script;
    vTable = &vt.iunk;
    iid = &lx::guid_ScriptLineEvent;
  }
};
class CLxLoc_ScriptLineEvent : public CLxLocalize<ILxScriptLineEventID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ScriptLineEvent() {_init();}
  CLxLoc_ScriptLineEvent(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ScriptLineEvent(const CLxLoc_ScriptLineEvent &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ScriptLineEvent;}
    LxResult
  Index (unsigned int *index)
  {
    return m_loc[0]->Index (m_loc,index);
  }
    LxResult
  Script (void **ppvObj)
  {
    return m_loc[0]->Script (m_loc,ppvObj);
  }
};

class CLxLoc_PlatformService : public CLxLocalizedService
{
  ILxPlatformServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_PlatformService() {_init();set();}
 ~CLxLoc_PlatformService() {}
  void set() {m_loc=reinterpret_cast<ILxPlatformServiceID>(lx::GetGlobal(&lx::guid_PlatformService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  LicensedTo (const char **licensee)
  {
    return m_loc[0]->LicensedTo (m_loc,licensee);
  }
    LxResult
  ExpiresIn (int *daysLeft)
  {
    return m_loc[0]->ExpiresIn (m_loc,daysLeft);
  }
    LxResult
  SerialNumber (const char **serial)
  {
    return m_loc[0]->SerialNumber (m_loc,serial);
  }
    LxResult
  NumLicenses (int *licenses)
  {
    return m_loc[0]->NumLicenses (m_loc,licenses);
  }
    LxResult
  AppName (const char **name)
  {
    return m_loc[0]->AppName (m_loc,name);
  }
    LxResult
  AppVersion (int *version)
  {
    return m_loc[0]->AppVersion (m_loc,version);
  }
    LxResult
  AppBuild (int *build)
  {
    return m_loc[0]->AppBuild (m_loc,build);
  }
    LxResult
  IsHeadless (void)
  {
    return m_loc[0]->IsHeadless (m_loc);
  }
    LxResult
  OSType (int *type)
  {
    return m_loc[0]->OSType (m_loc,type);
  }
    LxResult
  OSName (const char **name)
  {
    return m_loc[0]->OSName (m_loc,name);
  }
    LxResult
  OSVersion (const char **version)
  {
    return m_loc[0]->OSVersion (m_loc,version);
  }
    LxResult
  PathCount (int *count)
  {
    return m_loc[0]->PathCount (m_loc,count);
  }
    LxResult
  PathByIndex (int index, const char **path)
  {
    return m_loc[0]->PathByIndex (m_loc,index,path);
  }
    LxResult
  PathNameByIndex (int index, const char **name)
  {
    return m_loc[0]->PathNameByIndex (m_loc,index,name);
  }
    LxResult
  ImportPathCount (int *index)
  {
    return m_loc[0]->ImportPathCount (m_loc,index);
  }
    LxResult
  ImportPathByIndex (int index, const char **path)
  {
    return m_loc[0]->ImportPathByIndex (m_loc,index,path);
  }
    LxResult
  IsApp64Bit (void)
  {
    return m_loc[0]->IsApp64Bit (m_loc);
  }
};

class CLxImpl_Script {
  public:
    virtual ~CLxImpl_Script() {}
    virtual LxResult
      scr_Hash (const char **hash)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_UserName (const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_SetUserName (const char *userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_Desc (const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_SetDesc (const char *desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_Icon (const char **icon)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_HelpKey (const char *args, const char **key)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_Manager (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_GetBuffer (const char **buffer, unsigned int *bufferLength)
        { return LXe_NOTIMPL; }
    virtual LxResult
      scr_SetBuffer (const char *buffer, unsigned int bufferLength)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_Script : public CLxInterface
{
    static LxResult
  Hash (LXtObjectID wcom, const char **hash)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_Hash (hash);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UserName (LXtObjectID wcom, const char **userName)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_UserName (userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetUserName (LXtObjectID wcom, const char *userName)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_SetUserName (userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Desc (LXtObjectID wcom, const char **desc)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_Desc (desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetDesc (LXtObjectID wcom, const char *desc)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_SetDesc (desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Icon (LXtObjectID wcom, const char **icon)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_Icon (icon);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  HelpKey (LXtObjectID wcom, const char *args, const char **key)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_HelpKey (args,key);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Manager (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_Manager (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetBuffer (LXtObjectID wcom, const char **buffer, unsigned int *bufferLength)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_GetBuffer (buffer,bufferLength);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetBuffer (LXtObjectID wcom, const char *buffer, unsigned int bufferLength)
  {
    LXCWxINST (CLxImpl_Script, loc);
    try {
      return loc->scr_SetBuffer (buffer,bufferLength);
    } catch (LxResult rc) { return rc; }
  }
  ILxScript vt;
public:
  CLxIfc_Script ()
  {
    vt.Hash = Hash;
    vt.UserName = UserName;
    vt.SetUserName = SetUserName;
    vt.Desc = Desc;
    vt.SetDesc = SetDesc;
    vt.Icon = Icon;
    vt.HelpKey = HelpKey;
    vt.Manager = Manager;
    vt.GetBuffer = GetBuffer;
    vt.SetBuffer = SetBuffer;
    vTable = &vt.iunk;
    iid = &lx::guid_Script;
  }
};
class CLxLoc_Script : public CLxLocalize<ILxScriptID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Script() {_init();}
  CLxLoc_Script(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Script(const CLxLoc_Script &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Script;}
    LxResult
  Hash (const char **hash)
  {
    return m_loc[0]->Hash (m_loc,hash);
  }
    LxResult
  UserName (const char **userName)
  {
    return m_loc[0]->UserName (m_loc,userName);
  }
    LxResult
  SetUserName (const char *userName)
  {
    return m_loc[0]->SetUserName (m_loc,userName);
  }
    LxResult
  Desc (const char **desc)
  {
    return m_loc[0]->Desc (m_loc,desc);
  }
    LxResult
  SetDesc (const char *desc)
  {
    return m_loc[0]->SetDesc (m_loc,desc);
  }
    LxResult
  Icon (const char **icon)
  {
    return m_loc[0]->Icon (m_loc,icon);
  }
    LxResult
  HelpKey (const char *args, const char **key)
  {
    return m_loc[0]->HelpKey (m_loc,args,key);
  }
    LxResult
  Manager (void **ppvObj)
  {
    return m_loc[0]->Manager (m_loc,ppvObj);
  }
    LxResult
  GetBuffer (const char **buffer, unsigned int *bufferLength)
  {
    return m_loc[0]->GetBuffer (m_loc,buffer,bufferLength);
  }
    LxResult
  SetBuffer (const char *buffer, unsigned int bufferLength)
  {
    return m_loc[0]->SetBuffer (m_loc,buffer,bufferLength);
  }
};

class CLxLoc_ScriptSysService : public CLxLocalizedService
{
  ILxScriptSysServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_ScriptSysService() {_init();set();}
 ~CLxLoc_ScriptSysService() {}
  void set() {m_loc=reinterpret_cast<ILxScriptSysServiceID>(lx::GetGlobal(&lx::guid_ScriptSysService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  Count (unsigned int *count)
  {
    return m_loc[0]->Count (m_loc,count);
  }
    LxResult
  ByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->ByIndex (m_loc,index,ppvObj);
  }
    LxResult
  NameByIndex (unsigned int index, const char **name)
  {
    return m_loc[0]->NameByIndex (m_loc,index,name);
  }
    LxResult
  Lookup (const char *name, void **ppvObj)
  {
    return m_loc[0]->Lookup (m_loc,name,ppvObj);
  }
    LxResult
  UserName (ILxUnknownID manager, const char **name)
  {
    return m_loc[0]->UserName (m_loc,(ILxUnknownID)manager,name);
  }
    LxResult
  Desc (ILxUnknownID manager, const char **name)
  {
    return m_loc[0]->Desc (m_loc,(ILxUnknownID)manager,name);
  }
    LxResult
  ResolveAlias (const char *alias, const char **path)
  {
    return m_loc[0]->ResolveAlias (m_loc,alias,path);
  }
};

class CLxImpl_TextScriptInterpreter {
  public:
    virtual ~CLxImpl_TextScriptInterpreter() {}
    virtual LxResult
      tsi_ValidateFileType (ILxUnknownID script, const char *firstLine)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsi_Validate (ILxUnknownID script, ILxUnknownID msg)
        { return LXe_OK; }
    virtual LxResult
      tsi_Run (ILxUnknownID script, int execFlags, const char *args, ILxUnknownID msg)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_TextScriptInterpreter : public CLxInterface
{
    static LxResult
  ValidateFileType (LXtObjectID wcom, LXtObjectID script, const char *firstLine)
  {
    LXCWxINST (CLxImpl_TextScriptInterpreter, loc);
    try {
      return loc->tsi_ValidateFileType ((ILxUnknownID)script,firstLine);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Validate (LXtObjectID wcom, LXtObjectID script, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_TextScriptInterpreter, loc);
    try {
      return loc->tsi_Validate ((ILxUnknownID)script,(ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Run (LXtObjectID wcom, LXtObjectID script, int execFlags, const char *args, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_TextScriptInterpreter, loc);
    try {
      return loc->tsi_Run ((ILxUnknownID)script,execFlags,args,(ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
  ILxTextScriptInterpreter vt;
public:
  CLxIfc_TextScriptInterpreter ()
  {
    vt.ValidateFileType = ValidateFileType;
    vt.Validate = Validate;
    vt.Run = Run;
    vTable = &vt.iunk;
    iid = &lx::guid_TextScriptInterpreter;
  }
};
class CLxLoc_TextScriptInterpreter : public CLxLocalize<ILxTextScriptInterpreterID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TextScriptInterpreter() {_init();}
  CLxLoc_TextScriptInterpreter(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TextScriptInterpreter(const CLxLoc_TextScriptInterpreter &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TextScriptInterpreter;}
    LxResult
  ValidateFileType (ILxUnknownID script, const char *firstLine)
  {
    return m_loc[0]->ValidateFileType (m_loc,(ILxUnknownID)script,firstLine);
  }
    LxResult
  Validate (ILxUnknownID script, ILxUnknownID msg)
  {
    return m_loc[0]->Validate (m_loc,(ILxUnknownID)script,(ILxUnknownID)msg);
  }
    LxResult
  Run (ILxUnknownID script, int execFlags, const char *args, ILxUnknownID msg)
  {
    return m_loc[0]->Run (m_loc,(ILxUnknownID)script,execFlags,args,(ILxUnknownID)msg);
  }
};

#endif

