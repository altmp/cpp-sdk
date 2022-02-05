#pragma once

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CWindowFocusChangeEvent : public CEvent
	{
	public:
		CWindowFocusChangeEvent(bool _state) :
			CEvent(Type::WINDOW_FOCUS_CHANGE),
			state(_state)
		{
		}

		bool GetState() const { return state; }

	private:
		bool state;
	};
}
