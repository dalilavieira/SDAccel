#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  GdiSharedHandleTable; } ;
struct TYPE_4__ {TYPE_2__* ProcessEnvironmentBlock; } ;
typedef  TYPE_1__* PTEB ;
typedef  TYPE_2__* PPEB ;
typedef  int /*<<< orphan*/  PGDI_TABLE_ENTRY ;

/* Variables and functions */
 TYPE_1__* NtCurrentTeb () ; 

__attribute__((used)) static
PGDI_TABLE_ENTRY
MyGdiQueryTable()
{
	PTEB pTeb = NtCurrentTeb();
	PPEB pPeb = pTeb->ProcessEnvironmentBlock;
	return pPeb->GdiSharedHandleTable;
}

