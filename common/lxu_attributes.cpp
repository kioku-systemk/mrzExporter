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
 * Dynamic Attributes
 */

/*
 * Disable deprecated function warning.
 */
#pragma warning(disable: 4996)

#include <lxu_attributes.hpp>
#include <lxu_getstring.hpp>
#include <vector>
#include <string>

using namespace std;


/*
 * ----------------------------------------------------------------
 * CUIValueHintWrapper is used to export a client CLxDynamicUIValue as a COM
 * object. The methods are all just pass-throughs to the equivalent methods
 * in the client's object, with slightly nicer APIs.
 */
class CUIValueHintWrapper :
                public CLxImpl_UIValueHints
{
    public:
        CLxDynamicUIValue	*val;

        unsigned	uiv_Flags (void) LXx_OVERRIDE
        {
                return val->Flags ();
        }

        unsigned	uiv_PopCount (void) LXx_OVERRIDE
        {
                return val->PopCount ();
        }

        const char *	uiv_PopUserName (unsigned index) LXx_OVERRIDE
        {
                return val->PopUserName (index);
        }

        const char *	uiv_PopInternalName (unsigned index) LXx_OVERRIDE
        {
                return val->PopInternalName (index);
        }

        LxResult	uiv_PopFlags (unsigned index, int *flags) LXx_OVERRIDE
        {
                flags[0] = val->PopFlags (index);
                return LXe_OK;
        }

        LxResult	uiv_PopCategory (const char **category) LXx_OVERRIDE
        {
                category[0] = val->PopCategory ();
                return LXe_OK;
        }

        LxResult	uiv_PopIconSize (int *w, int *h) LXx_OVERRIDE
        {
                return val->PopIconSize (*w, *h);
        }

        LxResult	uiv_PopIconImage (int index, void **ppvObj) LXx_OVERRIDE
        {
                return val->PopIconImage ( index, ppvObj );
        }

        LxResult	uiv_PopIconResource (int index, const char **iconResource) LXx_OVERRIDE
        {
                return val->PopIconResource ( index, iconResource );
        }

        LxResult	uiv_ItemTest (ILxUnknownID item) LXx_OVERRIDE
        {
                CLxUser_Item		 ui (item);
                return val->ItemTest (ui) ? LXe_TRUE : LXe_FALSE;
        }

        LxResult	uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens) LXx_OVERRIDE
        {
                return LXe_NOTIMPL;
        }
};


/*
 * ----------------------------------------------------------------
 * DynaAttributes : Implementation
 *
 * Private data is a vector of DynaAttr structs containing an attribute name,
 * its type, optional text hints, and its value. Private data is allocated for
 * each instance of the class.
 */
class pv_DynaAttributes {
    public:
        typedef struct {
                string			 name;
                string			 type;
                const LXtTextValueHint	*hint;
                CLxUser_Value		 value;
                bool			 set;
        } DynaAttr;

        DynaAttr &		 Elt (unsigned int index);
        void			 Set (unsigned int index, bool value = true);

        LxResult		 sgs_GetString (char *buf, unsigned len);
        unsigned		 sgs_index;

        vector<DynaAttr>	 dlist;
};


CLxDynamicAttributes::CLxDynamicAttributes ()
{
        pv = new pv_DynaAttributes;
}

CLxDynamicAttributes::~CLxDynamicAttributes ()
{
        delete pv;
}


/*
 * The implementation is very easy, since we let nexus implement the
 * actual values. Adding a new value pushes one on the end of the struct,
 * including allocating a value of the given type.
 */
        void
CLxDynamicAttributes::dyna_Add (
        const char		*name,
        const char		*type)
{
        CLxUser_ValueService		 vs;
        pv_DynaAttributes::DynaAttr	 da;

        da.name  = name;
        da.type  = type;
        da.hint  = 0;
        da.set   = false;
        pv->dlist.push_back (da);

        vs.NewValue (pv->dlist.back().value, type);
}


/*
 * Private method to access the DynaAttr struct for a given index. This encapsulates
 * the out-of-bounds exception.
 */
        pv_DynaAttributes::DynaAttr &
pv_DynaAttributes::Elt (
        unsigned int		 index)
{
        if (index >= dlist.size ())
                throw (LXe_OUTOFBOUNDS);

        return dlist[index];
}


/*
 * Public method for accessing the value by index.
 */
        CLxUser_Value &
CLxDynamicAttributes::dyna_Value (
        unsigned int		 index)
{
        return pv->Elt (index) . value;
}


/*
 * Public method to read the 'set' flag, which is true if the value is not its
 * default, plus a private method to set it.
 */
        bool
