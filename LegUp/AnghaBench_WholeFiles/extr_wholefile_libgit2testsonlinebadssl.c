#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int (* certificate_check ) (void*,int,char const*,void*) ;} ;
struct TYPE_7__ {TYPE_1__ callbacks; } ;
struct TYPE_8__ {TYPE_2__ fetch_opts; } ;
typedef  TYPE_3__ git_clone_options ;
typedef  void git_cert ;

/* Variables and functions */
 TYPE_3__ GIT_CLONE_OPTIONS_INIT ; 
 int GIT_ECERTIFICATE ; 
 int /*<<< orphan*/  GIT_UNUSED (void*) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  cl_git_fail_with (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_skip () ; 
 int /*<<< orphan*/  g_has_ssl ; 
 int /*<<< orphan*/  g_repo ; 
 int /*<<< orphan*/  git_clone (int /*<<< orphan*/ *,char*,char*,TYPE_3__*) ; 

__attribute__((used)) static int cert_check_assert_invalid(git_cert *cert, int valid, const char* host, void *payload)
{
	GIT_UNUSED(cert); GIT_UNUSED(host); GIT_UNUSED(payload);

	cl_assert_equal_i(0, valid);

	return GIT_ECERTIFICATE;
}

void test_online_badssl__expired(void)
{
	git_clone_options opts = GIT_CLONE_OPTIONS_INIT;
	opts.fetch_opts.callbacks.certificate_check = cert_check_assert_invalid;

	if (!g_has_ssl)
		cl_skip();

	cl_git_fail_with(GIT_ECERTIFICATE,
			 git_clone(&g_repo, "https://expired.badssl.com/fake.git", "./fake", NULL));

	cl_git_fail_with(GIT_ECERTIFICATE,
			 git_clone(&g_repo, "https://expired.badssl.com/fake.git", "./fake", &opts));
}

void test_online_badssl__wrong_host(void)
{
	git_clone_options opts = GIT_CLONE_OPTIONS_INIT;
	opts.fetch_opts.callbacks.certificate_check = cert_check_assert_invalid;

	if (!g_has_ssl)
		cl_skip();

	cl_git_fail_with(GIT_ECERTIFICATE,
			 git_clone(&g_repo, "https://wrong.host.badssl.com/fake.git", "./fake", NULL));
	cl_git_fail_with(GIT_ECERTIFICATE,
			 git_clone(&g_repo, "https://wrong.host.badssl.com/fake.git", "./fake", &opts));
}

void test_online_badssl__self_signed(void)
{
	git_clone_options opts = GIT_CLONE_OPTIONS_INIT;
	opts.fetch_opts.callbacks.certificate_check = cert_check_assert_invalid;

	if (!g_has_ssl)
		cl_skip();

	cl_git_fail_with(GIT_ECERTIFICATE,
			 git_clone(&g_repo, "https://self-signed.badssl.com/fake.git", "./fake", NULL));
	cl_git_fail_with(GIT_ECERTIFICATE,
			 git_clone(&g_repo, "https://self-signed.badssl.com/fake.git", "./fake", &opts));
}

void test_online_badssl__old_cipher(void)
{
	git_clone_options opts = GIT_CLONE_OPTIONS_INIT;
	opts.fetch_opts.callbacks.certificate_check = cert_check_assert_invalid;

	/* FIXME: we don't actually reject RC4 anywhere, figure out what to tweak */
	cl_skip();

	if (!g_has_ssl)
		cl_skip();

	cl_git_fail_with(GIT_ECERTIFICATE,
			 git_clone(&g_repo, "https://rc4.badssl.com/fake.git", "./fake", NULL));
	cl_git_fail_with(GIT_ECERTIFICATE,
			 git_clone(&g_repo, "https://rc4.badssl.com/fake.git", "./fake", &opts));
}

