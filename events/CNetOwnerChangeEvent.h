#pragma once

#include "CEvent.h"

namespace alt
{
	class IEntity;
	class IPlayer;

	class CNetOwnerChangeEvent : public CEvent
	{
	public:
		CNetOwnerChangeEvent(const std::shared_ptr<IEntity>& _target, const std::shared_ptr<IPlayer>& _newowner, const std::shared_ptr<IPlayer>& _oldowner) :
			CEvent(Type::NETOWNER_CHANGE),
			target(_target),
			newOwner(_newowner),
			oldOwner(_oldowner)
		{

		}

		IEntity* GetTarget() const { return target.get(); }
		IPlayer* GetNewOwner() const { return newOwner.get(); }
		IPlayer* GetOldOwner() const { return oldOwner.get(); }

	private:
		std::shared_ptr<IEntity> target;
		std::shared_ptr<IPlayer> newOwner;
		std::shared_ptr<IPlayer> oldOwner;
	};
}