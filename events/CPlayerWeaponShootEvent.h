#pragma once

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerWeaponShootEvent : public CEvent
	{
	public:
		CPlayerWeaponShootEvent(uint32_t _weapon, uint16_t _totalAmmo, uint16_t _ammoInClip, const std::shared_ptr<IEntity>& _victim, alt::Position _pos) :
			CEvent(Type::PLAYER_WEAPON_SHOOT_EVENT),
			weapon(_weapon),
			totalAmmo(_totalAmmo),
			ammoInClip(_ammoInClip),
			victim(_victim),
			pos(_pos)
		{}

		uint32_t GetWeapon() const { return weapon; }
		uint16_t GetTotalAmmo() const { return totalAmmo; }
		uint16_t GetAmmoInClip() const { return ammoInClip; }
		IEntity* GetVictim() const { return victim.get(); }
		alt::Position GetPosition() const { return pos; }

	private:
		uint32_t weapon;
		uint16_t totalAmmo;
		uint16_t ammoInClip;
		std::shared_ptr<IEntity> victim;
		alt::Position pos;
	};
}
