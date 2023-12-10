#pragma once

#include <string>

#include "BoneInfo.h"

namespace alt
{
	struct VehicleModelInfo
	{
		enum class Type : uint8_t
		{
			INVALID,
			PED,
			AUTOMOBILE,
			PLANE,
			TRAILER,
			QUAD_BIKE,
			SUBMARINE_CAR,
			AMPHIBIOUS_AUTOMOBILE,
			AMPHIBIOUS_QUAD_BIKE,
			HELI,
			BLIMP,
			AUTOGYRO,
			BIKE,
			BMX,
			BOAT,
			TRAIN,
			SUBMARINE,
			OBJECT
		};

		bool invalid = false;

		std::string title;
		Type modelType;
		uint8_t wheelsCount;
		bool hasArmoredWindows;
		uint8_t primaryColor;
		uint8_t secondaryColor;
		uint8_t pearlColor;
		uint8_t wheelsColor;
		uint8_t interiorColor;
		uint8_t dashboardColor;

		uint16_t modkits[2];
		uint16_t extras;
		uint16_t defaultExtras;
		bool hasAutoAttachTrailer;
		
		std::vector<BoneInfo> bones;

		bool canAttachCars;
		uint32_t handlingNameHash;

		bool DoesExtraExist(uint8_t extraId) const
		{
			return ((!!((extras) & (1ULL << (extraId)))));
		}

		bool DoesExtraDefault(uint8_t extraId) const
		{
			return ((!!((defaultExtras) & (1ULL << (extraId)))));
		}
	};
}
