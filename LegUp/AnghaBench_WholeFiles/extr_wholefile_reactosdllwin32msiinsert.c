#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_62__   TYPE_9__ ;
typedef  struct TYPE_61__   TYPE_8__ ;
typedef  struct TYPE_60__   TYPE_7__ ;
typedef  struct TYPE_59__   TYPE_6__ ;
typedef  struct TYPE_58__   TYPE_5__ ;
typedef  struct TYPE_57__   TYPE_4__ ;
typedef  struct TYPE_56__   TYPE_3__ ;
typedef  struct TYPE_55__   TYPE_2__ ;
typedef  struct TYPE_54__   TYPE_1__ ;

/* Type definitions */
struct tagMSIVIEW {int dummy; } ;
struct TYPE_58__ {struct TYPE_58__* next; TYPE_2__* val; } ;
typedef  TYPE_5__ column_info ;
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int UINT ;
struct TYPE_62__ {int /*<<< orphan*/  hdr; } ;
struct TYPE_57__ {int /*<<< orphan*/ * ops; } ;
struct TYPE_61__ {TYPE_6__* sv; void* bIsTemp; TYPE_5__* vals; TYPE_9__* db; TYPE_6__* table; TYPE_4__ view; } ;
struct TYPE_60__ {int /*<<< orphan*/  hdr; } ;
struct TYPE_59__ {TYPE_3__* ops; } ;
struct TYPE_56__ {int (* get_column_info ) (TYPE_6__*,int,int /*<<< orphan*/ *,int*,void**,int /*<<< orphan*/ *) ;int (* get_dimensions ) (TYPE_6__*,int*,int*) ;int (* execute ) (TYPE_6__*,int /*<<< orphan*/ ) ;int (* insert_row ) (TYPE_6__*,TYPE_7__*,int,void*) ;int (* close ) (TYPE_6__*) ;int /*<<< orphan*/  (* delete ) (TYPE_6__*) ;} ;
struct TYPE_54__ {int /*<<< orphan*/  ival; int /*<<< orphan*/  sval; } ;
struct TYPE_55__ {int type; TYPE_1__ u; } ;
typedef  TYPE_6__ MSIVIEW ;
typedef  TYPE_7__ MSIRECORD ;
typedef  int /*<<< orphan*/  MSIMODIFY ;
typedef  int /*<<< orphan*/  MSIITERHANDLE ;
typedef  TYPE_8__ MSIINSERTVIEW ;
typedef  TYPE_9__ MSIDATABASE ;
typedef  int /*<<< orphan*/ * LPWSTR ;
typedef  char* LPSTR ;
typedef  int /*<<< orphan*/  LPCWSTR ;
typedef  int /*<<< orphan*/  LPCSTR ;
typedef  int DWORD ;
typedef  void* BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CP_ACP ; 
 int /*<<< orphan*/  ERR (char*,int) ; 
 int ERROR_BAD_QUERY_SYNTAX ; 
 int ERROR_FUNCTION_FAILED ; 
 int ERROR_OUTOFMEMORY ; 
 int ERROR_SUCCESS ; 
