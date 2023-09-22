#pragma once

#include <cstdint>
#include <memory>

#include "CEvent.h"

namespace alt
{
	class IPed;
	class IEntity;

	class CPedDeathEvent : public CEvent
	{
	public:
		CPedDeathEvent(const std::shared_ptr<IPed>& _target, const std::shared_ptr<IEntity>& _killer, uint32_t _weapon) :
			CEvent(Type::PED_DEATH),
			target(_target),
			killer(_killer),
			weapon(_weapon)
		{

		}

		IPed* GetTarget() const { return target.get(); }
		IEntity* GetKiller() const { return killer.get(); }
		uint32_t GetWeapon() const { return weapon; }

	private:
		std::shared_ptr<IPed> target;
		std::shared_ptr<IEntity> killer;
		uint32_t weapon;
	};
}
