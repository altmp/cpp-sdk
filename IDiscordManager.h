#pragma once

namespace alt
{
    class IDiscordManager
    {
    protected:
        virtual ~IDiscordManager() = default;

    public:
        virtual bool IsUserDataReady() = 0;
        virtual int64_t GetUserID() = 0;
        virtual std::string GetUsername() = 0;
        virtual std::string GetDiscriminator() = 0;
        virtual std::string GetAvatar() = 0;
    };
} // namespace alt
