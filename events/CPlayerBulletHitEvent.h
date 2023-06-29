#pragma once

#include "CEvent.h"

namespace alt
{
	class CPlayerBulletHitEvent : public CEvent
	{
	public:
		CPlayerBulletHitEvent(uint32_t _weapon, const std::shared_ptr<IEntity>& _victim, alt::Position _pos) :
			CEvent(Type::PLAYER_BULLET_HIT_EVENT),
			weapon(_weapon),
			victim(_victim),
			pos(_pos)
		{}

		uint32_t GetWeapon() const { return weapon; }
		IEntity* GetVictim() const { return victim.get(); }
		alt::Position GetPosition() const { return pos; }

	private:
		uint32_t weapon;
		std::shared_ptr<IEntity> victim;
		alt::Position pos;
	};
}
