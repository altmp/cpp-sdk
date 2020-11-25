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
		CNetOwnerChangeEvent(Ref<IEntity> _target, Ref<IPlayer> _newowner, Ref<IPlayer> _oldowner) :
			CEvent(Type::NETOWNER_CHANGE),
			target(_target),
			newOwner(_newowner),
			oldOwner(_oldowner)
		{

		}

		Ref<IEntity> GetTarget() const { return target; }
		Ref<IPlayer> GetNewOwner() const { return newOwner; }
		Ref<IPlayer> GetOldOwner() const { return oldOwner; }

	private:
		Ref<IEntity> target;
		Ref<IPlayer> newOwner;
		Ref<IPlayer> oldOwner;
	};
}