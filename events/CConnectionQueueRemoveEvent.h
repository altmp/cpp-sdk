#pragma once

#include "../Ref.h"
#include "../types/IConnectionInfo.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CConnectionQueueRemoveEvent : public CEvent
	{
	public:
		CConnectionQueueRemoveEvent(Ref<IConnectionInfo> _connectionInfo) :
			CEvent(Type::CONNECTION_QUEUE_REMOVE),
			connectionInfo(_connectionInfo)
		{
		}

		Ref<IConnectionInfo> GetConnectionInfo() const { return connectionInfo; }

	private:
		Ref<IConnectionInfo> connectionInfo;
	};
}
