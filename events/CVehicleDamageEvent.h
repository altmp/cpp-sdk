#pragma once

#include <cstdint>
#include "../Ref.h"

#include "CEvent.h"

namespace alt
{
	class IVehicle;
	class IEntity;

	class CVehicleDamageEvent : public CEvent
	{
	public:
		CVehicleDamageEvent(Ref<IVehicle> _target, Ref<IEntity> _damager, 
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

		Ref<IVehicle> GetTarget() const { return target; }

		Ref<IEntity> GetDamager() const { return damager; }

		uint32_t GetBodyHealthDamage() const { return bodyHealthDamage; }

		uint32_t GetBodyAdditionalHealthDamage() const { return bodyAdditionalHealthDamage; }

		uint32_t GetEngineHealthDamage() const { return engineHealthDamage; }

		uint32_t GetPetrolTankHealthDamage() const { return petrolTankHealthDamage; }

		uint32_t GetDamagedWith() const { return damagedWith; }

	private:
		Ref<IVehicle> target;
		Ref<IEntity> damager;
		uint32_t bodyHealthDamage; 
		uint32_t bodyAdditionalHealthDamage;
		uint32_t engineHealthDamage; 
		uint32_t petrolTankHealthDamage; 
		uint32_t damagedWith;
	};
}
