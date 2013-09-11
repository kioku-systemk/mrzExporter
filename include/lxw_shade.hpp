/*
 * C++ wrapper for lxshade.h
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
#ifndef LXW_SHADE_HPP
#define LXW_SHADE_HPP

#include <lxshade.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_CompShader = {0x06717e9d,0x610d,0x439f,0x93,0x5b,0xaf,0x08,0x05,0x82,0x7e,0xde};
    static const LXtGUID guid_ValueTextureCustom = {0xDE3298A6,0x1607,0x4338,0xB0,0x61,0x18,0x55,0x28,0xE6,0xFB,0x51};
    static const LXtGUID guid_TextureGL = {0x55CE355E,0xC838,0x4222,0xAB,0xED,0xCB,0xDD,0x80,0x82,0x09,0xAF};
    static const LXtGUID guid_TextureLayer = {0x42369FE7,0x869E,0x4c61,0x8D,0x40,0xAC,0x62,0xE5,0x29,0xDD,0x15};
    static const LXtGUID guid_CustomMaterial = {0xd0c4106c,0xdfd5,0x4a58,0xad,0x48,0x45,0xb5,0x0a,0xe6,0x3f,0x59};
    static const LXtGUID guid_Texture = {0x6376D941,0x9437,0x4cf8,0xB6,0xEC,0xAB,0x50,0x79,0x1F,0xE6,0x0F};
    static const LXtGUID guid_TextureVMap = {0x0C68AC79,0x993C,0x4823,0x97,0xFA,0xEA,0xD5,0xEF,0xF9,0x7B,0x64};
    static const LXtGUID guid_TextureEval = {0x847C1567,0x1725,0x4e98,0xBA,0x09,0xEA,0x1F,0x90,0x49,0xD7,0x6A};
    static const LXtGUID guid_ValueTexture = {0xCA0E3524,0x6F82,0x44B8,0xAA,0xC9,0xDC,0x25,0x8F,0x54,0x8C,0x02};
    static const LXtGUID guid_TextureMask = {0x701E81D3,0xFFA6,0x475a,0xA0,0x2D,0xEC,0xE9,0xAB,0x15,0xB4,0xCD};
};

class CLxImpl_CompShader {
  public:
    virtual ~CLxImpl_CompShader() {}
    virtual LxResult
      csh_SetupChannels (ILxUnknownID addChan)
        { return LXe_NOTIMPL; }
    virtual LxResult
      csh_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      csh_ReadChannels (ILxUnknownID attr, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual LxResult
      csh_Customize (ILxUnknownID custom, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual void
      csh_Evaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
        { }
    virtual LxResult
      csh_SetShadeFlags (LXpShadeFlags *sFlg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      csh_SetOpaque (int *opaque)
        { return LXe_NOTIMPL; }
    virtual LxResult
      csh_CustomPacket (const char **packet)
        { return LXe_NOTIMPL; }
    virtual void
      csh_Cleanup (void *data)
        { }
};
template <class T>
class CLxIfc_CompShader : public CLxInterface
{
    static LxResult
  SetupChannels (LXtObjectID wcom, LXtObjectID addChan)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    try {
      return loc->csh_SetupChannels ((ILxUnknownID)addChan);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LinkChannels (LXtObjectID wcom, LXtObjectID eval, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    try {
      return loc->csh_LinkChannels ((ILxUnknownID)eval,(ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ReadChannels (LXtObjectID wcom, LXtObjectID attr, void **ppvData)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    try {
      return loc->csh_ReadChannels ((ILxUnknownID)attr,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Customize (LXtObjectID wcom, LXtObjectID custom, void **ppvData)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    try {
      return loc->csh_Customize ((ILxUnknownID)custom,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Evaluate (LXtObjectID wcom, LXtObjectID vector, LXtObjectID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    loc->csh_Evaluate ((ILxUnknownID)vector,(ILxUnknownID)rayObj,sCmp,sOut,data);
  }
    static LxResult
  SetShadeFlags (LXtObjectID wcom, LXpShadeFlags *sFlg)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    try {
      return loc->csh_SetShadeFlags (sFlg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetOpaque (LXtObjectID wcom, int *opaque)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    try {
      return loc->csh_SetOpaque (opaque);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CustomPacket (LXtObjectID wcom, const char **packet)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    try {
      return loc->csh_CustomPacket (packet);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom, void *data)
  {
    LXCWxINST (CLxImpl_CompShader, loc);
    loc->csh_Cleanup (data);
  }
  ILxCompShader vt;
public:
  CLxIfc_CompShader ()
  {
    vt.SetupChannels = SetupChannels;
    vt.LinkChannels = LinkChannels;
    vt.ReadChannels = ReadChannels;
    vt.Customize = Customize;
    vt.Evaluate = Evaluate;
    vt.SetShadeFlags = SetShadeFlags;
    vt.SetOpaque = SetOpaque;
    vt.CustomPacket = CustomPacket;
    vt.Cleanup = Cleanup;
    vTable = &vt.iunk;
    iid = &lx::guid_CompShader;
  }
};

class CLxLoc_ValueTextureCustom : public CLxLocalize<ILxValueTextureCustomID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ValueTextureCustom() {_init();}
  CLxLoc_ValueTextureCustom(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ValueTextureCustom(const CLxLoc_ValueTextureCustom &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ValueTextureCustom;}
    LxResult
  AddFeature (LXtID4 type, const char *name)
  {
    return m_loc[0]->AddFeature (m_loc,type,name);
  }
    LxResult
  AddPacket (const char *name)
  {
    return m_loc[0]->AddPacket (m_loc,name);
  }
};



class CLxImpl_CustomMaterial {
  public:
    virtual ~CLxImpl_CustomMaterial() {}
    virtual LxResult
      cmt_SetupChannels (ILxUnknownID addChan)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_ReadChannels (ILxUnknownID attr, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_Customize (ILxUnknownID custom, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual void
      cmt_MaterialEvaluate (ILxUnknownID vector, void *data)
        { }
    virtual void
      cmt_ShaderEvaluate (ILxUnknownID vector, ILxUnknownID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
        { }
    virtual LxResult
      cmt_SetShadeFlags (LXpShadeFlags *sFlg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetBump (float *bumpAmplitude, int *clearBump)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetDisplacement (float *dispDist)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetOpaque (int *opaque)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_SetSmoothing (double *smooth, double *angle)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmt_CustomPacket (const char **packet)
        { return LXe_NOTIMPL; }
    virtual void
      cmt_Cleanup (void *data)
        { }
    virtual LxResult
      cmt_UpdatePreview (int chanIdx, int *flags)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_CustomMaterial : public CLxInterface
{
    static LxResult
  SetupChannels (LXtObjectID wcom, LXtObjectID addChan)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_SetupChannels ((ILxUnknownID)addChan);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LinkChannels (LXtObjectID wcom, LXtObjectID eval, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_LinkChannels ((ILxUnknownID)eval,(ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ReadChannels (LXtObjectID wcom, LXtObjectID attr, void **ppvData)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_ReadChannels ((ILxUnknownID)attr,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Customize (LXtObjectID wcom, LXtObjectID custom, void **ppvData)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_Customize ((ILxUnknownID)custom,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static void
  MaterialEvaluate (LXtObjectID wcom, LXtObjectID vector, void *data)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    loc->cmt_MaterialEvaluate ((ILxUnknownID)vector,data);
  }
    static void
  ShaderEvaluate (LXtObjectID wcom, LXtObjectID vector, LXtObjectID rayObj, LXpShadeComponents *sCmp, LXpShadeOutput *sOut, void *data)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    loc->cmt_ShaderEvaluate ((ILxUnknownID)vector,(ILxUnknownID)rayObj,sCmp,sOut,data);
  }
    static LxResult
  SetShadeFlags (LXtObjectID wcom, LXpShadeFlags *sFlg)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_SetShadeFlags (sFlg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetBump (LXtObjectID wcom, float *bumpAmplitude, int *clearBump)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_SetBump (bumpAmplitude,clearBump);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetDisplacement (LXtObjectID wcom, float *dispDist)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_SetDisplacement (dispDist);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetOpaque (LXtObjectID wcom, int *opaque)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_SetOpaque (opaque);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetSmoothing (LXtObjectID wcom, double *smooth, double *angle)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_SetSmoothing (smooth,angle);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  CustomPacket (LXtObjectID wcom, const char **packet)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_CustomPacket (packet);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Cleanup (LXtObjectID wcom, void *data)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    loc->cmt_Cleanup (data);
  }
    static LxResult
  UpdatePreview (LXtObjectID wcom, int chanIdx, int *flags)
  {
    LXCWxINST (CLxImpl_CustomMaterial, loc);
    try {
      return loc->cmt_UpdatePreview (chanIdx,flags);
    } catch (LxResult rc) { return rc; }
  }
  ILxCustomMaterial vt;
public:
  CLxIfc_CustomMaterial ()
  {
    vt.SetupChannels = SetupChannels;
    vt.LinkChannels = LinkChannels;
    vt.ReadChannels = ReadChannels;
    vt.Customize = Customize;
    vt.MaterialEvaluate = MaterialEvaluate;
    vt.ShaderEvaluate = ShaderEvaluate;
    vt.SetShadeFlags = SetShadeFlags;
    vt.SetBump = SetBump;
    vt.SetDisplacement = SetDisplacement;
    vt.SetOpaque = SetOpaque;
    vt.SetSmoothing = SetSmoothing;
    vt.CustomPacket = CustomPacket;
    vt.Cleanup = Cleanup;
    vt.UpdatePreview = UpdatePreview;
    vTable = &vt.iunk;
    iid = &lx::guid_CustomMaterial;
  }
};

class CLxLoc_Texture : public CLxLocalize<ILxTextureID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Texture() {_init();}
  CLxLoc_Texture(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Texture(const CLxLoc_Texture &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Texture;}
    LxResult
  Locator (void **ppvObj)
  {
    return m_loc[0]->Locator (m_loc,ppvObj);
  }
    LxResult
  SetLocator (ILxUnknownID tloc)
  {
    return m_loc[0]->SetLocator (m_loc,(ILxUnknownID)tloc);
  }
    LxResult
  Image (void **ppvObj)
  {
    return m_loc[0]->Image (m_loc,ppvObj);
  }
    LxResult
  SetImage (ILxUnknownID img)
  {
    return m_loc[0]->SetImage (m_loc,(ILxUnknownID)img);
  }
    const char *
  ImageName (void)
  {
    return m_loc[0]->ImageName (m_loc);
  }
    LxResult
  EvalImage (ILxUnknownID scene, void **ppvObj)
  {
    return m_loc[0]->EvalImage (m_loc,(ILxUnknownID)scene,ppvObj);
  }
    int
  LocatorProjectionMode (double time)
  {
    return m_loc[0]->LocatorProjectionMode (m_loc,time);
  }
    int
  LocatorProjectionAxis (double time)
  {
    return m_loc[0]->LocatorProjectionAxis (m_loc,time);
  }
    const char *
  Effect (void)
  {
    return m_loc[0]->Effect (m_loc);
  }
    LxResult
  SetEffect (const char *effect)
  {
    return m_loc[0]->SetEffect (m_loc,effect);
  }
};



class CLxImpl_ValueTexture {
  public:
    virtual ~CLxImpl_ValueTexture() {}
    virtual LxResult
      vtx_SetupChannels (ILxUnknownID addChan)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtx_LinkChannels (ILxUnknownID eval, ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtx_ReadChannels (ILxUnknownID attr, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual LxResult
      vtx_Customize (ILxUnknownID custom, void **ppvData)
        { return LXe_NOTIMPL; }
    virtual void
      vtx_Evaluate (ILxUnknownID vector, LXpTextureOutput *tOut, void *data)
        { }
    virtual void
      vtx_Cleanup (void *data)
        { }
};
template <class T>
class CLxIfc_ValueTexture : public CLxInterface
{
    static LxResult
  SetupChannels (LXtObjectID wcom, LXtObjectID addChan)
  {
    LXCWxINST (CLxImpl_ValueTexture, loc);
    try {
      return loc->vtx_SetupChannels ((ILxUnknownID)addChan);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LinkChannels (LXtObjectID wcom, LXtObjectID eval, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_ValueTexture, loc);
    try {
      return loc->vtx_LinkChannels ((ILxUnknownID)eval,(ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ReadChannels (LXtObjectID wcom, LXtObjectID attr, void **ppvData)
  {
    LXCWxINST (CLxImpl_ValueTexture, loc);
    try {
      return loc->vtx_ReadChannels ((ILxUnknownID)attr,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Customize (LXtObjectID wcom, LXtObjectID custom, void **ppvData)
  {
    LXCWxINST (CLxImpl_ValueTexture, loc);
    try {
      return loc->vtx_Customize ((ILxUnknownID)custom,ppvData);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Evaluate (LXtObjectID wcom, LXtObjectID vector, LXpTextureOutput *tOut, void *data)
  {
    LXCWxINST (CLxImpl_ValueTexture, loc);
    loc->vtx_Evaluate ((ILxUnknownID)vector,tOut,data);
  }
    static void
  Cleanup (LXtObjectID wcom, void *data)
  {
    LXCWxINST (CLxImpl_ValueTexture, loc);
    loc->vtx_Cleanup (data);
  }
  ILxValueTexture vt;
public:
  CLxIfc_ValueTexture ()
  {
    vt.SetupChannels = SetupChannels;
    vt.LinkChannels = LinkChannels;
    vt.ReadChannels = ReadChannels;
    vt.Customize = Customize;
    vt.Evaluate = Evaluate;
    vt.Cleanup = Cleanup;
    vTable = &vt.iunk;
    iid = &lx::guid_ValueTexture;
  }
};


#endif

