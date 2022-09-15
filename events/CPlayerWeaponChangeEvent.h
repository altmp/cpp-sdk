#pragma once

#include "CEvent.h"
#include "../Ref.h"

namespace alt
{
	class IPlayer;

	class CPlayerWeaponChangeEvent : public CEvent
	{
	public:
#ifdef ALT_SERVER_API
		CPlayerWeaponChangeEvent(Ref<IPlayer> _target, uint32_t _oldWeapon, uint32_t _newWeapon) :
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
		Ref<IPlayer> GetTarget() const { return target; }
#endif
		uint32_t GetOldWeapon() const { return oldWeapon; }
		uint32_t GetNewWeapon() const { return newWeapon; }

	private:
#ifdef ALT_SERVER_API
		Ref<IPlayer> target;
#endif
		uint32_t oldWeapon;
		uint32_t newWeapon;
	};
}