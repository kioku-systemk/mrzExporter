/*
 * Plug-in SDK Source: Modifier Wrappers
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
 * Implements modifier wrapper classes.
 */
#include <lxu_modifier.hpp>


/*
 * Allocating the item modifier conjures the spawner for the modifier nodes out
 * of spawner space.
 */
CLxItemModifierServer::CLxItemModifierServer ()
{
        CLxSpawnerCreate<CLxItemModifierNode> sp ("CLxItemModifierServer");

        spawn = sp.spawn;
        if (sp.created)
                sp.AddInterface (new CLxIfc_Modifier<CLxItemModifierNode>);

        itr_type = LXiTYPE_NONE;
}


/*
 * For a modifier that acts on every member of a given item type, we specify
 * the type name as both the list of types to trigger an update and the item
 * type required to trigger activation of the modifier.
 */
        unsigned
CLxItemModifierServer::tag_Count ()
{
        return 2 + (GraphNames () ? 1 : 0);
}

        LxResult
CLxItemModifierServer::tag_Describe (
        unsigned		 index,
        LXtTagInfoDesc		*desc)
{
        if (index == 0) {
                desc->type = LXsMOD_TYPELIST;
                desc->info = ItemType ();

        } else if (index == 1) {
                desc->type = LXsMOD_REQUIREDTYPE;
                desc->info = ItemType ();

        } else if (index == 2) {
                desc->type = LXsMOD_GRAPHLIST;
                desc->info = GraphNames ();

        } else
                return LXe_OUTOFBOUNDS;

        return LXe_OK;
}


/*
 * These methods control traversal of the candidate items for the modifier. Reset()
 * stores the item type and gets the count of items of that type. Next() goes to the
 * next item in the sequence and returns the object pointer. The index for the key
 * channel is zero since we don't care.
 */
        LxResult
CLxItemModifierServer::eval_Reset (
        ILxUnknownID		 scene)
{
        if (itr_type == LXiTYPE_NONE) {
                CLxUser_SceneService	 srv;

                itr_type = srv.ItemType (ItemType ());
        }

        itr_scene.set (scene);
        itr_scene.ItemCount (itr_type, &itr_count);
        itr_i = 0;
        return LXe_OK;
}

        LXtObjectID
CLxItemModifierServer::eval_Next (
        unsigned		*index)
{
        if (itr_i >= itr_count)
                return 0;

        CLxUser_Item		 item;

        itr_scene.GetItem (itr_type, itr_i++, item);
        index[0] = 0;
        return item.m_loc;
}


/*
 * For each item this method is used to allocate the modifier node. We spawn the
 * object and store the eval context, but the rest is done by the client.
 *
 * Clients that want to link to related items would need a test() method and a way
 * to specify other item types and graphs. That could be added relatively easily.
 */
        LxResult
CLxItemModifierServer::eval_Alloc (
        ILxUnknownID		 item,
        unsigned		 index,
        ILxUnknownID		 eval,
        void		       **ppvObj)
{
        CLxItemModifierNode	*node = spawn->Alloc (ppvObj);

        node->m_eval.set (eval);
        node->m_attr.set (eval);
        node->has_cache = true;

        node->p_elt = Alloc (node->m_eval, item);
        return LXe_OK;
}

/*
 * Test if this modifier node matches what we would create with Alloc().
 */
        LxResult
CLxItemModifierNode::mod_Test (
        ILxUnknownID		 item,
        unsigned		 index)
{
        return (p_elt->Test (item) ? LXe_TRUE : LXe_FALSE);
}


/*
 * With the setup done, the evaluation defers completely to the client
 * implementation for reading and setting channels.
 */
        LxResult
CLxItemModifierNode::mod_Evaluate ()
{
        CLxObject		*cache;
        bool			 prev_eval;

        if (has_cache) {
                cache = (CLxObject *) m_eval.GetCache ();
                prev_eval = (cache != 0);
                if (!prev_eval) {
                        cache = p_elt->Cache ();
                        if (!cache)
                                has_cache = false;
                        else
                                m_eval.SetCache (cache);
                }
        }

        if (has_cache)
                return p_elt->EvalCache (m_eval, m_attr, cache, prev_eval);

        p_elt->Eval (m_eval, m_attr);
        return LXe_OK;
}

/*
 * Cache data installed in evalaution is freed here.
 */
        void
CLxItemModifierNode::mod_Free (
        void			*cacheRaw)
{
        CLxObject		*cache = (CLxObject *) cacheRaw;

        delete cache;
}


/*
 * Validate is called for input channels that change on a modifier with
 * cache state. If Validate() not implemented we return NOTIMPL to disable
 * validation on this modifier type forever.
 */
        LxResult
CLxItemModifierNode::mod_Validate (
        ILxUnknownID		 item,
        unsigned		 channel,
        LxResult		 rc)
{
        CLxObject		*cache = (CLxObject *) m_eval.GetCache ();
        CLxUser_Item		 itm (item);

        if (p_elt->Validate (cache, itm, channel, rc))
                return LXe_OK;
        else
                return LXe_NOTIMPL;
}


/*
 * This implements the only non-template method for the CLxObjectRefModifier
 * system. Evaluate index 0 for the value reference; allocate the real object;
 * insert it into the reference. Done.
 */
        void
CLxObjectRefModifierCore::Eval (
        CLxUser_Evaluation	&eval,
        CLxUser_Attributes	&attr)
{
        CLxUser_ValueReference	 ref;
        ILxUnknownID		 obj;

        attr.ObjectRW (0, ref);
        Alloc (eval, attr, 1, obj);
        ref.SetObject (obj);
        lx::UnkRelease (obj);
}


