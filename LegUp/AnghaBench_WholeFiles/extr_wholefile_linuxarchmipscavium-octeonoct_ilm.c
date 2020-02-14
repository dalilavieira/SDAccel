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
struct TYPE_2__ {int one_shot; int len; } ;
union cvmx_ciu_timx {void* u64; TYPE_1__ s; } ;
typedef  int u64 ;
struct seq_file {int dummy; } ;
struct latency_info {int max_latency; int min_latency; int latency_sum; int interrupt_cnt; int io_interval; int cpu_interval; int timer_start1; void* timer_start2; } ;
struct inode {int dummy; } ;
struct file {int dummy; } ;
struct dentry {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  CVMX_CIU_TIMX (int) ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int TIMER_NUM ; 
 void* cvmx_read_csr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cvmx_write_csr (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  debugfs_create_dir (char*,int /*<<< orphan*/ ) ; 
 struct dentry* debugfs_create_file (char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dir ; 
 struct latency_info li ; 
 int /*<<< orphan*/  oct_ilm_ops ; 
 int octeon_get_clock_rate () ; 
 int octeon_get_io_clock_rate () ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  raw_local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  raw_local_irq_save (unsigned long) ; 
 void* read_c0_cvmcount () ; 
 int /*<<< orphan*/  reset_statistics_ops ; 
 int reset_stats ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int,int,int,int) ; 
 int single_open (struct file*,int (*) (struct seq_file*,void*),int /*<<< orphan*/ *) ; 

__attribute__((used)) static int show_latency(struct seq_file *m, void *v)
{
	u64 cpuclk, avg, max, min;
	struct latency_info curr_li = li;

	cpuclk = octeon_get_clock_rate();

	max = (curr_li.max_latency * 1000000000) / cpuclk;
	min = (curr_li.min_latency * 1000000000) / cpuclk;
	avg = (curr_li.latency_sum * 1000000000) / (cpuclk * curr_li.interrupt_cnt);

	seq_printf(m, "cnt: %10lld, avg: %7lld ns, max: %7lld ns, min: %7lld ns\n",
		   curr_li.interrupt_cnt, avg, max, min);
	return 0;
}

__attribute__((used)) static int oct_ilm_open(struct inode *inode, struct file *file)
{
	return single_open(file, show_latency, NULL);
}

__attribute__((used)) static int reset_statistics(void *data, u64 value)
{
	reset_stats = true;
	return 0;
}

__attribute__((used)) static int init_debufs(void)
{
	struct dentry *show_dentry;
	dir = debugfs_create_dir("oct_ilm", 0);
	if (!dir) {
		pr_err("oct_ilm: failed to create debugfs entry oct_ilm\n");
		return -1;
	}

	show_dentry = debugfs_create_file("statistics", 0222, dir, NULL,
					  &oct_ilm_ops);
	if (!show_dentry) {
		pr_err("oct_ilm: failed to create debugfs entry oct_ilm/statistics\n");
		return -1;
	}

	show_dentry = debugfs_create_file("reset", 0222, dir, NULL,
					  &reset_statistics_ops);
	if (!show_dentry) {
		pr_err("oct_ilm: failed to create debugfs entry oct_ilm/reset\n");
		return -1;
	}

	return 0;

}

__attribute__((used)) static void init_latency_info(struct latency_info *li, int startup)
{
	/* interval in milli seconds after which the interrupt will
	 * be triggered
	 */
	int interval = 1;

	if (startup) {
		/* Calculating by the amounts io clock and cpu clock would
		 *  increment in interval amount of ms
		 */
		li->io_interval = (octeon_get_io_clock_rate() * interval) / 1000;
		li->cpu_interval = (octeon_get_clock_rate() * interval) / 1000;
	}
	li->timer_start1 = 0;
	li->timer_start2 = 0;
	li->max_latency = 0;
	li->min_latency = (u64)-1;
	li->latency_sum = 0;
	li->interrupt_cnt = 0;
}

__attribute__((used)) static void start_timer(int timer, u64 interval)
{
	union cvmx_ciu_timx timx;
	unsigned long flags;

	timx.u64 = 0;
	timx.s.one_shot = 1;
	timx.s.len = interval;
	raw_local_irq_save(flags);
	li.timer_start1 = read_c0_cvmcount();
	cvmx_write_csr(CVMX_CIU_TIMX(timer), timx.u64);
	/* Read it back to force wait until register is written. */
	timx.u64 = cvmx_read_csr(CVMX_CIU_TIMX(timer));
	li.timer_start2 = read_c0_cvmcount();
	raw_local_irq_restore(flags);
}

__attribute__((used)) static irqreturn_t cvm_oct_ciu_timer_interrupt(int cpl, void *dev_id)
{
	u64 last_latency;
	u64 last_int_cnt;

	if (reset_stats) {
		init_latency_info(&li, 0);
		reset_stats = false;
	} else {
		last_int_cnt = read_c0_cvmcount();
		last_latency = last_int_cnt - (li.timer_start1 + li.cpu_interval);
		li.interrupt_cnt++;
		li.latency_sum += last_latency;
		if (last_latency > li.max_latency)
			li.max_latency = last_latency;
		if (last_latency < li.min_latency)
			li.min_latency = last_latency;
	}
	start_timer(TIMER_NUM, li.io_interval);
	return IRQ_HANDLED;
}

__attribute__((used)) static void disable_timer(int timer)
{
	union cvmx_ciu_timx timx;

	timx.s.one_shot = 0;
	timx.s.len = 0;
	cvmx_write_csr(CVMX_CIU_TIMX(timer), timx.u64);
	/* Read it back to force immediate write of timer register*/
	timx.u64 = cvmx_read_csr(CVMX_CIU_TIMX(timer));
}

