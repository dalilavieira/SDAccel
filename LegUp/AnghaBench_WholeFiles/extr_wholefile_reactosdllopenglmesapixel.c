#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_29__   TYPE_5__ ;
typedef  struct TYPE_28__   TYPE_4__ ;
typedef  struct TYPE_27__   TYPE_3__ ;
typedef  struct TYPE_26__   TYPE_2__ ;
typedef  struct TYPE_25__   TYPE_1__ ;
typedef  struct TYPE_24__   TYPE_14__ ;

/* Type definitions */
struct TYPE_24__ {scalar_t__ RowLength; scalar_t__ SkipPixels; scalar_t__ SkipRows; scalar_t__ SwapBytes; scalar_t__ LsbFirst; int Alignment; } ;
struct TYPE_28__ {double RedBias; double RedScale; double GreenBias; double GreenScale; double BlueBias; double BlueScale; double AlphaBias; double AlphaScale; scalar_t__ MapColorFlag; double ZoomX; double ZoomY; int MapStoSsize; int* MapStoS; int MapItoIsize; int* MapItoI; int MapItoRsize; int* MapItoR; int MapItoGsize; int* MapItoG; int MapItoBsize; int* MapItoB; int MapItoAsize; int* MapItoA; int MapRtoRsize; int* MapRtoR; int MapGtoGsize; int* MapGtoG; int MapBtoBsize; int* MapBtoB; int MapAtoAsize; int* MapAtoA; int IndexShift; int IndexOffset; int DepthScale; int DepthBias; scalar_t__ MapStencilFlag; } ;
struct TYPE_27__ {int RowLength; int SkipPixels; int SkipRows; int Alignment; scalar_t__ LsbFirst; scalar_t__ SwapBytes; } ;
struct TYPE_29__ {TYPE_14__ Unpack; TYPE_4__ Pixel; TYPE_3__ Pack; TYPE_2__* Buffer; scalar_t__ FastDrawPixels; TYPE_1__* Visual; } ;
struct TYPE_26__ {int Height; int /*<<< orphan*/  Width; } ;
struct TYPE_25__ {scalar_t__ RGBAflag; scalar_t__ EightBitColor; } ;
typedef  int GLvoid ;
typedef  int /*<<< orphan*/  GLushort ;
typedef  int GLuint ;
typedef  int GLubyte ;
typedef  int GLsizei ;
typedef  int GLint ;
typedef  int GLfloat ;
typedef  int GLenum ;
typedef  int /*<<< orphan*/  GLdepth ;
typedef  TYPE_5__ GLcontext ;
typedef  scalar_t__ GLboolean ;

/* Variables and functions */
 scalar_t__ ABSF (int) ; 
 int CEILING (int,int) ; 
 void* CLAMP (int const,double,double) ; 
 int FLOAT_TO_UINT (int) ; 
 int /*<<< orphan*/  FLOAT_TO_USHORT (int) ; 
#define  GL_ALPHA_BIAS 163 
#define  GL_ALPHA_SCALE 162 
 int GL_BITMAP ; 
#define  GL_BLUE_BIAS 161 
#define  GL_BLUE_SCALE 160 
#define  GL_DEPTH_BIAS 159 
#define  GL_DEPTH_SCALE 158 
 scalar_t__ GL_FALSE ; 
#define  GL_GREEN_BIAS 157 
#define  GL_GREEN_SCALE 156 
#define  GL_INDEX_OFFSET 155 
#define  GL_INDEX_SHIFT 154 
 int /*<<< orphan*/  GL_INVALID_ENUM ; 
 int /*<<< orphan*/  GL_INVALID_OPERATION ; 
 int /*<<< orphan*/  GL_INVALID_VALUE ; 
#define  GL_MAP_COLOR 153 
#define  GL_MAP_STENCIL 152 
#define  GL_PACK_ALIGNMENT 151 
#define  GL_PACK_LSB_FIRST 150 
#define  GL_PACK_ROW_LENGTH 149 
#define  GL_PACK_SKIP_PIXELS 148 
#define  GL_PACK_SKIP_ROWS 147 
#define  GL_PACK_SWAP_BYTES 146 
#define  GL_PIXEL_MAP_A_TO_A 145 
#define  GL_PIXEL_MAP_B_TO_B 144 
#define  GL_PIXEL_MAP_G_TO_G 143 
#define  GL_PIXEL_MAP_I_TO_A 142 
#define  GL_PIXEL_MAP_I_TO_B 141 
#define  GL_PIXEL_MAP_I_TO_G 140 
#define  GL_PIXEL_MAP_I_TO_I 139 
#define  GL_PIXEL_MAP_I_TO_R 138 
#define  GL_PIXEL_MAP_R_TO_R 137 
#define  GL_PIXEL_MAP_S_TO_S 136 
#define  GL_RED_BIAS 135 
#define  GL_RED_SCALE 134 
 scalar_t__ GL_TRUE ; 
