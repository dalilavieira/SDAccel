#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_27__   TYPE_5__ ;
typedef  struct TYPE_26__   TYPE_4__ ;
typedef  struct TYPE_25__   TYPE_3__ ;
typedef  struct TYPE_24__   TYPE_2__ ;
typedef  struct TYPE_23__   TYPE_21__ ;
typedef  struct TYPE_22__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct wl_output {int dummy; } ;
struct TYPE_22__ {double x; double y; int currentMode; double scale; } ;
struct _GLFWmonitor {double widthMM; double heightMM; int modeCount; TYPE_1__ wl; TYPE_5__* modes; int /*<<< orphan*/  name; } ;
typedef  int /*<<< orphan*/  name ;
typedef  double int32_t ;
struct TYPE_25__ {int scale; int name; int x; int y; size_t currentMode; struct wl_output* output; } ;
struct TYPE_26__ {int modeCount; TYPE_3__ wl; TYPE_5__* modes; } ;
typedef  TYPE_4__ _GLFWmonitor ;
struct TYPE_27__ {double width; double height; int redBits; int greenBits; int blueBits; int refreshRate; } ;
struct TYPE_24__ {int /*<<< orphan*/  registry; } ;
struct TYPE_23__ {TYPE_2__ wl; } ;
typedef  TYPE_5__ GLFWvidmode ;
typedef  int /*<<< orphan*/  GLFWmonitor ;
typedef  int /*<<< orphan*/  GLFWgammaramp ;
typedef  int /*<<< orphan*/  GLFWbool ;

