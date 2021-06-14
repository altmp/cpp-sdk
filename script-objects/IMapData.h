#pragma once

#include "../objects/IBaseObject.h"

namespace alt
{
    class IMapData : public virtual CRefCountable
    {
    public:
        virtual ~IMapData() = default;

        virtual float GetZoomScale() const = 0;
        virtual float GetZoomSpeed() const = 0;
        virtual float GetScrollSpeed() const = 0;
        virtual float GetTilesCountX() const = 0;
        virtual float GetTilesCountY() const = 0;

        virtual void SetZoomScale(float scale) = 0;
        virtual void SetZoomSpeed(float scale) = 0;
        virtual void SetScrollSpeed(float scale) = 0;
        virtual void SetTilesCountX(float val) = 0;
        virtual void SetTilesCountY(float val) = 0;
        
		const std::type_info& GetTypeInfo() const override { return typeid(this); }
    };
} // namespace alt
