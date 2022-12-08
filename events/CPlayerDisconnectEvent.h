#pragma once

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	class CPlayerDisconnectEvent : public CEvent
	{
	public:
		CPlayerDisconnectEvent(const std::shared_ptr<IPlayer>& _target, const std::string& _reason) :
			CEvent(Type::PLAYER_DISCONNECT),
			target(_target),
			reason(_reason)
		{

		}

		IPlayer* GetTarget() const { return target.get(); }
		const std::string& GetReason() const { return reason; }

	private:
		std::shared_ptr<IPlayer> target;
		std::string reason;
	};
}
