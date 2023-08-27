#pragma once

#include <cstdint>

namespace alt
{
    struct CDecoration
    {
    public:
        uint32_t collection;
        uint32_t overlay;

        bool operator==(CDecoration other) const
        {
            return collection == other.collection && overlay == other.overlay;
        }
    };
}