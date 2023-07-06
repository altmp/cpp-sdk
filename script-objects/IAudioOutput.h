#pragma once

#include "../objects/IBaseObject.h"

namespace alt
{
	class IAudio;
	class IAudioFilter;
	class IAudioOutput : public virtual IBaseObject
	{
	public:
		virtual void SetVolume(float vol) = 0;
		virtual float GetVolume() const = 0;

		virtual void SetMuted(bool toggle) = 0;
		virtual bool IsMuted() const = 0;
		
		virtual uint32_t GetCategory() const = 0;

		virtual IAudio* GetOwner() const = 0;

		virtual void AddFilter(IAudioFilter* filter) = 0;
		virtual void RemoveFilter() = 0;
		virtual IAudioFilter* GetFilter() const = 0;
	};
}