#pragma once

#include "IAudioOutput.h"

namespace alt
{
	class IAudioAttachedOutput : public virtual IAudioOutput
	{
	public:
		virtual void SetEntity(IWorldObject* entity) = 0;
		virtual IWorldObject* GetEntity() const = 0;
	};
}