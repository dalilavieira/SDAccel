#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct gl_texture_object {int PaletteSize; int PaletteIntFormat; int PaletteFormat; int /*<<< orphan*/  Palette; } ;
struct gl_image {int Width; int Components; int /*<<< orphan*/  Data; } ;
struct TYPE_14__ {struct gl_texture_object* Current2D; struct gl_texture_object* Current1D; struct gl_texture_object* Proxy2D; struct gl_texture_object* Proxy1D; } ;
struct TYPE_13__ {int /*<<< orphan*/  (* UpdateTexturePalette ) (TYPE_3__*,struct gl_texture_object*) ;} ;
struct TYPE_15__ {TYPE_2__ Texture; TYPE_1__ Driver; } ;
typedef  int /*<<< orphan*/  GLvoid ;
typedef  int /*<<< orphan*/  GLsizei ;
typedef  int GLint ;
typedef  scalar_t__ GLfloat ;
typedef  int GLenum ;
typedef  TYPE_3__ GLcontext ;
typedef  scalar_t__ GLboolean ;

/* Variables and functions */
#define  GL_ALPHA 178 
#define  GL_ALPHA12 177 
#define  GL_ALPHA16 176 
#define  GL_ALPHA4 175 
#define  GL_ALPHA8 174 
#define  GL_COLOR_TABLE_ALPHA_SIZE_EXT 173 
#define  GL_COLOR_TABLE_BLUE_SIZE_EXT 172 
#define  GL_COLOR_TABLE_FORMAT_EXT 171 
#define  GL_COLOR_TABLE_GREEN_SIZE_EXT 170 
#define  GL_COLOR_TABLE_INTENSITY_SIZE_EXT 169 
#define  GL_COLOR_TABLE_LUMINANCE_SIZE_EXT 168 
#define  GL_COLOR_TABLE_RED_SIZE_EXT 167 
#define  GL_COLOR_TABLE_WIDTH_EXT 166 
 scalar_t__ GL_FALSE ; 
#define  GL_INTENSITY 165 
#define  GL_INTENSITY12 164 
#define  GL_INTENSITY16 163 
#define  GL_INTENSITY4 162 
#define  GL_INTENSITY8 161 
 int /*<<< orphan*/  GL_INVALID_ENUM ; 
 int /*<<< orphan*/  GL_INVALID_OPERATION ; 
 int /*<<< orphan*/  GL_INVALID_VALUE ; 