#define  EXPR_IVAL 130 
#define  EXPR_SVAL 129 
#define  EXPR_WILDCARD 128 
 void* FALSE ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 void* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t) ; 
 void* HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 void* HeapReAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,size_t) ; 
 int MSITYPE_KEY ; 
 TYPE_7__* MSI_CreateRecord (int) ; 
 int /*<<< orphan*/  MSI_RecordCopyField (TYPE_7__*,int,TYPE_7__*,int) ; 
 int MSI_RecordGetFieldCount (TYPE_7__*) ; 
 scalar_t__ MSI_RecordIsNull (TYPE_7__*,int) ; 
 int /*<<< orphan*/  MSI_RecordSetInteger (TYPE_7__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MSI_RecordSetStringW (TYPE_7__*,int,int /*<<< orphan*/ ) ; 
 int MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int) ; 
 int SELECT_CreateView (TYPE_9__*,TYPE_6__**,TYPE_6__*,TYPE_5__*) ; 
 int TABLE_CreateView (TYPE_9__*,int /*<<< orphan*/ ,TYPE_6__**) ; 
 int /*<<< orphan*/  TRACE (char*,...) ; 
 void* TRUE ; 
 int WideCharToMultiByte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  debugstr_w (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  insert_ops ; 
 int /*<<< orphan*/  lstrcpyW (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int lstrlenW (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msiobj_addref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  msiobj_release (int /*<<< orphan*/ *) ; 
 scalar_t__ strcmpW (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub1 (TYPE_6__*,int,int /*<<< orphan*/ *,int*,void**,int /*<<< orphan*/ *) ; 
 int stub10 (TYPE_6__*,TYPE_7__*,int,void*) ; 
 int stub11 (TYPE_6__*) ; 
 int stub12 (TYPE_6__*,int*,int*) ; 
 int stub13 (TYPE_6__*,int,int /*<<< orphan*/ *,int*,void**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub14 (TYPE_6__*) ; 
 int /*<<< orphan*/  stub15 (TYPE_6__*) ; 
 int stub2 (TYPE_6__*,int,int /*<<< orphan*/ *,int*,void**,int /*<<< orphan*/ *) ; 
 int stub3 (TYPE_6__*,int*,int*) ; 
 int stub4 (TYPE_6__*,int,int /*<<< orphan*/ *,int*,void**,int /*<<< orphan*/ *) ; 
 int stub5 (TYPE_6__*,int,int /*<<< orphan*/ *,int*,void**,int /*<<< orphan*/ *) ; 
 int stub6 (TYPE_6__*,int*,int*) ; 
 int stub7 (TYPE_6__*,int,int /*<<< orphan*/ *,int*,void**,int /*<<< orphan*/ *) ; 
 int stub8 (TYPE_6__*,int /*<<< orphan*/ ) ; 
 int stub9 (TYPE_6__*,int*,int*) ; 

__attribute__((used)) static inline void *msi_alloc( size_t len )
{
    return HeapAlloc( GetProcessHeap(), 0, len );
}

__attribute__((used)) static inline void *msi_alloc_zero( size_t len )
{
    return HeapAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, len );
}

__attribute__((used)) static inline void *msi_realloc( void *mem, size_t len )
{
    return HeapReAlloc( GetProcessHeap(), 0, mem, len );
}

__attribute__((used)) static inline void *msi_realloc_zero( void *mem, size_t len )
{
    return HeapReAlloc( GetProcessHeap(), HEAP_ZERO_MEMORY, mem, len );
}

__attribute__((used)) static inline BOOL msi_free( void *mem )
{
    return HeapFree( GetProcessHeap(), 0, mem );
}

__attribute__((used)) static inline char *strdupWtoA( LPCWSTR str )
{
    LPSTR ret = NULL;
    DWORD len;

    if (!str) return ret;
    len = WideCharToMultiByte( CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
    ret = msi_alloc( len );
    if (ret)
        WideCharToMultiByte( CP_ACP, 0, str, -1, ret, len, NULL, NULL );
    return ret;
}

__attribute__((used)) static inline LPWSTR strdupAtoW( LPCSTR str )
{
    LPWSTR ret = NULL;
    DWORD len;

    if (!str) return ret;
    len = MultiByteToWideChar( CP_ACP, 0, str, -1, NULL, 0 );
    ret = msi_alloc( len * sizeof(WCHAR) );
    if (ret)
        MultiByteToWideChar( CP_ACP, 0, str, -1, ret, len );
    return ret;
}

__attribute__((used)) static inline LPWSTR strdupW( LPCWSTR src )
{
    LPWSTR dest;
    if (!src) return NULL;
    dest = msi_alloc( (lstrlenW(src)+1)*sizeof(WCHAR) );
    if (dest)
        lstrcpyW(dest, src);
    return dest;
}

__attribute__((used)) static UINT INSERT_fetch_int( struct tagMSIVIEW *view, UINT row, UINT col, UINT *val )
{
    MSIINSERTVIEW *iv = (MSIINSERTVIEW*)view;

    TRACE("%p %d %d %p\n", iv, row, col, val );

    return ERROR_FUNCTION_FAILED;
}

MSIRECORD *msi_query_merge_record( UINT fields, const column_info *vl, MSIRECORD *rec )
{
    MSIRECORD *merged;
    DWORD wildcard_count = 1, i;

    merged = MSI_CreateRecord( fields );
    for( i=1; i <= fields; i++ )
    {
        if( !vl )
        {
            TRACE("Not enough elements in the list to insert\n");
            goto err;
        }
        switch( vl->val->type )
        {
        case EXPR_SVAL:
            TRACE("field %d -> %s\n", i, debugstr_w(vl->val->u.sval));
            MSI_RecordSetStringW( merged, i, vl->val->u.sval );
            break;
        case EXPR_IVAL:
            MSI_RecordSetInteger( merged, i, vl->val->u.ival );
            break;
        case EXPR_WILDCARD:
            if( !rec )
                goto err;
            MSI_RecordCopyField( rec, wildcard_count, merged, i );
            wildcard_count++;
            break;
        default:
            ERR("Unknown expression type %d\n", vl->val->type);
        }
        vl = vl->next;
    }

    return merged;
err:
    msiobj_release( &merged->hdr );
    return NULL;
}

__attribute__((used)) static BOOL msi_columns_in_order(MSIINSERTVIEW *iv, UINT col_count)
{
    LPCWSTR a, b;
    UINT i;

    for (i = 1; i <= col_count; i++)
    {
        iv->sv->ops->get_column_info(iv->sv, i, &a, NULL, NULL, NULL);
        iv->table->ops->get_column_info(iv->table, i, &b, NULL, NULL, NULL);

        if (strcmpW( a, b )) return FALSE;
    }
    return TRUE;
}

__attribute__((used)) static UINT msi_arrange_record(MSIINSERTVIEW *iv, MSIRECORD **values)
{
    MSIRECORD *padded;
    UINT col_count, val_count;
    UINT r, i, colidx;
    LPCWSTR a, b;

    r = iv->table->ops->get_dimensions(iv->table, NULL, &col_count);
    if (r != ERROR_SUCCESS)
        return r;

    val_count = MSI_RecordGetFieldCount(*values);

    /* check to see if the columns are arranged already
     * to avoid unnecessary copying
     */
    if (col_count == val_count && msi_columns_in_order(iv, col_count))
        return ERROR_SUCCESS;

    padded = MSI_CreateRecord(col_count);
    if (!padded)
        return ERROR_OUTOFMEMORY;

    for (colidx = 1; colidx <= val_count; colidx++)
    {
        r = iv->sv->ops->get_column_info(iv->sv, colidx, &a, NULL, NULL, NULL);
        if (r != ERROR_SUCCESS)
            goto err;

        for (i = 1; i <= col_count; i++)
        {
            r = iv->table->ops->get_column_info(iv->table, i, &b, NULL,
                                                NULL, NULL);
            if (r != ERROR_SUCCESS)
                goto err;

            if (!strcmpW( a, b ))
            {
                MSI_RecordCopyField(*values, colidx, padded, i);
                break;
            }
        }
    }
    msiobj_release(&(*values)->hdr);
    *values = padded;
    return ERROR_SUCCESS;

err:
    msiobj_release(&padded->hdr);
    return r;
}

__attribute__((used)) static BOOL row_has_null_primary_keys(MSIINSERTVIEW *iv, MSIRECORD *row)
{
    UINT r, i, col_count, type;

    r = iv->table->ops->get_dimensions( iv->table, NULL, &col_count );
    if (r != ERROR_SUCCESS)
        return FALSE;

    for (i = 1; i <= col_count; i++)
    {
        r = iv->table->ops->get_column_info(iv->table, i, NULL, &type,
                                            NULL, NULL);
        if (r != ERROR_SUCCESS)
            return FALSE;

        if (!(type & MSITYPE_KEY))
            continue;

        if (MSI_RecordIsNull(row, i))
            return TRUE;
    }

    return FALSE;
}

__attribute__((used)) static UINT INSERT_execute( struct tagMSIVIEW *view, MSIRECORD *record )
{
    MSIINSERTVIEW *iv = (MSIINSERTVIEW*)view;
    UINT r, row = -1, col_count = 0;
    MSIVIEW *sv;
    MSIRECORD *values = NULL;

    TRACE("%p %p\n", iv, record );

    sv = iv->sv;
    if( !sv )
        return ERROR_FUNCTION_FAILED;

    r = sv->ops->execute( sv, 0 );
    TRACE("sv execute returned %x\n", r);
    if( r )
        return r;

    r = sv->ops->get_dimensions( sv, NULL, &col_count );
    if( r )
        goto err;

    /*
     * Merge the wildcard values into the list of values provided
     * in the query, and create a record containing both.
     */
    values = msi_query_merge_record( col_count, iv->vals, record );
    if( !values )
        goto err;

    r = msi_arrange_record( iv, &values );
    if( r != ERROR_SUCCESS )
        goto err;

    /* rows with NULL primary keys are inserted at the beginning of the table */
    if( row_has_null_primary_keys( iv, values ) )
        row = 0;

    r = iv->table->ops->insert_row( iv->table, values, row, iv->bIsTemp );

err:
    if( values )
        msiobj_release( &values->hdr );

    return r;
}

__attribute__((used)) static UINT INSERT_close( struct tagMSIVIEW *view )
{
    MSIINSERTVIEW *iv = (MSIINSERTVIEW*)view;
    MSIVIEW *sv;

    TRACE("%p\n", iv);

    sv = iv->sv;
    if( !sv )
        return ERROR_FUNCTION_FAILED;

    return sv->ops->close( sv );
}

__attribute__((used)) static UINT INSERT_get_dimensions( struct tagMSIVIEW *view, UINT *rows, UINT *cols )
{
    MSIINSERTVIEW *iv = (MSIINSERTVIEW*)view;
    MSIVIEW *sv;

    TRACE("%p %p %p\n", iv, rows, cols );

    sv = iv->sv;
    if( !sv )
        return ERROR_FUNCTION_FAILED;

    return sv->ops->get_dimensions( sv, rows, cols );
}

__attribute__((used)) static UINT INSERT_get_column_info( struct tagMSIVIEW *view, UINT n, LPCWSTR *name,
                                    UINT *type, BOOL *temporary, LPCWSTR *table_name )
{
    MSIINSERTVIEW *iv = (MSIINSERTVIEW*)view;
    MSIVIEW *sv;

    TRACE("%p %d %p %p %p %p\n", iv, n, name, type, temporary, table_name );

    sv = iv->sv;
    if( !sv )
        return ERROR_FUNCTION_FAILED;

    return sv->ops->get_column_info( sv, n, name, type, temporary, table_name );
}

__attribute__((used)) static UINT INSERT_modify( struct tagMSIVIEW *view, MSIMODIFY eModifyMode, MSIRECORD *rec, UINT row)
{
    MSIINSERTVIEW *iv = (MSIINSERTVIEW*)view;

    TRACE("%p %d %p\n", iv, eModifyMode, rec );

    return ERROR_FUNCTION_FAILED;
}

__attribute__((used)) static UINT INSERT_delete( struct tagMSIVIEW *view )
{
    MSIINSERTVIEW *iv = (MSIINSERTVIEW*)view;
    MSIVIEW *sv;

    TRACE("%p\n", iv );

    sv = iv->sv;
    if( sv )
        sv->ops->delete( sv );
    msiobj_release( &iv->db->hdr );
    msi_free( iv );

    return ERROR_SUCCESS;
}

__attribute__((used)) static UINT INSERT_find_matching_rows( struct tagMSIVIEW *view, UINT col,
    UINT val, UINT *row, MSIITERHANDLE *handle )
{
    TRACE("%p, %d, %u, %p\n", view, col, val, *handle);

    return ERROR_FUNCTION_FAILED;
}

__attribute__((used)) static UINT count_column_info( const column_info *ci )
{
    UINT n = 0;
    for ( ; ci; ci = ci->next )
        n++;
    return n;
}

UINT INSERT_CreateView( MSIDATABASE *db, MSIVIEW **view, LPCWSTR table,
                        column_info *columns, column_info *values, BOOL temp )
{
    MSIINSERTVIEW *iv = NULL;
    UINT r;
    MSIVIEW *tv = NULL, *sv = NULL;

    TRACE("%p\n", iv );

    /* there should be one value for each column */
    if ( count_column_info( columns ) != count_column_info(values) )
        return ERROR_BAD_QUERY_SYNTAX;

    r = TABLE_CreateView( db, table, &tv );
    if( r != ERROR_SUCCESS )
        return r;

    r = SELECT_CreateView( db, &sv, tv, columns );
    if( r != ERROR_SUCCESS )
    {
        if( tv )
            tv->ops->delete( tv );
        return r;
    }

    iv = msi_alloc_zero( sizeof *iv );
    if( !iv )
        return ERROR_FUNCTION_FAILED;

    /* fill the structure */
    iv->view.ops = &insert_ops;
    msiobj_addref( &db->hdr );
    iv->table = tv;
    iv->db = db;
    iv->vals = values;
    iv->bIsTemp = temp;
    iv->sv = sv;
    *view = (MSIVIEW*) iv;

    return ERROR_SUCCESS;
}

