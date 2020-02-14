#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_63__   TYPE_9__ ;
typedef  struct TYPE_62__   TYPE_8__ ;
typedef  struct TYPE_61__   TYPE_7__ ;
typedef  struct TYPE_60__   TYPE_6__ ;
typedef  struct TYPE_59__   TYPE_5__ ;
typedef  struct TYPE_58__   TYPE_52__ ;
typedef  struct TYPE_57__   TYPE_4__ ;
typedef  struct TYPE_56__   TYPE_3__ ;
typedef  struct TYPE_55__   TYPE_2__ ;
typedef  struct TYPE_54__   TYPE_1__ ;
typedef  struct TYPE_53__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  template ;
struct wl_surface {int dummy; } ;
struct wl_shm_pool {int dummy; } ;
struct wl_shell_surface {int dummy; } ;
struct wl_display {int dummy; } ;
struct wl_cursor_image {int hotspot_x; int hotspot_y; int width; int height; } ;
struct wl_buffer {int dummy; } ;
struct pollfd {int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
typedef  int off_t ;
typedef  int int32_t ;
struct TYPE_61__ {int width; int height; TYPE_2__* monitor; } ;
typedef  TYPE_7__ _GLFWwndconfig ;
struct TYPE_56__ {int width; int height; double cursorPosX; double cursorPosY; TYPE_9__* currentCursor; struct wl_surface* surface; scalar_t__ shell_surface; scalar_t__ native; } ;
struct TYPE_62__ {scalar_t__ cursorMode; TYPE_3__ wl; struct TYPE_62__* next; } ;
typedef  TYPE_8__ _GLFWwindow ;
typedef  int /*<<< orphan*/  _GLFWfbconfig ;
struct TYPE_59__ {int width; int height; int xhot; int yhot; struct wl_buffer* buffer; } ;
struct TYPE_63__ {TYPE_5__ wl; } ;
typedef  TYPE_9__ _GLFWcursor ;
typedef  int /*<<< orphan*/  _GLFWctxconfig ;
struct TYPE_60__ {int /*<<< orphan*/  pointerSerial; int /*<<< orphan*/  pointer; TYPE_4__* defaultCursor; TYPE_8__* pointerFocus; struct wl_surface* cursorSurface; int /*<<< orphan*/  shm; struct wl_display* display; TYPE_8__* keyboardFocus; int /*<<< orphan*/  shell; int /*<<< orphan*/  compositor; } ;
struct TYPE_58__ {TYPE_6__ wl; TYPE_8__* windowListHead; } ;
struct TYPE_57__ {struct wl_cursor_image** images; } ;
struct TYPE_54__ {int /*<<< orphan*/  output; } ;
struct TYPE_55__ {TYPE_1__ wl; } ;
struct TYPE_53__ {int width; int height; scalar_t__ pixels; } ;
typedef  int GLboolean ;
typedef  TYPE_10__ GLFWimage ;

/* Variables and functions */
 int EAGAIN ; 
 int ENOENT ; 
 scalar_t__ GLFW_CURSOR_NORMAL ; 
 int /*<<< orphan*/  GLFW_PLATFORM_ERROR ; 
 int GL_FALSE ; 
 int GL_TRUE ; 
 void* MAP_FAILED ; 
 int /*<<< orphan*/  MAP_SHARED ; 
 int /*<<< orphan*/  O_CLOEXEC ; 
 int /*<<< orphan*/  POLLIN ; 
 int PROT_READ ; 
 int PROT_WRITE ; 
 int /*<<< orphan*/  WL_SHELL_SURFACE_FULLSCREEN_METHOD_DEFAULT ; 
 int /*<<< orphan*/  WL_SHM_FORMAT_ARGB8888 ; 
 TYPE_52__ _glfw ; 
 int /*<<< orphan*/  _glfwCreateContext (TYPE_8__*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  _glfwDestroyContext (TYPE_8__*) ; 
 int /*<<< orphan*/  _glfwInputCursorEnter (TYPE_8__*,int) ; 
 int /*<<< orphan*/  _glfwInputError (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  _glfwInputFramebufferSize (TYPE_8__*,int,int) ; 
 int /*<<< orphan*/  _glfwInputWindowCloseRequest (TYPE_8__*) ; 
 int /*<<< orphan*/  _glfwInputWindowDamage (TYPE_8__*) ; 
 int /*<<< orphan*/  _glfwInputWindowFocus (TYPE_8__*,int) ; 
 int /*<<< orphan*/  _glfwInputWindowSize (TYPE_8__*,int,int) ; 
 void _glfwPlatformSetCursor (TYPE_8__*,TYPE_9__*) ; 
 void _glfwPlatformSetWindowSize (TYPE_8__*,int,int) ; 
 char* calloc (scalar_t__,int) ; 
 int /*<<< orphan*/  close (int) ; 
 int errno ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  free (char*) ; 
 char* getenv (char*) ; 
 int mkostemp (char*,int /*<<< orphan*/ ) ; 
 void* mmap (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  munmap (void*,int) ; 
 scalar_t__ poll (struct pollfd*,int,int) ; 
 int posix_fallocate (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  shellSurfaceListener ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strcat (char*,char const*) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 scalar_t__ strlen (char const*) ; 
 int /*<<< orphan*/  unlink (char*) ; 
 int /*<<< orphan*/  wl_buffer_destroy (struct wl_buffer*) ; 
 struct wl_surface* wl_compositor_create_surface (int /*<<< orphan*/ ) ; 
 struct wl_buffer* wl_cursor_image_get_buffer (struct wl_cursor_image*) ; 
 int /*<<< orphan*/  wl_display_cancel_read (struct wl_display*) ; 
 int /*<<< orphan*/  wl_display_dispatch_pending (struct wl_display*) ; 
 scalar_t__ wl_display_flush (struct wl_display*) ; 
 int /*<<< orphan*/  wl_display_get_fd (struct wl_display*) ; 
 scalar_t__ wl_display_prepare_read (struct wl_display*) ; 
 int /*<<< orphan*/  wl_display_read_events (struct wl_display*) ; 
 int /*<<< orphan*/  wl_display_sync (struct wl_display*) ; 
 scalar_t__ wl_egl_window_create (struct wl_surface*,int,int) ; 
 int /*<<< orphan*/  wl_egl_window_destroy (scalar_t__) ; 
 int /*<<< orphan*/  wl_egl_window_resize (scalar_t__,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wl_pointer_set_cursor (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct wl_surface*,int,int) ; 
 scalar_t__ wl_shell_get_shell_surface (int /*<<< orphan*/ ,struct wl_surface*) ; 
 int /*<<< orphan*/  wl_shell_surface_add_listener (scalar_t__,int /*<<< orphan*/ *,TYPE_8__*) ; 
 int /*<<< orphan*/  wl_shell_surface_destroy (scalar_t__) ; 
 int /*<<< orphan*/  wl_shell_surface_pong (struct wl_shell_surface*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wl_shell_surface_set_fullscreen (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wl_shell_surface_set_title (scalar_t__,char const*) ; 
 int /*<<< orphan*/  wl_shell_surface_set_toplevel (scalar_t__) ; 
 struct wl_shm_pool* wl_shm_create_pool (int /*<<< orphan*/ ,int,int) ; 
 struct wl_buffer* wl_shm_pool_create_buffer (struct wl_shm_pool*,int /*<<< orphan*/ ,int,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wl_shm_pool_destroy (struct wl_shm_pool*) ; 
 int /*<<< orphan*/  wl_surface_attach (struct wl_surface*,struct wl_buffer*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wl_surface_commit (struct wl_surface*) ; 
 int /*<<< orphan*/  wl_surface_damage (struct wl_surface*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  wl_surface_destroy (struct wl_surface*) ; 
 int /*<<< orphan*/  wl_surface_set_user_data (struct wl_surface*,TYPE_8__*) ; 

__attribute__((used)) static void handlePing(void* data,
                       struct wl_shell_surface* shellSurface,
                       uint32_t serial)
{
    wl_shell_surface_pong(shellSurface, serial);
}

__attribute__((used)) static void handleConfigure(void* data,
                            struct wl_shell_surface* shellSurface,
                            uint32_t edges,
                            int32_t width,
                            int32_t height)
{
    _GLFWwindow* window = data;
    _glfwInputFramebufferSize(window, width, height);
    _glfwInputWindowSize(window, width, height);
    _glfwPlatformSetWindowSize(window, width, height);
    _glfwInputWindowDamage(window);
}

__attribute__((used)) static void handlePopupDone(void* data,
                            struct wl_shell_surface* shellSurface)
{
}

__attribute__((used)) static GLboolean createSurface(_GLFWwindow* window,
                               const _GLFWwndconfig* wndconfig)
{
    window->wl.surface = wl_compositor_create_surface(_glfw.wl.compositor);
    if (!window->wl.surface)
        return GL_FALSE;

    wl_surface_set_user_data(window->wl.surface, window);

    window->wl.native = wl_egl_window_create(window->wl.surface,
                                             wndconfig->width,
                                             wndconfig->height);
    if (!window->wl.native)
        return GL_FALSE;

    window->wl.shell_surface = wl_shell_get_shell_surface(_glfw.wl.shell,
                                                          window->wl.surface);
    if (!window->wl.shell_surface)
        return GL_FALSE;

    wl_shell_surface_add_listener(window->wl.shell_surface,
                                  &shellSurfaceListener,
                                  window);

    window->wl.width = wndconfig->width;
    window->wl.height = wndconfig->height;

    return GL_TRUE;
}

__attribute__((used)) static int
createTmpfileCloexec(char* tmpname)
{
    int fd;

    fd = mkostemp(tmpname, O_CLOEXEC);
    if (fd >= 0)
        unlink(tmpname);

    return fd;
}

__attribute__((used)) static void
handleEvents(int timeout)
{
    struct wl_display* display = _glfw.wl.display;
    struct pollfd fds[] = {
        { wl_display_get_fd(display), POLLIN },
    };

    while (wl_display_prepare_read(display) != 0)
        wl_display_dispatch_pending(display);

    // If an error different from EAGAIN happens, we have likely been
    // disconnected from the Wayland session, try to handle that the best we
    // can.
    if (wl_display_flush(display) < 0 && errno != EAGAIN)
    {
        _GLFWwindow* window = _glfw.windowListHead;
        while (window)
        {
            _glfwInputWindowCloseRequest(window);
            window = window->next;
        }
        wl_display_cancel_read(display);
        return;
    }

    if (poll(fds, 1, timeout) > 0)
    {
        wl_display_read_events(display);
        wl_display_dispatch_pending(display);
    }
    else
    {
        wl_display_cancel_read(display);
    }
}

int
createAnonymousFile(off_t size)
{
    static const char template[] = "/glfw-shared-XXXXXX";
    const char* path;
    char* name;
    int fd;
    int ret;

    path = getenv("XDG_RUNTIME_DIR");
    if (!path)
    {
        errno = ENOENT;
        return -1;
    }

    name = calloc(strlen(path) + sizeof(template), 1);
    strcpy(name, path);
    strcat(name, template);

    fd = createTmpfileCloexec(name);

    free(name);

    if (fd < 0)
        return -1;
    ret = posix_fallocate(fd, 0, size);
    if (ret != 0)
    {
        close(fd);
        errno = ret;
        return -1;
    }
    return fd;
}

int _glfwPlatformCreateWindow(_GLFWwindow* window,
                              const _GLFWwndconfig* wndconfig,
                              const _GLFWctxconfig* ctxconfig,
                              const _GLFWfbconfig* fbconfig)
{
    if (!_glfwCreateContext(window, ctxconfig, fbconfig))
        return GL_FALSE;

    if (!createSurface(window, wndconfig))
        return GL_FALSE;

    if (wndconfig->monitor)
    {
        wl_shell_surface_set_fullscreen(
            window->wl.shell_surface,
            WL_SHELL_SURFACE_FULLSCREEN_METHOD_DEFAULT,
            0,
            wndconfig->monitor->wl.output);
    }
    else
    {
        wl_shell_surface_set_toplevel(window->wl.shell_surface);
    }

    window->wl.currentCursor = NULL;

    return GL_TRUE;
}

void _glfwPlatformDestroyWindow(_GLFWwindow* window)
{
    if (window == _glfw.wl.pointerFocus)
    {
        _glfw.wl.pointerFocus = NULL;
        _glfwInputCursorEnter(window, GL_FALSE);
    }
    if (window == _glfw.wl.keyboardFocus)
    {
        _glfw.wl.keyboardFocus = NULL;
        _glfwInputWindowFocus(window, GL_FALSE);
    }

    _glfwDestroyContext(window);

    if (window->wl.native)
        wl_egl_window_destroy(window->wl.native);

    if (window->wl.shell_surface)
        wl_shell_surface_destroy(window->wl.shell_surface);

    if (window->wl.surface)
        wl_surface_destroy(window->wl.surface);
}

void _glfwPlatformSetWindowTitle(_GLFWwindow* window, const char* title)
{
    wl_shell_surface_set_title(window->wl.shell_surface, title);
}

void _glfwPlatformGetWindowPos(_GLFWwindow* window, int* xpos, int* ypos)
{
    // A Wayland client is not aware of its position, so just warn and leave it
    // as (0, 0)

    _glfwInputError(GLFW_PLATFORM_ERROR,
                    "Wayland: Window position retrieval not supported");
}

void _glfwPlatformSetWindowPos(_GLFWwindow* window, int xpos, int ypos)
{
    // A Wayland client can not set its position, so just warn

    _glfwInputError(GLFW_PLATFORM_ERROR,
                    "Wayland: Window position setting not supported");
}

void _glfwPlatformGetWindowSize(_GLFWwindow* window, int* width, int* height)
{
    if (width)
        *width = window->wl.width;
    if (height)
        *height = window->wl.height;
}

void _glfwPlatformSetWindowSize(_GLFWwindow* window, int width, int height)
{
    wl_egl_window_resize(window->wl.native, width, height, 0, 0);
    window->wl.width = width;
    window->wl.height = height;
}

void _glfwPlatformGetFramebufferSize(_GLFWwindow* window, int* width, int* height)
{
    _glfwPlatformGetWindowSize(window, width, height);
}

void _glfwPlatformGetWindowFrameSize(_GLFWwindow* window,
                                     int* left, int* top,
                                     int* right, int* bottom)
{
    // TODO
    fprintf(stderr, "_glfwPlatformGetWindowFrameSize not implemented yet\n");
}

void _glfwPlatformIconifyWindow(_GLFWwindow* window)
{
    // TODO
    fprintf(stderr, "_glfwPlatformIconifyWindow not implemented yet\n");
}

void _glfwPlatformRestoreWindow(_GLFWwindow* window)
{
    // TODO
    fprintf(stderr, "_glfwPlatformRestoreWindow not implemented yet\n");
}

void _glfwPlatformShowWindow(_GLFWwindow* window)
{
    wl_shell_surface_set_toplevel(window->wl.shell_surface);
}

void _glfwPlatformUnhideWindow(_GLFWwindow* window)
{
    // TODO
    fprintf(stderr, "_glfwPlatformUnhideWindow not implemented yet\n");
}

void _glfwPlatformHideWindow(_GLFWwindow* window)
{
    wl_surface_attach(window->wl.surface, NULL, 0, 0);
    wl_surface_commit(window->wl.surface);
}

int _glfwPlatformWindowFocused(_GLFWwindow* window)
{
    // TODO
    return GL_FALSE;
}

int _glfwPlatformWindowIconified(_GLFWwindow* window)
{
    // TODO
    return GL_FALSE;
}

int _glfwPlatformWindowVisible(_GLFWwindow* window)
{
    // TODO
    return GL_FALSE;
}

void _glfwPlatformPollEvents(void)
{
    handleEvents(0);
}

void _glfwPlatformWaitEvents(void)
{
    handleEvents(-1);
}

void _glfwPlatformPostEmptyEvent(void)
{
    wl_display_sync(_glfw.wl.display);
}

void _glfwPlatformGetCursorPos(_GLFWwindow* window, double* xpos, double* ypos)
{
    if (xpos)
        *xpos = window->wl.cursorPosX;
    if (ypos)
        *ypos = window->wl.cursorPosY;
}

void _glfwPlatformSetCursorPos(_GLFWwindow* window, double x, double y)
{
    // A Wayland client can not set the cursor position
    _glfwInputError(GLFW_PLATFORM_ERROR,
                    "Wayland: Cursor position setting not supported");
}

void _glfwPlatformApplyCursorMode(_GLFWwindow* window)
{
    _glfwPlatformSetCursor(window, window->wl.currentCursor);
}

int _glfwPlatformCreateCursor(_GLFWcursor* cursor,
                              const GLFWimage* image,
                              int xhot, int yhot)
{
    struct wl_shm_pool* pool;
    int stride = image->width * 4;
    int length = image->width * image->height * 4;
    void* data;
    int fd, i;

    fd = createAnonymousFile(length);
    if (fd < 0)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Wayland: Creating a buffer file for %d B failed: %m\n",
                        length);
        return GL_FALSE;
    }

    data = mmap(NULL, length, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (data == MAP_FAILED)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Wayland: Cursor mmap failed: %m\n");
        close(fd);
        return GL_FALSE;
    }

    pool = wl_shm_create_pool(_glfw.wl.shm, fd, length);

    close(fd);
    unsigned char* source = (unsigned char*) image->pixels;
    unsigned char* target = data;
    for (i = 0;  i < image->width * image->height;  i++, source += 4)
    {
        *target++ = source[2];
        *target++ = source[1];
        *target++ = source[0];
        *target++ = source[3];
    }

    cursor->wl.buffer =
        wl_shm_pool_create_buffer(pool, 0,
                                  image->width,
                                  image->height,
                                  stride, WL_SHM_FORMAT_ARGB8888);
    munmap(data, length);
    wl_shm_pool_destroy(pool);

    cursor->wl.width = image->width;
    cursor->wl.height = image->height;
    cursor->wl.xhot = xhot;
    cursor->wl.yhot = yhot;
    return GL_TRUE;
}

int _glfwPlatformCreateStandardCursor(_GLFWcursor* cursor, int shape)
{
    // TODO
    fprintf(stderr, "_glfwPlatformCreateStandardCursor not implemented yet\n");
    return GL_FALSE;
}

void _glfwPlatformDestroyCursor(_GLFWcursor* cursor)
{
    wl_buffer_destroy(cursor->wl.buffer);
}

void _glfwPlatformSetCursor(_GLFWwindow* window, _GLFWcursor* cursor)
{
    struct wl_buffer* buffer;
    struct wl_cursor_image* image;
    struct wl_surface* surface = _glfw.wl.cursorSurface;

    if (!_glfw.wl.pointer)
        return;

    window->wl.currentCursor = cursor;

    // If we're not in the correct window just save the cursor
    // the next time the pointer enters the window the cursor will change
    if (window != _glfw.wl.pointerFocus)
        return;

    if (window->cursorMode == GLFW_CURSOR_NORMAL)
    {
        if (cursor == NULL)
        {
            image = _glfw.wl.defaultCursor->images[0];
            buffer = wl_cursor_image_get_buffer(image);
            if (!buffer)
                return;
            wl_pointer_set_cursor(_glfw.wl.pointer, _glfw.wl.pointerSerial,
                                  surface,
                                  image->hotspot_x,
                                  image->hotspot_y);
            wl_surface_attach(surface, buffer, 0, 0);
            wl_surface_damage(surface, 0, 0,
                              image->width, image->height);
            wl_surface_commit(surface);
        }
        else
        {
            wl_pointer_set_cursor(_glfw.wl.pointer, _glfw.wl.pointerSerial,
                                  surface,
                                  cursor->wl.xhot,
                                  cursor->wl.yhot);
            wl_surface_attach(surface, cursor->wl.buffer, 0, 0);
            wl_surface_damage(surface, 0, 0,
                              cursor->wl.width, cursor->wl.height);
            wl_surface_commit(surface);
        }
    }
    else /* Cursor is hidden set cursor surface to NULL */
    {
        wl_pointer_set_cursor(_glfw.wl.pointer, _glfw.wl.pointerSerial, NULL, 0, 0);
    }
}

void _glfwPlatformSetClipboardString(_GLFWwindow* window, const char* string)
{
    // TODO
    fprintf(stderr, "_glfwPlatformSetClipboardString not implemented yet\n");
}

const char* _glfwPlatformGetClipboardString(_GLFWwindow* window)
{
    // TODO
    fprintf(stderr, "_glfwPlatformGetClipboardString not implemented yet\n");
    return NULL;
}

