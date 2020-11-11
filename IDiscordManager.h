#pragma once

#include "types/String.h"

namespace alt
{
    class IDiscordManager
    {
    protected:
        virtual ~IDiscordManager() = default;

    public:
        virtual bool IsUserDataReady() = 0;
        virtual alt::String GetUserID() = 0;
        virtual alt::String GetUsername() = 0;
        virtual alt::String GetDiscriminator() = 0;
        virtual alt::String GetAvatar() = 0;
    };
} // namespace alt
