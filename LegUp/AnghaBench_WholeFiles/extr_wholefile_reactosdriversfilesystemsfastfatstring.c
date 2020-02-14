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
typedef  int /*<<< orphan*/  WCHAR ;
typedef  int /*<<< orphan*/  BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  long_illegals ; 
 scalar_t__ wcschr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

BOOLEAN
vfatIsLongIllegal(
    WCHAR c)
{
    return wcschr(long_illegals, c) ? TRUE : FALSE;
}

