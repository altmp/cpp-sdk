#pragma once

#include "../objects/IBaseObject.h"

namespace alt
{
    class IHttpClient : public virtual IBaseObject
    {
        struct HttpResponse
        {
            int statusCode;
            alt::MValueDict headers;
            StringView body;
        };

        using HttpResponseCallback = void (*)(HttpResponse httpResponse, const void* userData);

    public:
        virtual ~IHttpClient() = default;

        virtual void SetExtraHeader(StringView name, StringView value) = 0;
        virtual alt::MValueDict GetExtraHeaders() const = 0;

        virtual void Get(HttpResponseCallback httpResponseCallback, StringView url) const = 0;
        virtual void Head(HttpResponseCallback httpResponseCallback, StringView url) const = 0;
        virtual void Post(HttpResponseCallback httpResponseCallback, StringView url, StringView body) const = 0;
        virtual void Put(HttpResponseCallback httpResponseCallback, StringView url, StringView body) const = 0;
        virtual void Delete(HttpResponseCallback httpResponseCallback, StringView url, StringView body) const = 0;
        virtual void Connect(HttpResponseCallback httpResponseCallback, StringView url, StringView body) const = 0;
        virtual void Options(HttpResponseCallback httpResponseCallback, StringView url, StringView body) const = 0;
        virtual void Trace(HttpResponseCallback httpResponseCallback, StringView url, StringView body) const = 0;
        virtual void Patch(HttpResponseCallback httpResponseCallback, StringView url, StringView body) const = 0;

        const std::type_info& GetTypeInfo() const override { return typeid(this); }
    };
} // namespace alt
