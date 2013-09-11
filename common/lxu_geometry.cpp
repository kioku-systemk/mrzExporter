/*
 * Plug-in SDK Source: Geometry Utilities
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
 *
 * Provides geometry utility functions for C++ plug-ins.
 */
#include <lxu_geometry.hpp>

#include <math.h>

using namespace std;

/*
 * Generate vertex normals for a triangle list,
 * with normal smoothing for shared vertices.
 */
        void
GenerateNormals (
        vector<Point>		&points,
        vector<unsigned>	&triangles,
        vector<Point>		&normals)
{
        /*
         * Zero out the normals array.
         */
        normals.clear ();
        Point	zeroVec;
        LXx_VCLR (zeroVec.vec);
        for (unsigned pointIndex = 0; pointIndex < points.size (); ++pointIndex) {
                normals.push_back (zeroVec);
        }

        const double MIN_VECTOR_LENGTH = 1e-20;

        for (unsigned triIndex = 0; triIndex < triangles.size (); triIndex += 3) {
                /*
                 * Fetch the points indexed by the triangle.
                 */
                unsigned pi0 = triangles[triIndex + 0];
                unsigned pi1 = triangles[triIndex + 1];
                unsigned pi2 = triangles[triIndex + 2];

                Point    *p0 = &points[pi0];
                Point    *p1 = &points[pi1];
                Point    *p2 = &points[pi2];

                /*
                 * Compute the face normal.
                 */
                LXtVector	 edge1, edge2, normal;
                LXx_VSUB3 (edge1, p1->vec, p0->vec);
                LXx_VSUB3 (edge2, p2->vec, p0->vec);
                LXx_VCROSS (normal, edge1, edge2);

                /*
                 * Normalize it.
                 */
                double      mag = LXx_VLEN (normal);
                if (mag < MIN_VECTOR_LENGTH) {
                        /*
                         * For normals with a length too close to zero,
                         * make a valid normal to avoid problems.
                         */
                        LXx_VSET3 (normal, 1.0, 0.0, 0.0);
                }
                else {
                        double      invMag = 1.0 / mag;
                        LXx_VSCL (normal, invMag);
                }

                /*
                 * Accumulate the normals at vertices shared by
                 * more than one face.
                 */
                Point    *n0 = &normals[pi0];
                Point    *n1 = &normals[pi1];
                Point    *n2 = &normals[pi2];

                LXx_VADD (n0->vec, normal);
                LXx_VADD (n1->vec, normal);
                LXx_VADD (n2->vec, normal);
        }

        /*
         * Normalize the normal vectors.
         */
        for (unsigned normalIndex = 0; normalIndex < normals.size (); ++normalIndex) {
                double      mag = LXx_VLEN (normals[normalIndex].vec);
                if (mag < MIN_VECTOR_LENGTH) {
                        /*
                         * For normals with a length too close to zero,
                         * make a valid normal to avoid problems.
                         */
                        LXx_VSET3 (normals[normalIndex].vec, 1.0, 0.0, 0.0);
                }
                else {
                        double      invMag = 1.0 / mag;
                        LXx_VSCL (normals[normalIndex].vec, invMag);
                }
        }
}

/*
 * Compute the UV gradient, which is the derivative of the world position with
 * respect to U and V. The caller provides the world position of three corners
 * of a triangle, and their corresponding UV coordinates, and the results are
 * returned in dPdU and dPdV. The function returns false if the triangle was
 * degenerate.
 */
        static bool
UVGradient (
        const LXtVector		 wp0,
        const LXtVector		 wp1,
        const LXtVector		 wp2,
        const LXtFVector2	 uv0,
        const LXtFVector2	 uv1,
        const LXtFVector2	 uv2,
        LXtVector		&dPdU,
        LXtVector		&dPdV)
{
        double			 du1, du2, dv1, dv2, determinant;
        LXtVector		 dp1, dp2;
        int			 i;

        du1 = uv0[0] - uv2[0];
        du2 = uv1[0] - uv2[0];
        dv1 = uv0[1] - uv2[1];
        dv2 = uv1[1] - uv2[1];

        LXx_VSUB3 (dp1, wp0, wp2);
        LXx_VSUB3 (dp2, wp1, wp2);

        determinant = du1 * dv2 - dv1 * du2;
        if (determinant == 0.0)
                return false;

        for (i = 0; i < 3; i++) {
                dPdU[i] = ( dv2 * dp1[i] - dv1 * dp2[i]) / determinant;
                dPdV[i] = (-du2 * dp1[i] + du1 * dp2[i]) / determinant;
        }
        return true;
}

