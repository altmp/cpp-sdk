#pragma once

#include "CEvent.h"
#include "../Ref.h"

namespace alt
{
	class IPlayer;

	class CPlayerWeaponShootEvent : public CEvent
	{
	public:
		CPlayerWeaponShootEvent(Ref<IPlayer> _target, uint32_t _weapon, uint16_t _totalAmmo, uint16_t _ammoInClip) :
			CEvent(Type::PLAYER_WEAPON_SHOOT_EVENT),
			target(_target),
			weapon(_weapon),
			totalAmmo(_totalAmmo),
			ammoInClip(_ammoInClip)
		{}

		Ref<IPlayer> GetTarget() const { return target; }
		uint32_t GetWeapon() const { return weapon; }
		uint16_t GetTotalAmmo() const { return totalAmmo; }
		uint16_t GetAmmoInClip() const { return ammoInClip; }

	private:
		Ref<IPlayer> target;
		uint32_t weapon;
		uint16_t totalAmmo;
		uint16_t ammoInClip;
	};
}
