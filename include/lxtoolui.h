/*
 * LX toolui module
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
#ifndef LX_toolui_H
#define LX_toolui_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxRaycastPacket ** ILxRaycastPacketID;
typedef struct vt_ILxPaintBrushPacket ** ILxPaintBrushPacketID;
typedef struct vt_ILxPaintInkPacket ** ILxPaintInkPacketID;
typedef struct vt_ILxPaintNozzlePacket ** ILxPaintNozzlePacketID;
#include <lxcom.h>
#include <lxresult.h>
#include <lxvalue.h>
#include <lxvector.h>
#include <lximage.h>


typedef struct st_LXpToolViewEvent {
        struct st_Viewport      *vport;
        struct st_AGLView       *view;
        unsigned                 flags;
        unsigned                 type;
} LXpToolViewEvent;
typedef struct st_LXpTool3DEvent {
        LXtVector                v0, dv;
        LXtVector                rv0, rdv;
} LXpTool3DEvent;
typedef struct st_LXpToolScreenEvent {
        int              px, py;
        int              cx, cy;
        float            fpx, fpy;
        float            fcx, fcy;
} LXpToolScreenEvent;
typedef struct st_LXpToolInputEvent {
        int              mode;
        int              input;
        int              count;
        int              part;
        int              type;
        int              haul;
} LXpToolInputEvent;
typedef struct st_LXpToolTabletEvent {
        int                      exists;
        int                      inUse;

        double                   normal;
        double                   tangent;
        double                   tilt[2];
        double                   twist;
} LXpToolTabletEvent;
typedef struct st_LXpToolColor {
        float            fg[4];
        float            bg[4]; 
} LXpToolColor;
typedef struct st_LXtHitPolygon {
        LXtPolID                 pol;
        LXtVector                pos;
        LXtVector                nrm;
        float                    uv[2];
        float                    cosine;
        float                    disp;
        void                    *surf;
        void                    *mbin;
} LXtHitPolygon;
typedef struct st_LXtHitEdge {
        LXtOldEdgeID             edge;
        LXtVector                pos;
        float                    t;
} LXtHitEdge;
typedef struct st_LXtHitVertex {
        LXtPntID                 vrt;
        LXtVector                pos;
} LXtHitVertex;
typedef struct st_LXpToolHitEvent {
        LXtHitPolygon            hit;
        float                    dist;
} LXpToolHitEvent;
typedef struct st_LXtHitItem {
        LXtObjectID              item;
        LXtVector                pos;
        LXtVector                nrm;
        int                      isMesh;
} LXtHitItem;
typedef struct st_LXpToolPaintTarget {
        ILxImageID               image;
        int                      projMode, projWidth, projHeight;
        int                      xc, yc;
        int                      xp, yp;
        float                    fxp, fyp;
} LXpToolPaintTarget;
typedef struct st_LXpToolPaintStroke {
        float            start[2], end[2];
        float            length;
        float            total;
        float            current;
        int              align;
} LXpToolPaintStroke;
typedef struct st_LXtPaintBrush {
        int              width, height;
        float           *wgt;
        float           *rgb;
        float            rotation;
        int              mode;
        int              flags;
} LXtPaintBrush;
typedef struct st_LXpToolProfile {
        LXtObjectID              xobj;
        int                      dimension;
} LXpToolProfile;
typedef struct st_LXpToolImage {
        char                    *path;
        int                      flags;
} LXpToolImage;
typedef struct st_LXpToolSnapElement {
        LXtMeshID                mesh;
        LXtVMapID                vmap;
        LXtID4                   type;
        LXtPolID                 pol;
        LXtPntID                 vrt0, vrt1;
        LXtVector                pos;
        double                   cx, cy;
        double                   dist;
        struct st_AGLView       *view;
} LXpToolSnapElement;
typedef struct vt_ILxRaycastPacket {
        ILxUnknown       iunk;
                LXxMETHOD(  int,
        HitPolygon) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                float                    x,
                float                    y,
                LXtHitPolygon           *hit);

                LXxMETHOD(  int,
        HitEdge) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                float                    x,
                float                    y,
                LXtHitEdge              *hit);

                LXxMETHOD(  int,
        HitVertex) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                float                    x,
                float                    y,
                LXtHitVertex            *hit);

                LXxMETHOD(  int,
        HitItem) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                float                    x,
                float                    y,
                LXtHitItem              *hit);
} ILxRaycastPacket;
typedef struct vt_ILxPaintBrushPacket {
        ILxUnknown       iunk;
                LXxMETHOD(  int,
        Flags) (
                LXtObjectID              self);

                LXxMETHOD(  float,
        Size) (
                LXtObjectID              self);

                LXxMETHOD(  int,
        BBox) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                const LXtVector          center,
                double                   size,
                LXtBBox                 *bbox);

                LXxMETHOD(  int,
        Eval2D) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                float                    multiplier,
                LXtPaintBrush           *brush);

                LXxMETHOD(  double,
        Eval3D) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                const LXtVector          center,
                const LXtVector          wpos,
                const LXtVector          bpos,
                double                   rad,
                float                   *rgba);
} ILxPaintBrushPacket;
typedef struct vt_ILxPaintInkPacket {
        ILxUnknown       iunk;
                LXxMETHOD(  int,
        Flags) (
                LXtObjectID              self,
                LXtObjectID              toolVector);

                LXxMETHOD(  int,
        Color) (
                LXtObjectID              self,
                LXtObjectID              toolVector,
                int                      flags,
                LXtColorRGBA             rgba);

                LXxMETHOD(  int,
        Stamp) (
                LXtObjectID      self,
                LXtPaintBrush   *brush);
} ILxPaintInkPacket;
typedef struct vt_ILxPaintNozzlePacket {
        ILxUnknown       iunk;
                LXxMETHOD(  int,
        Paint) (
                LXtObjectID      self,
                LXtObjectID              toolVector,
                float            brushSize);

                LXxMETHOD(  int,
        Jitter) (
                LXtObjectID      self,
                LXtObjectID              toolVector,
                float            brushSize,
                int                     *xj,
                int                     *yj);

                LXxMETHOD(  int,
        Nozzle) (
                LXtObjectID      self,
                LXtObjectID              toolVector,
                float           *strength,
                float           *size,
                float           *rotation);
} ILxPaintNozzlePacket;

#define LXsP_TOOL_VIEW_EVENT    "ToolViewEvent"
#define LXi_VIEWTYPE_3D         0
#define LXi_VIEWTYPE_UV         1
#define LXsP_TOOL_3D_EVENT      "Tool3DEvent"
#define LXsP_TOOL_SCREEN_EVENT  "ToolScreenEvent"
#define LXiTIE_TYPE_NONE        0
#define LXiTIE_TYPE_DOWN        1
#define LXiTIE_TYPE_MOVE        2
#define LXiTIE_TYPE_UP  3
#define LXiTIE_INPUT_I0                 0
#define LXiTIE_INPUT_I1                 1

#define LXiTIE_CURVE_EDIT               2
#define LXiTIE_CURVE_ADD                3
#define LXiTIE_CURVE_DELETE             4
#define LXiTIE_CURVE_DELETE_ALL         5
#define LXiTIE_CURVE_MOVE               6
#define LXiTIE_CURVE_MOVE_ALL           7
#define LXiTIE_CURVE_MOVE_CONS          8
#define LXiTIE_CURVE_MOVE_CONS_ALL      9
#define LXiTIE_CURVE_SCALE              10
#define LXiTIE_CURVE_SCALE_ALL          11
#define LXiTIE_CURVE_ALT                12

#define LXiTIE_GENERAL_PRI              20
#define LXiTIE_GENERAL_SEC              21
#define LXiTIE_GENERAL_TER              22
#define LXiTIE_GENERAL_PRI_ALT          23
#define LXiTIE_GENERAL_SEC_ALT          24
#define LXiTIE_GENERAL_TER_ALT          25
#define LXiTIE_GENERAL_PRI_CONS         26
#define LXiTIE_GENERAL_SEC_CONS         27
#define LXiTIE_GENERAL_TER_CONS         28
#define LXiTIE_GENERAL_CLICK_1          29
#define LXiTIE_GENERAL_CLICK_2          30      
#define LXsP_TOOL_INPUT_EVENT   "ToolInputEvent"
#define LXsP_TOOL_TABLET_EVENT  "ToolTabletEvent"
#define LXsP_TOOL_COLOR         "ToolColor"
#define LXu_RAYCASTPACKET               "D622B573-2638-4A47-AD91-6BC7A6D2D30B"
#define LXa_RAYCASTPACKET               "RaycastPacket"
// [local]  ILxRaycastPacket
#define LXsP_TOOL_RAYCAST               "ToolRaycast"
#define LXsP_TOOL_HIT_EVENT     "ToolHitEvent"
typedef ILxVectorList           ILxStrokePacket;
typedef ILxVectorListID         ILxStrokePacketID;
#define LXsP_TOOL_STROKE_EVENT  "ToolStrokeEvent"
#define LXsP_TOOL_PAINT_TARGET  "ToolPaintTarget"
#define LXsP_TOOL_PAINT_STROKE  "ToolPaintStroke"
#define LXfPAINTBRUSH_2D                0x01
#define LXfPAINTBRUSH_3D                0x02
#define LXfPAINTBRUSH_3D_RGBA           0x04
#define LXiPAINTMODE_SET        0
#define LXiPAINTMODE_ADD        1
#define LXiPAINTMODE_MAX        2
#define LXfPAINTSTEP_BUMP       0x01
#define LXfPAINT_ROLLER         0x02
#define LXfPAINT_STAMP          0x04
#define LXu_PAINTBRUSHPACKET            "9283C21E-77FC-402D-B22A-7B26285888C4"
#define LXa_PAINTBRUSHPACKET            "PaintBrushPacket"
// [local]  ILxPaintBrushPacket
#define LXsP_TOOL_PAINT_BRUSH           "ToolPaintBrush"
#define LXf_PAINT_INK_PERPIXEL          0x01
#define LXf_PAINT_INK_3D                0x02
#define LXf_PAINT_INK_STAMP             0x04
#define LXu_PAINTINKPACKET              "340EE412-232D-4619-974D-7E59C7B39353"
#define LXa_PAINTINKPACKET              "PaintInkPacket"
// [local]  ILxPaintInkPacket
#define LXsP_TOOL_PAINT_INK             "ToolPaintInk"
#define LXu_PAINTNOZZLEPACKET           "F0BB49ED-0BBB-448a-8339-F69F78E95048"
#define LXa_PAINTNOZZLEPACKET           "PaintNozzlePacket"
// [local]  ILxPaintNozzlePacket
#define LXsP_TOOL_PAINT_NOZZLE          "ToolPaintNozzle"
#define LXsP_TOOL_PROFILE       "toolProfile"
#define LXsP_TOOL_IMAGE         "toolImage"
#define LXsP_TOOL_SNAPELEMENT   "toolSnapElement"

 #ifdef __cplusplus
  }
 #endif
#endif