/*
 * Generate vertex dPdu/dPdv values, with smoothing for shared vertices.
 */
        void
GenerateDPDUs (
        vector<Point>		&points,
        vector<UV>		&uvs,
        vector<unsigned>	&triangles,
        vector<Point>		&dPdus,
        vector<Point>		&dPdvs)
{
        /*
         * Zero out the dPdu arrays.
         */
        dPdus.clear ();
        dPdvs.clear ();
        Point	zeroVec;
        LXx_VCLR (zeroVec.vec);
        unsigned pointIndex;
        for (pointIndex = 0; pointIndex < points.size (); ++pointIndex) {
                dPdus.push_back (zeroVec);
                dPdvs.push_back (zeroVec);
        }

        /*
         * Zero out the point reference counts.
         */
        vector<unsigned>	refCounts;
        for (pointIndex = 0; pointIndex < points.size (); ++pointIndex) {
                refCounts.push_back (0);
        }

        for (unsigned triIndex = 0; triIndex < triangles.size (); triIndex += 3) {
                /*
                 * Fetch the points indexed by the triangle.
                 */
                unsigned pi0 = triangles[triIndex + 0];
                unsigned pi1 = triangles[triIndex + 1];
                unsigned pi2 = triangles[triIndex + 2];

                /*
                 * Fetch the points indexed by the triangle.
                 */
                Point    *p0 = &points[pi0];
                Point    *p1 = &points[pi1];
                Point    *p2 = &points[pi2];

                UV    *uv0 = &uvs[pi0];
                UV    *uv1 = &uvs[pi1];
                UV    *uv2 = &uvs[triangles[triIndex + 2]];

                LXtVector	dPdu, dPdv;
                if (!UVGradient (p0->vec, p1->vec, p2->vec,
                        uv0->uv, uv1->uv, uv2->uv, dPdu, dPdv)) {
                        dPdu[0] = dPdv[0] = 1.0;
                        dPdu[1] = dPdv[1] = dPdu[2] = dPdv[2] = 0.0;
                }

                refCounts[pi0]++;
                refCounts[pi1]++;
                refCounts[pi2]++;

                /*
                 * Accumulate the dPdus. Vertices shared by more than one
                 * face will be finalized in a second pass later on.
                 */
                Point    *dPdu0 = &dPdus[pi0];
                Point    *dPdu1 = &dPdus[pi1];
                Point    *dPdu2 = &dPdus[pi2];

                LXx_VADD (dPdu0->vec, dPdu);
                LXx_VADD (dPdu1->vec, dPdu);
                LXx_VADD (dPdu2->vec, dPdu);

                Point    *dPdv0 = &dPdvs[pi0];
                Point    *dPdv1 = &dPdvs[pi1];
                Point    *dPdv2 = &dPdvs[pi2];

                LXx_VADD (dPdv0->vec, dPdv);
                LXx_VADD (dPdv1->vec, dPdv);
                LXx_VADD (dPdv2->vec, dPdv);
        }

        /*
         * Finalize the averages for each dPdu/dPdv vector pair.
         */
        for (pointIndex = 0; pointIndex < points.size (); ++pointIndex) {
                unsigned refCount = refCounts[pointIndex];
                if (refCount > 1) {
                        Point    *dPdu = &dPdus[pointIndex];
                        Point    *dPdv = &dPdvs[pointIndex];

                        double invN = 1.0 / refCount;

                        LXx_VSCL (dPdu->vec, invN);
                        LXx_VSCL (dPdv->vec, invN);
                }
        }
}

