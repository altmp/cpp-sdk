#pragma once

#include "../objects/IBaseObject.h"

namespace alt
{
    class IMapData : public virtual CRefCountable
    {
    public:
        virtual ~IMapData() = default;

        virtual float GetZoomScale() = 0;
        virtual float GetZoomSpeed() = 0;
        virtual float GetScrollSpeed() = 0;
        virtual float GetTilesCountX() = 0;
        virtual float GetTilesCountY() = 0;

        virtual void SetZoomScale(float scale) = 0;
        virtual void SetZoomSpeed(float scale) = 0;
        virtual void SetScrollSpeed(float scale) = 0;
        virtual void SetTilesCountX(float val) = 0;
        virtual void SetTilesCountY(float val) = 0;
        
		const std::type_info& GetTypeInfo() override { return typeid(this); }
    };
} // namespace alt
