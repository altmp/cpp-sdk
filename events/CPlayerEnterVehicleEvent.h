#pragma once

#include "CEvent.h"

namespace alt
{
	class IVehicle;
	class IPlayer;

	class CPlayerEnterVehicleEvent : public CEvent
	{
	public:
		CPlayerEnterVehicleEvent(const std::shared_ptr<IVehicle>& _target, const std::shared_ptr<IPlayer>& _player, uint8_t _seat) :
			CEvent(Type::PLAYER_ENTER_VEHICLE),
			target(_target),
			player(_player),
			seat(_seat)
		{

		}

		IVehicle* GetTarget() const { return target.get(); }
		IPlayer* GetPlayer() const { return player.get(); }
		uint8_t GetSeat() const { return seat; }

	private:
		std::shared_ptr<IVehicle> target;
		std::shared_ptr<IPlayer> player;
		uint8_t seat;
	};
}