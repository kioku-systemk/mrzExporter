/*
 * C++ wrapper for lxtableau.h
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
#ifndef LXW_TABLEAU_HPP
#define LXW_TABLEAU_HPP

#include <lxtableau.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_TableauSurface = {0xB5769A8B,0x6254,0x42E3,0x86,0x2F,0x0A,0x81,0x1E,0x71,0x6E,0x21};
    static const LXtGUID guid_TableauVertex = {0xF90A0A39,0xEE2A,0x4D11,0x91,0x2B,0x93,0x38,0xEF,0x27,0x1D,0xFF};
    static const LXtGUID guid_LightSample = {0x43734621,0x9B93,0x4174,0xAC,0x63,0xE2,0xFE,0x7D,0xDA,0x87,0x94};
    static const LXtGUID guid_TableauFilter = {0xFD1326E7,0xEECF,0x4EAC,0xB9,0xAD,0xB1,0xD6,0x4E,0x75,0x03,0xBE};
    static const LXtGUID guid_TableauShader = {0xA0E3B574,0xB0AC,0x4530,0xA4,0x3F,0x7C,0xC8,0xDA,0x53,0x6E,0x25};
    static const LXtGUID guid_TableauVolume = {0x97962302,0x4B49,0x4282,0xB2,0x59,0xF3,0x47,0xF1,0x01,0x28,0x18};
    static const LXtGUID guid_Tableau = {0x76C4EDD9,0x5FF9,0x4342,0xBB,0x08,0xEF,0xCD,0x0B,0x34,0x40,0x04};
    static const LXtGUID guid_TableauProxy = {0xFB34BD64,0x099C,0x4B30,0x8E,0xF7,0x2B,0xB0,0x4C,0xA0,0xE9,0x2C};
    static const LXtGUID guid_TableauSource = {0x1121C167,0xF934,0x4421,0x8A,0xBE,0x32,0xF8,0xE4,0x65,0x93,0x24};
    static const LXtGUID guid_ShaderSlice = {0x47B885B9,0xB1D9,0x4F86,0x82,0x9F,0xA6,0xAA,0xBB,0xD7,0xFF,0xF7};
    static const LXtGUID guid_TableauService = {0x8DF92316,0x3172,0x465A,0xA1,0x99,0x25,0x47,0x92,0xD3,0x77,0x32};
    static const LXtGUID guid_TableauInstance = {0x9B57D0DB,0xC0B4,0x435E,0x8C,0xDD,0xE3,0xDD,0xCF,0x66,0x17,0x2D};
    static const LXtGUID guid_TriangleSoup = {0x17536C2D,0x07BD,0x49C8,0x83,0x48,0xCE,0xBD,0xE4,0xD3,0xA8,0x56};
    static const LXtGUID guid_TableauElement = {0x71D90AD9,0x3E30,0x4CE8,0x9E,0x2B,0xF7,0x0D,0xA2,0x81,0xB2,0xDC};
    static const LXtGUID guid_TableauLight = {0x7FE816D1,0x4A7F,0x4BE5,0x96,0x89,0x49,0x91,0xC0,0x3C,0xAE,0xE0};
};

class CLxImpl_TableauSurface {
  public:
    virtual ~CLxImpl_TableauSurface() {}
    virtual LxResult
      tsrf_Bound (LXtTableauBox bbox)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      tsrf_FeatureCount (LXtID4 type)
        { return 0; }
    virtual LxResult
      tsrf_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
        { return LXe_OUTOFBOUNDS; }
    virtual LxResult
      tsrf_SetVertex (ILxUnknownID vdesc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrf_Sample (const LXtTableauBox bbox, float scale, ILxUnknownID trisoup)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrf_Padding (float *dist)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_TableauSurface : public CLxInterface
{
    static LxResult
  Bound (LXtObjectID wcom, LXtTableauBox bbox)
  {
    LXCWxINST (CLxImpl_TableauSurface, loc);
    try {
      return loc->tsrf_Bound (bbox);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  FeatureCount (LXtObjectID wcom, LXtID4 type)
  {
    LXCWxINST (CLxImpl_TableauSurface, loc);
    return loc->tsrf_FeatureCount (type);
  }
    static LxResult
  FeatureByIndex (LXtObjectID wcom, LXtID4 type, unsigned int index, const char **name)
  {
    LXCWxINST (CLxImpl_TableauSurface, loc);
    try {
      return loc->tsrf_FeatureByIndex (type,index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetVertex (LXtObjectID wcom, LXtObjectID vdesc)
  {
    LXCWxINST (CLxImpl_TableauSurface, loc);
    try {
      return loc->tsrf_SetVertex ((ILxUnknownID)vdesc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Sample (LXtObjectID wcom, const LXtTableauBox bbox, float scale, LXtObjectID trisoup)
  {
    LXCWxINST (CLxImpl_TableauSurface, loc);
    try {
      return loc->tsrf_Sample (bbox,scale,(ILxUnknownID)trisoup);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Padding (LXtObjectID wcom, float *dist)
  {
    LXCWxINST (CLxImpl_TableauSurface, loc);
    try {
      return loc->tsrf_Padding (dist);
    } catch (LxResult rc) { return rc; }
  }
  ILxTableauSurface vt;
public:
  CLxIfc_TableauSurface ()
  {
    vt.Bound = Bound;
    vt.FeatureCount = FeatureCount;
    vt.FeatureByIndex = FeatureByIndex;
    vt.SetVertex = SetVertex;
    vt.Sample = Sample;
    vt.Padding = Padding;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauSurface;
  }
};
class CLxLoc_TableauSurface : public CLxLocalize<ILxTableauSurfaceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TableauSurface() {_init();}
  CLxLoc_TableauSurface(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TableauSurface(const CLxLoc_TableauSurface &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TableauSurface;}
    LxResult
  Bound (LXtTableauBox bbox)
  {
    return m_loc[0]->Bound (m_loc,bbox);
  }
    unsigned int
  FeatureCount (LXtID4 type)
  {
    return m_loc[0]->FeatureCount (m_loc,type);
  }
    LxResult
  FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
  {
    return m_loc[0]->FeatureByIndex (m_loc,type,index,name);
  }
    LxResult
  SetVertex (ILxUnknownID vdesc)
  {
    return m_loc[0]->SetVertex (m_loc,(ILxUnknownID)vdesc);
  }
    LxResult
  Sample (const LXtTableauBox bbox, float scale, ILxUnknownID trisoup)
  {
    return m_loc[0]->Sample (m_loc,bbox,scale,(ILxUnknownID)trisoup);
  }
    LxResult
  Padding (float *dist)
  {
    return m_loc[0]->Padding (m_loc,dist);
  }
};

class CLxLoc_TableauVertex : public CLxLocalize<ILxTableauVertexID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TableauVertex() {_init();}
  CLxLoc_TableauVertex(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TableauVertex(const CLxLoc_TableauVertex &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TableauVertex;}
    LxResult
  AddFeature (LXtID4 type, const char *name, unsigned int *index)
  {
    return m_loc[0]->AddFeature (m_loc,type,name,index);
  }
    LxResult
  Lookup (LXtID4 type, const char *name, unsigned int *offset)
  {
    return m_loc[0]->Lookup (m_loc,type,name,offset);
  }
    unsigned int
  Size (void)
  {
    return m_loc[0]->Size (m_loc);
  }
    unsigned int
  Count (void)
  {
    return m_loc[0]->Count (m_loc);
  }
    LxResult
  ByIndex (unsigned int index, LXtID4 *type, const char **name, unsigned int *offset)
  {
    return m_loc[0]->ByIndex (m_loc,index,type,name,offset);
  }
};

class CLxLoc_LightSample : public CLxLocalize<ILxLightSampleID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_LightSample() {_init();}
  CLxLoc_LightSample(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_LightSample(const CLxLoc_LightSample &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_LightSample;}
    void
  Vertex (const float *vertex)
  {
    m_loc[0]->Vertex (m_loc,vertex);
  }
};


class CLxImpl_TableauShader {
  public:
    virtual ~CLxImpl_TableauShader() {}
    virtual LxResult
      tsha_Select (ILxUnknownID teElt, ILxUnknownID tvDesc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsha_Slice (ILxUnknownID vtOutput, ILxUnknownID tvDesc, void **ppvObj)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_TableauShader : public CLxInterface
{
    static LxResult
  Select (LXtObjectID wcom, LXtObjectID teElt, LXtObjectID tvDesc)
  {
    LXCWxINST (CLxImpl_TableauShader, loc);
    try {
      return loc->tsha_Select ((ILxUnknownID)teElt,(ILxUnknownID)tvDesc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Slice (LXtObjectID wcom, LXtObjectID vtOutput, LXtObjectID tvDesc, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TableauShader, loc);
    try {
      return loc->tsha_Slice ((ILxUnknownID)vtOutput,(ILxUnknownID)tvDesc,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxTableauShader vt;
public:
  CLxIfc_TableauShader ()
  {
    vt.Select = Select;
    vt.Slice = Slice;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauShader;
  }
};
class CLxLoc_TableauShader : public CLxLocalize<ILxTableauShaderID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TableauShader() {_init();}
  CLxLoc_TableauShader(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TableauShader(const CLxLoc_TableauShader &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TableauShader;}
    LxResult
  Select (ILxUnknownID teElt, ILxUnknownID tvDesc)
  {
    return m_loc[0]->Select (m_loc,(ILxUnknownID)teElt,(ILxUnknownID)tvDesc);
  }
    LxResult
  Slice (ILxUnknownID vtOutput, ILxUnknownID tvDesc, void **ppvObj)
  {
    return m_loc[0]->Slice (m_loc,(ILxUnknownID)vtOutput,(ILxUnknownID)tvDesc,ppvObj);
  }
};

class CLxImpl_TableauVolume {
  public:
    virtual ~CLxImpl_TableauVolume() {}
    virtual LxResult
      tvol_Bound (LXtTableauBox bbox)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      tvol_FeatureCount (LXtID4 type)
        { return 0; }
    virtual LxResult
      tvol_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
        { return LXe_OUTOFBOUNDS; }
    virtual LxResult
      tvol_SetVertex (ILxUnknownID vdesc)
        { return LXe_NOTIMPL; }
    virtual int
      tvol_Type (void)
        = 0;
    virtual LxResult
      tvol_RenderInit (ILxUnknownID sv)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tvol_RaySample (ILxUnknownID densitySlice, ILxUnknownID shadingSlice, ILxUnknownID sv, ILxUnknownID raycastObj, ILxUnknownID raymarchObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tvol_RayCast (ILxUnknownID densitySlice, ILxUnknownID sv, ILxUnknownID raycastObj, double *dist)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tvol_Density (ILxUnknownID densitySlice, ILxUnknownID sv, ILxUnknownID raycastObj, const LXtVector pos, int worldPos, double *dens)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_TableauVolume : public CLxInterface
{
    static LxResult
  Bound (LXtObjectID wcom, LXtTableauBox bbox)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    try {
      return loc->tvol_Bound (bbox);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  FeatureCount (LXtObjectID wcom, LXtID4 type)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    return loc->tvol_FeatureCount (type);
  }
    static LxResult
  FeatureByIndex (LXtObjectID wcom, LXtID4 type, unsigned int index, const char **name)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    try {
      return loc->tvol_FeatureByIndex (type,index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetVertex (LXtObjectID wcom, LXtObjectID vdesc)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    try {
      return loc->tvol_SetVertex ((ILxUnknownID)vdesc);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Type (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    return loc->tvol_Type ();
  }
    static LxResult
  RenderInit (LXtObjectID wcom, LXtObjectID sv)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    try {
      return loc->tvol_RenderInit ((ILxUnknownID)sv);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RaySample (LXtObjectID wcom, LXtObjectID densitySlice, LXtObjectID shadingSlice, LXtObjectID sv, LXtObjectID raycastObj, LXtObjectID raymarchObj)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    try {
      return loc->tvol_RaySample ((ILxUnknownID)densitySlice,(ILxUnknownID)shadingSlice,(ILxUnknownID)sv,(ILxUnknownID)raycastObj,(ILxUnknownID)raymarchObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  RayCast (LXtObjectID wcom, LXtObjectID densitySlice, LXtObjectID sv, LXtObjectID raycastObj, double *dist)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    try {
      return loc->tvol_RayCast ((ILxUnknownID)densitySlice,(ILxUnknownID)sv,(ILxUnknownID)raycastObj,dist);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Density (LXtObjectID wcom, LXtObjectID densitySlice, LXtObjectID sv, LXtObjectID raycastObj, const LXtVector pos, int worldPos, double *dens)
  {
    LXCWxINST (CLxImpl_TableauVolume, loc);
    try {
      return loc->tvol_Density ((ILxUnknownID)densitySlice,(ILxUnknownID)sv,(ILxUnknownID)raycastObj,pos,worldPos,dens);
    } catch (LxResult rc) { return rc; }
  }
  ILxTableauVolume vt;
public:
  CLxIfc_TableauVolume ()
  {
    vt.Bound = Bound;
    vt.FeatureCount = FeatureCount;
    vt.FeatureByIndex = FeatureByIndex;
    vt.SetVertex = SetVertex;
    vt.Type = Type;
    vt.RenderInit = RenderInit;
    vt.RaySample = RaySample;
    vt.RayCast = RayCast;
    vt.Density = Density;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauVolume;
  }
};

class CLxLoc_Tableau : public CLxLocalize<ILxTableauID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Tableau() {_init();}
  CLxLoc_Tableau(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Tableau(const CLxLoc_Tableau &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Tableau;}
    LxResult
  Time (float *t0, float *interval)
  {
    return m_loc[0]->Time (m_loc,t0,interval);
  }
    LxResult
  AddElement (ILxUnknownID element, ILxUnknownID shader)
  {
    return m_loc[0]->AddElement (m_loc,(ILxUnknownID)element,(ILxUnknownID)shader);
  }
    LxResult
  AddInstance (ILxUnknownID inst, ILxUnknownID element, ILxUnknownID shader)
  {
    return m_loc[0]->AddInstance (m_loc,(ILxUnknownID)inst,(ILxUnknownID)element,(ILxUnknownID)shader);
  }
    LxResult
  Channels (unsigned type, void **ppvObj)
  {
    return m_loc[0]->Channels (m_loc,type,ppvObj);
  }
    LxResult
  Visible (ILxUnknownID item)
  {
    return m_loc[0]->Visible (m_loc,(ILxUnknownID)item);
  }
    LxResult
  FindShader (ILxUnknownID item, ILxUnknownID tags, void **ppvObj)
  {
    return m_loc[0]->FindShader (m_loc,(ILxUnknownID)item,(ILxUnknownID)tags,ppvObj);
  }
    ILxUnknownID
  InstanceItem (void)
  {
    return (ILxUnknownID) m_loc[0]->InstanceItem (m_loc);
  }
};

class CLxImpl_TableauProxy {
  public:
    virtual ~CLxImpl_TableauProxy() {}
    virtual LxResult
      tpro_Bound (LXtTableauBox bbox)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      tpro_FeatureCount (LXtID4 type)
        { return 0; }
    virtual LxResult
      tpro_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
        { return LXe_OUTOFBOUNDS; }
    virtual LxResult
      tpro_SetVertex (ILxUnknownID vdesc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tpro_Sample (const LXtTableauBox bbox, ILxUnknownID tableau)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_TableauProxy : public CLxInterface
{
    static LxResult
  Bound (LXtObjectID wcom, LXtTableauBox bbox)
  {
    LXCWxINST (CLxImpl_TableauProxy, loc);
    try {
      return loc->tpro_Bound (bbox);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  FeatureCount (LXtObjectID wcom, LXtID4 type)
  {
    LXCWxINST (CLxImpl_TableauProxy, loc);
    return loc->tpro_FeatureCount (type);
  }
    static LxResult
  FeatureByIndex (LXtObjectID wcom, LXtID4 type, unsigned int index, const char **name)
  {
    LXCWxINST (CLxImpl_TableauProxy, loc);
    try {
      return loc->tpro_FeatureByIndex (type,index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetVertex (LXtObjectID wcom, LXtObjectID vdesc)
  {
    LXCWxINST (CLxImpl_TableauProxy, loc);
    try {
      return loc->tpro_SetVertex ((ILxUnknownID)vdesc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Sample (LXtObjectID wcom, const LXtTableauBox bbox, LXtObjectID tableau)
  {
    LXCWxINST (CLxImpl_TableauProxy, loc);
    try {
      return loc->tpro_Sample (bbox,(ILxUnknownID)tableau);
    } catch (LxResult rc) { return rc; }
  }
  ILxTableauProxy vt;
public:
  CLxIfc_TableauProxy ()
  {
    vt.Bound = Bound;
    vt.FeatureCount = FeatureCount;
    vt.FeatureByIndex = FeatureByIndex;
    vt.SetVertex = SetVertex;
    vt.Sample = Sample;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauProxy;
  }
};

class CLxImpl_TableauSource {
  public:
    virtual ~CLxImpl_TableauSource() {}
    virtual LxResult
      tsrc_Elements (ILxUnknownID tableau)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_Preview (ILxUnknownID tableau)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_Instance (ILxUnknownID tableau, ILxUnknownID instance)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_SubShader (ILxUnknownID tableau, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_PreviewUpdate (int chanIndex, int *update)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tsrc_GetCurves (ILxUnknownID tableau, ILxUnknownID tags, void **ppvObj)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_TableauSource : public CLxInterface
{
    static LxResult
  Elements (LXtObjectID wcom, LXtObjectID tableau)
  {
    LXCWxINST (CLxImpl_TableauSource, loc);
    try {
      return loc->tsrc_Elements ((ILxUnknownID)tableau);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Preview (LXtObjectID wcom, LXtObjectID tableau)
  {
    LXCWxINST (CLxImpl_TableauSource, loc);
    try {
      return loc->tsrc_Preview ((ILxUnknownID)tableau);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Instance (LXtObjectID wcom, LXtObjectID tableau, LXtObjectID instance)
  {
    LXCWxINST (CLxImpl_TableauSource, loc);
    try {
      return loc->tsrc_Instance ((ILxUnknownID)tableau,(ILxUnknownID)instance);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SubShader (LXtObjectID wcom, LXtObjectID tableau, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TableauSource, loc);
    try {
      return loc->tsrc_SubShader ((ILxUnknownID)tableau,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PreviewUpdate (LXtObjectID wcom, int chanIndex, int *update)
  {
    LXCWxINST (CLxImpl_TableauSource, loc);
    try {
      return loc->tsrc_PreviewUpdate (chanIndex,update);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetCurves (LXtObjectID wcom, LXtObjectID tableau, LXtObjectID tags, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TableauSource, loc);
    try {
      return loc->tsrc_GetCurves ((ILxUnknownID)tableau,(ILxUnknownID)tags,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxTableauSource vt;
public:
  CLxIfc_TableauSource ()
  {
    vt.Elements = Elements;
    vt.Preview = Preview;
    vt.Instance = Instance;
    vt.SubShader = SubShader;
    vt.PreviewUpdate = PreviewUpdate;
    vt.GetCurves = GetCurves;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauSource;
  }
};

class CLxLoc_ShaderSlice : public CLxLocalize<ILxShaderSliceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ShaderSlice() {_init();}
  CLxLoc_ShaderSlice(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ShaderSlice(const CLxLoc_ShaderSlice &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ShaderSlice;}
    LxResult
  Evaluate (ILxUnknownID vecstack)
  {
    return m_loc[0]->Evaluate (m_loc,(ILxUnknownID)vecstack);
  }
};

class CLxLoc_TableauService : public CLxLocalizedService
{
  ILxTableauServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_TableauService() {_init();set();}
 ~CLxLoc_TableauService() {}
  void set() {m_loc=reinterpret_cast<ILxTableauServiceID>(lx::GetGlobal(&lx::guid_TableauService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  AllocVertex (void **ppvObj)
  {
    return m_loc[0]->AllocVertex (m_loc,ppvObj);
  }
};

class CLxImpl_TableauInstance {
  public:
    virtual ~CLxImpl_TableauInstance() {}
    virtual LxResult
      tins_Properties (ILxUnknownID vecstack)
        { return LXe_OK; }
    virtual LxResult
      tins_GetTransform (unsigned endPoint, LXtVector offset, LXtMatrix xfrm)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_TableauInstance : public CLxInterface
{
    static LxResult
  Properties (LXtObjectID wcom, LXtObjectID vecstack)
  {
    LXCWxINST (CLxImpl_TableauInstance, loc);
    try {
      return loc->tins_Properties ((ILxUnknownID)vecstack);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetTransform (LXtObjectID wcom, unsigned endPoint, LXtVector offset, LXtMatrix xfrm)
  {
    LXCWxINST (CLxImpl_TableauInstance, loc);
    try {
      return loc->tins_GetTransform (endPoint,offset,xfrm);
    } catch (LxResult rc) { return rc; }
  }
  ILxTableauInstance vt;
public:
  CLxIfc_TableauInstance ()
  {
    vt.Properties = Properties;
    vt.GetTransform = GetTransform;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauInstance;
  }
};
class CLxLoc_TableauInstance : public CLxLocalize<ILxTableauInstanceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TableauInstance() {_init();}
  CLxLoc_TableauInstance(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TableauInstance(const CLxLoc_TableauInstance &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TableauInstance;}
    LxResult
  Properties (ILxUnknownID vecstack)
  {
    return m_loc[0]->Properties (m_loc,(ILxUnknownID)vecstack);
  }
    LxResult
  GetTransform (unsigned endPoint, LXtVector offset, LXtMatrix xfrm)
  {
    return m_loc[0]->GetTransform (m_loc,endPoint,offset,xfrm);
  }
};

class CLxImpl_TriangleSoup {
  public:
    virtual ~CLxImpl_TriangleSoup() {}
    virtual unsigned int
      soup_TestBox (const LXtTableauBox bbox)
        = 0;
    virtual LxResult
      soup_Segment (unsigned int segID, unsigned int type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      soup_Vertex (const float *vertex, unsigned int *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      soup_Polygon (unsigned int v0, unsigned int v1, unsigned int v2)
        { return LXe_NOTIMPL; }
    virtual void
      soup_Connect (unsigned int type)
        { }
};
template <class T>
class CLxIfc_TriangleSoup : public CLxInterface
{
    static unsigned int
  TestBox (LXtObjectID wcom, const LXtTableauBox bbox)
  {
    LXCWxINST (CLxImpl_TriangleSoup, loc);
    return loc->soup_TestBox (bbox);
  }
    static LxResult
  Segment (LXtObjectID wcom, unsigned int segID, unsigned int type)
  {
    LXCWxINST (CLxImpl_TriangleSoup, loc);
    try {
      return loc->soup_Segment (segID,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Vertex (LXtObjectID wcom, const float *vertex, unsigned int *index)
  {
    LXCWxINST (CLxImpl_TriangleSoup, loc);
    try {
      return loc->soup_Vertex (vertex,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Polygon (LXtObjectID wcom, unsigned int v0, unsigned int v1, unsigned int v2)
  {
    LXCWxINST (CLxImpl_TriangleSoup, loc);
    try {
      return loc->soup_Polygon (v0,v1,v2);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Connect (LXtObjectID wcom, unsigned int type)
  {
    LXCWxINST (CLxImpl_TriangleSoup, loc);
    loc->soup_Connect (type);
  }
  ILxTriangleSoup vt;
public:
  CLxIfc_TriangleSoup ()
  {
    vt.TestBox = TestBox;
    vt.Segment = Segment;
    vt.Vertex = Vertex;
    vt.Polygon = Polygon;
    vt.Connect = Connect;
    vTable = &vt.iunk;
    iid = &lx::guid_TriangleSoup;
  }
};
class CLxLoc_TriangleSoup : public CLxLocalize<ILxTriangleSoupID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TriangleSoup() {_init();}
  CLxLoc_TriangleSoup(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TriangleSoup(const CLxLoc_TriangleSoup &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TriangleSoup;}
    unsigned int
  TestBox (const LXtTableauBox bbox)
  {
    return m_loc[0]->TestBox (m_loc,bbox);
  }
    LxResult
  Segment (unsigned int segID, unsigned int type)
  {
    return m_loc[0]->Segment (m_loc,segID,type);
  }
    LxResult
  Vertex (const float *vertex, unsigned int *index)
  {
    return m_loc[0]->Vertex (m_loc,vertex,index);
  }
    LxResult
  Polygon (unsigned int v0, unsigned int v1, unsigned int v2)
  {
    return m_loc[0]->Polygon (m_loc,v0,v1,v2);
  }
    void
  Connect (unsigned int type)
  {
    m_loc[0]->Connect (m_loc,type);
  }
};

class CLxLoc_TableauElement : public CLxLocalize<ILxTableauElementID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TableauElement() {_init();}
  CLxLoc_TableauElement(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TableauElement(const CLxLoc_TableauElement &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TableauElement;}
    LxResult
  Bound (LXtTableauBox bbox)
  {
    return m_loc[0]->Bound (m_loc,bbox);
  }
    unsigned int
  FeatureCount (LXtID4 type)
  {
    return m_loc[0]->FeatureCount (m_loc,type);
  }
    LxResult
  FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
  {
    return m_loc[0]->FeatureByIndex (m_loc,type,index,name);
  }
    LxResult
  SetVertex (ILxUnknownID vdesc)
  {
    return m_loc[0]->SetVertex (m_loc,(ILxUnknownID)vdesc);
  }
};

class CLxImpl_TableauLight {
  public:
    virtual ~CLxImpl_TableauLight() {}
    virtual LxResult
      tlgt_Bound (LXtTableauBox bbox)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      tlgt_FeatureCount (LXtID4 type)
        { return 0; }
    virtual LxResult
      tlgt_FeatureByIndex (LXtID4 type, unsigned int index, const char **name)
        { return LXe_OUTOFBOUNDS; }
    virtual LxResult
      tlgt_SetVertex (ILxUnknownID vdesc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      tlgt_Sample (int sample, float ju, float jv, const LXtFVector dir, LXtFVector wPos, LXtFVector oPos)
        { return LXe_NOTIMPL; }
    virtual int
      tlgt_Geometry (void *gc)
        = 0;
    virtual LxResult
      tlgt_Emit (unsigned int nPhotons, int offset, ILxUnknownID slice, LXtSampleVectorID sv)
        { return LXe_NOTIMPL; }
    virtual int
      tlgt_ShadowMap (void **ppvObj)
        = 0;
};
template <class T>
class CLxIfc_TableauLight : public CLxInterface
{
    static LxResult
  Bound (LXtObjectID wcom, LXtTableauBox bbox)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    try {
      return loc->tlgt_Bound (bbox);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  FeatureCount (LXtObjectID wcom, LXtID4 type)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    return loc->tlgt_FeatureCount (type);
  }
    static LxResult
  FeatureByIndex (LXtObjectID wcom, LXtID4 type, unsigned int index, const char **name)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    try {
      return loc->tlgt_FeatureByIndex (type,index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetVertex (LXtObjectID wcom, LXtObjectID vdesc)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    try {
      return loc->tlgt_SetVertex ((ILxUnknownID)vdesc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Sample (LXtObjectID wcom, int sample, float ju, float jv, const LXtFVector dir, LXtFVector wPos, LXtFVector oPos)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    try {
      return loc->tlgt_Sample (sample,ju,jv,dir,wPos,oPos);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Geometry (LXtObjectID wcom, void *gc)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    return loc->tlgt_Geometry (gc);
  }
    static LxResult
  Emit (LXtObjectID wcom, unsigned int nPhotons, int offset, LXtObjectID slice, LXtSampleVectorID sv)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    try {
      return loc->tlgt_Emit (nPhotons,offset,(ILxUnknownID)slice,sv);
    } catch (LxResult rc) { return rc; }
  }
    static int
  ShadowMap (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_TableauLight, loc);
    return loc->tlgt_ShadowMap (ppvObj);
  }
  ILxTableauLight vt;
public:
  CLxIfc_TableauLight ()
  {
    vt.Bound = Bound;
    vt.FeatureCount = FeatureCount;
    vt.FeatureByIndex = FeatureByIndex;
    vt.SetVertex = SetVertex;
    vt.Sample = Sample;
    vt.Geometry = Geometry;
    vt.Emit = Emit;
    vt.ShadowMap = ShadowMap;
    vTable = &vt.iunk;
    iid = &lx::guid_TableauLight;
  }
};

#endif

