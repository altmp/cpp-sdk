#pragma once

#include <cstdint>

#include "deps/alt-math/alt-math.h"
#include "IBaseObject.h"

namespace alt
{
	class IWorldObject : public virtual IBaseObject
	{
	public:
		virtual Position GetPosition() const = 0;
		virtual int16_t GetDimension() const = 0;

#ifdef ALT_SERVER_API
		virtual void SetPosition(Position pos) = 0;
		virtual void SetDimension(int16_t dimension) = 0;
#endif // ALT_SERVER_API

	protected:
		virtual ~IWorldObject() = default;
	};
}
