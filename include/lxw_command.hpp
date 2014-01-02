/*
 * C++ wrapper for lxcommand.h
 *
 *	Copyright (c) 2008-2013 Luxology LLC
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
#ifndef LXW_COMMAND_HPP
#define LXW_COMMAND_HPP

#include <lxcommand.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx {
    static const LXtGUID guid_UIValueHints1 = {0x7BB10C3F,0x1FFB,0x4104,0x8F,0xBE,0xCB,0x1C,0x33,0x4E,0xE3,0xC1};
    static const LXtGUID guid_CommandBlock = {0x65AEBD9F,0xD518,0x47b2,0x8C,0xC6,0xE4,0x53,0xF8,0xC4,0x3C,0xB6};
    static const LXtGUID guid_CommandEvent = {0xF7CD29B5,0x6858,0x445b,0xBE,0x6D,0x83,0x47,0x60,0x3B,0x47,0xE9};
    static const LXtGUID guid_Command1 = {0x4F540BF1,0xF97E,0x4D46,0x8A,0x5F,0x6B,0x27,0x50,0xA6,0xCE,0xB9};
    static const LXtGUID guid_UIValueHints = {0xf37bb385,0x7214,0x42d5,0x9b,0xed,0x55,0x2f,0xf4,0x73,0x89,0x08};
    static const LXtGUID guid_CommandDBHelp = {0x7c8a58e0,0x0052,0x4d8e,0xad,0xdb,0x73,0x87,0xfb,0xa9,0xd5,0xbf};
    static const LXtGUID guid_CommandPostEnd = {0xAEB6B7BF,0x34B9,0x4991,0x90,0x4C,0x29,0x8B,0x8D,0xB1,0xAE,0x12};
    static const LXtGUID guid_UIHints = {0x944D9CFD,0xDB04,0x4bba,0xB8,0xB1,0xAD,0xE4,0x24,0x69,0x5E,0xDC};
    static const LXtGUID guid_Command = {0x5e981e16,0x94b7,0x4364,0x92,0xf0,0xd7,0x67,0x92,0x36,0xf3,0xd1};
    static const LXtGUID guid_AttributesUI = {0x44D9C65E,0xAE2E,0x4012,0xAB,0x57,0xE2,0x83,0x97,0x34,0xF7,0xFF};
    static const LXtGUID guid_CommandService = {0x9DB8BA65,0x8C36,0x45A7,0xB4,0x03,0xDF,0x7B,0xA5,0x9B,0xA6,0xC2};
};

class CLxImpl_UIValueHints1 {
  public:
    virtual ~CLxImpl_UIValueHints1() {}
    virtual unsigned
      uiv_Flags (void)
        = 0;
    virtual unsigned
      uiv_PopCount (void)
        = 0;
    virtual const char *
      uiv_PopUserName (unsigned index)
        = 0;
    virtual const char *
      uiv_PopInternalName (unsigned index)
        = 0;
    virtual LxResult
      uiv_PopFlags (unsigned index, int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_PopCategory (const char **category)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_ItemTest (ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_NotifierCount (int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_NotifierByIndex (const char **name, const char **args)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_FormCommandListCount (int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_FormCommandListByIndex (int index, const char **command)
        { return LXe_NOTIMPL; }
};
#define LXxD_UIValueHints1_Flags unsigned uiv_Flags (void)
#define LXxO_UIValueHints1_Flags LXxD_UIValueHints1_Flags LXx_OVERRIDE
#define LXxD_UIValueHints1_PopCount unsigned uiv_PopCount (void)
#define LXxO_UIValueHints1_PopCount LXxD_UIValueHints1_PopCount LXx_OVERRIDE
#define LXxD_UIValueHints1_PopUserName const char * uiv_PopUserName (unsigned index)
#define LXxO_UIValueHints1_PopUserName LXxD_UIValueHints1_PopUserName LXx_OVERRIDE
#define LXxD_UIValueHints1_PopInternalName const char * uiv_PopInternalName (unsigned index)
#define LXxO_UIValueHints1_PopInternalName LXxD_UIValueHints1_PopInternalName LXx_OVERRIDE
#define LXxD_UIValueHints1_PopFlags LxResult uiv_PopFlags (unsigned index, int *flags)
#define LXxO_UIValueHints1_PopFlags LXxD_UIValueHints1_PopFlags LXx_OVERRIDE
#define LXxD_UIValueHints1_PopCategory LxResult uiv_PopCategory (const char **category)
#define LXxO_UIValueHints1_PopCategory LXxD_UIValueHints1_PopCategory LXx_OVERRIDE
#define LXxD_UIValueHints1_ItemTest LxResult uiv_ItemTest (ILxUnknownID item)
#define LXxO_UIValueHints1_ItemTest LXxD_UIValueHints1_ItemTest LXx_OVERRIDE
#define LXxD_UIValueHints1_ColorPickerCommands LxResult uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
#define LXxO_UIValueHints1_ColorPickerCommands LXxD_UIValueHints1_ColorPickerCommands LXx_OVERRIDE
#define LXxD_UIValueHints1_NotifierCount LxResult uiv_NotifierCount (int *count)
#define LXxO_UIValueHints1_NotifierCount LXxD_UIValueHints1_NotifierCount LXx_OVERRIDE
#define LXxD_UIValueHints1_NotifierByIndex LxResult uiv_NotifierByIndex (const char **name, const char **args)
#define LXxO_UIValueHints1_NotifierByIndex LXxD_UIValueHints1_NotifierByIndex LXx_OVERRIDE
#define LXxD_UIValueHints1_FormCommandListCount LxResult uiv_FormCommandListCount (int *count)
#define LXxO_UIValueHints1_FormCommandListCount LXxD_UIValueHints1_FormCommandListCount LXx_OVERRIDE
#define LXxD_UIValueHints1_FormCommandListByIndex LxResult uiv_FormCommandListByIndex (int index, const char **command)
#define LXxO_UIValueHints1_FormCommandListByIndex LXxD_UIValueHints1_FormCommandListByIndex LXx_OVERRIDE
template <class T>
class CLxIfc_UIValueHints1 : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    return loc->uiv_Flags ();
  }
    static unsigned
  PopCount (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    return loc->uiv_PopCount ();
  }
    static const char *
  PopUserName (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    return loc->uiv_PopUserName (index);
  }
    static const char *
  PopInternalName (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    return loc->uiv_PopInternalName (index);
  }
    static LxResult
  PopFlags (LXtObjectID wcom, unsigned index, int *flags)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_PopFlags (index,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PopCategory (LXtObjectID wcom, const char **category)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_PopCategory (category);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ItemTest (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_ItemTest ((ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColorPickerCommands (LXtObjectID wcom, char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_ColorPickerCommands (rgb,alpha,rgbAlt,alphaAlt,useAlt,bufLens);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_NotifierCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierByIndex (LXtObjectID wcom, const char **name, const char **args)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_NotifierByIndex (name,args);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FormCommandListCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_FormCommandListCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FormCommandListByIndex (LXtObjectID wcom, int index, const char **command)
  {
    LXCWxINST (CLxImpl_UIValueHints1, loc);
    try {
      return loc->uiv_FormCommandListByIndex (index,command);
    } catch (LxResult rc) { return rc; }
  }
  ILxUIValueHints1 vt;
public:
  CLxIfc_UIValueHints1 ()
  {
    vt.Flags = Flags;
    vt.PopCount = PopCount;
    vt.PopUserName = PopUserName;
    vt.PopInternalName = PopInternalName;
    vt.PopFlags = PopFlags;
    vt.PopCategory = PopCategory;
    vt.ItemTest = ItemTest;
    vt.ColorPickerCommands = ColorPickerCommands;
    vt.NotifierCount = NotifierCount;
    vt.NotifierByIndex = NotifierByIndex;
    vt.FormCommandListCount = FormCommandListCount;
    vt.FormCommandListByIndex = FormCommandListByIndex;
    vTable = &vt.iunk;
    iid = &lx::guid_UIValueHints1;
  }
};
class CLxLoc_UIValueHints1 : public CLxLocalize<ILxUIValueHints1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_UIValueHints1() {_init();}
  CLxLoc_UIValueHints1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_UIValueHints1(const CLxLoc_UIValueHints1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_UIValueHints1;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    unsigned
  PopCount (void)
  {
    return m_loc[0]->PopCount (m_loc);
  }
    const char *
  PopUserName (unsigned index)
  {
    return m_loc[0]->PopUserName (m_loc,index);
  }
    const char *
  PopInternalName (unsigned index)
  {
    return m_loc[0]->PopInternalName (m_loc,index);
  }
    LxResult
  PopFlags (unsigned index, int *flags)
  {
    return m_loc[0]->PopFlags (m_loc,index,flags);
  }
    LxResult
  PopCategory (const char **category)
  {
    return m_loc[0]->PopCategory (m_loc,category);
  }
    LxResult
  ItemTest (ILxUnknownID item)
  {
    return m_loc[0]->ItemTest (m_loc,(ILxUnknownID)item);
  }
    LxResult
  ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
  {
    return m_loc[0]->ColorPickerCommands (m_loc,rgb,alpha,rgbAlt,alphaAlt,useAlt,bufLens);
  }
    LxResult
  NotifierCount (int *count)
  {
    return m_loc[0]->NotifierCount (m_loc,count);
  }
    LxResult
  NotifierByIndex (const char **name, const char **args)
  {
    return m_loc[0]->NotifierByIndex (m_loc,name,args);
  }
    LxResult
  FormCommandListCount (int *count)
  {
    return m_loc[0]->FormCommandListCount (m_loc,count);
  }
    LxResult
  FormCommandListByIndex (int index, const char **command)
  {
    return m_loc[0]->FormCommandListByIndex (m_loc,index,command);
  }
};


class CLxImpl_CommandEvent {
  public:
    virtual ~CLxImpl_CommandEvent() {}
    virtual LxResult
      cevt_Event (unsigned int flags)
        { return LXe_NOTIMPL; }
};
#define LXxD_CommandEvent_Event LxResult cevt_Event (unsigned int flags)
#define LXxO_CommandEvent_Event LXxD_CommandEvent_Event LXx_OVERRIDE
template <class T>
class CLxIfc_CommandEvent : public CLxInterface
{
    static LxResult
  Event (LXtObjectID wcom, unsigned int flags)
  {
    LXCWxINST (CLxImpl_CommandEvent, loc);
    try {
      return loc->cevt_Event (flags);
    } catch (LxResult rc) { return rc; }
  }
  ILxCommandEvent vt;
public:
  CLxIfc_CommandEvent ()
  {
    vt.Event = Event;
    vTable = &vt.iunk;
    iid = &lx::guid_CommandEvent;
  }
};
class CLxLoc_CommandEvent : public CLxLocalize<ILxCommandEventID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_CommandEvent() {_init();}
  CLxLoc_CommandEvent(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_CommandEvent(const CLxLoc_CommandEvent &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_CommandEvent;}
    LxResult
  Event (unsigned int flags)
  {
    return m_loc[0]->Event (m_loc,flags);
  }
};

class CLxImpl_Command1 {
  public:
    virtual ~CLxImpl_Command1() {}
    virtual LxResult
      cmd1_Tag (LXtCommandTag *tag)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Name (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_UserName (const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ButtonName (const char **buttonName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Desc (const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Tooltip (const char **tooltip)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Help (const char **help)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Example (const char **example)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Icon (const char **iconNames)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Flags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_PostExecFlags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_PostExecBehaviorFlags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_PostExecHints (unsigned int *hints)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_SandboxGUID (const LXtGUID **guid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Message (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Enable (ILxUnknownID msg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ContainedEnable (LXtID4 *types)
        { return LXe_NOTIMPL; }
    virtual void
      cmd1_Interact (void)
        { }
    virtual void
      cmd1_PreExecute (void)
        { }
    virtual void
      cmd1_Execute (unsigned int flags)
        { }
    virtual LxResult
      cmd1_ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgFlags (unsigned int index, unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgClear (unsigned int index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgResetAll (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgSetDatatypes (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgUserName (unsigned int index, const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgDesc (unsigned int index, const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgExample (unsigned int index, const char **example)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgType (unsigned int index, const char **type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgTypeUserName (unsigned int index, const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgTypeDesc (unsigned int index, const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_DialogInit (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_DialogArgChange (unsigned int arg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgEnable (unsigned int arg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_ArgParseString (unsigned int argIndex, const char *argString)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Copy (ILxUnknownID sourceCommand)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_Query (unsigned int index, ILxUnknownID vaQuery)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_NotifyAddClient (int argument, ILxUnknownID object)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd1_NotifyRemoveClient (ILxUnknownID object)
        { return LXe_NOTIMPL; }
};
#define LXxD_Command1_Tag LxResult cmd1_Tag (LXtCommandTag *tag)
#define LXxO_Command1_Tag LXxD_Command1_Tag LXx_OVERRIDE
#define LXxD_Command1_Name LxResult cmd1_Name (const char **name)
#define LXxO_Command1_Name LXxD_Command1_Name LXx_OVERRIDE
#define LXxD_Command1_UserName LxResult cmd1_UserName (const char **userName)
#define LXxO_Command1_UserName LXxD_Command1_UserName LXx_OVERRIDE
#define LXxD_Command1_ButtonName LxResult cmd1_ButtonName (const char **buttonName)
#define LXxO_Command1_ButtonName LXxD_Command1_ButtonName LXx_OVERRIDE
#define LXxD_Command1_Desc LxResult cmd1_Desc (const char **desc)
#define LXxO_Command1_Desc LXxD_Command1_Desc LXx_OVERRIDE
#define LXxD_Command1_Tooltip LxResult cmd1_Tooltip (const char **tooltip)
#define LXxO_Command1_Tooltip LXxD_Command1_Tooltip LXx_OVERRIDE
#define LXxD_Command1_Help LxResult cmd1_Help (const char **help)
#define LXxO_Command1_Help LXxD_Command1_Help LXx_OVERRIDE
#define LXxD_Command1_Example LxResult cmd1_Example (const char **example)
#define LXxO_Command1_Example LXxD_Command1_Example LXx_OVERRIDE
#define LXxD_Command1_Icon LxResult cmd1_Icon (const char **iconNames)
#define LXxO_Command1_Icon LXxD_Command1_Icon LXx_OVERRIDE
#define LXxD_Command1_Flags LxResult cmd1_Flags (unsigned int *flags)
#define LXxO_Command1_Flags LXxD_Command1_Flags LXx_OVERRIDE
#define LXxD_Command1_PostExecFlags LxResult cmd1_PostExecFlags (unsigned int *flags)
#define LXxO_Command1_PostExecFlags LXxD_Command1_PostExecFlags LXx_OVERRIDE
#define LXxD_Command1_PostExecBehaviorFlags LxResult cmd1_PostExecBehaviorFlags (unsigned int *flags)
#define LXxO_Command1_PostExecBehaviorFlags LXxD_Command1_PostExecBehaviorFlags LXx_OVERRIDE
#define LXxD_Command1_PostExecHints LxResult cmd1_PostExecHints (unsigned int *hints)
#define LXxO_Command1_PostExecHints LXxD_Command1_PostExecHints LXx_OVERRIDE
#define LXxD_Command1_SandboxGUID LxResult cmd1_SandboxGUID (const LXtGUID **guid)
#define LXxO_Command1_SandboxGUID LXxD_Command1_SandboxGUID LXx_OVERRIDE
#define LXxD_Command1_Message LxResult cmd1_Message (void **ppvObj)
#define LXxO_Command1_Message LXxD_Command1_Message LXx_OVERRIDE
#define LXxD_Command1_Enable LxResult cmd1_Enable (ILxUnknownID msg)
#define LXxO_Command1_Enable LXxD_Command1_Enable LXx_OVERRIDE
#define LXxD_Command1_ContainedEnable LxResult cmd1_ContainedEnable (LXtID4 *types)
#define LXxO_Command1_ContainedEnable LXxD_Command1_ContainedEnable LXx_OVERRIDE
#define LXxD_Command1_Interact void cmd1_Interact (void)
#define LXxO_Command1_Interact LXxD_Command1_Interact LXx_OVERRIDE
#define LXxD_Command1_PreExecute void cmd1_PreExecute (void)
#define LXxO_Command1_PreExecute LXxD_Command1_PreExecute LXx_OVERRIDE
#define LXxD_Command1_Execute void cmd1_Execute (unsigned int flags)
#define LXxO_Command1_Execute LXxD_Command1_Execute LXx_OVERRIDE
#define LXxD_Command1_ToggleArg LxResult cmd1_ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
#define LXxO_Command1_ToggleArg LXxD_Command1_ToggleArg LXx_OVERRIDE
#define LXxD_Command1_ArgFlags LxResult cmd1_ArgFlags (unsigned int index, unsigned int *flags)
#define LXxO_Command1_ArgFlags LXxD_Command1_ArgFlags LXx_OVERRIDE
#define LXxD_Command1_ArgClear LxResult cmd1_ArgClear (unsigned int index)
#define LXxO_Command1_ArgClear LXxD_Command1_ArgClear LXx_OVERRIDE
#define LXxD_Command1_ArgResetAll LxResult cmd1_ArgResetAll (void)
#define LXxO_Command1_ArgResetAll LXxD_Command1_ArgResetAll LXx_OVERRIDE
#define LXxD_Command1_ArgSetDatatypes LxResult cmd1_ArgSetDatatypes (void)
#define LXxO_Command1_ArgSetDatatypes LXxD_Command1_ArgSetDatatypes LXx_OVERRIDE
#define LXxD_Command1_ArgUserName LxResult cmd1_ArgUserName (unsigned int index, const char **userName)
#define LXxO_Command1_ArgUserName LXxD_Command1_ArgUserName LXx_OVERRIDE
#define LXxD_Command1_ArgDesc LxResult cmd1_ArgDesc (unsigned int index, const char **desc)
#define LXxO_Command1_ArgDesc LXxD_Command1_ArgDesc LXx_OVERRIDE
#define LXxD_Command1_ArgExample LxResult cmd1_ArgExample (unsigned int index, const char **example)
#define LXxO_Command1_ArgExample LXxD_Command1_ArgExample LXx_OVERRIDE
#define LXxD_Command1_ArgType LxResult cmd1_ArgType (unsigned int index, const char **type)
#define LXxO_Command1_ArgType LXxD_Command1_ArgType LXx_OVERRIDE
#define LXxD_Command1_ArgTypeUserName LxResult cmd1_ArgTypeUserName (unsigned int index, const char **userName)
#define LXxO_Command1_ArgTypeUserName LXxD_Command1_ArgTypeUserName LXx_OVERRIDE
#define LXxD_Command1_ArgTypeDesc LxResult cmd1_ArgTypeDesc (unsigned int index, const char **desc)
#define LXxO_Command1_ArgTypeDesc LXxD_Command1_ArgTypeDesc LXx_OVERRIDE
#define LXxD_Command1_ArgOptionUserName LxResult cmd1_ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
#define LXxO_Command1_ArgOptionUserName LXxD_Command1_ArgOptionUserName LXx_OVERRIDE
#define LXxD_Command1_ArgOptionDesc LxResult cmd1_ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
#define LXxO_Command1_ArgOptionDesc LXxD_Command1_ArgOptionDesc LXx_OVERRIDE
#define LXxD_Command1_DialogInit LxResult cmd1_DialogInit (void)
#define LXxO_Command1_DialogInit LXxD_Command1_DialogInit LXx_OVERRIDE
#define LXxD_Command1_DialogArgChange LxResult cmd1_DialogArgChange (unsigned int arg)
#define LXxO_Command1_DialogArgChange LXxD_Command1_DialogArgChange LXx_OVERRIDE
#define LXxD_Command1_ArgEnable LxResult cmd1_ArgEnable (unsigned int arg)
#define LXxO_Command1_ArgEnable LXxD_Command1_ArgEnable LXx_OVERRIDE
#define LXxD_Command1_ArgParseString LxResult cmd1_ArgParseString (unsigned int argIndex, const char *argString)
#define LXxO_Command1_ArgParseString LXxD_Command1_ArgParseString LXx_OVERRIDE
#define LXxD_Command1_Copy LxResult cmd1_Copy (ILxUnknownID sourceCommand)
#define LXxO_Command1_Copy LXxD_Command1_Copy LXx_OVERRIDE
#define LXxD_Command1_Query LxResult cmd1_Query (unsigned int index, ILxUnknownID vaQuery)
#define LXxO_Command1_Query LXxD_Command1_Query LXx_OVERRIDE
#define LXxD_Command1_NotifyAddClient LxResult cmd1_NotifyAddClient (int argument, ILxUnknownID object)
#define LXxO_Command1_NotifyAddClient LXxD_Command1_NotifyAddClient LXx_OVERRIDE
#define LXxD_Command1_NotifyRemoveClient LxResult cmd1_NotifyRemoveClient (ILxUnknownID object)
#define LXxO_Command1_NotifyRemoveClient LXxD_Command1_NotifyRemoveClient LXx_OVERRIDE
template <class T>
class CLxIfc_Command1 : public CLxInterface
{
    static LxResult
  Tag (LXtObjectID wcom, LXtCommandTag *tag)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Tag (tag);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Name (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Name (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UserName (LXtObjectID wcom, const char **userName)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_UserName (userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ButtonName (LXtObjectID wcom, const char **buttonName)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ButtonName (buttonName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Desc (LXtObjectID wcom, const char **desc)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Desc (desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Tooltip (LXtObjectID wcom, const char **tooltip)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Tooltip (tooltip);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Help (LXtObjectID wcom, const char **help)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Help (help);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Example (LXtObjectID wcom, const char **example)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Example (example);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Icon (LXtObjectID wcom, const char **iconNames)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Icon (iconNames);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Flags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Flags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostExecFlags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_PostExecFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostExecBehaviorFlags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_PostExecBehaviorFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostExecHints (LXtObjectID wcom, unsigned int *hints)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_PostExecHints (hints);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SandboxGUID (LXtObjectID wcom, const LXtGUID **guid)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_SandboxGUID (guid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Message (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Message (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Enable (LXtObjectID wcom, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Enable ((ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ContainedEnable (LXtObjectID wcom, LXtID4 *types)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ContainedEnable (types);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Interact (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    loc->cmd1_Interact ();
  }
    static void
  PreExecute (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    loc->cmd1_PreExecute ();
  }
    static void
  Execute (LXtObjectID wcom, unsigned int flags)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    loc->cmd1_Execute (flags);
  }
    static LxResult
  ToggleArg (LXtObjectID wcom, unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ToggleArg (index,ppvObj,typeID,typeName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgFlags (LXtObjectID wcom, unsigned int index, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgFlags (index,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgClear (LXtObjectID wcom, unsigned int index)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgClear (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgResetAll (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgResetAll ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgSetDatatypes (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgSetDatatypes ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgUserName (LXtObjectID wcom, unsigned int index, const char **userName)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgUserName (index,userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgDesc (LXtObjectID wcom, unsigned int index, const char **desc)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgDesc (index,desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgExample (LXtObjectID wcom, unsigned int index, const char **example)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgExample (index,example);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgType (LXtObjectID wcom, unsigned int index, const char **type)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgType (index,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgTypeUserName (LXtObjectID wcom, unsigned int index, const char **userName)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgTypeUserName (index,userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgTypeDesc (LXtObjectID wcom, unsigned int index, const char **desc)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgTypeDesc (index,desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgOptionUserName (LXtObjectID wcom, unsigned int index, unsigned int optIndex, const char **userName)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgOptionUserName (index,optIndex,userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgOptionDesc (LXtObjectID wcom, unsigned int index, unsigned int optIndex, const char **desc)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgOptionDesc (index,optIndex,desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DialogInit (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_DialogInit ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DialogArgChange (LXtObjectID wcom, unsigned int arg)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_DialogArgChange (arg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgEnable (LXtObjectID wcom, unsigned int arg)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgEnable (arg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgParseString (LXtObjectID wcom, unsigned int argIndex, const char *argString)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_ArgParseString (argIndex,argString);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Copy (LXtObjectID wcom, LXtObjectID sourceCommand)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Copy ((ILxUnknownID)sourceCommand);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Query (LXtObjectID wcom, unsigned int index, LXtObjectID vaQuery)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_Query (index,(ILxUnknownID)vaQuery);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifyAddClient (LXtObjectID wcom, int argument, LXtObjectID object)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_NotifyAddClient (argument,(ILxUnknownID)object);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifyRemoveClient (LXtObjectID wcom, LXtObjectID object)
  {
    LXCWxINST (CLxImpl_Command1, loc);
    try {
      return loc->cmd1_NotifyRemoveClient ((ILxUnknownID)object);
    } catch (LxResult rc) { return rc; }
  }
  ILxCommand1 vt;
public:
  CLxIfc_Command1 ()
  {
    vt.Tag = Tag;
    vt.Name = Name;
    vt.UserName = UserName;
    vt.ButtonName = ButtonName;
    vt.Desc = Desc;
    vt.Tooltip = Tooltip;
    vt.Help = Help;
    vt.Example = Example;
    vt.Icon = Icon;
    vt.Flags = Flags;
    vt.PostExecFlags = PostExecFlags;
    vt.PostExecBehaviorFlags = PostExecBehaviorFlags;
    vt.PostExecHints = PostExecHints;
    vt.SandboxGUID = SandboxGUID;
    vt.Message = Message;
    vt.Enable = Enable;
    vt.ContainedEnable = ContainedEnable;
    vt.Interact = Interact;
    vt.PreExecute = PreExecute;
    vt.Execute = Execute;
    vt.ToggleArg = ToggleArg;
    vt.ArgFlags = ArgFlags;
    vt.ArgClear = ArgClear;
    vt.ArgResetAll = ArgResetAll;
    vt.ArgSetDatatypes = ArgSetDatatypes;
    vt.ArgUserName = ArgUserName;
    vt.ArgDesc = ArgDesc;
    vt.ArgExample = ArgExample;
    vt.ArgType = ArgType;
    vt.ArgTypeUserName = ArgTypeUserName;
    vt.ArgTypeDesc = ArgTypeDesc;
    vt.ArgOptionUserName = ArgOptionUserName;
    vt.ArgOptionDesc = ArgOptionDesc;
    vt.DialogInit = DialogInit;
    vt.DialogArgChange = DialogArgChange;
    vt.ArgEnable = ArgEnable;
    vt.ArgParseString = ArgParseString;
    vt.Copy = Copy;
    vt.Query = Query;
    vt.NotifyAddClient = NotifyAddClient;
    vt.NotifyRemoveClient = NotifyRemoveClient;
    vTable = &vt.iunk;
    iid = &lx::guid_Command1;
  }
};
class CLxLoc_Command1 : public CLxLocalize<ILxCommand1ID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Command1() {_init();}
  CLxLoc_Command1(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Command1(const CLxLoc_Command1 &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Command1;}
    LxResult
  Tag (LXtCommandTag *tag)
  {
    return m_loc[0]->Tag (m_loc,tag);
  }
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  UserName (const char **userName)
  {
    return m_loc[0]->UserName (m_loc,userName);
  }
    LxResult
  ButtonName (const char **buttonName)
  {
    return m_loc[0]->ButtonName (m_loc,buttonName);
  }
    LxResult
  Desc (const char **desc)
  {
    return m_loc[0]->Desc (m_loc,desc);
  }
    LxResult
  Tooltip (const char **tooltip)
  {
    return m_loc[0]->Tooltip (m_loc,tooltip);
  }
    LxResult
  Help (const char **help)
  {
    return m_loc[0]->Help (m_loc,help);
  }
    LxResult
  Example (const char **example)
  {
    return m_loc[0]->Example (m_loc,example);
  }
    LxResult
  Icon (const char **iconNames)
  {
    return m_loc[0]->Icon (m_loc,iconNames);
  }
    LxResult
  Flags (unsigned int *flags)
  {
    return m_loc[0]->Flags (m_loc,flags);
  }
    LxResult
  PostExecFlags (unsigned int *flags)
  {
    return m_loc[0]->PostExecFlags (m_loc,flags);
  }
    LxResult
  PostExecBehaviorFlags (unsigned int *flags)
  {
    return m_loc[0]->PostExecBehaviorFlags (m_loc,flags);
  }
    LxResult
  PostExecHints (unsigned int *hints)
  {
    return m_loc[0]->PostExecHints (m_loc,hints);
  }
    LxResult
  SandboxGUID (const LXtGUID **guid)
  {
    return m_loc[0]->SandboxGUID (m_loc,guid);
  }
    LxResult
  Message (void **ppvObj)
  {
    return m_loc[0]->Message (m_loc,ppvObj);
  }
    LxResult
  Enable (ILxUnknownID msg)
  {
    return m_loc[0]->Enable (m_loc,(ILxUnknownID)msg);
  }
    LxResult
  ContainedEnable (LXtID4 *types)
  {
    return m_loc[0]->ContainedEnable (m_loc,types);
  }
    void
  Interact (void)
  {
    m_loc[0]->Interact (m_loc);
  }
    void
  PreExecute (void)
  {
    m_loc[0]->PreExecute (m_loc);
  }
    void
  Execute (unsigned int flags)
  {
    m_loc[0]->Execute (m_loc,flags);
  }
    LxResult
  ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
  {
    return m_loc[0]->ToggleArg (m_loc,index,ppvObj,typeID,typeName);
  }
    LxResult
  ArgFlags (unsigned int index, unsigned int *flags)
  {
    return m_loc[0]->ArgFlags (m_loc,index,flags);
  }
    LxResult
  ArgClear (unsigned int index)
  {
    return m_loc[0]->ArgClear (m_loc,index);
  }
    LxResult
  ArgResetAll (void)
  {
    return m_loc[0]->ArgResetAll (m_loc);
  }
    LxResult
  ArgSetDatatypes (void)
  {
    return m_loc[0]->ArgSetDatatypes (m_loc);
  }
    LxResult
  ArgUserName (unsigned int index, const char **userName)
  {
    return m_loc[0]->ArgUserName (m_loc,index,userName);
  }
    LxResult
  ArgDesc (unsigned int index, const char **desc)
  {
    return m_loc[0]->ArgDesc (m_loc,index,desc);
  }
    LxResult
  ArgExample (unsigned int index, const char **example)
  {
    return m_loc[0]->ArgExample (m_loc,index,example);
  }
    LxResult
  ArgType (unsigned int index, const char **type)
  {
    return m_loc[0]->ArgType (m_loc,index,type);
  }
    LxResult
  ArgTypeUserName (unsigned int index, const char **userName)
  {
    return m_loc[0]->ArgTypeUserName (m_loc,index,userName);
  }
    LxResult
  ArgTypeDesc (unsigned int index, const char **desc)
  {
    return m_loc[0]->ArgTypeDesc (m_loc,index,desc);
  }
    LxResult
  ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
  {
    return m_loc[0]->ArgOptionUserName (m_loc,index,optIndex,userName);
  }
    LxResult
  ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
  {
    return m_loc[0]->ArgOptionDesc (m_loc,index,optIndex,desc);
  }
    LxResult
  DialogInit (void)
  {
    return m_loc[0]->DialogInit (m_loc);
  }
    LxResult
  DialogArgChange (unsigned int arg)
  {
    return m_loc[0]->DialogArgChange (m_loc,arg);
  }
    LxResult
  ArgEnable (unsigned int arg)
  {
    return m_loc[0]->ArgEnable (m_loc,arg);
  }
    LxResult
  ArgParseString (unsigned int argIndex, const char *argString)
  {
    return m_loc[0]->ArgParseString (m_loc,argIndex,argString);
  }
    LxResult
  Copy (ILxUnknownID sourceCommand)
  {
    return m_loc[0]->Copy (m_loc,(ILxUnknownID)sourceCommand);
  }
    LxResult
  Query (unsigned int index, ILxUnknownID vaQuery)
  {
    return m_loc[0]->Query (m_loc,index,(ILxUnknownID)vaQuery);
  }
    LxResult
  NotifyAddClient (int argument, ILxUnknownID object)
  {
    return m_loc[0]->NotifyAddClient (m_loc,argument,(ILxUnknownID)object);
  }
    LxResult
  NotifyRemoveClient (ILxUnknownID object)
  {
    return m_loc[0]->NotifyRemoveClient (m_loc,(ILxUnknownID)object);
  }
};

class CLxImpl_UIValueHints {
  public:
    virtual ~CLxImpl_UIValueHints() {}
    virtual unsigned
      uiv_Flags (void)
        = 0;
    virtual unsigned
      uiv_PopCount (void)
        = 0;
    virtual const char *
      uiv_PopUserName (unsigned index)
        = 0;
    virtual const char *
      uiv_PopInternalName (unsigned index)
        = 0;
    virtual unsigned
      uiv_PopIconSize (int *w, int *h)
        = 0;
    virtual LxResult
      uiv_PopIconImage (int index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_PopIconResource (int index, const char **iconResource)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_PopFlags (unsigned index, int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_PopCategory (const char **category)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_ItemTest (ILxUnknownID item)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_NotifierCount (int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_NotifierByIndex (int index, const char **name, const char **args)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_FormCommandListCount (int *count)
        { return LXe_NOTIMPL; }
    virtual LxResult
      uiv_FormCommandListByIndex (int index, const char **command)
        { return LXe_NOTIMPL; }
};
#define LXxD_UIValueHints_Flags unsigned uiv_Flags (void)
#define LXxO_UIValueHints_Flags LXxD_UIValueHints_Flags LXx_OVERRIDE
#define LXxD_UIValueHints_PopCount unsigned uiv_PopCount (void)
#define LXxO_UIValueHints_PopCount LXxD_UIValueHints_PopCount LXx_OVERRIDE
#define LXxD_UIValueHints_PopUserName const char * uiv_PopUserName (unsigned index)
#define LXxO_UIValueHints_PopUserName LXxD_UIValueHints_PopUserName LXx_OVERRIDE
#define LXxD_UIValueHints_PopInternalName const char * uiv_PopInternalName (unsigned index)
#define LXxO_UIValueHints_PopInternalName LXxD_UIValueHints_PopInternalName LXx_OVERRIDE
#define LXxD_UIValueHints_PopIconSize unsigned uiv_PopIconSize (int *w, int *h)
#define LXxO_UIValueHints_PopIconSize LXxD_UIValueHints_PopIconSize LXx_OVERRIDE
#define LXxD_UIValueHints_PopIconImage LxResult uiv_PopIconImage (int index, void **ppvObj)
#define LXxO_UIValueHints_PopIconImage LXxD_UIValueHints_PopIconImage LXx_OVERRIDE
#define LXxD_UIValueHints_PopIconResource LxResult uiv_PopIconResource (int index, const char **iconResource)
#define LXxO_UIValueHints_PopIconResource LXxD_UIValueHints_PopIconResource LXx_OVERRIDE
#define LXxD_UIValueHints_PopFlags LxResult uiv_PopFlags (unsigned index, int *flags)
#define LXxO_UIValueHints_PopFlags LXxD_UIValueHints_PopFlags LXx_OVERRIDE
#define LXxD_UIValueHints_PopCategory LxResult uiv_PopCategory (const char **category)
#define LXxO_UIValueHints_PopCategory LXxD_UIValueHints_PopCategory LXx_OVERRIDE
#define LXxD_UIValueHints_ItemTest LxResult uiv_ItemTest (ILxUnknownID item)
#define LXxO_UIValueHints_ItemTest LXxD_UIValueHints_ItemTest LXx_OVERRIDE
#define LXxD_UIValueHints_ColorPickerCommands LxResult uiv_ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
#define LXxO_UIValueHints_ColorPickerCommands LXxD_UIValueHints_ColorPickerCommands LXx_OVERRIDE
#define LXxD_UIValueHints_NotifierCount LxResult uiv_NotifierCount (int *count)
#define LXxO_UIValueHints_NotifierCount LXxD_UIValueHints_NotifierCount LXx_OVERRIDE
#define LXxD_UIValueHints_NotifierByIndex LxResult uiv_NotifierByIndex (int index, const char **name, const char **args)
#define LXxO_UIValueHints_NotifierByIndex LXxD_UIValueHints_NotifierByIndex LXx_OVERRIDE
#define LXxD_UIValueHints_FormCommandListCount LxResult uiv_FormCommandListCount (int *count)
#define LXxO_UIValueHints_FormCommandListCount LXxD_UIValueHints_FormCommandListCount LXx_OVERRIDE
#define LXxD_UIValueHints_FormCommandListByIndex LxResult uiv_FormCommandListByIndex (int index, const char **command)
#define LXxO_UIValueHints_FormCommandListByIndex LXxD_UIValueHints_FormCommandListByIndex LXx_OVERRIDE
template <class T>
class CLxIfc_UIValueHints : public CLxInterface
{
    static unsigned
  Flags (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    return loc->uiv_Flags ();
  }
    static unsigned
  PopCount (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    return loc->uiv_PopCount ();
  }
    static const char *
  PopUserName (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    return loc->uiv_PopUserName (index);
  }
    static const char *
  PopInternalName (LXtObjectID wcom, unsigned index)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    return loc->uiv_PopInternalName (index);
  }
    static unsigned
  PopIconSize (LXtObjectID wcom, int *w, int *h)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    return loc->uiv_PopIconSize (w,h);
  }
    static LxResult
  PopIconImage (LXtObjectID wcom, int index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_PopIconImage (index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PopIconResource (LXtObjectID wcom, int index, const char **iconResource)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_PopIconResource (index,iconResource);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PopFlags (LXtObjectID wcom, unsigned index, int *flags)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_PopFlags (index,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PopCategory (LXtObjectID wcom, const char **category)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_PopCategory (category);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ItemTest (LXtObjectID wcom, LXtObjectID item)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_ItemTest ((ILxUnknownID)item);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ColorPickerCommands (LXtObjectID wcom, char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_ColorPickerCommands (rgb,alpha,rgbAlt,alphaAlt,useAlt,bufLens);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_NotifierCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifierByIndex (LXtObjectID wcom, int index, const char **name, const char **args)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_NotifierByIndex (index,name,args);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FormCommandListCount (LXtObjectID wcom, int *count)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_FormCommandListCount (count);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  FormCommandListByIndex (LXtObjectID wcom, int index, const char **command)
  {
    LXCWxINST (CLxImpl_UIValueHints, loc);
    try {
      return loc->uiv_FormCommandListByIndex (index,command);
    } catch (LxResult rc) { return rc; }
  }
  ILxUIValueHints vt;
public:
  CLxIfc_UIValueHints ()
  {
    vt.Flags = Flags;
    vt.PopCount = PopCount;
    vt.PopUserName = PopUserName;
    vt.PopInternalName = PopInternalName;
    vt.PopIconSize = PopIconSize;
    vt.PopIconImage = PopIconImage;
    vt.PopIconResource = PopIconResource;
    vt.PopFlags = PopFlags;
    vt.PopCategory = PopCategory;
    vt.ItemTest = ItemTest;
    vt.ColorPickerCommands = ColorPickerCommands;
    vt.NotifierCount = NotifierCount;
    vt.NotifierByIndex = NotifierByIndex;
    vt.FormCommandListCount = FormCommandListCount;
    vt.FormCommandListByIndex = FormCommandListByIndex;
    vTable = &vt.iunk;
    iid = &lx::guid_UIValueHints;
  }
};
class CLxLoc_UIValueHints : public CLxLocalize<ILxUIValueHintsID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_UIValueHints() {_init();}
  CLxLoc_UIValueHints(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_UIValueHints(const CLxLoc_UIValueHints &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_UIValueHints;}
    unsigned
  Flags (void)
  {
    return m_loc[0]->Flags (m_loc);
  }
    unsigned
  PopCount (void)
  {
    return m_loc[0]->PopCount (m_loc);
  }
    const char *
  PopUserName (unsigned index)
  {
    return m_loc[0]->PopUserName (m_loc,index);
  }
    const char *
  PopInternalName (unsigned index)
  {
    return m_loc[0]->PopInternalName (m_loc,index);
  }
    unsigned
  PopIconSize (int *w, int *h)
  {
    return m_loc[0]->PopIconSize (m_loc,w,h);
  }
    LxResult
  PopIconImage (int index, void **ppvObj)
  {
    return m_loc[0]->PopIconImage (m_loc,index,ppvObj);
  }
    bool
  PopIconImage (int index, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->PopIconImage (m_loc,index,&obj)) && dest.take(obj);
  }
    LxResult
  PopIconResource (int index, const char **iconResource)
  {
    return m_loc[0]->PopIconResource (m_loc,index,iconResource);
  }
    LxResult
  PopFlags (unsigned index, int *flags)
  {
    return m_loc[0]->PopFlags (m_loc,index,flags);
  }
    LxResult
  PopCategory (const char **category)
  {
    return m_loc[0]->PopCategory (m_loc,category);
  }
    LxResult
  ItemTest (ILxUnknownID item)
  {
    return m_loc[0]->ItemTest (m_loc,(ILxUnknownID)item);
  }
    LxResult
  ColorPickerCommands (char *rgb, char *alpha, char *rgbAlt, char *alphaAlt, char *useAlt, unsigned bufLens)
  {
    return m_loc[0]->ColorPickerCommands (m_loc,rgb,alpha,rgbAlt,alphaAlt,useAlt,bufLens);
  }
    LxResult
  NotifierCount (int *count)
  {
    return m_loc[0]->NotifierCount (m_loc,count);
  }
    LxResult
  NotifierByIndex (int index, const char **name, const char **args)
  {
    return m_loc[0]->NotifierByIndex (m_loc,index,name,args);
  }
    LxResult
  FormCommandListCount (int *count)
  {
    return m_loc[0]->FormCommandListCount (m_loc,count);
  }
    LxResult
  FormCommandListByIndex (int index, const char **command)
  {
    return m_loc[0]->FormCommandListByIndex (m_loc,index,command);
  }
};

class CLxLoc_CommandDBHelp : public CLxLocalize<ILxCommandDBHelpID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_CommandDBHelp() {_init();}
  CLxLoc_CommandDBHelp(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_CommandDBHelp(const CLxLoc_CommandDBHelp &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_CommandDBHelp;}
    LxResult
  DBHelp (const char **dbhelp)
  {
    return m_loc[0]->DBHelp (m_loc,dbhelp);
  }
};


class CLxLoc_UIHints : public CLxLocalize<ILxUIHintsID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_UIHints() {_init();}
  CLxLoc_UIHints(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_UIHints(const CLxLoc_UIHints &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_UIHints;}
    LxResult
  Class (const char *c)
  {
    return m_loc[0]->Class (m_loc,c);
  }
    LxResult
  Label (const char *label)
  {
    return m_loc[0]->Label (m_loc,label);
  }
    LxResult
  MinInt (int min)
  {
    return m_loc[0]->MinInt (m_loc,min);
  }
    LxResult
  MaxInt (int max)
  {
    return m_loc[0]->MaxInt (m_loc,max);
  }
    LxResult
  MinFloat (double min)
  {
    return m_loc[0]->MinFloat (m_loc,min);
  }
    LxResult
  MaxFloat (double max)
  {
    return m_loc[0]->MaxFloat (m_loc,max);
  }
    LxResult
  StepInt (int step)
  {
    return m_loc[0]->StepInt (m_loc,step);
  }
    LxResult
  StepFloat (double step)
  {
    return m_loc[0]->StepFloat (m_loc,step);
  }
    LxResult
  Track (unsigned int state)
  {
    return m_loc[0]->Track (m_loc,state);
  }
    LxResult
  StringList (const char **strings)
  {
    return m_loc[0]->StringList (m_loc,strings);
  }
    LxResult
  TextLines (unsigned int lines)
  {
    return m_loc[0]->TextLines (m_loc,lines);
  }
    LxResult
  TextFixedWidthFont (unsigned int state)
  {
    return m_loc[0]->TextFixedWidthFont (m_loc,state);
  }
    LxResult
  TextPasswordMode (unsigned int state)
  {
    return m_loc[0]->TextPasswordMode (m_loc,state);
  }
    LxResult
  ValuePresetCookie (const char *cookie)
  {
    return m_loc[0]->ValuePresetCookie (m_loc,cookie);
  }
    LxResult
  ForceUpdate (void)
  {
    return m_loc[0]->ForceUpdate (m_loc);
  }
    LxResult
  BooleanStyle (unsigned int style)
  {
    return m_loc[0]->BooleanStyle (m_loc,style);
  }
    LxResult
  ChannelFlags (unsigned int flags)
  {
    return m_loc[0]->ChannelFlags (m_loc,flags);
  }
};

class CLxImpl_Command {
  public:
    virtual ~CLxImpl_Command() {}
    virtual LxResult
      cmd_Tag (LXtCommandTag *tag)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Name (const char **name)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_UserName (const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ButtonName (const char **buttonName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Desc (const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Tooltip (const char **tooltip)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Help (const char **help)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Example (const char **example)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Icon (const char **iconNames)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Flags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_PostExecFlags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_PostExecBehaviorFlags (unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_PostExecHints (unsigned int *hints)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_SandboxGUID (const LXtGUID **guid)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Message (void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Enable (ILxUnknownID msg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ContainedEnable (LXtID4 *types)
        { return LXe_NOTIMPL; }
    virtual void
      cmd_Interact (void)
        { }
    virtual void
      cmd_PreExecute (void)
        { }
    virtual void
      cmd_Execute (unsigned int flags)
        { }
    virtual LxResult
      cmd_ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgFlags (unsigned int index, unsigned int *flags)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgClear (unsigned int index)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgResetAll (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgSetDatatypes (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgUserName (unsigned int index, const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgDesc (unsigned int index, const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgExample (unsigned int index, const char **example)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgType (unsigned int index, const char **type)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgTypeUserName (unsigned int index, const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgTypeDesc (unsigned int index, const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_DialogInit (void)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_DialogArgChange (unsigned int arg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgEnable (unsigned int arg)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_ArgParseString (unsigned int argIndex, const char *argString)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Copy (ILxUnknownID sourceCommand)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_Query (unsigned int index, ILxUnknownID vaQuery)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_NotifyAddClient (int argument, ILxUnknownID object)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_NotifyRemoveClient (ILxUnknownID object)
        { return LXe_NOTIMPL; }
    virtual LxResult
      cmd_DialogFormatting (const char **formatting)
        { return LXe_NOTIMPL; }
};
#define LXxD_Command_Tag LxResult cmd_Tag (LXtCommandTag *tag)
#define LXxO_Command_Tag LXxD_Command_Tag LXx_OVERRIDE
#define LXxD_Command_Name LxResult cmd_Name (const char **name)
#define LXxO_Command_Name LXxD_Command_Name LXx_OVERRIDE
#define LXxD_Command_UserName LxResult cmd_UserName (const char **userName)
#define LXxO_Command_UserName LXxD_Command_UserName LXx_OVERRIDE
#define LXxD_Command_ButtonName LxResult cmd_ButtonName (const char **buttonName)
#define LXxO_Command_ButtonName LXxD_Command_ButtonName LXx_OVERRIDE
#define LXxD_Command_Desc LxResult cmd_Desc (const char **desc)
#define LXxO_Command_Desc LXxD_Command_Desc LXx_OVERRIDE
#define LXxD_Command_Tooltip LxResult cmd_Tooltip (const char **tooltip)
#define LXxO_Command_Tooltip LXxD_Command_Tooltip LXx_OVERRIDE
#define LXxD_Command_Help LxResult cmd_Help (const char **help)
#define LXxO_Command_Help LXxD_Command_Help LXx_OVERRIDE
#define LXxD_Command_Example LxResult cmd_Example (const char **example)
#define LXxO_Command_Example LXxD_Command_Example LXx_OVERRIDE
#define LXxD_Command_Icon LxResult cmd_Icon (const char **iconNames)
#define LXxO_Command_Icon LXxD_Command_Icon LXx_OVERRIDE
#define LXxD_Command_Flags LxResult cmd_Flags (unsigned int *flags)
#define LXxO_Command_Flags LXxD_Command_Flags LXx_OVERRIDE
#define LXxD_Command_PostExecFlags LxResult cmd_PostExecFlags (unsigned int *flags)
#define LXxO_Command_PostExecFlags LXxD_Command_PostExecFlags LXx_OVERRIDE
#define LXxD_Command_PostExecBehaviorFlags LxResult cmd_PostExecBehaviorFlags (unsigned int *flags)
#define LXxO_Command_PostExecBehaviorFlags LXxD_Command_PostExecBehaviorFlags LXx_OVERRIDE
#define LXxD_Command_PostExecHints LxResult cmd_PostExecHints (unsigned int *hints)
#define LXxO_Command_PostExecHints LXxD_Command_PostExecHints LXx_OVERRIDE
#define LXxD_Command_SandboxGUID LxResult cmd_SandboxGUID (const LXtGUID **guid)
#define LXxO_Command_SandboxGUID LXxD_Command_SandboxGUID LXx_OVERRIDE
#define LXxD_Command_Message LxResult cmd_Message (void **ppvObj)
#define LXxO_Command_Message LXxD_Command_Message LXx_OVERRIDE
#define LXxD_Command_Enable LxResult cmd_Enable (ILxUnknownID msg)
#define LXxO_Command_Enable LXxD_Command_Enable LXx_OVERRIDE
#define LXxD_Command_ContainedEnable LxResult cmd_ContainedEnable (LXtID4 *types)
#define LXxO_Command_ContainedEnable LXxD_Command_ContainedEnable LXx_OVERRIDE
#define LXxD_Command_Interact void cmd_Interact (void)
#define LXxO_Command_Interact LXxD_Command_Interact LXx_OVERRIDE
#define LXxD_Command_PreExecute void cmd_PreExecute (void)
#define LXxO_Command_PreExecute LXxD_Command_PreExecute LXx_OVERRIDE
#define LXxD_Command_Execute void cmd_Execute (unsigned int flags)
#define LXxO_Command_Execute LXxD_Command_Execute LXx_OVERRIDE
#define LXxD_Command_ToggleArg LxResult cmd_ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
#define LXxO_Command_ToggleArg LXxD_Command_ToggleArg LXx_OVERRIDE
#define LXxD_Command_ArgFlags LxResult cmd_ArgFlags (unsigned int index, unsigned int *flags)
#define LXxO_Command_ArgFlags LXxD_Command_ArgFlags LXx_OVERRIDE
#define LXxD_Command_ArgClear LxResult cmd_ArgClear (unsigned int index)
#define LXxO_Command_ArgClear LXxD_Command_ArgClear LXx_OVERRIDE
#define LXxD_Command_ArgResetAll LxResult cmd_ArgResetAll (void)
#define LXxO_Command_ArgResetAll LXxD_Command_ArgResetAll LXx_OVERRIDE
#define LXxD_Command_ArgSetDatatypes LxResult cmd_ArgSetDatatypes (void)
#define LXxO_Command_ArgSetDatatypes LXxD_Command_ArgSetDatatypes LXx_OVERRIDE
#define LXxD_Command_ArgUserName LxResult cmd_ArgUserName (unsigned int index, const char **userName)
#define LXxO_Command_ArgUserName LXxD_Command_ArgUserName LXx_OVERRIDE
#define LXxD_Command_ArgDesc LxResult cmd_ArgDesc (unsigned int index, const char **desc)
#define LXxO_Command_ArgDesc LXxD_Command_ArgDesc LXx_OVERRIDE
#define LXxD_Command_ArgExample LxResult cmd_ArgExample (unsigned int index, const char **example)
#define LXxO_Command_ArgExample LXxD_Command_ArgExample LXx_OVERRIDE
#define LXxD_Command_ArgType LxResult cmd_ArgType (unsigned int index, const char **type)
#define LXxO_Command_ArgType LXxD_Command_ArgType LXx_OVERRIDE
#define LXxD_Command_ArgTypeUserName LxResult cmd_ArgTypeUserName (unsigned int index, const char **userName)
#define LXxO_Command_ArgTypeUserName LXxD_Command_ArgTypeUserName LXx_OVERRIDE
#define LXxD_Command_ArgTypeDesc LxResult cmd_ArgTypeDesc (unsigned int index, const char **desc)
#define LXxO_Command_ArgTypeDesc LXxD_Command_ArgTypeDesc LXx_OVERRIDE
#define LXxD_Command_ArgOptionUserName LxResult cmd_ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
#define LXxO_Command_ArgOptionUserName LXxD_Command_ArgOptionUserName LXx_OVERRIDE
#define LXxD_Command_ArgOptionDesc LxResult cmd_ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
#define LXxO_Command_ArgOptionDesc LXxD_Command_ArgOptionDesc LXx_OVERRIDE
#define LXxD_Command_DialogInit LxResult cmd_DialogInit (void)
#define LXxO_Command_DialogInit LXxD_Command_DialogInit LXx_OVERRIDE
#define LXxD_Command_DialogArgChange LxResult cmd_DialogArgChange (unsigned int arg)
#define LXxO_Command_DialogArgChange LXxD_Command_DialogArgChange LXx_OVERRIDE
#define LXxD_Command_ArgEnable LxResult cmd_ArgEnable (unsigned int arg)
#define LXxO_Command_ArgEnable LXxD_Command_ArgEnable LXx_OVERRIDE
#define LXxD_Command_ArgParseString LxResult cmd_ArgParseString (unsigned int argIndex, const char *argString)
#define LXxO_Command_ArgParseString LXxD_Command_ArgParseString LXx_OVERRIDE
#define LXxD_Command_Copy LxResult cmd_Copy (ILxUnknownID sourceCommand)
#define LXxO_Command_Copy LXxD_Command_Copy LXx_OVERRIDE
#define LXxD_Command_Query LxResult cmd_Query (unsigned int index, ILxUnknownID vaQuery)
#define LXxO_Command_Query LXxD_Command_Query LXx_OVERRIDE
#define LXxD_Command_NotifyAddClient LxResult cmd_NotifyAddClient (int argument, ILxUnknownID object)
#define LXxO_Command_NotifyAddClient LXxD_Command_NotifyAddClient LXx_OVERRIDE
#define LXxD_Command_NotifyRemoveClient LxResult cmd_NotifyRemoveClient (ILxUnknownID object)
#define LXxO_Command_NotifyRemoveClient LXxD_Command_NotifyRemoveClient LXx_OVERRIDE
#define LXxD_Command_DialogFormatting LxResult cmd_DialogFormatting (const char **formatting)
#define LXxO_Command_DialogFormatting LXxD_Command_DialogFormatting LXx_OVERRIDE
template <class T>
class CLxIfc_Command : public CLxInterface
{
    static LxResult
  Tag (LXtObjectID wcom, LXtCommandTag *tag)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Tag (tag);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Name (LXtObjectID wcom, const char **name)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Name (name);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UserName (LXtObjectID wcom, const char **userName)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_UserName (userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ButtonName (LXtObjectID wcom, const char **buttonName)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ButtonName (buttonName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Desc (LXtObjectID wcom, const char **desc)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Desc (desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Tooltip (LXtObjectID wcom, const char **tooltip)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Tooltip (tooltip);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Help (LXtObjectID wcom, const char **help)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Help (help);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Example (LXtObjectID wcom, const char **example)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Example (example);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Icon (LXtObjectID wcom, const char **iconNames)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Icon (iconNames);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Flags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Flags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostExecFlags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_PostExecFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostExecBehaviorFlags (LXtObjectID wcom, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_PostExecBehaviorFlags (flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  PostExecHints (LXtObjectID wcom, unsigned int *hints)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_PostExecHints (hints);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  SandboxGUID (LXtObjectID wcom, const LXtGUID **guid)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_SandboxGUID (guid);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Message (LXtObjectID wcom, void **ppvObj)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Message (ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Enable (LXtObjectID wcom, LXtObjectID msg)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Enable ((ILxUnknownID)msg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ContainedEnable (LXtObjectID wcom, LXtID4 *types)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ContainedEnable (types);
    } catch (LxResult rc) { return rc; }
  }
    static void
  Interact (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command, loc);
    loc->cmd_Interact ();
  }
    static void
  PreExecute (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command, loc);
    loc->cmd_PreExecute ();
  }
    static void
  Execute (LXtObjectID wcom, unsigned int flags)
  {
    LXCWxINST (CLxImpl_Command, loc);
    loc->cmd_Execute (flags);
  }
    static LxResult
  ToggleArg (LXtObjectID wcom, unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ToggleArg (index,ppvObj,typeID,typeName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgFlags (LXtObjectID wcom, unsigned int index, unsigned int *flags)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgFlags (index,flags);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgClear (LXtObjectID wcom, unsigned int index)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgClear (index);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgResetAll (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgResetAll ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgSetDatatypes (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgSetDatatypes ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgUserName (LXtObjectID wcom, unsigned int index, const char **userName)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgUserName (index,userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgDesc (LXtObjectID wcom, unsigned int index, const char **desc)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgDesc (index,desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgExample (LXtObjectID wcom, unsigned int index, const char **example)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgExample (index,example);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgType (LXtObjectID wcom, unsigned int index, const char **type)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgType (index,type);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgTypeUserName (LXtObjectID wcom, unsigned int index, const char **userName)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgTypeUserName (index,userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgTypeDesc (LXtObjectID wcom, unsigned int index, const char **desc)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgTypeDesc (index,desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgOptionUserName (LXtObjectID wcom, unsigned int index, unsigned int optIndex, const char **userName)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgOptionUserName (index,optIndex,userName);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgOptionDesc (LXtObjectID wcom, unsigned int index, unsigned int optIndex, const char **desc)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgOptionDesc (index,optIndex,desc);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DialogInit (LXtObjectID wcom)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_DialogInit ();
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DialogArgChange (LXtObjectID wcom, unsigned int arg)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_DialogArgChange (arg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgEnable (LXtObjectID wcom, unsigned int arg)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgEnable (arg);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  ArgParseString (LXtObjectID wcom, unsigned int argIndex, const char *argString)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_ArgParseString (argIndex,argString);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Copy (LXtObjectID wcom, LXtObjectID sourceCommand)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Copy ((ILxUnknownID)sourceCommand);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  Query (LXtObjectID wcom, unsigned int index, LXtObjectID vaQuery)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_Query (index,(ILxUnknownID)vaQuery);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifyAddClient (LXtObjectID wcom, int argument, LXtObjectID object)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_NotifyAddClient (argument,(ILxUnknownID)object);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  NotifyRemoveClient (LXtObjectID wcom, LXtObjectID object)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_NotifyRemoveClient ((ILxUnknownID)object);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DialogFormatting (LXtObjectID wcom, const char **formatting)
  {
    LXCWxINST (CLxImpl_Command, loc);
    try {
      return loc->cmd_DialogFormatting (formatting);
    } catch (LxResult rc) { return rc; }
  }
  ILxCommand vt;
public:
  CLxIfc_Command ()
  {
    vt.Tag = Tag;
    vt.Name = Name;
    vt.UserName = UserName;
    vt.ButtonName = ButtonName;
    vt.Desc = Desc;
    vt.Tooltip = Tooltip;
    vt.Help = Help;
    vt.Example = Example;
    vt.Icon = Icon;
    vt.Flags = Flags;
    vt.PostExecFlags = PostExecFlags;
    vt.PostExecBehaviorFlags = PostExecBehaviorFlags;
    vt.PostExecHints = PostExecHints;
    vt.SandboxGUID = SandboxGUID;
    vt.Message = Message;
    vt.Enable = Enable;
    vt.ContainedEnable = ContainedEnable;
    vt.Interact = Interact;
    vt.PreExecute = PreExecute;
    vt.Execute = Execute;
    vt.ToggleArg = ToggleArg;
    vt.ArgFlags = ArgFlags;
    vt.ArgClear = ArgClear;
    vt.ArgResetAll = ArgResetAll;
    vt.ArgSetDatatypes = ArgSetDatatypes;
    vt.ArgUserName = ArgUserName;
    vt.ArgDesc = ArgDesc;
    vt.ArgExample = ArgExample;
    vt.ArgType = ArgType;
    vt.ArgTypeUserName = ArgTypeUserName;
    vt.ArgTypeDesc = ArgTypeDesc;
    vt.ArgOptionUserName = ArgOptionUserName;
    vt.ArgOptionDesc = ArgOptionDesc;
    vt.DialogInit = DialogInit;
    vt.DialogArgChange = DialogArgChange;
    vt.ArgEnable = ArgEnable;
    vt.ArgParseString = ArgParseString;
    vt.Copy = Copy;
    vt.Query = Query;
    vt.NotifyAddClient = NotifyAddClient;
    vt.NotifyRemoveClient = NotifyRemoveClient;
    vt.DialogFormatting = DialogFormatting;
    vTable = &vt.iunk;
    iid = &lx::guid_Command;
  }
};
class CLxLoc_Command : public CLxLocalize<ILxCommandID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_Command() {_init();}
  CLxLoc_Command(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_Command(const CLxLoc_Command &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_Command;}
    LxResult
  Tag (LXtCommandTag *tag)
  {
    return m_loc[0]->Tag (m_loc,tag);
  }
    LxResult
  Name (const char **name)
  {
    return m_loc[0]->Name (m_loc,name);
  }
    LxResult
  UserName (const char **userName)
  {
    return m_loc[0]->UserName (m_loc,userName);
  }
    LxResult
  ButtonName (const char **buttonName)
  {
    return m_loc[0]->ButtonName (m_loc,buttonName);
  }
    LxResult
  Desc (const char **desc)
  {
    return m_loc[0]->Desc (m_loc,desc);
  }
    LxResult
  Tooltip (const char **tooltip)
  {
    return m_loc[0]->Tooltip (m_loc,tooltip);
  }
    LxResult
  Help (const char **help)
  {
    return m_loc[0]->Help (m_loc,help);
  }
    LxResult
  Example (const char **example)
  {
    return m_loc[0]->Example (m_loc,example);
  }
    LxResult
  Icon (const char **iconNames)
  {
    return m_loc[0]->Icon (m_loc,iconNames);
  }
    LxResult
  Flags (unsigned int *flags)
  {
    return m_loc[0]->Flags (m_loc,flags);
  }
    LxResult
  PostExecFlags (unsigned int *flags)
  {
    return m_loc[0]->PostExecFlags (m_loc,flags);
  }
    LxResult
  PostExecBehaviorFlags (unsigned int *flags)
  {
    return m_loc[0]->PostExecBehaviorFlags (m_loc,flags);
  }
    LxResult
  PostExecHints (unsigned int *hints)
  {
    return m_loc[0]->PostExecHints (m_loc,hints);
  }
    LxResult
  SandboxGUID (const LXtGUID **guid)
  {
    return m_loc[0]->SandboxGUID (m_loc,guid);
  }
    LxResult
  Message (void **ppvObj)
  {
    return m_loc[0]->Message (m_loc,ppvObj);
  }
    bool
  Message (CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Message (m_loc,&obj)) && dest.take(obj);
  }
    LxResult
  Enable (ILxUnknownID msg)
  {
    return m_loc[0]->Enable (m_loc,(ILxUnknownID)msg);
  }
    LxResult
  ContainedEnable (LXtID4 *types)
  {
    return m_loc[0]->ContainedEnable (m_loc,types);
  }
    void
  Interact (void)
  {
    m_loc[0]->Interact (m_loc);
  }
    void
  PreExecute (void)
  {
    m_loc[0]->PreExecute (m_loc);
  }
    void
  Execute (unsigned int flags)
  {
    m_loc[0]->Execute (m_loc,flags);
  }
    LxResult
  ToggleArg (unsigned int *index, void **ppvObj, unsigned int *typeID, const char **typeName)
  {
    return m_loc[0]->ToggleArg (m_loc,index,ppvObj,typeID,typeName);
  }
    bool
  ToggleArg (unsigned int *index, CLxLocalizedObject &dest, unsigned int *typeID, const char **typeName)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->ToggleArg (m_loc,index,&obj,typeID,typeName)) && dest.take(obj);
  }
    LxResult
  ArgFlags (unsigned int index, unsigned int *flags)
  {
    return m_loc[0]->ArgFlags (m_loc,index,flags);
  }
    LxResult
  ArgClear (unsigned int index)
  {
    return m_loc[0]->ArgClear (m_loc,index);
  }
    LxResult
  ArgResetAll (void)
  {
    return m_loc[0]->ArgResetAll (m_loc);
  }
    LxResult
  ArgSetDatatypes (void)
  {
    return m_loc[0]->ArgSetDatatypes (m_loc);
  }
    LxResult
  ArgUserName (unsigned int index, const char **userName)
  {
    return m_loc[0]->ArgUserName (m_loc,index,userName);
  }
    LxResult
  ArgDesc (unsigned int index, const char **desc)
  {
    return m_loc[0]->ArgDesc (m_loc,index,desc);
  }
    LxResult
  ArgExample (unsigned int index, const char **example)
  {
    return m_loc[0]->ArgExample (m_loc,index,example);
  }
    LxResult
  ArgType (unsigned int index, const char **type)
  {
    return m_loc[0]->ArgType (m_loc,index,type);
  }
    LxResult
  ArgTypeUserName (unsigned int index, const char **userName)
  {
    return m_loc[0]->ArgTypeUserName (m_loc,index,userName);
  }
    LxResult
  ArgTypeDesc (unsigned int index, const char **desc)
  {
    return m_loc[0]->ArgTypeDesc (m_loc,index,desc);
  }
    LxResult
  ArgOptionUserName (unsigned int index, unsigned int optIndex, const char **userName)
  {
    return m_loc[0]->ArgOptionUserName (m_loc,index,optIndex,userName);
  }
    LxResult
  ArgOptionDesc (unsigned int index, unsigned int optIndex, const char **desc)
  {
    return m_loc[0]->ArgOptionDesc (m_loc,index,optIndex,desc);
  }
    LxResult
  DialogInit (void)
  {
    return m_loc[0]->DialogInit (m_loc);
  }
    LxResult
  DialogArgChange (unsigned int arg)
  {
    return m_loc[0]->DialogArgChange (m_loc,arg);
  }
    LxResult
  ArgEnable (unsigned int arg)
  {
    return m_loc[0]->ArgEnable (m_loc,arg);
  }
    LxResult
  ArgParseString (unsigned int argIndex, const char *argString)
  {
    return m_loc[0]->ArgParseString (m_loc,argIndex,argString);
  }
    LxResult
  Copy (ILxUnknownID sourceCommand)
  {
    return m_loc[0]->Copy (m_loc,(ILxUnknownID)sourceCommand);
  }
    LxResult
  Query (unsigned int index, ILxUnknownID vaQuery)
  {
    return m_loc[0]->Query (m_loc,index,(ILxUnknownID)vaQuery);
  }
    LxResult
  NotifyAddClient (int argument, ILxUnknownID object)
  {
    return m_loc[0]->NotifyAddClient (m_loc,argument,(ILxUnknownID)object);
  }
    LxResult
  NotifyRemoveClient (ILxUnknownID object)
  {
    return m_loc[0]->NotifyRemoveClient (m_loc,(ILxUnknownID)object);
  }
    LxResult
  DialogFormatting (const char **formatting)
  {
    return m_loc[0]->DialogFormatting (m_loc,formatting);
  }
};

class CLxImpl_AttributesUI {
  public:
    virtual ~CLxImpl_AttributesUI() {}
    virtual LxResult
      atrui_UIHints (unsigned int index, ILxUnknownID hints)
        { return LXe_NOTIMPL; }
    virtual LxResult
      atrui_UIValueHints (unsigned int index, void **ppvObj)
        { return LXe_NOTIMPL; }
    virtual LxResult
      atrui_DisableMsg (unsigned int index, ILxUnknownID message)
        { return LXe_NOTIMPL; }
};
#define LXxD_AttributesUI_UIHints LxResult atrui_UIHints (unsigned int index, ILxUnknownID hints)
#define LXxO_AttributesUI_UIHints LXxD_AttributesUI_UIHints LXx_OVERRIDE
#define LXxD_AttributesUI_UIValueHints LxResult atrui_UIValueHints (unsigned int index, void **ppvObj)
#define LXxO_AttributesUI_UIValueHints LXxD_AttributesUI_UIValueHints LXx_OVERRIDE
#define LXxD_AttributesUI_DisableMsg LxResult atrui_DisableMsg (unsigned int index, ILxUnknownID message)
#define LXxO_AttributesUI_DisableMsg LXxD_AttributesUI_DisableMsg LXx_OVERRIDE
template <class T>
class CLxIfc_AttributesUI : public CLxInterface
{
    static LxResult
  UIHints (LXtObjectID wcom, unsigned int index, LXtObjectID hints)
  {
    LXCWxINST (CLxImpl_AttributesUI, loc);
    try {
      return loc->atrui_UIHints (index,(ILxUnknownID)hints);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  UIValueHints (LXtObjectID wcom, unsigned int index, void **ppvObj)
  {
    LXCWxINST (CLxImpl_AttributesUI, loc);
    try {
      return loc->atrui_UIValueHints (index,ppvObj);
    } catch (LxResult rc) { return rc; }
  }
    static LxResult
  DisableMsg (LXtObjectID wcom, unsigned int index, LXtObjectID message)
  {
    LXCWxINST (CLxImpl_AttributesUI, loc);
    try {
      return loc->atrui_DisableMsg (index,(ILxUnknownID)message);
    } catch (LxResult rc) { return rc; }
  }
  ILxAttributesUI vt;
public:
  CLxIfc_AttributesUI ()
  {
    vt.UIHints = UIHints;
    vt.UIValueHints = UIValueHints;
    vt.DisableMsg = DisableMsg;
    vTable = &vt.iunk;
    iid = &lx::guid_AttributesUI;
  }
};
class CLxLoc_AttributesUI : public CLxLocalize<ILxAttributesUIID>
{
public:
  void _init() {m_loc=0;}
  CLxLoc_AttributesUI() {_init();}
  CLxLoc_AttributesUI(ILxUnknownID obj) {_init();set(obj);}
  CLxLoc_AttributesUI(const CLxLoc_AttributesUI &other) {_init();set(other.m_loc);}
  const LXtGUID * guid() const {return &lx::guid_AttributesUI;}
    LxResult
  UIHints (unsigned int index, ILxUnknownID hints)
  {
    return m_loc[0]->UIHints (m_loc,index,(ILxUnknownID)hints);
  }
    LxResult
  UIValueHints (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->UIValueHints (m_loc,index,ppvObj);
  }
    bool
  UIValueHints (unsigned int index, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->UIValueHints (m_loc,index,&obj)) && dest.take(obj);
  }
    LxResult
  DisableMsg (unsigned int index, ILxUnknownID message)
  {
    return m_loc[0]->DisableMsg (m_loc,index,(ILxUnknownID)message);
  }
};

class CLxLoc_CommandService : public CLxLocalizedService
{
  ILxCommandServiceID m_loc;
public:
  void _init() {m_loc=0;}
  CLxLoc_CommandService() {_init();set();}
 ~CLxLoc_CommandService() {}
  void set() {if(!m_loc)m_loc=reinterpret_cast<ILxCommandServiceID>(lx::GetGlobal(&lx::guid_CommandService));}
    LxResult
  ScriptQuery (void **ppvObj)
  {
    return m_loc[0]->ScriptQuery (m_loc,ppvObj);
  }
    LxResult
  MasterStatus (unsigned int *status)
  {
    return m_loc[0]->MasterStatus (m_loc,status);
  }
    LxResult
  GetNameSep (unsigned int *sep)
  {
    return m_loc[0]->GetNameSep (m_loc,sep);
  }
    LxResult
  SetNameSep (unsigned int sep)
  {
    return m_loc[0]->SetNameSep (m_loc,sep);
  }
    LxResult
  Proto (LXtCommandTag tag, const char *name, void **ppvObj)
  {
    return m_loc[0]->Proto (m_loc,tag,name,ppvObj);
  }
    bool
  Proto (LXtCommandTag tag, const char *name, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Proto (m_loc,tag,name,&obj)) && dest.take(obj);
  }
    LxResult
  ProtoFromCommand (ILxUnknownID cmd, void **ppvObj)
  {
    return m_loc[0]->ProtoFromCommand (m_loc,(ILxUnknownID)cmd,ppvObj);
  }
    bool
  ProtoFromCommand (ILxUnknownID cmd, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->ProtoFromCommand (m_loc,(ILxUnknownID)cmd,&obj)) && dest.take(obj);
  }
    LxResult
  Lookup (const char *name, LXtCommandTag *tag)
  {
    return m_loc[0]->Lookup (m_loc,name,tag);
  }
    LxResult
  Spawn (LXtCommandTag tag, const char *name, void **ppvObj)
  {
    return m_loc[0]->Spawn (m_loc,tag,name,ppvObj);
  }
    bool
  Spawn (LXtCommandTag tag, const char *name, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Spawn (m_loc,tag,name,&obj)) && dest.take(obj);
  }
    LxResult
  SpawnFromCommand (ILxUnknownID cmd, void **ppvObj)
  {
    return m_loc[0]->SpawnFromCommand (m_loc,(ILxUnknownID)cmd,ppvObj);
  }
    bool
  SpawnFromCommand (ILxUnknownID cmd, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->SpawnFromCommand (m_loc,(ILxUnknownID)cmd,&obj)) && dest.take(obj);
  }
    LxResult
  SpawnFromString (const char *args, unsigned int *execFlags, int *queryArgIndex, void **ppvObj)
  {
    return m_loc[0]->SpawnFromString (m_loc,args,execFlags,queryArgIndex,ppvObj);
  }
    bool
  SpawnFromString (const char *args, unsigned int *execFlags, int *queryArgIndex, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->SpawnFromString (m_loc,args,execFlags,queryArgIndex,&obj)) && dest.take(obj);
  }
    LxResult
  ExecuteArgString (unsigned int execFlags, LXtCommandTag tag, const char *args)
  {
    return m_loc[0]->ExecuteArgString (m_loc,execFlags,tag,args);
  }
    LxResult
  ExecuteToggleArgString (unsigned int execFlags, LXtCommandTag tag, const char *args, int newState)
  {
    return m_loc[0]->ExecuteToggleArgString (m_loc,execFlags,tag,args,newState);
  }
    LxResult
  IsToggleArgString (const char *string)
  {
    return m_loc[0]->IsToggleArgString (m_loc,string);
  }
    LxResult
  IsBooleanArgString (const char *string)
  {
    return m_loc[0]->IsBooleanArgString (m_loc,string);
  }
    LxResult
  ExecuteBooleanArgString (unsigned int execFlags, LXtCommandTag tag, const char *args)
  {
    return m_loc[0]->ExecuteBooleanArgString (m_loc,execFlags,tag,args);
  }
    LxResult
  ExecuteSpecial (unsigned int execFlags, ILxUnknownID cmd, int specialArgIndex)
  {
    return m_loc[0]->ExecuteSpecial (m_loc,execFlags,(ILxUnknownID)cmd,specialArgIndex);
  }
    LxResult
  ExecuteAttribObject (unsigned int execFlags, LXtCommandTag tag, const char *cmdName, ILxUnknownID attribArgs)
  {
    return m_loc[0]->ExecuteAttribObject (m_loc,execFlags,tag,cmdName,(ILxUnknownID)attribArgs);
  }
    LxResult
  ProcessStringFlags (unsigned int flags, const char *string, unsigned int *newFlags, const char **afterFlags)
  {
    return m_loc[0]->ProcessStringFlags (m_loc,flags,string,newFlags,afterFlags);
  }
    LxResult
  ExecFlagsAsPrefixString (unsigned int flags, char *buf, unsigned int len)
  {
    return m_loc[0]->ExecFlagsAsPrefixString (m_loc,flags,buf,len);
  }
    LxResult
  ExecFlagsAsPrefixString (unsigned int flags, std::string &result)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ExecFlagsAsPrefixString (m_loc,flags,buf,len);
    LXWx_SBUF2
  }
    LxResult
  SetToggleArgState (ILxUnknownID cmd, int state)
  {
    return m_loc[0]->SetToggleArgState (m_loc,(ILxUnknownID)cmd,state);
  }
    LxResult
  GetToggleArgState (ILxUnknownID cmd, int *state, void **ppvObj)
  {
    return m_loc[0]->GetToggleArgState (m_loc,(ILxUnknownID)cmd,state,ppvObj);
  }
    bool
  GetToggleArgState (ILxUnknownID cmd, int *state, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->GetToggleArgState (m_loc,(ILxUnknownID)cmd,state,&obj)) && dest.take(obj);
  }
    LxResult
  IsImplicitScript (const char *def)
  {
    return m_loc[0]->IsImplicitScript (m_loc,def);
  }
    LxResult
  SpawnImplicitScript (const char *def, void **ppvObj)
  {
    return m_loc[0]->SpawnImplicitScript (m_loc,def,ppvObj);
  }
    bool
  SpawnImplicitScript (const char *def, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->SpawnImplicitScript (m_loc,def,&obj)) && dest.take(obj);
  }
    LxResult
  ExecuteImplicitScript (const char *def, unsigned int execFlags)
  {
    return m_loc[0]->ExecuteImplicitScript (m_loc,def,execFlags);
  }
    LxResult
  RefireBegin (void)
  {
    return m_loc[0]->RefireBegin (m_loc);
  }
    LxResult
  RefireEnd (void)
  {
    return m_loc[0]->RefireEnd (m_loc);
  }
    LxResult
  RefireState (unsigned int *state)
  {
    return m_loc[0]->RefireState (m_loc,state);
  }
    LxResult
  RefireCmd (void **ppvObj)
  {
    return m_loc[0]->RefireCmd (m_loc,ppvObj);
  }
    bool
  RefireCmd (CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->RefireCmd (m_loc,&obj)) && dest.take(obj);
  }
    LxResult
  RefireBlock (const char **name)
  {
    return m_loc[0]->RefireBlock (m_loc,name);
  }
    LxResult
  PostModeBegin (ILxUnknownID cmd, LXtCommandTag tag, const char *name, const char *args, ILxUnknownID postEndObj)
  {
    return m_loc[0]->PostModeBegin (m_loc,(ILxUnknownID)cmd,tag,name,args,(ILxUnknownID)postEndObj);
  }
    LxResult
  PostModeEnd (void)
  {
    return m_loc[0]->PostModeEnd (m_loc);
  }
    LxResult
  PostModeState (void)
  {
    return m_loc[0]->PostModeState (m_loc);
  }
    LxResult
  PostModeRestart (void)
  {
    return m_loc[0]->PostModeRestart (m_loc);
  }
    LxResult
  CurrentExecDepth (int *depth)
  {
    return m_loc[0]->CurrentExecDepth (m_loc,depth);
  }
    LxResult
  BlockBegin (const char *name, unsigned int flags)
  {
    return m_loc[0]->BlockBegin (m_loc,name,flags);
  }
    LxResult
  BlockEnd (void)
  {
    return m_loc[0]->BlockEnd (m_loc);
  }
    LxResult
  BlockCurrent (void **block)
  {
    return m_loc[0]->BlockCurrent (m_loc,block);
  }
    LxResult
  SandboxFlags (unsigned int *flags)
  {
    return m_loc[0]->SandboxFlags (m_loc,flags);
  }
    LxResult
  SandboxAddObject (ILxUnknownID object)
  {
    return m_loc[0]->SandboxAddObject (m_loc,(ILxUnknownID)object);
  }
    LxResult
  SandboxObjectCount (unsigned int *count)
  {
    return m_loc[0]->SandboxObjectCount (m_loc,count);
  }
    LxResult
  SandboxObjectByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->SandboxObjectByIndex (m_loc,index,ppvObj);
  }
    bool
  SandboxObjectByIndex (unsigned int index, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->SandboxObjectByIndex (m_loc,index,&obj)) && dest.take(obj);
  }
    LxResult
  SandboxObjectLookup (const LXtGUID *guid, void **ppvObj)
  {
    return m_loc[0]->SandboxObjectLookup (m_loc,guid,ppvObj);
  }
    LxResult
  SandboxObjectByCommand (ILxUnknownID cmd, void **ppvObj)
  {
    return m_loc[0]->SandboxObjectByCommand (m_loc,(ILxUnknownID)cmd,ppvObj);
  }
    bool
  SandboxObjectByCommand (ILxUnknownID cmd, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->SandboxObjectByCommand (m_loc,(ILxUnknownID)cmd,&obj)) && dest.take(obj);
  }
    LxResult
  SandboxBegin (unsigned int flags)
  {
    return m_loc[0]->SandboxBegin (m_loc,flags);
  }
    LxResult
  SandboxState (void)
  {
    return m_loc[0]->SandboxState (m_loc);
  }
    LxResult
  SandboxEnd (void)
  {
    return m_loc[0]->SandboxEnd (m_loc);
  }
    LxResult
  ParseArgString (ILxUnknownID cmd, int alertFlags, const char *args)
  {
    return m_loc[0]->ParseArgString (m_loc,(ILxUnknownID)cmd,alertFlags,args);
  }
    LxResult
  ParseAttribObject (ILxUnknownID cmd, unsigned int alertFlags, ILxUnknownID attribArgs)
  {
    return m_loc[0]->ParseAttribObject (m_loc,(ILxUnknownID)cmd,alertFlags,(ILxUnknownID)attribArgs);
  }
    LxResult
  Usage (ILxUnknownID cmd, const char **buffer)
  {
    return m_loc[0]->Usage (m_loc,(ILxUnknownID)cmd,buffer);
  }
    LxResult
  ArgsAsString (ILxUnknownID cmd, char *buf, unsigned int len, unsigned int includeCmd)
  {
    return m_loc[0]->ArgsAsString (m_loc,(ILxUnknownID)cmd,buf,len,includeCmd);
  }
    LxResult
  ArgsAsString (ILxUnknownID cmd, std::string &result, unsigned int includeCmd)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ArgsAsString (m_loc,(ILxUnknownID)cmd,buf,len,includeCmd);
    LXWx_SBUF2
  }
    LxResult
  Query (ILxUnknownID cmd, unsigned int index, void **ppvObj)
  {
    return m_loc[0]->Query (m_loc,(ILxUnknownID)cmd,index,ppvObj);
  }
    bool
  Query (ILxUnknownID cmd, unsigned int index, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->Query (m_loc,(ILxUnknownID)cmd,index,&obj)) && dest.take(obj);
  }
    LxResult
  QueryArgString (ILxUnknownID cmd, unsigned int alertFlags, const char *args, void **ppvObj, unsigned int *queryIndex, unsigned int includesCmdName)
  {
    return m_loc[0]->QueryArgString (m_loc,(ILxUnknownID)cmd,alertFlags,args,ppvObj,queryIndex,includesCmdName);
  }
    bool
  QueryArgString (ILxUnknownID cmd, unsigned int alertFlags, const char *args, CLxLocalizedObject &dest, unsigned int *queryIndex, unsigned int includesCmdName)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->QueryArgString (m_loc,(ILxUnknownID)cmd,alertFlags,args,&obj,queryIndex,includesCmdName)) && dest.take(obj);
  }
    LxResult
  CreateQueryObject (const char *typeName, void **ppvObj)
  {
    return m_loc[0]->CreateQueryObject (m_loc,typeName,ppvObj);
  }
    bool
  CreateQueryObject (const char *typeName, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->CreateQueryObject (m_loc,typeName,&obj)) && dest.take(obj);
  }
    LxResult
  AliasCreate (const char *name, ILxUnknownID targetCmd, LXtCommandTag targetTag, const char *targetName, const char *args)
  {
    return m_loc[0]->AliasCreate (m_loc,name,(ILxUnknownID)targetCmd,targetTag,targetName,args);
  }
    LxResult
  AliasDelete (ILxUnknownID alias, LXtCommandTag tag, const char *name)
  {
    return m_loc[0]->AliasDelete (m_loc,(ILxUnknownID)alias,tag,name);
  }
    LxResult
  IsContainer (ILxUnknownID cmd)
  {
    return m_loc[0]->IsContainer (m_loc,(ILxUnknownID)cmd);
  }
    LxResult
  IsAliased (ILxUnknownID cmd)
  {
    return m_loc[0]->IsAliased (m_loc,(ILxUnknownID)cmd);
  }
    LxResult
  CommandCount (unsigned int *count)
  {
    return m_loc[0]->CommandCount (m_loc,count);
  }
    LxResult
  CommandByIndex (unsigned int index, void **ppvObj)
  {
    return m_loc[0]->CommandByIndex (m_loc,index,ppvObj);
  }
    bool
  CommandByIndex (unsigned int index, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->CommandByIndex (m_loc,index,&obj)) && dest.take(obj);
  }
    LxResult
  ExecEntryType (int index, int *type)
  {
    return m_loc[0]->ExecEntryType (m_loc,index,type);
  }
    LxResult
  ExecEntryUserName (int index, const char **userName)
  {
    return m_loc[0]->ExecEntryUserName (m_loc,index,userName);
  }
    LxResult
  ExecEntryName (int index, const char **name)
  {
    return m_loc[0]->ExecEntryName (m_loc,index,name);
  }
    LxResult
  ExecEntryAsArgString (int index, char *buf, int len)
  {
    return m_loc[0]->ExecEntryAsArgString (m_loc,index,buf,len);
  }
    LxResult
  IsGlobalInteractionOK (void)
  {
    return m_loc[0]->IsGlobalInteractionOK (m_loc);
  }
    LxResult
  ArgsAsStringLen (ILxUnknownID cmd, char *buf, unsigned int len, unsigned int includeCmd)
  {
    return m_loc[0]->ArgsAsStringLen (m_loc,(ILxUnknownID)cmd,buf,len,includeCmd);
  }
    LxResult
  ArgsAsStringLen (ILxUnknownID cmd, std::string &result, unsigned int includeCmd)
  {
    LXWx_SBUF1
    rc = m_loc[0]->ArgsAsStringLen (m_loc,(ILxUnknownID)cmd,buf,len,includeCmd);
    LXWx_SBUF2
  }
    LxResult
  SpawnUnaliased (LXtCommandTag tag, const char *name, void **ppvObj)
  {
    return m_loc[0]->SpawnUnaliased (m_loc,tag,name,ppvObj);
  }
    bool
  SpawnUnaliased (LXtCommandTag tag, const char *name, CLxLocalizedObject &dest)
  {
    LXtObjectID obj;
    dest.clear();
    return LXx_OK(m_loc[0]->SpawnUnaliased (m_loc,tag,name,&obj)) && dest.take(obj);
  }
    LxResult
  SetIsGlobalInteractionOK (int isOK)
  {
    return m_loc[0]->SetIsGlobalInteractionOK (m_loc,isOK);
  }
};

#endif

