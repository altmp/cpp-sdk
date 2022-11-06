#pragma once

#include "../types/IConnectionInfo.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CConnectionQueueRemoveEvent : public CEvent
	{
	public:
		CConnectionQueueRemoveEvent(IConnectionInfo* _connectionInfo) :
			CEvent(Type::CONNECTION_QUEUE_REMOVE),
			connectionInfo(_connectionInfo)
		{
		}

		IConnectionInfo* GetConnectionInfo() const { return connectionInfo; }

	private:
		IConnectionInfo* connectionInfo;
	};
}
