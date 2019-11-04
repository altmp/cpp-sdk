#pragma once

#include "CEvent.h"
#include "../Ref.h"

namespace alt
{
	class IColShape;
	class IEntity;

	class CColShapeEvent : public CEvent
	{
	public:
		CColShapeEvent(Ref<IColShape> _target, Ref<IEntity> _entity, bool _state) :
			CEvent(Type::COLSHAPE_EVENT),
			target(_target),
			entity(_entity),
			state(_state)
		{

		}

		Ref<IColShape> GetTarget() const { return target; }
		Ref<IEntity> GetEntity() const { return entity; }
		bool GetState() const { return state; }

	private:
		Ref<IColShape> target;
		Ref<IEntity> entity;
		bool state;
	};
}
