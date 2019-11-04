#pragma once

#include "types/StringView.h"
#include "types/MValue.h"
#include "Ref.h"

namespace alt
{
	class IBaseObject : public virtual CRefCountable
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

		virtual ~IBaseObject() = default;

		virtual Type GetType() const = 0;

		virtual bool IsDeleted() const = 0;

		virtual MValueConst GetMetaData(StringView key) const = 0;
		virtual void SetMetaData(StringView key, MValue val) = 0;
	};
}
