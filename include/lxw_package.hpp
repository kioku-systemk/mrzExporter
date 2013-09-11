/*
 * C++ wrapper for lxpackage.h
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
#ifndef LXW_PACKAGE_HPP
#define LXW_PACKAGE_HPP

#include <lxpackage.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_PackageInstance = {0x09D603F7,0xCCF6,0x4A5C,0xB4,0x1C,0x02,0x1A,0xC6,0xC1,0x7A,0x94};
    static const LXtGUID guid_SceneItemListener1 = {0xBCCD05F8,0xE560,0x11D7,0xB3,0xB8,0x00,0x03,0x93,0xCE,0x96,0x80};
    static const LXtGUID guid_AddChannel = {0x6E732ACC,0xAAA5,0x4695,0xB5,0xDE,0x80,0x59,0xA2,0x80,0x05,0x54};
    static const LXtGUID guid_Package = {0x6383211E,0x2624,0x492e,0x8C,0x4B,0xD0,0x6B,0xB4,0x38,0x86,0xA7};
    static const LXtGUID guid_Item1 = {0x5B14C8B6,0x29EF,0x473A,0xB1,0xB3,0x56,0x8D,0xFD,0x9A,0xE8,0xD7};
    static const LXtGUID guid_SceneItemListener = {0xC72C641E,0xCDCD,0x431B,0xAD,0xD9,0xD7,0x55,0x54,0xD6,0x56,0xE1};
    static const LXtGUID guid_Scene1 = {0x4340A8FC,0xF984,0x4E04,0xA4,0xBB,0x83,0x93,0x1A,0x63,0x35,0xAF};
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
  SetHint (LXtTextValueHint *hint)
  {
    return m_loc[0]->SetHint (m_loc,hint);
  }
    LxResult
  SetDefaultObj (void **ppvObj)
  {
    return m_loc[0]->SetDefaultObj (m_loc,ppvObj);
  }
    void
  SetInternal (void)
  {
    m_loc[0]->SetInternal (m_loc);
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


#endif

