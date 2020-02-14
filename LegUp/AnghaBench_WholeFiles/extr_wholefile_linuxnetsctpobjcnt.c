#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct seq_file {int dummy; } ;
struct proc_dir_entry {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  proc_net_sctp; } ;
struct net {TYPE_1__ sctp; } ;
typedef  scalar_t__ loff_t ;
struct TYPE_5__ {int /*<<< orphan*/  counter; int /*<<< orphan*/  label; } ;

/* Variables and functions */
 scalar_t__ ARRAY_SIZE (TYPE_2__*) ; 
 int /*<<< orphan*/  atomic_read (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 struct proc_dir_entry* proc_create_seq (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 TYPE_2__* sctp_dbg_objcnt ; 
 int /*<<< orphan*/  sctp_objcnt_seq_ops ; 
 int /*<<< orphan*/  seq_pad (struct seq_file*,char) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  seq_setwidth (struct seq_file*,int) ; 

__attribute__((used)) static int sctp_objcnt_seq_show(struct seq_file *seq, void *v)
{
	int i;

	i = (int)*(loff_t *)v;
	seq_setwidth(seq, 127);
	seq_printf(seq, "%s: %d", sctp_dbg_objcnt[i].label,
				atomic_read(sctp_dbg_objcnt[i].counter));
	seq_pad(seq, '\n');
	return 0;
}

__attribute__((used)) static void *sctp_objcnt_seq_start(struct seq_file *seq, loff_t *pos)
{
	return (*pos >= ARRAY_SIZE(sctp_dbg_objcnt)) ? NULL : (void *)pos;
}

__attribute__((used)) static void sctp_objcnt_seq_stop(struct seq_file *seq, void *v)
{
}

__attribute__((used)) static void *sctp_objcnt_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
	++*pos;
	return (*pos >= ARRAY_SIZE(sctp_dbg_objcnt)) ? NULL : (void *)pos;
}

void sctp_dbg_objcnt_init(struct net *net)
{
	struct proc_dir_entry *ent;

	ent = proc_create_seq("sctp_dbg_objcnt", 0,
			  net->sctp.proc_net_sctp, &sctp_objcnt_seq_ops);
	if (!ent)
		pr_warn("sctp_dbg_objcnt: Unable to create /proc entry.\n");
}

