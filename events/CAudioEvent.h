#pragma once

#include "../types/MValue.h"

#include "CEvent.h"

namespace alt
{
	class IAudio;

	class CAudioEvent : public CEvent
	{
	public:
		CAudioEvent(const std::shared_ptr<IAudio>& _target, const std::string& _name, const MValueArgs& _args) : CEvent(Type::AUDIO_EVENT),
			target(_target),
			name(_name),
			args(_args)
		{
		}

		IAudio* GetTarget() const { return target.get(); }
		const std::string& GetName() const { return name; }
		const MValueArgs& GetArgs() const { return args; }

	private:
		std::shared_ptr<IAudio> target;
		std::string name;
		MValueArgs args;
	};
} // namespace alt