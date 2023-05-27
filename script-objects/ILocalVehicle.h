#pragma once

#ifdef ALT_CLIENT_API

#include <cstdint>

#include "../objects/IVehicle.h"

namespace alt
{
	class ILocalVehicle : public virtual IVehicle
	{
	protected:
		virtual ~ILocalVehicle() = default;
	public:
		virtual void SetModel(uint32_t model) = 0;

		virtual uint32_t GetStreamingDistance() const = 0;

		virtual void SetVisible(bool toggle) = 0;
		virtual bool IsVisible() const = 0;

		virtual uint32_t GetScriptID() const = 0;

		virtual uint32_t GetRemoteID() const = 0;
		virtual bool IsRemote() const = 0;
		virtual bool IsStreamedIn() const = 0;
	};
}

#endif