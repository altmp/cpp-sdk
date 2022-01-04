#pragma once

#include <cstdint>

#include "CEvent.h"

namespace alt
{
	class CSpawnedEvent : public CEvent
	{
	public:
		CSpawnedEvent() : CEvent(Type::SPAWNED) {}
	};
}
