/*
 * LX media module
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
#ifndef LX_media_H
#define LX_media_H
 #ifdef __cplusplus
  extern "C" {
 #endif


typedef struct vt_ILxAudioLoaderTarget ** ILxAudioLoaderTargetID;
typedef struct vt_ILxAudio ** ILxAudioID;
typedef struct vt_ILxAudioWrite ** ILxAudioWriteID;
typedef struct vt_ILxAudioDevice ** ILxAudioDeviceID;
typedef struct vt_ILxAudioHandle ** ILxAudioHandleID;
#include <lxcom.h>
#include <lxio.h>
#include <lxserver.h>
#include <lxvmath.h>

typedef unsigned int     LXtAudioState;
#define LXaSTATE_STOPPED                 0
#define LXaSTATE_PLAYING                 1
#define LXaSTATE_PAUSED                  2
#define LXaSTATE_INITIAL                 3
typedef struct st_LXtAudioMetrics {
        unsigned int             channels;              // 1: mono, 2: stereo
        unsigned int             type;                  // bits per smaple. 8, 16 or 32 bits
        unsigned int             frequency;             // sample per second (sample rate)
        unsigned int             samples;               // total samples
        const char              *filename;              // filename
} LXtAudioMetrics;
typedef struct st_AudioTargetData {
        unsigned int             channels;
        unsigned int             type;
        unsigned int             frequency;
        unsigned int             samples;
} AudioTargetData;
typedef struct vt_ILxAudioLoaderTarget {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        SetChannels) (
                LXtObjectID              self,
                unsigned                 channels);

                LXxMETHOD( LxResult,
        SetType) (
                LXtObjectID              self,
                unsigned                 type);

                LXxMETHOD( LxResult,
        SetFrequency) (
                LXtObjectID              self,
                unsigned                 frequency);

                LXxMETHOD( LxResult,
        SetSamples) (
                LXtObjectID              self,
                unsigned                 samples);
} ILxAudioLoaderTarget;
typedef struct vt_ILxAudio {
        ILxUnknown       iunk;
                LXxMETHOD( unsigned int,
        Channels) (
                LXtObjectID              self);
                LXxMETHOD( unsigned int,
        Type) (
                LXtObjectID              self);
                LXxMETHOD( unsigned int,
        Frequency) (
                LXtObjectID              self);
                LXxMETHOD( double,
        TrimStart) (
                LXtObjectID              self);
                LXxMETHOD( double,
        Duration) (
                LXtObjectID              self);
                LXxMETHOD( const char *,
        Filename) (
                LXtObjectID              self);
                LXxMETHOD( unsigned int,
        Size) (
                LXtObjectID              self);
                LXxMETHOD( const void *,
        Data) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Sample) (
                LXtObjectID              self,
                double                   time,
                unsigned int             type,
                void                    *value);
                LXxMETHOD( void,
        Seek) (
                LXtObjectID              self,
                unsigned int             frame);
                LXxMETHOD( unsigned int,
        Tell) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Read) (
                LXtObjectID              self,
                unsigned int            *frames,
                void                    *buff,
                int                     *eof);
                LXxMETHOD( void,
        Metrics) (
                LXtObjectID              self,
                LXtAudioMetrics         *metrics);
} ILxAudio;
typedef struct vt_ILxAudioWrite {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        WriteBegin) (
                LXtObjectID              self,
                LXtAudioMetrics         *metrics,
                unsigned int            *frameRange);
                LXxMETHOD( LxResult,
        Write) (
                LXtObjectID              self,
                unsigned int            *frames,
                const void              *data);
                LXxMETHOD( LxResult,
        WriteEnd) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        SetSample) (
                LXtObjectID              self,
                double                   time,
                unsigned int             type,
                const void              *value);
                LXxMETHOD( LxResult,
        SetStart) (
                LXtObjectID              self,
                double                   start);
                LXxMETHOD( LxResult,
        SetDuration) (
                LXtObjectID              self,
                double                   duration);
} ILxAudioWrite;
typedef struct vt_ILxAudioDevice {
        ILxUnknown       iunk;
                LXxMETHOD( LxResult,
        Handle) (
                LXtObjectID              self,
                LXtObjectID              audio,
                void                    **ppvObj);
                LXxMETHOD( LxResult,
        StopAll) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        PlayFile) (
                LXtObjectID              self,
                const char              *filePath);
                LXxMETHOD( int,
        Playing) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        PlayRange) (
                LXtObjectID              self,
                LXtObjectID              audio,
                double                   start,
                double                   end,
                double                   volume,
                double                   pitch);
} ILxAudioDevice;
typedef struct vt_ILxAudioHandle {
        ILxUnknown       iunk;
                LXxMETHOD( LXtObjectID,
        Audio) (
                LXtObjectID              self);
                LXxMETHOD( double,
        Offset) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        SetOffset) (
                LXtObjectID              self,
                double                   offset);
                LXxMETHOD( double,
        Pitch) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        SetPitch) (
                LXtObjectID              self,
                double                   pitch);
                LXxMETHOD( double,
        Volume) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        SetVolume) (
                LXtObjectID              self,
                double                   volume);
                LXxMETHOD( LxResult,
        Loop) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        SetLoop) (
                LXtObjectID              self,
                unsigned int             loop);
                LXxMETHOD( LxResult,
        Play) (
                LXtObjectID              self,
                int                      forward);
                LXxMETHOD( LxResult,
        Stop) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Pause) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        Resume) (
                LXtObjectID              self);
                LXxMETHOD( LxResult,
        State) (
                LXtObjectID              self,
                LXtAudioState           *state);
} ILxAudioHandle;

#define LXiAUDIO_CHAN_MONO      1
#define LXiAUDIO_CHAN_STEREO    2
#define LXiAUDIO_TYPE_U8        8
#define LXiAUDIO_TYPE_I16       16
#define LXiAUDIO_TYPE_F32       32
#define LXu_AUDIOLOADERTARGET   "EDD92652-76A0-471B-B02C-F47CCC16A860"
// [local]  ILxAudioLoaderTarget
#define LXu_AUDIO       "ABADACB8-A93D-45B1-B776-347CBE761B13"
#define LXa_AUDIO       "audio"
//[local]  ILxAudio
//[export] ILxAudio audio
//[python] ILxAudio:Sample:value        vector
//[python] ILxAudio:Read:buff           vector
#define LXu_AUDIOWRITE  "B1C160A8-6FF3-4C54-B817-8C17A49AB1D6"
#define LXa_AUDIOWRITE  "audiowrite"
//[local]  ILxAudioWrite
//[export] ILxAudioWrite audiow
#define LXu_AUDIODEVICE "5CBC3BC8-95BB-4F24-B1A4-8474708EDE3A"
#define LXa_AUDIODEVICE "audioDevice"
//[local]  ILxAudioDevice
//[python] ILxAudioDevice:Handle        obj AudioHandle
#define LXu_AUDIOHANDLE "6A7F9318-A9CF-44CA-9F71-32006102FF24"
#define LXa_AUDIOHANDLE "audioHandle"
//[local]  ILxAudioHandle

 #ifdef __cplusplus
  }
 #endif
#endif

