/*
 * C++ wrapper for lxparticle.h
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
#ifndef LXW_PARTICLE_HPP
#define LXW_PARTICLE_HPP

#include <lxparticle.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_ParticleFilter = {0x04A3C0C5,0x1C5C,0x43F5,0x85,0x59,0xAC,0xF3,0xBA,0xE7,0x9C,0x0B};
    static const LXtGUID guid_ParticleFilterItem = {0xEF31BA82,0x8EC4,0x46C5,0x9A,0x28,0x27,0x85,0xBE,0x78,0xD8,0x61};
    static const LXtGUID guid_ParticleEvalFrame = {0x1AC26263,0xA422,0x4B17,0xA9,0x29,0x2F,0x61,0x60,0x37,0x75,0x4F};
    static const LXtGUID guid_ParticleItem = {0xBA13DD5D,0x5093,0x4D0D,0xBE,0xFE,0x11,0x9A,0xD4,0xF1,0xFA,0xCB};
    static const LXtGUID guid_ReplicatorEnumerator = {0x01EC90A9,0x924F,0x4475,0xBA,0x6A,0xFF,0xF8,0xA2,0x69,0x1C,0xD5};
};

class CLxImpl_ParticleFilter {
  public:
    virtual ~CLxImpl_ParticleFilter() {}
    virtual LXtObjectID
      pfilt_Vertex (void)
        = 0;
    virtual unsigned
      pfilt_Type (void)
        = 0;
    virtual LxResult
      pfilt_Initialize (ILxUnknownID vertex, ILxUnknownID frame, double time)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pfilt_Step (ILxUnknownID other, double dt)
        { return LXe_NOTIMPL; }
    virtual void
      pfilt_Cleanup (void)
        { }
    virtual LxResult
      pfilt_Frame (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pfilt_Run (float **values, unsigned count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pfilt_Particle (float *vertex)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_ParticleFilter : public CLxInterface
{
    static LXtObjectID
  Vertex (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    return loc->pfilt_Vertex ();
  }
    static unsigned
  Type (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    return loc->pfilt_Type ();
  }
    static LxResult
  Initialize (LXtObjectID wcom, LXtObjectID vertex, LXtObjectID frame, double time)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    try {
      return loc->pfilt_Initialize ((ILxUnknownID)vertex,(ILxUnknownID)frame,time);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Step (LXtObjectID wcom, LXtObjectID other, double dt)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    try {
      return loc->pfilt_Step ((ILxUnknownID)other,dt);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    loc->pfilt_Cleanup ();
  }
    static LxResult
  Frame (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    try {
      return loc->pfilt_Frame ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Run (LXtObjectID wcom, float **values, unsigned count)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    try {
      return loc->pfilt_Run (values,count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Particle (LXtObjectID wcom, float *vertex)
  {
    LXCWxINST (CLxImpl_ParticleFilter, loc);
    try {
      return loc->pfilt_Particle (vertex);
    } catch (LxResult rc) { return rc; }
  }
  ILxParticleFilter vt;
public:
  CLxIfc_ParticleFilter ()
  {
    vt.Vertex = Vertex;
    vt.Type = Type;
    vt.Initialize = Initialize;
    vt.Step = Step;
    vt.Cleanup = Cleanup;
    vt.Frame = Frame;
    vt.Run = Run;
    vt.Particle = Particle;
    vTable = &vt.iunk;
    iid = &lx::guid_ParticleFilter;
  }
};
class CLxLoc_ParticleFilter : public CLxLocalize<ILxParticleFilterID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ParticleFilter() {_init();}
  CLxLoc_ParticleFilter(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ParticleFilter(const CLxLoc_ParticleFilter &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ParticleFilter;}
    ILxUnknownID
  Vertex (void)
  {
    return (ILxUnknownID) m_loc[0]->Vertex (m_loc);
  }
    unsigned
  Type (void)
  {
    return m_loc[0]->Type (m_loc);
  }
    LxResult
  Initialize (ILxUnknownID vertex, ILxUnknownID frame, double time)
  {
    return m_loc[0]->Initialize (m_loc,(ILxUnknownID)vertex,(ILxUnknownID)frame,time);
  }
    LxResult
  Step (ILxUnknownID other, double dt)
  {
    return m_loc[0]->Step (m_loc,(ILxUnknownID)other,dt);
  }
    void
  Cleanup (void)
  {
    m_loc[0]->Cleanup (m_loc);
  }
    LxResult
  Frame (void)
  {
    return m_loc[0]->Frame (m_loc);
  }
    LxResult
  Run (float **values, unsigned count)
  {
    return m_loc[0]->Run (m_loc,values,count);
  }
    LxResult
  Particle (float *vertex)
  {
    return m_loc[0]->Particle (m_loc,vertex);
  }
};

class CLxImpl_ParticleFilterItem {
  public:
    virtual ~CLxImpl_ParticleFilterItem() {}
    virtual LxResult
      pfi_Prepare (ILxUnknownID eval, unsigned *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      pfi_Evaluate (ILxUnknownID attr, unsigned index, void **ppvObj)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_ParticleFilterItem : public CLxInterface
{
    static LxResult
  Prepare (LXtObjectID wcom, LXtObjectID eval, unsigned *index)
  {
    LXCWxINST (CLxImpl_ParticleFilterItem, loc);
    try {
      return loc->pfi_Prepare ((ILxUnknownID)eval,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Evaluate (LXtObjectID wcom, LXtObjectID attr, unsigned index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ParticleFilterItem, loc);
    try {
      return loc->pfi_Evaluate ((ILxUnknownID)attr,index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxParticleFilterItem vt;
public:
  CLxIfc_ParticleFilterItem ()
  {
    vt.Prepare = Prepare;
    vt.Evaluate = Evaluate;
    vTable = &vt.iunk;
    iid = &lx::guid_ParticleFilterItem;
  }
};
class CLxLoc_ParticleFilterItem : public CLxLocalize<ILxParticleFilterItemID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ParticleFilterItem() {_init();}
  CLxLoc_ParticleFilterItem(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ParticleFilterItem(const CLxLoc_ParticleFilterItem &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ParticleFilterItem;}
    LxResult
  Prepare (ILxUnknownID eval, unsigned *index)
  {
    return m_loc[0]->Prepare (m_loc,(ILxUnknownID)eval,index);
  }
    LxResult
  Evaluate (ILxUnknownID attr, unsigned index, void **ppvObj)
  {
    return m_loc[0]->Evaluate (m_loc,(ILxUnknownID)attr,index,ppvObj);
  }
};

class CLxLoc_ParticleEvalFrame : public CLxLocalize<ILxParticleEvalFrameID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ParticleEvalFrame() {_init();}
  CLxLoc_ParticleEvalFrame(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ParticleEvalFrame(const CLxLoc_ParticleEvalFrame &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ParticleEvalFrame;}
    ILxUnknownID
  VertexDescription (void)
  {
    return (ILxUnknownID) m_loc[0]->VertexDescription (m_loc);
  }
    unsigned
  MaxCount (void)
  {
    return m_loc[0]->MaxCount (m_loc);
  }
    unsigned
  AliveCount (void)
  {
    return m_loc[0]->AliveCount (m_loc);
  }
    LxResult
  AddParticle (const float *state, unsigned *index)
  {
    return m_loc[0]->AddParticle (m_loc,state,index);
  }
    LxResult
  KillParticle (unsigned index)
  {
    return m_loc[0]->KillParticle (m_loc,index);
  }
    unsigned
  IsAlive (unsigned index)
  {
    return m_loc[0]->IsAlive (m_loc,index);
  }
    LxResult
  GetVector (unsigned index, float *vector)
  {
    return m_loc[0]->GetVector (m_loc,index,vector);
  }
    LxResult
  SetVector (unsigned index, const float *vector)
  {
    return m_loc[0]->SetVector (m_loc,index,vector);
  }
    LxResult
  AliveRun (unsigned first, const unsigned **alive, unsigned *count)
  {
    return m_loc[0]->AliveRun (m_loc,first,alive,count);
  }
    LxResult
  VectorRun (unsigned first, float **values, unsigned *count)
  {
    return m_loc[0]->VectorRun (m_loc,first,values,count);
  }
};

class CLxImpl_ParticleItem {
  public:
    virtual ~CLxImpl_ParticleItem() {}
    virtual LxResult
      prti_Prepare (ILxUnknownID eval, unsigned *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      prti_Evaluate (ILxUnknownID attr, unsigned index, void **ppvObj)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_ParticleItem : public CLxInterface
{
    static LxResult
  Prepare (LXtObjectID wcom, LXtObjectID eval, unsigned *index)
  {
    LXCWxINST (CLxImpl_ParticleItem, loc);
    try {
      return loc->prti_Prepare ((ILxUnknownID)eval,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Evaluate (LXtObjectID wcom, LXtObjectID attr, unsigned index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ParticleItem, loc);
    try {
      return loc->prti_Evaluate ((ILxUnknownID)attr,index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxParticleItem vt;
public:
  CLxIfc_ParticleItem ()
  {
    vt.Prepare = Prepare;
    vt.Evaluate = Evaluate;
    vTable = &vt.iunk;
    iid = &lx::guid_ParticleItem;
  }
};
class CLxLoc_ParticleItem : public CLxLocalize<ILxParticleItemID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ParticleItem() {_init();}
  CLxLoc_ParticleItem(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ParticleItem(const CLxLoc_ParticleItem &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ParticleItem;}
    LxResult
  Prepare (ILxUnknownID eval, unsigned *index)
  {
    return m_loc[0]->Prepare (m_loc,(ILxUnknownID)eval,index);
  }
    LxResult
  Evaluate (ILxUnknownID attr, unsigned index, void **ppvObj)
  {
    return m_loc[0]->Evaluate (m_loc,(ILxUnknownID)attr,index,ppvObj);
  }
};

class CLxLoc_ReplicatorEnumerator : public CLxLocalize<ILxReplicatorEnumeratorID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ReplicatorEnumerator() {_init();}
  CLxLoc_ReplicatorEnumerator(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ReplicatorEnumerator(const CLxLoc_ReplicatorEnumerator &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ReplicatorEnumerator;}
    LxResult
  Enumerate (ILxUnknownID visitor, ILxUnknownID chan, int localXform)
  {
    return m_loc[0]->Enumerate (m_loc,(ILxUnknownID)visitor,(ILxUnknownID)chan,localXform);
  }
    LxResult
  Item (void **ppvObj)
  {
    return m_loc[0]->Item (m_loc,ppvObj);
  }
    void
  Position (LXtVector pos)
  {
    m_loc[0]->Position (m_loc,pos);
  }
    void
  Orientation (LXtMatrix mx)
  {
    m_loc[0]->Orientation (m_loc,mx);
  }
    float
  Id (void)
  {
    return m_loc[0]->Id (m_loc);
  }
    float
  Dissolve (void)
  {
    return m_loc[0]->Dissolve (m_loc);
  }
};

#endif

