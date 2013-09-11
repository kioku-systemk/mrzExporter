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
 * The wrapper classes defined here provide three services.
 *
 *  (1) C++ objects can be wrapped with COM interfaces to be exported to nexus.
 *
 *  (2) COM objects from nexus can be localized with C++ object wrappers.
 *
 *  (3) The entire dynamic library can be exposed to nexus as a module, and
 * nexus can instantiate the servers defined here. This also provides access
 * to nexus internal state and service globals.
 */
#ifndef LX_CWRAP_HPP
#define LX_CWRAP_HPP

#include <lx_util.hpp>

/*
 * Disable the multiple assignment operators warning in Visual C++.
 * (CLxLocalize has const and non-const versions of the assignment operator.)
 */
#ifdef _MSC_VER
        #pragma warning(disable: 4522)
#endif


/*
 * ----------------------------------------------------------
 * Localized COM Objects:
 *
 * COM objects from nexus come in as LXtObjectID pointers. These can be
 * localized to a specific interface which is a sub-class of this abstract
 * class.
 *
 *	guid ()		-- return the interface guid, mostly for internal use
 *	set (obj)	-- set the localization wrapper to use the object
 *	take (obj)	-- same as set but also releases the object, taking ownership
 *	copy (loc)	-- sets this to use the same object as another
 *	test ()		-- returns true if this wrapper has a valid interface
 *	clear ()	-- releases the interface for the current object
 *	get (ppvObj)	-- sets a ppvObj pointer for exporting wrapped objects
 *	casts		-- casts the current object to forms usable by other calls
 */
class CLxLocalizedObject
{
    public:
        virtual			~CLxLocalizedObject () {}

        virtual const LXtGUID *	 guid  () const			= 0;
        virtual bool		 set   (LXtObjectID obj)	= 0;
        virtual bool		 take  (LXtObjectID obj)	= 0;
        virtual bool		 copy  (CLxLocalizedObject& loc)= 0;
        virtual bool		 test  () const			= 0;
        virtual void		 clear ()			= 0;
        virtual LxResult	 get   (void **ppvObj) const	= 0;
        virtual operator  ILxUnknownID () const			= 0;
};


/*
 * Services are automatically set to point to the global service for the
 * current module, so they cannot be changed or cleared.  They can be set()
 * again if their constructor was called before the global modules were valid.
 */
class CLxLocalizedService
{
    public:
        void			 set (void) {}
};


/*
 * This template is part of a localization for a specific interface.  The actual
 * methods of the interface are implemented as part of the CLxLoc_??? class,
 * which is also where all the constructors are defined.
 */
template <class T>
class CLxLocalize : public CLxLocalizedObject
{
    public:
        T			 m_loc;

        ~CLxLocalize ()
        {
                clear ();
        }

        bool set (LXtObjectID obj)
                                 LXx_OVERRIDE
        {
                T		 loc;

                if (obj && lx::ObjQuery (obj, guid (), &loc)) {
                        clear ();
                        m_loc = loc;
                        return true;
                }

                clear ();
                return false;
        }

        bool take (LXtObjectID obj)
                                 LXx_OVERRIDE
        {
                if (!obj) {
                        clear ();
                        return false;
                }

                set (obj);
                lx::ObjRelease (obj);
                return test ();
        }

        bool copy (CLxLocalizedObject& loc)
                                 LXx_OVERRIDE
        {
                ILxUnknownID		 unk = loc;

                return set (reinterpret_cast<LXtObjectID>(unk));
        }

        void clear()
                                 LXx_OVERRIDE
        {
                if (m_loc) {
                        lx::IfcRelease (m_loc);
                        m_loc = 0;
                }
        }

        bool test() const
                                 LXx_OVERRIDE
        {
                return (m_loc != 0);
        }

        LxResult get (void **ppvObj) const
                                 LXx_OVERRIDE
        {
                if (!test ())
                        return LXe_NOTFOUND;

                lx::IfcAddRef (m_loc);
                ppvObj[0] = m_loc;
                return LXe_OK;
        }

        operator ILxUnknownID() const
                                 LXx_OVERRIDE
        {
                return reinterpret_cast<ILxUnknownID>(m_loc);
        }

        CLxLocalize& operator=(CLxLocalize& right)
        {
                set (right);
                return *this;
        }

        CLxLocalize& operator=(const CLxLocalize& right)
        {
                set (const_cast<CLxLocalize&>(right));
                return *this;
        }
};


