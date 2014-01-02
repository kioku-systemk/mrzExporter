/*
 * C++ wrapper for lxseltypes.h
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
#ifndef LXW_SELTYPES_HPP
#define LXW_SELTYPES_HPP

#include <lxseltypes.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_VMapPacketTranslation = {0xBBCB6B90,0x9586,0x11D9,0xA3,0xB8,0x00,0x0A,0x95,0x6C,0x2E,0x10};
    static const LXtGUID guid_VertexPacketTranslation = {0xD77B8382,0x9572,0x11D9,0xAF,0xDE,0x00,0x0A,0x95,0x6C,0x2E,0x10};
    static const LXtGUID guid_PolygonPacketTranslation = {0x2E0929DC,0x9583,0x11D9,0xB0,0x58,0x00,0x0A,0x95,0x6C,0x2E,0x10};
    static const LXtGUID guid_PresetPathPacketTranslation = {0x6b95c2ac,0x9a9e,0x471f,0x97,0x71,0xcf,0x10,0xfd,0x5c,0x6b,0xcb};
    static const LXtGUID guid_ScenePacketTranslation = {0xA63F8E08,0x94D8,0x11D9,0x96,0xD3,0x00,0x0A,0x95,0x6C,0x2E,0x10};
    static const LXtGUID guid_EdgePacketTranslation = {0xCA4DFE14,0x957E,0x11D9,0xAC,0x64,0x00,0x0A,0x95,0x6C,0x2E,0x10};
    static const LXtGUID guid_ItemPacketTranslation = {0x029663CC,0x9571,0x11D9,0xB9,0xAD,0x00,0x0A,0x95,0x6C,0x2E,0x10};
    static const LXtGUID guid_CenterPacketTranslation = {0x52B10EAB,0x9EA6,0x4F28,0x81,0xD1,0x2F,0xEC,0x51,0xE0,0x29,0x33};
    static const LXtGUID guid_PivotPacketTranslation = {0x9744D68E,0xD6CD,0x4652,0xAD,0x33,0x07,0x3A,0x24,0xE1,0x69,0x01};
    static const LXtGUID guid_ChannelPacketTranslation = {0x00DE9D39,0x6A83,0x46DC,0x9C,0x28,0x36,0x06,0x62,0x92,0x2C,0xE5};
    static const LXtGUID guid_LinkPacketTranslation = {0xEEA9F625,0xEB3C,0x43FD,0xA1,0x56,0xC8,0x55,0x2D,0x6D,0x18,0xC9};
};

class CLxLoc_VMapPacketTranslation : public CLxLocalize<ILxVMapPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VMapPacketTranslation() {_init();}
  CLxLoc_VMapPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VMapPacketTranslation(const CLxLoc_VMapPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VMapPacketTranslation;}
    LxResult
  Name (void *packet, const char **name)
  {
    return m_loc[0]->Name (m_loc,packet,name);
  }
    LxResult
  Type (void *packet, LXtID4 *type)
  {
    return m_loc[0]->Type (m_loc,packet,type);
  }
    void *
  Packet (LXtID4 type, const char *name)
  {
    return m_loc[0]->Packet (m_loc,type,name);
  }
};

class CLxLoc_VertexPacketTranslation : public CLxLocalize<ILxVertexPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_VertexPacketTranslation() {_init();}
  CLxLoc_VertexPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_VertexPacketTranslation(const CLxLoc_VertexPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_VertexPacketTranslation;}
    LxResult
  Vertex (void *packet, LXtPointID *vertex)
  {
    return m_loc[0]->Vertex (m_loc,packet,vertex);
  }
    LxResult
  Polygon (void *packet, LXtPolygonID *polygon)
  {
    return m_loc[0]->Polygon (m_loc,packet,polygon);
  }
    LxResult
  Mesh (void *packet, void **ppvObj)
  {
    return m_loc[0]->Mesh (m_loc,packet,ppvObj);
  }
    bool
  Mesh (void *packet, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Mesh (m_loc,packet,&obj)) && dest.take(obj);
  }
    void *
  Packet (LXtPointID vertex, LXtPolygonID polygon, ILxUnknownID mesh)
  {
    return m_loc[0]->Packet (m_loc,vertex,polygon,(ILxUnknownID)mesh);
  }
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    bool
  Item (void *packet, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Item (m_loc,packet,&obj)) && dest.take(obj);
  }
};

class CLxLoc_PolygonPacketTranslation : public CLxLocalize<ILxPolygonPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PolygonPacketTranslation() {_init();}
  CLxLoc_PolygonPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PolygonPacketTranslation(const CLxLoc_PolygonPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PolygonPacketTranslation;}
    LxResult
  Polygon (void *packet, LXtPolygonID *polygon)
  {
    return m_loc[0]->Polygon (m_loc,packet,polygon);
  }
    LxResult
  Mesh (void *packet, void **ppvObj)
  {
    return m_loc[0]->Mesh (m_loc,packet,ppvObj);
  }
    bool
  Mesh (void *packet, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Mesh (m_loc,packet,&obj)) && dest.take(obj);
  }
    void *
  Packet (LXtPolygonID polygon, ILxUnknownID mesh)
  {
    return m_loc[0]->Packet (m_loc,polygon,(ILxUnknownID)mesh);
  }
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    bool
  Item (void *packet, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Item (m_loc,packet,&obj)) && dest.take(obj);
  }
};

class CLxLoc_PresetPathPacketTranslation : public CLxLocalize<ILxPresetPathPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PresetPathPacketTranslation() {_init();}
  CLxLoc_PresetPathPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PresetPathPacketTranslation(const CLxLoc_PresetPathPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PresetPathPacketTranslation;}
    LxResult
  Path (void *packet, const char **path)
  {
    return m_loc[0]->Path (m_loc,packet,path);
  }
    LxResult
  Identifier (void *packet, const char **identifier)
  {
    return m_loc[0]->Identifier (m_loc,packet,identifier);
  }
    void *
  Packet (const char *path, const char *identifier)
  {
    return m_loc[0]->Packet (m_loc,path,identifier);
  }
};

class CLxLoc_ScenePacketTranslation : public CLxLocalize<ILxScenePacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ScenePacketTranslation() {_init();}
  CLxLoc_ScenePacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ScenePacketTranslation(const CLxLoc_ScenePacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ScenePacketTranslation;}
    LxResult
  Scene (void *packet, void **ppvObj)
  {
    return m_loc[0]->Scene (m_loc,packet,ppvObj);
  }
    bool
  Scene (void *packet, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Scene (m_loc,packet,&obj)) && dest.take(obj);
  }
    void *
  Packet (ILxUnknownID scene)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)scene);
  }
};

class CLxLoc_EdgePacketTranslation : public CLxLocalize<ILxEdgePacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_EdgePacketTranslation() {_init();}
  CLxLoc_EdgePacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_EdgePacketTranslation(const CLxLoc_EdgePacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_EdgePacketTranslation;}
    LxResult
  Vertices (void *packet, LXtPointID *vertexA, LXtPointID *vertexB)
  {
    return m_loc[0]->Vertices (m_loc,packet,vertexA,vertexB);
  }
    LxResult
  Polygon (void *packet, LXtPolygonID *polygon)
  {
    return m_loc[0]->Polygon (m_loc,packet,polygon);
  }
    LxResult
  Mesh (void *packet, void **ppvObj)
  {
    return m_loc[0]->Mesh (m_loc,packet,ppvObj);
  }
    bool
  Mesh (void *packet, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Mesh (m_loc,packet,&obj)) && dest.take(obj);
  }
    void *
  Packet (LXtPointID vertexA, LXtPointID vertexB, LXtPolygonID polygon, ILxUnknownID mesh)
  {
    return m_loc[0]->Packet (m_loc,vertexA,vertexB,polygon,(ILxUnknownID)mesh);
  }
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    bool
  Item (void *packet, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Item (m_loc,packet,&obj)) && dest.take(obj);
  }
};

class CLxLoc_ItemPacketTranslation : public CLxLocalize<ILxItemPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ItemPacketTranslation() {_init();}
  CLxLoc_ItemPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ItemPacketTranslation(const CLxLoc_ItemPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ItemPacketTranslation;}
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    bool
  Item (void *packet, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Item (m_loc,packet,&obj)) && dest.take(obj);
  }
    void *
  Packet (ILxUnknownID item)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)item);
  }
};

class CLxLoc_CenterPacketTranslation : public CLxLocalize<ILxCenterPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_CenterPacketTranslation() {_init();}
  CLxLoc_CenterPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_CenterPacketTranslation(const CLxLoc_CenterPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_CenterPacketTranslation;}
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    bool
  Item (void *packet, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Item (m_loc,packet,&obj)) && dest.take(obj);
  }
    void *
  Packet (ILxUnknownID item)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)item);
  }
};

class CLxLoc_PivotPacketTranslation : public CLxLocalize<ILxPivotPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PivotPacketTranslation() {_init();}
  CLxLoc_PivotPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PivotPacketTranslation(const CLxLoc_PivotPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PivotPacketTranslation;}
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    bool
  Item (void *packet, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Item (m_loc,packet,&obj)) && dest.take(obj);
  }
    unsigned int
  Type (void *packet)
  {
    return m_loc[0]->Type (m_loc,packet);
  }
    void *
  Packet (ILxUnknownID item, unsigned int type)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)item,type);
  }
};

class CLxLoc_ChannelPacketTranslation : public CLxLocalize<ILxChannelPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ChannelPacketTranslation() {_init();}
  CLxLoc_ChannelPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ChannelPacketTranslation(const CLxLoc_ChannelPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ChannelPacketTranslation;}
    LxResult
  Item (void *packet, void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,packet,ppvObj);
  }
    bool
  Item (void *packet, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Item (m_loc,packet,&obj)) && dest.take(obj);
  }
    unsigned int
  Index (void *packet)
  {
    return m_loc[0]->Index (m_loc,packet);
  }
    void *
  Packet (ILxUnknownID item, unsigned int index)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)item,index);
  }
};

class CLxLoc_LinkPacketTranslation : public CLxLocalize<ILxLinkPacketTranslationID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_LinkPacketTranslation() {_init();}
  CLxLoc_LinkPacketTranslation(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_LinkPacketTranslation(const CLxLoc_LinkPacketTranslation &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_LinkPacketTranslation;}
    LxResult
  From (void *packet, int *channel, void **ppvObj)
  {
    return m_loc[0]->From (m_loc,packet,channel,ppvObj);
  }
    bool
  From (void *packet, int *channel, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->From (m_loc,packet,channel,&obj)) && dest.take(obj);
  }
    LxResult
  To (void *packet, int *channel, void **ppvObj)
  {
    return m_loc[0]->To (m_loc,packet,channel,ppvObj);
  }
    bool
  To (void *packet, int *channel, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->To (m_loc,packet,channel,&obj)) && dest.take(obj);
  }
    void *
  Packet (ILxUnknownID fromItem, int fromChannel, ILxUnknownID toItem, int toChannel)
  {
    return m_loc[0]->Packet (m_loc,(ILxUnknownID)fromItem,fromChannel,(ILxUnknownID)toItem,toChannel);
  }
};

#endif

