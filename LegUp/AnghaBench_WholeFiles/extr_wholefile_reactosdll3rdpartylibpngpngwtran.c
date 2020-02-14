#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned int png_uint_32 ;
typedef  int /*<<< orphan*/ * png_structrp ;
typedef  TYPE_1__* png_row_infop ;
typedef  TYPE_2__* png_const_color_8p ;
typedef  int* png_bytep ;
typedef  unsigned int png_byte ;
struct TYPE_10__ {int red; int green; int blue; int gray; int alpha; } ;
struct TYPE_9__ {int bit_depth; int channels; unsigned int width; unsigned int pixel_depth; size_t rowbytes; int color_type; } ;

/* Variables and functions */
 int PNG_COLOR_MASK_ALPHA ; 
 int PNG_COLOR_MASK_COLOR ; 
 scalar_t__ PNG_COLOR_TYPE_GRAY_ALPHA ; 
 int PNG_COLOR_TYPE_PALETTE ; 
 scalar_t__ PNG_COLOR_TYPE_RGB_ALPHA ; 
 size_t PNG_ROWBYTES (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  png_debug (int,char*) ; 
 unsigned int png_get_uint_16 (int*) ; 

__attribute__((used)) static void
png_do_pack(png_row_infop row_info, png_bytep row, png_uint_32 bit_depth)
{
   png_debug(1, "in png_do_pack");

   if (row_info->bit_depth == 8 &&
      row_info->channels == 1)
   {
      switch ((int)bit_depth)
      {
         case 1:
         {
            png_bytep sp, dp;
            int mask, v;
            png_uint_32 i;
            png_uint_32 row_width = row_info->width;

            sp = row;
            dp = row;
            mask = 0x80;
            v = 0;

            for (i = 0; i < row_width; i++)
            {
               if (*sp != 0)
                  v |= mask;

               sp++;

               if (mask > 1)
                  mask >>= 1;

               else
               {
                  mask = 0x80;
                  *dp = (png_byte)v;
                  dp++;
                  v = 0;
               }
            }

            if (mask != 0x80)
               *dp = (png_byte)v;

            break;
         }

         case 2:
         {
            png_bytep sp, dp;
            unsigned int shift;
            int v;
            png_uint_32 i;
            png_uint_32 row_width = row_info->width;

            sp = row;
            dp = row;
            shift = 6;
            v = 0;

            for (i = 0; i < row_width; i++)
            {
               png_byte value;

               value = (png_byte)(*sp & 0x03);
               v |= (value << shift);

               if (shift == 0)
               {
                  shift = 6;
                  *dp = (png_byte)v;
                  dp++;
                  v = 0;
               }

               else
                  shift -= 2;

               sp++;
            }

            if (shift != 6)
               *dp = (png_byte)v;

            break;
         }

         case 4:
         {
            png_bytep sp, dp;
            unsigned int shift;
            int v;
            png_uint_32 i;
            png_uint_32 row_width = row_info->width;

            sp = row;
            dp = row;
            shift = 4;
            v = 0;

            for (i = 0; i < row_width; i++)
            {
               png_byte value;

               value = (png_byte)(*sp & 0x0f);
               v |= (value << shift);

               if (shift == 0)
               {
                  shift = 4;
                  *dp = (png_byte)v;
                  dp++;
                  v = 0;
               }

               else
                  shift -= 4;

               sp++;
            }

            if (shift != 4)
               *dp = (png_byte)v;

            break;
         }

         default:
            break;
      }

      row_info->bit_depth = (png_byte)bit_depth;
      row_info->pixel_depth = (png_byte)(bit_depth * row_info->channels);
      row_info->rowbytes = PNG_ROWBYTES(row_info->pixel_depth,
          row_info->width);
   }
}

__attribute__((used)) static void
png_do_shift(png_row_infop row_info, png_bytep row,
    png_const_color_8p bit_depth)
{
   png_debug(1, "in png_do_shift");

   if (row_info->color_type != PNG_COLOR_TYPE_PALETTE)
   {
      int shift_start[4], shift_dec[4];
      unsigned int channels = 0;

      if ((row_info->color_type & PNG_COLOR_MASK_COLOR) != 0)
      {
         shift_start[channels] = row_info->bit_depth - bit_depth->red;
         shift_dec[channels] = bit_depth->red;
         channels++;

         shift_start[channels] = row_info->bit_depth - bit_depth->green;
         shift_dec[channels] = bit_depth->green;
         channels++;

         shift_start[channels] = row_info->bit_depth - bit_depth->blue;
         shift_dec[channels] = bit_depth->blue;
         channels++;
      }

      else
      {
         shift_start[channels] = row_info->bit_depth - bit_depth->gray;
         shift_dec[channels] = bit_depth->gray;
         channels++;
      }

      if ((row_info->color_type & PNG_COLOR_MASK_ALPHA) != 0)
      {
         shift_start[channels] = row_info->bit_depth - bit_depth->alpha;
         shift_dec[channels] = bit_depth->alpha;
         channels++;
      }

      /* With low row depths, could only be grayscale, so one channel */
      if (row_info->bit_depth < 8)
      {
         png_bytep bp = row;
         size_t i;
         unsigned int mask;
         size_t row_bytes = row_info->rowbytes;

         if (bit_depth->gray == 1 && row_info->bit_depth == 2)
            mask = 0x55;

         else if (row_info->bit_depth == 4 && bit_depth->gray == 3)
            mask = 0x11;

         else
            mask = 0xff;

         for (i = 0; i < row_bytes; i++, bp++)
         {
            int j;
            unsigned int v, out;

            v = *bp;
            out = 0;

            for (j = shift_start[0]; j > -shift_dec[0]; j -= shift_dec[0])
            {
               if (j > 0)
                  out |= v << j;

               else
                  out |= (v >> (-j)) & mask;
            }

            *bp = (png_byte)(out & 0xff);
         }
      }

      else if (row_info->bit_depth == 8)
      {
         png_bytep bp = row;
         png_uint_32 i;
         png_uint_32 istop = channels * row_info->width;

         for (i = 0; i < istop; i++, bp++)
         {
            unsigned int c = i%channels;
            int j;
            unsigned int v, out;

            v = *bp;
            out = 0;

            for (j = shift_start[c]; j > -shift_dec[c]; j -= shift_dec[c])
            {
               if (j > 0)
                  out |= v << j;

               else
                  out |= v >> (-j);
            }

            *bp = (png_byte)(out & 0xff);
         }
      }

      else
      {
         png_bytep bp;
         png_uint_32 i;
         png_uint_32 istop = channels * row_info->width;

         for (bp = row, i = 0; i < istop; i++)
         {
            unsigned int c = i%channels;
            int j;
            unsigned int value, v;

            v = png_get_uint_16(bp);
            value = 0;

            for (j = shift_start[c]; j > -shift_dec[c]; j -= shift_dec[c])
            {
               if (j > 0)
                  value |= v << j;

               else
                  value |= v >> (-j);
            }
            *bp++ = (png_byte)((value >> 8) & 0xff);
            *bp++ = (png_byte)(value & 0xff);
         }
      }
   }
}

__attribute__((used)) static void
png_do_write_swap_alpha(png_row_infop row_info, png_bytep row)
{
   png_debug(1, "in png_do_write_swap_alpha");

   {
      if (row_info->color_type == PNG_COLOR_TYPE_RGB_ALPHA)
      {
         if (row_info->bit_depth == 8)
         {
            /* This converts from ARGB to RGBA */
            png_bytep sp, dp;
            png_uint_32 i;
            png_uint_32 row_width = row_info->width;

            for (i = 0, sp = dp = row; i < row_width; i++)
            {
               png_byte save = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = save;
            }
         }

#ifdef PNG_WRITE_16BIT_SUPPORTED
         else
         {
            /* This converts from AARRGGBB to RRGGBBAA */
            png_bytep sp, dp;
            png_uint_32 i;
            png_uint_32 row_width = row_info->width;

            for (i = 0, sp = dp = row; i < row_width; i++)
            {
               png_byte save[2];
               save[0] = *(sp++);
               save[1] = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = save[0];
               *(dp++) = save[1];
            }
         }
#endif /* WRITE_16BIT */
      }

      else if (row_info->color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
      {
         if (row_info->bit_depth == 8)
         {
            /* This converts from AG to GA */
            png_bytep sp, dp;
            png_uint_32 i;
            png_uint_32 row_width = row_info->width;

            for (i = 0, sp = dp = row; i < row_width; i++)
            {
               png_byte save = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = save;
            }
         }

#ifdef PNG_WRITE_16BIT_SUPPORTED
         else
         {
            /* This converts from AAGG to GGAA */
            png_bytep sp, dp;
            png_uint_32 i;
            png_uint_32 row_width = row_info->width;

            for (i = 0, sp = dp = row; i < row_width; i++)
            {
               png_byte save[2];
               save[0] = *(sp++);
               save[1] = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = save[0];
               *(dp++) = save[1];
            }
         }
#endif /* WRITE_16BIT */
      }
   }
}

__attribute__((used)) static void
png_do_write_invert_alpha(png_row_infop row_info, png_bytep row)
{
   png_debug(1, "in png_do_write_invert_alpha");

   {
      if (row_info->color_type == PNG_COLOR_TYPE_RGB_ALPHA)
      {
         if (row_info->bit_depth == 8)
         {
            /* This inverts the alpha channel in RGBA */
            png_bytep sp, dp;
            png_uint_32 i;
            png_uint_32 row_width = row_info->width;

            for (i = 0, sp = dp = row; i < row_width; i++)
            {
               /* Does nothing
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               */
               sp+=3; dp = sp;
               *dp = (png_byte)(255 - *(sp++));
            }
         }

#ifdef PNG_WRITE_16BIT_SUPPORTED
         else
         {
            /* This inverts the alpha channel in RRGGBBAA */
            png_bytep sp, dp;
            png_uint_32 i;
            png_uint_32 row_width = row_info->width;

            for (i = 0, sp = dp = row; i < row_width; i++)
            {
               /* Does nothing
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               */
               sp+=6; dp = sp;
               *(dp++) = (png_byte)(255 - *(sp++));
               *dp     = (png_byte)(255 - *(sp++));
            }
         }
#endif /* WRITE_16BIT */
      }

      else if (row_info->color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
      {
         if (row_info->bit_depth == 8)
         {
            /* This inverts the alpha channel in GA */
            png_bytep sp, dp;
            png_uint_32 i;
            png_uint_32 row_width = row_info->width;

            for (i = 0, sp = dp = row; i < row_width; i++)
            {
               *(dp++) = *(sp++);
               *(dp++) = (png_byte)(255 - *(sp++));
            }
         }

#ifdef PNG_WRITE_16BIT_SUPPORTED
         else
         {
            /* This inverts the alpha channel in GGAA */
            png_bytep sp, dp;
            png_uint_32 i;
            png_uint_32 row_width = row_info->width;

            for (i = 0, sp = dp = row; i < row_width; i++)
            {
               /* Does nothing
               *(dp++) = *(sp++);
               *(dp++) = *(sp++);
               */
               sp+=2; dp = sp;
               *(dp++) = (png_byte)(255 - *(sp++));
               *dp     = (png_byte)(255 - *(sp++));
            }
         }
#endif /* WRITE_16BIT */
      }
   }
}

void /* PRIVATE */
png_do_write_transformations(png_structrp png_ptr, png_row_infop row_info)
{
   png_debug(1, "in png_do_write_transformations");

   if (png_ptr == NULL)
      return;

#ifdef PNG_WRITE_USER_TRANSFORM_SUPPORTED
   if ((png_ptr->transformations & PNG_USER_TRANSFORM) != 0)
      if (png_ptr->write_user_transform_fn != NULL)
         (*(png_ptr->write_user_transform_fn)) /* User write transform
                                                 function */
             (png_ptr,  /* png_ptr */
             row_info,  /* row_info: */
                /*  png_uint_32 width;       width of row */
                /*  size_t rowbytes;         number of bytes in row */
                /*  png_byte color_type;     color type of pixels */
                /*  png_byte bit_depth;      bit depth of samples */
                /*  png_byte channels;       number of channels (1-4) */
                /*  png_byte pixel_depth;    bits per pixel (depth*channels) */
             png_ptr->row_buf + 1);      /* start of pixel data for row */
#endif

#ifdef PNG_WRITE_FILLER_SUPPORTED
   if ((png_ptr->transformations & PNG_FILLER) != 0)
      png_do_strip_channel(row_info, png_ptr->row_buf + 1,
          !(png_ptr->flags & PNG_FLAG_FILLER_AFTER));
#endif

#ifdef PNG_WRITE_PACKSWAP_SUPPORTED
   if ((png_ptr->transformations & PNG_PACKSWAP) != 0)
      png_do_packswap(row_info, png_ptr->row_buf + 1);
#endif

#ifdef PNG_WRITE_PACK_SUPPORTED
   if ((png_ptr->transformations & PNG_PACK) != 0)
      png_do_pack(row_info, png_ptr->row_buf + 1,
          (png_uint_32)png_ptr->bit_depth);
#endif

#ifdef PNG_WRITE_SWAP_SUPPORTED
#  ifdef PNG_16BIT_SUPPORTED
   if ((png_ptr->transformations & PNG_SWAP_BYTES) != 0)
      png_do_swap(row_info, png_ptr->row_buf + 1);
#  endif
#endif

#ifdef PNG_WRITE_SHIFT_SUPPORTED
   if ((png_ptr->transformations & PNG_SHIFT) != 0)
      png_do_shift(row_info, png_ptr->row_buf + 1,
           &(png_ptr->shift));
#endif

#ifdef PNG_WRITE_SWAP_ALPHA_SUPPORTED
   if ((png_ptr->transformations & PNG_SWAP_ALPHA) != 0)
      png_do_write_swap_alpha(row_info, png_ptr->row_buf + 1);
#endif

#ifdef PNG_WRITE_INVERT_ALPHA_SUPPORTED
   if ((png_ptr->transformations & PNG_INVERT_ALPHA) != 0)
      png_do_write_invert_alpha(row_info, png_ptr->row_buf + 1);
#endif

#ifdef PNG_WRITE_BGR_SUPPORTED
   if ((png_ptr->transformations & PNG_BGR) != 0)
      png_do_bgr(row_info, png_ptr->row_buf + 1);
#endif

#ifdef PNG_WRITE_INVERT_SUPPORTED
   if ((png_ptr->transformations & PNG_INVERT_MONO) != 0)
      png_do_invert(row_info, png_ptr->row_buf + 1);
#endif
}

