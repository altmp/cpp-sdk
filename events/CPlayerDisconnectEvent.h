#pragma once

#include "../types/StringView.h"
#include "../types/String.h"
#include "../Ref.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerDisconnectEvent : public CEvent
	{
	public:
		CPlayerDisconnectEvent(Ref<IPlayer> _target, StringView _reason) :
			CEvent(Type::PLAYER_DISCONNECT),
			target(_target),
			reason(_reason)
		{

		}

		Ref<IPlayer> GetTarget() const { return target; }
		StringView GetReason() const { return reason; }

	private:
		Ref<IPlayer> target;
		String reason;
	};
}
