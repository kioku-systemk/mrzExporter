/*
 * Plug-in SDK Header: Math Utilities
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
 * Provides math utility functions for C++ plug-ins.
 */

#ifndef LXU_MATH_HPP
#define LXU_MATH_HPP

#include <math.h>
#include <lxvmath.h>


/*
 * ----------------------------------------------------------
 * "lx" namespace for utility functions.
 */
                namespace lx {


/*
 * IEEE floating point numbers actually store the results of irrational math
 * operations.  This function can be used to test a 32-bit float for weird
 * conditions.  It returns 0 for a valid number, -1 for an invalid number, and
 * +1 for infinity.
 */
        int
IEEEFloatTest (
        float			 val);


/*
 * Template for copying a 3x3 matrix.
 */
        template <class M>
        void
MatrixCopy (
        M			 dst,
        const M			 src)
{
        int			 i, j;

        for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                        dst[i][j] = src[i][j];
}


/*
 * Template for multiplying a vector times a matrix, in our unusual order.
 *
 *	r = m * x;
 */
        template <class M, class VIN, class VOUT>
        void
MatrixMultiply (
        VOUT			 r,
        const M			 m,
        const VIN		 x)
{
        int			 i, j;
        double			 d;

        for (i = 0; i < 3; i++) {
                d = 0.0;
                for (j = 0; j < 3; j++)
                        d += x[j] * m[i][j];

                r[i] = d;
        }
}


/*
 * Template for multiplying a matrix by another matrix.
 *
 *	M = M * X;
 */
        template <class M>
        void
MatrixMultiply (
        M			 m,
        const M			 x)
{
        LXtMatrix4		 tmp;
        int			 i, j, k;

        for (i = 0; i < 3; i++)
                LXx_VCLR (tmp[i]);

        for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                        for (k = 0; k < 3; k++)
                                tmp[i][j] += m[k][j] * x[i][k];

        for (i = 0; i < 3; i++)
                LXx_VCPY (m[i], tmp[i]);
}


/*
 * Template for copying a 4x4 matrix.
 */
        template <class M>
        void
Matrix4Copy (
        M			 dst,
        const M			 src)
{
        int			 i, j;

        for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                        dst[i][j] = src[i][j];
}


/*
 * Template for multiplying a 3-component vector times a 4x4 matrix. More
 * typical order this time.
 *
 *	r = m * x;
 */
        template <class M, class VIN, class VOUT>
        void
Matrix4Multiply (
        VOUT			 r,
        const M			 m,
        const VIN		 x)
{
        int			 i, j;
        double			 d, t[4];

        t[0] = x[0];
        t[1] = x[1];
        t[2] = x[2];
        t[3] = 1.0;
        for (i = 0; i < 3; i++) {
                d = 0.0;
                for (j = 0; j < 4; j++)
                        d += t[j] * m[j][i];

                r[i] = d;
        }
}


/*
 * Template for multiplying a 4x4 matrix by another matrix.
 *
 *	M = M * X;
 */
        template <class M>
        void
Matrix4Multiply (
        M			 m,
        const M			 x)
{
        LXtMatrix4		 tmp;
        int			 i, j, k;

        for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                        tmp[i][j] = 0.0;

        for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                        for (k = 0; k < 4; k++)
                                tmp[i][j] += m[i][k] * x[k][j];

        for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                        m[i][j] = tmp[i][j];
}


/*
 * Template to compute a new matrix that encodes a rotation about an arbitrary axis.
 * The angle is input as sine and cosine, which are sometimes easier to compute than
 * the actual angle.
 */
        template <class M, class V>
        void
MatrixAxisRotation (
        M			 m,
        V			 a,
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
 * Taking a value from zero to one, this returns a cubic smoothed version.
 */
        template <class F>
        F
Smooth (
        F			 a)
{
        return (3.0 - 2.0 * a) * a * a;
}

/*
 * Interpolate between four points using a cubic. p0, p1, p2, p3 are uniform
 * samples along a line. 'f' is the fraction between p1 and p2, from 0 to 1.
 */
        template <class F>
        F
CubicInterp (
        F			 p0,
        F			 p1,
        F			 p2,
        F			 p3,
        F			 f)
{
        F			 a0, a1, a2, a3;

        a0 =  p1;
        a1 = (-2.0 * p0 + p1 + 4.0 * p2 - p3) / 6.0;
        a2 = (p0 + p2) / 2.0 - p1;
        a3 = (-p0 - p1 - p2 + p3) / 6.0;

        return a0 + a1 * f + a2 * f * f + a3 * f * f * f;
}

                }; // END namespace lx


/*
 * Class for generating pseudo-random numbers of various types.
 */
class CLxPseudoRandom {
        static const int	 ARAND = 16807;
        static const int	 MRAND = 2147483647;
        static const int	 QRAND = 127773;
        static const int	 RRAND = 2836;
    public:
        int			 random_seed;

        CLxPseudoRandom (
                int		 seed)
        {
                random_seed = seed;
        }

        CLxPseudoRandom ()
        {
                random_seed = 3216913;
        }

                void
        seed (
                int		 seed)
        {
                random_seed = seed;
        }

        /*
         * Get a random number from 0.0 to just less than 1.0.
         */
                float
        uniform ()
        {
                int		 hi, lo, test;

                hi = random_seed / QRAND;
                lo = random_seed % QRAND;
                test = ARAND * lo - RRAND * hi;
                random_seed = (test > 0) ? test : test + MRAND;
                return static_cast<float>((random_seed * (1.0 / (float) MRAND)));
        }

        /*
         * Get a random number from zero to just less than 'n'.
         */
                float
        range (
                float		 n)
        {
                return uniform () * n;
        }

                int
        range (
                int		 n)
        {
                return uniform () * n;
        }

        /*
         * Get a random number from 'low' to just less than 'high'.
         */
                float
        range (
                float		 low,
                float		 high)
        {
                return low + range (high - low);
        }

                int
        range (
                int		 low,
                int		 high)
        {
                return low + range (high - low);
        }

        /*
         * Get a uniform random number centered on zero, from -1.0 to 1.0.
         */
                float
        centered ()
        {
                return uniform () * 2 - 1;
        }

        /*
         * Vary a base value by +/- delta.
         */
                float
        vary (
                float		 base,
                float		 delta)
        {
                return base + delta * centered ();
        }

        /*
         * Get a random number in an approximately normal (Gaussian)
         * distribution with stddev of 1.0.  (Box-Muller transform)
         */
                double
        normal ()
        {
                float		 u = centered ();
                float		 v = centered ();
                double		 r, c;

                r = u * u + v * v;
                if (r == 0 || r > 1)
                        return normal ();

                c = sqrt (-2.0 * log (r) / r);
                return u * c;
        }
};


#endif // LXU_MATH_HPP

