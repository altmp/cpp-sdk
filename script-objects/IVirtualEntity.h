#pragma once

#include <cstdint>

#include "../objects/IWorldObject.h"

namespace alt
{
	class IVirtualEntity : public virtual IWorldObject
	{
	public:
		virtual ~IVirtualEntity() = default;
	};
} // namespace alt
