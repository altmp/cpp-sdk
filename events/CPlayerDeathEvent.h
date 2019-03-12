#pragma once

#include <cstdint>

#include "CEvent.h"

namespace alt
{
	class IPlayer;
	class IEntity;

	class CPlayerDeathEvent : public CEvent
	{
	public:
		CPlayerDeathEvent(IPlayer* _target, IEntity* _killer, uint32_t _weapon) :
			CEvent(Type::PLAYER_DEATH),
			target(_target),
			killer(_killer),
			weapon(_weapon)
		{

		}

		IPlayer* GetTarget() const { return target; }
		IEntity* GetKiller() const { return killer; }
		uint32_t GetWeapon() const { return weapon; }

	private:
		IPlayer* target;
		IEntity* killer;
		uint32_t weapon;
	};
}
