#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_45__   TYPE_7__ ;
typedef  struct TYPE_44__   TYPE_6__ ;
typedef  struct TYPE_43__   TYPE_5__ ;
typedef  struct TYPE_42__   TYPE_4__ ;
typedef  struct TYPE_41__   TYPE_3__ ;
typedef  struct TYPE_40__   TYPE_2__ ;
typedef  struct TYPE_39__   TYPE_1__ ;

/* Type definitions */
struct tagMSIVIEW {int dummy; } ;
struct expr {int dummy; } ;
struct TYPE_41__ {struct TYPE_41__* next; } ;
typedef  TYPE_3__ column_info ;
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int UINT ;
struct TYPE_45__ {int /*<<< orphan*/  hdr; } ;
struct TYPE_44__ {int /*<<< orphan*/  hdr; } ;
struct TYPE_39__ {int /*<<< orphan*/ * ops; } ;
struct TYPE_43__ {TYPE_4__* wv; TYPE_3__* vals; TYPE_7__* db; TYPE_1__ view; } ;
struct TYPE_42__ {TYPE_2__* ops; } ;
struct TYPE_40__ {int (* execute ) (TYPE_4__*,TYPE_6__*) ;int (* get_dimensions ) (TYPE_4__*,int*,int*) ;int (* set_row ) (TYPE_4__*,int,TYPE_6__*,int) ;int (* close ) (TYPE_4__*) ;int (* get_column_info ) (TYPE_4__*,int,int /*<<< orphan*/ *,int*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* delete ) (TYPE_4__*) ;} ;
typedef  TYPE_4__ MSIVIEW ;
typedef  TYPE_5__ MSIUPDATEVIEW ;
typedef  TYPE_6__ MSIRECORD ;
typedef  int /*<<< orphan*/  MSIMODIFY ;
typedef  int /*<<< orphan*/  MSIITERHANDLE ;
typedef  TYPE_7__ MSIDATABASE ;
typedef  int /*<<< orphan*/ * LPWSTR ;
typedef  char* LPSTR ;
typedef  int /*<<< orphan*/  LPCWSTR ;
typedef  int /*<<< orphan*/  LPCSTR ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  CP_ACP ; 
 int ERROR_FUNCTION_FAILED ; 
 int ERROR_SUCCESS ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 void* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 void* HeapReAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,size_t) ; 
 TYPE_6__* MSI_CreateRecord (int) ; 
 int /*<<< orphan*/  MSI_RecordCopyField (TYPE_6__*,int,TYPE_6__*,int) ; 
 int MSI_RecordGetFieldCount (TYPE_6__*) ; 
 int MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int) ; 
 int SELECT_CreateView (TYPE_7__*,TYPE_4__**,TYPE_4__*,TYPE_3__*) ; 
 int TABLE_CreateView (TYPE_7__*,int /*<<< orphan*/ *,TYPE_4__**) ; 
 int /*<<< orphan*/  TRACE (char*,...) ; 
 int WHERE_CreateView (TYPE_7__*,TYPE_4__**,int /*<<< orphan*/ *,struct expr*) ; 
 int WideCharToMultiByte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lstrcpyW (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int lstrlenW (int /*<<< orphan*/ ) ; 
 TYPE_6__* msi_query_merge_record (int,TYPE_3__*,TYPE_6__*) ; 
 int /*<<< orphan*/  msiobj_addref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  msiobj_release (int /*<<< orphan*/ *) ; 
 int stub1 (TYPE_4__*,TYPE_6__*) ; 
 int stub2 (TYPE_4__*,int*,int*) ; 
 int stub3 (TYPE_4__*,int,TYPE_6__*,int) ; 
 int stub4 (TYPE_4__*) ; 
 int stub5 (TYPE_4__*,int*,int*) ; 
 int stub6 (TYPE_4__*,int,int /*<<< orphan*/ *,int*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub7 (TYPE_4__*) ; 
 int /*<<< orphan*/  stub8 (TYPE_4__*) ; 
 int /*<<< orphan*/  stub9 (TYPE_4__*) ; 
 int /*<<< orphan*/  update_ops ; 

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

__attribute__((used)) static UINT UPDATE_fetch_int( struct tagMSIVIEW *view, UINT row, UINT col, UINT *val )
{
    MSIUPDATEVIEW *uv = (MSIUPDATEVIEW*)view;

    TRACE("%p %d %d %p\n", uv, row, col, val );

    return ERROR_FUNCTION_FAILED;
}

__attribute__((used)) static UINT UPDATE_execute( struct tagMSIVIEW *view, MSIRECORD *record )
{
    MSIUPDATEVIEW *uv = (MSIUPDATEVIEW*)view;
    UINT i, r, col_count = 0, row_count = 0;
    MSIRECORD *values = NULL;
    MSIRECORD *where = NULL;
    MSIVIEW *wv;
    UINT cols_count, where_count;
    column_info *col = uv->vals;

    TRACE("%p %p\n", uv, record );

    /* extract the where markers from the record */
    if (record)
    {
        r = MSI_RecordGetFieldCount(record);

        for (i = 0; col; col = col->next)
            i++;

        cols_count = i;
        where_count = r - i;

        if (where_count > 0)
        {
            where = MSI_CreateRecord(where_count);

            if (where)
                for (i = 1; i <= where_count; i++)
                    MSI_RecordCopyField(record, cols_count + i, where, i);
        }
    }

    wv = uv->wv;
    if( !wv )
    {
        r = ERROR_FUNCTION_FAILED;
        goto done;
    }

    r = wv->ops->execute( wv, where );
    TRACE("tv execute returned %x\n", r);
    if( r )
        goto done;

    r = wv->ops->get_dimensions( wv, &row_count, &col_count );
    if( r )
        goto done;

    values = msi_query_merge_record( col_count, uv->vals, record );
    if (!values)
    {
        r = ERROR_FUNCTION_FAILED;
        goto done;
    }

    for ( i=0; i<row_count; i++ )
    {
        r = wv->ops->set_row( wv, i, values, (1 << col_count) - 1 );
        if (r != ERROR_SUCCESS)
            break;
    }

done:
    if ( where ) msiobj_release( &where->hdr );
    if ( values ) msiobj_release( &values->hdr );

    return r;
}

__attribute__((used)) static UINT UPDATE_close( struct tagMSIVIEW *view )
{
    MSIUPDATEVIEW *uv = (MSIUPDATEVIEW*)view;
    MSIVIEW *wv;

    TRACE("%p\n", uv);

    wv = uv->wv;
    if( !wv )
        return ERROR_FUNCTION_FAILED;

    return wv->ops->close( wv );
}

__attribute__((used)) static UINT UPDATE_get_dimensions( struct tagMSIVIEW *view, UINT *rows, UINT *cols )
{
    MSIUPDATEVIEW *uv = (MSIUPDATEVIEW*)view;
    MSIVIEW *wv;

    TRACE("%p %p %p\n", uv, rows, cols );

    wv = uv->wv;
    if( !wv )
        return ERROR_FUNCTION_FAILED;

    return wv->ops->get_dimensions( wv, rows, cols );
}

__attribute__((used)) static UINT UPDATE_get_column_info( struct tagMSIVIEW *view, UINT n, LPCWSTR *name,
                                    UINT *type, BOOL *temporary, LPCWSTR *table_name )
{
    MSIUPDATEVIEW *uv = (MSIUPDATEVIEW*)view;
    MSIVIEW *wv;

    TRACE("%p %d %p %p %p %p\n", uv, n, name, type, temporary, table_name );

    wv = uv->wv;
    if( !wv )
        return ERROR_FUNCTION_FAILED;

    return wv->ops->get_column_info( wv, n, name, type, temporary, table_name );
}

__attribute__((used)) static UINT UPDATE_modify( struct tagMSIVIEW *view, MSIMODIFY eModifyMode,
                           MSIRECORD *rec, UINT row )
{
    MSIUPDATEVIEW *uv = (MSIUPDATEVIEW*)view;

    TRACE("%p %d %p\n", uv, eModifyMode, rec );

    return ERROR_FUNCTION_FAILED;
}

__attribute__((used)) static UINT UPDATE_delete( struct tagMSIVIEW *view )
{
    MSIUPDATEVIEW *uv = (MSIUPDATEVIEW*)view;
    MSIVIEW *wv;

    TRACE("%p\n", uv );

    wv = uv->wv;
    if( wv )
        wv->ops->delete( wv );
    msiobj_release( &uv->db->hdr );
    msi_free( uv );

    return ERROR_SUCCESS;
}

__attribute__((used)) static UINT UPDATE_find_matching_rows( struct tagMSIVIEW *view, UINT col, UINT val, UINT *row, MSIITERHANDLE *handle )
{
    TRACE("%p %d %d %p\n", view, col, val, *handle );

    return ERROR_FUNCTION_FAILED;
}

UINT UPDATE_CreateView( MSIDATABASE *db, MSIVIEW **view, LPWSTR table,
                        column_info *columns, struct expr *expr )
{
    MSIUPDATEVIEW *uv = NULL;
    UINT r;
    MSIVIEW *sv = NULL, *wv = NULL;

    TRACE("%p\n", uv );

    if (expr)
        r = WHERE_CreateView( db, &wv, table, expr );
    else
        r = TABLE_CreateView( db, table, &wv );

    if( r != ERROR_SUCCESS )
        return r;

    /* then select the columns we want */
    r = SELECT_CreateView( db, &sv, wv, columns );
    if( r != ERROR_SUCCESS )
    {
        wv->ops->delete( wv );
        return r;
    }

    uv = msi_alloc_zero( sizeof *uv );
    if( !uv )
    {
        wv->ops->delete( wv );
        return ERROR_FUNCTION_FAILED;
    }

    /* fill the structure */
    uv->view.ops = &update_ops;
    msiobj_addref( &db->hdr );
    uv->db = db;
    uv->vals = columns;
    uv->wv = sv;
    *view = (MSIVIEW*) uv;

    return ERROR_SUCCESS;
}

