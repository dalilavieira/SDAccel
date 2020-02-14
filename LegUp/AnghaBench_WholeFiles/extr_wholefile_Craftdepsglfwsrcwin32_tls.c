#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  _GLFWwindow ;
struct TYPE_3__ {scalar_t__ context; int allocated; } ;
struct TYPE_4__ {TYPE_1__ win32_tls; } ;

/* Variables and functions */
 int /*<<< orphan*/  GLFW_PLATFORM_ERROR ; 
 int GL_FALSE ; 
 int GL_TRUE ; 
 scalar_t__ TLS_OUT_OF_INDEXES ; 
 scalar_t__ TlsAlloc () ; 
 int /*<<< orphan*/  TlsFree (scalar_t__) ; 
 int /*<<< orphan*/ * TlsGetValue (scalar_t__) ; 
 int /*<<< orphan*/  TlsSetValue (scalar_t__,int /*<<< orphan*/ *) ; 
 TYPE_2__ _glfw ; 
 int /*<<< orphan*/  _glfwInputError (int /*<<< orphan*/ ,char*) ; 

int _glfwCreateContextTLS(void)
{
    _glfw.win32_tls.context = TlsAlloc();
    if (_glfw.win32_tls.context == TLS_OUT_OF_INDEXES)
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "Win32: Failed to allocate TLS index");
        return GL_FALSE;
    }

    _glfw.win32_tls.allocated = GL_TRUE;
    return GL_TRUE;
}

void _glfwDestroyContextTLS(void)
{
    if (_glfw.win32_tls.allocated)
        TlsFree(_glfw.win32_tls.context);
}

void _glfwSetContextTLS(_GLFWwindow* context)
{
    TlsSetValue(_glfw.win32_tls.context, context);
}

_GLFWwindow* _glfwPlatformGetCurrentContext(void)
{
    return TlsGetValue(_glfw.win32_tls.context);
}

