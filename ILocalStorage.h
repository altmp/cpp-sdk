#pragma once

#include <cstdint>
#include "types/MValue.h"

namespace alt
{
    class ILocalStorage
    {
    protected:
        virtual ~ILocalStorage() = default;

    public:
        virtual MValueConst Get(const std::string& key) = 0;
        virtual void Set(const std::string& key, MValue value) = 0;
        virtual void Delete(const std::string& key) = 0;
        virtual void Clear() = 0;
        virtual bool Save() = 0;
    };
} // namespace alt
