/*
 * C++ wrapper for lxchannelui.h
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
#ifndef LXW_CHANNELUI_HPP
#define LXW_CHANNELUI_HPP

#include <lxchannelui.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_ChannelUIService = {0x3C3A2D98,0x7EF1,0x43F4,0x84,0x5C,0x39,0xEF,0x2D,0x8F,0x6D,0x52};
    static const LXtGUID guid_ChannelUI = {0xBF1BFE3B,0xF0F5,0x490b,0x89,0x61,0x72,0x17,0x95,0xDA,0x57,0xB4};
};

class CLxLoc_ChannelUIService : public CLxLocalizedService
{
  ILxChannelUIServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_ChannelUIService() {_init();set();}
 ~CLxLoc_ChannelUIService() {}
  void set() {m_loc=reinterpret_cast<ILxChannelUIServiceID>(lx::GetGlobal(&lx::guid_ChannelUIService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  ItemTypeName (LXtItemType typeID, unsigned useSuper, const char **name)
  {
    return m_loc[0]->ItemTypeName (m_loc,typeID,useSuper,name);
  }
    LxResult
  ItemTypeDesc (LXtItemType typeID, unsigned useSuper, const char **name)
  {
    return m_loc[0]->ItemTypeDesc (m_loc,typeID,useSuper,name);
  }
    LxResult
  ItemTypeIconText (LXtItemType typeID, unsigned useSuper, char *buf, unsigned len)
  {
    return m_loc[0]->ItemTypeIconText (m_loc,typeID,useSuper,buf,len);
  }
    LxResult
  MeshMapUserName (const char *name, unsigned addIcon, char *buf, unsigned len)
  {
    return m_loc[0]->MeshMapUserName (m_loc,name,addIcon,buf,len);
  }
};

class CLxImpl_ChannelUI {
  public:
    virtual ~CLxImpl_ChannelUI() {}
    virtual LxResult
      cui_Enabled (const char *channelName, ILxUnknownID msg, ILxUnknownID item, ILxUnknownID chanRead)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cui_DependencyCount (const char *channelName, unsigned *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cui_DependencyByIndex (const char *channelName, unsigned index, LXtItemType *depItemType, const char **depChannelName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cui_ItemEnabled (ILxUnknownID msg, ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cui_UIHints (const char *channelName, ILxUnknownID hints)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cui_UIValueHints (const char *channelName, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cui_Cookie (const char *channelName, const char *requestedFor, const char **cookie)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_ChannelUI : public CLxInterface
{
    static LxResult
  Enabled (LXtObjectID wcom, const char *channelName, LXtObjectID msg, LXtObjectID item, LXtObjectID chanRead)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_Enabled (channelName,(ILxUnknownID)msg,(ILxUnknownID)item,(ILxUnknownID)chanRead);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DependencyCount (LXtObjectID wcom, const char *channelName, unsigned *count)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_DependencyCount (channelName,count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DependencyByIndex (LXtObjectID wcom, const char *channelName, unsigned index, LXtItemType *depItemType, const char **depChannelName)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_DependencyByIndex (channelName,index,depItemType,depChannelName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ItemEnabled (LXtObjectID wcom, LXtObjectID msg, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_ItemEnabled ((ILxUnknownID)msg,(ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UIHints (LXtObjectID wcom, const char *channelName, LXtObjectID hints)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_UIHints (channelName,(ILxUnknownID)hints);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UIValueHints (LXtObjectID wcom, const char *channelName, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_UIValueHints (channelName,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Cookie (LXtObjectID wcom, const char *channelName, const char *requestedFor, const char **cookie)
  {
    LXCWxINST (CLxImpl_ChannelUI, loc);
    try {
      return loc->cui_Cookie (channelName,requestedFor,cookie);
    } catch (LxResult rc) { return rc; }
  }
  ILxChannelUI vt;
public:
  CLxIfc_ChannelUI ()
  {
    vt.Enabled = Enabled;
    vt.DependencyCount = DependencyCount;
    vt.DependencyByIndex = DependencyByIndex;
    vt.ItemEnabled = ItemEnabled;
    vt.UIHints = UIHints;
    vt.UIValueHints = UIValueHints;
    vt.Cookie = Cookie;
    vTable = &vt.iunk;
    iid = &lx::guid_ChannelUI;
  }
};
class CLxLoc_ChannelUI : public CLxLocalize<ILxChannelUIID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ChannelUI() {_init();}
  CLxLoc_ChannelUI(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ChannelUI(const CLxLoc_ChannelUI &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ChannelUI;}
    LxResult
  Enabled (const char *channelName, ILxUnknownID msg, ILxUnknownID item, ILxUnknownID chanRead)
  {
    return m_loc[0]->Enabled (m_loc,channelName,(ILxUnknownID)msg,(ILxUnknownID)item,(ILxUnknownID)chanRead);
  }
    LxResult
  DependencyCount (const char *channelName, unsigned *count)
  {
    return m_loc[0]->DependencyCount (m_loc,channelName,count);
  }
    LxResult
  DependencyByIndex (const char *channelName, unsigned index, LXtItemType *depItemType, const char **depChannelName)
  {
    return m_loc[0]->DependencyByIndex (m_loc,channelName,index,depItemType,depChannelName);
  }
    LxResult
  ItemEnabled (ILxUnknownID msg, ILxUnknownID item)
  {
    return m_loc[0]->ItemEnabled (m_loc,(ILxUnknownID)msg,(ILxUnknownID)item);
  }
    LxResult
  UIHints (const char *channelName, ILxUnknownID hints)
  {
    return m_loc[0]->UIHints (m_loc,channelName,(ILxUnknownID)hints);
  }
    LxResult
  UIValueHints (const char *channelName, void **ppvObj)
  {
    return m_loc[0]->UIValueHints (m_loc,channelName,ppvObj);
  }
    LxResult
  Cookie (const char *channelName, const char *requestedFor, const char **cookie)
  {
    return m_loc[0]->Cookie (m_loc,channelName,requestedFor,cookie);
  }
};

#endif

