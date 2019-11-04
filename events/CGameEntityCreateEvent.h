#pragma once

#include "CEvent.h"
#include "../Ref.h"

namespace alt
{
	class IEntity;

	class CGameEntityCreateEvent : public CEvent
	{
	public:
		CGameEntityCreateEvent(Ref<IEntity> _target) :
			CEvent(Type::GAME_ENTITY_CREATE),
			target(_target)
		{

		}

		Ref<IEntity> GetTarget() const { return target; }

	private:
		Ref<IEntity> target;
	};
}
