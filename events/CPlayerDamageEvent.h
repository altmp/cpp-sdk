#pragma once

#include <cstdint>
#include "../Ref.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;
	class IEntity;

	class CPlayerDamageEvent : public CEvent
	{
	public:
		CPlayerDamageEvent(Ref<IPlayer> _target, Ref<IEntity> _attacker, uint16_t _healthDamage, uint16_t _armourDamage, uint32_t _weapon) :
			CEvent(Type::PLAYER_DAMAGE),
			target(_target),
			attacker(_attacker),
			healthDamage(_healthDamage),
			armourDamage(_armourDamage),
			weapon(_weapon)
		{

		}

		Ref<IPlayer> GetTarget() const { return target; }
		Ref<IEntity> GetAttacker() const { return attacker; }
		uint16_t GetHealthDamage() const { return healthDamage; }
		uint16_t GetArmourDamage() const { return armourDamage; }
		uint32_t GetWeapon() const { return weapon; }

	private:
		Ref<IPlayer> target;
		Ref<IEntity> attacker;
		uint16_t healthDamage;
		uint16_t armourDamage;
		uint32_t weapon;
	};
}
