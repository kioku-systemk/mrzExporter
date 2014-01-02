/*
 * LX group module
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
#ifndef LX_group_H
#define LX_group_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxGroupItem ** ILxGroupItemID;
typedef struct vt_ILxGroupEnumerator ** ILxGroupEnumeratorID;




typedef struct vt_ILxGroupItem {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Enumerator) (
                LXtObjectID              self,
                void                   **ppvObj);
} ILxGroupItem;
typedef struct vt_ILxGroupEnumerator {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Enumerate) (
                LXtObjectID              self,
                LXtObjectID              visitor,
                unsigned                 mask);

                LXxMETHOD(  unsigned,
        Type) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        Item) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  LxResult,
        Channel) (
                LXtObjectID              self,
                void                   **ppvObj,
                unsigned                *index);
} ILxGroupEnumerator;

#define LXu_GROUPITEM           "47FDFD87-3FBA-41A4-8044-74EC9D9AA986"
// [local]  ILxGroupItem
// [python] ILxGroupItem:Enumerator     obj GroupEnumerator
#define LXu_GROUPENUMERATOR     "CA4E1FE0-B655-429F-9674-3E1D7DEA5D04"
// [local]  ILxGroupEnumerator
// [python] ILxGroupEnumerator:Item     obj Item (item)
// [python] ILxGroupEnumerator:Channel  obj Item

#define LXfGRPTYPE_ITEM          0x01
#define LXfGRPTYPE_CHANNEL       0x02
#define LXfGRPTYPE_BOTH         (LXfGRPTYPE_ITEM | LXfGRPTYPE_CHANNEL)

 #ifdef __cplusplus
  }
 #endif
#endif

