/*
 * LX schematic module
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
#ifndef LX_schematic_H
#define LX_schematic_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxSchematic ** ILxSchematicID;
#include <lxcom.h>
#include <lxvalue.h>



typedef struct vt_ILxSchematic {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        GraphRegister) (
                LXtObjectID              self,
                char                    *string);
                LXxMETHOD(  LxResult,
        GraphTest) (
                LXtObjectID              self,
                LXtObjectID              from,
                LXtObjectID              to);
} ILxSchematic;

#define LXu_SCHEMATIC   "F656CC26-2580-4B4C-8CBC-8BDD01378BFD"
#define LXa_SCHEMATIC   "schematic"
// [local] ILxSchematic
// [export]  ILxSchematic schm

 #ifdef __cplusplus
  }
 #endif
#endif

