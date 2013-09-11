/*
 * LX cmds2 module
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
#ifndef LX_cmds2_H
#define LX_cmds2_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxCommand ** ILxCommandID;
typedef struct vt_ILxCommandDBHelp ** ILxCommandDBHelpID;
typedef struct vt_ILxUIHints ** ILxUIHintsID;
typedef struct vt_ILxUIValueHints ** ILxUIValueHintsID;
typedef struct vt_ILxUIValueHints1 ** ILxUIValueHints1ID;
typedef struct vt_ILxAttributesUI ** ILxAttributesUIID;
typedef struct vt_ILxCommandEvent ** ILxCommandEventID;
typedef struct vt_ILxCommandBlock ** ILxCommandBlockID;
typedef struct vt_ILxCommandService ** ILxCommandServiceID;
typedef struct vt_ILxCommandPostEnd ** ILxCommandPostEndID;
#include <lxserver.h>
#include <lxvalue.h>

typedef unsigned short  LXtCommandTag;
#define LXiCTAG_NULL    ((LXtCommandTag) 0)

typedef struct vt_ILxCommand {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Tag) (
                LXtObjectID              self,
                LXtCommandTag           *tag);
                LXxMETHOD(  LxResult,
        Name) (
                LXtObjectID              self,
                const char             **name);

                LXxMETHOD(  LxResult,
        UserName) (
                LXtObjectID              self,
                const char             **userName);

                LXxMETHOD(  LxResult,
        ButtonName) (
                LXtObjectID              self,
                const char             **buttonName);

                LXxMETHOD(  LxResult,
        Desc) (
                LXtObjectID              self,
                const char             **desc);

                LXxMETHOD(  LxResult,
        Tooltip) (
                LXtObjectID              self,
                const char             **tooltip);
                LXxMETHOD(  LxResult,
        Help) (
                LXtObjectID              self,
                const char             **help);
                LXxMETHOD(  LxResult,
        Example) (
                LXtObjectID              self,
                const char             **example);
                LXxMETHOD(  LxResult,
        Icon) (
                LXtObjectID              self,
                const char             **iconNames);
                LXxMETHOD(  LxResult,
        Flags) (
                LXtObjectID              self,
                unsigned int            *flags);
                LXxMETHOD(  LxResult,
        PostExecFlags) (
                LXtObjectID              self,
                unsigned int            *flags);
                LXxMETHOD(  LxResult,
        PostExecBehaviorFlags) (
                LXtObjectID              self,
                unsigned int            *flags);
                LXxMETHOD(  LxResult,
        PostExecHints) (
                LXtObjectID              self,
                unsigned int            *hints);
                LXxMETHOD(  LxResult,
        SandboxGUID) (
                LXtObjectID               self,
                LXtGUID                 **guid);
                LXxMETHOD(  LxResult,
        Message) (
                LXtObjectID               self,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        Enable) (
                LXtObjectID               self,
                LXtObjectID               msg);
                LXxMETHOD(  LxResult,
        ContainedEnable) (
                LXtObjectID               self,
                LXtID4                   *types);
                LXxMETHOD( void,
        Interact) (
                LXtObjectID               self);
                LXxMETHOD( void,
        PreExecute) (
                LXtObjectID               self);
                LXxMETHOD(  void,
        Execute) (
                LXtObjectID              self,
                unsigned int             flags);
                LXxMETHOD(  LxResult,
        ToggleArg) (
                LXtObjectID               self,
                unsigned int             *index,
                void                    **value,
                unsigned int             *typeID,
                const char              **typeName);
                LXxMETHOD(  LxResult,
        ArgFlags) (
                LXtObjectID               self,
                unsigned int              index,
                unsigned int             *flags);
                LXxMETHOD(  LxResult,
        ArgClear) (
                LXtObjectID               self,
                unsigned int              index );
                LXxMETHOD(  LxResult,
        ArgResetAll) (
                LXtObjectID               self );
                LXxMETHOD(  LxResult,
        ArgSetDatatypes) (
                LXtObjectID               self );
                LXxMETHOD(  LxResult,
        ArgUserName) (
                LXtObjectID              self,
                unsigned int             index,
                const char             **userName);

                LXxMETHOD(  LxResult,
        ArgDesc) (
                LXtObjectID              self,
                unsigned int             index,
                const char             **desc);

                LXxMETHOD(  LxResult,
        ArgExample) (
                LXtObjectID              self,
                unsigned int             index,
                const char             **example);
                LXxMETHOD(  LxResult,
        ArgType) (
                LXtObjectID              self,
                unsigned int             index,
                const char             **type);

                LXxMETHOD(  LxResult,
        ArgTypeUserName) (
                LXtObjectID              self,
                unsigned int             index,
                const char             **userName);

                LXxMETHOD(  LxResult,
        ArgTypeDesc) (
                LXtObjectID              self,
                unsigned int             index,
                const char             **desc);
                LXxMETHOD(  LxResult,
        ArgOptionUserName) (
                LXtObjectID              self,
                unsigned int             index,
                unsigned int             optIndex,
                const char             **userName);

                LXxMETHOD(  LxResult,
        ArgOptionDesc) (
                LXtObjectID              self,
                unsigned int             index,
                unsigned int             optIndex,
                const char             **desc);
                LXxMETHOD(  LxResult,
        DialogInit) (
                LXtObjectID               self);
                LXxMETHOD(  LxResult,
        DialogArgChange) (
                LXtObjectID               self,
                unsigned int              arg);
                LXxMETHOD(  LxResult,
        ArgEnable) (
                LXtObjectID               self,
                unsigned int              arg);
                LXxMETHOD(  LxResult,
        ArgParseString) (
                LXtObjectID               self,
                unsigned int              argIndex,
                const char               *argString);
                LXxMETHOD(  LxResult,
        Copy) (
                LXtObjectID               self,
                LXtObjectID               sourceCommand );
                LXxMETHOD(  LxResult,
        Query) (
                LXtObjectID               self,
                unsigned int              index,
                LXtObjectID               vaQuery );
                LXxMETHOD(  LxResult,
        NotifyAddClient) (
                LXtObjectID               self,
                int                       argument,
                LXtObjectID               object);
                LXxMETHOD(  LxResult,
        NotifyRemoveClient) (
                LXtObjectID               self,
                LXtObjectID               object);
} ILxCommand;
typedef struct vt_ILxCommandDBHelp {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        DBHelp) (
                LXtObjectID              self,
                const char             **dbhelp);
} ILxCommandDBHelp;
typedef struct vt_ILxUIHints {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Class) (
                LXtObjectID               self,
                const char               *c);
                LXxMETHOD(  LxResult,
        Label) (
                LXtObjectID               self,
                const char               *label);
                LXxMETHOD(  LxResult,
        MinInt) (
                LXtObjectID               self,
                int                       min);

                LXxMETHOD(  LxResult,
        MaxInt) (
                LXtObjectID               self,
                int                       max);

                LXxMETHOD(  LxResult,
        MinFloat) (
                LXtObjectID               self,
                double                    min);

                LXxMETHOD(  LxResult,
        MaxFloat) (
                LXtObjectID               self,
                double                    max);
                LXxMETHOD(  LxResult,
        StepInt) (
                LXtObjectID               self,
                int                       step);

                LXxMETHOD(  LxResult,
        StepFloat) (
                LXtObjectID               self,
                double                    step);
                LXxMETHOD(  LxResult,
        Track) (
                LXtObjectID               self,
                unsigned int              state);
                LXxMETHOD(  LxResult,
        StringList) (
                LXtObjectID               self,
                const char              **strings);
                LXxMETHOD(  LxResult,
        TextLines) (
                LXtObjectID               self,
                unsigned int              lines);
                LXxMETHOD(  LxResult,
        TextFixedWidthFont) (
                LXtObjectID               self,
                unsigned int              state);
                LXxMETHOD(  LxResult,
        TextPasswordMode) (
                LXtObjectID               self,
                unsigned int              state);
                LXxMETHOD(  LxResult,
        ValuePresetCookie) (
                LXtObjectID               self,
                const char               *cookie);
                LXxMETHOD(  LxResult,
        ForceUpdate) (
                LXtObjectID               self);
                LXxMETHOD(  LxResult,
        BooleanStyle) (
                LXtObjectID               self,
                unsigned int              style);
} ILxUIHints;
typedef struct vt_ILxUIValueHints {
        ILxUnknown       iunk;
                LXxMETHOD(  unsigned,
        Flags) (
                LXtObjectID              self);
                LXxMETHOD(  unsigned,
        PopCount) (
                LXtObjectID              self);

                LXxMETHOD(  const char *,
        PopUserName) (
                LXtObjectID              self,
                unsigned                 index);

                LXxMETHOD(  const char *,
        PopInternalName) (
                LXtObjectID              self,
                unsigned                 index);
                LXxMETHOD(  unsigned,
        PopIconSize) (
                LXtObjectID              self,
                int                     *w,
                int                     *h);
                LXxMETHOD(  LxResult,
        PopIconImage) (
                LXtObjectID               self,
                int                       index,
                void                    **ppvObj);

                LXxMETHOD(  LxResult,
        PopIconResource) (
                LXtObjectID               self,
                int                       index,
                const char              **iconResource);
                LXxMETHOD(  LxResult,
        PopFlags) (
                LXtObjectID              self,
                unsigned                 index,
                int                     *flags);
                LXxMETHOD(  LxResult,
        PopCategory) (
                LXtObjectID               self,
                const char              **category);
                LXxMETHOD(  LxResult,
        ItemTest) (
                LXtObjectID              self,
                LXtObjectID              item);
                LXxMETHOD(  LxResult,
        ColorPickerCommands) (
                LXtObjectID               self,
                char                     *rgb,
                char                     *alpha,
                char                     *rgbAlt,
                char                     *alphaAlt,
                char                     *useAlt,
                unsigned                  bufLens);
                LXxMETHOD(  LxResult,
        NotifierCount) (
                LXtObjectID               self,
                int                      *count);
                LXxMETHOD(  LxResult,
        NotifierByIndex) (
                LXtObjectID               self,
                int                       index,
                const char              **name,
                const char              **args);
                LXxMETHOD(  LxResult,
        FormCommandListCount) (
                LXtObjectID               self,
                int                      *count);

                LXxMETHOD(  LxResult,
        FormCommandListByIndex) (
                LXtObjectID               self,
                int                       index,
                const char              **command);
} ILxUIValueHints;
typedef struct vt_ILxUIValueHints1 {
        ILxUnknown       iunk;
                LXxMETHOD(  unsigned,
        Flags) (
                LXtObjectID              self);

                LXxMETHOD(  unsigned,
        PopCount) (
                LXtObjectID              self);

                LXxMETHOD(  const char *,
        PopUserName) (
                LXtObjectID              self,
                unsigned                 index);

                LXxMETHOD(  const char *,
        PopInternalName) (
                LXtObjectID              self,
                unsigned                 index);

                LXxMETHOD(  LxResult,
        PopFlags) (
                LXtObjectID              self,
                unsigned                 index,
                int                     *flags);

                LXxMETHOD(  LxResult,
        PopCategory) (
                LXtObjectID               self,
                const char              **category);

                LXxMETHOD(  LxResult,
        ItemTest) (
                LXtObjectID              self,
                LXtObjectID              item);

                LXxMETHOD(  LxResult,
        ColorPickerCommands) (
                LXtObjectID               self,
                char                     *rgb,
                char                     *alpha,
                char                     *rgbAlt,
                char                     *alphaAlt,
                char                     *useAlt,
                unsigned                  bufLens);

                LXxMETHOD(  LxResult,
        NotifierCount) (
                LXtObjectID               self,
                int                      *count);

                LXxMETHOD(  LxResult,
        NotifierByIndex) (
                LXtObjectID               self,
                const char              **name,
                const char              **args);

                LXxMETHOD(  LxResult,
        FormCommandListCount) (
                LXtObjectID               self,
                int                      *count);

                LXxMETHOD(  LxResult,
        FormCommandListByIndex) (
                LXtObjectID               self,
                int                       index,
                const char              **command);
} ILxUIValueHints1;
typedef struct vt_ILxAttributesUI {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        UIHints) (
                LXtObjectID               self,
                unsigned int              index,
                LXtObjectID               hints);
                LXxMETHOD(  LxResult,
        UIValueHints) (
                LXtObjectID               self,
                unsigned int              index,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        DisableMsg) (
                LXtObjectID               self,
                unsigned int              index,
                LXtObjectID               message);
} ILxAttributesUI;
typedef struct vt_ILxCommandEvent {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Event) (
                LXtObjectID              self,
                unsigned int             flags);
} ILxCommandEvent;
typedef struct vt_ILxCommandBlock {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        Name) (
                LXtObjectID              self,
                const char             **name);
                LXxMETHOD(  LxResult,
        Flags) (
                LXtObjectID              self,
                unsigned int            *flags);
                LXxMETHOD(  LxResult,
        SubExecs) (
                LXtObjectID              self,
                unsigned int            *execs);
                LXxMETHOD(  LxResult,
        PostExecFlags) (
                LXtObjectID              self,
                unsigned int            *flags);
} ILxCommandBlock;
typedef struct vt_ILxCommandService {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        ScriptQuery) (
                LXtObjectID              self,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        MasterStatus) (
                LXtObjectID              self,
                unsigned int            *status);
                LXxMETHOD(  LxResult,
        GetNameSep) (
                LXtObjectID              self,
                unsigned int            *sep);

                LXxMETHOD(  LxResult,
        SetNameSep) (
                LXtObjectID              self,
                unsigned int             sep);
                LXxMETHOD(  LxResult,
        Proto) (
                LXtObjectID               self,
                LXtCommandTag             tag,
                const char               *name,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        ProtoFromCommand) (
                LXtObjectID               self,
                LXtObjectID               cmd,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        Lookup) (
                LXtObjectID              self,
                const char              *name,
                LXtCommandTag           *tag);
                LXxMETHOD(  LxResult,
        Spawn) (
                LXtObjectID               self,
                LXtCommandTag             tag,
                const char               *name,
                void                    **cmd);
                LXxMETHOD(  LxResult,
        SpawnFromCommand) (
                LXtObjectID               self,
                LXtObjectID               cmd,
                void                    **spawn);
                LXxMETHOD(  LxResult,
        SpawnFromString) (
                LXtObjectID               self,
                const char               *args,
                unsigned int             *execFlags,
                int                      *queryArgIndex,
                void                    **spawn);
                LXxMETHOD(  LxResult,
        ExecuteArgString) (
                LXtObjectID              self,
                unsigned int             execFlags,
                LXtCommandTag            tag,
                const char              *args);
                LXxMETHOD(  LxResult,
        ExecuteToggleArgString) (
                LXtObjectID              self,
                unsigned int             execFlags,
                LXtCommandTag            tag,
                const char              *args,
                int                      newState);
                LXxMETHOD(  LxResult,
        IsToggleArgString) (
                LXtObjectID              self,
                const char              *string);
                LXxMETHOD(  LxResult,
        IsBooleanArgString) (
                LXtObjectID              self,
                const char              *string);
                LXxMETHOD(  LxResult,
        ExecuteBooleanArgString) (
                LXtObjectID              self,
                unsigned int             execFlags,
                LXtCommandTag            tag,
                const char              *args);
                LXxMETHOD(  LxResult,
        ExecuteSpecial) (
                LXtObjectID              self,
                unsigned int             execFlags,
                LXtObjectID              cmd,
                int                      specialArgIndex);
                LXxMETHOD(  LxResult,
        ExecuteAttribObject) (
                LXtObjectID              self,
                unsigned int             execFlags,
                LXtCommandTag            tag,
                const char              *cmdName,
                LXtObjectID              attribArgs);
                LXxMETHOD(  LxResult,
        ProcessStringFlags) (
                LXtObjectID               self,
                unsigned int              flags,
                const char               *string,
                unsigned int             *newFlags,
                char                    **afterFlags);
                LXxMETHOD(  LxResult,
        ExecFlagsAsPrefixString) (
                LXtObjectID               self,
                unsigned int              flags,
                char                     *buffer,
                unsigned int              len);
                LXxMETHOD(  LxResult,
        SetToggleArgState) (
                LXtObjectID              self,
                LXtObjectID              cmd,
                int                      state);
                LXxMETHOD(  LxResult,
        GetToggleArgState) (
                LXtObjectID              self,
                LXtObjectID              cmd,
                int                     *state,
                void                   **ppvObj);
                LXxMETHOD(  LxResult,
        IsImplicitScript) (
                LXtObjectID              self,
                const char              *def );
                LXxMETHOD(  LxResult,
        SpawnImplicitScript) (
                LXtObjectID               self,
                const char               *def,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        ExecuteImplicitScript) (
                LXtObjectID              self,
                const char              *def,
                unsigned int             execFlags);
                LXxMETHOD(  LxResult,
        RefireBegin) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        RefireEnd) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        RefireState) (
                LXtObjectID              self,
                unsigned int            *state);
                LXxMETHOD(  LxResult,
        RefireCmd) (
                LXtObjectID               self,
                void                    **cmd);
                LXxMETHOD(  LxResult,
        RefireBlock) (
                LXtObjectID              self,
                const char             **name);
                LXxMETHOD(  LxResult,
        PostModeBegin) (
                LXtObjectID              self,
                LXtObjectID              cmd,
                LXtCommandTag            tag,
                const char              *name,
                const char              *args,
                LXtObjectID              postEndObj);
                LXxMETHOD(  LxResult,
        PostModeEnd ) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        PostModeState ) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        PostModeRestart ) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        CurrentExecDepth ) (
                LXtObjectID              self,
                int                     *depth);
                LXxMETHOD(  LxResult,
        BlockBegin) (
                LXtObjectID              self,
                const char              *name,
                unsigned int             flags);
                LXxMETHOD(  LxResult,
        BlockEnd) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        BlockCurrent) (
                LXtObjectID               self,
                void                    **block);
                LXxMETHOD(  LxResult,
        SandboxFlags) (
                LXtObjectID              self,
                unsigned int            *flags);
                LXxMETHOD(  LxResult,
        SandboxAddObject) (
                LXtObjectID              self,
                LXtObjectID              object);
                LXxMETHOD(  LxResult,
        SandboxObjectCount) (
                LXtObjectID               self,
                unsigned int             *count);

                LXxMETHOD(  LxResult,
        SandboxObjectByIndex) (
                LXtObjectID               self,
                unsigned int              index,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        SandboxObjectLookup) (
                LXtObjectID               self,
                LXtGUID                  *guid,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        SandboxObjectByCommand) (
                LXtObjectID               self,
                LXtObjectID               cmd,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        SandboxBegin) (
                LXtObjectID              self,
                unsigned int             flags);
                LXxMETHOD(  LxResult,
        SandboxState) (
                LXtObjectID               self);
                LXxMETHOD(  LxResult,
        SandboxEnd) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        ParseArgString) (
                LXtObjectID              self,
                LXtObjectID              cmd,
                int                      alertFlags,
                const char              *args);
                LXxMETHOD(  LxResult,
        ParseAttribObject) (
                LXtObjectID              self,
                LXtObjectID              cmd,
                unsigned int             alertFlags,
                LXtObjectID              attribArgs);
                LXxMETHOD(  LxResult,
        Usage) (
                LXtObjectID              self,
                LXtObjectID              cmd,
                char                   **buffer);
                LXxMETHOD(  LxResult,
        ArgsAsString) (
                LXtObjectID              self,
                LXtObjectID              cmd,
                char                    *buffer,
                unsigned int             bufLen,
                unsigned int             includeCmd);
                LXxMETHOD(  LxResult,
        Query) (
                LXtObjectID               self,
                LXtObjectID               cmd,
                unsigned int              index,
                void                    **ppvObj);
                LXxMETHOD(  LxResult,
        QueryArgString) (
                LXtObjectID               self,
                LXtObjectID               cmd,
                unsigned int              alertFlags,
                const char               *args,
                void                    **vaQuery,
                unsigned int             *queryIndex,
                unsigned int              includesCmdName);
                LXxMETHOD(  LxResult,
        CreateQueryObject) (
                LXtObjectID               self,
                const char               *typeName,
                void                    **vaQuery);
                LXxMETHOD(  LxResult,
        AliasCreate) (
                LXtObjectID              self,
                const char              *name,
                LXtObjectID              targetCmd,
                LXtCommandTag            targetTag,
                const char              *targetName,
                const char              *args);

                LXxMETHOD(  LxResult,
        AliasDelete) (
                LXtObjectID              self,
                LXtObjectID              alias,
                LXtCommandTag            tag,
                const char              *name);
                LXxMETHOD(  LxResult,
        IsContainer) (
                LXtObjectID              self,
                LXtObjectID              cmd);
                LXxMETHOD(  LxResult,
        IsAliased) (
                LXtObjectID              self,
                LXtObjectID              cmd);
                LXxMETHOD(  LxResult,
        CommandCount) (
                LXtObjectID               self,
                unsigned int             *count);

                LXxMETHOD(  LxResult,
        CommandByIndex) (
                LXtObjectID               self,
                unsigned int              index,
                void                    **cmd);
                LXxMETHOD(  LxResult,
        ExecEntryType ) (
                LXtObjectID              self,
                int                      index,
                int                     *type);
                LXxMETHOD(  LxResult,
        ExecEntryUserName ) (
                LXtObjectID               self,
                int                       index,
                const char              **userName);
                LXxMETHOD(  LxResult,
        ExecEntryName ) (
                LXtObjectID               self,
                int                       index,
                const char              **name);
                LXxMETHOD(  LxResult,
        ExecEntryAsArgString ) (
                LXtObjectID              self,
                int                      index,
                char                    *buffer,
                int                      len);
                LXxMETHOD(  LxResult,
        IsGlobalInteractionOK) (
                LXtObjectID              self);
                LXxMETHOD(  LxResult,
        ArgsAsStringLen) (
                LXtObjectID              self,
                LXtObjectID              cmd,
                char                    *buffer,
                unsigned int             bufLen,
                unsigned int             includeCmd);
} ILxCommandService;
typedef struct vt_ILxCommandPostEnd {
        ILxUnknown       iunk;
                LXxMETHOD(  LxResult,
        End) (
                LXtObjectID              self);
} ILxCommandPostEnd;

#define LXu_COMMAND             "4F540BF1-F97E-4D46-8A5F-6B2750A6CEB9"
#define LXa_COMMAND             "command"
// [export] ILxCommand cmd
// [local]  ILxCommand

#define LXe_CMD_ALREADY_EXISTS                  LXxFAILCODE( LXeSYS_CMDS,   1)
#define LXe_CMD_MISSING_ARGS                    LXxFAILCODE( LXeSYS_CMDS,   2)
#define LXe_CMD_NOT_AVAILABLE                   LXxFAILCODE( LXeSYS_CMDS,   3)
#define LXe_CMD_DISABLED                        LXxFAILCODE( LXeSYS_CMDS,   4)
#define LXe_CMD_UNKNOWN_COMMAND                 LXxFAILCODE( LXeSYS_CMDS,   5)
#define LXe_CMD_INVALID_ON_PROTO                LXxFAILCODE( LXeSYS_CMDS,   6)
#define LXe_CMD_DIFFERENT_TYPES                 LXxFAILCODE( LXeSYS_CMDS,   7)
#define LXe_CMD_UNBALANCED_BRACES               LXxFAILCODE( LXeSYS_CMDS,   8)
#define LXe_CMD_BAD_DEFINITION                  LXxFAILCODE( LXeSYS_CMDS,   9)
#define LXe_CMD_UNKNOWN_ARGUMENT                LXxFAILCODE( LXeSYS_CMDS,  10)
#define LXe_CMD_TOO_MANY_ARGUMENTS              LXxFAILCODE( LXeSYS_CMDS,  11)
#define LXe_CMD_ARGUMENT_ALREADY_SET            LXxFAILCODE( LXeSYS_CMDS,  12)
#define LXe_CMD_ARGUMENT_NOT_QUERYABLE          LXxFAILCODE( LXeSYS_CMDS,  13)
#define LXe_CMD_NO_QUERY_MARKED                 LXxFAILCODE( LXeSYS_CMDS,  14)
#define LXe_CMD_TOO_MANY_QUERIES_MARKED         LXxFAILCODE( LXeSYS_CMDS,  15)
#define LXe_CMD_ILLEGAL_REFIRE_BEGIN            LXxFAILCODE( LXeSYS_CMDS,  16)
#define LXe_CMD_ILLEGAL_REFIRE_END              LXxFAILCODE( LXeSYS_CMDS,  17)
#define LXe_CMD_ALREADY_REFIRING                LXxFAILCODE( LXeSYS_CMDS,  18)
#define LXe_CMD_NOT_ALIASED                     LXxFAILCODE( LXeSYS_CMDS,  19)
#define LXe_CMD_ERROR_SETTING_DATATYPE          LXxFAILCODE( LXeSYS_CMDS,  20)
#define LXe_CMD_ERROR_ARG_MISSING_VALUE         LXxFAILCODE( LXeSYS_CMDS,  21)
#define LXe_CMD_SANDBOX_NOT_COMPATIBLE          LXxFAILCODE( LXeSYS_CMDS,  22)
#define LXe_CMD_SANDBOX_ONLY                    LXxFAILCODE( LXeSYS_CMDS,  23)
#define LXe_CMD_EXPECTED_OPENING_BRACE          LXxFAILCODE( LXeSYS_CMDS,  24)
#define LXe_CMD_VARIABLE_DATATYPES_SET          LXxFAILCODE( LXeSYS_CMDS,  25)
#define LXe_CMD_VARIABLE_DATATYPES_PENDING      LXxFAILCODE( LXeSYS_CMDS,  26)
#define LXe_CMD_REQUIRES_USER_INTERACTION       LXxFAILCODE( LXeSYS_CMDS,  27)
#define LXe_CMD_HAS_NO_ARGUMENTS                LXxFAILCODE( LXeSYS_CMDS,  28)
#define LXe_CMD_QUERY_MISMATCHED_DATATYPES      LXxFAILCODE( LXeSYS_CMDS,  29)

#define LXe_CMD_SANDBOX_GLOBAL                  LXxGOODCODE( LXeSYS_CMDS,   1)  // Good, not Fail
#define LXe_CMD_SANDBOXED                       LXxGOODCODE( LXeSYS_CMDS,   2)  // Good, not Fail
#define LXfCMD_SELECT                    0x00000080
#define LXfCMD_QUIET                     0x00000400
#define LXfCMD_POSTCMD                   0x00000800
#define LXfCMD_MUSTSETARG                0x00001000
#define LXfCMD_EXTRA1                    0x00002000
#define LXfCMD_EXTRA2                    0x00004000
#define LXfCMD_SELECTIONLESS             0x00008000
#define LXfCMD_INTERNAL                  0x00020000
#define LXfCMD_MOUSEDOWNOK               0x00080000

#define LXfCMD_INIT_ONLY                 0x000FFFF0     // Init only flags

#define LXfCMD_REPEAT                    0x00100000
#define LXfCMD_DEFER_INTERACTIVITY       0x00200000

#define LXfCMD_UI                        0x01000000
#define LXfCMD_MODEL                     0x02000000
#define LXfCMD_UNDO                     (LXfCMD_UNDO_INTERNAL | LXfCMD_MODEL)
#define LXfCMD_UNDO_UI                  (LXfCMD_UNDO_INTERNAL | LXfCMD_UI)
#define LXfCMD_UNDOSPECIAL               0x08000000
#define LXfCMD_SANDBOXED                 0x10000000

#define LXfCMD_TYPES                     0xFF000000     // Type flags

#define LXxCMD_IS_SIDEEFFECT(flags)     ((flags & LXfCMD_TYPES) == 0)

#define LXfCMD_UNDO_INTERNAL             0x04000000     // Used for testing for undoable commands only; do NOT set command flags with this.  Use LXfCMD_UNDO/LXfCMD_UNDO_UI to make an undoable command
#define LXfCMDHINT_SUPPRESS_INFOS       0x00000001
#define LXfCMDHINT_SUPPRESS_WARNINGS    0x00000002
#define LXfCMDHINT_SUPPRESS_ERRORS      0x00000004

#define LXmCMDHINT_SUPPRESS_DIALOGS     (LXfCMDHINT_SUPPRESS_INFOS | LXfCMDHINT_SUPPRESS_WARNINGS | LXfCMDHINT_SUPPRESS_ERRORS)
#define LXfCMD_ALERT_NONE                        0x0000

#define LXfCMD_ALERT_SHOWERR                     0x0001
#define LXfCMD_ALERT_SHOWERR_FORCESUB            0x0002
#define LXfCMD_ALERT_SHOWERR_FORCESUB_OFF        0x0004

#define LXfCMD_ALERT_SYNTAXERR                   0x0008

#define LXfCMD_ALERT_MASK                        0x00FF
#define LXiCMD_EXEC_WITH_PARENTS_FLAGS           (-1)

#define LXxCMD_EXEC_WITH_PARENTS_FLAGS( flags )  ((flags) == LXiCMD_EXEC_WITH_PARENTS_FLAGS)
#define LXfCMD_EXEC_NONE                         0x0000

#define LXfCMD_EXEC_GETARGS                      0x0100
#define LXfCMD_EXEC_GETARGS_FORCESUB             0x0200
#define LXfCMD_EXEC_GETARGS_FORCESUB_OFF         0x0400

#define LXfCMD_EXEC_ALWAYSGETARGS                0x0800

#define LXfCMD_EXEC_MASK                         0xFF00

#define LXxCMD_EXEC_MASK( flags )                ((flags) & LXfCMD_EXEC_MASK)
#define LXxCMD_IS_USER_INTERACTION_OK( flags )   ((flags & LXfCMD_EXEC_GETARGS) || (flags & LXfCMD_EXEC_ALWAYSGETARGS))
#define LXfCMD_EXEC_PARENT_FLAGS_PASSED_MARKER   0x8000

#define LXxCMD_EXEC_WERE_PARENT_FLAGS_PASSED(flags) ((flags) & LXfCMD_EXEC_PARENT_FLAGS_PASSED_MARKER)
#define LXfCMD_ALERT_DEFAULT                     (LXfCMD_ALERT_SHOWERR | LXfCMD_ALERT_SYNTAXERR)
#define LXfCMD_EXEC_DEFAULT                      (LXfCMD_ALERT_SHOWERR | LXfCMD_ALERT_SYNTAXERR | LXfCMD_EXEC_GETARGS)
#define LXfCMD_PARSED_FLAGS                      0x10000000
#define         LXfCMDARG_INIT_ONLY                      0x0FFFF
#define         LXfCMDARG_OPTIONAL                       0x00001
#define         LXfCMDARG_QUERY                          0x00002
#define         LXfCMDARG_READONLY                       0x00004
#define         LXfCMDARG_VARIABLE                       0x00008
#define         LXfCMDARG_DYNAMICHINTS                   0x00010
#define         LXfCMDARG_REQFORVARIABLE                 0x00020
#define         LXfCMDARG_HIDDEN                         0x00040
#define         LXfCMDARG_DYNAMIC_DEFAULTS               0x00080
#define         LXfCMDARG_DIALOG_ALWAYS_SETS             0x00100
#define         LXfCMDARG_CAN_QUERY_WHEN_DISABLED        0x00200
#define         LXfCMDARG_DIALOG_DIVIDER_AFTER_ARG       0x00400

#define         LXfCMDARG_STATE_ONLY                     0xF0000
#define         LXfCMDARG_VALUE_SET                      0x10000
#define         LXfCMDARG_CHANGED                        0x20000
#define         LXfCMDARG_REQFORVAR_SET                  0x40000

#define         LXxCMDARG_ISREQFORVARIABLE(f)      ((f) & LXfCMDARG_REQFORVARIABLE)
#define         LXxCMDARG_ISVARIABLE(f)            ((f) & LXfCMDARG_VARIABLE)
#define         LXxCMDARG_ISREQUIRED(f)         ( (((f) & LXfCMDARG_INIT_ONLY) == 0) || (((f) & LXfCMDARG_INIT_ONLY) == LXfCMDARG_REQFORVARIABLE) )
#define         LXxCMDARG_ISNEEDED(f)           ( !((f) & LXfCMDARG_OPTIONAL) && !((f) & LXfCMDARG_READONLY) )
#define         LXxCMDARG_ISQUERY(f)            (  ((f) & LXfCMDARG_QUERY)    ||  ((f) & LXfCMDARG_READONLY) )

#define         LXxCMDARG_ISSET(f)              ((f) & LXfCMDARG_VALUE_SET)
#define LXu_COMMANDDBHELP       "7c8a58e0-0052-4d8e-addb-7387fba9d5bf"
#define LXa_COMMANDDBHELP       "commanddbhelp"
// [local]  ILxCommandDBHelp
#define LXu_UIHINTS             "944D9CFD-DB04-4bba-B8B1-ADE424695EDC"
#define LXa_UIHINTS             "uihints"
// [local]  ILxUIHints
#define LXiBOOLEANSTYLE_DEFAULT         0
#define LXiBOOLEANSTYLE_CHECKMARK       1
#define LXiBOOLEANSTYLE_BUTTON          2
#define LXu_UIVALUEHINTS        "f37bb385-7214-42d5-9bed-552ff4738908"
#define LXa_UIVALUEHINTS        "uivaluehints"
// [local]  ILxUIValueHints
// [export] ILxUIValueHints
#define LXfVALHINT_POPUPS               0x001
#define LXfVALHINT_POPUP_DIRECT         0x002
#define LXfVALHINT_POPUP_ALPHA_SORT     0x004
#define LXfVALHINT_ITEMS                0x008
#define LXfVALHINT_ITEMS_NONE           0x010
#define LXfVALHINT_FORM_COMMAND_LIST    0x020
#define LXmPOPFLAGS_GROUP_MASK          0x00F

#define LXfPOPFLAGS_SELECTED            0x010
#define LXfPOPFLAGS_UNSELECTED          0x020
#define LXfPOPFLAGS_MIXED               0x030
#define LXfPOPFLAGS_DISABLED            0x080
#define LXu_UIVALUEHINTS1       "7BB10C3F-1FFB-4104-8FBE-CB1C334EE3C1"
// [local]  ILxUIValueHints
// [export] ILxUIValueHints
#define LXu_ATTRIBUTESUI        "44D9C65E-AE2E-4012-AB57-E2839734F7FF"
#define LXa_ATTRIBUTESUI        "attributesui"
// [local]  ILxAttributesUI
// [export] ILxAttributesUI atrui
#define LXfCMDNOTIFY_VALUE      0x01
#define LXfCMDNOTIFY_LABEL      0x02
#define LXfCMDNOTIFY_DISABLE    0x04
#define LXfCMDNOTIFY_DATATYPE   0x08

#define LXfCMDNOTIFY_CHANGE_ALL 0x0F
#define LXu_COMMANDEVENT        "F7CD29B5-6858-445b-BE6D-8347603B47E9"
#define LXa_COMMANDEVENT        "commandevent"
// [local]  ILxCommandEvent
// [export] ILxCommandEvent cevt
#define LXu_COMMANDBLOCK        "65AEBD9F-D518-47b2-8CC6-E453F8C43CB6"
#define LXa_COMMANDBLOCK        "commandblock"
#define LXu_COMMANDSERVICE      "9DB8BA65-8C36-45A7-B403-DF7BA59BA6C2"
#define LXa_COMMANDSERVICE      "commandservice"
#define LXiCMDSTATUS_INITIALIZING                       0
#define LXiCMDSTATUS_NORMAL                             1
#define LXiCMDSTATUS_EXECUTING_STARTUP_COMMANDS         2
#define LXiCMD_SEP_DOT          0
#define LXiCMD_SEP_BACKSLASH    1
#define LXiCMD_SEP_SLASH        2
#define LXiCMD_SEP_COLON        3
#define LXiCMDREFIRE_NONE               0
#define LXiCMDREFIRE_PENDING            1
#define LXiCMDREFIRE_COMMAND            2
#define LXiCMDREFIRE_BLOCK              3
#define LXu_COMMANDPOSTEND      "AEB6B7BF-34B9-4991-904C-298B8DB1AE12"
#define LXa_COMMANDPOSTEND      "commandpostmodeend"
#define LXsCMD_CONTAINER_NAME   "command.container.name"
#define LXsCMD_CONTAINER_ARGS   "command.container.args"
#define LXsCMD_CONTAINER_TYPES  "command.container.types"
#define LXfCMDBLOCK_PRESERVE_SELECTION  0x000100

#define LXfCMDBLOCK_UI                  0x010000
#define LXfCMDBLOCK_UNDO_UI             0x020000

#define LXfCMDBLOCK_SANDBOXED           0x040000

#define LXfCMDBLOCK_POSTMODE            0x100000
#define LXfCMDBLOCK_STEPUNDO            0x200000
#define LXfCMDSANDBOX_ALLOW_UI  1
#define LXiCMDENTRYTYPE_INVALID         0
#define LXiCMDENTRYTYPE_COMMAND         1
#define LXiCMDENTRYTYPE_BLOCK           2

 #ifdef __cplusplus
  }
 #endif
#endif

