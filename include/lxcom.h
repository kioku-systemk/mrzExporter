/*
 * LX xcom module
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
#ifndef LX_xcom_H
#define LX_xcom_H
 #ifdef __cplusplus
  extern "C" {
 #endif

typedef void *                   LXtObjectID;
typedef struct vt_ILxUnknown **  ILxUnknownID;
typedef struct vt_ILxGUIDService ** ILxGUIDServiceID;
#include <lxresult.h>

typedef unsigned int             LXtID4;
#define LXxMETHOD(rv,fn)        rv (*fn)
typedef struct vt_ILxUnknown {
                LXxMETHOD (LxResult,
        QueryInterface) (
                LXtObjectID              self,
                const struct st_LXtGUID *iid,
                void                   **ppvObj);

                LXxMETHOD (unsigned int,
        AddRef) (
                LXtObjectID              self);

                LXxMETHOD (unsigned int,
        Release) (
                LXtObjectID              self);
} ILxUnknown;
typedef struct st_LXtGUID {
        unsigned int             x4;
        unsigned short           x2[2];
        unsigned char            x1[8];
} LXtGUID;
typedef struct vt_ILxGUIDService {
        ILxUnknown       iunk;
                LXxMETHOD( const LXtGUID *,
        Translate) (
                LXtObjectID              self,
                const char              *guidStr);

                LXxMETHOD( const char *,
        GetName) (
                LXtObjectID              self,
                const LXtGUID           *guid);

                LXxMETHOD( int,
        Compare) (
                LXtObjectID              self,
                const LXtGUID           *guid1,
                const LXtGUID           *guid2);

                LXxMETHOD( const LXtGUID *,
        Fixed) (
                LXtObjectID              self,
                const LXtGUID           *guid);

                LXxMETHOD( const LXtGUID *,
        Class) (
                LXtObjectID              self,
                const LXtGUID           *guid);

                LXxMETHOD( const char *,
        ClassName) (
                LXtObjectID              self,
                const LXtGUID           *guid);
} ILxGUIDService;

#define LXu_UNKNOWN     "00000000-0000-0000-0000-0000000000C4"
#define LXxID4(a,b,c,d)         ((a) << 24 | (b) << 16 | (c) << 8 | (d))
#define LXu_GUIDSERVICE         "B11826F1-A6BC-48B4-909B-5F6D01938327"
#define LXa_GUIDSERVICE         "guidservice"
#if defined(_MSC_VER)
        #define LXx_OVERRIDE override
#else
        #ifndef __has_feature
                #define __has_feature(x) 0
        #endif

        #if __has_feature(cxx_override_control)
                #define LXx_OVERRIDE override
        #else
                #define LXx_OVERRIDE
        #endif
#endif

 #ifdef __cplusplus
  }
 #endif
#endif

