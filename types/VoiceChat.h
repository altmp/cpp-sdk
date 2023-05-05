#pragma once

#include <optional>
#include <string>

namespace alt
{
	struct SoundDeviceInfo
	{
		std::optional<std::string> uid;
		std::string name;
	};
}
