#pragma once

#include <cstdint>

#include "../objects/IBaseObject.h"

namespace alt
{
	class IVirtualEntityGroup: public virtual IBaseObject
	{
	public:
		virtual ~IVirtualEntityGroup() = default;

		virtual uint32_t GetID() const = 0;

		virtual uint32_t GetStreamingRangeLimit() const = 0;

#ifdef ALT_CLIENT_API
		virtual uint32_t GetRemoteID() const = 0;
		virtual bool IsRemote() const = 0;
#endif
	};
} // namespace alt
