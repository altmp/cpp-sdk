#pragma once

#include "../objects/IBaseObject.h"

namespace alt
{
    class IAudioCategory
    {
    public:
        virtual ~IAudioCategory() = default;

        virtual std::string GetName() const = 0;

        virtual float GetVolume() const = 0;
        virtual float GetDistanceRolloffScale() const = 0;
        virtual float GetPlateauRolloffScale() const = 0;
        virtual float GetOcclusionDamping() const = 0;
        virtual float GetEnvironmentalFilterDamping() const = 0;
        virtual float GetSourceReverbDamping() const = 0;
        virtual float GetDistanceReverbDamping() const = 0;
        virtual float GetInteriorReverbDamping() const = 0;
        virtual float GetEnvironmentalLoudness() const = 0;
        virtual float GetUnderwaterWetLevel() const = 0;
        virtual float GetStonedWetLevel() const = 0;
        virtual int16_t GetPitch() const = 0;
        virtual int16_t GetLowPassFilterCutoff() const = 0;
        virtual int16_t GetHighPassFilterCutoff() const = 0;

        virtual void SetVolume(float value) = 0;
        virtual void SetDistanceRolloffScale(float value) = 0;
        virtual void SetPlateauRolloffScale(float value) = 0;
        virtual void SetOcclusionDamping(float value) = 0;
        virtual void SetEnvironmentalFilterDamping(float value) = 0;
        virtual void SetSourceReverbDamping(float value) = 0;
        virtual void SetDistanceReverbDamping(float value) = 0;
        virtual void SetInteriorReverbDamping(float value) = 0;
        virtual void SetEnvironmentalLoudness(float value) = 0;
        virtual void SetUnderwaterWetLevel(float value) = 0;
        virtual void SetStonedWetLevel(float value) = 0;
        virtual void SetPitch(int16_t value) = 0;
        virtual void SetLowPassFilterCutoff(int16_t value) = 0;
        virtual void SetHighPassFilterCutoff(int16_t value) = 0;

        virtual void Reset() = 0;
    };
}