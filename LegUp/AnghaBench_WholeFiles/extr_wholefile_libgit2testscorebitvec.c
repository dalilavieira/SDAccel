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
typedef  int /*<<< orphan*/  git_bitvec ;

/* Variables and functions */
 int /*<<< orphan*/  cl_assert_equal_b (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cl_git_pass (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  git_bitvec_clear (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_bitvec_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_bitvec_get (int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  git_bitvec_init (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  git_bitvec_set (int /*<<< orphan*/ *,size_t,int) ; 

__attribute__((used)) static void set_some_bits(git_bitvec *bv, size_t length)
{
	size_t i;

	for (i = 0; i < length; ++i) {
		if (i % 3 == 0 || i % 7 == 0)
			git_bitvec_set(bv, i, true);
	}
}

__attribute__((used)) static void check_some_bits(git_bitvec *bv, size_t length)
{
	size_t i;

	for (i = 0; i < length; ++i)
		cl_assert_equal_b(i % 3 == 0 || i % 7 == 0, git_bitvec_get(bv, i));
}

void test_core_bitvec__0(void)
{
	git_bitvec bv;

	cl_git_pass(git_bitvec_init(&bv, 32));
	set_some_bits(&bv, 16);
	check_some_bits(&bv, 16);
	git_bitvec_clear(&bv);
	set_some_bits(&bv, 32);
	check_some_bits(&bv, 32);
	git_bitvec_clear(&bv);
	set_some_bits(&bv, 64);
	check_some_bits(&bv, 64);
	git_bitvec_free(&bv);

	cl_git_pass(git_bitvec_init(&bv, 128));
	set_some_bits(&bv, 32);
	check_some_bits(&bv, 32);
	set_some_bits(&bv, 128);
	check_some_bits(&bv, 128);
	git_bitvec_free(&bv);

	cl_git_pass(git_bitvec_init(&bv, 4000));
	set_some_bits(&bv, 4000);
	check_some_bits(&bv, 4000);
	git_bitvec_free(&bv);
}

