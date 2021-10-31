#pragma once

#include "../types/StringView.h"
#include "../types/String.h"
#include "../Ref.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerBeforeConnectEvent : public CEvent
	{
	public:
		CPlayerBeforeConnectEvent(Ref<IPlayer> _target, uint64_t _passwordHash, StringView _cdnUrl) :
			CEvent(Type::PLAYER_BEFORE_CONNECT),
			target(_target), passwordHash(_passwordHash), cdnUrl(_cdnUrl)
		{
		}

		Ref<IPlayer> GetTarget() const { return target; }
		uint64_t GetPasswordHash() const { return passwordHash; }
		StringView GetCdnUrl() const { return cdnUrl; }
		StringView GetReason() { return reason; }

		void Cancel(StringView _reason)
		{
			reason = _reason;
			CEvent::Cancel();
		}

	private:
		Ref<IPlayer> target;
		uint64_t passwordHash;
		StringView cdnUrl;
		String reason;
	};
}
