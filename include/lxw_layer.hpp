/*
 * C++ wrapper for lxlayer.h
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
#ifndef LXW_LAYER_HPP
#define LXW_LAYER_HPP

#include <lxlayer.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_Scene1Service = {0x11D99CDC,0xF662,0x40FF,0x9A,0xC3,0xB7,0x6E,0x59,0xC8,0xDE,0xB0};
    static const LXtGUID guid_TransformScan = {0x6DD4BC9B,0xBEDC,0x46B9,0xB5,0xAC,0x85,0x0A,0x06,0xAD,0x5E,0xEB};
    static const LXtGUID guid_LayerService = {0xF12B06AA,0xBF92,0x4585,0x80,0x0E,0x45,0xAB,0x99,0xD4,0x7A,0x20};
    static const LXtGUID guid_LayerScan = {0x097DB669,0x91C3,0x11D9,0x8E,0xA2,0x00,0x0A,0x95,0x6C,0x2E,0x10};
};


class CLxLoc_TransformScan : public CLxLocalize<ILxTransformScanID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TransformScan() {_init();}
  CLxLoc_TransformScan(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TransformScan(const CLxLoc_TransformScan &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TransformScan;}
    LxResult
  Enumerate (ILxUnknownID visitor)
  {
    return m_loc[0]->Enumerate (m_loc,(ILxUnknownID)visitor);
  }
    unsigned int
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    const float *
  Position (void)
  {
    return m_loc[0]->Position (m_loc);
  }
    LxResult
  SetPosition (LXtFVector pos)
  {
    return m_loc[0]->SetPosition (m_loc,pos);
  }
    double
  Weight (void)
  {
    return m_loc[0]->Weight (m_loc);
  }
    LxResult
  AlternateCenter (LXtFVector center)
  {
    return m_loc[0]->AlternateCenter (m_loc,center);
  }
    LxResult
  AlternateAxis (LXtMatrix matrix, LXtMatrix inverse)
  {
    return m_loc[0]->AlternateAxis (m_loc,matrix,inverse);
  }
};

class CLxLoc_LayerService : public CLxLocalizedService
{
  ILxLayerServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_LayerService() {_init();set();}
 ~CLxLoc_LayerService() {}
  void set() {m_loc=reinterpret_cast<ILxLayerServiceID>(lx::GetGlobal(&lx::guid_LayerService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  SetScene (ILxUnknownID scene)
  {
    return m_loc[0]->SetScene (m_loc,(ILxUnknownID)scene);
  }
    LxResult
  Scene (void **xcin)
  {
    return m_loc[0]->Scene (m_loc,xcin);
  }
    LxResult
  Count (unsigned int *count)
  {
    return m_loc[0]->Count (m_loc,count);
  }
    LxResult
  Name (unsigned int index, const char **name)
  {
    return m_loc[0]->Name (m_loc,index,name);
  }
    LxResult
  Slot (unsigned int index, int *slot)
  {
    return m_loc[0]->Slot (m_loc,index,slot);
  }
    LxResult
  Item (unsigned int index, void **item)
  {
    return m_loc[0]->Item (m_loc,index,item);
  }
    LxResult
  Mesh (unsigned int index, void **mesh)
  {
    return m_loc[0]->Mesh (m_loc,index,mesh);
  }
    LxResult
  Flags (unsigned int index, int *flags)
  {
    return m_loc[0]->Flags (m_loc,index,flags);
  }
    LxResult
  Pivot (unsigned int index, double *pivot)
  {
    return m_loc[0]->Pivot (m_loc,index,pivot);
  }
    LxResult
  PatchSubdivision (unsigned int index, int *level)
  {
    return m_loc[0]->PatchSubdivision (m_loc,index,level);
  }
    LxResult
  Bounds (unsigned int index, double *min, double *max)
  {
    return m_loc[0]->Bounds (m_loc,index,min,max);
  }
    LxResult
  CurveSmoothAngle (unsigned int index, double *angle)
  {
    return m_loc[0]->CurveSmoothAngle (m_loc,index,angle);
  }
    LxResult
  SplinePatchSubdivision (unsigned int index, int *level)
  {
    return m_loc[0]->SplinePatchSubdivision (m_loc,index,level);
  }
    LxResult
  ItemLookup (int mode, ILxUnknownID item, int *index)
  {
    return m_loc[0]->ItemLookup (m_loc,mode,(ILxUnknownID)item,index);
  }
    LxResult
  NameLookup (int mode, const char *name, int *index)
  {
    return m_loc[0]->NameLookup (m_loc,mode,name,index);
  }
    LxResult
  LayerParent (int index, int *parentIndex)
  {
    return m_loc[0]->LayerParent (m_loc,index,parentIndex);
  }
    LxResult
  LayerChildCount (int index, int *num)
  {
    return m_loc[0]->LayerChildCount (m_loc,index,num);
  }
    LxResult
  LayerChild (int index, int childNumber, int *childIndex)
  {
    return m_loc[0]->LayerChild (m_loc,index,childNumber,childIndex);
  }
    LxResult
  LayerVMapCount (int *num)
  {
    return m_loc[0]->LayerVMapCount (m_loc,num);
  }
    LxResult
  LayerVMap (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->LayerVMap (m_loc,index,ppvObj);
  }
    LxResult
  LayerClipCount (int *num)
  {
    return m_loc[0]->LayerClipCount (m_loc,num);
  }
    LxResult
  LayerClip (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->LayerClip (m_loc,index,ppvObj);
  }
    LxResult
  LayerMaterialCount (int *num)
  {
    return m_loc[0]->LayerMaterialCount (m_loc,num);
  }
    LxResult
  LayerMaterial (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->LayerMaterial (m_loc,index,ppvObj);
  }
    LxResult
  LayerPartCount (int *num)
  {
    return m_loc[0]->LayerPartCount (m_loc,num);
  }
    LxResult
  LayerPart (unsigned int index, const char **part)
  {
    return m_loc[0]->LayerPart (m_loc,index,part);
  }
    LxResult
  LayerSelSetCount (unsigned int type, int *num)
  {
    return m_loc[0]->LayerSelSetCount (m_loc,type,num);
  }
    LxResult
  LayerSelSet (unsigned int type, unsigned int index, const char **selSet)
  {
    return m_loc[0]->LayerSelSet (m_loc,type,index,selSet);
  }
    LxResult
  LayerTextureCount (int layer, int *num)
  {
    return m_loc[0]->LayerTextureCount (m_loc,layer,num);
  }
    LxResult
  LayerTexture (int layer, unsigned int index, void **ppvObj)
  {
    return m_loc[0]->LayerTexture (m_loc,layer,index,ppvObj);
  }
    LxResult
  LayerTagTextureCount (int layer, unsigned int type, const char *tag, int *num)
  {
    return m_loc[0]->LayerTagTextureCount (m_loc,layer,type,tag,num);
  }
    LxResult
  LayerTagTexture (int layer, unsigned int type, const char *tag, unsigned int index, void **ppvObj)
  {
    return m_loc[0]->LayerTagTexture (m_loc,layer,type,tag,index,ppvObj);
  }
    LxResult
  LayerVertexCount (int mode, int *num)
  {
    return m_loc[0]->LayerVertexCount (m_loc,mode,num);
  }
    LxResult
  LayerVertex (int mode, unsigned int index, void **ppvObj)
  {
    return m_loc[0]->LayerVertex (m_loc,mode,index,ppvObj);
  }
    LxResult
  LayerPolyCount (int mode, int *num)
  {
    return m_loc[0]->LayerPolyCount (m_loc,mode,num);
  }
    LxResult
  LayerPoly (int mode, unsigned int index, void **ppvObj)
  {
    return m_loc[0]->LayerPoly (m_loc,mode,index,ppvObj);
  }
    LxResult
  LayerEdgeCount (int mode, int *num)
  {
    return m_loc[0]->LayerEdgeCount (m_loc,mode,num);
  }
    LxResult
  LayerEdge (int mode, unsigned int index, void **ppvObj)
  {
    return m_loc[0]->LayerEdge (m_loc,mode,index,ppvObj);
  }
    LxResult
  ScanAllocate (unsigned flags, void **ppvObj)
  {
    return m_loc[0]->ScanAllocate (m_loc,flags,ppvObj);
  }
    LxResult
  CurrentMap (LXtID4 type, const char **name)
  {
    return m_loc[0]->CurrentMap (m_loc,type,name);
  }
    LxResult
  XfrmAllocate (ILxUnknownID toolVec, void **ppvObj)
  {
    return m_loc[0]->XfrmAllocate (m_loc,(ILxUnknownID)toolVec,ppvObj);
  }
};

class CLxLoc_LayerScan : public CLxLocalize<ILxLayerScanID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_LayerScan() {_init();}
  CLxLoc_LayerScan(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_LayerScan(const CLxLoc_LayerScan &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_LayerScan;}
    LxResult
  Apply (void)
  {
    return m_loc[0]->Apply (m_loc);
  }
    LxResult
  Count (unsigned *count)
  {
    return m_loc[0]->Count (m_loc,count);
  }
    LxResult
  GetState (unsigned index, unsigned *state)
  {
    return m_loc[0]->GetState (m_loc,index,state);
  }
    LxResult
  MeshItem (unsigned index, void **ppvObj)
  {
    return m_loc[0]->MeshItem (m_loc,index,ppvObj);
  }
    LxResult
  MeshAction (unsigned index, void **ppvObj)
  {
    return m_loc[0]->MeshAction (m_loc,index,ppvObj);
  }
    LxResult
  MeshBase (unsigned index, void **ppvObj)
  {
    return m_loc[0]->MeshBase (m_loc,index,ppvObj);
  }
    LxResult
  MeshInstance (unsigned index, void **ppvObj)
  {
    return m_loc[0]->MeshInstance (m_loc,index,ppvObj);
  }
    LxResult
  MeshEdit (unsigned index, void **ppvObj)
  {
    return m_loc[0]->MeshEdit (m_loc,index,ppvObj);
  }
    LxResult
  SetMeshChange (unsigned index, unsigned int edits)
  {
    return m_loc[0]->SetMeshChange (m_loc,index,edits);
  }
};

#endif

