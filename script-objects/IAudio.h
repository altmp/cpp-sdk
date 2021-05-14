#pragma once

#include "../objects/IBaseObject.h"
#include "../objects/IEntity.h"

namespace alt
{
    class IAudio : public virtual IBaseObject
    {
    public:
        virtual ~IAudio() = default;

        virtual void SetSource(StringView source) = 0; //data/file/url
        virtual StringView GetSource() const = 0;

        virtual void SetLoop(bool toggle) = 0;
        virtual void SetVolume(float volume) = 0;  //0.0 - 1.0 range
        virtual void SetCategory(StringView category) = 0; //default: radio

        virtual bool IsLoop() const = 0;
        virtual float GetVolume() const = 0;
        virtual StringView GetCategory() const = 0;

        virtual void SetFrontendPlay(bool toggle) = 0;
        virtual bool IsFrontendPlay() const = 0;

        virtual void AddOutput(alt::Ref<alt::IEntity> entity) = 0;
        virtual void AddOutput(uint32_t scriptID) = 0;
        virtual void RemoveOutput(alt::Ref<alt::IEntity> entity) = 0;
        virtual void RemoveOutput(uint32_t scriptID) = 0;
        virtual MValueList GetOutputs() = 0;

        virtual void Play() = 0;
        virtual void Pause() = 0;
        virtual void Reset() = 0;
        virtual double GetCurrentTime() const = 0; //seconds
        virtual double GetMaxTime() const = 0; //seconds
        virtual void Seek(double time) = 0; //seconds
        virtual bool IsPlaying() const = 0;

        const std::type_info& GetTypeInfo() const override { return typeid(this); }
    };
}