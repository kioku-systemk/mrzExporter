/*
 * C++ wrapper for lxtool.h
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
#ifndef LXW_TOOL_HPP
#define LXW_TOOL_HPP

#include <lxtool.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_ElementAxisPacket = {0x292A47BF,0x3CF5,0x492D,0xAA,0xFD,0xAE,0x76,0x10,0x92,0xA7,0x82};
    static const LXtGUID guid_BagGenerator = {0x9A368FAA,0x7576,0x42B9,0x9B,0x6A,0xC2,0xF8,0xD3,0x46,0x12,0xF0};
    static const LXtGUID guid_PathStep = {0xB9F58563,0xFBA0,0x4CA2,0x86,0x6B,0x1D,0xD6,0x41,0x74,0xA2,0x77};
    static const LXtGUID guid_SymmetryPacket = {0xF13F6933,0x1289,0x4EFC,0x9C,0xE1,0xD5,0xC4,0xF1,0x3E,0xE7,0xD8};
    static const LXtGUID guid_AttrSequence = {0xF54FEF16,0x223F,0x439D,0x85,0x93,0x6F,0x35,0x07,0x83,0x99,0x3E};
    static const LXtGUID guid_FalloffPacket = {0xD0F8CF5D,0x1BB5,0x4002,0x81,0x0B,0x0E,0x7E,0xF3,0x4B,0x78,0x67};
    static const LXtGUID guid_TexturePacket = {0x851271E5,0xF4F4,0x444D,0xA8,0x7A,0x56,0x3B,0x9E,0x1E,0x6E,0xFB};
    static const LXtGUID guid_Tool = {0x12E79F81,0x565E,0x11D7,0xA4,0xCF,0x00,0x0A,0x95,0x76,0x5C,0x9E};
    static const LXtGUID guid_PathGeneratorPacket = {0xAE70D946,0x8A9A,0x4A72,0x95,0xEC,0xBF,0xF8,0x56,0x39,0x1D,0x22};
    static const LXtGUID guid_ElementCenterPacket = {0x5221C415,0x073A,0x4610,0xBC,0xB6,0xF8,0x20,0xF8,0xD7,0xF6,0xD0};
    static const LXtGUID guid_ParticleGeneratorPacket = {0x5CDF5B58,0x46BF,0x4D78,0x86,0x52,0x65,0x9E,0x87,0xE1,0x9C,0x4B};
};

class CLxLoc_ElementAxisPacket : public CLxLocalize<ILxElementAxisPacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ElementAxisPacket() {_init();}
  CLxLoc_ElementAxisPacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ElementAxisPacket(const CLxLoc_ElementAxisPacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ElementAxisPacket;}
    LxResult
  Axis (LXtPointID vrx, LXtFVector axis, LXtMatrix m, LXtMatrix mInv)
  {
    return m_loc[0]->Axis (m_loc,vrx,axis,m,mInv);
  }
};

class CLxLoc_BagGenerator : public CLxLocalize<ILxBagGeneratorID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_BagGenerator() {_init();}
  CLxLoc_BagGenerator(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_BagGenerator(const CLxLoc_BagGenerator &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_BagGenerator;}
    void*
  Generate (void *data, void *cloneMe)
  {
    return m_loc[0]->Generate (m_loc,data,cloneMe);
  }
    void
  Dispose (void *data)
  {
    m_loc[0]->Dispose (m_loc,data);
  }
};

class CLxLoc_PathStep : public CLxLocalize<ILxPathStepID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PathStep() {_init();}
  CLxLoc_PathStep(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PathStep(const CLxLoc_PathStep &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PathStep;}
    void
  Setup (void)
  {
    m_loc[0]->Setup (m_loc);
  }
    int
  Step (double t, LXtVector pos)
  {
    return m_loc[0]->Step (m_loc,t,pos);
  }
    void
  CleanUp (void)
  {
    m_loc[0]->CleanUp (m_loc);
  }
};

class CLxLoc_SymmetryPacket : public CLxLocalize<ILxSymmetryPacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_SymmetryPacket() {_init();}
  CLxLoc_SymmetryPacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_SymmetryPacket(const CLxLoc_SymmetryPacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_SymmetryPacket;}
    int
  Active (void)
  {
    return m_loc[0]->Active (m_loc);
  }
    int
  Axis (LXtFVector axvec, float *offset)
  {
    return m_loc[0]->Axis (m_loc,axvec,offset);
  }
    LXtPointID
  Point (LXtMeshID mesh, LXtPointID vrx)
  {
    return m_loc[0]->Point (m_loc,mesh,vrx);
  }
    LXtPolygonID
  Polygon (LXtMeshID mesh, LXtPolygonID pol)
  {
    return m_loc[0]->Polygon (m_loc,mesh,pol);
  }
    LXtEdgeID
  Edge (LXtMeshID mesh, LXtEdgeID edge)
  {
    return m_loc[0]->Edge (m_loc,mesh,edge);
  }
    int
  Position (const LXtFVector pos, LXtFVector sv)
  {
    return m_loc[0]->Position (m_loc,pos,sv);
  }
};

class CLxLoc_AttrSequence : public CLxLocalize<ILxAttrSequenceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AttrSequence() {_init();}
  CLxLoc_AttrSequence(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AttrSequence(const CLxLoc_AttrSequence &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AttrSequence;}
    LxResult
  Integer (const char *name, int value)
  {
    return m_loc[0]->Integer (m_loc,name,value);
  }
    LxResult
  Float (const char *name, double value)
  {
    return m_loc[0]->Float (m_loc,name,value);
  }
    LxResult
  String (const char *name, const char *value)
  {
    return m_loc[0]->String (m_loc,name,value);
  }
    LxResult
  Value (const char *name, ILxUnknownID value)
  {
    return m_loc[0]->Value (m_loc,name,(ILxUnknownID)value);
  }
};

class CLxLoc_FalloffPacket : public CLxLocalize<ILxFalloffPacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_FalloffPacket() {_init();}
  CLxLoc_FalloffPacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_FalloffPacket(const CLxLoc_FalloffPacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_FalloffPacket;}
    double
  Evaluate (LXtFVector pos, LXtPointID vrx)
  {
    return m_loc[0]->Evaluate (m_loc,pos,vrx);
  }
    double
  Screen (ILxUnknownID vts, int x, int y)
  {
    return m_loc[0]->Screen (m_loc,(ILxUnknownID)vts,x,y);
  }
};

class CLxLoc_TexturePacket : public CLxLocalize<ILxTexturePacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TexturePacket() {_init();}
  CLxLoc_TexturePacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TexturePacket(const CLxLoc_TexturePacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TexturePacket;}
    LxResult
  Evaluate (LXtFVector pos, LXtPointID vrx, LXtPolygonID pol, int context, double *res)
  {
    return m_loc[0]->Evaluate (m_loc,pos,vrx,pol,context,res);
  }
};

class CLxImpl_Tool {
  public:
    virtual ~CLxImpl_Tool() {}
    virtual void
      tool_Reset (void)
        { }
    virtual void
      tool_Evaluate (ILxUnknownID vts)
        { }
    virtual LXtObjectID
      tool_VectorType (void)
        = 0;
    virtual const char *
      tool_Order (void)
        = 0;
    virtual LXtID4
      tool_Task (void)
        = 0;
    virtual LxResult
      tool_Sequence (ILxUnknownID seq)
        { return LXe_NOTIMPL; }
    virtual int
      tool_ShouldBeAttribute (LXtID4 task)
        { return 0; }
};
#define LXxD_Tool_Reset void tool_Reset (void)
#define LXxO_Tool_Reset LXxD_Tool_Reset LXx_OVERRIDE
#define LXxD_Tool_Evaluate void tool_Evaluate (ILxUnknownID vts)
#define LXxO_Tool_Evaluate LXxD_Tool_Evaluate LXx_OVERRIDE
#define LXxD_Tool_VectorType LXtObjectID tool_VectorType (void)
#define LXxO_Tool_VectorType LXxD_Tool_VectorType LXx_OVERRIDE
#define LXxD_Tool_Order const char * tool_Order (void)
#define LXxO_Tool_Order LXxD_Tool_Order LXx_OVERRIDE
#define LXxD_Tool_Task LXtID4 tool_Task (void)
#define LXxO_Tool_Task LXxD_Tool_Task LXx_OVERRIDE
#define LXxD_Tool_Sequence LxResult tool_Sequence (ILxUnknownID seq)
#define LXxO_Tool_Sequence LXxD_Tool_Sequence LXx_OVERRIDE
#define LXxD_Tool_ShouldBeAttribute int tool_ShouldBeAttribute (LXtID4 task)
#define LXxO_Tool_ShouldBeAttribute LXxD_Tool_ShouldBeAttribute LXx_OVERRIDE
template <class T>
class CLxIfc_Tool : public CLxInterface
{
    static void
  Reset (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Tool, loc);
    loc->tool_Reset ();
  }
    static void
  Evaluate (LXtObjectID wcom, LXtObjectID vts)
  {
    LXCWxINST (CLxImpl_Tool, loc);
    loc->tool_Evaluate ((ILxUnknownID)vts);
  }
    static LXtObjectID
  VectorType (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Tool, loc);
    return loc->tool_VectorType ();
  }
    static const char *
  Order (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Tool, loc);
    return loc->tool_Order ();
  }
    static LXtID4
  Task (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Tool, loc);
    return loc->tool_Task ();
  }
    static LxResult
  Sequence (LXtObjectID wcom, LXtObjectID seq)
  {
    LXCWxINST (CLxImpl_Tool, loc);
    try {
      return loc->tool_Sequence ((ILxUnknownID)seq);
    } catch (LxResult rc) { return rc; }
  }
    static int
  ShouldBeAttribute (LXtObjectID wcom, LXtID4 task)
  {
    LXCWxINST (CLxImpl_Tool, loc);
    return loc->tool_ShouldBeAttribute (task);
  }
  ILxTool vt;
public:
  CLxIfc_Tool ()
  {
    vt.Reset = Reset;
    vt.Evaluate = Evaluate;
    vt.VectorType = VectorType;
    vt.Order = Order;
    vt.Task = Task;
    vt.Sequence = Sequence;
    vt.ShouldBeAttribute = ShouldBeAttribute;
    vTable = &vt.iunk;
    iid = &lx::guid_Tool;
  }
};
class CLxLoc_Tool : public CLxLocalize<ILxToolID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Tool() {_init();}
  CLxLoc_Tool(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Tool(const CLxLoc_Tool &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Tool;}
    void
  Reset (void)
  {
    m_loc[0]->Reset (m_loc);
  }
    void
  Evaluate (ILxUnknownID vts)
  {
    m_loc[0]->Evaluate (m_loc,(ILxUnknownID)vts);
  }
    ILxUnknownID
  VectorType (void)
  {
    return (ILxUnknownID) m_loc[0]->VectorType (m_loc);
  }
    const char *
  Order (void)
  {
    return m_loc[0]->Order (m_loc);
  }
    LXtID4
  Task (void)
  {
    return m_loc[0]->Task (m_loc);
  }
    LxResult
  Sequence (ILxUnknownID seq)
  {
    return m_loc[0]->Sequence (m_loc,(ILxUnknownID)seq);
  }
    int
  ShouldBeAttribute (LXtID4 task)
  {
    return m_loc[0]->ShouldBeAttribute (m_loc,task);
  }
};

class CLxLoc_PathGeneratorPacket : public CLxLocalize<ILxPathGeneratorPacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PathGeneratorPacket() {_init();}
  CLxLoc_PathGeneratorPacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PathGeneratorPacket(const CLxLoc_PathGeneratorPacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PathGeneratorPacket;}
    LxResult
  Value (ILxUnknownID vts, double t, LXtVector pos)
  {
    return m_loc[0]->Value (m_loc,(ILxUnknownID)vts,t,pos);
  }
    double
  Length (ILxUnknownID vts, double t0, double t1)
  {
    return m_loc[0]->Length (m_loc,(ILxUnknownID)vts,t0,t1);
  }
    LxResult
  Tangent (ILxUnknownID vts, double t, double *tan)
  {
    return m_loc[0]->Tangent (m_loc,(ILxUnknownID)vts,t,tan);
  }
    LXtPolygonID
  Source (ILxUnknownID vts)
  {
    return m_loc[0]->Source (m_loc,(ILxUnknownID)vts);
  }
    int
  Count (ILxUnknownID vts)
  {
    return m_loc[0]->Count (m_loc,(ILxUnknownID)vts);
  }
    LxResult
  Knot (ILxUnknownID vts, int index, LXtPathKnot *knot)
  {
    return m_loc[0]->Knot (m_loc,(ILxUnknownID)vts,index,knot);
  }
    int
  Current (ILxUnknownID vts)
  {
    return m_loc[0]->Current (m_loc,(ILxUnknownID)vts);
  }
    LxResult
  KnotDataSet (ILxUnknownID gen)
  {
    return m_loc[0]->KnotDataSet (m_loc,(ILxUnknownID)gen);
  }
    int
  Walk (ILxUnknownID vts, ILxUnknownID pathStep, double angle, double ti, double tf)
  {
    return m_loc[0]->Walk (m_loc,(ILxUnknownID)vts,(ILxUnknownID)pathStep,angle,ti,tf);
  }
    double
  Bank (ILxUnknownID vts, double t)
  {
    return m_loc[0]->Bank (m_loc,(ILxUnknownID)vts,t);
  }
};

class CLxLoc_ElementCenterPacket : public CLxLocalize<ILxElementCenterPacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ElementCenterPacket() {_init();}
  CLxLoc_ElementCenterPacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ElementCenterPacket(const CLxLoc_ElementCenterPacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ElementCenterPacket;}
    LxResult
  Center (LXtPointID vrx, LXtFVector center)
  {
    return m_loc[0]->Center (m_loc,vrx,center);
  }
};

class CLxLoc_ParticleGeneratorPacket : public CLxLocalize<ILxParticleGeneratorPacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ParticleGeneratorPacket() {_init();}
  CLxLoc_ParticleGeneratorPacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ParticleGeneratorPacket(const CLxLoc_ParticleGeneratorPacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ParticleGeneratorPacket;}
    int
  Count (ILxUnknownID vts)
  {
    return m_loc[0]->Count (m_loc,(ILxUnknownID)vts);
  }
    LxResult
  Particle (ILxUnknownID vts, int index, LXtPGenParticle *part)
  {
    return m_loc[0]->Particle (m_loc,(ILxUnknownID)vts,index,part);
  }
    LxResult
  InitialParticleSet (const LXtPGenParticle *part)
  {
    return m_loc[0]->InitialParticleSet (m_loc,part);
  }
    LxResult
  HintBoxSet (const LXtBBox *box, LXtPGenParticle *part)
  {
    return m_loc[0]->HintBoxSet (m_loc,box,part);
  }
};

#endif

