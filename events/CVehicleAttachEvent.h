#pragma once

#include "CEvent.h"

namespace alt
{
	class IVehicle;

	class CVehicleAttachEvent : public CEvent
	{
	public:
		CVehicleAttachEvent(const std::shared_ptr<IVehicle>& _target, const std::shared_ptr<IVehicle>& _attached) :
			CEvent(Type::VEHICLE_ATTACH),
			target(_target),
			attached(_attached)
		{

		}

		IVehicle* GetTarget() const { return target.get(); }
		IVehicle* GetAttached() const { return attached.get(); }

	private:
		std::shared_ptr<IVehicle> target;
		std::shared_ptr<IVehicle> attached;
	};
}