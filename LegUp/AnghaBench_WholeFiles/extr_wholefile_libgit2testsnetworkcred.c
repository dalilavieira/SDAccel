#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int /*<<< orphan*/  username; } ;
typedef  TYPE_1__ git_cred_userpass_plaintext ;
struct TYPE_11__ {char* member_0; char* username; char* member_1; } ;
typedef  TYPE_2__ git_cred_userpass_payload ;
struct TYPE_12__ {int /*<<< orphan*/  (* free ) (TYPE_3__*) ;} ;
typedef  TYPE_3__ git_cred ;

/* Variables and functions */
 int /*<<< orphan*/  GIT_CREDTYPE_USERPASS_PLAINTEXT ; 
 int /*<<< orphan*/  cl_assert_equal_s (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_cred_userpass (TYPE_3__**,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  stub1 (TYPE_3__*) ; 
 int /*<<< orphan*/  stub2 (TYPE_3__*) ; 
 int /*<<< orphan*/  stub3 (TYPE_3__*) ; 
 int /*<<< orphan*/  stub4 (TYPE_3__*) ; 

void test_network_cred__stock_userpass_validates_args(void)
{
	git_cred_userpass_payload payload = {0};

	cl_git_fail(git_cred_userpass(NULL, NULL, NULL, 0, NULL));

	payload.username = "user";
	cl_git_fail(git_cred_userpass(NULL, NULL, NULL, 0, &payload));

	payload.username = NULL;
	payload.username = "pass";
	cl_git_fail(git_cred_userpass(NULL, NULL, NULL, 0, &payload));
}

void test_network_cred__stock_userpass_validates_that_method_is_allowed(void)
{
	git_cred *cred;
	git_cred_userpass_payload payload = {"user", "pass"};

	cl_git_fail(git_cred_userpass(&cred, NULL, NULL, 0, &payload));
	cl_git_pass(git_cred_userpass(&cred, NULL, NULL, GIT_CREDTYPE_USERPASS_PLAINTEXT, &payload));
	cred->free(cred);
}

void test_network_cred__stock_userpass_properly_handles_username_in_url(void)
{
	git_cred *cred;
	git_cred_userpass_plaintext *plain;
	git_cred_userpass_payload payload = {"alice", "password"};

	cl_git_pass(git_cred_userpass(&cred, NULL, NULL, GIT_CREDTYPE_USERPASS_PLAINTEXT, &payload));
	plain = (git_cred_userpass_plaintext*)cred;
	cl_assert_equal_s(plain->username, "alice");
	cred->free(cred);

	cl_git_pass(git_cred_userpass(&cred, NULL, "bob", GIT_CREDTYPE_USERPASS_PLAINTEXT, &payload));
	plain = (git_cred_userpass_plaintext*)cred;
	cl_assert_equal_s(plain->username, "alice");
	cred->free(cred);

	payload.username = NULL;
	cl_git_pass(git_cred_userpass(&cred, NULL, "bob", GIT_CREDTYPE_USERPASS_PLAINTEXT, &payload));
	plain = (git_cred_userpass_plaintext*)cred;
	cl_assert_equal_s(plain->username, "bob");
	cred->free(cred);
}

