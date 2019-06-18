#pragma once

#include "types/StringView.h"
#include "types/MValue.h"

namespace alt
{
	class IBaseObject
	{
	public:
		enum class Type : uint8_t
		{
			PLAYER,
			VEHICLE,
			CHECKPOINT,
			BLIP,
			WEBVIEW,
			VOICE_CHANNEL,
			COLSHAPE
		};

		virtual Type GetType() const = 0;

		virtual MValue GetMetaData(StringView key) const = 0;
		virtual void SetMetaData(StringView key, MValue val) = 0;

	protected:
		virtual ~IBaseObject() = default;
	};
}
