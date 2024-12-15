using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.WindowsRuntime;
using Microsoft.Graphics.Canvas;
using Microsoft.Graphics.Canvas.Effects;
using SharpGen.Runtime;
using SkiaSharp;
using Vortice.Direct2D1;
using Vortice.Direct3D11;
using Vortice.DXGI;
using Win2DInterop;
using Windows.ApplicationModel;
using Windows.ApplicationModel.Activation;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.Graphics.DirectX.Direct3D11;
using Windows.Graphics.Imaging;
using Windows.Storage;
using Windows.Storage.Streams;
using Windows.UI;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

namespace Sample.UWP
{
    /// <summary>
    /// Provides application-specific behavior to supplement the default Application class.
    /// </summary>
    sealed partial class App : Application
    {
        /// <summary>
        /// Initializes the singleton application object.  This is the first line of authored code
        /// executed, and as such is the logical equivalent of main() or WinMain().
        /// </summary>
        public App()
        {
            this.InitializeComponent();
            this.Suspending += OnSuspending;
        }

        /// <summary>
        /// Invoked when the application is launched normally by the end user.  Other entry points
        /// will be used such as when the application is launched to open a specific file.
        /// </summary>
        /// <param name="e">Details about the launch request and process.</param>
        protected override async void OnLaunched(LaunchActivatedEventArgs e)
        {
            Frame rootFrame = Window.Current.Content as Frame;

            try
            {
                var image = await CanvasBitmap.LoadAsync(CanvasDevice.GetSharedDevice(), new Uri("ms-appx:///Assets/test.jpg"), 96, CanvasAlphaMode.Premultiplied);

                var array = image.GetPixelBytes();
                var res = D3D11.D3D11CreateDevice(null, Vortice.Direct3D.DriverType.Hardware, DeviceCreationFlags.Debug | DeviceCreationFlags.BgraSupport, new Vortice.Direct3D.FeatureLevel[]
                {
                    Vortice.Direct3D.FeatureLevel.Level_11_1,
                    Vortice.Direct3D.FeatureLevel.Level_11_0,
                    Vortice.Direct3D.FeatureLevel.Level_9_3,
                    Vortice.Direct3D.FeatureLevel.Level_9_2
                }, out ID3D11Device dev);

                var pointer = GCHandle.Alloc(array, GCHandleType.Pinned);
                var resour = new SubresourceData(pointer.AddrOfPinnedObject(), 1920 * 4);

                ID3D11Texture2D texture = dev.CreateTexture2D(Format.B8G8R8A8_UNorm, 1920, 1080, 1, 1, new SubresourceData[]
                {
                    resour
                }, BindFlags.RenderTarget);

                IDXGISurface surface = texture.QueryInterface<IDXGISurface>();
                IDXGIDevice1 dxgiDevice = dev.QueryInterfaceOrNull<IDXGIDevice1>();
                IDirect3DDevice deviceUWP = InteropHelper.GetUWPDevice((long)dxgiDevice.NativePointer);
                CanvasDevice inContextWin2dDevice = CanvasDevice.CreateFromDirect3D11Device(deviceUWP);
                ID2D1Device1 device = new ID2D1Device1((IntPtr)InteropHelper.GetWrappedResource(inContextWin2dDevice));
                ID2D1RenderTarget d2dDevice = device.Factory.CreateDxgiSurfaceRenderTarget(surface, new RenderTargetProperties(new Vortice.DCommon.PixelFormat(Format.B8G8R8A8_UNorm, Vortice.DCommon.AlphaMode.Premultiplied)));
                CanvasRenderTarget target = CanvasRenderTarget.CreateFromDirect3D11Surface(inContextWin2dDevice, InteropHelper.GetUWPSurface((long)surface.NativePointer));

                using (CanvasDrawingSession sesion = target.CreateDrawingSession())
                {
                    sesion.DrawEllipse(new System.Numerics.Vector2(100, 100), 40, 40, Colors.Red);
                }

                var file = await ApplicationData.Current.LocalFolder.CreateFileAsync("temp.png", CreationCollisionOption.ReplaceExisting);

                using (var stream = await file.OpenAsync(FileAccessMode.ReadWrite))
                {
                    await CanvasImage.SaveAsync(target, target.Bounds, 96, target, stream, CanvasBitmapFileFormat.Png);
                }


            }
            catch (Exception ex)
            {
                var a = ex;
            }
            //D3D11_TEXTURE2D_DESC des = new D3D11_TEXTURE2D_DESC()
            //{
            //    Height = 1080,
            //    Width = 1920,
            //    ArraySize = 1080 * 1920 * 4,
            //    CPUAccessFlags = (uint)D3D11_CPU_ACCESS_FLAG.D3D11_CPU_ACCESS_READ,
            //    Format = DXGI_FORMAT.DXGI_FORMAT_R8G8B8A8_UINT,
            //    BindFlags = (uint)D3D11_BIND_FLAG.D3D11_BIND_RENDER_TARGET,
            //    Usage = D3D11_USAGE.D3D11_USAGE_DYNAMIC,

            //};

            //IBuffer buffer = await FileIO.ReadBufferAsync(await StorageFile.GetFileFromPathAsync("ms-appx:///Assets/test.jpg"));

            //InMemoryRandomAccessStream stream = new InMemoryRandomAccessStream();
            //CanvasBitmap bitmap = CanvasBitmap.CreateFromBytes(CanvasDevice.GetSharedDevice(), buffer.ToArray(), 1920, 1080, Windows.Graphics.DirectX.DirectXPixelFormat.R8G8B8A8UInt, 96);
            //var bytes = bitmap.GetPixelBytes();

            //D3D11_SUBRESOURCE_DATA data = new D3D11_SUBRESOURCE_DATA()
            //{
            //    pSysMem = bitmap.Pixe
            //};

            //Windows.Storage.Streams.Buffer.CreateCopyFromMemoryBuffer

            //  device.CreateTexture2D(ref des, new D3D11_SUBRESOURCE_DATA[1] { data }, out ID3D11Texture2D texure2d);
            // Do not repeat app initialization when the Window already has content,
            // just ensure that the window is active
            if (rootFrame == null)
            {
                // Create a Frame to act as the navigation context and navigate to the first page
                rootFrame = new Frame();

                rootFrame.NavigationFailed += OnNavigationFailed;

                if (e.PreviousExecutionState == ApplicationExecutionState.Terminated)
                {
                    //TODO: Load state from previously suspended application
                }

                // Place the frame in the current Window
                Window.Current.Content = rootFrame;
            }

            if (e.PrelaunchActivated == false)
            {
                if (rootFrame.Content == null)
                {
                    // When the navigation stack isn't restored navigate to the first page,
                    // configuring the new page by passing required information as a navigation
                    // parameter
                    rootFrame.Navigate(typeof(MainPage), e.Arguments);
                }
                // Ensure the current window is active
                Window.Current.Activate();
            }
        }

        /// <summary>
        /// Invoked when Navigation to a certain page fails
        /// </summary>
        /// <param name="sender">The Frame which failed navigation</param>
        /// <param name="e">Details about the navigation failure</param>
        void OnNavigationFailed(object sender, NavigationFailedEventArgs e)
        {
            throw new Exception("Failed to load Page " + e.SourcePageType.FullName);
        }

        /// <summary>
        /// Invoked when application execution is being suspended.  Application state is saved
        /// without knowing whether the application will be terminated or resumed with the contents
        /// of memory still intact.
        /// </summary>
        /// <param name="sender">The source of the suspend request.</param>
        /// <param name="e">Details about the suspend request.</param>
        private void OnSuspending(object sender, SuspendingEventArgs e)
        {
            var deferral = e.SuspendingOperation.GetDeferral();
            //TODO: Save application state and stop any background activity
            deferral.Complete();
        }
    }
}