#define  GL_LUMINANCE 160 
#define  GL_LUMINANCE12 159 
#define  GL_LUMINANCE12_ALPHA12 158 
#define  GL_LUMINANCE12_ALPHA4 157 
#define  GL_LUMINANCE16 156 
#define  GL_LUMINANCE16_ALPHA16 155 
#define  GL_LUMINANCE4 154 
#define  GL_LUMINANCE4_ALPHA4 153 
#define  GL_LUMINANCE6_ALPHA2 152 
#define  GL_LUMINANCE8 151 
#define  GL_LUMINANCE8_ALPHA8 150 
#define  GL_LUMINANCE_ALPHA 149 
#define  GL_PROXY_TEXTURE_1D 148 
#define  GL_PROXY_TEXTURE_2D 147 
#define  GL_R3_G3_B2 146 
#define  GL_RGB 145 
#define  GL_RGB10 144 
#define  GL_RGB10_A2 143 
#define  GL_RGB12 142 
#define  GL_RGB16 141 
#define  GL_RGB4 140 
#define  GL_RGB5 139 
#define  GL_RGB5_A1 138 
#define  GL_RGB8 137 
#define  GL_RGBA 136 
#define  GL_RGBA12 135 
#define  GL_RGBA16 134 
#define  GL_RGBA2 133 
#define  GL_RGBA4 132 
#define  GL_RGBA8 131 
#define  GL_TEXTURE_1D 130 
#define  GL_TEXTURE_2D 129 
#define  GL_TEXTURE_3D_EXT 128 
 scalar_t__ GL_TRUE ; 
 scalar_t__ INSIDE_BEGIN_END (TYPE_3__*) ; 
 int MAX_TEXTURE_PALETTE_SIZE ; 
 int /*<<< orphan*/  MEMCPY (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 void gl_GetColorTableParameteriv (TYPE_3__*,int,int,int*) ; 
 int /*<<< orphan*/  gl_error (TYPE_3__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gl_problem (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  stub1 (TYPE_3__*,struct gl_texture_object*) ; 

__attribute__((used)) static GLboolean power_of_two( GLint k )
{
   GLint i, m = 1;
   for (i=0; i<32; i++) {
      if (k == m)
         return GL_TRUE;
      m = m << 1;
   }
   return GL_FALSE;
}

__attribute__((used)) static GLint decode_internal_format( GLint format )
{
   switch (format) {
      case GL_ALPHA:
      case GL_ALPHA4:
      case GL_ALPHA8:
      case GL_ALPHA12:
      case GL_ALPHA16:
         return GL_ALPHA;
      case 1:
      case GL_LUMINANCE:
      case GL_LUMINANCE4:
      case GL_LUMINANCE8:
      case GL_LUMINANCE12:
      case GL_LUMINANCE16:
         return GL_LUMINANCE;
      case 2:
      case GL_LUMINANCE_ALPHA:
      case GL_LUMINANCE4_ALPHA4:
      case GL_LUMINANCE6_ALPHA2:
      case GL_LUMINANCE8_ALPHA8:
      case GL_LUMINANCE12_ALPHA4:
      case GL_LUMINANCE12_ALPHA12:
      case GL_LUMINANCE16_ALPHA16:
         return GL_LUMINANCE_ALPHA;
      case GL_INTENSITY:
      case GL_INTENSITY4:
      case GL_INTENSITY8:
      case GL_INTENSITY12:
      case GL_INTENSITY16:
         return GL_INTENSITY;
      case 3:
      case GL_RGB:
      case GL_R3_G3_B2:
      case GL_RGB4:
      case GL_RGB5:
      case GL_RGB8:
      case GL_RGB10:
      case GL_RGB12:
      case GL_RGB16:
         return GL_RGB;
      case 4:
      case GL_RGBA:
      case GL_RGBA2:
      case GL_RGBA4:
      case GL_RGB5_A1:
      case GL_RGBA8:
      case GL_RGB10_A2:
      case GL_RGBA12:
      case GL_RGBA16:
         return GL_RGBA;
      default:
         return -1;  /* error */
   }
}

void gl_ColorTable( GLcontext *ctx, GLenum target,
                    GLenum internalFormat, struct gl_image *table )
{
   struct gl_texture_object *texObj;
   GLboolean proxy = GL_FALSE;

   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glGetBooleanv" );
      return;
   }

   switch (target) {
      case GL_TEXTURE_1D:
         texObj = ctx->Texture.Current1D;
         break;
      case GL_TEXTURE_2D:
         texObj = ctx->Texture.Current2D;
         break;
      case GL_PROXY_TEXTURE_1D:
         texObj = ctx->Texture.Proxy1D;
         proxy = GL_TRUE;
         break;
      case GL_PROXY_TEXTURE_2D:
         texObj = ctx->Texture.Proxy2D;
         proxy = GL_TRUE;
         break;
      default:
         gl_error(ctx, GL_INVALID_ENUM, "glColorTableEXT(target)");
         return;
   }

   /* internalformat = just like glTexImage */

   if (table->Width < 1 || table->Width > MAX_TEXTURE_PALETTE_SIZE
       || !power_of_two(table->Width)) {
      gl_error(ctx, GL_INVALID_VALUE, "glColorTableEXT(width)");
      if (proxy) {
         texObj->PaletteSize = 0;
         texObj->PaletteIntFormat = 0;
         texObj->PaletteFormat = 0;
      }
      return;
   }

  /* per-texture object palette */
  texObj->PaletteSize = table->Width;
  texObj->PaletteIntFormat = internalFormat;
  texObj->PaletteFormat = decode_internal_format(internalFormat);
  if (!proxy) {
     MEMCPY(texObj->Palette, table->Data, table->Width*table->Components);
     if (ctx->Driver.UpdateTexturePalette) {
        (*ctx->Driver.UpdateTexturePalette)( ctx, texObj );
     }
   }
}

void gl_ColorSubTable( GLcontext *ctx, GLenum target,
                       GLsizei start, struct gl_image *data )
{
   /* XXX TODO */
   gl_problem(ctx, "glColorSubTableEXT not implemented");
}

void gl_GetColorTable( GLcontext *ctx, GLenum target, GLenum format,
                       GLenum type, GLvoid *table )
{
   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glGetBooleanv" );
      return;
   }

   switch (target) {
      case GL_TEXTURE_1D:
         break;
      case GL_TEXTURE_2D:
         break;
      case GL_TEXTURE_3D_EXT:
         break;
      default:
         gl_error(ctx, GL_INVALID_ENUM, "glGetColorTableEXT(target)");
         return;
   }

   gl_problem(ctx, "glGetColorTableEXT not implemented!");
}

void gl_GetColorTableParameterfv( GLcontext *ctx, GLenum target,
                                  GLenum pname, GLfloat *params )
{
   GLint iparams[10];

   gl_GetColorTableParameteriv( ctx, target, pname, iparams );
   *params = (GLfloat) iparams[0];
}

void gl_GetColorTableParameteriv( GLcontext *ctx, GLenum target,
                                  GLenum pname, GLint *params )
{
   struct gl_texture_object *texObj;

   if (INSIDE_BEGIN_END(ctx)) {
      gl_error( ctx, GL_INVALID_OPERATION, "glGetColorTableParameter" );
      return;
   }

   switch (target) {
      case GL_TEXTURE_1D:
         texObj = ctx->Texture.Current1D;
         break;
      case GL_TEXTURE_2D:
         texObj = ctx->Texture.Current2D;
         break;
      default:
         gl_error(ctx, GL_INVALID_ENUM, "glGetColorTableParameter(target)");
         return;
   }

   switch (pname) {
      case GL_COLOR_TABLE_FORMAT_EXT:
         if (texObj)
            *params = texObj->PaletteIntFormat;
         break;
      case GL_COLOR_TABLE_WIDTH_EXT:
         if (texObj)
            *params = texObj->PaletteSize;
         break;
      case GL_COLOR_TABLE_RED_SIZE_EXT:
         *params = 8;
         break;
      case GL_COLOR_TABLE_GREEN_SIZE_EXT:
         *params = 8;
         break;
      case GL_COLOR_TABLE_BLUE_SIZE_EXT:
         *params = 8;
         break;
      case GL_COLOR_TABLE_ALPHA_SIZE_EXT:
         *params = 8;
         break;
      case GL_COLOR_TABLE_LUMINANCE_SIZE_EXT:
         *params = 8;
         break;
      case GL_COLOR_TABLE_INTENSITY_SIZE_EXT:
         *params = 8;
         break;
      default:
         gl_error(ctx, GL_INVALID_ENUM, "glGetColorTableParameter" );
         return;
   }
}

