/*
 * LX draw module
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
#ifndef LX_draw_H
#define LX_draw_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxView ** ILxViewID;
typedef struct vt_ILxStrokeDraw ** ILxStrokeDrawID;
#include <lxcom.h>
#include <lxvmath.h>



typedef struct vt_ILxView {
        ILxUnknown       iunk;
                LXxMETHOD( int,
        Type) (
                LXtObjectID              self);

                LXxMETHOD( void,
        Center) (
                LXtObjectID              self,
                LXtVector                center);

                LXxMETHOD( double,
        Scale) (
                LXtObjectID              self);

                LXxMETHOD( double,
        PixelScale) (
                LXtObjectID              self);

                LXxMETHOD( double,
        Aspect) (
                LXtObjectID              self);

                LXxMETHOD( void,
        Matrix) (
                LXtObjectID              self,
                LXtMatrix                xfrm);

                LXxMETHOD( void,
        InvMatrix) (
                LXtObjectID              self,
                LXtMatrix                xfrm);

                LXxMETHOD( void,
        Ortho) (
                LXtObjectID              self,
                int                     *index,
                int                     *spin);

                LXxMETHOD( int,
        Axis) (
                LXtObjectID              self);

                LXxMETHOD( double,
        Zoom) (
                LXtObjectID              self);

                LXxMETHOD( void,
        Focal) (
                LXtObjectID              self,
                double                  *flen,
                double                  *fdist);

                LXxMETHOD( int,
        ToScreen) (
                LXtObjectID              self,
                const LXtVector          pos,
                double                  *x,
                double                  *y);

                LXxMETHOD( int,
        ToScreen3) (
                LXtObjectID              self,
                const LXtVector          pos,
                LXtVector                vp);

                LXxMETHOD( void,
        ToModel) (
                LXtObjectID              self,
                int                      x,
                int                      y,
                LXtVector                pos,
                int                      snap);

                LXxMETHOD( void,
        ScreenNormals) (
                LXtObjectID              self,
                const LXtVector          pos,
                LXtVector                ax,
                LXtVector                ay,
                LXtVector                az);

                LXxMETHOD( double,
        EyeVector) (
                LXtObjectID              self,
                const LXtVector          pos,
                LXtVector                eye);

                LXxMETHOD( void,
        Dimensions) (
                LXtObjectID              self,
                int                     *w,
                int                     *h);

                LXxMETHOD( int,
        WorkPlane) (
                LXtObjectID              self,
                LXtVector                center);       
} ILxView;
typedef struct vt_ILxStrokeDraw {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        Begin) (
                LXtObjectID              self,
                int                      type,
                LXtVector                color,
                double                   alpha);

                LXxMETHOD( void,
        BeginW) (
                LXtObjectID              self,
                int                      type,
                LXtVector                color,
                double                   alpha,
                double                   width);

                LXxMETHOD( void,
        BeginWD) (
                LXtObjectID              self,
                int                      type,
                LXtVector                color,
                double                   alpha,
                double                   width,
                int                      dashPattern);

                LXxMETHOD( void,
        Vertex) (
                LXtObjectID              self,
                LXtVector                pos,
                int                      flags);

                LXxMETHOD( void,
        Vertex3) (
                LXtObjectID              self,
                double                   x,
                double                   y,
                double                   z,
                int                      flags);        

                LXxMETHOD( void,
        TextureUV) (
                LXtObjectID              self,
                double                   u,
                double                   v);

                LXxMETHOD( void,
        Text) (
                LXtObjectID              self,
                const char              *text,
                int                      just);

                LXxMETHOD( void,
        PushTransform) (
                LXtObjectID              self,
                const LXtVector          v,
                const LXtMatrix          m);

                LXxMETHOD( void,
        PopTransform) (
                LXtObjectID              self);

                LXxMETHOD( void,
        SetPart) (
                LXtObjectID              self,
                int                      part);

                LXxMETHOD( void,
        BeginPoints) (
                LXtObjectID              self,
                double                   size,
                LXtVector                color,
                double                   alpha);
} ILxStrokeDraw;

#define LXiVIEWv_PIXEL           0x000
#define LXiVIEWv_SCREEN          0x001
#define LXiVIEWv_ORTHOGONAL      0x002
#define LXiVIEWv_PERSPECTIVE     0x003
#define LXiVIEWv_CAMERA          0x004
#define LXiVIEWv_GRAPH           0x005
#define LXiVIEWv_MASTER          0x006
#define LXiVIEWf_ABSOLUTE        0x100
#define LXiORTHOv_TOP            0
#define LXiORTHOv_BOTTOM         1
#define LXiORTHOv_BACK           2
#define LXiORTHOv_FRONT          3
#define LXiORTHOv_RIGHT          4
#define LXiORTHOv_LEFT           5
#define LXu_VIEW                "7D171FD2-20D5-438C-8664-AECC2F828B76"
// [local]  ILxView
#define LXu_STROKEDRAW  "DA71480A-95AA-11D9-936D-000A956C2E10"
//[local] ILxStrokeDraw
#define LXiSTROKE_NONE                  0
#define LXiSTROKE_POINTS                1
#define LXiSTROKE_LINES                 2
#define LXiSTROKE_LINE_STRIP            3
#define LXiSTROKE_LINE_LOOP             4
#define LXiSTROKE_TRIANGLES             5
#define LXiSTROKE_QUADS                 6
#define LXiSTROKE_BEZIERS               7
#define LXiSTROKE_ARCS                  8
#define LXiSTROKE_CIRCLES               9
#define LXiSTROKE_BOXES                 10
#define LXiSTROKE_FRONT_BOXES           11
#define LXiSTROKE_TEXT                  12
#define LXiSTROKE_FRONT_LINE_LOOP       13

#define LXiSTROKE_ABSOLUTE              0
#define LXiSTROKE_RELATIVE              1
#define LXiSTROKE_SCREEN                2
#define LXiSTROKE_REL_SCREEN            (LXiSTROKE_RELATIVE | LXiSTROKE_SCREEN)

#define LXiHITPART_INVIS                -2000000000

#define LXiTEXT_LEFT                     0
#define LXiTEXT_CENTER                   1
#define LXiTEXT_RIGHT                    2

#define LXiLPAT_DOTS                     0xAAAA 
#define LXiLPAT_DOTSLONG                 0x2222 
#define LXiLPAT_DASH                     0x3333 
#define LXiLPAT_DASHLONG                 0xF0F0 
#define LXiLPAT_DASHXLONG                0xE007 
#define LXiLPAT_DOTDASH                  0xE083 

 #ifdef __cplusplus
  }
 #endif
#endif

