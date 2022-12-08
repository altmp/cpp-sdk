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
		CPlayerDeathEvent(const std::shared_ptr<IPlayer>& _target, const std::shared_ptr<IEntity>& _killer, uint32_t _weapon) :
			CEvent(Type::PLAYER_DEATH),
			target(_target),
			killer(_killer),
			weapon(_weapon)
		{

		}

		IPlayer* GetTarget() const { return target.get(); }
		IEntity* GetKiller() const { return killer.get(); }
		uint32_t GetWeapon() const { return weapon; }

	private:
		std::shared_ptr<IPlayer> target;
		std::shared_ptr<IEntity> killer;
		uint32_t weapon;
	};
}
