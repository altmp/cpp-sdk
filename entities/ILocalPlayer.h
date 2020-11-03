#pragma once

#include "IPlayer.h"

namespace alt
{
    class ILocalPlayer : public virtual IPlayer
    {
    protected:
        virtual ~ILocalPlayer() = default;
    };
} // namespace alt