/*
 * ----------------------------------------------------------
 * Exported COM Objects:
 *
 * We create our own COM objects that conform to the binary standard
 * regardless of compiler.  Our COM objects are proxies that are implemented
 * by a C++ object, and the interfaces are hooked to the objects using
 * simple glue stubs implemented as template classes.
 *
 * An interface wrapper is an abstract class that defines a VTable for an
 * interface plus it's GUID.  Typically the vTable contains stubs that
 * decode the COM proxy object and pass control to the underlying class.
 */
class CLxInterface
{
    public:
        CLxInterface		*next, *prev;
        ILxUnknown		*vTable;
        const LXtGUID		*iid;
};


typedef struct st_LXtCOMProxy *		LXtCOMProxyID;
typedef struct st_LXtCOMInstance *	LXtCOMInstanceID;

/*
 * A Proxy is a real COM object with a vTable at the start.  The proxy
 * points back to the instance to keep counts rights, and it also has the
 * object cached locally for quicker access.  Note that there does not
 * seem to be a way to do this with type-safety, so we rely on a void
 * pointer to the actual client object.
 */
typedef struct st_LXtCOMProxy {
        ILxUnknown		*vTable;
        LXtCOMProxyID		 next, prev;
        CLxInterface		*iFace;
        LXtCOMInstanceID	 instance;
        void			*object;
        unsigned		 refCount;
} LXtCOMProxy;


/*
 * An instance is a struct holding the actual object and a list of its
 * proxies.  Again the actual client object is a void pointer.
 */
typedef struct st_LXtCOMInstance {
        class CLxGenericPolymorph *polymorph;
        LXtCOMInstanceID	   next, prev;
        CLxList<LXtCOMProxy>	   proxyList;
        void			  *object;
        unsigned		   refCount;
} LXtCOMInstance;


/*
 * Macros to extract the real data type from a proxy.
 *
 *	LXCWxOBJ(p,X)	given a proxy 'p', this macro performs a cast, a deref,
 *			another cast, and returns the referenced object as a
 *			pointer to type X
 *
 *	LXCWxWCOM(X)	same again, but the proxy is always called 'wcom'
 *
 *	LXCWxINST(Y,v)	given the 'wcom' COM proxy, this macro first gets the
 *			object pointer as type 'T', then performs a static
 *			cast to a Y pointer and sets v to that value
 */
#define LXCWxOBJ(p,X)	reinterpret_cast<X*>((reinterpret_cast<LXtCOMProxy*>(p))->object)
#define LXCWxWCOM(X)	LXCWxOBJ(wcom,X)
#define LXCWxINST(Y,v)	Y *v = static_cast<Y*> (LXCWxWCOM(T))


/*
 * A polymorph is the COM front-end for some internal object.  The client
 * has to provide the NewObj() and FreeObj() methods to allocate and free
 * their actual object.  AddInterface() is used to add new interface
 * wrappers that act on the object.  Once fully defined, Spawn() is used
 * to create new instances wrapped as COM objects.
 */
class CLxGenericPolymorph
{
    private:
        CLxList<LXtCOMInstance>	 obj_list;
        CLxList<CLxInterface>	 ifc_list;

        CLxInterface *		 FindIID (const LXtGUID *iid);
        LXtCOMProxyID		 NewProxy (LXtCOMInstance *, CLxInterface *);

        static LxResult		 QueryInterface (LXtObjectID, const LXtGUID *, void **);
        static unsigned		 AddRef (LXtObjectID);
        static unsigned		 Release (LXtObjectID);

    public:
                                 CLxGenericPolymorph () {}
        virtual			~CLxGenericPolymorph () {}
        virtual void *		 NewObj  ()       = 0;
        virtual void		 FreeObj (void *) = 0;

        void			 AddInterface (CLxInterface *);
        bool			 TestInterface (const LXtGUID *);
        const LXtGUID *		 DefaultInterface ();
        ILxUnknownID		 Spawn (const LXtGUID *iid = 0);
};


/*
 * The basic polymorph template call can create the NewObj() and FreeObj()
 * for any C++ datatype. It also has a method for "casting" a wrapped COM
 * object of this type back to the base type, and for allocating a new
 * instance and returning the internal object.
 */
template <class T>
class CLxPolymorph : public CLxGenericPolymorph
{
    public:
                void *
        NewObj ()
                                         LXx_OVERRIDE
        {
                return reinterpret_cast<void *> (new T);
        }

