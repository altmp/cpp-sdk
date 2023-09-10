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

		virtual ColShapeType GetColshapeType() const = 0;

		virtual bool IsEntityIn(IEntity* ent) const = 0;
		virtual bool IsEntityIdIn(uint16_t id) const = 0;
		virtual bool IsPointIn(Position p) const = 0;
		virtual void SetPlayersOnly(bool state) = 0;
		virtual bool IsPlayersOnly() const = 0;
	};

	class IColShapeSphere : public virtual IColShape
	{
	public:
		virtual float GetRadius() const = 0;
	};

	class IColShapeCylinder : public virtual IColShape
	{
	public:
		virtual float GetRadius() const = 0;
		virtual float GetHeight() const = 0;
	};

	class IColShapeCircle : public virtual IColShape
	{
	public:
		virtual float GetRadius() const = 0;
	};

	class IColShapeCuboid : public virtual IColShape
	{
	public:
		virtual Position GetMin() const = 0;
		virtual Position GetMax() const = 0;
	};

	class IColShapeRect : public virtual IColShape
	{
	public:
		virtual Vector2f GetMin() const = 0;
		virtual Vector2f GetMax() const = 0;
	};

	class IColShapePoly : public virtual IColShape
	{
	public:
		virtual float GetMinZ() const = 0;
		virtual float GetMaxZ() const = 0;

		virtual std::vector<Vector2f> GetPoints() const = 0;
	};

} // namespace alt
