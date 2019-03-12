#pragma once

#include <cstdint>

#include "CEvent.h"

namespace alt
{
	class CKeyboardEvent : public CEvent
	{
	public:
		enum class KeyState
		{
			UP,
			DOWN
		};
		
		CKeyboardEvent(uint32_t _keyCode, KeyState state) :
			CEvent(Type::KEYBOARD_EVENT),
			keyCode(_keyCode),
			keyState(state)
		{

		}

		uint32_t GetKeyCode() const { return keyCode; }
		KeyState GetKeyState() const { return keyState; }

	private:
		uint32_t keyCode;
		KeyState keyState;
	};
}
