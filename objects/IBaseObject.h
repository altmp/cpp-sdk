#pragma once

#include "../types/MValue.h"
#include "../Ref.h"

namespace alt
{
	class IBaseObject : public virtual CRefCountable
	{
	protected:
		virtual ~IBaseObject() = default;

	public:
		enum class Type : uint8_t
		{
			PLAYER,
			VEHICLE,
			BLIP,
			WEBVIEW,
			VOICE_CHANNEL,
			COLSHAPE,
			CHECKPOINT,
			WEBSOCKET_CLIENT,
			HTTP_CLIENT,
			AUDIO,
			RML_ELEMENT,
			RML_DOCUMENT,
			LOCAL_PLAYER
		};

		virtual Type GetType() const = 0;

		virtual bool HasMetaData(const std::string& key) const = 0;
		virtual MValueConst GetMetaData(const std::string& key) const = 0;
		virtual void SetMetaData(const std::string& key, MValue val) = 0;
		virtual void DeleteMetaData(const std::string& key) = 0;
	};
} // namespace alt
