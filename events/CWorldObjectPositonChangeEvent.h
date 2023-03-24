#pragma once

#include <cstdint>
#include <memory>

#include "CEvent.h"

#include "../deps/alt-math/alt-math.h"

namespace alt
{
	class IWorldObject;

	class CWorldObjectPositionChangeEvent : public CEvent
	{
	public:
		CWorldObjectPositionChangeEvent(const std::shared_ptr<IWorldObject>& _worldObject, const alt::Position& _oldPosition) :
			CEvent(Type::WORLD_OBJECT_POSITION_CHANGE),
			worldObject(_worldObject),
			oldPosition(_oldPosition)
		{

		}

		IWorldObject* GetWorldObject() const { return worldObject.get(); }
		const alt::Position& GetOldPosition() const { return oldPosition; }

	private:
		std::shared_ptr<IWorldObject> worldObject;
		alt::Position oldPosition;
	};
}
