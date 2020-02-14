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
typedef  int u64 ;
struct seq_file {int dummy; } ;
struct inode {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int,int,scalar_t__) ; 
 int /*<<< orphan*/  seq_puts (struct seq_file*,char*) ; 
 int single_open (struct file*,int (*) (struct seq_file*,void*),int /*<<< orphan*/ *) ; 
 scalar_t__* sleep_time_bin ; 

__attribute__((used)) static inline u64 clocksource_delta(u64 now, u64 last, u64 mask)
{
	return (now - last) & mask;
}

__attribute__((used)) static int tk_debug_show_sleep_time(struct seq_file *s, void *data)
{
	unsigned int bin;
	seq_puts(s, "      time (secs)        count\n");
	seq_puts(s, "------------------------------\n");
	for (bin = 0; bin < 32; bin++) {
		if (sleep_time_bin[bin] == 0)
			continue;
		seq_printf(s, "%10u - %-10u %4u\n",
			bin ? 1 << (bin - 1) : 0, 1 << bin,
				sleep_time_bin[bin]);
	}
	return 0;
}

__attribute__((used)) static int tk_debug_sleep_time_open(struct inode *inode, struct file *file)
{
	return single_open(file, tk_debug_show_sleep_time, NULL);
}