                void
        FreeObj (
                void			*obj)
                                         LXx_OVERRIDE
        {
                T			*elt = reinterpret_cast<T*> (obj);

                delete elt;
        }

                T *
        Cast (
                ILxUnknownID		 wcom)
        {
                return LXCWxOBJ (wcom, T);
        }

                T *
        Alloc (
                void		       **ppvObj)
        {
                ILxUnknownID		 obj;

                obj = Spawn ();
                if (!obj)
                        throw (LXe_FAILED);

                ppvObj[0] = obj;
                return Cast (obj);
        }

                T *
        Alloc (
                ILxUnknownID		&obj)
        {
                return Alloc ((void **) &obj);
        }

                T *
        Alloc (
                CLxLocalizedObject	&loc)
        {
                ILxUnknownID		 obj;

                obj = Spawn ();
                if (!obj)
                        throw (LXe_FAILED);

                loc.take (obj);
                return Cast (loc);
        }
};


/*
 * A singleton polymorph is a generic polymorph that can be cast to a
 * single instance of itself. The base class has to implement the NewObj()
 * method as provided in the macro below. Typically subclasses will add
 * their interfaces in their constructor to prevent timing issues with
 * when the instance is spawned.
 */
class CLxSingletonPolymorph :
                public CLxGenericPolymorph
{
    public:
        LXtObjectID		 m_ifc;

        CLxSingletonPolymorph ()
        {
                m_ifc = 0;
        }

        ~CLxSingletonPolymorph ()
        {
                if (m_ifc)
                        lx::ObjRelease (m_ifc);
        }

                operator
        ILxUnknownID ()
        {
                if (!m_ifc)
                        m_ifc = Spawn ();

                return reinterpret_cast <ILxUnknownID> (m_ifc);
        }

                void
        FreeObj (
                void		*self)
                                 LXx_OVERRIDE
        {
        }
};

#define LXxSINGLETON_METHOD	void * NewObj() LXx_OVERRIDE { return this; }


/*
 * Common setup functions.
 */
namespace lx {

        /*
         * Plug-ins and client apps can register new servers by calling this generic
         * utility function. The polymorph will be added as a server of the given name.
         * FindServer() gets the generic back again.
         */
        extern void			AddServer (const char *, CLxGenericPolymorph *);
        extern CLxGenericPolymorph *	FindServer (const char *);

        /*
         * Plug-ins and client apps can store their own spawners (polymorphs) in a global
         * table. FindSpawner() gets the generic.
         */
        extern void			AddSpawner (const char *, CLxGenericPolymorph *);
        extern CLxGenericPolymorph *	FindSpawner (const char *);

        /*
         * Template function allows a COM object known to be derived from one of this
         * module's servers to be cast back to the C++ object that it contains.
         */
                template <class T>
                void
        CastServer (
                const char		*name,
                ILxUnknownID		 unk,
                T		       *&tptr)
        {
                CLxGenericPolymorph	*pg;
                CLxPolymorph<T>		*pT;

                pg   = FindServer (name);
                pT   = dynamic_cast<CLxPolymorph<T> *> (pg);
                tptr = pT->Cast (unk);
        }
}	// END namespace


/*
 * ----------------------------------------------------------
 * Interfaces and Wrappers.
 *
 * An interface is simply an abstract class that defines methods which
 * correspond 1 to 1 with the function vectors of the COM interface.
 * The client would inherit from one or more of these interfaces and
 * fill in their implementations.
 *
 * A wrapper template acts as a translator from COM proxies to the
 * client's class implementation.  They provide static entry points 
 * which extract the client's object pointer from the proxy, and then
 * does a static cast to convert the client's object type into the type
 * of the abstract class.  Then it simply calls the methods.
 */
#include <lxw_server.hpp>


/*
 * Global cache is a utility class for maintaining globals
 */
class CLxGlobalCache
{
    public:
                                 CLxGlobalCache ();
                                ~CLxGlobalCache ();

        void			 InitGlobal (ILxUnknownID);
        void			 FreeGlobal ();

        const LXtGUID *		 LookupGUID (const LXtGUID *);
        const LXtGUID *		 LookupGUID (const char *);
        LXtObjectID		 GetGlobal  (const LXtGUID *);
        LXtObjectID		 GetGlobal  (const char *ident)
                                  {  return GetGlobal (LookupGUID (ident));  }

        void			 AddSpawner (const char *, CLxGenericPolymorph *);
        CLxGenericPolymorph *	 FindSpawner (const char *);

