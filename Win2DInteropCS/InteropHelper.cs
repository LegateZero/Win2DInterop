using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Microsoft.Graphics.Canvas;
using Microsoft.Graphics.Canvas.Brushes;
using Microsoft.Graphics.Canvas.Effects;
using Microsoft.Graphics.Canvas.Geometry;
using Microsoft.Graphics.Canvas.Svg;
using Microsoft.Graphics.Canvas.Text;
using Windows.Foundation.Metadata;

namespace Win2DInteropCS
{
    public static class InteropHelper
    {
        public static IntPtr GetWrappedResource(CanvasDevice canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }

      
        public static IntPtr GetWrappedResource(CanvasBitmap canvasBitmap)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasBitmap);
        }

       
        public static IntPtr GetWrappedResource(CanvasCachedGeometry canvasCachedGeometry)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasCachedGeometry);
        }


        public static IntPtr GetWrappedResource(CanvasCommandList canvasCommandList)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasCommandList);
        }


        public static IntPtr GetWrappedResource(CanvasDrawingSession canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasFontFace canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasFontSet canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasGeometry canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasGradientMesh canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasImageBrush canvasDevice, float dpi)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice, dpi);
        }


        public static IntPtr GetWrappedResource(CanvasLinearGradientBrush canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasNumberSubstitution canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasRadialGradientBrush canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }

        public static IntPtr GetWrappedResource(CanvasRenderTarget canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasSolidColorBrush canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasStrokeStyle canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasSvgDocument canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasSwapChain canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasTextFormat canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasTextLayout canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasTextRenderingParameters canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasTypography canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(CanvasVirtualBitmap canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(ColorManagementProfile canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(EffectTransferTable3D canvasDevice)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
        }


        public static IntPtr GetWrappedResource(ICanvasEffect canvasDevice, CanvasDevice device, float dpi)
        {
            return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice, device, dpi);
        }
    }
}
