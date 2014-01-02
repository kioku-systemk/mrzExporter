/*
 * C++ wrapper for lxtoolui.h
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
#ifndef LXW_TOOLUI_HPP
#define LXW_TOOLUI_HPP

#include <lxtoolui.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_PaintBrushPacket = {0x9283C21E,0x77FC,0x402D,0xB2,0x2A,0x7B,0x26,0x28,0x58,0x88,0xC4};
    static const LXtGUID guid_PaintNozzlePacket = {0xF0BB49ED,0x0BBB,0x448a,0x83,0x39,0xF6,0x9F,0x78,0xE9,0x50,0x48};
    static const LXtGUID guid_PaintInkPacket = {0x340EE412,0x232D,0x4619,0x97,0x4D,0x7E,0x59,0xC7,0xB3,0x93,0x53};
    static const LXtGUID guid_RaycastPacket = {0xD622B573,0x2638,0x4A47,0xAD,0x91,0x6B,0xC7,0xA6,0xD2,0xD3,0x0B};
};

class CLxLoc_PaintBrushPacket : public CLxLocalize<ILxPaintBrushPacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PaintBrushPacket() {_init();}
  CLxLoc_PaintBrushPacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PaintBrushPacket(const CLxLoc_PaintBrushPacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PaintBrushPacket;}
    int
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    float
  Size (void)
  {
    return m_loc[0]->Size (m_loc);
  }
    int
  BBox (ILxUnknownID toolVector, const LXtVector center, double size, LXtBBox *bbox)
  {
    return m_loc[0]->BBox (m_loc,(ILxUnknownID)toolVector,center,size,bbox);
  }
    int
  Eval2D (ILxUnknownID toolVector, float multiplier, LXtPaintBrush *brush)
  {
    return m_loc[0]->Eval2D (m_loc,(ILxUnknownID)toolVector,multiplier,brush);
  }
    double
  Eval3D (ILxUnknownID toolVector, const LXtVector center, const LXtVector wpos, const LXtVector bpos, double rad, float *rgba)
  {
    return m_loc[0]->Eval3D (m_loc,(ILxUnknownID)toolVector,center,wpos,bpos,rad,rgba);
  }
};

class CLxLoc_PaintNozzlePacket : public CLxLocalize<ILxPaintNozzlePacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PaintNozzlePacket() {_init();}
  CLxLoc_PaintNozzlePacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PaintNozzlePacket(const CLxLoc_PaintNozzlePacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PaintNozzlePacket;}
    int
  Paint (ILxUnknownID toolVector, float brushSize)
  {
    return m_loc[0]->Paint (m_loc,(ILxUnknownID)toolVector,brushSize);
  }
    int
  Jitter (ILxUnknownID toolVector, float brushSize, int *xj, int *yj)
  {
    return m_loc[0]->Jitter (m_loc,(ILxUnknownID)toolVector,brushSize,xj,yj);
  }
    int
  Nozzle (ILxUnknownID toolVector, float *strength, float *size, float *rotation)
  {
    return m_loc[0]->Nozzle (m_loc,(ILxUnknownID)toolVector,strength,size,rotation);
  }
};

class CLxLoc_PaintInkPacket : public CLxLocalize<ILxPaintInkPacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_PaintInkPacket() {_init();}
  CLxLoc_PaintInkPacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_PaintInkPacket(const CLxLoc_PaintInkPacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_PaintInkPacket;}
    int
  Flags (ILxUnknownID toolVector)
  {
    return m_loc[0]->Flags (m_loc,(ILxUnknownID)toolVector);
  }
    int
  Color (ILxUnknownID toolVector, int flags, LXtColorRGBA rgba)
  {
    return m_loc[0]->Color (m_loc,(ILxUnknownID)toolVector,flags,rgba);
  }
    int
  Stamp (LXtPaintBrush *brush)
  {
    return m_loc[0]->Stamp (m_loc,brush);
  }
};

class CLxLoc_RaycastPacket : public CLxLocalize<ILxRaycastPacketID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_RaycastPacket() {_init();}
  CLxLoc_RaycastPacket(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_RaycastPacket(const CLxLoc_RaycastPacket &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_RaycastPacket;}
    int
  HitPolygon (ILxUnknownID toolVector, float x, float y, LXtHitPolygon *hit)
  {
    return m_loc[0]->HitPolygon (m_loc,(ILxUnknownID)toolVector,x,y,hit);
  }
    int
  HitEdge (ILxUnknownID toolVector, float x, float y, LXtHitEdge *hit)
  {
    return m_loc[0]->HitEdge (m_loc,(ILxUnknownID)toolVector,x,y,hit);
  }
    int
  HitVertex (ILxUnknownID toolVector, float x, float y, LXtHitVertex *hit)
  {
    return m_loc[0]->HitVertex (m_loc,(ILxUnknownID)toolVector,x,y,hit);
  }
    int
  HitItem (ILxUnknownID toolVector, float x, float y, LXtHitItem *hit)
  {
    return m_loc[0]->HitItem (m_loc,(ILxUnknownID)toolVector,x,y,hit);
  }
};

#endif

