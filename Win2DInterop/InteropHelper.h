#pragma once

#include "InteropHelper.g.h"

namespace winrt::Win2DInterop::implementation
{
    struct InteropHelper : InteropHelperT<InteropHelper>
    {
        InteropHelper() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::Win2DInterop::factory_implementation
{
    struct InteropHelper :InteropHelperT<InteropHelper, implementation::InteropHelper>
    {
    };
}
