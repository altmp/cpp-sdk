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
        virtual MValueConst Get(StringView key) = 0;
        virtual void Set(StringView key, MValue value) = 0;
        virtual void Delete(StringView key) = 0;
        virtual void Clear() = 0;
        virtual bool Save() = 0;
    };
} // namespace alt
