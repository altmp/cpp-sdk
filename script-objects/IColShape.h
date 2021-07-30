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
			CHECKPOINT_CYLINDER
		};

		virtual ~IColShape() = default;

		virtual ColShapeType GetColshapeType() const = 0;

		virtual bool IsEntityIn(Ref<IEntity> entity) const = 0;
		virtual bool IsPointIn(Vector3f point) const = 0;
		virtual void SetPlayersOnly(bool state) = 0;
		virtual bool IsPlayersOnly() const = 0;

		const std::type_info& GetTypeInfo() const override { return typeid(this); }
	};
} // namespace alt
