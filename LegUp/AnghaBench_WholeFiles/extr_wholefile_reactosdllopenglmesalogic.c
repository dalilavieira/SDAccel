#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_4__ ;
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
struct TYPE_19__ {int LogicOp; } ;
struct TYPE_18__ {int /*<<< orphan*/  (* ReadColorPixels ) (TYPE_4__*,size_t,int const*,int const*,int*,int*,int*,int*,int*) ;int /*<<< orphan*/  (* ReadIndexPixels ) (TYPE_4__*,size_t,int const*,int const*,size_t*,int*) ;int /*<<< orphan*/  (* ReadIndexSpan ) (TYPE_4__*,size_t,int,int,size_t*) ;} ;
struct TYPE_21__ {int RasterMask; TYPE_3__* Visual; TYPE_2__ Color; TYPE_1__ Driver; int /*<<< orphan*/  NewState; } ;
struct TYPE_20__ {int /*<<< orphan*/  AlphaScale; int /*<<< orphan*/  BlueScale; int /*<<< orphan*/  GreenScale; int /*<<< orphan*/  RedScale; } ;
typedef  size_t GLuint ;
typedef  int GLubyte ;
typedef  int GLint ;
typedef  int GLenum ;
typedef  TYPE_4__ GLcontext ;

/* Variables and functions */
 int ALPHABUF_BIT ; 
#define  GL_AND 143 
#define  GL_AND_INVERTED 142 
#define  GL_AND_REVERSE 141 
#define  GL_CLEAR 140 
#define  GL_COPY 139 
#define  GL_COPY_INVERTED 138 
#define  GL_EQUIV 137 
 int /*<<< orphan*/  GL_INVALID_ENUM ; 
 int /*<<< orphan*/  GL_INVALID_OPERATION ; 
#define  GL_INVERT 136 
#define  GL_NAND 135 
#define  GL_NOOP 134 
#define  GL_NOR 133 
#define  GL_OR 132 
#define  GL_OR_INVERTED 131 
#define  GL_OR_REVERSE 130 
#define  GL_SET 129 
#define  GL_XOR 128 
 scalar_t__ INSIDE_BEGIN_END (TYPE_4__*) ; 
 int MAX_WIDTH ; 
 int /*<<< orphan*/  NEW_RASTER_OPS ; 
 int PB_SIZE ; 
 int /*<<< orphan*/  gl_error (TYPE_4__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gl_problem (TYPE_4__*,char*) ; 
 int /*<<< orphan*/  gl_read_alpha_pixels (TYPE_4__*,size_t,int const*,int const*,int*,int*) ; 
 int /*<<< orphan*/  gl_read_color_span (TYPE_4__*,size_t,int,int,int*,int*,int*,int*) ; 
 int /*<<< orphan*/  stub1 (TYPE_4__*,size_t,int,int,size_t*) ; 
 int /*<<< orphan*/  stub2 (TYPE_4__*,size_t,int const*,int const*,size_t*,int*) ; 
 int /*<<< orphan*/  stub3 (TYPE_4__*,size_t,int const*,int const*,int*,int*,int*,int*,int*) ; 

void gl_LogicOp( GLcontext *ctx, GLenum opcode )
{
   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glLogicOp" );
      return;
   }
   switch (opcode) {
      case GL_CLEAR:
      case GL_SET:
      case GL_COPY:
      case GL_COPY_INVERTED:
      case GL_NOOP:
      case GL_INVERT:
      case GL_AND:
      case GL_NAND:
      case GL_OR:
      case GL_NOR:
      case GL_XOR:
      case GL_EQUIV:
      case GL_AND_REVERSE:
      case GL_AND_INVERTED:
      case GL_OR_REVERSE:
      case GL_OR_INVERTED:
         ctx->Color.LogicOp = opcode;
         ctx->NewState |= NEW_RASTER_OPS;
	 return;
      default:
         gl_error( ctx, GL_INVALID_ENUM, "glLogicOp" );
	 return;
   }
}

