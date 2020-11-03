#pragma once

#include <cstdint>
#include "../entities/IBaseObject.h"

namespace alt
{
    class IWebView : public virtual IBaseObject
    {
    public:
        virtual ~IWebView() = default;
        virtual void Trigger(alt::StringView eventname, const alt::MValueArgs &args) = 0;
        virtual void Focus() = 0;
        virtual void Unfocus() = 0;
        virtual bool IsFocused() const = 0;
        virtual String GetUrl() const = 0;
        virtual void SetUrl(alt::StringView url) = 0;
        virtual bool IsVisible() const = 0;
        virtual void SetVisible(bool visible) = 0;
        virtual bool IsOverlay() const = 0;
        virtual bool IsReady() const = 0;
    };
} // namespace alt