#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {scalar_t__ colormap; scalar_t__ border_pixel; } ;
typedef  TYPE_1__ XSetWindowAttributes ;
struct TYPE_13__ {int /*<<< orphan*/  visual; int /*<<< orphan*/  depth; int /*<<< orphan*/  screen; } ;
struct TYPE_12__ {scalar_t__ wnd; scalar_t__ cmap; int /*<<< orphan*/ * dpy; TYPE_3__* vi; int /*<<< orphan*/ * ctx; } ;
typedef  scalar_t__ GLenum ;
typedef  int GLboolean ;
typedef  int /*<<< orphan*/  GLXFBConfig ;
typedef  TYPE_2__ GLContext ;

/* Variables and functions */
 int /*<<< orphan*/  AllocNone ; 
 int CWBorderPixel ; 
 int CWColormap ; 
 int CreateContext (TYPE_2__*) ; 
 int /*<<< orphan*/  DefaultScreen (int /*<<< orphan*/ *) ; 
 void DestroyContext (TYPE_2__*) ; 
 scalar_t__ GLEW_OK ; 
 int /*<<< orphan*/  GLU_EXTENSIONS ; 
 int /*<<< orphan*/  GLU_VERSION ; 
 scalar_t__ GLXEW_NV_float_buffer ; 
 int GLX_ACCUM_ALPHA_SIZE ; 
 int GLX_ACCUM_BLUE_SIZE ; 
 int GLX_ACCUM_GREEN_SIZE ; 
 int GLX_ACCUM_RED_SIZE ; 
 int GLX_ALPHA_SIZE ; 
 int GLX_AUX_BUFFERS ; 
 int GLX_BLUE_SIZE ; 
 int GLX_BUFFER_SIZE ; 
 int GLX_COLOR_INDEX_BIT ; 
 int GLX_CONFIG_CAVEAT ; 
 int GLX_DEPTH_SIZE ; 
 int GLX_DIRECT_COLOR ; 
 int GLX_DOUBLEBUFFER ; 
 int GLX_DRAWABLE_TYPE ; 
 int GLX_FBCONFIG_ID ; 
 int GLX_FLOAT_COMPONENTS_NV ; 
 int GLX_GRAY_SCALE ; 
 int GLX_GREEN_SIZE ; 
 int GLX_LEVEL ; 
 int GLX_NONE ; 
 int GLX_NON_CONFORMANT_CONFIG ; 
 int GLX_PBUFFER_BIT ; 
 int GLX_PIXMAP_BIT ; 
 int GLX_PSEUDO_COLOR ; 
 int GLX_RED_SIZE ; 
 int GLX_RENDER_TYPE ; 
 int GLX_RGBA ; 
 int GLX_RGBA_BIT ; 
 int GLX_RGBA_FLOAT_ATI_BIT ; 
 int GLX_SAMPLES ; 
 int GLX_SAMPLE_BUFFERS ; 
 int GLX_SLOW_CONFIG ; 
 int GLX_STATIC_COLOR ; 
 int GLX_STATIC_GRAY ; 
 int GLX_STENCIL_SIZE ; 
 int GLX_STEREO ; 
 int GLX_TRANSPARENT_INDEX ; 
 int GLX_TRANSPARENT_RGB ; 
 int GLX_TRANSPARENT_TYPE ; 
 int GLX_TRUE_COLOR ; 
 int GLX_WINDOW_BIT ; 
 int GLX_X_RENDERABLE ; 
 int GLX_X_VISUAL_TYPE ; 
 int /*<<< orphan*/  GL_EXTENSIONS ; 
 int GL_FALSE ; 
 int /*<<< orphan*/  GL_RENDERER ; 
 int GL_TRUE ; 
 int /*<<< orphan*/  GL_VENDOR ; 
 int /*<<< orphan*/  GL_VERSION ; 
 void InitContext (TYPE_2__*) ; 
 int /*<<< orphan*/  InputOutput ; 
 int None ; 
 int ParseArgs (int,char**) ; 
 void PrintExtensions (char const*) ; 
 int /*<<< orphan*/  RootWindow (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int Success ; 
 int /*<<< orphan*/  True ; 
 void VisualInfo (TYPE_2__*) ; 
 int /*<<< orphan*/  XCloseDisplay (int /*<<< orphan*/ *) ; 
 scalar_t__ XCreateColormap (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ XCreateWindow (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,TYPE_1__*) ; 
 int /*<<< orphan*/  XDestroyWindow (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  XFree (TYPE_3__*) ; 
 int /*<<< orphan*/  XFreeColormap (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/ * XOpenDisplay (char*) ; 
 char* display ; 
 int /*<<< orphan*/  fclose (scalar_t__) ; 
 scalar_t__ file ; 
 int /*<<< orphan*/  fprintf (scalar_t__,char*,...) ; 
 char* glGetString (int /*<<< orphan*/ ) ; 
 TYPE_3__* glXChooseVisual (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/ * glXCreateContext (int /*<<< orphan*/ *,TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  glXDestroyContext (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * glXGetCurrentDisplay () ; 
 int glXGetFBConfigAttrib (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int*) ; 
 int /*<<< orphan*/ * glXGetFBConfigs (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  glXMakeCurrent (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  glXQueryExtension (int /*<<< orphan*/ *,int*,int*) ; 
 char const* glXQueryExtensionsString (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int glewExperimental ; 
 char* glewGetErrorString (scalar_t__) ; 
 scalar_t__ glewInit () ; 
 char* gluGetString (int /*<<< orphan*/ ) ; 
 scalar_t__ stderr ; 
 scalar_t__ stdout ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 scalar_t__ strlen (char*) ; 
 scalar_t__ strtol (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  verbose ; 
 int visual ; 

int 
main (int argc, char** argv)
{
  GLenum err;
  GLContext ctx;

  /* ---------------------------------------------------------------------- */
  /* parse arguments */
  if (GL_TRUE == ParseArgs(argc-1, argv+1))
  {
#if defined(_WIN32)
    fprintf(stderr, "Usage: visualinfo [-a] [-s] [-h] [-pf <id>]\n");
    fprintf(stderr, "        -a: show all visuals\n");
    fprintf(stderr, "        -s: display to stdout instead of visualinfo.txt\n");
    fprintf(stderr, "        -pf <id>: use given pixelformat\n");
    fprintf(stderr, "        -h: this screen\n");
#else
    fprintf(stderr, "Usage: visualinfo [-h] [-display <display>] [-visual <id>]\n");
    fprintf(stderr, "        -h: this screen\n");
    fprintf(stderr, "        -display <display>: use given display\n");
    fprintf(stderr, "        -visual <id>: use given visual\n");
#endif
    return 1;
  }

  /* ---------------------------------------------------------------------- */
  /* create OpenGL rendering context */
  InitContext(&ctx);
  if (GL_TRUE == CreateContext(&ctx))
  {
    fprintf(stderr, "Error: CreateContext failed\n");
    DestroyContext(&ctx);
    return 1;
  }

  /* ---------------------------------------------------------------------- */
  /* initialize GLEW */
  glewExperimental = GL_TRUE;
#ifdef GLEW_MX
  err = glewContextInit(glewGetContext());
#  ifdef _WIN32
  err = err || wglewContextInit(wglewGetContext());
#  elif !defined(__APPLE__) || defined(GLEW_APPLE_GLX)
  err = err || glxewContextInit(glxewGetContext());
#  endif
#else
  err = glewInit();
#endif
  if (GLEW_OK != err)
  {
    fprintf(stderr, "Error [main]: glewInit failed: %s\n", glewGetErrorString(err));
    DestroyContext(&ctx);
    return 1;
  }

  /* ---------------------------------------------------------------------- */
  /* open file */
#if defined(_WIN32)
  if (!displaystdout) 
    file = fopen("visualinfo.txt", "w");
  if (file == NULL)
    file = stdout;
#else
  file = stdout;
#endif

  /* ---------------------------------------------------------------------- */
  /* output header information */
  /* OpenGL extensions */
  fprintf(file, "OpenGL vendor string: %s\n", glGetString(GL_VENDOR));
  fprintf(file, "OpenGL renderer string: %s\n", glGetString(GL_RENDERER));
  fprintf(file, "OpenGL version string: %s\n", glGetString(GL_VERSION));
  fprintf(file, "OpenGL extensions (GL_): \n");
  PrintExtensions((char*)glGetString(GL_EXTENSIONS));

#ifndef GLEW_NO_GLU
  /* GLU extensions */
  fprintf(file, "GLU version string: %s\n", gluGetString(GLU_VERSION));
  fprintf(file, "GLU extensions (GLU_): \n");
  PrintExtensions((char*)gluGetString(GLU_EXTENSIONS));
#endif

  /* ---------------------------------------------------------------------- */
  /* extensions string */
#if defined(_WIN32)
  /* WGL extensions */
  if (WGLEW_ARB_extensions_string || WGLEW_EXT_extensions_string)
  {
    fprintf(file, "WGL extensions (WGL_): \n");
    PrintExtensions(wglGetExtensionsStringARB ? 
                    (char*)wglGetExtensionsStringARB(ctx.dc) :
		    (char*)wglGetExtensionsStringEXT());
  }
#elif defined(__APPLE__) && !defined(GLEW_APPLE_GLX)
  
#else
  /* GLX extensions */
  fprintf(file, "GLX extensions (GLX_): \n");
  PrintExtensions(glXQueryExtensionsString(glXGetCurrentDisplay(), 
                                           DefaultScreen(glXGetCurrentDisplay())));
#endif

  /* ---------------------------------------------------------------------- */
  /* enumerate all the formats */
  VisualInfo(&ctx);

  /* ---------------------------------------------------------------------- */
  /* release resources */
  DestroyContext(&ctx);
  if (file != stdout)
    fclose(file);
  return 0;
}

void PrintExtensions (const char* s)
{
  char t[80];
  int i=0;
  char* p=0;

  t[79] = '\0';
  while (*s)
  {
    t[i++] = *s;
    if(*s == ' ')
    {
      if (*(s+1) != '\0') {
	t[i-1] = ',';
	t[i] = ' ';
	p = &t[i++];
      }
      else /* zoinks! last one terminated in a space! */
      {
	t[i-1] = '\0';
      }
    }
    if(i > 80 - 5)
    {
      *p = t[i] = '\0';
      fprintf(file, "    %s\n", t);
      p++;
      i = (int)strlen(p);
      strcpy(t, p);
    }
    s++;
  }
  t[i] = '\0';
  fprintf(file, "    %s.\n", t);
}

void
VisualInfo (GLContext* ctx)
{
  int n_fbc;
  GLXFBConfig* fbc;
  int value, ret, i;

  fbc = glXGetFBConfigs(ctx->dpy, DefaultScreen(ctx->dpy), &n_fbc);

  if (fbc)
  {
    if (!verbose)
    {
      /* print table header */
      fprintf(file, " +-----+-------------------------+-----------------+----------+-------------+-------+------+\n");
      fprintf(file, " |     |        visual           |      color      | ax dp st |    accum    |   ms  |  cav |\n");
      fprintf(file, " |  id | tp xr cl fm db st lv xp |  sz  r  g  b  a | bf th cl | r  g  b  a  | ns  b |  eat |\n");
      fprintf(file, " +-----+-------------------------+-----------------+----------+-------------+-------+------+\n");
      /* loop through all the fbcs */
      for (i=0; i<n_fbc; i++)
      {
        /* print out the information for this fbc */
        /* visual id */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_FBCONFIG_ID, &value);
        if (ret != Success)
        {
          fprintf(file, "|  ?  |");
        }
        else
        {
          fprintf(file, " |% 4d | ", value);
        }
        /* visual type */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_DRAWABLE_TYPE, &value);
        if (ret != Success)
        {
          fprintf(file, " ? ");
        }
        else
        {
          if (value & GLX_WINDOW_BIT)
          {
            if (value & GLX_PBUFFER_BIT)
            {
              fprintf(file, "wp ");
            }
            else
            {
              fprintf(file, "wn ");
            }
          }
          else
          {
            if (value & GLX_PBUFFER_BIT)
            {
              fprintf(file, "pb ");
            }
            else if (value & GLX_PIXMAP_BIT)
            {
              fprintf(file, "pm ");
            }
            else
            {
              fprintf(file, " ? ");
            }
          }
        }
        /* x renderable */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_X_RENDERABLE, &value);
        if (ret != Success)
        {
          fprintf(file, " ? ");
        }
        else
        {
          fprintf(file, value ? " y " : " n ");
        }
        /* class */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_X_VISUAL_TYPE, &value);
        if (ret != Success)
        {
          fprintf(file, " ? ");
        }
        else
        {
          if (GLX_TRUE_COLOR == value)
            fprintf(file, "tc ");
          else if (GLX_DIRECT_COLOR == value)
            fprintf(file, "dc ");
          else if (GLX_PSEUDO_COLOR == value)
            fprintf(file, "pc ");
          else if (GLX_STATIC_COLOR == value)
            fprintf(file, "sc ");
          else if (GLX_GRAY_SCALE == value)
            fprintf(file, "gs ");
          else if (GLX_STATIC_GRAY == value)
            fprintf(file, "sg ");
          else if (GLX_X_VISUAL_TYPE == value)
            fprintf(file, " . ");
          else
            fprintf(file, " ? ");
        }
        /* format */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_RENDER_TYPE, &value);
        if (ret != Success)
        {
          fprintf(file, " ? ");
        }
        else
        {
          if (GLXEW_NV_float_buffer)
          {
            int ret2, value2;
            ret2 = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_FLOAT_COMPONENTS_NV, &value2);
            if (Success == ret2 && GL_TRUE == value2)
            {
              fprintf(file, " f ");
            }
            else if (value & GLX_RGBA_BIT)
              fprintf(file, " i ");
            else if (value & GLX_COLOR_INDEX_BIT)
              fprintf(file, " c ");
            else
              fprintf(file, " ? ");
          }
          else
          {
            if (value & GLX_RGBA_FLOAT_ATI_BIT)
              fprintf(file, " f ");
            else if (value & GLX_RGBA_BIT)
              fprintf(file, " i ");
            else if (value & GLX_COLOR_INDEX_BIT)
              fprintf(file, " c ");
            else
              fprintf(file, " ? ");
          }
        }
        /* double buffer */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_DOUBLEBUFFER, &value);
        fprintf(file, " %c ", Success != ret ? '?' : (value ? 'y' : '.'));
        /* stereo */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_STEREO, &value);
        fprintf(file, " %c ", Success != ret ? '?' : (value ? 'y' : '.'));
        /* level */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_LEVEL, &value);
        if (Success != ret)
        {
          fprintf(file, " ? ");
        }
        else
        {
          fprintf(file, "%2d ", value);
        }
        /* transparency */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_TRANSPARENT_TYPE, &value);
        if (Success != ret)
        {
          fprintf(file, " ? | ");
        }
        else
        {
          if (GLX_TRANSPARENT_RGB == value)
            fprintf(file, " r | ");
          else if (GLX_TRANSPARENT_INDEX == value)
            fprintf(file, " i | ");
          else if (GLX_NONE == value)
            fprintf(file, " . | ");
          else
            fprintf(file, " ? | ");
        }
        /* color size */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_BUFFER_SIZE, &value);
        if (Success != ret)
        {
          fprintf(file, "  ? ");
        }
        else
        {
          if (value)
            fprintf(file, "%3d ", value);
          else
            fprintf(file, "  . ");
        }
        /* red size */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_RED_SIZE, &value);
        if (Success != ret)
        {
          fprintf(file, " ? ");
        }
        else
        {
          if (value)
            fprintf(file, "%2d ", value);
          else
            fprintf(file, " . ");
        }
        /* green size */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_GREEN_SIZE, &value);
        if (Success != ret)
        {
          fprintf(file, " ? ");
        }
        else
        {
          if (value)
            fprintf(file, "%2d ", value);
          else
            fprintf(file, " . ");
        }
        /* blue size */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_BLUE_SIZE, &value);
        if (Success != ret)
        {
          fprintf(file, " ? ");
        }
        else
        {
          if (value)
            fprintf(file, "%2d ", value);
          else
            fprintf(file, " . ");
        }
        /* alpha size */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_ALPHA_SIZE, &value);
        if (Success != ret)
        {
          fprintf(file, " ? | ");
        }
        else
        {
          if (value)
            fprintf(file, "%2d | ", value);
          else
            fprintf(file, " . | ");
        }
        /* aux buffers */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_AUX_BUFFERS, &value);
        if (Success != ret)
        {
          fprintf(file, " ? ");
        }
        else
        {
          if (value)
            fprintf(file, "%2d ", value);
          else
            fprintf(file, " . ");
        }
        /* depth size */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_DEPTH_SIZE, &value);
        if (Success != ret)
        {
          fprintf(file, " ? ");
        }
        else
        {
          if (value)
            fprintf(file, "%2d ", value);
          else
            fprintf(file, " . ");
        }
        /* stencil size */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_STENCIL_SIZE, &value);
        if (Success != ret)
        {
          fprintf(file, " ? | ");
        }
        else
        {
          if (value)
            fprintf(file, "%2d | ", value);
          else
            fprintf(file, " . | ");
        }
        /* accum red size */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_ACCUM_RED_SIZE, &value);
        if (Success != ret)
        {
          fprintf(file, " ? ");
        }
        else
        {
          if (value)
            fprintf(file, "%2d ", value);
          else
            fprintf(file, " . ");
        }
        /* accum green size */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_ACCUM_GREEN_SIZE, &value);
        if (Success != ret)
        {
          fprintf(file, " ? ");
        }
        else
        {
          if (value)
            fprintf(file, "%2d ", value);
          else
            fprintf(file, " . ");
        }
        /* accum blue size */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_ACCUM_BLUE_SIZE, &value);
        if (Success != ret)
        {
          fprintf(file, " ? ");
        }
        else
        {
          if (value)
            fprintf(file, "%2d ", value);
          else
            fprintf(file, " . ");
        }
        /* accum alpha size */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_ACCUM_ALPHA_SIZE, &value);
        if (Success != ret)
        {
          fprintf(file, " ? | ");
        }
        else
        {
          if (value)
            fprintf(file, "%2d | ", value);
          else
            fprintf(file, " . | ");
        }
        /* multisample */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_SAMPLES, &value);
        if (Success != ret)
        {
          fprintf(file, " ? ");
        }
        else
        {
          fprintf(file, "%2d ", value);
        }
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_SAMPLE_BUFFERS, &value);
        if (Success != ret)
        {
          fprintf(file, " ? | ");
        }
        else
        {
          fprintf(file, "%2d | ", value);
        }
        /* caveat */
        ret = glXGetFBConfigAttrib(ctx->dpy, fbc[i], GLX_CONFIG_CAVEAT, &value);
        if (Success != ret)
        {
          fprintf(file, "???? |");
        }
        else
        {
          if (GLX_NONE == value)
            fprintf(file, "none |\n");
          else if (GLX_SLOW_CONFIG == value)
            fprintf(file, "slow |\n");
          else if (GLX_NON_CONFORMANT_CONFIG == value)
            fprintf(file, "ncft |\n");
          else
            fprintf(file, "???? |\n");
        }
      }
      /* print table footer */
      fprintf(file, " +-----+-------------------------+-----------------+----------+-------------+-------+------+\n");
      fprintf(file, " |  id | tp xr cl fm db st lv xp |  sz  r  g  b  a | bf th cl | r  g  b  a  | ns  b |  eat |\n");
      fprintf(file, " |     |        visual           |      color      | ax dp st |    accum    |   ms  |  cav |\n");
      fprintf(file, " +-----+-------------------------+-----------------+----------+-------------+-------+------+\n");
    }
  }
}

