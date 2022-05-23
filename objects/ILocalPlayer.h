#pragma once

#include "IPlayer.h"
#include "../script-objects/IWeaponData.h"

namespace alt
{
    class ILocalPlayer : public virtual IPlayer
    {
    protected:
        virtual ~ILocalPlayer() = default;

    public:
        virtual uint16_t GetCurrentAmmo() const = 0;

        virtual alt::Ref<IWeaponData> GetCurrentWeaponData() const = 0;

        const std::type_info& GetTypeInfo() const override { return typeid(this); }
    };
} // namespace alt
