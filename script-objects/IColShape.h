#pragma once

#include <cstdint>

#include "../types/RGBA.h"
#include "../IWorldObject.h"
#include "../entities/IEntity.h"
#include "../Ref.h"

namespace alt
{
	enum class ColShapeType: uint8_t {
		ColshapeSphere,
		ColshapeCylinder,
		ColshapeCircle,
		ColshapeCube,
		ColshapeRect
	};

	class IEntity;

	class IColShape : public virtual IWorldObject
	{
	public:
		virtual ~IColShape() = default;

		virtual ColShapeType GetColshapeType() const = 0;

		virtual bool IsEntityIn(Ref<IEntity> ent) const = 0;
	};
}
