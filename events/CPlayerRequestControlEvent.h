#pragma once

#include "CEvent.h"

namespace alt
{
	class IEntity;
	class IPlayer;

	class CPlayerRequestControlEvent : public CEvent
	{
	public:
		CPlayerRequestControlEvent(IEntity* _target, IPlayer* _player) :
			CEvent(Type::PLAYER_REQUEST_CONTROL),
			target(_target),
			player(_player)
		{

		}

		IEntity* GetTarget() const { return target; }
		IPlayer* GetPlayer() const { return player; }

	private:
		IEntity* target;
		IPlayer* player;
	};
}