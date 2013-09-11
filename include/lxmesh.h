/*
 * LX ilxmesh module
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
#ifndef LX_ilxmesh_H
#define LX_ilxmesh_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxMeshService ** ILxMeshServiceID;
typedef struct vt_ILxMesh ** ILxMeshID;
typedef struct vt_ILxPoint ** ILxPointID;
typedef struct vt_ILxPolygon ** ILxPolygonID;
typedef struct vt_ILxEdge ** ILxEdgeID;
typedef struct vt_ILxMeshMap ** ILxMeshMapID;
typedef struct vt_ILxMeshListener ** ILxMeshListenerID;
typedef struct vt_ILxMeshFilter ** ILxMeshFilterID;
typedef struct vt_ILxMeshFilterBBox ** ILxMeshFilterBBoxID;
#include <lxserver.h>
#include <lxvmath.h>

typedef unsigned int    LXtMarkMode;
#define LXiMARK_ANY     ((LXtMarkMode) 0)

#define LXsMARK_HIDE    "hide"
#define LXsMARK_HALO    "halo"
#define LXsMARK_LOCK    "lock"
#define LXsMARK_SELECT  "select"
#define LXsMARK_USER_0  "user0"
#define LXsMARK_USER_1  "user1"
#define LXsMARK_USER_2  "user2"
#define LXsMARK_USER_3  "user3"
#define LXsMARK_USER_4  "user4"
#define LXsMARK_USER_5  "user5"
#define LXsMARK_USER_6  "user6"
#define LXsMARK_USER_7  "user7"
typedef struct st_MeshVertex *    LXtPointID;
typedef struct st_MeshPolygon *   LXtPolygonID;
typedef struct st_MeshEdge *      LXtEdgeID;
typedef struct st_MeshVertexMap * LXtMeshMapID;

typedef struct vt_ILxMeshService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ModeCompose) (
                LXtObjectID              self,
                const char              *set,
                const char              *clear,
                LXtMarkMode             *mode);
                LXxMETHOD(  LxResult,
        VMapLookupType) (
                LXtObjectID              self,
                const char              *name,
                LXtID4                  *type);

                LXxMETHOD(  LxResult,
        VMapLookupName) (
                LXtObjectID              self,
                LXtID4                   type,
                const char             **name);
                LXxMETHOD(  LxResult,
        VMapDimension) (
                LXtObjectID              self,
                LXtID4                   type,
                unsigned int            *dimension);

                LXxMETHOD(  LxResult,
        VMapIsEdgeMap) (
                LXtObjectID              self,
                LXtID4                   type);

                LXxMETHOD(  LxResult,
        VMapIsContinuous) (
                LXtObjectID              self,
                LXtID4                   type);

                LXxMETHOD(  LxResult,
        VMapZeroDefault) (
                LXtObjectID              self,
                LXtID4                   type);
                LXxMETHOD(  LxResult,
        CreateMesh) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        ConvertMesh) (
                LXtObjectID              self,
                LXtObjectID              triGroupItem,
                LXtObjectID              meshItem);
} ILxMeshService;
typedef struct vt_ILxMesh {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        PointCount) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        PolygonCount) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        EdgeCount) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        MapCount) (
                LXtObjectID              self,
                unsigned int            *count);
                LXxMETHOD(  LxResult,
        BoundingBox) (
                LXtObjectID              self,
                LXtMarkMode              pick,
                LXtBBox                 *bbox);
                LXxMETHOD(  LxResult,
        MaxPointPolygons) (
                LXtObjectID              self,
                LXtMarkMode              pick,
                unsigned int            *count);
                LXxMETHOD(  LxResult,
        MaxPolygonSize) (
                LXtObjectID              self,
                LXtMarkMode              pick,
                unsigned int            *count);
                LXxMETHOD(  LxResult,
        PolyTagSetDefault) (
                LXtObjectID              self,
                LXtID4                   type,
                const char              *tag);
                LXxMETHOD(  LxResult,
        PointAccessor) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        PolygonAccessor) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        EdgeAccessor) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        MeshMapAccessor) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        SetMeshEdits) (
                LXtObjectID              self,
                unsigned int             edits);
                LXxMETHOD(  LxResult,
        SUBDGetLevel) (
                LXtObjectID              self,
                int                     *n);
                LXxMETHOD(  LxResult,
        SUBDSetLevel) (
                LXtObjectID              self,
                int                      n);
                LXxMETHOD(  LxResult,
        SUBDGetLinearUV) (
                LXtObjectID              self,
                int                     *isLinear);
                LXxMETHOD(  LxResult,
        SUBDSetLinearUV) (
                LXtObjectID              self,
                int                      isLinear);
                LXxMETHOD(  LxResult,
        PSUBGetBoundRule) (
                LXtObjectID              self,
                int                     *bound);
                LXxMETHOD(  LxResult,
        PSUBSetBoundRule) (
                LXtObjectID              self,
                int                      bound);
                LXxMETHOD(  LxResult,
        TestSameMesh) (
                LXtObjectID              self,
                LXtObjectID              other);
                LXxMETHOD(  LxResult,
        PTagCount) (
                LXtObjectID              self,
                LXtID4                   type);
                LXxMETHOD(  LxResult,
        PTagByIndex) (
                LXtObjectID              self,
                LXtID4                   type,
                unsigned                 index,
                const char              **tag);
                LXxMETHOD(  LxResult,
        PSUBGetLevel) (
                LXtObjectID              self,
                int                     *n);
                LXxMETHOD(  LxResult,
        PSUBSetLevel) (
                LXtObjectID              self,
                int                      n);
                LXxMETHOD(  LxResult,
        PSUBGetCurrentLevel) (
                LXtObjectID              self,
                int                     *n);
                LXxMETHOD(  LxResult,
        PSUBSetCurrentLevel) (
                LXtObjectID              self,
                int                      n);
} ILxMesh;
typedef struct vt_ILxPoint {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Spawn) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        Enumerate) (
                LXtObjectID              self,
                LXtMarkMode              mode,
                LXtObjectID              visitor,
                LXtObjectID              monitor);
                LXxMETHOD(  LxResult,
        TestMarks) (
                LXtObjectID              self,
                LXtMarkMode              mode);
                LXxMETHOD(  LxResult,
        SetMarks) (
                LXtObjectID              self,
                LXtMarkMode              set);
                LXxMETHOD(  LxResult,
        Select) (
                LXtObjectID              self,
                LXtPointID               point);
                LXxMETHOD(  LxResult,
        SelectByIndex) (
                LXtObjectID              self,
                unsigned int             index);
                LXxMETHOD(  LxResult,
        SelectPolygonVertex) (
                LXtObjectID              self,
                LXtPolygonID             polygon,
                unsigned int             index);
                LXxMETHOD( LXtPointID,
        ID) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Index) (
                LXtObjectID              self,
                unsigned int            *index);
                LXxMETHOD(  LxResult,
        Pos) (
                LXtObjectID              self,
                LXtFVector               pos);
                LXxMETHOD(  LxResult,
        Normal) (
                LXtObjectID              self,
                LXtPolygonID             pol,
                LXtVector                normal);
                LXxMETHOD(  LxResult,
        MapValue) (
                LXtObjectID              self,
                LXtMeshMapID             map,
                float                   *value);
                LXxMETHOD(  LxResult,
        MapEvaluate) (
                LXtObjectID              self,
                LXtMeshMapID             map,
                float                   *value);
                LXxMETHOD(  LxResult,
        PolygonCount) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        PolygonByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                LXtPolygonID            *polygonID);
                LXxMETHOD(  LxResult,
        New) (
                LXtObjectID              self,
                LXtVector                pos,
                LXtPointID              *pointID);
                LXxMETHOD(  LxResult,
        Copy) (
                LXtObjectID              self,
                LXtPointID              *pointID);
                LXxMETHOD(  LxResult,
        Remove) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        SetPos) (
                LXtObjectID              self,
                LXtVector                pos);
                LXxMETHOD(  LxResult,
        SetMapValue) (
                LXtObjectID              self,
                LXtMeshMapID             map,
                const float             *value);
                LXxMETHOD(  LxResult,
        ClearMapValue) (
                LXtObjectID              self,
                LXtMeshMapID             map);
                LXxMETHOD(  LxResult,
        Corner) (
                LXtObjectID              self,
                LXtFVector               pos);
                LXxMETHOD(  LxResult,
        PointCount) (
                LXtObjectID              self,
                unsigned int            *count);
                LXxMETHOD(  LxResult,
        PointByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                LXtPointID              *pointID);
                LXxMETHOD(  LxResult,
        EdgeCount) (
                LXtObjectID              self,
                unsigned int            *count);
                LXxMETHOD(  LxResult,
        EdgeByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                LXtEdgeID               *edgeID);
} ILxPoint;
typedef struct vt_ILxPolygon {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Spawn) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        Enumerate) (
                LXtObjectID              self,
                LXtMarkMode              mode,
                LXtObjectID              visitor,
                LXtObjectID              monitor);
                LXxMETHOD(  LxResult,
        TestMarks) (
                LXtObjectID              self,
                LXtMarkMode              mode);
                LXxMETHOD(  LxResult,
        SetMarks) (
                LXtObjectID              self,
                LXtMarkMode              set);
                LXxMETHOD(  LxResult,
        Select) (
                LXtObjectID              self,
                LXtPolygonID             polygon);
                LXxMETHOD(  LxResult,
        SelectByIndex) (
                LXtObjectID              self,
                unsigned int             index);
                LXxMETHOD( LXtPolygonID,
        ID) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Index) (
                LXtObjectID              self,
                int                     *index);
                LXxMETHOD(  LxResult,
        Type) (
                LXtObjectID              self,
                LXtID4                  *type);
                LXxMETHOD(  LxResult,
        VertexCount) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        VertexByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                LXtPointID              *point);
                LXxMETHOD(  LxResult,
        FirstIsControlEndpoint) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        LastIsControlEndpoint) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        Normal) (
                LXtObjectID              self,
                LXtVector                normal);
                LXxMETHOD(  LxResult,
        MapValue) (
                LXtObjectID              self,
                LXtMeshMapID             map,
                LXtPointID               point,
                float                   *value);
                LXxMETHOD(  LxResult,
        MapEvaluate) (
                LXtObjectID              self,
                LXtMeshMapID             map,
                LXtPointID               point,
                float                   *value);
                LXxMETHOD(  LxResult,
        New) (
                LXtObjectID              self,
                LXtID4                   type,
                const LXtPointID        *vertices,
                unsigned int             numVert,
                unsigned int             rev,
                LXtPolygonID            *polygonID);
                LXxMETHOD(  LxResult,
        NewProto) (
                LXtObjectID              self,
                LXtID4                   type,
                const LXtPointID        *vertices,
                unsigned int             numVert,
                unsigned int             rev,
                LXtPolygonID            *polygonID);
                LXxMETHOD(  LxResult,
        Remove) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        SetFirstIsControlEndpoint) (
                LXtObjectID              self,
                int                      state);

                LXxMETHOD(  LxResult,
        SetLastIsControlEndpoint) (
                LXtObjectID              self,
                int                      state);
                LXxMETHOD(  LxResult,
        SetVertexList) (
                LXtObjectID              self,
                const LXtPointID        *vertices,
                unsigned int             numVert,
                unsigned int             rev);
                LXxMETHOD(  LxResult,
        SetMapValue) (
                LXtObjectID              self,
                LXtPointID               point,
                LXtMeshMapID             map,
                const float             *value);
                LXxMETHOD(  LxResult,
        ClearMapValue) (
                LXtObjectID              self,
                LXtPointID               point,
                LXtMeshMapID             map);
                LXxMETHOD(  LxResult,
        StartContour) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        AddContourEdge) (
                LXtObjectID              self,
                LXtPointID               startPt,
                LXtPointID               endPt);
                LXxMETHOD(  LxResult,
        GenerateContour) (
                LXtObjectID              self,
                LXtID4                   type,
                LXtPolygonID            *polygonID);
                LXxMETHOD(  LxResult,
        GenerateContourProto) (
                LXtObjectID              self,
                LXtPolygonID            *polygonID);
                LXxMETHOD(  LxResult,
        IntersectRay) (
                LXtObjectID              self,
                const LXtVector          pos,
                const LXtVector          dir,
                LXtVector                hitNorm,
                double                  *hitDist);
                LXxMETHOD(  LxResult,
        Closest) (
                LXtObjectID              self,
                double                   maxDist,
                const LXtVector          pos,
                LXtVector                hitPos,
                LXtVector                hitNorm,
                double                  *hitDist);
                LXxMETHOD( LxResult,
        PointIndex) (
                LXtObjectID              self,
                LXtPointID               pointID,
                unsigned int            *index);
                LXxMETHOD( LxResult,
        EdgeIndex) (
                LXtObjectID              self,
                LXtEdgeID                edgeID,
                unsigned int            *index);
                LXxMETHOD( LxResult,
        SharedEdge) (
                LXtObjectID              self,
                LXtPolygonID             polygonID,
                LXtEdgeID               *edgeID);
                LXxMETHOD( LxResult,
        IsBorder) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        RepresentativePosition) (
                LXtObjectID              self,
                LXtVector                pos);
                LXxMETHOD( LxResult,
        GoodPoint) (
                LXtObjectID              self,
                const LXtPointID        *points,
                unsigned int             nPoints,
                unsigned int            *index);
} ILxPolygon;
typedef struct vt_ILxEdge {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Spawn) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        Enumerate) (
                LXtObjectID              self,
                LXtMarkMode              mode,
                LXtObjectID              visitor,
                LXtObjectID              monitor);
                LXxMETHOD(  LxResult,
        TestMarks) (
                LXtObjectID              self,
                LXtMarkMode              mode);
                LXxMETHOD(  LxResult,
        SetMarks) (
                LXtObjectID              self,
                LXtMarkMode              set);
                LXxMETHOD(  LxResult,
        Select) (
                LXtObjectID              self,
                LXtEdgeID                edge);
                LXxMETHOD(  LxResult,
        SelectEndpoints) (
                LXtObjectID              self,
                LXtPointID               v0,
                LXtPointID               v1);
                LXxMETHOD(  LXtEdgeID,
        ID) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        Endpoints) (
                LXtObjectID              self,
                LXtPointID              *point0,
                LXtPointID              *point1);
                LXxMETHOD(  LxResult,
        MapValue) (
                LXtObjectID              self,
                LXtMeshMapID             map,
                float                   *value);
                LXxMETHOD(  LxResult,
        MapEvaluate) (
                LXtObjectID              self,
                LXtMeshMapID             map,
                float                   *value);
                LXxMETHOD(  LxResult,
        SetMapValue) (
                LXtObjectID              self,
                LXtMeshMapID             map,
                const float             *value);
                LXxMETHOD(  LxResult,
        ClearMapValue) (
                LXtObjectID              self,
                LXtMeshMapID             map);
                LXxMETHOD(  LxResult,
        PolygonCount) (
                LXtObjectID              self,
                unsigned int            *count);
                LXxMETHOD(  LxResult,
        PolygonByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                LXtPolygonID            *polygonID);
                LXxMETHOD(  LxResult,
        RepresentativePolygon) (
                LXtObjectID              self,
                LXtPolygonID            *polygonID,
                unsigned int            *index);
                LXxMETHOD(  LxResult,
        SharedPolygon) (
                LXtObjectID              self,
                LXtEdgeID                edgeID,
                LXtPolygonID            *polygonID);
                LXxMETHOD(  LxResult,
        IsBorder) (
                LXtObjectID              self);
} ILxEdge;
typedef struct vt_ILxMeshMap {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Spawn) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        Enumerate) (
                LXtObjectID              self,
                LXtMarkMode              mode,
                LXtObjectID              visitor,
                LXtObjectID              monitor);
                LXxMETHOD(  LxResult,
        Select) (
                LXtObjectID              self,
                LXtMeshMapID             map);
                LXxMETHOD(  LxResult,
        SelectByName) (
                LXtObjectID              self,
                LXtID4                   type,
                const char              *name);
                LXxMETHOD( LxResult,
        FilterByType) (
                LXtObjectID              self,
                LXtID4                   type);
                LXxMETHOD( LXtMeshMapID,
        ID) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Name) (
                LXtObjectID              self,
                const char             **name);
                LXxMETHOD( LxResult,
        Type) (
                LXtObjectID              self,
                LXtID4                  *type);
                LXxMETHOD(  LxResult,
        Dimension) (
                LXtObjectID              self,
                unsigned int            *dimension);
                LXxMETHOD(  LxResult,
        IsEdgeMap) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        IsContinuous) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        ZeroDefault) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        New) (
                LXtObjectID              self,
                LXtID4                   type,
                const char              *name,
                LXtMeshMapID            *mapID);
                LXxMETHOD(  LxResult,
        Remove) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        Clear) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        EnumerateContinuous) (
                LXtObjectID              self,
                LXtObjectID              visitor,
                LXtObjectID              point);
                LXxMETHOD(  LxResult,
        EnumerateDiscontinuous) (
                LXtObjectID              self,
                LXtObjectID              visitor,
                LXtObjectID              point,
                LXtObjectID              poly);
                LXxMETHOD(  LxResult,
        EnumerateEdges) (
                LXtObjectID              self,
                LXtObjectID              visitor,
                LXtObjectID              edge);
} ILxMeshMap;
typedef struct vt_ILxMeshListener {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        Destroy) (
                LXtObjectID              self);
} ILxMeshListener;
typedef struct vt_ILxMeshFilter {
        ILxUnknown       iunk;
                LXxMETHOD(  unsigned,
        Type) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        Evaluate) (
                LXtObjectID              self,
                LXtObjectID              mesh);
                LXxMETHOD(  LxResult,
        Generate) (
                LXtObjectID              self,
                void                   **ppvMesh);
} ILxMeshFilter;
typedef struct vt_ILxMeshFilterBBox {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Evaluate) (
                LXtObjectID              self,
                LXtBBox                 *box);
} ILxMeshFilterBBox;

#define LXa_MESHSERVICE "meshservice"
#define LXu_MESHSERVICE "82B739EC-F92E-4CC9-A5FB-584A866D5897"
#define LXa_MESH        "mesh"
#define LXu_MESH        "1F1BB7BF-A862-4810-95FF-3346AF738209"
// [local]  ILxMesh
// [const] ILxMesh:PointCount
// [const] ILxMesh:PolygonCount
// [const] ILxMesh:EdgeCount
// [const] ILxMesh:MapCount
#define LXf_MESHEDIT_POSITION            0x001
#define LXf_MESHEDIT_POINTS              0x002
#define LXf_MESHEDIT_POLYGONS            0x004
#define LXf_MESHEDIT_GEOMETRY           (LXf_MESHEDIT_POINTS | LXf_MESHEDIT_POLYGONS)
#define LXf_MESHEDIT_POL_TAGS            0x008
#define LXf_MESHEDIT_POL_TYPE            0x010
#define LXf_MESHEDIT_MAP_CONTINUITY      0x020
#define LXf_MESHEDIT_MAP_UV              0x040
#define LXf_MESHEDIT_MAP_MORPH           0x080
#define LXf_MESHEDIT_MAP_OTHER           0x100
#define LXiPSUB_BOUND_SMOOTH     0
#define LXiPSUB_BOUND_CREASE     1
#define LXa_POINT       "point"
#define LXu_POINT       "37B477FE-ED3C-4EDC-A4A8-9BB24F58A4E6"
// [local]  ILxPoint
#define LXa_POLYGON     "polygon"
#define LXu_POLYGON     "5839056D-28BF-4D72-8A26-E4AA00DA788F"
// [local]  ILxPolygon
#define LXi_POLY_MAXVERT         65535
#define LXsPTYP_FACE            "face"
#define LXsPTYP_CURVE           "curve"
#define LXsPTYP_BEZIER          "bezier"
#define LXsPTYP_SUBD            "subdiv"
#define LXsPTYP_SPCH            "spatch"
#define LXsPTYP_TEXT            "text"
#define LXsPTYP_PSUB            "psubdiv"
#define LXiPTYP_FACE            LXxID4('F','A','C','E')
#define LXiPTYP_CURVE           LXxID4('C','U','R','V')
#define LXiPTYP_BEZIER          LXxID4('B','E','Z','R')
#define LXiPTYP_SUBD            LXxID4('S','U','B','D')
#define LXiPTYP_SPCH            LXxID4('S','P','C','H')
#define LXiPTYP_TEXT            LXxID4('T','E','X','T')
#define LXiPTYP_PSUB            LXxID4('P','S','U','B')
#define LXi_PTAG_MATR           LXxID4('M','A','T','R')
#define LXi_PTAG_PART           LXxID4('P','A','R','T')
#define LXi_PTAG_PICK           LXxID4('P','I','C','K')
#define LXi_PTAG_FONT           LXxID4('F','O','N','T')
#define LXi_PTAG_TEXT           LXxID4('T','E','X','T')
#define LXi_PTAG_JUST           LXxID4('J','U','S','T')
#define LXa_EDGE        "edge"
#define LXu_EDGE        "19A44432-E2CF-4BCF-9EA6-D696E7A0F16E"
// [local]  ILxEdge
#define LXa_MESHMAP     "meshmap"
#define LXu_MESHMAP     "2AEBA454-2AC4-4F1E-B892-7A16F7601030"
// [local]  ILxMeshMap
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
#define LXsVMAP_ITEMPREFIX      "__item_"
#define LXu_MESHLISTENER        "957900AC-BC06-45D9-B1B1-9CC5A2AEC026"
// [export] ILxMeshListener ml
#define LXiFILT_MODIFY          1
#define LXiFILT_GENERATE        2
#define LXiFILT_SOURCE          3
#define LXu_MESHFILTER  "F5896BA1-7EC5-4EE9-852F-BF977E451953"
// [local]   ILxMeshFilter
// [export]  ILxMeshFilter mfilt
#define LXu_MESHFILTERBBOX      "FBD83166-4B50-42A0-8C91-C36D3BB76904"
// [local]  ILxMeshFilterBBox
// [export] ILxMeshFilterBBox mfbbox

 #ifdef __cplusplus
  }
 #endif
#endif

