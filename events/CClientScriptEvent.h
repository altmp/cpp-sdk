#pragma once

#include "../types/StringView.h"
#include "../types/MValue.h"

#include "CEvent.h"
#include "../Ref.h"

namespace alt
{
#ifdef ALT_SERVER_API
	class IPlayer;

	class CClientScriptEvent : public CEvent
	{
	public:
		CClientScriptEvent(Ref<IPlayer> _target, StringView _name, const MValueArgs&_args) :
			CEvent(Type::CLIENT_SCRIPT_EVENT),
			target(_target),
			name(_name),
			args(_args)
		{

		}

		Ref<IPlayer> GetTarget() const { return target; }
		StringView GetName() const { return name; }
		const MValueArgs& GetArgs() const { return args; }

	private:
		Ref<IPlayer> target;
		String name;
		MValueArgs args;
	};
#else
	class CClientScriptEvent : public CEvent
	{
	public:
		CClientScriptEvent(StringView _name, const MValueArgs& _args) :
			CEvent(Type::CLIENT_SCRIPT_EVENT),
			name(_name),
			args(_args)
		{

		}

		StringView GetName() const { return name; }
		const MValueArgs& GetArgs() const { return args; }

	private:
		String name;
		MValueArgs args;
	};
#endif
}
