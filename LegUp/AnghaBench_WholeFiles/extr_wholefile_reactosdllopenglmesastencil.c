#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_33__   TYPE_7__ ;
typedef  struct TYPE_32__   TYPE_6__ ;
typedef  struct TYPE_31__   TYPE_5__ ;
typedef  struct TYPE_30__   TYPE_4__ ;
typedef  struct TYPE_29__   TYPE_3__ ;
typedef  struct TYPE_28__   TYPE_2__ ;
typedef  struct TYPE_27__   TYPE_1__ ;

/* Type definitions */
struct TYPE_31__ {int Clear; int Function; int Ref; size_t ValueMask; int WriteMask; int FailFunc; int ZFailFunc; int ZPassFunc; scalar_t__ Enabled; } ;
struct TYPE_30__ {scalar_t__ Enabled; } ;
struct TYPE_28__ {int /*<<< orphan*/  (* DepthTestPixels ) (TYPE_7__*,size_t,size_t const*,size_t const*,int /*<<< orphan*/  const*,int*) ;int /*<<< orphan*/  (* DepthTestSpan ) (TYPE_7__*,size_t,size_t,size_t,int /*<<< orphan*/  const*,int*) ;} ;
struct TYPE_27__ {scalar_t__ Test; } ;
struct TYPE_33__ {TYPE_6__* Buffer; TYPE_5__ Stencil; TYPE_4__ Scissor; TYPE_3__* Visual; TYPE_2__ Driver; TYPE_1__ Depth; } ;
struct TYPE_32__ {int* Stencil; size_t Width; size_t Height; size_t Xmax; size_t Xmin; size_t Ymin; size_t Ymax; } ;
struct TYPE_29__ {scalar_t__ StencilBits; } ;
typedef  size_t GLuint ;
typedef  int GLubyte ;
typedef  int GLstencil ;
typedef  size_t GLint ;
typedef  int GLenum ;
typedef  int /*<<< orphan*/  GLdepth ;
typedef  TYPE_7__ GLcontext ;

/* Variables and functions */
 int CLAMP (size_t,int /*<<< orphan*/ ,size_t) ; 
#define  GL_ALWAYS 141 
#define  GL_DECR 140 
#define  GL_EQUAL 139 
 scalar_t__ GL_FALSE ; 
#define  GL_GEQUAL 138 
#define  GL_GREATER 137 
#define  GL_INCR 136 
 int /*<<< orphan*/  GL_INVALID_ENUM ; 
 int /*<<< orphan*/  GL_INVALID_OPERATION ; 
#define  GL_INVERT 135 
#define  GL_KEEP 134 
#define  GL_LEQUAL 133 
#define  GL_LESS 132 
#define  GL_NEVER 131 
#define  GL_NOTEQUAL 130 
 int /*<<< orphan*/  GL_OUT_OF_MEMORY ; 
#define  GL_REPLACE 129 
#define  GL_ZERO 128 
 scalar_t__ INSIDE_BEGIN_END (TYPE_7__*) ; 
 int MAX_WIDTH ; 
 int /*<<< orphan*/  MEMCPY (int*,int const*,size_t) ; 
 int /*<<< orphan*/  MEMSET (int*,int,int) ; 
 int PB_SIZE ; 
 int* STENCIL_ADDRESS (size_t const,size_t const) ; 
 int STENCIL_BITS ; 
 int /*<<< orphan*/  free (int*) ; 
 int /*<<< orphan*/  gl_error (TYPE_7__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gl_problem (TYPE_7__*,char*) ; 
 scalar_t__ malloc (size_t) ; 
 int /*<<< orphan*/  stub1 (TYPE_7__*,size_t,size_t,size_t,int /*<<< orphan*/  const*,int*) ; 
 int /*<<< orphan*/  stub2 (TYPE_7__*,size_t,size_t const*,size_t const*,int /*<<< orphan*/  const*,int*) ; 

void gl_ClearStencil( GLcontext *ctx, GLint s )
{
   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glClearStencil" );
      return;
   }
   ctx->Stencil.Clear = (GLstencil) s;
}

