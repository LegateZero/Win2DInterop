#include "pch.h"
#include "InteropHelper.h"
#include "InteropHelper.g.cpp"
#include <d2d1_3.h>
#include <dwrite.h>
#include <dwrite_1.h>
#include <dwrite_2.h>
#include <dwrite_3.h>
#include "dxgi1_2.h"
#include "d3d11.h"
#include "d3d11_1.h"

namespace winrt::Win2DInterop::implementation
{
	namespace abi {
		using namespace ABI::Microsoft::Graphics::Canvas;
	}


	EGLConfig InteropHelper::_config = nullptr;
	EGLDisplay InteropHelper::_display = nullptr;
	EGLContext InteropHelper::_context = nullptr;

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
		auto res = check_hresult(nativeDeviceWrapper->GetNativeResource(nullptr, dpi, guid_of<ID2D1BitmapBrush1>(), pDevice.put_void()));

		if (res == 0)
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

	__int64 InteropHelper::CreateSharedEglSurface(Microsoft::Graphics::Canvas::CanvasBitmap canvasBitmap)
	{
		if (_display == EGL_NO_DISPLAY)
		{
			InitializeEglDisplay();
		}

		int* pBufferAttributes = new int[9]
			{
				EGL_WIDTH, 1920,
				EGL_HEIGHT, 1080,
				EGL_TEXTURE_TARGET, EGL_TEXTURE_2D,
				EGL_TEXTURE_FORMAT, EGL_TEXTURE_RGBA,
				EGL_NONE
			};

		long resource = GetWrappedResource(canvasBitmap);
		com_ptr<ID2D1Bitmap1> bitmap((void*)(resource), winrt::take_ownership_from_abi);
		IDXGIResource* sharedResource = nullptr;
		bitmap->QueryInterface<IDXGIResource>(&sharedResource);
		com_ptr<IDXGIResource> dxResource((void*)(sharedResource), winrt::take_ownership_from_abi);
		HANDLE sharedHandle = nullptr;
		dxResource->GetSharedHandle(&sharedHandle);
		EGLSurface surface = eglCreatePbufferFromClientBuffer(_display, EGL_D3D_TEXTURE_2D_SHARE_HANDLE_ANGLE, sharedHandle, _config, pBufferAttributes);
		return 0;
	}

	void InteropHelper::InitializeEglDisplay()
	{
		const EGLint* defaultDisplayAttributes =
			new EGLint[7]{
			// These are the default display attributes, used to request ANGLE's D3D11 renderer.
			// eglInitialize will only succeed with these attributes if the hardware supports D3D11 Feature Level 10_0+.
			EGL_PLATFORM_ANGLE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,

			// EGL_ANGLE_DISPLAY_ALLOW_RENDER_TO_BACK_BUFFER is an optimization that can have large performance benefits on mobile devices.
			// Its syntax is subject to change, though. Please update your Visual Studio templates if you experience compilation issues with it.
			EGL_EXPERIMENTAL_PRESENT_PATH_ANGLE, EGL_EXPERIMENTAL_PRESENT_PATH_FAST_ANGLE,

			// EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE is an option that enables ANGLE to automatically call 
			// the IDXGIDevice3::Trim method on behalf of the application when it gets suspended. 
			// Calling IDXGIDevice3::Trim when an application is suspended is a Windows Store application certification requirement.
			EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE, EGL_TRUE,
			EGL_NONE,
		};

		int fl9_3DisplayAttributes[] =
		{
			// These can be used to request ANGLE's D3D11 renderer, with D3D11 Feature Level 9_3.
			// These attributes are used if the call to eglInitialize fails with the default display attributes.
			EGL_PLATFORM_ANGLE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,
			EGL_PLATFORM_ANGLE_MAX_VERSION_MAJOR_ANGLE, 9,
			EGL_PLATFORM_ANGLE_MAX_VERSION_MINOR_ANGLE, 3,
			EGL_EXPERIMENTAL_PRESENT_PATH_ANGLE, EGL_EXPERIMENTAL_PRESENT_PATH_FAST_ANGLE,
			EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE, EGL_TRUE,
			EGL_NONE,
		};

		int warpDisplayAttributes[] =
		{
			// These attributes can be used to request D3D11 WARP.
			// They are used if eglInitialize fails with both the default display attributes and the 9_3 display attributes.
			EGL_PLATFORM_ANGLE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_TYPE_D3D11_ANGLE,
			EGL_PLATFORM_ANGLE_DEVICE_TYPE_ANGLE, EGL_PLATFORM_ANGLE_DEVICE_TYPE_D3D_WARP_ANGLE,
			EGL_EXPERIMENTAL_PRESENT_PATH_ANGLE, EGL_EXPERIMENTAL_PRESENT_PATH_FAST_ANGLE,
			EGL_PLATFORM_ANGLE_ENABLE_AUTOMATIC_TRIM_ANGLE, EGL_TRUE,
			EGL_NONE,
		};

		//
		// To initialize the display, we make three sets of calls to eglGetPlatformDisplayEXT and eglInitialize, with varying 
		// parameters passed to eglGetPlatformDisplayEXT:
		// 1) The first calls uses "defaultDisplayAttributes" as a parameter. This corresponds to D3D11 Feature Level 10_0+.
		// 2) If eglInitialize fails for step 1 (e.g. because 10_0+ isn't supported by the default GPU), then we try again 
		//    using "fl9_3DisplayAttributes". This corresponds to D3D11 Feature Level 9_3.
		// 3) If eglInitialize fails for step 2 (e.g. because 9_3+ isn't supported by the default GPU), then we try again 
		//    using "warpDisplayAttributes".  This corresponds to D3D11 Feature Level 11_0 on WARP, a D3D11 software rasterizer.
		//

		// This tries to initialize EGL to D3D11 Feature Level 10_0+. See above comment for details.
		_display = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, defaultDisplayAttributes);

