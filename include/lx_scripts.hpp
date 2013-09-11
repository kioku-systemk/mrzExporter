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
#ifndef LXUSER_scripts_HPP
#define LXUSER_scripts_HPP

#include <lxw_scripts.hpp>
#include <string>


class CLxUser_PlatformService : public CLxLoc_PlatformService
{
    public:
                std::string
        LicensedTo ()
        {
                const char *licensee;
                CLxLoc_PlatformService::LicensedTo (&licensee);
                return std::string(licensee);
        }
                std::string
        SerialNumber ()
        {
                const char *serial;
                CLxLoc_PlatformService::SerialNumber (&serial);
                return std::string(serial);
        }
                std::string
        AppName ()
        {
                const char *appName;
                CLxLoc_PlatformService::AppName (&appName);
                return std::string(appName);
        }
                bool
        IsHeadless ()
        {
                return (CLxLoc_PlatformService::IsHeadless () == LXe_TRUE);
        }
                std::string
        OSName ()
        {
                const char *osName;
                CLxLoc_PlatformService::OSName (&osName);
                return std::string(osName);
        }
                std::string
        OSVersion ()
        {
                const char *osVersion;
                CLxLoc_PlatformService::OSVersion (&osVersion);
                return std::string(osVersion);
        }
                std::string
        PathByIndex (
                int                       index)
        {
                const char *path;
                CLxLoc_PlatformService::PathByIndex (index, &path);
                return std::string(path);
        }
                std::string
        PathNameByIndex (
                int                       index)
        {
                const char *path;
                CLxLoc_PlatformService::PathNameByIndex (index, &path);
                return std::string(path);
        }
                std::string
        ImportPathByIndex (
                int                       index)
        {
                const char *path;
                CLxLoc_PlatformService::ImportPathByIndex (index, &path);
                return std::string(path);
        }
                bool
        IsApp64Bit ()
        {
                return (CLxLoc_PlatformService::IsApp64Bit () == LXe_TRUE);
        }
};



#endif

