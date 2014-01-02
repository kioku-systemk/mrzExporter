/*
 * Plug-in SDK Header: C++ User Classes
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
#ifndef LXUSER_mesh_HPP
#define LXUSER_mesh_HPP

#include <lxw_mesh.hpp>
#include <lx_visitor.hpp>

class CLxUser_Mesh : public CLxLoc_Mesh
{
    public:
        CLxUser_Mesh () {}
        CLxUser_Mesh (ILxUnknownID obj) : CLxLoc_Mesh (obj) {}

                int
        NPoints () const
        {
                unsigned         count;

                if (LXx_OK (PointCount (&count)))
                        return count;
                return -1;
        }

                int
        NPolygons () const
        {
                unsigned         count;

                if (LXx_OK (PolygonCount (&count)))
                        return count;
                return -1;
        }

                int
        NEdges () const
        {
                unsigned         count;

                if (LXx_OK (EdgeCount (&count)))
                        return count;
                return -1;
        }

                int
        NMaps () const
        {
                unsigned         count;

                if (LXx_OK (MapCount (&count)))
                        return count;
                return -1;
        }
                bool
        GetPoints (
                CLxLoc_Point            &acc)
        {
                return PointAccessor (acc);
        }

                bool
        GetPolygons (
                CLxLoc_Polygon          &acc)
        {
                return PolygonAccessor (acc);
        }

                bool
        GetEdges (
                CLxLoc_Edge             &acc)
        {
                return EdgeAccessor (acc);
        }

                bool
        GetMaps (
                CLxLoc_MeshMap          &acc)
        {
                return MeshMapAccessor (acc);
        }
                bool
        IsSame (
                ILxUnknownID             other)
        {
                return (TestSameMesh (other) == LXe_TRUE);
        }
};
class CLxUser_Point : public CLxLoc_Point
{
    public:
        CLxUser_Point () {}
        CLxUser_Point (ILxUnknownID obj) : CLxLoc_Point (obj) {}

        CLxUser_Point (
                CLxLoc_Mesh             &mesh)
        {
                _init ();
                fromMesh (mesh);
        }

                bool
        fromMesh (
                CLxLoc_Mesh             &mesh)
        {
                LXtObjectID              acc;

                clear ();
                if (mesh.test () && LXx_OK (mesh.PointAccessor (&acc)))
                        return take (acc);

                return false;
        }

                bool
        fromMeshObj (
                ILxUnknownID             obj)
        {
                CLxLoc_Mesh              mesh (obj);
                LXtObjectID              acc;

                clear ();
                if (mesh.test () && LXx_OK (mesh.PointAccessor (&acc)))
                        return take (acc);

                return false;
        }

                bool
        duplicate (
                CLxLoc_Point               &acc)
        {
                LXtObjectID              obj;

                acc.clear ();
                if (LXx_FAIL (Spawn (&obj)))
                        return false;

                return acc.take (obj);
        }
                bool
        Test (
                LXtMarkMode              mode)
        {
                return (TestMarks (mode) == LXe_TRUE);
        }
                LxResult
        Enum (
                CLxImpl_AbstractVisitor *visitor,
                LXtMarkMode              mode = LXiMARK_ANY,
                ILxUnknownID             mon  = 0)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;

                gv.loc.vis = visitor;
                return Enumerate (mode, gv, mon);
        }
};
class CLxUser_Polygon : public CLxLoc_Polygon
{
    public:
        CLxUser_Polygon () {}
        CLxUser_Polygon (ILxUnknownID obj) : CLxLoc_Polygon (obj) {}

        CLxUser_Polygon (
                CLxLoc_Mesh             &mesh)
        {
                _init ();
                fromMesh (mesh);
        }

                bool
        fromMesh (
                CLxLoc_Mesh             &mesh)
        {
                LXtObjectID              acc;

                clear ();
                if (mesh.test () && LXx_OK (mesh.PolygonAccessor (&acc)))
                        return take (acc);

                return false;
        }

                bool
        fromMeshObj (
                ILxUnknownID             obj)
        {
                CLxLoc_Mesh              mesh (obj);
                LXtObjectID              acc;

                clear ();
                if (mesh.test () && LXx_OK (mesh.PolygonAccessor (&acc)))
                        return take (acc);

                return false;
        }

                bool
        duplicate (
                CLxLoc_Polygon               &acc)
        {
                LXtObjectID              obj;

                acc.clear ();
                if (LXx_FAIL (Spawn (&obj)))
                        return false;

                return acc.take (obj);
        }
                bool
        Test (
                LXtMarkMode              mode)
        {
                return (TestMarks (mode) == LXe_TRUE);
        }
                LxResult
        Enum (
                CLxImpl_AbstractVisitor *visitor,
                LXtMarkMode              mode = LXiMARK_ANY,
                ILxUnknownID             mon  = 0)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;

                gv.loc.vis = visitor;
                return Enumerate (mode, gv, mon);
        }
};
class CLxUser_Edge : public CLxLoc_Edge
{
    public:
        CLxUser_Edge () {}
        CLxUser_Edge (ILxUnknownID obj) : CLxLoc_Edge (obj) {}

        CLxUser_Edge (
                CLxLoc_Mesh             &mesh)
        {
                _init ();
                fromMesh (mesh);
        }

                bool
        fromMesh (
                CLxLoc_Mesh             &mesh)
        {
                LXtObjectID              acc;

                clear ();
                if (mesh.test () && LXx_OK (mesh.EdgeAccessor (&acc)))
                        return take (acc);

                return false;
        }

                bool
        fromMeshObj (
                ILxUnknownID             obj)
        {
                CLxLoc_Mesh              mesh (obj);
                LXtObjectID              acc;

                clear ();
                if (mesh.test () && LXx_OK (mesh.EdgeAccessor (&acc)))
                        return take (acc);

                return false;
        }

                bool
        duplicate (
                CLxLoc_Edge               &acc)
        {
                LXtObjectID              obj;

                acc.clear ();
                if (LXx_FAIL (Spawn (&obj)))
                        return false;

                return acc.take (obj);
        }
                bool
        Test (
                LXtMarkMode              mode)
        {
                return (TestMarks (mode) == LXe_TRUE);
        }
                LxResult
        Enum (
                CLxImpl_AbstractVisitor *visitor,
                LXtMarkMode              mode = LXiMARK_ANY,
                ILxUnknownID             mon  = 0)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;

                gv.loc.vis = visitor;
                return Enumerate (mode, gv, mon);
        }
};
class CLxUser_MeshMap : public CLxLoc_MeshMap
{
    public:
        CLxUser_MeshMap () {}
        CLxUser_MeshMap (ILxUnknownID obj) : CLxLoc_MeshMap (obj) {}

        CLxUser_MeshMap (
                CLxLoc_Mesh             &mesh)
        {
                _init ();
                fromMesh (mesh);
        }

                bool
        fromMesh (
                CLxLoc_Mesh             &mesh)
        {
                LXtObjectID              acc;

                clear ();
                if (mesh.test () && LXx_OK (mesh.MeshMapAccessor (&acc)))
                        return take (acc);

                return false;
        }

                bool
        fromMeshObj (
                ILxUnknownID             obj)
        {
                CLxLoc_Mesh              mesh (obj);
                LXtObjectID              acc;

                clear ();
                if (mesh.test () && LXx_OK (mesh.MeshMapAccessor (&acc)))
                        return take (acc);

                return false;
        }

                bool
        duplicate (
                CLxLoc_MeshMap               &acc)
        {
                LXtObjectID              obj;

                acc.clear ();
                if (LXx_FAIL (Spawn (&obj)))
                        return false;

                return acc.take (obj);
        }
                LxResult
        Enum (
                CLxImpl_AbstractVisitor *visitor,
                LXtMarkMode              mode = LXiMARK_ANY,
                ILxUnknownID             mon  = 0)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;

                gv.loc.vis = visitor;
                return Enumerate (mode, gv, mon);
        }
                LxResult
        EnumContents (
                CLxImpl_AbstractVisitor *visitor,
                CLxLoc_Point            &point)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;

                gv.loc.vis = visitor;
                return EnumerateContinuous (gv, point);
        }

                LxResult
        EnumContents (
                CLxImpl_AbstractVisitor *visitor,
                CLxLoc_Point            &point,
                CLxLoc_Polygon          &poly)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;

                gv.loc.vis = visitor;
                return EnumerateDiscontinuous (gv, point, poly);
        }

                LxResult
        EnumContents (
                CLxImpl_AbstractVisitor *visitor,
                CLxLoc_Edge             &edge)
        {
                CLxInst_OneVisitor<CLxGenericVisitor>  gv;

                gv.loc.vis = visitor;
                return EnumerateEdges (gv, edge);
        }
};
class CLxUser_MeshFilter : public CLxLoc_MeshFilter
{
    public:
        CLxUser_MeshFilter () {}
        CLxUser_MeshFilter (ILxUnknownID obj) : CLxLoc_MeshFilter (obj) {}

                bool
        GetMesh (
                CLxLoc_Mesh             &mesh)
        {
                return Generate (mesh);
        }
};
class CLxUser_MeshFilterBBox : public CLxLoc_MeshFilterBBox
{
    public:
        CLxUser_MeshFilterBBox () {}
        CLxUser_MeshFilterBBox (ILxUnknownID obj) : CLxLoc_MeshFilterBBox (obj) {}


};
class CLxUser_MeshService : public CLxLoc_MeshService
{
    public:
                LXtMarkMode
        SetMode (
                const char              *set)
        {
                LXtMarkMode              mode;

                ModeCompose (set, 0, &mode);
                return mode;
        }

                LXtMarkMode
        ClearMode (
                const char              *clr)
        {
                LXtMarkMode              mode;

                ModeCompose (0, clr, &mode);
                return mode;
        }
                bool
        NewMesh (
                CLxLoc_Mesh             &mesh)
        {
                return CreateMesh (mesh);
        }
};



#endif

