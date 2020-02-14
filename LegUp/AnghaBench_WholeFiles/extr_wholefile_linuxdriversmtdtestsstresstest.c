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
typedef  int loff_t ;
struct TYPE_5__ {int erasesize; } ;

/* Variables and functions */
 int EINTR ; 
 scalar_t__* bbt ; 
 unsigned int bufsize ; 
 int /*<<< orphan*/  cond_resched () ; 
 int /*<<< orphan*/  current ; 
 int ebcnt ; 
 TYPE_1__* mtd ; 
 int mtdtest_erase_eraseblock (TYPE_1__*,int) ; 
 int mtdtest_read (TYPE_1__*,int,int,int /*<<< orphan*/ ) ; 
 int mtdtest_write (TYPE_1__*,int,int,int /*<<< orphan*/ ) ; 
 int* offsets ; 
 int pgsize ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int prandom_u32 () ; 
 int /*<<< orphan*/  readbuf ; 
 scalar_t__ signal_pending (int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  writebuf ; 

__attribute__((used)) static inline int mtdtest_relax(void)
{
	cond_resched();
	if (signal_pending(current)) {
		pr_info("aborting test due to pending signal!\n");
		return -EINTR;
	}

	return 0;
}

__attribute__((used)) static int rand_eb(void)
{
	unsigned int eb;

again:
	eb = prandom_u32();
	/* Read or write up 2 eraseblocks at a time - hence 'ebcnt - 1' */
	eb %= (ebcnt - 1);
	if (bbt[eb])
		goto again;
	return eb;
}

__attribute__((used)) static int rand_offs(void)
{
	unsigned int offs;

	offs = prandom_u32();
	offs %= bufsize;
	return offs;
}

__attribute__((used)) static int rand_len(int offs)
{
	unsigned int len;

	len = prandom_u32();
	len %= (bufsize - offs);
	return len;
}

__attribute__((used)) static int do_read(void)
{
	int eb = rand_eb();
	int offs = rand_offs();
	int len = rand_len(offs);
	loff_t addr;

	if (bbt[eb + 1]) {
		if (offs >= mtd->erasesize)
			offs -= mtd->erasesize;
		if (offs + len > mtd->erasesize)
			len = mtd->erasesize - offs;
	}
	addr = (loff_t)eb * mtd->erasesize + offs;
	return mtdtest_read(mtd, addr, len, readbuf);
}

__attribute__((used)) static int do_write(void)
{
	int eb = rand_eb(), offs, err, len;
	loff_t addr;

	offs = offsets[eb];
	if (offs >= mtd->erasesize) {
		err = mtdtest_erase_eraseblock(mtd, eb);
		if (err)
			return err;
		offs = offsets[eb] = 0;
	}
	len = rand_len(offs);
	len = ((len + pgsize - 1) / pgsize) * pgsize;
	if (offs + len > mtd->erasesize) {
		if (bbt[eb + 1])
			len = mtd->erasesize - offs;
		else {
			err = mtdtest_erase_eraseblock(mtd, eb + 1);
			if (err)
				return err;
			offsets[eb + 1] = 0;
		}
	}
	addr = (loff_t)eb * mtd->erasesize + offs;
	err = mtdtest_write(mtd, addr, len, writebuf);
	if (unlikely(err))
		return err;
	offs += len;
	while (offs > mtd->erasesize) {
		offsets[eb++] = mtd->erasesize;
		offs -= mtd->erasesize;
	}
	offsets[eb] = offs;
	return 0;
}

__attribute__((used)) static int do_operation(void)
{
	if (prandom_u32() & 1)
		return do_read();
	else
		return do_write();
}

