#pragma once

#include <cstdint>

namespace alt
{
    struct CDecoration
    {
    public:
        uint32_t collection;
        uint32_t overlay;

        bool operator==(const CDecoration &other) const
        {
            return collection == other.collection && overlay == other.overlay;
        }
    };
}