#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_15__ {size_t width; size_t rows; int* buffer; } ;
struct TYPE_14__ {TYPE_3__* glyph; } ;
struct TYPE_11__ {scalar_t__ y; scalar_t__ x; } ;
struct TYPE_13__ {size_t bitmap_left; size_t bitmap_top; TYPE_1__ advance; TYPE_5__ bitmap; } ;
struct TYPE_12__ {scalar_t__ y; scalar_t__ x; } ;
typedef  TYPE_2__ FT_Vector ;
typedef  int /*<<< orphan*/  FT_Library ;
typedef  size_t FT_Int ;
typedef  TYPE_3__* FT_GlyphSlot ;
typedef  TYPE_4__* FT_Face ;
typedef  scalar_t__ FT_Error ;
typedef  TYPE_5__ FT_Bitmap ;

/* Variables and functions */
 int /*<<< orphan*/  FT_Done_Face (TYPE_4__*) ; 
 int /*<<< orphan*/  FT_Done_FreeType (int /*<<< orphan*/ ) ; 
 scalar_t__ FT_Init_FreeType (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FT_LOAD_RENDER ; 
 scalar_t__ FT_Load_Char (TYPE_4__*,char,int /*<<< orphan*/ ) ; 
 scalar_t__ FT_New_Face (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,TYPE_4__**) ; 
 scalar_t__ FT_Set_Char_Size (TYPE_4__*,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 size_t HEIGHT ; 
 size_t WIDTH ; 
 int* image ; 
 scalar_t__ malloc (size_t) ; 
 int /*<<< orphan*/  printError (scalar_t__) ; 
 int /*<<< orphan*/  putchar (char) ; 
 int strlen (char*) ; 

void
draw_bitmap( FT_Bitmap*  bitmap,
             FT_Int      x,
             FT_Int      y)
{
  FT_Int  i, j, p, q;
  FT_Int  x_max = x + bitmap->width;
  FT_Int  y_max = y + bitmap->rows;


  for ( i = x, p = 0; i < x_max; i++, p++ )
  {
    for ( j = y, q = 0; j < y_max; j++, q++ )
    {
      if ( i < 0      || j < 0       ||
           i >= WIDTH || j >= HEIGHT )
        continue;

      image[j*WIDTH + i] |= bitmap->buffer[q * bitmap->width + p];
    }
  }
}

void
show_image( void )
{
  int  i, j;
  int count = 0;

  for ( i = 0; i < HEIGHT; i++ )
  {
    for ( j = 0; j < WIDTH; j++ ) {
      if (image[i*WIDTH + j]) count++;
      putchar( image[i*WIDTH + j] == 0 ? ' '
                                : image[i*WIDTH + j] < 128 ? '+'
                                                           : '*' );
    }
    putchar( '\n' );
  }
}

int
main( int     argc,
      char**  argv )
{
  FT_Library    library;
  FT_Face       face;

  FT_GlyphSlot  slot;
  FT_Vector     pen;
  FT_Error      error;

  char*         filename;
  char*         text;

  double        angle;
  int           target_height;
  int           n, num_chars;

  filename      = "LiberationSansBold.ttf";                          
  text          = "w";
  num_chars     = strlen( text );
  WIDTH         = 16;
  HEIGHT        = 16;
  target_height = HEIGHT;

  image = (unsigned char*)malloc(WIDTH*HEIGHT);
  for (int x = 0; x < WIDTH; x++)
    for (int y = 0; y < HEIGHT; y++)
      image[y*WIDTH + x] = 0;

  error = FT_Init_FreeType( &library ); /* initialize library */
  if (error) printError(error);

  error = FT_New_Face( library, filename, 0, &face ); /* create face object */
  if (error) printError(error);

  error = FT_Set_Char_Size( face, 16 * 64, 0, 100, 0 ); /* set character size */
  if (error) printError(error);

  slot = face->glyph;

  pen.x = 0;
  pen.y = 0;

  for ( n = 0; n < num_chars; n++ )
  {

    /* load glyph image into the slot (erase previous one) */
    error = FT_Load_Char( face, text[n], FT_LOAD_RENDER );
    if ( error )
      continue;                 /* ignore errors */

    /* now, draw to our target surface (convert position) */
    draw_bitmap( &slot->bitmap,
                 slot->bitmap_left,
                 target_height - slot->bitmap_top );

    /* increment pen position */
    pen.x += slot->advance.x;
    pen.y += slot->advance.y;
  }

  show_image();

  FT_Done_Face    ( face );
  FT_Done_FreeType( library );

  
  return 0;
}

