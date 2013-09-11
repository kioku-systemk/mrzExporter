/*
 * LX action module
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
#ifndef LX_action_H
#define LX_action_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxActionListener ** ILxActionListenerID;
typedef struct vt_ILxChannelRead ** ILxChannelReadID;
typedef struct vt_ILxChannelWrite ** ILxChannelWriteID;
typedef struct vt_ILxEvalModifier ** ILxEvalModifierID;
typedef struct vt_ILxModifier ** ILxModifierID;
typedef struct vt_ILxSimulationModifier ** ILxSimulationModifierID;
typedef struct vt_ILxEvaluation ** ILxEvaluationID;
typedef struct vt_ILxModifier1 ** ILxModifier1ID;
#include <lxcom.h>



typedef struct vt_ILxActionListener {
        ILxUnknown       iunk;
                LXxMETHOD( void,
        ActionChannelSignal) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                 channel);

                LXxMETHOD( void,
        ActionChannelConstantChange) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                 channel);

                LXxMETHOD( void,
        ActionChannelConstantPreChange) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                 channel);
} ILxActionListener;
typedef struct vt_ILxChannelRead {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        ValueObj) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        Integer) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel,
                int                     *value);

                LXxMETHOD( LxResult,
        Double) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel,
                double                  *value);

                LXxMETHOD( LxResult,
        String) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel,
                const char             **value);

                LXxMETHOD( LxResult,
        Envelope) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel,
                void                   **ppvObj);

                LXxMETHOD( double,
        Time) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        IsAnimated) (
                LXtObjectID              self,
                LXtObjectID              item,
                int                      index);
                LXxMETHOD( LxResult,
        IsBaked) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel);

                LXxMETHOD( LxResult,
        BakedSamples) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel,
                double                  *firstSample,
                double                  *spsRate,
                void                   **ppvObj);
} ILxChannelRead;
typedef struct vt_ILxChannelWrite {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        ValueObj) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        Integer) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel,
                int                      value);

                LXxMETHOD( LxResult,
        Double) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel,
                double                   value);

                LXxMETHOD( LxResult,
        String) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel,
                const char              *value);

                LXxMETHOD( LxResult,
        Envelope) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        IntegerKey) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel,
                int                      value,
                int                      create);

                LXxMETHOD( LxResult,
        DoubleKey) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel,
                double                   value,
                int                      create);

                LXxMETHOD( LxResult,
        SetState) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel,
                unsigned int             state);
                LXxMETHOD( LxResult,
        BakeSamples) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned int             channel,
                double                   firstSample,
                double                   spsRate,
                void                   **ppvObj);
} ILxChannelWrite;
typedef struct vt_ILxEvalModifier {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Reset) (
                LXtObjectID              self,
                LXtObjectID              scene);

                LXxMETHOD( LXtObjectID,
        Next) (
                LXtObjectID              self,
                unsigned                *index);

                LXxMETHOD( LxResult,
        Alloc) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                 index,
                LXtObjectID              eval,
                void                   **ppvObj);
} ILxEvalModifier;
typedef struct vt_ILxModifier {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Evaluate) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Test) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                 index);

                LXxMETHOD( LxResult,
        Invalidate) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                 index);

                LXxMETHOD( LxResult,
        Validate) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                 index,
                LxResult                 rc);

                LXxMETHOD( unsigned,
        RequiredCount) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Required) (
                LXtObjectID              self,
                unsigned                 index,
                unsigned                *attr,
                void                   **ppvObj);

                LXxMETHOD( void,
        Free) (
                LXtObjectID              self,
                void                    *cache);
} ILxModifier;
typedef struct vt_ILxSimulationModifier {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Initialize) (
                LXtObjectID              self,
                double                   time,
                double                   sample);

                LXxMETHOD( void,
        Cleanup) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        StepSize) (
                LXtObjectID              self,
                double                  *stepSize);

                LXxMETHOD( LxResult,
        Step) (
                LXtObjectID              self,
                double                   dt);
} ILxSimulationModifier;
typedef struct vt_ILxEvaluation {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        AddChannel) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                 index,
                unsigned                 type,
                unsigned                *attr);

                LXxMETHOD( LxResult,
        AddChannelName) (
                LXtObjectID              self,
                LXtObjectID              item,
                const char              *name,
                unsigned                 type,
                unsigned                *attr);

                LXxMETHOD( LxResult,
        ReadTime) (
                LXtObjectID              self,
                unsigned                *attr);
                LXxMETHOD( LxResult,
        SetAlternateTime) (
                LXtObjectID              self,
                double                   time);

                LXxMETHOD( LxResult,
        SetAlternate) (
                LXtObjectID              self,
                void                   **ppvObj);

                LXxMETHOD( LxResult,
        ClearAlternate) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        SetCache) (
                LXtObjectID              self,
                void                    *cache);

                LXxMETHOD( void *,
        GetCache) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        SetAlternateSetup) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        GetBakedSample) (
                LXtObjectID              self,
                unsigned                 index,
                unsigned                 bracket,
                double                  *fraction,
                void                   **ppvObj);
} ILxEvaluation;
typedef struct vt_ILxModifier1 {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Evaluate) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Test) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                 index);

                LXxMETHOD( LxResult,
        Invalidate) (
                LXtObjectID              self,
                LXtObjectID              item,
                unsigned                 index);

                LXxMETHOD( unsigned,
        RequiredCount) (
                LXtObjectID              self);

                LXxMETHOD( LxResult,
        Required) (
                LXtObjectID              self,
                unsigned                 index,
                unsigned                *attr,
                void                   **ppvObj);

                LXxMETHOD( void,
        Free) (
                LXtObjectID              self,
                void                    *cache);
} ILxModifier1;

#define LXu_ACTIONLISTENER      "4819A297-A922-11D8-B1AD-000393CE9680"
#define LXu_CHANNELREAD         "D5A8C4FD-151C-4D8B-97E1-6E1B4087886B"
// [local]   ILxChannelRead
// [default] ILxChannelRead:IsBaked = LXe_FALSE
// [const]   ILxChannelRead:IsAnimated
// [const]   ILxChannelRead:IsBaked
#define LXu_CHANNELWRITE        "91BFE3B8-16C6-4195-BFE5-3F0E3C0C5C57"
// [local]  ILxChannelWrite
#define LXs_ACTIONLAYER_SETUP   "setup"
#define LXs_ACTIONLAYER_ANIM    "scene"
#define LXs_ACTIONLAYER_EDIT    "edit"
#define LXu_EVALMODIFIER        "30AAAF24-9699-4737-8E3B-E264AA4B7A3E"
#define LXa_EVALMODIFIER        "evalModifier"
// [export]  ILxEvalModifier eval
// [default] ILxEvalModifier:Next = 0
#define LXsMOD_TYPELIST         "modifier.typeList"
#define LXsMOD_GRAPHLIST        "modifier.graphList"
#define LXsMOD_GUIDLIST         "modifier.guidList"
#define LXsMOD_REQUIREDTYPE     "modifier.required"
#define LXeEVAL_IDENTICAL       LXxGOODCODE(LXeSYS_EVAL,1)
#define LXeEVAL_DIFFERENT       LXe_OK
#define LXu_MODIFIER            "8D3BEC86-E10B-426A-8BA3-846250E25AF4"
// [local]   ILxModifier
// [export]  ILxModifier mod
// [default] ILxModifier:RequiredCount = 0
// [default] ILxModifier:Test = LXe_TRUE
#define LXu_SIMULATIONMODIFIER          "A44F37F3-E94F-4042-85E2-1BBF633E00D2"
// [export]  ILxSimulationModifier sim
#define LXfECHAN_READ            0x01
#define LXfECHAN_WRITE           0x02
#define LXfECHAN_SETUP           0x04

#define LXu_EVALUATION          "FB552E5F-746E-4d74-885C-40A931B82B84"
// [local]   ILxEvaluation
// [default] ILxEvaluation:GetCache = 0
#define LXu_MODIFIER1           "FA406E1C-5E6A-4574-A795-AA0F07DFAFB5"

 #ifdef __cplusplus
  }
 #endif
#endif

