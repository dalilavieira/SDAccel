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
typedef  int /*<<< orphan*/  git_transport ;
typedef  void git_remote ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (char const**) ; 
 int GIT_EEXISTS ; 
 int GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_UNUSED (void*) ; 
 int /*<<< orphan*/  _transport ; 
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_git_fail_with (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_transport_new (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  git_transport_register (char*,int (*) (int /*<<< orphan*/ **,void*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_transport_unregister (char*) ; 

__attribute__((used)) static int dummy_transport(git_transport **transport, git_remote *owner, void *param)
{
	*transport = &_transport;
	GIT_UNUSED(owner);
	GIT_UNUSED(param);
	return 0;
}

void test_transport_register__custom_transport(void)
{
	git_transport *transport;

	cl_git_pass(git_transport_register("something", dummy_transport, NULL));

	cl_git_pass(git_transport_new(&transport, NULL, "something://somepath"));

	cl_assert(transport == &_transport);

	cl_git_pass(git_transport_unregister("something"));
}

void test_transport_register__custom_transport_error_doubleregister(void)
{
	cl_git_pass(git_transport_register("something", dummy_transport, NULL));

	cl_git_fail_with(git_transport_register("something", dummy_transport, NULL), GIT_EEXISTS);

	cl_git_pass(git_transport_unregister("something"));
}

void test_transport_register__custom_transport_error_remove_non_existing(void)
{
	cl_git_fail_with(git_transport_unregister("something"), GIT_ENOTFOUND);
}

void test_transport_register__custom_transport_ssh(void)
{
	const char *urls[] = {
		"ssh://somehost:somepath",
		"ssh+git://somehost:somepath",
		"git+ssh://somehost:somepath",
		"git@somehost:somepath",
		"ssh://somehost:somepath%20with%20%spaces",
		"ssh://somehost:somepath with spaces"
	};
	git_transport *transport;
	unsigned i;

	for (i = 0; i < ARRAY_SIZE(urls); i++) {
#ifndef GIT_SSH
		cl_git_fail_with(git_transport_new(&transport, NULL, urls[i]), -1);
#else
		cl_git_pass(git_transport_new(&transport, NULL, urls[i]));
		transport->free(transport);
#endif
	}

	cl_git_pass(git_transport_register("ssh", dummy_transport, NULL));

	cl_git_pass(git_transport_new(&transport, NULL, "git@somehost:somepath"));

	cl_assert(transport == &_transport);

	cl_git_pass(git_transport_unregister("ssh"));

	for (i = 0; i < ARRAY_SIZE(urls); i++) {
#ifndef GIT_SSH
		cl_git_fail_with(git_transport_new(&transport, NULL, urls[i]), -1);
#else
		cl_git_pass(git_transport_new(&transport, NULL, urls[i]));
		transport->free(transport);
#endif
	}
}

