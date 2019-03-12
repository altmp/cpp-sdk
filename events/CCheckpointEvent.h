#pragma once

#include "CEvent.h"

namespace alt
{
	class ICheckpoint;
	class IEntity;

	class CCheckpointEvent : public CEvent
	{
	public:
		CCheckpointEvent(ICheckpoint* _target, IEntity* _entity, bool _state) :
			CEvent(Type::CHECKPOINT_EVENT),
			target(_target),
			entity(_entity),
			state(_state)
		{

		}

		ICheckpoint* GetTarget() const { return target; }
		IEntity* GetEntity() const { return entity; }
		bool GetState() const { return state; }

	private:
		ICheckpoint* target;
		IEntity* entity;
		bool state;
	};
}
