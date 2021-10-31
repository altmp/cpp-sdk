#pragma once

#include <iostream>
#include <cstdint>
#include <unordered_set>

namespace alt
{
	struct Weapon
	{
		uint32_t hash = 0;
		uint8_t tintIndex = 0;
		std::unordered_set<uint32_t> components {};

		Weapon() = default;

		Weapon(uint32_t _hash, uint8_t _tintIndex, std::unordered_set<uint32_t> _components) :
			hash(_hash), tintIndex(_tintIndex), components(_components) { }

		friend std::ostream &operator<<(std::ostream &stream, const Weapon& weapon)
		{
			stream << "Weapon{ " << weapon.hash<< ", " << weapon.tintIndex << ", " << weapon.components.size() <<  " }";
			return stream;
		}
	};
}
