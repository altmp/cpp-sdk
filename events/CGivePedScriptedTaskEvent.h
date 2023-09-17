#pragma once
#ifdef ALT_SERVER_API
#include "../deps/alt-math/alt-math.h"

#include "CEvent.h"

namespace alt
{
	class IEntity;
	class IPlayer;
	class IPed;

	class CGivePedScriptedTaskEvent : public CCancellableEvent
	{
	public:
        CGivePedScriptedTaskEvent(const std::shared_ptr<IPlayer> _source, const std::shared_ptr<IPed> _target, int32_t _taskType) :
			CCancellableEvent(Type::GIVE_PED_SCRIPTED_TASK),
			source(_source),
			target(_target),
			taskType(_taskType)
		{

		}

		IPlayer* GetSource() const { return source.get(); }
		IPed* GetTarget() const { return target.get(); }
		int32_t GetTaskType() const { return taskType; }

	private:
		std::shared_ptr<IPlayer> source;
		std::shared_ptr<IPed> target;
		int32_t taskType;
	};
}
#endif
