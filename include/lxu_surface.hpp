/*
 * Plug-in SDK Header: C++ Services
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
 * Wrapper for accessing surface items.
 */
#ifndef LX_SURFACE_HPP
#define LX_SURFACE_HPP

#include <lx_surface.hpp>
#include <lx_tableau.hpp>


/*
 * ----------------------------------------------------------------
 * CLxSurfaceVistor allows a client to sample surfaces to get triangles and quads.
 */
class CLxSurfaceVisitor
{
    public:
                         CLxSurfaceVisitor ();
        virtual		~CLxSurfaceVisitor ();

        virtual bool	 TestFeature  (LXtID4 type, const char *name)
                                        { return false; }
        virtual bool	 TestBox      (LXtBBox *box)
                                        { return true; }
        virtual bool	 StartBin     (CLxUser_SurfaceBin &bin)
                                        { return true; }
        virtual bool	 StartSegment (unsigned int segID, unsigned int type)
                                        { return true; }
        virtual void	 Vertex       (const float *vertex, unsigned int index)
                                        {}
        virtual void	 Triangle     (unsigned int v0, unsigned int v1, unsigned int v2)
                                        {}
        virtual void	 Quad         (unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3)
                                        {}

        void		 EnableExceptions (bool state);
        void		 AllowQuads (bool state);
        void		 VisitFeatures (bool state);
        void		 SetSampleRate (float rate);

        LxResult	 SetSurface (ILxUnknownID surf);
        LxResult	 DefaultFeatures ();
        CLxUser_TableauVertex &
                         Features ();

        LxResult	 Sample ();

        class pv_SurfaceVisitor	*pv;
};



#endif	/* LX_SURFACE_HPP */

