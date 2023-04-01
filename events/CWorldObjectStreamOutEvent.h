#pragma once

#include <cstdint>
#include <memory>

#include "CEvent.h"

#include "../deps/alt-math/alt-math.h"

namespace alt
{
	class IWorldObject;

	class CWorldObjectStreamOutEvent : public CEvent
	{
	public:
		CWorldObjectStreamOutEvent(const std::shared_ptr<IWorldObject>& _worldObject) :
			CEvent(Type::WORLD_OBJECT_STREAM_OUT),
			worldObject(_worldObject)
		{

		}

		IWorldObject* GetWorldObject() const { return worldObject.get(); }

	private:
		std::shared_ptr<IWorldObject> worldObject;
	};
}
