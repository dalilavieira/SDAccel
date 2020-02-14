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
struct WINE_WAVEMAP {int dummy; } ;
struct TYPE_4__ {struct TYPE_4__ const* self; } ;
typedef  TYPE_1__ WAVEMAPDATA ;
typedef  int LRESULT ;
typedef  int /*<<< orphan*/  LPSTR ;
typedef  int /*<<< orphan*/  DWORD_PTR ;
typedef  int BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  IsBadReadPtr (TYPE_1__ const*,int) ; 
 int /*<<< orphan*/  TRACE (char*,int /*<<< orphan*/ ) ; 
 struct WINE_WAVEMAP* oss ; 

__attribute__((used)) static	BOOL	WAVEMAP_IsData(const WAVEMAPDATA* wm)
{
    return (!IsBadReadPtr(wm, sizeof(WAVEMAPDATA)) && wm->self == wm);
}

__attribute__((used)) static LRESULT WAVEMAP_drvOpen(LPSTR str)
{
    TRACE("(%p)\n", str);

    if (oss)
	return 0;

    /* I know, this is ugly, but who cares... */
    oss = (struct WINE_WAVEMAP*)1;
    return 1;
}

__attribute__((used)) static LRESULT WAVEMAP_drvClose(DWORD_PTR dwDevID)
{
    TRACE("(%08lx)\n", dwDevID);

    if (oss) {
	oss = NULL;
	return 1;
    }
    return 0;
}