#define  GL_UNPACK_ALIGNMENT 133 
#define  GL_UNPACK_LSB_FIRST 132 
#define  GL_UNPACK_ROW_LENGTH 131 
#define  GL_UNPACK_SKIP_PIXELS 130 
#define  GL_UNPACK_SKIP_ROWS 129 
#define  GL_UNPACK_SWAP_BYTES 128 
 scalar_t__ INSIDE_BEGIN_END (TYPE_5__*) ; 
 int MAX_PIXEL_MAP_TABLE ; 
 int MAX_WIDTH ; 
 int /*<<< orphan*/  MEMCPY (int*,int*,int) ; 
 int MIN2 (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  free (int*) ; 
 int gl_components_in_format (int) ; 
 int /*<<< orphan*/  gl_error (TYPE_5__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gl_flip_bytes (int*,int) ; 
 int* gl_pixel_addr_in_image (TYPE_14__*,int const*,int,int,int,int,int) ; 
 int gl_sizeof_type (int) ; 
 int /*<<< orphan*/  gl_swap2 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  gl_swap4 (int*,int) ; 
 int /*<<< orphan*/  gl_write_color_span (TYPE_5__*,int,int,int,int /*<<< orphan*/ *,int*,int*,int*,int*,int) ; 
 int /*<<< orphan*/  gl_write_index_span (TYPE_5__*,int,int,int,int /*<<< orphan*/ *,int*,int) ; 
 int /*<<< orphan*/  gl_write_stencil_span (TYPE_5__*,int,int,int,int*) ; 
 scalar_t__ malloc (int) ; 

__attribute__((used)) static void update_drawpixels_state( GLcontext *ctx )
{
   if (ctx->Visual->RGBAflag==GL_TRUE &&
       ctx->Visual->EightBitColor &&
       ctx->Pixel.RedBias==0.0   && ctx->Pixel.RedScale==1.0 &&
       ctx->Pixel.GreenBias==0.0 && ctx->Pixel.GreenScale==1.0 &&
       ctx->Pixel.BlueBias==0.0  && ctx->Pixel.BlueScale==1.0 &&
       ctx->Pixel.AlphaBias==0.0 && ctx->Pixel.AlphaScale==1.0 &&
       ctx->Pixel.MapColorFlag==GL_FALSE &&
       ctx->Pixel.ZoomX==1.0 && ctx->Pixel.ZoomY==1.0 &&
/*       ctx->Unpack.Alignment==4 &&*/
       ctx->Unpack.RowLength==0 &&
       ctx->Unpack.SkipPixels==0 &&
       ctx->Unpack.SkipRows==0 &&
       ctx->Unpack.SwapBytes==0 &&
       ctx->Unpack.LsbFirst==0) {
      ctx->FastDrawPixels = GL_TRUE;
   }
   else {
      ctx->FastDrawPixels = GL_FALSE;
   }
}

void gl_PixelZoom( GLcontext *ctx, GLfloat xfactor, GLfloat yfactor )
{
   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glPixelZoom" );
      return;
   }
   ctx->Pixel.ZoomX = xfactor;
   ctx->Pixel.ZoomY = yfactor;
   update_drawpixels_state( ctx );
}

void
gl_write_zoomed_color_span( GLcontext *ctx,
                            GLuint n, GLint x, GLint y, const GLdepth z[],
                            const GLubyte red[], const GLubyte green[],
                            const GLubyte blue[], const GLubyte alpha[],
                            GLint y0 )
{
   GLint m;
   GLint r0, r1, row, r;
   GLint i, j, skipcol;
   GLubyte zred[MAX_WIDTH], zgreen[MAX_WIDTH];  /* zoomed pixel colors */
   GLubyte zblue[MAX_WIDTH], zalpha[MAX_WIDTH];
   GLdepth zdepth[MAX_WIDTH];  /* zoomed depth values */
   GLint maxwidth = MIN2( ctx->Buffer->Width, MAX_WIDTH );

   /* compute width of output row */
   m = (GLint) ABSF( n * ctx->Pixel.ZoomX );
   if (m==0) {
      return;
   }
   if (ctx->Pixel.ZoomX<0.0) {
      /* adjust x coordinate for left/right mirroring */
      x = x - m;
   }

   /* compute which rows to draw */
   row = y-y0;
   r0 = y0 + (GLint) (row * ctx->Pixel.ZoomY);
   r1 = y0 + (GLint) ((row+1) * ctx->Pixel.ZoomY);
   if (r0==r1) {
      return;
   }
   else if (r1<r0) {
      GLint rtmp = r1;
      r1 = r0;
      r0 = rtmp;
   }

   /* return early if r0...r1 is above or below window */
   if (r0<0 && r1<0) {
      /* below window */
      return;
   }
   if (r0>=ctx->Buffer->Height && r1>=ctx->Buffer->Height) {
      /* above window */
      return;
   }

   /* check if left edge is outside window */
   skipcol = 0;
   if (x<0) {
      skipcol = -x;
      m += x;
   }
   /* make sure span isn't too long or short */
   if (m>maxwidth) {
      m = maxwidth;
   }
   else if (m<=0) {
      return;
   }

   assert( m <= MAX_WIDTH );

   /* zoom the span horizontally */
   if (ctx->Pixel.ZoomX==-1.0F) {
      /* n==m */
      for (j=0;j<m;j++) {
         i = n - (j+skipcol) - 1;
         zred[j]   = red[i];
         zgreen[j] = green[i];
         zblue[j]  = blue[i];
         zalpha[j] = alpha[i];
         zdepth[j] = z[i];
      }
   }
   else {
      GLfloat xscale = 1.0F / ctx->Pixel.ZoomX;
      for (j=0;j<m;j++) {
         i = (j+skipcol) * xscale;
         if (i<0)  i = n + i - 1;
         zred[j]   = red[i];
         zgreen[j] = green[i];
         zblue[j]  = blue[i];
         zalpha[j] = alpha[i];
         zdepth[j] = z[i];
      }
   }

   /* write the span */
   for (r=r0; r<r1; r++) {
      gl_write_color_span( ctx, m, x+skipcol, r, zdepth,
                           zred, zgreen, zblue, zalpha, GL_BITMAP );
   }
}

void
gl_write_zoomed_index_span( GLcontext *ctx,
                            GLuint n, GLint x, GLint y, const GLdepth z[],
                            const GLuint indexes[], GLint y0 )
{
   GLint m;
   GLint r0, r1, row, r;
   GLint i, j, skipcol;
   GLuint zindexes[MAX_WIDTH];  /* zoomed color indexes */
   GLdepth zdepth[MAX_WIDTH];  /* zoomed depth values */
   GLint maxwidth = MIN2( ctx->Buffer->Width, MAX_WIDTH );

   /* compute width of output row */
   m = (GLint) ABSF( n * ctx->Pixel.ZoomX );
   if (m==0) {
      return;
   }
   if (ctx->Pixel.ZoomX<0.0) {
      /* adjust x coordinate for left/right mirroring */
      x = x - m;
   }

   /* compute which rows to draw */
   row = y-y0;
   r0 = y0 + (GLint) (row * ctx->Pixel.ZoomY);
   r1 = y0 + (GLint) ((row+1) * ctx->Pixel.ZoomY);
   if (r0==r1) {
      return;
   }
   else if (r1<r0) {
      GLint rtmp = r1;
      r1 = r0;
      r0 = rtmp;
   }

   /* return early if r0...r1 is above or below window */
   if (r0<0 && r1<0) {
      /* below window */
      return;
   }
   if (r0>=ctx->Buffer->Height && r1>=ctx->Buffer->Height) {
      /* above window */
      return;
   }

   /* check if left edge is outside window */
   skipcol = 0;
   if (x<0) {
      skipcol = -x;
      m += x;
   }
   /* make sure span isn't too long or short */
   if (m>maxwidth) {
      m = maxwidth;
   }
   else if (m<=0) {
      return;
   }

   assert( m <= MAX_WIDTH );

   /* zoom the span horizontally */
   if (ctx->Pixel.ZoomX==-1.0F) {
      /* n==m */
      for (j=0;j<m;j++) {
         i = n - (j+skipcol) - 1;
         zindexes[j] = indexes[i];
         zdepth[j]   = z[i];
      }
   }
   else {
      GLfloat xscale = 1.0F / ctx->Pixel.ZoomX;
      for (j=0;j<m;j++) {
         i = (j+skipcol) * xscale;
         if (i<0)  i = n + i - 1;
         zindexes[j] = indexes[i];
         zdepth[j] = z[i];
      }
   }

   /* write the span */
   for (r=r0; r<r1; r++) {
      gl_write_index_span( ctx, m, x+skipcol, r, zdepth, zindexes, GL_BITMAP );
   }
}

void
gl_write_zoomed_stencil_span( GLcontext *ctx,
                              GLuint n, GLint x, GLint y,
                              const GLubyte stencil[], GLint y0 )
{
   GLint m;
   GLint r0, r1, row, r;
   GLint i, j, skipcol;
   GLubyte zstencil[MAX_WIDTH];  /* zoomed stencil values */
   GLint maxwidth = MIN2( ctx->Buffer->Width, MAX_WIDTH );

   /* compute width of output row */
   m = (GLint) ABSF( n * ctx->Pixel.ZoomX );
   if (m==0) {
      return;
   }
   if (ctx->Pixel.ZoomX<0.0) {
      /* adjust x coordinate for left/right mirroring */
      x = x - m;
   }

   /* compute which rows to draw */
   row = y-y0;
   r0 = y0 + (GLint) (row * ctx->Pixel.ZoomY);
   r1 = y0 + (GLint) ((row+1) * ctx->Pixel.ZoomY);
   if (r0==r1) {
      return;
   }
   else if (r1<r0) {
      GLint rtmp = r1;
      r1 = r0;
      r0 = rtmp;
   }

   /* return early if r0...r1 is above or below window */
   if (r0<0 && r1<0) {
      /* below window */
      return;
   }
   if (r0>=ctx->Buffer->Height && r1>=ctx->Buffer->Height) {
      /* above window */
      return;
   }

   /* check if left edge is outside window */
   skipcol = 0;
   if (x<0) {
      skipcol = -x;
      m += x;
   }
   /* make sure span isn't too long or short */
   if (m>maxwidth) {
      m = maxwidth;
   }
   else if (m<=0) {
      return;
   }

   assert( m <= MAX_WIDTH );

   /* zoom the span horizontally */
   if (ctx->Pixel.ZoomX==-1.0F) {
      /* n==m */
      for (j=0;j<m;j++) {
         i = n - (j+skipcol) - 1;
         zstencil[j] = stencil[i];
      }
   }
   else {
      GLfloat xscale = 1.0F / ctx->Pixel.ZoomX;
      for (j=0;j<m;j++) {
         i = (j+skipcol) * xscale;
         if (i<0)  i = n + i - 1;
         zstencil[j] = stencil[i];
      }
   }

   /* write the span */
   for (r=r0; r<r1; r++) {
      gl_write_stencil_span( ctx, m, x+skipcol, r, zstencil );
   }
}

void gl_PixelStorei( GLcontext *ctx, GLenum pname, GLint param )
{
   /* NOTE: this call can't be compiled into the display list */

   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glPixelStore" );
      return;
   }

   switch (pname) {
      case GL_PACK_SWAP_BYTES:
         ctx->Pack.SwapBytes = param ? GL_TRUE : GL_FALSE;
	 break;
      case GL_PACK_LSB_FIRST:
         ctx->Pack.LsbFirst = param ? GL_TRUE : GL_FALSE;
	 break;
      case GL_PACK_ROW_LENGTH:
	 if (param<0) {
	    gl_error( ctx, GL_INVALID_VALUE, "glPixelStore(param)" );
	 }
	 else {
	    ctx->Pack.RowLength = param;
	 }
	 break;
      case GL_PACK_SKIP_PIXELS:
	 if (param<0) {
	    gl_error( ctx, GL_INVALID_VALUE, "glPixelStore(param)" );
	 }
	 else {
	    ctx->Pack.SkipPixels = param;
	 }
	 break;
      case GL_PACK_SKIP_ROWS:
	 if (param<0) {
	    gl_error( ctx, GL_INVALID_VALUE, "glPixelStore(param)" );
	 }
	 else {
	    ctx->Pack.SkipRows = param;
	 }
	 break;
      case GL_PACK_ALIGNMENT:
         if (param==1 || param==2 || param==4 || param==8) {
	    ctx->Pack.Alignment = param;
	 }
	 else {
	    gl_error( ctx, GL_INVALID_VALUE, "glPixelStore(param)" );
	 }
	 break;
      case GL_UNPACK_SWAP_BYTES:
	 ctx->Unpack.SwapBytes = param ? GL_TRUE : GL_FALSE;
         break;
      case GL_UNPACK_LSB_FIRST:
	 ctx->Unpack.LsbFirst = param ? GL_TRUE : GL_FALSE;
	 break;
      case GL_UNPACK_ROW_LENGTH:
	 if (param<0) {
	    gl_error( ctx, GL_INVALID_VALUE, "glPixelStore(param)" );
	 }
	 else {
	    ctx->Unpack.RowLength = param;
	 }
	 break;
      case GL_UNPACK_SKIP_PIXELS:
	 if (param<0) {
	    gl_error( ctx, GL_INVALID_VALUE, "glPixelStore(param)" );
	 }
	 else {
	    ctx->Unpack.SkipPixels = param;
	 }
	 break;
      case GL_UNPACK_SKIP_ROWS:
	 if (param<0) {
	    gl_error( ctx, GL_INVALID_VALUE, "glPixelStore(param)" );
	 }
	 else {
	    ctx->Unpack.SkipRows = param;
	 }
	 break;
      case GL_UNPACK_ALIGNMENT:
         if (param==1 || param==2 || param==4 || param==8) {
	    ctx->Unpack.Alignment = param;
	 }
	 else {
	    gl_error( ctx, GL_INVALID_VALUE, "glPixelStore" );
	 }
	 break;
      default:
	 gl_error( ctx, GL_INVALID_ENUM, "glPixelStore" );
   }
   update_drawpixels_state( ctx );
}

