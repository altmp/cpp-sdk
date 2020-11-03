#pragma once

#include <cstdint>
#include "types/String.h"
#include "types/MValue.h"

namespace alt
{
    class ILocalStorage
    {
    protected:
        virtual ~ILocalStorage() = default;

    public:
        virtual MValueConst Get(StringView key) const = 0;
        virtual void Set(StringView key, MValue) const = 0;
        virtual void Delete(StringView key) const = 0;
        virtual void Clear() const = 0;
        virtual bool Save() const = 0;
    };
} // namespace alt
