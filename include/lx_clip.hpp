/*
 * Plug-in SDK Header: C++ User Classes
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
 */
#ifndef LXUSER_clip_HPP
#define LXUSER_clip_HPP

#include <lxw_clip.hpp>
#include <lxw_value.hpp>

class CLxUser_VideoClipItem : public CLxLoc_VideoClipItem
{
    public:
        CLxUser_VideoClipItem () {}
        CLxUser_VideoClipItem (ILxUnknownID obj) : CLxLoc_VideoClipItem (obj) {}

                bool
        GetFilter (
                CLxLoc_Attributes       &attr,
                void                    *cache,
                CLxLocalizedObject      &filter)
        {
                LXtObjectID              obj;

                if (LXx_OK (AllocFilter (attr, cache, &obj)))
                        return filter.take (obj);

                filter.clear ();
                return false;
        }
};




#endif
