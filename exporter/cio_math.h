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

#ifndef CIO_MATH_H
#define CIO_MATH_H

#include <vector>

namespace cio {

namespace math
{
        const double RAD2DEG = 57.295779513082320876798154814105;
        const double DEG2RAD = 0.017453292519943295769236907684886;

        /*
         * Max template function.
         */
        template <class T> T Max(T a, T b) {
                return (a > b) ? a: b;
        }

        /*
         * Min template function.
         */
        template <class T> T Min(T a, T b) {
                return (a < b) ? a: b;
        }

#ifndef ABS
        #define ABS(a)                 ((a) < 0 ? -(a) : (a))
#endif

        /*
         * Since vectors can have double and single precision forms, and since vector
         * operations are often small, repetitive mathematical calculations which are
         * highly amenable to optimization, most basic vector ops are coded as macros.
         * The macro form allows arguments to have mixed types, and the in-line code
         * thus generated should be about as fast as possible.  To make things easier
         * for the programmer, the macros are coded using the slightly confusing 'comma
         * operator' which allows the multiple assignments to be performed as a single
         * expression.  These macros can therefore be used as if they were single
         * atomic operations regardless of context.
         */

        #define VCLR(a)		 VSET(a,0.0)

        /*
         * ---------------------------------------------------------------------------
         * Binary Operations
         */

        #define VSET(a,x)	 ((a)[0]=(x), (a)[1]=(x), (a)[2]=(x))

        /*
         * Assign the vector 'a' to have the same value as the vector 'b'.
         */
        #define VCPY(a,b)	((a)[0] = (b)[0], (a)[1] = (b)[1], (a)[2] = (b)[2])

        /*
         * Return the dot product of vectors 'a' and 'b'.
         */
        #define VDOT(a,b)	((a)[0] * (b)[0] + (a)[1] * (b)[1] + (a)[2] * (b)[2])

        /*
         * Multiply the vector 'a' by the scalar 'x', storing the result in 'a'.
         */
        #define VSCL(a,x)	((a)[0] *= (x),   (a)[1] *= (x),   (a)[2] *= (x))

        /*
         * ---------------------------------------------------------------------------
         * Trinary Operations
         */

        /*
         * Add the vector 'b' to the vector 'a', storing the result in 'r'.
         */
        #define VADD3(r,a,b)	((r)[0]=(a)[0]+(b)[0], (r)[1]=(a)[1]+(b)[1], (r)[2]=(a)[2]+(b)[2])

        /*
         * Multiply the vector 'b' by the scalar 'x' and then add it to 'a'.
         * The result is stored in the vector 'r'.
         */
        #define VADDS3(r,a,b,x)	((r)[0]=(a)[0]+(b)[0]*(x), (r)[1]=(a)[1]+(b)[1]*(x), (r)[2]=(a)[2]+(b)[2]*(x))

        /*
         * Subtract the vector 'b' from the vector 'a', storing the result in 'r'.
         */
        #define VSUB3(r,a,b)	((r)[0]=(a)[0]-(b)[0], (r)[1]=(a)[1]-(b)[1], (r)[2]=(a)[2]-(b)[2])

        /*
         * Multiply the vector 'a' by the scalar 'x', storing the result in 'r'.
         */
        #define VSCL3(r,a,x)	((r)[0]=(a)[0]*(x),    (r)[1]=(a)[1]*(x),    (r)[2]=(a)[2]*(x))

        /*
         * Multiply the vector 'b' by the vector 'a'.
         * The result is stored in the vector 'r'.
         */
        #define VMUL3(r,a,b)	((r)[0]=(a)[0]*(b)[0], (r)[1]=(a)[1]*(b)[1], (r)[2]=(a)[2]*(b)[2])

        /*
         * General Vector Binary OPerator.  Perform the given operator on each
         * component of 'a' and 'b' as a pair, and store the result in 'r'.
         */
        #define VBOP3(r,a,b,op) ((r)[0]=op((a)[0],(b)[0]), (r)[1]=op((a)[1],(b)[1]), (r)[2]=op((a)[2],(b)[2]))

        /*
         * Compute the cross product 'a x b' and places the result in the vector 'r'.
         */
        #define VCROSS(r,a,b)	((r)[0] = (a)[1]*(b)[2] - (a)[2]*(b)[1],\
                                 (r)[1] = (a)[2]*(b)[0] - (a)[0]*(b)[2],\
                                 (r)[2] = (a)[0]*(b)[1] - (a)[1]*(b)[0])

        /*
         * ---------------------------------------------------------------------------
         * Vector and matrix operations.
         */

        /*
         * Number of Dimensions for a generic 3D vector.
         */
        #define ND		 3

        typedef double	Vector3[ND];
        typedef struct en_Vector3Wrap
        {
                Vector3	vec;
        } Vector3Wrap;
        typedef std::vector<Vector3Wrap>	Vector3Array;

        void		Vector3Copy (
                                Vector3		&dst,
                                const Vector3	&src);

        bool		Normalize (Vector3	&vec);

        typedef double	Vector4[4];
        typedef struct en_Vector4Wrap
        {
                Vector4	vec;
        } Vector4Wrap;
        typedef std::vector<Vector4Wrap>	Vector4Array;

        void		Vector4Copy (
                                Vector4		&dst,
                                const Vector4	&src);

        typedef double			Matrix3[ND][ND];
        typedef struct en_Matrix3Wrap
        {
                Matrix3	m;
        } Matrix3Wrap;
        typedef std::vector<Matrix3Wrap>	Matrix3Array;

