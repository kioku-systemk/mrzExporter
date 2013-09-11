/*
 * Plug-in SDK Source: C++ COM Wrapper Implementation
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
 * This implements the utility functions for the C++ COM proxy wrappers.
 * These are the functions and methods common to the plug-in and API wrappers.
 */
#include <lx_wrap.hpp>
#include <lxu_getstring.hpp>
#include <lxthread.h>
#include <map>

using namespace lx;


/*
 * ----------------------------------------------------------
 * Utilities:
 */

/*
 * Simple GUID comparison metric.
 */
        int
lx::GUIDCompare (
        const LXtGUID		*g1,
        const LXtGUID		*g2)
{
        int			 x;

        if (x = (g1->x4    - g2->x4   ))	return x;
        if (x = (g1->x2[0] - g2->x2[0]))	return x;
        if (x = (g1->x2[1] - g2->x2[1]))	return x;
        if (x = (g1->x1[0] - g2->x1[0]))	return x;
        if (x = (g1->x1[1] - g2->x1[1]))	return x;
        if (x = (g1->x1[2] - g2->x1[2]))	return x;
        if (x = (g1->x1[3] - g2->x1[3]))	return x;
        if (x = (g1->x1[4] - g2->x1[4]))	return x;
        if (x = (g1->x1[5] - g2->x1[5]))	return x;
        if (x = (g1->x1[6] - g2->x1[6]))	return x;
        if (x = (g1->x1[7] - g2->x1[7]))	return x;
        return 0;
}

/*
 * Function to assign all the elements of a guid, which could perhaps be
 * simpler.
 */
        void
lx::GUIDSet (
        LXtGUID			*guid,
        unsigned int		 x4,
        unsigned int		 x2a,
        unsigned int		 x2b,
        unsigned int		 x1a,
        unsigned int		 x1b,
        unsigned int		 x1c,
        unsigned int		 x1d,
        unsigned int		 x1e,
        unsigned int		 x1f,
        unsigned int		 x1g,
        unsigned int		 x1h)
{
        guid->x4    = x4;
        guid->x2[0] = x2a;
        guid->x2[1] = x2b;
        guid->x1[0] = x1a;
        guid->x1[1] = x1b;
        guid->x1[2] = x1c;
        guid->x1[3] = x1d;
        guid->x1[4] = x1e;
        guid->x1[5] = x1f;
        guid->x1[6] = x1g;
        guid->x1[7] = x1h;
}


        ILxUnknownID
lx::UnkAddRef (
        ILxUnknownID		 iunk)
{
        iunk[0]->AddRef (iunk);
        return iunk;
}

        LXtObjectID
lx::ObjAddRef (
        LXtObjectID		 obj)
{
        ILxUnknownID		 iunk;

        iunk = reinterpret_cast<ILxUnknownID>(obj);
        iunk[0]->AddRef (iunk);
        return obj;
}

        void
lx::UnkRelease (
        ILxUnknownID		 iunk)
{
        iunk[0]->Release (iunk);
}

        void
lx::ObjRelease (
        LXtObjectID		 obj)
{
        ILxUnknownID		 iunk;

        iunk = reinterpret_cast<ILxUnknownID>(obj);
        iunk[0]->Release (iunk);
}

        LXtObjectID
lx::GetGlobal (
        const char		*name)
{
        return lx::GetGlobal (lx::LookupGUID (name));
}


/*
 * Send string back to modo, perhaps raising the "short buffer" error.
 */
        LxResult
lx::StringOut (
        std::string		&string,
        char			*buf,
        unsigned		 len)
{
        if (len > string.length ()) {
                strcpy (buf, string.c_str ());
                return LXe_OK;
        } else {
                strncpy (buf, string.c_str (), len - 1);
                buf[len - 1] = 0;
                return LXe_SHORTBUFFER;
        }
}


/*
 * The venerable IUnknown has a nice simple pattern.
 */
static const LXtGUID		 iUnknown = {
        0, { 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0xC4 }
};



/*
 * ----------------------------------------------------------
 * Generic Polymorph Methods:
 */

/*
 * Find the interface given an ID.  If the interface is null or iUnknown
 * then we just use the first interface in the list.  Otherwise we scan
 * list and return the wrapper that matches.
 */
        CLxInterface *
CLxGenericPolymorph::FindIID (
        const LXtGUID		*iid)
{
        CLxInterface		*wrap;

        if (!iid || GUIDCompare (iid, &iUnknown) == 0)
                return ifc_list.first;

        for (wrap = ifc_list.first; wrap; wrap = wrap->next)
                if (GUIDCompare (iid, wrap->iid) == 0)
                        return wrap;

        return 0;
}


/*
 * Create a new proxy object for the given instance and wrapper.  We could
 * also search for an existing one if we felt like it.  The new COM object
 * has been addref-ed.
 */
        LXtCOMProxyID
CLxGenericPolymorph::NewProxy (
        LXtCOMInstance		*inst,
        CLxInterface		*wrap)
{
        LXtCOMProxy		*wcom;

        wcom = new LXtCOMProxy;
        wcom->vTable    = wrap->vTable;
        wcom->iFace     = wrap;
        wcom->object    = inst->object;
        wcom->instance  = inst;
        wcom->refCount  = 0;
        inst->proxyList.AddTail (wcom);

        AddRef (wcom);
        return wcom;
}


