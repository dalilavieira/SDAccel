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
struct TYPE_19__ {int width; size_t rows; unsigned char* buffer; int /*<<< orphan*/  pitch; } ;
struct TYPE_18__ {TYPE_3__* glyph; } ;
struct TYPE_15__ {scalar_t__ y; scalar_t__ x; } ;
struct TYPE_17__ {size_t bitmap_left; size_t bitmap_top; TYPE_1__ advance; TYPE_5__ bitmap; } ;
struct TYPE_16__ {scalar_t__ y; scalar_t__ x; } ;
typedef  TYPE_2__ FT_Vector ;
typedef  int /*<<< orphan*/  FT_UInt ;
typedef  int /*<<< orphan*/  FT_Library ;
typedef  size_t FT_Int ;
typedef  TYPE_3__* FT_GlyphSlot ;
typedef  TYPE_4__* FT_Face ;
typedef  int FT_Error ;
typedef  TYPE_5__ FT_Bitmap ;

/* Variables and functions */
 int /*<<< orphan*/  FT_Done_Face (TYPE_4__*) ; 
 int /*<<< orphan*/  FT_Done_FreeType (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FT_Get_Char_Index (TYPE_4__*,char) ; 
 int FT_Init_FreeType (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FT_LOAD_DEFAULT ; 
 int FT_Load_Glyph (TYPE_4__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int FT_New_Face (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,TYPE_4__**) ; 
 int /*<<< orphan*/  FT_RENDER_MODE_MONO ; 
 int FT_Render_Glyph (TYPE_3__*,int /*<<< orphan*/ ) ; 
 int FT_Set_Char_Size (TYPE_4__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FT_Set_Transform (TYPE_4__*,int /*<<< orphan*/ ,TYPE_2__*) ; 
 size_t HEIGHT ; 
 size_t WIDTH ; 
 size_t atoi (char*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int* image ; 
 scalar_t__ malloc (size_t) ; 
 int* pixelData ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 int /*<<< orphan*/  putchar (char) ; 
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
  int xbyte;
  int xbit;
  unsigned char* pcur;

  unsigned char* src = bitmap->buffer;
  unsigned char* dest = pixelData;

  // Note: FT_RENDER_MONO_MODE render characater's one pixel by a single bit,
  // translate the single bit to a single char for displaying image.
  for(int _y = 0; _y < bitmap->rows; ++_y)
  {
	  for(int _x = 0; _x < bitmap->width; ++_x)
	  {	
		  xbyte = _x / 8;
		  xbit = _x - xbyte * 8;
		  pcur = dest + _x;

		  // test if the pixel bit be set
		  if(src[xbyte] & (0x80 >> xbit))
		  {
			  *pcur = 0xFF;
		  }
		  else
		  {
			  *pcur = 0;
		  }
	  }
	  src += bitmap->pitch;
	  dest += bitmap->width;
  }

  // display the character to ref txt file
  for ( i = x, p = 0; i < x_max; i++, p++ )
  {
    for ( j = y, q = 0; j < y_max; j++, q++ )
    {
      if ( i < 0      || j < 0       ||
           i >= WIDTH || j >= HEIGHT )
        continue;
		
      image[j*WIDTH + i] |= pixelData[q * bitmap->width + p];
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
                                                           : '*');
    }
    putchar('\n');
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
  FT_Error      error;
  FT_Vector     pen;                    /* untransformed origin  */
  
  char*         filename;
  char*         text;

  double        angle;
  int           target_height;
  int           n, num_chars;
  FT_UInt		glyphIndex;

  if ( argc != 6 )
  {
    fprintf ( stderr, "usage: %s font sample-text width height angle\n", argv[0] );
    exit( 1 );
  }

  filename      = argv[1];                           /* first argument     */
  text          = argv[2];          /* second argument    */
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
  error = FT_Set_Char_Size( face, 32 * 64, 0,
                            0, 0 );                /* set character size */
  if (error) printf("Set_Char_Size Error! %d\n", error);

  slot = face->glyph;
  pen.x = 0;
  pen.y = 0;
  for ( n = 0; n < num_chars; n++ )
  {
	  /* set transformation */
	  FT_Set_Transform( face, 0, &pen );

	  /* load glyph image into the slot (erase previous one) */
	  glyphIndex = FT_Get_Char_Index(face, text[n]);
	  
	  /* load glyph image into the slot (erase previous one) */
	  error = FT_Load_Glyph(face, glyphIndex, FT_LOAD_DEFAULT);
	  if(error) printf("FT_Load_Glyph Error! %d\n", error);
	  
	  error = FT_Render_Glyph(slot, FT_RENDER_MODE_MONO);
	  if(error) printf("FT_Render_Glyph Error! %d\n", error);

	  /* now, draw to our target surface (convert position) */
	  draw_bitmap(&slot->bitmap,
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

