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
 * Dynamic Attributes
 */
#ifndef LXU_ATTRIBUTES_HPP
#define LXU_ATTRIBUTES_HPP

#include <lx_command.hpp>
#include <lx_value.hpp>
#include <lx_item.hpp>
#include <vector>
#include <string>


/*
 * ----------------------------------------------------------------
 * The DynamicUIValue class is a simpler form of the ILxUIValueHint interface,
 * allowing the client to define custom UI behaviors for an attribute. The Flags()
 * method must be defined to indicate which of the other method are used.
 */
class CLxDynamicUIValue
{
    public:
        virtual	~CLxDynamicUIValue () {}

        virtual unsigned	Flags () = 0;

        virtual unsigned	PopCount ()
                { return 0; }
        virtual const char *	PopUserName (unsigned index)
                { return 0; }
        virtual const char *	PopInternalName (unsigned index)
                { return 0; }
        virtual int		PopFlags (unsigned index)
                { return 0; }
        virtual bool		PopAlphaSort ()
                { return false; }
        virtual const char *	PopCategory ()
                { return 0; }
        virtual LxResult	PopIconSize ( int &w, int &h )
                { return LXe_NOTIMPL; }
        virtual LxResult	PopIconImage ( int index, void **ppvObj )
                { return LXe_NOTIMPL; }
        virtual LxResult	PopIconResource ( int index, const char **iconResource )
                { return LXe_NOTIMPL; }

        virtual bool		ItemTest (CLxUser_Item &item)
                { return true; }

        virtual LxResult	ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
                { return LXe_NOTIMPL; }

        virtual LxResult	NotifierCount (int *count)
                { return LXe_NOTIMPL; }

        virtual LxResult	NotifierByIndex (int index, const char **name, const char **args)
                { return LXe_NOTIMPL; }

        virtual LxResult	FormCommandListCount (int *count)
                { return LXe_NOTIMPL; }

        virtual LxResult	FormCommandListByIndex (int index, const char **command)
                { return LXe_NOTIMPL; }
};


/*
 * ----------------------------------------------------------------
 * A common specialization of the DynamicUIValue class allows the client to
 * present a simple popup list. The client customizes the list by wrting a
 * function to populate the user list. If set, the list of internal names
 * should be the same length as the user names.
 */
class CLxUIListPopup : public CLxDynamicUIValue
{
    public:
        std::vector<std::string>	 user_list, internal_list;

        virtual void		UpdateLists () = 0;

        unsigned		Flags ()			LXx_OVERRIDE;
        unsigned		PopCount ()			LXx_OVERRIDE;
        const char *		PopUserName (unsigned)		LXx_OVERRIDE;
        const char *		PopInternalName (unsigned)	LXx_OVERRIDE;
};



/*
 * ----------------------------------------------------------------
 * The DynamicAttributes class is an implementation of ILxAttributes that
 * can be used by clients. All the client has to do is add attributes in
 * the order they want, set their flags and hints, if any, and the rest
 * is automatic. It also supports the command methods needed to implement
 * a command, 
 */
class CLxDynamicAttributes :
        public CLxImpl_Attributes,
        public CLxImpl_AttributesUI
{
    public:
         CLxDynamicAttributes();
        ~CLxDynamicAttributes();

        void		dyna_Add      (const char *name, const char *type);
        void		dyna_SetHint  (unsigned int index, const LXtTextValueHint *hint);
        CLxUser_Value &	dyna_Value    (unsigned int index);
        void		dyna_SetType  (unsigned int index, const char *type);
        bool		dyna_IsSet    (unsigned int index);

        bool		dyna_Bool     (unsigned int index, bool   value = false);
        int		dyna_Int      (unsigned int index, int    value = 0);
        double		dyna_Float    (unsigned int index, double value = 0.0);
        bool		dyna_String   (unsigned int index, std::string &text, const char *value = "");
        bool		dyna_Object   (unsigned int index, CLxLocalizedObject &);

        unsigned int	attr_Count    ()					LXx_OVERRIDE;
        LxResult	attr_Name     (unsigned int index, const char **name)	LXx_OVERRIDE;
        LxResult	attr_Lookup   (const char *name, unsigned int *index)	LXx_OVERRIDE;
        LxResult	attr_Type     (unsigned int index, unsigned int *type)	LXx_OVERRIDE;
        LxResult	attr_TypeName (unsigned int index, const char **tname)	LXx_OVERRIDE;
        const LXtTextValueHint *
                        attr_Hints    (unsigned int index)			LXx_OVERRIDE;

        LxResult	attr_Value     (unsigned int index, void **ppvObj, int writeOK)	 LXx_OVERRIDE;
        LxResult	attr_GetInt    (unsigned int index, int *val)			 LXx_OVERRIDE;
        LxResult	attr_SetInt    (unsigned int index, int val)			 LXx_OVERRIDE;
        LxResult	attr_GetFlt    (unsigned int index, double *val)		 LXx_OVERRIDE;
        LxResult	attr_SetFlt    (unsigned int index, double val)			 LXx_OVERRIDE;
        LxResult	attr_GetString (unsigned int index, char *val, unsigned int len) LXx_OVERRIDE;
        LxResult	attr_SetString (unsigned int index, const char *val)		 LXx_OVERRIDE;

        LxResult	attr_GetBool   (unsigned int index, bool *val);
        LxResult	attr_SetBool   (unsigned int index, bool val);
        LxResult	attr_GetString (unsigned int index, std::string &value);

        virtual bool	atrui_Enabled  (unsigned int index, CLxUser_Message &msg)   { return true; }
        virtual void	atrui_UIHints  (unsigned int index, CLxUser_UIHints &hints) { }
        virtual CLxDynamicUIValue *
                        atrui_UIValue  (unsigned int index) { return 0; }

 	LxResult	atrui_DisableMsg   (unsigned int index, ILxUnknownID msg)   LXx_OVERRIDE;
 	LxResult	atrui_UIHints      (unsigned int index, ILxUnknownID hints) LXx_OVERRIDE;
 	LxResult	atrui_UIValueHints (unsigned int index, void **ppvObj)      LXx_OVERRIDE;

    private:
        class pv_DynaAttributes	*pv;
};


#endif /* LX_ATTRIBUTES_HPP */

