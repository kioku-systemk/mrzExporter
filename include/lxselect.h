/*
 * LX sel module
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
#ifndef LX_sel_H
#define LX_sel_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxSelectionType ** ILxSelectionTypeID;
typedef struct vt_ILxSelectionListener ** ILxSelectionListenerID;
typedef struct vt_ILxSelectionService ** ILxSelectionServiceID;
typedef struct vt_ILxSelectionPacket1Service ** ILxSelectionPacket1ServiceID;
#include <lxcom.h>

typedef void *           LXtScanInfoID;

typedef struct vt_ILxSelectionType {
        ILxUnknown       iunk;
                LXxMETHOD(  unsigned int,
        Size) (
                LXtObjectID              self);

                LXxMETHOD(  unsigned int,
        Flags) (
                LXtObjectID              self);

                LXxMETHOD(  const char *,
        MessageTable) (
                LXtObjectID              self);

                LXxMETHOD(  int,
        Compare) (
                LXtObjectID              self,
                void                    *pkey,
                void                    *pelt);

                LXxMETHOD(  unsigned int,
        SubType) (
                LXtObjectID              self,
                void                    *pkt);
} ILxSelectionType;
typedef struct vt_ILxSelectionListener {
        ILxUnknown       iunk;
                LXxMETHOD(  void,
        Current) (
                LXtObjectID              self,
                LXtID4                   type);

                LXxMETHOD(  void,
        Add) (
                LXtObjectID              self,
                LXtID4                   type,
                unsigned int             subtType);

                LXxMETHOD(  void,
        Remove) (
                LXtObjectID              self,
                LXtID4                   type,
                unsigned int             subtType);

                LXxMETHOD(  void,
        Time) (
                LXtObjectID              self,
                double                   time);

                LXxMETHOD(  void,
        TimeRange) (
                LXtObjectID              self,
                LXtID4                   type);
} ILxSelectionListener;
typedef struct vt_ILxSelectionService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  int,
        Count) (
                LXtObjectID              self,
                LXtID4                   type);

                LXxMETHOD(  void *,
        ByIndex) (
                LXtObjectID              self,
                LXtID4                   type,
                unsigned int             idx);

                LXxMETHOD(  void *,
        Recent) (
                LXtObjectID              self,
                LXtID4                   type);

                LXxMETHOD(  LxResult,
        Test) (
                LXtObjectID              self,
                LXtID4                   type,
                void                    *packet);
                LXxMETHOD(  LXtScanInfoID,
        ScanLoop) (
                LXtObjectID              self,
                LXtScanInfoID            scan,
                LXtID4                   type,
                void                   **packet);

                LXxMETHOD(  LXtScanInfoID,
        ScanLoopCurrent) (
                LXtObjectID              self,
                LXtScanInfoID            scan,
                LXtID4                   type,
                void                   **packet);
                LXxMETHOD(  LxResult,
        Select) (
                LXtObjectID              self,
                LXtID4                   type,
                void                    *packet);

                LXxMETHOD(  LxResult,
        Deselect) (
                LXtObjectID              self,
                LXtID4                   type,
                void                    *packet);

                LXxMETHOD(  LxResult,
        Remove) (
                LXtObjectID              self,
                LXtID4                   type,
                void                    *packet);

                LXxMETHOD(  LxResult,
        Toggle) (
                LXtObjectID              self,
                LXtID4                   type,
                void                    *packet);

                LXxMETHOD(  LxResult,
        Drop) (
                LXtObjectID              self,
                LXtID4                   type);

                LXxMETHOD(  LxResult,
        StartBatch) (
                LXtObjectID              self,
                LXtID4                   type,
                int                      desel);

                LXxMETHOD(  LxResult,
        EndBatch) (
                LXtObjectID              self,
                int                      desel);

                LXxMETHOD(  LxResult,
        AbortBatch) (
                LXtObjectID              self);
                LXxMETHOD(  const char *,
        LookupName) (
                LXtObjectID              self,
                LXtID4                   type);

                LXxMETHOD(  LXtID4,
        LookupType) (
                LXtObjectID              self,
                const char              *name);

                LXxMETHOD( LxResult,
        Allocate) (
                LXtObjectID              self,
                const char              *name,
                void                   **ppvObj);
                LXxMETHOD(  double,
        GetTime) (
                LXtObjectID              self);

                LXxMETHOD(  LxResult,
        SetTime) (
                LXtObjectID              self,
                double                   time); 
                LXxMETHOD(  double,
        Clear) (
                LXtObjectID              self,
                LXtID4                   type);
                LXxMETHOD(  int,
        State) (
                LXtObjectID              self,
                LXtID4                   type,
                void                    *packet);
                LXxMETHOD(  LXtID4,
        CurrentType) (
                LXtObjectID              self,
                LXtID4                  *types);
} ILxSelectionService;
typedef struct vt_ILxSelectionPacket1Service {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD(  const char *,
        LookupName) (
                LXtObjectID              self,
                LXtID4                   type);

                LXxMETHOD(  LXtID4,
        LookupType) (
                LXtObjectID              self,
                const char              *name);

                LXxMETHOD( LxResult,
        Allocate) (
                LXtObjectID              self,
                const char              *name,
                void                   **ppvObj);
} ILxSelectionPacket1Service;

#define LXu_SELECTIONTYPE       "6f0E612B-4462-43B5-84D3-A6FCA7C8EF94"
#define LXa_SELECTIONTYPE       "SelectionType"
// [export]  ILxSelectionType selTyp
// [local]   ILxSelectionType
// [default] ILxSelectionType:SubType = 0
#define LXf_SELPACKET_UNDOABLE          0x01
#define LXu_SELECTIONLISTENER   "32E1B478-F2F6-41A8-9D79-14919B793AFE"
#define LXa_SELECTIONLISTENER   "selectionListener"
// [export] ILxSelectionListener selEvent
#define LXf_SELECTION_NONE              0x00
#define LXf_SELECTION_PRIMARY           0x01
#define LXf_SELECTION_SECONDARY         0x02
#define LXf_SELECTION_LAST              0x04
#define LXf_SELECTION_CURRENT           0x08
#define LXf_SELECTION_HISTORY           0x10
#define LXu_SELECTIONSERVICE    "6AEF6F27-046F-4C04-90E0-994D742851E7"
#define LXa_SELECTIONSERVICE    "selectionservice"
#define LXu_SELECTIONPACKET1SERVICE     "58D8DEAD-3B0C-41FB-AC1E-B17A36521D44"

 #ifdef __cplusplus
  }
 #endif
#endif

