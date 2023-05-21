#pragma once

#include "../script-objects/IConnectionInfo.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CConnectionQueueRemoveEvent : public CEvent
	{
	public:
		CConnectionQueueRemoveEvent(const std::shared_ptr<IConnectionInfo>& _connectionInfo) :
			CEvent(Type::CONNECTION_QUEUE_REMOVE),
			connectionInfo(_connectionInfo)
		{
		}

		IConnectionInfo* GetConnectionInfo() const { return connectionInfo.get(); }

	private:
		std::shared_ptr<IConnectionInfo> connectionInfo;
	};
}
