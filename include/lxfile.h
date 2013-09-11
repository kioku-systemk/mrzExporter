/*
 * LX file module
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
#ifndef LX_file_H
#define LX_file_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxFileService ** ILxFileServiceID;
#include <lxcom.h>



typedef struct vt_ILxFileService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        FileSystemPath) (
                LXtObjectID               self,
                const char               *name,
                const char              **path);
                LXxMETHOD(  const char *,
        FileSystemDefaultIO) (
                LXtObjectID              self,
                int                      isForLoad);
                LXxMETHOD(  LxResult,
        IsAbsolutePath) (
                LXtObjectID              self,
                const char              *path);
                LXxMETHOD(  LxResult,
        ArePathsEqual) (
                LXtObjectID              self,
                const char              *path1,
                const char              *path2);
                LXxMETHOD(  LxResult,
        ParsePath) (
                LXtObjectID              self,
                const char              *filename,
                char                    *basename,
                char                    *path);
                LXxMETHOD(  LxResult,
        ComposePath) (
                LXtObjectID              self,
                char                    *filename,
                const char              *basename,
                const char              *path);
                LXxMETHOD(  LxResult,
        MakeRelative) (
                LXtObjectID              self,
                char                    *relname,
                const char              *filename,
                const char              *path);
                LXxMETHOD(  LxResult,
        MakeUnique) (
                LXtObjectID              self,
                char                    *filename);
                LXxMETHOD(  LxResult,
        FindExtension) (
                LXtObjectID               self,
                char                     *path,
                char                    **extension);
                LXxMETHOD(  LxResult,
        SetExtension) (
                LXtObjectID              self,
                char                    *path,
                const char              *extension);
                LXxMETHOD(  LxResult,
        MakeDirectory) (
                LXtObjectID               self,
                const char               *path);
                LXxMETHOD(  LxResult,
        TestFileType) (
                LXtObjectID              self,
                const char              *filename,
                int                     *type);
                LXxMETHOD(  LxResult,
        TestFileMode) (
                LXtObjectID              self,
                const char              *filename,
                int                     *mode);
                LXxMETHOD(  LxResult,
        RenameFile) (
                LXtObjectID              self,
                const char              *from,
                const char              *to);
                LXxMETHOD(  LxResult,
        FileCopy) (
                LXtObjectID              self,
                const char              *srcFilePath,
                const char              *dstFilePath,
                int                      overwrite);
                LXxMETHOD(  LxResult,
        FileDelete) (
                LXtObjectID              self,
                const char              *filename);
                LXxMETHOD(  LxResult,
        OpenFileWithDefaultApp) (
                LXtObjectID              self,
                const char              *filename);
                LXxMETHOD(  LxResult,
        RevealInFileViewer) (
                LXtObjectID              self,
                const char              *filename);
                LXxMETHOD(  LxResult,
        Execute) (
                LXtObjectID              self,
                const char              **argv,
                int                       show,
                int                       force32);
                LXxMETHOD(  LxResult,
        FileToURL) (
                LXtObjectID              self,
                const char              *filename,
                char                    *urlBuffer,
                int                      urlBufferLen);

                LXxMETHOD(  LxResult,
        FileFromURL) (
                LXtObjectID              self,
                const char              *url,
                char                    *filenameBuffer,
                int                      filenameBufferLen);
                LXxMETHOD(  char *,
        FromLocal) (
                LXtObjectID              self,
                char                    *neutral,
                const char              *local);

                LXxMETHOD(  char *,
        ToLocal) (
                LXtObjectID              self,
                char                    *local,
                const char              *neutral);

                LXxMETHOD(  char *,
        ToLocalAlias) (
                LXtObjectID              self,
                char                    *local,
                const char              *neutral);
} ILxFileService;

#define LXu_FILESERVICE         "D792F5C0-0555-4FC7-832C-D200CDA42D97"
#define LXa_FILESERVICE         "fileservice"

#define LXsSYSTEM_PATH_PROGRAM          "program"
#define LXsSYSTEM_PATH_EXENAME          "exename"
#define LXsSYSTEM_PATH_PROJECT          "project"
#define LXsSYSTEM_PATH_TEMP             "temp"
#define LXsSYSTEM_PATH_LICENSE          "license"
#define LXsSYSTEM_PATH_RESOURCE         "resource"
#define LXsSYSTEM_PATH_MODULE           "module"
#define LXsSYSTEM_PATH_PREFS            "prefs"
#define LXsSYSTEM_PATH_HELP             "help"
#define LXsSYSTEM_PATH_USER             "user"
#define LXsSYSTEM_PATH_CONTENT          "content"
#define LXsSYSTEM_PATH_ASSET            "asset"
#define LXsSYSTEM_PATH_HEADLESS         "headless"
#define LXsSYSTEM_PATH_HEADLESS32       "headless32"
#define LXsSYSTEM_PATH_CONFIGS          "configs"
#define LXsSYSTEM_PATH_SCRIPTS          "scripts"
#define LXsSYSTEM_PATH_DOCUMENTS        "documents"
#define LXsSYSTEM_PATH_KITS             "kits"

#define LXiFILETYPE_NONE                0
#define LXiFILETYPE_NORMAL              1
#define LXiFILETYPE_DIRECTORY           2
#define LXiFILETYPE_UNKNOWN             3

#define LXiFILEMODE_READ                1
#define LXiFILEMODE_WRITE               2

#define LXsSTAGED_FILE_LIST             "LxStagedFiles.txt"

 #ifdef __cplusplus
  }
 #endif
#endif

