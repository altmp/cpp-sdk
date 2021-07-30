#pragma once

#include <cstdint>
#include "../Ref.h"

#include "../types/RGBA.h"
#include "IColShape.h"

namespace alt
{
	class IPlayer;

	class ICheckpoint : public virtual IColShape
	{
	public:
		virtual ~ICheckpoint() = default;

		virtual uint8_t GetCheckpointType() const = 0;
		virtual float GetHeight() const = 0;
		virtual float GetRadius() const = 0;
		virtual RGBA GetColor() const = 0;
		virtual Vector3f GetNextPosition() const = 0;

		virtual void SetCheckpointType(uint8_t type) = 0;
		virtual void SetHeight(float height) = 0;
		virtual void SetRadius(float radius) = 0;
		virtual void SetColor(RGBA color) = 0;
		virtual void SetNextPosition(Vector3f pos) = 0;

		const std::type_info& GetTypeInfo() const override { return typeid(this); }
	};
}
