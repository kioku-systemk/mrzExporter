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
#ifndef LXUSER_action_HPP
#define LXUSER_action_HPP

#include <lxw_action.hpp>
#include <lx_item.hpp>
#include <lxw_envelope.hpp>
#include <lx_value.hpp>
#include <string>

class CLxUser_ChannelRead : public CLxLoc_ChannelRead
{
    public:
        CLxUser_ChannelRead () {}
        CLxUser_ChannelRead (ILxUnknownID obj) : CLxLoc_ChannelRead (obj) {}

                int
        IValue (
                ILxUnknownID             item,
                unsigned                 channel)
        {
                int                      value = 0;

                Integer (item, channel, &value);
                return value;
        }

                bool
        Encoded (
                CLxLoc_Item             &item,
                unsigned                 channel,
                std::string             &result)
        {
                CLxUser_ValueService     valueSvc;
                const LXtTextValueHint  *hints;
                int                      value;

                return (    LXx_OK (Integer (item, channel, &value))
                        &&  LXx_OK (item.ChannelIntHint (channel, &hints))
                        &&  valueSvc.EncodeHint (value, hints, result) );
        }

                double
        FValue (
                ILxUnknownID             item,
                unsigned                 channel)
        {
                double                   value = 0.0;

                Double (item, channel, &value);
                return value;
        }

                bool
        GetString (
                ILxUnknownID             item,
                unsigned                 channel,
                std::string             &result)
        {
                const char              *str;

                if (LXx_FAIL (String (item, channel, &str)))
                        return false;

                result = str;
                return true;
        }

                bool
        Object (
                ILxUnknownID             item,
                unsigned                 channel,
                CLxLocalizedObject      &loc)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (ValueObj (item, channel, &obj)))
                        return false;

                return loc.take (obj);
        }

                bool
        GetEnv (
                ILxUnknownID             item,
                unsigned                 channel,
                CLxLoc_Envelope         &env)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (Envelope (item, channel, &obj)))
                        return false;

                return env.take (obj);
        }

                bool
        GetBake (
                ILxUnknownID             item,
                unsigned                 channel,
                double                  *firstSample,
                double                  *spsRate,
                CLxLoc_ValueArray       &array)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (BakedSamples (item, channel, firstSample, spsRate, &obj)))
                        return false;

                return array.take (obj);
        }
                int
        IValue (
                CLxLoc_Item             &item,
                const char              *channel)
        {
                unsigned int             index;

                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return 0;

                return IValue (item, index);
        }

                bool
        Encoded (
                CLxLoc_Item             &item,
                const char              *channel,
                std::string             &result)
        {
                unsigned int             index;

                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;

                return Encoded (item, index, result);
        }

                double
        FValue (
                CLxLoc_Item             &item,
                const char              *channel)
        {
                unsigned int             index;

                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return 0.0;

                return FValue (item, index);
        }

                double
        GetString (
                CLxLoc_Item             &item,
                const char              *channel,
                std::string             &result)
        {
                unsigned int             index;

                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return 0.0;

                return GetString (item, index, result);
        }

                bool
        Object (
                const CLxUser_Item      &item,
                const char              *channel,
                CLxLocalizedObject      &loc)
        {
                unsigned int             index;

                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;

                return Object (reinterpret_cast<ILxUnknownID>(item.m_loc), index, loc);
        }

                bool
        GetEnv (
                CLxLoc_Item             &item,
                const char              *channel,
                CLxLoc_Envelope         &env)
        {
                unsigned int             index;

                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;

                return GetEnv (item, index, env);
        }
                bool
        from (
                CLxLoc_Scene            &scene)
        {
                LXtObjectID              obj;

                return LXx_OK (scene.Channels (LXs_ACTIONLAYER_EDIT, 0.0, &obj))
                   &&  take (obj);
        }

                bool
        from (
                CLxLoc_Scene            &scene,
                double                   time)
        {
                LXtObjectID              obj;

                return LXx_OK (scene.Channels (0, time, &obj))
                   &&  take (obj);
        }

                bool
        from (
                CLxLoc_Item             &item)
        {
                LXtObjectID              obj;
                CLxLoc_Scene             scene;

                return LXx_OK (item.Context (&obj))
                   &&  scene.take (obj)
                   &&  from (scene);
        }

                bool
        from (
                CLxLoc_Item             &item,
                double                   time)
        {
                LXtObjectID              obj;
                CLxLoc_Scene             scene;

                return LXx_OK (item.Context (&obj))
                   &&  scene.take (obj)
                   &&  from (scene, time);
        }
};
class CLxUser_ChannelWrite : public CLxLoc_ChannelWrite
{
    public:
        CLxUser_ChannelWrite () {}
        CLxUser_ChannelWrite (ILxUnknownID obj) : CLxLoc_ChannelWrite (obj) {}

                bool
        Set (
                ILxUnknownID             item,
                unsigned                 channel,
                int                      value)
        {
                return LXx_OK (Integer (item, channel, value));
        }

                bool
        SetEncoded (
                ILxUnknownID             item,
                unsigned                 channel,
                const char              *encoded)
        {
                CLxLoc_Item              user (item);
                CLxLoc_ValueService      valueSvc;
                const LXtTextValueHint  *hints;
                int                      value;

                if (  LXx_FAIL (user.ChannelIntHint (channel, &hints))
                  ||  LXx_FAIL (valueSvc.TextHintDecode (encoded, hints, &value)) )
                        return false;

                return LXx_OK (Integer (item, channel, value));
        }

