/*
 * COLLADAio library for Scene I/O
 *
 * Copyright (c) 2008-2011 Luxology LLC
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
 */

#include "cio_math.h"

#include <math.h>

namespace cio {

namespace math {

/*
 * ---------------------------------------------------------------------------
 * Vector and matrix operations.
 */
        void
Vector3Copy (
        Vector3			&dst,
        const Vector3		&src)
{
        for (unsigned index = 0; index < ND; ++index) {
                dst[index] = src[index];
        }
}

/*
 * Rescale the input vector to be unit length.  Return zero if the vector
 * is of length zero and cannot be rescaled.
 */
        bool
Normalize (Vector3	&vec)
{
        bool		 normalized(false);
        double		 x;

        x = VDOT (vec, vec);
        if (x > 0.0) {
                x = 1.0 / sqrt (x);
                VSCL (vec, x);
                normalized = true;
        }

        return normalized;
}

        void
Vector4Copy (
        Vector4			&dst,
        const Vector4		&src)
{
        for (unsigned index = 0; index < 4; ++index) {
                dst[index] = src[index];
        }
}

        void
Matrix3Copy (
        Matrix3			 dst,
        const Matrix3		&src)
{
        int			 i;

        for (i = 0; i < ND; i++)
                VCPY (dst[i], src[i]);
}

        void
Matrix3Identity (
        Matrix3			&m)
{
        m[0][0] = m[1][1] = m[2][2] = 1.0;
        m[0][1] = m[0][2] = 0.0;
        m[1][0] = m[1][2] = 0.0;
        m[2][0] = m[2][1] = 0.0;
}

        void
Matrix3Compose (
        Matrix3			&m,
        const Matrix3		&a)
{
        Matrix3			 tmp;
        int			 i, j, k;

        for (i = 0; i < ND; i++)
                VCLR (tmp[i]);

        for (i = 0; i < ND; i++)
                for (j = 0; j < ND; j++)
                        for (k = 0; k < ND; k++)
                                tmp[i][j] += m[k][j] * a[i][k];

        for (i = 0; i < ND; i++)
                VCPY (m[i], tmp[i]);
}

        void
Matrix3Multiply (
        Vector3			 r,
        const Matrix3		 m,
        const Vector3		 x)
{
        int			 i, j;
        double			 d;

        for (i = 0; i < ND; i++) {
                d = 0.0;
                for (j = 0; j < ND; j++)
                        d += x[j] * m[i][j];
                r[i] = d;
        }
}

        void
Matrix4Copy (
        Matrix4			 dst,
        const Matrix4		&src)
{
        int			 i, j;

        for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                        dst[i][j] = src[i][j];
}

        void
Matrix4Identity (
        Matrix4			&m)
{
        m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0;
        m[0][1] = m[0][2] = m[0][3] = 0.0;
        m[1][0] = m[1][2] = m[1][3] = 0.0;
        m[2][0] = m[2][1] = m[2][3] = 0.0;
        m[3][0] = m[3][1] = m[3][2] = 0.0;
}

        void
Matrix4CreateTranslation (
        Matrix4			&m,
        const Vector3		&v)
{
        Matrix4Identity (m);

        m[3][0] = v[0];
        m[3][1] = v[1];
        m[3][2] = v[2];
}

        void
Matrix4CreateRotation (
        Matrix4			&m,
        const double		 angle,
        const int		 axis)
{
        double			 s, c;

        Matrix4Identity (m);
        if (angle == 0.0)
                return;
        s = sin (angle);
        c = cos (angle);

        switch (axis) {
                case 0:		// x rotation
                        m[1][2] =  s;
                        m[2][1] = -s;
                        m[1][1] = m[2][2] = c;
                        break;

                case 1:		// y rotation
                        m[0][2] = -s;
                        m[2][0] =  s;
                        m[0][0] = m[2][2] = c;
                        break;

                case 2:		// z rotation
                        m[0][1] =  s;
                        m[1][0] = -s;
                        m[0][0] = m[1][1] = c;
                        break;
        }
}

        void
Matrix4CreateScale (
        Matrix4			&m,
        const Vector3		&s)
{
        Matrix4Identity (m);

        m[0][0] = s[0];
        m[1][1] = s[1];
        m[2][2] = s[2];
}

        void
Matrix4Compose (
        Matrix4			&m,
        const Matrix4		&a)
{
        Matrix4			 tmp;
        int			 i, j, k;

        for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                        tmp[i][j] = 0.0;

        for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                        for (k = 0; k < 4; k++)
                                tmp[i][j] += m[i][k] * a[k][j];

        Matrix4Copy (m, tmp);
}

