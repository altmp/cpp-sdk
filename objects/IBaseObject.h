#pragma once

#include "../types/MValue.h"

namespace alt
{
	class IBaseObject: public std::enable_shared_from_this<IBaseObject>
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
			LOCAL_PLAYER,
			OBJECT
		};

		virtual Type GetType() const = 0;

		virtual bool HasMetaData(const std::string& key) const = 0;
		virtual MValueConst GetMetaData(const std::string& key) const = 0;
		virtual void SetMetaData(const std::string& key, MValue val) = 0;
		virtual void DeleteMetaData(const std::string& key) = 0;

		template <typename Derived>
		std::shared_ptr<Derived> SharedAs()
		{
			return std::dynamic_pointer_cast<Derived>(shared_from_this());
		}
	};
} // namespace alt