void gl_PixelMapfv( GLcontext *ctx,
                    GLenum map, GLint mapsize, const GLfloat *values )
{
   GLuint i;

   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glPixelMapfv" );
      return;
   }

   if (mapsize<0 || mapsize>MAX_PIXEL_MAP_TABLE) {
      gl_error( ctx, GL_INVALID_VALUE, "glPixelMapfv(mapsize)" );
      return;
   }

   if (map>=GL_PIXEL_MAP_S_TO_S && map<=GL_PIXEL_MAP_I_TO_A) {
      /* test that mapsize is a power of two */
      GLuint p;
      GLboolean ok = GL_FALSE;
      for (p=1; p<=MAX_PIXEL_MAP_TABLE; p=p<<1) {
	 if ( (p&mapsize) == p ) {
	    ok = GL_TRUE;
	    break;
	 }
      }
      if (!ok) {
	 gl_error( ctx, GL_INVALID_VALUE, "glPixelMapfv(mapsize)" );
         return;
      }
   }

   switch (map) {
      case GL_PIXEL_MAP_S_TO_S:
         ctx->Pixel.MapStoSsize = mapsize;
         for (i=0;i<mapsize;i++) {
	    ctx->Pixel.MapStoS[i] = (GLint) values[i];
	 }
	 break;
      case GL_PIXEL_MAP_I_TO_I:
         ctx->Pixel.MapItoIsize = mapsize;
         for (i=0;i<mapsize;i++) {
	    ctx->Pixel.MapItoI[i] = (GLint) values[i];
	 }
	 break;
      case GL_PIXEL_MAP_I_TO_R:
         ctx->Pixel.MapItoRsize = mapsize;
         for (i=0;i<mapsize;i++) {
	    ctx->Pixel.MapItoR[i] = CLAMP( values[i], 0.0, 1.0 );
	 }
	 break;
      case GL_PIXEL_MAP_I_TO_G:
         ctx->Pixel.MapItoGsize = mapsize;
         for (i=0;i<mapsize;i++) {
	    ctx->Pixel.MapItoG[i] = CLAMP( values[i], 0.0, 1.0 );
	 }
	 break;
      case GL_PIXEL_MAP_I_TO_B:
         ctx->Pixel.MapItoBsize = mapsize;
         for (i=0;i<mapsize;i++) {
	    ctx->Pixel.MapItoB[i] = CLAMP( values[i], 0.0, 1.0 );
	 }
	 break;
      case GL_PIXEL_MAP_I_TO_A:
         ctx->Pixel.MapItoAsize = mapsize;
         for (i=0;i<mapsize;i++) {
	    ctx->Pixel.MapItoA[i] = CLAMP( values[i], 0.0, 1.0 );
	 }
	 break;
      case GL_PIXEL_MAP_R_TO_R:
         ctx->Pixel.MapRtoRsize = mapsize;
         for (i=0;i<mapsize;i++) {
	    ctx->Pixel.MapRtoR[i] = CLAMP( values[i], 0.0, 1.0 );
	 }
	 break;
      case GL_PIXEL_MAP_G_TO_G:
         ctx->Pixel.MapGtoGsize = mapsize;
         for (i=0;i<mapsize;i++) {
	    ctx->Pixel.MapGtoG[i] = CLAMP( values[i], 0.0, 1.0 );
	 }
	 break;
      case GL_PIXEL_MAP_B_TO_B:
         ctx->Pixel.MapBtoBsize = mapsize;
         for (i=0;i<mapsize;i++) {
	    ctx->Pixel.MapBtoB[i] = CLAMP( values[i], 0.0, 1.0 );
	 }
	 break;
      case GL_PIXEL_MAP_A_TO_A:
         ctx->Pixel.MapAtoAsize = mapsize;
         for (i=0;i<mapsize;i++) {
	    ctx->Pixel.MapAtoA[i] = CLAMP( values[i], 0.0, 1.0 );
	 }
	 break;
      default:
         gl_error( ctx, GL_INVALID_ENUM, "glPixelMapfv(map)" );
   }
}

