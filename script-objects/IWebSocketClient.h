#pragma once

#include "../objects/IBaseObject.h"

namespace alt
{
    class IWebSocketClient : public virtual IBaseObject
    {
    public:
        virtual ~IWebSocketClient() = default;

        virtual StringView GetUrl() const = 0;
        virtual void SetUrl(StringView _url) = 0;

        virtual void AddSubProtocol(StringView protocol) = 0;
        virtual alt::Array<StringView> GetSubProtocols() const = 0;

        virtual void SetExtraHeader(StringView name, StringView value) = 0;
        virtual alt::MValueDict GetExtraHeaders() const = 0;

        virtual uint8_t GetReadyState() const = 0;

        virtual bool IsAutoReconnectEnabled() const = 0;
        virtual void SetAutoReconnectEnabled(bool toggle) = 0;

        virtual bool IsPerMessageDeflateEnabled() const = 0;
        virtual void SetPerMessageDeflateEnabled(bool toggle) = 0;

        virtual void Start() = 0;
        virtual void Stop() = 0;
        virtual bool Send(StringView message) = 0;
        virtual bool SendBinary(StringView message) = 0;

        virtual void SetPingInterval(uint16_t seconds) = 0;
        virtual uint16_t GetPingInterval() const = 0;

        const std::type_info& GetTypeInfo() const override { return typeid(this); }
    };
} // namespace alt
