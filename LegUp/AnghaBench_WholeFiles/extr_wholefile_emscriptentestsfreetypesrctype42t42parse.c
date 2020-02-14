#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_38__   TYPE_9__ ;
typedef  struct TYPE_37__   TYPE_8__ ;
typedef  struct TYPE_36__   TYPE_7__ ;
typedef  struct TYPE_35__   TYPE_6__ ;
typedef  struct TYPE_34__   TYPE_5__ ;
typedef  struct TYPE_33__   TYPE_4__ ;
typedef  struct TYPE_32__   TYPE_3__ ;
typedef  struct TYPE_31__   TYPE_2__ ;
typedef  struct TYPE_30__   TYPE_1__ ;

/* Type definitions */
struct TYPE_38__ {TYPE_1__* ps_table_funcs; } ;
struct TYPE_37__ {char** elements; int* lengths; } ;
struct TYPE_36__ {scalar_t__ type; int location; int /*<<< orphan*/  (* reader ) (int /*<<< orphan*/ ,TYPE_5__*) ;} ;
struct TYPE_32__ {int /*<<< orphan*/  font_bbox; int /*<<< orphan*/  font_extra; int /*<<< orphan*/  font_info; } ;
struct TYPE_35__ {char* ttf_data; int ttf_size; TYPE_3__ type1; int /*<<< orphan*/  psaux; } ;
struct TYPE_31__ {char* limit; char* cursor; void* error; int /*<<< orphan*/  memory; } ;
struct TYPE_33__ {TYPE_2__ root; } ;
struct TYPE_34__ {size_t num_glyphs; TYPE_4__ parser; TYPE_8__ swap_table; TYPE_8__ glyph_names; TYPE_8__ charstrings; } ;
struct TYPE_30__ {void* (* init ) (TYPE_8__*,int,int /*<<< orphan*/ ) ;} ;
typedef  TYPE_4__* T42_Parser ;
typedef  TYPE_5__* T42_Loader ;
typedef  int T42_Load_Status ;
typedef  TYPE_6__* T42_Face ;
typedef  TYPE_7__* T1_Field ;
typedef  TYPE_8__* PS_Table ;
typedef  TYPE_9__* PSAux_Service ;
typedef  int FT_ULong ;
typedef  size_t FT_UInt ;
typedef  int FT_PtrDist ;
typedef  int /*<<< orphan*/  FT_Memory ;
typedef  int FT_Long ;
typedef  int FT_Int ;
typedef  int /*<<< orphan*/  FT_Face ;
typedef  void* FT_Error ;
typedef  char FT_Byte ;
typedef  int FT_Bool ;

/* Variables and functions */
#define  BEFORE_START 133 
#define  BEFORE_TABLE_DIR 132 
 int /*<<< orphan*/  FT_ERROR (char*) ; 
 int /*<<< orphan*/  FT_FREE (char*) ; 
 int FT_PEEK_ULONG (char*) ; 
 scalar_t__ FT_REALLOC (char*,int,int) ; 
#define  OTHER_TABLES 131 
 void* T1_Add_Table (TYPE_8__*,size_t,char*,int) ; 
