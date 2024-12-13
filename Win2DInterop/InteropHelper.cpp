#include "pch.h"
#include "InteropHelper.h"
#include "InteropHelper.g.cpp"
#include <d2d1_3.h>
#include <dwrite.h>
#include <dwrite_1.h>
#include <dwrite_2.h>
#include <dwrite_3.h>
#include "dxgi1_2.h"
namespace winrt::Win2DInterop::implementation
{
    namespace abi {
        using namespace ABI::Microsoft::Graphics::Canvas;
    }

    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::CanvasDevice canvasDevice) 
    {
        return GetWrappedResource<ID2D1Device1, Microsoft::Graphics::Canvas::CanvasDevice>(canvasDevice);
    }

    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::CanvasBitmap canvasBitmap) 
    {
        return GetWrappedResource<ID2D1Bitmap1, Microsoft::Graphics::Canvas::CanvasBitmap>(canvasBitmap);
    }

    template<typename D2DResouce, typename Win2DObject> __int64 InteropHelper::GetWrappedResource(Win2DObject item, float dpi)
    {
        com_ptr<abi::ICanvasResourceWrapperNative> nativeDeviceWrapper = item.as<abi::ICanvasResourceWrapperNative>();
        com_ptr<D2DResouce> pDevice{ nullptr };
        check_hresult(nativeDeviceWrapper->GetNativeResource(nullptr, dpi, guid_of<D2DResouce>(), pDevice.put_void()));
        __int64 result = reinterpret_cast<__int64>(pDevice.get());
        return result;
    }

    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Geometry::CanvasCachedGeometry canvasCachedGeometry)
    {
        return GetWrappedResource<ID2D1GeometryRealization, Microsoft::Graphics::Canvas::Geometry::CanvasCachedGeometry>(canvasCachedGeometry);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::CanvasCommandList canvasCommandList)
    {
        return GetWrappedResource<ID2D1CommandList, Microsoft::Graphics::Canvas::CanvasCommandList>(canvasCommandList);

    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::CanvasDrawingSession canvasDevice)
    {
        return GetWrappedResource<ID2D1DeviceContext1, Microsoft::Graphics::Canvas::CanvasDrawingSession>(canvasDevice);

    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Text::CanvasFontFace canvasDevice)
    {
        return GetWrappedResource<IDWriteFontFaceReference, Microsoft::Graphics::Canvas::Text::CanvasFontFace>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Text::CanvasFontSet canvasDevice)
    {
        return GetWrappedResource<IDWriteFontSet, Microsoft::Graphics::Canvas::Text::CanvasFontSet>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Geometry::CanvasGeometry canvasDevice)
    {
        return GetWrappedResource<ID2D1Geometry>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Geometry::CanvasGradientMesh canvasDevice)
    {
        return GetWrappedResource<ID2D1GradientMesh>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Brushes::CanvasImageBrush canvasDevice, float dpi)
    {
        com_ptr<abi::ICanvasResourceWrapperNative> nativeDeviceWrapper = canvasDevice.as<abi::ICanvasResourceWrapperNative>();
        com_ptr<ID2D1BitmapBrush1> pDevice{ nullptr };
        auto res= check_hresult(nativeDeviceWrapper->GetNativeResource(nullptr, dpi, guid_of<ID2D1BitmapBrush1>(), pDevice.put_void()));

        if(res == 0)
        {
            __int64 result = reinterpret_cast<__int64>(pDevice.get());
            return result;
        }
        else
        {
            com_ptr<ID2D1ImageBrush> pDevice{ nullptr };
            auto res = check_hresult(nativeDeviceWrapper->GetNativeResource(nullptr, dpi, guid_of<ID2D1ImageBrush>(), pDevice.put_void()));
            __int64 result = reinterpret_cast<__int64>(pDevice.get());
            return result;
        }
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Brushes::CanvasLinearGradientBrush canvasDevice)
    {
        return GetWrappedResource<ID2D1LinearGradientBrush>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Text::CanvasNumberSubstitution canvasDevice)
    {
        return GetWrappedResource<IDWriteNumberSubstitution>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Brushes::CanvasRadialGradientBrush canvasDevice)
    {
        return GetWrappedResource<ID2D1RadialGradientBrush>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::CanvasRenderTarget canvasDevice)
    {
        return GetWrappedResource<ID2D1Bitmap1>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush canvasDevice)
    {
        return GetWrappedResource<ID2D1SolidColorBrush>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Geometry::CanvasStrokeStyle canvasDevice)
    {
        return GetWrappedResource<ID2D1StrokeStyle1>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Svg::CanvasSvgDocument canvasDevice)
    {
        return GetWrappedResource<ID2D1SvgDocument>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::CanvasSwapChain canvasDevice)
    {
        return GetWrappedResource<IDXGISwapChain1>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Text::CanvasTextFormat canvasDevice)
    {
        return GetWrappedResource<IDWriteTextFormat1>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Text::CanvasTextLayout canvasDevice)
    {
        return GetWrappedResource<IDWriteTextLayout3>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Text::CanvasTextRenderingParameters canvasDevice)
    {
        return GetWrappedResource<IDWriteRenderingParams3>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Text::CanvasTypography canvasDevice)
    {
        return GetWrappedResource<IDWriteTypography>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::CanvasVirtualBitmap canvasDevice)
    {
        com_ptr<abi::ICanvasResourceWrapperNative> nativeDeviceWrapper = canvasDevice.as<abi::ICanvasResourceWrapperNative>();
        com_ptr<ID2D1ImageSource> pDevice{ nullptr };
        auto res = check_hresult(nativeDeviceWrapper->GetNativeResource(nullptr, 0.0f, guid_of<ID2D1ImageSource>(), pDevice.put_void()));

        if (res == 0)
        {
            __int64 result = reinterpret_cast<__int64>(pDevice.get());
            return result;
        }
        else
        {
            com_ptr<ID2D1TransformedImageSource > pDevice{ nullptr };
            auto res = check_hresult(nativeDeviceWrapper->GetNativeResource(nullptr, 0.0f, guid_of<ID2D1TransformedImageSource>(), pDevice.put_void()));
            __int64 result = reinterpret_cast<__int64>(pDevice.get());
            return result;
        }
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Effects::ColorManagementProfile canvasDevice)
    {
        return GetWrappedResource<ID2D1ColorContext>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Effects::EffectTransferTable3D canvasDevice)
    {
        return GetWrappedResource<ID2D1LookupTable3D>(canvasDevice);
    }
    __int64 InteropHelper::GetWrappedResource(Microsoft::Graphics::Canvas::Effects::ICanvasEffect canvasDevice, Microsoft::Graphics::Canvas::CanvasDevice device, float dpi)
    {
        com_ptr<abi::ICanvasResourceWrapperNative> nativeDeviceWrapper = device.as<abi::ICanvasResourceWrapperNative>();
        com_ptr<ID2D1Device1> pDevice{ nullptr };
        check_hresult(nativeDeviceWrapper->GetNativeResource(nullptr, dpi, guid_of<ID2D1Device1>(), pDevice.put_void()));

        com_ptr<abi::ICanvasResourceWrapperNative> nativeDeviceWrapper2 = canvasDevice.as<abi::ICanvasResourceWrapperNative>();
        com_ptr<ID2D1Effect> pEffect{ nullptr };
        check_hresult(nativeDeviceWrapper2->GetNativeResource(device.as<abi::ICanvasDevice>().get(), dpi, guid_of<ID2D1Effect>(), pEffect.put_void()));

        __int64 result = reinterpret_cast<__int64>(pEffect.get());
        return result;
    }

}
