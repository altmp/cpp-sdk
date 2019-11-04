#pragma once

#include <cstdint>
#include "../Ref.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;
	class IEntity;

	class CPlayerDeathEvent : public CEvent
	{
	public:
		CPlayerDeathEvent(Ref<IPlayer> _target, Ref<IEntity> _killer, uint32_t _weapon) :
			CEvent(Type::PLAYER_DEATH),
			target(_target),
			killer(_killer),
			weapon(_weapon)
		{

		}

		Ref<IPlayer> GetTarget() const { return target; }
		Ref<IEntity> GetKiller() const { return killer; }
		uint32_t GetWeapon() const { return weapon; }

	private:
		Ref<IPlayer> target;
		Ref<IEntity> killer;
		uint32_t weapon;
	};
}
