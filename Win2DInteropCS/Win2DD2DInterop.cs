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
	/// <summary>
	/// Collection of methods that return pointer to underline D2D class of Win2D wrapper.
	/// </summary>
	public static class Win2DD2DInterop
	{
		#region Public Methods

		public static IntPtr GetWrappedResource(this CanvasDevice canvasDevice)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDevice);
		}

		public static IntPtr GetWrappedResource(this CanvasBitmap canvasBitmap)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasBitmap);
		}

		public static IntPtr GetWrappedResource(this CanvasCachedGeometry canvasCachedGeometry)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasCachedGeometry);
		}

		public static IntPtr GetWrappedResource(this CanvasCommandList canvasCommandList)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasCommandList);
		}

		public static IntPtr GetWrappedResource(this CanvasDrawingSession canvasDrawingSession)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasDrawingSession);
		}

		public static IntPtr GetWrappedResource(this CanvasFontFace canvasFontFace)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasFontFace);
		}

		public static IntPtr GetWrappedResource(this CanvasFontSet canvasFontSet)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasFontSet);
		}

		public static IntPtr GetWrappedResource(this CanvasGeometry canvasGeometry)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasGeometry);
		}

		public static IntPtr GetWrappedResource(this CanvasGradientMesh canvasGradientMesh)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasGradientMesh);
		}

		public static IntPtr GetWrappedResource(this CanvasImageBrush canvasImageBrush, float dpi)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasImageBrush, dpi);
		}

		public static IntPtr GetWrappedResource(this CanvasLinearGradientBrush canvasLinearGradientBrush)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasLinearGradientBrush);
		}

		public static IntPtr GetWrappedResource(this CanvasNumberSubstitution canvasNumberSubstitution)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasNumberSubstitution);
		}

		public static IntPtr GetWrappedResource(this CanvasRadialGradientBrush canvasRadialGradientBrush)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasRadialGradientBrush);
		}

		public static IntPtr GetWrappedResource(this CanvasRenderTarget canvasRenderTarget)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasRenderTarget);
		}

		public static IntPtr GetWrappedResource(this CanvasSolidColorBrush canvasSolidColorBrush)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasSolidColorBrush);
		}

		public static IntPtr GetWrappedResource(this CanvasStrokeStyle canvasStrokeStyle)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasStrokeStyle);
		}

		public static IntPtr GetWrappedResource(this CanvasSvgDocument canvasSvgDocument)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasSvgDocument);
		}

		public static IntPtr GetWrappedResource(this CanvasSwapChain canvasSwapChain)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasSwapChain);
		}

		public static IntPtr GetWrappedResource(this CanvasTextFormat canvasTextFormat)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasTextFormat);
		}

		public static IntPtr GetWrappedResource(this CanvasTextLayout canvasTextLayout)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasTextLayout);
		}

		public static IntPtr GetWrappedResource(this CanvasTextRenderingParameters canvasTextRenderingParamters)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasTextRenderingParamters);
		}

		public static IntPtr GetWrappedResource(this CanvasTypography canvasTypography)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasTypography);
		}

		public static IntPtr GetWrappedResource(this CanvasVirtualBitmap canvasVirtualBitmap)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasVirtualBitmap);
		}

		public static IntPtr GetWrappedResource(this ColorManagementProfile colorManagementProfile)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(colorManagementProfile);
		}

		public static IntPtr GetWrappedResource(this EffectTransferTable3D effectTransferTable3D)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(effectTransferTable3D);
		}

		public static IntPtr GetWrappedResource(this ICanvasEffect canvasEffect, CanvasDevice device, float dpi)
		{
			return (IntPtr)Win2DInterop.InteropHelper.GetWrappedResource(canvasEffect, device, dpi);
		}

		#endregion Public Methods
	}
}
