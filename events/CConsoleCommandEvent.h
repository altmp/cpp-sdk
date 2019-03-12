#pragma once

#include "../types/StringView.h"
#include "../types/Array.h"

#include "CEvent.h"

namespace alt
{
	class CConsoleCommandEvent : public CEvent
	{
	public:
		CConsoleCommandEvent(StringView _name, Array<StringView> _args) :
			CEvent(Type::CONSOLE_COMMAND_EVENT),
			name(_name),
			args(_args)
		{

		}

		StringView GetName() const { return name; }
		const Array<StringView>& GetArgs() const { return args; }

	private:
		StringView name;
		Array<StringView> args;
	};
}
