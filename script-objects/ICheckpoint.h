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

		const std::type_info& GetTypeInfo() override { return typeid(this); }
	};
}
