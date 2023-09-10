#pragma once

#include <vector>

#include "../deps/alt-math/alt-math.h"

#include "CEvent.h"

namespace alt
{
	class CFireEvent : public CCancellableEvent
	{
	public:
		struct FireInfo
		{
			Position position;
			uint32_t weaponHash;

			FireInfo(const Position& _position, uint32_t _weaponHash): position(_position), weaponHash(_weaponHash) {}

			FireInfo() = default;
		};

		CFireEvent(const std::shared_ptr<IPlayer>& _source, std::vector<FireInfo>&& _fires) :
			CCancellableEvent(Type::FIRE_EVENT),
			source(_source),
			fires(std::move(_fires))
		{

		}

		IPlayer* GetSource() const { return source.get(); }
		const std::vector<FireInfo>& GetFires() const { return fires; }

	private:
		std::shared_ptr<IPlayer> source;
		std::vector<FireInfo> fires;
	};
}
