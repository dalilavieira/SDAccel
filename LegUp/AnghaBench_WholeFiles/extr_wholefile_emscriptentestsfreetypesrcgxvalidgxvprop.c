#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
struct TYPE_21__ {TYPE_5__* glyph; } ;
struct TYPE_16__ {scalar_t__ x; scalar_t__ y; } ;
struct TYPE_20__ {TYPE_1__ advance; } ;
struct TYPE_19__ {scalar_t__ u; } ;
struct TYPE_18__ {int /*<<< orphan*/  u; } ;
struct TYPE_17__ {scalar_t__ lookuptbl_head; TYPE_6__* face; } ;
typedef  TYPE_2__* GXV_Validator ;
typedef  TYPE_3__ GXV_LookupValueDesc ;
typedef  TYPE_4__* GXV_LookupValueCPtr ;
typedef  scalar_t__ FT_UShort ;
typedef  scalar_t__ FT_Pos ;
typedef  TYPE_5__* FT_GlyphSlot ;
typedef  TYPE_6__* FT_Face ;
typedef  scalar_t__ FT_Error ;
typedef  scalar_t__ FT_Bytes ;

/* Variables and functions */
 int /*<<< orphan*/  FT_INVALID_DATA ; 
 int /*<<< orphan*/  FT_INVALID_GLYPH_ID ; 
 int /*<<< orphan*/  FT_LOAD_IGNORE_TRANSFORM ; 
 scalar_t__ FT_Load_Glyph (TYPE_6__*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FT_NEXT_USHORT (scalar_t__) ; 
 int /*<<< orphan*/  GXV_EXIT ; 
 int /*<<< orphan*/  GXV_LIMIT_CHECK (int) ; 
 int /*<<< orphan*/  GXV_NAME_ENTER (char*) ; 
 scalar_t__ GXV_PROP_ATTACHING_TO_RIGHT ; 
 scalar_t__ GXV_PROP_COMPLEMENTARY_BRACKET_OFFSET ; 
 int GXV_PROP_DATA (int /*<<< orphan*/ ) ; 
 scalar_t__ GXV_PROP_DIRECTIONALITY_CLASS ; 
 scalar_t__ GXV_PROP_FLOATER ; 
 scalar_t__ GXV_PROP_RESERVED ; 
 scalar_t__ GXV_PROP_USE_COMPLEMENTARY_BRACKET ; 
 int /*<<< orphan*/  GXV_TRACE (char*) ; 
 int /*<<< orphan*/  gxv_glyphid_validate (scalar_t__,TYPE_2__*) ; 
 int /*<<< orphan*/  version ; 

__attribute__((used)) static void
  gxv_prop_zero_advance_validate( FT_UShort      gid,
                                  GXV_Validator  valid )
  {
    FT_Face       face;
    FT_Error      error;
    FT_GlyphSlot  glyph;


    GXV_NAME_ENTER( "zero advance" );

    face = valid->face;

    error = FT_Load_Glyph( face,
                           gid,
                           FT_LOAD_IGNORE_TRANSFORM );
    if ( error )
      FT_INVALID_GLYPH_ID;

    glyph = face->glyph;

    if ( glyph->advance.x != (FT_Pos)0 ||
         glyph->advance.y != (FT_Pos)0 )
      FT_INVALID_DATA;

    GXV_EXIT;
  }

__attribute__((used)) static void
  gxv_prop_property_validate( FT_UShort      property,
                              FT_UShort      glyph,
                              GXV_Validator  valid )
  {
    if ( glyph != 0 && ( property & GXV_PROP_FLOATER ) )
      gxv_prop_zero_advance_validate( glyph, valid );

    if ( property & GXV_PROP_USE_COMPLEMENTARY_BRACKET )
    {
      FT_UShort  offset;
      char       complement;


      offset = (FT_UShort)( property & GXV_PROP_COMPLEMENTARY_BRACKET_OFFSET );
      if ( offset == 0 )
        FT_INVALID_DATA;

      complement = (char)( offset >> 8 );
      if ( complement & 0x08 )
      {
        /* Top bit is set: negative */

        /* Calculate the absolute offset */
        complement = (char)( ( complement & 0x07 ) + 1 );

        /* The gid for complement must be greater than 0 */
        if ( glyph <= complement )
          FT_INVALID_DATA;
      }
      else
      {
        /* The gid for complement must be the face. */
        gxv_glyphid_validate( (FT_UShort)( glyph + complement ), valid );
      }
    }
    else
    {
      if ( property & GXV_PROP_COMPLEMENTARY_BRACKET_OFFSET )
        GXV_TRACE(( "glyph %d cannot have complementary bracketing\n",
                    glyph ));
    }

    /* this is introduced in version 2.0 */
    if ( property & GXV_PROP_ATTACHING_TO_RIGHT )
    {
      if ( GXV_PROP_DATA( version ) == 0x00010000UL )
        FT_INVALID_DATA;
    }

    if ( property & GXV_PROP_RESERVED )
      FT_INVALID_DATA;

    if ( ( property & GXV_PROP_DIRECTIONALITY_CLASS ) > 11 )
    {
      /* TODO: Too restricted. Use the validation level. */
      if ( GXV_PROP_DATA( version ) == 0x00010000UL ||
           GXV_PROP_DATA( version ) == 0x00020000UL )
        FT_INVALID_DATA;
    }
  }

__attribute__((used)) static void
  gxv_prop_LookupValue_validate( FT_UShort            glyph,
                                 GXV_LookupValueCPtr  value_p,
                                 GXV_Validator        valid )
  {
    gxv_prop_property_validate( value_p->u, glyph, valid );
  }

__attribute__((used)) static GXV_LookupValueDesc
  gxv_prop_LookupFmt4_transit( FT_UShort            relative_gindex,
                               GXV_LookupValueCPtr  base_value_p,
                               FT_Bytes             lookuptbl_limit,
                               GXV_Validator        valid )
  {
    FT_Bytes             p;
    FT_Bytes             limit;
    FT_UShort            offset;
    GXV_LookupValueDesc  value;

    /* XXX: check range? */
    offset = (FT_UShort)( base_value_p->u +
                          relative_gindex * sizeof( FT_UShort ) );
    p      = valid->lookuptbl_head + offset;
    limit  = lookuptbl_limit;

    GXV_LIMIT_CHECK ( 2 );
    value.u = FT_NEXT_USHORT( p );

    return value;
  }