void gl_logicop_ci_span( GLcontext *ctx, GLuint n, GLint x, GLint y,
                         GLuint index[], GLubyte mask[] )
{
   GLuint dest[MAX_WIDTH];
   GLuint i;

   /* Read dest values from frame buffer */
   (*ctx->Driver.ReadIndexSpan)( ctx, n, x, y, dest );

   switch (ctx->Color.LogicOp) {
      case GL_CLEAR:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = 0;
	    }
	 }
	 break;
      case GL_SET:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = 1;
	    }
	 }
	 break;
      case GL_COPY:
	 /* do nothing */
	 break;
      case GL_COPY_INVERTED:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = ~index[i];
	    }
	 }
	 break;
      case GL_NOOP:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = dest[i];
	    }
	 }
	 break;
      case GL_INVERT:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = ~dest[i];
	    }
	 }
	 break;
      case GL_AND:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] &= dest[i];
	    }
	 }
	 break;
      case GL_NAND:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = ~(index[i] & dest[i]);
	    }
	 }
	 break;
      case GL_OR:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] |= dest[i];
	    }
	 }
	 break;
      case GL_NOR:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = ~(index[i] | dest[i]);
	    }
	 }
	 break;
      case GL_XOR:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] ^= dest[i];
	    }
	 }
	 break;
      case GL_EQUIV:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = ~(index[i] ^ dest[i]);
	    }
	 }
	 break;
      case GL_AND_REVERSE:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = index[i] & ~dest[i];
	    }
	 }
	 break;
      case GL_AND_INVERTED:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = ~index[i] & dest[i];
	    }
	 }
	 break;
      case GL_OR_REVERSE:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = index[i] | ~dest[i];
	    }
	 }
	 break;
      case GL_OR_INVERTED:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = ~index[i] | dest[i];
	    }
	 }
	 break;
      default:
	 gl_error( ctx, GL_INVALID_ENUM, "gl_logic error" );
   }
}

void gl_logicop_ci_pixels( GLcontext *ctx,
                           GLuint n, const GLint x[], const GLint y[],
                           GLuint index[], GLubyte mask[] )
{
   GLuint dest[PB_SIZE];
   GLuint i;

   /* Read dest values from frame buffer */
   (*ctx->Driver.ReadIndexPixels)( ctx, n, x, y, dest, mask );

   switch (ctx->Color.LogicOp) {
      case GL_CLEAR:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = 0;
	    }
	 }
	 break;
      case GL_SET:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = 1;
	    }
	 }
	 break;
      case GL_COPY:
	 /* do nothing */
	 break;
      case GL_COPY_INVERTED:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = ~index[i];
	    }
	 }
	 break;
      case GL_NOOP:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = dest[i];
	    }
	 }
	 break;
      case GL_INVERT:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = ~dest[i];
	    }
	 }
	 break;
      case GL_AND:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] &= dest[i];
	    }
	 }
	 break;
      case GL_NAND:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = ~(index[i] & dest[i]);
	    }
	 }
	 break;
      case GL_OR:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] |= dest[i];
	    }
	 }
	 break;
      case GL_NOR:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = ~(index[i] | dest[i]);
	    }
	 }
	 break;
      case GL_XOR:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] ^= dest[i];
	    }
	 }
	 break;
      case GL_EQUIV:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = ~(index[i] ^ dest[i]);
	    }
	 }
	 break;
      case GL_AND_REVERSE:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = index[i] & ~dest[i];
	    }
	 }
	 break;
      case GL_AND_INVERTED:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = ~index[i] & dest[i];
	    }
	 }
	 break;
      case GL_OR_REVERSE:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = index[i] | ~dest[i];
	    }
	 }
	 break;
      case GL_OR_INVERTED:
         for (i=0;i<n;i++) {
	    if (mask[i]) {
	       index[i] = ~index[i] | dest[i];
	    }
	 }
	 break;
      default:
	 gl_error( ctx, GL_INVALID_ENUM, "gl_logic_pixels error" );
   }
}

