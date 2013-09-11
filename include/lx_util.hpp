/*
 * Plug-in SDK Header: C++ Wrapper Classes
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
 * General utilities that are used in the wrappers, not necessarily for
 * anything else.
 */
#ifndef LX_CWUTIL_HPP
#define LX_CWUTIL_HPP

#include <lxcom.h>


/*
 * ----------------------------------------------------------
 * C++ treats all classes as unique datatypes, so you can't just have a
 * pointer to an object of unknown type. In cases where that's necessary
 * classes can derive from CLxObject, which is just something guaranteed
 * to have a virtual destructor to allow 'delete'.
 */
class CLxObject
{
    public:
        virtual ~CLxObject() {}
};


/*
 * ----------------------------------------------------------
 * List template.  Doubly-liked lists, but using "next" and "prev"
 * pointers directly in the client's data object.
 */
template <class T>
class CLxList
{
    public:
        T			*first;
        T			*last;

        CLxList ()
        {
                first = 0;
                last  = 0;
        }

                void
        AddHead (
                T			*elt)
        {
                if (first)
                        first->prev = elt;
                else
                        last = elt;

                elt->next = first;
                elt->prev = 0;
                first = elt;
        }

                void
        AddTail (
                T			*elt)
        {
                if (last)
                        last->next = elt;
                else
                        first = elt;

                elt->prev = last;
                elt->next = 0;
                last = elt;
        }

                void
        Remove (
                T			*elt)
        {
                if (elt->prev)
                        elt->prev->next = elt->next;
                else
                        first = elt->next;

                if (elt->next)
                        elt->next->prev = elt->prev;
                else
                        last = elt->prev;
        }
}; // END CLxList template


/*
 * ----------------------------------------------------------
 * "lx" namespace for utility functions.
 */
                namespace lx {

/*
 * Functions for the basic IUnknown methods -- QueryInterface, AddRef and
 * Release -- in three flavors.  The "Ifc" functions take any interface, the
 * "Obj" functions take an LXtObjectID, and the "Unk" functions take an
 * ILxUknownID.  Some are templates, some not as needed.
 */
        template <class T, class U>
        bool
IfcQuery (
        T			 iface,
        const LXtGUID		*iid,
        U			*other)
{
        LxResult		 res;
        void			*pv;

        res = (iface[0]->iunk.QueryInterface) (iface, iid, &pv);
        if (LXx_OK (res)) {
                other[0] = reinterpret_cast<U> (pv);
                return true;
        } else
                return false;
};

        template <class U>
        bool
ObjQuery (
        LXtObjectID		 obj,
        const LXtGUID		*iid,
        U			*other)
{
        ILxUnknownID		 iunk;
        LxResult		 res;
        void			*pv;

        iunk = reinterpret_cast<ILxUnknownID> (obj);
        res = (iunk[0]->QueryInterface) (iunk, iid, &pv);
        if (LXx_OK (res)) {
                other[0] = reinterpret_cast<U> (pv);
                return true;
        } else
                return false;
};

        template <class U>
        bool
UnkQuery (
        ILxUnknownID		 iunk,
        const LXtGUID		*iid,
        U			*other)
{
        LxResult		 res;
        void			*pv;

        res = (iunk[0]->QueryInterface) (iunk, iid, &pv);
        if (LXx_OK (res)) {
                other[0] = reinterpret_cast<U> (pv);
                return true;
        } else
                return false;
};

        template <class T>
        T
IfcAddRef (
        T			 iface)
{
        (iface[0]->iunk.AddRef) (iface);
        return iface;
};

extern LXtObjectID	 ObjAddRef  (LXtObjectID);
extern ILxUnknownID	 UnkAddRef  (ILxUnknownID);

        template <class T>
        unsigned int
IfcRelease (
        T			 iface)
{
        return (iface[0]->iunk.Release) (iface);
};

extern void		 ObjRelease (LXtObjectID);
extern void		 UnkRelease (ILxUnknownID);


/*
 * Functions to lookup GUIDs and get globals. These are needed as basis
 * functions for much of anything else, and the implementation depends on
 * whether we are a plug-in or a client application.
 */
extern const LXtGUID *	 LookupGUID (const char *);
extern LXtObjectID	 GetGlobal  (const char *);
extern LXtObjectID	 GetGlobal  (const LXtGUID *);


/*
 * Simple GUID functions to set and compare.
 */
extern int	GUIDCompare (const LXtGUID *g1, const LXtGUID *g2);
extern void	GUIDSet (LXtGUID *, unsigned int, unsigned int, unsigned int,
                         unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int, unsigned int, unsigned int, unsigned int);


                };	// END lx namespace

#endif

