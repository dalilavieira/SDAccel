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
typedef  int /*<<< orphan*/  mutex_t ;

/* Variables and functions */

void MutexLock( mutex_t *m ){
}

void MutexUnlock( mutex_t *m ){
}

mutex_t *MutexAlloc( void ){
	return NULL;
}