void gl_StencilFunc( GLcontext *ctx, GLenum func, GLint ref, GLuint mask )
{
   GLint maxref;

   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glStencilFunc" );
      return;
   }

   switch (func) {
      case GL_NEVER:
      case GL_LESS:
      case GL_LEQUAL:
      case GL_GREATER:
      case GL_GEQUAL:
      case GL_EQUAL:
      case GL_NOTEQUAL:
      case GL_ALWAYS:
         ctx->Stencil.Function = func;
         break;
      default:
         gl_error( ctx, GL_INVALID_ENUM, "glStencilFunc" );
         return;
   }

   maxref = (1 << STENCIL_BITS) - 1;
   ctx->Stencil.Ref = CLAMP( ref, 0, maxref );
   ctx->Stencil.ValueMask = mask;
}

void gl_StencilMask( GLcontext *ctx, GLuint mask )
{
   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glStencilMask" );
      return;
   }
   ctx->Stencil.WriteMask = (GLstencil) mask;
}

void gl_StencilOp( GLcontext *ctx, GLenum fail, GLenum zfail, GLenum zpass )
{
   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glStencilOp" );
      return;
   }
   switch (fail) {
      case GL_KEEP:
      case GL_ZERO:
      case GL_REPLACE:
      case GL_INCR:
      case GL_DECR:
      case GL_INVERT:
         ctx->Stencil.FailFunc = fail;
         break;
      default:
         gl_error( ctx, GL_INVALID_ENUM, "glStencilOp" );
         return;
   }
   switch (zfail) {
      case GL_KEEP:
      case GL_ZERO:
      case GL_REPLACE:
      case GL_INCR:
      case GL_DECR:
      case GL_INVERT:
         ctx->Stencil.ZFailFunc = zfail;
         break;
      default:
         gl_error( ctx, GL_INVALID_ENUM, "glStencilOp" );
         return;
   }
   switch (zpass) {
      case GL_KEEP:
      case GL_ZERO:
      case GL_REPLACE:
      case GL_INCR:
      case GL_DECR:
      case GL_INVERT:
         ctx->Stencil.ZPassFunc = zpass;
         break;
      default:
         gl_error( ctx, GL_INVALID_ENUM, "glStencilOp" );
         return;
   }
}

__attribute__((used)) static void apply_stencil_op_to_span( GLcontext *ctx,
                                      GLuint n, GLint x, GLint y,
				      GLenum oper, GLubyte mask[] )
{
   GLint i;
   GLstencil s, ref;
   GLstencil wrtmask, invmask;
   GLstencil *stencil;

   wrtmask = ctx->Stencil.WriteMask;
   invmask = ~ctx->Stencil.WriteMask;
   ref = ctx->Stencil.Ref;
   stencil = STENCIL_ADDRESS( x, y );

   switch (oper) {
      case GL_KEEP:
         /* do nothing */
         break;
      case GL_ZERO:
	 if (invmask==0) {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
		  stencil[i] = 0;
	       }
	    }
	 }
	 else {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
		  stencil[i] = stencil[i] & invmask;
	       }
	    }
	 }
	 break;
      case GL_REPLACE:
	 if (invmask==0) {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
                  stencil[i] = ref;
	       }
	    }
	 }
	 else {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
		  s = stencil[i];
		  stencil[i] = (invmask & s ) | (wrtmask & ref);
	       }
	    }
	 }
	 break;
      case GL_INCR:
	 if (invmask==0) {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
		  s = stencil[i];
		  if (s<0xff) {
		     stencil[i] = s+1;
		  }
	       }
	    }
	 }
	 else {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
		  /* VERIFY logic of adding 1 to a write-masked value */
		  s = stencil[i];
		  if (s<0xff) {
		     stencil[i] = (invmask & s) | (wrtmask & (s+1));
		  }
	       }
	    }
	 }
	 break;
      case GL_DECR:
	 if (invmask==0) {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
		  s = stencil[i];
		  if (s>0) {
		     stencil[i] = s-1;
		  }
	       }
	    }
	 }
	 else {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
		  /* VERIFY logic of subtracting 1 to a write-masked value */
		  s = stencil[i];
		  if (s>0) {
		     stencil[i] = (invmask & s) | (wrtmask & (s-1));
		  }
	       }
	    }
	 }
	 break;
      case GL_INVERT:
	 if (invmask==0) {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
		  s = stencil[i];
		  stencil[i] = ~s;
	       }
	    }
	 }
	 else {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
		  s = stencil[i];
		  stencil[i] = (invmask & s) | (wrtmask & ~s);
	       }
	    }
	 }
	 break;
      default:
         gl_problem(ctx, "Bad stencilop in apply_stencil_op_to_span");
   }
}

