#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_30__   TYPE_5__ ;
typedef  struct TYPE_29__   TYPE_4__ ;
typedef  struct TYPE_28__   TYPE_3__ ;
typedef  struct TYPE_27__   TYPE_2__ ;
typedef  struct TYPE_26__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ WORD ;
struct TYPE_26__ {char UnicodeChar; } ;
struct TYPE_30__ {scalar_t__ Attributes; TYPE_1__ Char; } ;
struct TYPE_29__ {int dwSize; int bVisible; } ;
struct TYPE_28__ {scalar_t__ X; scalar_t__ Y; } ;
struct TYPE_27__ {scalar_t__ Left; int Right; scalar_t__ Top; int Bottom; } ;
typedef  TYPE_2__ SMALL_RECT ;
typedef  int /*<<< orphan*/  HMODULE ;
typedef  int /*<<< orphan*/ * HANDLE ;
typedef  int DWORD ;
typedef  TYPE_3__ COORD ;
typedef  TYPE_4__ CONSOLE_CURSOR_INFO ;
typedef  TYPE_5__ CHAR_INFO ;
typedef  int BOOL ;

/* Variables and functions */
 char CONTENT (TYPE_3__) ; 
 scalar_t__ DEFAULT_ATTRIB ; 
 int ENABLE_PROCESSED_OUTPUT ; 
 int ENABLE_WRAP_AT_EOL_OUTPUT ; 
 int ERROR_INVALID_HANDLE ; 
 int ERROR_INVALID_PARAMETER ; 
 int ERROR_NOT_ENOUGH_MEMORY ; 
 int FALSE ; 
 int GetConsoleCursorInfo (int /*<<< orphan*/ *,TYPE_4__*) ; 
 scalar_t__ GetConsoleMode (int /*<<< orphan*/ *,int*) ; 
 int GetLastError () ; 
 int /*<<< orphan*/  GetModuleHandleA (char*) ; 
 scalar_t__ GetProcAddress (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ReadConsoleOutputAttribute (int /*<<< orphan*/ *,scalar_t__*,int,TYPE_3__,int*) ; 
 int ScrollConsoleScreenBufferA (int /*<<< orphan*/ *,TYPE_2__*,TYPE_2__*,TYPE_3__,TYPE_5__*) ; 
 scalar_t__ SetConsoleCursorPosition (int /*<<< orphan*/ *,TYPE_3__) ; 
 scalar_t__ SetConsoleMode (int /*<<< orphan*/ *,int) ; 
 int SetConsoleTextAttribute (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  SetLastError (int) ; 
 scalar_t__ TEST_ATTRIB ; 
 int TRUE ; 
 scalar_t__ WriteConsoleA (int /*<<< orphan*/ *,char const*,int const,int*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  WriteConsoleOutputAttribute (int /*<<< orphan*/ *,scalar_t__*,int,TYPE_3__,int*) ; 
 int /*<<< orphan*/  WriteConsoleOutputCharacterA (int /*<<< orphan*/ *,char*,int,TYPE_3__,int*) ; 
 void* min (int,int) ; 
 int /*<<< orphan*/  ok (int,char*,...) ; 
 int /*<<< orphan*/  okCHAR (int /*<<< orphan*/ *,TYPE_3__,char const,scalar_t__) ; 
 int /*<<< orphan*/  okCURSOR (int /*<<< orphan*/ *,TYPE_3__) ; 
 void* pGetConsoleInputExeNameA ; 
 void* pGetConsoleProcessList ; 
 void* pOpenConsoleW ; 
 void* pSetConsoleInputExeNameA ; 
 void* pVerifyConsoleIoHandle ; 
 char const* strchr (char const*,char) ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  trace (char*,char*) ; 
 int /*<<< orphan*/  win_skip (char*) ; 

__attribute__((used)) static void init_function_pointers(void)
{
    HMODULE hKernel32;

#define KERNEL32_GET_PROC(func)                                     \
    p##func = (void *)GetProcAddress(hKernel32, #func);             \
    if(!p##func) trace("GetProcAddress(hKernel32, '%s') failed\n", #func);

    hKernel32 = GetModuleHandleA("kernel32.dll");
    KERNEL32_GET_PROC(GetConsoleInputExeNameA);
    KERNEL32_GET_PROC(GetConsoleProcessList);
    KERNEL32_GET_PROC(OpenConsoleW);
    KERNEL32_GET_PROC(SetConsoleInputExeNameA);
    KERNEL32_GET_PROC(VerifyConsoleIoHandle);

#undef KERNEL32_GET_PROC
}

__attribute__((used)) static void resetContent(HANDLE hCon, COORD sbSize, BOOL content)
{
    COORD       c;
    WORD        attr = DEFAULT_ATTRIB;
    char        ch;
    DWORD       len;

    for (c.X = 0; c.X < sbSize.X; c.X++)
    {
        for (c.Y = 0; c.Y < sbSize.Y; c.Y++)
        {
            ch = (content) ? CONTENT(c) : ' ';
            WriteConsoleOutputAttribute(hCon, &attr, 1, c, &len);
            WriteConsoleOutputCharacterA(hCon, &ch, 1, c, &len);
        }
    }
}

__attribute__((used)) static void testCursor(HANDLE hCon, COORD sbSize)
{
    COORD		c;

    c.X = c.Y = 0;
    ok(SetConsoleCursorPosition(0, c) == 0, "No handle\n");
    ok(GetLastError() == ERROR_INVALID_HANDLE, "GetLastError: expecting %u got %u\n",
       ERROR_INVALID_HANDLE, GetLastError());

    c.X = c.Y = 0;
    ok(SetConsoleCursorPosition(hCon, c) != 0, "Cursor in upper-left\n");
    okCURSOR(hCon, c);

    c.X = sbSize.X - 1;
    c.Y = sbSize.Y - 1;
    ok(SetConsoleCursorPosition(hCon, c) != 0, "Cursor in lower-right\n");
    okCURSOR(hCon, c);

    c.X = sbSize.X;
    c.Y = sbSize.Y - 1;
    ok(SetConsoleCursorPosition(hCon, c) == 0, "Cursor is outside\n");
    ok(GetLastError() == ERROR_INVALID_PARAMETER, "GetLastError: expecting %u got %u\n",
       ERROR_INVALID_PARAMETER, GetLastError());

    c.X = sbSize.X - 1;
    c.Y = sbSize.Y;
    ok(SetConsoleCursorPosition(hCon, c) == 0, "Cursor is outside\n");
    ok(GetLastError() == ERROR_INVALID_PARAMETER, "GetLastError: expecting %u got %u\n",
       ERROR_INVALID_PARAMETER, GetLastError());

    c.X = -1;
    c.Y = 0;
    ok(SetConsoleCursorPosition(hCon, c) == 0, "Cursor is outside\n");
    ok(GetLastError() == ERROR_INVALID_PARAMETER, "GetLastError: expecting %u got %u\n",
       ERROR_INVALID_PARAMETER, GetLastError());

    c.X = 0;
    c.Y = -1;
    ok(SetConsoleCursorPosition(hCon, c) == 0, "Cursor is outside\n");
    ok(GetLastError() == ERROR_INVALID_PARAMETER, "GetLastError: expecting %u got %u\n",
       ERROR_INVALID_PARAMETER, GetLastError());
}

__attribute__((used)) static void testCursorInfo(HANDLE hCon)
{
    BOOL ret;
    CONSOLE_CURSOR_INFO info;

    SetLastError(0xdeadbeef);
    ret = GetConsoleCursorInfo(NULL, NULL);
    ok(!ret, "Expected failure\n");
    ok(GetLastError() == ERROR_INVALID_HANDLE, "GetLastError: expecting %u got %u\n",
       ERROR_INVALID_HANDLE, GetLastError());

    SetLastError(0xdeadbeef);
    info.dwSize = -1;
    ret = GetConsoleCursorInfo(NULL, &info);
    ok(!ret, "Expected failure\n");
    ok(info.dwSize == -1, "Expected no change for dwSize\n");
    ok(GetLastError() == ERROR_INVALID_HANDLE, "GetLastError: expecting %u got %u\n",
       ERROR_INVALID_HANDLE, GetLastError());

    /* Test the correct call first to distinguish between win9x and the rest */
    SetLastError(0xdeadbeef);
    ret = GetConsoleCursorInfo(hCon, &info);
    ok(ret, "Expected success\n");
    ok(info.dwSize == 25 ||
       info.dwSize == 12 /* win9x */,
       "Expected 12 or 25, got %d\n", info.dwSize);
    ok(info.bVisible, "Expected the cursor to be visible\n");
    ok(GetLastError() == 0xdeadbeef, "GetLastError: expecting %u got %u\n",
       0xdeadbeef, GetLastError());

    /* Don't test NULL CONSOLE_CURSOR_INFO, it crashes on win9x and win7 */
}

__attribute__((used)) static void testEmptyWrite(HANDLE hCon)
{
    static const char	emptybuf[16];
    COORD		c;
    DWORD		len;

    c.X = c.Y = 0;
    ok(SetConsoleCursorPosition(hCon, c) != 0, "Cursor in upper-left\n");

    len = -1;
    ok(WriteConsoleA(hCon, NULL, 0, &len, NULL) != 0 && len == 0, "WriteConsole\n");
    okCURSOR(hCon, c);

    /* Passing a NULL lpBuffer with sufficiently large non-zero length succeeds
     * on native Windows and result in memory-like contents being written to
     * the console. Calling WriteConsoleW like this will crash on Wine. */
    if (0)
    {
        len = -1;
        ok(!WriteConsoleA(hCon, NULL, 16, &len, NULL) && len == -1, "WriteConsole\n");
        okCURSOR(hCon, c);

        /* Cursor advances for this call. */
        len = -1;
        ok(WriteConsoleA(hCon, NULL, 128, &len, NULL) != 0 && len == 128, "WriteConsole\n");
    }

    len = -1;
    ok(WriteConsoleA(hCon, emptybuf, 0, &len, NULL) != 0 && len == 0, "WriteConsole\n");
    okCURSOR(hCon, c);

    /* WriteConsole does not halt on a null terminator and is happy to write
     * memory contents beyond the actual size of the buffer. */
    len = -1;
    ok(WriteConsoleA(hCon, emptybuf, 16, &len, NULL) != 0 && len == 16, "WriteConsole\n");
    c.X += 16;
    okCURSOR(hCon, c);
}

__attribute__((used)) static void testWriteSimple(HANDLE hCon)
{
    COORD		c;
    DWORD		len;
    const char*		mytest = "abcdefg";
    const int	mylen = strlen(mytest);

    /* single line write */
    c.X = c.Y = 0;
    ok(SetConsoleCursorPosition(hCon, c) != 0, "Cursor in upper-left\n");

    ok(WriteConsoleA(hCon, mytest, mylen, &len, NULL) != 0 && len == mylen, "WriteConsole\n");
    c.Y = 0;
    for (c.X = 0; c.X < mylen; c.X++)
    {
        okCHAR(hCon, c, mytest[c.X], TEST_ATTRIB);
    }

    okCURSOR(hCon, c);
    okCHAR(hCon, c, ' ', DEFAULT_ATTRIB);
}

__attribute__((used)) static void testWriteNotWrappedNotProcessed(HANDLE hCon, COORD sbSize)
{
    COORD		c;
    DWORD		len, mode;
    const char*         mytest = "123";
    const int           mylen = strlen(mytest);
    int                 ret;
    int			p;

    ok(GetConsoleMode(hCon, &mode) && SetConsoleMode(hCon, mode & ~(ENABLE_PROCESSED_OUTPUT|ENABLE_WRAP_AT_EOL_OUTPUT)),
       "clearing wrap at EOL & processed output\n");

    /* write line, wrapping disabled, buffer exceeds sb width */
    c.X = sbSize.X - 3; c.Y = 0;
    ok(SetConsoleCursorPosition(hCon, c) != 0, "Cursor in upper-left-3\n");

    ret = WriteConsoleA(hCon, mytest, mylen, &len, NULL);
    ok(ret != 0 && len == mylen, "Couldn't write, ret = %d, len = %d\n", ret, len);
    c.Y = 0;
    for (p = mylen - 3; p < mylen; p++)
    {
        c.X = sbSize.X - 3 + p % 3;
        okCHAR(hCon, c, mytest[p], TEST_ATTRIB);
    }

    c.X = 0; c.Y = 1;
    okCHAR(hCon, c, ' ', DEFAULT_ATTRIB);

    p = sbSize.X - 3 + mylen % 3;
    c.X = p; c.Y = 0;

    /* write line, wrapping disabled, strings end on end of line */
    c.X = sbSize.X - mylen; c.Y = 0;
    ok(SetConsoleCursorPosition(hCon, c) != 0, "Cursor in upper-left-3\n");

    ok(WriteConsoleA(hCon, mytest, mylen, &len, NULL) != 0 && len == mylen, "WriteConsole\n");
}

__attribute__((used)) static void testWriteNotWrappedProcessed(HANDLE hCon, COORD sbSize)
{
    COORD		c;
    DWORD		len, mode;
    const char*		mytest = "abcd\nf\tg";
    const int	mylen = strlen(mytest);
    const int	mylen2 = strchr(mytest, '\n') - mytest;
    int			p;
    WORD                attr;

    ok(GetConsoleMode(hCon, &mode) && SetConsoleMode(hCon, (mode | ENABLE_PROCESSED_OUTPUT) & ~ENABLE_WRAP_AT_EOL_OUTPUT),
       "clearing wrap at EOL & setting processed output\n");

    /* write line, wrapping disabled, buffer exceeds sb width */
    c.X = sbSize.X - 5; c.Y = 0;
    ok(SetConsoleCursorPosition(hCon, c) != 0, "Cursor in upper-left-5\n");

    ok(WriteConsoleA(hCon, mytest, mylen, &len, NULL) != 0 && len == mylen, "WriteConsole\n");
    c.Y = 0;
    for (c.X = sbSize.X - 5; c.X < sbSize.X - 1; c.X++)
    {
        okCHAR(hCon, c, mytest[c.X - sbSize.X + 5], TEST_ATTRIB);
    }

    ReadConsoleOutputAttribute(hCon, &attr, 1, c, &len);
    /* Win9x and WinMe change the attribs for '\n' up to 'f' */
    if (attr == TEST_ATTRIB)
    {
        win_skip("Win9x/WinMe don't respect ~ENABLE_WRAP_AT_EOL_OUTPUT\n");
        return;
    }

    okCHAR(hCon, c, ' ', DEFAULT_ATTRIB);

    c.X = 0; c.Y++;
    okCHAR(hCon, c, mytest[5], TEST_ATTRIB);
    for (c.X = 1; c.X < 8; c.X++)
        okCHAR(hCon, c, ' ', TEST_ATTRIB);
    okCHAR(hCon, c, mytest[7], TEST_ATTRIB);
    c.X++;
    okCHAR(hCon, c, ' ', DEFAULT_ATTRIB);

    okCURSOR(hCon, c);

    /* write line, wrapping disabled, strings end on end of line */
    c.X = sbSize.X - 4; c.Y = 0;
    ok(SetConsoleCursorPosition(hCon, c) != 0, "Cursor in upper-left-4\n");

    ok(WriteConsoleA(hCon, mytest, mylen, &len, NULL) != 0 && len == mylen, "WriteConsole\n");
    c.Y = 0;
    for (c.X = sbSize.X - 4; c.X < sbSize.X; c.X++)
    {
        okCHAR(hCon, c, mytest[c.X - sbSize.X + 4], TEST_ATTRIB);
    }
    c.X = 0; c.Y++;
    okCHAR(hCon, c, mytest[5], TEST_ATTRIB);
    for (c.X = 1; c.X < 8; c.X++)
        okCHAR(hCon, c, ' ', TEST_ATTRIB);
    okCHAR(hCon, c, mytest[7], TEST_ATTRIB);
    c.X++;
    okCHAR(hCon, c, ' ', DEFAULT_ATTRIB);

    okCURSOR(hCon, c);

    /* write line, wrapping disabled, strings end after end of line */
    c.X = sbSize.X - 3; c.Y = 0;
    ok(SetConsoleCursorPosition(hCon, c) != 0, "Cursor in upper-left-4\n");

    ok(WriteConsoleA(hCon, mytest, mylen, &len, NULL) != 0 && len == mylen, "WriteConsole\n");
    c.Y = 0;
    for (p = mylen2 - 3; p < mylen2; p++)
    {
        c.X = sbSize.X - 3 + p % 3;
        okCHAR(hCon, c, mytest[p], TEST_ATTRIB);
    }
    c.X = 0; c.Y = 1;
    okCHAR(hCon, c, mytest[5], TEST_ATTRIB);
    for (c.X = 1; c.X < 8; c.X++)
        okCHAR(hCon, c, ' ', TEST_ATTRIB);
    okCHAR(hCon, c, mytest[7], TEST_ATTRIB);
    c.X++;
    okCHAR(hCon, c, ' ', DEFAULT_ATTRIB);

    okCURSOR(hCon, c);
}

__attribute__((used)) static void testWriteWrappedNotProcessed(HANDLE hCon, COORD sbSize)
{
    COORD		c;
    DWORD		len, mode;
    const char*		mytest = "abcd\nf\tg";
    const int	mylen = strlen(mytest);
    int			p;

    ok(GetConsoleMode(hCon, &mode) && SetConsoleMode(hCon,(mode | ENABLE_WRAP_AT_EOL_OUTPUT) & ~(ENABLE_PROCESSED_OUTPUT)),
       "setting wrap at EOL & clearing processed output\n");

    /* write line, wrapping enabled, buffer doesn't exceed sb width */
    c.X = sbSize.X - 9; c.Y = 0;
    ok(SetConsoleCursorPosition(hCon, c) != 0, "Cursor in upper-left-9\n");

    ok(WriteConsoleA(hCon, mytest, mylen, &len, NULL) != 0 && len == mylen, "WriteConsole\n");
    c.Y = 0;
    for (p = 0; p < mylen; p++)
    {
        c.X = sbSize.X - 9 + p;
        okCHAR(hCon, c, mytest[p], TEST_ATTRIB);
    }
    c.X = sbSize.X - 9 + mylen;
    okCHAR(hCon, c, ' ', DEFAULT_ATTRIB);
    c.X = 0; c.Y = 1;
    okCHAR(hCon, c, ' ', DEFAULT_ATTRIB);

    /* write line, wrapping enabled, buffer does exceed sb width */
    c.X = sbSize.X - 3; c.Y = 0;
    ok(SetConsoleCursorPosition(hCon, c) != 0, "Cursor in upper-left-3\n");

    c.Y = 1;
    c.X = mylen - 3;
    okCHAR(hCon, c, ' ', DEFAULT_ATTRIB);
}

__attribute__((used)) static void testWriteWrappedProcessed(HANDLE hCon, COORD sbSize)
{
    COORD		c;
    DWORD		len, mode;
    const char*		mytest = "abcd\nf\tg";
    const int	mylen = strlen(mytest);
    int			p;
    WORD                attr;

    ok(GetConsoleMode(hCon, &mode) && SetConsoleMode(hCon, mode | (ENABLE_WRAP_AT_EOL_OUTPUT|ENABLE_PROCESSED_OUTPUT)),
       "setting wrap at EOL & processed output\n");

    /* write line, wrapping enabled, buffer doesn't exceed sb width */
    c.X = sbSize.X - 9; c.Y = 0;
    ok(SetConsoleCursorPosition(hCon, c) != 0, "Cursor in upper-left-9\n");

    ok(WriteConsoleA(hCon, mytest, mylen, &len, NULL) != 0 && len == mylen, "WriteConsole\n");
    for (p = 0; p < 4; p++)
    {
        c.X = sbSize.X - 9 + p;
        okCHAR(hCon, c, mytest[p], TEST_ATTRIB);
    }
    c.X = sbSize.X - 9 + p;
    ReadConsoleOutputAttribute(hCon, &attr, 1, c, &len);
    if (attr == TEST_ATTRIB)
        win_skip("Win9x/WinMe changes attribs for '\\n' up to 'f'\n");
    else
        okCHAR(hCon, c, ' ', DEFAULT_ATTRIB);
    c.X = 0; c.Y++;
    okCHAR(hCon, c, mytest[5], TEST_ATTRIB);
    for (c.X = 1; c.X < 8; c.X++)
        okCHAR(hCon, c, ' ', TEST_ATTRIB);
    okCHAR(hCon, c, mytest[7], TEST_ATTRIB);
    c.X++;
    okCHAR(hCon, c, ' ', DEFAULT_ATTRIB);
    okCURSOR(hCon, c);

    /* write line, wrapping enabled, buffer does exceed sb width */
    c.X = sbSize.X - 3; c.Y = 2;
    ok(SetConsoleCursorPosition(hCon, c) != 0, "Cursor in upper-left-3\n");

    ok(WriteConsoleA(hCon, mytest, mylen, &len, NULL) != 0 && len == mylen, "WriteConsole\n");
    for (p = 0; p < 3; p++)
    {
        c.X = sbSize.X - 3 + p;
        okCHAR(hCon, c, mytest[p], TEST_ATTRIB);
    }
    c.X = 0; c.Y++;
    okCHAR(hCon, c, mytest[3], TEST_ATTRIB);
    c.X++;
    ReadConsoleOutputAttribute(hCon, &attr, 1, c, &len);
    if (attr == TEST_ATTRIB)
        win_skip("Win9x/WinMe changes attribs for '\\n' up to 'f'\n");
    else
        okCHAR(hCon, c, ' ', DEFAULT_ATTRIB);

    c.X = 0; c.Y++;
    okCHAR(hCon, c, mytest[5], TEST_ATTRIB);
    for (c.X = 1; c.X < 8; c.X++)
        okCHAR(hCon, c, ' ', TEST_ATTRIB);
    okCHAR(hCon, c, mytest[7], TEST_ATTRIB);
    c.X++;
    okCHAR(hCon, c, ' ', DEFAULT_ATTRIB);
    okCURSOR(hCon, c);
}

__attribute__((used)) static void testWrite(HANDLE hCon, COORD sbSize)
{
    /* FIXME: should in fact ensure that the sb is at least 10 characters wide */
    ok(SetConsoleTextAttribute(hCon, TEST_ATTRIB), "Setting default text color\n");
    resetContent(hCon, sbSize, FALSE);
    testEmptyWrite(hCon);
    resetContent(hCon, sbSize, FALSE);
    testWriteSimple(hCon);
    resetContent(hCon, sbSize, FALSE);
    testWriteNotWrappedNotProcessed(hCon, sbSize);
    resetContent(hCon, sbSize, FALSE);
    testWriteNotWrappedProcessed(hCon, sbSize);
    resetContent(hCon, sbSize, FALSE);
    testWriteWrappedNotProcessed(hCon, sbSize);
    resetContent(hCon, sbSize, FALSE);
    testWriteWrappedProcessed(hCon, sbSize);
}

__attribute__((used)) static void testScroll(HANDLE hCon, COORD sbSize)
{
    SMALL_RECT  scroll, clip;
    COORD       dst, c, tc;
    CHAR_INFO   ci;
    BOOL ret;

#define W 11
#define H 7

#define IN_SRECT(r,c) ((r).Left <= (c).X && (c).X <= (r).Right && (r).Top <= (c).Y && (c).Y <= (r).Bottom)
#define IN_SRECT2(r,d,c) ((d).X <= (c).X && (c).X <= (d).X + (r).Right - (r).Left && (d).Y <= (c).Y && (c).Y <= (d).Y + (r).Bottom - (r).Top)

    /* no clipping, src & dst rect don't overlap */
    resetContent(hCon, sbSize, TRUE);

    scroll.Left = 0;
    scroll.Right = W - 1;
    scroll.Top = 0;
    scroll.Bottom = H - 1;
    dst.X = W + 3;
    dst.Y = H + 3;
    ci.Char.UnicodeChar = '#';
    ci.Attributes = TEST_ATTRIB;

    clip.Left = 0;
    clip.Right = sbSize.X - 1;
    clip.Top = 0;
    clip.Bottom = sbSize.Y - 1;

    ok(ScrollConsoleScreenBufferA(hCon, &scroll, NULL, dst, &ci), "Scrolling SB\n");

    for (c.Y = 0; c.Y < sbSize.Y; c.Y++)
    {
        for (c.X = 0; c.X < sbSize.X; c.X++)
        {
            if (IN_SRECT2(scroll, dst, c) && IN_SRECT(clip, c))
            {
                tc.X = c.X - dst.X;
                tc.Y = c.Y - dst.Y;
                okCHAR(hCon, c, CONTENT(tc), DEFAULT_ATTRIB);
            }
            else if (IN_SRECT(scroll, c) && IN_SRECT(clip, c))
                okCHAR(hCon, c, '#', TEST_ATTRIB);
            else okCHAR(hCon, c, CONTENT(c), DEFAULT_ATTRIB);
        }
    }

    /* no clipping, src & dst rect do overlap */
    resetContent(hCon, sbSize, TRUE);

    scroll.Left = 0;
    scroll.Right = W - 1;
    scroll.Top = 0;
    scroll.Bottom = H - 1;
    dst.X = W /2;
    dst.Y = H / 2;
    ci.Char.UnicodeChar = '#';
    ci.Attributes = TEST_ATTRIB;

    clip.Left = 0;
    clip.Right = sbSize.X - 1;
    clip.Top = 0;
    clip.Bottom = sbSize.Y - 1;

    ok(ScrollConsoleScreenBufferA(hCon, &scroll, NULL, dst, &ci), "Scrolling SB\n");

    for (c.Y = 0; c.Y < sbSize.Y; c.Y++)
    {
        for (c.X = 0; c.X < sbSize.X; c.X++)
        {
            if (dst.X <= c.X && c.X < dst.X + W && dst.Y <= c.Y && c.Y < dst.Y + H)
            {
                tc.X = c.X - dst.X;
                tc.Y = c.Y - dst.Y;
                okCHAR(hCon, c, CONTENT(tc), DEFAULT_ATTRIB);
            }
            else if (c.X < W && c.Y < H) okCHAR(hCon, c, '#', TEST_ATTRIB);
            else okCHAR(hCon, c, CONTENT(c), DEFAULT_ATTRIB);
        }
    }

    /* clipping, src & dst rect don't overlap */
    resetContent(hCon, sbSize, TRUE);

    scroll.Left = 0;
    scroll.Right = W - 1;
    scroll.Top = 0;
    scroll.Bottom = H - 1;
    dst.X = W + 3;
    dst.Y = H + 3;
    ci.Char.UnicodeChar = '#';
    ci.Attributes = TEST_ATTRIB;

    clip.Left = W / 2;
    clip.Right = min(W + W / 2, sbSize.X - 1);
    clip.Top = H / 2;
    clip.Bottom = min(H + H / 2, sbSize.Y - 1);

    SetLastError(0xdeadbeef);
    ret = ScrollConsoleScreenBufferA(hCon, &scroll, &clip, dst, &ci);
    if (ret)
    {
        for (c.Y = 0; c.Y < sbSize.Y; c.Y++)
        {
            for (c.X = 0; c.X < sbSize.X; c.X++)
            {
                if (IN_SRECT2(scroll, dst, c) && IN_SRECT(clip, c))
                {
                    tc.X = c.X - dst.X;
                    tc.Y = c.Y - dst.Y;
                    okCHAR(hCon, c, CONTENT(tc), DEFAULT_ATTRIB);
                }
                else if (IN_SRECT(scroll, c) && IN_SRECT(clip, c))
                    okCHAR(hCon, c, '#', TEST_ATTRIB);
                else okCHAR(hCon, c, CONTENT(c), DEFAULT_ATTRIB);
            }
        }
    }
    else
    {
        /* Win9x will fail, Only accept ERROR_NOT_ENOUGH_MEMORY */
        ok(GetLastError() == ERROR_NOT_ENOUGH_MEMORY,
            "Expected ERROR_NOT_ENOUGH_MEMORY, got %u\n", GetLastError());
    }

    /* clipping, src & dst rect do overlap */
    resetContent(hCon, sbSize, TRUE);

    scroll.Left = 0;
    scroll.Right = W - 1;
    scroll.Top = 0;
    scroll.Bottom = H - 1;
    dst.X = W / 2 - 3;
    dst.Y = H / 2 - 3;
    ci.Char.UnicodeChar = '#';
    ci.Attributes = TEST_ATTRIB;

    clip.Left = W / 2;
    clip.Right = min(W + W / 2, sbSize.X - 1);
    clip.Top = H / 2;
    clip.Bottom = min(H + H / 2, sbSize.Y - 1);

    ok(ScrollConsoleScreenBufferA(hCon, &scroll, &clip, dst, &ci), "Scrolling SB\n");

    for (c.Y = 0; c.Y < sbSize.Y; c.Y++)
    {
        for (c.X = 0; c.X < sbSize.X; c.X++)
        {
            if (IN_SRECT2(scroll, dst, c) && IN_SRECT(clip, c))
            {
                tc.X = c.X - dst.X;
                tc.Y = c.Y - dst.Y;
                okCHAR(hCon, c, CONTENT(tc), DEFAULT_ATTRIB);
            }
            else if (IN_SRECT(scroll, c) && IN_SRECT(clip, c))
                okCHAR(hCon, c, '#', TEST_ATTRIB);
            else okCHAR(hCon, c, CONTENT(c), DEFAULT_ATTRIB);
        }
    }
}

