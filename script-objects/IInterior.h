#pragma once
#include <cstdint>

#include "../types/AABB.h"
//#ifdef ALT_CLIENT_API

namespace alt
{
	class IInteriorRoom;
	class IInteriorPortal;

	class IInterior
	{
	protected:
		virtual ~IInterior() = default;

	public:
		virtual std::shared_ptr<alt::IInteriorRoom> GetRoomByHash(uint32_t hash) const = 0;
		virtual std::shared_ptr<alt::IInteriorRoom> GetRoomByIndex(uint32_t roomIndex) const = 0;		
		virtual std::shared_ptr<alt::IInteriorPortal> GetPortalByIndex(uint32_t portalIndex) const = 0;

		virtual uint16_t GetRoomCount() const = 0;
		virtual uint16_t GetPortalCount() const = 0;
		virtual alt::Position GetPosition() const = 0;
		virtual alt::Rotation GetRotation() const = 0;
		virtual alt::AABB GetEntitiesExtents() const = 0;
	};
}
//##endif