                bool
        Set (
                ILxUnknownID             item,
                unsigned                 channel,
                double                   value)
        {
                return LXx_OK (Double (item, channel, value));
        }

                bool
        Set (
                ILxUnknownID             item,
                unsigned                 channel,
                const char              *value)
        {
                return LXx_OK (String (item, channel, value));
        }

                bool
        Object (
                ILxUnknownID             item,
                unsigned                 channel,
                CLxLocalizedObject      &loc)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (ValueObj (item, channel, &obj)))
                        return false;

                return loc.take (obj);
        }

                bool
        AddEnv (
                ILxUnknownID             item,
                unsigned                 channel,
                CLxLoc_Envelope         &env)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (Envelope (item, channel, &obj)))
                        return false;

                return env.take (obj);
        }

                bool
        WriteBake (
                ILxUnknownID             item,
                unsigned                 channel,
                double                   firstSample,
                double                   spsRate,
                CLxLoc_ValueArray       &array)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (BakeSamples (item, channel, firstSample, spsRate, &obj)))
                        return false;

                return array.take (obj);
        }
                bool
        Set (
                CLxLoc_Item             &item,
                const char              *channel,
                int                      value)
        {
                unsigned int             index;

                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;

                return Set (item, index, value);
        }

                bool
        SetEncoded (
                CLxLoc_Item             &item,
                const char              *channel,
                const char              *encoded)
        {
                unsigned int             index;

                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;

                return SetEncoded (item, index, encoded);
        }

                bool
        Set (
                CLxLoc_Item             &item,
                const char              *channel,
                double                   value)
        {
                unsigned int             index;

                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;

                return Set (item, index, value);
        }

                bool
        Set (
                CLxLoc_Item             &item,
                const char              *channel,
                const char              *value)
        {
                unsigned int             index;

                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;

                return Set (item, index, value);
        }

                bool
        Object (
                CLxLoc_Item             &item,
                const char              *channel,
                CLxLocalizedObject      &loc)
        {
                unsigned int             index;

                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;

                return Object (item, index, loc);
        }

                bool
        AddEnv (
                CLxLoc_Item             &item,
                const char              *channel,
                CLxLoc_Envelope         &env)
        {
                unsigned int             index;

                if (LXx_FAIL (item.ChannelLookup (channel, &index)))
                        return false;

                return AddEnv (item, index, env);
        }
                bool
        from (
                CLxLoc_Scene            &scene,
                double                   time = 0.0)
        {
                LXtObjectID              obj;

                return LXx_OK (scene.Channels (LXs_ACTIONLAYER_EDIT, time, &obj))
                   &&  take (obj);
        }

                bool
        from (
                CLxLoc_Item             &item,
                double                   time = 0.0)
        {
                LXtObjectID              obj;
                CLxLoc_Scene             scene;

                return LXx_OK (item.Context (&obj))
                   &&  scene.take (obj)
                   &&  from (scene, time);
        }

                bool
        setupFrom (
                CLxLoc_Scene            &scene)
        {
                LXtObjectID              obj;

                return LXx_OK (scene.Channels (LXs_ACTIONLAYER_SETUP, 0.0, &obj))
                   &&  take (obj);
        }

                bool
        setupFrom (
                CLxLoc_Item             &item)
        {
                LXtObjectID              obj;
                CLxLoc_Scene             scene;

                return LXx_OK (item.Context (&obj))
                   &&  scene.take (obj)
                   &&  setupFrom (scene);
        }
};
class CLxUser_Modifier : public CLxLoc_Modifier
{
    public:
        CLxUser_Modifier () {}
        CLxUser_Modifier (ILxUnknownID obj) : CLxLoc_Modifier (obj) {}


};
class CLxUser_Evaluation : public CLxLoc_Evaluation
{
    public:
        CLxUser_Evaluation () {}
        CLxUser_Evaluation (ILxUnknownID obj) : CLxLoc_Evaluation (obj) {}

                unsigned
        AddChan (
                ILxUnknownID             item,
                unsigned                 index,
                unsigned                 type = LXfECHAN_READ)
        {
                LxResult                 rc;
                unsigned                 idx;

                rc = AddChannel (item, index, type, &idx);
                if (LXx_FAIL (rc))
                        throw (rc);

                return idx;
        }

                unsigned
        AddChan (
                ILxUnknownID             item,
                const char              *name,
                unsigned                 type = LXfECHAN_READ)
        {
                LxResult                 rc;
                unsigned                 idx;

                rc = AddChannelName (item, name, type, &idx);
                if (LXx_FAIL (rc))
                        throw (rc);

                return idx;
        }

                unsigned
        AddTime ()
        {
                LxResult                 rc;
                unsigned                 idx;

                rc = ReadTime (&idx);
                if (LXx_FAIL (rc))
                        throw (rc);

                return idx;
        }
                bool
        Alternate (
                CLxLoc_ChannelWrite     &cw)
        {
                LXtObjectID              obj;

                if (LXx_FAIL (SetAlternate (&obj)))
                        return false;

                return cw.take (obj);
        }
                double
        GetBaked (
                unsigned                 index,
                bool                     after,
                CLxLocalizedObject      &loc)
        {
                LXtObjectID              obj;
                double                   f;

                if (LXx_FAIL (GetBakedSample (index, (after ? 1 : 0), &f, &obj)))
                        return -1.0;

                return (loc.take (obj) ? f : -1.0);
        }
};




#endif

