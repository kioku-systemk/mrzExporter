/*
 * LX mesh module
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
#ifndef LX_mesh_H
#define LX_mesh_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxMeshOLD ** ILxMeshOLDID;
typedef struct vt_ILxMeshOLDEdit ** ILxMeshOLDEditID;
#include <lxcom.h>
#include <lxvmath.h>

typedef void *           LXtPntID;
typedef void *           LXtPolID;
typedef void *           LXtOldEdgeID;
typedef void *           LXtVMapID;
typedef struct st_Mesh *        LXtMeshID;
typedef struct st_LXtMeshPointInfo {
        LXtPntID                 id;
        const LXtPolID          *polys;
        int                      npoly;
        float                    pos[3];
} LXtMeshPointInfo;
typedef struct st_LXtMeshPolyInfo {
        LXtPolID                 id;
        const char              *type;
        LXtPntID                *vlist;
        int                      nvert;
        int                      flags;

} LXtMeshPolyInfo;
typedef struct st_LXtMeshVMapInfo {
        LXtVMapID                id;
        int                      type;
        const char              *name;
        int                      dimension;
} LXtMeshVMapInfo;
typedef struct st_LXtMeshEdgeInfo {
        LXtOldEdgeID             id;
        LXtPntID                 A;
        LXtPntID                 B;
        int                      idxA;
        int                      idxB;
        const LXtPolID          *polys;
        int                      npoly;
} LXtMeshEdgeInfo;
typedef struct vt_ILxMeshOLD {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        GetBoundingBox) (
                LXtObjectID              self,
                LXtBBox                 *bbox);

                LXxMETHOD(  int,
        NumPoints) (
                LXtObjectID              self);

                LXxMETHOD(  int,
        NumPolys) (
                LXtObjectID              self);

                LXxMETHOD(  int,
        NumEdges) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        GetEdge) (
                LXtObjectID              self,
                unsigned int             index,
                LXtMeshEdgeInfo         *info);

                LXxMETHOD(  LxResult,
        IterateEdge) (
                LXtObjectID              self,
                LXtMeshEdgeInfo         *info);

                LXxMETHOD(  LxResult,
        GetEdgeLength) (
                LXtObjectID              self,
                LXtOldEdgeID             e,
                double                  *val);

                LXxMETHOD(  LxResult,
        GetEdgeCenter) (
                LXtObjectID              self,
                LXtOldEdgeID             e,
                float                   *pos);

                LXxMETHOD(  LxResult,
        GetEdgeInfo) (
                LXtObjectID              self,
                LXtOldEdgeID             e,
                LXtMeshEdgeInfo         *info);

                LXxMETHOD(  LxResult,
        GetPointsEdge) (
                LXtObjectID              self,
                LXtPntID                 vA,
                LXtPntID                 vB,
                LXtMeshEdgeInfo         *info);

                LXxMETHOD(  int,
        GetPointConnectedEdges) (
                LXtObjectID              self,
                LXtPntID                 v,
                const LXtOldEdgeID             **edges);

                LXxMETHOD(  int,
        GetPolyConnectedEdges) (
                LXtObjectID              self,
                LXtPolID                 p,
                LXtOldEdgeID           **edges);

                LXxMETHOD(  int,
        NumVMaps) (
                LXtObjectID              self,
                int                      type);

                LXxMETHOD(  LxResult,
        GetPoint) (
                LXtObjectID              self,
                unsigned int             index,
                LXtMeshPointInfo        *info);

                LXxMETHOD(  LxResult,
        GetPointPos) (
                LXtObjectID              self,
                unsigned int             index,
                float                   *pos);

                LXxMETHOD(  LxResult,
        GetPoly) (
                LXtObjectID              self,
                unsigned int             index,
                LXtMeshPolyInfo         *info);

                LXxMETHOD(  const float *,
        GetPolyNormal) (
                LXtObjectID              self,
                LXtPolID                 p);

                LXxMETHOD(  LxResult,
        GetPointNormal) (
                LXtObjectID              self,
                LXtPntID                 v,
                double                  *vec);

                LXxMETHOD(  LxResult,
        GetPolyCenteroid) (
                LXtObjectID              self,
                LXtPolID                 p,
                double                  *pos);

                LXxMETHOD(  unsigned int,
        GetPolyTagCount) (
                LXtObjectID              self,
                LXtPolID                 p);

                LXxMETHOD(  LXtID4,
        GetPolyTagByIndex) (
                LXtObjectID              self,
                LXtPolID                 p,
                unsigned int             index,
                const char             **tag);

                LXxMETHOD(  const char *,
        GetPolyTag) (
                LXtObjectID              self,
                LXtPolID                 p,
                LXtID4                   type);

                LXxMETHOD(  unsigned int,
        GetMaterialCount) (
                LXtObjectID              self);

                LXxMETHOD(  const char *,
        GetMaterialNameByIndex) (
                LXtObjectID              self,
                unsigned int             index);

                LXxMETHOD(  unsigned int,
        GetPartCount) (
                LXtObjectID              self);

                LXxMETHOD(  const char *,
        GetPartNameByIndex) (
                LXtObjectID              self,
                unsigned int             index);

                LXxMETHOD(  LxResult,
        GetPointPoly) (
                LXtObjectID              self,
                unsigned int             index,
                LXtPntID                 v,
                LXtMeshPolyInfo         *pInfo);
        /*
                LXxMETHOD(  LxResult,
        GetPointEdges) (
                LXtObjectID              self,
                LXtOldEdgeID            *v,
                LXtMeshPolyInfo         *pInfo);
        */
                LXxMETHOD(  LxResult,
        GetPolyPoint) (
                LXtObjectID              self,
                unsigned int             index,
                LXtPolID                 p,
                LXtMeshPointInfo        *vinfo);

                LXxMETHOD(  LxResult,
        GetVMap) (
                LXtObjectID              self,
                LXtID4                   type,
                unsigned int             index,
                LXtMeshVMapInfo         *vmInfo);

                LXxMETHOD(  LxResult,
        GetVMapByName) (
                LXtObjectID              self,
                LXtID4                   type,
                const char              *name,
                LXtMeshVMapInfo         *vmInfo);

                LXxMETHOD(  const char *,
        GetVMapName) (
                LXtObjectID              self,
                LXtVMapID                m);

                LXxMETHOD(  float *,
        GetPointVMapValue) (
                LXtObjectID              self,
                LXtVMapID                m,
                LXtPntID                 v);

                LXxMETHOD(  float *,
        GetPolyPointVMapValue) (
                LXtObjectID              self,
                LXtVMapID                m,
                LXtPolID                 p,
                LXtPntID                 v,
                int                     *disco);

                LXxMETHOD(  int,
        GetPolyFirstConvex) (
                LXtObjectID              self,
                LXtPolID                 p);

                LXxMETHOD(  float *,
        GetEdgeVMapValue) (
                LXtObjectID              self,
                LXtVMapID                m,
                LXtOldEdgeID             e);

                LXxMETHOD(  LxResult,
        GetPolyIntersect) (
                LXtObjectID              self,
                double                   pos[3],
                double                   dir[3],
                double                  *hitPos,
                double                  *hitNorm,
                LXtMeshPolyInfo         *pInfo);

                LXxMETHOD( unsigned int,
        GetPointIndex) (
                LXtObjectID              self,
                LXtPntID                 v);

                LXxMETHOD( unsigned int,
        GetPolyIndex) (
                LXtObjectID              self,
                LXtPolID                 p);

} ILxMeshOLD;
typedef struct vt_ILxMeshOLDEdit {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        AddPoint) (
                LXtObjectID              self,
                LXtMeshPointInfo        *info);

                LXxMETHOD(  LxResult,
        AddPoly) (
                LXtObjectID              self,
                LXtMeshPolyInfo         *info);

                LXxMETHOD(  LxResult,
        MovePoint) (
                LXtObjectID              self,
                LXtPntID                 vrt,
                const double            *pos);

                LXxMETHOD(  LxResult,
        PolyTagSet) (
                LXtObjectID              self,
                LXtPolID                 pol,
                LXtID4                   type,
                const char              *tag);

                LXxMETHOD(  LxResult,
        PolyTagSetDefault) (
                LXtObjectID              self,
                LXtID4                   type,
                const char              *tag);

                LXxMETHOD(  LxResult,
        PolyTagCopy) (
                LXtObjectID              self,
                LXtPolID                 from,
                LXtPolID                 to);

                LXxMETHOD(  LxResult,
        PolyTagDelete) (
                LXtObjectID              self,
                LXtPolID                 poly);

                LXxMETHOD(  LxResult,
        AdjustPoint) (
                LXtObjectID              self,
                LXtPntID                 vrt,
                const double            *pos);

                LXxMETHOD(  LxResult,
        VMapCreate) (
                LXtObjectID              self,
                LXtID4                   type,
                const char              *name,
                LXtMeshVMapInfo         *info);

                LXxMETHOD(  LxResult,
        SetPointVMapValue) (
                LXtObjectID              self,
                LXtVMapID                m,
                LXtPntID                 v,
                const float             *value);

                LXxMETHOD(  LxResult,
        SetPolyPointVMapValue) (
                LXtObjectID              self,
                LXtVMapID                m,
                LXtPolID                 p,
                LXtPntID                 v,
                const float             *value);

                LXxMETHOD(  LxResult,
        SetEdgeVMapValue) (
                LXtObjectID              self,
                LXtVMapID                m,
                LXtOldEdgeID             p,
                const float             *value);

} ILxMeshOLDEdit;

