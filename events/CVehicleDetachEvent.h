#pragma once

#include "CEvent.h"

namespace alt
{
	class IVehicle;

	class CVehicleDetachEvent : public CEvent
	{
	public:
		CVehicleDetachEvent(IVehicle* _target, IVehicle* _detached) :
			CEvent(Type::VEHICLE_DETACH),
			target(_target),
			detached(_detached)
		{

		}

		IVehicle* GetTarget() const { return target; }
		IVehicle* GetDetached() const { return detached; }

	private:
		IVehicle* target;
		IVehicle* detached;
	};
}