/*
 * The query interface callback from all COM wrapper vTables.  This
 * searches for a wrapper interface matching the given IID, and if found
 * creates a new proxy.  For iUnknown queries we return the first proxy
 * for the instance.
 */
        LxResult
CLxGenericPolymorph::QueryInterface (
        LXtObjectID		 self,
        const LXtGUID		*iid,
        void		       **ppvObj)
{
        LXtCOMProxy		*wcom = reinterpret_cast<LXtCOMProxy *> (self);
        LXtCOMInstance		*inst = wcom->instance;
        CLxInterface		*wrap;

        wrap = inst->polymorph->FindIID (iid);
        if (!wrap)
                return LXe_NOINTERFACE;

        ppvObj[0] = inst->polymorph->NewProxy (inst, wrap);
        return LXe_OK;
}


/*
 * Reference counting methods increment and decrement the counts on the
 * proxy and the instance.  When the counts go to zero we free either or
 * both.
 */
        unsigned
CLxGenericPolymorph::AddRef (
        LXtObjectID		 self)
{
        LXtCOMProxy		*wcom = reinterpret_cast<LXtCOMProxy *> (self);

        ++wcom->instance->refCount;
        return ++wcom->refCount;
}

        unsigned
CLxGenericPolymorph::Release (
        LXtObjectID		 self)
{
        LXtCOMProxy		*wcom = reinterpret_cast<LXtCOMProxy *> (self);
        LXtCOMInstance		*inst;

        --wcom->instance->refCount;
        if (--wcom->refCount)
                return wcom->refCount;

        inst = wcom->instance;
        inst->proxyList.Remove (wcom);
        delete wcom;
        if (inst->refCount)
                return 0;

        inst->polymorph->obj_list.Remove (inst);
        inst->polymorph->FreeObj (inst->object);
        delete inst;
        return 0;
}


/*
 * Add a new interface wrapper to the polymorph.  We initialize the
 * IUnknown methods to our local forms and add the wrapper to the list.
 */
        void
CLxGenericPolymorph::AddInterface (
        CLxInterface		*wrap)
{
        ILxUnknown		*iunk;

        iunk = wrap->vTable;
        iunk->QueryInterface = QueryInterface;
        iunk->AddRef         = AddRef;
        iunk->Release        = Release;

        ifc_list.AddTail (wrap);
}


/*
 * The default interface for a polymorph is given by the first one added.
 */
        const LXtGUID *
CLxGenericPolymorph::DefaultInterface ()
{
        return ifc_list.first->iid;
}


/*
 * Test if this polymorph supports the given interface.
 */
        bool
CLxGenericPolymorph::TestInterface (
        const LXtGUID		*iid)
{
        return (FindIID (iid) != 0);
}


/*
 * Spawn generates a new instance and wraps it with an interface.
 */
        ILxUnknownID
CLxGenericPolymorph::Spawn (
        const LXtGUID		*iid)
{
        CLxInterface		*wrap;
        LXtCOMInstance		*inst;

        wrap = FindIID (iid);
        if (!wrap)
                return 0;

        inst = new LXtCOMInstance;
        inst->polymorph = this;
        inst->object    = NewObj ();
        inst->refCount  = 0;
        obj_list.AddHead (inst);

        return (ILxUnknownID) NewProxy (inst, wrap);
}


/*
 * ----------------------------------------------------------
 * Global Cache Methods:
 *
 * The global cache keeps globals in a fixed-sized array.
 */
#define MAX_GLOBAL	 100

class pv_GlobalCache {
    public:
                                 pv_GlobalCache ();
                                ~pv_GlobalCache ();

        bool			 InitGUIDService ();
        bool			 InitMutex ();
        LXtObjectID		 ScanGUID (const LXtGUID *guid);
        LXtObjectID		 AddGUID (const LXtGUID *guid);

        ILxUnknownID		 global;
        ILxGUIDServiceID	 guidSvc;
        ILxThreadMutexID	 mutex;
        LXtObjectID		 gSrvc[MAX_GLOBAL];
        const LXtGUID		*gGUID[MAX_GLOBAL];
        unsigned		 numGlob;

        typedef	std::map<std::string, CLxGenericPolymorph *>		SpawnTable;
        typedef	std::map<std::string, CLxGenericPolymorph *>::iterator	SpawnTable_Itr;

        SpawnTable		 table;
};

/*
 * Set everything to uninitialized to start, and destroy anything allocated
 * at the end.
 */
pv_GlobalCache::pv_GlobalCache ()
{
        global  = 0;
        guidSvc = 0;
        mutex   = 0;
        numGlob = 0;
}

pv_GlobalCache::~pv_GlobalCache ()
{
        SpawnTable_Itr		 tit;

        for (tit = table.begin (); tit != table.end (); tit++)
                delete tit->second;

        for (unsigned i = 0; i < numGlob; i++)
                ObjRelease (gSrvc[i]);

        if (guidSvc)
                IfcRelease (guidSvc);

        if (mutex)
                IfcRelease (mutex);

        if (global)
                UnkRelease (global);
}

