/*
 * Plug-in SDK Header: Math Utilities
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
 * Templates for making ident matrices.
 */
        template <class M>
        void
MatrixIdent (
        M			 dst)
{
        int			 i, j;

        for (i = 0; i < 3; i++)
                for (j = 0; j < 3; j++)
                        dst[i][j] = (i == j ? 1.0 : 0.0);
}

        template <class M>
        void
Matrix4Ident (
        M			 dst)
{
        int			 i, j;

        for (i = 0; i < 4; i++)
                for (j = 0; j < 4; j++)
                        dst[i][j] = (i == j ? 1.0 : 0.0);
}


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

        for (i = 0; i < 3; i++)
        {
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
        for (i = 0; i < 3; i++)
        {
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

        CLxPseudoRandom ()
        {
                random_seed = 3216913;
        }

        CLxPseudoRandom (
                int		 seedInit)
        {
                seed (seedInit);
        }

                void
        seed (
                int		 seed)
        {
                random_seed = LXxMAX (1, seed);
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
                template<class T>
                T
        range (
                T		 n)
        {
                return (T)(uniform () * n);
        }

        /*
         * Get a random number from 'low' to just less than 'high'.
         */
                template<class T>
                T
        range (
                T		 low,
                T		 high)
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

        /*
         * Get a random integer in an approximately Poisson distribution
         * with a given lambda (average rate).
         *
         * For small lambda we use Knuth's iterative method. For large
         * numbers where interation takes too long and exp(-lambda) gets
         * too close to zero to be useful, we switch to a Gaussian
         * approximation.
         */
                unsigned
        poisson (
                double		 lambda)
        {
                double		 limit, p;
                int		 n;

                if (lambda > 60.0)
                {
                        n = (int) (lambda + sqrt (lambda) * normal ());
                        return (n > 0 ? n : 0);
                }

                limit = exp ( -lambda );
                p     = 1.0;
                n     = 0;

                while (limit > 0.0)	// prevents hangs on bad input
                {
                        p *= uniform ();
                        if (p < limit)
                                break;
                        n++;
                }
                return n;
        }

        /*
         * Generate a barycentric coordinate, which is just a vector where
         * the components are all 0-1 and sum to 1.
         */
                void
        barycentric (
                LXtVector	 b)
        {
                while (1)
                {
                        b[0] = uniform ();
                        b[1] = uniform ();
                        b[2] = 1.0 - b[0] - b[1];
                        if (b[2] >= 0.0)
                                return;
                }
        }

        /*
         * Get a random point in a unit sphere. This is done by generating
         * points in a cube until we get one inside the sphere. The square
         * of the vector length is returned, and cannot be zero.
         */
                double
        sphere (
                LXtVector	 p)
        {
                double		 r2;

                while (1)
                {
                        LXx_VSET3 (p, centered (), centered (), centered ());
                        r2 = LXx_VDOT (p, p);
                        if (r2 <= 1.0)
                                return r2;
                }
        }
};


/*
 * Class for generating Perlin-style smooth deterministic noise. This
 * implementation was adapted from code submitted to the FlipCode archive
 * by John Ratcliff, which was adapted from code by Ken Perlin.
 *
 * http://www.flipcode.com/archives/Perlin_Noise_Class.shtml
 */
template<class T>
class CLxPerlin
{
    public:

        CLxPerlin (
                int		 octaves = 4,
                T		 freq    = 1,
                T		 amp     = 1,
                int		 seed    = 94) 
        {
                mOctaves   = octaves;
                mFrequency = freq;
                mAmplitude = amp;

                init(seed);
        }

                T
        eval (
                T		 x)
        {
                return noise_1D(x);
        }

                T
        eval (
                T		 x,
                T		 y)
        {
                T		 vec[2];

                vec[0] = x;
                vec[1] = y;

                return noise_2D(vec);
        }

                T
        eval (
                T		 x,
                T		 y,
                T		 z)
        {
                T		 vec[3];

                vec[0] = x;
                vec[1] = y;
                vec[2] = z;

                return noise_3D(vec);
        }

                T
        eval (
                const LXtVector		 pos)
        {
                return eval (pos[0], pos[1], pos[2]);
        }

                T
        eval (
                const LXtFVector	 pos)
        {
                return eval (pos[0], pos[1], pos[2]);
        }

private:
        static const unsigned	 SAMPLE_SIZE	= 1024;
        static const unsigned	 N		= 0x1000;
        static const unsigned	 NP		= 12;   /* 2^N */
        static const unsigned	 NM		= 0xfff;
        static const unsigned	 B		= SAMPLE_SIZE;
        static const unsigned	 BM		= SAMPLE_SIZE - 1;

        int		 mOctaves;
        T		 mFrequency;
        T		 mAmplitude;

        int		 p [SAMPLE_SIZE + SAMPLE_SIZE + 2];
        T		 g3[SAMPLE_SIZE + SAMPLE_SIZE + 2][3];
        T		 g2[SAMPLE_SIZE + SAMPLE_SIZE + 2][2];
        T		 g1[SAMPLE_SIZE + SAMPLE_SIZE + 2];

                T
        noise_1D (
                T		 val)
        {
                T		 amp    = mAmplitude;
                T		 result = 0.0;

                val *= mFrequency;

                for( int i = 0; i < mOctaves; i++ )
                {
                        result += noise1(val) * amp;
                        val    *= 2.0;
                        amp    *= 0.5;
                }

                return result;
        }

                T
        noise_2D (
                T		 vec[2])
        {
                T		 amp    = mAmplitude;
                T		 result = 0.0;

                vec[0] *= mFrequency;
                vec[1] *= mFrequency;

                for( int i = 0; i < mOctaves; i++ )
                {
                        result += noise2(vec) * amp;
                        vec[0] *= 2.0;
                        vec[1] *= 2.0;
                        amp    *= 0.5;
                }

                return result;
        }

                T
        noise_3D (
                T		 vec[3])
        {
                T		 amp    = mAmplitude;
                T		 result = 0.0;

                vec[0] *= mFrequency;
                vec[1] *= mFrequency;
                vec[2] *= mFrequency;

                for( int i = 0; i < mOctaves; i++ )
                {
                        result += noise3(vec) * amp;
                        vec[0] *= 2.0;
                        vec[1] *= 2.0;
                        vec[2] *= 2.0;
                        amp    *= 0.5;
                }

                return result;
        }

                T
        s_curve (
                T		 t)
        {
                return t * t * (3.0 - 2.0 * t);
        }

                T
        lerp (
                T		 t,
                T		 a,
                T		 b)
        {
                return a + t * (b - a);
        }

                void
        setup (
                T		 t,
                int		&b0,
                int		&b1,
                T		&r0,
                T		&r1)
        {
                t += N;
                b0 = ((int) t) & BM;
                b1 = (b0 + 1)  & BM;
                r0 = t - (int)t;
                r1 = r0 - 1.0;
        }

                T
        at2 (
                T		 rx,
                T		 ry,
                int		 b)
        {
                return rx * g2[b][0] + ry * g2[b][1];
        }

                T
        at3 (
                T		 rx,
                T		 ry,
                T		 rz,
                int		 b)
        {
                return rx * g3[b][0] + ry * g3[b][1] + rz * g3[b][2];
        }

                T
        noise1 (
                T		 arg)
        {
                int		 bx0, bx1;
                T		 rx0, rx1, sx, u, v;

                setup(arg, bx0,bx1, rx0,rx1);

                sx = s_curve(rx0);

                u = rx0 * g1[ p[ bx0 ] ];
                v = rx1 * g1[ p[ bx1 ] ];

                return lerp(sx, u, v);
        }

                T
        noise2 (
                T		 vec[2])
        {
                int		 bx0, bx1, by0, by1, b00, b10, b01, b11;
                T		 rx0, rx1, ry0, ry1, sx, sy, a, b, u, v;
                int		 i, j;

                setup(vec[0],bx0,bx1,rx0,rx1);
                setup(vec[1],by0,by1,ry0,ry1);

                i = p[bx0];
                j = p[bx1];

                b00 = p[i + by0];
                b10 = p[j + by0];
                b01 = p[i + by1];
                b11 = p[j + by1];

                sx = s_curve(rx0);
                sy = s_curve(ry0);

                u = at2(rx0,ry0,b00);
                v = at2(rx1,ry0,b10);
                a = lerp(sx, u, v);

                u = at2(rx0,ry1,b01);
                v = at2(rx1,ry1,b11);
                b = lerp(sx, u, v);

                return lerp(sy, a, b);
        }

                T
        noise3 (
                T		 vec[3])
        {
                int		 bx0, bx1, by0, by1, bz0, bz1, b00, b10, b01, b11;
                T		 rx0, rx1, ry0, ry1, rz0, rz1, sy, sz, a, b, c, d, t, u, v;
                int		 i, j;

                setup(vec[0], bx0,bx1, rx0,rx1);
                setup(vec[1], by0,by1, ry0,ry1);
                setup(vec[2], bz0,bz1, rz0,rz1);

                i = p[ bx0 ];
                j = p[ bx1 ];

                b00 = p[ i + by0 ];
                b10 = p[ j + by0 ];
                b01 = p[ i + by1 ];
                b11 = p[ j + by1 ];

                t  = s_curve(rx0);
                sy = s_curve(ry0);
                sz = s_curve(rz0);

                u = at3(rx0,ry0,rz0,b00 + bz0);
                v = at3(rx1,ry0,rz0,b10 + bz0);
                a = lerp(t, u, v);

                u = at3(rx0,ry1,rz0,b01 + bz0);
                v = at3(rx1,ry1,rz0,b11 + bz0);
                b = lerp(t, u, v);

                c = lerp(sy, a, b);

                u = at3(rx0,ry0,rz1,b00 + bz1);
                v = at3(rx1,ry0,rz1,b10 + bz1);
                a = lerp(t, u, v);

                u = at3(rx0,ry1,rz1,b01 + bz1);
                v = at3(rx1,ry1,rz1,b11 + bz1);
                b = lerp(t, u, v);

                d = lerp(sy, a, b);

                return lerp(sz, c, d);
        }

                void
        normalize2 (
                T		 v[2])
        {
                T		 s;

                s = (T)sqrt(v[0] * v[0] + v[1] * v[1]);
                s = 1.0 / s;

                v[0] = v[0] * s;
                v[1] = v[1] * s;
        }

                void
        normalize3 (
                T		 v[3])
        {
                T		 s;

                s = (T)sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
                s = 1.0 / s;

                v[0] = v[0] * s;
                v[1] = v[1] * s;
                v[2] = v[2] * s;
        }

                void
        init (
                int		 seed)
        {
                CLxPseudoRandom	 psr (seed);
                int		 i, j, k;

                for (i = 0 ; i < B ; i++)
                {
                        p[i] = i;

                        g1[i] = psr.centered();

                        for (j = 0 ; j < 2 ; j++)
                                g2[i][j] = psr.centered();

                        normalize2(g2[i]);

                        for (j = 0 ; j < 3 ; j++)
                                g3[i][j] = psr.centered();

                        normalize3(g3[i]);
                }

                while (--i)
                {
                        j    = psr.range((int)B);
                        k    = p[i];
                        p[i] = p[j];
                        p[j] = k;
                }

                for (i = 0 ; i < B + 2 ; i++)
                {
                        p [B + i] = p[i];
                        g1[B + i] = g1[i];
                        for (j = 0 ; j < 2 ; j++)
                                g2[B + i][j] = g2[i][j];
                        for (j = 0 ; j < 3 ; j++)
                                g3[B + i][j] = g3[i][j];
                }
        }
};


#endif // LXU_MATH_HPP

