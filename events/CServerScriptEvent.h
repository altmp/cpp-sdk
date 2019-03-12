#pragma once

#include "../types/MValue.h"
#include "../types/MValueList.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CServerScriptEvent : public CEvent
	{
	public:
		CServerScriptEvent(StringView _name, MValueList _args) :
			CEvent(Type::SERVER_SCRIPT_EVENT),
			name(_name),
			args(_args)
		{

		}

		StringView GetName() const { return name; }
		MValueList GetArgs() const { return args; }

	private:
		String name;
		MValueList args;
	};
}
