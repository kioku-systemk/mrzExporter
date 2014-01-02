/*
 * C++ wrapper for lxmesh.h
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
#ifndef LXW_MESH_HPP
#define LXW_MESH_HPP

#include <lxmesh.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_MeshFilterBBox = {0xFBD83166,0x4B50,0x42A0,0x8C,0x91,0xC3,0x6D,0x3B,0xB7,0x69,0x04};
    static const LXtGUID guid_MeshFilter = {0xF5896BA1,0x7EC5,0x4EE9,0x85,0x2F,0xBF,0x97,0x7E,0x45,0x19,0x53};
    static const LXtGUID guid_MeshMap = {0x2AEBA454,0x2AC4,0x4F1E,0xB8,0x92,0x7A,0x16,0xF7,0x60,0x10,0x30};
    static const LXtGUID guid_Mesh = {0x1F1BB7BF,0xA862,0x4810,0x95,0xFF,0x33,0x46,0xAF,0x73,0x82,0x09};
    static const LXtGUID guid_MeshService = {0x82B739EC,0xF92E,0x4CC9,0xA5,0xFB,0x58,0x4A,0x86,0x6D,0x58,0x97};
    static const LXtGUID guid_Polygon = {0x5839056D,0x28BF,0x4D72,0x8A,0x26,0xE4,0xAA,0x00,0xDA,0x78,0x8F};
    static const LXtGUID guid_MeshListener = {0x957900AC,0xBC06,0x45D9,0xB1,0xB1,0x9C,0xC5,0xA2,0xAE,0xC0,0x26};
    static const LXtGUID guid_Point = {0x37B477FE,0xED3C,0x4EDC,0xA4,0xA8,0x9B,0xB2,0x4F,0x58,0xA4,0xE6};
    static const LXtGUID guid_Edge = {0x19A44432,0xE2CF,0x4BCF,0x9E,0xA6,0xD6,0x96,0xE7,0xA0,0xF1,0x6E};
};

class CLxImpl_MeshFilterBBox {
  public:
    virtual ~CLxImpl_MeshFilterBBox() {}
    virtual LxResult
      mfbbox_Evaluate (LXtBBox *box)
        { return LXe_NOTIMPL; }
};
#define LXxD_MeshFilterBBox_Evaluate LxResult mfbbox_Evaluate (LXtBBox *box)
#define LXxO_MeshFilterBBox_Evaluate LXxD_MeshFilterBBox_Evaluate LXx_OVERRIDE
template <class T>
class CLxIfc_MeshFilterBBox : public CLxInterface
{
    static LxResult
  Evaluate (LXtObjectID wcom, LXtBBox *box)
  {
    LXCWxINST (CLxImpl_MeshFilterBBox, loc);
    try {
      return loc->mfbbox_Evaluate (box);
    } catch (LxResult rc) { return rc; }
  }
  ILxMeshFilterBBox vt;
public:
  CLxIfc_MeshFilterBBox ()
  {
    vt.Evaluate = Evaluate;
    vTable = &vt.iunk;
    iid = &lx::guid_MeshFilterBBox;
  }
};
class CLxLoc_MeshFilterBBox : public CLxLocalize<ILxMeshFilterBBoxID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshFilterBBox() {_init();}
  CLxLoc_MeshFilterBBox(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshFilterBBox(const CLxLoc_MeshFilterBBox &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshFilterBBox;}
    LxResult
  Evaluate (LXtBBox *box)
  {
    return m_loc[0]->Evaluate (m_loc,box);
  }
};

class CLxImpl_MeshFilter {
  public:
    virtual ~CLxImpl_MeshFilter() {}
    virtual unsigned
      mfilt_Type (void)
        = 0;
    virtual LxResult
      mfilt_Evaluate (ILxUnknownID mesh)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mfilt_Generate (void **ppvObj)
        { return LXe_NOTIMPL; }
};
#define LXxD_MeshFilter_Type unsigned mfilt_Type (void)
#define LXxO_MeshFilter_Type LXxD_MeshFilter_Type LXx_OVERRIDE
#define LXxD_MeshFilter_Evaluate LxResult mfilt_Evaluate (ILxUnknownID mesh)
#define LXxO_MeshFilter_Evaluate LXxD_MeshFilter_Evaluate LXx_OVERRIDE
#define LXxD_MeshFilter_Generate LxResult mfilt_Generate (void **ppvObj)
#define LXxO_MeshFilter_Generate LXxD_MeshFilter_Generate LXx_OVERRIDE
template <class T>
class CLxIfc_MeshFilter : public CLxInterface
{
    static unsigned
  Type (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_MeshFilter, loc);
    return loc->mfilt_Type ();
  }
    static LxResult
  Evaluate (LXtObjectID wcom, LXtObjectID mesh)
  {
    LXCWxINST (CLxImpl_MeshFilter, loc);
    try {
      return loc->mfilt_Evaluate ((ILxUnknownID)mesh);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Generate (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_MeshFilter, loc);
    try {
      return loc->mfilt_Generate (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxMeshFilter vt;
public:
  CLxIfc_MeshFilter ()
  {
    vt.Type = Type;
    vt.Evaluate = Evaluate;
    vt.Generate = Generate;
    vTable = &vt.iunk;
    iid = &lx::guid_MeshFilter;
  }
};
class CLxLoc_MeshFilter : public CLxLocalize<ILxMeshFilterID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshFilter() {_init();}
  CLxLoc_MeshFilter(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshFilter(const CLxLoc_MeshFilter &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshFilter;}
    unsigned
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    LxResult
  Evaluate (ILxUnknownID mesh)
  {
    return m_loc[0]->Evaluate (m_loc,(ILxUnknownID)mesh);
  }
    LxResult
  Generate (void **ppvObj)
  {
    return m_loc[0]->Generate (m_loc,ppvObj);
  }
    bool
  Generate (CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Generate (m_loc,&obj)) && dest.take(obj);
  }
};

class CLxLoc_MeshMap : public CLxLocalize<ILxMeshMapID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshMap() {_init();}
  CLxLoc_MeshMap(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_MeshMap(const CLxLoc_MeshMap &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_MeshMap;}
    LxResult
  Spawn (void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,ppvObj);
  }
    bool
  Spawn (CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Spawn (m_loc,&obj)) && dest.take(obj);
  }
    LxResult
  Enumerate (LXtMarkMode mode, ILxUnknownID visitor, ILxUnknownID monitor)
  {
    return m_loc[0]->Enumerate (m_loc,mode,(ILxUnknownID)visitor,(ILxUnknownID)monitor);
  }
    LxResult
  Select (LXtMeshMapID map)
  {
    return m_loc[0]->Select (m_loc,map);
  }
    LxResult
  SelectByName (LXtID4 type, const char *name)
  {
    return m_loc[0]->SelectByName (m_loc,type,name);
  }
    LxResult
  FilterByType (LXtID4 type)
  {
    return m_loc[0]->FilterByType (m_loc,type);
  }
    LXtMeshMapID
  ID (void)
  {
    return m_loc[0]->ID (m_loc);
  }
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  Type (LXtID4 *type)
  {
    return m_loc[0]->Type (m_loc,type);
  }
    LxResult
  Dimension (unsigned int *dimension)
  {
    return m_loc[0]->Dimension (m_loc,dimension);
  }
    LxResult
  IsEdgeMap (void)
  {
    return m_loc[0]->IsEdgeMap (m_loc);
  }
    LxResult
  IsContinuous (void)
  {
    return m_loc[0]->IsContinuous (m_loc);
  }
    LxResult
  ZeroDefault (void)
  {
    return m_loc[0]->ZeroDefault (m_loc);
  }
    LxResult
  New (LXtID4 type, const char *name, LXtMeshMapID *mapID)
  {
    return m_loc[0]->New (m_loc,type,name,mapID);
  }
    LxResult
  Remove (void)
  {
    return m_loc[0]->Remove (m_loc);
  }
    LxResult
  Clear (void)
  {
    return m_loc[0]->Clear (m_loc);
  }
    LxResult
  EnumerateContinuous (ILxUnknownID visitor, ILxUnknownID point)
  {
    return m_loc[0]->EnumerateContinuous (m_loc,(ILxUnknownID)visitor,(ILxUnknownID)point);
  }
    LxResult
  EnumerateDiscontinuous (ILxUnknownID visitor, ILxUnknownID point, ILxUnknownID poly)
  {
    return m_loc[0]->EnumerateDiscontinuous (m_loc,(ILxUnknownID)visitor,(ILxUnknownID)point,(ILxUnknownID)poly);
  }
    LxResult
  EnumerateEdges (ILxUnknownID visitor, ILxUnknownID edge)
  {
    return m_loc[0]->EnumerateEdges (m_loc,(ILxUnknownID)visitor,(ILxUnknownID)edge);
  }
};

class CLxLoc_Mesh : public CLxLocalize<ILxMeshID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Mesh() {_init();}
  CLxLoc_Mesh(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Mesh(const CLxLoc_Mesh &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Mesh;}
    LxResult
  PointCount (unsigned int *count) const
  {
    return m_loc[0]->PointCount (m_loc,count);
  }
    LxResult
  PolygonCount (unsigned int *count) const
  {
    return m_loc[0]->PolygonCount (m_loc,count);
  }
    LxResult
  EdgeCount (unsigned int *count) const
  {
    return m_loc[0]->EdgeCount (m_loc,count);
  }
    LxResult
  MapCount (unsigned int *count) const
  {
    return m_loc[0]->MapCount (m_loc,count);
  }
    LxResult
  BoundingBox (LXtMarkMode pick, LXtBBox *bbox)
  {
    return m_loc[0]->BoundingBox (m_loc,pick,bbox);
  }
    LxResult
  MaxPointPolygons (LXtMarkMode pick, unsigned int *count)
  {
    return m_loc[0]->MaxPointPolygons (m_loc,pick,count);
  }
    LxResult
  MaxPolygonSize (LXtMarkMode pick, unsigned int *count)
  {
    return m_loc[0]->MaxPolygonSize (m_loc,pick,count);
  }
    LxResult
  PolyTagSetDefault (LXtID4 type, const char *tag)
  {
    return m_loc[0]->PolyTagSetDefault (m_loc,type,tag);
  }
    LxResult
  PointAccessor (void **ppvObj)
  {
    return m_loc[0]->PointAccessor (m_loc,ppvObj);
  }
    bool
  PointAccessor (CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->PointAccessor (m_loc,&obj)) && dest.take(obj);
  }
    LxResult
  PolygonAccessor (void **ppvObj)
  {
    return m_loc[0]->PolygonAccessor (m_loc,ppvObj);
  }
    bool
  PolygonAccessor (CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->PolygonAccessor (m_loc,&obj)) && dest.take(obj);
  }
    LxResult
  EdgeAccessor (void **ppvObj)
  {
    return m_loc[0]->EdgeAccessor (m_loc,ppvObj);
  }
    bool
  EdgeAccessor (CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->EdgeAccessor (m_loc,&obj)) && dest.take(obj);
  }
    LxResult
  MeshMapAccessor (void **ppvObj)
  {
    return m_loc[0]->MeshMapAccessor (m_loc,ppvObj);
  }
    bool
  MeshMapAccessor (CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->MeshMapAccessor (m_loc,&obj)) && dest.take(obj);
  }
    LxResult
  SetMeshEdits (unsigned int edits)
  {
    return m_loc[0]->SetMeshEdits (m_loc,edits);
  }
    LxResult
  SUBDGetLevel (int *n)
  {
    return m_loc[0]->SUBDGetLevel (m_loc,n);
  }
    LxResult
  SUBDSetLevel (int n)
  {
    return m_loc[0]->SUBDSetLevel (m_loc,n);
  }
    LxResult
  SUBDGetLinearUV (int *isLinear)
  {
    return m_loc[0]->SUBDGetLinearUV (m_loc,isLinear);
  }
    LxResult
  SUBDSetLinearUV (int isLinear)
  {
    return m_loc[0]->SUBDSetLinearUV (m_loc,isLinear);
  }
    LxResult
  PSUBGetBoundRule (int *bound)
  {
    return m_loc[0]->PSUBGetBoundRule (m_loc,bound);
  }
    LxResult
  PSUBSetBoundRule (int bound)
  {
    return m_loc[0]->PSUBSetBoundRule (m_loc,bound);
  }
    LxResult
  TestSameMesh (ILxUnknownID other)
  {
    return m_loc[0]->TestSameMesh (m_loc,(ILxUnknownID)other);
  }
    unsigned
  PTagCount (LXtID4 type)
  {
    return m_loc[0]->PTagCount (m_loc,type);
  }
    LxResult
  PTagByIndex (LXtID4 type, unsigned index, const char **tag)
  {
    return m_loc[0]->PTagByIndex (m_loc,type,index,tag);
  }
    LxResult
  PSUBGetLevel (int *n)
  {
    return m_loc[0]->PSUBGetLevel (m_loc,n);
  }
    LxResult
  PSUBSetLevel (int n)
  {
    return m_loc[0]->PSUBSetLevel (m_loc,n);
  }
    LxResult
  PSUBGetCurrentLevel (int *n)
  {
    return m_loc[0]->PSUBGetCurrentLevel (m_loc,n);
  }
    LxResult
  PSUBSetCurrentLevel (int n)
  {
    return m_loc[0]->PSUBSetCurrentLevel (m_loc,n);
  }
};

class CLxLoc_MeshService : public CLxLocalizedService
{
  ILxMeshServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_MeshService() {_init();set();}
 ~CLxLoc_MeshService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxMeshServiceID>(lx::GetGlobal(&lx::guid_MeshService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  ModeCompose (const char *set, const char *clear, LXtMarkMode *mode)
  {
    return m_loc[0]->ModeCompose (m_loc,set,clear,mode);
  }
    LxResult
  VMapLookupType (const char *name, LXtID4 *type)
  {
    return m_loc[0]->VMapLookupType (m_loc,name,type);
  }
    LxResult
  VMapLookupName (LXtID4 type, const char **name)
  {
    return m_loc[0]->VMapLookupName (m_loc,type,name);
  }
    LxResult
  VMapDimension (LXtID4 type, unsigned int *dimension)
  {
    return m_loc[0]->VMapDimension (m_loc,type,dimension);
  }
    LxResult
  VMapIsEdgeMap (LXtID4 type)
  {
    return m_loc[0]->VMapIsEdgeMap (m_loc,type);
  }
    LxResult
  VMapIsContinuous (LXtID4 type)
  {
    return m_loc[0]->VMapIsContinuous (m_loc,type);
  }
    LxResult
  VMapZeroDefault (LXtID4 type)
  {
    return m_loc[0]->VMapZeroDefault (m_loc,type);
  }
    LxResult
  CreateMesh (void **ppvObj)
  {
    return m_loc[0]->CreateMesh (m_loc,ppvObj);
  }
    bool
  CreateMesh (CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->CreateMesh (m_loc,&obj)) && dest.take(obj);
  }
    LxResult
  ConvertMesh (ILxUnknownID triGroupObj, ILxUnknownID meshObj)
  {
    return m_loc[0]->ConvertMesh (m_loc,(ILxUnknownID)triGroupObj,(ILxUnknownID)meshObj);
  }
    LxResult
  MeshFromMeshID (LXtMeshID meshID, void **ppvObj)
  {
    return m_loc[0]->MeshFromMeshID (m_loc,meshID,ppvObj);
  }
    bool
  MeshFromMeshID (LXtMeshID meshID, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->MeshFromMeshID (m_loc,meshID,&obj)) && dest.take(obj);
  }
    LXtMeshID
  MeshToMeshID (ILxUnknownID mesh)
  {
    return m_loc[0]->MeshToMeshID (m_loc,(ILxUnknownID)mesh);
  }
};

class CLxLoc_Polygon : public CLxLocalize<ILxPolygonID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Polygon() {_init();}
  CLxLoc_Polygon(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Polygon(const CLxLoc_Polygon &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Polygon;}
    LxResult
  Spawn (void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,ppvObj);
  }
    bool
  Spawn (CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Spawn (m_loc,&obj)) && dest.take(obj);
  }
    LxResult
  Enumerate (LXtMarkMode mode, ILxUnknownID visitor, ILxUnknownID monitor)
  {
    return m_loc[0]->Enumerate (m_loc,mode,(ILxUnknownID)visitor,(ILxUnknownID)monitor);
  }
    LxResult
  TestMarks (LXtMarkMode mode)
  {
    return m_loc[0]->TestMarks (m_loc,mode);
  }
    LxResult
  SetMarks (LXtMarkMode set)
  {
    return m_loc[0]->SetMarks (m_loc,set);
  }
    LxResult
  Select (LXtPolygonID polygon)
  {
    return m_loc[0]->Select (m_loc,polygon);
  }
    LxResult
  SelectByIndex (unsigned int index)
  {
    return m_loc[0]->SelectByIndex (m_loc,index);
  }
    LXtPolygonID
  ID (void)
  {
    return m_loc[0]->ID (m_loc);
  }
    LxResult
  Index (int *index)
  {
    return m_loc[0]->Index (m_loc,index);
  }
    LxResult
  Type (LXtID4 *type)
  {
    return m_loc[0]->Type (m_loc,type);
  }
    LxResult
  VertexCount (unsigned int *count)
  {
    return m_loc[0]->VertexCount (m_loc,count);
  }
    LxResult
  VertexByIndex (unsigned int index, LXtPointID *point)
  {
    return m_loc[0]->VertexByIndex (m_loc,index,point);
  }
    LxResult
  FirstIsControlEndpoint (void)
  {
    return m_loc[0]->FirstIsControlEndpoint (m_loc);
  }
    LxResult
  LastIsControlEndpoint (void)
  {
    return m_loc[0]->LastIsControlEndpoint (m_loc);
  }
    LxResult
  Normal (LXtVector normal)
  {
    return m_loc[0]->Normal (m_loc,normal);
  }
    LxResult
  MapValue (LXtMeshMapID map, LXtPointID point, float *value)
  {
    return m_loc[0]->MapValue (m_loc,map,point,value);
  }
    LxResult
  MapEvaluate (LXtMeshMapID map, LXtPointID point, float *value)
  {
    return m_loc[0]->MapEvaluate (m_loc,map,point,value);
  }
    LxResult
  New (LXtID4 type, const LXtPointID *vertices, unsigned int numVert, unsigned int rev, LXtPolygonID *polygonID)
  {
    return m_loc[0]->New (m_loc,type,vertices,numVert,rev,polygonID);
  }
    LxResult
  NewProto (LXtID4 type, const LXtPointID *vertices, unsigned int numVert, unsigned int rev, LXtPolygonID *polygonID)
  {
    return m_loc[0]->NewProto (m_loc,type,vertices,numVert,rev,polygonID);
  }
    LxResult
  Remove (void)
  {
    return m_loc[0]->Remove (m_loc);
  }
    LxResult
  SetFirstIsControlEndpoint (int state)
  {
    return m_loc[0]->SetFirstIsControlEndpoint (m_loc,state);
  }
    LxResult
  SetLastIsControlEndpoint (int state)
  {
    return m_loc[0]->SetLastIsControlEndpoint (m_loc,state);
  }
    LxResult
  SetVertexList (const LXtPointID *vertices, unsigned int numVert, unsigned int rev)
  {
    return m_loc[0]->SetVertexList (m_loc,vertices,numVert,rev);
  }
    LxResult
  SetMapValue (LXtPointID point, LXtMeshMapID map, const float *value)
  {
    return m_loc[0]->SetMapValue (m_loc,point,map,value);
  }
    LxResult
  ClearMapValue (LXtPointID point, LXtMeshMapID map)
  {
    return m_loc[0]->ClearMapValue (m_loc,point,map);
  }
    LxResult
  StartContour (void)
  {
    return m_loc[0]->StartContour (m_loc);
  }
    LxResult
  AddContourEdge (LXtPointID startPt, LXtPointID endPt)
  {
    return m_loc[0]->AddContourEdge (m_loc,startPt,endPt);
  }
    LxResult
  GenerateContour (LXtID4 type, LXtPolygonID *polygonID)
  {
    return m_loc[0]->GenerateContour (m_loc,type,polygonID);
  }
    LxResult
  GenerateContourProto (LXtPolygonID *polygonID)
  {
    return m_loc[0]->GenerateContourProto (m_loc,polygonID);
  }
    LxResult
  IntersectRay (const LXtVector pos, const LXtVector dir, LXtVector hitNorm, double *hitDist)
  {
    return m_loc[0]->IntersectRay (m_loc,pos,dir,hitNorm,hitDist);
  }
    LxResult
  Closest (double maxDist, const LXtVector pos, LXtVector hitPos, LXtVector hitNorm, double *hitDist)
  {
    return m_loc[0]->Closest (m_loc,maxDist,pos,hitPos,hitNorm,hitDist);
  }
    LxResult
  PointIndex (LXtPointID pointID, unsigned int *index)
  {
    return m_loc[0]->PointIndex (m_loc,pointID,index);
  }
    LxResult
  EdgeIndex (LXtEdgeID edgeID, unsigned int *index)
  {
    return m_loc[0]->EdgeIndex (m_loc,edgeID,index);
  }
    LxResult
  SharedEdge (LXtPolygonID polygonID, LXtEdgeID *edgeID)
  {
    return m_loc[0]->SharedEdge (m_loc,polygonID,edgeID);
  }
    LxResult
  IsBorder (void)
  {
    return m_loc[0]->IsBorder (m_loc);
  }
    LxResult
  RepresentativePosition (LXtVector pos)
  {
    return m_loc[0]->RepresentativePosition (m_loc,pos);
  }
    LxResult
  GoodPoint (const LXtPointID *points, unsigned int nPoints, unsigned int *index)
  {
    return m_loc[0]->GoodPoint (m_loc,points,nPoints,index);
  }
};

class CLxImpl_MeshListener {
  public:
    virtual ~CLxImpl_MeshListener() {}
    virtual void
      ml_Destroy (void)
        { }
};
#define LXxD_MeshListener_Destroy void ml_Destroy (void)
#define LXxO_MeshListener_Destroy LXxD_MeshListener_Destroy LXx_OVERRIDE
template <class T>
class CLxIfc_MeshListener : public CLxInterface
{
    static void
  Destroy (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_MeshListener, loc);
    loc->ml_Destroy ();
  }
  ILxMeshListener vt;
public:
  CLxIfc_MeshListener ()
  {
    vt.Destroy = Destroy;
    vTable = &vt.iunk;
    iid = &lx::guid_MeshListener;
  }
};

class CLxLoc_Point : public CLxLocalize<ILxPointID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Point() {_init();}
  CLxLoc_Point(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Point(const CLxLoc_Point &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Point;}
    LxResult
  Spawn (void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,ppvObj);
  }
    bool
  Spawn (CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Spawn (m_loc,&obj)) && dest.take(obj);
  }
    LxResult
  Enumerate (LXtMarkMode mode, ILxUnknownID visitor, ILxUnknownID monitor)
  {
    return m_loc[0]->Enumerate (m_loc,mode,(ILxUnknownID)visitor,(ILxUnknownID)monitor);
  }
    LxResult
  TestMarks (LXtMarkMode mode)
  {
    return m_loc[0]->TestMarks (m_loc,mode);
  }
    LxResult
  SetMarks (LXtMarkMode set)
  {
    return m_loc[0]->SetMarks (m_loc,set);
  }
    LxResult
  Select (LXtPointID point)
  {
    return m_loc[0]->Select (m_loc,point);
  }
    LxResult
  SelectByIndex (unsigned int index)
  {
    return m_loc[0]->SelectByIndex (m_loc,index);
  }
    LxResult
  SelectPolygonVertex (LXtPolygonID polygon, unsigned int index)
  {
    return m_loc[0]->SelectPolygonVertex (m_loc,polygon,index);
  }
    LXtPointID
  ID (void)
  {
    return m_loc[0]->ID (m_loc);
  }
    LxResult
  Index (unsigned int *index)
  {
    return m_loc[0]->Index (m_loc,index);
  }
    LxResult
  Pos (LXtFVector pos)
  {
    return m_loc[0]->Pos (m_loc,pos);
  }
    LxResult
  Normal (LXtPolygonID pol, LXtVector normal)
  {
    return m_loc[0]->Normal (m_loc,pol,normal);
  }
    LxResult
  MapValue (LXtMeshMapID map, float *value)
  {
    return m_loc[0]->MapValue (m_loc,map,value);
  }
    LxResult
  MapEvaluate (LXtMeshMapID map, float *value)
  {
    return m_loc[0]->MapEvaluate (m_loc,map,value);
  }
    LxResult
  PolygonCount (unsigned int *count)
  {
    return m_loc[0]->PolygonCount (m_loc,count);
  }
    LxResult
  PolygonByIndex (unsigned int index, LXtPolygonID *polygonID)
  {
    return m_loc[0]->PolygonByIndex (m_loc,index,polygonID);
  }
    LxResult
  New (const LXtVector pos, LXtPointID *pointID)
  {
    return m_loc[0]->New (m_loc,pos,pointID);
  }
    LxResult
  Copy (LXtPointID *pointID)
  {
    return m_loc[0]->Copy (m_loc,pointID);
  }
    LxResult
  Remove (void)
  {
    return m_loc[0]->Remove (m_loc);
  }
    LxResult
  SetPos (const LXtVector pos)
  {
    return m_loc[0]->SetPos (m_loc,pos);
  }
    LxResult
  SetMapValue (LXtMeshMapID map, const float *value)
  {
    return m_loc[0]->SetMapValue (m_loc,map,value);
  }
    LxResult
  ClearMapValue (LXtMeshMapID map)
  {
    return m_loc[0]->ClearMapValue (m_loc,map);
  }
    LxResult
  Corner (LXtFVector pos)
  {
    return m_loc[0]->Corner (m_loc,pos);
  }
    LxResult
  PointCount (unsigned int *count)
  {
    return m_loc[0]->PointCount (m_loc,count);
  }
    LxResult
  PointByIndex (unsigned int index, LXtPointID *pointID)
  {
    return m_loc[0]->PointByIndex (m_loc,index,pointID);
  }
    LxResult
  EdgeCount (unsigned int *count)
  {
    return m_loc[0]->EdgeCount (m_loc,count);
  }
    LxResult
  EdgeByIndex (unsigned int index, LXtEdgeID *edgeID)
  {
    return m_loc[0]->EdgeByIndex (m_loc,index,edgeID);
  }
};

class CLxLoc_Edge : public CLxLocalize<ILxEdgeID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Edge() {_init();}
  CLxLoc_Edge(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Edge(const CLxLoc_Edge &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Edge;}
    LxResult
  Spawn (void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,ppvObj);
  }
    bool
  Spawn (CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Spawn (m_loc,&obj)) && dest.take(obj);
  }
    LxResult
  Enumerate (LXtMarkMode mode, ILxUnknownID visitor, ILxUnknownID monitor)
  {
    return m_loc[0]->Enumerate (m_loc,mode,(ILxUnknownID)visitor,(ILxUnknownID)monitor);
  }
    LxResult
  TestMarks (LXtMarkMode mode)
  {
    return m_loc[0]->TestMarks (m_loc,mode);
  }
    LxResult
  SetMarks (LXtMarkMode set)
  {
    return m_loc[0]->SetMarks (m_loc,set);
  }
    LxResult
  Select (LXtEdgeID edge)
  {
    return m_loc[0]->Select (m_loc,edge);
  }
    LxResult
  SelectEndpoints (LXtPointID v0, LXtPointID v1)
  {
    return m_loc[0]->SelectEndpoints (m_loc,v0,v1);
  }
    LXtEdgeID
  ID (void)
  {
    return m_loc[0]->ID (m_loc);
  }
    LxResult
  Endpoints (LXtPointID *point0, LXtPointID *point1)
  {
    return m_loc[0]->Endpoints (m_loc,point0,point1);
  }
    LxResult
  MapValue (LXtMeshMapID map, float *value)
  {
    return m_loc[0]->MapValue (m_loc,map,value);
  }
    LxResult
  MapEvaluate (LXtMeshMapID map, float *value)
  {
    return m_loc[0]->MapEvaluate (m_loc,map,value);
  }
    LxResult
  SetMapValue (LXtMeshMapID map, const float *value)
  {
    return m_loc[0]->SetMapValue (m_loc,map,value);
  }
    LxResult
  ClearMapValue (LXtMeshMapID map)
  {
    return m_loc[0]->ClearMapValue (m_loc,map);
  }
    LxResult
  PolygonCount (unsigned int *count)
  {
    return m_loc[0]->PolygonCount (m_loc,count);
  }
    LxResult
  PolygonByIndex (unsigned int index, LXtPolygonID *polygonID)
  {
    return m_loc[0]->PolygonByIndex (m_loc,index,polygonID);
  }
    LxResult
  RepresentativePolygon (LXtPolygonID *polygonID, unsigned int *index)
  {
    return m_loc[0]->RepresentativePolygon (m_loc,polygonID,index);
  }
    LxResult
  SharedPolygon (LXtEdgeID edgeID, LXtPolygonID *polygonID)
  {
    return m_loc[0]->SharedPolygon (m_loc,edgeID,polygonID);
  }
    LxResult
  IsBorder (void)
  {
    return m_loc[0]->IsBorder (m_loc);
  }
};

#endif

