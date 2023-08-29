#pragma once
#ifdef ALT_SERVER_API
#include <cstdint>

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	// not cancelable
	class CPlayerHealEvent : public CEvent
	{
	public:
		CPlayerHealEvent(const std::shared_ptr<IPlayer>& _target, uint16_t _oldHealth, uint16_t _newHealth, uint16_t _oldArmour, uint16_t _newArmour) :
			CEvent(Type::PLAYER_HEAL),
			target(_target),
			oldHealth(_oldHealth),
			newHealth(_newHealth),
			oldArmour(_oldArmour),
			newArmour(_newArmour)
		{

		}

		IPlayer* GetTarget() const { return target.get(); }
		uint16_t GetOldHealth() const { return oldHealth; }
		uint16_t GetNewHealth() const { return newHealth; }
		uint16_t GetOldArmour() const { return oldArmour; }
		uint16_t GetNewArmour() const { return newArmour; }

	private:
		std::shared_ptr<IPlayer> target;
		uint16_t oldHealth;
		uint16_t newHealth;
		uint16_t oldArmour;
		uint16_t newArmour;
	};
}
#endif