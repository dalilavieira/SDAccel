#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_8__ ;
typedef  struct TYPE_27__   TYPE_7__ ;
typedef  struct TYPE_26__   TYPE_6__ ;
typedef  struct TYPE_25__   TYPE_5__ ;
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;

/* Type definitions */
struct TYPE_28__ {scalar_t__ num_glyphs; } ;
struct TYPE_27__ {TYPE_8__* face; } ;
struct TYPE_26__ {int /*<<< orphan*/  metrics; int /*<<< orphan*/  face; } ;
struct TYPE_25__ {int /*<<< orphan*/  x; scalar_t__ y; } ;
struct TYPE_24__ {int /*<<< orphan*/  (* get_kerning ) (TYPE_2__*,scalar_t__,scalar_t__) ;} ;
struct TYPE_23__ {scalar_t__ interpreter_version; } ;
struct TYPE_22__ {int /*<<< orphan*/  sfnt; } ;
struct TYPE_21__ {int /*<<< orphan*/  hinted_metrics; int /*<<< orphan*/ * metrics; } ;
typedef  TYPE_1__* TT_Size ;
typedef  int /*<<< orphan*/  TT_GlyphSlot ;
typedef  TYPE_2__* TT_Face ;
typedef  TYPE_3__* TT_Driver ;
typedef  TYPE_4__* SFNT_Service ;
typedef  TYPE_5__ FT_Vector ;
typedef  int /*<<< orphan*/  FT_UShort ;
typedef  scalar_t__ FT_UInt ;
typedef  int /*<<< orphan*/  FT_Size_Request ;
typedef  TYPE_6__* FT_Size ;
typedef  int /*<<< orphan*/  FT_Short ;
typedef  int /*<<< orphan*/  FT_Module ;
typedef  int FT_Int32 ;
typedef  TYPE_7__* FT_GlyphSlot ;
typedef  int /*<<< orphan*/  FT_Fixed ;
typedef  TYPE_8__* FT_Face ;
typedef  int /*<<< orphan*/  FT_Error ;

