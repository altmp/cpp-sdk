#pragma once

#include "CEvent.h"

namespace alt
{
	class IEntity;

	class CRemoveEntityEvent : public CEvent
	{
	public:
		CRemoveEntityEvent(IEntity* _target) :
			CEvent(Type::REMOVE_ENTITY_EVENT),
			target(_target)
		{

		}

		IEntity* GetEntity() const { return target; }

	private:
		IEntity* target;
	};
}
