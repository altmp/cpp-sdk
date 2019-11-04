#pragma once

#include "CEvent.h"
#include "../Ref.h"

namespace alt
{
	class IEntity;

	class CGameEntityDestroyEvent : public CEvent
	{
	public:
		CGameEntityDestroyEvent(Ref<IEntity> _target) :
			CEvent(Type::GAME_ENTITY_DESTROY),
			target(_target)
		{

		}

		Ref<IEntity> GetTarget() const { return target; }

	private:
		Ref<IEntity> target;
	};
}
