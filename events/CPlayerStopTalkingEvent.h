#pragma once

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerStopTalkingEvent : public CEvent
	{
	public:
		CPlayerStopTalkingEvent(const std::shared_ptr<IPlayer>& _player) :
			CEvent(Type::PLAYER_STOP_TALKING),
			player(_player)
		{

		}

		IPlayer* GetPlayer() const { return player.get(); }

	private:
		std::shared_ptr<IPlayer> player;
	};
}
