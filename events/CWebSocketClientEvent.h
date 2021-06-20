#pragma once

#include "../types/StringView.h"
#include "../types/MValue.h"
#include "../Ref.h"

#include "CEvent.h"

namespace alt
{
	class IWebSocketClient;

	class CWebSocketClientEvent : public CEvent
	{
	public:
		CWebSocketClientEvent(Ref<IWebSocketClient> _target, StringView _name, const MValueArgs& _args) : CEvent(Type::WEB_SOCKET_CLIENT_EVENT),
			target(_target),
			name(_name),
			args(_args)
		{
		}

		Ref<IWebSocketClient> GetTarget() const { return target; }
		StringView GetName() const { return name; }
		const MValueArgs& GetArgs() const { return args; }

	private:
		Ref<IWebSocketClient> target;
		String name;
		MValueArgs args;
	};
} // namespace alt
