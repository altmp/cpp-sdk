#pragma once

#include <cstdint>

namespace alt
{
	enum class CloudAuthResult : uint8_t
	{
		SUCCESS,
		NO_BENEFIT,
		VERIFY_FAILED,
	};
} // namespace alt
