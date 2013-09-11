/*
 * LX vmodel module
 *
 * Copyright (c) 2008-2012 Luxology LLC
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
#ifndef LX_vmodel_H
#define LX_vmodel_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxViewItem3D ** ILxViewItem3DID;
typedef struct vt_ILxToolModel ** ILxToolModelID;
typedef struct vt_ILxAdjustTool ** ILxAdjustToolID;
#include <lxvalue.h>
#include <lxvector.h>
#include <lxtool.h>
#include <lxhandles.h>
#include <lxdraw.h>
#include <lxvalue.h>



typedef struct vt_ILxViewItem3D {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Draw) (
                LXtObjectID              self,
                LXtObjectID              chanRead,
                LXtObjectID              strokeDraw,
                int                      selectionFlags,
                LXtVector                itemColor);

                LXxMETHOD(  LxResult,
        DrawBackground) (
                LXtObjectID              self,
                LXtObjectID              chanRead,
                LXtObjectID              strokeDraw,
                LXtVector                itemColor);

                LXxMETHOD(  LxResult,
        WorldSpace) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        HandleCount) (
                LXtObjectID              self,
                int                     *count);

                LXxMETHOD(  LxResult,
        HandleMotion) (
                LXtObjectID              self,
                int                      handleIndex,
                int                     *motionType,
                double                  *min,
                double                  *max,
                LXtVector                plane,
                LXtVector                offset);

                LXxMETHOD(  LxResult,
        HandleChannel) (
                LXtObjectID              self,
                int                      handleIndex,
                int                     *chanIndex);

                LXxMETHOD(  LxResult,
        HandleValueToPosition) (
                LXtObjectID              self,
                int                      handleIndex,
                double                   chanValue,
                LXtVector                position);

                LXxMETHOD(  LxResult,
        HandlePositionToValue) (
                LXtObjectID              self,
                int                      handleIndex,
                LXtVector                position,
                double                  *chanValue);
} ILxViewItem3D;
typedef struct vt_ILxToolModel {
        ILxUnknown       iunk;
                LXxMETHOD( unsigned,
        Flags) (
                LXtObjectID              self);
                LXxMETHOD( void,
        Draw) (
                LXtObjectID              self,
                LXtObjectID              vts,
                LXtObjectID              stroke,
                int                      flags);

                LXxMETHOD( void,
        Test) (
                LXtObjectID              self,
                LXtObjectID              vts,
                LXtObjectID              stroke,
                int                      flags);

                LXxMETHOD( void,
        Filter) (
                LXtObjectID              self,
                LXtObjectID              vts);
                LXxMETHOD( void,
        Initialize) (
                LXtObjectID              self,
                LXtObjectID              vts,
                LXtObjectID              adjust,
                unsigned int             flags);
                LXxMETHOD( LxResult,
        Down) (
                LXtObjectID              self,
                LXtObjectID              vts,
                LXtObjectID              adjust);

                LXxMETHOD( void,
        Move) (
                LXtObjectID              self,
                LXtObjectID              vts,
                LXtObjectID              adjust);

                LXxMETHOD( void,
        Up) (
                LXtObjectID              self,
                LXtObjectID              vts,
                LXtObjectID              adjust);
                LXxMETHOD( const char *,
        Haul) (
                LXtObjectID              self,
                unsigned int             index);
                LXxMETHOD( const char *,
        Help) (
                LXtObjectID              self,
                LXtObjectID              vts);
                LXxMETHOD( LxResult,
        Enable) (
                LXtObjectID              self,
                LXtObjectID              msg);
                LXxMETHOD( LxResult,
        Drop) (
                LXtObjectID              self);
} ILxToolModel;
typedef struct vt_ILxAdjustTool {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        Value) (
                LXtObjectID              self,
                unsigned int             index,
                LXtObjectID              val);

                LXxMETHOD( void,
        SetInt) (
                LXtObjectID              self,
                unsigned int             index,
                int                      val);

                LXxMETHOD( void,
        SetFlt) (
                LXtObjectID              self,
                unsigned int             index,
                double                   val);

                LXxMETHOD( void,
        SetString) (
                LXtObjectID              self,
                unsigned int             index,
                const char              *val);
                LXxMETHOD( void,
        Lock) (
                LXtObjectID              self);

                LXxMETHOD( void,
        Invalidate) (
                LXtObjectID              self);

                LXxMETHOD( void,
        Update) (
                LXtObjectID              self);
} ILxAdjustTool;

#define LXu_VIEWITEM3D          "9BCE73B5-3264-48BB-B129-15FF53FD1661"
#define LXa_VIEWITEM3D          "viewitem3d"
//[local]  ILxViewItem3D
//[export] ILxViewItem3D vitm
#define LXiSELECTION_UNSELECTED         0
#define LXiSELECTION_SELECTED           1
#define LXiSELECTION_ROLLOVER           2

#define LXiMOTION_1D                    1
#define LXiMOTION_ANGULAR               2
#define LXiMOTION_RADIAL                3
#define LXu_TOOLMODEL   "EECE6570-AD5F-4190-AFA7-15067500454F"
// [local]   ILxToolModel
// [export]  ILxToolModel tmod
// [default] ILxToolModel:Flags = LXfTMOD_DRAW_3D
// [default] ILxToolModel:Help  = 0
// [default] ILxToolModel:Haul  = 0
#define LXfTMOD_MODELSPACE       0x00004
#define LXfTMOD_DRAW_3D          0x00010
#define LXfTMOD_DRAW_PIXEL       0x00020
#define NEW_TOOL_INPUT
#ifdef NEW_TOOL_INPUT
        #define LXfTMOD_I0_INPUT         0x00040
        #define LXfTMOD_I0_ATTRHAUL      0x00080
        #define LXfTMOD_I1_INPUT         0x00100
        #define LXfTMOD_I1_ATTRHAUL      0x00200
        #define LXfTMOD_I_CURVE          0x00400
        #define LXfTMOD_I_BRUSH          0x00800
        #define LXfTMOD_I_GENERAL        0x01000
#else
        #define LXfTMOD_I0_INPUT         0x00040
        #define LXfTMOD_I0_ATTRHAUL      0x00080
        #define LXfTMOD_I1_INPUT         0x00100
        #define LXfTMOD_I1_ATTRHAUL      0x00200
        #define LXfTMOD_I_CURVE          0x00400
        #define LXfTMOD_I_BRUSH          0x00800
#endif
#ifdef NEW_TOOL_INPUT
        #define LXfTMOD_BRUSHRESET       0x02000
        #define LXfTMOD_INITAGAIN        0x04000
        #define LXfTMOD_NEEDSHAUL        0x08000
        #define LXfTMOD_ROLLOVERS        0x10000
        #define LXfTMOD_AUTORESET        0x20000
        #define LXfTMOD_HANDLERESET      0x40000
#else
        #define LXfTMOD_BRUSHRESET       0x01000
        #define LXfTMOD_INITAGAIN        0x02000
        #define LXfTMOD_NEEDSHAUL        0x04000
        #define LXfTMOD_ROLLOVERS        0x08000
        #define LXfTMOD_AUTORESET        0x10000
        #define LXfTMOD_HANDLERESET      0x20000
#endif
        #define LXfTMOD_I0_NOSELECT      0x40000
        #define LXfTMOD_I1_NOSELECT      0x80000
#define LXu_ADJUSTTOOL  "26E85301-8165-4FF3-AF26-392A03C9E1E7"
// [local]  ILxAdjustTool

 #ifdef __cplusplus
  }
 #endif
#endif

