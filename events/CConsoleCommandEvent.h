#pragma once

#include <vector>

#include "CEvent.h"

namespace alt
{
	class CConsoleCommandEvent : public CCancellableEvent
	{
	public:
		CConsoleCommandEvent(const std::string& _name, const std::vector<std::string>& _args) :
			CCancellableEvent(Type::CONSOLE_COMMAND_EVENT),
			name(_name),
			args(_args)
		{

		}

		std::string GetName() const { return name; }
		const std::vector<std::string>& GetArgs() const { return args; }

	private:
		std::string name;
		std::vector<std::string> args;
	};
}
