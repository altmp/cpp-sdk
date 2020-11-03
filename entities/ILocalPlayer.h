#pragma once

#include "IPlayer.h"

namespace alt
{
    class ILocalPlayer : public virtual IPlayer
    {
    public:
        virtual ~ILocalPlayer() = default;
    };
} // namespace alt
