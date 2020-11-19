#pragma once

#include "IPlayer.h"

namespace alt
{
    class ILocalPlayer : public virtual IPlayer
    {
    protected:
        virtual ~ILocalPlayer() = default;

		const std::type_info& GetTypeInfo() override { return typeid(this); }
    };
} // namespace alt
