#pragma once

#include <cstdint>
#include "../objects/IWorldObject.h"

namespace alt
{
	class ITextLabel : public virtual IWorldObject
	{
	public:
		virtual ~ITextLabel() = default;

		virtual uint32_t GetID() const = 0;

#ifdef ALT_CLIENT_API
		virtual bool IsRemote() const = 0;
		virtual uint32_t GetRemoteID() const = 0;
#endif

		virtual bool IsGlobal() const = 0;
		virtual IPlayer* GetTarget() const = 0;

		virtual alt::RGBA GetColor() const = 0;
		virtual void SetColor(alt::RGBA color) = 0;

		virtual bool GetVisible() const = 0;
		virtual void SetVisible(bool visible) = 0;

		virtual float GetScale() const = 0;
		virtual void SetScale(float scale) = 0;

		virtual Rotation GetRotation() const = 0;
		virtual void SetRotation(Rotation _rot) = 0;
	};
} // namespace alt
