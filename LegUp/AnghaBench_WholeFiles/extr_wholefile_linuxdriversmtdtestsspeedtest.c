#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint64_t ;
struct erase_info {int addr; int len; } ;
typedef  int loff_t ;
struct TYPE_5__ {int erasesize; } ;

/* Variables and functions */
 int EINTR ; 
 int /*<<< orphan*/  cond_resched () ; 
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  do_div (int,long) ; 
 void* finish ; 
 scalar_t__ goodebcnt ; 
 void* iobuf ; 
 void* ktime_get () ; 
 long ktime_ms_delta (void*,void*) ; 
 int /*<<< orphan*/  memset (struct erase_info*,int /*<<< orphan*/ ,int) ; 
 TYPE_1__* mtd ; 
 int mtd_erase (TYPE_1__*,struct erase_info*) ; 
 int mtdtest_read (TYPE_1__*,int,int,void*) ; 
 int mtdtest_write (TYPE_1__*,int,int,void*) ; 
 int pgcnt ; 
 int pgsize ; 
 int /*<<< orphan*/  pr_err (char*,int,int,int) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 scalar_t__ signal_pending (int /*<<< orphan*/ ) ; 
 void* start ; 

__attribute__((used)) static inline int mtdtest_relax(void)
{
	cond_resched();
	if (signal_pending(current)) {
		pr_info("aborting test due to pending signal!\n");
		return -EINTR;
	}

	return 0;
}

__attribute__((used)) static int multiblock_erase(int ebnum, int blocks)
{
	int err;
	struct erase_info ei;
	loff_t addr = (loff_t)ebnum * mtd->erasesize;

	memset(&ei, 0, sizeof(struct erase_info));
	ei.addr = addr;
	ei.len  = mtd->erasesize * blocks;

	err = mtd_erase(mtd, &ei);
	if (err) {
		pr_err("error %d while erasing EB %d, blocks %d\n",
		       err, ebnum, blocks);
		return err;
	}

	return 0;
}

__attribute__((used)) static int write_eraseblock(int ebnum)
{
	loff_t addr = (loff_t)ebnum * mtd->erasesize;

	return mtdtest_write(mtd, addr, mtd->erasesize, iobuf);
}

__attribute__((used)) static int write_eraseblock_by_page(int ebnum)
{
	int i, err = 0;
	loff_t addr = (loff_t)ebnum * mtd->erasesize;
	void *buf = iobuf;

	for (i = 0; i < pgcnt; i++) {
		err = mtdtest_write(mtd, addr, pgsize, buf);
		if (err)
			break;
		addr += pgsize;
		buf += pgsize;
	}

	return err;
}

__attribute__((used)) static int write_eraseblock_by_2pages(int ebnum)
{
	size_t sz = pgsize * 2;
	int i, n = pgcnt / 2, err = 0;
	loff_t addr = (loff_t)ebnum * mtd->erasesize;
	void *buf = iobuf;

	for (i = 0; i < n; i++) {
		err = mtdtest_write(mtd, addr, sz, buf);
		if (err)
			return err;
		addr += sz;
		buf += sz;
	}
	if (pgcnt % 2)
		err = mtdtest_write(mtd, addr, pgsize, buf);

	return err;
}

__attribute__((used)) static int read_eraseblock(int ebnum)
{
	loff_t addr = (loff_t)ebnum * mtd->erasesize;

	return mtdtest_read(mtd, addr, mtd->erasesize, iobuf);
}

__attribute__((used)) static int read_eraseblock_by_page(int ebnum)
{
	int i, err = 0;
	loff_t addr = (loff_t)ebnum * mtd->erasesize;
	void *buf = iobuf;

	for (i = 0; i < pgcnt; i++) {
		err = mtdtest_read(mtd, addr, pgsize, buf);
		if (err)
			break;
		addr += pgsize;
		buf += pgsize;
	}

	return err;
}

__attribute__((used)) static int read_eraseblock_by_2pages(int ebnum)
{
	size_t sz = pgsize * 2;
	int i, n = pgcnt / 2, err = 0;
	loff_t addr = (loff_t)ebnum * mtd->erasesize;
	void *buf = iobuf;

	for (i = 0; i < n; i++) {
		err = mtdtest_read(mtd, addr, sz, buf);
		if (err)
			return err;
		addr += sz;
		buf += sz;
	}
	if (pgcnt % 2)
		err = mtdtest_read(mtd, addr, pgsize, buf);

	return err;
}

__attribute__((used)) static inline void start_timing(void)
{
	start = ktime_get();
}

__attribute__((used)) static inline void stop_timing(void)
{
	finish = ktime_get();
}

__attribute__((used)) static long calc_speed(void)
{
	uint64_t k;
	long ms;

	ms = ktime_ms_delta(finish, start);
	if (ms == 0)
		return 0;
	k = (uint64_t)goodebcnt * (mtd->erasesize / 1024) * 1000;
	do_div(k, ms);
	return k;
}