void gl_logicop_rgba_span( GLcontext *ctx,
                           GLuint n, GLint x, GLint y,
                           GLubyte red[], GLubyte green[],
                           GLubyte blue[], GLubyte alpha[],
                           GLubyte mask[] )
{
   GLubyte rdest[MAX_WIDTH], gdest[MAX_WIDTH];
   GLubyte bdest[MAX_WIDTH], adest[MAX_WIDTH];
   GLuint i;

   /* Read span of current frame buffer pixels */
   gl_read_color_span( ctx, n, x, y, rdest, gdest, bdest, adest );

   /* apply logic op */
   switch (ctx->Color.LogicOp) {
      case GL_CLEAR:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i] = green[i] = blue[i] = alpha[i] = 0;
            }
         }
         break;
      case GL_SET:
         {
            GLubyte r = (GLint) ctx->Visual->RedScale;
            GLubyte g = (GLint) ctx->Visual->GreenScale;
            GLubyte b = (GLint) ctx->Visual->BlueScale;
            GLubyte a = (GLint) ctx->Visual->AlphaScale;
            for (i=0;i<n;i++) {
               if (mask[i]) {
                  red[i]   = r;
                  green[i] = g;
                  blue[i]  = b;
                  alpha[i] = a;
               }
            }
         }
         break;
      case GL_COPY:
         /* do nothing */
         break;
      case GL_COPY_INVERTED:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = ~red[i];
               green[i] = ~green[i];
               blue[i]  = ~blue[i];
               alpha[i] = ~alpha[i];
            }
         }
         break;
      case GL_NOOP:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = rdest[i];
               green[i] = gdest[i];
               blue[i]  = bdest[i];
               alpha[i] = adest[i];
            }
         }
         break;
      case GL_INVERT:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = ~rdest[i];
               green[i] = ~gdest[i];
               blue[i]  = ~bdest[i];
               alpha[i] = ~adest[i];
            }
         }
         break;
      case GL_AND:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   &= rdest[i];
               green[i] &= gdest[i];
               blue[i]  &= bdest[i];
               alpha[i] &= adest[i];
            }
         }
         break;
      case GL_NAND:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = ~(red[i]   & rdest[i]);
               green[i] = ~(green[i] & gdest[i]);
               blue[i]  = ~(blue[i]  & bdest[i]);
               alpha[i] = ~(alpha[i] & adest[i]);
            }
         }
         break;
      case GL_OR:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   |= rdest[i];
               green[i] |= gdest[i];
               blue[i]  |= bdest[i];
               alpha[i] |= adest[i];
            }
         }
         break;
      case GL_NOR:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = ~(red[i]   | rdest[i]);
               green[i] = ~(green[i] | gdest[i]);
               blue[i]  = ~(blue[i]  | bdest[i]);
               alpha[i] = ~(alpha[i] | adest[i]);
            }
         }
         break;
      case GL_XOR:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   ^= rdest[i];
               green[i] ^= gdest[i];
               blue[i]  ^= bdest[i];
               alpha[i] ^= adest[i];
            }
         }
         break;
      case GL_EQUIV:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = ~(red[i]   ^ rdest[i]);
               green[i] = ~(green[i] ^ gdest[i]);
               blue[i]  = ~(blue[i]  ^ bdest[i]);
               alpha[i] = ~(alpha[i] ^ adest[i]);
            }
         }
         break;
      case GL_AND_REVERSE:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = red[i]   & ~rdest[i];
               green[i] = green[i] & ~gdest[i];
               blue[i]  = blue[i]  & ~bdest[i];
               alpha[i] = alpha[i] & ~adest[i];
            }
         }
         break;
      case GL_AND_INVERTED:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = ~red[i]   & rdest[i];
               green[i] = ~green[i] & gdest[i];
               blue[i]  = ~blue[i]  & bdest[i];
               alpha[i] = ~alpha[i] & adest[i];
            }
         }
         break;
      case GL_OR_REVERSE:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = red[i]   | ~rdest[i];
               green[i] = green[i] | ~gdest[i];
               blue[i]  = blue[i]  | ~bdest[i];
               alpha[i] = alpha[i] | ~adest[i];
            }
         }
         break;
      case GL_OR_INVERTED:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = ~red[i]   | rdest[i];
               green[i] = ~green[i] | gdest[i];
               blue[i]  = ~blue[i]  | bdest[i];
               alpha[i] = ~alpha[i] | adest[i];
            }
         }
         break;
      default:
         /* should never happen */
         gl_problem(ctx, "Bad function in gl_logicop_rgba_span");
         return;
   }
}

