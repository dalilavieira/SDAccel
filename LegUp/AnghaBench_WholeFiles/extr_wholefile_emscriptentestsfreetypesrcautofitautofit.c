#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_33__   TYPE_9__ ;
typedef  struct TYPE_32__   TYPE_8__ ;
typedef  struct TYPE_31__   TYPE_7__ ;
typedef  struct TYPE_30__   TYPE_6__ ;
typedef  struct TYPE_29__   TYPE_5__ ;
typedef  struct TYPE_28__   TYPE_4__ ;
typedef  struct TYPE_27__   TYPE_3__ ;
typedef  struct TYPE_26__   TYPE_2__ ;
typedef  struct TYPE_25__   TYPE_1__ ;
typedef  struct TYPE_24__   TYPE_12__ ;
typedef  struct TYPE_23__   TYPE_11__ ;
typedef  struct TYPE_22__   TYPE_10__ ;

/* Type definitions */
struct TYPE_33__ {TYPE_11__* axis; } ;
struct TYPE_32__ {TYPE_7__* script_uni_ranges; } ;
struct TYPE_31__ {scalar_t__ first; size_t last; } ;
struct TYPE_30__ {TYPE_5__* glyph; int /*<<< orphan*/  charmap; } ;
struct TYPE_25__ {scalar_t__ n_points; size_t n_contours; size_t* contours; int /*<<< orphan*/ * tags; TYPE_4__* points; } ;
struct TYPE_29__ {TYPE_1__ outline; } ;
struct TYPE_28__ {scalar_t__ y; } ;
struct TYPE_27__ {scalar_t__ org; } ;
struct TYPE_26__ {scalar_t__ org; } ;
struct TYPE_24__ {int* glyph_scripts; size_t glyph_count; TYPE_6__* face; } ;
struct TYPE_23__ {size_t blue_count; TYPE_10__* blues; } ;
struct TYPE_22__ {int /*<<< orphan*/  flags; TYPE_3__ shoot; TYPE_2__ ref; } ;
typedef  TYPE_4__ FT_Vector ;
typedef  size_t FT_ULong ;
typedef  size_t FT_UInt ;
typedef  scalar_t__ FT_Pos ;
typedef  size_t FT_Long ;
typedef  size_t FT_Int ;
typedef  TYPE_5__* FT_GlyphSlot ;
typedef  TYPE_6__* FT_Face ;
typedef  scalar_t__ FT_Error ;
typedef  int /*<<< orphan*/  FT_CharMap ;
typedef  int FT_Byte ;
typedef  int FT_Bool ;
typedef  TYPE_7__* AF_Script_UniRange ;
typedef  TYPE_8__* AF_ScriptClass ;
typedef  TYPE_9__* AF_LatinMetrics ;
typedef  TYPE_10__* AF_LatinBlue ;
typedef  TYPE_11__* AF_LatinAxis ;
typedef  TYPE_12__* AF_FaceGlobals ;

