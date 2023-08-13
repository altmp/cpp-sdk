#pragma once
#ifdef ALT_SERVER_API
#include <memory>
#include <cstdint>
#include "../deps/alt-math/alt-math.h"

#include "CEvent.h"

namespace alt
{
	class IPlayer;

	// cancellable
	class CClientRequestObjectEvent : public CEvent
	{
	public:
		CClientRequestObjectEvent(std::shared_ptr<IPlayer> _target, const uint32_t _model, const alt::Position& _position) :
			CEvent(Type::CLIENT_REQUEST_OBJECT_EVENT),
			target(std::move(_target)),
			model(_model),
			position(_position)
		{

		}

		IPlayer* GetTarget() const { return target.get(); }
		uint32_t GetModel() const { return model; }
		alt::Position GetPosition() const { return position; }

	private:
		std::shared_ptr<IPlayer> target;
		uint32_t model;
		alt::Position position;
	};
}
#endif
