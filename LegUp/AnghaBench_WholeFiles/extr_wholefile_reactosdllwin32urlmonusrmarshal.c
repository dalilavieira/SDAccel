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

/* Variables and functions */
 int /*<<< orphan*/  InterlockedDecrement (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  InterlockedIncrement (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  URLMON_refCount ; 

__attribute__((used)) static inline void URLMON_LockModule(void) { InterlockedIncrement( &URLMON_refCount ); }

__attribute__((used)) static inline void URLMON_UnlockModule(void) { InterlockedDecrement( &URLMON_refCount ); }