/* Variables and functions */
 int AF_DIGIT ; 
 size_t AF_DIMENSION_VERT ; 
 scalar_t__ AF_Err_Ok ; 
 int /*<<< orphan*/  AF_LATIN_BLUE_ADJUSTMENT ; 
 size_t AF_LATIN_BLUE_MAX ; 
 size_t AF_LATIN_BLUE_SMALL_TOP ; 
 int /*<<< orphan*/  AF_LATIN_BLUE_TOP ; 
 int AF_LATIN_IS_TOP_BLUE (size_t) ; 
 int AF_LATIN_MAX_TEST_CHARACTERS ; 
 int /*<<< orphan*/  AF_LOG (char*) ; 
 TYPE_8__** AF_SCRIPT_CLASSES_GET ; 
 int AF_SCRIPT_LIST_DEFAULT ; 
 int AF_SCRIPT_LIST_NONE ; 
 int FT_BOOL (int) ; 
 scalar_t__ FT_CURVE_TAG (int /*<<< orphan*/ ) ; 
 scalar_t__ FT_CURVE_TAG_ON ; 
 int /*<<< orphan*/  FT_ENCODING_UNICODE ; 
 size_t FT_Get_Char_Index (TYPE_6__*,size_t) ; 
 size_t FT_Get_Next_Char (TYPE_6__*,size_t,size_t*) ; 
 int /*<<< orphan*/  FT_LOAD_NO_SCALE ; 
 scalar_t__ FT_Load_Glyph (TYPE_6__*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FT_MEM_SET (int*,int,size_t) ; 
 scalar_t__ FT_Select_Charmap (TYPE_6__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FT_Set_Charmap (TYPE_6__*,int /*<<< orphan*/ ) ; 
 char** af_latin_blue_chars ; 
 int /*<<< orphan*/  af_sort_pos (size_t,scalar_t__*) ; 

__attribute__((used)) static FT_Error
  af_face_globals_compute_script_coverage( AF_FaceGlobals  globals )
  {
    FT_Error    error       = AF_Err_Ok;
    FT_Face     face        = globals->face;
    FT_CharMap  old_charmap = face->charmap;
    FT_Byte*    gscripts    = globals->glyph_scripts;
    FT_UInt     ss, i;


    /* the value 255 means `uncovered glyph' */
    FT_MEM_SET( globals->glyph_scripts,
                AF_SCRIPT_LIST_NONE,
                globals->glyph_count );

    error = FT_Select_Charmap( face, FT_ENCODING_UNICODE );
    if ( error )
    {
     /*
      *  Ignore this error; we simply use the default script.
      *  XXX: Shouldn't we rather disable hinting?
      */
      error = AF_Err_Ok;
      goto Exit;
    }

    /* scan each script in a Unicode charmap */
    for ( ss = 0; AF_SCRIPT_CLASSES_GET[ss]; ss++ )
    {
      AF_ScriptClass      clazz = AF_SCRIPT_CLASSES_GET[ss];
      AF_Script_UniRange  range;


      if ( clazz->script_uni_ranges == NULL )
        continue;

      /*
       *  Scan all unicode points in the range and set the corresponding
       *  glyph script index.
       */
      for ( range = clazz->script_uni_ranges; range->first != 0; range++ )
      {
        FT_ULong  charcode = range->first;
        FT_UInt   gindex;


        gindex = FT_Get_Char_Index( face, charcode );

        if ( gindex != 0                             &&
             gindex < (FT_ULong)globals->glyph_count &&
             gscripts[gindex] == AF_SCRIPT_LIST_NONE )
        {
          gscripts[gindex] = (FT_Byte)ss;
        }

        for (;;)
        {
          charcode = FT_Get_Next_Char( face, charcode, &gindex );

          if ( gindex == 0 || charcode > range->last )
            break;

          if ( gindex < (FT_ULong)globals->glyph_count &&
               gscripts[gindex] == AF_SCRIPT_LIST_NONE )
          {
            gscripts[gindex] = (FT_Byte)ss;
          }
        }
      }
    }

    /* mark ASCII digits */
    for ( i = 0x30; i <= 0x39; i++ )
    {
      FT_UInt  gindex = FT_Get_Char_Index( face, i );


      if ( gindex != 0 && gindex < (FT_ULong)globals->glyph_count )
        gscripts[gindex] |= AF_DIGIT;
    }

  Exit:
    /*
     *  By default, all uncovered glyphs are set to the latin script.
     *  XXX: Shouldn't we disable hinting or do something similar?
     */
    {
      FT_Long  nn;


      for ( nn = 0; nn < globals->glyph_count; nn++ )
      {
        if ( ( gscripts[nn] & ~AF_DIGIT ) == AF_SCRIPT_LIST_NONE )
        {
          gscripts[nn] &= ~AF_SCRIPT_LIST_NONE;
          gscripts[nn] |= AF_SCRIPT_LIST_DEFAULT;
        }
      }
    }

    FT_Set_Charmap( face, old_charmap );
    return error;
  }

__attribute__((used)) static void
  af_latin_metrics_init_blues( AF_LatinMetrics  metrics,
                               FT_Face          face )
  {
    FT_Pos        flats [AF_LATIN_MAX_TEST_CHARACTERS];
    FT_Pos        rounds[AF_LATIN_MAX_TEST_CHARACTERS];
    FT_Int        num_flats;
    FT_Int        num_rounds;
    FT_Int        bb;
    AF_LatinBlue  blue;
    FT_Error      error;
    AF_LatinAxis  axis  = &metrics->axis[AF_DIMENSION_VERT];
    FT_GlyphSlot  glyph = face->glyph;


    /* we compute the blues simply by loading each character from the    */
    /* 'af_latin_blue_chars[blues]' string, then compute its top-most or */
    /* bottom-most points (depending on `AF_IS_TOP_BLUE')                */

    AF_LOG(( "blue zones computation\n" ));
    AF_LOG(( "------------------------------------------------\n" ));

    for ( bb = 0; bb < AF_LATIN_BLUE_MAX; bb++ )
    {
      const char*  p     = af_latin_blue_chars[bb];
      const char*  limit = p + AF_LATIN_MAX_TEST_CHARACTERS;
      FT_Pos*      blue_ref;
      FT_Pos*      blue_shoot;


      AF_LOG(( "blue %3d: ", bb ));

      num_flats  = 0;
      num_rounds = 0;

      for ( ; p < limit && *p; p++ )
      {
        FT_UInt     glyph_index;
        FT_Pos      best_y; /* same as points.y */
        FT_Int      best_point, best_first, best_last;
        FT_Vector*  points;
        FT_Bool     round = 0;


        AF_LOG(( "'%c'", *p ));

        /* load the character in the face -- skip unknown or empty ones */
        glyph_index = FT_Get_Char_Index( face, (FT_UInt)*p );
        if ( glyph_index == 0 )
          continue;

        error = FT_Load_Glyph( face, glyph_index, FT_LOAD_NO_SCALE );
        if ( error || glyph->outline.n_points <= 0 )
          continue;

        /* now compute min or max point indices and coordinates */
        points      = glyph->outline.points;
        best_point  = -1;
        best_y      = 0;  /* make compiler happy */
        best_first  = 0;  /* ditto */
        best_last   = 0;  /* ditto */

        {
          FT_Int  nn;
          FT_Int  first = 0;
          FT_Int  last  = -1;


          for ( nn = 0; nn < glyph->outline.n_contours; first = last+1, nn++ )
          {
            FT_Int  old_best_point = best_point;
            FT_Int  pp;


            last = glyph->outline.contours[nn];

            /* Avoid single-point contours since they are never rasterized. */
            /* In some fonts, they correspond to mark attachment points     */
            /* which are way outside of the glyph's real outline.           */
            if ( last <= first )
                continue;

            if ( AF_LATIN_IS_TOP_BLUE( bb ) )
            {
              for ( pp = first; pp <= last; pp++ )
                if ( best_point < 0 || points[pp].y > best_y )
                {
                  best_point = pp;
                  best_y     = points[pp].y;
                }
            }
            else
            {
              for ( pp = first; pp <= last; pp++ )
                if ( best_point < 0 || points[pp].y < best_y )
                {
                  best_point = pp;
                  best_y     = points[pp].y;
                }
            }

            if ( best_point != old_best_point )
            {
              best_first = first;
              best_last  = last;
            }
          }
          AF_LOG(( "%5d", best_y ));
        }

        /* now check whether the point belongs to a straight or round   */
        /* segment; we first need to find in which contour the extremum */
        /* lies, then inspect its previous and next points              */
        if ( best_point >= 0 )
        {
          FT_Int  prev, next;
          FT_Pos  dist;


          /* now look for the previous and next points that are not on the */
          /* same Y coordinate.  Threshold the `closeness'...              */
          prev = best_point;
          next = prev;

          do
          {
            if ( prev > best_first )
              prev--;
            else
              prev = best_last;

            dist = points[prev].y - best_y;
            if ( dist < -5 || dist > 5 )
              break;

          } while ( prev != best_point );

          do
          {
            if ( next < best_last )
              next++;
            else
              next = best_first;

            dist = points[next].y - best_y;
            if ( dist < -5 || dist > 5 )
              break;

          } while ( next != best_point );

          /* now, set the `round' flag depending on the segment's kind */
          round = FT_BOOL(
            FT_CURVE_TAG( glyph->outline.tags[prev] ) != FT_CURVE_TAG_ON ||
            FT_CURVE_TAG( glyph->outline.tags[next] ) != FT_CURVE_TAG_ON );

          AF_LOG(( "%c ", round ? 'r' : 'f' ));
        }

        if ( round )
          rounds[num_rounds++] = best_y;
        else
          flats[num_flats++]   = best_y;
      }

      AF_LOG(( "\n" ));

      if ( num_flats == 0 && num_rounds == 0 )
      {
        /*
         *  we couldn't find a single glyph to compute this blue zone,
         *  we will simply ignore it then
         */
        AF_LOG(( "empty\n" ));
        continue;
      }

      /* we have computed the contents of the `rounds' and `flats' tables, */
      /* now determine the reference and overshoot position of the blue -- */
      /* we simply take the median value after a simple sort               */
      af_sort_pos( num_rounds, rounds );
      af_sort_pos( num_flats,  flats );

      blue       = & axis->blues[axis->blue_count];
      blue_ref   = & blue->ref.org;
      blue_shoot = & blue->shoot.org;

      axis->blue_count++;

      if ( num_flats == 0 )
      {
        *blue_ref   =
        *blue_shoot = rounds[num_rounds / 2];
      }
      else if ( num_rounds == 0 )
      {
        *blue_ref   =
        *blue_shoot = flats[num_flats / 2];
      }
      else
      {
        *blue_ref   = flats[num_flats / 2];
        *blue_shoot = rounds[num_rounds / 2];
      }

      /* there are sometimes problems: if the overshoot position of top     */
      /* zones is under its reference position, or the opposite for bottom  */
      /* zones.  We must thus check everything there and correct the errors */
      if ( *blue_shoot != *blue_ref )
      {
        FT_Pos   ref      = *blue_ref;
        FT_Pos   shoot    = *blue_shoot;
        FT_Bool  over_ref = FT_BOOL( shoot > ref );


        if ( AF_LATIN_IS_TOP_BLUE( bb ) ^ over_ref )
          *blue_shoot = *blue_ref = ( shoot + ref ) / 2;
      }

      blue->flags = 0;
      if ( AF_LATIN_IS_TOP_BLUE( bb ) )
        blue->flags |= AF_LATIN_BLUE_TOP;

      /*
       * The following flag is used later to adjust the y and x scales
       * in order to optimize the pixel grid alignment of the top of small
       * letters.
       */
      if ( bb == AF_LATIN_BLUE_SMALL_TOP )
        blue->flags |= AF_LATIN_BLUE_ADJUSTMENT;

      AF_LOG(( "-- ref = %ld, shoot = %ld\n", *blue_ref, *blue_shoot ));
    }

    return;
  }

