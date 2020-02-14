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
 int /*<<< orphan*/  cl_assert (int) ; 
 int /*<<< orphan*/  cl_assert_equal_i (int,scalar_t__) ; 
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_fromstr (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  git_oid_fromstrp (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int git_oid_ncmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 scalar_t__ git_oid_strcmp (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ git_oid_streq (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  id ; 
 int /*<<< orphan*/  idm ; 
 int /*<<< orphan*/  idp ; 
 char* str_oid ; 
 int /*<<< orphan*/  str_oid_m ; 
 int /*<<< orphan*/  str_oid_p ; 

void test_core_oid__initialize(void)
{
	cl_git_pass(git_oid_fromstr(&id, str_oid));
	cl_git_pass(git_oid_fromstrp(&idp, str_oid_p));
	cl_git_fail(git_oid_fromstrp(&idm, str_oid_m));
}

void test_core_oid__streq(void)
{
	cl_assert_equal_i(0, git_oid_streq(&id, str_oid));
	cl_assert_equal_i(-1, git_oid_streq(&id, "deadbeefdeadbeefdeadbeefdeadbeefdeadbeef"));

	cl_assert_equal_i(-1, git_oid_streq(&id, "deadbeef"));
	cl_assert_equal_i(-1, git_oid_streq(&id, "I'm not an oid.... :)"));

	cl_assert_equal_i(0, git_oid_streq(&idp, "ae90f12eea699729ed0000000000000000000000"));
	cl_assert_equal_i(0, git_oid_streq(&idp, "ae90f12eea699729ed"));
	cl_assert_equal_i(-1, git_oid_streq(&idp, "ae90f12eea699729ed1"));
	cl_assert_equal_i(-1, git_oid_streq(&idp, "ae90f12eea699729ec"));
	cl_assert_equal_i(-1, git_oid_streq(&idp, "deadbeefdeadbeefdeadbeefdeadbeefdeadbeef"));

	cl_assert_equal_i(-1, git_oid_streq(&idp, "deadbeef"));
	cl_assert_equal_i(-1, git_oid_streq(&idp, "I'm not an oid.... :)"));
}

void test_core_oid__strcmp(void)
{
	cl_assert_equal_i(0, git_oid_strcmp(&id, str_oid));
	cl_assert(git_oid_strcmp(&id, "deadbeefdeadbeefdeadbeefdeadbeefdeadbeef") < 0);

	cl_assert(git_oid_strcmp(&id, "deadbeef") < 0);
	cl_assert_equal_i(-1, git_oid_strcmp(&id, "I'm not an oid.... :)"));

	cl_assert_equal_i(0, git_oid_strcmp(&idp, "ae90f12eea699729ed0000000000000000000000"));
	cl_assert_equal_i(0, git_oid_strcmp(&idp, "ae90f12eea699729ed"));
	cl_assert(git_oid_strcmp(&idp, "ae90f12eea699729ed1") < 0);
	cl_assert(git_oid_strcmp(&idp, "ae90f12eea699729ec") > 0);
	cl_assert(git_oid_strcmp(&idp, "deadbeefdeadbeefdeadbeefdeadbeefdeadbeef") < 0);

	cl_assert(git_oid_strcmp(&idp, "deadbeef") < 0);
	cl_assert_equal_i(-1, git_oid_strcmp(&idp, "I'm not an oid.... :)"));
}

void test_core_oid__ncmp(void)
{
	cl_assert(!git_oid_ncmp(&id, &idp, 0));
	cl_assert(!git_oid_ncmp(&id, &idp, 1));
	cl_assert(!git_oid_ncmp(&id, &idp, 2));
	cl_assert(!git_oid_ncmp(&id, &idp, 17));
	cl_assert(!git_oid_ncmp(&id, &idp, 18));
	cl_assert(git_oid_ncmp(&id, &idp, 19));
	cl_assert(git_oid_ncmp(&id, &idp, 40));
	cl_assert(git_oid_ncmp(&id, &idp, 41));
	cl_assert(git_oid_ncmp(&id, &idp, 42));

	cl_assert(!git_oid_ncmp(&id, &id, 0));
	cl_assert(!git_oid_ncmp(&id, &id, 1));
	cl_assert(!git_oid_ncmp(&id, &id, 39));
	cl_assert(!git_oid_ncmp(&id, &id, 40));
	cl_assert(!git_oid_ncmp(&id, &id, 41));
}

