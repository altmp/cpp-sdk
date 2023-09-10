#pragma once

#include "CEvent.h"

namespace alt
{
	class IEntity;
	class IPlayer;

	class CPlayerRequestControlEvent : public CCancellableEvent
	{
	public:
		CPlayerRequestControlEvent(const std::shared_ptr<IEntity>& _target, const std::shared_ptr<IPlayer>& _player) :
			CCancellableEvent(Type::PLAYER_REQUEST_CONTROL),
			target(_target),
			player(_player)
		{

		}

		IEntity* GetTarget() const { return target.get(); }
		IPlayer* GetPlayer() const { return player.get(); }

	private:
		std::shared_ptr<IEntity> target;
		std::shared_ptr<IPlayer> player;
	};
}