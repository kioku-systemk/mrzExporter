/*
 * C++ wrapper for lxpackage.h
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
#ifndef LXW_PACKAGE_HPP
#define LXW_PACKAGE_HPP

#include <lxpackage.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_PackageInstance = {0x09D603F7,0xCCF6,0x4A5C,0xB4,0x1C,0x02,0x1A,0xC6,0xC1,0x7A,0x94};
    static const LXtGUID guid_SceneItemListener1 = {0xBCCD05F8,0xE560,0x11D7,0xB3,0xB8,0x00,0x03,0x93,0xCE,0x96,0x80};
    static const LXtGUID guid_AddChannel = {0x6E732ACC,0xAAA5,0x4695,0xB5,0xDE,0x80,0x59,0xA2,0x80,0x05,0x54};
    static const LXtGUID guid_Scene1 = {0x4340A8FC,0xF984,0x4E04,0xA4,0xBB,0x83,0x93,0x1A,0x63,0x35,0xAF};
    static const LXtGUID guid_SceneLoaderTarget = {0xA914B4F9,0x947C,0x4334,0x9D,0x89,0x64,0xBB,0x8D,0xC2,0x6B,0xF6};
    static const LXtGUID guid_SceneItemListener = {0xC72C641E,0xCDCD,0x431B,0xAD,0xD9,0xD7,0x55,0x54,0xD6,0x56,0xE1};
    static const LXtGUID guid_Item1 = {0x5B14C8B6,0x29EF,0x473A,0xB1,0xB3,0x56,0x8D,0xFD,0x9A,0xE8,0xD7};
    static const LXtGUID guid_Package = {0x6383211E,0x2624,0x492e,0x8C,0x4B,0xD0,0x6B,0xB4,0x38,0x86,0xA7};
};

class CLxImpl_PackageInstance {
  public:
    virtual ~CLxImpl_PackageInstance() {}
    virtual LxResult
      pins_Initialize (ILxUnknownID item, ILxUnknownID super)
        { return LXe_NOTIMPL; }
    virtual void
      pins_Cleanup (void)
        { }
    virtual LxResult
      pins_SynthName (char *buf, unsigned len)
        { return LXe_NOTIMPL; }
    virtual unsigned
      pins_DupType (void)
        { return 0; }
    virtual LxResult
      pins_TestParent (ILxUnknownID item)
        { return LXe_TRUE; }
    virtual LxResult
      pins_Newborn (ILxUnknownID original)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pins_Loading (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pins_AfterLoad (void)
        { return LXe_NOTIMPL; }
    virtual void
      pins_Doomed (void)
        { }
};
#define LXxD_PackageInstance_Initialize LxResult pins_Initialize (ILxUnknownID item, ILxUnknownID super)
#define LXxO_PackageInstance_Initialize LXxD_PackageInstance_Initialize LXx_OVERRIDE
#define LXxD_PackageInstance_Cleanup void pins_Cleanup (void)
#define LXxO_PackageInstance_Cleanup LXxD_PackageInstance_Cleanup LXx_OVERRIDE
#define LXxD_PackageInstance_SynthName LxResult pins_SynthName (char *buf, unsigned len)
#define LXxO_PackageInstance_SynthName LXxD_PackageInstance_SynthName LXx_OVERRIDE
#define LXxD_PackageInstance_DupType unsigned pins_DupType (void)
#define LXxO_PackageInstance_DupType LXxD_PackageInstance_DupType LXx_OVERRIDE
#define LXxD_PackageInstance_TestParent LxResult pins_TestParent (ILxUnknownID item)
#define LXxO_PackageInstance_TestParent LXxD_PackageInstance_TestParent LXx_OVERRIDE
#define LXxD_PackageInstance_Newborn LxResult pins_Newborn (ILxUnknownID original)
#define LXxO_PackageInstance_Newborn LXxD_PackageInstance_Newborn LXx_OVERRIDE
#define LXxD_PackageInstance_Loading LxResult pins_Loading (void)
#define LXxO_PackageInstance_Loading LXxD_PackageInstance_Loading LXx_OVERRIDE
#define LXxD_PackageInstance_AfterLoad LxResult pins_AfterLoad (void)
#define LXxO_PackageInstance_AfterLoad LXxD_PackageInstance_AfterLoad LXx_OVERRIDE
#define LXxD_PackageInstance_Doomed void pins_Doomed (void)
#define LXxO_PackageInstance_Doomed LXxD_PackageInstance_Doomed LXx_OVERRIDE
template <class T>
class CLxIfc_PackageInstance : public CLxInterface
{
    static LxResult
  Initialize (LXtObjectID wcom, LXtObjectID item, LXtObjectID super)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    try {
      return loc->pins_Initialize ((ILxUnknownID)item,(ILxUnknownID)super);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    loc->pins_Cleanup ();
  }
    static LxResult
  SynthName (LXtObjectID wcom, char *buf, unsigned len)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    try {
      return loc->pins_SynthName (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned
  DupType (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    return loc->pins_DupType ();
  }
    static LxResult
  TestParent (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    try {
      return loc->pins_TestParent ((ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Newborn (LXtObjectID wcom, LXtObjectID original)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    try {
      return loc->pins_Newborn ((ILxUnknownID)original);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Loading (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    try {
      return loc->pins_Loading ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AfterLoad (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    try {
      return loc->pins_AfterLoad ();
    } catch (LxResult rc) { return rc; }
  }
    static void
  Doomed (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_PackageInstance, loc);
    loc->pins_Doomed ();
  }
  ILxPackageInstance vt;
public:
  CLxIfc_PackageInstance ()
  {
    vt.Initialize = Initialize;
    vt.Cleanup = Cleanup;
    vt.SynthName = SynthName;
    vt.DupType = DupType;
    vt.TestParent = TestParent;
    vt.Newborn = Newborn;
    vt.Loading = Loading;
    vt.AfterLoad = AfterLoad;
    vt.Doomed = Doomed;
    vTable = &vt.iunk;
    iid = &lx::guid_PackageInstance;
  }
};
class CLxLoc_PackageInstance : public CLxLocalize<ILxPackageInstanceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PackageInstance() {_init();}
  CLxLoc_PackageInstance(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PackageInstance(const CLxLoc_PackageInstance &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PackageInstance;}
    LxResult
  Initialize (ILxUnknownID item, ILxUnknownID super)
  {
    return m_loc[0]->Initialize (m_loc,(ILxUnknownID)item,(ILxUnknownID)super);
  }
    void
  Cleanup (void)
  {
    m_loc[0]->Cleanup (m_loc);
  }
    LxResult
  SynthName (char *buf, unsigned len)
  {
    return m_loc[0]->SynthName (m_loc,buf,len);
  }
    LxResult
  SynthName (std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->SynthName (m_loc,buf,len);
    LXWx_SBUF2
  }
    unsigned
  DupType (void)
  {
    return m_loc[0]->DupType (m_loc);
  }
    LxResult
  TestParent (ILxUnknownID item)
  {
    return m_loc[0]->TestParent (m_loc,(ILxUnknownID)item);
  }
    LxResult
  Newborn (ILxUnknownID original)
  {
    return m_loc[0]->Newborn (m_loc,(ILxUnknownID)original);
  }
    LxResult
  Loading (void)
  {
    return m_loc[0]->Loading (m_loc);
  }
    LxResult
  AfterLoad (void)
  {
    return m_loc[0]->AfterLoad (m_loc);
  }
    void
  Doomed (void)
  {
    m_loc[0]->Doomed (m_loc);
  }
};


class CLxLoc_AddChannel : public CLxLocalize<ILxAddChannelID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AddChannel() {_init();}
  CLxLoc_AddChannel(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AddChannel(const CLxLoc_AddChannel &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AddChannel;}
    LxResult
  NewChannel (const char *name, const char *type)
  {
    return m_loc[0]->NewChannel (m_loc,name,type);
  }
    LxResult
  SetGradient (const char *inType)
  {
    return m_loc[0]->SetGradient (m_loc,inType);
  }
    LxResult
  SetStorage (const char *stType)
  {
    return m_loc[0]->SetStorage (m_loc,stType);
  }
    LxResult
  SetVector (const char *vecType)
  {
    return m_loc[0]->SetVector (m_loc,vecType);
  }
    LxResult
  SetDefault (double defFlt, int defInt)
  {
    return m_loc[0]->SetDefault (m_loc,defFlt,defInt);
  }
    LxResult
  SetDefaultVec (const double *defVec)
  {
    return m_loc[0]->SetDefaultVec (m_loc,defVec);
  }
    LxResult
  SetHint (const LXtTextValueHint *hint)
  {
    return m_loc[0]->SetHint (m_loc,hint);
  }
    LxResult
  SetDefaultObj (void **ppvObj)
  {
    return m_loc[0]->SetDefaultObj (m_loc,ppvObj);
  }
    bool
  SetDefaultObj (CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->SetDefaultObj (m_loc,&obj)) && dest.take(obj);
  }
    void
  SetInternal (void)
  {
    m_loc[0]->SetInternal (m_loc);
  }
};


class CLxLoc_SceneLoaderTarget : public CLxLocalize<ILxSceneLoaderTargetID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SceneLoaderTarget() {_init();}
  CLxLoc_SceneLoaderTarget(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SceneLoaderTarget(const CLxLoc_SceneLoaderTarget &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SceneLoaderTarget;}
    LxResult
  SetRootType (const char *typeName)
  {
    return m_loc[0]->SetRootType (m_loc,typeName);
  }
    LxResult
  SetFlags (unsigned flags)
  {
    return m_loc[0]->SetFlags (m_loc,flags);
  }
    LxResult
  ClearFlags (unsigned flags)
  {
    return m_loc[0]->ClearFlags (m_loc,flags);
  }
};

class CLxImpl_SceneItemListener {
  public:
    virtual ~CLxImpl_SceneItemListener() {}
    virtual void
      sil_SceneCreate (ILxUnknownID scene)
        { }
    virtual void
      sil_SceneDestroy (ILxUnknownID scene)
        { }
    virtual void
      sil_SceneFilename (ILxUnknownID scene, const char *filename)
        { }
    virtual void
      sil_SceneClear (ILxUnknownID scene)
        { }
    virtual void
      sil_ItemPreChange (ILxUnknownID scene)
        { }
    virtual void
      sil_ItemPostDelete (ILxUnknownID scene)
        { }
    virtual void
      sil_ItemAdd (ILxUnknownID item)
        { }
    virtual void
      sil_ItemRemove (ILxUnknownID item)
        { }
    virtual void
      sil_ItemParent (ILxUnknownID item)
        { }
    virtual void
      sil_ItemChild (ILxUnknownID item)
        { }
    virtual void
      sil_ItemAddChannel (ILxUnknownID item)
        { }
    virtual void
      sil_ItemLocal (ILxUnknownID item)
        { }
    virtual void
      sil_ItemName (ILxUnknownID item)
        { }
    virtual void
      sil_ItemSource (ILxUnknownID item)
        { }
    virtual void
      sil_ItemPackage (ILxUnknownID item)
        { }
    virtual void
      sil_ChannelValue (const char *action, ILxUnknownID item, unsigned index)
        { }
    virtual void
      sil_LinkAdd (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
        { }
    virtual void
      sil_LinkRemBefore (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
        { }
    virtual void
      sil_LinkRemAfter (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
        { }
    virtual void
      sil_LinkSet (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
        { }
    virtual void
      sil_ChanLinkAdd (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
        { }
    virtual void
      sil_ChanLinkRemBefore (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
        { }
    virtual void
      sil_ChanLinkRemAfter (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
        { }
    virtual void
      sil_ChanLinkSet (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
        { }
};
#define LXxD_SceneItemListener_SceneCreate void sil_SceneCreate (ILxUnknownID scene)
#define LXxO_SceneItemListener_SceneCreate LXxD_SceneItemListener_SceneCreate LXx_OVERRIDE
#define LXxD_SceneItemListener_SceneDestroy void sil_SceneDestroy (ILxUnknownID scene)
#define LXxO_SceneItemListener_SceneDestroy LXxD_SceneItemListener_SceneDestroy LXx_OVERRIDE
#define LXxD_SceneItemListener_SceneFilename void sil_SceneFilename (ILxUnknownID scene, const char *filename)
#define LXxO_SceneItemListener_SceneFilename LXxD_SceneItemListener_SceneFilename LXx_OVERRIDE
#define LXxD_SceneItemListener_SceneClear void sil_SceneClear (ILxUnknownID scene)
#define LXxO_SceneItemListener_SceneClear LXxD_SceneItemListener_SceneClear LXx_OVERRIDE
#define LXxD_SceneItemListener_ItemPreChange void sil_ItemPreChange (ILxUnknownID scene)
#define LXxO_SceneItemListener_ItemPreChange LXxD_SceneItemListener_ItemPreChange LXx_OVERRIDE
#define LXxD_SceneItemListener_ItemPostDelete void sil_ItemPostDelete (ILxUnknownID scene)
#define LXxO_SceneItemListener_ItemPostDelete LXxD_SceneItemListener_ItemPostDelete LXx_OVERRIDE
#define LXxD_SceneItemListener_ItemAdd void sil_ItemAdd (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemAdd LXxD_SceneItemListener_ItemAdd LXx_OVERRIDE
#define LXxD_SceneItemListener_ItemRemove void sil_ItemRemove (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemRemove LXxD_SceneItemListener_ItemRemove LXx_OVERRIDE
#define LXxD_SceneItemListener_ItemParent void sil_ItemParent (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemParent LXxD_SceneItemListener_ItemParent LXx_OVERRIDE
#define LXxD_SceneItemListener_ItemChild void sil_ItemChild (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemChild LXxD_SceneItemListener_ItemChild LXx_OVERRIDE
#define LXxD_SceneItemListener_ItemAddChannel void sil_ItemAddChannel (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemAddChannel LXxD_SceneItemListener_ItemAddChannel LXx_OVERRIDE
#define LXxD_SceneItemListener_ItemLocal void sil_ItemLocal (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemLocal LXxD_SceneItemListener_ItemLocal LXx_OVERRIDE
#define LXxD_SceneItemListener_ItemName void sil_ItemName (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemName LXxD_SceneItemListener_ItemName LXx_OVERRIDE
#define LXxD_SceneItemListener_ItemSource void sil_ItemSource (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemSource LXxD_SceneItemListener_ItemSource LXx_OVERRIDE
#define LXxD_SceneItemListener_ItemPackage void sil_ItemPackage (ILxUnknownID item)
#define LXxO_SceneItemListener_ItemPackage LXxD_SceneItemListener_ItemPackage LXx_OVERRIDE
#define LXxD_SceneItemListener_ChannelValue void sil_ChannelValue (const char *action, ILxUnknownID item, unsigned index)
#define LXxO_SceneItemListener_ChannelValue LXxD_SceneItemListener_ChannelValue LXx_OVERRIDE
#define LXxD_SceneItemListener_LinkAdd void sil_LinkAdd (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
#define LXxO_SceneItemListener_LinkAdd LXxD_SceneItemListener_LinkAdd LXx_OVERRIDE
#define LXxD_SceneItemListener_LinkRemBefore void sil_LinkRemBefore (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
#define LXxO_SceneItemListener_LinkRemBefore LXxD_SceneItemListener_LinkRemBefore LXx_OVERRIDE
#define LXxD_SceneItemListener_LinkRemAfter void sil_LinkRemAfter (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
#define LXxO_SceneItemListener_LinkRemAfter LXxD_SceneItemListener_LinkRemAfter LXx_OVERRIDE
#define LXxD_SceneItemListener_LinkSet void sil_LinkSet (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
#define LXxO_SceneItemListener_LinkSet LXxD_SceneItemListener_LinkSet LXx_OVERRIDE
#define LXxD_SceneItemListener_ChanLinkAdd void sil_ChanLinkAdd (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
#define LXxO_SceneItemListener_ChanLinkAdd LXxD_SceneItemListener_ChanLinkAdd LXx_OVERRIDE
#define LXxD_SceneItemListener_ChanLinkRemBefore void sil_ChanLinkRemBefore (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
#define LXxO_SceneItemListener_ChanLinkRemBefore LXxD_SceneItemListener_ChanLinkRemBefore LXx_OVERRIDE
#define LXxD_SceneItemListener_ChanLinkRemAfter void sil_ChanLinkRemAfter (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
#define LXxO_SceneItemListener_ChanLinkRemAfter LXxD_SceneItemListener_ChanLinkRemAfter LXx_OVERRIDE
#define LXxD_SceneItemListener_ChanLinkSet void sil_ChanLinkSet (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
#define LXxO_SceneItemListener_ChanLinkSet LXxD_SceneItemListener_ChanLinkSet LXx_OVERRIDE
template <class T>
class CLxIfc_SceneItemListener : public CLxInterface
{
    static void
  SceneCreate (LXtObjectID wcom, LXtObjectID scene)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_SceneCreate ((ILxUnknownID)scene);
  }
    static void
  SceneDestroy (LXtObjectID wcom, LXtObjectID scene)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_SceneDestroy ((ILxUnknownID)scene);
  }
    static void
  SceneFilename (LXtObjectID wcom, LXtObjectID scene, const char *filename)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_SceneFilename ((ILxUnknownID)scene,filename);
  }
    static void
  SceneClear (LXtObjectID wcom, LXtObjectID scene)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_SceneClear ((ILxUnknownID)scene);
  }
    static void
  ItemPreChange (LXtObjectID wcom, LXtObjectID scene)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemPreChange ((ILxUnknownID)scene);
  }
    static void
  ItemPostDelete (LXtObjectID wcom, LXtObjectID scene)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemPostDelete ((ILxUnknownID)scene);
  }
    static void
  ItemAdd (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemAdd ((ILxUnknownID)item);
  }
    static void
  ItemRemove (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemRemove ((ILxUnknownID)item);
  }
    static void
  ItemParent (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemParent ((ILxUnknownID)item);
  }
    static void
  ItemChild (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemChild ((ILxUnknownID)item);
  }
    static void
  ItemAddChannel (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemAddChannel ((ILxUnknownID)item);
  }
    static void
  ItemLocal (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemLocal ((ILxUnknownID)item);
  }
    static void
  ItemName (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemName ((ILxUnknownID)item);
  }
    static void
  ItemSource (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemSource ((ILxUnknownID)item);
  }
    static void
  ItemPackage (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ItemPackage ((ILxUnknownID)item);
  }
    static void
  ChannelValue (LXtObjectID wcom, const char *action, LXtObjectID item, unsigned index)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ChannelValue (action,(ILxUnknownID)item,index);
  }
    static void
  LinkAdd (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, LXtObjectID itemTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_LinkAdd (graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    static void
  LinkRemBefore (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, LXtObjectID itemTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_LinkRemBefore (graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    static void
  LinkRemAfter (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, LXtObjectID itemTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_LinkRemAfter (graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    static void
  LinkSet (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, LXtObjectID itemTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_LinkSet (graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    static void
  ChanLinkAdd (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, unsigned chanFrom, LXtObjectID itemTo, unsigned chanTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ChanLinkAdd (graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
    static void
  ChanLinkRemBefore (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, unsigned chanFrom, LXtObjectID itemTo, unsigned chanTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ChanLinkRemBefore (graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
    static void
  ChanLinkRemAfter (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, unsigned chanFrom, LXtObjectID itemTo, unsigned chanTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ChanLinkRemAfter (graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
    static void
  ChanLinkSet (LXtObjectID wcom, const char *graph, LXtObjectID itemFrom, unsigned chanFrom, LXtObjectID itemTo, unsigned chanTo)
  {
    LXCWxINST (CLxImpl_SceneItemListener, loc);
    loc->sil_ChanLinkSet (graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
  ILxSceneItemListener vt;
public:
  CLxIfc_SceneItemListener ()
  {
    vt.SceneCreate = SceneCreate;
    vt.SceneDestroy = SceneDestroy;
    vt.SceneFilename = SceneFilename;
    vt.SceneClear = SceneClear;
    vt.ItemPreChange = ItemPreChange;
    vt.ItemPostDelete = ItemPostDelete;
    vt.ItemAdd = ItemAdd;
    vt.ItemRemove = ItemRemove;
    vt.ItemParent = ItemParent;
    vt.ItemChild = ItemChild;
    vt.ItemAddChannel = ItemAddChannel;
    vt.ItemLocal = ItemLocal;
    vt.ItemName = ItemName;
    vt.ItemSource = ItemSource;
    vt.ItemPackage = ItemPackage;
    vt.ChannelValue = ChannelValue;
    vt.LinkAdd = LinkAdd;
    vt.LinkRemBefore = LinkRemBefore;
    vt.LinkRemAfter = LinkRemAfter;
    vt.LinkSet = LinkSet;
    vt.ChanLinkAdd = ChanLinkAdd;
    vt.ChanLinkRemBefore = ChanLinkRemBefore;
    vt.ChanLinkRemAfter = ChanLinkRemAfter;
    vt.ChanLinkSet = ChanLinkSet;
    vTable = &vt.iunk;
    iid = &lx::guid_SceneItemListener;
  }
};
class CLxLoc_SceneItemListener : public CLxLocalize<ILxSceneItemListenerID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SceneItemListener() {_init();}
  CLxLoc_SceneItemListener(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SceneItemListener(const CLxLoc_SceneItemListener &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SceneItemListener;}
    void
  SceneCreate (ILxUnknownID scene)
  {
    m_loc[0]->SceneCreate (m_loc,(ILxUnknownID)scene);
  }
    void
  SceneDestroy (ILxUnknownID scene)
  {
    m_loc[0]->SceneDestroy (m_loc,(ILxUnknownID)scene);
  }
    void
  SceneFilename (ILxUnknownID scene, const char *filename)
  {
    m_loc[0]->SceneFilename (m_loc,(ILxUnknownID)scene,filename);
  }
    void
  SceneClear (ILxUnknownID scene)
  {
    m_loc[0]->SceneClear (m_loc,(ILxUnknownID)scene);
  }
    void
  ItemPreChange (ILxUnknownID scene)
  {
    m_loc[0]->ItemPreChange (m_loc,(ILxUnknownID)scene);
  }
    void
  ItemPostDelete (ILxUnknownID scene)
  {
    m_loc[0]->ItemPostDelete (m_loc,(ILxUnknownID)scene);
  }
    void
  ItemAdd (ILxUnknownID item)
  {
    m_loc[0]->ItemAdd (m_loc,(ILxUnknownID)item);
  }
    void
  ItemRemove (ILxUnknownID item)
  {
    m_loc[0]->ItemRemove (m_loc,(ILxUnknownID)item);
  }
    void
  ItemParent (ILxUnknownID item)
  {
    m_loc[0]->ItemParent (m_loc,(ILxUnknownID)item);
  }
    void
  ItemChild (ILxUnknownID item)
  {
    m_loc[0]->ItemChild (m_loc,(ILxUnknownID)item);
  }
    void
  ItemAddChannel (ILxUnknownID item)
  {
    m_loc[0]->ItemAddChannel (m_loc,(ILxUnknownID)item);
  }
    void
  ItemLocal (ILxUnknownID item)
  {
    m_loc[0]->ItemLocal (m_loc,(ILxUnknownID)item);
  }
    void
  ItemName (ILxUnknownID item)
  {
    m_loc[0]->ItemName (m_loc,(ILxUnknownID)item);
  }
    void
  ItemSource (ILxUnknownID item)
  {
    m_loc[0]->ItemSource (m_loc,(ILxUnknownID)item);
  }
    void
  ItemPackage (ILxUnknownID item)
  {
    m_loc[0]->ItemPackage (m_loc,(ILxUnknownID)item);
  }
    void
  ChannelValue (const char *action, ILxUnknownID item, unsigned index)
  {
    m_loc[0]->ChannelValue (m_loc,action,(ILxUnknownID)item,index);
  }
    void
  LinkAdd (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
  {
    m_loc[0]->LinkAdd (m_loc,graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    void
  LinkRemBefore (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
  {
    m_loc[0]->LinkRemBefore (m_loc,graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    void
  LinkRemAfter (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
  {
    m_loc[0]->LinkRemAfter (m_loc,graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    void
  LinkSet (const char *graph, ILxUnknownID itemFrom, ILxUnknownID itemTo)
  {
    m_loc[0]->LinkSet (m_loc,graph,(ILxUnknownID)itemFrom,(ILxUnknownID)itemTo);
  }
    void
  ChanLinkAdd (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
  {
    m_loc[0]->ChanLinkAdd (m_loc,graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
    void
  ChanLinkRemBefore (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
  {
    m_loc[0]->ChanLinkRemBefore (m_loc,graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
    void
  ChanLinkRemAfter (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
  {
    m_loc[0]->ChanLinkRemAfter (m_loc,graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
    void
  ChanLinkSet (const char *graph, ILxUnknownID itemFrom, unsigned chanFrom, ILxUnknownID itemTo, unsigned chanTo)
  {
    m_loc[0]->ChanLinkSet (m_loc,graph,(ILxUnknownID)itemFrom,chanFrom,(ILxUnknownID)itemTo,chanTo);
  }
};


class CLxImpl_Package {
  public:
    virtual ~CLxImpl_Package() {}
    virtual LxResult
      pkg_SetupChannels (ILxUnknownID addChan)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pkg_Attach (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pkg_TestInterface (const LXtGUID *guid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pkg_PostLoad (ILxUnknownID scene)
        { return LXe_NOTIMPL; }
};
#define LXxD_Package_SetupChannels LxResult pkg_SetupChannels (ILxUnknownID addChan)
#define LXxO_Package_SetupChannels LXxD_Package_SetupChannels LXx_OVERRIDE
#define LXxD_Package_Attach LxResult pkg_Attach (void **ppvObj)
#define LXxO_Package_Attach LXxD_Package_Attach LXx_OVERRIDE
#define LXxD_Package_TestInterface LxResult pkg_TestInterface (const LXtGUID *guid)
#define LXxO_Package_TestInterface LXxD_Package_TestInterface LXx_OVERRIDE
#define LXxD_Package_PostLoad LxResult pkg_PostLoad (ILxUnknownID scene)
#define LXxO_Package_PostLoad LXxD_Package_PostLoad LXx_OVERRIDE
template <class T>
class CLxIfc_Package : public CLxInterface
{
    static LxResult
  SetupChannels (LXtObjectID wcom, LXtObjectID addChan)
  {
    LXCWxINST (CLxImpl_Package, loc);
    try {
      return loc->pkg_SetupChannels ((ILxUnknownID)addChan);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Attach (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Package, loc);
    try {
      return loc->pkg_Attach (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TestInterface (LXtObjectID wcom, const LXtGUID *guid)
  {
    LXCWxINST (CLxImpl_Package, loc);
    try {
      return loc->pkg_TestInterface (guid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostLoad (LXtObjectID wcom, LXtObjectID scene)
  {
    LXCWxINST (CLxImpl_Package, loc);
    try {
      return loc->pkg_PostLoad ((ILxUnknownID)scene);
    } catch (LxResult rc) { return rc; }
  }
  ILxPackage vt;
public:
  CLxIfc_Package ()
  {
    vt.SetupChannels = SetupChannels;
    vt.Attach = Attach;
    vt.TestInterface = TestInterface;
    vt.PostLoad = PostLoad;
    vTable = &vt.iunk;
    iid = &lx::guid_Package;
  }
};
class CLxLoc_Package : public CLxLocalize<ILxPackageID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Package() {_init();}
  CLxLoc_Package(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Package(const CLxLoc_Package &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Package;}
    LxResult
  SetupChannels (ILxUnknownID addChan)
  {
    return m_loc[0]->SetupChannels (m_loc,(ILxUnknownID)addChan);
  }
    LxResult
  Attach (void **ppvObj)
  {
    return m_loc[0]->Attach (m_loc,ppvObj);
  }
    LxResult
  TestInterface (const LXtGUID *guid)
  {
    return m_loc[0]->TestInterface (m_loc,guid);
  }
    LxResult
  PostLoad (ILxUnknownID scene)
  {
    return m_loc[0]->PostLoad (m_loc,(ILxUnknownID)scene);
  }
};

#endif

