/*
 * Plug-in SDK Header: C++ User Classes
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
#ifndef LXUSER_file_HPP
#define LXUSER_file_HPP

#include <lxw_file.hpp>
#include <string>


class CLxUser_FileService : public CLxLoc_FileService
{
    public:
                LxResult
        FileSystemPath (
                const std::string       &name,
                std::string             &path)
        {
                LxResult        result;
                const char*     systemPath;

                result = CLxLoc_FileService::FileSystemPath (
                        name.c_str (), &systemPath);
                if (LXx_OK (result)) {
                        path = std::string(systemPath);
                }

                return result;
        }
                LxResult
        ComposePath (
                std::string             &fullPath,
                const std::string       &basename,
                const std::string       &path)
        {
                const size_t MAX_FILE_PATH_LEN = 1024;
                char fullFilePath[MAX_FILE_PATH_LEN];

                LxResult result = CLxLoc_FileService::ComposePath (
                        fullFilePath, basename.c_str (), path.c_str ());

                if (LXx_OK (result)) {
                        fullPath = std::string(fullFilePath);
                }

                return result;
        }

                LxResult
        MakeDirectory (
                const std::string       &path)
        {
                return CLxLoc_FileService::MakeDirectory (path.c_str ());
        }

                LxResult
        TestFileType (
                std::string             &filename,
                int                     *fileType)
        {
                return CLxLoc_FileService::TestFileType (filename.c_str (), fileType);
        }
};



#endif

