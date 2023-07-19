#pragma once

#include "CEvent.h"

#include <cstdint>

namespace alt
{
	class CVoiceConnectionEvent : public CEvent
	{
	public:
		enum class State: uint8_t
		{
			DISCONNECTED,
			CONNECTING,
			CONNECTED
		};

		explicit CVoiceConnectionEvent(const State _state) :
			CEvent(Type::VOICE_CONNECTION_EVENT),
			state(_state)
		{

		}
		
		State GetState() const { return state; }

	private:
		State state;
	};
}