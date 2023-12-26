#pragma once

#include <iostream>
#include <cstdint>
#include <ostream>

#include "../deps/alt-math/alt-math.h"

namespace alt
{
	struct VehicleBadgePosition
	{
		bool active { false };
		uint8_t alpha { 255 };
		float size { 1.f };
		int16_t boneIndex { 0 };
		Vector3f offset { 0, 0, 0 };
		Vector3f direction { 0, 0, 0 };
		Vector3f side { 0, 0, 0 };

		VehicleBadgePosition() = default;

		VehicleBadgePosition(uint8_t alpha, float size, int16_t boneIndex, const Vector3f& offset,
			const Vector3f& direction, const Vector3f& side)
			: alpha(alpha),
			  size(size),
			  boneIndex(boneIndex),
			  offset(offset),
			  direction(direction),
			  side(side)
		{
		}

		friend std::ostream& operator<<(std::ostream& os, const VehicleBadgePosition& obj)
		{
			return os
				<< "alpha: " << obj.alpha
				<< " size: " << obj.size
				<< " boneIndex: " << obj.boneIndex
				<< " offset: " << obj.offset
				<< " direction: " << obj.direction
				<< " side: " << obj.side;
		}
	};
}
