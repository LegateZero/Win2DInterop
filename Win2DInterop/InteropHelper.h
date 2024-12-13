#pragma once

#include "InteropHelper.g.h"

namespace winrt::Win2DInterop::implementation
{
    static struct InteropHelper
    {
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::CanvasDevice canvasDevice);

        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::CanvasBitmap canvasBitmap);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Geometry::CanvasCachedGeometry canvasCachedGeometry);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::CanvasCommandList canvasCommandList);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::CanvasDrawingSession canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Text::CanvasFontFace canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Text::CanvasFontSet canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Geometry::CanvasGeometry canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Geometry::CanvasGradientMesh canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Brushes::CanvasImageBrush canvasDevice, float dpi);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Brushes::CanvasLinearGradientBrush canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Text::CanvasNumberSubstitution canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Brushes::CanvasRadialGradientBrush canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::CanvasRenderTarget canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Brushes::CanvasSolidColorBrush canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Geometry::CanvasStrokeStyle canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Svg::CanvasSvgDocument canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::CanvasSwapChain canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Text::CanvasTextFormat canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Text::CanvasTextLayout canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Text::CanvasTextRenderingParameters canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Text::CanvasTypography canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::CanvasVirtualBitmap canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Effects::ColorManagementProfile canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Effects::EffectTransferTable3D canvasDevice);
        static __int64 GetWrappedResource(Microsoft::Graphics::Canvas::Effects::ICanvasEffect canvasDevice, Microsoft::Graphics::Canvas::CanvasDevice device, float dpi);

    private:
        template<typename D2DResouce, typename Win2DObject> static __int64 GetWrappedResource(Win2DObject item, float dpi = 0.0f);
    };
}

namespace winrt::Win2DInterop::factory_implementation
{
    struct InteropHelper :InteropHelperT<InteropHelper, implementation::InteropHelper>
    {
    };
}
