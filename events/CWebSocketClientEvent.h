#pragma once

#include "../types/MValue.h"

#include "CEvent.h"

namespace alt
{
	class IWebSocketClient;

	class CWebSocketClientEvent : public CEvent
	{
	public:
		CWebSocketClientEvent(IWebSocketClient* _target, const std::string& _name, const MValueArgs& _args) : CEvent(Type::WEB_SOCKET_CLIENT_EVENT),
			target(_target),
			name(_name),
			args(_args)
		{
		}

		IWebSocketClient* GetTarget() const { return target; }
		const std::string& GetName() const { return name; }
		const MValueArgs& GetArgs() const { return args; }

	private:
		IWebSocketClient* target;
		std::string name;
		MValueArgs args;
	};
} // namespace alt
