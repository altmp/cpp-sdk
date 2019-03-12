#pragma once

#include <cstdint>

#include "../types/RGBA.h"
#include "../IWorldObject.h"

namespace alt
{
	class IPlayer;

	class ICheckpoint : public virtual IWorldObject
	{
	public:
		virtual bool IsGlobal() const = 0;
		virtual IPlayer* GetTarget() const = 0;

		virtual uint8_t GetCheckpointType() const = 0;
		virtual float GetHeight() const = 0;
		virtual float GetRadius() const = 0;
		virtual RGBA GetColor() const = 0;

		virtual bool IsEntityIn(IEntity* ent) const = 0;

	protected:
		virtual ~ICheckpoint() = default;
	};
}
