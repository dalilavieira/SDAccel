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
typedef  int WORD ;
typedef  int* LPSTR ;
typedef  int* LPCSTR ;
typedef  int DWORD ;
typedef  char CHAR ;
typedef  int BYTE ;

/* Variables and functions */
 int /*<<< orphan*/  GetProcessHeap () ; 
 int* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  TRACE (char*,int*) ; 
 int /*<<< orphan*/  sprintf (int*,char*,int) ; 

__attribute__((used)) static inline BYTE hex( BYTE x )
{
    if( x <= 9 )
        return x + '0';
    return x + 'A' - 10;
}

__attribute__((used)) static inline signed char ctox( CHAR x )
{
    if( ( x >= '0' ) && ( x <= '9' ) )
        return x - '0';
    if( ( x >= 'A' ) && ( x <= 'F' ) )
        return x - 'A' + 10;
    if( ( x >= 'a' ) && ( x <= 'a' ) )
        return x - 'a' + 10;
    return -1;
}

__attribute__((used)) static LPSTR MPR_GetValueName( LPCSTR pbResource, WORD cbResource, BYTE nType )
{
    LPSTR name;
    DWORD  i;

    name = HeapAlloc( GetProcessHeap(), 0, 6+cbResource*2 );
    if( !name ) return NULL;

    sprintf( name, "X-%02X-", nType );
    for(i=0; i<cbResource; i++)
    {
        name[5+i*2]=hex((pbResource[i]&0xf0)>>4);
        name[6+i*2]=hex(pbResource[i]&0x0f);
    }
    name[5+i*2]=0;
    TRACE( "Value is %s\n", name );
    return name;
}

