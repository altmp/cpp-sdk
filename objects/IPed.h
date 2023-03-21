#pragma once

#include "IEntity.h"

namespace alt
{
    class IPed : public virtual IEntity
    {
    protected:
        virtual ~IPed() = default;

    public:
        virtual uint16_t GetHealth() const = 0;
        virtual uint16_t GetMaxHealth() const = 0;

        virtual uint16_t GetArmour() const = 0;

        virtual uint32_t GetCurrentWeapon() const = 0;
        
#ifdef ALT_SERVER_API
        virtual void SetHealth(uint16_t health) = 0;
        virtual void SetMaxHealth(uint16_t health) = 0;

        virtual void SetArmour(uint16_t armor) = 0;

        virtual void SetCurrentWeapon(uint32_t weapon) = 0;
#endif

    };
} // namespace alt