        void
Matrix4GetSubMatrix (
        Matrix3			&m3,
        const Matrix4		&m4,
        bool			 transpose)
{
        int			 i, j;

        for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                        m3[i][j] = m4[i][j];

        if (transpose)
                MatrixTranspose (m3);
}

        void
MatrixTranspose (
        Matrix3			&m)
{
        double			 t;

        t       = m[0][1];
        m[0][1] = m[1][0];
        m[1][0] = t;

        t       = m[2][1];
        m[2][1] = m[1][2];
        m[1][2] = t;

        t       = m[0][2];
        m[0][2] = m[2][0];
        m[2][0] = t;
}

        static bool
ValidAxis (Axis axis)
{
        return (axis >= AXIS_X && axis <= AXIS_Z);
}

        bool
MatrixRotate (
        Matrix3			&m,
        double			 angle,
        Axis			 axis)
{
        bool			 rotated(false);
        static const int	 axis0[] = { 1, 2, 0 };
        static const int	 axis1[] = { 2, 0, 1 };
        Matrix3			 rot;
        double			 s;
        int			 a, b;

        if (angle != 0.0 && ValidAxis (axis)) {
                a = axis0[axis];
                b = axis1[axis];

                Matrix3Identity (rot);

                s = sin (angle);
                rot[a][b] = -s;
                rot[b][a] =  s;
                rot[a][a] = rot[b][b] = cos (angle);
                Matrix3Compose (m, rot);
                rotated = true;
        }

        return rotated;
}

/*
 * Create a rotation matrix for spinning around an arbitrary axis by the given
 * angle.  Note: The rotation axis must be normalized.
 */
        void
MatrixAxisRotation (
        Matrix3			&m,
        const Vector3		 axis,
        double			 angle)
{
        MatrixAxisRotation (m, axis, sin (angle), cos (angle));
}

/*
 * Compute a new matrix that encodes a rotation about an arbitrary axis.
 * The axis is given as a unit vector, and the angle is specified by the
 * sine and cosine of the angle.  The angle specification may seem odd,
 * but there are times when the sine and cosine are known directly but
 * the angle would have to be back-computed.
 *
 * Note: The rotation axis vector must be normalized.
 */
        void
MatrixAxisRotation (
        Matrix3			&m,
        const Vector3		 a,
        double			 s,
        double			 c)
{
        double			 t;

        t = 1.0 - c;
        m[0][0] = t * a[0] * a[0] + c;
        m[0][1] = t * a[0] * a[1] - s * a[2];
        m[0][2] = t * a[0] * a[2] + s * a[1];
        m[1][0] = t * a[1] * a[0] + s * a[2];
        m[1][1] = t * a[1] * a[1] + c;
        m[1][2] = t * a[1] * a[2] - s * a[0];
        m[2][0] = t * a[2] * a[0] - s * a[1];
        m[2][1] = t * a[2] * a[1] + s * a[0];
        m[2][2] = t * a[2] * a[2] + c;
}

/*
 * Euler angles can be extracted from a matrix in any rotation order using the
 * following function.  The required rotation order is placed in the i, j, k
 * variables and the rotation angles are placed into 'eAngles'.
 */
        bool
MatrixToEuler (
        const Matrix3		&m,
        Axis			 i,
        Axis			 j,
        Axis			 k,
        Vector3			&eAngles)
{
        bool			 result(false);
        if (ValidAxis (i) && ValidAxis (j) && ValidAxis (k)) {
                double		 s = sqrt (m[i][i] * m[i][i] + m[j][i] * m[j][i]);

#ifndef DBL_EPSILON
                /*
                 * smallest such that 1.0+DBL_EPSILON != 1.0
                 */
                const double DBL_EPSILON     = 2.2204460492503131e-016;
#endif
                if (s > 16 * DBL_EPSILON) {

                        eAngles[0] = atan2 ( m[k][j], m[k][k]);
                        eAngles[1] = atan2 (-m[k][i], s);
                        eAngles[2] = atan2 ( m[j][i], m[i][i]);
                }
                else {

                        eAngles[0] = atan2 (-m[j][k], m[j][j]);
                        eAngles[1] = atan2 (-m[k][i], s);
                        eAngles[2] = 0.0;
                }

                /*
                 * Parity is even if the inner-axis X is followed by the middle-axis Y,
                 * or Y is followed by Z, or Z is followed by X.
                 */
                if ((i == 0 && j != 1) || (i == 1 && j != 2) || (i == 2 && j != 0)) {

                        /*
                         * Parity is odd.
                         */
                        eAngles[0] = -eAngles[0];
                        eAngles[1] = -eAngles[1];
                        eAngles[2] = -eAngles[2];
                }
                result = true;
        }

        return result;
}

