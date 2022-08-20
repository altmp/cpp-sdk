#pragma once

#include <string>

#include "BoneInfo.h"

namespace alt
{
	struct PedModelInfo
	{
		uint32_t hash;
		std::string name;
		std::vector<BoneInfo> bones;
	};
}
