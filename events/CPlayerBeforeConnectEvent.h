#pragma once

#include "../Ref.h"
#include "../types/IConnectionInfo.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerBeforeConnectEvent : public CEvent
	{
	public:
		CPlayerBeforeConnectEvent(Ref<IConnectionInfo> _connectionInfo) :
			CEvent(Type::PLAYER_BEFORE_CONNECT),
			connectionInfo(_connectionInfo)
		{
		}

		Ref<IConnectionInfo> GetConnectionInfo() const { return connectionInfo; }
		std::string GetReason() const { return reason; }

		void Cancel(std::string _reason)
		{
			reason = _reason;
			CEvent::Cancel();
		}

	private:
		Ref<IConnectionInfo> connectionInfo;
		std::string reason;
	};
}
