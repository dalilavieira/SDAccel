#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  char WCHAR ;
struct TYPE_4__ {int len; char const* name; int tokenType; } ;
typedef  int /*<<< orphan*/ * LPWSTR ;
typedef  char* LPSTR ;
typedef  int /*<<< orphan*/  LPCWSTR ;
typedef  int /*<<< orphan*/  LPCSTR ;
typedef  TYPE_1__ Keyword ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CP_ACP ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 void* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  HeapFree (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*) ; 
 void* HeapReAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void*,size_t) ; 
 int MAX_TOKEN_LEN ; 
 int MultiByteToWideChar (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ *,int) ; 
 int TK_COMMA ; 
 int TK_DOT ; 
 int TK_EQ ; 
 int TK_GE ; 
 int TK_GT ; 
 int TK_ID ; 
 int TK_ILLEGAL ; 
 int TK_INTEGER ; 
 int TK_LE ; 
 int TK_LP ; 
 int TK_LT ; 
 int TK_MINUS ; 
 int TK_NE ; 
 int TK_RP ; 
 int TK_SPACE ; 
 int TK_STAR ; 
 int TK_STRING ; 
 int TK_WILDCARD ; 
 int WideCharToMultiByte (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  aKeywordTable ; 
 TYPE_1__* bsearch (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int (*) (void const*,void const*)) ; 
 int /*<<< orphan*/ * isIdChar ; 
 int /*<<< orphan*/  lstrcpyW (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int lstrlenW (int /*<<< orphan*/ ) ; 
 int memicmpW (char const*,char const*,int) ; 
 int min (int,int) ; 

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

__attribute__((used)) static int compKeyword(const void *m1, const void *m2){
  const Keyword *k1 = m1, *k2 = m2;
  int ret, len = min( k1->len, k2->len );

  if ((ret = memicmpW( k1->name, k2->name, len ))) return ret;
  if (k1->len < k2->len) return -1;
  else if (k1->len > k2->len) return 1;
  return 0;
}

__attribute__((used)) static int sqliteKeywordCode(const WCHAR *z, int n){
  Keyword key, *r;

  if( n>MAX_TOKEN_LEN )
    return TK_ID;

  key.tokenType = 0;
  key.name = z;
  key.len = n;
  r = bsearch( &key, aKeywordTable, ARRAY_SIZE(aKeywordTable), sizeof(Keyword), compKeyword );
  if( r )
    return r->tokenType;
  return TK_ID;
}

__attribute__((used)) static inline int isDigit(WCHAR c)
{
    return c >= '0' && c <= '9';
}

__attribute__((used)) static inline int isSpace(WCHAR c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\f';
}

int sqliteGetToken(const WCHAR *z, int *tokenType, int *skip){
  int i;

  *skip = 0;
  switch( *z ){
    case ' ': case '\t': case '\n': case '\f':
      for(i=1; isSpace(z[i]); i++){}
      *tokenType = TK_SPACE;
      return i;
    case '-':
      if( z[1]==0 ) return -1;
      *tokenType = TK_MINUS;
      return 1;
    case '(':
      *tokenType = TK_LP;
      return 1;
    case ')':
      *tokenType = TK_RP;
      return 1;
    case '*':
      *tokenType = TK_STAR;
      return 1;
    case '=':
      *tokenType = TK_EQ;
      return 1;
    case '<':
      if( z[1]=='=' ){
        *tokenType = TK_LE;
        return 2;
      }else if( z[1]=='>' ){
        *tokenType = TK_NE;
        return 2;
      }else{
        *tokenType = TK_LT;
        return 1;
      }
    case '>':
      if( z[1]=='=' ){
        *tokenType = TK_GE;
        return 2;
      }else{
        *tokenType = TK_GT;
        return 1;
      }
    case '!':
      if( z[1]!='=' ){
        *tokenType = TK_ILLEGAL;
        return 2;
      }else{
        *tokenType = TK_NE;
        return 2;
      }
    case '?':
      *tokenType = TK_WILDCARD;
      return 1;
    case ',':
      *tokenType = TK_COMMA;
      return 1;
    case '`': case '\'': {
      int delim = z[0];
      for(i=1; z[i]; i++){
        if( z[i]==delim )
          break;
      }
      if( z[i] ) i++;
      if( delim == '`' )
        *tokenType = TK_ID;
      else
        *tokenType = TK_STRING;
      return i;
    }
    case '.':
      if( !isDigit(z[1]) ){
        *tokenType = TK_DOT;
        return 1;
      }
      /* Fall through */
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      *tokenType = TK_INTEGER;
      for(i=1; isDigit(z[i]); i++){}
      return i;
    case '[':
      for(i=1; z[i] && z[i-1]!=']'; i++){}
      *tokenType = TK_ID;
      return i;
    default:
      if( !isIdChar[*z] ){
        break;
      }
      for(i=1; isIdChar[z[i]]; i++){}
      *tokenType = sqliteKeywordCode(z, i);
      if( *tokenType == TK_ID && z[i] == '`' ) *skip = 1;
      return i;
  }
  *tokenType = TK_ILLEGAL;
  return 1;
}

