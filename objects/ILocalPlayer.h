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
#ifdef ALT_CLIENT_API
        virtual uint16_t GetCurrentAmmo() const = 0;

        virtual uint16_t GetWeaponAmmo(uint32_t weaponHash) const = 0;
        virtual bool HasWeapon(uint32_t weaponHash) const = 0;
        virtual std::vector<uint32_t> GetWeapons() const = 0;

        virtual alt::Ref<IWeaponData> GetCurrentWeaponData() const = 0;
#endif

        const std::type_info& GetTypeInfo() const override { return typeid(this); }
    };
} // namespace alt
