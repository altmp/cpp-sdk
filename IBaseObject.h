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
			PLAYER = 0,
			VEHICLE = 1,
			CHECKPOINT = 2,
			BLIP = 3,
			WEBVIEW = 4
		};

		virtual Type GetType() const = 0;

		virtual MValue GetMetaData(StringView key) const = 0;
		virtual void SetMetaData(StringView key, MValue val) = 0;

	protected:
		virtual ~IBaseObject() = default;
	};
}
