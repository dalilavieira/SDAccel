#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {scalar_t__ cursor; } ;
struct TYPE_11__ {TYPE_6__* stream; TYPE_4__* names; } ;
struct TYPE_10__ {int /*<<< orphan*/  memory; } ;
struct TYPE_13__ {size_t num_tables; char const* postscript_name; int num_names; TYPE_3__ name_table; TYPE_2__ root; TYPE_1__* dir_tables; } ;
struct TYPE_12__ {int nameID; scalar_t__ stringLength; int platformID; int encodingID; int languageID; char const* string; scalar_t__ stringOffset; } ;
struct TYPE_9__ {int /*<<< orphan*/  Length; int /*<<< orphan*/  Offset; int /*<<< orphan*/  Tag; } ;
typedef  TYPE_4__ TT_NameEntryRec ;
typedef  TYPE_5__* TT_Face ;
typedef  int /*<<< orphan*/  FT_ULong ;
typedef  size_t FT_UInt ;
typedef  char FT_String ;
typedef  TYPE_6__* FT_Stream ;
typedef  int /*<<< orphan*/  FT_Memory ;
typedef  int FT_Int ;
typedef  int /*<<< orphan*/  FT_Error ;
typedef  int FT_Byte ;

/* Variables and functions */
 int /*<<< orphan*/  FT_ALLOC (char const*,size_t) ; 
 scalar_t__ FT_FRAME_ENTER (int) ; 
 int /*<<< orphan*/  FT_FRAME_EXIT () ; 
 int /*<<< orphan*/  FT_FREE (char const*) ; 
 scalar_t__ FT_STREAM_READ (char const*,size_t) ; 
 scalar_t__ FT_STREAM_SEEK (scalar_t__) ; 
 int /*<<< orphan*/  FT_UNUSED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SFNT_Err_Invalid_Argument ; 
 int /*<<< orphan*/  SFNT_Err_Ok ; 
 int /*<<< orphan*/  SFNT_Err_Table_Missing ; 

__attribute__((used)) static FT_Error
  sfnt_table_info( TT_Face    face,
                   FT_UInt    idx,
                   FT_ULong  *tag,
                   FT_ULong  *offset,
                   FT_ULong  *length )
  {
    if ( !tag || !offset || !length )
      return SFNT_Err_Invalid_Argument;

    if ( idx >= face->num_tables )
      return SFNT_Err_Table_Missing;

    *tag    = face->dir_tables[idx].Tag;
    *offset = face->dir_tables[idx].Offset;
    *length = face->dir_tables[idx].Length;

    return SFNT_Err_Ok;
  }

__attribute__((used)) static const char*
  sfnt_get_ps_name( TT_Face  face )
  {
    FT_Int       n, found_win, found_apple;
    const char*  result = NULL;


    /* shouldn't happen, but just in case to avoid memory leaks */
    if ( face->postscript_name )
      return face->postscript_name;

    /* scan the name table to see whether we have a Postscript name here, */
    /* either in Macintosh or Windows platform encodings                  */
    found_win   = -1;
    found_apple = -1;

    for ( n = 0; n < face->num_names; n++ )
    {
      TT_NameEntryRec*  name = face->name_table.names + n;


      if ( name->nameID == 6 && name->stringLength > 0 )
      {
        if ( name->platformID == 3     &&
             name->encodingID == 1     &&
             name->languageID == 0x409 )
          found_win = n;

        if ( name->platformID == 1 &&
             name->encodingID == 0 &&
             name->languageID == 0 )
          found_apple = n;
      }
    }

    if ( found_win != -1 )
    {
      FT_Memory         memory = face->root.memory;
      TT_NameEntryRec*  name   = face->name_table.names + found_win;
      FT_UInt           len    = name->stringLength / 2;
      FT_Error          error  = SFNT_Err_Ok;

      FT_UNUSED( error );


      if ( !FT_ALLOC( result, name->stringLength + 1 ) )
      {
        FT_Stream   stream = face->name_table.stream;
        FT_String*  r      = (FT_String*)result;
        FT_Byte*    p      = (FT_Byte*)name->string;


        if ( FT_STREAM_SEEK( name->stringOffset ) ||
             FT_FRAME_ENTER( name->stringLength ) )
        {
          FT_FREE( result );
          name->stringLength = 0;
          name->stringOffset = 0;
          FT_FREE( name->string );

          goto Exit;
        }

        p = (FT_Byte*)stream->cursor;

        for ( ; len > 0; len--, p += 2 )
        {
          if ( p[0] == 0 && p[1] >= 32 && p[1] < 128 )
            *r++ = p[1];
        }
        *r = '\0';

        FT_FRAME_EXIT();
      }
      goto Exit;
    }

    if ( found_apple != -1 )
    {
      FT_Memory         memory = face->root.memory;
      TT_NameEntryRec*  name   = face->name_table.names + found_apple;
      FT_UInt           len    = name->stringLength;
      FT_Error          error  = SFNT_Err_Ok;

      FT_UNUSED( error );


      if ( !FT_ALLOC( result, len + 1 ) )
      {
        FT_Stream  stream = face->name_table.stream;


        if ( FT_STREAM_SEEK( name->stringOffset ) ||
             FT_STREAM_READ( result, len )        )
        {
          name->stringOffset = 0;
          name->stringLength = 0;
          FT_FREE( name->string );
          FT_FREE( result );
          goto Exit;
        }
        ((char*)result)[len] = '\0';
      }
    }

  Exit:
    face->postscript_name = result;
    return result;
  }

