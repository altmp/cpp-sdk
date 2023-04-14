#pragma once

#include <memory>
#include "CEvent.h"

namespace alt
{
	class IColShape;
	class IWorldObject;

	class CColShapeEvent : public CEvent
	{
	public:
		CColShapeEvent(const std::shared_ptr<IColShape>& _target, const std::shared_ptr<IWorldObject>& _entity, bool _state) :
			CEvent(Type::COLSHAPE_EVENT),
			target(_target),
			entity(_entity),
			state(_state)
		{

		}

		IColShape* GetTarget() const { return target.get(); }
		IWorldObject* GetEntity() const { return entity.get(); }
		bool GetState() const { return state; }

	private:
		std::shared_ptr<IColShape> target;
		std::shared_ptr<IWorldObject> entity;
		bool state;
	};
}
