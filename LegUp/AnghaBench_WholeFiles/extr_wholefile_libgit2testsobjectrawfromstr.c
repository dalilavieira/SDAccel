#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  id; } ;
typedef  TYPE_1__ git_oid ;

/* Variables and functions */
 int /*<<< orphan*/  cl_git_fail (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_oid_fromstr (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  memcmp (int /*<<< orphan*/ ,unsigned char*,int) ; 

void test_object_raw_fromstr__fail_on_invalid_oid_string(void)
{
	git_oid out;
	cl_git_fail(git_oid_fromstr(&out, ""));
	cl_git_fail(git_oid_fromstr(&out, "moo"));
	cl_git_fail(git_oid_fromstr(&out, "16a67770b7d8d72317c4b775213c23a8bd74f5ez"));
}

void test_object_raw_fromstr__succeed_on_valid_oid_string(void)
{
	git_oid out;
	unsigned char exp[] = {
		0x16, 0xa6, 0x77, 0x70, 0xb7,
		0xd8, 0xd7, 0x23, 0x17, 0xc4,
		0xb7, 0x75, 0x21, 0x3c, 0x23,
		0xa8, 0xbd, 0x74, 0xf5, 0xe0,
	};

	cl_git_pass(git_oid_fromstr(&out, "16a67770b7d8d72317c4b775213c23a8bd74f5e0"));
	cl_git_pass(memcmp(out.id, exp, sizeof(out.id)));

	cl_git_pass(git_oid_fromstr(&out, "16A67770B7D8D72317C4b775213C23A8BD74F5E0"));
	cl_git_pass(memcmp(out.id, exp, sizeof(out.id)));

}