    private:
        class pv_GlobalCache	*pv;
};


/*
 * This is a non-standard Tag Description wrapper.  This allows a client
 * class to define a static array of descriptions to be displayed as a
 * Tag Description COM interface.
 */
template <class T>
class CLxIfc_StaticDesc : public CLxInterface
{
                static unsigned
        Count (
                LXtObjectID		 wcom)
        {
                T			*obj  = LXCWxWCOM(T);
                LXtTagInfoDesc		*list = obj->descInfo;
                int			 n;

                for (n = 0; list[n].type; n++)
                        ;

                return n;
        }

                static LxResult
        Describe (
                LXtObjectID		 wcom,
                unsigned		 index,
                LXtTagInfoDesc		*desc)
        {
                T			*obj  = LXCWxWCOM(T);
                LXtTagInfoDesc		*list = obj->descInfo;

                *desc = list[index];
                return LXe_OK;
        }

                ILxTagDescription	 vt;
        public:

        CLxIfc_StaticDesc ()
        {
                vt.Count	= Count;
                vt.Describe	= Describe;
                vTable		= &vt.iunk;
                iid		= &lx::guid_TagDescription;
        }
};


/*
 * Spawners hold a polymorph for a specific class and pass common methods
 * for allocating and testing through directly.
 */
template <class T>
class CLxSpawnerCommon
{
    public:
        CLxPolymorph<T>			*spawn;

        T *	Cast  (ILxUnknownID wcom)	{ return spawn->Cast (wcom); }
        T *	Alloc (void **ppvObj)		{ return spawn->Alloc (ppvObj); }
        T *	Alloc (ILxUnknownID &obj)	{ return spawn->Alloc (obj); }
        T *	Alloc (CLxLocalizedObject &loc)	{ return spawn->Alloc (loc); }

                void
        AddInterface (
                CLxInterface		*ifc)
        {
                spawn->AddInterface (ifc);
        }

                LxResult
        TestInterfaceRC (
                const LXtGUID		*guid)
        {
                return (spawn->TestInterface (guid) ? LXe_TRUE : LXe_FALSE);
        }
};


/*
 * A spawner object can be declared for a given type and spawner name. If the
 * spawner has already been registered then this provides methods for creating
 * COM-object instances for the given type.
 *
 *	CLxSpawner<MyClass>	 sp ("spawn.name");
 *	MyClass			*my;
 *	ILxUnknownID		 obj;
 *
 *	my = sp.Alloc (obj);
 */
template <class T>
class CLxSpawner :
                 public CLxSpawnerCommon<T>
{
    public:
        CLxSpawner (
                const char		*spname)
        {
                CLxGenericPolymorph	*gp;

                gp = lx::FindSpawner (spname);
                CLxSpawnerCommon<T>::spawn = dynamic_cast<CLxPolymorph<T> *> (gp);
        }

};

/*
 * This is the same but will create the spawner if it doesn't already exist.
 * The client of this object should add appropriate interfaces when spawners
 * are created.
 *
 *	CLxSpawnerCreate<MyClass>	 sp ("MyClass");
 *	MyClass				*my;
 *	ILxUnknownID			 obj;
 *
 *	if (sp.created)
 *		sp.AddInterface(new CLxImpl_SomeInterface<MyClass>);
 *
 *	my = sp.Alloc (obj);
 */
template <class T>
class CLxSpawnerCreate :
                 public CLxSpawnerCommon<T>
{
    public:
        bool				 created;

        CLxSpawnerCreate (
                const char		*spname)
        {
                CLxGenericPolymorph	*gp;

                gp = lx::FindSpawner (spname);
                if (gp) {
                        CLxSpawnerCommon<T>::spawn   = dynamic_cast<CLxPolymorph<T> *> (gp);
                        created = false;
                } else {
                        CLxSpawnerCommon<T>::spawn = new CLxPolymorph<T>;
                        lx::AddSpawner (spname, CLxSpawnerCommon<T>::spawn);
                        created = true;
                }
        }
};


/*
 * A typical server consists of a single interface of the server's type, plus
 * a static description for its tags.
 */
#define LXx_ADD_SERVER(what,T,name)\
        { CLxGenericPolymorph *srv = new CLxPolymorph<T>;\
        srv->AddInterface (new CLxIfc_##what<T>);\
        srv->AddInterface (new CLxIfc_StaticDesc<T>);\
        lx::AddServer (name, srv); }


#endif