GLint gl_stencil_span( GLcontext *ctx,
                       GLuint n, GLint x, GLint y, GLubyte mask[] )
{
   GLubyte fail[MAX_WIDTH];
   GLint allfail = 0;
   GLuint i;
   GLstencil r, s;
   GLstencil *stencil;

   stencil = STENCIL_ADDRESS( x, y );

   /*
    * Perform stencil test.  The results of this operation are stored
    * in the fail[] array:
    *   IF fail[i] is non-zero THEN
    *       the stencil fail operator is to be applied
    *   ELSE
    *       the stencil fail operator is not to be applied
    *   ENDIF
    */
   switch (ctx->Stencil.Function) {
      case GL_NEVER:
         /* always fail */
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       mask[i] = 0;
	       fail[i] = 1;
	    }
	    else {
	       fail[i] = 0;
	    }
	 }
	 allfail = 1;
	 break;
      case GL_LESS:
	 r = ctx->Stencil.Ref & ctx->Stencil.ValueMask;
	 for (i=0;i<n;i++) {
	    if (mask[i]) {
	       s = stencil[i] & ctx->Stencil.ValueMask;
	       if (r < s) {
		  /* passed */
		  fail[i] = 0;
	       }
	       else {
		  fail[i] = 1;
		  mask[i] = 0;
	       }
	    }
	    else {
	       fail[i] = 0;
	    }
	 }
	 break;
      case GL_LEQUAL:
	 r = ctx->Stencil.Ref & ctx->Stencil.ValueMask;
	 for (i=0;i<n;i++) {
	    if (mask[i]) {
	       s = stencil[i] & ctx->Stencil.ValueMask;
	       if (r <= s) {
		  /* pass */
		  fail[i] = 0;
	       }
	       else {
		  fail[i] = 1;
		  mask[i] = 0;
	       }
	    }
	    else {
	       fail[i] = 0;
	    }
	 }
	 break;
      case GL_GREATER:
	 r = ctx->Stencil.Ref & ctx->Stencil.ValueMask;
	 for (i=0;i<n;i++) {
	    if (mask[i]) {
	       s = stencil[i] & ctx->Stencil.ValueMask;
	       if (r > s) {
		  /* passed */
		  fail[i] = 0;
	       }
	       else {
		  fail[i] = 1;
		  mask[i] = 0;
	       }
	    }
	    else {
	       fail[i] = 0;
	    }
	 }
	 break;
      case GL_GEQUAL:
	 r = ctx->Stencil.Ref & ctx->Stencil.ValueMask;
	 for (i=0;i<n;i++) {
	    if (mask[i]) {
	       s = stencil[i] & ctx->Stencil.ValueMask;
	       if (r >= s) {
		  /* passed */
		  fail[i] = 0;
	       }
	       else {
		  fail[i] = 1;
		  mask[i] = 0;
	       }
	    }
	    else {
	       fail[i] = 0;
	    }
	 }
	 break;
      case GL_EQUAL:
	 r = ctx->Stencil.Ref & ctx->Stencil.ValueMask;
	 for (i=0;i<n;i++) {
	    if (mask[i]) {
	       s = stencil[i] & ctx->Stencil.ValueMask;
	       if (r == s) {
		  /* passed */
		  fail[i] = 0;
	       }
	       else {
		  fail[i] = 1;
		  mask[i] = 0;
	       }
	    }
	    else {
	       fail[i] = 0;
	    }
	 }
	 break;
      case GL_NOTEQUAL:
	 r = ctx->Stencil.Ref & ctx->Stencil.ValueMask;
	 for (i=0;i<n;i++) {
	    if (mask[i]) {
	       s = stencil[i] & ctx->Stencil.ValueMask;
	       if (r != s) {
		  /* passed */
		  fail[i] = 0;
	       }
	       else {
		  fail[i] = 1;
		  mask[i] = 0;
	       }
	    }
	    else {
	       fail[i] = 0;
	    }
	 }
	 break;
      case GL_ALWAYS:
	 /* always pass */
	 for (i=0;i<n;i++) {
	    fail[i] = 0;
	 }
	 break;
      default:
         gl_problem(ctx, "Bad stencil func in gl_stencil_span");
         return 0;
   }

   apply_stencil_op_to_span( ctx, n, x, y, ctx->Stencil.FailFunc, fail );

   return (allfail) ? 0 : 1;
}

