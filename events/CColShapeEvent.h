#pragma once

#include <memory>
#include "CEvent.h"

namespace alt
{
	class IColShape;
	class IEntity;

	class CColShapeEvent : public CEvent
	{
	public:
		CColShapeEvent(const std::shared_ptr<IColShape>& _target, const std::shared_ptr<IEntity>& _entity, bool _state) :
			CEvent(Type::COLSHAPE_EVENT),
			target(_target),
			entity(_entity),
			state(_state)
		{

		}

		IColShape* GetTarget() const { return target.get(); }
		IEntity* GetEntity() const { return entity.get(); }
		bool GetState() const { return state; }

	private:
		std::shared_ptr<IColShape> target;
		std::shared_ptr<IEntity> entity;
		bool state;
	};
}