/* Variables and functions */
 int /*<<< orphan*/  FT_Err_Ok ; 
 scalar_t__ FT_IS_SCALABLE (int /*<<< orphan*/ ) ; 
 scalar_t__ FT_IS_TRICKY (TYPE_8__*) ; 
 int FT_LOAD_NO_AUTOHINT ; 
 int FT_LOAD_NO_BITMAP ; 
 int FT_LOAD_NO_HINTING ; 
 int FT_LOAD_NO_RECURSE ; 
 int FT_LOAD_NO_SCALE ; 
 int FT_LOAD_VERTICAL_LAYOUT ; 
 int /*<<< orphan*/  FT_Request_Metrics (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FT_THROW (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FT_TRACE0 (char*) ; 
 int /*<<< orphan*/  Invalid_Argument ; 
 int /*<<< orphan*/  Invalid_Face_Handle ; 
 int /*<<< orphan*/  Invalid_Size_Handle ; 
 int /*<<< orphan*/  Invalid_Slot_Handle ; 
 int /*<<< orphan*/  Missing_Property ; 
 int /*<<< orphan*/  TT_Get_HMetrics (TYPE_2__*,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TT_Get_VMetrics (TYPE_2__*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TT_Load_Glyph (TYPE_1__*,int /*<<< orphan*/ ,scalar_t__,int) ; 
 int /*<<< orphan*/  ft_strcmp (char const*,char*) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  tt_size_reset (TYPE_1__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static FT_Error
  tt_property_get( FT_Module    module,         /* TT_Driver */
                   const char*  property_name,
                   const void*  value )
  {
    FT_Error   error  = FT_Err_Ok;
    TT_Driver  driver = (TT_Driver)module;

    FT_UInt  interpreter_version = driver->interpreter_version;


    if ( !ft_strcmp( property_name, "interpreter-version" ) )
    {
      FT_UInt*  val = (FT_UInt*)value;


      *val = interpreter_version;

      return error;
    }

    FT_TRACE0(( "tt_property_get: missing property `%s'\n",
                property_name ));
    return FT_THROW( Missing_Property );
  }

__attribute__((used)) static FT_Error
  tt_get_kerning( FT_Face     ttface,          /* TT_Face */
                  FT_UInt     left_glyph,
                  FT_UInt     right_glyph,
                  FT_Vector*  kerning )
  {
    TT_Face       face = (TT_Face)ttface;
    SFNT_Service  sfnt = (SFNT_Service)face->sfnt;


    kerning->x = 0;
    kerning->y = 0;

    if ( sfnt )
      kerning->x = sfnt->get_kerning( face, left_glyph, right_glyph );

    return 0;
  }

__attribute__((used)) static FT_Error
  tt_get_advances( FT_Face    ttface,
                   FT_UInt    start,
                   FT_UInt    count,
                   FT_Int32   flags,
                   FT_Fixed  *advances )
  {
    FT_UInt  nn;
    TT_Face  face = (TT_Face)ttface;


    /* XXX: TODO: check for sbits */

    if ( flags & FT_LOAD_VERTICAL_LAYOUT )
    {
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
      /* no fast retrieval for blended MM fonts without VVAR table */
      if ( ( FT_IS_NAMED_INSTANCE( ttface ) || FT_IS_VARIATION( ttface ) ) &&
           !( face->variation_support & TT_FACE_FLAG_VAR_VADVANCE )        )
        return FT_THROW( Unimplemented_Feature );
#endif

      for ( nn = 0; nn < count; nn++ )
      {
        FT_Short   tsb;
        FT_UShort  ah;


        /* since we don't need `tsb', we use zero for `yMax' parameter */
        TT_Get_VMetrics( face, start + nn, 0, &tsb, &ah );
        advances[nn] = ah;
      }
    }
    else
    {
#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
      /* no fast retrieval for blended MM fonts without HVAR table */
      if ( ( FT_IS_NAMED_INSTANCE( ttface ) || FT_IS_VARIATION( ttface ) ) &&
           !( face->variation_support & TT_FACE_FLAG_VAR_HADVANCE )        )
        return FT_THROW( Unimplemented_Feature );
#endif

      for ( nn = 0; nn < count; nn++ )
      {
        FT_Short   lsb;
        FT_UShort  aw;


        TT_Get_HMetrics( face, start + nn, &lsb, &aw );
        advances[nn] = aw;
      }
    }

    return FT_Err_Ok;
  }

__attribute__((used)) static FT_Error
  tt_size_request( FT_Size          size,
                   FT_Size_Request  req )
  {
    TT_Size   ttsize = (TT_Size)size;
    FT_Error  error  = FT_Err_Ok;


#ifdef TT_CONFIG_OPTION_EMBEDDED_BITMAPS

    if ( FT_HAS_FIXED_SIZES( size->face ) )
    {
      TT_Face       ttface = (TT_Face)size->face;
      SFNT_Service  sfnt   = (SFNT_Service)ttface->sfnt;
      FT_ULong      strike_index;


      error = sfnt->set_sbit_strike( ttface, req, &strike_index );

      if ( error )
        ttsize->strike_index = 0xFFFFFFFFUL;
      else
        return tt_size_select( size, strike_index );
    }

#endif /* TT_CONFIG_OPTION_EMBEDDED_BITMAPS */

    FT_Request_Metrics( size->face, req );

    if ( FT_IS_SCALABLE( size->face ) )
    {
      error = tt_size_reset( ttsize, 0 );

#ifdef TT_USE_BYTECODE_INTERPRETER
      /* for the `MPS' bytecode instruction we need the point size */
      if ( !error )
      {
        FT_UInt  resolution =
                   ttsize->metrics->x_ppem > ttsize->metrics->y_ppem
                     ? req->horiResolution
                     : req->vertResolution;


        /* if we don't have a resolution value, assume 72dpi */
        if ( req->type == FT_SIZE_REQUEST_TYPE_SCALES ||
             !resolution                              )
          resolution = 72;

        ttsize->point_size = FT_MulDiv( ttsize->ttmetrics.ppem,
                                        64 * 72,
                                        resolution );
      }
#endif
    }

    return error;
  }

__attribute__((used)) static FT_Error
  tt_glyph_load( FT_GlyphSlot  ttslot,      /* TT_GlyphSlot */
                 FT_Size       ttsize,      /* TT_Size      */
                 FT_UInt       glyph_index,
                 FT_Int32      load_flags )
  {
    TT_GlyphSlot  slot = (TT_GlyphSlot)ttslot;
    TT_Size       size = (TT_Size)ttsize;
    FT_Face       face = ttslot->face;
    FT_Error      error;


    if ( !slot )
      return FT_THROW( Invalid_Slot_Handle );

    if ( !size )
      return FT_THROW( Invalid_Size_Handle );

    if ( !face )
      return FT_THROW( Invalid_Face_Handle );

#ifdef FT_CONFIG_OPTION_INCREMENTAL
    if ( glyph_index >= (FT_UInt)face->num_glyphs &&
         !face->internal->incremental_interface   )
#else
    if ( glyph_index >= (FT_UInt)face->num_glyphs )
#endif
      return FT_THROW( Invalid_Argument );

    if ( load_flags & FT_LOAD_NO_HINTING )
    {
      /* both FT_LOAD_NO_HINTING and FT_LOAD_NO_AUTOHINT   */
      /* are necessary to disable hinting for tricky fonts */

      if ( FT_IS_TRICKY( face ) )
        load_flags &= ~FT_LOAD_NO_HINTING;

      if ( load_flags & FT_LOAD_NO_AUTOHINT )
        load_flags |= FT_LOAD_NO_HINTING;
    }

    if ( load_flags & ( FT_LOAD_NO_RECURSE | FT_LOAD_NO_SCALE ) )
    {
      load_flags |= FT_LOAD_NO_BITMAP | FT_LOAD_NO_SCALE;

      if ( !FT_IS_TRICKY( face ) )
        load_flags |= FT_LOAD_NO_HINTING;
    }

    /* use hinted metrics only if we load a glyph with hinting */
    size->metrics = ( load_flags & FT_LOAD_NO_HINTING )
                      ? &ttsize->metrics
                      : &size->hinted_metrics;

    /* now load the glyph outline if necessary */
    error = TT_Load_Glyph( size, slot, glyph_index, load_flags );

    /* force drop-out mode to 2 - irrelevant now */
    /* slot->outline.dropout_mode = 2; */

    return error;
  }

