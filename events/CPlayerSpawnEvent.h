#pragma once

#include <cstdint>

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerSpawnEvent : public CEvent
	{
	public:
		CPlayerSpawnEvent(const std::shared_ptr<IPlayer>& _player) :
			CEvent(Type::PLAYER_SPAWN),
			player(_player)
		{

		}

		IPlayer* GetPlayer() const { return player.get(); }

	private:
		std::shared_ptr<IPlayer> player;
	};
}
