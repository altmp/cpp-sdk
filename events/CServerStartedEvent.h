#pragma once

#include <cstdint>

#include "CEvent.h"

namespace alt
{
	class CServerStartedEvent : public CEvent
	{
	public:
		CServerStartedEvent() : CEvent(Type::SERVER_STARTED) {}
	};
}
