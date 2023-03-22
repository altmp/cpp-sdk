#pragma once

#include <cstdint>

#include "../objects/IWorldObject.h"

namespace alt
{
	class IVirtualEntity : public virtual IWorldObject
	{
	public:
		virtual ~IVirtualEntity() = default;

		virtual uint32_t GetStreamingDistance() const = 0;
	};
} // namespace alt
