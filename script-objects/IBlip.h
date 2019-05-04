#pragma once

#include <cstdint>

#include "../IWorldObject.h"

namespace alt
{
	class IEntity;
	class IPlayer;

	class IBlip : public virtual IWorldObject
	{
	public:
		enum class Type
		{
			VEHICLE = 1,
			PED = 2,
			OBJECT = 3,
			DESTINATION = 4,
			CONT = 5,
			PICKUP_UNK = 6,
			RADIUS = 7,
			PICKUP = 8,
			COP = 9,
			AREA = 11,
			GALLERY = 12,
			PICKUP_OBJECT = 13
		};

		virtual bool IsGlobal() const = 0;
		virtual IPlayer* GetTarget() const = 0;

		virtual bool IsAttached() const = 0;
		virtual IEntity* AttachedTo() const = 0;
		virtual Type GetBlipType() const = 0;

		virtual void SetSprite(uint16_t sprite) = 0;
		virtual void SetColor(uint8_t color) = 0;
		virtual void SetRoute(bool state) = 0;
		virtual void SetRouteColor(uint8_t color) = 0;

	protected:
		virtual ~IBlip() = default;
	};
}
