#pragma once

#include <cstdint>

#include "CEvent.h"

namespace alt
{
	class CConnectionCompleteEvent : public CEvent
	{
	public:		
		CConnectionCompleteEvent() :
			CEvent(Type::CONNECTION_COMPLETE)
		{

		}
	};
}
