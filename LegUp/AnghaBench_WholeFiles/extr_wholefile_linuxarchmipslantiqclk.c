#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_2__ {int /*<<< orphan*/  con_id; int /*<<< orphan*/  dev_id; } ;
struct clk {unsigned long rate; unsigned long (* get_rate ) () ;unsigned long* rates; int (* enable ) (struct clk*) ;int (* activate ) (struct clk*) ;int /*<<< orphan*/  (* deactivate ) (struct clk*) ;int /*<<< orphan*/  (* disable ) (struct clk*) ;TYPE_1__ cl; } ;

/* Variables and functions */
 int /*<<< orphan*/  IS_ERR (struct clk*) ; 
 struct clk* cpu_clk_generic ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned long) ; 
 unsigned long stub1 () ; 
 int stub2 (struct clk*) ; 
 int /*<<< orphan*/  stub3 (struct clk*) ; 
 int stub4 (struct clk*) ; 
 int /*<<< orphan*/  stub5 (struct clk*) ; 
 scalar_t__ unlikely (int) ; 

void clkdev_add_static(unsigned long cpu, unsigned long fpi,
			unsigned long io, unsigned long ppe)
{
	cpu_clk_generic[0].rate = cpu;
	cpu_clk_generic[1].rate = fpi;
	cpu_clk_generic[2].rate = io;
	cpu_clk_generic[3].rate = ppe;
}

struct clk *clk_get_cpu(void)
{
	return &cpu_clk_generic[0];
}

struct clk *clk_get_fpi(void)
{
	return &cpu_clk_generic[1];
}

struct clk *clk_get_io(void)
{
	return &cpu_clk_generic[2];
}

struct clk *clk_get_ppe(void)
{
	return &cpu_clk_generic[3];
}

__attribute__((used)) static inline int clk_good(struct clk *clk)
{
	return clk && !IS_ERR(clk);
}

unsigned long clk_get_rate(struct clk *clk)
{
	if (unlikely(!clk_good(clk)))
		return 0;

	if (clk->rate != 0)
		return clk->rate;

	if (clk->get_rate != NULL)
		return clk->get_rate();

	return 0;
}

int clk_set_rate(struct clk *clk, unsigned long rate)
{
	if (unlikely(!clk_good(clk)))
		return 0;
	if (clk->rates && *clk->rates) {
		unsigned long *r = clk->rates;

		while (*r && (*r != rate))
			r++;
		if (!*r) {
			pr_err("clk %s.%s: trying to set invalid rate %ld\n",
				clk->cl.dev_id, clk->cl.con_id, rate);
			return -1;
		}
	}
	clk->rate = rate;
	return 0;
}

long clk_round_rate(struct clk *clk, unsigned long rate)
{
	if (unlikely(!clk_good(clk)))
		return 0;
	if (clk->rates && *clk->rates) {
		unsigned long *r = clk->rates;

		while (*r && (*r != rate))
			r++;
		if (!*r) {
			return clk->rate;
		}
	}
	return rate;
}

int clk_enable(struct clk *clk)
{
	if (unlikely(!clk_good(clk)))
		return -1;

	if (clk->enable)
		return clk->enable(clk);

	return -1;
}

void clk_disable(struct clk *clk)
{
	if (unlikely(!clk_good(clk)))
		return;

	if (clk->disable)
		clk->disable(clk);
}

int clk_activate(struct clk *clk)
{
	if (unlikely(!clk_good(clk)))
		return -1;

	if (clk->activate)
		return clk->activate(clk);

	return -1;
}

void clk_deactivate(struct clk *clk)
{
	if (unlikely(!clk_good(clk)))
		return;

	if (clk->deactivate)
		clk->deactivate(clk);
}

__attribute__((used)) static inline u32 get_counter_resolution(void)
{
	u32 res;

	__asm__ __volatile__(
		".set	push\n"
		".set	mips32r2\n"
		"rdhwr	%0, $3\n"
		".set pop\n"
		: "=&r" (res)
		: /* no input */
		: "memory");

	return res;
}

