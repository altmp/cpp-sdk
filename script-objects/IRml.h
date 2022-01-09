#pragma once
#include "../Ref.h"
#include "../types/Array.h"
#include <string>
#include <unordered_map>

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

        virtual bool AddPseudoClass(const std::string& name) = 0;
        virtual bool RemovePseudoClass(const std::string& name) = 0;
        virtual bool HasPseudoClass(const std::string& name) const = 0;
        virtual const std::vector<std::string> GetPseudoClassList() const = 0;

        virtual void SetOffset(Ref<IRmlElement> offsetParent, Vector2f offset, bool fixed = false) = 0;
        virtual Vector2f GetRelativeOffset() const = 0;
        virtual Vector2f GetAbsoluteOffset() const = 0;
        virtual float GetBaseline() const = 0;
        virtual float GetZIndex() const = 0;

        virtual bool IsPointWithinElement(Vector2f point) const = 0;

        virtual bool SetProperty(const std::string& name, const std::string& value) = 0;
        virtual bool RemoveProperty(const std::string& name) = 0;
        // Checks property for local element and all inherited from ancestors
        virtual bool HasProperty(const std::string& name) const = 0;
        // Only check property for local element
        virtual bool HasLocalProperty(const std::string& name) const = 0;
        virtual std::string GetProperty(const std::string& name) const = 0;
        virtual std::string GetLocalProperty(const std::string& name) const = 0;
        // Returns the relative unit (e.g. 'percent' or 'angle') as absolute value ('px' or 'rad')
        virtual float GetPropertyAbsoluteValue(const std::string& name) const = 0;

        virtual Vector2f GetContainingBlock() const = 0;

        virtual Ref<IRmlElement> GetFocusedElement() const = 0;

        virtual const std::string& GetTagName() const = 0;
        virtual const std::string& GetID() const = 0;
        virtual void SetID(const std::string& id) = 0;

        virtual bool IsOwned() const = 0;

        virtual void SetAttribute(const std::string& name, const std::string& value) = 0;
        virtual bool RemoveAttribute(const std::string& name) = 0;
        virtual bool HasAttribute(const std::string& name) const = 0;
        virtual std::string GetAttribute(const std::string& name) const = 0;
        virtual const std::unordered_map<std::string, std::string> GetAttributes() const = 0;

        virtual float GetAbsoluteLeft() const = 0;
        virtual float GetAbsoluteTop() const = 0;
        virtual float GetClientLeft() const = 0;
        virtual float GetClientTop() const = 0;
        virtual float GetClientWidth() const = 0;
        virtual float GetClientHeight() const = 0;
        virtual Ref<IRmlElement> GetOffsetParent() const = 0;
        virtual float GetOffsetLeft() const = 0;
        virtual float GetOffsetTop() const = 0;
        virtual float GetOffsetWidth() const = 0;
        virtual float GetOffsetHeight() const = 0;

        virtual float GetScrollLeft() const = 0;
        virtual void SetScrollLeft(float value) = 0;
        virtual float GetScrollTop() const = 0;
        virtual void SetScrollTop(float value) = 0;
        virtual float GetScrollWidth() const = 0;
        virtual float GetScrollHeight() const = 0;

        virtual bool IsVisible() const = 0;

        virtual Ref<IRmlElement> GetParent() const = 0;
        virtual Ref<IRmlElement> GetClosest(const std::string& selectors) const = 0;
        virtual Ref<IRmlElement> GetNextSibling() const = 0;
        virtual Ref<IRmlElement> GetPreviousSibling() const = 0;
        virtual Ref<IRmlElement> GetFirstChild() const = 0;
        virtual Ref<IRmlElement> GetLastChild() const = 0;
        virtual Ref<IRmlElement> GetChild(int index) const = 0;
        virtual int GetChildCount() const = 0;
        virtual void AppendChild(Ref<IRmlElement> element) = 0;
        virtual void InsertBefore(Ref<IRmlElement> element, Ref<IRmlElement> adjacentElement) = 0;
        virtual void ReplaceChild(Ref<IRmlElement> newElement, Ref<IRmlElement> oldElement) = 0;
        virtual void RemoveChild(Ref<IRmlElement> element) = 0;
        virtual bool HasChildren() const = 0;

        virtual std::string GetInnerRML() const = 0;
        virtual void SetInnerRML(const std::string& value) = 0;

        virtual bool Focus() = 0;
        virtual void Blur() = 0;
        virtual void Click() = 0;
        virtual void ScrollIntoView(bool alignWithTop = true) = 0;

        virtual Ref<IRmlElement> GetElementByID(const std::string& id) const = 0;
        virtual const std::vector<Ref<IRmlElement>> GetElementsByTagName(const std::string& tag) const = 0;
        virtual const std::vector<Ref<IRmlElement>> GetElementsByClassName(const std::string& tag) const = 0;
        virtual Ref<IRmlElement> QuerySelector(const std::string& selector) const = 0;
        virtual const std::vector<Ref<IRmlElement>> QuerySelectorAll(const std::string& selector) const = 0;
        
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
        virtual bool IsVisible() const override = 0;
        virtual bool IsModal() const = 0;

        virtual Ref<IRmlElement> GetBody() const = 0;
        virtual Ref<IRmlElement> GetHead() const = 0;

        virtual void Update() = 0;

        const std::type_info& GetTypeInfo() const override { return typeid(this); }
    };
}