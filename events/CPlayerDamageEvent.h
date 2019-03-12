#pragma once

#include <cstdint>

#include "CEvent.h"

namespace alt
{
	class IPlayer;
	class IEntity;

	class CPlayerDamageEvent : public CEvent
	{
	public:
		CPlayerDamageEvent(IPlayer* _target, IEntity* _attacker, uint16_t _damage, uint32_t _weapon) :
			CEvent(Type::PLAYER_DAMAGE),
			target(_target),
			attacker(_attacker),
			damage(_damage),
			weapon(_weapon)
		{

		}

		IPlayer* GetTarget() const { return target; }
		IEntity* GetAttacker() const { return attacker; }
		uint16_t GetDamage() const { return damage; }
		uint32_t GetWeapon() const { return weapon; }

	private:
		IPlayer* target;
		IEntity* attacker;
		uint16_t damage;
		uint32_t weapon;
	};
}