void gl_GetPixelMapfv( GLcontext *ctx, GLenum map, GLfloat *values )
{
   GLuint i;

   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glGetPixelMapfv" );
      return;
   }
   switch (map) {
      case GL_PIXEL_MAP_I_TO_I:
         for (i=0;i<ctx->Pixel.MapItoIsize;i++) {
	    values[i] = (GLfloat) ctx->Pixel.MapItoI[i];
	 }
	 break;
      case GL_PIXEL_MAP_S_TO_S:
         for (i=0;i<ctx->Pixel.MapStoSsize;i++) {
	    values[i] = (GLfloat) ctx->Pixel.MapStoS[i];
	 }
	 break;
      case GL_PIXEL_MAP_I_TO_R:
         MEMCPY(values,ctx->Pixel.MapItoR,ctx->Pixel.MapItoRsize*sizeof(GLfloat));
	 break;
      case GL_PIXEL_MAP_I_TO_G:
         MEMCPY(values,ctx->Pixel.MapItoG,ctx->Pixel.MapItoGsize*sizeof(GLfloat));
	 break;
      case GL_PIXEL_MAP_I_TO_B:
         MEMCPY(values,ctx->Pixel.MapItoB,ctx->Pixel.MapItoBsize*sizeof(GLfloat));
	 break;
      case GL_PIXEL_MAP_I_TO_A:
         MEMCPY(values,ctx->Pixel.MapItoA,ctx->Pixel.MapItoAsize*sizeof(GLfloat));
	 break;
      case GL_PIXEL_MAP_R_TO_R:
         MEMCPY(values,ctx->Pixel.MapRtoR,ctx->Pixel.MapRtoRsize*sizeof(GLfloat));
	 break;
      case GL_PIXEL_MAP_G_TO_G:
         MEMCPY(values,ctx->Pixel.MapGtoG,ctx->Pixel.MapGtoGsize*sizeof(GLfloat));
	 break;
      case GL_PIXEL_MAP_B_TO_B:
         MEMCPY(values,ctx->Pixel.MapBtoB,ctx->Pixel.MapBtoBsize*sizeof(GLfloat));
	 break;
      case GL_PIXEL_MAP_A_TO_A:
         MEMCPY(values,ctx->Pixel.MapAtoA,ctx->Pixel.MapAtoAsize*sizeof(GLfloat));
	 break;
      default:
         gl_error( ctx, GL_INVALID_ENUM, "glGetPixelMapfv" );
   }
}

