#pragma once

#include <string>
#include <vector>

#include "BoneInfo.h"

namespace alt
{
	struct PedModelInfo
	{
		uint32_t hash;
		std::string name;
		std::string type;
		std::string dlcName;
		std::string defaultUnarmedWeapon;
		std::string movementClipSet;
		std::vector<BoneInfo> bones;
	};
}
