#pragma once

#include <cstdint>

#include "../objects/IWorldObject.h"

namespace alt
{
	class ILocalPed : public virtual IWorldObject
	{
	protected:
		virtual ~ILocalPed() = default;
	public:
		virtual uint32_t GetID() const = 0;
		virtual uint32_t GetModel() const = 0;
		virtual Rotation GetRotation() const = 0;
		virtual void SetRotation(Rotation rot) = 0;

		virtual uint32_t GetStreamingDistance() const = 0;

		virtual void SetVisible(bool toggle) = 0;
		virtual bool IsVisible() const = 0;

		virtual uint32_t GetScriptID() const = 0;

#ifdef ALT_CLIENT_API
		virtual uint32_t GetRemoteID() const = 0;
		virtual bool IsRemote() const = 0;
		virtual bool IsStreamedIn() const = 0;
#endif
	};
}