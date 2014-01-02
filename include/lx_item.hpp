/*
 * Plug-in SDK Header: C++ User Classes
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
 */
#ifndef LXUSER_item_HPP
#define LXUSER_item_HPP

#include <lxw_item.hpp>
#include <lxw_action.hpp>
#include <lxw_particle.hpp>
#include <lxw_value.hpp>
#include <string>

class CLxUser_Scene : public CLxLoc_Scene
{
    public:
        CLxUser_Scene () {}
        CLxUser_Scene (ILxUnknownID obj) : CLxLoc_Scene (obj) {}

                bool
        from (
                CLxLoc_Item             &item)
        {
                LXtObjectID              obj;

                clear ();
                if (LXx_FAIL (item.Context (&obj)))
                        return false;

                return take (obj);
        }

        CLxUser_Scene (
                CLxLoc_Item             &item)
        {
                CLxUser_Scene ();
                from (item);
        }
                bool
        GetChannels (
                CLxLoc_ChannelRead      &chan,
                double                   time) const
        {
                LXtObjectID              obj;

                if (LXx_FAIL (Channels (0, time, &obj))) return false;
                return chan.take (obj);
        }

                bool
        GetChannels (
                CLxLoc_ChannelRead      &chan,
                const char              *name,
                double                   time = 0.0) const
        {
                LXtObjectID              obj;

                if (LXx_FAIL (Channels (name, time, &obj))) return false;
                return chan.take (obj);
        }

                bool
        GetSetupChannels (
                CLxLoc_ChannelRead      &chan) const
        {
                LXtObjectID              obj;

                if (LXx_FAIL (SetupChannels (&obj))) {
                        return false;
                }
                else {
                        return chan.take (obj);
                }
        }

                bool
        SetChannels (
                CLxLoc_ChannelWrite     &chan,
                const char              *name,
                double                   time = 0.0)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (Channels (name, time, &obj))) return false;
                return chan.take (obj);
        }
                int
        NItems (
                LXtItemType              type)
        {
                unsigned                 n;

                if (LXx_OK (ItemCount (type, &n)))
                        return n;
                else
                        return -1;
        }

                bool
        GetItem (
                LXtItemType              type,
                unsigned                 index,
                CLxLoc_Item             &item)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (ItemByIndex (type, index, &obj)))
                        return false;

                return item.take (obj);
        }
                bool
        GetItem (
                const char              *name,
                CLxLoc_Item             &item)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (ItemLookup (name, &obj)))
                        return false;

                return item.take (obj);
        }
                bool
        GetItem (
                LXtItemType             *types,
                unsigned                 index,
                CLxLoc_Item             &item)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (ItemByIndexByTypes (types, index, &obj)))
                        return false;

                return item.take (obj);
        }
                bool
        GetItem (
                LXtItemType              type,
                CLxLoc_Item             &item)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (AnyItemOfType (type, &obj)))
                        return false;

                return item.take (obj);
        }
                bool
        NewItem (
                LXtItemType              type,
                CLxLoc_Item             &item)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (ItemAdd (type, &obj)))
                        return false;

                return item.take (obj);
        }

                bool
        NewItem (
                const char              *typeName,
                CLxLoc_SceneService     &svc,
                CLxLoc_Item             &item)
        {
                LXtItemType              type;

                if (LXx_FAIL (svc.ItemTypeLookup (typeName, &type)))
                        return false;

                return NewItem (type, item);
        }

                bool
        NewItem (
                const char              *typeName,
                CLxLoc_Item             &item)
        {
                CLxLoc_SceneService      svc;

                return NewItem (typeName, svc, item);
        }
                bool
        GetGraph (
                const char              *name,
                CLxLocalizedObject      &graph)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (GraphLookup (name, &obj)))
                        return false;

                return graph.take (obj);
        }
                bool
        RemItem (
                CLxLoc_Item             &item)
        {
                ILxUnknownID             unk;

                unk = item;
                item.clear ();
                return LXx_OK (ItemRemove (unk)) ? true : false;
        }
                bool
        ReplaceItem (
                CLxLoc_Item             &item,
                LXtItemType              type,
                CLxLoc_Item             &newItem)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (ItemReplace (item, type, &obj)))
                        return false;

                return newItem.take (obj);
        }
                bool
        GetItemByIdent (
                const char              *name,
                CLxLoc_Item             &item)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (ItemLookupIdent (name, &obj)))
                        return false;

                return item.take (obj);
        }
                bool
        GetImportedItem (
                const char              *name,
                CLxLoc_Item             &item)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (ItemLookupImported (name, &obj)))
                        return false;

                return item.take (obj);
        }
                int
        NRenderCameras ()
        {
                int                      n;

                if (LXx_OK (RenderCameraCount (&n)))
                        return n;
                else
                        return 0;
        }

                bool
        GetRenderCameraByIndex (
                int                      index,
                CLxLoc_Item             &item)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (RenderCameraByIndex (index, &obj)))
                        return false;

                return item.take (obj);
        }
                int
        GetRenderCameraIndex (
                CLxLoc_Evaluation        eval)
        {
                ILxEvaluationID          ev;
                int                      i;

                eval.get ((void **)&ev);

                if (LXx_OK (RenderCameraIndex ((ILxUnknownID)ev, &i)))
                        return i;
                else
                        return 0;
        }
};
class CLxUser_Item : public CLxLoc_Item
{
    public:
        CLxUser_Item () {}
        CLxUser_Item (ILxUnknownID obj) : CLxLoc_Item (obj) {}

