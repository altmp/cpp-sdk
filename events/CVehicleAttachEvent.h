#pragma once

#include "CEvent.h"

namespace alt
{
	class IVehicle;

	class CVehicleAttachEvent : public CEvent
	{
	public:
		CVehicleAttachEvent(IVehicle* _target, IVehicle* _attached) :
			CEvent(Type::VEHICLE_ATTACH),
			target(_target),
			attached(_attached)
		{

		}

		IVehicle* GetTarget() const { return target; }
		IVehicle* GetAttached() const { return attached; }

	private:
		IVehicle* target;
		IVehicle* attached;
	};
}