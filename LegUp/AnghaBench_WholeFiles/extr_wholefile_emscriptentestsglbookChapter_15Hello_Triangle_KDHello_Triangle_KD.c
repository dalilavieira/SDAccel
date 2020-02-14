#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {scalar_t__ eglContext; int /*<<< orphan*/  eglDisplay; scalar_t__ eglSurface; scalar_t__ programObject; } ;
typedef  TYPE_1__ UserData ;
struct TYPE_8__ {scalar_t__ type; } ;
typedef  int /*<<< orphan*/  KDint ;
typedef  int /*<<< orphan*/  KDchar ;
typedef  int /*<<< orphan*/  KDWindow ;
typedef  TYPE_2__ KDEvent ;
typedef  scalar_t__ GLuint ;
typedef  int GLint ;
typedef  float GLfloat ;
typedef  int /*<<< orphan*/  GLenum ;
typedef  char GLbyte ;
typedef  int EGLint ;
typedef  scalar_t__ EGLSurface ;
typedef  int /*<<< orphan*/  EGLNativeWindowType ;
typedef  scalar_t__ EGLContext ;
typedef  int /*<<< orphan*/  EGLConfig ;
typedef  int /*<<< orphan*/  EGLBoolean ;

/* Variables and functions */
 int EGL_ALPHA_SIZE ; 
 int EGL_BLUE_SIZE ; 
 int EGL_CONTEXT_CLIENT_VERSION ; 
 int /*<<< orphan*/  EGL_DEFAULT_DISPLAY ; 
 int EGL_DEPTH_SIZE ; 
 int EGL_DONT_CARE ; 
 int /*<<< orphan*/  EGL_FALSE ; 
 int EGL_GREEN_SIZE ; 
 int EGL_NONE ; 
 scalar_t__ EGL_NO_CONTEXT ; 
 scalar_t__ EGL_NO_SURFACE ; 
 int EGL_RED_SIZE ; 
 int EGL_STENCIL_SIZE ; 
 int /*<<< orphan*/  EGL_TRUE ; 
 int FALSE ; 
 int /*<<< orphan*/  GL_COLOR_BUFFER_BIT ; 
 int /*<<< orphan*/  GL_COMPILE_STATUS ; 
 int /*<<< orphan*/  GL_FALSE ; 
 int /*<<< orphan*/  GL_FLOAT ; 
 int /*<<< orphan*/  GL_FRAGMENT_SHADER ; 
 int /*<<< orphan*/  GL_INFO_LOG_LENGTH ; 
 int /*<<< orphan*/  GL_LINK_STATUS ; 
 int /*<<< orphan*/  GL_TRIANGLES ; 
 int /*<<< orphan*/  GL_VERTEX_SHADER ; 
 scalar_t__ KD_EVENT_WINDOW_CLOSE ; 
 int /*<<< orphan*/ * KD_NULL ; 
 int TRUE ; 
 int /*<<< orphan*/  eglChooseConfig (int /*<<< orphan*/ ,int*,int /*<<< orphan*/ *,int,int*) ; 
 scalar_t__ eglCreateContext (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int*) ; 
 scalar_t__ eglCreateWindowSurface (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  eglDestroyContext (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  eglDestroySurface (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  eglGetConfigs (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  eglGetDisplay (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  eglInitialize (int /*<<< orphan*/ ,int*,int*) ; 
 int /*<<< orphan*/  eglMakeCurrent (int /*<<< orphan*/ ,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  eglSwapBuffers (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  glAttachShader (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  glBindAttribLocation (scalar_t__,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  glClear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glClearColor (float,float,float,float) ; 
 int /*<<< orphan*/  glCompileShader (scalar_t__) ; 
 scalar_t__ glCreateProgram () ; 
 scalar_t__ glCreateShader (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glDeleteProgram (scalar_t__) ; 
 int /*<<< orphan*/  glDeleteShader (scalar_t__) ; 
 int /*<<< orphan*/  glDrawArrays (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  glEnableVertexAttribArray (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glGetProgramInfoLog (scalar_t__,int,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  glGetProgramiv (scalar_t__,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  glGetShaderInfoLog (scalar_t__,int,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  glGetShaderiv (scalar_t__,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  glLinkProgram (scalar_t__) ; 
 int /*<<< orphan*/  glShaderSource (scalar_t__,int,char const**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glUseProgram (scalar_t__) ; 
 int /*<<< orphan*/  glVertexAttribPointer (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,float*) ; 
 int /*<<< orphan*/  glViewport (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/ * kdCreateWindow (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kdDestroyWindow (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kdExit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kdFree (char*) ; 
 int /*<<< orphan*/  kdLogMessage (char*) ; 
 char* kdMalloc (int) ; 
 scalar_t__ kdRealizeWindow (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 TYPE_2__* kdWaitEvent (int /*<<< orphan*/ ) ; 

GLuint LoadShader ( GLenum type, const char *shaderSrc )
{
   GLuint shader;
   GLint compiled;
   
   // Create the shader object
   shader = glCreateShader ( type );

   if ( shader == 0 )
   	return 0;

   // Load the shader source
   glShaderSource ( shader, 1, &shaderSrc, NULL );
   
   // Compile the shader
   glCompileShader ( shader );

   // Check the compile status
   glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled );

   if ( !compiled ) 
   {
      GLint infoLen = 0;

      glGetShaderiv ( shader, GL_INFO_LOG_LENGTH, &infoLen );
      
      if ( infoLen > 1 )
      {
         char* infoLog = kdMalloc (sizeof(char) * infoLen );

         glGetShaderInfoLog ( shader, infoLen, NULL, infoLog );
         kdLogMessage ( infoLog );            
         
         kdFree ( infoLog );
      }

      glDeleteShader ( shader );
      return 0;
   }

   return shader;

}

int Init ( UserData *userData )
{
   GLbyte vShaderStr[] =  
      "attribute vec4 vPosition;    \n"
      "void main()                  \n"
      "{                            \n"
      "   gl_Position = vPosition;  \n"
      "}                            \n";
   
   GLbyte fShaderStr[] =  
      "precision mediump float;\n"\
      "void main()                                  \n"
      "{                                            \n"
      "  gl_FragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );\n"
      "}                                            \n";

   GLuint vertexShader;
   GLuint fragmentShader;
   GLuint programObject;
   GLint linked;

   // Load the vertex/fragment shaders
   vertexShader = LoadShader ( GL_VERTEX_SHADER, vShaderStr );
   fragmentShader = LoadShader ( GL_FRAGMENT_SHADER, fShaderStr );

   // Create the program object
   programObject = glCreateProgram ( );
   
   if ( programObject == 0 )
      return 0;

   glAttachShader ( programObject, vertexShader );
   glAttachShader ( programObject, fragmentShader );

   // Bind vPosition to attribute 0   
   glBindAttribLocation ( programObject, 0, "vPosition" );

   // Link the program
   glLinkProgram ( programObject );

   // Check the link status
   glGetProgramiv ( programObject, GL_LINK_STATUS, &linked );

   if ( !linked ) 
   {
      GLint infoLen = 0;

      glGetProgramiv ( programObject, GL_INFO_LOG_LENGTH, &infoLen );
      
      if ( infoLen > 1 )
      {
         char* infoLog = kdMalloc (sizeof(char) * infoLen );

         glGetProgramInfoLog ( programObject, infoLen, NULL, infoLog );
         kdLogMessage ( infoLog );
         
         kdFree ( infoLog );
      }

      glDeleteProgram ( programObject );
      return FALSE;
   }

   // Store the program object
   userData->programObject = programObject;

   glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f );
   return TRUE;
}

void Draw ( UserData *userData )
{
   GLfloat vVertices[] = {  0.0f,  0.5f, 0.0f, 
                           -0.5f, -0.5f, 0.0f,
                            0.5f, -0.5f, 0.0f };
      
   // Set the viewport
   glViewport ( 0, 0, 320, 240 );
   
   // Clear the color buffer
   glClear ( GL_COLOR_BUFFER_BIT );

   // Use the program object
   glUseProgram ( userData->programObject );

   // Load the vertex data
   glVertexAttribPointer ( 0, 3, GL_FLOAT, GL_FALSE, 0, vVertices );
   glEnableVertexAttribArray ( 0 );

   glDrawArrays ( GL_TRIANGLES, 0, 3 );

   eglSwapBuffers ( userData->eglDisplay, userData->eglSurface );
}

EGLBoolean InitEGLContext ( UserData *userData,
                            KDWindow *window,                             
                            EGLConfig config )
{
   EGLContext context;
   EGLSurface surface;   
   EGLint contextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE, EGL_NONE };

   // Get native window handle
   EGLNativeWindowType hWnd;
   if(kdRealizeWindow(window, &hWnd) != 0)
   {
      return EGL_FALSE;
   }
   surface = eglCreateWindowSurface(userData->eglDisplay, config, hWnd, NULL);
   if ( surface == EGL_NO_SURFACE )
   {
      return EGL_FALSE;
   }

   // Create a GL context
   context = eglCreateContext(userData->eglDisplay, config, EGL_NO_CONTEXT, contextAttribs );
   if ( context == EGL_NO_CONTEXT )
   {
      return EGL_FALSE;
   }   

   // Make the context current
   if ( !eglMakeCurrent(userData->eglDisplay, surface, surface, context) )
   {
      return EGL_FALSE;
   }

   userData->eglContext = context;
   userData->eglSurface = surface;

   return EGL_TRUE;
}

KDint kdMain ( KDint argc, const KDchar *const *argv )
{
   EGLint attribList[] =
   {
       EGL_RED_SIZE,       8,
       EGL_GREEN_SIZE,     8,
       EGL_BLUE_SIZE,      8,
       EGL_ALPHA_SIZE,     EGL_DONT_CARE,
       EGL_DEPTH_SIZE,     EGL_DONT_CARE,
       EGL_STENCIL_SIZE,   EGL_DONT_CARE,
       EGL_NONE
   };
   EGLint majorVersion, 
         minorVersion;
   UserData userData;
   EGLint numConfigs;
   EGLConfig config;
   KDWindow *window = KD_NULL;

   userData.eglDisplay = eglGetDisplay( EGL_DEFAULT_DISPLAY );

   // Initialize EGL
   if ( !eglInitialize(userData.eglDisplay, &majorVersion, &minorVersion) )
   {
      return EGL_FALSE;
   }

   // Get configs
   if ( !eglGetConfigs(userData.eglDisplay, NULL, 0, &numConfigs) )
   {
      return EGL_FALSE;
   }

   // Choose config
   if ( !eglChooseConfig(userData.eglDisplay, attribList, &config, 1, &numConfigs) )
   {
      return EGL_FALSE;
   }


   // Use OpenKODE to create a Window
   window = kdCreateWindow ( userData.eglDisplay, config, KD_NULL );
   if( !window )
      kdExit ( 0 );

   if ( !InitEGLContext ( &userData, window, config ) )
      kdExit ( 0 );

   if ( !Init ( &userData ) )
      kdExit ( 0 );

   // Main Loop
   while ( 1 )
   {
      // Wait for an event
      const KDEvent *evt = kdWaitEvent ( 0 );
      if ( evt )
      {
         // Exit app
         if ( evt->type == KD_EVENT_WINDOW_CLOSE)
            break;
      }

      // Draw frame
      Draw ( &userData );
   }

   // EGL clean up 
   eglMakeCurrent ( 0, 0, 0, 0 );
   eglDestroySurface ( userData.eglDisplay, userData.eglSurface );
   eglDestroyContext ( userData.eglDisplay, userData.eglContext );

   // Destroy the window
   kdDestroyWindow(window);

   return 0;
}

