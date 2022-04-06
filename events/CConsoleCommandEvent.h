#pragma once

#include "../types/Array.h"

#include "CEvent.h"

namespace alt
{
	class CConsoleCommandEvent : public CEvent
	{
	public:
		CConsoleCommandEvent(const std::string& _name, const std::vector<std::string>& _args) :
			CEvent(Type::CONSOLE_COMMAND_EVENT),
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
