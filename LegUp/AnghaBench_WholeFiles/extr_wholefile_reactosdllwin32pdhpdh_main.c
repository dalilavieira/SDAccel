#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct query {scalar_t__ magic; int /*<<< orphan*/  counters; struct query* path; } ;
struct counter {scalar_t__ magic; int /*<<< orphan*/  counters; struct counter* path; } ;
typedef  char WCHAR ;
typedef  char* LPCWSTR ;
typedef  scalar_t__ DWORD ;
typedef  int BOOL ;

/* Variables and functions */
 scalar_t__ ARRAY_SIZE (char*) ; 
 int /*<<< orphan*/  CP_ACP ; 
 int FALSE ; 
 int /*<<< orphan*/  GetComputerNameW (char*,scalar_t__*) ; 
 int /*<<< orphan*/  MAX_COMPUTERNAME_LENGTH ; 
 int MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const*,int,char*,int) ; 
 scalar_t__ PDH_MAGIC_COUNTER ; 
 scalar_t__ PDH_MAGIC_QUERY ; 
 char* heap_alloc (int) ; 
 struct query* heap_alloc_zero (int) ; 
 int /*<<< orphan*/  heap_free (struct query*) ; 
 int /*<<< orphan*/  list_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memicmpW (char const*,char*,scalar_t__) ; 
 char* strchrW (char*,char) ; 
 int /*<<< orphan*/  strcmpW (char const*,char*) ; 
 int /*<<< orphan*/  strcpyW (char*,char const*) ; 
 int strlenW (char const*) ; 
 char* strrchrW (char*,char) ; 

__attribute__((used)) static inline WCHAR *pdh_strdup( const WCHAR *src )
{
    WCHAR *dst;

    if (!src) return NULL;
    if ((dst = heap_alloc( (strlenW( src ) + 1) * sizeof(WCHAR) ))) strcpyW( dst, src );
    return dst;
}

__attribute__((used)) static inline WCHAR *pdh_strdup_aw( const char *src )
{
    int len;
    WCHAR *dst;

    if (!src) return NULL;
    len = MultiByteToWideChar( CP_ACP, 0, src, -1, NULL, 0 );
    if ((dst = heap_alloc( len * sizeof(WCHAR) ))) MultiByteToWideChar( CP_ACP, 0, src, -1, dst, len );
    return dst;
}

__attribute__((used)) static struct counter *create_counter( void )
{
    struct counter *counter;

    if ((counter = heap_alloc_zero( sizeof(struct counter) )))
    {
        counter->magic = PDH_MAGIC_COUNTER;
        return counter;
    }
    return NULL;
}

__attribute__((used)) static void destroy_counter( struct counter *counter )
{
    counter->magic = 0;
    heap_free( counter->path );
    heap_free( counter );
}

__attribute__((used)) static struct query *create_query( void )
{
    struct query *query;

    if ((query = heap_alloc_zero( sizeof(struct query) )))
    {
        query->magic = PDH_MAGIC_QUERY;
        list_init( &query->counters );
        return query;
    }
    return NULL;
}

__attribute__((used)) static void destroy_query( struct query *query )
{
    query->magic = 0;
    heap_free( query );
}

__attribute__((used)) static BOOL is_local_machine( const WCHAR *name, DWORD len )
{
    WCHAR buf[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD buflen = ARRAY_SIZE(buf);

    if (!GetComputerNameW( buf, &buflen )) return FALSE;
    return len == buflen && !memicmpW( name, buf, buflen );
}

__attribute__((used)) static BOOL pdh_match_path( LPCWSTR fullpath, LPCWSTR path )
{
    const WCHAR *p;

    if (path[0] == '\\' && path[1] == '\\' && (p = strchrW( path + 2, '\\' )) &&
        is_local_machine( path + 2, p - path - 2 ))
    {
        path += p - path;
    }
    if (strchrW( path, '\\' )) p = fullpath;
    else p = strrchrW( fullpath, '\\' ) + 1;
    return !strcmpW( p, path );
}

