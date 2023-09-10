#pragma once
#ifdef ALT_SERVER_API
#include <memory>

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	// cancellable
	class CClientDeleteObjectEvent : public CCancellableEvent
	{
	public:
		CClientDeleteObjectEvent(std::shared_ptr<IPlayer> _target) :
			CCancellableEvent(Type::CLIENT_DELETE_OBJECT_EVENT),
			target(std::move(_target))
		{

		}

		IPlayer* GetTarget() const { return target.get(); }

	private:
		std::shared_ptr<IPlayer> target;
	};
}
#endif