#pragma once

#include "CEvent.h"
#include "../Ref.h"

namespace alt
{
	class IEntity;
	class IPlayer;

	class CNetOwnerChangeEvent : public CEvent
	{
	public:
		CNetOwnerChangeEvent(Ref<IEntity> _target, Ref<IPlayer> _player) :
			CEvent(Type::NETOWNER_CHANGE),
			target(_target),
			player(_player)
		{

		}

		Ref<IEntity> GetTarget() const { return target; }
		Ref<IPlayer> GetPlayer() const { return player; }

	private:
		Ref<IEntity> target;
		Ref<IPlayer> player;
	};
}