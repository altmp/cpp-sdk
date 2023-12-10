#pragma once

#include <string>
#include <cstdint>

namespace alt
{
	struct WeaponModelInfo
	{
		bool invalid = false;

		uint32_t hash;
		uint32_t modelHash;
		uint32_t ammoTypeHash;

		std::string name;
		std::string model;
		std::string ammoType;
		
		// Above should be stored in a separate WeaponAmmoInfo, not parsed for custom weapons
		std::string ammoModelName;
		uint32_t ammoModelHash;
		int32_t defaultMaxAmmoMp;
		int32_t skillAbove50MaxAmmoMp;
		int32_t maxSkillMaxAmmoMp;
		int32_t bonusMaxAmmoMp;
	};
}