CLxDynamicAttributes::dyna_IsSet (
        unsigned int		 index)
{
        return pv->Elt (index) . set;
}

        void
pv_DynaAttributes::Set (
        unsigned int		 index,
        bool			 value)
{
        Elt (index) . set = value;
}


/*
 * The text hints for any attribute can be set. Hints are assumed to be static.
 */
        void
CLxDynamicAttributes::dyna_SetHint (
        unsigned int		 index,
        const LXtTextValueHint	*hint)
{
        pv->Elt (index) . hint = hint;
}


/*
 * The type for an attribute can be changed on the fly. This will allocate a
 * new value of the given type. If the type is null it will still be re-allocated,
 * allowing the value to be reset to a default state.
 */
        void
CLxDynamicAttributes::dyna_SetType (
        unsigned int		 index,
        const char		*type)
{
        pv_DynaAttributes::DynaAttr	&da = pv->Elt (index);
        CLxUser_ValueService		 vs;
        std::string			 tmp;

        if (!type) {
                tmp  = da.type;
                type = tmp.c_str();

        } else if (da.type.compare (type) == 0)
                return;

        da.type = type;
        da.set  = false;
        vs.NewValue (da.value, type);
}


/*
 * These methods implement the actual ILxAttributes interface. Querying the
 * actual list just uses the vector more or less directly.
 */
        unsigned int
CLxDynamicAttributes::attr_Count ()
{
        return static_cast<unsigned int>(pv->dlist.size());
}

        LxResult
CLxDynamicAttributes::attr_Name (
        unsigned int		 index,
        const char	       **name)
{
        name[0] = pv->Elt (index) . name.c_str ();
        return LXe_OK;
}

        LxResult
CLxDynamicAttributes::attr_Type (
        unsigned int		 index,
        unsigned int		*type)
{
        type[0] = dyna_Value (index) . Type ();
        return LXe_OK;
}

        LxResult
CLxDynamicAttributes::attr_TypeName (
        unsigned int		 index,
        const char	       **tname)
{
        tname[0] = pv->Elt (index) . type.c_str ();
        return LXe_OK;
}

        LxResult
CLxDynamicAttributes::attr_Lookup (
        const char		*name,
        unsigned int		*index)
{
        for (*index = 0; *index < pv->dlist.size (); index[0]++)
                if (!pv->dlist[*index].name.compare (name))
                        return LXe_OK;

        return LXe_NOTFOUND;
}

        const LXtTextValueHint *
CLxDynamicAttributes::attr_Hints (
        unsigned int		 index)
{
        return pv->Elt (index) . hint;
}


/*
 * For reading and writing values, all the hard work is deferred to the allocated
 * value object.
 */
        LxResult
CLxDynamicAttributes::attr_Value (
        unsigned int		 index,
        void		       **ppvObj,
        int			 writeOK)
{
        if (writeOK)
                pv->Set (index);

        dyna_Value (index) . get (ppvObj);
        return LXe_OK;
}

        LxResult
CLxDynamicAttributes::attr_GetBool (
        unsigned int		 index,
        bool			*val)
{
        int value;
        LxResult result = dyna_Value (index) . GetInt (&value);
        *val = value ? true : false;

        return result;
}

        LxResult
CLxDynamicAttributes::attr_SetBool (
        unsigned int		 index,
        bool			 val)
{
        int			 value = val ? 1 : 0;

        pv->Set (index);
        return dyna_Value (index) . SetInt (value);
}

        LxResult
CLxDynamicAttributes::attr_GetInt (
        unsigned int		 index,
        int			*val)
{
        return dyna_Value (index) . GetInt (val);
}

        LxResult
CLxDynamicAttributes::attr_SetInt (
        unsigned int		 index,
        int			 val)
{
        pv->Set (index);
        return dyna_Value (index) . SetInt (val);
}

        LxResult
CLxDynamicAttributes::attr_GetFlt (
        unsigned int		 index,
        double			*val)
{
        return dyna_Value (index) . GetFlt (val);
}

        LxResult
CLxDynamicAttributes::attr_SetFlt (
        unsigned int		 index,
        double			 val)
{
        pv->Set (index);
        return dyna_Value (index) . SetFlt (val);
}

        LxResult
CLxDynamicAttributes::attr_GetString (
        unsigned int		 index,
        char			*val,
        unsigned int		 len)
{
        return dyna_Value (index) . GetString (val, len);
}

        LxResult
CLxDynamicAttributes::attr_SetString (
        unsigned int		 index,
        const char		*val)
{
        pv->Set (index);
        return dyna_Value (index) . SetString (val);
}


