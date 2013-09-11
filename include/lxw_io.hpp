/*
 * C++ wrapper for lxio.h
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
#ifndef LXW_IO_HPP
#define LXW_IO_HPP

#include <lxio.h>
#include <lx_wrap.hpp>

namespace lx {
    static const LXtGUID guid_BlockWrite = {0xADE569E1,0xE9A1,0x4AD6,0xB6,0x25,0x63,0x40,0x93,0x66,0x09,0x65};
    static const LXtGUID guid_StreamIO = {0x2884D6EE,0x4BA7,0x46D6,0xA7,0x76,0x8E,0xE2,0x2C,0x9F,0xD4,0x14};
    static const LXtGUID guid_Monitor = {0x2B514D4C,0x5142,0x4687,0xBC,0xEF,0xB0,0xFD,0x44,0xA3,0x31,0x46};
    static const LXtGUID guid_Loader = {0x73333A41,0x3C0A,0x4B0E,0xA7,0xC5,0xD7,0x66,0x09,0x82,0x7A,0x2D};
    static const LXtGUID guid_BlockRead = {0x36A00A47,0x2664,0x49E0,0xBA,0xFF,0x26,0x3E,0x63,0x85,0x32,0xB5};
    static const LXtGUID guid_IOService = {0x9970CCAD,0x7322,0x4CD6,0xA6,0xBA,0x96,0x3A,0x63,0xDE,0x57,0xD7};
    static const LXtGUID guid_Saver = {0x75AD8F36,0x5B69,0x413b,0xA7,0x7B,0x5A,0x78,0xD3,0x9A,0xEF,0x51};
};

class CLxLoc_BlockWrite : public CLxLocalize<ILxBlockWriteID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_BlockWrite() {_init();}
  CLxLoc_BlockWrite(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_BlockWrite(const CLxLoc_BlockWrite &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_BlockWrite;}
    LxResult
  WriteBlock (const LXtBlockHeader *head, int flags)
  {
    return m_loc[0]->WriteBlock (m_loc,head,flags);
  }
    void
  End (void)
  {
    m_loc[0]->End (m_loc);
  }
    int
  Depth (void)
  {
    return m_loc[0]->Depth (m_loc);
  }
    LxResult
  WriteI1 (const char *data, int count)
  {
    return m_loc[0]->WriteI1 (m_loc,data,count);
  }
    LxResult
  WriteI2 (const short *data, int count)
  {
    return m_loc[0]->WriteI2 (m_loc,data,count);
  }
    LxResult
  WriteI4 (const int *data, int count)
  {
    return m_loc[0]->WriteI4 (m_loc,data,count);
  }
    LxResult
  WriteU1 (const unsigned char *data, int count)
  {
    return m_loc[0]->WriteU1 (m_loc,data,count);
  }
    LxResult
  WriteU2 (const unsigned short *data, int count)
  {
    return m_loc[0]->WriteU2 (m_loc,data,count);
  }
    LxResult
  WriteU4 (const unsigned int *data, int count)
  {
    return m_loc[0]->WriteU4 (m_loc,data,count);
  }
    LxResult
  WriteFP (const float *data, int count)
  {
    return m_loc[0]->WriteFP (m_loc,data,count);
  }
    LxResult
  WriteFP8 (const double *data, int count)
  {
    return m_loc[0]->WriteFP8 (m_loc,data,count);
  }
    LxResult
  WriteString (const char *str)
  {
    return m_loc[0]->WriteString (m_loc,str);
  }
    LxResult
  WriteIDCode (const LXtBlockHeader *ident)
  {
    return m_loc[0]->WriteIDCode (m_loc,ident);
  }
    LxResult
  WriteVX (const unsigned int *data, int count)
  {
    return m_loc[0]->WriteVX (m_loc,data,count);
  }
};

class CLxImpl_StreamIO {
  public:
    virtual ~CLxImpl_StreamIO() {}
    virtual LxResult
      io_Write (ILxUnknownID stream)
        { return LXe_NOTIMPL; }
    virtual LxResult
      io_Read (ILxUnknownID stream)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_StreamIO : public CLxInterface
{
    static LxResult
  Write (LXtObjectID wcom, LXtObjectID stream)
  {
    LXCWxINST (CLxImpl_StreamIO, loc);
    try {
      return loc->io_Write ((ILxUnknownID)stream);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Read (LXtObjectID wcom, LXtObjectID stream)
  {
    LXCWxINST (CLxImpl_StreamIO, loc);
    try {
      return loc->io_Read ((ILxUnknownID)stream);
    } catch (LxResult rc) { return rc; }
  }
  ILxStreamIO vt;
public:
  CLxIfc_StreamIO ()
  {
    vt.Write = Write;
    vt.Read = Read;
    vTable = &vt.iunk;
    iid = &lx::guid_StreamIO;
  }
};
class CLxLoc_StreamIO : public CLxLocalize<ILxStreamIOID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_StreamIO() {_init();}
  CLxLoc_StreamIO(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_StreamIO(const CLxLoc_StreamIO &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_StreamIO;}
    LxResult
  Write (ILxUnknownID stream)
  {
    return m_loc[0]->Write (m_loc,(ILxUnknownID)stream);
  }
    LxResult
  Read (ILxUnknownID stream)
  {
    return m_loc[0]->Read (m_loc,(ILxUnknownID)stream);
  }
};

class CLxImpl_Monitor {
  public:
    virtual ~CLxImpl_Monitor() {}
    virtual LxResult
      mon_Initialize (unsigned int count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      mon_Increment (unsigned int count)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_Monitor : public CLxInterface
{
    static LxResult
  Initialize (LXtObjectID wcom, unsigned int count)
  {
    LXCWxINST (CLxImpl_Monitor, loc);
    try {
      return loc->mon_Initialize (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Increment (LXtObjectID wcom, unsigned int count)
  {
    LXCWxINST (CLxImpl_Monitor, loc);
    try {
      return loc->mon_Increment (count);
    } catch (LxResult rc) { return rc; }
  }
  ILxMonitor vt;
public:
  CLxIfc_Monitor ()
  {
    vt.Initialize = Initialize;
    vt.Increment = Increment;
    vTable = &vt.iunk;
    iid = &lx::guid_Monitor;
  }
};
class CLxLoc_Monitor : public CLxLocalize<ILxMonitorID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Monitor() {_init();}
  CLxLoc_Monitor(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Monitor(const CLxLoc_Monitor &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Monitor;}
    LxResult
  Initialize (unsigned int count)
  {
    return m_loc[0]->Initialize (m_loc,count);
  }
    LxResult
  Increment (unsigned int count)
  {
    return m_loc[0]->Increment (m_loc,count);
  }
};

class CLxImpl_Loader {
  public:
    virtual ~CLxImpl_Loader() {}
    virtual LxResult
      load_Recognize (LXtLoadAccess *load)
        { return LXe_NOTIMPL; }
    virtual LxResult
      load_LoadInstance (LXtLoadAccess *load, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      load_LoadObject (LXtLoadAccess *load, ILxUnknownID dest)
        { return LXe_NOTIMPL; }
    virtual LxResult
      load_Cleanup (LXtLoadAccess *load)
        { return LXe_NOTIMPL; }
    virtual LxResult
      load_SpawnOptions (void **ppvObj)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_Loader : public CLxInterface
{
    static LxResult
  Recognize (LXtObjectID wcom, LXtLoadAccess *load)
  {
    LXCWxINST (CLxImpl_Loader, loc);
    try {
      return loc->load_Recognize (load);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LoadInstance (LXtObjectID wcom, LXtLoadAccess *load, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Loader, loc);
    try {
      return loc->load_LoadInstance (load,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  LoadObject (LXtObjectID wcom, LXtLoadAccess *load, LXtObjectID dest)
  {
    LXCWxINST (CLxImpl_Loader, loc);
    try {
      return loc->load_LoadObject (load,(ILxUnknownID)dest);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Cleanup (LXtObjectID wcom, LXtLoadAccess *load)
  {
    LXCWxINST (CLxImpl_Loader, loc);
    try {
      return loc->load_Cleanup (load);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SpawnOptions (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Loader, loc);
    try {
      return loc->load_SpawnOptions (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
  ILxLoader vt;
public:
  CLxIfc_Loader ()
  {
    vt.Recognize = Recognize;
    vt.LoadInstance = LoadInstance;
    vt.LoadObject = LoadObject;
    vt.Cleanup = Cleanup;
    vt.SpawnOptions = SpawnOptions;
    vTable = &vt.iunk;
    iid = &lx::guid_Loader;
  }
};
class CLxLoc_Loader : public CLxLocalize<ILxLoaderID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Loader() {_init();}
  CLxLoc_Loader(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Loader(const CLxLoc_Loader &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Loader;}
    LxResult
  Recognize (LXtLoadAccess *load)
  {
    return m_loc[0]->Recognize (m_loc,load);
  }
    LxResult
  LoadInstance (LXtLoadAccess *load, void **ppvObj)
  {
    return m_loc[0]->LoadInstance (m_loc,load,ppvObj);
  }
    LxResult
  LoadObject (LXtLoadAccess *load, ILxUnknownID dest)
  {
    return m_loc[0]->LoadObject (m_loc,load,(ILxUnknownID)dest);
  }
    LxResult
  Cleanup (LXtLoadAccess *load)
  {
    return m_loc[0]->Cleanup (m_loc,load);
  }
    LxResult
  SpawnOptions (void **ppvObj)
  {
    return m_loc[0]->SpawnOptions (m_loc,ppvObj);
  }
};

class CLxLoc_BlockRead : public CLxLocalize<ILxBlockReadID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_BlockRead() {_init();}
  CLxLoc_BlockRead(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_BlockRead(const CLxLoc_BlockRead &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_BlockRead;}
    LxResult
  FindBlock (const LXtBlockHeader *head, int flags, LXtID4 *blkId)
  {
    return m_loc[0]->FindBlock (m_loc,head,flags,blkId);
  }
    void
  End (void)
  {
    m_loc[0]->End (m_loc);
  }
    int
  Depth (void)
  {
    return m_loc[0]->Depth (m_loc);
  }
    LxResult
  ReadI1 (char *data, int count, int *ocount)
  {
    return m_loc[0]->ReadI1 (m_loc,data,count,ocount);
  }
    LxResult
  ReadI2 (short *data, int count, int *ocount)
  {
    return m_loc[0]->ReadI2 (m_loc,data,count,ocount);
  }
    LxResult
  ReadI4 (int *data, int count, int *ocount)
  {
    return m_loc[0]->ReadI4 (m_loc,data,count,ocount);
  }
    LxResult
  ReadU1 (unsigned char *data, int count, int *ocount)
  {
    return m_loc[0]->ReadU1 (m_loc,data,count,ocount);
  }
    LxResult
  ReadU2 (unsigned short *data, int count, int *ocount)
  {
    return m_loc[0]->ReadU2 (m_loc,data,count,ocount);
  }
    LxResult
  ReadU4 (unsigned int *data, int count, int *ocount)
  {
    return m_loc[0]->ReadU4 (m_loc,data,count,ocount);
  }
    LxResult
  ReadFP (float *data, int count, int *ocount)
  {
    return m_loc[0]->ReadFP (m_loc,data,count,ocount);
  }
    LxResult
  ReadFP8 (double *data, int count, int *ocount)
  {
    return m_loc[0]->ReadFP8 (m_loc,data,count,ocount);
  }
    LxResult
  ReadString (char *buf, int max, int flags, int *ocount)
  {
    return m_loc[0]->ReadString (m_loc,buf,max,flags,ocount);
  }
    LxResult
  ReadIDCode (const LXtBlockHeader *list, LXtID4 *idCode)
  {
    return m_loc[0]->ReadIDCode (m_loc,list,idCode);
  }
    LxResult
  ReadVX (unsigned *data, int count, int *ocount)
  {
    return m_loc[0]->ReadVX (m_loc,data,count,ocount);
  }
};

class CLxLoc_IOService : public CLxLocalizedService
{
  ILxIOServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_IOService() {_init();set();}
 ~CLxLoc_IOService() {}
  void set() {m_loc=reinterpret_cast<ILxIOServiceID>(lx::GetGlobal(&lx::guid_IOService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  SetOptions (ILxUnknownID options)
  {
    return m_loc[0]->SetOptions (m_loc,(ILxUnknownID)options);
  }
    ILxUnknownID
  PeekOptions (void)
  {
    return (ILxUnknownID) m_loc[0]->PeekOptions (m_loc);
  }
};

class CLxImpl_Saver {
  public:
    virtual ~CLxImpl_Saver() {}
    virtual LxResult
      sav_Verify (ILxUnknownID source, ILxUnknownID message)
        { return LXe_NOTIMPL; }
    virtual LxResult
      sav_Save (ILxUnknownID source, const char *filename, ILxUnknownID monitor)
        { return LXe_NOTIMPL; }
};
template <class T>
class CLxIfc_Saver : public CLxInterface
{
    static LxResult
  Verify (LXtObjectID wcom, LXtObjectID source, LXtObjectID message)
  {
    LXCWxINST (CLxImpl_Saver, loc);
    try {
      return loc->sav_Verify ((ILxUnknownID)source,(ILxUnknownID)message);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Save (LXtObjectID wcom, LXtObjectID source, const char *filename, LXtObjectID monitor)
  {
    LXCWxINST (CLxImpl_Saver, loc);
    try {
      return loc->sav_Save ((ILxUnknownID)source,filename,(ILxUnknownID)monitor);
    } catch (LxResult rc) { return rc; }
  }
  ILxSaver vt;
public:
  CLxIfc_Saver ()
  {
    vt.Verify = Verify;
    vt.Save = Save;
    vTable = &vt.iunk;
    iid = &lx::guid_Saver;
  }
};
class CLxLoc_Saver : public CLxLocalize<ILxSaverID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Saver() {_init();}
  CLxLoc_Saver(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Saver(const CLxLoc_Saver &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Saver;}
    LxResult
  Verify (ILxUnknownID source, ILxUnknownID message)
  {
    return m_loc[0]->Verify (m_loc,(ILxUnknownID)source,(ILxUnknownID)message);
  }
    LxResult
  Save (ILxUnknownID source, const char *filename, ILxUnknownID monitor)
  {
    return m_loc[0]->Save (m_loc,(ILxUnknownID)source,filename,(ILxUnknownID)monitor);
  }
};

#endif

