#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_7__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct lexret {char const* string; void* integer; int /*<<< orphan*/  function; int /*<<< orphan*/  proto; } ;
struct MacroDesc {scalar_t__ isBool; int /*<<< orphan*/  fn; int /*<<< orphan*/  arguments; int /*<<< orphan*/ * alias; int /*<<< orphan*/ * name; } ;
struct TYPE_10__ {scalar_t__ hMainWnd; TYPE_1__* info; struct TYPE_10__* next; TYPE_4__* first_button; } ;
typedef  TYPE_3__ WINHELP_WINDOW ;
struct TYPE_11__ {int /*<<< orphan*/  lpszID; struct TYPE_11__* next; } ;
typedef  TYPE_4__ WINHELP_BUTTON ;
struct TYPE_12__ {TYPE_2__* active_win; TYPE_3__* win_list; } ;
struct TYPE_9__ {scalar_t__ hMainWnd; } ;
struct TYPE_8__ {char const* name; } ;
typedef  int /*<<< orphan*/  LPCSTR ;
typedef  void* LONG_PTR ;

/* Variables and functions */
 int BOOL_FUNCTION ; 
 int EMPTY ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 TYPE_7__ Globals ; 
 char* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int IDENTIFIER ; 
 int INTEGER ; 
 struct MacroDesc* MACRO_Builtins ; 
 struct MacroDesc* MACRO_Loaded ; 
 unsigned int MACRO_NumLoaded ; 
 int VOID_FUNCTION ; 
 int /*<<< orphan*/  WINE_FIXME (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  debugstr_a (char const*) ; 
 int /*<<< orphan*/  lstrcmpiA (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ strcasecmp (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char const*) ; 
 scalar_t__ strlen (char const*) ; 

__attribute__((used)) static char* StrDup(const char* str)
{
    char* dst;
    dst=HeapAlloc(GetProcessHeap(),0,strlen(str)+1);
    strcpy(dst, str);
    return dst;
}

__attribute__((used)) static WINHELP_BUTTON**        MACRO_LookupButton(WINHELP_WINDOW* win, LPCSTR name)
{
    WINHELP_BUTTON**    b;

    for (b = &win->first_button; *b; b = &(*b)->next)
        if (!lstrcmpiA(name, (*b)->lpszID)) break;
    return b;
}

__attribute__((used)) static int MACRO_DoLookUp(struct MacroDesc* start, const char* name, struct lexret* lr, unsigned len)
{
    struct MacroDesc*   md;

    for (md = start; md->name && len != 0; md++, len--)
    {
        if (strcasecmp(md->name, name) == 0 || (md->alias != NULL && strcasecmp(md->alias, name) == 0))
        {
            lr->proto = md->arguments;
            lr->function = md->fn;
            return md->isBool ? BOOL_FUNCTION : VOID_FUNCTION;
        }
    }
    return EMPTY;
}

int MACRO_Lookup(const char* name, struct lexret* lr)
{
    int ret;

    if ((ret = MACRO_DoLookUp(MACRO_Builtins, name, lr, -1)) != EMPTY)
        return ret;
    if (MACRO_Loaded && (ret = MACRO_DoLookUp(MACRO_Loaded, name, lr, MACRO_NumLoaded)) != EMPTY)
        return ret;
    if (!strcmp(name, "hwndApp"))
    {
        WINHELP_WINDOW* win;
        lr->integer = 0;
        for (win = Globals.win_list; win; win = win->next)
        {
            if (!strcmp(win->info->name, "main"))
            {
                lr->integer = (LONG_PTR)win->hMainWnd;
                break;
            }
        }
        return INTEGER;
    }
    if (!strcmp(name, "hwndContext"))
    {
        lr->integer = Globals.active_win ?
            (LONG_PTR)Globals.active_win->hMainWnd : 0;
        return INTEGER;
    }
    if (!strcmp(name, "qchPath") || !strcmp(name, "qError") || !strcmp(name, "lTopicNo") ||
        !strcmp(name, "hfs") || !strcmp(name, "coForeground") || !strcmp(name, "coBackground"))
    {
        WINE_FIXME("keyword %s not substituted in macro parsing\n", debugstr_a(name));
        return EMPTY;
    }

    lr->string = name;
    return IDENTIFIER;
}

