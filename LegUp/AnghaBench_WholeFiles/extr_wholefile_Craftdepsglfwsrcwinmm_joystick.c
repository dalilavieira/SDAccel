#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_6__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {TYPE_1__* winmm_js; } ;
struct TYPE_9__ {int wCaps; int /*<<< orphan*/  szPname; scalar_t__ wNumButtons; scalar_t__ wVmax; scalar_t__ wVmin; scalar_t__ wUmax; scalar_t__ wUmin; scalar_t__ wRmax; scalar_t__ wRmin; scalar_t__ wZmax; scalar_t__ wZmin; scalar_t__ wYmax; scalar_t__ wYmin; scalar_t__ wXmax; scalar_t__ wXmin; } ;
struct TYPE_8__ {int dwSize; int dwFlags; unsigned long dwButtons; int dwPOV; scalar_t__ dwVpos; scalar_t__ dwUpos; scalar_t__ dwRpos; scalar_t__ dwZpos; scalar_t__ dwYpos; scalar_t__ dwXpos; } ;
struct TYPE_7__ {char const* name; float* axes; unsigned char* buttons; } ;
typedef  TYPE_2__ JOYINFOEX ;
typedef  int /*<<< orphan*/  JOYINFO ;
typedef  TYPE_3__ JOYCAPS ;
typedef  scalar_t__ DWORD ;

/* Variables and functions */
 int GLFW_JOYSTICK_LAST ; 
 unsigned char GLFW_PRESS ; 
 unsigned char GLFW_RELEASE ; 
 int GL_FALSE ; 
 int GL_TRUE ; 
 int JOYCAPS_HASPOV ; 
 int JOYCAPS_HASR ; 
 int JOYCAPS_HASU ; 
 int JOYCAPS_HASV ; 
 int JOYCAPS_HASZ ; 
 int JOYCAPS_POV4DIR ; 
 scalar_t__ JOYERR_NOERROR ; 
 int JOY_RETURNBUTTONS ; 
 int JOY_RETURNPOV ; 
 int JOY_RETURNR ; 
 int JOY_RETURNU ; 
 int JOY_RETURNV ; 
 int JOY_RETURNX ; 
 int JOY_RETURNY ; 
 int JOY_RETURNZ ; 
 TYPE_6__ _glfw ; 
 char const* _glfwCreateUTF8FromWideString (int /*<<< orphan*/ ) ; 
 scalar_t__ _glfw_joyGetDevCaps (int,TYPE_3__*,int) ; 
 scalar_t__ _glfw_joyGetPos (int,int /*<<< orphan*/ *) ; 
 scalar_t__ _glfw_joyGetPosEx (int,TYPE_2__*) ; 
 int /*<<< orphan*/  free (char const*) ; 

__attribute__((used)) static float normalizeAxis(DWORD pos, DWORD min, DWORD max)
{
    float fpos = (float) pos;
    float fmin = (float) min;
    float fmax = (float) max;

    return (2.f * (fpos - fmin) / (fmax - fmin)) - 1.f;
}

void _glfwInitJoysticks(void)
{
}

void _glfwTerminateJoysticks(void)
{
    int i;

    for (i = 0;  i < GLFW_JOYSTICK_LAST;  i++)
        free(_glfw.winmm_js[i].name);
}

int _glfwPlatformJoystickPresent(int joy)
{
    JOYINFO ji;

    if (_glfw_joyGetPos(joy, &ji) != JOYERR_NOERROR)
        return GL_FALSE;

    return GL_TRUE;
}

const float* _glfwPlatformGetJoystickAxes(int joy, int* count)
{
    JOYCAPS jc;
    JOYINFOEX ji;
    float* axes = _glfw.winmm_js[joy].axes;

    if (_glfw_joyGetDevCaps(joy, &jc, sizeof(JOYCAPS)) != JOYERR_NOERROR)
        return NULL;

    ji.dwSize = sizeof(JOYINFOEX);
    ji.dwFlags = JOY_RETURNX | JOY_RETURNY | JOY_RETURNZ |
                 JOY_RETURNR | JOY_RETURNU | JOY_RETURNV;
    if (_glfw_joyGetPosEx(joy, &ji) != JOYERR_NOERROR)
        return NULL;

    axes[(*count)++] = normalizeAxis(ji.dwXpos, jc.wXmin, jc.wXmax);
    axes[(*count)++] = normalizeAxis(ji.dwYpos, jc.wYmin, jc.wYmax);

    if (jc.wCaps & JOYCAPS_HASZ)
        axes[(*count)++] = normalizeAxis(ji.dwZpos, jc.wZmin, jc.wZmax);

    if (jc.wCaps & JOYCAPS_HASR)
        axes[(*count)++] = normalizeAxis(ji.dwRpos, jc.wRmin, jc.wRmax);

    if (jc.wCaps & JOYCAPS_HASU)
        axes[(*count)++] = normalizeAxis(ji.dwUpos, jc.wUmin, jc.wUmax);

    if (jc.wCaps & JOYCAPS_HASV)
        axes[(*count)++] = normalizeAxis(ji.dwVpos, jc.wVmin, jc.wVmax);

    return axes;
}

const unsigned char* _glfwPlatformGetJoystickButtons(int joy, int* count)
{
    JOYCAPS jc;
    JOYINFOEX ji;
    unsigned char* buttons = _glfw.winmm_js[joy].buttons;

    if (_glfw_joyGetDevCaps(joy, &jc, sizeof(JOYCAPS)) != JOYERR_NOERROR)
        return NULL;

    ji.dwSize = sizeof(JOYINFOEX);
    ji.dwFlags = JOY_RETURNBUTTONS | JOY_RETURNPOV;
    if (_glfw_joyGetPosEx(joy, &ji) != JOYERR_NOERROR)
        return NULL;

    while (*count < (int) jc.wNumButtons)
    {
        buttons[*count] = (unsigned char)
            (ji.dwButtons & (1UL << *count) ? GLFW_PRESS : GLFW_RELEASE);
        (*count)++;
    }

    // Virtual buttons - Inject data from hats
    // Each hat is exposed as 4 buttons which exposes 8 directions with
    // concurrent button presses
    // NOTE: this API exposes only one hat

    if ((jc.wCaps & JOYCAPS_HASPOV) && (jc.wCaps & JOYCAPS_POV4DIR))
    {
        int i, value = ji.dwPOV / 100 / 45;

        // Bit fields of button presses for each direction, including nil
        const int directions[9] = { 1, 3, 2, 6, 4, 12, 8, 9, 0 };

        if (value < 0 || value > 8)
            value = 8;

        for (i = 0;  i < 4;  i++)
        {
            if (directions[value] & (1 << i))
                buttons[(*count)++] = GLFW_PRESS;
            else
                buttons[(*count)++] = GLFW_RELEASE;
        }
    }

    return buttons;
}

const char* _glfwPlatformGetJoystickName(int joy)
{
    JOYCAPS jc;

    if (_glfw_joyGetDevCaps(joy, &jc, sizeof(JOYCAPS)) != JOYERR_NOERROR)
        return NULL;

    free(_glfw.winmm_js[joy].name);
    _glfw.winmm_js[joy].name = _glfwCreateUTF8FromWideString(jc.szPname);

    return _glfw.winmm_js[joy].name;
}

