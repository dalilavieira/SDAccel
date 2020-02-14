#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_83__   TYPE_9__ ;
typedef  struct TYPE_82__   TYPE_8__ ;
typedef  struct TYPE_81__   TYPE_7__ ;
typedef  struct TYPE_80__   TYPE_6__ ;
typedef  struct TYPE_79__   TYPE_5__ ;
typedef  struct TYPE_78__   TYPE_4__ ;
typedef  struct TYPE_77__   TYPE_3__ ;
typedef  struct TYPE_76__   TYPE_2__ ;
typedef  struct TYPE_75__   TYPE_1__ ;
typedef  struct TYPE_74__   TYPE_11__ ;
typedef  struct TYPE_73__   TYPE_10__ ;

/* Type definitions */
struct TYPE_83__ {int Height; int Width; int /*<<< orphan*/  FrontAlpha; int /*<<< orphan*/  Alpha; int /*<<< orphan*/  BackAlpha; } ;
struct TYPE_82__ {scalar_t__ SWmasking; scalar_t__ BlendEnabled; scalar_t__ SWLogicOpEnabled; scalar_t__ AlphaEnabled; } ;
struct TYPE_81__ {scalar_t__ Test; } ;
struct TYPE_80__ {scalar_t__ Enabled; } ;
struct TYPE_79__ {scalar_t__ StippleFlag; } ;
struct TYPE_78__ {scalar_t__ Enabled; } ;
struct TYPE_77__ {scalar_t__ Enabled; } ;
struct TYPE_76__ {scalar_t__ Fog; } ;
struct TYPE_75__ {scalar_t__ Enabled; } ;
struct TYPE_73__ {scalar_t__ (* DepthTestSpan ) (TYPE_11__*,size_t,int,int,int /*<<< orphan*/ *,size_t*) ;int /*<<< orphan*/  (* ReadIndexSpan ) (TYPE_11__*,size_t,int,int,size_t*) ;int /*<<< orphan*/  (* ReadColorSpan ) (TYPE_11__*,size_t,int,int,size_t*,size_t*,size_t*,size_t*) ;int /*<<< orphan*/  (* SetBuffer ) (TYPE_11__*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* WriteColorSpan ) (TYPE_11__*,size_t,int,int,size_t*,size_t*,size_t*,size_t*,size_t*) ;int /*<<< orphan*/  (* WriteMonocolorSpan ) (TYPE_11__*,size_t,int,int,size_t*) ;int /*<<< orphan*/  (* WriteMonoindexSpan ) (TYPE_11__*,size_t,int,int,size_t*) ;int /*<<< orphan*/  (* WriteIndexSpan ) (TYPE_11__*,size_t,int,int,size_t*,size_t*) ;} ;
struct TYPE_74__ {size_t* PolygonStipple; int RasterMask; TYPE_10__ Driver; TYPE_9__* Buffer; TYPE_8__ Color; TYPE_7__ Depth; TYPE_6__ Stencil; TYPE_5__ Polygon; TYPE_4__ Scissor; TYPE_3__ Texture; TYPE_2__ Hint; TYPE_1__ Fog; scalar_t__ MutablePixels; } ;
typedef  size_t GLuint ;
typedef  size_t GLubyte ;
typedef  int GLint ;
typedef  int /*<<< orphan*/  GLfloat ;
typedef  scalar_t__ GLenum ;
typedef  int /*<<< orphan*/  GLdepth ;
typedef  TYPE_11__ GLcontext ;
typedef  scalar_t__ GLboolean ;

