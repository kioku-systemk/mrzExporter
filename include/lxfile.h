/*
 * LX file module
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
#ifndef LX_file_H
#define LX_file_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxVirtualDevice ** ILxVirtualDeviceID;
typedef struct vt_ILxFileService ** ILxFileServiceID;
typedef struct vt_ILxFileReference ** ILxFileReferenceID;
#include <lxcom.h>



typedef struct vt_ILxVirtualDevice {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Initialize) (
                LXtObjectID              self,
                const char              *path);

                LXxMETHOD( LxResult,
        Select) (
                LXtObjectID              self,
                const char              *sub);

                LXxMETHOD( LxResult,
        Extract) (
                LXtObjectID              self,
                const char              *dest);

                LXxMETHOD( LxResult,
        Scan) (
                LXtObjectID              self,
                LXtObjectID              visitor);

                LXxMETHOD( LxResult,
        Type) (
                LXtObjectID              self,
                unsigned                *type);

                LXxMETHOD( LxResult,
        Name) (
                LXtObjectID              self,
                char                    *buf,
                unsigned                 len);

                LXxMETHOD( LxResult,
        Date) (
                LXtObjectID              self,
                char                    *buf,
                unsigned                 len);

                LXxMETHOD( LxResult,
        Size) (
                LXtObjectID              self,
                double                  *bytes);
} ILxVirtualDevice;
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
                LXtObjectID              self,
                const char              *path,
                const char             **extension);
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
                char                    *buf,
                unsigned                 len);

                LXxMETHOD(  LxResult,
        FileFromURL) (
                LXtObjectID              self,
                const char              *url,
                char                    *buf,
                unsigned                 len);
                LXxMETHOD(  const char *,
        FromLocal) (
                LXtObjectID              self,
                char                    *neutral,
                const char              *local);

                LXxMETHOD(  const char *,
        ToLocal) (
                LXtObjectID              self,
                char                    *local,
                const char              *neutral);

                LXxMETHOD(  const char *,
        ToLocalAlias) (
                LXtObjectID              self,
                char                    *local,
                const char              *neutral);
                LXxMETHOD( LxResult,
        AllocReference) (
                LXtObjectID              self,
                const char              *path,
                void                   **ppvObj);
} ILxFileService;
typedef struct vt_ILxFileReference {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Path) (
                LXtObjectID              self,
                const char             **path);

                LXxMETHOD( LxResult,
        NiceName) (
                LXtObjectID              self,
                char                    *buf,
                unsigned                 len);

                LXxMETHOD( LxResult,
        Type) (
                LXtObjectID              self,
                unsigned                *type);

                LXxMETHOD( LxResult,
        Mode) (
                LXtObjectID              self,
                unsigned                *mode);

                LXxMETHOD( LxResult,
        SubCount) (
                LXtObjectID              self,
                unsigned                *count);

                LXxMETHOD( LxResult,
        SubByIndex) (
                LXtObjectID              self,
                unsigned                 index,
                void                   **ppvObj);
} ILxFileReference;

#define LXu_VIRTUALDEVICE       "60B61E9D-17F3-4068-85C2-3799A73F5D95"
#define LXa_VIRTUALDEVICE       "virtualdevice"
// [export] ILxVirtualDevice vdev
// [local]  ILxVirtualDevice
#define LXu_FILESERVICE         "D792F5C0-0555-4FC7-832C-D200CDA42D97"
#define LXa_FILESERVICE         "fileservice"
// [python] ILxFileService:IsAbsolutePath       bool
// [python] ILxFileService:ArePathsEqual        bool
// [python] ILxFileService:SetExtension         bool
// [python] ILxFileService:ComposePath          bool
// [python] ILxFileService:AllocReference       obj FileReference
// [python] ILxFileService:MakeUnique:filename  vector
// [python] ILxFileService:SetExtension:path    vector
// [python] ILxFileService:FromLocal:neutral    vector
// [python] ILxFileService:ToLocal:local        vector
// [python] ILxFileService:ToLocalAlias:local   vector
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
#define LXsSYSTEM_PATH_SAMPLE           "sample"
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
#define LXiFILETYPE_UNRESOLVED          4

#define LXiFILEMODE_READ                1
#define LXiFILEMODE_WRITE               2

#define LXu_FILEREFERENCE       "A18B9A9D-6623-4463-B6AF-469771B41485"
// [local]  ILxFileReference
// [python] ILxFileReference:SubByIndex         obj FileReference
#define LXsSTAGED_FILE_LIST             "LxStagedFiles.txt"

 #ifdef __cplusplus
  }
 #endif
#endif

