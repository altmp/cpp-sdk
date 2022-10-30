#pragma once

#include "CEvent.h"

namespace alt
{
	class IEntity;

	class CGameEntityCreateEvent : public CEvent
	{
	public:
		CGameEntityCreateEvent(IEntity* _target) :
			CEvent(Type::GAME_ENTITY_CREATE),
			target(_target)
		{

		}

		IEntity* GetTarget() const { return target; }

	private:
		IEntity* target;
	};
}
