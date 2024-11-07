#pragma once
#include <cstdint>

#include "cpp-sdk/deps/alt-math/alt-math.h"

namespace alt
{
	class IInteriorPortal
	{
	protected:
		virtual ~IInteriorPortal() = default;
		
	public:
		virtual uint32_t GetIndex() const = 0;
		virtual uint16_t GetCornerCount() const = 0;
		virtual Position GetCornerPosition(uint32_t cornerIndex) const = 0;
		virtual int32_t GetRoomFrom() const = 0;
		virtual int32_t GetRoomTo() const = 0;
		virtual int32_t GetFlag() const = 0;

		virtual uint16_t GetEntityCount() const = 0;
		virtual uint32_t GetEntityArcheType(uint32_t entityIndex) const = 0;
		virtual int32_t GetEntityFlag(uint32_t entityIndex) const = 0;
		virtual alt::Position GetEntityPosition(uint32_t entityIndex) const = 0;
		virtual alt::Rotation GetEntityRotation(uint32_t entityIndex) const = 0;

		
		virtual void SetCornerPosition(uint32_t cornerIndex,
											 const alt::Position& position) = 0;
		virtual void SetRoomFrom(uint32_t roomFrom) = 0;
		virtual void SetRoomTo(uint32_t roomTo) = 0;
		virtual void SetFlag(uint32_t flag) = 0;
		virtual void SetEntityFlag(uint32_t entityIndex, uint32_t flag) = 0;

	};
}