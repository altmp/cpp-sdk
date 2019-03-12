#pragma once

#include "CEvent.h"

namespace alt
{
	class IVehicle;
	class IPlayer;

	class CPlayerChangeVehicleSeatEvent : public CEvent
	{
	public:
		CPlayerChangeVehicleSeatEvent(IVehicle* _target, IPlayer* _player, uint8_t _oldSeat, uint8_t _newSeat) :
			CEvent(Type::PLAYER_CHANGE_VEHICLE_SEAT),
			target(_target),
			player(_player),
			oldSeat(_oldSeat),
			newSeat(_newSeat)
		{

		}

		IVehicle* GetTarget() const { return target; }
		IPlayer* GetPlayer() const { return player; }
		uint8_t GetOldSeat() const { return oldSeat; }
		uint8_t GetNewSeat() const { return newSeat; }

	private:
		IVehicle* target;
		IPlayer* player;
		uint8_t oldSeat;
		uint8_t newSeat;
	};
}
