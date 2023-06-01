#pragma once

#include <cstdint>

#include "../objects/IBaseObject.h"

namespace alt
{
	class IVirtualEntityGroup: public virtual IBaseObject
	{
	public:
		virtual ~IVirtualEntityGroup() = default;

		virtual uint32_t GetMaxEntitiesInStream() const = 0;
	};
} // namespace alt
