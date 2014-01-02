/*
 * LX schematic module
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
#ifndef LX_schematic_H
#define LX_schematic_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxSchematicConnection ** ILxSchematicConnectionID;
#include <lxcom.h>
#include <lxvalue.h>



typedef struct vt_ILxSchematicConnection {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ItemFlags) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                *flags);
                LXxMETHOD(  LxResult,
        AllowConnect) (
                LXtObjectID              self,
                LXtObjectID              from,
                LXtObjectID              to);
                LXxMETHOD(  LxResult,
        GraphName) (
                LXtObjectID              self,
                const char             **name);
                LXxMETHOD(  LxResult,
        Count) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                *count);

                LXxMETHOD(  LxResult,
        ByIndex) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                 index,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        Connect) (
                LXtObjectID              self,
                LXtObjectID              from,
                LXtObjectID              to,
                int                      toIndex);

                LXxMETHOD(  LxResult,
        Disconnect) (
                LXtObjectID              self,
                LXtObjectID              from,
                LXtObjectID              to);
                LXxMETHOD(  int,
        BaseFlags) (
                LXtObjectID              self);
} ILxSchematicConnection;

#define LXfSCON_SINGLE           0x01
#define LXfSCON_MULTIPLE         0x02
#define LXfSCON_ORDERED          0x04
#define LXfSCON_REVERSE          0x08

#define LXfSCON_USESERVER        0x80
#define LXu_SCHEMATICCONNECTION "5AC0A075-72B7-4935-8DA5-588DF7999069"
#define LXa_SCHEMATICCONNECTION "schematicConnection"
// [local]   ILxSchematicConnection
// [export]  ILxSchematicConnection schm
// [default] ILxSchematicConnection:BaseFlags = 0
// [python]  ILxSchematicConnection:ByIndex             obj Item
// [python]  ILxSchematicConnection:AllowConnect        bool

 #ifdef __cplusplus
  }
 #endif
#endif

