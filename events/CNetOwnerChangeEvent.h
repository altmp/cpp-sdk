#pragma once

#include "CEvent.h"

namespace alt
{
	class IEntity;
	class IPlayer;

	class CNetOwnerChangeEvent : public CEvent
	{
	public:
		CNetOwnerChangeEvent(IEntity* _target, IPlayer* _newowner, IPlayer* _oldowner) :
			CEvent(Type::NETOWNER_CHANGE),
			target(_target),
			newOwner(_newowner),
			oldOwner(_oldowner)
		{

		}

		IEntity* GetTarget() const { return target; }
		IPlayer* GetNewOwner() const { return newOwner; }
		IPlayer* GetOldOwner() const { return oldOwner; }

	private:
		IEntity* target;
		IPlayer* newOwner;
		IPlayer* oldOwner;
	};
}