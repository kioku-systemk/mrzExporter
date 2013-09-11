/*
 * C++ wrapper for lxserver.h
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
#ifndef LXW_SERVER_HPP
#define LXW_SERVER_HPP

#include <lxserver.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_NeedContext = {0x7D30408C,0x74AB,0x4d87,0xB7,0x1C,0xC6,0x28,0x08,0x83,0x86,0x3C};
    static const LXtGUID guid_Factory = {0x2431A79E,0x3412,0x4B0D,0x98,0x7D,0x87,0x54,0x89,0x46,0x6C,0x58};
    static const LXtGUID guid_ServiceExtension = {0xE7C6F1A2,0x2F31,0x4FA5,0xB2,0xEF,0x42,0x1B,0xE1,0x59,0xD0,0xD8};
    static const LXtGUID guid_Module = {0xBD6F0E53,0xC903,0x46D3,0x92,0x11,0x75,0x85,0x58,0xD9,0x5C,0xAA};
    static const LXtGUID guid_TagDescription = {0x5582E0EE,0xD682,0x47BC,0xBF,0x3D,0xFB,0x14,0xD5,0x99,0x48,0xC1};
    static const LXtGUID guid_HostService = {0x525802A6,0xBF5F,0x46E9,0x98,0x63,0xC0,0x3B,0x54,0xA3,0xD9,0x08};
};

class CLxImpl_NeedContext {
  public:
    virtual ~CLxImpl_NeedContext() {}
    virtual LxResult
      need_SetContext (ILxUnknownID app)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_NeedContext : public CLxInterface
{
    static LxResult
  SetContext (LXtObjectID wcom, LXtObjectID app)
  {
    LXCWxINST (CLxImpl_NeedContext, loc);
    try {
      return loc->need_SetContext ((ILxUnknownID)app);
    } catch (LxResult rc) { return rc; }
  }
  ILxNeedContext vt;
public:
  CLxIfc_NeedContext ()
  {
    vt.SetContext = SetContext;
    vTable = &vt.iunk;
    iid = &lx::guid_NeedContext;
  }
};

class CLxImpl_Factory {
  public:
    virtual ~CLxImpl_Factory() {}
    virtual LxResult
      fac_Name (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fac_UserName (const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fac_ClassGUID (LXtGUID *guid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fac_Module (const char **module)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fac_InfoTag (const char *type, const char **value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fac_TagCount (unsigned int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fac_TagByIndex (unsigned int index, const char **type, const char **value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      fac_Spawn (void **ppvObj)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_Factory : public CLxInterface
{
    static LxResult
  Name (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_Name (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UserName (LXtObjectID wcom, const char **userName)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_UserName (userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ClassGUID (LXtObjectID wcom, LXtGUID *guid)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_ClassGUID (guid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Module (LXtObjectID wcom, const char **module)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_Module (module);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  InfoTag (LXtObjectID wcom, const char *type, const char **value)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_InfoTag (type,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TagCount (LXtObjectID wcom, unsigned int *count)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_TagCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TagByIndex (LXtObjectID wcom, unsigned int index, const char **type, const char **value)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_TagByIndex (index,type,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Spawn (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Factory, loc);
    try {
      return loc->fac_Spawn (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxFactory vt;
public:
  CLxIfc_Factory ()
  {
    vt.Name = Name;
    vt.UserName = UserName;
    vt.ClassGUID = ClassGUID;
    vt.Module = Module;
    vt.InfoTag = InfoTag;
    vt.TagCount = TagCount;
    vt.TagByIndex = TagByIndex;
    vt.Spawn = Spawn;
    vTable = &vt.iunk;
    iid = &lx::guid_Factory;
  }
};
class CLxLoc_Factory : public CLxLocalize<ILxFactoryID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Factory() {_init();}
  CLxLoc_Factory(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Factory(const CLxLoc_Factory &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Factory;}
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  UserName (const char **userName)
  {
    return m_loc[0]->UserName (m_loc,userName);
  }
    LxResult
  ClassGUID (LXtGUID *guid)
  {
    return m_loc[0]->ClassGUID (m_loc,guid);
  }
    LxResult
  Module (const char **module)
  {
    return m_loc[0]->Module (m_loc,module);
  }
    LxResult
  InfoTag (const char *type, const char **value)
  {
    return m_loc[0]->InfoTag (m_loc,type,value);
  }
    LxResult
  TagCount (unsigned int *count)
  {
    return m_loc[0]->TagCount (m_loc,count);
  }
    LxResult
  TagByIndex (unsigned int index, const char **type, const char **value)
  {
    return m_loc[0]->TagByIndex (m_loc,index,type,value);
  }
    LxResult
  Spawn (void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,ppvObj);
  }
};

class CLxImpl_ServiceExtension {
  public:
    virtual ~CLxImpl_ServiceExtension() {}
    virtual void
      ser_Dummy (void)
        { }
};
template <class T>
class CLxIfc_ServiceExtension : public CLxInterface
{
    static void
  Dummy (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ServiceExtension, loc);
    loc->ser_Dummy ();
  }
  ILxServiceExtension vt;
public:
  CLxIfc_ServiceExtension ()
  {
    vt.Dummy = Dummy;
    vTable = &vt.iunk;
    iid = &lx::guid_ServiceExtension;
  }
};

class CLxImpl_Module {
  public:
    virtual ~CLxImpl_Module() {}
    virtual LxResult
      mod_Generate (const char *name, const LXtGUID *iid, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual unsigned
      mod_IsLocked (void)
        { return 1; }
};
template <class T>
class CLxIfc_Module : public CLxInterface
{
    static LxResult
  Generate (LXtObjectID wcom, const char *name, const LXtGUID *iid, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Module, loc);
    try {
      return loc->mod_Generate (name,iid,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned
  IsLocked (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Module, loc);
    return loc->mod_IsLocked ();
  }
  ILxModule vt;
public:
  CLxIfc_Module ()
  {
    vt.Generate = Generate;
    vt.IsLocked = IsLocked;
    vTable = &vt.iunk;
    iid = &lx::guid_Module;
  }
};

class CLxImpl_TagDescription {
  public:
    virtual ~CLxImpl_TagDescription() {}
    virtual unsigned
      tag_Count (void)
        = 0;
    virtual LxResult
      tag_Describe (unsigned index, LXtTagInfoDesc *desc)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_TagDescription : public CLxInterface
{
    static unsigned
  Count (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TagDescription, loc);
    return loc->tag_Count ();
  }
    static LxResult
  Describe (LXtObjectID wcom, unsigned index, LXtTagInfoDesc *desc)
  {
    LXCWxINST (CLxImpl_TagDescription, loc);
    try {
      return loc->tag_Describe (index,desc);
    } catch (LxResult rc) { return rc; }
  }
  ILxTagDescription vt;
public:
  CLxIfc_TagDescription ()
  {
    vt.Count = Count;
    vt.Describe = Describe;
    vTable = &vt.iunk;
    iid = &lx::guid_TagDescription;
  }
};
class CLxLoc_TagDescription : public CLxLocalize<ILxTagDescriptionID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TagDescription() {_init();}
  CLxLoc_TagDescription(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TagDescription(const CLxLoc_TagDescription &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TagDescription;}
    unsigned
  Count (void)
  {
    return m_loc[0]->Count (m_loc);
  }
    LxResult
  Describe (unsigned index, LXtTagInfoDesc *desc)
  {
    return m_loc[0]->Describe (m_loc,index,desc);
  }
};

class CLxLoc_HostService : public CLxLocalizedService
{
  ILxHostServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_HostService() {_init();set();}
 ~CLxLoc_HostService() {}
  void set() {m_loc=reinterpret_cast<ILxHostServiceID>(lx::GetGlobal(&lx::guid_HostService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  LookupServer (const char *className, const char *name, unsigned allowLoad, void **ppvObj)
  {
    return m_loc[0]->LookupServer (m_loc,className,name,allowLoad,ppvObj);
  }
    LxResult
  TestServer (const char *className, const char *name)
  {
    return m_loc[0]->TestServer (m_loc,className,name);
  }
    unsigned
  NumServers (const char *className)
  {
    return m_loc[0]->NumServers (m_loc,className);
  }
    LxResult
  ServerByIndex (const char *className, unsigned index, void **ppvObj)
  {
    return m_loc[0]->ServerByIndex (m_loc,className,index,ppvObj);
  }
    LxResult
  ServerGetIndex (const char *className, const char *name, unsigned *index)
  {
    return m_loc[0]->ServerGetIndex (m_loc,className,name,index);
  }
    LxResult
  AddServer (ILxUnknownID factory)
  {
    return m_loc[0]->AddServer (m_loc,(ILxUnknownID)factory);
  }
    LxResult
  DefaultPath (const char **path)
  {
    return m_loc[0]->DefaultPath (m_loc,path);
  }
    LxResult
  SpawnForTagsOnly (void)
  {
    return m_loc[0]->SpawnForTagsOnly (m_loc);
  }
};

#endif

