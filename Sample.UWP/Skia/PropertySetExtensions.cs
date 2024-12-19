﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using Windows.Foundation;
using Windows.Foundation.Collections;

namespace SkiaSharpDraw
{
    internal static class PropertySetExtensions
    {
        private const string libInterop = "SkiaSharp.Views.Interop.UWP.dll";

        public static void AddSingle(this PropertySet properties, string key, float value)
        {
            PropertySet_AddSingle(properties, key, value);
        }

        public static void AddSize(this PropertySet properties, string key, Size size)
        {
            PropertySet_AddSize(properties, key, (float)size.Width, (float)size.Height);
        }

        public static void AddSize(this PropertySet properties, string key, float width, float height)
        {
            PropertySet_AddSize(properties, key, width, height);
        }

        [DllImport("SkiaSharp.Views.Interop.UWP.dll")]
        private static extern void PropertySet_AddSingle([MarshalAs(UnmanagedType.IInspectable)] object properties, [MarshalAs(UnmanagedType.HString)] string key, float value);

        [DllImport("SkiaSharp.Views.Interop.UWP.dll")]
        private static extern void PropertySet_AddSize([MarshalAs(UnmanagedType.IInspectable)] object properties, [MarshalAs(UnmanagedType.HString)] string key, float width, float height);
    }
}