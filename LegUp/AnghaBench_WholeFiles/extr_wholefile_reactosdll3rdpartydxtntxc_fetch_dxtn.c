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
typedef  int /*<<< orphan*/  GLvoid ;
typedef  int GLushort ;
typedef  int GLuint ;
typedef  int GLubyte ;
typedef  int GLint ;
typedef  scalar_t__ GLchan ;

/* Variables and functions */
 size_t ACOMP ; 
 size_t BCOMP ; 
 scalar_t__ CHAN_MAX ; 
 scalar_t__ EXP4TO8 (int const) ; 
 int EXP5TO8B (int const) ; 
 int EXP5TO8R (int const) ; 
 int EXP6TO8G (int const) ; 
 size_t GCOMP ; 
 size_t RCOMP ; 
 scalar_t__ UBYTE_TO_CHAN (int const) ; 

__attribute__((used)) static void dxt135_decode_imageblock ( const GLubyte *img_block_src,
                         GLint i, GLint j, GLuint dxt_type, GLvoid *texel ) {
   GLchan *rgba = (GLchan *) texel;
   const GLushort color0 = img_block_src[0] | (img_block_src[1] << 8);
   const GLushort color1 = img_block_src[2] | (img_block_src[3] << 8);
   const GLuint bits = img_block_src[4] | (img_block_src[5] << 8) |
      (img_block_src[6] << 16) | (img_block_src[7] << 24);
   /* What about big/little endian? */
   GLubyte bit_pos = 2 * (j * 4 + i) ;
   GLubyte code = (GLubyte) ((bits >> bit_pos) & 3);

   rgba[ACOMP] = CHAN_MAX;
   switch (code) {
   case 0:
      rgba[RCOMP] = UBYTE_TO_CHAN( EXP5TO8R(color0) );
      rgba[GCOMP] = UBYTE_TO_CHAN( EXP6TO8G(color0) );
      rgba[BCOMP] = UBYTE_TO_CHAN( EXP5TO8B(color0) );
      break;
   case 1:
      rgba[RCOMP] = UBYTE_TO_CHAN( EXP5TO8R(color1) );
      rgba[GCOMP] = UBYTE_TO_CHAN( EXP6TO8G(color1) );
      rgba[BCOMP] = UBYTE_TO_CHAN( EXP5TO8B(color1) );
      break;
   case 2:
      if ((dxt_type > 1) || (color0 > color1)) {
         rgba[RCOMP] = UBYTE_TO_CHAN( ((EXP5TO8R(color0) * 2 + EXP5TO8R(color1)) / 3) );
         rgba[GCOMP] = UBYTE_TO_CHAN( ((EXP6TO8G(color0) * 2 + EXP6TO8G(color1)) / 3) );
         rgba[BCOMP] = UBYTE_TO_CHAN( ((EXP5TO8B(color0) * 2 + EXP5TO8B(color1)) / 3) );
      }
      else {
         rgba[RCOMP] = UBYTE_TO_CHAN( ((EXP5TO8R(color0) + EXP5TO8R(color1)) / 2) );
         rgba[GCOMP] = UBYTE_TO_CHAN( ((EXP6TO8G(color0) + EXP6TO8G(color1)) / 2) );
         rgba[BCOMP] = UBYTE_TO_CHAN( ((EXP5TO8B(color0) + EXP5TO8B(color1)) / 2) );
      }
      break;
   case 3:
      if ((dxt_type > 1) || (color0 > color1)) {
         rgba[RCOMP] = UBYTE_TO_CHAN( ((EXP5TO8R(color0) + EXP5TO8R(color1) * 2) / 3) );
         rgba[GCOMP] = UBYTE_TO_CHAN( ((EXP6TO8G(color0) + EXP6TO8G(color1) * 2) / 3) );
         rgba[BCOMP] = UBYTE_TO_CHAN( ((EXP5TO8B(color0) + EXP5TO8B(color1) * 2) / 3) );
      }
      else {
         rgba[RCOMP] = 0;
         rgba[GCOMP] = 0;
         rgba[BCOMP] = 0;
         if (dxt_type == 1) rgba[ACOMP] = UBYTE_TO_CHAN(0);
      }
      break;
   default:
   /* CANNOT happen (I hope) */
      break;
   }
}

void fetch_2d_texel_rgb_dxt1(GLint srcRowStride, const GLubyte *pixdata,
                         GLint i, GLint j, GLvoid *texel)
{
   /* Extract the (i,j) pixel from pixdata and return it
    * in texel[RCOMP], texel[GCOMP], texel[BCOMP], texel[ACOMP].
    */

   const GLubyte *blksrc = (pixdata + ((srcRowStride + 3) / 4 * (j / 4) + (i / 4)) * 8);
   dxt135_decode_imageblock(blksrc, (i&3), (j&3), 0, texel);
}

void fetch_2d_texel_rgba_dxt1(GLint srcRowStride, const GLubyte *pixdata,
                         GLint i, GLint j, GLvoid *texel)
{
   /* Extract the (i,j) pixel from pixdata and return it
    * in texel[RCOMP], texel[GCOMP], texel[BCOMP], texel[ACOMP].
    */

   const GLubyte *blksrc = (pixdata + ((srcRowStride + 3) / 4 * (j / 4) + (i / 4)) * 8);
   dxt135_decode_imageblock(blksrc, (i&3), (j&3), 1, texel);
}

