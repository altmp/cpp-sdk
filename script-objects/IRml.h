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

        virtual void SetOffset(Ref<IRmlElement> offsetParent, alt::Vector2f offset, bool fixed = false) = 0;
        
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