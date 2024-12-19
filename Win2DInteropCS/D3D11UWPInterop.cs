namespace Win2DInteropCS
{
	using System;
	using Win2DInterop;
	using Windows.Graphics.DirectX.Direct3D11;

	/// <summary>
	/// Helper methods to get IDirect3DDevice and IDirect3DSurface from IDXGIDevice and IDXGISurface pointers
	/// </summary>
	public static class D3D11UWPInterop
	{
		#region Public Static Methods

		public static IDirect3DDevice GetDirect3DDevice(IntPtr iDXGIDevicePtr)
		{
			return InteropHelper.GetUWPDevice((long)iDXGIDevicePtr);
		}

		public static IDirect3DSurface GetDirect3DSurface(IntPtr iDXGISurfacePtr)
		{
			return InteropHelper.GetUWPSurface((long)iDXGISurfacePtr);
		}

		#endregion Public Static Methods
	}
}
