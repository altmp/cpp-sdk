#pragma once

#include <cstdint>
#include "../Ref.h"

#include "../types/RGBA.h"
#include "../IWorldObject.h"

namespace alt
{
	class IPlayer;

	class ICheckpoint : public virtual IWorldObject
	{
	public:
		virtual ~ICheckpoint() = default;

		virtual bool IsGlobal() const = 0;
		virtual Ref<IPlayer> GetTarget() const = 0;

		virtual uint8_t GetCheckpointType() const = 0;
		virtual float GetHeight() const = 0;
		virtual float GetRadius() const = 0;
		virtual RGBA GetColor() const = 0;

		virtual bool IsEntityIn(Ref<IEntity> ent) const = 0;
	};
}
