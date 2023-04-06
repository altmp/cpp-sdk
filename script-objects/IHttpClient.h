#pragma once

#include "../objects/IBaseObject.h"

namespace alt
{
    class IHttpClient : public virtual IBaseObject
    {
    public:
        struct HttpResponse
        {
            int statusCode;
            alt::MValueDict headers;
            std::string body;
        };

        using HttpResponseCallback = void (*)(HttpResponse httpResponse, const void* userData);

        virtual ~IHttpClient() = default;

        virtual uint32_t GetID() const = 0;

        virtual void SetExtraHeader(const std::string& name, const std::string& value) = 0;
        virtual alt::MValueDict GetExtraHeaders() const = 0;

        virtual void Get(HttpResponseCallback httpResponseCallback, const std::string& url, void* userData) const = 0;
        virtual void Head(HttpResponseCallback httpResponseCallback, const std::string& url, void* userData) const = 0;
        virtual void Post(HttpResponseCallback httpResponseCallback, const std::string& url, const std::string& body, void* userData) const = 0;
        virtual void Put(HttpResponseCallback httpResponseCallback, const std::string& url, const std::string& body, void* userData) const = 0;
        virtual void Delete(HttpResponseCallback httpResponseCallback, const std::string& url, const std::string& body, void* userData) const = 0;
        virtual void Connect(HttpResponseCallback httpResponseCallback, const std::string& url, const std::string& body, void* userData) const = 0;
        virtual void Options(HttpResponseCallback httpResponseCallback, const std::string& url, const std::string& body, void* userData) const = 0;
        virtual void Trace(HttpResponseCallback httpResponseCallback, const std::string& url, const std::string& body, void* userData) const = 0;
        virtual void Patch(HttpResponseCallback httpResponseCallback, const std::string& url, const std::string& body, void* userData) const = 0;
    };
} // namespace alt
