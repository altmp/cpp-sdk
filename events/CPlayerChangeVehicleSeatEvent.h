#pragma once

#include "CEvent.h"

namespace alt
{
	class IVehicle;
	class IPlayer;

	class CPlayerChangeVehicleSeatEvent : public CEvent
	{
	public:
		CPlayerChangeVehicleSeatEvent(const std::shared_ptr<IVehicle>& _target, const std::shared_ptr<IPlayer>& _player, uint8_t _oldSeat, uint8_t _newSeat) :
			CEvent(Type::PLAYER_CHANGE_VEHICLE_SEAT),
			target(_target),
			player(_player),
			oldSeat(_oldSeat),
			newSeat(_newSeat)
		{

		}

		IVehicle* GetTarget() const { return target.get(); }
		IPlayer* GetPlayer() const { return player.get(); }
		uint8_t GetOldSeat() const { return oldSeat; }
		uint8_t GetNewSeat() const { return newSeat; }

	private:
		std::shared_ptr<IVehicle> target;
		std::shared_ptr<IPlayer> player;
		uint8_t oldSeat;
		uint8_t newSeat;
	};
}
