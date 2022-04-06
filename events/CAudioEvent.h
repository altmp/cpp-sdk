#pragma once

#include "../types/MValue.h"
#include "../Ref.h"

#include "CEvent.h"

namespace alt
{
	class IAudio;

	class CAudioEvent : public CEvent
	{
	public:
		CAudioEvent(Ref<IAudio> _target, const std::string& _name, const MValueArgs& _args) : CEvent(Type::AUDIO_EVENT),
			target(_target),
			name(_name),
			args(_args)
		{
		}

		Ref<IAudio> GetTarget() const { return target; }
		const std::string& GetName() const { return name; }
		const MValueArgs& GetArgs() const { return args; }

	private:
		Ref<IAudio> target;
		std::string name;
		MValueArgs args;
	};
} // namespace alt