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
typedef  int (* char_type_func ) (scalar_t__) ;
struct TYPE_21__ {scalar_t__ cursor; } ;
struct TYPE_18__ {scalar_t__ names; TYPE_6__* stream; } ;
struct TYPE_17__ {int /*<<< orphan*/  memory; } ;
struct TYPE_20__ {size_t num_tables; scalar_t__ num_names; char const* postscript_name; TYPE_3__ name_table; TYPE_2__ root; TYPE_1__* dir_tables; } ;
struct TYPE_19__ {int stringLength; char* string; scalar_t__ nameID; scalar_t__ stringOffset; } ;
struct TYPE_16__ {size_t Tag; size_t Offset; size_t Length; } ;
typedef  TYPE_4__* TT_Name ;
typedef  TYPE_5__* TT_Face ;
typedef  scalar_t__ FT_UShort ;
typedef  size_t FT_ULong ;
typedef  size_t FT_UInt ;
typedef  char FT_String ;
typedef  TYPE_6__* FT_Stream ;
typedef  int /*<<< orphan*/  FT_Memory ;
typedef  scalar_t__ FT_Int ;
typedef  int /*<<< orphan*/  FT_Error ;
typedef  scalar_t__ FT_Char ;
typedef  int FT_Bool ;

/* Variables and functions */
 scalar_t__ FT_ALLOC (char*,int) ; 
 int /*<<< orphan*/  FT_Err_Ok ; 
 scalar_t__ FT_FRAME_ENTER (int) ; 
 int /*<<< orphan*/  FT_FRAME_EXIT () ; 
 int /*<<< orphan*/  FT_FREE (char*) ; 
 scalar_t__ FT_STREAM_SEEK (scalar_t__) ; 
 int /*<<< orphan*/  FT_THROW (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  FT_TRACE0 (char*) ; 
 int /*<<< orphan*/  FT_UNUSED (int /*<<< orphan*/ ) ; 
 scalar_t__ IS_APPLE (TYPE_4__*) ; 
 scalar_t__ IS_WIN (TYPE_4__*) ; 
 int /*<<< orphan*/  Invalid_Argument ; 
 scalar_t__ TT_NAME_ID_PS_NAME ; 
 int /*<<< orphan*/  Table_Missing ; 
 int* sfnt_ps_map ; 

__attribute__((used)) static FT_Error
  sfnt_table_info( TT_Face    face,
                   FT_UInt    idx,
                   FT_ULong  *tag,
                   FT_ULong  *offset,
                   FT_ULong  *length )
  {
    if ( !offset || !length )
      return FT_THROW( Invalid_Argument );

    if ( !tag )
      *length = face->num_tables;
    else
    {
      if ( idx >= face->num_tables )
        return FT_THROW( Table_Missing );

      *tag    = face->dir_tables[idx].Tag;
      *offset = face->dir_tables[idx].Offset;
      *length = face->dir_tables[idx].Length;
    }

    return FT_Err_Ok;
  }

__attribute__((used)) static int
  sfnt_is_postscript( int  c )
  {
    unsigned int  cc;


    if ( c < 0 || c >= 0x80 )
      return 0;

    cc = (unsigned int)c;

    return sfnt_ps_map[cc >> 3] & ( 1 << ( cc & 0x07 ) );
  }

__attribute__((used)) static char*
  get_win_string( FT_Memory       memory,
                  FT_Stream       stream,
                  TT_Name         entry,
                  char_type_func  char_type,
                  FT_Bool         report_invalid_characters )
  {
    FT_Error  error = FT_Err_Ok;

    char*       result = NULL;
    FT_String*  r;
    FT_Char*    p;
    FT_UInt     len;

    FT_UNUSED( error );


    if ( FT_ALLOC( result, entry->stringLength / 2 + 1 ) )
      return NULL;

    if ( FT_STREAM_SEEK( entry->stringOffset ) ||
         FT_FRAME_ENTER( entry->stringLength ) )
    {
      FT_FREE( result );
      entry->stringLength = 0;
      entry->stringOffset = 0;
      FT_FREE( entry->string );

      return NULL;
    }

    r = (FT_String*)result;
    p = (FT_Char*)stream->cursor;

    for ( len = entry->stringLength / 2; len > 0; len--, p += 2 )
    {
      if ( p[0] == 0 )
      {
        if ( char_type( p[1] ) )
          *r++ = p[1];
        else
        {
          if ( report_invalid_characters )
          {
            FT_TRACE0(( "get_win_string:"
                        " Character `%c' (0x%X) invalid in PS name string\n",
                        p[1], p[1] ));
            /* it's not the job of FreeType to correct PS names... */
            *r++ = p[1];
          }
        }
      }
    }
    *r = '\0';

    FT_FRAME_EXIT();

    return result;
  }

__attribute__((used)) static char*
  get_apple_string( FT_Memory       memory,
                    FT_Stream       stream,
                    TT_Name         entry,
                    char_type_func  char_type,
                    FT_Bool         report_invalid_characters )
  {
    FT_Error  error = FT_Err_Ok;

    char*       result = NULL;
    FT_String*  r;
    FT_Char*    p;
    FT_UInt     len;

    FT_UNUSED( error );


    if ( FT_ALLOC( result, entry->stringLength + 1 ) )
      return NULL;

    if ( FT_STREAM_SEEK( entry->stringOffset ) ||
         FT_FRAME_ENTER( entry->stringLength ) )
    {
      FT_FREE( result );
      entry->stringOffset = 0;
      entry->stringLength = 0;
      FT_FREE( entry->string );

      return NULL;
    }

    r = (FT_String*)result;
    p = (FT_Char*)stream->cursor;

    for ( len = entry->stringLength; len > 0; len--, p++ )
    {
      if ( char_type( *p ) )
        *r++ = *p;
      else
      {
        if ( report_invalid_characters )
        {
          FT_TRACE0(( "get_apple_string:"
                      " Character `%c' (0x%X) invalid in PS name string\n",
                      *p, *p ));
          /* it's not the job of FreeType to correct PS names... */
          *r++ = *p;
        }
      }
    }
    *r = '\0';

    FT_FRAME_EXIT();

    return result;
  }

__attribute__((used)) static FT_Bool
  sfnt_get_name_id( TT_Face    face,
                    FT_UShort  id,
                    FT_Int    *win,
                    FT_Int    *apple )
  {
    FT_Int  n;


    *win   = -1;
    *apple = -1;

    for ( n = 0; n < face->num_names; n++ )
    {
      TT_Name  name = face->name_table.names + n;


      if ( name->nameID == id && name->stringLength > 0 )
      {
        if ( IS_WIN( name ) )
          *win = n;

        if ( IS_APPLE( name ) )
          *apple = n;
      }
    }

    return ( *win >= 0 ) || ( *apple >= 0 );
  }

__attribute__((used)) static const char*
  sfnt_get_ps_name( TT_Face  face )
  {
    FT_Int       found, win, apple;
    const char*  result = NULL;


    if ( face->postscript_name )
      return face->postscript_name;

#ifdef TT_CONFIG_OPTION_GX_VAR_SUPPORT
    if ( face->blend                                 &&
         ( FT_IS_NAMED_INSTANCE( FT_FACE( face ) ) ||
           FT_IS_VARIATION( FT_FACE( face ) )      ) )
    {
      face->postscript_name = sfnt_get_var_ps_name( face );
      return face->postscript_name;
    }
#endif

    /* scan the name table to see whether we have a Postscript name here, */
    /* either in Macintosh or Windows platform encodings                  */
    found = sfnt_get_name_id( face, TT_NAME_ID_PS_NAME, &win, &apple );
    if ( !found )
      return NULL;

    /* prefer Windows entries over Apple */
    if ( win != -1 )
      result = get_win_string( face->root.memory,
                               face->name_table.stream,
                               face->name_table.names + win,
                               sfnt_is_postscript,
                               1 );
    else
      result = get_apple_string( face->root.memory,
                                 face->name_table.stream,
                                 face->name_table.names + apple,
                                 sfnt_is_postscript,
                                 1 );

    face->postscript_name = result;

    return result;
  }

