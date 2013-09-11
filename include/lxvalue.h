/*
 * LX value module
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
#ifndef LX_value_H
#define LX_value_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxValueService ** ILxValueServiceID;
typedef struct vt_ILxValue ** ILxValueID;
typedef struct vt_ILxStringConversion ** ILxStringConversionID;
typedef struct vt_ILxStringConversionNice ** ILxStringConversionNiceID;
typedef struct vt_ILxValueMath ** ILxValueMathID;
typedef struct vt_ILxValueReference ** ILxValueReferenceID;
typedef struct vt_ILxAttributes ** ILxAttributesID;
typedef struct vt_ILxMessage ** ILxMessageID;
typedef struct vt_ILxValueArray ** ILxValueArrayID;
typedef struct vt_ILxScriptQuery ** ILxScriptQueryID;
typedef struct vt_ILxStringTag ** ILxStringTagID;
typedef struct vt_ILxMatrix ** ILxMatrixID;
typedef struct vt_ILxVisitor ** ILxVisitorID;
#include <lxcom.h>
#include <lxvmath.h>


typedef struct st_LXtTextValueHint {
        int                      value;
        const char              *text;
} LXtTextValueHint;
typedef struct vt_ILxValueService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        TextHintEncode) (
                LXtObjectID              self,
                int                      value,
                const LXtTextValueHint  *hint,
                char                    *buf,
                unsigned                 bufLen);
                LXxMETHOD(  LxResult,
        TextHintDecode) (
                LXtObjectID              self,
                const char              *buf,
                const LXtTextValueHint  *hint,
                int                     *value);
                LXxMETHOD(  LxResult,
        CreateValue) (
                LXtObjectID              self,
                const char              *type,
                void                   **ppvObj);
} ILxValueService;
typedef struct vt_ILxValue {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Clone) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        Copy) (
                LXtObjectID              self,
                LXtObjectID              from);

                LXxMETHOD( LxResult,
        Compare) (
                LXtObjectID              self,
                LXtObjectID              other,
                int                     *diff);

                LXxMETHOD( unsigned int,
        Type) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        GetInt) (
                LXtObjectID              self,
                int                     *val);

                LXxMETHOD(  LxResult,
        SetInt) (
                LXtObjectID              self,
                int                      val);

                LXxMETHOD(  LxResult,
        GetFlt) (
                LXtObjectID              self,
                double                  *val);

                LXxMETHOD(  LxResult,
        SetFlt) (
                LXtObjectID              self,
                double                   val);

                LXxMETHOD(  LxResult,
        GetString) (
                LXtObjectID              self,
                char                    *val,
                unsigned int             len);

                LXxMETHOD(  LxResult,
        SetString) (
                LXtObjectID              self,
                const char              *val);
                LXxMETHOD(  void *,
        Intrinsic) (
                LXtObjectID              self);
} ILxValue;
typedef struct vt_ILxStringConversion {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Encode) (
                LXtObjectID              self,
                char                    *buf,
                int                      len);

                LXxMETHOD( LxResult,
        Decode) (
                LXtObjectID              self,
                const char              *buf);
} ILxStringConversion;
typedef struct vt_ILxStringConversionNice {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Encode) (
                LXtObjectID              self,
                char                    *buf,
                int                      len);

                LXxMETHOD( LxResult,
        Decode) (
                LXtObjectID              self,
                const char              *buf);
} ILxStringConversionNice;
typedef struct vt_ILxValueMath {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Step) (
                LXtObjectID              self,
                int                      direction);

                LXxMETHOD( int,
        Detent) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Add) (
                LXtObjectID              self,
                double                   delta);

                LXxMETHOD( LxResult,
        Multiply) (
                LXtObjectID              self,
                double                   factor);

                LXxMETHOD( LxResult,
        Blend) (
                LXtObjectID              self,
                LXtObjectID              other,
                double                   blend);
} ILxValueMath;
typedef struct vt_ILxValueReference {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        IsSet) (
                LXtObjectID              self);

                LXxMETHOD( int,
        GetObject) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        SetObject) (
                LXtObjectID              self,
                LXtObjectID              obj);
} ILxValueReference;
typedef struct vt_ILxAttributes {
        ILxUnknown       iunk;
                LXxMETHOD(  unsigned int,
        Count) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        Name) (
                LXtObjectID              self,
                unsigned int             index,
                const char             **name);

                LXxMETHOD(  LxResult,
        Lookup) (
                LXtObjectID              self,
                const char              *name,
                unsigned int            *index);

                LXxMETHOD(  LxResult,
        Type) (
                LXtObjectID              self,
                unsigned int             index,
                unsigned int            *type);

                LXxMETHOD(  LxResult,
        TypeName) (
                LXtObjectID              self,
                unsigned int             index,
                const char             **tname);

                LXxMETHOD(  const LXtTextValueHint *,
        Hints) (
                LXtObjectID              self,
                unsigned int             index);
                LXxMETHOD(  LxResult,
        Value) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **ppvObj,
                int                      writeOK);

                LXxMETHOD(  LxResult,
        GetInt) (
                LXtObjectID              self,
                unsigned int             index,
                int                     *val);

                LXxMETHOD(  LxResult,
        SetInt) (
                LXtObjectID              self,
                unsigned int             index,
                int                      val);

                LXxMETHOD(  LxResult,
        GetFlt) (
                LXtObjectID              self,
                unsigned int             index,
                double                  *val);

                LXxMETHOD(  LxResult,
        SetFlt) (
                LXtObjectID              self,
                unsigned int             index,
                double                   val);

                LXxMETHOD(  LxResult,
        GetString) (
                LXtObjectID              self,
                unsigned int             index,
                char                    *val,
                unsigned int             len);

                LXxMETHOD(  LxResult,
        SetString) (
                LXtObjectID              self,
                unsigned int             index,
                const char              *val);
} ILxAttributes;
typedef struct vt_ILxMessage {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Code) (
                LXtObjectID               self );
                LXxMETHOD(  LxResult,
        SetCode) (
                LXtObjectID               self,
                LxResult                  code );
                LXxMETHOD(  LxResult,
        SetMessage) (
                LXtObjectID               self,
                const char               *table,
                const char               *name,
                unsigned                  id);
                LXxMETHOD(  LxResult,
        SetArgumentInt) (
                LXtObjectID               self,
                unsigned                  arg,
                int                       value);
                LXxMETHOD(  LxResult,
        SetArgumentFloat) (
                LXtObjectID               self,
                unsigned                  arg,
                double                    value);
                LXxMETHOD(  LxResult,
        SetArgumentString) (
                LXtObjectID               self,
                unsigned                  arg,
                const char               *string);
                LXxMETHOD(  LxResult,
        SetArgumentObject) (
                LXtObjectID               self,
                unsigned                  arg,
                LXtObjectID               object);
                LXxMETHOD(  LxResult,
        Reset) (
                LXtObjectID               self);
                LXxMETHOD(  LxResult,
        Table) (
                LXtObjectID               self,
                const char              **table);
                LXxMETHOD(  LxResult,
        Name) (
                LXtObjectID               self,
                const char              **name);
                LXxMETHOD(  LxResult,
        SetMessageResult) (
                LXtObjectID               self,
                unsigned                  id);
} ILxMessage;
typedef struct vt_ILxValueArray {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Type) (
                LXtObjectID               self,
                unsigned int             *type );

                LXxMETHOD(  LxResult,
        TypeName) (
                LXtObjectID               self,
                const char              **name );
                LXxMETHOD(  unsigned int,
        Count) (
                LXtObjectID               self );
                LXxMETHOD(  LxResult,
        AddEmptyValue) (
                LXtObjectID              self,
                void                   **ppvObj );
                LXxMETHOD(  LxResult,
        AddValue) (
                LXtObjectID               self,
                LXtObjectID               value );

                LXxMETHOD(  LxResult,
        AddInt) (
                LXtObjectID               self,
                int                       value );

                LXxMETHOD(  LxResult,
        AddFloat) (
                LXtObjectID               self,
                double                    value );

                LXxMETHOD(  LxResult,
        AddString) (
                LXtObjectID               self,
                const char               *value );
                LXxMETHOD(  LxResult,
        GetValue) (
                LXtObjectID               self,
                unsigned int              index,
                void                   **ppvObj );

                LXxMETHOD(  LxResult,
        GetInt) (
                LXtObjectID               self,
                unsigned int              index,
                int                      *value );

                LXxMETHOD(  LxResult,
        GetFloat) (
                LXtObjectID               self,
                unsigned int              index,
                double                   *value );

                LXxMETHOD(  LxResult,
        GetString) (
                LXtObjectID               self,
                unsigned int              index,
                char                     *value,
                unsigned int              len );
                LXxMETHOD(  LxResult,
        FirstUnique) (
                LXtObjectID               self,
                unsigned int             *uniqueIndex );
                LXxMETHOD(  LxResult,
        Reset) (
                LXtObjectID               self );
} ILxValueArray;
typedef struct vt_ILxScriptQuery {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Select) (
                LXtObjectID              self,
                const char              *attribute,
                const char              *which);
                LXxMETHOD(  LxResult,
        Query) (
                LXtObjectID              self,
                const char              *attribute,
                LXtObjectID              query);
                LXxMETHOD(  LxResult,
        Type) (
                LXtObjectID              self,
                const char              *attribute,
                int                     *type);
                LXxMETHOD(  LxResult,
        TypeName) (
                LXtObjectID               self,
                const char               *attribute,
                const char              **type);
} ILxScriptQuery;
typedef struct vt_ILxStringTag {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Get) (
                LXtObjectID              self,
                LXtID4                   type,
                const char             **tag);
                LXxMETHOD( LxResult,
        Set) (
                LXtObjectID              self,
                LXtID4                   type,
                const char              *tag);
                LXxMETHOD( LxResult,
        Count) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD( LxResult,
        ByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                LXtID4                  *type,
                const char             **tag);
} ILxStringTag;
typedef struct vt_ILxMatrix {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Get3) (
                LXtObjectID              self,
                LXtMatrix                mat3);

                LXxMETHOD( LxResult,
        Get4) (
                LXtObjectID              self,
                LXtMatrix4               mat4);

                LXxMETHOD( LxResult,
        GetOffset) (
                LXtObjectID              self,
                LXtVector                offset);
                LXxMETHOD( LxResult,
        MultiplyVector) (
                LXtObjectID              self,
                const LXtVector          vector,
                LXtVector                result);
                LXxMETHOD( LxResult,
        Set3) (
                LXtObjectID              self,
                const LXtMatrix          mat3);

                LXxMETHOD( LxResult,
        Set4) (
                LXtObjectID              self,
                const LXtMatrix4         mat4);

                LXxMETHOD( LxResult,
        SetOffset) (
                LXtObjectID              self,
                const LXtVector          offset);
                LXxMETHOD( LxResult,
        SetIdentity) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Multiply3) (
                LXtObjectID              self,
                LXtMatrix                mat3);

                LXxMETHOD( LxResult,
        Multiply4) (
                LXtObjectID              self,
                LXtMatrix4               mat4);

                LXxMETHOD( LxResult,
        Invert) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Transpose) (
                LXtObjectID              self);
} ILxMatrix;
typedef struct vt_ILxVisitor {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Evaluate) (
                LXtObjectID              self);
} ILxVisitor;

#define LXu_VALUESERVICE        "DD2C3059-2CD0-4c7d-860C-CF353CFB2F92"
#define LXa_VALUESERVICE        "valueservice"

#define LXe_OK_INEXACT_MATCH    LXxGOODCODE( LXeSYS_VALUE,   1) // Good, not Fail
#define LXe_OK_NO_CHOICES       LXxGOODCODE( LXeSYS_VALUE,   2) // Good, not Fail
#define LXu_VALUE       "62E1DBE9-2FFE-4B5C-B286-E54E79415303"
#define LXa_VALUE       "value"
// [export]  ILxValue
// [local]   ILxValue
// [const]   ILxValue:Compare
// [const]   ILxValue:Type
// [const]   ILxValue:GetInt
// [const]   ILxValue:GetFlt
// [const]   ILxValue:GetString
// [const]   ILxValue:Intrinsic
// [default] ILxValue:Intrinsic = 0
#define LXu_STRINGCONVERSION            "5CB3EEDB-E4E0-499E-B0BA-A7FB51BABE3C"
// [export] ILxStringConversion str
// [local]  ILxStringConversion
// [const]  ILxStringConversion:Encode

#define LXu_STRINGCONVERSIONNICE        "5407328B-DE99-4F15-866F-F6E214FFA412"
// [export] ILxStringConversionNice niceStr
// [local]  ILxStringConversionNice
// [const]  ILxStringConversionNice:Encode
#define LXu_VALUEMATH   "752B4D2E-6F13-4B2C-B0B3-0BA8CA6B0692"
// [export] ILxValueMath
// [local]  ILxValueMath
// [const]  ILxValueMath:Detent
#define LXu_VALUEREFERENCE      "0567BC88-F782-426E-98C5-8302FD52D9E4"
// [export] ILxValueReference
// [local]  ILxValueReference
// [const]  ILxValueReference:IsSet
// [const]  ILxValueReference:GetObject
#define LXu_ATTRIBUTES  "117957D0-5A13-11D7-A18C-000A95765C9E"
// [export] ILxAttributes attr
// [local]  ILxAttributes
// [const]  ILxAttributes:Count
// [const]  ILxAttributes:Name
// [const]  ILxAttributes:Lookup
// [const]  ILxAttributes:Type
// [const]  ILxAttributes:TypeName
// [const]  ILxAttributes:Hints
// [const]  ILxAttributes:GetInt
// [const]  ILxAttributes:GetFlt
// [const]  ILxAttributes:GetString
#define LXi_TYPE_OBJECT         0
#define LXi_TYPE_INTEGER        1
#define LXi_TYPE_FLOAT          2
#define LXi_TYPE_STRING         3
#define LXsTYPE_INTEGER         "integer"
#define LXsTYPE_FLOAT           "float"
#define LXsTYPE_DISTANCE        "distance"
#define LXsTYPE_PERCENT         "percent"
#define LXsTYPE_ANGLE           "angle"
#define LXsTYPE_FLOAT3          "float3"
#define LXsTYPE_DISTANCE3       "distance3"
#define LXsTYPE_PERCENT3        "percent3"
#define LXsTYPE_ANGLE3          "angle3"
#define LXsTYPE_TIME            "time"
#define LXsTYPE_LIGHT           "light"
#define LXsTYPE_STRING          "string"
#define LXsTYPE_FILEPATH        "filepath"
#define LXsTYPE_UVCOORD         "uvcoord"
#define LXsTYPE_BOOLEAN         "boolean"
#define LXsTYPE_AXIS            "axis"
#define LXsTYPE_MEMORY          "memory"
#define LXsTYPE_PIXEL           "pixel"
#define LXsTYPE_FPIXEL          "fpixel"
#define LXsTYPE_COLOR           "color"
#define LXsTYPE_COLOR1          "color1"
#define LXsTYPE_MATRIX3         "matrix3"
#define LXsTYPE_MATRIX4         "matrix4"
#define LXsTYPE_DATETIME        "datetime"
#define LXsTYPE_TOD             "timeofday"
#define LXsTYPE_DATE            "date"
#define LXsTYPE_OBJREF          "objref"
#define LXsTYPE_VERTMAPNAME     "vertmapname"
// [default] ILxAttributes:Count = 0
// [default] ILxAttributes:Hints = 0
#define LXu_MESSAGE             "DDDBF46A-0865-4AB7-9962-72E7B477FD22"
#define LXa_MESSAGE             "message"
// [export] ILxMessage msg
// [local]  ILxMessage
#define LXu_VALUEARRAY          "A964962F-9028-4CA3-9612-17D360DF92BA"
#define LXa_VALUEARRAY          "valuearray"
// [export] ILxValueArray va
// [local]  ILxValueArray
#define LXu_SCRIPTQUERY         "0434F07E-AD4A-492f-AD43-3249BD16994D"
#define LXa_SCRIPTQUERY         "scriptquery"
// [export] ILxScriptQuery sq
// [local]  ILxScriptQuery
#define LXe_QUERY_UNKNOWN_SERVICE               LXxFAILCODE(LXeSYS_QUERY,0)
#define LXe_QUERY_SERVICE_UNAVAILABLE           LXxFAILCODE(LXeSYS_QUERY,1)
#define LXe_QUERY_UNKNOWN_ATTRIBUTE             LXxFAILCODE(LXeSYS_QUERY,2)
#define LXe_QUERY_MISMATCHED_TYPE               LXxFAILCODE(LXeSYS_QUERY,3)
#define LXe_QUERY_SELECT_FAILED                 LXxFAILCODE(LXeSYS_QUERY,4)
#define LXe_QUERY_NEED_SELECTION                LXxFAILCODE(LXeSYS_QUERY,5)
#define LXe_QUERY_MISMATCHED_SELECTION          LXxFAILCODE(LXeSYS_QUERY,6)
#define LXe_QUERY_NOT_APPLICABLE_TO_SELECTED    LXxFAILCODE(LXeSYS_QUERY,7)
#define LXe_QUERY_ERROR                         LXxFAILCODE(LXeSYS_QUERY,8)
#define LXu_STRINGTAG           "C2004BC7-6A90-4BD3-BDF7-B375C790DB70"
// [local]  ILxStringTag
// [export] ILxStringTag stag
#define LXu_MATRIX              "EF9FDE7B-E7FA-48B2-838E-A5A8F7D5C254"
// [local]  ILxMatrix
// [const]  ILxMatrix:Get3
// [const]  ILxMatrix:Get4
// [const]  ILxMatrix:GetOffset
// [const]  ILxMatrix:MultiplyVector
#define LXa_VISITOR     "visitor"
#define LXu_VISITOR     "C8FCAD70-DDDF-499E-A03B-A08B906D3E53"
// [local]  ILxVisitor
// [export] ILxVisitor

 #ifdef __cplusplus
  }
 #endif
#endif