/*
 * These methods take defaults, which are returned if the attribute is unset.
 */
        bool
CLxDynamicAttributes::dyna_Bool (
        unsigned int		 index,
        bool			 value)
{
        if (dyna_IsSet (index))
                attr_GetBool (index, &value);

        return value;
}

        int
CLxDynamicAttributes::dyna_Int (
        unsigned int		 index,
        int			 value)
{
        if (dyna_IsSet (index))
                attr_GetInt (index, &value);

        return value;
}

        double
CLxDynamicAttributes::dyna_Float (
        unsigned int		 index,
        double			 value)
{
        if (dyna_IsSet (index))
                attr_GetFlt (index, &value);

        return value;
}

        bool
CLxDynamicAttributes::dyna_String (
        unsigned int		 index,
        std::string		&text,
        const char		*value)
{
        if (!dyna_IsSet (index)) {
                text = value;
                return true;
        } else
                return dyna_Value (index) . String (text);
}

        bool
CLxDynamicAttributes::dyna_Object (
        unsigned int		 index,
        CLxLocalizedObject	&loc)
{
        if (!dyna_IsSet (index))
                return false;

        return loc.set (dyna_Value (index));
}



/*
 * The safe version of GetString, the one that returns the result as a
 * dynamic string object, relies on a special named method in the private
 * class.
 */
        LxResult
pv_DynaAttributes::sgs_GetString (
        char			*buf,
        unsigned		 len)
{
        return Elt (sgs_index) . value . GetString (buf, len);
}

        LxResult
CLxDynamicAttributes::attr_GetString (
        unsigned int		 index,
        std::string		&value)
{
        CLxSafeGetString<pv_DynaAttributes> sgs;

        pv->sgs_index = index;
        return sgs.GetString (*pv, value);
}


/*
 * The ILxAttributeUI interface allows attributes to have features specific
 * to their presentation in the UI. In this case we just wrap the raw objects 
 * as nice interfaces and pass them on.
 */
        LxResult
CLxDynamicAttributes::atrui_UIHints (
        unsigned int		 index,
        ILxUnknownID		 hints)
{
        CLxUser_UIHints		 uiHints (hints);

        atrui_UIHints (index, uiHints);
        return LXe_OK;
}

        LxResult
CLxDynamicAttributes::atrui_DisableMsg (
        unsigned int		 index,
        ILxUnknownID		 msg)
{
        CLxUser_Message		 message (msg);

        if (!atrui_Enabled (index, message))
                message.SetCode (LXe_DISABLED);

        return message.Code ();
}


/*
 * To create UIValueHint objects we need a factory to spawn the COM objects
 * from. We create it the first time it's needed.
 *
 * NOTE: need a way to free this on shutdown. Or, since modules are never unloaded
 * and C++ objects don't show up in the unfreed memory trace, why bother?
 */
 	LxResult
CLxDynamicAttributes::atrui_UIValueHints (
        unsigned int		 index,
        void		       **ppvObj)
{
        static CLxPolymorph<CUIValueHintWrapper>	*valFactory = 0;

        CUIValueHintWrapper	*wrap;
        CLxDynamicUIValue	*val;

        val = atrui_UIValue (index);
        if (!val)
                return LXe_NOTIMPL;

        if (!valFactory) {
                valFactory = new CLxPolymorph<CUIValueHintWrapper>;
                valFactory->AddInterface (new CLxIfc_UIValueHints<CUIValueHintWrapper>);
        }

        wrap = valFactory->Alloc (ppvObj);
        wrap->val = val;
        return LXe_OK;
}



/*
 * ----------------------------------------------------------------
 * CLxUIListPopup : Implementation
 *
 * We update the lists on any call to count. This is probably redundant, but it
 * assures that the lists are always up to date.
 */
        unsigned
CLxUIListPopup::Flags ()
{
        return LXfVALHINT_POPUPS;
}

        unsigned
CLxUIListPopup::PopCount ()
{
        user_list.clear ();
        internal_list.clear ();
        UpdateLists ();

        return user_list.size ();
}

        const char *
CLxUIListPopup::PopUserName (
        unsigned		 index)
{
        if (index < user_list.size ())
                return user_list[index].c_str ();

        return "*O*O*B*";
}

        const char *
CLxUIListPopup::PopInternalName (
        unsigned		 index)
{
        if (index < internal_list.size ())
                return internal_list[index].c_str ();

        if (index < user_list.size ())
                return user_list[index].c_str ();

        return "*O*O*B*";
}


