#pragma once

#include "../Ref.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerDisconnectEvent : public CEvent
	{
	public:
		CPlayerDisconnectEvent(Ref<IPlayer> _target, const std::string& _reason) :
			CEvent(Type::PLAYER_DISCONNECT),
			target(_target),
			reason(_reason)
		{

		}

		Ref<IPlayer> GetTarget() const { return target; }
		const std::string& GetReason() const { return reason; }

	private:
		Ref<IPlayer> target;
		std::string reason;
	};
}