/* Variables and functions */
 int ALPHABUF_BIT ; 
 int /*<<< orphan*/  ASSERT (scalar_t__) ; 
 int FRONT_AND_BACK_BIT ; 
 int /*<<< orphan*/  GL_BACK ; 
 scalar_t__ GL_BITMAP ; 
 scalar_t__ GL_FALSE ; 
 int /*<<< orphan*/  GL_FRONT ; 
 scalar_t__ GL_NICEST ; 
 scalar_t__ GL_POLYGON ; 
 scalar_t__ GL_TRUE ; 
 int MAX_WIDTH ; 
 int /*<<< orphan*/  MEMCPY (size_t*,size_t*,size_t) ; 
 int /*<<< orphan*/  MEMSET (size_t*,int,size_t) ; 
 size_t MIN2 (size_t,int) ; 
 int NO_DRAW_BIT ; 
 int WINCLIP_BIT ; 
 scalar_t__ gl_alpha_test (TYPE_11__*,size_t,size_t*,size_t*) ; 
 int /*<<< orphan*/  gl_blend_span (TYPE_11__*,size_t,int,int,size_t*,size_t*,size_t*,size_t*,size_t*) ; 
 int /*<<< orphan*/  gl_depth_stencil_span (TYPE_11__*,size_t,int,int,int /*<<< orphan*/ *,size_t*) ; 
 int /*<<< orphan*/  gl_fog_color_pixels (TYPE_11__*,size_t,int /*<<< orphan*/ *,size_t*,size_t*,size_t*,size_t*) ; 
 int /*<<< orphan*/  gl_fog_index_pixels (TYPE_11__*,size_t,int /*<<< orphan*/ *,size_t*) ; 
 int /*<<< orphan*/  gl_logicop_ci_span (TYPE_11__*,size_t,int,int,size_t*,size_t*) ; 
 int /*<<< orphan*/  gl_logicop_rgba_span (TYPE_11__*,size_t,int,int,size_t*,size_t*,size_t*,size_t*,size_t*) ; 
 int /*<<< orphan*/  gl_mask_color_span (TYPE_11__*,size_t,int,int,size_t*,size_t*,size_t*,size_t*) ; 
 int /*<<< orphan*/  gl_mask_index_span (TYPE_11__*,size_t,int,int,size_t*) ; 
 int /*<<< orphan*/  gl_read_alpha_span (TYPE_11__*,size_t,int,int,size_t*) ; 
 scalar_t__ gl_scissor_span (TYPE_11__*,size_t,int,int,size_t*) ; 
 scalar_t__ gl_stencil_span (TYPE_11__*,size_t,int,int,size_t*) ; 
 int /*<<< orphan*/  gl_texture_pixels (TYPE_11__*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,size_t*,size_t*,size_t*,size_t*) ; 
 int /*<<< orphan*/  gl_write_alpha_span (TYPE_11__*,size_t,int,int,size_t*,size_t*) ; 
 int /*<<< orphan*/  gl_write_mono_alpha_span (TYPE_11__*,size_t,int,int,int,size_t*) ; 
 scalar_t__ stub1 (TYPE_11__*,size_t,int,int,int /*<<< orphan*/ *,size_t*) ; 
 int /*<<< orphan*/  stub10 (TYPE_11__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub11 (TYPE_11__*,size_t,int,int,size_t*) ; 
 int /*<<< orphan*/  stub12 (TYPE_11__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub13 (TYPE_11__*,size_t,int,int,size_t*) ; 
 int /*<<< orphan*/  stub14 (TYPE_11__*,int /*<<< orphan*/ ) ; 
 size_t stub15 (TYPE_11__*,size_t,int,int,int /*<<< orphan*/ *,size_t*) ; 
 int /*<<< orphan*/  stub16 (TYPE_11__*,size_t,int,int,size_t*,size_t*,size_t*,size_t*,size_t*) ; 
 int /*<<< orphan*/  stub17 (TYPE_11__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub18 (TYPE_11__*,size_t,int,int,size_t*,size_t*,size_t*,size_t*,size_t*) ; 
 int /*<<< orphan*/  stub19 (TYPE_11__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (TYPE_11__*,size_t,int,int,size_t*,size_t*) ; 
 size_t stub20 (TYPE_11__*,size_t,int,int,int /*<<< orphan*/ *,size_t*) ; 
 int /*<<< orphan*/  stub21 (TYPE_11__*,size_t,int,int,size_t*,size_t*,size_t*,size_t*,size_t*) ; 
 int /*<<< orphan*/  stub22 (TYPE_11__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub23 (TYPE_11__*,size_t,int,int,size_t*,size_t*,size_t*,size_t*,size_t*) ; 
 int /*<<< orphan*/  stub24 (TYPE_11__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub25 (TYPE_11__*,size_t,int,int,size_t*) ; 
 int /*<<< orphan*/  stub26 (TYPE_11__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub27 (TYPE_11__*,size_t,int,int,size_t*) ; 
 int /*<<< orphan*/  stub28 (TYPE_11__*,int /*<<< orphan*/ ) ; 
 size_t stub29 (TYPE_11__*,size_t,int,int,int /*<<< orphan*/ *,size_t*) ; 
 int /*<<< orphan*/  stub3 (TYPE_11__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub30 (TYPE_11__*,size_t,int,int,size_t*,size_t*,size_t*,size_t*,size_t*) ; 
 int /*<<< orphan*/  stub31 (TYPE_11__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub32 (TYPE_11__*,size_t,int,int,size_t*,size_t*,size_t*,size_t*,size_t*) ; 
 int /*<<< orphan*/  stub33 (TYPE_11__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub34 (TYPE_11__*,size_t,int,int,size_t*,size_t*,size_t*,size_t*) ; 
 int /*<<< orphan*/  stub35 (TYPE_11__*,size_t,int,int,size_t*,size_t*,size_t*,size_t*) ; 
 int /*<<< orphan*/  stub36 (TYPE_11__*,size_t,int,int,size_t*) ; 
 int /*<<< orphan*/  stub37 (TYPE_11__*,size_t,int,int,size_t*) ; 
 int /*<<< orphan*/  stub4 (TYPE_11__*,size_t,int,int,size_t*,size_t*) ; 
 int /*<<< orphan*/  stub5 (TYPE_11__*,int /*<<< orphan*/ ) ; 
 scalar_t__ stub6 (TYPE_11__*,size_t,int,int,int /*<<< orphan*/ *,size_t*) ; 
 int /*<<< orphan*/  stub7 (TYPE_11__*,size_t,int,int,size_t*,size_t*) ; 
 int /*<<< orphan*/  stub8 (TYPE_11__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub9 (TYPE_11__*,size_t,int,int,size_t*,size_t*) ; 

__attribute__((used)) static void stipple_polygon_span( GLcontext *ctx,
                                  GLuint n, GLint x, GLint y, GLubyte mask[] )
{
   register GLuint i, m, stipple, highbit=0x80000000;

   stipple = ctx->PolygonStipple[y % 32];
   m = highbit >> (GLuint) (x % 32);

   for (i=0;i<n;i++) {
      if ((m & stipple)==0) {
	 mask[i] = 0;
      }
      m = m >> 1;
      if (m==0) {
	 m = 0x80000000;
      }
   }
}

__attribute__((used)) static GLuint clip_span( GLcontext *ctx,
                         GLint n, GLint x, GLint y, GLubyte mask[] )
{
   GLint i;

   /* Clip to top and bottom */
   if (y<0 || y>=ctx->Buffer->Height) {
      return 0;
   }

   /* Clip to left and right */
   if (x>=0 && x+n<=ctx->Buffer->Width) {
      /* no clipping needed */
      return 1;
   }
   else if (x+n<=0) {
      /* completely off left side */
      return 0;
   }
   else if (x>=ctx->Buffer->Width) {
      /* completely off right side */
      return 0;
   }
   else {
      /* clip-test each pixel, this could be done better */
      for (i=0;i<n;i++) {
         if (x+i<0 || x+i>=ctx->Buffer->Width) {
            mask[i] = 0;
         }
      }
      return 1;
   }
}

void gl_write_index_span( GLcontext *ctx,
                          GLuint n, GLint x, GLint y, GLdepth z[],
			  GLuint index[], GLenum primitive )
{
   GLubyte mask[MAX_WIDTH];
   GLuint index_save[MAX_WIDTH];

   /* init mask to 1's (all pixels are to be written) */
   MEMSET(mask, 1, n);

   if ((ctx->RasterMask & WINCLIP_BIT) || primitive==GL_BITMAP) {
      if (clip_span(ctx,n,x,y,mask)==0) {
	 return;
      }
   }

   /* Per-pixel fog */
   if (ctx->Fog.Enabled
       && (ctx->Hint.Fog==GL_NICEST || primitive==GL_BITMAP)) {
      gl_fog_index_pixels( ctx, n, z, index );
   }

   /* Do the scissor test */
   if (ctx->Scissor.Enabled) {
      if (gl_scissor_span( ctx, n, x, y, mask )==0) {
	 return;
      }
   }

   /* Polygon Stippling */
   if (ctx->Polygon.StippleFlag && primitive==GL_POLYGON) {
      stipple_polygon_span( ctx, n, x, y, mask );
   }

   if (ctx->Stencil.Enabled) {
      /* first stencil test */
      if (gl_stencil_span( ctx, n, x, y, mask )==0) {
	 return;
      }
      /* depth buffering w/ stencil */
      gl_depth_stencil_span( ctx, n, x, y, z, mask );
   }
   else if (ctx->Depth.Test) {
      /* regular depth testing */
      if ((*ctx->Driver.DepthTestSpan)( ctx, n, x, y, z, mask )==0)  return;
   }

   if (ctx->RasterMask & NO_DRAW_BIT) {
      /* write no pixels */
      return;
   }

   if (ctx->RasterMask & FRONT_AND_BACK_BIT) {
      /* Save a copy of the indexes since LogicOp and IndexMask
       * may change them
       */
      MEMCPY( index_save, index, n * sizeof(GLuint) );
   }

   if (ctx->Color.SWLogicOpEnabled) {
      gl_logicop_ci_span( ctx, n, x, y, index, mask );
   }
   if (ctx->Color.SWmasking) {
      gl_mask_index_span( ctx, n, x, y, index );
   }

   /* write pixels */
   (*ctx->Driver.WriteIndexSpan)( ctx, n, x, y, index, mask );


   if (ctx->RasterMask & FRONT_AND_BACK_BIT) {
      /*** Also draw to back buffer ***/
      (*ctx->Driver.SetBuffer)( ctx, GL_BACK );
      MEMCPY( index, index_save, n * sizeof(GLuint) );
      if (ctx->Color.SWLogicOpEnabled) {
         gl_logicop_ci_span( ctx, n, x, y, index, mask );
      }
      if (ctx->Color.SWmasking) {
         gl_mask_index_span( ctx, n, x, y, index );
      }
      (*ctx->Driver.WriteIndexSpan)( ctx, n, x, y, index, mask );
      (*ctx->Driver.SetBuffer)( ctx, GL_FRONT );
   }
}

void gl_write_monoindex_span( GLcontext *ctx,
                              GLuint n, GLint x, GLint y, GLdepth z[],
			      GLuint index, GLenum primitive )
{
    GLuint i;
    GLubyte mask[MAX_WIDTH];
    GLuint index_save[MAX_WIDTH];

    /* init mask to 1's (all pixels are to be written) */
    MEMSET(mask, 1, n);

    if ((ctx->RasterMask & WINCLIP_BIT) || primitive==GL_BITMAP)
    {
        if (clip_span( ctx,n,x,y,mask)==0) {
            return;
        }
    }

    /* Do the scissor test */
    if (ctx->Scissor.Enabled)
    {
        if (gl_scissor_span( ctx, n, x, y, mask )==0) {
            return;
        }
    }

    /* Polygon Stippling */
    if (ctx->Polygon.StippleFlag && primitive==GL_POLYGON)
    {
        stipple_polygon_span( ctx, n, x, y, mask );
    }

    if (ctx->Stencil.Enabled)
    {
        /* first stencil test */
        if (gl_stencil_span( ctx, n, x, y, mask )==0)
        {
            return;
        }
        /* depth buffering w/ stencil */
        gl_depth_stencil_span( ctx, n, x, y, z, mask );
    }
    else if (ctx->Depth.Test)
    {
        /* regular depth testing */
        if ((*ctx->Driver.DepthTestSpan)( ctx, n, x, y, z, mask )==0)
            return;
    }

    if (ctx->RasterMask & NO_DRAW_BIT)
    {
        /* write no pixels */
        return;
   }

    if ((ctx->Fog.Enabled && (ctx->Hint.Fog==GL_NICEST || primitive==GL_BITMAP))
            || ctx->Color.SWLogicOpEnabled || ctx->Color.SWmasking)
    {
        GLuint ispan[MAX_WIDTH];
        /* index may change, replicate single index into an array */
        for (i=0;i<n;i++)
        {
            ispan[i] = index;
        }

        if (ctx->Fog.Enabled
                && (ctx->Hint.Fog==GL_NICEST || primitive==GL_BITMAP))
        {
            gl_fog_index_pixels( ctx, n, z, ispan );
        }

        if (ctx->RasterMask & FRONT_AND_BACK_BIT)
        {
            MEMCPY( index_save, ispan, n * sizeof(GLuint) );
        }

        if (ctx->Color.SWLogicOpEnabled)
        {
            gl_logicop_ci_span( ctx, n, x, y, ispan, mask );
        }

        if (ctx->Color.SWmasking)
        {
            gl_mask_index_span( ctx, n, x, y, ispan );
        }

        (*ctx->Driver.WriteIndexSpan)( ctx, n, x, y, ispan, mask );

        if (ctx->RasterMask & FRONT_AND_BACK_BIT)
        {
             /*** Also draw to back buffer ***/
             (*ctx->Driver.SetBuffer)( ctx, GL_BACK );
             for (i=0;i<n;i++)
             {
                ispan[i] = index;
             }

             if (ctx->Color.SWLogicOpEnabled) {
                 gl_logicop_ci_span( ctx, n, x, y, ispan, mask );
             }
             if (ctx->Color.SWmasking) {
                 gl_mask_index_span( ctx, n, x, y, ispan );
             }
             (*ctx->Driver.WriteIndexSpan)( ctx, n, x, y, ispan, mask );
             (*ctx->Driver.SetBuffer)( ctx, GL_FRONT );
        }
    }
    else
    {
        (*ctx->Driver.WriteMonoindexSpan)( ctx, n, x, y, mask );

        if (ctx->RasterMask & FRONT_AND_BACK_BIT)
        {
            /*** Also draw to back buffer ***/
            (*ctx->Driver.SetBuffer)( ctx, GL_BACK );
            (*ctx->Driver.WriteMonoindexSpan)( ctx, n, x, y, mask );
            (*ctx->Driver.SetBuffer)( ctx, GL_FRONT );
        }
    }
}

void gl_write_color_span( GLcontext *ctx,
                          GLuint n, GLint x, GLint y, GLdepth z[],
			  GLubyte r[], GLubyte g[],
			  GLubyte b[], GLubyte a[],
			  GLenum primitive )
{
   GLubyte mask[MAX_WIDTH];
   GLboolean write_all = GL_TRUE;
   GLubyte rtmp[MAX_WIDTH], gtmp[MAX_WIDTH], btmp[MAX_WIDTH], atmp[MAX_WIDTH];
   GLubyte *red, *green, *blue, *alpha;

   /* init mask to 1's (all pixels are to be written) */
   MEMSET(mask, 1, n);

   if ((ctx->RasterMask & WINCLIP_BIT) || primitive==GL_BITMAP) {
      if (clip_span( ctx,n,x,y,mask)==0) {
	 return;
      }
      write_all = GL_FALSE;
   }

   if ((primitive==GL_BITMAP && ctx->MutablePixels)
       || (ctx->RasterMask & FRONT_AND_BACK_BIT)) {
      /* must make a copy of the colors since they may be modified */
      MEMCPY( rtmp, r, n * sizeof(GLubyte) );
      MEMCPY( gtmp, g, n * sizeof(GLubyte) );
      MEMCPY( btmp, b, n * sizeof(GLubyte) );
      MEMCPY( atmp, a, n * sizeof(GLubyte) );
      red = rtmp;
      green = gtmp;
      blue = btmp;
      alpha = atmp;
   }
   else {
      red   = r;
      green = g;
      blue  = b;
      alpha = a;
   }

   /* Per-pixel fog */
   if (ctx->Fog.Enabled && (ctx->Hint.Fog==GL_NICEST || primitive==GL_BITMAP
                            || ctx->Texture.Enabled)) {
      gl_fog_color_pixels( ctx, n, z, red, green, blue, alpha );
   }

   /* Do the scissor test */
   if (ctx->Scissor.Enabled) {
      if (gl_scissor_span( ctx, n, x, y, mask )==0) {
	 return;
      }
      write_all = GL_FALSE;
   }

   /* Polygon Stippling */
   if (ctx->Polygon.StippleFlag && primitive==GL_POLYGON) {
      stipple_polygon_span( ctx, n, x, y, mask );
      write_all = GL_FALSE;
   }

   /* Do the alpha test */
   if (ctx->Color.AlphaEnabled) {
      if (gl_alpha_test( ctx, n, alpha, mask )==0) {
	 return;
      }
      write_all = GL_FALSE;
   }

   if (ctx->Stencil.Enabled) {
      /* first stencil test */
      if (gl_stencil_span( ctx, n, x, y, mask )==0) {
	 return;
      }
      /* depth buffering w/ stencil */
      gl_depth_stencil_span( ctx, n, x, y, z, mask );
      write_all = GL_FALSE;
   }
   else if (ctx->Depth.Test) {
      /* regular depth testing */
      GLuint m = (*ctx->Driver.DepthTestSpan)( ctx, n, x, y, z, mask );
      if (m==0) {
         return;
      }
      if (m<n) {
         write_all = GL_FALSE;
      }
   }

   if (ctx->RasterMask & NO_DRAW_BIT) {
      /* write no pixels */
      return;
   }

   /* logic op or blending */
   if (ctx->Color.SWLogicOpEnabled) {
      gl_logicop_rgba_span( ctx, n, x, y, red, green, blue, alpha, mask );
   }
   else if (ctx->Color.BlendEnabled) {
      gl_blend_span( ctx, n, x, y, red, green, blue, alpha, mask );
   }

   /* Color component masking */
   if (ctx->Color.SWmasking) {
      gl_mask_color_span( ctx, n, x, y, red, green, blue, alpha );
   }

   /* write pixels */
   (*ctx->Driver.WriteColorSpan)( ctx, n, x, y, red, green, blue, alpha,
                                  write_all ? NULL : mask );
   if (ctx->RasterMask & ALPHABUF_BIT) {
      gl_write_alpha_span( ctx, n, x, y, alpha, write_all ? NULL : mask );
   }

   if (ctx->RasterMask & FRONT_AND_BACK_BIT) {
      /*** Also render to back buffer ***/
      MEMCPY( rtmp, r, n * sizeof(GLubyte) );
      MEMCPY( gtmp, g, n * sizeof(GLubyte) );
      MEMCPY( btmp, b, n * sizeof(GLubyte) );
      MEMCPY( atmp, a, n * sizeof(GLubyte) );
      (*ctx->Driver.SetBuffer)( ctx, GL_BACK );
      if (ctx->Color.SWLogicOpEnabled) {
         gl_logicop_rgba_span( ctx, n, x, y, red, green, blue, alpha, mask );
      }
      else  if (ctx->Color.BlendEnabled) {
         gl_blend_span( ctx, n, x, y, red, green, blue, alpha, mask );
      }
      if (ctx->Color.SWmasking) {
         gl_mask_color_span( ctx, n, x, y, red, green, blue, alpha );
      }
      (*ctx->Driver.WriteColorSpan)( ctx, n, x, y, red, green, blue, alpha,
                              write_all ? NULL : mask );
      if (ctx->RasterMask & ALPHABUF_BIT) {
         ctx->Buffer->Alpha = ctx->Buffer->BackAlpha;
         gl_write_alpha_span( ctx, n, x, y, alpha, write_all ? NULL : mask );
         ctx->Buffer->Alpha = ctx->Buffer->FrontAlpha;
      }
      (*ctx->Driver.SetBuffer)( ctx, GL_FRONT );
   }

}

void gl_write_monocolor_span( GLcontext *ctx,
                              GLuint n, GLint x, GLint y, GLdepth z[],
			      GLint r, GLint g, GLint b, GLint a,
                              GLenum primitive )
{
   GLuint i;
   GLubyte mask[MAX_WIDTH];
   GLboolean write_all = GL_TRUE;
   GLubyte red[MAX_WIDTH], green[MAX_WIDTH], blue[MAX_WIDTH], alpha[MAX_WIDTH];

   /* init mask to 1's (all pixels are to be written) */
   MEMSET(mask, 1, n);

   if ((ctx->RasterMask & WINCLIP_BIT) || primitive==GL_BITMAP) {
      if (clip_span( ctx,n,x,y,mask)==0) {
	 return;
      }
      write_all = GL_FALSE;
   }

   /* Do the scissor test */
   if (ctx->Scissor.Enabled) {
      if (gl_scissor_span( ctx, n, x, y, mask )==0) {
	 return;
      }
      write_all = GL_FALSE;
   }

   /* Polygon Stippling */
   if (ctx->Polygon.StippleFlag && primitive==GL_POLYGON) {
      stipple_polygon_span( ctx, n, x, y, mask );
      write_all = GL_FALSE;
   }

   /* Do the alpha test */
   if (ctx->Color.AlphaEnabled) {
      GLubyte alpha[MAX_WIDTH];
      for (i=0;i<n;i++) {
         alpha[i] = a;
      }
      if (gl_alpha_test( ctx, n, alpha, mask )==0) {
	 return;
      }
      write_all = GL_FALSE;
   }

   if (ctx->Stencil.Enabled) {
      /* first stencil test */
      if (gl_stencil_span( ctx, n, x, y, mask )==0) {
	 return;
      }
      /* depth buffering w/ stencil */
      gl_depth_stencil_span( ctx, n, x, y, z, mask );
      write_all = GL_FALSE;
   }
   else if (ctx->Depth.Test) {
      /* regular depth testing */
      GLuint m = (*ctx->Driver.DepthTestSpan)( ctx, n, x, y, z, mask );
      if (m==0) {
         return;
      }
      if (m<n) {
         write_all = GL_FALSE;
      }
   }

   if (ctx->RasterMask & NO_DRAW_BIT) {
      /* write no pixels */
      return;
   }

   if (ctx->Color.BlendEnabled || ctx->Color.SWLogicOpEnabled
       || ctx->Color.SWmasking) {
      /* assign same color to each pixel */
      for (i=0;i<n;i++) {
	 if (mask[i]) {
	    red[i]   = r;
	    green[i] = g;
	    blue[i]  = b;
	    alpha[i] = a;
	 }
      }

      if (ctx->Color.SWLogicOpEnabled) {
         gl_logicop_rgba_span( ctx, n, x, y, red, green, blue, alpha, mask );
      }
      else if (ctx->Color.BlendEnabled) {
         gl_blend_span( ctx, n, x, y, red, green, blue, alpha, mask );
      }

      /* Color component masking */
      if (ctx->Color.SWmasking) {
         gl_mask_color_span( ctx, n, x, y, red, green, blue, alpha );
      }

      /* write pixels */
      (*ctx->Driver.WriteColorSpan)( ctx, n, x, y, red, green, blue, alpha,
                                     write_all ? NULL : mask );
      if (ctx->RasterMask & ALPHABUF_BIT) {
         gl_write_alpha_span( ctx, n, x, y, alpha, write_all ? NULL : mask );
      }

      if (ctx->RasterMask & FRONT_AND_BACK_BIT) {
         /*** Also draw to back buffer ***/
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = r;
               green[i] = g;
               blue[i]  = b;
               alpha[i] = a;
            }
         }
         (*ctx->Driver.SetBuffer)( ctx, GL_BACK );
         if (ctx->Color.SWLogicOpEnabled) {
            gl_logicop_rgba_span( ctx, n, x, y, red, green, blue, alpha, mask);
         }
         else if (ctx->Color.BlendEnabled) {
            gl_blend_span( ctx, n, x, y, red, green, blue, alpha, mask );
         }
         if (ctx->Color.SWmasking) {
            gl_mask_color_span( ctx, n, x, y, red, green, blue, alpha );
         }
         (*ctx->Driver.WriteColorSpan)( ctx, n, x, y, red, green, blue, alpha,
                                        write_all ? NULL : mask );
         (*ctx->Driver.SetBuffer)( ctx, GL_FRONT );
         if (ctx->RasterMask & ALPHABUF_BIT) {
            ctx->Buffer->Alpha = ctx->Buffer->BackAlpha;
            gl_write_alpha_span( ctx, n, x, y, alpha,
                                 write_all ? NULL : mask );
            ctx->Buffer->Alpha = ctx->Buffer->FrontAlpha;
         }
      }
   }
   else {
      (*ctx->Driver.WriteMonocolorSpan)( ctx, n, x, y, mask );
      if (ctx->RasterMask & ALPHABUF_BIT) {
         gl_write_mono_alpha_span( ctx, n, x, y, a, write_all ? NULL : mask );
      }
      if (ctx->RasterMask & FRONT_AND_BACK_BIT) {
         /* Also draw to back buffer */
         (*ctx->Driver.SetBuffer)( ctx, GL_BACK );
         (*ctx->Driver.WriteMonocolorSpan)( ctx, n, x, y, mask );
         (*ctx->Driver.SetBuffer)( ctx, GL_FRONT );
         if (ctx->RasterMask & ALPHABUF_BIT) {
            ctx->Buffer->Alpha = ctx->Buffer->BackAlpha;
            gl_write_mono_alpha_span( ctx, n, x, y, a,
                                      write_all ? NULL : mask );
            ctx->Buffer->Alpha = ctx->Buffer->FrontAlpha;
         }
      }
   }
}

void gl_write_texture_span( GLcontext *ctx,
                            GLuint n, GLint x, GLint y, GLdepth z[],
			    GLfloat s[], GLfloat t[], GLfloat u[],
                            GLfloat lambda[],
			    GLubyte r[], GLubyte g[],
			    GLubyte b[], GLubyte a[],
			    GLenum primitive )
{
   GLubyte mask[MAX_WIDTH];
   GLboolean write_all = GL_TRUE;
   GLubyte rtmp[MAX_WIDTH], gtmp[MAX_WIDTH], btmp[MAX_WIDTH], atmp[MAX_WIDTH];
   GLubyte *red, *green, *blue, *alpha;

   /* init mask to 1's (all pixels are to be written) */
   MEMSET(mask, 1, n);

   if ((ctx->RasterMask & WINCLIP_BIT) || primitive==GL_BITMAP) {
      if (clip_span( ctx,n,x,y,mask)==0) {
	 return;
      }
      write_all = GL_FALSE;
   }


   if (primitive==GL_BITMAP || (ctx->RasterMask & FRONT_AND_BACK_BIT)) {
      /* must make a copy of the colors since they may be modified */
      MEMCPY( rtmp, r, n * sizeof(GLubyte) );
      MEMCPY( gtmp, g, n * sizeof(GLubyte) );
      MEMCPY( btmp, b, n * sizeof(GLubyte) );
      MEMCPY( atmp, a, n * sizeof(GLubyte) );
      red = rtmp;
      green = gtmp;
      blue = btmp;
      alpha = atmp;
   }
   else {
      red   = r;
      green = g;
      blue  = b;
      alpha = a;
   }

   /* Texture */
   ASSERT(ctx->Texture.Enabled);
   gl_texture_pixels( ctx, n, s, t, u, lambda, red, green, blue, alpha );

   /* Per-pixel fog */
   if (ctx->Fog.Enabled && (ctx->Hint.Fog==GL_NICEST || primitive==GL_BITMAP
                            || ctx->Texture.Enabled)) {
      gl_fog_color_pixels( ctx, n, z, red, green, blue, alpha );
   }

   /* Do the scissor test */
   if (ctx->Scissor.Enabled) {
      if (gl_scissor_span( ctx, n, x, y, mask )==0) {
	 return;
      }
      write_all = GL_FALSE;
   }

   /* Polygon Stippling */
   if (ctx->Polygon.StippleFlag && primitive==GL_POLYGON) {
      stipple_polygon_span( ctx, n, x, y, mask );
      write_all = GL_FALSE;
   }

   /* Do the alpha test */
   if (ctx->Color.AlphaEnabled) {
      if (gl_alpha_test( ctx, n, alpha, mask )==0) {
	 return;
      }
      write_all = GL_FALSE;
   }

   if (ctx->Stencil.Enabled) {
      /* first stencil test */
      if (gl_stencil_span( ctx, n, x, y, mask )==0) {
	 return;
      }
      /* depth buffering w/ stencil */
      gl_depth_stencil_span( ctx, n, x, y, z, mask );
      write_all = GL_FALSE;
   }
   else if (ctx->Depth.Test) {
      /* regular depth testing */
      GLuint m = (*ctx->Driver.DepthTestSpan)( ctx, n, x, y, z, mask );
      if (m==0) {
         return;
      }
      if (m<n) {
         write_all = GL_FALSE;
      }
   }

   if (ctx->RasterMask & NO_DRAW_BIT) {
      /* write no pixels */
      return;
   }

   /* blending */
   if (ctx->Color.SWLogicOpEnabled) {
      gl_logicop_rgba_span( ctx, n, x, y, red, green, blue, alpha, mask );
   }
   else  if (ctx->Color.BlendEnabled) {
      gl_blend_span( ctx, n, x, y, red, green, blue, alpha, mask );
   }

   if (ctx->Color.SWmasking) {
      gl_mask_color_span( ctx, n, x, y, red, green, blue, alpha );
   }

   /* write pixels */
   (*ctx->Driver.WriteColorSpan)( ctx, n, x, y, red, green, blue, alpha,
                                  write_all ? NULL : mask );
   if (ctx->RasterMask & ALPHABUF_BIT) {
      gl_write_alpha_span( ctx, n, x, y, alpha, write_all ? NULL : mask );
   }

   if (ctx->RasterMask & FRONT_AND_BACK_BIT) {
      /* Also draw to back buffer */
      MEMCPY( rtmp, r, n * sizeof(GLubyte) );
      MEMCPY( gtmp, g, n * sizeof(GLubyte) );
      MEMCPY( btmp, b, n * sizeof(GLubyte) );
      MEMCPY( atmp, a, n * sizeof(GLubyte) );
      (*ctx->Driver.SetBuffer)( ctx, GL_BACK );
      if (ctx->Color.SWLogicOpEnabled) {
         gl_logicop_rgba_span( ctx, n, x, y, red, green, blue, alpha, mask );
      }
      else if (ctx->Color.BlendEnabled) {
         gl_blend_span( ctx, n, x, y, red, green, blue, alpha, mask );
      }
      if (ctx->Color.SWmasking) {
         gl_mask_color_span( ctx, n, x, y, red, green, blue, alpha );
      }
      (*ctx->Driver.WriteColorSpan)( ctx, n, x, y, red, green, blue, alpha,
                                     write_all ? NULL : mask );
      (*ctx->Driver.SetBuffer)( ctx, GL_FRONT );
      if (ctx->RasterMask & ALPHABUF_BIT) {
         ctx->Buffer->Alpha = ctx->Buffer->BackAlpha;
         gl_write_alpha_span( ctx, n, x, y, alpha, write_all ? NULL : mask );
         ctx->Buffer->Alpha = ctx->Buffer->FrontAlpha;
      }
   }
}

void gl_read_color_span( GLcontext *ctx,
                         GLuint n, GLint x, GLint y,
			 GLubyte red[], GLubyte green[],
			 GLubyte blue[], GLubyte alpha[] )
{
   register GLuint i;

   if (y<0 || y>=ctx->Buffer->Height || x>=ctx->Buffer->Width) {
      /* completely above, below, or right */
      for (i=0;i<n;i++) {
	 red[i] = green[i] = blue[i] = alpha[i] = 0;
      }
   }
   else {
      if (x>=0 && x+n<=ctx->Buffer->Width) {
	 /* OK */
	 (*ctx->Driver.ReadColorSpan)( ctx, n, x, y, red, green, blue, alpha );
         if (ctx->RasterMask & ALPHABUF_BIT) {
            gl_read_alpha_span( ctx, n, x, y, alpha );
         }
      }
      else {
	 i = 0;
	 if (x<0) {
	    while (x<0 && n>0) {
	       red[i] = green[i] =  blue[i] = alpha[i] = 0;
	       x++;
	       n--;
	       i++;
	    }
	 }
	 n = MIN2( n, ctx->Buffer->Width - x );
	 (*ctx->Driver.ReadColorSpan)( ctx, n, x, y, red+i, green+i, blue+i, alpha+i);
         if (ctx->RasterMask & ALPHABUF_BIT) {
            gl_read_alpha_span( ctx, n, x, y, alpha+i );
         }
      }
   }
}

void gl_read_index_span( GLcontext *ctx,
                         GLuint n, GLint x, GLint y, GLuint indx[] )
{
   register GLuint i;

   if (y<0 || y>=ctx->Buffer->Height || x>=ctx->Buffer->Width) {
      /* completely above, below, or right */
      for (i=0;i<n;i++) {
	 indx[i] = 0;
      }
   }
   else {
      if (x>=0 && x+n<=ctx->Buffer->Width) {
	 /* OK */
	 (*ctx->Driver.ReadIndexSpan)( ctx, n, x, y, indx );
      }
      else {
	 i = 0;
	 if (x<0) {
	    while (x<0 && n>0) {
	       indx[i] = 0;
	       x++;
	       n--;
	       i++;
	    }
	 }
	 n = MIN2( n, ctx->Buffer->Width - x );
	 (*ctx->Driver.ReadIndexSpan)( ctx, n, x, y, indx+i );
      }
   }
}

