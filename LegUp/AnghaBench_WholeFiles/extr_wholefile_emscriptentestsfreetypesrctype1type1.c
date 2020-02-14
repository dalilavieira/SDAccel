#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_46__   TYPE_8__ ;
typedef  struct TYPE_45__   TYPE_7__ ;
typedef  struct TYPE_44__   TYPE_6__ ;
typedef  struct TYPE_43__   TYPE_5__ ;
typedef  struct TYPE_42__   TYPE_4__ ;
typedef  struct TYPE_41__   TYPE_3__ ;
typedef  struct TYPE_40__   TYPE_30__ ;
typedef  struct TYPE_39__   TYPE_2__ ;
typedef  struct TYPE_38__   TYPE_1__ ;

/* Type definitions */
struct TYPE_46__ {char* cursor; } ;
struct TYPE_45__ {scalar_t__ y; scalar_t__ x; } ;
struct TYPE_38__ {size_t num_glyphs; char** glyph_names; int /*<<< orphan*/  private_dict; int /*<<< orphan*/  font_extra; int /*<<< orphan*/  font_info; scalar_t__ font_name; } ;
struct TYPE_44__ {scalar_t__ afm_data; TYPE_1__ type1; } ;
struct TYPE_43__ {int const dict; scalar_t__ ident; } ;
struct TYPE_40__ {scalar_t__ init; } ;
struct TYPE_39__ {char* cursor; char* limit; void* error; } ;
struct TYPE_41__ {TYPE_2__ root; } ;
struct TYPE_42__ {int keywords_encountered; TYPE_30__ subrs; TYPE_30__ swap_table; TYPE_30__ glyph_names; TYPE_30__ charstrings; TYPE_30__ encoding_table; TYPE_3__ parser; scalar_t__ fontdata; scalar_t__ num_chars; scalar_t__ num_glyphs; } ;
typedef  TYPE_3__* T1_Parser ;
typedef  TYPE_4__* T1_Loader ;
typedef  TYPE_5__* T1_Field ;
typedef  TYPE_6__* T1_Face ;
typedef  int /*<<< orphan*/  PS_PrivateRec ;
typedef  int /*<<< orphan*/  PS_FontInfoRec ;
typedef  int /*<<< orphan*/  PS_FontExtraRec ;
typedef  TYPE_7__ FT_Vector ;
typedef  int FT_UShort ;
typedef  int /*<<< orphan*/  FT_ULong ;
typedef  int FT_UInt ;
typedef  char const FT_String ;
typedef  TYPE_8__* FT_Stream ;
typedef  int FT_PtrDist ;
typedef  int /*<<< orphan*/  FT_Module_Interface ;
typedef  int FT_Long ;
typedef  size_t FT_Int ;
typedef  TYPE_6__* FT_Face ;
typedef  void* FT_Error ;
typedef  TYPE_6__* FT_Driver ;
typedef  char FT_Byte ;
typedef  int FT_Bool ;
typedef  int /*<<< orphan*/  AFM_FontInfo ;

