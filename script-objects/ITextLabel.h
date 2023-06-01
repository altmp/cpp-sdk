#pragma once

#include <cstdint>
#include "../objects/IWorldObject.h"

namespace alt
{
	class ITextLabel : public virtual IWorldObject
	{
	public:
		virtual ~ITextLabel() = default;

#ifdef ALT_CLIENT_API
		virtual bool IsStreamedIn() const = 0;
#endif

		virtual bool IsGlobal() const = 0;
		virtual IPlayer* GetTarget() const = 0;

		virtual alt::RGBA GetColor() const = 0;
		virtual void SetColor(alt::RGBA color) = 0;

		virtual bool IsVisible() const = 0;
		virtual void SetVisible(bool visible) = 0;

		virtual float GetScale() const = 0;
		virtual void SetScale(float scale) = 0;

		virtual Rotation GetRotation() const = 0;
		virtual void SetRotation(Rotation _rot) = 0;

		virtual void SetFaceCamera(bool state) = 0;
		virtual bool IsFacingCamera() const = 0;

		virtual uint32_t GetStreamingDistance() const = 0;
	};
} // namespace alt
