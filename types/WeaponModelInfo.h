#pragma once

#include <string>
#include <cstdint>

namespace alt
{
	struct WeaponModelInfo
	{
		uint32_t hash;
		std::string name;
		uint32_t modelHash;
		uint32_t ammoTypeHash;
		std::string ammoType;
		uint32_t ammoModelHash;
		int32_t defaultMaxAmmoMp;
		int32_t skillAbove50MaxAmmoMp;
		int32_t maxSkillMaxAmmoMp;
		int32_t bonusMaxAmmoMp;
	};
}
