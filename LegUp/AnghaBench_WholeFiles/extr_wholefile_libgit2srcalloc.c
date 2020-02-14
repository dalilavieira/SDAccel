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
typedef  int /*<<< orphan*/  git_allocator ;
struct TYPE_4__ {int /*<<< orphan*/ * gmalloc; } ;

/* Variables and functions */
 TYPE_1__ git__allocator ; 
 int git_stdalloc_init_allocator (TYPE_1__*) ; 
 int /*<<< orphan*/  memcpy (TYPE_1__*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int setup_default_allocator(void)
{
#if defined(GIT_MSVC_CRTDBG)
	return git_win32_crtdbg_init_allocator(&git__allocator);
#else
	return git_stdalloc_init_allocator(&git__allocator);
#endif
}

int git_allocator_global_init(void)
{
	/*
	 * We don't want to overwrite any allocator which has been set before
	 * the init function is called.
	 */
	if (git__allocator.gmalloc != NULL)
		return 0;

	return setup_default_allocator();
}

int git_allocator_setup(git_allocator *allocator)
{
	if (!allocator)
		return setup_default_allocator();

	memcpy(&git__allocator, allocator, sizeof(*allocator));
	return 0;
}