void gl_GetPixelMapuiv( GLcontext *ctx, GLenum map, GLuint *values )
{
   GLuint i;

   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glGetPixelMapfv" );
      return;
   }
   switch (map) {
      case GL_PIXEL_MAP_I_TO_I:
         MEMCPY(values, ctx->Pixel.MapItoI, ctx->Pixel.MapItoIsize*sizeof(GLint));
	 break;
      case GL_PIXEL_MAP_S_TO_S:
         MEMCPY(values, ctx->Pixel.MapStoS, ctx->Pixel.MapStoSsize*sizeof(GLint));
	 break;
      case GL_PIXEL_MAP_I_TO_R:
	 for (i=0;i<ctx->Pixel.MapItoRsize;i++) {
	    values[i] = FLOAT_TO_UINT( ctx->Pixel.MapItoR[i] );
	 }
	 break;
      case GL_PIXEL_MAP_I_TO_G:
	 for (i=0;i<ctx->Pixel.MapItoGsize;i++) {
	    values[i] = FLOAT_TO_UINT( ctx->Pixel.MapItoG[i] );
	 }
	 break;
      case GL_PIXEL_MAP_I_TO_B:
	 for (i=0;i<ctx->Pixel.MapItoBsize;i++) {
	    values[i] = FLOAT_TO_UINT( ctx->Pixel.MapItoB[i] );
	 }
	 break;
      case GL_PIXEL_MAP_I_TO_A:
	 for (i=0;i<ctx->Pixel.MapItoAsize;i++) {
	    values[i] = FLOAT_TO_UINT( ctx->Pixel.MapItoA[i] );
	 }
	 break;
      case GL_PIXEL_MAP_R_TO_R:
	 for (i=0;i<ctx->Pixel.MapRtoRsize;i++) {
	    values[i] = FLOAT_TO_UINT( ctx->Pixel.MapRtoR[i] );
	 }
	 break;
      case GL_PIXEL_MAP_G_TO_G:
	 for (i=0;i<ctx->Pixel.MapGtoGsize;i++) {
	    values[i] = FLOAT_TO_UINT( ctx->Pixel.MapGtoG[i] );
	 }
	 break;
      case GL_PIXEL_MAP_B_TO_B:
	 for (i=0;i<ctx->Pixel.MapBtoBsize;i++) {
	    values[i] = FLOAT_TO_UINT( ctx->Pixel.MapBtoB[i] );
	 }
	 break;
      case GL_PIXEL_MAP_A_TO_A:
	 for (i=0;i<ctx->Pixel.MapAtoAsize;i++) {
	    values[i] = FLOAT_TO_UINT( ctx->Pixel.MapAtoA[i] );
	 }
	 break;
      default:
         gl_error( ctx, GL_INVALID_ENUM, "glGetPixelMapfv" );
   }
}

