#pragma once

#include <cstdint>

namespace alt
{
	enum class AmmoSpecialType : uint32_t
	{
		NONE,
		ARMOR_PIERCING,
		EXPLOSIVE,
		FULL_METAL_JACKET,
		HOLLOW_POINT,
		INCENDIARY,
		TRACER
	};
} // namespace alt
