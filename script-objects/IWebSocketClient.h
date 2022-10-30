#pragma once

#include "../objects/IBaseObject.h"

namespace alt
{
    class IWebSocketClient : public virtual IBaseObject
    {
    public:
        virtual ~IWebSocketClient() = default;

        virtual const std::string& GetUrl() const = 0;
        virtual void SetUrl(const std::string& _url) = 0;

        virtual void AddSubProtocol(const std::string& protocol) = 0;
        virtual alt::Array<std::string> GetSubProtocols() const = 0;

        virtual void SetExtraHeader(const std::string& name, const std::string& value) = 0;
        virtual alt::MValueDict GetExtraHeaders() const = 0;

        virtual uint8_t GetReadyState() const = 0;

        virtual bool IsAutoReconnectEnabled() const = 0;
        virtual void SetAutoReconnectEnabled(bool toggle) = 0;

        virtual bool IsPerMessageDeflateEnabled() const = 0;
        virtual void SetPerMessageDeflateEnabled(bool toggle) = 0;

        virtual void Start() = 0;
        virtual void Stop() = 0;
        virtual bool Send(const std::string& message) = 0;
        virtual bool SendBinary(const std::string& message) = 0;

        virtual void SetPingInterval(uint16_t seconds) = 0;
        virtual uint16_t GetPingInterval() const = 0;
    };
} // namespace alt
