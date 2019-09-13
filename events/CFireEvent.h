#pragma once

#include "CEvent.h"

namespace alt
{
	// TODO
	class CFireEvent : public CEvent
	{
	public:
		CFireEvent() :
			CEvent(Type::FIRE_EVENT)
		{

		}

	private:
	};
}
