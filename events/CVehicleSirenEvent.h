#pragma once

#include <memory>

#include "CEvent.h"
#include "../objects/IVehicle.h"

namespace alt
{
	class CVehicleSirenEvent : public CEvent
	{
	public:
		CVehicleSirenEvent(const std::shared_ptr<IVehicle>& _target, bool _toggle) :
			CEvent(Type::VEHICLE_SIREN),
			target(_target),
			toggle(_toggle)
		{

		}

		IVehicle* GetTarget() const { return target.get(); }
		bool GetToggle() const { return toggle; }

	private:
		std::shared_ptr<IVehicle> target;
		bool toggle;
	};
}