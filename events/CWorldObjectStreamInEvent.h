#pragma once

#include <cstdint>
#include <memory>

#include "CEvent.h"

#include "../deps/alt-math/alt-math.h"

namespace alt
{
	class IWorldObject;

	class CWorldObjectStreamInEvent : public CEvent
	{
	public:
		CWorldObjectStreamInEvent(const std::shared_ptr<IWorldObject>& _worldObject) :
			CEvent(Type::WORLD_OBJECT_STREAM_IN),
			worldObject(_worldObject)
		{

		}

		IWorldObject* GetWorldObject() const { return worldObject.get(); }

	private:
		std::shared_ptr<IWorldObject> worldObject;
	};
}
