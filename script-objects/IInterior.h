#pragma once
#include <cstdint>
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
		struct ExtentInfo
		{
			alt::Position min;
			alt::Position max;
		};

		virtual alt::IInteriorRoom* GetRoomByHash(uint32_t hash) const = 0;
		virtual alt::IInteriorRoom* GetRoomByIndex(uint32_t roomIndex) const = 0;		
		virtual alt::IInteriorPortal* GetPortalByIndex(uint32_t portalIndex) const = 0;

		virtual uint16_t GetRoomCount() const = 0;
		virtual uint16_t GetPortalCount() const = 0;
		virtual alt::Position GetPosition() const = 0;
		virtual alt::Position GetRotation() const = 0;
		virtual alt::IInterior::ExtentInfo GetEntitiesExtents() const = 0;
	};
}
//##endif