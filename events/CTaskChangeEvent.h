#pragma once

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CTaskChangeEvent : public CEvent
	{
	public:
		CTaskChangeEvent(IPlayer* _target, uint32_t _oldTask, uint32_t _newTask) :
			CEvent(Type::TASK_CHANGE),
			oldTask(_oldTask),
			newTask(_newTask)
		{
		}

		IPlayer* GetTarget() const { return target; }
		uint32_t GetOldTask() const { return oldTask; }
		uint32_t GetNewTask() const { return newTask; }

	private:
		IPlayer* target;
		uint32_t oldTask;
		uint32_t newTask;
	};
}
