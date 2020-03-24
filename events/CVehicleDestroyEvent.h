#pragma once

#include <cstdint>
#include "../Ref.h"

#include "CEvent.h"

namespace alt
{
	class IVehicle;
	class IEntity;

	class CVehicleDestroyEvent : public CEvent
	{
	public:
		CVehicleDestroyEvent(Ref<IVehicle> _target) :
			CEvent(Type::VEHICLE_DESTROY),
			target(_target)
		{

		}

		Ref<IVehicle> GetTarget() const { return target; }

	private:
		Ref<IVehicle> target;
	};
}