void gl_depth_stencil_span( GLcontext *ctx,
                            GLuint n, GLint x, GLint y, const GLdepth z[],
			    GLubyte mask[] )
{
   if (ctx->Depth.Test==GL_FALSE) {
      /*
       * No depth buffer, just apply zpass stencil function to active pixels.
       */
      apply_stencil_op_to_span( ctx, n, x, y, ctx->Stencil.ZPassFunc, mask );
   }
   else {
      /*
       * Perform depth buffering, then apply zpass or zfail stencil function.
       */
      GLubyte passmask[MAX_WIDTH], failmask[MAX_WIDTH], oldmask[MAX_WIDTH];
      GLuint i;

      /* init pass and fail masks to zero, copy mask[] to oldmask[] */
      for (i=0;i<n;i++) {
	 passmask[i] = failmask[i] = 0;
         oldmask[i] = mask[i];
      }

      /* apply the depth test */
      if (ctx->Driver.DepthTestSpan)
         (*ctx->Driver.DepthTestSpan)( ctx, n, x, y, z, mask );

      /* set the stencil pass/fail flags according to result of depth test */
      for (i=0;i<n;i++) {
         if (oldmask[i]) {
            if (mask[i]) {
               passmask[i] = 1;
            }
            else {
               failmask[i] = 1;
            }
         }
      }

      /* apply the pass and fail operations */
      apply_stencil_op_to_span( ctx, n, x, y, ctx->Stencil.ZFailFunc, failmask );
      apply_stencil_op_to_span( ctx, n, x, y, ctx->Stencil.ZPassFunc, passmask );
   }
}

__attribute__((used)) static void apply_stencil_op_to_pixels( GLcontext *ctx,
                                        GLuint n, const GLint x[],
				        const GLint y[],
				        GLenum oper, GLubyte mask[] )
{
   GLint i;
   GLstencil ref;
   GLstencil wrtmask, invmask;

   wrtmask = ctx->Stencil.WriteMask;
   invmask = ~ctx->Stencil.WriteMask;

   ref = ctx->Stencil.Ref;

   switch (oper) {
      case GL_KEEP:
         /* do nothing */
         break;
      case GL_ZERO:
	 if (invmask==0) {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
                  GLstencil *sptr = STENCIL_ADDRESS( x[i], y[i] );
                  *sptr = 0;
	       }
	    }
	 }
	 else {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
                  GLstencil *sptr = STENCIL_ADDRESS( x[i], y[i] );
		  *sptr = invmask & *sptr;
	       }
	    }
	 }
	 break;
      case GL_REPLACE:
	 if (invmask==0) {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
                  GLstencil *sptr = STENCIL_ADDRESS( x[i], y[i] );
                  *sptr = ref;
	       }
	    }
	 }
	 else {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
                  GLstencil *sptr = STENCIL_ADDRESS( x[i], y[i] );
		  *sptr = (invmask & *sptr ) | (wrtmask & ref);
	       }
	    }
	 }
	 break;
      case GL_INCR:
	 if (invmask==0) {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
                  GLstencil *sptr = STENCIL_ADDRESS( x[i], y[i] );
		  if (*sptr < 0xff) {
		     *sptr = *sptr + 1;
		  }
	       }
	    }
	 }
	 else {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
                  GLstencil *sptr = STENCIL_ADDRESS( x[i], y[i] );
		  if (*sptr<0xff) {
		     *sptr = (invmask & *sptr) | (wrtmask & (*sptr+1));
		  }
	       }
	    }
	 }
	 break;
      case GL_DECR:
	 if (invmask==0) {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
                  GLstencil *sptr = STENCIL_ADDRESS( x[i], y[i] );
		  if (*sptr>0) {
		     *sptr = *sptr - 1;
		  }
	       }
	    }
	 }
	 else {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
                  GLstencil *sptr = STENCIL_ADDRESS( x[i], y[i] );
		  if (*sptr>0) {
		     *sptr = (invmask & *sptr) | (wrtmask & (*sptr-1));
		  }
	       }
	    }
	 }
	 break;
      case GL_INVERT:
	 if (invmask==0) {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
                  GLstencil *sptr = STENCIL_ADDRESS( x[i], y[i] );
                  *sptr = ~*sptr;
	       }
	    }
	 }
	 else {
	    for (i=0;i<n;i++) {
	       if (mask[i]) {
                  GLstencil *sptr = STENCIL_ADDRESS( x[i], y[i] );
                  *sptr = (invmask & *sptr) | (wrtmask & ~*sptr);
	       }
	    }
	 }
	 break;
      default:
         gl_problem(ctx, "Bad stencilop in apply_stencil_op_to_pixels");
   }
}

