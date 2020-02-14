#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  time_t ;
struct stat {int st_size; int /*<<< orphan*/  st_mode; } ;
struct fontlist {int isbinary; int isascii; int ishex; char* name; int len; } ;
struct dirent {char* d_name; } ;
typedef  void forever ;
typedef  int /*<<< orphan*/  buffer ;
struct TYPE_10__ {int /*<<< orphan*/  outline; } ;
struct TYPE_9__ {int num_glyphs; int num_faces; TYPE_4__* glyph; } ;
typedef  int /*<<< orphan*/  FT_Vector ;
typedef  int /*<<< orphan*/  FT_Library ;
typedef  TYPE_1__* FT_Face ;
typedef  int FT_F26Dot6 ;
typedef  int /*<<< orphan*/  FILE ;
typedef  int /*<<< orphan*/  DIR ;

/* Variables and functions */
 int /*<<< orphan*/  FT_Done_Face (TYPE_1__*) ; 
 scalar_t__ FT_IS_SCALABLE (TYPE_1__*) ; 
 scalar_t__ FT_Init_FreeType (int /*<<< orphan*/ *) ; 
 int FT_LOAD_DEFAULT ; 
 int FT_LOAD_NO_BITMAP ; 
 int FT_LOAD_NO_HINTING ; 
 int /*<<< orphan*/  FT_Load_Glyph (TYPE_1__*,int,int) ; 
 scalar_t__ FT_New_Face (int /*<<< orphan*/ ,char*,int,TYPE_1__**) ; 
 int /*<<< orphan*/  FT_Outline_Decompose (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FT_Render_Glyph (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FT_Set_Char_Size (TYPE_1__*,int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  SIGALRM ; 
 int /*<<< orphan*/  SIGFPE ; 
 scalar_t__ S_ISDIR (int /*<<< orphan*/ ) ; 
 scalar_t__ WIFSIGNALED (int) ; 
 int /*<<< orphan*/  alarm (int) ; 
 char** calloc (int,int) ; 
 scalar_t__ ceil (int) ; 
 int check_outlines ; 
 int child_pid ; 
 int /*<<< orphan*/  closedir (int /*<<< orphan*/ *) ; 
 char** default_dir_list ; 
 char** default_ext_list ; 
 scalar_t__ error_count ; 
 int error_fraction ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int fcnt ; 
 scalar_t__ ferror (int /*<<< orphan*/ *) ; 
 int font_size ; 
 struct fontlist* fontlist ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int fork () ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,...) ; 
 int fread (char*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fseek (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ft_render_mode_normal ; 
 int /*<<< orphan*/  fwrite (char*,int,int,int /*<<< orphan*/ *) ; 
 int getc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kill (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mkdir (char*,int) ; 
 int nohints ; 
 int /*<<< orphan*/ * opendir (char*) ; 
 int /*<<< orphan*/  outlinefuncs ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 int /*<<< orphan*/  putc (int,int /*<<< orphan*/ *) ; 
 int random () ; 
 int rasterize ; 
 struct dirent* readdir (int /*<<< orphan*/ *) ; 
 struct fontlist* realloc (struct fontlist*,int) ; 
 char* results_dir ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,void (*) (int)) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*,char*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  srandom (int /*<<< orphan*/ ) ; 
 int stat (char*,struct stat*) ; 
 int /*<<< orphan*/ * stderr ; 
 int /*<<< orphan*/ * stdout ; 
 scalar_t__ strcasecmp (char*,char*) ; 
 scalar_t__ strcmp (char*,char*) ; 
 char* strdup (char*) ; 
 char* strrchr (char*,char) ; 
 int /*<<< orphan*/ * strstr (char*,char*) ; 
 int strtod (char*,char**) ; 
 scalar_t__ strtol (char*,char**,int) ; 
 int /*<<< orphan*/  time (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  unlink (char*) ; 
 int /*<<< orphan*/  waitpid (int,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  write (int,char*,int) ; 

__attribute__((used)) static int
  FT_MoveTo( const FT_Vector  *to,
             void             *user )
  {
    return 0;
  }

__attribute__((used)) static int
  FT_LineTo( const FT_Vector  *to,
             void             *user )
  {
    return 0;
  }

__attribute__((used)) static int
  FT_ConicTo( const FT_Vector  *_cp,
              const FT_Vector  *to,
              void             *user )
  {
    return 0;
  }

__attribute__((used)) static int
  FT_CubicTo( const FT_Vector  *cp1,
              const FT_Vector  *cp2,
              const FT_Vector  *to,
              void             *user )
  {
    return 0;
  }

__attribute__((used)) static void
  TestFace( FT_Face  face )
  {
    int  gid;
    int  load_flags = FT_LOAD_DEFAULT;


    if ( check_outlines         &&
         FT_IS_SCALABLE( face ) )
      load_flags = FT_LOAD_NO_BITMAP;

    if ( nohints )
      load_flags |= FT_LOAD_NO_HINTING;

    FT_Set_Char_Size( face, 0, font_size, 72, 72 );

    for ( gid = 0; gid < face->num_glyphs; ++gid )
    {
      if ( check_outlines         &&
           FT_IS_SCALABLE( face ) )
      {
        if ( !FT_Load_Glyph( face, gid, load_flags ) )
          FT_Outline_Decompose( &face->glyph->outline, &outlinefuncs, NULL );
      }
      else
        FT_Load_Glyph( face, gid, load_flags );

      if ( rasterize )
        FT_Render_Glyph( face->glyph, ft_render_mode_normal );
    }

    FT_Done_Face( face );
  }

__attribute__((used)) static void
  ExecuteTest( char*  testfont )
  {
    FT_Library  context;
    FT_Face     face;
    int         i, num;


    if ( FT_Init_FreeType( &context ) )
    {
      fprintf( stderr, "Can't initialize FreeType.\n" );
      exit( 1 );
    }

    if ( FT_New_Face( context, testfont, 0, &face ) )
    {
      /* The font is erroneous, so if this fails that's ok. */
      exit( 0 );
    }

    if ( face->num_faces == 1 )
      TestFace( face );
    else
    {
      num = face->num_faces;
      FT_Done_Face( face );

      for ( i = 0; i < num; ++i )
      {
        if ( !FT_New_Face( context, testfont, i, &face ) )
          TestFace( face );
      }
    }

    exit( 0 );
  }

__attribute__((used)) static int
  extmatch( char*   filename,
            char**  extensions )
  {
    int    i;
    char*  pt;


    if ( extensions == NULL )
      return true;

    pt = strrchr( filename, '.' );
    if ( pt == NULL )
      return false;
    if ( pt < strrchr( filename, '/' ) )
      return false;

    for ( i = 0; extensions[i] != NULL; ++i )
      if ( strcasecmp( pt + 1, extensions[i] ) == 0 ||
           strcasecmp( pt,     extensions[i] ) == 0 )
        return true;

    return false;
  }

__attribute__((used)) static void
  figurefiletype( struct fontlist*  item )
  {
    FILE*  foo;


    item->isbinary = item->isascii = item->ishex = false;

    foo = fopen( item->name, "rb" );
    if ( foo != NULL )
    {
      /* Try to guess the file type from the first few characters... */
      int  ch1 = getc( foo );
      int  ch2 = getc( foo );
      int  ch3 = getc( foo );
      int  ch4 = getc( foo );


      fclose( foo );

      if ( ( ch1 == 0   && ch2 == 1   && ch3 == 0   && ch4 == 0   ) ||
           ( ch1 == 'O' && ch2 == 'T' && ch3 == 'T' && ch4 == 'O' ) ||
           ( ch1 == 't' && ch2 == 'r' && ch3 == 'u' && ch4 == 'e' ) ||
           ( ch1 == 't' && ch2 == 't' && ch3 == 'c' && ch4 == 'f' ) )
      {
        /* ttf, otf, ttc files */
        item->isbinary = true;
      }
      else if ( ch1 == 0x80 && ch2 == '\01' )
      {
        /* PFB header */
        item->isbinary = true;
      }
      else if ( ch1 == '%' && ch2 == '!' )
      {
        /* Random PostScript */
        if ( strstr( item->name, ".pfa" ) != NULL ||
             strstr( item->name, ".PFA" ) != NULL )
          item->ishex = true;
        else
          item->isascii = true;
      }
      else if ( ch1 == 1 && ch2 == 0 && ch3 == 4 )
      {
        /* Bare CFF */
        item->isbinary = true;
      }
      else if ( ch1 == 'S' && ch2 == 'T' && ch3 == 'A' && ch4 == 'R' )
      {
        /* BDF */
        item->ishex = true;
      }
      else if ( ch1 == 'P' && ch2 == 'F' && ch3 == 'R' && ch4 == '0' )
      {
        /* PFR */
        item->isbinary = true;
      }
      else if ( ( ch1 == '\1' && ch2 == 'f' && ch3 == 'c' && ch4 == 'p' ) ||
                ( ch1 == 'M'  && ch2 == 'Z' )                             )
      {
        /* Windows FON */
        item->isbinary = true;
      }
      else
      {
        fprintf( stderr,
                 "Can't recognize file type of `%s', assuming binary\n",
                 item->name );
        item->isbinary = true;
      }
    }
    else
    {
      fprintf( stderr, "Can't open `%s' for typing the file.\n",
               item->name );
      item->isbinary = true;
    }
  }

__attribute__((used)) static void
  FindFonts( char**  fontdirs,
             char**  extensions )
  {
    DIR*            examples;
    struct dirent*  ent;

    int             i, max;
    char            buffer[1025];
    struct stat     statb;


    max  = 0;
    fcnt = 0;

    for ( i = 0; fontdirs[i] != NULL; ++i )
    {
      examples = opendir( fontdirs[i] );
      if ( examples == NULL )
      {
        fprintf( stderr,
                 "Can't open example font directory `%s'\n",
                 fontdirs[i] );
        exit( 1 );
      }

      while ( ( ent = readdir( examples ) ) != NULL )
      {
        snprintf( buffer, sizeof ( buffer ),
                  "%s/%s", fontdirs[i], ent->d_name );
        if ( stat( buffer, &statb ) == -1 || S_ISDIR( statb.st_mode ) )
          continue;
        if ( extensions == NULL || extmatch( buffer, extensions ) )
        {
          if ( fcnt >= max )
          {
            max += 100;
            fontlist = realloc( fontlist, max * sizeof ( struct fontlist ) );
            if ( fontlist == NULL )
            {
              fprintf( stderr, "Can't allocate memory\n" );
              exit( 1 );
            }
          }

          fontlist[fcnt].name = strdup( buffer );
          fontlist[fcnt].len  = statb.st_size;

          figurefiletype( &fontlist[fcnt] );
          ++fcnt;
        }
      }

      closedir( examples );
    }

    if ( fcnt == 0 )
    {
      fprintf( stderr, "Can't find matching font files.\n" );
      exit( 1 );
    }

    fontlist[fcnt].name = NULL;
  }

__attribute__((used)) static int
  getErrorCnt( struct fontlist*  item )
  {
    if ( error_count == 0 && error_fraction == 0 )
      return 0;

    return error_count + ceil( error_fraction * item->len );
  }

__attribute__((used)) static int
  getRandom( int  low,
             int  high )
  {
    if ( low - high < 0x10000L )
      return low + ( ( random() >> 8 ) % ( high + 1 - low ) );

    return low + ( random() % ( high + 1 - low ) );
  }

__attribute__((used)) static int
  copyfont( struct fontlist*  item,
            char*             newfont )
  {
    static char  buffer[8096];
    FILE         *good, *new;
    int          len;
    int          i, err_cnt;


    good = fopen( item->name, "r" );
    if ( good == NULL )
    {
      fprintf( stderr, "Can't open `%s'\n", item->name );
      return false;
    }

    new = fopen( newfont, "w+" );
    if ( new == NULL )
    {
      fprintf( stderr, "Can't create temporary output file `%s'\n",
               newfont );
      exit( 1 );
    }

    while ( ( len = fread( buffer, 1, sizeof ( buffer ), good ) ) > 0 )
      fwrite( buffer, 1, len, new );

    fclose( good );

    err_cnt = getErrorCnt( item );
    for ( i = 0; i < err_cnt; ++i )
    {
      fseek( new, getRandom( 0, item->len - 1 ), SEEK_SET );

      if ( item->isbinary )
        putc( getRandom( 0, 0xff ), new );
      else if ( item->isascii )
        putc( getRandom( 0x20, 0x7e ), new );
      else
      {
        int  hex = getRandom( 0, 15 );


        if ( hex < 10 )
          hex += '0';
        else
          hex += 'A' - 10;

        putc( hex, new );
      }
    }

    if ( ferror( new ) )
    {
      fclose( new );
      unlink( newfont );
      return false;
    }

    fclose( new );

    return true;
  }

__attribute__((used)) static void
  abort_test( int  sig )
  {
    /* If a time-out happens, then kill the child */
    kill( child_pid, SIGFPE );
    write( 2, "Timeout... ", 11 );
  }

__attribute__((used)) static void
  do_test( void )
  {
    int         i        = getRandom( 0, fcnt - 1 );
    static int  test_num = 0;
    char        buffer[1024];


    sprintf( buffer, "%s/test%d", results_dir, test_num++ );

    if ( copyfont ( &fontlist[i], buffer ) )
    {
      signal( SIGALRM, abort_test );
      /* Anything that takes more than 20 seconds */
      /* to parse and/or rasterize is an error.   */
      alarm( 20 );
      if ( ( child_pid = fork() ) == 0 )
        ExecuteTest( buffer );
      else if ( child_pid != -1 )
      {
        int  status;


        waitpid( child_pid, &status, 0 );
        alarm( 0 );
        if ( WIFSIGNALED ( status ) )
          printf( "Error found in file `%s'\n", buffer );
        else
          unlink( buffer );
      }
      else
      {
        fprintf( stderr, "Can't fork test case.\n" );
        exit( 1 );
      }
      alarm( 0 );
    }
  }

__attribute__((used)) static void
  usage( FILE*  out,
         char*  name )
  {
    fprintf( out, "%s [options] -- Generate random erroneous fonts\n"
                  "  and attempt to parse them with FreeType.\n\n", name );

    fprintf( out, "  --all                    All non-directory files are assumed to be fonts.\n" );
    fprintf( out, "  --check-outlines         Make sure we can parse the outlines of each glyph.\n" );
    fprintf( out, "  --dir <path>             Append <path> to list of font search directories.\n" );
    fprintf( out, "  --error-count <cnt>      Introduce <cnt> single byte errors into each font.\n" );
    fprintf( out, "  --error-fraction <frac>  Introduce <frac>*filesize single byte errors\n"
                  "                           into each font.\n" );
    fprintf( out, "  --ext <ext>              Add <ext> to list of extensions indicating fonts.\n" );
    fprintf( out, "  --help                   Print this.\n" );
    fprintf( out, "  --nohints                Turn off hinting.\n" );
    fprintf( out, "  --rasterize              Attempt to rasterize each glyph.\n" );
    fprintf( out, "  --results <dir>          Directory in which to place the test fonts.\n" );
    fprintf( out, "  --size <float>           Use the given font size for the tests.\n" );
    fprintf( out, "  --test <file>            Run a single test on an already existing file.\n" );
  }

int
  main( int     argc,
        char**  argv )
  {
    char    **dirs, **exts;
    char    *pt, *end;
    int     dcnt = 0, ecnt = 0, rset = false, allexts = false;
    int     i;
    time_t  now;
    char*   testfile = NULL;


    dirs = calloc( argc + 1, sizeof ( char ** ) );
    exts = calloc( argc + 1, sizeof ( char ** ) );

    for ( i = 1; i < argc; ++i )
    {
      pt = argv[i];
      if ( pt[0] == '-' && pt[1] == '-' )
        ++pt;

      if ( strcmp( pt, "-all" ) == 0 )
        allexts = true;
      else if ( strcmp( pt, "-check-outlines" ) == 0 )
        check_outlines = true;
      else if ( strcmp( pt, "-dir" ) == 0 )
        dirs[dcnt++] = argv[++i];
      else if ( strcmp( pt, "-error-count" ) == 0 )
      {
        if ( !rset )
          error_fraction = 0;
        rset = true;
        error_count = strtol( argv[++i], &end, 10 );
        if ( *end != '\0' )
        {
          fprintf( stderr, "Bad value for error-count: %s\n", argv[i] );
          exit( 1 );
        }
      }
      else if ( strcmp( pt, "-error-fraction" ) == 0 )
      {
        if ( !rset )
          error_count = 0;
        rset = true;
        error_fraction = strtod( argv[++i], &end );
        if ( *end != '\0' )
        {
          fprintf( stderr, "Bad value for error-fraction: %s\n", argv[i] );
          exit( 1 );
        }
      }
      else if ( strcmp( pt, "-ext" ) == 0 )
        exts[ecnt++] = argv[++i];
      else if ( strcmp( pt, "-help" ) == 0 )
      {
        usage( stdout, argv[0] );
        exit( 0 );
      }
      else if ( strcmp( pt, "-nohints" ) == 0 )
        nohints = true;
      else if ( strcmp( pt, "-rasterize" ) == 0 )
        rasterize = true;
      else if ( strcmp( pt, "-results" ) == 0 )
        results_dir = argv[++i];
      else if ( strcmp( pt, "-size" ) == 0 )
      {
        font_size = (FT_F26Dot6)( strtod( argv[++i], &end ) * 64 );
        if ( *end != '\0' || font_size < 64 )
        {
          fprintf( stderr, "Bad value for size: %s\n", argv[i] );
          exit( 1 );
        }
      }
      else if ( strcmp( pt, "-test" ) == 0 )
        testfile = argv[++i];
      else
      {
        usage( stderr, argv[0] );
        exit( 1 );
      }
    }

    if ( allexts )
      exts = NULL;
    else if ( ecnt == 0 )
      exts = default_ext_list;

    if ( dcnt == 0 )
      dirs = default_dir_list;

    if ( testfile != NULL )
      ExecuteTest( testfile );         /* This should never return */

    time( &now );
    srandom( now );

    FindFonts( dirs, exts );
    mkdir( results_dir, 0755 );

    forever
      do_test();

    return 0;
  }

