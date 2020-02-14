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
struct seq_file {struct hcall_stats* private; } ;
struct inode {int dummy; } ;
struct hcall_stats {scalar_t__ purr_start; int /*<<< orphan*/  purr_total; scalar_t__ tb_start; int /*<<< orphan*/  tb_total; scalar_t__ num_calls; } ;
struct file {struct seq_file* private_data; } ;
typedef  scalar_t__ loff_t ;
struct TYPE_2__ {struct hcall_stats* i_private; } ;

/* Variables and functions */
 int /*<<< orphan*/  CPU_FTR_PURR ; 
 int HCALL_STAT_ARRAY_SIZE ; 
 unsigned long MAX_HCALL_OPCODE ; 
 int /*<<< orphan*/  SPRN_PURR ; 
 scalar_t__ cpu_has_feature (int /*<<< orphan*/ ) ; 
 TYPE_1__* file_inode (struct file*) ; 
 int /*<<< orphan*/  hcall_inst_seq_ops ; 
 int /*<<< orphan*/ * hcall_stats ; 
 scalar_t__ mfspr (int /*<<< orphan*/ ) ; 
 scalar_t__ mftb () ; 
 int seq_open (struct file*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,unsigned long,scalar_t__,int /*<<< orphan*/ ,...) ; 
 struct hcall_stats* this_cpu_ptr (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void *hc_start(struct seq_file *m, loff_t *pos)
{
	if ((int)*pos < (HCALL_STAT_ARRAY_SIZE-1))
		return (void *)(unsigned long)(*pos + 1);

	return NULL;
}

__attribute__((used)) static void *hc_next(struct seq_file *m, void *p, loff_t * pos)
{
	++*pos;

	return hc_start(m, pos);
}

__attribute__((used)) static void hc_stop(struct seq_file *m, void *p)
{
}

__attribute__((used)) static int hc_show(struct seq_file *m, void *p)
{
	unsigned long h_num = (unsigned long)p;
	struct hcall_stats *hs = m->private;

	if (hs[h_num].num_calls) {
		if (cpu_has_feature(CPU_FTR_PURR))
			seq_printf(m, "%lu %lu %lu %lu\n", h_num<<2,
				   hs[h_num].num_calls,
				   hs[h_num].tb_total,
				   hs[h_num].purr_total);
		else
			seq_printf(m, "%lu %lu %lu\n", h_num<<2,
				   hs[h_num].num_calls,
				   hs[h_num].tb_total);
	}

	return 0;
}

__attribute__((used)) static int hcall_inst_seq_open(struct inode *inode, struct file *file)
{
	int rc;
	struct seq_file *seq;

	rc = seq_open(file, &hcall_inst_seq_ops);
	seq = file->private_data;
	seq->private = file_inode(file)->i_private;

	return rc;
}

__attribute__((used)) static void probe_hcall_entry(void *ignored, unsigned long opcode, unsigned long *args)
{
	struct hcall_stats *h;

	if (opcode > MAX_HCALL_OPCODE)
		return;

	h = this_cpu_ptr(&hcall_stats[opcode / 4]);
	h->tb_start = mftb();
	h->purr_start = mfspr(SPRN_PURR);
}

__attribute__((used)) static void probe_hcall_exit(void *ignored, unsigned long opcode, long retval,
			     unsigned long *retbuf)
{
	struct hcall_stats *h;

	if (opcode > MAX_HCALL_OPCODE)
		return;

	h = this_cpu_ptr(&hcall_stats[opcode / 4]);
	h->num_calls++;
	h->tb_total += mftb() - h->tb_start;
	h->purr_total += mfspr(SPRN_PURR) - h->purr_start;
}

