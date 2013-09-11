/*
 * C++ wrapper for lxtrisurf.h
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
#ifndef LXW_TRISURF_HPP
#define LXW_TRISURF_HPP

#include <lxtrisurf.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_TriangleGroup = {0x6975B2A4,0x69E8,0x4ED2,0x90,0x58,0x9C,0x09,0x48,0xCB,0xB4,0x3C};
    static const LXtGUID guid_TriangleSurface = {0xB1D985A7,0x34D6,0x4251,0x94,0xAA,0xEE,0xFB,0x2C,0x75,0x27,0xF9};
};

class CLxLoc_TriangleGroup : public CLxLocalize<ILxTriangleGroupID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TriangleGroup() {_init();}
  CLxLoc_TriangleGroup(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TriangleGroup(const CLxLoc_TriangleGroup &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TriangleGroup;}
    LxResult
  AddSurface (void **ppvObj)
  {
    return m_loc[0]->AddSurface (m_loc,ppvObj);
  }
    LxResult
  GetSurface (unsigned index, void **ppvObj)
  {
    return m_loc[0]->GetSurface (m_loc,index,ppvObj);
  }
};

class CLxLoc_TriangleSurface : public CLxLocalize<ILxTriangleSurfaceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_TriangleSurface() {_init();}
  CLxLoc_TriangleSurface(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_TriangleSurface(const CLxLoc_TriangleSurface &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_TriangleSurface;}
    LxResult
  SetSize (unsigned nvrt, unsigned ntri)
  {
    return m_loc[0]->SetSize (m_loc,nvrt,ntri);
  }
    LxResult
  AddVector (LXtID4 type, const char *name, unsigned *index)
  {
    return m_loc[0]->AddVector (m_loc,type,name,index);
  }
    float *
  SetVector (unsigned index, unsigned vrt)
  {
    return m_loc[0]->SetVector (m_loc,index,vrt);
  }
    unsigned *
  SetTriangle (unsigned tri)
  {
    return m_loc[0]->SetTriangle (m_loc,tri);
  }
    unsigned *
  FixNormals (void)
  {
    return m_loc[0]->FixNormals (m_loc);
  }
    void
  GetSize (unsigned *nvrt, unsigned *ntri)
  {
    m_loc[0]->GetSize (m_loc,nvrt,ntri);
  }
    unsigned *
  Triangles (void)
  {
    return m_loc[0]->Triangles (m_loc);
  }
    LxResult
  VectorInfo (unsigned index, LXtID4 *type, const char **name, unsigned *dim)
  {
    return m_loc[0]->VectorInfo (m_loc,index,type,name,dim);
  }
    float *
  Vector (unsigned index)
  {
    return m_loc[0]->Vector (m_loc,index);
  }
};

#endif
