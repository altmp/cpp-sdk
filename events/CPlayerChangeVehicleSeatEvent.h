#pragma once

#include "../Ref.h"\

#include "CEvent.h"

namespace alt
{
	class IVehicle;
	class IPlayer;

	class CPlayerChangeVehicleSeatEvent : public CEvent
	{
	public:
		CPlayerChangeVehicleSeatEvent(Ref<IVehicle> _target, Ref<IPlayer> _player, uint8_t _oldSeat, uint8_t _newSeat) :
			CEvent(Type::PLAYER_CHANGE_VEHICLE_SEAT),
			target(_target),
			player(_player),
			oldSeat(_oldSeat),
			newSeat(_newSeat)
		{

		}

		Ref<IVehicle> GetTarget() const { return target; }
		Ref<IPlayer> GetPlayer() const { return player; }
		uint8_t GetOldSeat() const { return oldSeat; }
		uint8_t GetNewSeat() const { return newSeat; }

	private:
		Ref<IVehicle> target;
		Ref<IPlayer> player;
		uint8_t oldSeat;
		uint8_t newSeat;
	};
}
