/*
 * LX log module
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
#ifndef LX_log_H
#define LX_log_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxLogService ** ILxLogServiceID;
typedef struct vt_ILxLogInfoBlock ** ILxLogInfoBlockID;
typedef struct vt_ILxLog ** ILxLogID;
typedef struct vt_ILxLogEntry ** ILxLogEntryID;
typedef struct vt_ILxLogListener ** ILxLogListenerID;
#include <lxcom.h>
#include <lxvmath.h>
#ifdef long
 #undef long
  #include <stdio.h>
  #include <stdarg.h>
  #include <time.h>
 #define long   longs_are_evil
#else
  #include <stdio.h>
  #include <stdarg.h>
  #include <time.h>
#endif

/*
 * Suppress warnings for deprecated functions.
 */
#ifdef _MSC_VER
        #define _CRT_SECURE_NO_WARNINGS 1
        #define _CRT_SECURE_NO_DEPRECATE 1
        #pragma warning(disable: 4996)
#endif



typedef struct vt_ILxLogService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        SubSystemCount) (
                LXtObjectID              self,
                unsigned int            *count);
                LXxMETHOD(  LxResult,
        SubSystemByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        SubSystemLookup) (
                LXtObjectID              self,
                const char              *name,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        MasterSubSystem) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        InfoBlockCount) (
                LXtObjectID              self,
                unsigned int            *count);
                LXxMETHOD(  LxResult,
        InfoBlockByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        InfoBlockLookup) (
                LXtObjectID              self,
                const char              *name,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        InfoBlockFieldsAreSameGroup) (
                LXtObjectID              self,
                const char              *name1,
                const char              *name2);
                LXxMETHOD(  LxResult,
        InfoBlockFieldGetParts) (
                LXtObjectID               self,
                const char               *name,
                const char              **group,
                const char              **sub);
                LXxMETHOD(  LxResult,
        CreateEntryMessage) (
                LXtObjectID              self,
                LxResult                 type,
                const char              *message,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        CreateEntryInfoBlock) (
                LXtObjectID              self,
                LxResult                 type,
                const char              *blockName,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        CreateEntryPaired) (
                LXtObjectID              self,
                LxResult                 type,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        SetMonitor) (
                LXtObjectID              self,
                LXtObjectID              monitor);
                LXxMETHOD(  LXtObjectID,
        AcquireMonitor) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        EnableLogging) (
                LXtObjectID              self,
                const char              *systemName,
                unsigned int             state);
                LXxMETHOD(  LxResult,
        IsLoggingEnabled) (
                LXtObjectID              self,
                const char              *systemName);
                LXxMETHOD(  LxResult,
        CreateEntryMessageFromMsgObj) (
                LXtObjectID              self,
                LXtObjectID              msgObj,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        DebugLogOutput) (
                LXtObjectID              self,
                unsigned int             level,
                const char              *line);
                LXxMETHOD(  LxResult,
        DebugLogOutputSys) (
                LXtObjectID              self,
                unsigned int             level,
                const char              *logSystem,
                const char              *line);
} ILxLogService;
typedef struct vt_ILxLogInfoBlock {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Name) (
                LXtObjectID               self,
                const char              **name);
                LXxMETHOD(  LxResult,
        FieldCount) (
                LXtObjectID              self,
                unsigned int            *count);

                LXxMETHOD(  LxResult,
        FieldName) (
                LXtObjectID               self,
                unsigned int              index,
                const char              **name);

                LXxMETHOD(  LxResult,
        FieldType) (
                LXtObjectID               self,
                unsigned int              index,
                const char              **type);
} ILxLogInfoBlock;
typedef struct vt_ILxLog {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        AddEntry) (
                LXtObjectID              self,
                LXtObjectID              entry);
                LXxMETHOD(  LxResult,
        RollEntry) (
                LXtObjectID              self,
                LXtObjectID              entry);
                LXxMETHOD(  LxResult,
        RollClear) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        EntryCount) (
                LXtObjectID              self,
                unsigned int            *count );
                LXxMETHOD(  LxResult,
        EntryByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **ppvObj );
                LXxMETHOD(  LXtObjectID,
        PeekEntryByIndex) (
                LXtObjectID              self,
                unsigned int             index );
                LXxMETHOD(  LxResult,
        GetCurrentEntry) (
                LXtObjectID              self,
                void                   **ppvObj );
                LXxMETHOD(  LxResult,
        SetMaxEntries) (
                LXtObjectID              self,
                unsigned int             max );
                LXxMETHOD(  LxResult,
        GetMaxEntries) (
                LXtObjectID              self,
                unsigned int            *max );
                LXxMETHOD(  LxResult,
        GetRolling) (
                LXtObjectID              self,
                void                   **ppvObj );
                LXxMETHOD(  LxResult,
        ClearAll) (
                LXtObjectID              self );
                LXxMETHOD(  LxResult,
        Name) (
                LXtObjectID               self,
                const char              **name );
} ILxLog;
typedef struct vt_ILxLogEntry {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        AddEntry) (
                LXtObjectID              self,
                LXtObjectID              entry);
                LXxMETHOD(  LxResult,
        SetTitle) (
                LXtObjectID              self,
                const char              *title );
                LXxMETHOD(  LxResult,
        SetDesc) (
                LXtObjectID              self,
                const char              *desc );
                LXxMETHOD(  LxResult,
        SetValue) (
                LXtObjectID              self,
                const char              *name,
                unsigned int             index,
                LXtObjectID              value );
                LXxMETHOD(  LxResult,
        AddPair) (
                LXtObjectID              self,
                const char              *name,
                const char              *value );
                LXxMETHOD(  LxResult,
        Class) (
                LXtObjectID              self,
                unsigned int            *classType );
                LXxMETHOD(  LxResult,
        Type) (
                LXtObjectID              self,
                LxResult                *type );
                LXxMETHOD(  LxResult,
        Time) (
                LXtObjectID              self,
                time_t                  *time );
                LXxMETHOD(  LxResult,
        TimeString) (
                LXtObjectID               self,
                const char              **string );
                LXxMETHOD(  LxResult,
        ChildCount) (
                LXtObjectID              self,
                unsigned int            *count );
                LXxMETHOD(  LxResult,
        ChildByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **ppvObj );
                LXxMETHOD(  LXtObjectID,
        PeekChildByIndex) (
                LXtObjectID              self,
                unsigned int             index );
                LXxMETHOD(  LxResult,
        SubSystemCount) (
                LXtObjectID              self,
                unsigned int            *count );
                LXxMETHOD(  LxResult,
        SubSystemByIndex) (
                LXtObjectID              self,
                unsigned int             index,
                void                   **ppvObj );
                LXxMETHOD(  LxResult,
        Message) (
                LXtObjectID               self,
                const char              **message );
                LXxMETHOD(  LxResult,
        Title) (
                LXtObjectID               self,
                const char              **title );
                LXxMETHOD(  LxResult,
        Desc) (
                LXtObjectID               self,
                const char              **desc );
                LXxMETHOD(  LxResult,
        InfoBlock) (
                LXtObjectID               self,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        InfoBlockValue) (
                LXtObjectID              self,
                const char              *name,
                unsigned int             index,
                void                   **ppvObj );
                LXxMETHOD(  LxResult,
        PairCount) (
                LXtObjectID               self,
                unsigned int             *count );
                LXxMETHOD(  LxResult,
        PairName) (
                LXtObjectID               self,
                unsigned int              index,
                const char              **name );
                LXxMETHOD(  LxResult,
        PairValue) (
                LXtObjectID               self,
                unsigned int              index,
                const char              **value );
} ILxLogEntry;
typedef struct vt_ILxLogListener {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        SystemAdded) (
                LXtObjectID              self,
                LXtObjectID              system);
                LXxMETHOD( void,
        EntryAdded) (
                LXtObjectID              self,
                LXtObjectID              system,
                LXtObjectID              entry);
                LXxMETHOD( void,
        ChildEntryAdded) (
                LXtObjectID              self,
                LXtObjectID              entry,
                LXtObjectID              parentEntry);
                LXxMETHOD( void,
        EntryDropped) (
                LXtObjectID              self,
                LXtObjectID              system,
                LXtObjectID              entry);
                LXxMETHOD( void,
        RollingEntryAdded) (
                LXtObjectID              self,
                LXtObjectID              system,
                LXtObjectID              entry);

                LXxMETHOD( void,
        RollingChildEntryAdded) (
                LXtObjectID              self,
                LXtObjectID              entry,
                LXtObjectID              parentEntry);

                LXxMETHOD( void,
        RollingEntryDropped) (
                LXtObjectID              self,
                LXtObjectID              system,
                LXtObjectID              entry);
} ILxLogListener;

