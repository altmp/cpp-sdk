#pragma once

#include "IPlayer.h"

namespace alt
{
    class ILocalPlayer : public virtual IPlayer
    {
    protected:
        virtual ~ILocalPlayer() = default;

    public:
        virtual uint16_t GetCurrentAmmo() const = 0;

        virtual float GetCurrentWeaponRecoil() const = 0;
        virtual float GetCurrentWeaponSpread() const = 0;
        virtual float GetCurrentWeaponDamage() const = 0;
        virtual float GetCurrentWeaponRange() const = 0;

        const std::type_info& GetTypeInfo() const override { return typeid(this); }
    };
} // namespace alt