		if (_display == EGL_NO_DISPLAY)
		{
			return;
		}
		EGLint* major = nullptr, * minor = nullptr;

		if (eglInitialize(_display, major, minor) == EGL_FALSE)
		{
			// This tries to initialize EGL to D3D11 Feature Level 9_3, if 10_0+ is unavailable (e.g. on some mobile devices).
			_display = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, fl9_3DisplayAttributes);
			if (_display == EGL_NO_DISPLAY)
			{
				return;
			}

			if (eglInitialize(_display, major, minor) == EGL_FALSE)
			{
				// This initializes EGL to D3D11 Feature Level 11_0 on WARP, if 9_3+ is unavailable on the default GPU.
				_display = eglGetPlatformDisplayEXT(EGL_PLATFORM_ANGLE_ANGLE, EGL_DEFAULT_DISPLAY, warpDisplayAttributes);
				if (_display == EGL_NO_DISPLAY)
				{
					return;
				}

				if (eglInitialize(_display, major, minor) == EGL_FALSE)
				{
					// If all of the calls to eglInitialize returned EGL_FALSE then an error has occurred.
					return;
				}
			}
		}

		int *configAttributes = new int[13]
		{
			EGL_RED_SIZE, 8,
			EGL_GREEN_SIZE, 8,
			EGL_BLUE_SIZE, 8,
			EGL_ALPHA_SIZE, 8,
			EGL_DEPTH_SIZE, 8,
			EGL_STENCIL_SIZE, 8,
			EGL_NONE
		};

		int* contextAttributes = new int[3]
		{
			EGL_CONTEXT_CLIENT_VERSION, 2,
			EGL_NONE
		};

		EGLConfig *configs = new EGLConfig[1];
		int *configNumber = nullptr;
		if (eglChooseConfig(_display, configAttributes, configs, 1, configNumber) == EGL_FALSE)
		{
			return;
		}
		_config = configs[0];

		_context = eglCreateContext(_display, _config, EGL_NO_CONTEXT, contextAttributes);

		if (_context == EGL_NO_CONTEXT)
		{
			return;
		}
	}

	Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice InteropHelper::GetUWPDevice(__int64 pointer)
	{
		winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice d3dDevice2{ nullptr };
		IDXGIDevice* device = reinterpret_cast<IDXGIDevice*>(pointer);
		com_ptr<IDXGIDevice> ptrDevice{ device, winrt::take_ownership_from_abi };
		CreateDirect3D11DeviceFromDXGIDevice(ptrDevice.get(),
			reinterpret_cast<::IInspectable**>(winrt::put_abi(d3dDevice2)));
		return d3dDevice2;
	}

	Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface InteropHelper::GetUWPSurface(__int64 pointer)
	{
		winrt::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface d3dDevice2{ nullptr };
		IDXGISurface* device = reinterpret_cast<IDXGISurface*>(pointer);
		com_ptr<IDXGISurface> ptrDevice{ device, winrt::take_ownership_from_abi };
		CreateDirect3D11SurfaceFromDXGISurface(ptrDevice.get(),
			reinterpret_cast<::IInspectable**>(winrt::put_abi(d3dDevice2)));
		return d3dDevice2;
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
