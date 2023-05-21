#pragma once

#include <cstdint>

#include "../types/RGBA.h"
#include "../objects/IWorldObject.h"
#include "../objects/IEntity.h"

namespace alt
{
	class IEntity;

	class IColShape : public virtual IWorldObject
	{
	public:
		enum class ColShapeType : uint8_t
		{
			SPHERE,
			CYLINDER,
			CIRCLE,
			CUBOID,
			RECT,
			CHECKPOINT_CYLINDER,
			POLYGON
		};

		virtual ~IColShape() = default;

#ifdef ALT_CLIENT_API
		virtual uint32_t GetRemoteID() const = 0;
		virtual bool IsRemote() const = 0;
#endif

		virtual ColShapeType GetColshapeType() const = 0;

		virtual bool IsEntityIn(IEntity* ent) const = 0;
		virtual bool IsEntityIdIn(uint16_t id) const = 0;
		virtual bool IsPointIn(Position p) const = 0;
		virtual void SetPlayersOnly(bool state) = 0;
		virtual bool IsPlayersOnly() const = 0;
	};
} // namespace alt
