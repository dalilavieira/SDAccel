#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_9__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint32_t ;
struct TYPE_11__ {scalar_t__ client; } ;
struct TYPE_12__ {TYPE_2__ context; } ;
typedef  TYPE_3__ _GLFWwindow ;
typedef  scalar_t__ VkSurfaceKHR ;
typedef  int VkResult ;
typedef  scalar_t__ VkPhysicalDevice ;
typedef  scalar_t__ VkInstance ;
struct TYPE_13__ {int /*<<< orphan*/  extensionName; } ;
typedef  TYPE_4__ VkExtensionProperties ;
typedef  int /*<<< orphan*/  VkAllocationCallbacks ;
struct TYPE_10__ {int available; int KHR_surface; int /*<<< orphan*/ * extensions; scalar_t__ handle; scalar_t__ EnumerateInstanceExtensionProperties; scalar_t__ GetInstanceProcAddr; } ;
struct TYPE_14__ {TYPE_1__ vk; } ;
typedef  scalar_t__ PFN_vkGetInstanceProcAddr ;
typedef  scalar_t__ PFN_vkEnumerateInstanceExtensionProperties ;
typedef  int /*<<< orphan*/  GLFWwindow ;
typedef  int /*<<< orphan*/ * GLFWvkproc ;
typedef  int GLFWbool ;

/* Variables and functions */
 int /*<<< orphan*/  GLFW_API_UNAVAILABLE ; 
 int GLFW_FALSE ; 
 int /*<<< orphan*/  GLFW_INVALID_VALUE ; 
 scalar_t__ GLFW_NO_API ; 
 int GLFW_TRUE ; 
#define  VK_ERROR_DEVICE_LOST 150 
#define  VK_ERROR_EXTENSION_NOT_PRESENT 149 
#define  VK_ERROR_FEATURE_NOT_PRESENT 148 
#define  VK_ERROR_FORMAT_NOT_SUPPORTED 147 
#define  VK_ERROR_INCOMPATIBLE_DISPLAY_KHR 146 
#define  VK_ERROR_INCOMPATIBLE_DRIVER 145 
#define  VK_ERROR_INITIALIZATION_FAILED 144 
#define  VK_ERROR_LAYER_NOT_PRESENT 143 
#define  VK_ERROR_MEMORY_MAP_FAILED 142 
#define  VK_ERROR_NATIVE_WINDOW_IN_USE_KHR 141 
#define  VK_ERROR_OUT_OF_DATE_KHR 140 
#define  VK_ERROR_OUT_OF_DEVICE_MEMORY 139 
#define  VK_ERROR_OUT_OF_HOST_MEMORY 138 
#define  VK_ERROR_SURFACE_LOST_KHR 137 
#define  VK_ERROR_TOO_MANY_OBJECTS 136 
#define  VK_ERROR_VALIDATION_FAILED_EXT 135 
#define  VK_EVENT_RESET 134 
#define  VK_EVENT_SET 133 
#define  VK_INCOMPLETE 132 
#define  VK_NOT_READY 131 
 scalar_t__ VK_NULL_HANDLE ; 
#define  VK_SUBOPTIMAL_KHR 130 
#define  VK_SUCCESS 129 
#define  VK_TIMEOUT 128 
 int _GLFW_FIND_LOADER ; 
 int /*<<< orphan*/  _GLFW_REQUIRE_INIT_OR_RETURN (int const) ; 
 int _GLFW_REQUIRE_LOADER ; 
 TYPE_9__ _glfw ; 
 char const* _glfwGetVulkanResultString (int) ; 
 int /*<<< orphan*/  _glfwInputError (int /*<<< orphan*/ ,char*,...) ; 
 int _glfwPlatformCreateWindowSurface (scalar_t__,TYPE_3__*,int /*<<< orphan*/  const*,scalar_t__*) ; 
 int _glfwPlatformGetPhysicalDevicePresentationSupport (scalar_t__,scalar_t__,size_t) ; 
 int /*<<< orphan*/  _glfwPlatformGetRequiredInstanceExtensions (int /*<<< orphan*/ *) ; 
 void _glfwTerminateVulkan () ; 
 int /*<<< orphan*/  _glfw_dlclose (scalar_t__) ; 
 scalar_t__ _glfw_dlopen (char*) ; 
 scalar_t__ _glfw_dlsym (scalar_t__,char const*) ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_4__* calloc (size_t,int) ; 
 int /*<<< orphan*/  free (TYPE_4__*) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 
 int vkEnumerateInstanceExtensionProperties (int /*<<< orphan*/ *,size_t*,TYPE_4__*) ; 
 scalar_t__ vkGetInstanceProcAddr (scalar_t__,char const*) ; 

