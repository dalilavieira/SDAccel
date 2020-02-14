#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_56__   TYPE_8__ ;
typedef  struct TYPE_55__   TYPE_7__ ;
typedef  struct TYPE_54__   TYPE_6__ ;
typedef  struct TYPE_53__   TYPE_5__ ;
typedef  struct TYPE_52__   TYPE_4__ ;
typedef  struct TYPE_51__   TYPE_3__ ;
typedef  struct TYPE_50__   TYPE_2__ ;
typedef  struct TYPE_49__   TYPE_1__ ;

/* Type definitions */
struct TYPE_55__ {int* ClearColor; int DrawBuffer; scalar_t__ SWmasking; scalar_t__ ClearIndex; } ;
struct TYPE_54__ {char* (* RendererString ) () ;int /*<<< orphan*/  (* SetBuffer ) (TYPE_8__*,int const) ;int /*<<< orphan*/  (* Flush ) (TYPE_8__*) ;int /*<<< orphan*/  (* Finish ) (TYPE_8__*) ;int /*<<< orphan*/  (* ClearDepthBuffer ) (TYPE_8__*) ;int /*<<< orphan*/  (* ClearColorAndDepth ) (TYPE_8__*,int,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ;int /*<<< orphan*/  (* Clear ) (TYPE_8__*,int,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ;int /*<<< orphan*/  (* WriteIndexSpan ) (TYPE_8__*,scalar_t__,scalar_t__,scalar_t__,scalar_t__*,int const*) ;int /*<<< orphan*/  (* WriteColorSpan ) (TYPE_8__*,scalar_t__,scalar_t__,scalar_t__,int const*,int const*,int const*,int const*,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* ClearColor ) (TYPE_8__*,int const,int const,int const,int const) ;int /*<<< orphan*/  (* ClearIndex ) (TYPE_8__*,scalar_t__) ;} ;
struct TYPE_52__ {int ReadBuffer; } ;
struct TYPE_51__ {int Fog; int LineSmooth; int PerspectiveCorrection; int PointSmooth; int PolygonSmooth; } ;
struct TYPE_50__ {scalar_t__ Enabled; } ;
struct TYPE_56__ {int RasterMask; scalar_t__ RenderMode; TYPE_7__ Color; TYPE_6__ Driver; scalar_t__ NewState; TYPE_5__* Buffer; TYPE_4__ Pixel; TYPE_3__ Hint; TYPE_2__ Scissor; TYPE_1__* Visual; } ;
struct TYPE_53__ {scalar_t__ Xmin; scalar_t__ Ymin; scalar_t__ Ymax; scalar_t__ Xmax; scalar_t__ Height; scalar_t__ Width; int /*<<< orphan*/ * BackAlpha; int /*<<< orphan*/ * Alpha; int /*<<< orphan*/ * FrontAlpha; } ;
struct TYPE_49__ {int RedScale; int GreenScale; int BlueScale; int AlphaScale; scalar_t__ RGBAflag; } ;
typedef  scalar_t__ GLuint ;
typedef  int const GLubyte ;
typedef  scalar_t__ GLint ;
typedef  scalar_t__ GLfloat ;
typedef  int GLenum ;
typedef  TYPE_8__ GLcontext ;
typedef  int /*<<< orphan*/  GLclampf ;
typedef  int GLbitfield ;

/* Variables and functions */
 int ALPHABUF_BIT ; 
 void* CLAMP (int /*<<< orphan*/ ,float,float) ; 
 int FRONT_AND_BACK_BIT ; 
 int GL_ACCUM_BUFFER_BIT ; 
#define  GL_AUX0 147 
#define  GL_BACK 146 
#define  GL_BACK_LEFT 145 
#define  GL_BACK_RIGHT 144 
 int GL_COLOR_BUFFER_BIT ; 
 int GL_DEPTH_BUFFER_BIT ; 
 int GL_DONT_CARE ; 
#define  GL_EXTENSIONS 143 
 int /*<<< orphan*/  GL_FALSE ; 
 int GL_FASTEST ; 
#define  GL_FOG_HINT 142 
#define  GL_FRONT 141 
#define  GL_FRONT_AND_BACK 140 
#define  GL_FRONT_LEFT 139 
#define  GL_FRONT_RIGHT 138 
 int /*<<< orphan*/  GL_INVALID_ENUM ; 
 int /*<<< orphan*/  GL_INVALID_OPERATION ; 
#define  GL_LEFT 137 
#define  GL_LINE_SMOOTH_HINT 136 
 int GL_NICEST ; 
#define  GL_NONE 135 
#define  GL_PERSPECTIVE_CORRECTION_HINT 134 
#define  GL_POINT_SMOOTH_HINT 133 
#define  GL_POLYGON_SMOOTH_HINT 132 
 scalar_t__ GL_RENDER ; 
#define  GL_RENDERER 131 
#define  GL_RIGHT 130 
 int GL_STENCIL_BUFFER_BIT ; 
#define  GL_VENDOR 129 
#define  GL_VERSION 128 
 scalar_t__ INSIDE_BEGIN_END (TYPE_8__*) ; 
 int MAX_WIDTH ; 
 int /*<<< orphan*/  MEMSET (int const*,int,scalar_t__) ; 
 scalar_t__ NEW_ALL ; 
 scalar_t__ NEW_RASTER_OPS ; 
 int /*<<< orphan*/  gl_clear_accum_buffer (TYPE_8__*) ; 
 int /*<<< orphan*/  gl_clear_alpha_buffers (TYPE_8__*) ; 
 int /*<<< orphan*/  gl_clear_stencil_buffer (TYPE_8__*) ; 
 int /*<<< orphan*/  gl_error (TYPE_8__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gl_mask_color_span (TYPE_8__*,scalar_t__,scalar_t__,scalar_t__,int const*,int const*,int const*,int const*) ; 
 int /*<<< orphan*/  gl_mask_index_span (TYPE_8__*,scalar_t__,scalar_t__,scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  gl_update_state (TYPE_8__*) ; 
 int /*<<< orphan*/  gl_write_alpha_span (TYPE_8__*,scalar_t__,scalar_t__,scalar_t__,int const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int /*<<< orphan*/  stub1 (TYPE_8__*,scalar_t__) ; 
 int /*<<< orphan*/  stub10 (TYPE_8__*,int) ; 
 int /*<<< orphan*/  stub11 (TYPE_8__*,int,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  stub12 (TYPE_8__*,int) ; 
 int /*<<< orphan*/  stub13 (TYPE_8__*) ; 
 char* stub14 () ; 
 int /*<<< orphan*/  stub15 (TYPE_8__*) ; 
 int /*<<< orphan*/  stub16 (TYPE_8__*) ; 
 int /*<<< orphan*/  stub17 (TYPE_8__*,int const) ; 
 int /*<<< orphan*/  stub18 (TYPE_8__*,int const) ; 
 int /*<<< orphan*/  stub19 (TYPE_8__*,int const) ; 
 int /*<<< orphan*/  stub2 (TYPE_8__*,int const,int const,int const,int const) ; 
 int /*<<< orphan*/  stub20 (TYPE_8__*,int const) ; 
 int /*<<< orphan*/  stub21 (TYPE_8__*,int const) ; 
 int /*<<< orphan*/  stub3 (TYPE_8__*,scalar_t__,scalar_t__,scalar_t__,int const*,int const*,int const*,int const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub4 (TYPE_8__*,scalar_t__,scalar_t__,scalar_t__,scalar_t__*,int const*) ; 
 int /*<<< orphan*/  stub5 (TYPE_8__*,int,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  stub6 (TYPE_8__*,int) ; 
 int /*<<< orphan*/  stub7 (TYPE_8__*,int,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  stub8 (TYPE_8__*,int) ; 
 int /*<<< orphan*/  stub9 (TYPE_8__*,int,scalar_t__,scalar_t__,scalar_t__,scalar_t__) ; 

void gl_ClearIndex( GLcontext *ctx, GLfloat c )
{
   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glClearIndex" );
      return;
   }
   ctx->Color.ClearIndex = (GLuint) c;
   if (!ctx->Visual->RGBAflag) {
      /* it's OK to call glClearIndex in RGBA mode but it should be a NOP */
      (*ctx->Driver.ClearIndex)( ctx, ctx->Color.ClearIndex );
   }
}

void gl_ClearColor( GLcontext *ctx, GLclampf red, GLclampf green,
                    GLclampf blue, GLclampf alpha )
{
   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glClearColor" );
      return;
   }

   ctx->Color.ClearColor[0] = CLAMP( red,   0.0F, 1.0F );
   ctx->Color.ClearColor[1] = CLAMP( green, 0.0F, 1.0F );
   ctx->Color.ClearColor[2] = CLAMP( blue,  0.0F, 1.0F );
   ctx->Color.ClearColor[3] = CLAMP( alpha, 0.0F, 1.0F );

   if (ctx->Visual->RGBAflag) {
      GLubyte r = (GLint) (ctx->Color.ClearColor[0] * ctx->Visual->RedScale);
      GLubyte g = (GLint) (ctx->Color.ClearColor[1] * ctx->Visual->GreenScale);
      GLubyte b = (GLint) (ctx->Color.ClearColor[2] * ctx->Visual->BlueScale);
      GLubyte a = (GLint) (ctx->Color.ClearColor[3] * ctx->Visual->AlphaScale);
      (*ctx->Driver.ClearColor)( ctx, r, g, b, a );
   }
}

__attribute__((used)) static void clear_color_buffer_with_masking( GLcontext *ctx )
{
   GLint x, y, height, width;

   /* Compute region to clear */
   if (ctx->Scissor.Enabled) {
      x = ctx->Buffer->Xmin;
      y = ctx->Buffer->Ymin;
      height = ctx->Buffer->Ymax - ctx->Buffer->Ymin + 1;
      width  = ctx->Buffer->Xmax - ctx->Buffer->Xmin + 1;
   }
   else {
      x = 0;
      y = 0;
      height = ctx->Buffer->Height;
      width  = ctx->Buffer->Width;
   }

   if (ctx->Visual->RGBAflag) {
      /* RGBA mode */
      GLubyte red[MAX_WIDTH], green[MAX_WIDTH];
      GLubyte blue[MAX_WIDTH], alpha[MAX_WIDTH];
      GLubyte r = ctx->Color.ClearColor[0] * ctx->Visual->RedScale;
      GLubyte g = ctx->Color.ClearColor[1] * ctx->Visual->GreenScale;
      GLubyte b = ctx->Color.ClearColor[2] * ctx->Visual->BlueScale;
      GLubyte a = ctx->Color.ClearColor[3] * ctx->Visual->AlphaScale;
      GLint i;
      for (i=0;i<height;i++,y++) {
         MEMSET( red,   (int) r, width );
         MEMSET( green, (int) g, width );
         MEMSET( blue,  (int) b, width );
         MEMSET( alpha, (int) a, width );
         gl_mask_color_span( ctx, width, x, y, red, green, blue, alpha );
         (*ctx->Driver.WriteColorSpan)( ctx,
                                 width, x, y, red, green, blue, alpha, NULL );
         if (ctx->RasterMask & ALPHABUF_BIT) {
            gl_write_alpha_span( ctx, width, x, y, alpha, NULL );
         }
      }
   }
   else {
      /* Color index mode */
      GLuint indx[MAX_WIDTH];
      GLubyte mask[MAX_WIDTH];
      GLint i, j;
      MEMSET( mask, 1, width );
      for (i=0;i<height;i++,y++) {
         for (j=0;j<width;j++) {
            indx[j] = ctx->Color.ClearIndex;
         }
         gl_mask_index_span( ctx, width, x, y, indx );
         (*ctx->Driver.WriteIndexSpan)( ctx, width, x, y, indx, mask );
      }
   }
}

__attribute__((used)) static void clear_color_buffers( GLcontext *ctx )
{
   if (ctx->Color.SWmasking) {
      clear_color_buffer_with_masking( ctx );
   }
   else {
      GLint x = ctx->Buffer->Xmin;
      GLint y = ctx->Buffer->Ymin;
      GLint height = ctx->Buffer->Ymax - ctx->Buffer->Ymin + 1;
      GLint width  = ctx->Buffer->Xmax - ctx->Buffer->Xmin + 1;
      (*ctx->Driver.Clear)( ctx, !ctx->Scissor.Enabled,
                            x, y, width, height );
      if (ctx->RasterMask & ALPHABUF_BIT) {
         /* front and/or back alpha buffers will be cleared here */
         gl_clear_alpha_buffers( ctx );
      }
   }

   if (ctx->RasterMask & FRONT_AND_BACK_BIT) {
      /*** Also clear the back buffer ***/
      (*ctx->Driver.SetBuffer)( ctx, GL_BACK );
      if (ctx->Color.SWmasking) {
         clear_color_buffer_with_masking( ctx );
      }
      else {
         GLint x = ctx->Buffer->Xmin;
         GLint y = ctx->Buffer->Ymin;
         GLint height = ctx->Buffer->Ymax - ctx->Buffer->Ymin + 1;
         GLint width  = ctx->Buffer->Xmax - ctx->Buffer->Xmin + 1;
         (*ctx->Driver.Clear)( ctx, !ctx->Scissor.Enabled,
                               x, y, width, height );
      }
      (*ctx->Driver.SetBuffer)( ctx, GL_FRONT );
   }
}

void gl_Clear( GLcontext *ctx, GLbitfield mask )
{
#ifdef PROFILE
   GLdouble t0 = gl_time();
#endif

   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glClear" );
      return;
   }

   if (ctx->RenderMode==GL_RENDER) {
      if (ctx->NewState) {
         gl_update_state( ctx );
      }

      /* See if we can call device driver function to clear both the
       * color and depth buffers.
       */
      if (ctx->Driver.ClearColorAndDepth &&
          (mask & GL_COLOR_BUFFER_BIT) && (mask & GL_DEPTH_BUFFER_BIT)) {
         GLint x = ctx->Buffer->Xmin;
         GLint y = ctx->Buffer->Ymin;
         GLint height = ctx->Buffer->Ymax - ctx->Buffer->Ymin + 1;
         GLint width  = ctx->Buffer->Xmax - ctx->Buffer->Xmin + 1;
         (*ctx->Driver.ClearColorAndDepth)( ctx, !ctx->Scissor.Enabled,
                                            x, y, width, height );
         if (ctx->RasterMask & FRONT_AND_BACK_BIT) {
            /*** Also clear the back buffer ***/
            (*ctx->Driver.SetBuffer)( ctx, GL_BACK );
            (*ctx->Driver.ClearColorAndDepth)( ctx, !ctx->Scissor.Enabled,
                                               x, y, width, height );
            (*ctx->Driver.SetBuffer)( ctx, GL_FRONT );
         }
      }
      else {
         /* normal procedure for clearing buffers */
         if (mask & GL_COLOR_BUFFER_BIT)  clear_color_buffers( ctx );
         if (mask & GL_DEPTH_BUFFER_BIT)  (*ctx->Driver.ClearDepthBuffer)(ctx);
         if (mask & GL_ACCUM_BUFFER_BIT)   gl_clear_accum_buffer( ctx );
         if (mask & GL_STENCIL_BUFFER_BIT) gl_clear_stencil_buffer( ctx );
      }

#ifdef PROFILE
      ctx->ClearTime += gl_time() - t0;
      ctx->ClearCount++;
#endif
   }
}

const GLubyte *gl_GetString( GLcontext *ctx, GLenum name )
{
   static char renderer[1000];
   static char *vendor = "Brian Paul & ReactOS Developers";
   static char *version = "1.1";
   static char *extensions = "GL_EXT_paletted_texture GL_EXT_bgra GL_WIN_swap_hint";

   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glGetString" );
      return (GLubyte *) 0;
   }

   switch (name) {
      case GL_VENDOR:
         return (GLubyte *) vendor;
      case GL_RENDERER:
         strcpy(renderer, "Mesa");
         if (ctx->Driver.RendererString) {
            strcat(renderer, " ");
            strcat(renderer, (*ctx->Driver.RendererString)());
         }
         return (GLubyte *) renderer;
      case GL_VERSION:
         return (GLubyte *) version;
      case GL_EXTENSIONS:
         return (GLubyte *) extensions;
      default:
         gl_error( ctx, GL_INVALID_ENUM, "glGetString" );
         return (GLubyte *) 0;
   }
}

void gl_Finish( GLcontext *ctx )
{
   /* Don't compile into display list */
   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glFinish" );
      return;
   }
   if (ctx->Driver.Finish) {
      (*ctx->Driver.Finish)( ctx );
   }
}

void gl_Flush( GLcontext *ctx )
{
   /* Don't compile into display list */
   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glFlush" );
      return;
   }
   if (ctx->Driver.Flush) {
      (*ctx->Driver.Flush)( ctx );
   }
}

void gl_Hint( GLcontext *ctx, GLenum target, GLenum mode )
{
   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glHint" );
      return;
   }
   if (mode!=GL_DONT_CARE && mode!=GL_FASTEST && mode!=GL_NICEST) {
      gl_error( ctx, GL_INVALID_ENUM, "glHint(mode)" );
      return;
   }
   switch (target) {
      case GL_FOG_HINT:
         ctx->Hint.Fog = mode;
         break;
      case GL_LINE_SMOOTH_HINT:
         ctx->Hint.LineSmooth = mode;
         break;
      case GL_PERSPECTIVE_CORRECTION_HINT:
         ctx->Hint.PerspectiveCorrection = mode;
         break;
      case GL_POINT_SMOOTH_HINT:
         ctx->Hint.PointSmooth = mode;
         break;
      case GL_POLYGON_SMOOTH_HINT:
         ctx->Hint.PolygonSmooth = mode;
         break;
      default:
         gl_error( ctx, GL_INVALID_ENUM, "glHint(target)" );
   }
   ctx->NewState |= NEW_ALL;   /* just to be safe */
}

void gl_DrawBuffer( GLcontext *ctx, GLenum mode )
{
   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glDrawBuffer" );
      return;
   }
   switch (mode) {
      case GL_FRONT:
      case GL_FRONT_LEFT:
      case GL_FRONT_AND_BACK:
         if ( (*ctx->Driver.SetBuffer)( ctx, GL_FRONT ) == GL_FALSE ) {
            gl_error( ctx, GL_INVALID_ENUM, "glDrawBuffer" );
            return;
         }
         ctx->Color.DrawBuffer = mode;
         ctx->Buffer->Alpha = ctx->Buffer->FrontAlpha;
	 ctx->NewState |= NEW_RASTER_OPS;
         break;
      case GL_BACK:
      case GL_BACK_LEFT:
         if ( (*ctx->Driver.SetBuffer)( ctx, GL_BACK ) == GL_FALSE) {
            gl_error( ctx, GL_INVALID_ENUM, "glDrawBuffer" );
            return;
         }
         ctx->Color.DrawBuffer = mode;
         ctx->Buffer->Alpha = ctx->Buffer->BackAlpha;
	 ctx->NewState |= NEW_RASTER_OPS;
         break;
      case GL_NONE:
         ctx->Color.DrawBuffer = mode;
         ctx->Buffer->Alpha = NULL;
         ctx->NewState |= NEW_RASTER_OPS;
         break;
      case GL_FRONT_RIGHT:
      case GL_BACK_RIGHT:
      case GL_LEFT:
      case GL_RIGHT:
      case GL_AUX0:
         gl_error( ctx, GL_INVALID_OPERATION, "glDrawBuffer" );
         break;
      default:
         gl_error( ctx, GL_INVALID_ENUM, "glDrawBuffer" );
   }
}

void gl_ReadBuffer( GLcontext *ctx, GLenum mode )
{
   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glReadBuffer" );
      return;
   }
   switch (mode) {
      case GL_FRONT:
      case GL_FRONT_LEFT:
         if ( (*ctx->Driver.SetBuffer)( ctx, GL_FRONT ) == GL_FALSE) {
            gl_error( ctx, GL_INVALID_ENUM, "glReadBuffer" );
            return;
         }
         ctx->Pixel.ReadBuffer = mode;
         ctx->Buffer->Alpha = ctx->Buffer->FrontAlpha;
         ctx->NewState |= NEW_RASTER_OPS;
         break;
      case GL_BACK:
      case GL_BACK_LEFT:
         if ( (*ctx->Driver.SetBuffer)( ctx, GL_BACK ) == GL_FALSE) {
            gl_error( ctx, GL_INVALID_ENUM, "glReadBuffer" );
            return;
         }
         ctx->Pixel.ReadBuffer = mode;
         ctx->Buffer->Alpha = ctx->Buffer->BackAlpha;
         ctx->NewState |= NEW_RASTER_OPS;
         break;
      case GL_FRONT_RIGHT:
      case GL_BACK_RIGHT:
      case GL_LEFT:
      case GL_RIGHT:
      case GL_AUX0:
         gl_error( ctx, GL_INVALID_OPERATION, "glReadBuffer" );
         break;
      default:
         gl_error( ctx, GL_INVALID_ENUM, "glReadBuffer" );
   }

   /* Remember, the draw buffer is the default state */
   (void) (*ctx->Driver.SetBuffer)( ctx, ctx->Color.DrawBuffer );
}

