#pragma once

#include "CEvent.h"
#include "../Ref.h"

namespace alt
{
	class IVehicle;

	class CVehicleAttachEvent : public CEvent
	{
	public:
		CVehicleAttachEvent(Ref<IVehicle> _target, Ref<IVehicle> _attached) :
			CEvent(Type::VEHICLE_ATTACH),
			target(_target),
			attached(_attached)
		{

		}

		Ref<IVehicle> GetTarget() const { return target; }
		Ref<IVehicle> GetAttached() const { return attached; }

	private:
		Ref<IVehicle> target;
		Ref<IVehicle> attached;
	};
}