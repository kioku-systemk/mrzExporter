/*
 * C++ wrapper for lxfile.h
 *
 *	Copyright (c) 2008-2012 Luxology LLC
 *	
 *	Permission is hereby granted, free of charge, to any person obtaining a
 *	copy of this software and associated documentation files (the "Software"),
 *	to deal in the Software without restriction, including without limitation
 *	the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *	and/or sell copies of the Software, and to permit persons to whom the
 *	Software is furnished to do so, subject to the following conditions:
 *	
 *	The above copyright notice and this permission notice shall be included in
 *	all copies or substantial portions of the Software.   Except as contained
 *	in this notice, the name(s) of the above copyright holders shall not be
 *	used in advertising or otherwise to promote the sale, use or other dealings
 *	in this Software without prior written authorization.
 *	
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *	DEALINGS IN THE SOFTWARE.
 *
 */
#ifndef LXW_FILE_HPP
#define LXW_FILE_HPP

#include <lxfile.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_FileService = {0xD792F5C0,0x0555,0x4FC7,0x83,0x2C,0xD2,0x00,0xCD,0xA4,0x2D,0x97};
};

class CLxLoc_FileService : public CLxLocalizedService
{
  ILxFileServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_FileService() {_init();set();}
 ~CLxLoc_FileService() {}
  void set() {m_loc=reinterpret_cast<ILxFileServiceID>(lx::GetGlobal(&lx::guid_FileService));}
    LxResult
  FileSystemPath (const char *name, const char **path)
  {
    return m_loc[0]->FileSystemPath (m_loc,name,path);
  }
    const char *
  FileSystemDefaultIO (int isForLoad)
  {
    return m_loc[0]->FileSystemDefaultIO (m_loc,isForLoad);
  }
    LxResult
  IsAbsolutePath (const char *path)
  {
    return m_loc[0]->IsAbsolutePath (m_loc,path);
  }
    LxResult
  ArePathsEqual (const char *path1, const char *path2)
  {
    return m_loc[0]->ArePathsEqual (m_loc,path1,path2);
  }
    LxResult
  ParsePath (const char *filename, char *basename, char *path)
  {
    return m_loc[0]->ParsePath (m_loc,filename,basename,path);
  }
    LxResult
  ComposePath (char *filename, const char *basename, const char *path)
  {
    return m_loc[0]->ComposePath (m_loc,filename,basename,path);
  }
    LxResult
  MakeRelative (char *relname, const char *filename, const char *path)
  {
    return m_loc[0]->MakeRelative (m_loc,relname,filename,path);
  }
    LxResult
  MakeUnique (char *filename)
  {
    return m_loc[0]->MakeUnique (m_loc,filename);
  }
    LxResult
  FindExtension (char *path, char **extension)
  {
    return m_loc[0]->FindExtension (m_loc,path,extension);
  }
    LxResult
  SetExtension (char *path, const char *extension)
  {
    return m_loc[0]->SetExtension (m_loc,path,extension);
  }
    LxResult
  MakeDirectory (const char *path)
  {
    return m_loc[0]->MakeDirectory (m_loc,path);
  }
    LxResult
  TestFileType (const char *filename, int *type)
  {
    return m_loc[0]->TestFileType (m_loc,filename,type);
  }
    LxResult
  TestFileMode (const char *filename, int *mode)
  {
    return m_loc[0]->TestFileMode (m_loc,filename,mode);
  }
    LxResult
  RenameFile (const char *from, const char *to)
  {
    return m_loc[0]->RenameFile (m_loc,from,to);
  }
    LxResult
  FileCopy (const char *srcFilePath, const char *dstFilePath, int overwrite)
  {
    return m_loc[0]->FileCopy (m_loc,srcFilePath,dstFilePath,overwrite);
  }
    LxResult
  FileDelete (const char *filename)
  {
    return m_loc[0]->FileDelete (m_loc,filename);
  }
    LxResult
  OpenFileWithDefaultApp (const char *filename)
  {
    return m_loc[0]->OpenFileWithDefaultApp (m_loc,filename);
  }
    LxResult
  RevealInFileViewer (const char *filename)
  {
    return m_loc[0]->RevealInFileViewer (m_loc,filename);
  }
    LxResult
  Execute (const char **argv, int show, int force32)
  {
    return m_loc[0]->Execute (m_loc,argv,show,force32);
  }
    LxResult
  FileToURL (const char *filename, char *urlBuffer, int urlBufferLen)
  {
    return m_loc[0]->FileToURL (m_loc,filename,urlBuffer,urlBufferLen);
  }
    LxResult
  FileFromURL (const char *url, char *filenameBuffer, int filenameBufferLen)
  {
    return m_loc[0]->FileFromURL (m_loc,url,filenameBuffer,filenameBufferLen);
  }
    char *
  FromLocal (char *neutral, const char *local)
  {
    return m_loc[0]->FromLocal (m_loc,neutral,local);
  }
    char *
  ToLocal (char *local, const char *neutral)
  {
    return m_loc[0]->ToLocal (m_loc,local,neutral);
  }
    char *
  ToLocalAlias (char *local, const char *neutral)
  {
    return m_loc[0]->ToLocalAlias (m_loc,local,neutral);
  }
};

#endif