void fetch_2d_texel_rgba_dxt3(GLint srcRowStride, const GLubyte *pixdata,
                         GLint i, GLint j, GLvoid *texel) {

   /* Extract the (i,j) pixel from pixdata and return it
    * in texel[RCOMP], texel[GCOMP], texel[BCOMP], texel[ACOMP].
    */

   GLchan *rgba = (GLchan *) texel;
   const GLubyte *blksrc = (pixdata + ((srcRowStride + 3) / 4 * (j / 4) + (i / 4)) * 16);
#if 0
   /* Simple 32bit version. */
/* that's pretty brain-dead for a single pixel, isn't it? */
   const GLubyte bit_pos = 4 * ((j&3) * 4 + (i&3));
   const GLuint alpha_low = blksrc[0] | (blksrc[1] << 8) | (blksrc[2] << 16) | (blksrc[3] << 24);
   const GLuint alpha_high = blksrc[4] | (blksrc[5] << 8) | (blksrc[6] << 16) | (blksrc[7] << 24);

   dxt135_decode_imageblock(blksrc + 8, (i&3), (j&3), 2, texel);
   if (bit_pos < 32)
      rgba[ACOMP] = UBYTE_TO_CHAN( (GLubyte)(EXP4TO8((alpha_low >> bit_pos) & 15)) );
   else
      rgba[ACOMP] = UBYTE_TO_CHAN( (GLubyte)(EXP4TO8((alpha_high >> (bit_pos - 32)) & 15)) );
#endif
#if 1
/* TODO test this! */
   const GLubyte anibble = (blksrc[((j&3) * 4 + (i&3)) / 2] >> (4 * (i&1))) & 0xf;
   dxt135_decode_imageblock(blksrc + 8, (i&3), (j&3), 2, texel);
   rgba[ACOMP] = UBYTE_TO_CHAN( (GLubyte)(EXP4TO8(anibble)) );
#endif

}

void fetch_2d_texel_rgba_dxt5(GLint srcRowStride, const GLubyte *pixdata,
                         GLint i, GLint j, GLvoid *texel) {

   /* Extract the (i,j) pixel from pixdata and return it
    * in texel[RCOMP], texel[GCOMP], texel[BCOMP], texel[ACOMP].
    */

   GLchan *rgba = (GLchan *) texel;
   const GLubyte *blksrc = (pixdata + ((srcRowStride + 3) / 4 * (j / 4) + (i / 4)) * 16);
   const GLubyte alpha0 = blksrc[0];
   const GLubyte alpha1 = blksrc[1];
#if 0
   const GLubyte bit_pos = 3 * ((j&3) * 4 + (i&3));
   /* simple 32bit version */
   const GLuint bits_low = blksrc[2] | (blksrc[3] << 8) | (blksrc[4] << 16) | (blksrc[5] << 24);
   const GLuint bits_high = blksrc[6] | (blksrc[7] << 8);
   GLubyte code;

   if (bit_pos < 30)
      code = (GLubyte) ((bits_low >> bit_pos) & 7);
   else if (bit_pos == 30)
      code = (GLubyte) ((bits_low >> 30) & 3) | ((bits_high << 2) & 4);
   else
      code = (GLubyte) ((bits_high >> (bit_pos - 32)) & 7);
#endif
#if 1
/* TODO test this! */
   const GLubyte bit_pos = ((j&3) * 4 + (i&3)) * 3;
   const GLubyte acodelow = blksrc[2 + bit_pos / 8];
   const GLubyte acodehigh = blksrc[3 + bit_pos / 8];
   const GLubyte code = (acodelow >> (bit_pos & 0x7) |
      (acodehigh  << (8 - (bit_pos & 0x7)))) & 0x7;
#endif
   dxt135_decode_imageblock(blksrc + 8, (i&3), (j&3), 2, texel);
#if 0
   if (alpha0 > alpha1) {
      switch (code) {
      case 0:
         rgba[ACOMP] = UBYTE_TO_CHAN( alpha0 );
         break;
      case 1:
         rgba[ACOMP] = UBYTE_TO_CHAN( alpha1 );
         break;
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
         rgba[ACOMP] = UBYTE_TO_CHAN( ((alpha0 * (8 - code) + (alpha1 * (code - 1))) / 7) );
         break;
      }
   }
   else {
      switch (code) {
      case 0:
         rgba[ACOMP] = UBYTE_TO_CHAN( alpha0 );
         break;
      case 1:
         rgba[ACOMP] = UBYTE_TO_CHAN( alpha1 );
         break;
      case 2:
      case 3:
      case 4:
      case 5:
         rgba[ACOMP] = UBYTE_TO_CHAN( ((alpha0 * (6 - code) + (alpha1 * (code - 1))) / 5) );
         break;
      case 6:
         rgba[ACOMP] = 0;
         break;
      case 7:
         rgba[ACOMP] = CHAN_MAX;
         break;
      }
   }
#endif
/* not sure. Which version is faster? */
#if 1
/* TODO test this */
   if (code == 0)
      rgba[ACOMP] = UBYTE_TO_CHAN( alpha0 );
   else if (code == 1)
      rgba[ACOMP] = UBYTE_TO_CHAN( alpha1 );
   else if (alpha0 > alpha1)
      rgba[ACOMP] = UBYTE_TO_CHAN( ((alpha0 * (8 - code) + (alpha1 * (code - 1))) / 7) );
   else if (code < 6)
      rgba[ACOMP] = UBYTE_TO_CHAN( ((alpha0 * (6 - code) + (alpha1 * (code - 1))) / 5) );
   else if (code == 6)
      rgba[ACOMP] = 0;
   else
      rgba[ACOMP] = CHAN_MAX;
#endif
}