/* Variables and functions */
 int /*<<< orphan*/  GLFW_CONNECTED ; 
 int /*<<< orphan*/  GLFW_FALSE ; 
 int /*<<< orphan*/  GLFW_PLATFORM_ERROR ; 
 int WL_OUTPUT_MODE_CURRENT ; 
 int /*<<< orphan*/  _GLFW_INSERT_LAST ; 
 int /*<<< orphan*/  _GLFW_REQUIRE_INIT_OR_RETURN (int /*<<< orphan*/ *) ; 
 TYPE_21__ _glfw ; 
 TYPE_4__* _glfwAllocMonitor (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _glfwFreeMonitor (TYPE_4__*) ; 
 int /*<<< orphan*/  _glfwInputError (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  _glfwInputMonitor (struct _GLFWmonitor*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _glfw_strdup (char*) ; 
 int /*<<< orphan*/  outputListener ; 
 TYPE_5__* realloc (TYPE_5__*,int) ; 
 scalar_t__ round (double) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char const*,char const*) ; 
 int /*<<< orphan*/  wl_output_add_listener (struct wl_output*,int /*<<< orphan*/ *,TYPE_4__*) ; 
 int /*<<< orphan*/  wl_output_destroy (struct wl_output*) ; 
 int /*<<< orphan*/  wl_output_interface ; 
 struct wl_output* wl_registry_bind (int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void outputHandleGeometry(void* data,
                                struct wl_output* output,
                                int32_t x,
                                int32_t y,
                                int32_t physicalWidth,
                                int32_t physicalHeight,
                                int32_t subpixel,
                                const char* make,
                                const char* model,
                                int32_t transform)
{
    struct _GLFWmonitor *monitor = data;
    char name[1024];

    monitor->wl.x = x;
    monitor->wl.y = y;
    monitor->widthMM = physicalWidth;
    monitor->heightMM = physicalHeight;

    snprintf(name, sizeof(name), "%s %s", make, model);
    monitor->name = _glfw_strdup(name);
}

__attribute__((used)) static void outputHandleMode(void* data,
                            struct wl_output* output,
                            uint32_t flags,
                            int32_t width,
                            int32_t height,
                            int32_t refresh)
{
    struct _GLFWmonitor *monitor = data;
    GLFWvidmode mode;

    mode.width = width;
    mode.height = height;
    mode.redBits = 8;
    mode.greenBits = 8;
    mode.blueBits = 8;
    mode.refreshRate = (int)round(refresh / 1000.0);

    monitor->modeCount++;
    monitor->modes =
        realloc(monitor->modes, monitor->modeCount * sizeof(GLFWvidmode));
    monitor->modes[monitor->modeCount - 1] = mode;

    if (flags & WL_OUTPUT_MODE_CURRENT)
        monitor->wl.currentMode = monitor->modeCount - 1;
}

__attribute__((used)) static void outputHandleDone(void* data, struct wl_output* output)
{
    struct _GLFWmonitor *monitor = data;

    _glfwInputMonitor(monitor, GLFW_CONNECTED, _GLFW_INSERT_LAST);
}

__attribute__((used)) static void outputHandleScale(void* data,
                            struct wl_output* output,
                            int32_t factor)
{
    struct _GLFWmonitor *monitor = data;
    if (factor > 0 && factor < 24)
        monitor->wl.scale = factor;
}

void _glfwAddOutputWayland(uint32_t name, uint32_t version)
{
    _GLFWmonitor *monitor;
    struct wl_output *output;

    if (version < 2)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Wayland: Unsupported output interface version");
        return;
    }

    // The actual name of this output will be set in the geometry handler.
    monitor = _glfwAllocMonitor(NULL, 0, 0);

    output = wl_registry_bind(_glfw.wl.registry,
                              name,
                              &wl_output_interface,
                              2);
    if (!output)
    {
        _glfwFreeMonitor(monitor);
        return;
    }

    monitor->wl.scale = 1;
    monitor->wl.output = output;
    monitor->wl.name = name;

    wl_output_add_listener(output, &outputListener, monitor);
}

void _glfwPlatformFreeMonitor(_GLFWmonitor* monitor)
{
    if (monitor->wl.output)
        wl_output_destroy(monitor->wl.output);
}

void _glfwPlatformGetMonitorPos(_GLFWmonitor* monitor, int* xpos, int* ypos)
{
    if (xpos)
        *xpos = monitor->wl.x;
    if (ypos)
        *ypos = monitor->wl.y;
}

void _glfwPlatformGetMonitorContentScale(_GLFWmonitor* monitor,
                                         float* xscale, float* yscale)
{
    if (xscale)
        *xscale = (float) monitor->wl.scale;
    if (yscale)
        *yscale = (float) monitor->wl.scale;
}

void _glfwPlatformGetMonitorWorkarea(_GLFWmonitor* monitor, int* xpos, int* ypos, int *width, int *height)
{
    if (xpos)
        *xpos = monitor->wl.x;
    if (ypos)
        *ypos = monitor->wl.y;
    if (width)
        *width = monitor->modes[monitor->wl.currentMode].width;
    if (height)
        *height = monitor->modes[monitor->wl.currentMode].height;
}

GLFWvidmode* _glfwPlatformGetVideoModes(_GLFWmonitor* monitor, int* found)
{
    *found = monitor->modeCount;
    return monitor->modes;
}

void _glfwPlatformGetVideoMode(_GLFWmonitor* monitor, GLFWvidmode* mode)
{
    *mode = monitor->modes[monitor->wl.currentMode];
}

GLFWbool _glfwPlatformGetGammaRamp(_GLFWmonitor* monitor, GLFWgammaramp* ramp)
{
    _glfwInputError(GLFW_PLATFORM_ERROR,
                    "Wayland: Gamma ramp access is not available");
    return GLFW_FALSE;
}

void _glfwPlatformSetGammaRamp(_GLFWmonitor* monitor, const GLFWgammaramp* ramp)
{
    _glfwInputError(GLFW_PLATFORM_ERROR,
                    "Wayland: Gamma ramp access is not available");
}

struct wl_output* glfwGetWaylandMonitor(GLFWmonitor* handle)
{
    _GLFWmonitor* monitor = (_GLFWmonitor*) handle;
    _GLFW_REQUIRE_INIT_OR_RETURN(NULL);
    return monitor->wl.output;
}