/*
 * Lookup of GUIDs use the GUID service, which we query for here as needed.
 */
        bool
pv_GlobalCache::InitGUIDService ()
{
        if (guidSvc)
                return true;

        if (!global)
                return false;

        LXtGUID			 guid;
        LxResult		 res;

        GUIDSet (&guid,	0xB11826F1, 0xA6BC, 0x48B4,
                        0x90, 0x9B, 0x5F, 0x6D, 0x01, 0x93, 0x83, 0x27);

        res = global[0]->QueryInterface (global, &guid, (void **) &guidSvc);
        if (LXx_FAIL (res)) {
                guidSvc = 0;
                return false;
        }

        return true;
}

/*
 * Write access to the global list is protected by a mutex, which we get
 * here when needed. We're fairly low-level here, so we don't employ any
 * of the wrappers.
 */
        bool
pv_GlobalCache::InitMutex ()
{
        if (mutex)
                return true;

        if (!global)
                return false;

        ILxThreadServiceID	 tsrv;
        const LXtGUID		*guid;
        LxResult		 res;

        guid = LookupGUID (LXu_THREADSERVICE);

        res = global[0]->QueryInterface (global, guid, (void **) &tsrv);
        if (LXx_FAIL (res))
                return false;

        res = tsrv[0]->CreateMutex (tsrv, (void **) &mutex);
        IfcRelease (tsrv);

        if (LXx_FAIL (res)) {
                mutex = 0;
                return false;
        }

        return true;
}

/*
 * This does a scan of the global list for a cached global. This can be done
 * outside the mutex since the list only grows.
 */
        LXtObjectID
pv_GlobalCache::ScanGUID (
        const LXtGUID		*guid)
{
        unsigned		 i, n = numGlob;

        for (i = 0; i < n; i++)
                if (!GUIDCompare (guid, gGUID[i]))
                        return gSrvc[i];

        return 0;
}

/*
 * Add a global GUID if not aready there. This happens inside the mutex, and we
 * scan the list again to avoid duplication. This GUID must be non-volatile.
 */
        LXtObjectID
pv_GlobalCache::AddGUID (
        const LXtGUID		*guid)
{
        LXtObjectID		 obj;
        LxResult		 res;

        if (!InitMutex ())
                return 0;

        mutex[0]->Enter (mutex);

        obj = ScanGUID (guid);
        if (!obj) {
                res = global[0]->QueryInterface (global, guid, &obj);
                if (LXx_FAIL (res))
                        obj = 0;
                else {
                        gSrvc[numGlob] = obj;
                        gGUID[numGlob] = guid;
                        numGlob++;
                }
        }

        mutex[0]->Leave (mutex);
        return obj;
}


/*
 * The public class just manages the private class. Initialization just
 * sets the global pointer from the controlling context.
 */
CLxGlobalCache::CLxGlobalCache ()
{
        pv = new pv_GlobalCache;
}

CLxGlobalCache::~CLxGlobalCache ()
{
        FreeGlobal ();
}

        void
CLxGlobalCache::InitGlobal (
        ILxUnknownID		 glob)
{
        pv->global = glob;	// NOTE: it comes in pre-addrefed!
}

        void
CLxGlobalCache::FreeGlobal ()
{
        if (pv) {
                delete pv;
                pv = 0;
        }
}


/*
 * Getting a global first tries the unprotected search, then the protected add.
 * GUIDs passed here may be volatile, so we convert them to cannonical form
 * before caching them.
 */
        LXtObjectID
CLxGlobalCache::GetGlobal (
        const LXtGUID		*guid)
{
        LXtObjectID		 obj;

        if (!pv || !pv->global || !guid)
                return 0;

        obj = pv->ScanGUID (guid);
        if (obj)
                return obj;

        return pv->AddGUID (LookupGUID (guid));
}

/*
 * Accessing GUIDs uses the service.
 */
        const LXtGUID *
CLxGlobalCache::LookupGUID (
        const char		*ident)
{
        if (!pv->InitGUIDService ())
                return 0;

        return pv->guidSvc[0]->Translate (pv->guidSvc, ident);
}

        const LXtGUID *
CLxGlobalCache::LookupGUID (
        const LXtGUID		*guid)
{
        if (!pv->InitGUIDService ())
                return 0;

        return pv->guidSvc[0]->Fixed (pv->guidSvc, guid);
}


/*
 * Using the spawner table.
 */
        void
CLxGlobalCache::AddSpawner (
        const char		*name,
        CLxGenericPolymorph	*spawn)
{
        std::string		 key (name);

        pv->table[key] = spawn;
}

        CLxGenericPolymorph *
CLxGlobalCache::FindSpawner (
        const char		*name)
{
        std::string			 key (name);
        pv_GlobalCache::SpawnTable_Itr	 tit;

        tit = pv->table.find (key);
        if (tit == pv->table.end ())
                return 0;

        return tit->second;
}


