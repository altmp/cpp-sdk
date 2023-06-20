#pragma once

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerStartTalkingEvent : public CEvent
	{
	public:
		CPlayerStartTalkingEvent(const std::shared_ptr<IPlayer>& _player) :
			CEvent(Type::PLAYER_START_TALKING),
			player(_player)
		{

		}

		IPlayer* GetPlayer() const { return player.get(); }

	private:
		std::shared_ptr<IPlayer> player;
	};
}