void InitContext (GLContext* ctx)
{
  ctx->dpy = NULL;
  ctx->vi = NULL;
  ctx->ctx = NULL;
  ctx->wnd = 0;
  ctx->cmap = 0;
}

GLboolean CreateContext (GLContext* ctx)
{
  int attrib[] = { GLX_RGBA, GLX_DOUBLEBUFFER, None };
  int erb, evb;
  XSetWindowAttributes swa;
  /* check input */
  if (NULL == ctx) return GL_TRUE;
  /* open display */
  ctx->dpy = XOpenDisplay(display);
  if (NULL == ctx->dpy) return GL_TRUE;
  /* query for glx */
  if (!glXQueryExtension(ctx->dpy, &erb, &evb)) return GL_TRUE;
  /* choose visual */
  ctx->vi = glXChooseVisual(ctx->dpy, DefaultScreen(ctx->dpy), attrib);
  if (NULL == ctx->vi) return GL_TRUE;
  /* create context */
  ctx->ctx = glXCreateContext(ctx->dpy, ctx->vi, None, True);
  if (NULL == ctx->ctx) return GL_TRUE;
  /* create window */
  /*wnd = XCreateSimpleWindow(dpy, RootWindow(dpy, vi->screen), 0, 0, 1, 1, 1, 0, 0);*/
  ctx->cmap = XCreateColormap(ctx->dpy, RootWindow(ctx->dpy, ctx->vi->screen),
                              ctx->vi->visual, AllocNone);
  swa.border_pixel = 0;
  swa.colormap = ctx->cmap;
  ctx->wnd = XCreateWindow(ctx->dpy, RootWindow(ctx->dpy, ctx->vi->screen), 
                           0, 0, 1, 1, 0, ctx->vi->depth, InputOutput, ctx->vi->visual, 
                           CWBorderPixel | CWColormap, &swa);
  /* make context current */
  if (!glXMakeCurrent(ctx->dpy, ctx->wnd, ctx->ctx)) return GL_TRUE;
  return GL_FALSE;
}

