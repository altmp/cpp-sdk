#pragma once

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
		const std::string& GetReason() { return reason; }

		void Cancel(const std::string& _reason)
		{
			reason = _reason;
			CEvent::Cancel();
		}

	private:
		Ref<IPlayer> target;
		std::string reason;
	};
}
