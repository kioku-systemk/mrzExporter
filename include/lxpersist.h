/*
 * LX persist module
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
#ifndef LX_persist_H
#define LX_persist_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxPersistenceService ** ILxPersistenceServiceID;
typedef struct vt_ILxPersistenceClient ** ILxPersistenceClientID;
typedef struct vt_ILxPersistentEntry ** ILxPersistentEntryID;




typedef struct vt_ILxPersistenceService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD( LxResult,
        Configure) (
                LXtObjectID              self,
                const char              *name,
                LXtObjectID              obj);
                LXxMETHOD( LxResult,
        Start) (
                LXtObjectID              self,
                const char              *name,
                unsigned int             type);

                LXxMETHOD( LxResult,
        End) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD( LxResult,
        AddValue) (
                LXtObjectID              self,
                const char              *typeName);
} ILxPersistenceService;
typedef struct vt_ILxPersistenceClient {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Setup) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        SyncRead) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        SyncWrite) (
                LXtObjectID              self);
} ILxPersistenceClient;
typedef struct vt_ILxPersistentEntry {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Count) (
                LXtObjectID              self,
                unsigned int            *count);
                LXxMETHOD( LxResult,
        Select) (
                LXtObjectID              self,
                unsigned int             index);

                LXxMETHOD( LxResult,
        Lookup) (
                LXtObjectID              self,
                const char              *key);
                LXxMETHOD( LxResult,
        Append) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Insert) (
                LXtObjectID              self,
                const char              *key);
                LXxMETHOD( LxResult,
        Delete) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Clear) (
                LXtObjectID              self);
} ILxPersistentEntry;

#define LXu_PERSISTENCESERVICE  "4CB5705E-C705-499D-9561-6FD369CEFE99"
#define LXa_PERSISTENCESERVICE  "persistenceservice"
// [python] ILxPersistenceService:End   obj PersistentEntry
#define LXi_PERSIST_ATOM         0
#define LXi_PERSIST_HASH         1
#define LXi_PERSIST_LIST         2
#define LXu_PERSISTENCECLIENT   "435E3BEE-8317-4DEB-92A8-74E115384F3F"
#define LXa_PERSISTENCECLIENT   "persistenceclient"
// [local]  ILxPersistenceClient
// [export] ILxPersistenceClient cc
#define LXu_PERSISTENTENTRY     "BD3F1DF5-967B-441F-86A7-A091F2E6CDA5"
// [local] ILxPersistentEntry

 #ifdef __cplusplus
  }
 #endif
#endif

