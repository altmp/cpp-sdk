#pragma once

#include "../types/StringView.h"
#include "../types/String.h"
#include "../Ref.h"
#include "../types/IConnectionInfo.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CConnectionQueueAddEvent : public CEvent
	{
	public:
		CConnectionQueueAddEvent(Ref<IConnectionInfo> _connectionInfo) :
			CEvent(Type::CONNECTION_QUEUE_ADD),
			connectionInfo(_connectionInfo)
		{
		}

		Ref<IConnectionInfo> GetConnectionInfo() const { return connectionInfo; }

	private:
		Ref<IConnectionInfo> connectionInfo;
	};
}
