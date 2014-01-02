/*
 * LX handles module
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
#ifndef LX_handles_H
#define LX_handles_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxShapeDraw ** ILxShapeDrawID;
typedef struct vt_ILxHandleDraw ** ILxHandleDrawID;
typedef struct vt_ILxEventTranslatePacket ** ILxEventTranslatePacketID;
typedef struct vt_ILxEventGuide ** ILxEventGuideID;
typedef struct vt_ILxGeoConstraintPacket ** ILxGeoConstraintPacketID;
#include <lxcom.h>
#include <lxresult.h>
#include <lxvalue.h>
#include <lxvector.h>
#include <lxidef.h>
#include <lximage.h>



typedef struct vt_ILxShapeDraw {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        Circle) (
                LXtObjectID              self,
                const LXtVector          col,
                double                   alpha,
                const LXtVector          pos,
                double                   rad,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        Ellipse) (
                LXtObjectID              self,
                const LXtVector          col,
                double                   alpha,
                const LXtVector          pos,
                const LXtVector          rad,
                int                      axis,
                int                      flags);        

                LXxMETHOD( void,
        Pill) (
                LXtObjectID              self,
                const LXtVector          col,
                double                   alpha,
                const LXtVector          pos,
                double                   width,
                double                   height,
                double                   rad,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        Bone) (
                LXtObjectID              self,
                const LXtVector          col,
                double                   rlen,
                int                      active);

                LXxMETHOD( void,
        Arc) (
                LXtObjectID              self,
                const LXtVector          col,
                double                   alpha,
                const LXtVector          pos,
                double                   rad,
                double                   start,
                double                   end,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        Plane) (
                LXtObjectID              self,
                const LXtVector          col,
                const LXtVector          pos,
                const LXtVector          size,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        Ellipsoid) (
                LXtObjectID              self,
                const LXtVector          col,
                double                   alpha,
                const LXtVector          pos,
                const LXtVector          rad,
                int                      flags);

                LXxMETHOD( void,
        Cube) (
                LXtObjectID              self,
                const LXtVector          col,
                const LXtVector          pos,
                const LXtVector          size,
                int                      flags);

                LXxMETHOD( void,
        CubeFill) (
                LXtObjectID              self,
                const LXtVector          col,
                double                   alpha,
                const LXtVector          pos,
                const LXtVector          size,
                int                      flags);

                LXxMETHOD( void,
        BoxShape) (
                LXtObjectID              self,
                const LXtVector          colW,
                const LXtVector          colF,
                const LXtVector          pos,
                const LXtVector          size,
                int                      flags);

                LXxMETHOD( void,
        Pyramid) (
                LXtObjectID              self,
                const LXtVector          col,
                const LXtVector          pos,
                const LXtVector          size,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        PyramidShape) (
                LXtObjectID              self,
                const LXtVector          colW,
                const LXtVector          colF,
                const LXtVector          pos,
                const LXtVector          size,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        Rhombus) (
                LXtObjectID              self,
                const LXtVector          col,
                const LXtVector          pos,
                const LXtVector          size,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        RhombusShape) (
                LXtObjectID              self,
                const LXtVector          colW,
                const LXtVector          colF,
                const LXtVector          pos,
                const LXtVector          size,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        Cone) (
                LXtObjectID              self,
                const LXtVector          col,
                const LXtVector          pos,
                double                   rad,
                double                   height,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        ConeShape) (
                LXtObjectID              self,
                const LXtVector          colW,
                const LXtVector          colF,
                const LXtVector          pos,
                double                   radius,
                double                   height,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        Cylinder) (
                LXtObjectID              self,
                const LXtVector          col,
                const LXtVector          pos,
                double                   rad,
                double                   height,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        CylinderShape) (
                LXtObjectID              self,
                const LXtVector          colW,
                const LXtVector          colF,
                const LXtVector          pos,
                double                   radius,
                double                   height,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        SphereShape) (
                LXtObjectID              self,
                const LXtVector          colW,
                const LXtVector          colF,
                const LXtVector          pos,
                double                   radius,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        CircleShape) (
                LXtObjectID              self,
                const LXtVector          colW,
                const LXtVector          colF,
                const LXtVector          pos,
                double                   radius,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        PlaneShape) (
                LXtObjectID              self,
                const LXtVector          colW,
                const LXtVector          colF,
                const LXtVector          pos,
                const LXtVector          size,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        RadialMap) (
                LXtObjectID              self,
                LXtObjectID              image,
                const LXtVector          col,
                const LXtVector          cen,
                double                   size,
                int                      sel,
                int                      flags);

                LXxMETHOD( void,
        RadialRays) (
                LXtObjectID              self,
                LXtObjectID              image,
                const LXtVector          col,
                const LXtVector          cen,
                double                   size,
                int                      sel,
                int                      flags);

                LXxMETHOD( void,
        Link) (
                LXtObjectID              self,
                const LXtVector          col,
                const LXtVector          posS,
                const LXtVector          posE,
                int                      solid,
                int                      flags);

                LXxMETHOD( void,
        BBox) (
                LXtObjectID              self,
                const LXtVector          col,
                double                   size,
                int                      flags);

                LXxMETHOD( void,
        Arrow) (
                LXtObjectID              self,
                const LXtVector          col,
                const LXtVector          pos,
                double                   size,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        Axis) (
                LXtObjectID              self,
                const LXtVector          col,
                const LXtVector          pos,
                const LXtVector          size,
                int                      flags);

                LXxMETHOD( void,
        Star) (
                LXtObjectID              self,
                const LXtVector          col,
                const LXtVector          pos,
                const LXtVector          rad,
                int                      flags);

                LXxMETHOD( void,
        Cross) (
                LXtObjectID              self,
                const LXtVector          col,
                const LXtVector          pos,
                const LXtVector          rad,
                int                      flags);

                LXxMETHOD( void,
        Line) (
                LXtObjectID              self,
                const LXtVector          v0,
                const LXtVector          v1,
                const LXtVector          col,
                double                   alpha,
                int                      flags);

                LXxMETHOD( void,
        CSeg) (
                LXtObjectID              self,
                const LXtVector          cen,
                const LXtVector          offset,
                double                   screen,
                const LXtVector          col,
                int                      flags);

                LXxMETHOD( void,
        PlaneIndicator) (
                LXtObjectID              self,
                const LXtVector          col,
                double                   alpha,
                const LXtVector          pos,
                double                   rad,
                int                      axis,
                int                      flags);

                LXxMETHOD( void,
        CrossHair) (
                LXtObjectID              self,
                const LXtVector          col,
                double                   alpha,
                const LXtVector          pos,
                int                      flags);

                LXxMETHOD( void,
        PreciseHandle) (
                LXtObjectID              self,
                const LXtVector          col,
                double                   alpha,
                const LXtVector          pos,
                const LXtVector          size,
                int                      flags);
} ILxShapeDraw;
typedef struct vt_ILxHandleDraw {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        Handle) (
                LXtObjectID              self,
                const LXtVector          pos,
                const LXtMatrix          mat,
                int                      part,
                int                      flags);

                LXxMETHOD( void,
        AxisHandle) (
                LXtObjectID              self,
                const LXtVector          pos,
                const LXtMatrix          mat,
                int                      axis,
                int                      part,
                double                   len,
                int                      flags);

                LXxMETHOD( void,
        MoveHandle) (
                LXtObjectID              self,
                const LXtVector          pos,
                const LXtMatrix          mat,
                int                      axis,
                int                      part,
                int                      flags);

                LXxMETHOD( void,
        RotateHandle) (
                LXtObjectID              self,
                const LXtVector          pos,
                const LXtMatrix          mat,
                int                      axis,
                int                      part,
                double                   sAngle,
                double                   eAngle,
                int                      facing,
                int                      flags);

                LXxMETHOD( void,
        RotateMouseHandle) (
                LXtObjectID              self,
                const LXtVector          center,
                const LXtVector          pos,
                const LXtMatrix          mat,
                int                      axis,
                int                      part,
                int                      flags);

                LXxMETHOD( void,
        ScaleHandle) (
                LXtObjectID              self,
                const LXtVector          pos,
                const LXtMatrix          mat,
                int                      axis,
                int                      part,
                double                   offset,
                int                      line,
                int                      flags);

                LXxMETHOD( void,
        CrossHandle) (
                LXtObjectID              self,
                const LXtVector          pos,
                const LXtMatrix          mat,
                int                      part,
                int                      flags);

                LXxMETHOD( void,
        PointHandle) (
                LXtObjectID              self,
                const LXtVector          pos,
                int                      part,
                int                      flags);

                LXxMETHOD( void,
        XHandle) (
                LXtObjectID              self,
                const LXtVector          pos,
                const LXtMatrix          mat,
                int                      part,
                int                      flags);

                LXxMETHOD( void,
        PlaneHandle) (
                LXtObjectID              self,
                const LXtVector          pos,
                const LXtMatrix          mat,
                int                      axis,
                int                      part,
                int                      flags);
} ILxHandleDraw;
typedef struct vt_ILxEventTranslatePacket {
        ILxUnknown       iunk;
                LXxMETHOD(  int,
        ToModel) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                LXtVector                pos,
                LXtVector                axis);

                LXxMETHOD(  void,
        ToModelLine) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                LXtVector                center,
                LXtVector                dir,
                LXtVector                pos);

                LXxMETHOD(  void,
        ToModelPlane) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                LXtVector                center,
                LXtVector                normal,
                LXtVector                pos);

                LXxMETHOD(  void,
        ModelDelta) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                LXtVector                handle,
                LXtVector                delta);

                LXxMETHOD(  void,
        ModelLineDelta) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                LXtVector                center,
                LXtVector                dir,
                LXtVector                handle,
                LXtVector                delta);

                LXxMETHOD(  void,
        ModelPlaneDelta) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                LXtVector                center,
                LXtVector                normal,
                LXtVector                handle,
                LXtVector                delta);

                LXxMETHOD(  void,
        HitHandle) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                LXtVector                handle);

                LXxMETHOD(  void,
        GetNewPosition) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                LXtVector                pos);
                LXxMETHOD(  void,
        SetLinearConstraint) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                LXtVector                center,
                LXtVector                dir);

                LXxMETHOD(  void,
        SetPlanarConstraint) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                LXtVector                center,
                LXtVector                normal);

                LXxMETHOD(  int,
        GetConstraint) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                LXtVector                center,
                LXtVector                vector);

                LXxMETHOD(  void,
        SetSnapRange) (
                LXtObjectID              self,
                double                   inner,
                double                   outer);
                LXxMETHOD(  void,
        ScreenToRay) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                float                    x,
                float                    y,
                LXtVector                pos,
                LXtVector                dir);
            LXxMETHOD(  void,
        AddGuide) (
                LXtObjectID              self,
                LXtObjectID              guide,
                void                    *client);

            LXxMETHOD(  int,
        RemoveGuide) (
                LXtObjectID              self,
                LXtObjectID              guide,
                void                    *client);
} ILxEventTranslatePacket;
typedef struct vt_ILxEventGuide {
        ILxUnknown       iunk;
                LXxMETHOD(  int,
        Limits) (
                LXtObjectID              self,
                double                   inner,
                double                   outer);

                LXxMETHOD(  int,
        Proximity) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                LXtVector                pos,
                double                  *dist,
                int                     *priority,
                void                    *element);

                LXxMETHOD(  int,
        SetDrawState) (
                LXtObjectID              self,
                int                      flags);

                LXxMETHOD(  void,
        SetFlags) (
                LXtObjectID              self,
                int                      flags);

                LXxMETHOD(  int,
        Flags) (
                LXtObjectID              self);
} ILxEventGuide;
typedef struct vt_ILxGeoConstraintPacket {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        PointConstrain) (
                LXtObjectID              self,
                LXtVector                pos,
                LXtVector                delta);
                LXxMETHOD( LxResult,
        VectorConstrain) (
                LXtObjectID              self,
                LXtVector                pos,
                LXtVector                delta);
                LXxMETHOD( int,
        Flags) (
                LXtObjectID              self);
                LXxMETHOD( void,
        ModeMaskSet) (
                LXtObjectID              self,
                int                      mask);
} ILxGeoConstraintPacket;

#define LXfVDRAW_MASK            (0xFF<<24)
#define LXfVDRAW_FILL            (1<<31)
#define LXfVDRAW_DASH            (1<<30)
#define LXfVDRAW_CUSTOM0         (1<<24)
#define LXfVDRAW_CUSTOM1         (1<<25)
#define LXfVDRAW_CUSTOM2         (1<<26)
#define LXfVDRAW_CUSTOM3         (1<<23)
#define LXfVDRAW_AXARROW         LXfVDRAW_CUSTOM0
#define LXu_SHAPEDRAW           "DC46A7E2-2849-46CE-9075-2394E04EB3AE"
// [local]  ILxShapeDraw
#define LXi_THANDf_SMALL        (1<<16)
#define LXi_THANDf_HOT          (1<<17)
#define LXi_THANDf_HIT          (1<<18)
#define LXi_THANDf_CONST        (1<<19)
#define LXi_THANDf_GHOST        (1<<20)
#define LXi_THANDf_FLIP         (1<<21)
#define LXi_THANDf_DISABLE      (1<<22)

#define LXi_THANDf_AXES         (3<<24)
#define LXi_THANDf_AXIS_X       (1<<24)
#define LXi_THANDf_AXIS_Y       (2<<24)
#define LXi_THANDf_AXIS_Z       (3<<24)
#define LXi_THANDv_AXIS(f)      ((((f) & LXi_THANDf_AXES) >> 24) - 1)

#define LXi_THANDv_MASK         (0xFFFF)
#define LXu_HANDLEDRAW          "EEC6665A-BB44-48A4-8F8C-B4BCDF2ED880"
// [local] ILxHandleDraw
#define LXi_EVTRAN_CONSTRAIN_NONE       0
#define LXi_EVTRAN_CONSTRAIN_LINE       1
#define LXi_EVTRAN_CONSTRAIN_PLANE      2
#define LXf_EVTRAN_SNAPS                0
#define LXf_EVTRAN_NOSNAP               1
#define LXf_EVTRAN_NOQUANT              2
#define LXf_EVTRAN_NOCONST              4
#define LXf_EVTRAN_UNSNAPPED            (LXf_EVTRAN_NOSNAP|LXf_EVTRAN_NOQUANT|LXf_EVTRAN_NOCONST)
#define LXf_GUIDE_LINE          1
#define LXf_GUIDE_PLANE         2
#define LXf_GUIDE_POINT         (LXf_GUIDE_PLANE | LXf_GUIDE_LINE)
#define LXf_GUIDE_SNAP          LXf_GUIDE_POINT
#define LXf_GUIDE_SNAP_NONE     0
#define LXf_GUIDE_SNAP_AXIS_X   1 //  (1<<0)
#define LXf_GUIDE_SNAP_AXIS_Y   2 //  (1<<1)
#define LXf_GUIDE_SNAP_AXIS_Z   4 //  (1<<2)
#define LXf_GUIDE_SNAP_ALLAXES  7 //  (LXf_GUIDE_AXIS_X | LXf_GUIDE_AXIS_Y | LXf_GUIDE_AXIS_Z)
#define LXi_GUIDE_OFF           0
#define LXi_GUIDE_SUGGEST       1
#define LXi_GUIDE_CHOSEN        2
#define LXi_GUIDE_FLAGS_NONE    0x00
#define LXi_GUIDE_FLAGS_ALWAYS  0x01
#define LXu_EVENTTRANSLATEPACKET        "81B7CACE-DB90-4AD7-AE93-42C23E62130D"
#define LXu_EVENTGUIDE                  "B2A11425-25DE-4628-839C-995020BD8DF1"
#define LXsP_TOOL_EVENTTRANS            "toolEventTranslate"
// [local] ILxEventTranslatePacket
// [local] ILxEventGuide
#define LXf_GEOCONS_POINT               0x01
#define LXf_GEOCONS_VECTOR              0x02
#define LXu_GEOCONSTRAINTPACKET         "0589BA62-5A11-453d-B84A-1C7CF30A0D35"

 #ifdef __cplusplus
  }
 #endif
#endif

