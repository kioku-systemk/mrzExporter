/*
 * LX tpipe module
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
#ifndef LX_tpipe_H
#define LX_tpipe_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxTool ** ILxToolID;
typedef struct vt_ILxAttrSequence ** ILxAttrSequenceID;
typedef struct vt_ILxFalloffPacket ** ILxFalloffPacketID;
typedef struct vt_ILxSymmetryPacket ** ILxSymmetryPacketID;
typedef struct vt_ILxTexturePacket ** ILxTexturePacketID;
typedef struct vt_ILxElementAxisPacket ** ILxElementAxisPacketID;
typedef struct vt_ILxElementCenterPacket ** ILxElementCenterPacketID;
typedef struct vt_ILxPathGeneratorPacket ** ILxPathGeneratorPacketID;
typedef struct vt_ILxBagGenerator ** ILxBagGeneratorID;
typedef struct vt_ILxPathStep ** ILxPathStepID;
typedef struct vt_ILxParticleGeneratorPacket ** ILxParticleGeneratorPacketID;
#include <lxcom.h>
#include <lxvalue.h>
#include <lxvector.h>
#include <lxmesh.h>


typedef struct st_LXpToolSubject {
        LXtMeshID                mesh;
        LXtMeshMapID             vmap;
        LXtID4                   type;
        LXtMeshID                base;
} LXpToolSubject;
typedef struct st_LXpToolActionCenter {
        LXtVector                v;
} LXpToolActionCenter;
typedef struct st_LXpToolAxis {
        LXtVector                axis;
        LXtVector                up;
        LXtVector                right;
        LXtMatrix                m, mInv;
        int                      axIndex;
        int                      type;
} LXpToolAxis;
typedef struct st_LXpToolXfrm {
        LXtVector                v;
        LXtMatrix                m;
        LXtMatrix                mInv;
        int                      flags;
        int                      handedness;
        unsigned int             marks;
} LXpToolXfrm;
typedef struct st_LXtPathKnot {
        LXtFVector               position;
        LXtFVector               tanIn;
        LXtFVector               tanOut;
        int                      flags;
        void                    *clientData;
        double                   bank;
} LXtPathKnot;
typedef struct st_LXtPGenParticle {
        LXtFVector               position;
        LXtFVector               scale;
        LXtMatrix                orientation;
        int                      flags;
} LXtPGenParticle;
typedef struct st_LXpToolContent {
        const char              *path;
        const char              *type;
        double                   scale;
        LXtVector                axis;
        LXtVector                offset;
        int                      axIndex;
        int                      flags;
        void                    *data;
} LXpToolContent;
typedef struct vt_ILxTool {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        Reset) (
                LXtObjectID              self);

                LXxMETHOD( void,
        Evaluate) (
                LXtObjectID              self,
                LXtObjectID              vts);

                LXxMETHOD( LXtObjectID,
        VectorType) (
                LXtObjectID              self);

                LXxMETHOD( const char *,
        Order) (
                LXtObjectID              self);

                LXxMETHOD( LXtID4,
        Task) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Sequence) (
                LXtObjectID              self,
                LXtObjectID              seq);
                LXxMETHOD( int,
        ShouldBeAttribute) (
                LXtObjectID              self,
                LXtID4                   task);
} ILxTool;
typedef struct vt_ILxAttrSequence {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Integer) (
                LXtObjectID              self,
                const char              *name,
                int                      value);

                LXxMETHOD( LxResult,
        Float) (
                LXtObjectID              self,
                const char              *name,
                double                   value);

                LXxMETHOD( LxResult,
        String) (
                LXtObjectID              self,
                const char              *name,
                const char              *value);

                LXxMETHOD( LxResult,
        Value) (
                LXtObjectID              self,
                const char              *name,
                LXtObjectID              value);

} ILxAttrSequence;
typedef struct vt_ILxFalloffPacket {
        ILxUnknown       iunk;
                LXxMETHOD(  double,
        Evaluate) (
                LXtObjectID              self,
                LXtFVector               pos,
                LXtPointID               vrx);
                LXxMETHOD(  double,
        Screen) (
                LXtObjectID              self,
                LXtObjectID              vts,
                int                      x,
                int                      y);
} ILxFalloffPacket;
typedef struct vt_ILxSymmetryPacket {
        ILxUnknown       iunk;
                LXxMETHOD(  int,
        Active) (
                LXtObjectID              self);

                LXxMETHOD(  int,
        Axis) (
                LXtObjectID              self,
                LXtFVector               axvec,
                float                   *offset);

                LXxMETHOD(  LXtPointID,
        Point) (
                LXtObjectID              self,
                LXtMeshID                mesh,
                LXtPointID               vrx);

                LXxMETHOD(  LXtPolygonID,
        Polygon) (
                LXtObjectID              self,
                LXtMeshID                mesh,
                LXtPolygonID             pol);

                LXxMETHOD(  LXtEdgeID,
        Edge) (
                LXtObjectID              self,
                LXtMeshID                mesh,
                LXtEdgeID                edge);

                LXxMETHOD(  int,
        Position) (
                LXtObjectID              self,
                const LXtFVector         pos,
                LXtFVector               sv);
} ILxSymmetryPacket;
typedef struct vt_ILxTexturePacket {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Evaluate) (
                LXtObjectID              self,
                LXtFVector               pos,
                LXtPointID               vrx,
                LXtPolygonID             pol,
                int                      context,
                double                  *res);
} ILxTexturePacket;
typedef struct vt_ILxElementAxisPacket {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Axis) (
                LXtObjectID              self,
                LXtPointID               vrx,
                LXtFVector               axis,
                LXtMatrix                m,
                LXtMatrix                mInv);
} ILxElementAxisPacket;
typedef struct vt_ILxElementCenterPacket {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Center) (
                LXtObjectID              self,
                LXtPointID               vrx,
                LXtFVector               center);
} ILxElementCenterPacket;
typedef struct vt_ILxPathGeneratorPacket {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Value) (
                LXtObjectID              self,
                LXtObjectID              vts,
                double                   t,
                LXtVector                pos);
                LXxMETHOD(  double,
        Length) (
                LXtObjectID              self,
                LXtObjectID              vts,
                double                   t0,
                double                   t1);
                LXxMETHOD(  LxResult,
        Tangent) (
                LXtObjectID              self,
                LXtObjectID              vts,
                double                   t,
                double                  *tan);
                LXxMETHOD(  LXtPolygonID,
        Source) (
                LXtObjectID              self,
                LXtObjectID              vts);
                LXxMETHOD(  int,
        Count) (
                LXtObjectID              self,
                LXtObjectID              vts);

                LXxMETHOD(  LxResult,
        Knot) (
                LXtObjectID              self,
                LXtObjectID              vts,
                int                      index,
                LXtPathKnot             *knot);

                LXxMETHOD(  int,
        Current) (
                LXtObjectID              self,
                LXtObjectID              vts);
                LXxMETHOD(  LxResult,
        KnotDataSet) (
                LXtObjectID              self,
                LXtObjectID              gen);
                LXxMETHOD(  int,
        Walk) (
                LXtObjectID              self,
                LXtObjectID              vts,
                LXtObjectID              pathStep,
                double                   angle,
                double                   ti,
                double                   tf);
                LXxMETHOD(  double,
        Bank) (
                LXtObjectID              self,
                LXtObjectID              vts,
                double                   t);
} ILxPathGeneratorPacket;
typedef struct vt_ILxBagGenerator {
        ILxUnknown       iunk;
                LXxMETHOD(  void*,
        Generate) (
                LXtObjectID              self,
                void                    *data,
                void                    *cloneMe);

                LXxMETHOD(  void,
        Dispose) (
                LXtObjectID              self,
                void                    *data);
} ILxBagGenerator;
typedef struct vt_ILxPathStep {
        ILxUnknown       iunk;
                LXxMETHOD(  void,
        Setup) (
                LXtObjectID              self);
                LXxMETHOD(  int,
        Step) (
                LXtObjectID              self,
                double                   t, 
                LXtVector                pos);
                LXxMETHOD(  void,
        CleanUp) (
                LXtObjectID              self);
} ILxPathStep;
typedef struct vt_ILxParticleGeneratorPacket {
        ILxUnknown       iunk;
                LXxMETHOD(  int,
        Count) (
                LXtObjectID              self,
                LXtObjectID              vts);

                LXxMETHOD(  LxResult,
        Particle) (
                LXtObjectID              self,
                LXtObjectID              vts,
                int                      index,
                LXtPGenParticle         *part);
                LXxMETHOD(  LxResult,
        InitialParticleSet) (
                LXtObjectID              self,
                const LXtPGenParticle   *part);
                LXxMETHOD(  LxResult,
        HintBoxSet) (
                LXtObjectID              self,
                const LXtBBox           *box,
                LXtPGenParticle         *part);
} ILxParticleGeneratorPacket;

#define LXf_SHOULDBE_ATTR               1
#define LXi_TASK_SNAP           LXxID4 ('S','N','A','P')
#define LXi_TASK_ACEN           LXxID4 ('A','C','E','N')
#define LXi_TASK_AXIS           LXxID4 ('A','X','I','S')
#define LXi_TASK_WGHT           LXxID4 ('W','G','H','T')
#define LXi_TASK_CONS           LXxID4 ('C','O','N','S')
#define LXi_TASK_ACTR           LXxID4 ('A','C','T','R')
#define LXi_TASK_SIDE           LXxID4 ('S','I','D','E')
#define LXi_TASK_PATH           LXxID4 ('P','A','T','H')
#define LXi_TASK_PTCL           LXxID4 ('P','T','C','L')
#define LXi_TASK_EFFR           LXxID4 ('E','F','F','R')
#define LXi_TASK_BRSH           LXxID4 ('B','R','S','H')
#define LXi_TASK_NOZL           LXxID4 ('N','O','Z','L')
#define LXi_TASK_PINK           LXxID4 ('P','I','N','K')
#define LXi_TASK_CONT           LXxID4 ('C','O','N','T')
#define LXi_TASK_POST           LXxID4 ('P','O','S','T')
#define LXs_ORD_CONT            "\x38"
#define LXs_ORD_SNAP            "\x40"
#define LXs_ORD_CONS            "\x41"
#define LXs_ORD_ACEN            "\x60"
#define LXs_ORD_AXIS            "\x70"
#define LXs_ORD_PATH            "\x80"
#define LXs_ORD_WGHT            "\x90"
#define LXs_ORD_PINK            "\xB0"
#define LXs_ORD_NOZL            "\xB1"
#define LXs_ORD_BRSH            "\xB2"
#define LXs_ORD_PTCL            "\xC0"
#define LXs_ORD_SIDE            "\xD0"
#define LXs_ORD_EFFR            "\xD8"
#define LXs_ORD_ACTR            "\xF0"
#define LXs_ORD_POST            "\xF1"
#define LXu_TOOL        "12E79F81-565E-11D7-A4CF-000A95765C9E"
#define LXa_TOOL        "tool"
// [local]   ILxTool
// [export]  ILxTool
// [default] ILxTool:ShouldBeAttribute = 0
#define LXu_ATTRSEQUENCE                "F54FEF16-223F-439D-8593-6F350783993E"
// [local]  ILxAttrSequence
#define LXsCATEGORY_TOOL        "tool"
#define LXiTVXFMf_OFFSET        1
#define LXiTVXFMf_MATRIX        2
#define LXiTVXFMf_INVERSE       4
#define LXiTVXFMf_USEFUL        (LXiTVXFMf_OFFSET | LXiTVXFMf_MATRIX)
#define LXsP_TOOL_SUBJECT       "tool.subject"
#define LXsP_TOOL_ACTCENTER     "tool.actionCenter"
#define LXsP_TOOL_AXIS          "tool.axis"
#define LXsP_TOOL_XFRM          "tool.xfrm"
#define LXsP_TOOL_FALLOFF       "tool.falloff"
#define LXsP_TOOL_SYMMETRY      "tool.symmetry"
#define LXsP_TOOL_TEXTURE       "tool.texture"
#define LXsP_TOOL_ELTCENTER     "tool.eltCenter"
#define LXsP_TOOL_ELTAXIS       "tool.eltAxis"
#define LXu_FALLOFFPACKET               "D0F8CF5D-1BB5-4002-810B-0E7EF34B7867"
// [local]  ILxFalloffPacket
#define LXu_SYMMETRYPACKET              "F13F6933-1289-4EFC-9CE1-D5C4F13EE7D8"
// [local]  ILxSymmetryPacket
#define LXu_TEXTUREPACKET               "851271E5-F4F4-444D-A87A-563B9E1E6EFB"
// [local]  ILxTexturePacket
#define LXu_ELEMENTAXISPACKET   "292A47BF-3CF5-492D-AAFD-AE761092A782"
// [local]  ILxElementAxisPacket
#define LXu_ELEMENTCENTERPACKET "5221C415-073A-4610-BCB6-F820F8D7F6D0"
// [local]  ILxElementCenterPacket
#define LXf_PATHKNOT_BROKEN     1
#define LXu_BAGGENERATOR                "9A368FAA-7576-42B9-9B6A-C2F8D34612F0"
// [local]  ILxBagGenerator
#define LXu_PATHSTEP            "B9F58563-FBA0-4CA2-866B-1DD64174A277"
// [local]  ILxPathStep
#define LXv_PATHGEN_DIV_COARSE          0.105           
#define LXv_PATHGEN_DIV_MEDIUM          0.087           
#define LXv_PATHGEN_DIV_FINE            0.052           
#define LXu_PATHGENERATORPACKET         "AE70D946-8A9A-4A72-95EC-BFF856391D22"
// [local]  ILxPathGeneratorPacket
#define LXsP_TOOL_PATHGEN       "tool.pathGenerator"
typedef void PathWalkerFunc (void *data, double t, LXtVector pos);
#define LXf_PARTGEN_CONNECT             0x01
#define LXf_PARTGEN_ABSSIZE             0x02
#define LXf_PARTGEN_MIRROR              0x04
#define LXu_PARTICLEGENERATORPACKET     "5CDF5B58-46BF-4D78-8652-659E87E19C4B"
// [local]  ILxParticleGeneratorPacket
#define LXsP_TOOL_PARTGEN       "tool.partGenerator"
#define LXsP_TOOL_CONTENT       "tool.content"

 #ifdef __cplusplus
  }
 #endif
#endif

