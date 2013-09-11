/*
 * C++ wrapper for lxvalue.h
 *
 *	Copyright (c) 2008-2012 Luxology LLC
 *	
 *	Permission is hereby granted, free of charge, to any person obtaining a
 *	copy of this software and associated documentation files (the "Software"),
 *	to deal in the Software without restriction, including without limitation
 *	the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *	and/or sell copies of the Software, and to permit persons to whom the
 *	Software is furnished to do so, subject to the following conditions:
 *	
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.   Except as contained
 *	in this notice, the name(s) of the above copyright holders shall not be
 *	used in advertising or otherwise to promote the sale, use or other dealings
 *	in this Software without prior written authorization.
 *	
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *	DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef LXW_VALUE_HPP
#define LXW_VALUE_HPP

#include <lxvalue.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_StringConversion = {0x5CB3EEDB,0xE4E0,0x499E,0xB0,0xBA,0xA7,0xFB,0x51,0xBA,0xBE,0x3C};
    static const LXtGUID guid_Value = {0x62E1DBE9,0x2FFE,0x4B5C,0xB2,0x86,0xE5,0x4E,0x79,0x41,0x53,0x03};
    static const LXtGUID guid_ValueService = {0xDD2C3059,0x2CD0,0x4c7d,0x86,0x0C,0xCF,0x35,0x3C,0xFB,0x2F,0x92};
    static const LXtGUID guid_Matrix = {0xEF9FDE7B,0xE7FA,0x48B2,0x83,0x8E,0xA5,0xA8,0xF7,0xD5,0xC2,0x54};
    static const LXtGUID guid_ValueArray = {0xA964962F,0x9028,0x4CA3,0x96,0x12,0x17,0xD3,0x60,0xDF,0x92,0xBA};
    static const LXtGUID guid_ScriptQuery = {0x0434F07E,0xAD4A,0x492f,0xAD,0x43,0x32,0x49,0xBD,0x16,0x99,0x4D};
    static const LXtGUID guid_ValueMath = {0x752B4D2E,0x6F13,0x4B2C,0xB0,0xB3,0x0B,0xA8,0xCA,0x6B,0x06,0x92};
    static const LXtGUID guid_StringConversionNice = {0x5407328B,0xDE99,0x4F15,0x86,0x6F,0xF6,0xE2,0x14,0xFF,0xA4,0x12};
    static const LXtGUID guid_ValueReference = {0x0567BC88,0xF782,0x426E,0x98,0xC5,0x83,0x02,0xFD,0x52,0xD9,0xE4};
    static const LXtGUID guid_Attributes = {0x117957D0,0x5A13,0x11D7,0xA1,0x8C,0x00,0x0A,0x95,0x76,0x5C,0x9E};
    static const LXtGUID guid_Message = {0xDDDBF46A,0x0865,0x4AB7,0x99,0x62,0x72,0xE7,0xB4,0x77,0xFD,0x22};
    static const LXtGUID guid_Visitor = {0xC8FCAD70,0xDDDF,0x499E,0xA0,0x3B,0xA0,0x8B,0x90,0x6D,0x3E,0x53};
    static const LXtGUID guid_StringTag = {0xC2004BC7,0x6A90,0x4BD3,0xBD,0xF7,0xB3,0x75,0xC7,0x90,0xDB,0x70};
};

class CLxImpl_StringConversion {
  public:
    virtual ~CLxImpl_StringConversion() {}
    virtual LxResult
      str_Encode (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      str_Decode (const char *buf)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_StringConversion : public CLxInterface
{
    static LxResult
  Encode (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_StringConversion, loc);
    try {
      return loc->str_Encode (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Decode (LXtObjectID wcom, const char *buf)
  {
    LXCWxINST (CLxImpl_StringConversion, loc);
    try {
      return loc->str_Decode (buf);
    } catch (LxResult rc) { return rc; }
  }
  ILxStringConversion vt;
public:
  CLxIfc_StringConversion ()
  {
    vt.Encode = Encode;
    vt.Decode = Decode;
    vTable = &vt.iunk;
    iid = &lx::guid_StringConversion;
  }
};
class CLxLoc_StringConversion : public CLxLocalize<ILxStringConversionID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_StringConversion() {_init();}
  CLxLoc_StringConversion(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_StringConversion(const CLxLoc_StringConversion &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_StringConversion;}
    LxResult
  Encode (char *buf, int len) const
  {
    return m_loc[0]->Encode (m_loc,buf,len);
  }
    LxResult
  Decode (const char *buf)
  {
    return m_loc[0]->Decode (m_loc,buf);
  }
};

class CLxImpl_Value {
  public:
    virtual ~CLxImpl_Value() {}
    virtual LxResult
      val_Clone (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_Copy (ILxUnknownID from)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_Compare (ILxUnknownID other, int *diff)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      val_Type (void)
        = 0;
    virtual LxResult
      val_GetInt (int *val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_SetInt (int val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_GetFlt (double *val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_SetFlt (double val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_GetString (char *val, unsigned int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_SetString (const char *val)
        { return LXe_NOTIMPL; }
    virtual void *
      val_Intrinsic (void)
        { return 0; }
};
template <class T>
class CLxIfc_Value : public CLxInterface
{
    static LxResult
  Clone (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_Clone (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Copy (LXtObjectID wcom, LXtObjectID from)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_Copy ((ILxUnknownID)from);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Compare (LXtObjectID wcom, LXtObjectID other, int *diff)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_Compare ((ILxUnknownID)other,diff);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  Type (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Value, loc);
    return loc->val_Type ();
  }
    static LxResult
  GetInt (LXtObjectID wcom, int *val)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_GetInt (val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetInt (LXtObjectID wcom, int val)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_SetInt (val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetFlt (LXtObjectID wcom, double *val)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_GetFlt (val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetFlt (LXtObjectID wcom, double val)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_SetFlt (val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetString (LXtObjectID wcom, char *val, unsigned int len)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_GetString (val,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetString (LXtObjectID wcom, const char *val)
  {
    LXCWxINST (CLxImpl_Value, loc);
    try {
      return loc->val_SetString (val);
    } catch (LxResult rc) { return rc; }
  }
    static void *
  Intrinsic (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Value, loc);
    return loc->val_Intrinsic ();
  }
  ILxValue vt;
public:
  CLxIfc_Value ()
  {
    vt.Clone = Clone;
    vt.Copy = Copy;
    vt.Compare = Compare;
    vt.Type = Type;
    vt.GetInt = GetInt;
    vt.SetInt = SetInt;
    vt.GetFlt = GetFlt;
    vt.SetFlt = SetFlt;
    vt.GetString = GetString;
    vt.SetString = SetString;
    vt.Intrinsic = Intrinsic;
    vTable = &vt.iunk;
    iid = &lx::guid_Value;
  }
};
class CLxLoc_Value : public CLxLocalize<ILxValueID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Value() {_init();}
  CLxLoc_Value(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Value(const CLxLoc_Value &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Value;}
    LxResult
  Clone (void **ppvObj)
  {
    return m_loc[0]->Clone (m_loc,ppvObj);
  }
    LxResult
  Copy (ILxUnknownID from)
  {
    return m_loc[0]->Copy (m_loc,(ILxUnknownID)from);
  }
    LxResult
  Compare (ILxUnknownID other, int *diff) const
  {
    return m_loc[0]->Compare (m_loc,(ILxUnknownID)other,diff);
  }
    unsigned int
  Type (void) const
  {
    return m_loc[0]->Type (m_loc);
  }
    LxResult
  GetInt (int *val) const
  {
    return m_loc[0]->GetInt (m_loc,val);
  }
    LxResult
  SetInt (int val)
  {
    return m_loc[0]->SetInt (m_loc,val);
  }
    LxResult
  GetFlt (double *val) const
  {
    return m_loc[0]->GetFlt (m_loc,val);
  }
    LxResult
  SetFlt (double val)
  {
    return m_loc[0]->SetFlt (m_loc,val);
  }
    LxResult
  GetString (char *val, unsigned int len) const
  {
    return m_loc[0]->GetString (m_loc,val,len);
  }
    LxResult
  SetString (const char *val)
  {
    return m_loc[0]->SetString (m_loc,val);
  }
    void *
  Intrinsic (void) const
  {
    return m_loc[0]->Intrinsic (m_loc);
  }
};

class CLxLoc_ValueService : public CLxLocalizedService
{
  ILxValueServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_ValueService() {_init();set();}
 ~CLxLoc_ValueService() {}
  void set() {m_loc=reinterpret_cast<ILxValueServiceID>(lx::GetGlobal(&lx::guid_ValueService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  TextHintEncode (int value, const LXtTextValueHint *hint, char *buf, unsigned bufLen)
  {
    return m_loc[0]->TextHintEncode (m_loc,value,hint,buf,bufLen);
  }
    LxResult
  TextHintDecode (const char *buf, const LXtTextValueHint *hint, int *value)
  {
    return m_loc[0]->TextHintDecode (m_loc,buf,hint,value);
  }
    LxResult
  CreateValue (const char *type, void **ppvObj)
  {
    return m_loc[0]->CreateValue (m_loc,type,ppvObj);
  }
};

class CLxLoc_Matrix : public CLxLocalize<ILxMatrixID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Matrix() {_init();}
  CLxLoc_Matrix(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Matrix(const CLxLoc_Matrix &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Matrix;}
    LxResult
  Get3 (LXtMatrix mat3) const
  {
    return m_loc[0]->Get3 (m_loc,mat3);
  }
    LxResult
  Get4 (LXtMatrix4 mat4) const
  {
    return m_loc[0]->Get4 (m_loc,mat4);
  }
    LxResult
  GetOffset (LXtVector offset) const
  {
    return m_loc[0]->GetOffset (m_loc,offset);
  }
    LxResult
  MultiplyVector (const LXtVector vector, LXtVector result) const
  {
    return m_loc[0]->MultiplyVector (m_loc,vector,result);
  }
    LxResult
  Set3 (const LXtMatrix mat3)
  {
    return m_loc[0]->Set3 (m_loc,mat3);
  }
    LxResult
  Set4 (const LXtMatrix4 mat4)
  {
    return m_loc[0]->Set4 (m_loc,mat4);
  }
    LxResult
  SetOffset (const LXtVector offset)
  {
    return m_loc[0]->SetOffset (m_loc,offset);
  }
    LxResult
  SetIdentity (void)
  {
    return m_loc[0]->SetIdentity (m_loc);
  }
    LxResult
  Multiply3 (LXtMatrix mat3)
  {
    return m_loc[0]->Multiply3 (m_loc,mat3);
  }
    LxResult
  Multiply4 (LXtMatrix4 mat4)
  {
    return m_loc[0]->Multiply4 (m_loc,mat4);
  }
    LxResult
  Invert (void)
  {
    return m_loc[0]->Invert (m_loc);
  }
    LxResult
  Transpose (void)
  {
    return m_loc[0]->Transpose (m_loc);
  }
};

class CLxImpl_ValueArray {
  public:
    virtual ~CLxImpl_ValueArray() {}
    virtual LxResult
      va_Type (unsigned int *type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_TypeName (const char **name)
        { return LXe_NOTIMPL; }
    virtual unsigned int
      va_Count (void)
        = 0;
    virtual LxResult
      va_AddEmptyValue (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_AddValue (ILxUnknownID value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_AddInt (int value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_AddFloat (double value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_AddString (const char *value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_GetValue (unsigned int index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_GetInt (unsigned int index, int *value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_GetFloat (unsigned int index, double *value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_GetString (unsigned int index, char *value, unsigned int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_FirstUnique (unsigned int *uniqueIndex)
        { return LXe_NOTIMPL; }
    virtual LxResult
      va_Reset (void)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_ValueArray : public CLxInterface
{
    static LxResult
  Type (LXtObjectID wcom, unsigned int *type)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_Type (type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TypeName (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_TypeName (name);
    } catch (LxResult rc) { return rc; }
  }
    static unsigned int
  Count (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    return loc->va_Count ();
  }
    static LxResult
  AddEmptyValue (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_AddEmptyValue (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddValue (LXtObjectID wcom, LXtObjectID value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_AddValue ((ILxUnknownID)value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddInt (LXtObjectID wcom, int value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_AddInt (value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddFloat (LXtObjectID wcom, double value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_AddFloat (value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  AddString (LXtObjectID wcom, const char *value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_AddString (value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetValue (LXtObjectID wcom, unsigned int index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_GetValue (index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetInt (LXtObjectID wcom, unsigned int index, int *value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_GetInt (index,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetFloat (LXtObjectID wcom, unsigned int index, double *value)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_GetFloat (index,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetString (LXtObjectID wcom, unsigned int index, char *value, unsigned int len)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_GetString (index,value,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FirstUnique (LXtObjectID wcom, unsigned int *uniqueIndex)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_FirstUnique (uniqueIndex);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Reset (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ValueArray, loc);
    try {
      return loc->va_Reset ();
    } catch (LxResult rc) { return rc; }
  }
  ILxValueArray vt;
public:
  CLxIfc_ValueArray ()
  {
    vt.Type = Type;
    vt.TypeName = TypeName;
    vt.Count = Count;
    vt.AddEmptyValue = AddEmptyValue;
    vt.AddValue = AddValue;
    vt.AddInt = AddInt;
    vt.AddFloat = AddFloat;
    vt.AddString = AddString;
    vt.GetValue = GetValue;
    vt.GetInt = GetInt;
    vt.GetFloat = GetFloat;
    vt.GetString = GetString;
    vt.FirstUnique = FirstUnique;
    vt.Reset = Reset;
    vTable = &vt.iunk;
    iid = &lx::guid_ValueArray;
  }
};
class CLxLoc_ValueArray : public CLxLocalize<ILxValueArrayID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ValueArray() {_init();}
  CLxLoc_ValueArray(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ValueArray(const CLxLoc_ValueArray &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ValueArray;}
    LxResult
  Type (unsigned int *type)
  {
    return m_loc[0]->Type (m_loc,type);
  }
    LxResult
  TypeName (const char **name)
  {
    return m_loc[0]->TypeName (m_loc,name);
  }
    unsigned int
  Count (void)
  {
    return m_loc[0]->Count (m_loc);
  }
    LxResult
  AddEmptyValue (void **ppvObj)
  {
    return m_loc[0]->AddEmptyValue (m_loc,ppvObj);
  }
    LxResult
  AddValue (ILxUnknownID value)
  {
    return m_loc[0]->AddValue (m_loc,(ILxUnknownID)value);
  }
    LxResult
  AddInt (int value)
  {
    return m_loc[0]->AddInt (m_loc,value);
  }
    LxResult
  AddFloat (double value)
  {
    return m_loc[0]->AddFloat (m_loc,value);
  }
    LxResult
  AddString (const char *value)
  {
    return m_loc[0]->AddString (m_loc,value);
  }
    LxResult
  GetValue (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->GetValue (m_loc,index,ppvObj);
  }
    LxResult
  GetInt (unsigned int index, int *value)
  {
    return m_loc[0]->GetInt (m_loc,index,value);
  }
    LxResult
  GetFloat (unsigned int index, double *value)
  {
    return m_loc[0]->GetFloat (m_loc,index,value);
  }
    LxResult
  GetString (unsigned int index, char *value, unsigned int len)
  {
    return m_loc[0]->GetString (m_loc,index,value,len);
  }
    LxResult
  FirstUnique (unsigned int *uniqueIndex)
  {
    return m_loc[0]->FirstUnique (m_loc,uniqueIndex);
  }
    LxResult
  Reset (void)
  {
    return m_loc[0]->Reset (m_loc);
  }
};

class CLxImpl_ScriptQuery {
  public:
    virtual ~CLxImpl_ScriptQuery() {}
    virtual LxResult
      sq_Select (const char *attribute, const char *which)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sq_Query (const char *attribute, ILxUnknownID query)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sq_Type (const char *attribute, int *type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sq_TypeName (const char *attribute, const char **type)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_ScriptQuery : public CLxInterface
{
    static LxResult
  Select (LXtObjectID wcom, const char *attribute, const char *which)
  {
    LXCWxINST (CLxImpl_ScriptQuery, loc);
    try {
      return loc->sq_Select (attribute,which);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Query (LXtObjectID wcom, const char *attribute, LXtObjectID query)
  {
    LXCWxINST (CLxImpl_ScriptQuery, loc);
    try {
      return loc->sq_Query (attribute,(ILxUnknownID)query);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Type (LXtObjectID wcom, const char *attribute, int *type)
  {
    LXCWxINST (CLxImpl_ScriptQuery, loc);
    try {
      return loc->sq_Type (attribute,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TypeName (LXtObjectID wcom, const char *attribute, const char **type)
  {
    LXCWxINST (CLxImpl_ScriptQuery, loc);
    try {
      return loc->sq_TypeName (attribute,type);
    } catch (LxResult rc) { return rc; }
  }
  ILxScriptQuery vt;
public:
  CLxIfc_ScriptQuery ()
  {
    vt.Select = Select;
    vt.Query = Query;
    vt.Type = Type;
    vt.TypeName = TypeName;
    vTable = &vt.iunk;
    iid = &lx::guid_ScriptQuery;
  }
};
class CLxLoc_ScriptQuery : public CLxLocalize<ILxScriptQueryID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ScriptQuery() {_init();}
  CLxLoc_ScriptQuery(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ScriptQuery(const CLxLoc_ScriptQuery &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ScriptQuery;}
    LxResult
  Select (const char *attribute, const char *which)
  {
    return m_loc[0]->Select (m_loc,attribute,which);
  }
    LxResult
  Query (const char *attribute, ILxUnknownID query)
  {
    return m_loc[0]->Query (m_loc,attribute,(ILxUnknownID)query);
  }
    LxResult
  Type (const char *attribute, int *type)
  {
    return m_loc[0]->Type (m_loc,attribute,type);
  }
    LxResult
  TypeName (const char *attribute, const char **type)
  {
    return m_loc[0]->TypeName (m_loc,attribute,type);
  }
};

class CLxImpl_ValueMath {
  public:
    virtual ~CLxImpl_ValueMath() {}
    virtual LxResult
      val_Step (int direction)
        { return LXe_NOTIMPL; }
    virtual int
      val_Detent (void)
        = 0;
    virtual LxResult
      val_Add (double delta)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_Multiply (double factor)
        { return LXe_NOTIMPL; }
    virtual LxResult
      val_Blend (ILxUnknownID other, double blend)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_ValueMath : public CLxInterface
{
    static LxResult
  Step (LXtObjectID wcom, int direction)
  {
    LXCWxINST (CLxImpl_ValueMath, loc);
    try {
      return loc->val_Step (direction);
    } catch (LxResult rc) { return rc; }
  }
    static int
  Detent (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ValueMath, loc);
    return loc->val_Detent ();
  }
    static LxResult
  Add (LXtObjectID wcom, double delta)
  {
    LXCWxINST (CLxImpl_ValueMath, loc);
    try {
      return loc->val_Add (delta);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Multiply (LXtObjectID wcom, double factor)
  {
    LXCWxINST (CLxImpl_ValueMath, loc);
    try {
      return loc->val_Multiply (factor);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Blend (LXtObjectID wcom, LXtObjectID other, double blend)
  {
    LXCWxINST (CLxImpl_ValueMath, loc);
    try {
      return loc->val_Blend ((ILxUnknownID)other,blend);
    } catch (LxResult rc) { return rc; }
  }
  ILxValueMath vt;
public:
  CLxIfc_ValueMath ()
  {
    vt.Step = Step;
    vt.Detent = Detent;
    vt.Add = Add;
    vt.Multiply = Multiply;
    vt.Blend = Blend;
    vTable = &vt.iunk;
    iid = &lx::guid_ValueMath;
  }
};
class CLxLoc_ValueMath : public CLxLocalize<ILxValueMathID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ValueMath() {_init();}
  CLxLoc_ValueMath(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ValueMath(const CLxLoc_ValueMath &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ValueMath;}
    LxResult
  Step (int direction)
  {
    return m_loc[0]->Step (m_loc,direction);
  }
    int
  Detent (void) const
  {
    return m_loc[0]->Detent (m_loc);
  }
    LxResult
  Add (double delta)
  {
    return m_loc[0]->Add (m_loc,delta);
  }
    LxResult
  Multiply (double factor)
  {
    return m_loc[0]->Multiply (m_loc,factor);
  }
    LxResult
  Blend (ILxUnknownID other, double blend)
  {
    return m_loc[0]->Blend (m_loc,(ILxUnknownID)other,blend);
  }
};

class CLxImpl_StringConversionNice {
  public:
    virtual ~CLxImpl_StringConversionNice() {}
    virtual LxResult
      nicestr_Encode (char *buf, int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      nicestr_Decode (const char *buf)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_StringConversionNice : public CLxInterface
{
    static LxResult
  Encode (LXtObjectID wcom, char *buf, int len)
  {
    LXCWxINST (CLxImpl_StringConversionNice, loc);
    try {
      return loc->nicestr_Encode (buf,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Decode (LXtObjectID wcom, const char *buf)
  {
    LXCWxINST (CLxImpl_StringConversionNice, loc);
    try {
      return loc->nicestr_Decode (buf);
    } catch (LxResult rc) { return rc; }
  }
  ILxStringConversionNice vt;
public:
  CLxIfc_StringConversionNice ()
  {
    vt.Encode = Encode;
    vt.Decode = Decode;
    vTable = &vt.iunk;
    iid = &lx::guid_StringConversionNice;
  }
};
class CLxLoc_StringConversionNice : public CLxLocalize<ILxStringConversionNiceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_StringConversionNice() {_init();}
  CLxLoc_StringConversionNice(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_StringConversionNice(const CLxLoc_StringConversionNice &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_StringConversionNice;}
    LxResult
  Encode (char *buf, int len) const
  {
    return m_loc[0]->Encode (m_loc,buf,len);
  }
    LxResult
  Decode (const char *buf)
  {
    return m_loc[0]->Decode (m_loc,buf);
  }
};

class CLxImpl_ValueReference {
  public:
    virtual ~CLxImpl_ValueReference() {}
    virtual LxResult
      val_IsSet (void)
        { return LXe_NOTIMPL; }
    virtual int
      val_GetObject (void **ppvObj)
        = 0;
    virtual LxResult
      val_SetObject (ILxUnknownID obj)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_ValueReference : public CLxInterface
{
    static LxResult
  IsSet (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_ValueReference, loc);
    try {
      return loc->val_IsSet ();
    } catch (LxResult rc) { return rc; }
  }
    static int
  GetObject (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_ValueReference, loc);
    return loc->val_GetObject (ppvObj);
  }
    static LxResult
  SetObject (LXtObjectID wcom, LXtObjectID obj)
  {
    LXCWxINST (CLxImpl_ValueReference, loc);
    try {
      return loc->val_SetObject ((ILxUnknownID)obj);
    } catch (LxResult rc) { return rc; }
  }
  ILxValueReference vt;
public:
  CLxIfc_ValueReference ()
  {
    vt.IsSet = IsSet;
    vt.GetObject = GetObject;
    vt.SetObject = SetObject;
    vTable = &vt.iunk;
    iid = &lx::guid_ValueReference;
  }
};
class CLxLoc_ValueReference : public CLxLocalize<ILxValueReferenceID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ValueReference() {_init();}
  CLxLoc_ValueReference(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ValueReference(const CLxLoc_ValueReference &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ValueReference;}
    LxResult
  IsSet (void) const
  {
    return m_loc[0]->IsSet (m_loc);
  }
    int
  GetObject (void **ppvObj) const
  {
    return m_loc[0]->GetObject (m_loc,ppvObj);
  }
    LxResult
  SetObject (ILxUnknownID obj)
  {
    return m_loc[0]->SetObject (m_loc,(ILxUnknownID)obj);
  }
};

class CLxImpl_Attributes {
  public:
    virtual ~CLxImpl_Attributes() {}
    virtual unsigned int
      attr_Count (void)
        { return 0; }
    virtual LxResult
      attr_Name (unsigned int index, const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_Lookup (const char *name, unsigned int *index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_Type (unsigned int index, unsigned int *type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_TypeName (unsigned int index, const char **tname)
        { return LXe_NOTIMPL; }
    virtual const LXtTextValueHint *
      attr_Hints (unsigned int index)
        { return 0; }
    virtual LxResult
      attr_Value (unsigned int index, void **ppvObj, int writeOK)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_GetInt (unsigned int index, int *val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_SetInt (unsigned int index, int val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_GetFlt (unsigned int index, double *val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_SetFlt (unsigned int index, double val)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_GetString (unsigned int index, char *val, unsigned int len)
        { return LXe_NOTIMPL; }
    virtual LxResult
      attr_SetString (unsigned int index, const char *val)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_Attributes : public CLxInterface
{
    static unsigned int
  Count (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    return loc->attr_Count ();
  }
    static LxResult
  Name (LXtObjectID wcom, unsigned int index, const char **name)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_Name (index,name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Lookup (LXtObjectID wcom, const char *name, unsigned int *index)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_Lookup (name,index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Type (LXtObjectID wcom, unsigned int index, unsigned int *type)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_Type (index,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  TypeName (LXtObjectID wcom, unsigned int index, const char **tname)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_TypeName (index,tname);
    } catch (LxResult rc) { return rc; }
  }
    static const LXtTextValueHint *
  Hints (LXtObjectID wcom, unsigned int index)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    return loc->attr_Hints (index);
  }
    static LxResult
  Value (LXtObjectID wcom, unsigned int index, void **ppvObj, int writeOK)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_Value (index,ppvObj,writeOK);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetInt (LXtObjectID wcom, unsigned int index, int *val)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_GetInt (index,val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetInt (LXtObjectID wcom, unsigned int index, int val)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_SetInt (index,val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetFlt (LXtObjectID wcom, unsigned int index, double *val)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_GetFlt (index,val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetFlt (LXtObjectID wcom, unsigned int index, double val)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_SetFlt (index,val);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  GetString (LXtObjectID wcom, unsigned int index, char *val, unsigned int len)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_GetString (index,val,len);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetString (LXtObjectID wcom, unsigned int index, const char *val)
  {
    LXCWxINST (CLxImpl_Attributes, loc);
    try {
      return loc->attr_SetString (index,val);
    } catch (LxResult rc) { return rc; }
  }
  ILxAttributes vt;
public:
  CLxIfc_Attributes ()
  {
    vt.Count = Count;
    vt.Name = Name;
    vt.Lookup = Lookup;
    vt.Type = Type;
    vt.TypeName = TypeName;
    vt.Hints = Hints;
    vt.Value = Value;
    vt.GetInt = GetInt;
    vt.SetInt = SetInt;
    vt.GetFlt = GetFlt;
    vt.SetFlt = SetFlt;
    vt.GetString = GetString;
    vt.SetString = SetString;
    vTable = &vt.iunk;
    iid = &lx::guid_Attributes;
  }
};
class CLxLoc_Attributes : public CLxLocalize<ILxAttributesID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Attributes() {_init();}
  CLxLoc_Attributes(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Attributes(const CLxLoc_Attributes &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Attributes;}
    unsigned int
  Count (void) const
  {
    return m_loc[0]->Count (m_loc);
  }
    LxResult
  Name (unsigned int index, const char **name) const
  {
    return m_loc[0]->Name (m_loc,index,name);
  }
    LxResult
  Lookup (const char *name, unsigned int *index) const
  {
    return m_loc[0]->Lookup (m_loc,name,index);
  }
    LxResult
  Type (unsigned int index, unsigned int *type) const
  {
    return m_loc[0]->Type (m_loc,index,type);
  }
    LxResult
  TypeName (unsigned int index, const char **tname) const
  {
    return m_loc[0]->TypeName (m_loc,index,tname);
  }
    const LXtTextValueHint *
  Hints (unsigned int index) const
  {
    return m_loc[0]->Hints (m_loc,index);
  }
    LxResult
  Value (unsigned int index, void **ppvObj, int writeOK)
  {
    return m_loc[0]->Value (m_loc,index,ppvObj,writeOK);
  }
    LxResult
  GetInt (unsigned int index, int *val) const
  {
    return m_loc[0]->GetInt (m_loc,index,val);
  }
    LxResult
  SetInt (unsigned int index, int val)
  {
    return m_loc[0]->SetInt (m_loc,index,val);
  }
    LxResult
  GetFlt (unsigned int index, double *val) const
  {
    return m_loc[0]->GetFlt (m_loc,index,val);
  }
    LxResult
  SetFlt (unsigned int index, double val)
  {
    return m_loc[0]->SetFlt (m_loc,index,val);
  }
    LxResult
  GetString (unsigned int index, char *val, unsigned int len) const
  {
    return m_loc[0]->GetString (m_loc,index,val,len);
  }
    LxResult
  SetString (unsigned int index, const char *val)
  {
    return m_loc[0]->SetString (m_loc,index,val);
  }
};

class CLxImpl_Message {
  public:
    virtual ~CLxImpl_Message() {}
    virtual LxResult
      msg_Code (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_SetCode (LxResult code)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_SetMessage (const char *table, const char *name, unsigned id)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_SetArgumentInt (unsigned arg, int value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_SetArgumentFloat (unsigned arg, double value)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_SetArgumentString (unsigned arg, const char *string)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_SetArgumentObject (unsigned arg, ILxUnknownID object)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_Reset (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_Table (const char **table)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_Name (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      msg_SetMessageResult (unsigned id)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_Message : public CLxInterface
{
    static LxResult
  Code (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_Code ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetCode (LXtObjectID wcom, LxResult code)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_SetCode (code);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetMessage (LXtObjectID wcom, const char *table, const char *name, unsigned id)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_SetMessage (table,name,id);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetArgumentInt (LXtObjectID wcom, unsigned arg, int value)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_SetArgumentInt (arg,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetArgumentFloat (LXtObjectID wcom, unsigned arg, double value)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_SetArgumentFloat (arg,value);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetArgumentString (LXtObjectID wcom, unsigned arg, const char *string)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_SetArgumentString (arg,string);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetArgumentObject (LXtObjectID wcom, unsigned arg, LXtObjectID object)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_SetArgumentObject (arg,(ILxUnknownID)object);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Reset (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_Reset ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Table (LXtObjectID wcom, const char **table)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_Table (table);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Name (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_Name (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SetMessageResult (LXtObjectID wcom, unsigned id)
  {
    LXCWxINST (CLxImpl_Message, loc);
    try {
      return loc->msg_SetMessageResult (id);
    } catch (LxResult rc) { return rc; }
  }
  ILxMessage vt;
public:
  CLxIfc_Message ()
  {
    vt.Code = Code;
    vt.SetCode = SetCode;
    vt.SetMessage = SetMessage;
    vt.SetArgumentInt = SetArgumentInt;
    vt.SetArgumentFloat = SetArgumentFloat;
    vt.SetArgumentString = SetArgumentString;
    vt.SetArgumentObject = SetArgumentObject;
    vt.Reset = Reset;
    vt.Table = Table;
    vt.Name = Name;
    vt.SetMessageResult = SetMessageResult;
    vTable = &vt.iunk;
    iid = &lx::guid_Message;
  }
};
class CLxLoc_Message : public CLxLocalize<ILxMessageID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Message() {_init();}
  CLxLoc_Message(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Message(const CLxLoc_Message &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Message;}
    LxResult
  Code (void)
  {
    return m_loc[0]->Code (m_loc);
  }
    LxResult
  SetCode (LxResult code)
  {
    return m_loc[0]->SetCode (m_loc,code);
  }
    LxResult
  SetMessage (const char *table, const char *name, unsigned id)
  {
    return m_loc[0]->SetMessage (m_loc,table,name,id);
  }
    LxResult
  SetArgumentInt (unsigned arg, int value)
  {
    return m_loc[0]->SetArgumentInt (m_loc,arg,value);
  }
    LxResult
  SetArgumentFloat (unsigned arg, double value)
  {
    return m_loc[0]->SetArgumentFloat (m_loc,arg,value);
  }
    LxResult
  SetArgumentString (unsigned arg, const char *string)
  {
    return m_loc[0]->SetArgumentString (m_loc,arg,string);
  }
    LxResult
  SetArgumentObject (unsigned arg, ILxUnknownID object)
  {
    return m_loc[0]->SetArgumentObject (m_loc,arg,(ILxUnknownID)object);
  }
    LxResult
  Reset (void)
  {
    return m_loc[0]->Reset (m_loc);
  }
    LxResult
  Table (const char **table)
  {
    return m_loc[0]->Table (m_loc,table);
  }
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  SetMessageResult (unsigned id)
  {
    return m_loc[0]->SetMessageResult (m_loc,id);
  }
};

class CLxImpl_Visitor {
  public:
    virtual ~CLxImpl_Visitor() {}
    virtual LxResult
      vis_Evaluate (void)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_Visitor : public CLxInterface
{
    static LxResult
  Evaluate (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Visitor, loc);
    try {
      return loc->vis_Evaluate ();
    } catch (LxResult rc) { return rc; }
  }
  ILxVisitor vt;
public:
  CLxIfc_Visitor ()
  {
    vt.Evaluate = Evaluate;
    vTable = &vt.iunk;
    iid = &lx::guid_Visitor;
  }
};
class CLxLoc_Visitor : public CLxLocalize<ILxVisitorID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Visitor() {_init();}
  CLxLoc_Visitor(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Visitor(const CLxLoc_Visitor &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Visitor;}
    LxResult
  Evaluate (void)
  {
    return m_loc[0]->Evaluate (m_loc);
  }
};

class CLxImpl_StringTag {
  public:
    virtual ~CLxImpl_StringTag() {}
    virtual LxResult
      stag_Get (LXtID4 type, const char **tag)
        { return LXe_NOTIMPL; }
    virtual LxResult
      stag_Set (LXtID4 type, const char *tag)
        { return LXe_NOTIMPL; }
    virtual LxResult
      stag_Count (unsigned int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      stag_ByIndex (unsigned int index, LXtID4 *type, const char **tag)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_StringTag : public CLxInterface
{
    static LxResult
  Get (LXtObjectID wcom, LXtID4 type, const char **tag)
  {
    LXCWxINST (CLxImpl_StringTag, loc);
    try {
      return loc->stag_Get (type,tag);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Set (LXtObjectID wcom, LXtID4 type, const char *tag)
  {
    LXCWxINST (CLxImpl_StringTag, loc);
    try {
      return loc->stag_Set (type,tag);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Count (LXtObjectID wcom, unsigned int *count)
  {
    LXCWxINST (CLxImpl_StringTag, loc);
    try {
      return loc->stag_Count (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ByIndex (LXtObjectID wcom, unsigned int index, LXtID4 *type, const char **tag)
  {
    LXCWxINST (CLxImpl_StringTag, loc);
    try {
      return loc->stag_ByIndex (index,type,tag);
    } catch (LxResult rc) { return rc; }
  }
  ILxStringTag vt;
public:
  CLxIfc_StringTag ()
  {
    vt.Get = Get;
    vt.Set = Set;
    vt.Count = Count;
    vt.ByIndex = ByIndex;
    vTable = &vt.iunk;
    iid = &lx::guid_StringTag;
  }
};
class CLxLoc_StringTag : public CLxLocalize<ILxStringTagID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_StringTag() {_init();}
  CLxLoc_StringTag(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_StringTag(const CLxLoc_StringTag &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_StringTag;}
    LxResult
  Get (LXtID4 type, const char **tag)
  {
    return m_loc[0]->Get (m_loc,type,tag);
  }
    LxResult
  Set (LXtID4 type, const char *tag)
  {
    return m_loc[0]->Set (m_loc,type,tag);
  }
    LxResult
  Count (unsigned int *count)
  {
    return m_loc[0]->Count (m_loc,count);
  }
    LxResult
  ByIndex (unsigned int index, LXtID4 *type, const char **tag)
  {
    return m_loc[0]->ByIndex (m_loc,index,type,tag);
  }
};

#endif