void gl_GetPixelMapusv( GLcontext *ctx, GLenum map, GLushort *values )
{
   GLuint i;

   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glGetPixelMapfv" );
      return;
   }
   switch (map) {
      case GL_PIXEL_MAP_I_TO_I:
	 for (i=0;i<ctx->Pixel.MapItoIsize;i++) {
	    values[i] = (GLushort) ctx->Pixel.MapItoI[i];
	 }
	 break;
      case GL_PIXEL_MAP_S_TO_S:
	 for (i=0;i<ctx->Pixel.MapStoSsize;i++) {
	    values[i] = (GLushort) ctx->Pixel.MapStoS[i];
	 }
	 break;
      case GL_PIXEL_MAP_I_TO_R:
	 for (i=0;i<ctx->Pixel.MapItoRsize;i++) {
	    values[i] = FLOAT_TO_USHORT( ctx->Pixel.MapItoR[i] );
	 }
	 break;
      case GL_PIXEL_MAP_I_TO_G:
	 for (i=0;i<ctx->Pixel.MapItoGsize;i++) {
	    values[i] = FLOAT_TO_USHORT( ctx->Pixel.MapItoG[i] );
	 }
	 break;
      case GL_PIXEL_MAP_I_TO_B:
	 for (i=0;i<ctx->Pixel.MapItoBsize;i++) {
	    values[i] = FLOAT_TO_USHORT( ctx->Pixel.MapItoB[i] );
	 }
	 break;
      case GL_PIXEL_MAP_I_TO_A:
	 for (i=0;i<ctx->Pixel.MapItoAsize;i++) {
	    values[i] = FLOAT_TO_USHORT( ctx->Pixel.MapItoA[i] );
	 }
	 break;
      case GL_PIXEL_MAP_R_TO_R:
	 for (i=0;i<ctx->Pixel.MapRtoRsize;i++) {
	    values[i] = FLOAT_TO_USHORT( ctx->Pixel.MapRtoR[i] );
	 }
	 break;
      case GL_PIXEL_MAP_G_TO_G:
	 for (i=0;i<ctx->Pixel.MapGtoGsize;i++) {
	    values[i] = FLOAT_TO_USHORT( ctx->Pixel.MapGtoG[i] );
	 }
	 break;
      case GL_PIXEL_MAP_B_TO_B:
	 for (i=0;i<ctx->Pixel.MapBtoBsize;i++) {
	    values[i] = FLOAT_TO_USHORT( ctx->Pixel.MapBtoB[i] );
	 }
	 break;
      case GL_PIXEL_MAP_A_TO_A:
	 for (i=0;i<ctx->Pixel.MapAtoAsize;i++) {
	    values[i] = FLOAT_TO_USHORT( ctx->Pixel.MapAtoA[i] );
	 }
	 break;
      default:
         gl_error( ctx, GL_INVALID_ENUM, "glGetPixelMapfv" );
   }
}

