#pragma once

#include <cstdint>

#include "../deps/alt-math/alt-math.h"
#include "IBaseObject.h"

namespace alt
{
	class IWorldObject : public virtual IBaseObject
	{
	protected:
		virtual ~IWorldObject() = default;

	public:
		virtual Vector3f GetPosition() const = 0;
		virtual void SetPosition(Vector3f pos) = 0;

		virtual int32_t GetDimension() const = 0;
		virtual void SetDimension(int32_t dimension) = 0;
	};
} // namespace alt
