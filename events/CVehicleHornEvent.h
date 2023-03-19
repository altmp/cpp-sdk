#pragma once

#include <memory>

#include "CEvent.h"
#include "../objects/IPlayer.h"
#include "../objects/IVehicle.h"

namespace alt
{
	class CVehicleHornEvent : public CEvent
	{
	public:
		CVehicleHornEvent(const std::shared_ptr<IVehicle>& _target, const std::shared_ptr<IPlayer>& _reporter, bool _toggle) :
			CEvent(Type::VEHICLE_HORN),
			target(_target),
			reporter(_reporter),
			toggle(_toggle)
		{

		}

		IVehicle* GetTarget() const { return target.get(); }
		IPlayer* GetReporter() const { return reporter.get(); }
		bool GetToggle() const { return toggle; }

	private:
		std::shared_ptr<IVehicle> target;
		std::shared_ptr<IPlayer> reporter;
		bool toggle;
	};
}