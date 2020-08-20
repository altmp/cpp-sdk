#pragma once

#include "CEvent.h"
#include "../Ref.h"

namespace alt
{
	class IPlayer;

	class CPlayerWeaponChangeEvent : public CEvent
	{
	public:
		CPlayerWeaponChangeEvent(Ref<IPlayer> _target, uint32_t _oldWeapon, uint32_t _newWeapon) :
			CEvent(Type::PLAYER_WEAPON_CHANGE),
			target(_target),
			oldWeapon(_oldWeapon),
			newWeapon(_newWeapon)
		{

		}

		Ref<IPlayer> GetTarget() const { return target; }
		uint32_t GetOldWeapon() const { return oldWeapon; }
		uint32_t GetNewWeapon() const { return newWeapon; }

	private:
		Ref<IPlayer> target;
		uint32_t oldWeapon;
		uint32_t newWeapon;
	};
}