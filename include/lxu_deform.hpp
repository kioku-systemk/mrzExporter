/*
 * Plug-in SDK Header: Deformation Wrapper Classes
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
 *
 * Provides wrapper classes for creating deformation, fallof and influence
 * objects in C++ plug-ins.
 */
#ifndef LXU_DEFORM_HPP
#define LXU_DEFORM_HPP

#include <lx_deform.hpp>
#include <lx_mesh.hpp>


/*
 * ----------------------------------------------------
 * Mesh Influence
 *
 * A mesh influence is used to perform deformations over a mesh. A mesh
 * influence consists of three things:
 *
 *	- a subset of vertices. This is given either by vertex marking or
 *	  by vertex map membership.
 *
 *	- an offset at each vertex. This is how the vertex should move in
 *	  object space. There may also be an optional transform which is
 *	  how it should move and rotate.
 *
 *	- an optional weight. Weighting vertices allows the influence to
 *	  fade smoothly at the edges. Influences without weights are assumed
 *	  to have a weight of 1.0 everywhere.
 *
 * The CLxMeshInfluence class is subclassed by the client, and the virtual
 * functions define the features of the influence.
 */
class CLxMeshInfluence
{
    public:
                                 CLxMeshInfluence ();
        virtual			~CLxMeshInfluence ();

        /*
         * These methods define gross features of the influence -- whether
         * it supports non-unity weights (default false), whether it has
         * per-vertex offsets (default true), and whether it supports
         * rotational or scaling transforms in addition to offsets (false).
         */
        virtual bool		 HasWeight () { return false; }
        virtual bool		 HasOffset () { return true; }

        /*
         * Return false if the influence is disabled and has no effect.
         */
        virtual bool		 IsEnabled () { return true; }

        /*
         * Traversal over the mesh is done either by point marking or by vertex
         * map. SelectMap() is called to select the vertex map for traversal.
         * If this returns false (the default) then MarkMode() is called to
         * mark vertices on the mesh and return the mark mode. SetXfrm() is called
         * with the world transform of the target mesh.
         */
        virtual bool		 SelectMap (CLxUser_Mesh &, CLxUser_MeshMap &) { return false; }
        virtual LXtMarkMode	 MarkMode (CLxUser_Mesh &, CLxUser_Point &) { return LXiMARK_ANY; }
        virtual void		 WorldXfrm (LXtMatrix4 xfrm) {}
        virtual void		 SourceItem (CLxUser_Item &) {}

        /*
         * During traversal these methods are called to get the offset, and the
         * optional weight of a given point.
         */
        virtual void		 Offset (CLxUser_Point &, float, LXtFVector) {}
        virtual float		 Weight (CLxUser_Point &) { return 1.0; }

        /*
         * Spawn() is called by the client to get a COM-object version of this
         * object.
         */
        void		 Spawn (void **ppvObj);

        class pv_MeshInfluence	*pv;
};



/*
 * ----------------------------------------------------
 * Falloff
 *
 * A falloff defines a scalar field defined in world space which can be sampled
 * in a variety of ways.
 */
namespace lx {

        /*
         * This templated function can be used to implement WeightRun()
         * using any suitable GetWeight() method. This has the potential to in-line
         * and vectorize.
         */
                template <class T>
                LxResult
        WeightRun (
                T			*that,
                const float	       **pos,
                float			*weight,
                unsigned		 count)
        {
                const float		*fx, *fy, *fz;

                fx = pos[0];
                fy = pos[1];
                fz = pos[2];
                for (int i = 0; i < count; i++) {
                        LXtFVector		 v;

                        LXx_VSET3 (v, fx[i], fy[i], fz[i]);
                        weight[i] = that->GetWeight (v);
                }

                return LXe_OK;
        }

};

/*
 * The constructor for this class can be called to create a spawner for a falloff
 * implementation class:
 *
 *	initialize ()
 *	{
 *		CLxSpawner_Falloff<MyFalloff> ("myfalloffname");
 *	}
 */
template <class T>
class CLxSpawner_Falloff
{
    public:
        CLxSpawner_Falloff (
                const char		*spname)
        {
                CLxSpawnerCreate<T>	 sc (spname);

                if (sc.created)
                        sc.spawn->AddInterface (new CLxIfc_Falloff<T>);
        }
};



/*
 * ----------------------------------------------------
 * Deformation
 *
 * A deformation specifies a vector field defined in world space which can be sampled
 * in doubles or floats.
 *
 * The constructor for this class can be called to create a spawner for a deformation
 * implementation class:
 *
 *	initialize ()
 *	{
 *		CLxSpawner_Deformation<MyDeformation> ("myDeformationName");
 *	}
 */
template <class T>
class CLxSpawner_Deformation
{
    public:
        CLxSpawner_Deformation (
                const char		*spname)
        {
                CLxSpawnerCreate<T>	 sc (spname);

                if (sc.created)
                        sc.spawn->AddInterface (new CLxIfc_Deformation<T>);
        }
};

#endif // LXU_DEFORM_HPP

