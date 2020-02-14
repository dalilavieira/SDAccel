#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  scalar_t__ GLuint ;
typedef  int GLsizei ;
typedef  int EGLint ;
typedef  int /*<<< orphan*/  EGLSurface ;
typedef  int /*<<< orphan*/  EGLNativeWindowType ;
typedef  int /*<<< orphan*/  EGLDisplay ;
typedef  int /*<<< orphan*/  EGLContext ;
typedef  int /*<<< orphan*/  EGLConfig ;

/* Variables and functions */
#define  EGL_ALPHA_SIZE 135 
#define  EGL_BLUE_SIZE 134 
#define  EGL_CONTEXT_CLIENT_VERSION 133 
 int /*<<< orphan*/  EGL_DEFAULT_DISPLAY ; 
#define  EGL_GREEN_SIZE 132 
#define  EGL_NONE 131 
 int /*<<< orphan*/  EGL_NO_CONTEXT ; 
#define  EGL_RED_SIZE 130 
#define  EGL_SURFACE_TYPE 129 
#define  EGL_WINDOW_BIT 128 
 int /*<<< orphan*/  GL_FRAGMENT_SHADER ; 
 int /*<<< orphan*/  GL_VERTEX_SHADER ; 
 int /*<<< orphan*/  REPORT_RESULT (int) ; 
 int /*<<< orphan*/  abort () ; 
 int /*<<< orphan*/  eglChooseConfig (int /*<<< orphan*/ ,int const*,int /*<<< orphan*/ *,int,int*) ; 
 int /*<<< orphan*/  eglCreateContext (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int const*) ; 
 int /*<<< orphan*/  eglCreateWindowSurface (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  eglGetDisplay (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  eglInitialize (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  eglMakeCurrent (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glAttachShader (scalar_t__,scalar_t__) ; 
 scalar_t__ glCreateProgram () ; 
 scalar_t__ glCreateShader (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glGetAttachedShaders (scalar_t__,int,int*,scalar_t__*) ; 
 scalar_t__ glGetError () ; 
 int /*<<< orphan*/  printf (char*,char const*) ; 

__attribute__((used)) static void die(const char *msg)
{
   printf("%s\n", msg);
   abort();
}

__attribute__((used)) static void create_context(void)
{
   EGLint num_config;
   EGLContext g_egl_ctx;
   EGLDisplay g_egl_dpy;
   EGLConfig g_config;

   static const EGLint attribute_list[] =
   {
      EGL_RED_SIZE, 8,
      EGL_GREEN_SIZE, 8,
      EGL_BLUE_SIZE, 8,
      EGL_ALPHA_SIZE, 8,
      EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
      EGL_NONE
   };

   static const EGLint context_attributes[] =
   {
      EGL_CONTEXT_CLIENT_VERSION, 2,
      EGL_NONE
   };

   g_egl_dpy = eglGetDisplay(EGL_DEFAULT_DISPLAY);
   if (!g_egl_dpy)
      die("failed to create display");

   if (!eglInitialize(g_egl_dpy, NULL, NULL))
      die("failed to initialize egl");

   if (!eglChooseConfig(g_egl_dpy, attribute_list, &g_config, 1, &num_config))
      die("failed to choose config");

   g_egl_ctx = eglCreateContext(g_egl_dpy, g_config, EGL_NO_CONTEXT, context_attributes);
   if (!g_egl_ctx)
      die("failed to create context");

    EGLNativeWindowType dummyWindow;
    EGLSurface surface = eglCreateWindowSurface(g_egl_dpy, g_config, dummyWindow, NULL);
    if (!surface)
      die("failed to create window surface");

   if (!eglMakeCurrent(g_egl_dpy, surface, surface, g_egl_ctx))
      die("failed to activate context");
}

int main(int argc, char *argv[])
{
   unsigned i;

   create_context();

   GLuint prog = glCreateProgram();
   if (glGetError())
      die("failed to create program");

   GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
   if (glGetError())
      die("failed to create vertex shader");
   glAttachShader(prog, vertex);

   GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
   if (glGetError())
      die("failed to create fragment shader");
   glAttachShader(prog, fragment);

   GLuint shaders[2];
   GLsizei count;

   glGetAttachedShaders(prog, 2, &count, shaders);
   if (glGetError())
      die("failed to get attached shaders");
   if (count != 2)
      die("unknown number of shaders returned");
   if (shaders[0] == shaders[1])
      die("returned identical shaders");

   for (i = 0; i < count; i++)
   {
      if (shaders[i] == 0)
         die("returned 0");
      if (shaders[i] != vertex && shaders[i] != fragment)
         die("unknown shader returned");
   }

   REPORT_RESULT(1);

   return 0;
}

