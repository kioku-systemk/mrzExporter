/*
 * C++ wrapper for lxraycast.h
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
#ifndef LXW_RAYCAST_HPP
#define LXW_RAYCAST_HPP

#include <lxraycast.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_Raycast = {0x7B13E5D2,0xD0D9,0x427A,0xA1,0xD4,0x6D,0xAE,0xB1,0x92,0xB8,0xB0};
};

class CLxLoc_Raycast : public CLxLocalize<ILxRaycastID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Raycast() {_init();}
  CLxLoc_Raycast(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Raycast(const CLxLoc_Raycast &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Raycast;}
    ILxUnknownID
  RayPush (ILxUnknownID vector)
  {
    return m_loc[0]->RayPush (m_loc,(ILxUnknownID)vector);
  }
    LxResult
  RayPop (ILxUnknownID vector)
  {
    return m_loc[0]->RayPop (m_loc,(ILxUnknownID)vector);
  }
    float
  Raycast (ILxUnknownID vector, const LXtVector pos, const LXtFVector dir)
  {
    return m_loc[0]->Raycast (m_loc,(ILxUnknownID)vector,pos,dir);
  }
    float
  Raytrace (ILxUnknownID vector, const LXtVector pos, const LXtFVector dir, int flags)
  {
    return m_loc[0]->Raytrace (m_loc,(ILxUnknownID)vector,pos,dir,flags);
  }
    LxResult
  InternalShade (ILxUnknownID vector)
  {
    return m_loc[0]->InternalShade (m_loc,(ILxUnknownID)vector);
  }
    int
  LightCount (ILxUnknownID vector) const
  {
    return m_loc[0]->LightCount (m_loc,(ILxUnknownID)vector);
  }
    LxResult
  LightSampleCount (ILxUnknownID vector, const LXtVector pos, const LXtFVector nrm, int *num)
  {
    return m_loc[0]->LightSampleCount (m_loc,(ILxUnknownID)vector,pos,nrm,num);
  }
    int
  LightShadowType (ILxUnknownID vector, int lgtIndex) const
  {
    return m_loc[0]->LightShadowType (m_loc,(ILxUnknownID)vector,lgtIndex);
  }
    int
  LightSampleCountByLight (ILxUnknownID vector, int lgtIndex) const
  {
    return m_loc[0]->LightSampleCountByLight (m_loc,(ILxUnknownID)vector,lgtIndex);
  }
    LxResult
  LightSampleByIndex (ILxUnknownID vector, int index, LXpLightColor *lCol, float *dot)
  {
    return m_loc[0]->LightSampleByIndex (m_loc,(ILxUnknownID)vector,index,lCol,dot);
  }
    LxResult
  LightValue (ILxUnknownID vector, int lgtIndex, LXtFVector *color, float *intensity)
  {
    return m_loc[0]->LightValue (m_loc,(ILxUnknownID)vector,lgtIndex,color,intensity);
  }
    LxResult
  GetNextShadowRay (ILxUnknownID vector, int lgtIndex, LXtVector pos, LXtFVector *dir, int *flags)
  {
    return m_loc[0]->GetNextShadowRay (m_loc,(ILxUnknownID)vector,lgtIndex,pos,dir,flags);
  }
    LxResult
  GetNextGIRaySphere (ILxUnknownID vector, LXtFVector *dir, int *flags)
  {
    return m_loc[0]->GetNextGIRaySphere (m_loc,(ILxUnknownID)vector,dir,flags);
  }
    LxResult
  GetNextGIRayHemisphere (ILxUnknownID vector, LXtFVector *dir, int *flags)
  {
    return m_loc[0]->GetNextGIRayHemisphere (m_loc,(ILxUnknownID)vector,dir,flags);
  }
    LxResult
  GetSurfaceID (ILxUnknownID vector, void **id)
  {
    return m_loc[0]->GetSurfaceID (m_loc,(ILxUnknownID)vector,id);
  }
    LxResult
  PixelToRay (ILxUnknownID vector, int mode, float x, float y, LXpSampleRay *sRay)
  {
    return m_loc[0]->PixelToRay (m_loc,(ILxUnknownID)vector,mode,x,y,sRay);
  }
    LxResult
  PixelGeometry (ILxUnknownID vector, int mode, float x, float y, LXpPixelGeometry *pGeo)
  {
    return m_loc[0]->PixelGeometry (m_loc,(ILxUnknownID)vector,mode,x,y,pGeo);
  }
    LxResult
  PoissonOffset (ILxUnknownID vector, float *u, float *v)
  {
    return m_loc[0]->PoissonOffset (m_loc,(ILxUnknownID)vector,u,v);
  }
    LxResult
  Irradiance (ILxUnknownID vector, const LXtVector pos, const LXtFVector nrm, LXtFVector lum)
  {
    return m_loc[0]->Irradiance (m_loc,(ILxUnknownID)vector,pos,nrm,lum);
  }
    LxResult
  GetBucketGlobalBounce (ILxUnknownID vector, int *globBounce)
  {
    return m_loc[0]->GetBucketGlobalBounce (m_loc,(ILxUnknownID)vector,globBounce);
  }
    LxResult
  GetBucketPixel (ILxUnknownID vector, int *x, int *y)
  {
    return m_loc[0]->GetBucketPixel (m_loc,(ILxUnknownID)vector,x,y);
  }
    LxResult
  GetBucketSubPixel (ILxUnknownID vector, float *x, float *y)
  {
    return m_loc[0]->GetBucketSubPixel (m_loc,(ILxUnknownID)vector,x,y);
  }
    LxResult
  GetBucketTimeOffset (ILxUnknownID vector, float *tOffset)
  {
    return m_loc[0]->GetBucketTimeOffset (m_loc,(ILxUnknownID)vector,tOffset);
  }
    int
  GetSurfaceType (ILxUnknownID vector)
  {
    return m_loc[0]->GetSurfaceType (m_loc,(ILxUnknownID)vector);
  }
    LxResult
  GetLightSampleDirection (ILxUnknownID vector, int lgtIndex, LXtVector pos, LXtFVector *dir)
  {
    return m_loc[0]->GetLightSampleDirection (m_loc,(ILxUnknownID)vector,lgtIndex,pos,dir);
  }
};

#endif

