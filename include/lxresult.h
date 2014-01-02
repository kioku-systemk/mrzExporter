/*
 * LX result module
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
#ifndef LX_result_H
#define LX_result_H
 #ifdef __cplusplus
  extern "C" {
 #endif

typedef unsigned int            LxResult;

#define LXe_FAILED              (LxResult)(0x80000000)
#define LXxGOODCODE(m,v)        (LxResult)((((m) << 16) & 0x7FFF0000) | (v & 0xFFFF))
#define LXxFAILCODE(m,v)        (LxResult)(LXe_FAILED | (((m) << 16) & 0x7FFF0000) | (v & 0xFFFF))
#define LXx_FAIL(r)             (((r) & LXe_FAILED) != 0)
#define LXx_OK(r)               (!LXx_FAIL(r))
#define LXx_OKNI(r)             (LXx_OK(r) || (r == LXe_NOTIMPL))
#define LXe_OK                  (LxResult)(0x0)
#define LXe_TRUE                (LxResult)(0x0)
#define LXe_FALSE               (LxResult)(0x1)
#define LXe_INFO                LXxGOODCODE(0,1)
#define LXe_WARNING             LXxGOODCODE(0,2)
#define LXe_NOTIMPL             LXxFAILCODE(0,1)
#define LXe_OUTOFMEMORY         LXxFAILCODE(0,2)
#define LXe_INVALIDARG          LXxFAILCODE(0,3)
#define LXe_NOINTERFACE         LXxFAILCODE(0,4)
#define LXe_ABORT               LXxFAILCODE(0,7)
#define LXe_NOACCESS            LXxFAILCODE(0,9)
#define LXe_OUTOFBOUNDS         LXxFAILCODE(0,21)
#define LXe_NOTFOUND            LXxFAILCODE(0,23)
#define LXe_STARTUP             LXxFAILCODE(0,24)
#define LXe_DISABLED            LXxFAILCODE(0,25)
#define LXe_CKPTOVERFLOW        LXxFAILCODE(0,26)
#define LXe_ALREADYEXISTS       LXxFAILCODE(0,27)
#define LXe_NOTAVAILABLE        LXxFAILCODE(0,28)
#define LXe_CRASH               LXxFAILCODE(0,29)
#define LXe_SHORTBUFFER         LXxFAILCODE(0,30)
#define LXe_RECOVERING          LXxFAILCODE(0,31)
#define LXeSYS_IO               0x400
#define LXeSYS_PLUG             0x410
#define LXeSYS_IMAGE            0x420
#define LXeSYS_OPAL1            0x430
#define LXeSYS_OPAL2            0x440
#define LXeSYS_FONT             0x450
#define LXeSYS_ADISP            0x460
#define LXeSYS_AWIN             0x470
#define LXeSYS_CMDS             0x480
#define LXeSYS_IMSG             0x490
#define LXeSYS_COMP             0x500
#define LXeSYS_ITEM             0x510
#define LXeSYS_MESH             0x520
#define LXeSYS_BOOT             0x530
#define LXeSYS_FRAME            0x540
#define LXeSYS_REND             0x550
#define LXeSYS_SCRIPT           0x560
#define LXeSYS_QUERY            0x570
#define LXeSYS_UIIMAGE          0x580
#define LXeSYS_INPUTMAP         0x590
#define LXeSYS_AFILE            0x600
#define LXeSYS_LOG              0x610
#define LXeSYS_VALUE            0x620
#define LXeSYS_NETWORK          0x630
#define LXeSYS_RENDER           0x640
#define LXeSYS_EVAL             0x650
#define LXeSYS_DEFORM           0x660
#define LXeSYS_MT               0x670
#define LXeSYS_PREVIEW          0x680
#define LXeSYS_PSYS             0x690
#define LXeSYS_UNDO             0x700
#define LXeSYS_PRESET           0x710

 #ifdef __cplusplus
  }
 #endif
#endif

