/*
 * Plug-in SDK Header: C++ User Classes
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
 */
#ifndef LXUSER_value_HPP
#define LXUSER_value_HPP

#include <lxw_value.hpp>
#include <lxu_getstring.hpp>

class CLxUser_Value : public CLxLoc_Value
{
    public:
        CLxUser_Value () {}
        CLxUser_Value (ILxUnknownID obj) : CLxLoc_Value (obj) {}

                bool
        Clone (
                CLxUser_Value           &value)
        {
                LXtObjectID              obj;

                value.clear ();
                if (LXx_FAIL (CLxLoc_Value::Clone (&obj)))
                        return false;

                return value.take (obj);
        }

                int
        Compare (
                ILxUnknownID             other)
        {
                int                      diff;

                if (LXx_FAIL (CLxLoc_Value::Compare (other, &diff)))
                        return -1;

                return diff;
        }
                LxResult
        sgs_GetString (char *buf, unsigned int len)
        {
                return GetString (buf, len);
        }

                bool
        String (
                std::string             &text)
        {
                CLxSafeGetString<CLxUser_Value>  sgs;

                return sgs.GetStringBool (*this, text);
        }
};
class CLxUser_StringConversion : public CLxLoc_StringConversion
{
    public:
        CLxUser_StringConversion () {}
        CLxUser_StringConversion (ILxUnknownID obj) : CLxLoc_StringConversion (obj) {}

        class Tmp_Sgs {
            public:
                CLxLoc_StringConversion               *conv;

                LxResult sgs_GetString (char *buf, unsigned int len)
                {
                        return conv->Encode (buf, len);
                }
        };

                LxResult
        EncodeStr (
                std::string             &text)
        {
                Tmp_Sgs                          tmp;
                CLxSafeGetString<Tmp_Sgs>        sgs;

                tmp.conv = this;
                return sgs.GetString (tmp, text);
        }
};
class CLxUser_StringConversionNice : public CLxLoc_StringConversionNice
{
    public:
        CLxUser_StringConversionNice () {}
        CLxUser_StringConversionNice (ILxUnknownID obj) : CLxLoc_StringConversionNice (obj) {}

        class Tmp_Sgs {
            public:
                CLxLoc_StringConversionNice               *conv;

                LxResult sgs_GetString (char *buf, unsigned int len)
                {
                        return conv->Encode (buf, len);
                }
        };

                LxResult
        EncodeStr (
                std::string             &text)
        {
                Tmp_Sgs                          tmp;
                CLxSafeGetString<Tmp_Sgs>        sgs;

                tmp.conv = this;
                return sgs.GetString (tmp, text);
        }
};
class CLxUser_ValueMath : public CLxLoc_ValueMath
{
    public:
        CLxUser_ValueMath () {}
        CLxUser_ValueMath (ILxUnknownID obj) : CLxLoc_ValueMath (obj) {}


};
class CLxUser_ValueReference : public CLxLoc_ValueReference
{
    public:
        CLxUser_ValueReference () {}
        CLxUser_ValueReference (ILxUnknownID obj) : CLxLoc_ValueReference (obj) {}

                bool
        Get (
                CLxLocalizedObject      &loc)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (GetObject (&obj)))
                        return false;

                return loc.take (obj);
        }
};
class CLxUser_Attributes : public CLxLoc_Attributes
{
    public:
        CLxUser_Attributes () {}
        CLxUser_Attributes (ILxUnknownID obj) : CLxLoc_Attributes (obj) {}

                int
        FindIndex (
                const std::string       &name)
        {
                unsigned                 index;

                if (LXx_OK (Lookup (name.c_str (), &index)))
                        return index;
                else
                        return -1;
        }

                int
        FindIndex (
                const char              *name)
        {
                unsigned                 index;

                if (LXx_OK (Lookup (name, &index)))
                        return index;
                else
                        return -1;
        }

                int
        Type (
                unsigned                 index)
        {
                unsigned                 type;

                if (LXx_OK (CLxLoc_Attributes::Type (index, &type))) {
                        return type;
                }
                else {
                        return -1;
                }
        }

                bool
        Name (
                unsigned                 index,
                std::string             &name)
        {
                const char      *nameChars;
                bool             foundName;

                foundName = LXx_OK (CLxLoc_Attributes::Name (index, &nameChars));
                if (foundName) {
                        name = std::string (nameChars);
                        foundName = true;
                }
                else {
                        name = "";
                }

                return foundName;
        }

                bool
        Set (
                unsigned                 index,
                bool                     val)
        {
                return LXx_OK (SetInt (index, val ? 1 : 0));
        }

                bool
        Set (
                unsigned                 index,
                int                      val)
        {
                return LXx_OK (SetInt (index, val));
        }

                bool
        Set (
                unsigned                 index,
                double                   val)
        {
                return LXx_OK (SetFlt (index, val));
        }

                bool
        Set (
                unsigned                 index,
                const char              *val)
        {
                return LXx_OK (SetString (index, val));
        }
                bool
        Bool (
                unsigned                 index,
                bool                     preset = false)
        {
                int                      val;

                if (LXx_FAIL (GetInt (index, &val)))
                        return preset;

                return val ? true : false;
        }

                int
        Int (
                unsigned                 index,
                int                      preset = 0)
        {
                int                      val;

                if (LXx_FAIL (GetInt (index, &val)))
                        return preset;

                return val;
        }

                double
        Float (
                unsigned                 index,
                double                   preset = 0.0)
        {
                double                   val;

                if (LXx_FAIL (GetFlt (index, &val)))
                        return preset;

                return val;
        }

