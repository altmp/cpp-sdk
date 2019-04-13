#pragma once

#include <cstdint>

#include "CEvent.h"

namespace alt
{
	class CConnectionCompleteEvent : public CEvent
	{
	public:		
		CConnectionCompleteEvent(bool _anyMapLoaded) :
			CEvent(Type::CONNECTION_COMPLETE),
			isAnyMapLoaded(_anyMapLoaded)
		{

		}

		bool IsAnyMapLoaded() const { return isAnyMapLoaded; }

	private:
		bool isAnyMapLoaded;
	};
}
