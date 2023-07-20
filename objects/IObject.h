#pragma once

#include "IEntity.h"

namespace alt
{
    class IObject : public virtual IEntity
    {
    protected:
        virtual ~IObject() = default;

    public:
		virtual uint8_t GetAlpha() const = 0;
		virtual uint8_t GetTextureVariation() const = 0;
		virtual uint16_t GetLodDistance() const = 0;

#ifdef ALT_SERVER_API
		virtual void ActivatePhysics() = 0;
		virtual void PlaceOnGroundProperly() = 0;
		virtual void SetAlpha(uint8_t alpha) = 0;
		virtual void SetTextureVariation(uint8_t textureVariation) = 0;
		virtual void SetLodDistance(uint16_t lodDistance) = 0;
#endif
    };
} // namespace alt
