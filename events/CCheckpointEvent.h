#pragma once

#include "CEvent.h"
#include "../Ref.h"

namespace alt
{
	class ICheckpoint;
	class IEntity;

	class CCheckpointEvent : public CEvent
	{
	public:
		CCheckpointEvent(Ref<ICheckpoint> _target, Ref<IEntity> _entity, bool _state) :
			CEvent(Type::CHECKPOINT_EVENT),
			target(_target),
			entity(_entity),
			state(_state)
		{

		}

		Ref<ICheckpoint> GetTarget() const { return target; }
		Ref<IEntity> GetEntity() const { return entity; }
		bool GetState() const { return state; }

	private:
		Ref<ICheckpoint> target;
		Ref<IEntity> entity;
		bool state;
	};
}