void gl_PixelTransferf( GLcontext *ctx, GLenum pname, GLfloat param )
{
   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glPixelTransfer" );
      return;
   }

   switch (pname) {
      case GL_MAP_COLOR:
         ctx->Pixel.MapColorFlag = param ? GL_TRUE : GL_FALSE;
	 break;
      case GL_MAP_STENCIL:
         ctx->Pixel.MapStencilFlag = param ? GL_TRUE : GL_FALSE;
	 break;
      case GL_INDEX_SHIFT:
         ctx->Pixel.IndexShift = (GLint) param;
	 break;
      case GL_INDEX_OFFSET:
         ctx->Pixel.IndexOffset = (GLint) param;
	 break;
      case GL_RED_SCALE:
         ctx->Pixel.RedScale = param;
	 break;
      case GL_RED_BIAS:
         ctx->Pixel.RedBias = param;
	 break;
      case GL_GREEN_SCALE:
         ctx->Pixel.GreenScale = param;
	 break;
      case GL_GREEN_BIAS:
         ctx->Pixel.GreenBias = param;
	 break;
      case GL_BLUE_SCALE:
         ctx->Pixel.BlueScale = param;
	 break;
      case GL_BLUE_BIAS:
         ctx->Pixel.BlueBias = param;
	 break;
      case GL_ALPHA_SCALE:
         ctx->Pixel.AlphaScale = param;
	 break;
      case GL_ALPHA_BIAS:
         ctx->Pixel.AlphaBias = param;
	 break;
      case GL_DEPTH_SCALE:
         ctx->Pixel.DepthScale = param;
	 break;
      case GL_DEPTH_BIAS:
         ctx->Pixel.DepthBias = param;
	 break;
      default:
         gl_error( ctx, GL_INVALID_ENUM, "glPixelTransfer(pname)" );
         return;
   }
   update_drawpixels_state( ctx );
}