#define  T1_FIELD_LOCATION_BBOX 130 
#define  T1_FIELD_LOCATION_FONT_EXTRA 129 
#define  T1_FIELD_LOCATION_FONT_INFO 128 
 scalar_t__ T1_FIELD_TYPE_CALLBACK ; 
 scalar_t__ T1_FIELD_TYPE_FIXED_ARRAY ; 
 scalar_t__ T1_FIELD_TYPE_INTEGER_ARRAY ; 
 void* T1_Load_Field (TYPE_4__*,TYPE_7__*,void**,size_t,int /*<<< orphan*/ ) ; 
 void* T1_Load_Field_Table (TYPE_4__*,TYPE_7__*,void**,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  T1_Skip_PS_Token (TYPE_4__*) ; 
 int /*<<< orphan*/  T1_Skip_Spaces (TYPE_4__*) ; 
 int /*<<< orphan*/  T1_ToBytes (TYPE_4__*,char*,int,int*,int) ; 
 int T1_ToInt (TYPE_4__*) ; 
 void* T42_Err_Invalid_File_Format ; 
 scalar_t__ ft_isdigit (char) ; 
 scalar_t__ ft_strcmp (char const*,char const*) ; 
 void* stub1 (TYPE_8__*,size_t,int /*<<< orphan*/ ) ; 
 void* stub2 (TYPE_8__*,size_t,int /*<<< orphan*/ ) ; 
 void* stub3 (TYPE_8__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ ,TYPE_5__*) ; 
 scalar_t__ t42_is_space (char) ; 

__attribute__((used)) static void
  t42_parse_sfnts( T42_Face    face,
                   T42_Loader  loader )
  {
    T42_Parser  parser = &loader->parser;
    FT_Memory   memory = parser->root.memory;
    FT_Byte*    cur;
    FT_Byte*    limit  = parser->root.limit;
    FT_Error    error;
    FT_Int      num_tables = 0;
    FT_ULong    count, ttf_size = 0;

    FT_Long     n, string_size, old_string_size, real_size;
    FT_Byte*    string_buf = NULL;
    FT_Bool     allocated  = 0;

    T42_Load_Status  status;


    /* The format is                                */
    /*                                              */
    /*   /sfnts [ <hexstring> <hexstring> ... ] def */
    /*                                              */
    /* or                                           */
    /*                                              */
    /*   /sfnts [                                   */
    /*      <num_bin_bytes> RD <binary data>        */
    /*      <num_bin_bytes> RD <binary data>        */
    /*      ...                                     */
    /*   ] def                                      */
    /*                                              */
    /* with exactly one space after the `RD' token. */

    T1_Skip_Spaces( parser );

    if ( parser->root.cursor >= limit || *parser->root.cursor++ != '[' )
    {
      FT_ERROR(( "t42_parse_sfnts: can't find begin of sfnts vector\n" ));
      error = T42_Err_Invalid_File_Format;
      goto Fail;
    }

    T1_Skip_Spaces( parser );
    status          = BEFORE_START;
    string_size     = 0;
    old_string_size = 0;
    count           = 0;

    while ( parser->root.cursor < limit )
    {
      cur = parser->root.cursor;

      if ( *cur == ']' )
      {
        parser->root.cursor++;
        goto Exit;
      }

      else if ( *cur == '<' )
      {
        T1_Skip_PS_Token( parser );
        if ( parser->root.error )
          goto Exit;

        /* don't include delimiters */
        string_size = (FT_Long)( ( parser->root.cursor - cur - 2 + 1 ) / 2 );
        if ( FT_REALLOC( string_buf, old_string_size, string_size ) )
          goto Fail;

        allocated = 1;

        parser->root.cursor = cur;
        (void)T1_ToBytes( parser, string_buf, string_size, &real_size, 1 );
        old_string_size = string_size;
        string_size = real_size;
      }

      else if ( ft_isdigit( *cur ) )
      {
        if ( allocated )
        {
          FT_ERROR(( "t42_parse_sfnts: "
                     "can't handle mixed binary and hex strings\n" ));
          error = T42_Err_Invalid_File_Format;
          goto Fail;
        }

        string_size = T1_ToInt( parser );
        if ( string_size < 0 )
        {
          FT_ERROR(( "t42_parse_sfnts: invalid string size\n" ));
          error = T42_Err_Invalid_File_Format;
          goto Fail;
        }

        T1_Skip_PS_Token( parser );             /* `RD' */
        if ( parser->root.error )
          return;

        string_buf = parser->root.cursor + 1;   /* one space after `RD' */

        if ( limit - parser->root.cursor < string_size )
        {
          FT_ERROR(( "t42_parse_sfnts: too many binary data\n" ));
          error = T42_Err_Invalid_File_Format;
          goto Fail;
        }
        else
          parser->root.cursor += string_size + 1;
      }

      if ( !string_buf )
      {
        FT_ERROR(( "t42_parse_sfnts: invalid data in sfnts array\n" ));
        error = T42_Err_Invalid_File_Format;
        goto Fail;
      }

      /* A string can have a trailing zero byte for padding.  Ignore it. */
      if ( string_buf[string_size - 1] == 0 && ( string_size % 2 == 1 ) )
        string_size--;

      if ( !string_size )
      {
        FT_ERROR(( "t42_parse_sfnts: invalid string\n" ));
        error = T42_Err_Invalid_File_Format;
        goto Fail;
      }

      for ( n = 0; n < string_size; n++ )
      {
        switch ( status )
        {
        case BEFORE_START:
          /* load offset table, 12 bytes */
          if ( count < 12 )
          {
            face->ttf_data[count++] = string_buf[n];
            continue;
          }
          else
          {
            num_tables = 16 * face->ttf_data[4] + face->ttf_data[5];
            status     = BEFORE_TABLE_DIR;
            ttf_size   = 12 + 16 * num_tables;

            if ( FT_REALLOC( face->ttf_data, 12, ttf_size ) )
              goto Fail;
          }
          /* fall through */

        case BEFORE_TABLE_DIR:
          /* the offset table is read; read the table directory */
          if ( count < ttf_size )
          {
            face->ttf_data[count++] = string_buf[n];
            continue;
          }
          else
          {
            int       i;
            FT_ULong  len;


            for ( i = 0; i < num_tables; i++ )
            {
              FT_Byte*  p = face->ttf_data + 12 + 16 * i + 12;


              len = FT_PEEK_ULONG( p );

              /* Pad to a 4-byte boundary length */
              ttf_size += ( len + 3 ) & ~3;
            }

            status         = OTHER_TABLES;
            face->ttf_size = ttf_size;

            /* there are no more than 256 tables, so no size check here */
            if ( FT_REALLOC( face->ttf_data, 12 + 16 * num_tables,
                             ttf_size + 1 ) )
              goto Fail;
          }
          /* fall through */

        case OTHER_TABLES:
          /* all other tables are just copied */
          if ( count >= ttf_size )
          {
            FT_ERROR(( "t42_parse_sfnts: too many binary data\n" ));
            error = T42_Err_Invalid_File_Format;
            goto Fail;
          }
          face->ttf_data[count++] = string_buf[n];
        }
      }

      T1_Skip_Spaces( parser );
    }

    /* if control reaches this point, the format was not valid */
    error = T42_Err_Invalid_File_Format;

  Fail:
    parser->root.error = error;

  Exit:
    if ( allocated )
      FT_FREE( string_buf );
  }

__attribute__((used)) static void
  t42_parse_charstrings( T42_Face    face,
                         T42_Loader  loader )
  {
    T42_Parser     parser       = &loader->parser;
    PS_Table       code_table   = &loader->charstrings;
    PS_Table       name_table   = &loader->glyph_names;
    PS_Table       swap_table   = &loader->swap_table;
    FT_Memory      memory       = parser->root.memory;
    FT_Error       error;

    PSAux_Service  psaux        = (PSAux_Service)face->psaux;

    FT_Byte*       cur;
    FT_Byte*       limit        = parser->root.limit;
    FT_UInt        n;
    FT_UInt        notdef_index = 0;
    FT_Byte        notdef_found = 0;


    T1_Skip_Spaces( parser );

    if ( parser->root.cursor >= limit )
    {
      FT_ERROR(( "t42_parse_charstrings: out of bounds\n" ));
      error = T42_Err_Invalid_File_Format;
      goto Fail;
    }

    if ( ft_isdigit( *parser->root.cursor ) )
    {
      loader->num_glyphs = (FT_UInt)T1_ToInt( parser );
      if ( parser->root.error )
        return;
    }
    else if ( *parser->root.cursor == '<' )
    {
      /* We have `<< ... >>'.  Count the number of `/' in the dictionary */
      /* to get its size.                                                */
      FT_UInt  count = 0;


      T1_Skip_PS_Token( parser );
      if ( parser->root.error )
        return;
      T1_Skip_Spaces( parser );
      cur = parser->root.cursor;

      while ( parser->root.cursor < limit )
      {
        if ( *parser->root.cursor == '/' )
          count++;
        else if ( *parser->root.cursor == '>' )
        {
          loader->num_glyphs  = count;
          parser->root.cursor = cur;        /* rewind */
          break;
        }
        T1_Skip_PS_Token( parser );
        if ( parser->root.error )
          return;
        T1_Skip_Spaces( parser );
      }
    }
    else
    {
      FT_ERROR(( "t42_parse_charstrings: invalid token\n" ));
      error = T42_Err_Invalid_File_Format;
      goto Fail;
    }

    if ( parser->root.cursor >= limit )
    {
      FT_ERROR(( "t42_parse_charstrings: out of bounds\n" ));
      error = T42_Err_Invalid_File_Format;
      goto Fail;
    }

    /* initialize tables */

    error = psaux->ps_table_funcs->init( code_table,
                                         loader->num_glyphs,
                                         memory );
    if ( error )
      goto Fail;

    error = psaux->ps_table_funcs->init( name_table,
                                         loader->num_glyphs,
                                         memory );
    if ( error )
      goto Fail;

    /* Initialize table for swapping index notdef_index and */
    /* index 0 names and codes (if necessary).              */

    error = psaux->ps_table_funcs->init( swap_table, 4, memory );
    if ( error )
      goto Fail;

    n = 0;

    for (;;)
    {
      /* The format is simple:                   */
      /*   `/glyphname' + index [+ def]          */

      T1_Skip_Spaces( parser );

      cur = parser->root.cursor;
      if ( cur >= limit )
        break;

      /* We stop when we find an `end' keyword or '>' */
      if ( *cur   == 'e'          &&
           cur + 3 < limit        &&
           cur[1] == 'n'          &&
           cur[2] == 'd'          &&
           t42_is_space( cur[3] ) )
        break;
      if ( *cur == '>' )
        break;

      T1_Skip_PS_Token( parser );
      if ( parser->root.error )
        return;

      if ( *cur == '/' )
      {
        FT_PtrDist  len;


        if ( cur + 1 >= limit )
        {
          FT_ERROR(( "t42_parse_charstrings: out of bounds\n" ));
          error = T42_Err_Invalid_File_Format;
          goto Fail;
        }

        cur++;                              /* skip `/' */
        len = parser->root.cursor - cur;

        error = T1_Add_Table( name_table, n, cur, len + 1 );
        if ( error )
          goto Fail;

        /* add a trailing zero to the name table */
        name_table->elements[n][len] = '\0';

        /* record index of /.notdef */
        if ( *cur == '.'                                              &&
             ft_strcmp( ".notdef",
                        (const char*)(name_table->elements[n]) ) == 0 )
        {
          notdef_index = n;
          notdef_found = 1;
        }

        T1_Skip_Spaces( parser );

        cur = parser->root.cursor;

        (void)T1_ToInt( parser );
        if ( parser->root.cursor >= limit )
        {
          FT_ERROR(( "t42_parse_charstrings: out of bounds\n" ));
          error = T42_Err_Invalid_File_Format;
          goto Fail;
        }

        len = parser->root.cursor - cur;

        error = T1_Add_Table( code_table, n, cur, len + 1 );
        if ( error )
          goto Fail;

        code_table->elements[n][len] = '\0';

        n++;
        if ( n >= loader->num_glyphs )
          break;
      }
    }

    loader->num_glyphs = n;

    if ( !notdef_found )
    {
      FT_ERROR(( "t42_parse_charstrings: no /.notdef glyph\n" ));
      error = T42_Err_Invalid_File_Format;
      goto Fail;
    }

    /* if /.notdef does not occupy index 0, do our magic. */
    if ( ft_strcmp( (const char*)".notdef",
                    (const char*)name_table->elements[0] ) )
    {
      /* Swap glyph in index 0 with /.notdef glyph.  First, add index 0  */
      /* name and code entries to swap_table.  Then place notdef_index   */
      /* name and code entries into swap_table.  Then swap name and code */
      /* entries at indices notdef_index and 0 using values stored in    */
      /* swap_table.                                                     */

      /* Index 0 name */
      error = T1_Add_Table( swap_table, 0,
                            name_table->elements[0],
                            name_table->lengths [0] );
      if ( error )
        goto Fail;

      /* Index 0 code */
      error = T1_Add_Table( swap_table, 1,
                            code_table->elements[0],
                            code_table->lengths [0] );
      if ( error )
        goto Fail;

      /* Index notdef_index name */
      error = T1_Add_Table( swap_table, 2,
                            name_table->elements[notdef_index],
                            name_table->lengths [notdef_index] );
      if ( error )
        goto Fail;

      /* Index notdef_index code */
      error = T1_Add_Table( swap_table, 3,
                            code_table->elements[notdef_index],
                            code_table->lengths [notdef_index] );
      if ( error )
        goto Fail;

      error = T1_Add_Table( name_table, notdef_index,
                            swap_table->elements[0],
                            swap_table->lengths [0] );
      if ( error )
        goto Fail;

      error = T1_Add_Table( code_table, notdef_index,
                            swap_table->elements[1],
                            swap_table->lengths [1] );
      if ( error )
        goto Fail;

      error = T1_Add_Table( name_table, 0,
                            swap_table->elements[2],
                            swap_table->lengths [2] );
      if ( error )
        goto Fail;

      error = T1_Add_Table( code_table, 0,
                            swap_table->elements[3],
                            swap_table->lengths [3] );
      if ( error )
        goto Fail;

    }

    return;

  Fail:
    parser->root.error = error;
  }

__attribute__((used)) static FT_Error
  t42_load_keyword( T42_Face    face,
                    T42_Loader  loader,
                    T1_Field    field )
  {
    FT_Error  error;
    void*     dummy_object;
    void**    objects;
    FT_UInt   max_objects = 0;


    /* if the keyword has a dedicated callback, call it */
    if ( field->type == T1_FIELD_TYPE_CALLBACK )
    {
      field->reader( (FT_Face)face, loader );
      error = loader->parser.root.error;
      goto Exit;
    }

    /* now the keyword is either a simple field or a table of fields; */
    /* we are now going to take care of it                            */

    switch ( field->location )
    {
    case T1_FIELD_LOCATION_FONT_INFO:
      dummy_object = &face->type1.font_info;
      break;

    case T1_FIELD_LOCATION_FONT_EXTRA:
      dummy_object = &face->type1.font_extra;
      break;

    case T1_FIELD_LOCATION_BBOX:
      dummy_object = &face->type1.font_bbox;
      break;

    default:
      dummy_object = &face->type1;
    }

    objects = &dummy_object;

    if ( field->type == T1_FIELD_TYPE_INTEGER_ARRAY ||
         field->type == T1_FIELD_TYPE_FIXED_ARRAY   )
      error = T1_Load_Field_Table( &loader->parser, field,
                                   objects, max_objects, 0 );
    else
      error = T1_Load_Field( &loader->parser, field,
                             objects, max_objects, 0 );

   Exit:
    return error;
  }

