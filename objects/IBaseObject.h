#pragma once

#include "../types/MValue.h"
#include <vector>

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
			PED,
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
			OBJECT,
			PED,
			VIRTUAL_ENTITY,
			MARKER,
			TEXT_LABEL,
			PICKUP,
		};

		virtual Type GetType() const = 0;

		virtual bool HasMetaData(const std::string& key) const = 0;
		virtual MValueConst GetMetaData(const std::string& key) const = 0;
		virtual void SetMetaData(const std::string& key, MValue val) = 0;
		virtual void DeleteMetaData(const std::string& key) = 0;
		virtual std::vector<std::string> GetMetaDataKeys() const = 0;

		virtual bool IsRemoved() const = 0;

		template <typename Derived>
		std::shared_ptr<Derived> SharedAs()
		{
			try
			{
				Derived* derived = dynamic_cast<Derived*>(this);
				if (!derived)
				{
					static std::shared_ptr<Derived> empty;
					return empty;
				}
				std::shared_ptr<IBaseObject> shared = derived->shared_from_this();
				return std::dynamic_pointer_cast<Derived>(shared);
			}
			catch (std::bad_weak_ptr&)
			{
				static std::shared_ptr<Derived> empty;
				return empty;
			}
		}

        template <typename Derived>
        Derived* As()
        {
            return dynamic_cast<Derived*>(this);
        }
	};
} // namespace alt
