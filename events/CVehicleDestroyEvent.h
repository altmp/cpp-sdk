#pragma once

#include <cstdint>

#include "CEvent.h"

namespace alt
{
	class IVehicle;
	class IEntity;

	class CVehicleDestroyEvent : public CEvent
	{
	public:
		CVehicleDestroyEvent(const std::shared_ptr<IVehicle>& _target) :
			CEvent(Type::VEHICLE_DESTROY),
			target(_target)
		{

		}

		IVehicle* GetTarget() const { return target.get(); }

	private:
		std::shared_ptr<IVehicle> target;
	};
}