/* Variables and functions */
 scalar_t__ FT_ERROR_BASE (void*) ; 
 scalar_t__ FT_Err_Ignore ; 
 int /*<<< orphan*/  FT_FRAME_ENTER (size_t) ; 
 int /*<<< orphan*/  FT_FRAME_EXIT () ; 
 int /*<<< orphan*/  FT_MEM_ZERO (TYPE_4__*,int) ; 
 scalar_t__ FT_STREAM_SEEK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FT_TRACE1 (char*) ; 
 int /*<<< orphan*/  FT_UNUSED (TYPE_6__*) ; 
 scalar_t__ IS_PS_TOKEN (char*,char*,char*) ; 
 void* T1_Err_Invalid_File_Format ; 
 void* T1_Err_Ok ; 
 void* T1_Err_Unknown_File_Format ; 
 int T1_FIELD_DICT_FONTDICT ; 
 int T1_FIELD_DICT_PRIVATE ; 
 int T1_FONTDIR_AFTER_PRIVATE ; 
 int /*<<< orphan*/  T1_Finalize_Parser (TYPE_3__*) ; 
 int /*<<< orphan*/  T1_Get_Kerning (int /*<<< orphan*/ ,int,int,TYPE_7__*) ; 
 int T1_PRIVATE ; 
 int /*<<< orphan*/  T1_Release_Table (TYPE_30__*) ; 
 int /*<<< orphan*/  T1_Skip_PS_Token (TYPE_3__*) ; 
 int /*<<< orphan*/  T1_Skip_Spaces (TYPE_3__*) ; 
 scalar_t__ ft_isdigit (char) ; 
 scalar_t__ ft_memcmp (char*,char const*,int) ; 
 int /*<<< orphan*/  ft_service_list_lookup (int /*<<< orphan*/ ,char const*) ; 
 scalar_t__ ft_strcmp (char const*,char const*) ; 
 scalar_t__ ft_strlen (char const*) ; 
 int /*<<< orphan*/  read_binary_data (TYPE_3__*,int*,char**) ; 
 void* read_pfb_tag (TYPE_8__*,int*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  t1_keywords ; 
 void* t1_load_keyword (TYPE_6__*,TYPE_4__*,TYPE_5__*) ; 
 int /*<<< orphan*/  t1_services ; 

__attribute__((used)) static FT_Error
  check_type1_format( FT_Stream    stream,
                      const char*  header_string,
                      size_t       header_length )
  {
    FT_Error   error;
    FT_UShort  tag;
    FT_ULong   dummy;


    if ( FT_STREAM_SEEK( 0 ) )
      goto Exit;

    error = read_pfb_tag( stream, &tag, &dummy );
    if ( error )
      goto Exit;

    /* We assume that the first segment in a PFB is always encoded as   */
    /* text.  This might be wrong (and the specification doesn't insist */
    /* on that), but we have never seen a counterexample.               */
    if ( tag != 0x8001U && FT_STREAM_SEEK( 0 ) )
      goto Exit;

    if ( !FT_FRAME_ENTER( header_length ) )
    {
      error = T1_Err_Ok;

      if ( ft_memcmp( stream->cursor, header_string, header_length ) != 0 )
        error = T1_Err_Unknown_File_Format;

      FT_FRAME_EXIT();
    }

  Exit:
    return error;
  }

__attribute__((used)) static FT_Error
  parse_dict( T1_Face    face,
              T1_Loader  loader,
              FT_Byte*   base,
              FT_Long    size )
  {
    T1_Parser  parser = &loader->parser;
    FT_Byte   *limit, *start_binary = NULL;
    FT_Bool    have_integer = 0;


    parser->root.cursor = base;
    parser->root.limit  = base + size;
    parser->root.error  = T1_Err_Ok;

    limit = parser->root.limit;

    T1_Skip_Spaces( parser );

    while ( parser->root.cursor < limit )
    {
      FT_Byte*  cur;


      cur = parser->root.cursor;

      /* look for `eexec' */
      if ( IS_PS_TOKEN( cur, limit, "eexec" ) )
        break;

      /* look for `closefile' which ends the eexec section */
      else if ( IS_PS_TOKEN( cur, limit, "closefile" ) )
        break;

      /* in a synthetic font the base font starts after a           */
      /* `FontDictionary' token that is placed after a Private dict */
      else if ( IS_PS_TOKEN( cur, limit, "FontDirectory" ) )
      {
        if ( loader->keywords_encountered & T1_PRIVATE )
          loader->keywords_encountered |=
            T1_FONTDIR_AFTER_PRIVATE;
        parser->root.cursor += 13;
      }

      /* check whether we have an integer */
      else if ( ft_isdigit( *cur ) )
      {
        start_binary = cur;
        T1_Skip_PS_Token( parser );
        if ( parser->root.error )
          goto Exit;
        have_integer = 1;
      }

      /* in valid Type 1 fonts we don't see `RD' or `-|' directly */
      /* since those tokens are handled by parse_subrs and        */
      /* parse_charstrings                                        */
      else if ( *cur == 'R' && cur + 6 < limit && *(cur + 1) == 'D' &&
                have_integer )
      {
        FT_Long   s;
        FT_Byte*  b;


        parser->root.cursor = start_binary;
        if ( !read_binary_data( parser, &s, &b ) )
          return T1_Err_Invalid_File_Format;
        have_integer = 0;
      }

      else if ( *cur == '-' && cur + 6 < limit && *(cur + 1) == '|' &&
                have_integer )
      {
        FT_Long   s;
        FT_Byte*  b;


        parser->root.cursor = start_binary;
        if ( !read_binary_data( parser, &s, &b ) )
          return T1_Err_Invalid_File_Format;
        have_integer = 0;
      }

      /* look for immediates */
      else if ( *cur == '/' && cur + 2 < limit )
      {
        FT_PtrDist  len;


        cur++;

        parser->root.cursor = cur;
        T1_Skip_PS_Token( parser );
        if ( parser->root.error )
          goto Exit;

        len = parser->root.cursor - cur;

        if ( len > 0 && len < 22 && parser->root.cursor < limit )
        {
          /* now compare the immediate name to the keyword table */
          T1_Field  keyword = (T1_Field)t1_keywords;


          for (;;)
          {
            FT_Byte*  name;


            name = (FT_Byte*)keyword->ident;
            if ( !name )
              break;

            if ( cur[0] == name[0]                                  &&
                 len == (FT_PtrDist)ft_strlen( (const char *)name ) &&
                 ft_memcmp( cur, name, len ) == 0                   )
            {
              /* We found it -- run the parsing callback!     */
              /* We record every instance of every field      */
              /* (until we reach the base font of a           */
              /* synthetic font) to deal adequately with      */
              /* multiple master fonts; this is also          */
              /* necessary because later PostScript           */
              /* definitions override earlier ones.           */

              /* Once we encounter `FontDirectory' after      */
              /* `/Private', we know that this is a synthetic */
              /* font; except for `/CharStrings' we are not   */
              /* interested in anything that follows this     */
              /* `FontDirectory'.                             */

              /* MM fonts have more than one /Private token at */
              /* the top level; let's hope that all the junk   */
              /* that follows the first /Private token is not  */
              /* interesting to us.                            */

              /* According to Adobe Tech Note #5175 (CID-Keyed */
              /* Font Installation for ATM Software) a `begin' */
              /* must be followed by exactly one `end', and    */
              /* `begin' -- `end' pairs must be accurately     */
              /* paired.  We could use this to distinguish     */
              /* between the global Private and the Private    */
              /* dict that is a member of the Blend dict.      */

              const FT_UInt dict =
                ( loader->keywords_encountered & T1_PRIVATE )
                    ? T1_FIELD_DICT_PRIVATE
                    : T1_FIELD_DICT_FONTDICT;

              if ( !( dict & keyword->dict ) )
              {
                FT_TRACE1(( "parse_dict: found %s but ignoring it "
                            "since it is in the wrong dictionary\n",
                            keyword->ident ));
                break;
              }

              if ( !( loader->keywords_encountered &
                      T1_FONTDIR_AFTER_PRIVATE     )                  ||
                   ft_strcmp( (const char*)name, "CharStrings" ) == 0 )
              {
                parser->root.error = t1_load_keyword( face,
                                                      loader,
                                                      keyword );
                if ( parser->root.error != T1_Err_Ok )
                {
                  if ( FT_ERROR_BASE( parser->root.error ) == FT_Err_Ignore )
                    parser->root.error = T1_Err_Ok;
                  else
                    return parser->root.error;
                }
              }
              break;
            }

            keyword++;
          }
        }

        have_integer = 0;
      }
      else
      {
        T1_Skip_PS_Token( parser );
        if ( parser->root.error )
          goto Exit;
        have_integer = 0;
      }

      T1_Skip_Spaces( parser );
    }

  Exit:
    return parser->root.error;
  }

__attribute__((used)) static void
  t1_init_loader( T1_Loader  loader,
                  T1_Face    face )
  {
    FT_UNUSED( face );

    FT_MEM_ZERO( loader, sizeof ( *loader ) );
    loader->num_glyphs = 0;
    loader->num_chars  = 0;

    /* initialize the tables -- simply set their `init' field to 0 */
    loader->encoding_table.init  = 0;
    loader->charstrings.init     = 0;
    loader->glyph_names.init     = 0;
    loader->subrs.init           = 0;
    loader->swap_table.init      = 0;
    loader->fontdata             = 0;
    loader->keywords_encountered = 0;
  }

__attribute__((used)) static void
  t1_done_loader( T1_Loader  loader )
  {
    T1_Parser  parser = &loader->parser;


    /* finalize tables */
    T1_Release_Table( &loader->encoding_table );
    T1_Release_Table( &loader->charstrings );
    T1_Release_Table( &loader->glyph_names );
    T1_Release_Table( &loader->swap_table );
    T1_Release_Table( &loader->subrs );

    /* finalize parser */
    T1_Finalize_Parser( parser );
  }

__attribute__((used)) static FT_UInt
  t1_get_name_index( T1_Face     face,
                     FT_String*  glyph_name )
  {
    FT_Int      i;
    FT_String*  gname;


    for ( i = 0; i < face->type1.num_glyphs; i++ )
    {
      gname = face->type1.glyph_names[i];

      if ( !ft_strcmp( glyph_name, gname ) )
        return (FT_UInt)i;
    }

    return 0;
  }

__attribute__((used)) static const char*
  t1_get_ps_name( T1_Face  face )
  {
    return (const char*) face->type1.font_name;
  }

__attribute__((used)) static FT_Error
  t1_ps_get_font_info( FT_Face          face,
                       PS_FontInfoRec*  afont_info )
  {
    *afont_info = ((T1_Face)face)->type1.font_info;

    return T1_Err_Ok;
  }

__attribute__((used)) static FT_Error
  t1_ps_get_font_extra( FT_Face           face,
                        PS_FontExtraRec*  afont_extra )
  {
    *afont_extra = ((T1_Face)face)->type1.font_extra;

    return T1_Err_Ok;
  }

__attribute__((used)) static FT_Int
  t1_ps_has_glyph_names( FT_Face  face )
  {
    FT_UNUSED( face );

    return 1;
  }

__attribute__((used)) static FT_Error
  t1_ps_get_font_private( FT_Face         face,
                          PS_PrivateRec*  afont_private )
  {
    *afont_private = ((T1_Face)face)->type1.private_dict;

    return T1_Err_Ok;
  }

__attribute__((used)) static FT_Module_Interface
  Get_Interface( FT_Driver         driver,
                 const FT_String*  t1_interface )
  {
    FT_UNUSED( driver );

    return ft_service_list_lookup( t1_services, t1_interface );
  }

__attribute__((used)) static FT_Error
  Get_Kerning( T1_Face     face,
               FT_UInt     left_glyph,
               FT_UInt     right_glyph,
               FT_Vector*  kerning )
  {
    kerning->x = 0;
    kerning->y = 0;

    if ( face->afm_data )
      T1_Get_Kerning( (AFM_FontInfo)face->afm_data,
                      left_glyph,
                      right_glyph,
                      kerning );

    return T1_Err_Ok;
  }

