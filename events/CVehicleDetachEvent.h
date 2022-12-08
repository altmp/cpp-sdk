#pragma once

#include "CEvent.h"

namespace alt
{
	class IVehicle;

	class CVehicleDetachEvent : public CEvent
	{
	public:
		CVehicleDetachEvent(const std::shared_ptr<IVehicle>& _target, const std::shared_ptr<IVehicle>& _detached) :
			CEvent(Type::VEHICLE_DETACH),
			target(_target),
			detached(_detached)
		{

		}

		IVehicle* GetTarget() const { return target.get(); }
		IVehicle* GetDetached() const { return detached.get(); }

	private:
		std::shared_ptr<IVehicle> target;
		std::shared_ptr<IVehicle> detached;
	};
}