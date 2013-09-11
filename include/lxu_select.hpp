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
 * Wrapper for accessing different selection types. These are objects that are meant
 * to be created by the client and used for traversing the selection for different
 * varieties of elements. A few allow customization by subclassing.
 */
#ifndef LXU_SELECT_HPP
#define LXU_SELECT_HPP

#include <lx_select.hpp>
#include <lx_seltypes.hpp>
#include <lx_action.hpp>
#include <lx_item.hpp>
#include <lx_mesh.hpp>
#include <vector>
#include <map>
#include <set>


/*
 * --------------------------------------------------------------
 * Vertex selection object.
 */
class CLxVertexSelection
{
    public:
        typedef std::vector<LXtPointID>			PointList;
        typedef std::vector<LXtPointID>::iterator	PointList_Itr;
        class MeshEntry {
            public:
                CLxUser_Mesh		 mesh;
                CLxUser_Item		 item;
                PointList		 list;
        };
        typedef std::vector<MeshEntry>			MeshList;
        typedef std::vector<MeshEntry>::iterator	MeshList_Itr;

        CLxUser_SelectionService	 srv_sel;
        CLxUser_VertexPacketTranslation	 pkt_trans;
        LXtID4				 sel_ID;
        LXtID4				 sel_comp[4];

                        CLxVertexSelection ();

        /*
         * Return true if there are any vertices directly or indirectly
         * selected.
         */
        bool		AnyDirect ();
        bool		AnyIndirect ();

        /*
         * Get the selected vertices as a nested list: the mesh items that contain
         * selected vertices, and for each the list of selected vertices.
         */
        void		GetDirectList (MeshList &);
};


/*
 * --------------------------------------------------------------
 * Vertex map selection object.
 */
class CLxVertexMapSelection
{
    public:
        class MapInfo {
            public:
                LXtID4			 type;
                std::string		 name;
        };
        typedef std::vector<MapInfo>		MapList;
        typedef std::vector<MapInfo>::iterator	MapList_Itr;

        CLxUser_SelectionService	 srv_sel;
        CLxUser_VMapPacketTranslation	 pkt_trans;
        LXtID4				 sel_ID;

                         CLxVertexMapSelection ();
        virtual		~CLxVertexMapSelection () {}

        /*
         * Get the first selected map, or return false if none.
         */
        bool		First (std::string &);

        /*
         * Get a complete list of selected maps, given by type and name.
         */
        void		GetList (MapList &);

        /*
         * The methods above can be limited to map types that pass this
         * test, which can be overridden by subclasses.
         */
        virtual bool	Include (LXtID4 type)
                        { return true; }
};


/*
 * --------------------------------------------------------------
 * Item selection object.
 */
class CLxItemSelection
{
    public:
        typedef std::vector<CLxUser_Item>		ItemList;
        typedef std::vector<CLxUser_Item>::iterator	ItemList_Itr;
        typedef std::set<CLxUser_Item>			ItemSet;
        typedef std::set<CLxUser_Item>::iterator	ItemSet_Itr;

        CLxUser_SelectionService	 srv_sel;
        CLxUser_ItemPacketTranslation	 pkt_trans;
        LXtID4				 sel_ID;
        ItemList			 tmp_list;
        unsigned			 tmp_idx;

                         CLxItemSelection ();
        virtual		~CLxItemSelection () {}

        /*
         * Get the first selected item, or return false if none.
         */
        bool		GetFirst (CLxUser_Item &);

        /*
         * Return collections of selected items.
         */
        void		GetList (ItemList &);
        void		GetSet  (ItemSet &);

        /*
         * To loop over items, call LoopInit() and then call LoopNext() as long as
         * it returns true. LoopStop() can be called for early exit.
         */
        void		LoopInit ();
        bool		LoopNext (CLxUser_Item &);
        void		LoopStop ();

        /*
         * All the methods above can be limited to items that pass the inclusion
         * test, which can be overridden by subclasses.
         */
        virtual bool	Include (CLxUser_Item &item)
                        { return true; }

        /*
         * Methods to manipulate the selection.
         */
        void		Drop     ();
        void		Clear    ();
        void		Select   (CLxUser_Item &);
        void		Deselect (CLxUser_Item &);
};

/*
 * --------------------------------------------------------------
 * Item selection object, filtered for a single item type.
 */
class CLxItemSelectionType :
                public CLxItemSelection
{
    public:
        LXtItemType			 type;

                        CLxItemSelectionType (const char *typeName);
        bool		Include (CLxUser_Item &);
};


/*
 * --------------------------------------------------------------
 * Scene selection object.
 */
class CLxSceneSelection
{
    public:
        CLxUser_SelectionService	 srv_sel;
        CLxUser_ScenePacketTranslation	 pkt_trans;
        LXtID4				 sel_ID;

                        CLxSceneSelection ();

        /*
         * Get the currently selected scene.
         */
        bool		Get (CLxUser_Scene &);

        /*
         * Get evaluated channels from the currently selected scene at the
         * current time.
         */
        bool		Get (CLxUser_ChannelRead &evalChan);

        /*
         * Get action values from the currently selected scene and named
         * action. If the name pointer is null the edit action is used.
         */
        bool		Get (CLxUser_ChannelRead &actChan, const char *action);
};


#endif	/* LXU_SELECT_HPP */