GLFWbool _glfwInitVulkan(int mode)
{
    VkResult err;
    VkExtensionProperties* ep;
    uint32_t i, count;

    if (_glfw.vk.available)
        return GLFW_TRUE;

#if !defined(_GLFW_VULKAN_STATIC)
#if defined(_GLFW_VULKAN_LIBRARY)
    _glfw.vk.handle = _glfw_dlopen(_GLFW_VULKAN_LIBRARY);
#elif defined(_GLFW_WIN32)
    _glfw.vk.handle = _glfw_dlopen("vulkan-1.dll");
#elif defined(_GLFW_COCOA)
    _glfw.vk.handle = _glfw_dlopen("libvulkan.1.dylib");
#else
    _glfw.vk.handle = _glfw_dlopen("libvulkan.so.1");
#endif
    if (!_glfw.vk.handle)
    {
        if (mode == _GLFW_REQUIRE_LOADER)
            _glfwInputError(GLFW_API_UNAVAILABLE, "Vulkan: Loader not found");

        return GLFW_FALSE;
    }

    _glfw.vk.GetInstanceProcAddr = (PFN_vkGetInstanceProcAddr)
        _glfw_dlsym(_glfw.vk.handle, "vkGetInstanceProcAddr");
    if (!_glfw.vk.GetInstanceProcAddr)
    {
        _glfwInputError(GLFW_API_UNAVAILABLE,
                        "Vulkan: Loader does not export vkGetInstanceProcAddr");

        _glfwTerminateVulkan();
        return GLFW_FALSE;
    }

    _glfw.vk.EnumerateInstanceExtensionProperties = (PFN_vkEnumerateInstanceExtensionProperties)
        vkGetInstanceProcAddr(NULL, "vkEnumerateInstanceExtensionProperties");
    if (!_glfw.vk.EnumerateInstanceExtensionProperties)
    {
        _glfwInputError(GLFW_API_UNAVAILABLE,
                        "Vulkan: Failed to retrieve vkEnumerateInstanceExtensionProperties");

        _glfwTerminateVulkan();
        return GLFW_FALSE;
    }
#endif // _GLFW_VULKAN_STATIC

    err = vkEnumerateInstanceExtensionProperties(NULL, &count, NULL);
    if (err)
    {
        // NOTE: This happens on systems with a loader but without any Vulkan ICD
        if (mode == _GLFW_REQUIRE_LOADER)
        {
            _glfwInputError(GLFW_API_UNAVAILABLE,
                            "Vulkan: Failed to query instance extension count: %s",
                            _glfwGetVulkanResultString(err));
        }

        _glfwTerminateVulkan();
        return GLFW_FALSE;
    }

    ep = calloc(count, sizeof(VkExtensionProperties));

    err = vkEnumerateInstanceExtensionProperties(NULL, &count, ep);
    if (err)
    {
        _glfwInputError(GLFW_API_UNAVAILABLE,
                        "Vulkan: Failed to query instance extensions: %s",
                        _glfwGetVulkanResultString(err));

        free(ep);
        _glfwTerminateVulkan();
        return GLFW_FALSE;
    }

    for (i = 0;  i < count;  i++)
    {
        if (strcmp(ep[i].extensionName, "VK_KHR_surface") == 0)
            _glfw.vk.KHR_surface = GLFW_TRUE;
#if defined(_GLFW_WIN32)
        else if (strcmp(ep[i].extensionName, "VK_KHR_win32_surface") == 0)
            _glfw.vk.KHR_win32_surface = GLFW_TRUE;
#elif defined(_GLFW_COCOA)
        else if (strcmp(ep[i].extensionName, "VK_MVK_macos_surface") == 0)
            _glfw.vk.MVK_macos_surface = GLFW_TRUE;
#elif defined(_GLFW_X11)
        else if (strcmp(ep[i].extensionName, "VK_KHR_xlib_surface") == 0)
            _glfw.vk.KHR_xlib_surface = GLFW_TRUE;
        else if (strcmp(ep[i].extensionName, "VK_KHR_xcb_surface") == 0)
            _glfw.vk.KHR_xcb_surface = GLFW_TRUE;
#elif defined(_GLFW_WAYLAND)
        else if (strcmp(ep[i].extensionName, "VK_KHR_wayland_surface") == 0)
            _glfw.vk.KHR_wayland_surface = GLFW_TRUE;
#endif
    }

    free(ep);

    _glfw.vk.available = GLFW_TRUE;

    _glfwPlatformGetRequiredInstanceExtensions(_glfw.vk.extensions);

    return GLFW_TRUE;
}