void DestroyContext (GLContext* ctx)
{
  if (NULL != ctx->dpy && NULL != ctx->ctx) glXDestroyContext(ctx->dpy, ctx->ctx);
  if (NULL != ctx->dpy && 0 != ctx->wnd) XDestroyWindow(ctx->dpy, ctx->wnd);
  if (NULL != ctx->dpy && 0 != ctx->cmap) XFreeColormap(ctx->dpy, ctx->cmap);
  if (NULL != ctx->vi) XFree(ctx->vi);
  if (NULL != ctx->dpy) XCloseDisplay(ctx->dpy);
}

GLboolean ParseArgs (int argc, char** argv)
{
  int p = 0;
  while (p < argc)
  {
#if defined(_WIN32)
    if (!strcmp(argv[p], "-pf") || !strcmp(argv[p], "-pixelformat"))
    {
      if (++p >= argc) return GL_TRUE;
      display = NULL;
      visual = strtol(argv[p], NULL, 0);
    }
    else if (!strcmp(argv[p], "-a"))
    {
      showall = 1;
    }
    else if (!strcmp(argv[p], "-s"))
    {
      displaystdout = 1;
    }
    else if (!strcmp(argv[p], "-h"))
    {
      return GL_TRUE;
    }
    else
      return GL_TRUE;
#else
    if (!strcmp(argv[p], "-display"))
    {
      if (++p >= argc) return GL_TRUE;
      display = argv[p];
    }
    else if (!strcmp(argv[p], "-visual"))
    {
      if (++p >= argc) return GL_TRUE;
      visual = (int)strtol(argv[p], NULL, 0);
    }
    else if (!strcmp(argv[p], "-h"))
    {
      return GL_TRUE;
    }
    else
      return GL_TRUE;
#endif
    p++;
  }
  return GL_FALSE;
}

