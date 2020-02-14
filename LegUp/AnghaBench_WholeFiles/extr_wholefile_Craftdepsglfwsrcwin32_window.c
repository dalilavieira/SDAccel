#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_30__   TYPE_8__ ;
typedef  struct TYPE_29__   TYPE_7__ ;
typedef  struct TYPE_28__   TYPE_6__ ;
typedef  struct TYPE_27__   TYPE_5__ ;
typedef  struct TYPE_26__   TYPE_4__ ;
typedef  struct TYPE_25__   TYPE_3__ ;
typedef  struct TYPE_24__   TYPE_2__ ;
typedef  struct TYPE_23__   TYPE_1__ ;
typedef  struct TYPE_22__   TYPE_18__ ;

/* Type definitions */
struct TYPE_26__ {scalar_t__ handle; } ;
struct TYPE_27__ {int /*<<< orphan*/  monitor; TYPE_4__ win32; int /*<<< orphan*/  videoMode; TYPE_2__* cursor; scalar_t__ decorated; scalar_t__ resizable; } ;
typedef  TYPE_5__ _GLFWwindow ;
typedef  scalar_t__ WPARAM ;
struct TYPE_30__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; } ;
struct TYPE_29__ {scalar_t__ message; scalar_t__ wParam; int lParam; scalar_t__ time; } ;
struct TYPE_28__ {int /*<<< orphan*/  right; int /*<<< orphan*/  left; } ;
struct TYPE_25__ {int* publicKeys; } ;
struct TYPE_23__ {int /*<<< orphan*/ * handle; } ;
struct TYPE_24__ {TYPE_1__ win32; } ;
struct TYPE_22__ {TYPE_3__ win32; } ;
typedef  TYPE_6__ RECT ;
typedef  int /*<<< orphan*/  POINT ;
typedef  TYPE_7__ MSG ;
typedef  int /*<<< orphan*/ * LPWSTR ;
typedef  int LPARAM ;
typedef  int /*<<< orphan*/  GLboolean ;
typedef  TYPE_8__ GLFWvidmode ;
typedef  scalar_t__ DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  ClientToScreen (scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ClipCursor (TYPE_6__*) ; 
#define  GLFW_ARROW_CURSOR 133 
#define  GLFW_CROSSHAIR_CURSOR 132 
#define  GLFW_HAND_CURSOR 131 
#define  GLFW_HRESIZE_CURSOR 130 
#define  GLFW_IBEAM_CURSOR 129 
 int GLFW_KEY_LEFT_CONTROL ; 
 int GLFW_KEY_RIGHT_CONTROL ; 
 int GLFW_MOD_ALT ; 
 int GLFW_MOD_CONTROL ; 
 int GLFW_MOD_SHIFT ; 
 int GLFW_MOD_SUPER ; 
#define  GLFW_VRESIZE_CURSOR 128 
 int GetAsyncKeyState (scalar_t__) ; 
 int /*<<< orphan*/  GetClientRect (scalar_t__,TYPE_6__*) ; 
 scalar_t__ GetCursorPos (int /*<<< orphan*/ *) ; 
 int GetKeyState (scalar_t__) ; 
 scalar_t__ GetMessageTime () ; 
 int HIWORD (int) ; 
 int /*<<< orphan*/  HWND_TOPMOST ; 
 int /*<<< orphan*/ * IDC_ARROW ; 
 int /*<<< orphan*/ * IDC_CROSS ; 
 int /*<<< orphan*/ * IDC_HAND ; 
 int /*<<< orphan*/ * IDC_IBEAM ; 
 int /*<<< orphan*/ * IDC_SIZENS ; 
 int /*<<< orphan*/ * IDC_SIZEWE ; 
 int /*<<< orphan*/ * LoadCursorW (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  PM_NOREMOVE ; 
 scalar_t__ PeekMessageW (TYPE_7__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SWP_NOCOPYBITS ; 
 int /*<<< orphan*/  SetCursor (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetWindowPos (scalar_t__,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ VK_CONTROL ; 
 scalar_t__ VK_LWIN ; 
 scalar_t__ VK_MENU ; 
 scalar_t__ VK_RWIN ; 
 scalar_t__ VK_SHIFT ; 
 scalar_t__ WM_KEYDOWN ; 
 scalar_t__ WM_KEYUP ; 
 scalar_t__ WM_SYSKEYDOWN ; 
 scalar_t__ WM_SYSKEYUP ; 
 scalar_t__ WS_CAPTION ; 
 scalar_t__ WS_CLIPCHILDREN ; 
 scalar_t__ WS_CLIPSIBLINGS ; 
 scalar_t__ WS_EX_APPWINDOW ; 
 scalar_t__ WS_EX_WINDOWEDGE ; 
 scalar_t__ WS_MAXIMIZEBOX ; 
 scalar_t__ WS_MINIMIZEBOX ; 
 scalar_t__ WS_POPUP ; 
 scalar_t__ WS_SIZEBOX ; 
 scalar_t__ WS_SYSMENU ; 
 scalar_t__ WindowFromPoint (int /*<<< orphan*/ ) ; 
 int _GLFW_KEY_INVALID ; 
 TYPE_18__ _glfw ; 
 int /*<<< orphan*/  _glfwPlatformGetMonitorPos (int /*<<< orphan*/ ,int*,int*) ; 
 int /*<<< orphan*/  _glfwPlatformGetVideoMode (int /*<<< orphan*/ ,TYPE_8__*) ; 
 int /*<<< orphan*/  _glfwRestoreVideoMode (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  _glfwSetVideoMode (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static DWORD getWindowStyle(const _GLFWwindow* window)
{
    DWORD style = WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

    if (window->decorated && !window->monitor)
    {
        style |= WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;

        if (window->resizable)
            style |= WS_MAXIMIZEBOX | WS_SIZEBOX;
    }
    else
        style |= WS_POPUP;

    return style;
}

__attribute__((used)) static DWORD getWindowExStyle(const _GLFWwindow* window)
{
    DWORD style = WS_EX_APPWINDOW;

    if (window->decorated && !window->monitor)
        style |= WS_EX_WINDOWEDGE;

    return style;
}

__attribute__((used)) static void updateClipRect(_GLFWwindow* window)
{
    RECT clipRect;
    GetClientRect(window->win32.handle, &clipRect);
    ClientToScreen(window->win32.handle, (POINT*) &clipRect.left);
    ClientToScreen(window->win32.handle, (POINT*) &clipRect.right);
    ClipCursor(&clipRect);
}

__attribute__((used)) static void hideCursor(_GLFWwindow* window)
{
    POINT pos;

    ClipCursor(NULL);

    if (GetCursorPos(&pos))
    {
        if (WindowFromPoint(pos) == window->win32.handle)
            SetCursor(NULL);
    }
}

__attribute__((used)) static void disableCursor(_GLFWwindow* window)
{
    POINT pos;

    updateClipRect(window);

    if (GetCursorPos(&pos))
    {
        if (WindowFromPoint(pos) == window->win32.handle)
            SetCursor(NULL);
    }
}

__attribute__((used)) static void restoreCursor(_GLFWwindow* window)
{
    POINT pos;

    ClipCursor(NULL);

    if (GetCursorPos(&pos))
    {
        if (WindowFromPoint(pos) == window->win32.handle)
        {
            if (window->cursor)
                SetCursor(window->cursor->win32.handle);
            else
                SetCursor(LoadCursorW(NULL, IDC_ARROW));
        }
    }
}

__attribute__((used)) static LPWSTR translateCursorShape(int shape)
{
    switch (shape)
    {
        case GLFW_ARROW_CURSOR:
            return IDC_ARROW;
        case GLFW_IBEAM_CURSOR:
            return IDC_IBEAM;
        case GLFW_CROSSHAIR_CURSOR:
            return IDC_CROSS;
        case GLFW_HAND_CURSOR:
            return IDC_HAND;
        case GLFW_HRESIZE_CURSOR:
            return IDC_SIZEWE;
        case GLFW_VRESIZE_CURSOR:
            return IDC_SIZENS;
    }

    return NULL;
}

__attribute__((used)) static int getKeyMods(void)
{
    int mods = 0;

    if (GetKeyState(VK_SHIFT) & (1 << 31))
        mods |= GLFW_MOD_SHIFT;
    if (GetKeyState(VK_CONTROL) & (1 << 31))
        mods |= GLFW_MOD_CONTROL;
    if (GetKeyState(VK_MENU) & (1 << 31))
        mods |= GLFW_MOD_ALT;
    if ((GetKeyState(VK_LWIN) | GetKeyState(VK_RWIN)) & (1 << 31))
        mods |= GLFW_MOD_SUPER;

    return mods;
}

__attribute__((used)) static int getAsyncKeyMods(void)
{
    int mods = 0;

    if (GetAsyncKeyState(VK_SHIFT) & (1 << 31))
        mods |= GLFW_MOD_SHIFT;
    if (GetAsyncKeyState(VK_CONTROL) & (1 << 31))
        mods |= GLFW_MOD_CONTROL;
    if (GetAsyncKeyState(VK_MENU) & (1 << 31))
        mods |= GLFW_MOD_ALT;
    if ((GetAsyncKeyState(VK_LWIN) | GetAsyncKeyState(VK_RWIN)) & (1 << 31))
        mods |= GLFW_MOD_SUPER;

    return mods;
}

__attribute__((used)) static int translateKey(WPARAM wParam, LPARAM lParam)
{
    if (wParam == VK_CONTROL)
    {
        // The CTRL keys require special handling

        MSG next;
        DWORD time;

        // Is this an extended key (i.e. right key)?
        if (lParam & 0x01000000)
            return GLFW_KEY_RIGHT_CONTROL;

        // Here is a trick: "Alt Gr" sends LCTRL, then RALT. We only
        // want the RALT message, so we try to see if the next message
        // is a RALT message. In that case, this is a false LCTRL!
        time = GetMessageTime();

        if (PeekMessageW(&next, NULL, 0, 0, PM_NOREMOVE))
        {
            if (next.message == WM_KEYDOWN ||
                next.message == WM_SYSKEYDOWN ||
                next.message == WM_KEYUP ||
                next.message == WM_SYSKEYUP)
            {
                if (next.wParam == VK_MENU &&
                    (next.lParam & 0x01000000) &&
                    next.time == time)
                {
                    // Next message is a RALT down message, which
                    // means that this is not a proper LCTRL message
                    return _GLFW_KEY_INVALID;
                }
            }
        }

        return GLFW_KEY_LEFT_CONTROL;
    }

    return _glfw.win32.publicKeys[HIWORD(lParam) & 0x1FF];
}

__attribute__((used)) static GLboolean enterFullscreenMode(_GLFWwindow* window)
{
    GLFWvidmode mode;
    GLboolean status;
    int xpos, ypos;

    status = _glfwSetVideoMode(window->monitor, &window->videoMode);

    _glfwPlatformGetVideoMode(window->monitor, &mode);
    _glfwPlatformGetMonitorPos(window->monitor, &xpos, &ypos);

    SetWindowPos(window->win32.handle, HWND_TOPMOST,
                 xpos, ypos, mode.width, mode.height, SWP_NOCOPYBITS);

    return status;
}

__attribute__((used)) static void leaveFullscreenMode(_GLFWwindow* window)
{
    _glfwRestoreVideoMode(window->monitor);
}

