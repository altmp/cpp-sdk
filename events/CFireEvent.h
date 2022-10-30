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

		CFireEvent(IPlayer* _source, Array<FireInfo>&& _fires) :
			CEvent(Type::FIRE_EVENT),
			source(_source),
			fires(std::move(_fires))
		{

		}

		IPlayer* GetSource() const { return source; }
		const Array<FireInfo>& GetFires() const { return fires; }

	private:
		IPlayer* source;
		Array<FireInfo> fires;
	};
}
