/*
 * LX mt module
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
#ifndef LX_mt_H
#define LX_mt_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxWorkList ** ILxWorkListID;
typedef struct vt_ILxThreadMutex ** ILxThreadMutexID;
typedef struct vt_ILxThreadService ** ILxThreadServiceID;
typedef struct vt_ILxThreadJob ** ILxThreadJobID;
typedef struct vt_ILxThreadGroup ** ILxThreadGroupID;
typedef struct vt_ILxThreadSlot ** ILxThreadSlotID;
typedef struct vt_ILxThreadSlotClient ** ILxThreadSlotClientID;
typedef struct vt_ILxSharedWork ** ILxSharedWorkID;
typedef struct vt_ILxThreadRangeWorker ** ILxThreadRangeWorkerID;
typedef struct vt_ILxWaterfall ** ILxWaterfallID;
#include <lxcom.h>
#include <stdlib.h>



typedef struct vt_ILxWorkList {
        ILxUnknown       iunk;
                LXxMETHOD ( LxResult,
        IsEmpty) (
                LXtObjectID              self);

                LXxMETHOD ( void *,
        Next) (
                LXtObjectID              self);

                LXxMETHOD ( LxResult,
        Split) (
                LXtObjectID              self,
                unsigned                 mode,
                void                   **ppvObj);

                LXxMETHOD ( void,
        Clear) (
                LXtObjectID              self);
} ILxWorkList;
typedef struct vt_ILxThreadMutex {
        ILxUnknown       iunk;
                LXxMETHOD ( void,
        Enter) (
                LXtObjectID              self);

                LXxMETHOD ( void,
        Leave) (
                LXtObjectID              self);
} ILxThreadMutex;
typedef struct vt_ILxThreadService {
        ILxUnknown       iunk;
                LXxMETHOD ( LxResult,
        CreateMutex) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD ( LxResult,
        CreateCS) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD ( LxResult, 
        CreateGroup) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD ( unsigned int,
        NumProcs) (
                LXtObjectID              self);

                LXxMETHOD ( unsigned int,
        IsMainThread) (
                LXtObjectID              self);

                LXxMETHOD ( LxResult, 
        CreateSlot) (
                LXtObjectID              self,
                size_t                   size,
                LXtObjectID              client,
                void                    **ppvObj);
                LXxMETHOD ( LxResult, 
        ProcessShared) (
                LXtObjectID              self,
                LXtObjectID              shared);

                LXxMETHOD ( LxResult,
        ProcessRange) (
                LXtObjectID              self,
                void                    *data,
                int                      startIndex,
                int                      endIndex,
                LXtObjectID              rangeWorker);
                LXxMETHOD ( LxResult,
        InitThread) (
                LXtObjectID               self);
                LXxMETHOD ( LxResult,
        CleanupThread) (
                LXtObjectID               self);
                LXxMETHOD ( LxResult,
        ProcessWaterfall) (
                LXtObjectID              self,
                LXtObjectID              waterfall,
                unsigned                 threads);
} ILxThreadService;
typedef struct vt_ILxThreadJob {
        ILxUnknown       iunk;
                LXxMETHOD ( void,
        Execute) (
                LXtObjectID              self);
} ILxThreadJob;
typedef struct vt_ILxThreadGroup {
        ILxUnknown       iunk;
                LXxMETHOD ( void,
        AddJob) (
                LXtObjectID              self,
                LXtObjectID              job);

                LXxMETHOD ( unsigned,
        NumJobs) (
                LXtObjectID              self);

                LXxMETHOD ( void,
        Clear) (
                LXtObjectID              self);

                LXxMETHOD ( void,
        Execute) (
                LXtObjectID              self);

                LXxMETHOD ( void,
        Wait) (
                LXtObjectID              self);

                LXxMETHOD ( LxResult,
        Running) (
                LXtObjectID              self);

                LXxMETHOD ( void,
        Kill) (
                LXtObjectID              self);
} ILxThreadGroup;
typedef struct vt_ILxThreadSlot {
        ILxUnknown       iunk;
                LXxMETHOD ( LxResult,
        Set) (
                LXtObjectID              self,
                void                    *value);

                LXxMETHOD ( LxResult,
        Get) (
                LXtObjectID              self,
                void                   **value);

                LXxMETHOD ( LxResult,
        Clear) (
                LXtObjectID              self);
} ILxThreadSlot;
typedef struct vt_ILxThreadSlotClient {
        ILxUnknown       iunk;
                LXxMETHOD ( LxResult,
        Alloc) (
                LXtObjectID              self,
                void                   **value);

                LXxMETHOD ( LxResult,
        Free) (
                LXtObjectID              self,
                void                    *value);
} ILxThreadSlotClient;
typedef struct vt_ILxSharedWork {
        ILxUnknown       iunk;
                LXxMETHOD ( LxResult,
        Evaluate) (
                LXtObjectID              self);

                LXxMETHOD ( LxResult,
        Spawn) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD ( LxResult,
        Share) (
                LXtObjectID              self,
                LXtObjectID              other,
                unsigned int             split);
} ILxSharedWork;
typedef struct vt_ILxThreadRangeWorker {
        ILxUnknown       iunk;
                LXxMETHOD ( LxResult,
        Execute) (
                LXtObjectID              self,
                int                      index,
                void                    *sharedData);
} ILxThreadRangeWorker;
typedef struct vt_ILxWaterfall {
        ILxUnknown       iunk;
                LXxMETHOD ( LxResult,
        Spawn) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD ( unsigned,
        State) (
                LXtObjectID              self);
                LXxMETHOD ( LxResult,
        ProcessWork) (
                LXtObjectID              self);
                LXxMETHOD ( LxResult,
        GetWork) (
                LXtObjectID              self);
                LXxMETHOD ( LxResult,
        Advance) (
                LXtObjectID              self);
} ILxWaterfall;

#define LXu_THREADSERVICE       "0A9D5B42-1DA6-42A4-8FC4-01FCCE939AC4"
#define LXa_THREADSERVICE       "threadservice"
// [python] ILxThreadService:CreateCS           obj ThreadMutex
// [python] ILxThreadService:CreateMutex        obj ThreadMutex
// [python] ILxThreadService:CreateGroup        obj ThreadGroup
// [python] ILxThreadService:CreateSlot         obj ThreadSlot
// [const]  ILxThreadService:InitThread
// [const]  ILxThreadService:CleanupThread

#define LXu_THREADMUTEX         "7624F6B7-83FD-424F-A68E-0EDD089167CB"
#define LXa_THREADMUTEX         "threadmutex"
// [local]  ILxThreadMutex 

#define LXu_THREADJOB           "DE892B0B-A791-4FA5-B85D-46E8CACB695B"
#define LXa_THREADJOB           "threadjob"
// [local]  ILxThreadJob
// [export] ILxThreadJob job

#define LXu_THREADGROUP         "54A9DD48-3AFC-435F-9F17-2EEB6FB46FBA"
#define LXa_THREADGROUP         "threadgroup"
// [local]  ILxThreadGroup
// [python] ILxThreadGroup:Running      bool

#define LXu_WORKLIST            "74568CA9-92C9-4C73-9851-E9169934629A"
#define LXa_WORKLIST            "worklist"
// [local]  ILxWorkList
// [export] ILxWorkList work
// [python] ILxWorkList:Split   obj WorkList
// [python] ILxWorkList:IsEmpty bool

#define LXu_THREADSLOT          "365E4616-0FB9-478E-993D-D35282F4C326"
// [local]  ILxThreadSlot

#define LXu_THREADSLOTCLIENT    "D24835B6-518B-4E33-8A70-E53038C29BB7"
// [local]  ILxThreadSlotClient
// [export] ILxThreadSlotClient tsc

#define LXu_SHAREDWORK          "4D414F97-35A4-4B26-84FE-0E740C79722C"
// [local]  ILxSharedWork
// [export] ILxSharedWork share
// [python] ILxSharedWork:Spawn         obj SharedWork

#define LXu_THREADRANGEWORKER   "612153FE-572F-4CD6-8033-B905762C3106"
#define LXa_THREADRANGEWORKER   "threadrangeworker"
// [local] ILxThreadRangeWorker
// [export] ILxThreadRangeWorker rngw
#define LXiWLSPLIT_NONE  0
#define LXiWLSPLIT_ONE   1
#define LXiWLSPLIT_HALF  2
#define LXu_WATERFALL           "2B845B2A-06BE-4C90-8E50-58F7FBEEC25E"
#define LXa_WATERFALL           "waterfall"
// [local]  ILxWaterfall
// [export] ILxWaterfall wfall
// [python] ILxWaterfall:Spawn          obj Waterfall

#define LXiWFALL_DONE            0
#define LXiWFALL_HASWORK         1
#define LXiWFALL_NEXT_WORK       2
#define LXiWFALL_NEXT_STAGE      3

 #ifdef __cplusplus
  }
 #endif
#endif

