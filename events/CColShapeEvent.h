#pragma once

#include "CEvent.h"

namespace alt
{
	class IColShape;
	class IEntity;

	class CColShapeEvent : public CEvent
	{
	public:
		CColShapeEvent(IColShape* _target, IEntity* _entity, bool _state) :
			CEvent(Type::COLSHAPE_EVENT),
			target(_target),
			entity(_entity),
			state(_state)
		{

		}

		IColShape* GetTarget() const { return target; }
		IEntity* GetEntity() const { return entity; }
		bool GetState() const { return state; }

	private:
		IColShape* target;
		IEntity* entity;
		bool state;
	};
}
