#pragma once

#include <cstdint>

#include "../objects/IWorldObject.h"
#include "../script-objects/IVirtualEntityGroup.h"

namespace alt
{
	class IVirtualEntity : public virtual IWorldObject
	{
	public:
		virtual ~IVirtualEntity() = default;

		virtual uint32_t GetID() const = 0;

		virtual uint32_t GetStreamingDistance() const = 0;

		virtual IVirtualEntityGroup* GetGroup() const = 0;
	};
} // namespace alt
