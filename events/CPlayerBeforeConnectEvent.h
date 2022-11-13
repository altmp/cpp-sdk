#pragma once

#include "../types/IConnectionInfo.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerBeforeConnectEvent : public CEvent
	{
	public:
		CPlayerBeforeConnectEvent(IConnectionInfo* _connectionInfo) :
			CEvent(Type::PLAYER_BEFORE_CONNECT),
			connectionInfo(_connectionInfo)
		{
		}

		IConnectionInfo* GetConnectionInfo() const { return connectionInfo; }
		std::string GetReason() const { return reason; }

		void Cancel(std::string _reason)
		{
			reason = _reason;
			CEvent::Cancel();
		}

	private:
		IConnectionInfo* connectionInfo;
		std::string reason;
	};
}
