#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_4__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_7__ {int /*<<< orphan*/  nsaddr_list; int /*<<< orphan*/  nscount; } ;
struct TYPE_6__ {int /*<<< orphan*/  riAddressList; int /*<<< orphan*/  riCount; } ;
typedef  TYPE_1__* PIPHLP_RES_INFO ;

/* Variables and functions */
 TYPE_1__ ResInfo ; 
 TYPE_4__ _res ; 

PIPHLP_RES_INFO getResInfo() {
    ResInfo.riCount = _res.nscount;
    ResInfo.riAddressList = _res.nsaddr_list;
    return &ResInfo;
}

VOID disposeResInfo( PIPHLP_RES_INFO InfoPtr ) {
}

