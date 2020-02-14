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
struct ida {int dummy; } ;

/* Variables and functions */
 unsigned long BITS_PER_LONG ; 
 int EINVAL ; 
 unsigned long ENOSPC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long IDA_BITMAP_BITS ; 
 int /*<<< orphan*/  IDA_BUG_ON (struct ida*,int) ; 
 struct ida ida ; 
 unsigned long ida_alloc (struct ida*,int /*<<< orphan*/ ) ; 
 unsigned long ida_alloc_min (struct ida*,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ida_destroy (struct ida*) ; 
 int /*<<< orphan*/  ida_free (struct ida*,unsigned long) ; 
 int ida_is_empty (struct ida*) ; 
 int /*<<< orphan*/  printk (char*,scalar_t__,scalar_t__) ; 
 scalar_t__ tests_passed ; 
 scalar_t__ tests_run ; 

__attribute__((used)) static void ida_check_alloc(struct ida *ida)
{
	int i, id;

	for (i = 0; i < 10000; i++)
		IDA_BUG_ON(ida, ida_alloc(ida, GFP_KERNEL) != i);

	ida_free(ida, 20);
	ida_free(ida, 21);
	for (i = 0; i < 3; i++) {
		id = ida_alloc(ida, GFP_KERNEL);
		IDA_BUG_ON(ida, id < 0);
		if (i == 2)
			IDA_BUG_ON(ida, id != 10000);
	}

	for (i = 0; i < 5000; i++)
		ida_free(ida, i);

	IDA_BUG_ON(ida, ida_alloc_min(ida, 5000, GFP_KERNEL) != 10001);
	ida_destroy(ida);

	IDA_BUG_ON(ida, !ida_is_empty(ida));
}

__attribute__((used)) static void ida_check_destroy_1(struct ida *ida, unsigned int base)
{
	IDA_BUG_ON(ida, ida_alloc_min(ida, base, GFP_KERNEL) != base);
	IDA_BUG_ON(ida, ida_is_empty(ida));
	ida_destroy(ida);
	IDA_BUG_ON(ida, !ida_is_empty(ida));
}

__attribute__((used)) static void ida_check_destroy(struct ida *ida)
{
	/* Destroy an already-empty IDA */
	IDA_BUG_ON(ida, !ida_is_empty(ida));
	ida_destroy(ida);
	IDA_BUG_ON(ida, !ida_is_empty(ida));

	ida_check_destroy_1(ida, 0);
	ida_check_destroy_1(ida, 1);
	ida_check_destroy_1(ida, 1023);
	ida_check_destroy_1(ida, 1024);
	ida_check_destroy_1(ida, 12345678);
}

__attribute__((used)) static void ida_check_leaf(struct ida *ida, unsigned int base)
{
	unsigned long i;

	for (i = 0; i < IDA_BITMAP_BITS; i++) {
		IDA_BUG_ON(ida, ida_alloc_min(ida, base, GFP_KERNEL) !=
				base + i);
	}

	ida_destroy(ida);
	IDA_BUG_ON(ida, !ida_is_empty(ida));

	IDA_BUG_ON(ida, ida_alloc(ida, GFP_KERNEL) != 0);
	IDA_BUG_ON(ida, ida_is_empty(ida));
	ida_free(ida, 0);
	IDA_BUG_ON(ida, !ida_is_empty(ida));
}

__attribute__((used)) static void ida_check_max(struct ida *ida)
{
	unsigned long i, j;

	for (j = 1; j < 65537; j *= 2) {
		unsigned long base = (1UL << 31) - j;
		for (i = 0; i < j; i++) {
			IDA_BUG_ON(ida, ida_alloc_min(ida, base, GFP_KERNEL) !=
					base + i);
		}
		IDA_BUG_ON(ida, ida_alloc_min(ida, base, GFP_KERNEL) !=
				-ENOSPC);
		ida_destroy(ida);
		IDA_BUG_ON(ida, !ida_is_empty(ida));
	}
}

__attribute__((used)) static void ida_check_conv(struct ida *ida)
{
	unsigned long i;

	for (i = 0; i < IDA_BITMAP_BITS * 2; i += IDA_BITMAP_BITS) {
		IDA_BUG_ON(ida, ida_alloc_min(ida, i + 1, GFP_KERNEL) != i + 1);
		IDA_BUG_ON(ida, ida_alloc_min(ida, i + BITS_PER_LONG,
					GFP_KERNEL) != i + BITS_PER_LONG);
		ida_free(ida, i + 1);
		ida_free(ida, i + BITS_PER_LONG);
		IDA_BUG_ON(ida, !ida_is_empty(ida));
	}

	for (i = 0; i < IDA_BITMAP_BITS * 2; i++)
		IDA_BUG_ON(ida, ida_alloc(ida, GFP_KERNEL) != i);
	for (i = IDA_BITMAP_BITS * 2; i > 0; i--)
		ida_free(ida, i - 1);
	IDA_BUG_ON(ida, !ida_is_empty(ida));

	for (i = 0; i < IDA_BITMAP_BITS + BITS_PER_LONG - 4; i++)
		IDA_BUG_ON(ida, ida_alloc(ida, GFP_KERNEL) != i);
	for (i = IDA_BITMAP_BITS + BITS_PER_LONG - 4; i > 0; i--)
		ida_free(ida, i - 1);
	IDA_BUG_ON(ida, !ida_is_empty(ida));
}

__attribute__((used)) static int ida_checks(void)
{
	IDA_BUG_ON(&ida, !ida_is_empty(&ida));
	ida_check_alloc(&ida);
	ida_check_destroy(&ida);
	ida_check_leaf(&ida, 0);
	ida_check_leaf(&ida, 1024);
	ida_check_leaf(&ida, 1024 * 64);
	ida_check_max(&ida);
	ida_check_conv(&ida);

	printk("IDA: %u of %u tests passed\n", tests_passed, tests_run);
	return (tests_run != tests_passed) ? 0 : -EINVAL;
}

__attribute__((used)) static void ida_exit(void)
{
}

