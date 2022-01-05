#pragma once

#include "CEvent.h"
#include "../Ref.h"

namespace alt
{
	class IVehicle;

	class CVehicleLockStateChangeEvent : public CEvent
	{
	public:
		CVehicleLockStateChangeEvent(Ref<IVehicle> _target, uint8_t _newState, uint8_t _oldState) :
			CEvent(Type::VEHICLE_LOCK_STATE_CHANGE),
			target(_target),
			newState(_newState),
			oldState(_oldState)
		{

		}

		Ref<IVehicle> GetTarget() const { return target; }
		uint8_t GetNewState() const { return newState; }
		uint8_t GetOldState() const { return oldState; }

	private:
		Ref<IVehicle> target;
		uint8_t newState;
		uint8_t oldState;
	};
}