#pragma once

#include "../types/StringView.h"
#include "../types/String.h"
#include "../Ref.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerConnectEvent : public CEvent
	{
	public:
		CPlayerConnectEvent(Ref<IPlayer> _target) :
			CEvent(Type::PLAYER_CONNECT),
			target(_target)
		{
		}

		Ref<IPlayer> GetTarget() const { return target; }
		StringView GetReason() { return reason; }

		void Cancel(StringView _reason)
		{
			reason = _reason;
			CEvent::Cancel();
		}

	private:
		Ref<IPlayer> target;
		String reason;
	};
}
