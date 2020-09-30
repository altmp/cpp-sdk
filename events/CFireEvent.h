#pragma once

#include "../deps/alt-math/alt-math.h"
#include "../types/Array.h"

#include "CEvent.h"

namespace alt
{
	class CFireEvent : public CEvent
	{
	public:
		struct FireInfo
		{
			Position position;
			uint32_t weaponHash;
		};

		CFireEvent(Ref<IPlayer> _source, Array<FireInfo>&& _fires) :
			CEvent(Type::FIRE_EVENT),
			source(_source),
			fires(std::move(_fires))
		{

		}

		Ref<IPlayer> GetSource() const { return source; }
		const Array<FireInfo>& GetFires() const { return fires; }

	private:
		Ref<IPlayer> source;
		Array<FireInfo> fires;
	};
}
