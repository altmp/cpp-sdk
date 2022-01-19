#pragma once

#include "../types/StringView.h"
#include "../types/String.h"
#include "../Ref.h"
#include "../types/ConnectionInfo.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerBeforeConnectEvent : public CEvent
	{
	public:
		CPlayerBeforeConnectEvent(Ref<ConnectionInfo> _connectionInfo) :
			CEvent(Type::PLAYER_BEFORE_CONNECT),
			connectionInfo(_connectionInfo)
		{
		}

		Ref<ConnectionInfo> GetConnectionInfo() const { return connectionInfo; }
		std::string GetReason() const { return reason; }

		void Cancel(std::string _reason)
		{
			reason = _reason;
			CEvent::Cancel();
		}

	private:
		Ref<ConnectionInfo> connectionInfo;
		std::string reason;
	};
}
