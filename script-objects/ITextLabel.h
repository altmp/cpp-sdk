#pragma once

#include <cstdint>
#include "../objects/IWorldObject.h"

namespace alt
{
	class ITextLabel : public virtual IWorldObject
	{
	public:
		enum Alignment {
			ALIGN_LEFT,
			ALIGN_RIGHT,
			ALIGN_CENTER,
			ALIGN_JUSTIFY
		};
		
		virtual ~ITextLabel() = default;

#ifdef ALT_CLIENT_API
		virtual bool IsStreamedIn() const = 0;
#endif

		virtual bool IsGlobal() const = 0;
		virtual IPlayer* GetTarget() const = 0;

		virtual alt::RGBA GetColor() const = 0;
		virtual void SetColor(alt::RGBA color) = 0;

		virtual alt::RGBA GetOutlineColor() const = 0;
		virtual void SetOutlineColor(alt::RGBA color) = 0;
		
		virtual float GetOutlineWidth() const = 0;
		virtual void SetOutlineWidth(float width) = 0;

		virtual float GetFontSize() const = 0;
		virtual void SetFontSize(float size) = 0;
		
		virtual Alignment GetAlign() const = 0;
		virtual void SetAlign(Alignment align) = 0;

		virtual std::string GetText() const = 0;
		virtual void SetText(const std::string& text) = 0;

		virtual std::string GetFont() const = 0;
		virtual void SetFont(const std::string& font) = 0;

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