void gl_logicop_rgba_pixels( GLcontext *ctx,
                             GLuint n, const GLint x[], const GLint y[],
                             GLubyte red[], GLubyte green[],
                             GLubyte blue[], GLubyte alpha[],
                             GLubyte mask[] )
{
   GLubyte rdest[PB_SIZE], gdest[PB_SIZE], bdest[PB_SIZE], adest[PB_SIZE];
   GLuint i;

   /* Read pixels from current color buffer */
   (*ctx->Driver.ReadColorPixels)( ctx, n, x, y, rdest, gdest, bdest, adest, mask );
   if (ctx->RasterMask & ALPHABUF_BIT) {
      gl_read_alpha_pixels( ctx, n, x, y, adest, mask );
   }

   /* apply logic op */
   switch (ctx->Color.LogicOp) {
      case GL_CLEAR:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i] = green[i] = blue[i] = alpha[i] = 0;
            }
         }
         break;
      case GL_SET:
         {
            GLubyte r = (GLint) ctx->Visual->RedScale;
            GLubyte g = (GLint) ctx->Visual->GreenScale;
            GLubyte b = (GLint) ctx->Visual->BlueScale;
            GLubyte a = (GLint) ctx->Visual->AlphaScale;
            for (i=0;i<n;i++) {
               if (mask[i]) {
                  red[i]   = r;
                  green[i] = g;
                  blue[i]  = b;
                  alpha[i] = a;
               }
            }
         }
         break;
      case GL_COPY:
         /* do nothing */
         break;
      case GL_COPY_INVERTED:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = ~red[i];
               green[i] = ~green[i];
               blue[i]  = ~blue[i];
               alpha[i] = ~alpha[i];
            }
         }
         break;
      case GL_NOOP:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = rdest[i];
               green[i] = gdest[i];
               blue[i]  = bdest[i];
               alpha[i] = adest[i];
            }
         }
         break;
      case GL_INVERT:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = ~rdest[i];
               green[i] = ~gdest[i];
               blue[i]  = ~bdest[i];
               alpha[i] = ~adest[i];
            }
         }
         break;
      case GL_AND:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   &= rdest[i];
               green[i] &= gdest[i];
               blue[i]  &= bdest[i];
               alpha[i] &= adest[i];
            }
         }
         break;
      case GL_NAND:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = ~(red[i]   & rdest[i]);
               green[i] = ~(green[i] & gdest[i]);
               blue[i]  = ~(blue[i]  & bdest[i]);
               alpha[i] = ~(alpha[i] & adest[i]);
            }
         }
         break;
      case GL_OR:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   |= rdest[i];
               green[i] |= gdest[i];
               blue[i]  |= bdest[i];
               alpha[i] |= adest[i];
            }
         }
         break;
      case GL_NOR:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = ~(red[i]   | rdest[i]);
               green[i] = ~(green[i] | gdest[i]);
               blue[i]  = ~(blue[i]  | bdest[i]);
               alpha[i] = ~(alpha[i] | adest[i]);
            }
         }
         break;
      case GL_XOR:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   ^= rdest[i];
               green[i] ^= gdest[i];
               blue[i]  ^= bdest[i];
               alpha[i] ^= adest[i];
            }
         }
         break;
      case GL_EQUIV:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = ~(red[i]   ^ rdest[i]);
               green[i] = ~(green[i] ^ gdest[i]);
               blue[i]  = ~(blue[i]  ^ bdest[i]);
               alpha[i] = ~(alpha[i] ^ adest[i]);
            }
         }
         break;
      case GL_AND_REVERSE:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = red[i]   & ~rdest[i];
               green[i] = green[i] & ~gdest[i];
               blue[i]  = blue[i]  & ~bdest[i];
               alpha[i] = alpha[i] & ~adest[i];
            }
         }
         break;
      case GL_AND_INVERTED:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = ~red[i]   & rdest[i];
               green[i] = ~green[i] & gdest[i];
               blue[i]  = ~blue[i]  & bdest[i];
               alpha[i] = ~alpha[i] & adest[i];
            }
         }
         break;
      case GL_OR_REVERSE:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = red[i]   | ~rdest[i];
               green[i] = green[i] | ~gdest[i];
               blue[i]  = blue[i]  | ~bdest[i];
               alpha[i] = alpha[i] | ~adest[i];
            }
         }
         break;
      case GL_OR_INVERTED:
         for (i=0;i<n;i++) {
            if (mask[i]) {
               red[i]   = ~red[i]   | rdest[i];
               green[i] = ~green[i] | gdest[i];
               blue[i]  = ~blue[i]  | bdest[i];
               alpha[i] = ~alpha[i] | adest[i];
            }
         }
         break;
      default:
         /* should never happen */
         gl_problem(ctx, "Bad function in gl_logicop_rgba_pixels");
         return;
   }
}

