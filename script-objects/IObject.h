#pragma once

#include "../objects/IEntity.h"

namespace alt
{
	class IObject : public virtual IEntity
	{
	public:
		virtual uint8_t GetAlpha() const = 0;
		virtual void SetAlpha(uint8_t alpha) = 0;
		virtual void ResetAlpha() = 0;

		virtual void SetDynamic(bool dynamic) = 0;

		virtual uint16_t GetLodDistance() const = 0;
		virtual void SetLodDistance(uint16_t distance) = 0;

		virtual void ToggleGravity(bool toggle) = 0;

		virtual bool IsOnFire() const = 0;
		virtual uint32_t StartFire() = 0;
		virtual void StopFire() = 0;

#ifdef ALT_CLIENT_API
		virtual bool IsRemote() const = 0;
#endif

		const std::type_info& GetTypeInfo() const override { return typeid(this); }
	};
}
