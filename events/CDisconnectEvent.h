#pragma once

#include "CEvent.h"

namespace alt
{
	class CDisconnectEvent : public CEvent
	{
	public:		
		CDisconnectEvent() :
			CEvent(Type::DISCONNECT_EVENT)
		{

		}
	};
}
