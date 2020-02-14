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
typedef  int /*<<< orphan*/  refcount_t ;
typedef  int /*<<< orphan*/  atomic_t ;

/* Variables and functions */
 int /*<<< orphan*/  ATOMIC_INIT (int) ; 
 int INT_MAX ; 
 int /*<<< orphan*/  REFCOUNT_INIT (int const) ; 
#define  REFCOUNT_MAX 129 
#define  REFCOUNT_SATURATED 128 
 scalar_t__ atomic_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  pr_info (char*,...) ; 
 int /*<<< orphan*/  pr_warn (char*,...) ; 
 int /*<<< orphan*/  refcount_add (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  refcount_add_not_zero (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  refcount_dec (int /*<<< orphan*/ *) ; 
 scalar_t__ refcount_dec_and_test (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  refcount_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  refcount_inc_not_zero (int /*<<< orphan*/ *) ; 
 unsigned int refcount_read (int /*<<< orphan*/ *) ; 
 scalar_t__ refcount_sub_and_test (int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void overflow_check(refcount_t *ref)
{
	switch (refcount_read(ref)) {
	case REFCOUNT_SATURATED:
		pr_info("Overflow detected: saturated\n");
		break;
	case REFCOUNT_MAX:
		pr_warn("Overflow detected: unsafely reset to max\n");
		break;
	default:
		pr_err("Fail: refcount wrapped to %d\n", refcount_read(ref));
	}
}

void lkdtm_REFCOUNT_INC_OVERFLOW(void)
{
	refcount_t over = REFCOUNT_INIT(REFCOUNT_MAX - 1);

	pr_info("attempting good refcount_inc() without overflow\n");
	refcount_dec(&over);
	refcount_inc(&over);

	pr_info("attempting bad refcount_inc() overflow\n");
	refcount_inc(&over);
	refcount_inc(&over);

	overflow_check(&over);
}

void lkdtm_REFCOUNT_ADD_OVERFLOW(void)
{
	refcount_t over = REFCOUNT_INIT(REFCOUNT_MAX - 1);

	pr_info("attempting good refcount_add() without overflow\n");
	refcount_dec(&over);
	refcount_dec(&over);
	refcount_dec(&over);
	refcount_dec(&over);
	refcount_add(4, &over);

	pr_info("attempting bad refcount_add() overflow\n");
	refcount_add(4, &over);

	overflow_check(&over);
}

void lkdtm_REFCOUNT_INC_NOT_ZERO_OVERFLOW(void)
{
	refcount_t over = REFCOUNT_INIT(REFCOUNT_MAX);

	pr_info("attempting bad refcount_inc_not_zero() overflow\n");
	if (!refcount_inc_not_zero(&over))
		pr_warn("Weird: refcount_inc_not_zero() reported zero\n");

	overflow_check(&over);
}

void lkdtm_REFCOUNT_ADD_NOT_ZERO_OVERFLOW(void)
{
	refcount_t over = REFCOUNT_INIT(REFCOUNT_MAX);

	pr_info("attempting bad refcount_add_not_zero() overflow\n");
	if (!refcount_add_not_zero(6, &over))
		pr_warn("Weird: refcount_add_not_zero() reported zero\n");

	overflow_check(&over);
}

__attribute__((used)) static void check_zero(refcount_t *ref)
{
	switch (refcount_read(ref)) {
	case REFCOUNT_SATURATED:
		pr_info("Zero detected: saturated\n");
		break;
	case REFCOUNT_MAX:
		pr_warn("Zero detected: unsafely reset to max\n");
		break;
	case 0:
		pr_warn("Still at zero: refcount_inc/add() must not inc-from-0\n");
		break;
	default:
		pr_err("Fail: refcount went crazy: %d\n", refcount_read(ref));
	}
}

void lkdtm_REFCOUNT_DEC_ZERO(void)
{
	refcount_t zero = REFCOUNT_INIT(2);

	pr_info("attempting good refcount_dec()\n");
	refcount_dec(&zero);

	pr_info("attempting bad refcount_dec() to zero\n");
	refcount_dec(&zero);

	check_zero(&zero);
}

__attribute__((used)) static void check_negative(refcount_t *ref, int start)
{
	/*
	 * CONFIG_REFCOUNT_FULL refuses to move a refcount at all on an
	 * over-sub, so we have to track our starting position instead of
	 * looking only at zero-pinning.
	 */
	if (refcount_read(ref) == start) {
		pr_warn("Still at %d: refcount_inc/add() must not inc-from-0\n",
			start);
		return;
	}

	switch (refcount_read(ref)) {
	case REFCOUNT_SATURATED:
		pr_info("Negative detected: saturated\n");
		break;
	case REFCOUNT_MAX:
		pr_warn("Negative detected: unsafely reset to max\n");
		break;
	default:
		pr_err("Fail: refcount went crazy: %d\n", refcount_read(ref));
	}
}

void lkdtm_REFCOUNT_DEC_NEGATIVE(void)
{
	refcount_t neg = REFCOUNT_INIT(0);

	pr_info("attempting bad refcount_dec() below zero\n");
	refcount_dec(&neg);

	check_negative(&neg, 0);
}

void lkdtm_REFCOUNT_DEC_AND_TEST_NEGATIVE(void)
{
	refcount_t neg = REFCOUNT_INIT(0);

	pr_info("attempting bad refcount_dec_and_test() below zero\n");
	if (refcount_dec_and_test(&neg))
		pr_warn("Weird: refcount_dec_and_test() reported zero\n");

	check_negative(&neg, 0);
}

void lkdtm_REFCOUNT_SUB_AND_TEST_NEGATIVE(void)
{
	refcount_t neg = REFCOUNT_INIT(3);

	pr_info("attempting bad refcount_sub_and_test() below zero\n");
	if (refcount_sub_and_test(5, &neg))
		pr_warn("Weird: refcount_sub_and_test() reported zero\n");

	check_negative(&neg, 3);
}

__attribute__((used)) static void check_from_zero(refcount_t *ref)
{
	switch (refcount_read(ref)) {
	case 0:
		pr_info("Zero detected: stayed at zero\n");
		break;
	case REFCOUNT_SATURATED:
		pr_info("Zero detected: saturated\n");
		break;
	case REFCOUNT_MAX:
		pr_warn("Zero detected: unsafely reset to max\n");
		break;
	default:
		pr_info("Fail: zero not detected, incremented to %d\n",
			refcount_read(ref));
	}
}

void lkdtm_REFCOUNT_INC_ZERO(void)
{
	refcount_t zero = REFCOUNT_INIT(0);

	pr_info("attempting safe refcount_inc_not_zero() from zero\n");
	if (!refcount_inc_not_zero(&zero)) {
		pr_info("Good: zero detected\n");
		if (refcount_read(&zero) == 0)
			pr_info("Correctly stayed at zero\n");
		else
			pr_err("Fail: refcount went past zero!\n");
	} else {
		pr_err("Fail: Zero not detected!?\n");
	}

	pr_info("attempting bad refcount_inc() from zero\n");
	refcount_inc(&zero);

	check_from_zero(&zero);
}

void lkdtm_REFCOUNT_ADD_ZERO(void)
{
	refcount_t zero = REFCOUNT_INIT(0);

	pr_info("attempting safe refcount_add_not_zero() from zero\n");
	if (!refcount_add_not_zero(3, &zero)) {
		pr_info("Good: zero detected\n");
		if (refcount_read(&zero) == 0)
			pr_info("Correctly stayed at zero\n");
		else
			pr_err("Fail: refcount went past zero\n");
	} else {
		pr_err("Fail: Zero not detected!?\n");
	}

	pr_info("attempting bad refcount_add() from zero\n");
	refcount_add(3, &zero);

	check_from_zero(&zero);
}

__attribute__((used)) static void check_saturated(refcount_t *ref)
{
	switch (refcount_read(ref)) {
	case REFCOUNT_SATURATED:
		pr_info("Saturation detected: still saturated\n");
		break;
	case REFCOUNT_MAX:
		pr_warn("Saturation detected: unsafely reset to max\n");
		break;
	default:
		pr_err("Fail: refcount went crazy: %d\n", refcount_read(ref));
	}
}

void lkdtm_REFCOUNT_INC_SATURATED(void)
{
	refcount_t sat = REFCOUNT_INIT(REFCOUNT_SATURATED);

	pr_info("attempting bad refcount_inc() from saturated\n");
	refcount_inc(&sat);

	check_saturated(&sat);
}

void lkdtm_REFCOUNT_DEC_SATURATED(void)
{
	refcount_t sat = REFCOUNT_INIT(REFCOUNT_SATURATED);

	pr_info("attempting bad refcount_dec() from saturated\n");
	refcount_dec(&sat);

	check_saturated(&sat);
}

void lkdtm_REFCOUNT_ADD_SATURATED(void)
{
	refcount_t sat = REFCOUNT_INIT(REFCOUNT_SATURATED);

	pr_info("attempting bad refcount_dec() from saturated\n");
	refcount_add(8, &sat);

	check_saturated(&sat);
}

void lkdtm_REFCOUNT_INC_NOT_ZERO_SATURATED(void)
{
	refcount_t sat = REFCOUNT_INIT(REFCOUNT_SATURATED);

	pr_info("attempting bad refcount_inc_not_zero() from saturated\n");
	if (!refcount_inc_not_zero(&sat))
		pr_warn("Weird: refcount_inc_not_zero() reported zero\n");

	check_saturated(&sat);
}

void lkdtm_REFCOUNT_ADD_NOT_ZERO_SATURATED(void)
{
	refcount_t sat = REFCOUNT_INIT(REFCOUNT_SATURATED);

	pr_info("attempting bad refcount_add_not_zero() from saturated\n");
	if (!refcount_add_not_zero(7, &sat))
		pr_warn("Weird: refcount_add_not_zero() reported zero\n");

	check_saturated(&sat);
}

void lkdtm_REFCOUNT_DEC_AND_TEST_SATURATED(void)
{
	refcount_t sat = REFCOUNT_INIT(REFCOUNT_SATURATED);

	pr_info("attempting bad refcount_dec_and_test() from saturated\n");
	if (refcount_dec_and_test(&sat))
		pr_warn("Weird: refcount_dec_and_test() reported zero\n");

	check_saturated(&sat);
}

void lkdtm_REFCOUNT_SUB_AND_TEST_SATURATED(void)
{
	refcount_t sat = REFCOUNT_INIT(REFCOUNT_SATURATED);

	pr_info("attempting bad refcount_sub_and_test() from saturated\n");
	if (refcount_sub_and_test(8, &sat))
		pr_warn("Weird: refcount_sub_and_test() reported zero\n");

	check_saturated(&sat);
}

void lkdtm_ATOMIC_TIMING(void)
{
	unsigned int i;
	atomic_t count = ATOMIC_INIT(1);

	for (i = 0; i < INT_MAX - 1; i++)
		atomic_inc(&count);

	for (i = INT_MAX; i > 0; i--)
		if (atomic_dec_and_test(&count))
			break;

	if (i != 1)
		pr_err("atomic timing: out of sync up/down cycle: %u\n", i - 1);
	else
		pr_info("atomic timing: done\n");
}

void lkdtm_REFCOUNT_TIMING(void)
{
	unsigned int i;
	refcount_t count = REFCOUNT_INIT(1);

	for (i = 0; i < INT_MAX - 1; i++)
		refcount_inc(&count);

	for (i = INT_MAX; i > 0; i--)
		if (refcount_dec_and_test(&count))
			break;

	if (i != 1)
		pr_err("refcount: out of sync up/down cycle: %u\n", i - 1);
	else
		pr_info("refcount timing: done\n");
}