        void		Matrix3Copy (
                                Matrix3		 dst,
                                const Matrix3	&src);

        void		Matrix3Identity (Matrix3 &m);

        void		Matrix3Compose (
                                Matrix3		&m,
                                const Matrix3	&a);

        void		Matrix3Multiply (
                                Vector3		 r,
                                const Matrix3	 m,
                                const Vector3	 x);

        /*
        * The 4x4 matrix type combines a 3x3 rotation matrix in the upper left
        * corner with a translation vector in the bottom row. The matrix is
        * transposed compared to the 3x3 matrix above. This is to provide
        * compatiblity with other application SDKs (Maya, XSI, Max) allowing
        * our matrices to be used directly and to allow concatentation of
        * matrices to be simplified, the order in which the matrices are
        * multiplied is the order in which they occur.
        *
        * Matrix operations are applied on the right, e.g., multiplying a
        * vector by a matrix is performed as v * m, treating v as a row vector.
        */
        typedef double			Matrix4[4][4];
        typedef struct en_Matrix4Wrap
        {
                Matrix4		m;
        } Matrix4Wrap;
        typedef std::vector<Matrix4Wrap>	Matrix4Array;

        void		Matrix4Copy (
                                Matrix4		 dst,
                                const Matrix4	&src);

        void		Matrix4Identity (
                                Matrix4		&m);

        void		Matrix4CreateTranslation (
                                Matrix4		&m,
                                const Vector3	&v);

        void		Matrix4CreateRotation (
                                Matrix4		&m,
                                const double	 angle,
                                const int	 axis);

        void		Matrix4CreateScale (
                                Matrix4		&m,
                                const Vector3	&s);

        void		Matrix4Compose (
                                Matrix4		&m,
                                const Matrix4	&a);

        void		Matrix4GetSubMatrix (
                                Matrix3		&m3,
                                const Matrix4	&m4,
                                bool		 transpose);

        void		MatrixTranspose (
                                Matrix3		&m);

        typedef enum en_Axis
        {
                AXIS_X,
                AXIS_Y,
                AXIS_Z
        } Axis;

        typedef Axis			AxisOrder[ND];
        typedef std::vector<Axis>	AxisArray;

        bool		MatrixRotate (
                                Matrix3		&m,
                                double		 angle,
                                Axis		 axis);

        void		MatrixAxisRotation (
                                Matrix3		&m,
                                const Vector3	 axis,
                                double		 angle);

        void		MatrixAxisRotation (
                                Matrix3		&m,
                                const Vector3	 axis,
                                double		 s,
                                double		 c);

        bool		MatrixToEuler (
                                const Matrix3	&m,
                                Axis		 i,
                                Axis		 j,
                                Axis		 k,
                                Vector3		&eAngles);

        typedef enum en_RotationOrder
        {
                ROTATION_ORDER_XYZ,
                ROTATION_ORDER_XZY,
                ROTATION_ORDER_YXZ,
                ROTATION_ORDER_YZX,
                ROTATION_ORDER_ZXY,
                ROTATION_ORDER_ZYX
        } RotationOrder;

        void		RotationAxisOrder (
                                RotationOrder	 rotationOrder,
                                AxisOrder	&axisOrder);

        typedef enum en_TransformValue
        {
         	TransformValue_SCALEX,
         	TransformValue_SCALEY,
         	TransformValue_SCALEZ,
         	TransformValue_SHEARXY,
         	TransformValue_SHEARXZ,
         	TransformValue_SHEARYZ,
         	TransformValue_ROTATEX,
         	TransformValue_ROTATEY,
         	TransformValue_ROTATEZ,
         	TransformValue_TRANSX,
         	TransformValue_TRANSY,
         	TransformValue_TRANSZ,
                TransformValue_Count
        } TransformValue;

        bool		Matrix4Decompose (
                                const Matrix4	&m4,
                                double		 xformValues[TransformValue_Count],
                                RotationOrder	 order);

        /*
         * -------------------------------------------------------------------
         * Test axis planes.
         */

        /*
         * TestAxis struct for planar tests.
         *
         *	axis	the axis number (0-2; x, y, or z)
         *	ix, iy	the two other orthogonal axes.
         *	m	the rotation matrix to transform the postion to the axis plane.
         *	mInv	the inverse matrix for the 'm' matrix.
         *	flags	If 'flags' is 0, the axis is one of the major axes; other
         *              possible flags are TESTAXISf_MATRIX and TESTAXISf_INVERSE.
         */

        #define TESTAXISf_MATRIX        1
        #define TESTAXISf_INVERSE       2

        typedef struct st_TestAxis
        {
                int		 axis;
                int		 ix;
                int		 iy;
                int		 flags;
                Matrix3		 m;
                Matrix3		 mInv;
        } TestAxis;

        void		AxisTestMultiply (
                                Vector3		&r,
                                const TestAxis	&tax,
                                const Vector3	&x);

        void		AxisTestSet (
                                TestAxis	&tax,
                                int		 axis);

        void		AxisTestSetFromExtent (
                                TestAxis	&tax,
                                const Vector3	&ext);

        int		AxisMinExtent (
                                const Vector3	 v);

        int		AxisMaxExtent (
                                const Vector3	 v);

        void		AxisGetNormals (
                                int		 axis,
                                int		*ax,
                                int		*ay);

} // namespace math

} // namespace cio

#endif // CIO_MATH_H

