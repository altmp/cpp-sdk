#pragma once

#include <cstdint>

#include "CEvent.h"

namespace alt
{
	class IVehicle;
	class IEntity;

	class CVehicleDamageEvent : public CEvent
	{
	public:
		CVehicleDamageEvent(const std::shared_ptr<IVehicle>& _target, const std::shared_ptr<IEntity>& _damager,
			uint32_t _bodyHealthDamage, uint32_t _bodyAdditionalHealthDamage,
			uint32_t _engineHealthDamage, uint32_t _petrolTankHealthDamage, uint32_t _damagedWith) :
			CEvent(Type::VEHICLE_DAMAGE),
			target(_target),
			damager(_damager),
			bodyHealthDamage(_bodyHealthDamage),
			bodyAdditionalHealthDamage(_bodyAdditionalHealthDamage),
			engineHealthDamage(_engineHealthDamage),
			petrolTankHealthDamage(_petrolTankHealthDamage),
			damagedWith(_damagedWith)
		{

		}

		IVehicle* GetTarget() const { return target.get(); }

		IEntity* GetDamager() const { return damager.get(); }

		uint32_t GetBodyHealthDamage() const { return bodyHealthDamage; }

		uint32_t GetBodyAdditionalHealthDamage() const { return bodyAdditionalHealthDamage; }

		uint32_t GetEngineHealthDamage() const { return engineHealthDamage; }

		uint32_t GetPetrolTankHealthDamage() const { return petrolTankHealthDamage; }

		uint32_t GetDamagedWith() const { return damagedWith; }

	private:
		std::shared_ptr<IVehicle> target;
		std::shared_ptr<IEntity> damager;
		uint32_t bodyHealthDamage; 
		uint32_t bodyAdditionalHealthDamage;
		uint32_t engineHealthDamage; 
		uint32_t petrolTankHealthDamage; 
		uint32_t damagedWith;
	};
}
