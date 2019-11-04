#pragma once

#include "CEvent.h"
#include "../Ref.h"

namespace alt
{
	class IEntity;

	class CRemoveEntityEvent : public CEvent
	{
	public:
		CRemoveEntityEvent(Ref<IEntity> _target) :
			CEvent(Type::REMOVE_ENTITY_EVENT),
			target(_target)
		{

		}

		Ref<IEntity> GetEntity() const { return target; }

	private:
		Ref<IEntity> target;
	};
}
