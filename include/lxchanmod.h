/*
 * LX chanmod module
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
#ifndef LX_chanmod_H
#define LX_chanmod_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxChannelModItem ** ILxChannelModItemID;
typedef struct vt_ILxChannelModifier ** ILxChannelModifierID;
#include <lxcom.h>
#include <lxvalue.h>



typedef struct vt_ILxChannelModItem {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Allocate) (
                LXtObjectID              self,
                LXtObjectID              cmod,
                LXtObjectID              eval,
                LXtObjectID              item,
                void                   **ppvData);
                LXxMETHOD(  unsigned int,
        Flags) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             index);
                LXxMETHOD(  LxResult,
        Evaluate) (
                LXtObjectID              self,
                LXtObjectID              cmod,
                LXtObjectID              attr,
                void                    *data);
                LXxMETHOD(  void,
        Cleanup) (
                LXtObjectID              self,
                void                    *data); 
} ILxChannelModItem;
typedef struct vt_ILxChannelModifier {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        AddInput) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             index);
                LXxMETHOD(  LxResult,
        AddOutput) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             index);
                LXxMETHOD(  LxResult,
        AddTime) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        InputCount) (
                LXtObjectID              self,
                unsigned int             index,
                unsigned int            *nInputs);
                LXxMETHOD(  LxResult,
        OutputCount) (
                LXtObjectID              self,
                unsigned int             index,
                unsigned int            *nOutputs);
                LXxMETHOD(  LxResult,
        ReadInputFloat) (
                LXtObjectID              self,
                LXtObjectID              attr,
                unsigned int             inputIndex,
                double                  *dVal);
                LXxMETHOD(  LxResult,
        ReadInputFloatByIndex) (
                LXtObjectID              self,
                LXtObjectID              attr,
                unsigned int             inputIndex,
                unsigned int             linkIndex,
                double                  *dVal); 
                LXxMETHOD(  LxResult,
        ReadInputAngle) (
                LXtObjectID              self,
                LXtObjectID              attr,
                unsigned int             inputIndex,
                double                  *dVal);
                LXxMETHOD(  LxResult,
        ReadInputInt) (
                LXtObjectID              self,
                LXtObjectID              attr,
                unsigned int             inputIndex,
                int                     *iVal);
                LXxMETHOD(  LxResult,
        ReadInputIntByIndex) (
                LXtObjectID              self,
                LXtObjectID              attr,
                unsigned int             inputIndex,
                unsigned int             linkIndex,
                int                     *iVal);
                LXxMETHOD(  LxResult,
        ReadInputVal) (
                LXtObjectID              self,
                LXtObjectID              attr,
                unsigned int             inputIndex,
                void                    **val);
                LXxMETHOD(  LxResult,
        ReadInputValByIndex) (
                LXtObjectID              self,
                LXtObjectID              attr,
                unsigned int             inputIndex,
                unsigned int             linkIndex,
                void                    **val);
                LXxMETHOD(  LxResult,
        WriteOutputFloat) (
                LXtObjectID              self,
                LXtObjectID              attr,
                unsigned int             outputIndex,
                double                   dVal);
                LXxMETHOD(  LxResult,
        WriteOutputInt) (
                LXtObjectID              self,
                LXtObjectID              attr,
                unsigned int             outputIndex,
                int                      iVal);
                LXxMETHOD(  LxResult,
        WriteOutputVal) (
                LXtObjectID              self,
                LXtObjectID              attr,
                unsigned int             outputIndex,
                void                    **val);
                LXxMETHOD(  LxResult,
        WriteOutputValByIndex) (
                LXtObjectID              self,
                LXtObjectID              attr,
                unsigned int             outputIndex,
                unsigned int             linkIndex,
                void                    **val);
} ILxChannelModifier;

#define LXfCHMOD_INPUT          0x0001
#define LXfCHMOD_OUTPUT         0x0002
#define LXfCHMOD_MULTILINK      0x0004
#define LXu_CHANNELMODITEM      "1955CFD9-9E56-42AB-94C8-BF6BE1B069D6"
#define LXa_CHANNELMODITEM      "channelmoditem"
// [export]  ILxChannelModItem cmod
#define LXu_CHANNELMODIFIER     "7D633F1B-41A9-4151-B94E-A50322DB62EB"
#define LXa_CHANNELMODIFIER     "channelmodifier"
// [local]  ILxChannelModifier

 #ifdef __cplusplus
  }
 #endif
#endif