#define LXu_LOGSERVICE  "0BC355C2-5E6B-49EF-B368-600D9F26F543"
#define LXa_LOGSERVICE  "logservice"

// [python] ILxLogService:CreateEntryInfoBlock  obj LogEntry
// [python] ILxLogService:CreateEntryMessage    obj LogEntry
// [python] ILxLogService:CreateEntryMessageFromMsgObj  obj LogEntry
// [python] ILxLogService:CreateEntryPaired     obj LogEntry
// [python] ILxLogService:InfoBlockByIndex      obj LogInfoBlock
// [python] ILxLogService:InfoBlockLookup       obj LogInfoBlock
// [python] ILxLogService:MasterSubSystem       obj Log
// [python] ILxLogService:SubSystemByIndex      obj Log
// [python] ILxLogService:SubSystemLookup       obj Log
// [python] ILxLogService:InfoBlockFieldsAreSameGroup   bool
// [python] ILxLogService:IsLoggingEnabled      bool
#define LXsLOG_LOGSYS    "logsys"
#define LXsSRV_LOGSUBSYSTEM     "server.logsubsystem"
#define LXsLOG_MASTERSYS         "master"
#define LXe_LOG_DEBUG   LXxGOODCODE(LXeSYS_LOG,1)
#define LXi_DBLOG_ERROR          1
#define LXi_DBLOG_NORMAL         2
#define LXi_DBLOG_TRACE          3
#define LXi_DBLOG_VERBOSE        4
#define LXu_LOGINFOBLOCK        "B9AEE11A-3501-4dc2-90A6-41F2435856C6"
#define LXa_LOGINFOBLOCK        "loginfoblock"
// [local]  ILxLogInfoBlock
// [export] ILxLogInfoBlock lb
#define LXu_LOG         "1890538F-D64C-478c-8472-228B7C9AB1DF"
#define LXa_LOG         "logsubsystem"
// [local]  ILxLog

// [python] ILxLog:EntryByIndex         obj LogEntry
// [python] ILxLog:GetCurrentEntry      obj LogEntry
// [python] ILxLog:GetRolling           obj LogEntry
#define LXu_LOGENTRY    "E83679B2-DB4D-4D90-B81B-5F786D212FB3"
#define LXa_LOGENTRY    "logentry"
// [local]  ILxLogEntry

// [python] ILxLogEntry:ChildByIndex            obj LogEntry
// [python] ILxLogEntry:InfoBlock               obj LogInfoBlock
// [python] ILxLogEntry:InfoBlockValue          obj Unknown
// [python] ILxLogEntry:SubSystemByIndex        obj Unknown
#define LXiLOGCLASS_MESSAGE     0
#define LXiLOGCLASS_BLOCK       1
#define LXiLOGCLASS_PAIRS       2
#define LXu_LOGLISTENER         "c5fd260b-cab7-4283-b876-2314144ae83a"

 #ifdef __cplusplus
  }
 #endif
#endif

