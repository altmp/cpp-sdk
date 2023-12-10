#pragma once

#include <string>
#include <vector>

#include "BoneInfo.h"

namespace alt
{
	struct PedModelInfo
	{
		bool invalid = false;

		uint32_t hash;
		std::string name;
		std::string type;
		std::string dlcName; // Is not yet parsed for custom peds
		std::string defaultUnarmedWeapon;
		std::string movementClipSet;
		std::vector<BoneInfo> bones;
	};
}