GLint gl_stencil_pixels( GLcontext *ctx,
                         GLuint n, const GLint x[], const GLint y[],
			 GLubyte mask[] )
{
   GLubyte fail[PB_SIZE];
   GLstencil r, s;
   GLuint i;
   GLint allfail = 0;

   /*
    * Perform stencil test.  The results of this operation are stored
    * in the fail[] array:
    *   IF fail[i] is non-zero THEN
    *       the stencil fail operator is to be applied
    *   ELSE
    *       the stencil fail operator is not to be applied
    *   ENDIF
    */

   switch (ctx->Stencil.Function) {
      case GL_NEVER:
         /* always fail */
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       mask[i] = 0;
	       fail[i] = 1;
	    }
	    else {
	       fail[i] = 0;
	    }
	 }
	 allfail = 1;
	 break;
      case GL_LESS:
	 r = ctx->Stencil.Ref & ctx->Stencil.ValueMask;
	 for (i=0;i<n;i++) {
	    if (mask[i]) {
               GLstencil *sptr = STENCIL_ADDRESS(x[i],y[i]);
	       s = *sptr & ctx->Stencil.ValueMask;
	       if (r < s) {
		  /* passed */
		  fail[i] = 0;
	       }
	       else {
		  fail[i] = 1;
		  mask[i] = 0;
	       }
	    }
	    else {
	       fail[i] = 0;
	    }
	 }
	 break;
      case GL_LEQUAL:
	 r = ctx->Stencil.Ref & ctx->Stencil.ValueMask;
	 for (i=0;i<n;i++) {
	    if (mask[i]) {
               GLstencil *sptr = STENCIL_ADDRESS(x[i],y[i]);
	       s = *sptr & ctx->Stencil.ValueMask;
	       if (r <= s) {
		  /* pass */
		  fail[i] = 0;
	       }
	       else {
		  fail[i] = 1;
		  mask[i] = 0;
	       }
	    }
	    else {
	       fail[i] = 0;
	    }
	 }
	 break;
      case GL_GREATER:
	 r = ctx->Stencil.Ref & ctx->Stencil.ValueMask;
	 for (i=0;i<n;i++) {
	    if (mask[i]) {
               GLstencil *sptr = STENCIL_ADDRESS(x[i],y[i]);
	       s = *sptr & ctx->Stencil.ValueMask;
	       if (r > s) {
		  /* passed */
		  fail[i] = 0;
	       }
	       else {
		  fail[i] = 1;
		  mask[i] = 0;
	       }
	    }
	    else {
	       fail[i] = 0;
	    }
	 }
	 break;
      case GL_GEQUAL:
	 r = ctx->Stencil.Ref & ctx->Stencil.ValueMask;
	 for (i=0;i<n;i++) {
	    if (mask[i]) {
               GLstencil *sptr = STENCIL_ADDRESS(x[i],y[i]);
	       s = *sptr & ctx->Stencil.ValueMask;
	       if (r >= s) {
		  /* passed */
		  fail[i] = 0;
	       }
	       else {
		  fail[i] = 1;
		  mask[i] = 0;
	       }
	    }
	    else {
	       fail[i] = 0;
	    }
	 }
	 break;
      case GL_EQUAL:
	 r = ctx->Stencil.Ref & ctx->Stencil.ValueMask;
	 for (i=0;i<n;i++) {
	    if (mask[i]) {
               GLstencil *sptr = STENCIL_ADDRESS(x[i],y[i]);
	       s = *sptr & ctx->Stencil.ValueMask;
	       if (r == s) {
		  /* passed */
		  fail[i] = 0;
	       }
	       else {
		  fail[i] = 1;
		  mask[i] = 0;
	       }
	    }
	    else {
	       fail[i] = 0;
	    }
	 }
	 break;
      case GL_NOTEQUAL:
	 r = ctx->Stencil.Ref & ctx->Stencil.ValueMask;
	 for (i=0;i<n;i++) {
	    if (mask[i]) {
               GLstencil *sptr = STENCIL_ADDRESS(x[i],y[i]);
	       s = *sptr & ctx->Stencil.ValueMask;
	       if (r != s) {
		  /* passed */
		  fail[i] = 0;
	       }
	       else {
		  fail[i] = 1;
		  mask[i] = 0;
	       }
	    }
	    else {
	       fail[i] = 0;
	    }
	 }
	 break;
      case GL_ALWAYS:
	 /* always pass */
	 for (i=0;i<n;i++) {
	    fail[i] = 0;
	 }
	 break;
      default:
         gl_problem(ctx, "Bad stencil func in gl_stencil_pixels");
         return 0;
   }

   apply_stencil_op_to_pixels( ctx, n, x, y, ctx->Stencil.FailFunc, fail );

   return (allfail) ? 0 : 1;
}

