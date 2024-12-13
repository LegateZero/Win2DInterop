#include "pch.h"
#include "InteropHelper.h"
#include "InteropHelper.g.cpp"

namespace winrt::Win2DInterop::implementation
{
    int32_t InteropHelper::MyProperty()
    {
        return 10;
    }

    void InteropHelper::MyProperty(int32_t val)
    {
       
    }
}
