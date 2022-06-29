#pragma once

#include <cstdint>

#include "../types/RGBA.h"
#include "../objects/IWorldObject.h"
#include "../objects/IEntity.h"
#include "../Ref.h"

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

		virtual ColShapeType GetColshapeType() const = 0;

		virtual bool IsEntityIn(Ref<IEntity> ent) const = 0;
		virtual bool IsEntityIdIn(uint16_t id) const = 0;
		virtual bool IsPointIn(Position p) const = 0;
		virtual void SetPlayersOnly(bool state) = 0;
		virtual bool IsPlayersOnly() const = 0;

		const std::type_info& GetTypeInfo() const override { return typeid(this); }
	};
} // namespace alt