void gl_depth_stencil_pixels( GLcontext *ctx,
                              GLuint n, const GLint x[], const GLint y[],
			      const GLdepth z[], GLubyte mask[] )
{
   if (ctx->Depth.Test==GL_FALSE) {
      /*
       * No depth buffer, just apply zpass stencil function to active pixels.
       */
      apply_stencil_op_to_pixels( ctx, n, x, y, ctx->Stencil.ZPassFunc, mask );
   }
   else {
      /*
       * Perform depth buffering, then apply zpass or zfail stencil function.
       */
      GLubyte passmask[PB_SIZE], failmask[PB_SIZE], oldmask[PB_SIZE];
      GLuint i;

      /* init pass and fail masks to zero */
      for (i=0;i<n;i++) {
	 passmask[i] = failmask[i] = 0;
         oldmask[i] = mask[i];
      }

      /* apply the depth test */
      if (ctx->Driver.DepthTestPixels)
         (*ctx->Driver.DepthTestPixels)( ctx, n, x, y, z, mask );

      /* set the stencil pass/fail flags according to result of depth test */
      for (i=0;i<n;i++) {
         if (oldmask[i]) {
            if (mask[i]) {
               passmask[i] = 1;
            }
            else {
               failmask[i] = 1;
            }
         }
      }

      /* apply the pass and fail operations */
      apply_stencil_op_to_pixels( ctx, n, x, y,
                                  ctx->Stencil.ZFailFunc, failmask );
      apply_stencil_op_to_pixels( ctx, n, x, y,
                                  ctx->Stencil.ZPassFunc, passmask );
   }

}

void gl_read_stencil_span( GLcontext *ctx,
                           GLuint n, GLint x, GLint y, GLubyte stencil[] )
{
   GLstencil *s;

   if (ctx->Buffer->Stencil) {
      s = STENCIL_ADDRESS( x, y );
      MEMCPY( stencil, s, n * sizeof(GLubyte) );
   }
}

void gl_write_stencil_span( GLcontext *ctx,
                            GLuint n, GLint x, GLint y,
			    const GLubyte stencil[] )
{
   GLstencil *s;

   if (ctx->Buffer->Stencil) {
      s = STENCIL_ADDRESS( x, y );
      MEMCPY( s, stencil, n * sizeof(GLubyte) );
   }
}

void gl_alloc_stencil_buffer( GLcontext *ctx )
{
   GLuint buffersize = ctx->Buffer->Width * ctx->Buffer->Height;

   /* deallocate current stencil buffer if present */
   if (ctx->Buffer->Stencil) {
      free(ctx->Buffer->Stencil);
      ctx->Buffer->Stencil = NULL;
   }

   /* allocate new stencil buffer */
   ctx->Buffer->Stencil = (GLstencil *) malloc(buffersize * sizeof(GLstencil));
   if (!ctx->Buffer->Stencil) {
      /* out of memory */
      ctx->Stencil.Enabled = GL_FALSE;
      gl_error( ctx, GL_OUT_OF_MEMORY, "gl_alloc_stencil_buffer" );
   }
}

void gl_clear_stencil_buffer( GLcontext *ctx )
{
   if (ctx->Visual->StencilBits==0 || !ctx->Buffer->Stencil) {
      /* no stencil buffer */
      return;
   }

   if (ctx->Scissor.Enabled) {
      /* clear scissor region only */
      GLint y;
      GLint width = ctx->Buffer->Xmax - ctx->Buffer->Xmin + 1;
      for (y=ctx->Buffer->Ymin; y<=ctx->Buffer->Ymax; y++) {
         GLstencil *ptr = STENCIL_ADDRESS( ctx->Buffer->Xmin, y );
         MEMSET( ptr, ctx->Stencil.Clear, width * sizeof(GLstencil) );
      }
   }
   else {
      /* clear whole stencil buffer */
      MEMSET( ctx->Buffer->Stencil, ctx->Stencil.Clear,
              ctx->Buffer->Width * ctx->Buffer->Height * sizeof(GLstencil) );
   }
}

