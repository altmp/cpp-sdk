#pragma once

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerWeaponChangeEvent : public CEvent
	{
	public:
#ifdef ALT_SERVER_API
		CPlayerWeaponChangeEvent(const std::shared_ptr<IPlayer>& _target, uint32_t _oldWeapon, uint32_t _newWeapon) :
			CEvent(Type::PLAYER_WEAPON_CHANGE),
			target(_target),
			oldWeapon(_oldWeapon),
			newWeapon(_newWeapon)
		{}
#endif
#ifdef ALT_CLIENT_API
		CPlayerWeaponChangeEvent(uint32_t _oldWeapon, uint32_t _newWeapon) :
			CEvent(Type::PLAYER_WEAPON_CHANGE),
			oldWeapon(_oldWeapon),
			newWeapon(_newWeapon)
		{}
#endif

#ifdef ALT_SERVER_API
		IPlayer* GetTarget() const { return target.get(); }
#endif
		uint32_t GetOldWeapon() const { return oldWeapon; }
		uint32_t GetNewWeapon() const { return newWeapon; }

	private:
#ifdef ALT_SERVER_API
		std::shared_ptr<IPlayer> target;
#endif
		uint32_t oldWeapon;
		uint32_t newWeapon;
	};
}