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
        
        const std::type_info& GetTypeInfo() const override { return typeid(this); }
    };

    class IRmlDocument : public IRmlElement
    {
    public:
        virtual ~IRmlDocument() = default;

        const std::type_info& GetTypeInfo() const override { return typeid(this); }
    };
}