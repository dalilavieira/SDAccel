#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
struct TYPE_18__ {int Height; int Width; scalar_t__ Enabled; } ;
struct TYPE_15__ {scalar_t__ DrawBuffer; int* ClearColor; } ;
struct TYPE_19__ {TYPE_3__* Buffer; TYPE_4__ Scissor; TYPE_2__* Visual; TYPE_1__ Color; } ;
struct TYPE_17__ {int Width; int Height; void** FrontAlpha; void** BackAlpha; void** Alpha; int const Xmin; int Ymin; } ;
struct TYPE_16__ {int AlphaScale; scalar_t__ BackAlphaEnabled; scalar_t__ FrontAlphaEnabled; } ;
typedef  size_t GLuint ;
typedef  void* GLubyte ;
typedef  int GLint ;
typedef  TYPE_5__ GLcontext ;

/* Variables and functions */
 void** ALPHA_ADDR (int const,int const) ; 
 scalar_t__ GL_BACK ; 
 scalar_t__ GL_FRONT ; 
 scalar_t__ GL_FRONT_AND_BACK ; 
 int /*<<< orphan*/  GL_OUT_OF_MEMORY ; 
 int /*<<< orphan*/  MEMSET (void**,void*,int) ; 
 int /*<<< orphan*/  free (void**) ; 
 int /*<<< orphan*/  gl_error (TYPE_5__*,int /*<<< orphan*/ ,char*) ; 
 scalar_t__ malloc (int) ; 

void gl_alloc_alpha_buffers( GLcontext* ctx )
{
   GLint bytes = ctx->Buffer->Width * ctx->Buffer->Height * sizeof(GLubyte);

   if (ctx->Visual->FrontAlphaEnabled) {
      if (ctx->Buffer->FrontAlpha) {
         free( ctx->Buffer->FrontAlpha );
      }
      ctx->Buffer->FrontAlpha = (GLubyte *) malloc( bytes );
      if (!ctx->Buffer->FrontAlpha) {
         /* out of memory */
         gl_error( ctx, GL_OUT_OF_MEMORY, "Couldn't allocate front alpha buffer" );
      }
   }
   if (ctx->Visual->BackAlphaEnabled) {
      if (ctx->Buffer->BackAlpha) {
         free( ctx->Buffer->BackAlpha );
      }
      ctx->Buffer->BackAlpha = (GLubyte *) malloc( bytes );
      if (!ctx->Buffer->BackAlpha) {
         /* out of memory */
         gl_error( ctx, GL_OUT_OF_MEMORY, "Couldn't allocate back alpha buffer" );
      }
   }
   if (ctx->Color.DrawBuffer==GL_FRONT) {
      ctx->Buffer->Alpha = ctx->Buffer->FrontAlpha;
   }
   if (ctx->Color.DrawBuffer==GL_BACK) {
      ctx->Buffer->Alpha = ctx->Buffer->BackAlpha;
   }
}

void gl_clear_alpha_buffers( GLcontext* ctx )
{
   GLint buffer;

   /* Loop over front and back buffers */
   for (buffer=0;buffer<2;buffer++) {

      /* Get pointer to front or back buffer */
      GLubyte *abuffer = NULL;
      if (buffer==0
          && (   ctx->Color.DrawBuffer==GL_FRONT
              || ctx->Color.DrawBuffer==GL_FRONT_AND_BACK)
          && ctx->Visual->FrontAlphaEnabled && ctx->Buffer->FrontAlpha) {
         abuffer = ctx->Buffer->FrontAlpha;
      }
      else if (buffer==1
               && (   ctx->Color.DrawBuffer==GL_BACK
                   || ctx->Color.DrawBuffer==GL_FRONT_AND_BACK)
               && ctx->Visual->BackAlphaEnabled && ctx->Buffer->BackAlpha) {
         abuffer = ctx->Buffer->BackAlpha;
      }

      /* Clear the alpha buffer */
      if (abuffer) {
         GLubyte aclear = (GLint) (ctx->Color.ClearColor[3]
                                   * ctx->Visual->AlphaScale);
         if (ctx->Scissor.Enabled) {
            /* clear scissor region */
            GLint i, j;
            for (j=0;j<ctx->Scissor.Height;j++) {
               GLubyte *aptr = ALPHA_ADDR(ctx->Buffer->Xmin,
                                          ctx->Buffer->Ymin+j);
               for (i=0;i<ctx->Scissor.Width;i++) {
                  *aptr++ = aclear;
               }
            }
         }
         else {
            /* clear whole buffer */
            MEMSET( abuffer, aclear, ctx->Buffer->Width*ctx->Buffer->Height );
         }
      }
   }
}

void gl_write_alpha_span( GLcontext* ctx, GLuint n, GLint x, GLint y,
                          GLubyte alpha[], GLubyte mask[] )
{
   GLubyte *aptr = ALPHA_ADDR( x, y );
   GLuint i;

   if (mask) {
      for (i=0;i<n;i++) {
         if (mask[i]) {
            *aptr = alpha[i];
         }
         aptr++;
      }
   }
   else {
      for (i=0;i<n;i++) {
         *aptr++ = alpha[i];
      }
   }
}

void gl_write_mono_alpha_span( GLcontext* ctx, GLuint n, GLint x, GLint y,
                               GLubyte alpha, GLubyte mask[] )
{
   GLubyte *aptr = ALPHA_ADDR( x, y );
   GLuint i;

   if (mask) {
      for (i=0;i<n;i++) {
         if (mask[i]) {
            *aptr = alpha;
         }
         aptr++;
      }
   }
   else {
      for (i=0;i<n;i++) {
         *aptr++ = alpha;
      }
   }
}

void gl_write_alpha_pixels( GLcontext* ctx,
                            GLuint n, const GLint x[], const GLint y[],
                            const GLubyte alpha[], const GLubyte mask[] )
{
   GLuint i;

   if (mask) {
      for (i=0;i<n;i++) {
         if (mask[i]) {
            GLubyte *aptr = ALPHA_ADDR( x[i], y[i] );
            *aptr = alpha[i];
         }
      }
   }
   else {
      for (i=0;i<n;i++) {
         GLubyte *aptr = ALPHA_ADDR( x[i], y[i] );
         *aptr = alpha[i];
      }
   }
}

void gl_write_mono_alpha_pixels( GLcontext* ctx,
                                 GLuint n, const GLint x[], const GLint y[],
                                 GLubyte alpha, const GLubyte mask[] )
{
   GLuint i;

   if (mask) {
      for (i=0;i<n;i++) {
         if (mask[i]) {
            GLubyte *aptr = ALPHA_ADDR( x[i], y[i] );
            *aptr = alpha;
         }
      }
   }
   else {
      for (i=0;i<n;i++) {
         GLubyte *aptr = ALPHA_ADDR( x[i], y[i] );
         *aptr = alpha;
      }
   }
}

void gl_read_alpha_span( GLcontext* ctx,
                         GLuint n, GLint x, GLint y, GLubyte alpha[] )
{
   GLubyte *aptr = ALPHA_ADDR( x, y );
   GLuint i;
   for (i=0;i<n;i++) {
      alpha[i] = *aptr++;
   }
}

void gl_read_alpha_pixels( GLcontext* ctx,
                           GLuint n, const GLint x[], const GLint y[],
                           GLubyte alpha[], const GLubyte mask[] )
{
   GLuint i;
   for (i=0;i<n;i++) {
      if (mask[i]) {
         GLubyte *aptr = ALPHA_ADDR( x[i], y[i] );
         alpha[i] = *aptr;
      }
   }
}

