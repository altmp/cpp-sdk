#pragma once

#include <cstdint>
#include "../objects/IBaseObject.h"
#include "../types/WebView.h"

namespace alt
{
    class IAudioOutput;

    class IWebView : public virtual IBaseObject
    {
    public:
        virtual ~IWebView() = default;
        virtual void Trigger(const std::string& eventname, const alt::MValueArgs &args) = 0;
        virtual void Focus() = 0;
        virtual void Unfocus() = 0;
        virtual bool IsFocused() const = 0;
        virtual const std::string& GetUrl() const = 0;
        virtual void SetUrl(const std::string& url) = 0;
        virtual bool IsVisible() const = 0;
        virtual void SetVisible(bool visible) = 0;
        virtual bool IsOverlay() const = 0;
        virtual bool IsLoaded() const = 0;
        virtual bool IsReady() const = 0;
        virtual void SetExtraHeader(const std::string& name, const std::string& value) = 0;
        virtual void SetCookie(const WebViewCookie& cookie) = 0;
        virtual void SetZoomLevel(double value) = 0;
        virtual Vector2i GetSize() const = 0;
        virtual void SetSize(Vector2i size) = 0;
        virtual Vector2i GetPosition() const = 0;
        virtual void SetPosition(Vector2i pos) = 0;
        virtual void Reload(bool ignoreCache) = 0;

        virtual void AddOutput(IAudioOutput* output) = 0;
        virtual void RemoveOutput(IAudioOutput* output) = 0;
        virtual MValueList GetOutputs() = 0;
    };
} // namespace alt
