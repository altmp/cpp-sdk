#pragma once

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CTaskChangeEvent : public CEvent
	{
	public:
		CTaskChangeEvent(const std::shared_ptr<IPlayer> _target, uint32_t _oldTask, uint32_t _newTask) :
			CEvent(Type::TASK_CHANGE),
			target(_target),
			oldTask(_oldTask),
			newTask(_newTask)
		{
		}

		IPlayer* GetTarget() const { return target.get(); }
		uint32_t GetOldTask() const { return oldTask; }
		uint32_t GetNewTask() const { return newTask; }

	private:
		std::shared_ptr<IPlayer> target;
		uint32_t oldTask;
		uint32_t newTask;
	};
}
