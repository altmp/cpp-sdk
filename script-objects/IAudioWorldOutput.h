#pragma once

#include "IAudioOutput.h"

namespace alt
{
	class IAudioWorldOutput : public virtual IAudioOutput
	{
	public:
		virtual void SetPosition(alt::Position pos) = 0;
		virtual alt::Position GetPosition() const = 0;
	};
}