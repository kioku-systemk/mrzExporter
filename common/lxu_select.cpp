/*
 * Plug-in SDK Header: Common Utility
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
 * Selection Utility Classes
 */

#include <lxu_select.hpp>


/*
 * ----------------------------------------------------------------
 * CLxVertexSelection : Implementation
 */
CLxVertexSelection::CLxVertexSelection ()
{
        pkt_trans.autoInit ();
        sel_ID = srv_sel.LookupType (LXsSELTYP_VERTEX);
        sel_comp[0] = sel_ID;
        sel_comp[1] = srv_sel.LookupType (LXsSELTYP_EDGE);
        sel_comp[2] = srv_sel.LookupType (LXsSELTYP_POLYGON);
        sel_comp[3] = 0;
}

        bool
CLxVertexSelection::AnyDirect ()
{
        return srv_sel.Count (sel_ID) != 0;
}

        bool
CLxVertexSelection::AnyIndirect ()
{
        LXtID4			 cur;

        cur = srv_sel.CurrentType (sel_comp);
        return srv_sel.Count (cur) != 0;
}

        void
CLxVertexSelection::GetDirectList (
        MeshList		&list)
{
        CLxUser_Item		 item;
        MeshEntry		 entry;
        LXtScanInfoID		 scan;
        LXtPointID		 vrt;
        const char		*id;
        void			*pkt;
        int			 k;

        std::map<const char *, int>		entries;
        std::map<const char *, int>::iterator	eit;

        list.clear ();

        scan = 0;
        while (scan = srv_sel.ScanLoop (scan, sel_ID, &pkt)) {
                pkt_trans.Vertex (pkt, &vrt);

                pkt_trans.GetItem (pkt, item);
                item.Ident (&id);
                eit = entries.find (id);

                if (eit == entries.end ()) {
                        entry.item.set (item);
                        pkt_trans.GetMesh (pkt, entry.mesh);

                        k = list.size ();
                        entries[id] = k;
                        list.push_back (entry);
                } else
                        k = eit->second;

                list[k].list.push_back (vrt);
        }
}


/*
 * ----------------------------------------------------------------
 * CLxVertexMapSelection : Implementation
 */
        CLxUser_SelectionService	 srv_sel;
        CLxUser_VMapPacketTranslation	 pkt_trans;
        LXtID4				 sel_ID;

CLxVertexMapSelection::CLxVertexMapSelection ()
{
        sel_ID = srv_sel.LookupType (LXsSELTYP_VERTEXMAP);
        pkt_trans.autoInit ();
}

        bool
CLxVertexMapSelection::First (
        std::string		&name)
{
        LXtScanInfoID		 scan;
        LXtID4			 type;
        const char		*str;
        void			*pkt;

        scan = 0;
        while (scan = srv_sel.ScanLoop (scan, sel_ID, &pkt)) {
                pkt_trans.Type (pkt, &type);
                if (!Include (type))
                        continue;

                pkt_trans.Name (pkt, &str);
                name = str;
                return true;
        }

        return false;
}

        void
CLxVertexMapSelection::GetList (
        MapList			&list)
{
        LXtScanInfoID		 scan;
        LXtID4			 type;
        MapInfo			 info;
        const char		*str;
        void			*pkt;

        scan = 0;
        while (scan = srv_sel.ScanLoop (scan, sel_ID, &pkt)) {
                pkt_trans.Type (pkt, &info.type);
                if (!Include (info.type))
                        continue;

                pkt_trans.Name (pkt, &str);
                info.name = str;

                list.push_back (info);
        }
}


/*
 * ----------------------------------------------------------------
 * CLxItemSelection : Implementation
 */
CLxItemSelection::CLxItemSelection ()
{
        sel_ID = srv_sel.LookupType (LXsSELTYP_ITEM);
        pkt_trans.autoInit ();
}

        bool
CLxItemSelection::GetFirst (
        CLxUser_Item		&item)
{
        LXtScanInfoID		 scan;
        void			*pkt;

        scan = 0;
        while (scan = srv_sel.ScanLoop (scan, sel_ID, &pkt)) {
                pkt_trans.GetItem (pkt, item);
                if (Include (item))
                        return true;
        }

        return false;
}

        void
CLxItemSelection::GetList (
        ItemList		&list)
{
        CLxUser_Item		 item;
        LXtScanInfoID		 scan;
        void			*pkt;

        list.clear ();

        scan = 0;
        while (scan = srv_sel.ScanLoop (scan, sel_ID, &pkt)) {
                pkt_trans.GetItem (pkt, item);
                if (Include (item))
                        list.push_back (item);
        }
}

        void
CLxItemSelection::GetSet (
        ItemSet			&set)
{
        CLxUser_Item		 item;
        LXtScanInfoID		 scan;
        void			*pkt;

        set.clear ();

        scan = 0;
        while (scan = srv_sel.ScanLoop (scan, sel_ID, &pkt)) {
                pkt_trans.GetItem (pkt, item);
                if (Include (item))
                        set.insert (item);
        }
}

        void
CLxItemSelection::LoopInit ()
{
        GetList (tmp_list);
        tmp_idx = 0;
}

        void
CLxItemSelection::LoopStop ()
{
        tmp_list.clear ();
        tmp_idx = 0;
}

        bool
CLxItemSelection::LoopNext (
        CLxUser_Item		&item)
{
        if (tmp_idx < tmp_list.size ())
                return item.set (tmp_list[tmp_idx++]);

        LoopStop ();
        return false;
}

        void
CLxItemSelection::Drop ()
{
        srv_sel.Drop (sel_ID);
}

        void
CLxItemSelection::Clear ()
{
        srv_sel.Clear (sel_ID);
}

        void
CLxItemSelection::Select (
        CLxUser_Item		&item)
{
        srv_sel.Select (sel_ID, pkt_trans.Packet (item));
}

        void
CLxItemSelection::Deselect (
        CLxUser_Item		&item)
{
        srv_sel.Deselect (sel_ID, pkt_trans.Packet (item));
}


/*
 * ----------------------------------------------------------------
 * CLxItemSelectionType : Implementation
 */
CLxItemSelectionType::CLxItemSelectionType (
        const char		*typeName)
{
        CLxUser_SceneService	 svc;

        type = svc.ItemType (typeName);
}

        bool
CLxItemSelectionType::Include (
        CLxUser_Item		&item)
{
        return item.IsA (type);
}


/*
 * ----------------------------------------------------------------
 * CLxSceneSelection : Implementation
 */
CLxSceneSelection::CLxSceneSelection ()
{
        sel_ID = srv_sel.LookupType (LXsSELTYP_SCENE);
        pkt_trans.autoInit ();
}

        bool
CLxSceneSelection::Get (
        CLxUser_Scene		&scene)
{
        void			*pkt;

        pkt = srv_sel.Recent (sel_ID);
        return pkt_trans.GetScene (pkt, scene);
}

        bool
CLxSceneSelection::Get (
        CLxUser_ChannelRead	&evalChan)
{
        CLxUser_Scene		 scene;

        Get (scene);
        return scene.GetChannels (evalChan, srv_sel.GetTime ());
}

        bool
CLxSceneSelection::Get (
        CLxUser_ChannelRead	&actChan,
        const char		*action)
{
        CLxUser_Scene		 scene;

        Get (scene);
        if (!action)
                action = LXs_ACTIONLAYER_EDIT;

        return scene.GetChannels (actChan, action, srv_sel.GetTime ());
}