void _glfwTerminateVulkan(void)
{
#if !defined(_GLFW_VULKAN_STATIC)
    if (_glfw.vk.handle)
        _glfw_dlclose(_glfw.vk.handle);
#endif
}

const char* _glfwGetVulkanResultString(VkResult result)
{
    switch (result)
    {
        case VK_SUCCESS:
            return "Success";
        case VK_NOT_READY:
            return "A fence or query has not yet completed";
        case VK_TIMEOUT:
            return "A wait operation has not completed in the specified time";
        case VK_EVENT_SET:
            return "An event is signaled";
        case VK_EVENT_RESET:
            return "An event is unsignaled";
        case VK_INCOMPLETE:
            return "A return array was too small for the result";
        case VK_ERROR_OUT_OF_HOST_MEMORY:
            return "A host memory allocation has failed";
        case VK_ERROR_OUT_OF_DEVICE_MEMORY:
            return "A device memory allocation has failed";
        case VK_ERROR_INITIALIZATION_FAILED:
            return "Initialization of an object could not be completed for implementation-specific reasons";
        case VK_ERROR_DEVICE_LOST:
            return "The logical or physical device has been lost";
        case VK_ERROR_MEMORY_MAP_FAILED:
            return "Mapping of a memory object has failed";
        case VK_ERROR_LAYER_NOT_PRESENT:
            return "A requested layer is not present or could not be loaded";
        case VK_ERROR_EXTENSION_NOT_PRESENT:
            return "A requested extension is not supported";
        case VK_ERROR_FEATURE_NOT_PRESENT:
            return "A requested feature is not supported";
        case VK_ERROR_INCOMPATIBLE_DRIVER:
            return "The requested version of Vulkan is not supported by the driver or is otherwise incompatible";
        case VK_ERROR_TOO_MANY_OBJECTS:
            return "Too many objects of the type have already been created";
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            return "A requested format is not supported on this device";
        case VK_ERROR_SURFACE_LOST_KHR:
            return "A surface is no longer available";
        case VK_SUBOPTIMAL_KHR:
            return "A swapchain no longer matches the surface properties exactly, but can still be used";
        case VK_ERROR_OUT_OF_DATE_KHR:
            return "A surface has changed in such a way that it is no longer compatible with the swapchain";
        case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:
            return "The display used by a swapchain does not use the same presentable image layout";
        case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:
            return "The requested window is already connected to a VkSurfaceKHR, or to some other non-Vulkan API";
        case VK_ERROR_VALIDATION_FAILED_EXT:
            return "A validation layer found an error";
        default:
            return "ERROR: UNKNOWN VULKAN ERROR";
    }
}

