#pragma once

#include "../types/IConnectionInfo.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CConnectionQueueAddEvent : public CEvent
	{
	public:
		CConnectionQueueAddEvent(IConnectionInfo* _connectionInfo) :
			CEvent(Type::CONNECTION_QUEUE_ADD),
			connectionInfo(_connectionInfo)
		{
		}

		IConnectionInfo* GetConnectionInfo() const { return connectionInfo; }

	private:
		IConnectionInfo* connectionInfo;
	};
}
