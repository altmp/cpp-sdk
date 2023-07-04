#pragma once

#include "../objects/IBaseObject.h"

namespace alt
{
	class IAudio;
	class IAudioOutput : public virtual IBaseObject
	{
	public:
		virtual void SetVolume(float vol) = 0;
		virtual float GetVolume() const = 0;

		virtual void SetMuted(bool toggle) = 0;
		virtual bool IsMuted() const = 0;

		virtual void SetCategory(uint32_t cat) = 0;
		virtual uint32_t GetCategory() const = 0;

		virtual IAudio* GetOwner() const = 0;
	};
}