int glfwVulkanSupported(void)
{
    _GLFW_REQUIRE_INIT_OR_RETURN(GLFW_FALSE);
    return _glfwInitVulkan(_GLFW_FIND_LOADER);
}

const char** glfwGetRequiredInstanceExtensions(uint32_t* count)
{
    assert(count != NULL);

    *count = 0;

    _GLFW_REQUIRE_INIT_OR_RETURN(NULL);

    if (!_glfwInitVulkan(_GLFW_REQUIRE_LOADER))
        return NULL;

    if (!_glfw.vk.extensions[0])
        return NULL;

    *count = 2;
    return (const char**) _glfw.vk.extensions;
}

GLFWvkproc glfwGetInstanceProcAddress(VkInstance instance,
                                              const char* procname)
{
    GLFWvkproc proc;
    assert(procname != NULL);

    _GLFW_REQUIRE_INIT_OR_RETURN(NULL);

    if (!_glfwInitVulkan(_GLFW_REQUIRE_LOADER))
        return NULL;

    proc = (GLFWvkproc) vkGetInstanceProcAddr(instance, procname);
#if defined(_GLFW_VULKAN_STATIC)
    if (!proc)
    {
        if (strcmp(procname, "vkGetInstanceProcAddr") == 0)
            return (GLFWvkproc) vkGetInstanceProcAddr;
    }
#else
    if (!proc)
        proc = (GLFWvkproc) _glfw_dlsym(_glfw.vk.handle, procname);
#endif

    return proc;
}

int glfwGetPhysicalDevicePresentationSupport(VkInstance instance,
                                                     VkPhysicalDevice device,
                                                     uint32_t queuefamily)
{
    assert(instance != VK_NULL_HANDLE);
    assert(device != VK_NULL_HANDLE);

    _GLFW_REQUIRE_INIT_OR_RETURN(GLFW_FALSE);

    if (!_glfwInitVulkan(_GLFW_REQUIRE_LOADER))
        return GLFW_FALSE;

    if (!_glfw.vk.extensions[0])
    {
        _glfwInputError(GLFW_API_UNAVAILABLE,
                        "Vulkan: Window surface creation extensions not found");
        return GLFW_FALSE;
    }

    return _glfwPlatformGetPhysicalDevicePresentationSupport(instance,
                                                             device,
                                                             queuefamily);
}

VkResult glfwCreateWindowSurface(VkInstance instance,
                                         GLFWwindow* handle,
                                         const VkAllocationCallbacks* allocator,
                                         VkSurfaceKHR* surface)
{
    _GLFWwindow* window = (_GLFWwindow*) handle;
    assert(instance != VK_NULL_HANDLE);
    assert(window != NULL);
    assert(surface != NULL);

    *surface = VK_NULL_HANDLE;

    _GLFW_REQUIRE_INIT_OR_RETURN(VK_ERROR_INITIALIZATION_FAILED);

    if (!_glfwInitVulkan(_GLFW_REQUIRE_LOADER))
        return VK_ERROR_INITIALIZATION_FAILED;

    if (!_glfw.vk.extensions[0])
    {
        _glfwInputError(GLFW_API_UNAVAILABLE,
                        "Vulkan: Window surface creation extensions not found");
        return VK_ERROR_EXTENSION_NOT_PRESENT;
    }

    if (window->context.client != GLFW_NO_API)
    {
        _glfwInputError(GLFW_INVALID_VALUE,
                        "Vulkan: Window surface creation requires the window to have the client API set to GLFW_NO_API");
        return VK_ERROR_NATIVE_WINDOW_IN_USE_KHR;
    }

    return _glfwPlatformCreateWindowSurface(instance, window, allocator, surface);
}

