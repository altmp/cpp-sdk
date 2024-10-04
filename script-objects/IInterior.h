#pragma once
#include <cstdint>
#include <string>
//#ifdef ALT_CLIENT_API

namespace alt
{
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

		virtual int32_t GetRoomIndexByHash(uint32_t hash) const = 0;
		virtual std::string GetRoomName(uint32_t roomIndex) const = 0;
		virtual int32_t GetRoomFlag(uint32_t roomIndex) const = 0;
		virtual ExtentInfo GetRoomExtents(uint32_t roomId) const = 0;
		virtual uint32_t GetRoomTimecycle(uint32_t roomIndex) const = 0;

		virtual alt::Position GetPortalCornerPosition(uint32_t portalIndex, uint32_t cornerIndex) const = 0;
		virtual int32_t GetPortalRoomFrom(uint32_t portalIndex) const = 0;
		virtual int32_t GetPortalRoomTo(uint32_t portalIndex) const = 0;
		virtual int32_t GetPortalFlag(uint32_t portalIndex) const = 0;

		virtual uint16_t GetRoomCount() const = 0;
		virtual uint16_t GetPortalCount() const = 0;
		virtual alt::Position GetPosition() const = 0;
		virtual alt::Position GetRotation() const = 0;
		virtual alt::IInterior::ExtentInfo GetEntitiesExtents() const = 0;

		virtual uint16_t GetPortalEntityCount(uint32_t portalIndex) const = 0;
		virtual uint32_t GetPortalEntityArcheType(uint32_t portalIndex, uint32_t entityIndex) const = 0;
		virtual int32_t GetPortalEntityFlag(uint32_t portalIndex, uint32_t entityIndex) const = 0;
		virtual alt::Position GetPortalEntityPosition(uint32_t portalIndex, uint32_t entityIndex) const = 0;
		virtual alt::Position GetPortalEntityRotation(uint32_t portalIndex, uint32_t entityIndex) const = 0;

		virtual void SetRoomFlag(uint32_t roomIndex, uint32_t flag) = 0;
		virtual void SetRoomTimecycle(uint32_t roomIndex, uint32_t timecycleHash) = 0;
		virtual void SetRoomExtents(uint32_t roomIndex, ExtentInfo extentInfo) = 0;

		virtual void SetPortalCornerPosition(uint32_t portalIndex, uint32_t cornerIndex,
		                                     const alt::Position& position) = 0;
		virtual void SetPortalRoomFrom(uint32_t portalIndex, uint32_t roomFrom) = 0;
		virtual void SetPortalRoomTo(uint32_t portalIndex, uint32_t roomTo) = 0;
		virtual void SetPortalFlag(uint32_t portalIndex, uint32_t flag) = 0;
		virtual void SetPortalEntityFlag(uint32_t portalIndex, uint32_t entityIndex, uint32_t flag) = 0;
	};
}

//##endif