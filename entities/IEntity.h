#pragma once

#include "../deps/alt-math/alt-math.h"
#include "../types/StringView.h"
#include "../types/MValue.h"
#include "../IWorldObject.h"

namespace alt
{
	class IEntity : public virtual IWorldObject
	{
	public:
		virtual uint16_t GetID() const = 0;

		virtual uint32_t GetModel() const = 0;

		virtual Rotation GetRotation() const = 0;
		virtual void SetRotation(Rotation rot) = 0;

		virtual MValue GetSyncedMetaData(StringView key) const = 0;

#ifdef ALT_SERVER_API
		virtual void SetSyncedMetaData(StringView key, MValue val) = 0;
#endif // ALT_SERVER_API

	protected:
		virtual ~IEntity() = default;
	};
}
