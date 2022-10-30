#pragma once

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerDisconnectEvent : public CEvent
	{
	public:
		CPlayerDisconnectEvent(IPlayer* _target, const std::string& _reason) :
			CEvent(Type::PLAYER_DISCONNECT),
			target(_target),
			reason(_reason)
		{

		}

		IPlayer* GetTarget() const { return target; }
		const std::string& GetReason() const { return reason; }

	private:
		IPlayer* target;
		std::string reason;
	};
}
