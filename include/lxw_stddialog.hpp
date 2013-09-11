/*
 * C++ wrapper for lxstddialog.h
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
#ifndef LXW_STDDIALOG_HPP
#define LXW_STDDIALOG_HPP

#include <lxstddialog.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_ColorDialog = {0x2AB01AAE,0x110B,0x11DF,0xBF,0xD0,0x0A,0xC7,0x56,0xD8,0x95,0x93};
    static const LXtGUID guid_StdDialogService = {0xA78FA063,0x6C8D,0x471f,0x89,0x81,0x6B,0xAE,0xFF,0x62,0xBE,0xE3};
};

class CLxImpl_ColorDialog {
  public:
    virtual ~CLxImpl_ColorDialog() {}
    virtual LxResult
      colordlg_DoDialog (const char *title, double stops, double gamma, double *rgb)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_ColorDialog : public CLxInterface
{
    static LxResult
  DoDialog (LXtObjectID wcom, const char *title, double stops, double gamma, double *rgb)
  {
    LXCWxINST (CLxImpl_ColorDialog, loc);
    try {
      return loc->colordlg_DoDialog (title,stops,gamma,rgb);
    } catch (LxResult rc) { return rc; }
  }
  ILxColorDialog vt;
public:
  CLxIfc_ColorDialog ()
  {
    vt.DoDialog = DoDialog;
    vTable = &vt.iunk;
    iid = &lx::guid_ColorDialog;
  }
};
class CLxLoc_ColorDialog : public CLxLocalize<ILxColorDialogID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_ColorDialog() {_init();}
  CLxLoc_ColorDialog(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_ColorDialog(const CLxLoc_ColorDialog &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_ColorDialog;}
    LxResult
  DoDialog (const char *title, double stops, double gamma, double *rgb)
  {
    return m_loc[0]->DoDialog (m_loc,title,stops,gamma,rgb);
  }
};

class CLxLoc_StdDialogService : public CLxLocalizedService
{
  ILxStdDialogServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_StdDialogService() {_init();set();}
 ~CLxLoc_StdDialogService() {}
  void set() {m_loc=reinterpret_cast<ILxStdDialogServiceID>(lx::GetGlobal(&lx::guid_StdDialogService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  MonitorAllocate (const char *title, void **ppvObj)
  {
    return m_loc[0]->MonitorAllocate (m_loc,title,ppvObj);
  }
    LxResult
  MonitorRelease (void)
  {
    return m_loc[0]->MonitorRelease (m_loc);
  }
    LxResult
  MessageAllocate (void **ppvObj)
  {
    return m_loc[0]->MessageAllocate (m_loc,ppvObj);
  }
    LxResult
  MessageOpen (ILxUnknownID message, const char *title, const char *helpURL, const char *cookie)
  {
    return m_loc[0]->MessageOpen (m_loc,(ILxUnknownID)message,title,helpURL,cookie);
  }
};

#endif

