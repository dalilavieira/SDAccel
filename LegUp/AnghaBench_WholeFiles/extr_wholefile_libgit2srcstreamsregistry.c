#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  git__on_shutdown (void (*) ()) ; 
 int /*<<< orphan*/  git_rwlock_free (int /*<<< orphan*/ *) ; 
 scalar_t__ git_rwlock_init (int /*<<< orphan*/ *) ; 
 TYPE_1__ stream_registry ; 

__attribute__((used)) static void shutdown_stream_registry(void)
{
	git_rwlock_free(&stream_registry.lock);
}

int git_stream_registry_global_init(void)
{
	if (git_rwlock_init(&stream_registry.lock) < 0)
		return -1;

	git__on_shutdown(shutdown_stream_registry);
	return 0;
}

