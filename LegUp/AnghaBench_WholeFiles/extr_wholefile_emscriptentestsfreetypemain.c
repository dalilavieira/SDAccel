#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_6__ ;
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
struct TYPE_20__ {size_t width; size_t rows; int* buffer; } ;
struct TYPE_19__ {TYPE_4__* glyph; } ;
struct TYPE_15__ {scalar_t__ y; scalar_t__ x; } ;
struct TYPE_18__ {size_t bitmap_left; size_t bitmap_top; TYPE_1__ advance; TYPE_6__ bitmap; } ;
struct TYPE_17__ {void* yy; void* yx; void* xy; void* xx; } ;
struct TYPE_16__ {int x; scalar_t__ y; } ;
typedef  TYPE_2__ FT_Vector ;
typedef  TYPE_3__ FT_Matrix ;
typedef  int /*<<< orphan*/  FT_Library ;
typedef  size_t FT_Int ;
typedef  TYPE_4__* FT_GlyphSlot ;
typedef  void* FT_Fixed ;
typedef  TYPE_5__* FT_Face ;
typedef  int FT_Error ;
typedef  TYPE_6__ FT_Bitmap ;

/* Variables and functions */
 int /*<<< orphan*/  FT_Done_Face (TYPE_5__*) ; 
 int /*<<< orphan*/  FT_Done_FreeType (int /*<<< orphan*/ ) ; 
 int FT_Init_FreeType (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FT_LOAD_RENDER ; 
 int FT_Load_Char (TYPE_5__*,char,int /*<<< orphan*/ ) ; 
 int FT_New_Face (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,TYPE_5__**) ; 
 int FT_Set_Char_Size (TYPE_5__*,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FT_Set_Transform (TYPE_5__*,TYPE_3__*,TYPE_2__*) ; 
 size_t HEIGHT ; 
 size_t WIDTH ; 
 size_t atoi (char*) ; 
 int cos (double) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int* image ; 
 scalar_t__ malloc (size_t) ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 int /*<<< orphan*/  putchar (char) ; 
 int sin (double) ; 
 int /*<<< orphan*/  stderr ; 
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
  printf("Non-0s: %d\n", count);
}

int
main( int     argc,
      char**  argv )
{
  FT_Library    library;
  FT_Face       face;

  FT_GlyphSlot  slot;
  FT_Matrix     matrix;                 /* transformation matrix */
  FT_Vector     pen;                    /* untransformed origin  */
  FT_Error      error;

  char*         filename;
  char*         text;

  double        angle;
  int           target_height;
  int           n, num_chars;

  if ( argc != 6 )
  {
    fprintf ( stderr, "usage: %s font sample-text width height angle\n", argv[0] );
    exit( 1 );
  }

  filename      = argv[1];                           /* first argument     */
  text          = argv[2];                           /* second argument    */
  num_chars     = strlen( text );
  WIDTH         = atoi(argv[3]);
  HEIGHT        = atoi(argv[4]);
  angle         = ( ((float)atoi(argv[5])) / 360 ) * 3.14159 * 2;      /* use 25 degrees     */
  target_height = HEIGHT;

  image = (unsigned char*)malloc(WIDTH*HEIGHT);
  for (int x = 0; x < WIDTH; x++)
    for (int y = 0; y < HEIGHT; y++)
      image[y*WIDTH + x] = 0;

  error = FT_Init_FreeType( &library );              /* initialize library */
  if (error) printf("Init Error! %d\n", error);

  error = FT_New_Face( library, argv[1], 0, &face ); /* create face object */
  if (error) printf("New_Face Error! %d\n", error);

  /* use 50pt at 100dpi */
  error = FT_Set_Char_Size( face, 50 * 64, 0,
                            100, 0 );                /* set character size */
  if (error) printf("Set_Char_Size Error! %d\n", error);

  slot = face->glyph;

  /* set up matrix */
  matrix.xx = (FT_Fixed)( cos( angle ) * 0x10000L );
  matrix.xy = (FT_Fixed)(-sin( angle ) * 0x10000L );
  matrix.yx = (FT_Fixed)( sin( angle ) * 0x10000L );
  matrix.yy = (FT_Fixed)( cos( angle ) * 0x10000L );

  pen.x = 1000;
  pen.y = 0;

  for ( n = 0; n < num_chars; n++ )
  {
    /* set transformation */
    FT_Set_Transform( face, &matrix, &pen );

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

