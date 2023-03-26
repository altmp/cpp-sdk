#pragma once

#include "IEntity.h"

namespace alt
{
    class INetworkObject : public virtual IEntity
    {
    protected:
        virtual ~INetworkObject() = default;

    public:
		virtual uint8_t GetAlpha() const = 0;
		virtual uint8_t GetTextureVariation() const = 0;
		virtual uint16_t GetLodDistance() const = 0;

#ifdef ALT_SERVER_API
		virtual void ActivatePhysics() const = 0;
		virtual void PlaceOnGroundProperly() const = 0;
		virtual void SetAlpha(uint8_t alpha) = 0;
		virtual void SetTextureVariation(uint8_t textureVariation) = 0;
		virtual void SetLodDistance(uint16_t lodDistance) = 0;
#endif
    };
} // namespace alt
