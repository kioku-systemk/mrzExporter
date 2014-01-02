/*
 * Plug-in SDK Source: Math Utilities
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
#include <lxu_math.hpp>

/*
 * IEEE floating point numbers actually store the results of irrational math
 * operations.  This function can be used to test a 32-bit float for weird
 * conditions.  It returns 0 for a valid number, -1 for an invalid number, and
 * +1 for infinity.
 */
        int
IEEEFloatTest (
        float			 val)
{
        /*
         * Testing IEEE floating point numbers means looking at the bit pattern for
         * wacky values.  If the exponent is 255 then the mantissa can be used to
         * discriminate between NAN values and infinite values.
         */
        unsigned int		 n, exp, mant;

        n = ((unsigned int *) &val) [0];
        exp = (n & 0x7F800000) >> 23;
        if (exp != 255)
                return 0;

        mant = (n & 0x007FFFFF);
        if (mant != 0)
                return -1;	// NAN
        else
                return +1;	// INFINITY
}

