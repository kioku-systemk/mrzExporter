/*
 * LX undo module
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
#ifndef LX_undo_H
#define LX_undo_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxUndo ** ILxUndoID;
typedef struct vt_ILxUndoService ** ILxUndoServiceID;
#include <lxvalue.h>



typedef struct vt_ILxUndo {
        ILxUnknown       iunk;
                LXxMETHOD(  void,
        Forward) (
                LXtObjectID              self);

                LXxMETHOD(  void,
        Reverse) (
                LXtObjectID              self);
} ILxUndo;
typedef struct vt_ILxUndoService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  unsigned int,
        State) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        Apply) (
                LXtObjectID              self,
                LXtObjectID              undo);

                LXxMETHOD(  LxResult,
        Record) (
                LXtObjectID              self,
                LXtObjectID              undo);
} ILxUndoService;

#define LXu_UNDO                "17FF7DDF-6F9B-47F1-8335-57A41DB3D3AD"
// [export] ILxUndo undo
#define LXiUNDO_INVALID  0
#define LXiUNDO_ACTIVE   1
#define LXiUNDO_SUSPEND  2
#define LXu_UNDOSERVICE         "D8CA1EC8-F6A0-463E-AB82-9478A281B2CB"

 #ifdef __cplusplus
  }
 #endif
#endif

