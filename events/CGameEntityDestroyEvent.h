#pragma once

#include "CEvent.h"

namespace alt
{
	class IEntity;

	class CGameEntityDestroyEvent : public CEvent
	{
	public:
		CGameEntityDestroyEvent(IEntity* _target) :
			CEvent(Type::GAME_ENTITY_DESTROY),
			target(_target)
		{

		}

		IEntity* GetTarget() const { return target; }

	private:
		IEntity* target;
	};
}