        void
RotationAxisOrder (
        RotationOrder		 rotationOrder,
        AxisOrder		&axisOrder)
{
        static const Axis	 ROTORD[6][3] = {
                                         { AXIS_X, AXIS_Y, AXIS_Z },	// even
                                         { AXIS_X, AXIS_Z, AXIS_Y },	// odd
                                         { AXIS_Y, AXIS_X, AXIS_Z },	// odd
                                         { AXIS_Y, AXIS_Z, AXIS_X },	// even
                                         { AXIS_Z, AXIS_X, AXIS_Y },	// even
                                         { AXIS_Z, AXIS_Y, AXIS_X }};	// odd

        for (unsigned index = 0; index < ND; ++index) {
                axisOrder[index] = ROTORD[rotationOrder][index];
        }
}

/*
 * Return the length of the vector 'a'.
 */
#define VLEN(a)		sqrt (VDOT (a,a))


        static void
V3_Combine (
        Vector3			 a,
        Vector3			 b,
        Vector3			 r,
        double			 aScl,
        double			 bScl)
{
        r[0] = (aScl * a[0]) + (bScl * b[0]);
        r[1] = (aScl * a[1]) + (bScl * b[1]);
        r[2] = (aScl * a[2]) + (bScl * b[2]);
}

/*
 * After calling Matrix4Decompose with the matrix to be decomposed and the
 * required rotation order, the xformValues array will contain the individual
 * channel values which can then be accessed with the TransformValue enum.
 */
        bool
Matrix4Decompose (
        const Matrix4		&m4,
        double			 xformValues[TransformValue_Count],
        RotationOrder		 order)
{
        bool	decomposed(false);

        Matrix4		 m4Loc, m4p;
        Matrix3		 m3;
        Vector3		 r0, r1, r2, v, rot;
        int		 i, j;
        Axis		 ROTORD[6][3] = {{ AXIS_X, AXIS_Y, AXIS_Z },	// XYZ
                                         { AXIS_X, AXIS_Z, AXIS_Y },	// XZY
                                         { AXIS_Y, AXIS_X, AXIS_Z },	// YXZ
                                         { AXIS_Y, AXIS_Z, AXIS_X },	// YZX
                                         { AXIS_Z, AXIS_X, AXIS_Y },	// ZXY
                                         { AXIS_Z, AXIS_Y, AXIS_X }};	// ZYX

        if (m4[3][3] == 0)
                return false;
        
        Matrix4Copy (m4Loc, m4);
        
        for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                        m4Loc[i][j] /= m4Loc[3][3];

        Matrix4Copy (m4p, m4Loc);
        
        for (i= 0; i < 3; i++)
 		m4p[i][3] = 0;
                
 	m4p[3][3] = 1;
        
        // TODO - this function is also in Graphics Gems 4
        //if (det4x4 (m4p) == 0.0)
 	//	return 0;
        
        // don't deal with matricies that have perspective
        if (m4Loc[0][3] != 0 || m4Loc[1][3] != 0 || m4Loc[2][3] != 0)
                return false;
        
        // translation
 	for (i = 0; i < 3; i++) {
 		xformValues[TransformValue_TRANSX + i] = m4Loc[3][i];
 		m4Loc[3][i] = 0;
 	}
        
        r0[0] = m4Loc[0][0];
        r0[1] = m4Loc[0][1];
        r0[2] = m4Loc[0][2];
                
        r1[0] = m4Loc[1][0];
        r1[1] = m4Loc[1][1];
        r1[2] = m4Loc[1][2];
        
        r2[0] = m4Loc[2][0];
        r2[1] = m4Loc[2][1];
        r2[2] = m4Loc[2][2];
                
        // compute X scale factor and normalise first row
 	xformValues[TransformValue_SCALEX] = VLEN (r0);
 	Normalize (r0);

        // compute XY shear factor and make second row orthogonal to first
 	xformValues[TransformValue_SHEARXY] = VDOT (r0, r1);
 	V3_Combine (r1, r0, v, 1.0, -xformValues[TransformValue_SHEARXY]);
        VCPY (r1, v);
        
        // compute Y scale and normalise second row
 	xformValues[TransformValue_SCALEY] = VLEN (r1);
 	Normalize (r1);
 	xformValues[TransformValue_SHEARXY] /= xformValues[TransformValue_SCALEY];
        
 	// compute XZ and YZ shears, orthogonalise third row
 	xformValues[TransformValue_SHEARXZ] = VDOT (r0, r2);
 	V3_Combine (r2, r0, v, 1.0, -xformValues[TransformValue_SHEARXZ]);
        VCPY (r2, v);
 	xformValues[TransformValue_SHEARYZ] = VDOT (r1, r2);
 	V3_Combine (r2, r1, v, 1.0, -xformValues[TransformValue_SHEARYZ]);
        VCPY (r2, v);
        
 	// get Z scale and normalise third row
 	xformValues[TransformValue_SCALEZ] = VLEN (r2);
 	Normalize (r2);
 	xformValues[TransformValue_SHEARXZ] /= xformValues[TransformValue_SCALEZ];
 	xformValues[TransformValue_SHEARYZ] /= xformValues[TransformValue_SCALEZ];
        
 	// at this point the matrix (in r0, r1, r2) is orthonormal,
 	// check for a coordinate system flip, if the determinant
 	// is -1 then negate the matrix and the scaling factors

        VCROSS (v, r1, r2);
        if (VDOT (r0, v) < 0) {
                xformValues[TransformValue_SCALEX] *= -1;
                xformValues[TransformValue_SCALEY] *= -1;
                xformValues[TransformValue_SCALEZ] *= -1;
                
                r0[0] *= -1; r0[1] *= -1; r0[2] *= -1;
                r1[0] *= -1; r1[1] *= -1; r1[2] *= -1;
                r2[0] *= -1; r2[1] *= -1; r2[2] *= -1;
        }

        // build the transposed matrix for the MatrixToEuler() function
        m3[0][0] = r0[0];
        m3[1][0] = r0[1];
        m3[2][0] = r0[2];
        
        m3[0][1] = r1[0];
        m3[1][1] = r1[1];
        m3[2][1] = r1[2];
        
        m3[0][2] = r2[0];
        m3[1][2] = r2[1];
        m3[2][2] = r2[2];
        
        MatrixToEuler (m3, ROTORD[order][0], ROTORD[order][1], ROTORD[order][2], rot);
        
        // output in xyz order to match the defines - MatrixToEuler() really should do this
        // for consistency
        v[ROTORD[order][0]] = rot[0];
        v[ROTORD[order][1]] = rot[1];
        v[ROTORD[order][2]] = rot[2];
        
        xformValues[TransformValue_ROTATEX] = v[0];
        xformValues[TransformValue_ROTATEY] = v[1];
        xformValues[TransformValue_ROTATEZ] = v[2];
        
        decomposed = true;

        return decomposed;
}

/*
 * ---------------------------------------------------------------------------
 * Test axis planes.
 */

/*
 * Multiply the vector x by the matrix tax->m and place the result into r.
 */
        void
AxisTestMultiply (
        math::Vector3		&r,
        const TestAxis		&tax,
        const math::Vector3	&x)
{
        if (tax.flags & TESTAXISf_MATRIX) {
                Matrix3Multiply (r, tax.m, x);
        }
        else {
                VCPY (r, x);
        }
}

/*
 * Set a test axis plane for polygon calculations.
 * Takes the perpendicular axis and picks the other two in a nice way.
 */
        void
AxisTestSet (
        TestAxis		&tax,
        int			 axis)
{
        tax.axis = axis;
        AxisGetNormals (axis, &tax.ix, &tax.iy);
        Matrix3Identity (tax.m);
        Matrix3Identity (tax.mInv);
        tax.flags = 0;
}

/*
 * Set a plane given an extent.  Picks the largest two axes.
 */
        void
AxisTestSetFromExtent (
        TestAxis	&tax,
        const Vector3	&ext)
{
        AxisTestSet (tax, AxisMinExtent (ext));
}

/*
 * Return the axis (x=0, y=1, z=2) with the smallest absolute magnitude
 * relative to the others.
 */
        int
AxisMinExtent (
        const Vector3	 v)
{
        if (ABS(v[0]) < ABS(v[1]) && ABS(v[0]) < ABS(v[2]))
                return 0;
        else if (ABS(v[1]) <= ABS(v[0]) && ABS(v[1]) < ABS(v[2]))
                return 1;
        else
                return 2;
}

/*
 * Return the axis (x=0, y=1, z=2) with the largest absolute magnitude
 * relative to the others.
 */
        int
AxisMaxExtent (
        const Vector3	 v)
{
        if (ABS(v[0]) > ABS(v[1]) && ABS(v[0]) > ABS(v[2]))
                return 0;
        else if (ABS(v[1]) >= ABS(v[0]) && ABS(v[1]) > ABS(v[2]))
                return 1;
        else
                return 2;
}

/*
 * This function takes an axis as input and computes the two axes which are
 * orthogonal to that one.  The result is left-handed if the input axis is
 * treated as "az" in the triple.
 */
        void
AxisGetNormals (
        int			 axis,
        int			*ax,
        int			*ay)
{
        static const int	 axis0[] = { 1, 2, 0 };
        static const int	 axis1[] = { 2, 0, 1 };

        if (axis >= 0 && axis < ND) {
                *ax = axis0[axis];
                *ay = axis1[axis];
        }
}

} // namespace math

} // namespace cio

