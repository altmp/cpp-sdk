#pragma once
#include "../Ref.h"
#include "../types/Array.h"
#include <string>

namespace alt
{
    class IRmlElement : public virtual IBaseObject
    {
    public:
        virtual ~IRmlElement() = default;

        virtual bool AddClass(const std::string& name) = 0;
        virtual bool RemoveClass(const std::string& name) = 0;
        virtual bool HasClass(const std::string& name) const = 0;
        virtual const std::vector<std::string> GetClassList() const = 0;

        virtual void SetOffset(Ref<IRmlElement> offsetParent, Vector2f offset, bool fixed = false) = 0;
        virtual Vector2f GetRelativeOffset() const = 0;
        virtual Vector2f GetAbsoluteOffset() const = 0;
        virtual float GetBaseline() const = 0;

        virtual bool IsPointWithinElement(Vector2f point) const = 0;

        virtual float GetZIndex() const = 0;

        virtual bool SetProperty(const std::string& name, const std::string& value) = 0;
        virtual bool RemoveProperty(const std::string& name) = 0;
        // Checks property for local element and all inherited from ancestors
        virtual bool HasProperty(const std::string& name) const = 0;
        // Only check property for local element
        virtual bool HasLocalProperty(const std::string& name) const = 0;
        virtual const std::string& GetProperty(const std::string& name) const = 0;
        virtual const std::string& GetLocalProperty(const std::string& name) const = 0;
        // Returns the relative unit (e.g. 'percent' or 'angle') as absolute value ('px' or 'rad')
        virtual float GetPropertyAbsoluteValue(const std::string& name) const = 0;
        
        const std::type_info& GetTypeInfo() const override { return typeid(this); }
    };

    class IRmlDocument : public virtual IRmlElement
    {
    public:
        virtual ~IRmlDocument() = default;

        virtual void SetTitle(const std::string& title) = 0;
        virtual const std::string& GetTitle() const = 0;
        virtual const std::string& GetSourceUrl() const = 0;

        virtual Ref<IRmlElement> CreateElement(const std::string& name) = 0;
        virtual Ref<IRmlElement> CreateTextNode(const std::string& text) = 0;

        virtual void Hide() = 0;
        virtual void Show(bool isModal = false, bool focused = true) = 0;
        virtual bool IsVisible() const = 0;
        virtual bool IsModal() const = 0;

        virtual void Update() = 0;

        const std::type_info& GetTypeInfo() const override { return typeid(this); }
    };
}