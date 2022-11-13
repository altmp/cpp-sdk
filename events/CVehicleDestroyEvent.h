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
		CVehicleDestroyEvent(IVehicle* _target) :
			CEvent(Type::VEHICLE_DESTROY),
			target(_target)
		{

		}

		IVehicle* GetTarget() const { return target; }

	private:
		IVehicle* target;
	};
}