#define LXi_POLY_MAXVERT         65535
#define LXsPTYP_FACE            "face"
#define LXsPTYP_PATCH           "patch"
#define LXsPTYP_CURVE           "curve"
#define LXsPTYP_BEZIER          "bezier"
#define LXsPTYP_SUBD            "subdiv"
#define LXsPTYP_SPCH            "spatch"
#define LXsPTYP_HAIR            "hair"
#define LXsPTYP_TEXT            "text"
#define LXsPTYP_PSUB            "psubdiv"
#define LXiPTYP_FACE            LXxID4('F','A','C','E')
#define LXiPTYP_CURVE           LXxID4('C','U','R','V')
#define LXiPTYP_PATCH           LXxID4('P','T','C','H')
#define LXiPTYP_BEZIER          LXxID4('B','E','Z','R')
#define LXiPTYP_SUBD            LXxID4('S','U','B','D')
#define LXiPTYP_SPCH            LXxID4('S','P','C','H')
#define LXiPTYP_HAIR            LXxID4('H','A','I','R')
#define LXiPTYP_TEXT            LXxID4('T','E','X','T')
#define LXiPTYP_PSUB            LXxID4('P','S','U','B')

#define LXiPTYP_BEZR            LXiPTYP_BEZIER
#define LXiPTYP_CURV            LXiPTYP_CURVE
#define LXi_MELTf_CCSTART       1
#define LXi_MELTf_CCEND         2
#define LXi_POLYTAG_MATERIAL            LXxID4('M','A','T','R')
#define LXi_POLYTAG_PART                LXxID4('P','A','R','T')
#define LXi_POLYTAG_SMOOTHING_GROUP     LXxID4('S','M','G','P')
#define LXi_POLYTAG_PICK                LXxID4('P','I','C','K')
#define LXi_POLYTAG_FONT                LXxID4('F','O','N','T')
#define LXi_POLYTAG_TEXT                LXxID4('T','E','X','T')
#define LXi_POLYTAG_JUST                LXxID4('J','U','S','T')
#define LXu_MESH_OLD            "CAC2F76E-D72E-4E62-B406-A5E0ADDCF364"
#define LXu_MESHEDIT_OLD        "AB714588-CD54-4733-A619-99B07B2057C3"
#define LXi_VMAP_OBJECTPOS      LXxID4('O','P','O','S')
#define LXi_VMAP_MORPH          LXxID4('M','O','R','F')
#define LXi_VMAP_SPOT           LXxID4('S','P','O','T')
#define LXi_VMAP_NORMAL         LXxID4('N','O','R','M')
#define LXi_VMAP_TEXTUREUV      LXxID4('T','X','U','V')
#define LXi_VMAP_WEIGHT         LXxID4('W','G','H','T')
#define LXi_VMAP_PICK           LXxID4('P','I','C','K')
#define LXi_VMAP_EPCK           LXxID4('E','P','C','K')
#define LXi_VMAP_RGB            LXxID4('R','G','B',' ')
#define LXi_VMAP_RGBA           LXxID4('R','G','B','A')
#define LXi_VMAP_SUBDIV         LXxID4('S','U','B','V')
#define LXi_VMAP_POSESHAPE      LXxID4('P','O','S','E')

 #ifdef __cplusplus
  }
 #endif
#endif

