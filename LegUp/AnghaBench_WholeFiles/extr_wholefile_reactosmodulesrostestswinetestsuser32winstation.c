#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  buffer ;
struct TYPE_3__ {char* lpszClassName; int /*<<< orphan*/ * lpszMenuName; int /*<<< orphan*/  hbrBackground; int /*<<< orphan*/  hCursor; scalar_t__ hIcon; int /*<<< orphan*/  hInstance; scalar_t__ cbWndExtra; scalar_t__ cbClsExtra; int /*<<< orphan*/  lpfnWndProc; int /*<<< orphan*/  style; } ;
typedef  TYPE_1__ WNDCLASSA ;
typedef  int /*<<< orphan*/  LPCSTR ;
typedef  int /*<<< orphan*/  HANDLE ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  CS_DBLCLKS ; 
 int /*<<< orphan*/  DefWindowProcA ; 
 int /*<<< orphan*/  GetModuleHandleA (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetStockObject (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GetUserObjectInformationA (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int,int /*<<< orphan*/ *) ; 
 scalar_t__ IDC_ARROW ; 
 int /*<<< orphan*/  LoadCursorA (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  RegisterClassA (TYPE_1__*) ; 
 int /*<<< orphan*/  UOI_NAME ; 
 int /*<<< orphan*/  UOI_TYPE ; 
 int /*<<< orphan*/  WHITE_BRUSH ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int /*<<< orphan*/  trace (char*,int /*<<< orphan*/ ,...) ; 

__attribute__((used)) static void print_object( HANDLE obj )
{
    char buffer[100];
    DWORD size;

    strcpy( buffer, "foobar" );
    if (!GetUserObjectInformationA( obj, UOI_NAME, buffer, sizeof(buffer), &size ))
        trace( "could not get info for %p\n", obj );
    else
        trace( "obj %p name '%s'\n", obj, buffer );
    strcpy( buffer, "foobar" );
    if (!GetUserObjectInformationA( obj, UOI_TYPE, buffer, sizeof(buffer), &size ))
        trace( "could not get type for %p\n", obj );
    else
        trace( "obj %p type '%s'\n", obj, buffer );
}

__attribute__((used)) static void register_class(void)
{
    WNDCLASSA cls;

    cls.style = CS_DBLCLKS;
    cls.lpfnWndProc = DefWindowProcA;
    cls.cbClsExtra = 0;
    cls.cbWndExtra = 0;
    cls.hInstance = GetModuleHandleA(0);
    cls.hIcon = 0;
    cls.hCursor = LoadCursorA(0, (LPCSTR)IDC_ARROW);
    cls.hbrBackground = GetStockObject(WHITE_BRUSH);
    cls.lpszMenuName = NULL;
    cls.lpszClassName = "WinStationClass";
    RegisterClassA(&cls);
}

