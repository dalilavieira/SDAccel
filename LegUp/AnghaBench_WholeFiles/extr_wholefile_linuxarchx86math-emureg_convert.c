#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct desc_struct {unsigned long base0; unsigned long limit0; int type; scalar_t__ g; scalar_t__ limit1; scalar_t__ base1; scalar_t__ base2; } ;
struct TYPE_12__ {int sigh; int /*<<< orphan*/  sigl; int /*<<< orphan*/  exp; } ;
typedef  TYPE_1__ FPU_REG ;

/* Variables and functions */
 int /*<<< orphan*/  EXCEPTION (int) ; 
 scalar_t__ EXP_UNDER ; 
 int EX_INTERNAL ; 
 int /*<<< orphan*/  FPU_normalize_nuo (TYPE_1__*) ; 
 int SEG_TYPE_EXECUTE ; 
 int SEG_TYPE_EXECUTE_MASK ; 
 int SEG_TYPE_EXPANDS_DOWN ; 
 int SEG_TYPE_EXPAND_MASK ; 
 int SEG_TYPE_WRITABLE ; 
 int /*<<< orphan*/  addexponent (TYPE_1__*,int) ; 
 int /*<<< orphan*/  exponent (TYPE_1__ const*) ; 
 scalar_t__ exponent16 (TYPE_1__*) ; 
 int getsign (TYPE_1__ const*) ; 
 int /*<<< orphan*/  setexponent16 (TYPE_1__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct desc_struct FPU_get_ldt_descriptor(unsigned seg)
{
	static struct desc_struct zero_desc;
	struct desc_struct ret = zero_desc;

#ifdef CONFIG_MODIFY_LDT_SYSCALL
	seg >>= 3;
	mutex_lock(&current->mm->context.lock);
	if (current->mm->context.ldt && seg < current->mm->context.ldt->nr_entries)
		ret = current->mm->context.ldt->entries[seg];
	mutex_unlock(&current->mm->context.lock);
#endif
	return ret;
}

__attribute__((used)) static inline unsigned long seg_get_base(struct desc_struct *d)
{
	unsigned long base = (unsigned long)d->base2 << 24;

	return base | ((unsigned long)d->base1 << 16) | d->base0;
}

__attribute__((used)) static inline unsigned long seg_get_limit(struct desc_struct *d)
{
	return ((unsigned long)d->limit1 << 16) | d->limit0;
}

__attribute__((used)) static inline unsigned long seg_get_granularity(struct desc_struct *d)
{
	return d->g ? 4096 : 1;
}

__attribute__((used)) static inline bool seg_expands_down(struct desc_struct *d)
{
	return (d->type & SEG_TYPE_EXPAND_MASK) == SEG_TYPE_EXPANDS_DOWN;
}

__attribute__((used)) static inline bool seg_execute_only(struct desc_struct *d)
{
	return (d->type & SEG_TYPE_EXECUTE_MASK) == SEG_TYPE_EXECUTE;
}

__attribute__((used)) static inline bool seg_writable(struct desc_struct *d)
{
	return (d->type & SEG_TYPE_EXECUTE_MASK) == SEG_TYPE_WRITABLE;
}

__attribute__((used)) static inline void reg_copy(FPU_REG const *x, FPU_REG *y)
{
	*(short *)&(y->exp) = *(const short *)&(x->exp);
	*(long long *)&(y->sigl) = *(const long long *)&(x->sigl);
}

int FPU_to_exp16(FPU_REG const *a, FPU_REG *x)
{
	int sign = getsign(a);

	*(long long *)&(x->sigl) = *(const long long *)&(a->sigl);

	/* Set up the exponent as a 16 bit quantity. */
	setexponent16(x, exponent(a));

	if (exponent16(x) == EXP_UNDER) {
		/* The number is a de-normal or pseudodenormal. */
		/* We only deal with the significand and exponent. */

		if (x->sigh & 0x80000000) {
			/* Is a pseudodenormal. */
			/* This is non-80486 behaviour because the number
			   loses its 'denormal' identity. */
			addexponent(x, 1);
		} else {
			/* Is a denormal. */
			addexponent(x, 1);
			FPU_normalize_nuo(x);
		}
	}

	if (!(x->sigh & 0x80000000)) {
		EXCEPTION(EX_INTERNAL | 0x180);
	}

	return sign;
}

