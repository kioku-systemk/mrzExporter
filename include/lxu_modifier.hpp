/*
 * Plug-in SDK Header: Modifier Wrapper Classes
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
 * Provides wrapper classes for creating modifiers in C++ plug-ins.
 */
#ifndef LXU_MODIFIER_HPP
#define LXU_MODIFIER_HPP

#include <lx_action.hpp>
#include <lx_value.hpp>
#include <lx_item.hpp>


/*
 * ----------------------------------------------------
 * Item Modifier
 *
 * An item modifier is a server that allocates a modifier for each item of a
 * given type. The client can then read and set channels on that (or any other)
 * item.
 */

/*
 * The element is subclassed by the client, and there is one allocated for each
 * affected item.
 */
class CLxItemModifierElement
{
    public:
        virtual	~CLxItemModifierElement () {}

        /*
         * Test if the state of this element matches what would be generated
         * using the Alloc() method on this item. Default is true, which is
         * typically correct for modifiers that don't depend on other items.
         */
        virtual bool		Test (ILxUnknownID)
                                        { return true; }

        /*
         * The Eval() method is called to read from modifier inputs and
         * write to outputs. This is the core operation of the modifier.
         */
        virtual void		Eval (CLxUser_Evaluation &, CLxUser_Attributes &)
                                        {}

        /*
         * The Cache() method allocates and returns a cache object. It is not
         * initialized but will be passed to evaluation.
         */
        virtual CLxObject *	Cache ()
                                        { return 0; }

        /*
         * The EvalCache() method is called to read from modifier inputs and
         * write to outputs for modifiers that have a non-null cache. The
         * cache object is passed plus true if this is a cache from a previous
         * evaluation.
         */
        virtual LxResult	EvalCache (CLxUser_Evaluation &, CLxUser_Attributes &, CLxObject *, bool)
                                        { return LXe_FAILED; }

        /*
         * The Validate() method is called when there are changes to the inputs
         * of a modifier with cached state. Client methods must return 'true'.
         */
        virtual bool		Validate (CLxObject *, CLxUser_Item &, unsigned, LxResult)
                                        { return false; }
};


/*
 * Modifier node is the more raw object that wraps the element. This really
 * should be private except for its use in a template in the essentially
 * private part of the next class.
 */
class CLxItemModifierNode :
                public CLxImpl_Modifier
{
    public:
        CLxItemModifierElement	*p_elt;
        CLxUser_Evaluation	 m_eval;
        CLxUser_Attributes	 m_attr;
        bool			 has_cache;

        LxResult	 mod_Evaluate ()					LXx_OVERRIDE;
        LxResult	 mod_Test (ILxUnknownID, unsigned)			LXx_OVERRIDE;
        LxResult	 mod_Validate (ILxUnknownID, unsigned, LxResult)	LXx_OVERRIDE;
        void		 mod_Free (void *)					LXx_OVERRIDE;
};


/*
 * The modifier server is subclassed by the client, and is exported as a server.
 * The virtual methods specify the item type to traverse and provide a way to allocate
 * new elements for items in the scene.
 */
class CLxItemModifierServer :
                public CLxImpl_EvalModifier,
                public CLxImpl_TagDescription
{
    public:
                         CLxItemModifierServer ();
        virtual		~CLxItemModifierServer () {}

        /*
         * The ItemType() method returns the name of the item type for
         * this modifier.
         */
        virtual const char *			 ItemType () = 0;

        /*
         * This optionally returns the names of graphs to watch for changes.
         */
        virtual const char *			 GraphNames () { return 0; }

        /*
         * The Alloc() method is called to create a new modifier element for a
         * specific item. This should add channels in the evaluation interface and
         * record their indices for evaluation. Clients should generally only link
         * to channels in this item, because the node will not be updated on
         * changes to other items or graphs.
         */
        virtual CLxItemModifierElement *	 Alloc (CLxUser_Evaluation &, ILxUnknownID item) = 0;

        LxResult	 eval_Reset (ILxUnknownID scene)		LXx_OVERRIDE;
        LXtObjectID	 eval_Next (unsigned *index)			LXx_OVERRIDE;
        LxResult	 eval_Alloc (ILxUnknownID item, unsigned index, ILxUnknownID eval, void **ppvObj)
                                                                        LXx_OVERRIDE;

        unsigned	 tag_Count ()					LXx_OVERRIDE;
        LxResult	 tag_Describe (unsigned, LXtTagInfoDesc *desc)	LXx_OVERRIDE;

        CLxPolymorph<CLxItemModifierNode>	*spawn;

        CLxUser_Scene		 itr_scene;
        LXtItemType		 itr_type;
        unsigned int		 itr_count, itr_i;
};


/*
 * Construtors on template classes can kind of work like functions with
 * parameterized types. Declaring and installing the modifier server can be done
 * by instantiating this object with the class of the client's subclassed version
 * of CLxItemModifierServer and the server name.
 *
 *	initialize ()
 *	{
 *		CLxExport_ItemModifierServer<CMyModifier> ("myModifier");
 *	}
 */
template <class T>
class CLxExport_ItemModifierServer
{
    public:
        CLxExport_ItemModifierServer (
                const char		*name)
        {
                CLxGenericPolymorph	*srv;

                srv = new CLxPolymorph<T>;
                srv->AddInterface (new CLxIfc_EvalModifier  <T>);
                srv->AddInterface (new CLxIfc_TagDescription<T>);
                lx::AddServer (name, srv);
        }
};



/*
 * An object-ref modifier is a modifier whose role is solely to allocate
 * an object and insert it into an objref channel. This includes falloffs,
 * deformations, and mesh influences. The latter case can require a more
 * complex class since this doesn't allow for caching.
 *
 * The client subclasses the "core" class, implementing the required virtual
 * methods.
 */
class CLxObjectRefModifierCore :
                public CLxItemModifierElement
{
    public:
        /*
         * Return the name of the item type with the channel to set, and the
         * name of the channel.
         */
        virtual const char *	ItemType () = 0;
        virtual const char *	Channel () = 0;

        /*
         * Attach to the eval context. Just add channels for read.
         */
        virtual void		Attach (CLxUser_Evaluation &, ILxUnknownID) = 0;

        /*
         * Allocate the sub-object. The access interfaces and the starting index
         * are provided, and the new object is returned indirectly.
         */
        virtual void		Alloc (CLxUser_Evaluation &, CLxUser_Attributes &, unsigned, ILxUnknownID &) = 0;

        void		 Eval (CLxUser_Evaluation &, CLxUser_Attributes &)		LXx_OVERRIDE;
};

/*
 * The actual modifier server is declared as a template. This can all be
 * done with one arcane line in the init function:
 *
 *	initialize ()
 *	{
 *		CLxExport_ItemModifierServer<CLxObjectRefModifier<CMyCore> > ("myModifierServer");
 *	}
 */
template <class T>
class CLxObjectRefModifier :
                public CLxItemModifierServer
{
    public:
                const char *
        ItemType ()
        {
                T			 tmp;

                return tmp.ItemType ();
        }

                CLxItemModifierElement *
        Alloc (
                CLxUser_Evaluation	&eval,
                ILxUnknownID		 item)
        {
                T			*elt;

                elt = new T;
                eval.AddChan (item, elt->Channel (), LXfECHAN_WRITE);

                elt->Attach (eval, item);
                return elt;
        }
};


#endif // LXU_MODIFIER_HPP