                bool
        IsA (
                LXtItemType              type)
        {
                return (TestType (type) == LXe_OK);
        }

                bool
        IsA (
                LXtItemType             *types)
        {
                return (TestTypes (types) == LXe_OK);
        }
                const char *
        IdentPtr () const
        {
                const char              *id;

                Ident (&id);
                return id;
        }
                bool
        operator< (
                const CLxUser_Item      &rhs) const
        {
                return IdentPtr () < rhs.IdentPtr ();
        }

                bool
        operator== (
                const CLxUser_Item      &rhs) const
        {
                return IdentPtr () == rhs.IdentPtr ();
        }
                std::string
        GetIdentity ()
        {
                std::string      identity;
                const char      *ident;

                if (LXx_OK (Ident (&ident))) {
                        identity = std::string(ident);
                }

                return identity;
        }
                void
        GetUniqueName (
                std::string             &name)
        {
                const char              *sptr;

                if (LXx_OK (UniqueName (&sptr)))
                        name = sptr;
        }
                bool
        GetParent (
                CLxLoc_Item             &item)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (Parent (&obj)))
                        return false;

                return item.take (obj);
        }
                bool
        GetSubItem (
                unsigned                 index,
                CLxLoc_Item             &item)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (SubByIndex (index, &obj)))
                        return false;

                return item.take (obj);
        }
                bool
        GetRoot (
                CLxLoc_Item             &item)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (Root (&obj)))
                        return false;

                return item.take (obj);
        }
                bool
        GetContext (
                CLxLoc_Scene            &scene)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (Context (&obj)))
                        return false;

                return scene.take (obj);
        }
                unsigned
        NChannels () const
        {
                unsigned                 count;

                if (LXx_OK (ChannelCount (&count)))
                        return count;

                return 0;
        }

                int
        ChannelIndex (
                const char              *name) const
        {
                unsigned                 idx;

                if (LXx_OK (ChannelLookup (name, &idx)))
                        return idx;

                return -1;
        }
                int
        ChannelDecode (
                unsigned                 index,
                const char              *encoded) const
        {
                CLxLoc_ValueService      valueSvc;
                int                      value;
                const LXtTextValueHint  *hints;

                if (  LXx_OK (ChannelIntHint (index, &hints))
                  &&  LXx_OK (valueSvc.TextHintDecode (encoded, hints, &value)) )
                        return value;

                return -1;
        }
};
class CLxUser_SceneGraph : public CLxLoc_SceneGraph
{
    public:
        CLxUser_SceneGraph () {}
        CLxUser_SceneGraph (ILxUnknownID obj) : CLxLoc_SceneGraph (obj) {}

