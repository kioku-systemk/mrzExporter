/*
 * LX layer module
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
#ifndef LX_layer_H
#define LX_layer_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxLayerService ** ILxLayerServiceID;
typedef struct vt_ILxLayerScan ** ILxLayerScanID;
typedef struct vt_ILxTransformScan ** ILxTransformScanID;
typedef struct vt_ILxScene1Service ** ILxScene1ServiceID;
#define NEW_SURF_INTERFACE



typedef struct vt_ILxLayerService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        SetScene) (
                LXtObjectID              self,
                LXtObjectID              scene);

                LXxMETHOD(  LxResult,
        Scene) (
                LXtObjectID              self,
                void                   **xcin);
                LXxMETHOD(  LxResult,
        Count) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        Name) (
                LXtObjectID              self,
                unsigned int             index,
                const char             **name);

                LXxMETHOD(  LxResult,
        Slot) (
                LXtObjectID              self,
                unsigned int             index,
                int                     *slot);

                LXxMETHOD(  LxResult,
        Item) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **item);

                LXxMETHOD(  LxResult,
        Mesh) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **mesh);

                LXxMETHOD(  LxResult,
        Flags) (
                LXtObjectID              self,
                unsigned int             index,
                int                     *flags);

                LXxMETHOD(  LxResult,
        Pivot) (
                LXtObjectID              self,
                unsigned int             index,
                double                  *pivot);

                LXxMETHOD(  LxResult,
        PatchSubdivision) (
                LXtObjectID              self,
                unsigned int             index,
                int                     *level);

                LXxMETHOD(  LxResult,
        Bounds) (
                LXtObjectID              self,
                unsigned int             index,
                double                  *min,
                double                  *max);

                LXxMETHOD(  LxResult,
        CurveSmoothAngle) (
                LXtObjectID              self,
                unsigned int             index,
                double                  *angle);

                LXxMETHOD(  LxResult,
        SplinePatchSubdivision) (
                LXtObjectID              self,
                unsigned int             index,
                int                     *level);
                LXxMETHOD(  LxResult,
        ItemLookup) (
                LXtObjectID              self,
                int                      mode,
                LXtObjectID              item,
                int                     *index);

                LXxMETHOD(  LxResult,
        NameLookup) (
                LXtObjectID              self,
                int                      mode,
                const char              *name,
                int                     *index);
                LXxMETHOD(  LxResult,
        LayerParent) (
                LXtObjectID              self,
                int                      index,
                int                     *parentIndex);
                LXxMETHOD(  LxResult,
        LayerChildCount) (
                LXtObjectID              self,
                int                      index,
                int                     *num);

                LXxMETHOD(  LxResult,
        LayerChild) (
                LXtObjectID              self,
                int                      index,
                int                      childNumber,
                int                     *childIndex);
                LXxMETHOD(  LxResult,
        LayerVMapCount) (
                LXtObjectID              self,
                int                     *num);

                LXxMETHOD(  LxResult,
        LayerVMap) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        LayerClipCount) (
                LXtObjectID              self,
                int                     *num);

                LXxMETHOD(  LxResult,
        LayerClip) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        LayerMaterialCount) (
                LXtObjectID              self,
                int                     *num);

                LXxMETHOD(  LxResult,
        LayerMaterial) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        LayerPartCount) (
                LXtObjectID              self,
                int                     *num);

                LXxMETHOD(  LxResult,
        LayerPart) (
                LXtObjectID              self,
                unsigned int             index,
                const char              **part);
                LXxMETHOD(  LxResult,
        LayerSelSetCount) (
                LXtObjectID              self,
                unsigned int             type,
                int                     *num);

                LXxMETHOD(  LxResult,
        LayerSelSet) (
                LXtObjectID              self,
                unsigned int             type,
                unsigned int             index,
                const char              **selSet);
                LXxMETHOD(  LxResult,
        LayerTextureCount) (
                LXtObjectID              self,
                int                      layer,
                int                     *num);

                LXxMETHOD(  LxResult,
        LayerTexture) (
                LXtObjectID              self,
                int                      layer,
                unsigned int             index,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        LayerTagTextureCount) (
                LXtObjectID              self,
                int                      layer,
                unsigned int             type,
                const char              *tag,
                int                     *num);

                LXxMETHOD(  LxResult,
        LayerTagTexture) (
                LXtObjectID              self,
                int                      layer,
                unsigned int             type,
                const char              *tag,
                unsigned int             index,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        LayerVertexCount) (
                LXtObjectID              self,
                int                      mode,
                int                     *num);

                LXxMETHOD(  LxResult,
        LayerVertex) (
                LXtObjectID              self,
                int                      mode,
                unsigned int             index,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        LayerPolyCount) (
                LXtObjectID              self,
                int                      mode,
                int                     *num);

                LXxMETHOD(  LxResult,
        LayerPoly) (
                LXtObjectID              self,
                int                      mode,
                unsigned int             index,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        LayerEdgeCount) (
                LXtObjectID              self,
                int                      mode,
                int                     *num);

                LXxMETHOD(  LxResult,
        LayerEdge) (
                LXtObjectID              self,
                int                      mode,
                unsigned int             index,
                void                   **ppvObj);
                LXxMETHOD( LxResult,
        ScanAllocate) (
                LXtObjectID              self,
                unsigned                 flags,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        CurrentMap) (
                LXtObjectID              self,
                LXtID4                   type,
                const char              **name);
                LXxMETHOD( LxResult,
        XfrmAllocate) (
                LXtObjectID              self,
                LXtObjectID              toolVec,
                void                   **ppvObj);
} ILxLayerService;
typedef struct vt_ILxLayerScan {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Apply) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Count) (
                LXtObjectID              self,
                unsigned                *count);
                LXxMETHOD( LxResult,
        GetState) (
                LXtObjectID              self,
                unsigned                 index,
                unsigned                *state);
                LXxMETHOD( LxResult,
        MeshItem) (
                LXtObjectID              self,
                unsigned                 index,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        MeshAction) (
                LXtObjectID              self,
                unsigned                 index,
                void                   **ppvObj);
                LXxMETHOD( LxResult,
        MeshBase) (
                LXtObjectID              self,
                unsigned                 index,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        MeshInstance) (
                LXtObjectID              self,
                unsigned                 index,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        MeshEdit) (
                LXtObjectID              self,
                unsigned                 index,
                void                   **ppvObj);
                LXxMETHOD( LxResult,
        SetMeshChange) (
                LXtObjectID              self,
                unsigned                 index,
                unsigned int             edits);
} ILxLayerScan;
typedef struct vt_ILxTransformScan {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Enumerate) (
                LXtObjectID              self,
                LXtObjectID              visitor);

                LXxMETHOD( unsigned int,
        Flags) (
                LXtObjectID              self);
                LXxMETHOD( const float *,
        Position) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        SetPosition) (
                LXtObjectID              self,
                LXtFVector               pos);
                LXxMETHOD( double,
        Weight) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        AlternateCenter) (
                LXtObjectID              self,
                LXtFVector               center);

                LXxMETHOD( LxResult,
        AlternateAxis) (
                LXtObjectID              self,
                LXtMatrix                matrix,
                LXtMatrix                inverse);
} ILxTransformScan;
typedef struct vt_ILxScene1Service {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        ItemWorldTransform) (
                LXtObjectID              self,
                LXtObjectID              locator,
                double                   time,
                LXtMatrix                xfrm,
                LXtVector                pos);

                LXxMETHOD(  LxResult,
        ItemWorldRotation) (
                LXtObjectID              self,
                LXtObjectID              locator,
                double                   time,
                LXtMatrix                xfrm);
} ILxScene1Service;

#define LXu_LAYERSERVICE        "F12B06AA-BF92-4585-800E-45AB99D47A20"
#define LXa_LAYERSERVICE        "layerservice"
#define LXi_LAYER_PRIMARY               0
#define LXi_LAYER_FOREGROUND            1
#define LXi_LAYER_BACKGROUND            2
#define LXi_LAYER_ALL                   3
#define LXf_LAYER_FOREGROUND            1
#define LXf_LAYER_BACKGROUND            2
#define LXf_LAYER_MAIN                  4
#define LXu_LAYERSCAN   "097DB669-91C3-11D9-8EA2-000A956C2E10"
#define LXa_LAYERSCAN   "layerscan"
// [local] ILxLayerScan
#define LXf_LAYERSCAN_ACTIVE             0x001
#define LXf_LAYERSCAN_BACKGROUND         0x002
#define LXf_LAYERSCAN_PRIMARY            0x004
#define LXf_LAYERSCAN_ALL               (LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_BACKGROUND)

#define LXf_LAYERSCAN_MARKVERTS          0x010
#define LXf_LAYERSCAN_MARKEDGES          0x020
#define LXf_LAYERSCAN_MARKPOLYS          0x040
#define LXf_LAYERSCAN_MARKDVRTS          0x080
#define LXf_LAYERSCAN_MARKALL           (LXf_LAYERSCAN_MARKVERTS | LXf_LAYERSCAN_MARKEDGES | LXf_LAYERSCAN_MARKPOLYS | LXf_LAYERSCAN_MARKDVRTS)

#define LXf_LAYERSCAN_WRITEMESH          0x100

#define LXf_LAYERSCAN_EDIT              (LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_WRITEMESH | LXf_LAYERSCAN_MARKALL)
#define LXf_LAYERSCAN_EDIT_POLYS        (LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_WRITEMESH | LXf_LAYERSCAN_MARKPOLYS)
#define LXf_LAYERSCAN_EDIT_VERTS        (LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_WRITEMESH | LXf_LAYERSCAN_MARKVERTS)
#define LXf_LAYERSCAN_EDIT_EDGES        (LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_WRITEMESH | LXf_LAYERSCAN_MARKEDGES)
#define LXf_LAYERSCAN_EDIT_DVRTS        (LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_WRITEMESH | LXf_LAYERSCAN_MARKDVRTS)
#define LXf_LAYERSCAN_EDIT_POLVRT       (LXf_LAYERSCAN_ACTIVE | LXf_LAYERSCAN_WRITEMESH | LXf_LAYERSCAN_MARKPOLYS | LXf_LAYERSCAN_MARKVERTS)
#define LXfXFRMSCAN_WEIGHT       0x01
#define LXfXFRMSCAN_ALTCENTER    0x02
#define LXfXFRMSCAN_ALTAXIS      0x04
#define LXu_TRANSFORMSCAN       "6DD4BC9B-BEDC-46B9-B5AC-850A06AD5EEB"
// [local] ILxTransformScan
#define LXu_SCENE1SERVICE       "11D99CDC-F662-40FF-9AC3-B76E59C8DEB0"
#define LXa_SCENE1SERVICE       "sceneservice"

 #ifdef __cplusplus
  }
 #endif
#endif

