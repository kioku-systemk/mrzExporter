/*
 * LX ilxlocator module
 *
 * Copyright (c) 2008-2013 Luxology LLC
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.   Except as contained
 * in this notice, the name(s) of the above copyright holders shall not be
 * used in advertising or otherwise to promote the sale, use or other dealings
 * in this Software without prior written authorization.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
#ifndef LX_ilxlocator_H
#define LX_ilxlocator_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxLocator ** ILxLocatorID;
#include <lxvalue.h>
#include <lxitem.h>



typedef struct vt_ILxLocator {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Visible) (
                LXtObjectID              self,
                LXtObjectID              chanRead);
                LXxMETHOD(  LxResult,
        WorldTransform) (
                LXtObjectID              self,
                LXtObjectID              chanRead,
                LXtMatrix                xfrm,
                LXtVector                pos);
                LXxMETHOD(  LxResult,
        GetTransformItem) (
                LXtObjectID              self,
                LXtTransformType         type,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        AddTransformItem) (
                LXtObjectID              self,
                LXtTransformType         type,
                void                   **ppvObj,
                unsigned                *index);
                LXxMETHOD(  LxResult,
        SetTransformVector) (
                LXtObjectID              self,
                LXtObjectID              chanWrite,
                LXtTransformType         type,
                const LXtVector          value);
                LXxMETHOD(  LxResult,
        AddPreTransformItem) (
                LXtObjectID              self,
                LXtObjectID              chanWrite,
                LXtTransformType         type,
                const LXtVector          value,
                void                   **ppvObj,
                unsigned                *index);
                LXxMETHOD(  LxResult,
        AddPostTransformItem) (
                LXtObjectID              self,
                LXtObjectID              chanWrite,
                LXtTransformType         type,
                const LXtVector          value,
                void                   **ppvObj,
                unsigned                *index);
                LXxMETHOD(  LxResult,
        SetTarget) (
                LXtObjectID              self,
                LXtObjectID              target,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        PrependTransformItem) (
                LXtObjectID              self,
                LXtObjectID              chanWrite,
                LXtTransformType         type,
                const LXtVector          value,
                void                   **ppvObj,
                unsigned                *index);
                LXxMETHOD(  LxResult,
        AppendTransformItem) (
                LXtObjectID              self,
                LXtObjectID              chanWrite,
                LXtTransformType         type,
                const LXtVector          value,
                void                   **ppvObj,
                unsigned                *index);
                LXxMETHOD(  LxResult,
        SetPosition) (
                LXtObjectID              self,
                LXtObjectID              chanRead,
                LXtObjectID              chanWrite,
                const LXtVector          pos,
                unsigned                 type,
                unsigned                 comp);
                LXxMETHOD(  LxResult,
        SetRotation) (
                LXtObjectID              self,
                LXtObjectID              chanRead,
                LXtObjectID              chanWrite,
                const LXtMatrix          m3,
                unsigned                 type,
                unsigned                 comp);
                LXxMETHOD(  LxResult,
        SetScale) (
                LXtObjectID              self,
                LXtObjectID              chanRead,
                LXtObjectID              chanWrite,
                const LXtMatrix4         m4,
                unsigned                 type,
                unsigned                 comp);
                LXxMETHOD(  LxResult,
        ExtractLocalPosition) (
                LXtObjectID              self,
                LXtObjectID              chanRead,
                LXtVector                pos);
                LXxMETHOD(  LxResult,
        ExtractLocalRotation) (
                LXtObjectID              self,
                LXtObjectID              chanRead,
                LXtMatrix                m3);
                LXxMETHOD(  LxResult,
        ZeroTransform) (
                LXtObjectID              self,
                LXtObjectID              chanRead,
                LXtObjectID              chanWrite,
                LXtTransformType         type);
                LXxMETHOD(  LxResult,
        WorldTransform4) (
                LXtObjectID              self,
                LXtObjectID              chanRead,
                LXtMatrix4               xfrm4);
                LXxMETHOD(  LxResult,
        WorldInvertTransform) (
                LXtObjectID              self,
                LXtObjectID              chanRead,
                LXtMatrix                xfrm,
                LXtVector                pos);
} ILxLocator;

#define LXu_LOCATOR     "50DCCB9D-9856-4A33-9BDA-DAF3A71BBD2D"
#define LXa_LOCATOR     "locator"
// [local]  ILxLocator
// [const]  ILxLocator:Visible
// [const]  ILxLocator:WorldTransform
// [const]  ILxLocator:WorldTransform4
// [const]  ILxLocator:GetTransformItem
// [const]  ILxLocator:GetXfrmItem
// [python] type LXtTransformType unsigned
// [python] ILxLocator:AddPostTransformItem     obj Item
// [python] ILxLocator:AddPreTransformItem      obj Item
// [python] ILxLocator:AddTransformItem         obj Item
// [python] ILxLocator:AppendTransformItem      obj Item
// [python] ILxLocator:GetTransformItem         obj Item
// [python] ILxLocator:PrependTransformItem     obj Item
// [python] ILxLocator:SetTarget                obj Item
// [python] ILxLocator:Visible                  bool
#define LXiICVAL_LIGHT_SHADTYPE_NONE            0
#define LXiICVAL_LIGHT_SHADTYPE_RAYTRACE        1
#define LXiICVAL_LIGHT_SHADTYPE_SHADOWMAP       2
#define LXiICVAL_LIGHT_SHADTYPE_PORTAL          3
#define LXiLOCATOR_LOCAL        0
#define LXiLOCATOR_WORLD        1       

 #ifdef __cplusplus
  }
 #endif
#endif