                bool
        from (
                CLxLoc_Scene            &scene,
                const char              *name)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (scene.GraphLookup (name, &obj)))
                        return false;

                return take (obj);
        }

                bool
        from (
                CLxLoc_Item             &item,
                const char              *name)
        {
                CLxLoc_Scene             scene;
                LXtObjectID              obj;

                if (LXx_FAIL (item.Context (&obj)))
                        return false;

                scene.take (obj);
                return from (scene, name);
        }
};
class CLxUser_ItemGraph : public CLxLoc_ItemGraph
{
    public:
        CLxUser_ItemGraph () {}
        CLxUser_ItemGraph (ILxUnknownID obj) : CLxLoc_ItemGraph (obj) {}

                bool
        from (
                CLxLoc_Scene            &scene,
                const char              *name)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (scene.GraphLookup (name, &obj)))
                        return false;

                return take (obj);
        }

                bool
        from (
                CLxLoc_Item             &item,
                const char              *name)
        {
                CLxLoc_Scene             scene;
                LXtObjectID              obj;

                if (LXx_FAIL (item.Context (&obj)))
                        return false;

                scene.take (obj);
                return from (scene, name);
        }
                unsigned
        Forward (
                CLxLoc_Item             &item)
        {
                unsigned                 n;

                if (LXx_FAIL (FwdCount (item, &n)))
                        n = 0;

                return n;
        }

                bool
        Forward (
                CLxLoc_Item             &item,
                unsigned                 index,
                CLxLoc_Item             &dest)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (FwdByIndex (item, index, &obj)))
                        return false;

                return dest.take (obj);
        }
                unsigned
        Reverse (
                CLxLoc_Item             &item)
        {
                unsigned                 n;

                if (LXx_FAIL (RevCount (item, &n)))
                        n = 0;

                return n;
        }

                bool
        Reverse (
                CLxLoc_Item             &item,
                unsigned                 index,
                CLxLoc_Item             &dest)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (RevByIndex (item, index, &obj)))
                        return false;

                return dest.take (obj);
        }
};
class CLxUser_ChannelGraph : public CLxLoc_ChannelGraph
{
    public:
        CLxUser_ChannelGraph () {}
        CLxUser_ChannelGraph (ILxUnknownID obj) : CLxLoc_ChannelGraph (obj) {}

                bool
        from (
                CLxLoc_Scene            &scene,
                const char              *name)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (scene.GraphLookup (name, &obj)))
                        return false;

                return take (obj);
        }

                bool
        from (
                CLxLoc_Item             &item,
                const char              *name)
        {
                CLxLoc_Scene             scene;
                LXtObjectID              obj;

                if (LXx_FAIL (item.Context (&obj)))
                        return false;

                scene.take (obj);
                return from (scene, name);
        }
};
class CLxUser_SceneService : public CLxLoc_SceneService
{
    public:
                bool
        GetRoot (
                CLxLoc_Scene            &scene)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (Root (&obj)))
                        return false;

                return scene.take (obj);
        }
                LXtItemType
        ItemType (
                const char              *name)
        {
                LXtItemType              type;

                if (LXx_FAIL (ItemTypeLookup (name, &type)))
                        return LXiTYPE_NONE;

                return type;
        }
                bool
        NewScene (
                CLxLoc_Scene            &scene)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (CreateScene (&obj)))
                        return false;

                return scene.take (obj);
        }
                bool
        NewReplicatorEnumerator (
                ILxUnknownID                     pItem,
                CLxLoc_ReplicatorEnumerator     &replicatorEnum)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (GetReplicatorEnumerator (pItem, &obj)))
                        return false;

                return replicatorEnum.take (obj);
        }
};

class CLxItemType {
    public:
        const char              *type_name;
        LXtItemType              cached_code;

        CLxItemType (
                const char      *typeName)
        {
                type_name   = typeName;
                cached_code = LXiTYPE_NONE;
        }

                LXtItemType
        Type ()
        {
                if (cached_code != LXiTYPE_NONE)
                        return cached_code;

                CLxUser_SceneService srv;

                cached_code = srv.ItemType (type_name);
                return cached_code;
        }

                operator
        LXtItemType ()
        {
                return Type ();
        }
};

#endif

