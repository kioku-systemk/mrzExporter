/*
 * C++ wrapper for lxitem.h
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
#ifndef LXW_ITEM_HPP
#define LXW_ITEM_HPP

#include <lxitem.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_ChannelGraph = {0xF70C8AD7,0xC15F,0x42e7,0x98,0xF6,0x4C,0x4C,0x7F,0x6D,0x57,0x7E};
    static const LXtGUID guid_Item = {0x7FF2D6D5,0x5E28,0x4650,0x93,0xED,0x89,0xFF,0x25,0x7F,0x96,0x29};
    static const LXtGUID guid_ItemGraph = {0xC34D7C65,0x031A,0x4c9d,0x8C,0x01,0x31,0x87,0xD3,0x83,0x93,0x7B};
    static const LXtGUID guid_Scene = {0xFF870F44,0xFED9,0x4dbc,0x95,0xBA,0x29,0x72,0xA4,0x3F,0xC9,0x36};
    static const LXtGUID guid_SceneGraph = {0xFE07D3C5,0xC7E4,0x46af,0x8F,0x0A,0x5A,0xB1,0x73,0xD4,0x84,0x45};
    static const LXtGUID guid_Scene2Service = {0x3B1E02DD,0x8ACA,0x4f30,0x99,0xC4,0xF8,0x7B,0x62,0x6D,0x4F,0xA3};
    static const LXtGUID guid_SceneService = {0x50190141,0x0059,0x48FE,0xB2,0x7D,0x6C,0x98,0xE1,0x34,0x8D,0x7B};
};

class CLxLoc_ChannelGraph : public CLxLocalize<ILxChannelGraphID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ChannelGraph() {_init();}
  CLxLoc_ChannelGraph(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ChannelGraph(const CLxLoc_ChannelGraph &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ChannelGraph;}
    LxResult
  AddLink (ILxUnknownID from, int fromChan, ILxUnknownID to, int toChan)
  {
    return m_loc[0]->AddLink (m_loc,(ILxUnknownID)from,fromChan,(ILxUnknownID)to,toChan);
  }
    LxResult
  SetLink (ILxUnknownID from, int fromChan, int fromIndex, ILxUnknownID to, int toChan, int toIndex)
  {
    return m_loc[0]->SetLink (m_loc,(ILxUnknownID)from,fromChan,fromIndex,(ILxUnknownID)to,toChan,toIndex);
  }
    LxResult
  DeleteLink (ILxUnknownID from, int fromChan, ILxUnknownID to, int toChan)
  {
    return m_loc[0]->DeleteLink (m_loc,(ILxUnknownID)from,fromChan,(ILxUnknownID)to,toChan);
  }
    LxResult
  FwdCount (ILxUnknownID item, int channel, unsigned *count)
  {
    return m_loc[0]->FwdCount (m_loc,(ILxUnknownID)item,channel,count);
  }
    LxResult
  FwdByIndex (ILxUnknownID item, int channel, unsigned index, void **ppvObj, int *objChan)
  {
    return m_loc[0]->FwdByIndex (m_loc,(ILxUnknownID)item,channel,index,ppvObj,objChan);
  }
    LxResult
  RevCount (ILxUnknownID item, int channel, unsigned *count)
  {
    return m_loc[0]->RevCount (m_loc,(ILxUnknownID)item,channel,count);
  }
    LxResult
  RevByIndex (ILxUnknownID item, int channel, unsigned index, void **ppvObj, int *objChan)
  {
    return m_loc[0]->RevByIndex (m_loc,(ILxUnknownID)item,channel,index,ppvObj,objChan);
  }
};

class CLxLoc_Item : public CLxLocalize<ILxItemID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Item() {_init();}
  CLxLoc_Item(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Item(const CLxLoc_Item &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Item;}
    LXtItemType
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    LxResult
  TestType (LXtItemType type)
  {
    return m_loc[0]->TestType (m_loc,type);
  }
    LxResult
  TestTypes (LXtItemType *types)
  {
    return m_loc[0]->TestTypes (m_loc,types);
  }
    LxResult
  Ident (const char **ident) const
  {
    return m_loc[0]->Ident (m_loc,ident);
  }
    LxResult
  SetIdent (const char *ident)
  {
    return m_loc[0]->SetIdent (m_loc,ident);
  }
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  SetName (const char *name)
  {
    return m_loc[0]->SetName (m_loc,name);
  }
    LxResult
  UniqueName (const char **name)
  {
    return m_loc[0]->UniqueName (m_loc,name);
  }
    LxResult
  UniqueIndex (unsigned *index)
  {
    return m_loc[0]->UniqueIndex (m_loc,index);
  }
    LxResult
  SetUniqueIndex (unsigned index)
  {
    return m_loc[0]->SetUniqueIndex (m_loc,index);
  }
    LxResult
  Parent (void **ppvObj)
  {
    return m_loc[0]->Parent (m_loc,ppvObj);
  }
    LxResult
  SetParent (ILxUnknownID parent)
  {
    return m_loc[0]->SetParent (m_loc,(ILxUnknownID)parent);
  }
    LxResult
  SubCount (unsigned *count)
  {
    return m_loc[0]->SubCount (m_loc,count);
  }
    LxResult
  SubByIndex (unsigned index, void **ppvObj)
  {
    return m_loc[0]->SubByIndex (m_loc,index,ppvObj);
  }
    LxResult
  Root (void **ppvObj)
  {
    return m_loc[0]->Root (m_loc,ppvObj);
  }
    LxResult
  Context (void **ppvObj)
  {
    return m_loc[0]->Context (m_loc,ppvObj);
  }
    LxResult
  Reference (void **ppvObj)
  {
    return m_loc[0]->Reference (m_loc,ppvObj);
  }
    LxResult
  IsReferenced (void)
  {
    return m_loc[0]->IsReferenced (m_loc);
  }
    LxResult
  Source (void **ppvObj)
  {
    return m_loc[0]->Source (m_loc,ppvObj);
  }
    LxResult
  SetSource (ILxUnknownID source)
  {
    return m_loc[0]->SetSource (m_loc,(ILxUnknownID)source);
  }
    LxResult
  ChannelCount (unsigned *count) const
  {
    return m_loc[0]->ChannelCount (m_loc,count);
  }
    LxResult
  ChannelLookup (const char *name, unsigned *index) const
  {
    return m_loc[0]->ChannelLookup (m_loc,name,index);
  }
    LxResult
  ChannelName (unsigned index, const char **name) const
  {
    return m_loc[0]->ChannelName (m_loc,index,name);
  }
    LxResult
  ChannelType (unsigned index, unsigned *type)
  {
    return m_loc[0]->ChannelType (m_loc,index,type);
  }
    LxResult
  ChannelVectorMode (unsigned index, unsigned *mode, unsigned *components)
  {
    return m_loc[0]->ChannelVectorMode (m_loc,index,mode,components);
  }
    LxResult
  ChannelStorageType (unsigned index, const char **type)
  {
    return m_loc[0]->ChannelStorageType (m_loc,index,type);
  }
    LxResult
  ChannelEvalType (unsigned index, const char **type)
  {
    return m_loc[0]->ChannelEvalType (m_loc,index,type);
  }
    LxResult
  ChannelGradient (unsigned index, const char **input, const char **output)
  {
    return m_loc[0]->ChannelGradient (m_loc,index,input,output);
  }
    LxResult
  ChannelIntHint (unsigned index, const LXtTextValueHint **hints) const
  {
    return m_loc[0]->ChannelIntHint (m_loc,index,hints);
  }
    LxResult
  ChannelPackage (unsigned index, const char **package)
  {
    return m_loc[0]->ChannelPackage (m_loc,index,package);
  }
    LxResult
  PackageAdd (const char *package)
  {
    return m_loc[0]->PackageAdd (m_loc,package);
  }
    LxResult
  PackageTest (const char *package) const
  {
    return m_loc[0]->PackageTest (m_loc,package);
  }
    LxResult
  PackageStartIndex (const char *package, unsigned *index)
  {
    return m_loc[0]->PackageStartIndex (m_loc,package,index);
  }
    LxResult
  PackageRemove (const char *package)
  {
    return m_loc[0]->PackageRemove (m_loc,package);
  }
    LxResult
  ChannelAdd (int whatever)
  {
    return m_loc[0]->ChannelAdd (m_loc,whatever);
  }
    const char *
  GetTag (LXtID4 type)
  {
    return m_loc[0]->GetTag (m_loc,type);
  }
    LxResult
  SetTag (LXtID4 type, const char *tag)
  {
    return m_loc[0]->SetTag (m_loc,type,tag);
  }
    void
  InvalidateName (void)
  {
    m_loc[0]->InvalidateName (m_loc);
  }
    LxResult
  WasLoaded (unsigned test)
  {
    return m_loc[0]->WasLoaded (m_loc,test);
  }
};

class CLxLoc_ItemGraph : public CLxLocalize<ILxItemGraphID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ItemGraph() {_init();}
  CLxLoc_ItemGraph(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ItemGraph(const CLxLoc_ItemGraph &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ItemGraph;}
    LxResult
  AddLink (ILxUnknownID from, ILxUnknownID to)
  {
    return m_loc[0]->AddLink (m_loc,(ILxUnknownID)from,(ILxUnknownID)to);
  }
    LxResult
  SetLink (ILxUnknownID from, int fromIndex, ILxUnknownID to, int toIndex)
  {
    return m_loc[0]->SetLink (m_loc,(ILxUnknownID)from,fromIndex,(ILxUnknownID)to,toIndex);
  }
    LxResult
  DeleteLink (ILxUnknownID from, ILxUnknownID to)
  {
    return m_loc[0]->DeleteLink (m_loc,(ILxUnknownID)from,(ILxUnknownID)to);
  }
    LxResult
  FwdCount (ILxUnknownID item, unsigned *count)
  {
    return m_loc[0]->FwdCount (m_loc,(ILxUnknownID)item,count);
  }
    LxResult
  FwdByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
  {
    return m_loc[0]->FwdByIndex (m_loc,(ILxUnknownID)item,index,ppvObj);
  }
    LxResult
  RevCount (ILxUnknownID item, unsigned *count)
  {
    return m_loc[0]->RevCount (m_loc,(ILxUnknownID)item,count);
  }
    LxResult
  RevByIndex (ILxUnknownID item, unsigned index, void **ppvObj)
  {
    return m_loc[0]->RevByIndex (m_loc,(ILxUnknownID)item,index,ppvObj);
  }
};

class CLxLoc_Scene : public CLxLocalize<ILxSceneID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Scene() {_init();}
  CLxLoc_Scene(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Scene(const CLxLoc_Scene &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Scene;}
    LXtItemType
  ItemRootType (void)
  {
    return m_loc[0]->ItemRootType (m_loc);
  }
    LxResult
  Filename (const char **filename)
  {
    return m_loc[0]->Filename (m_loc,filename);
  }
    LxResult
  FriendlyFilename (unsigned flags, const char **filename)
  {
    return m_loc[0]->FriendlyFilename (m_loc,flags,filename);
  }
    LxResult
  FileFormat (const char **format)
  {
    return m_loc[0]->FileFormat (m_loc,format);
  }
    LxResult
  Changed (unsigned changed)
  {
    return m_loc[0]->Changed (m_loc,changed);
  }
    LxResult
  HasChanged (unsigned int *numChanges)
  {
    return m_loc[0]->HasChanged (m_loc,numChanges);
  }
    LxResult
  Parent (void **ppvObj)
  {
    return m_loc[0]->Parent (m_loc,ppvObj);
  }
    LxResult
  SubSceneCount (LXtItemType type, unsigned int *count)
  {
    return m_loc[0]->SubSceneCount (m_loc,type,count);
  }
    LxResult
  SubSceneByIndex (LXtItemType type, unsigned int index, void **ppvObj)
  {
    return m_loc[0]->SubSceneByIndex (m_loc,type,index,ppvObj);
  }
    unsigned
  LoadFlags (void)
  {
    return m_loc[0]->LoadFlags (m_loc);
  }
    LxResult
  Channels (const char *name, double time, void **ppvObj) const
  {
    return m_loc[0]->Channels (m_loc,name,time,ppvObj);
  }
    LxResult
  ItemCount (LXtItemType type, unsigned int *count) const
  {
    return m_loc[0]->ItemCount (m_loc,type,count);
  }
    LxResult
  ItemByIndex (LXtItemType type, unsigned int index, void **ppvObj) const
  {
    return m_loc[0]->ItemByIndex (m_loc,type,index,ppvObj);
  }
    LxResult
  ItemLookup (const char *id, void **ppvObj) const
  {
    return m_loc[0]->ItemLookup (m_loc,id,ppvObj);
  }
    LxResult
  ItemCountByTypes (LXtItemType *types, unsigned *count) const
  {
    return m_loc[0]->ItemCountByTypes (m_loc,types,count);
  }
    LxResult
  ItemByIndexByTypes (LXtItemType *types, unsigned index, void **ppvObj) const
  {
    return m_loc[0]->ItemByIndexByTypes (m_loc,types,index,ppvObj);
  }
    LxResult
  AnyItemOfType (LXtItemType type, void **ppvObj) const
  {
    return m_loc[0]->AnyItemOfType (m_loc,type,ppvObj);
  }
    LxResult
  ItemLocalize (ILxUnknownID item, void **ppvObj)
  {
    return m_loc[0]->ItemLocalize (m_loc,(ILxUnknownID)item,ppvObj);
  }
    LxResult
  ItemAdd (LXtItemType type, void **ppvObj)
  {
    return m_loc[0]->ItemAdd (m_loc,type,ppvObj);
  }
    LxResult
  ItemDuplicate (ILxUnknownID item, void **ppvObj)
  {
    return m_loc[0]->ItemDuplicate (m_loc,(ILxUnknownID)item,ppvObj);
  }
    LxResult
  ItemAddReference (ILxUnknownID item, void **ppvObj)
  {
    return m_loc[0]->ItemAddReference (m_loc,(ILxUnknownID)item,ppvObj);
  }
    LxResult
  GraphLookup (const char *name, void **ppvObj) const
  {
    return m_loc[0]->GraphLookup (m_loc,name,ppvObj);
  }
    LxResult
  GraphCount (int *count) const
  {
    return m_loc[0]->GraphCount (m_loc,count);
  }
    LxResult
  GraphByIndex (unsigned index, void **ppvObj) const
  {
    return m_loc[0]->GraphByIndex (m_loc,index,ppvObj);
  }
    LxResult
  ItemRemove (ILxUnknownID item)
  {
    return m_loc[0]->ItemRemove (m_loc,(ILxUnknownID)item);
  }
    LxResult
  Import (const char *path, ILxUnknownID monitor)
  {
    return m_loc[0]->Import (m_loc,path,(ILxUnknownID)monitor);
  }
    LxResult
  EvalModInvalidate (const char *modName)
  {
    return m_loc[0]->EvalModInvalidate (m_loc,modName);
  }
    LxResult
  EvalModReset (const char *modName)
  {
    return m_loc[0]->EvalModReset (m_loc,modName);
  }
    LxResult
  ItemReplace (ILxUnknownID item, int type, void **ppvObj)
  {
    return m_loc[0]->ItemReplace (m_loc,(ILxUnknownID)item,type,ppvObj);
  }
    LxResult
  SetupMode (void)
  {
    return m_loc[0]->SetupMode (m_loc);
  }
    LxResult
  SetupChannels (void **ppvObj) const
  {
    return m_loc[0]->SetupChannels (m_loc,ppvObj);
  }
    LxResult
  ItemLookupIdent (const char *id, void **ppvObj)
  {
    return m_loc[0]->ItemLookupIdent (m_loc,id,ppvObj);
  }
    LxResult
  ItemLookupImported (const char *id, void **ppvObj)
  {
    return m_loc[0]->ItemLookupImported (m_loc,id,ppvObj);
  }
};

class CLxLoc_SceneGraph : public CLxLocalize<ILxSceneGraphID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SceneGraph() {_init();}
  CLxLoc_SceneGraph(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SceneGraph(const CLxLoc_SceneGraph &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SceneGraph;}
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  Context (void **ppvObj)
  {
    return m_loc[0]->Context (m_loc,ppvObj);
  }
    LxResult
  RootCount (int *count)
  {
    return m_loc[0]->RootCount (m_loc,count);
  }
    LxResult
  RootByIndex (int index, void **ppvObj)
  {
    return m_loc[0]->RootByIndex (m_loc,index,ppvObj);
  }
    LxResult
  RootFirst (void **ppvObj)
  {
    return m_loc[0]->RootFirst (m_loc,ppvObj);
  }
    LxResult
  RootNext (void **ppvObj)
  {
    return m_loc[0]->RootNext (m_loc,ppvObj);
  }
    LxResult
  RootSetPos (ILxUnknownID item, int pos)
  {
    return m_loc[0]->RootSetPos (m_loc,(ILxUnknownID)item,pos);
  }
    LxResult
  RootRemove (ILxUnknownID item)
  {
    return m_loc[0]->RootRemove (m_loc,(ILxUnknownID)item);
  }
};


class CLxLoc_SceneService : public CLxLocalizedService
{
  ILxSceneServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_SceneService() {_init();set();}
 ~CLxLoc_SceneService() {}
  void set() {m_loc=reinterpret_cast<ILxSceneServiceID>(lx::GetGlobal(&lx::guid_SceneService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  Root (void **ppvObj)
  {
    return m_loc[0]->Root (m_loc,ppvObj);
  }
    unsigned
  ItemTypeCount (void)
  {
    return m_loc[0]->ItemTypeCount (m_loc);
  }
    LxResult
  ItemTypeByIndex (unsigned index, LXtItemType *type)
  {
    return m_loc[0]->ItemTypeByIndex (m_loc,index,type);
  }
    LxResult
  ItemTypeLookup (const char *name, LXtItemType *type)
  {
    return m_loc[0]->ItemTypeLookup (m_loc,name,type);
  }
    LxResult
  ItemTypeName (LXtItemType type, const char **name)
  {
    return m_loc[0]->ItemTypeName (m_loc,type,name);
  }
    LxResult
  ItemTypeTest (LXtItemType what, LXtItemType isA)
  {
    return m_loc[0]->ItemTypeTest (m_loc,what,isA);
  }
    LxResult
  ItemTypeSuper (LXtItemType type, LXtItemType *super)
  {
    return m_loc[0]->ItemTypeSuper (m_loc,type,super);
  }
    LxResult
  ItemTypeCommonChannels (ILxUnknownID item1, ILxUnknownID item2, unsigned *count)
  {
    return m_loc[0]->ItemTypeCommonChannels (m_loc,(ILxUnknownID)item1,(ILxUnknownID)item2,count);
  }
    LxResult
  ItemSubTypeCount (LXtItemType type, unsigned int *count)
  {
    return m_loc[0]->ItemSubTypeCount (m_loc,type,count);
  }
    LxResult
  ItemSubTypeByIndex (LXtItemType type, unsigned int index, const char **subtype)
  {
    return m_loc[0]->ItemSubTypeByIndex (m_loc,type,index,subtype);
  }
    LxResult
  ChannelVectorSize (unsigned int mode, unsigned int *size)
  {
    return m_loc[0]->ChannelVectorSize (m_loc,mode,size);
  }
    LxResult
  ChannelVectorTextHints (const LXtTextValueHint **hints)
  {
    return m_loc[0]->ChannelVectorTextHints (m_loc,hints);
  }
    LxResult
  CreateScene (void **ppvObj)
  {
    return m_loc[0]->CreateScene (m_loc,ppvObj);
  }
    LxResult
  DestroyScene (ILxUnknownID scene)
  {
    return m_loc[0]->DestroyScene (m_loc,(ILxUnknownID)scene);
  }
    LxResult
  SubSceneAdd (ILxUnknownID scene, ILxUnknownID other, unsigned refItems)
  {
    return m_loc[0]->SubSceneAdd (m_loc,(ILxUnknownID)scene,(ILxUnknownID)other,refItems);
  }
    LxResult
  SubSceneLoad (ILxUnknownID scene, const char *path, ILxUnknownID monitor, void **ppvObj)
  {
    return m_loc[0]->SubSceneLoad (m_loc,(ILxUnknownID)scene,path,(ILxUnknownID)monitor,ppvObj);
  }
    LxResult
  GetMeshInstSourceItem (ILxUnknownID inst, void **ppvObj)
  {
    return m_loc[0]->GetMeshInstSourceItem (m_loc,(ILxUnknownID)inst,ppvObj);
  }
    int
  MeshInstanceCount (ILxUnknownID mesh)
  {
    return m_loc[0]->MeshInstanceCount (m_loc,(ILxUnknownID)mesh);
  }
    LxResult
  MeshInstanceByIndex (ILxUnknownID mesh, int index, void **ppvObj)
  {
    return m_loc[0]->MeshInstanceByIndex (m_loc,(ILxUnknownID)mesh,index,ppvObj);
  }
    LxResult
  LoadImage (ILxUnknownID scene, const char *name, unsigned *flags, ILxUnknownID monitor, void **ppvObj)
  {
    return m_loc[0]->LoadImage (m_loc,(ILxUnknownID)scene,name,flags,(ILxUnknownID)monitor,ppvObj);
  }
    LxResult
  GetReplicatorEnumerator (ILxUnknownID replicatorItem, void **ppvObj)
  {
    return m_loc[0]->GetReplicatorEnumerator (m_loc,(ILxUnknownID)replicatorItem,ppvObj);
  }
};

#endif

