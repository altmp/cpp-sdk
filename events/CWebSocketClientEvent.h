#pragma once

#include "../types/const std::string&.h"
#include "../types/MValue.h"
#include "../Ref.h"

#include "CEvent.h"

namespace alt
{
	class IWebSocketClient;

	class CWebSocketClientEvent : public CEvent
	{
	public:
		CWebSocketClientEvent(Ref<IWebSocketClient> _target, const std::string& _name, const MValueArgs& _args) : CEvent(Type::WEB_SOCKET_CLIENT_EVENT),
			target(_target),
			name(_name),
			args(_args)
		{
		}

		Ref<IWebSocketClient> GetTarget() const { return target; }
		const std::string& GetName() const { return name; }
		const MValueArgs& GetArgs() const { return args; }

	private:
		Ref<IWebSocketClient> target;
		std::string name;
		MValueArgs args;
	};
} // namespace alt
