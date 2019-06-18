#pragma once

#include <cstdint>

#include "../types/RGBA.h"
#include "../IWorldObject.h"
#include "../entities/IEntity.h"

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
		virtual ColShapeType GetColshapeType() const = 0;

		virtual bool IsEntityIn(IEntity* ent) const = 0;

	protected:
		virtual ~IColShape() = default;
	};
}
