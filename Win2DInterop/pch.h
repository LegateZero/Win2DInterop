#pragma once
#include <unknwn.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include "winrt/Microsoft.Graphics.Canvas.h"
#include "winrt/Microsoft.Graphics.Canvas.Brushes.h"
#include "winrt/Microsoft.Graphics.Canvas.Effects.h"
#include "winrt/Microsoft.Graphics.Canvas.Text.h"
#include "winrt/Microsoft.Graphics.Canvas.Geometry.h"
#include "winrt/Microsoft.Graphics.Canvas.Printing.h"
#include "winrt/Microsoft.Graphics.Canvas.UI.h"
#include "winrt/Microsoft.Graphics.Canvas.UI.Composition.h"
#include "winrt/Microsoft.Graphics.Canvas.UI.Xaml.h"
#include "Microsoft.Graphics.Canvas.native.h"
#include <Microsoft.Graphics.Canvas.h>
#include "windows.graphics.directx.direct3d11.h"
#include "windows.graphics.directx.direct3d11.interop.h"

// Enable function definitions in the GL headers below
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES

// OpenGL ES includes
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

// EGL includes
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <EGL/eglplatform.h>
#include <EGL/eglext_angle.h>
