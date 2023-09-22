#pragma once

#include <cstdint>
#include <memory>

#include "CEvent.h"

namespace alt
{
	class IPed;
	class IEntity;

	class CPedDamageEvent : public CEvent
	{
	public:
		CPedDamageEvent(const std::shared_ptr<IPed>& _target, const std::shared_ptr<IEntity>& _attacker, uint16_t _healthDamage, uint16_t _armourDamage, uint32_t _weapon) :
			CEvent(Type::PED_DAMAGE),
			target(_target),
			attacker(_attacker),
			healthDamage(_healthDamage),
			armourDamage(_armourDamage),
			weapon(_weapon)
		{

		}

		IPed* GetTarget() const { return target.get(); }
		IEntity* GetAttacker() const { return attacker.get(); }
		uint16_t GetHealthDamage() const { return healthDamage; }
		uint16_t GetArmourDamage() const { return armourDamage; }
		uint32_t GetWeapon() const { return weapon; }

	private:
		std::shared_ptr<IPed> target;
		std::shared_ptr<IEntity> attacker;
		uint16_t healthDamage;
		uint16_t armourDamage;
		uint32_t weapon;
	};
}