GLvoid *gl_unpack_pixels( GLcontext *ctx,
                          GLsizei width, GLsizei height,
                          GLenum format, GLenum type,
                          const GLvoid *pixels )
{
   GLint s, n;

   s = gl_sizeof_type( type );
   if (s<0) {
      gl_error( ctx, GL_INVALID_ENUM, "internal error in gl_unpack(type)" );
      return NULL;
   }

   n = gl_components_in_format( format );
   if (n<0) {
      gl_error( ctx, GL_INVALID_ENUM, "gl_unpack_pixels(format)" );
      return NULL;
   }

   if (type==GL_BITMAP) {
      /* BITMAP data */
      GLint bytes, i, width_in_bytes;
      GLubyte *buffer, *dst;
      GLvoid *src;

      /* Alloc dest storage */
      bytes = CEILING( width * height , 8 );
      buffer = (GLubyte *) malloc( bytes );
      if (!buffer) {
	 return NULL;
      }

      /* Copy/unpack pixel data to buffer */
      width_in_bytes = CEILING( width, 8 );
      dst = buffer;
      for (i=0;i<height;i++) {
         src = gl_pixel_addr_in_image( &ctx->Unpack, pixels, width, height,
                                       format, type, i);
         if (!src) {
            free(buffer);
            return NULL;
         }
	 MEMCPY( dst, src, width_in_bytes );
	 dst += width_in_bytes;
      }

      /* Bit flipping */
      if (ctx->Unpack.LsbFirst) {
	 gl_flip_bytes( buffer, bytes );
      }
      return (GLvoid *) buffer;
   }
   else {
      /* Non-BITMAP data */
      GLint width_in_bytes, bytes, i;
      GLubyte *buffer, *dst;
      GLvoid *src;

      width_in_bytes = width * n * s;

      /* Alloc dest storage */
      bytes = height * width_in_bytes;
      buffer = (GLubyte *) malloc( bytes );
      if (!buffer) {
	 return NULL;
      }

      /* Copy/unpack pixel data to buffer */
      dst = buffer;
      for (i=0;i<height;i++) {
         src = gl_pixel_addr_in_image( &ctx->Unpack, pixels, width, height,
                                       format, type, i);
         if (!src) {
            free(buffer);
            return NULL;
         }
	 MEMCPY( dst, src, width_in_bytes );
	 dst += width_in_bytes;
      }

      /* Byte swapping */
      if (ctx->Unpack.SwapBytes && s>1) {
	 if (s==2) {
	    gl_swap2( (GLushort *) buffer, bytes/2 );
	 }
	 else if (s==4) {
	    gl_swap4( (GLuint *) buffer, bytes/4 );
	 }
      }
      return (GLvoid *) buffer;
   }
}

