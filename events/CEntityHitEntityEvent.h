#pragma once

#include <cstdint>

#include "CEvent.h"

namespace alt
{
	class IEntity;

	class CEntityHitEntityEvent : public CEvent
	{
	public:
		CEntityHitEntityEvent(const std::shared_ptr<IEntity>& _damager, const std::shared_ptr<IEntity>& _target, uint32_t _weaponHash) :
			CEvent(Type::ENTITY_HIT_ENTITY),
			damager(_damager),
			target(_target),
			weaponHash(_weaponHash)
		{}

		IEntity* GetTarget() const { return target.get(); }
		IEntity* GetDamager() const { return damager.get(); }
		uint32_t GetWeapon() const { return weaponHash; }

	private:
		std::shared_ptr<IEntity> damager;
		std::shared_ptr<IEntity> target;
		uint32_t weaponHash; 
	};
}
