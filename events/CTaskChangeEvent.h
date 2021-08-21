#pragma once

#include "../Ref.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CTaskChangeEvent : public CEvent
	{
	public:
		CTaskChangeEvent(Ref<IPlayer> _target, uint32_t _oldTask, uint32_t _newTask) :
			CEvent(Type::TASK_CHANGE),
			oldTask(_oldTask),
			newTask(_newTask)
		{
		}

		Ref<IPlayer> GetTarget() const { return target; }
		uint32_t GetOldTask() const { return oldTask; }
		uint32_t GetNewTask() const { return newTask; }

	private:
		Ref<IPlayer> target;
		uint32_t oldTask;
		uint32_t newTask;
	};
}
