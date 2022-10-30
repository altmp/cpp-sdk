#pragma once

#include "../types/MValue.h"

#include "CEvent.h"

namespace alt
{
#ifdef ALT_SERVER_API
	class IPlayer;

	class CClientScriptEvent : public CEvent
	{
	public:
		CClientScriptEvent(IPlayer* _target, const std::string& _name, const MValueArgs&_args) :
			CEvent(Type::CLIENT_SCRIPT_EVENT),
			target(_target),
			name(_name),
			args(_args)
		{

		}

		IPlayer* GetTarget() const { return target; }
		const std::string& GetName() const { return name; }
		const MValueArgs& GetArgs() const { return args; }

	private:
		IPlayer* target;
		std::string name;
		MValueArgs args;
	};
#else
	class CClientScriptEvent : public CEvent
	{
	public:
		CClientScriptEvent(const std::string& _name, const MValueArgs& _args) :
			CEvent(Type::CLIENT_SCRIPT_EVENT),
			name(_name),
			args(_args)
		{

		}

		const std::string& GetName() const { return name; }
		const MValueArgs& GetArgs() const { return args; }

	private:
		std::string name;
		MValueArgs args;
	};
#endif
}
