#pragma once

namespace alt
{
    class IDiscordManager
    {
    protected:
        virtual ~IDiscordManager() = default;

    public:
        virtual bool IsUserDataReady() = 0;
        virtual std::string GetUserID() = 0;
        virtual std::string GetUsername() = 0;
        virtual std::string GetDiscriminator() = 0;
        virtual std::string GetAvatar() = 0;
    };
} // namespace alt