                bool
        Set (
                unsigned                 index,
                const std::string       &text)
        {
                return LXx_OK (SetString (index, text.c_str ()));
        }

        class Tmp_Sgs {
            public:
                CLxLoc_Attributes       *attr;
                unsigned                 index;

                LxResult sgs_GetString (char *buf, unsigned int len)
                {
                        return attr->GetString (index, buf, len);
                }
        };

                bool
        String (
                unsigned                 index,
                std::string             &text)
        {
                Tmp_Sgs                          tmp;
                CLxSafeGetString<Tmp_Sgs>        sgs;

                tmp.attr  = this;
                tmp.index = index;
                return sgs.GetStringBool (tmp, text);
        }
                bool
        ObjectRO (
                unsigned                 index,
                CLxLocalizedObject      &loc)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (Value (index, &obj, 0)))
                        return false;

                return loc.take (obj);
        }

                bool
        ObjectRW (
                unsigned                 index,
                CLxLocalizedObject      &loc)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (Value (index, &obj, 1)))
                        return false;

                return loc.take (obj);
        }
};
class CLxUser_Message : public CLxLoc_Message
{
    public:
        CLxUser_Message () {}
        CLxUser_Message (ILxUnknownID obj) : CLxLoc_Message (obj) {}

                bool
        SetArg (
                unsigned                 arg,
                int                      val)
        {
                return LXx_OK (SetArgumentInt (arg, val));
        }

                bool
        SetArg (
                unsigned                 arg,
                double                   val)
        {
                return LXx_OK (SetArgumentFloat (arg, val));
        }

                bool
        SetArg (
                unsigned                 arg,
                const char              *val)
        {
                return LXx_OK (SetArgumentString (arg, val));
        }
                bool
        SetMsg (
                const char              *table,
                unsigned                 id)
        {
                return LXx_OK (SetMessage (table, 0, id));
        }

                bool
        SetMsg (
                const char              *table,
                const char              *name)
        {
                return LXx_OK (SetMessage (table, name, 0));
        }
};
class CLxUser_ValueArray : public CLxLoc_ValueArray
{
    public:
        CLxUser_ValueArray () {}
        CLxUser_ValueArray (ILxUnknownID obj) : CLxLoc_ValueArray (obj) {}

                bool
        AddEmpty (
                CLxLocalizedObject      &val)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (AddEmptyValue (&obj)))
                        return false;

                return val.take (obj);
        }

                bool
        Add (
                CLxLoc_Value            &val)
        {
                return LXx_OK (AddValue (val));
        }

                bool
        Add (
                bool                     val)
        {
                return LXx_OK (AddInt (val ? 1 : 0));
        }

                bool
        Add (
                int                      val)
        {
                return LXx_OK (AddInt (val));
        }

                bool
        Add (
                double                   val)
        {
                return LXx_OK (AddFloat (val));
        }

                bool
        Add (
                const char              *val)
        {
                return LXx_OK (AddString (val));
        }
        class Tmp_Sgs {
            public:
                CLxLoc_ValueArray       *vary;
                unsigned                 index;

                LxResult sgs_GetString (char *buf, unsigned int len)
                {
                        return vary->GetString (index, buf, len);
                }
        };

                bool
        String (
                unsigned                 index,
                std::string             &text)
        {
                Tmp_Sgs                          tmp;
                CLxSafeGetString<Tmp_Sgs>        sgs;

                tmp.vary  = this;
                tmp.index = index;
                return sgs.GetStringBool (tmp, text);
        }
};
class CLxUser_ScriptQuery : public CLxLoc_ScriptQuery
{
    public:
        CLxUser_ScriptQuery () {}
        CLxUser_ScriptQuery (ILxUnknownID obj) : CLxLoc_ScriptQuery (obj) {}

                bool
        fromGlobal (
                LXtObjectID              obj)
        {
                ILxValueServiceID        srv = reinterpret_cast<ILxValueServiceID> (obj);

                if (LXx_OK (srv[0]->ScriptQuery (srv, &obj)))
                        return take (obj);

                clear ();
                return false;
        }
};
class CLxUser_StringTag : public CLxLoc_StringTag
{
    public:
        CLxUser_StringTag () {}
        CLxUser_StringTag (ILxUnknownID obj) : CLxLoc_StringTag (obj) {}

                const char *
        Value (
                LXtID4                   type)
        {
                const char              *tag;

                if (LXx_OK (Get (type, &tag)))
                        return tag;
                else
                        return 0;
        }
};
class CLxUser_Matrix : public CLxLoc_Matrix
{
    public:
        CLxUser_Matrix () {}
        CLxUser_Matrix (ILxUnknownID obj) : CLxLoc_Matrix (obj) {}


};
class CLxUser_ValueService : public CLxLoc_ValueService
{
    public:
        class Tmp_Sgs {
            public:
                CLxLoc_ValueService     *vsrv;
                const LXtTextValueHint  *hint;
                int                      value;

                LxResult sgs_GetString (char *buf, unsigned int len)
                {
                        return vsrv->TextHintEncode (value, hint, buf, len);
                }
        };

                bool
        EncodeHint (
                int                      value,
                const LXtTextValueHint  *hint,
                std::string             &text)
        {
                Tmp_Sgs                          tmp;
                CLxSafeGetString<Tmp_Sgs>        sgs;

                tmp.vsrv  = this;
                tmp.value = value;
                tmp.hint  = hint;
                return sgs.GetStringBool (tmp, text);
        }
                bool
        NewValue (
                CLxLocalizedObject      &value,
                const char              *type)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (CreateValue (type, &obj)))
                        return false;

                return value.take (obj);
        }
};



#endif

