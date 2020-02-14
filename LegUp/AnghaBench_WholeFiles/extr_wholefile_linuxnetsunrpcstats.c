#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct svc_version {unsigned int vs_nproc; int /*<<< orphan*/ * vs_count; } ;
struct svc_stat {struct svc_program* program; scalar_t__ rpcbadclnt; scalar_t__ rpcbadauth; scalar_t__ rpcbadfmt; int /*<<< orphan*/  rpccnt; int /*<<< orphan*/  nettcpconn; int /*<<< orphan*/  nettcpcnt; int /*<<< orphan*/  netudpcnt; int /*<<< orphan*/  netcnt; } ;
struct svc_program {unsigned int pg_nvers; char* pg_name; struct svc_version** pg_vers; } ;
struct sunrpc_net {int /*<<< orphan*/ * proc_net_rpc; } ;
struct seq_file {struct rpc_stat* private; } ;
struct rpc_xprt {TYPE_4__* ops; } ;
struct rpc_version {unsigned int nrprocs; int /*<<< orphan*/ * counts; int /*<<< orphan*/  number; } ;
struct TYPE_6__ {TYPE_1__* rpc_proc; } ;
struct rpc_task {TYPE_2__ tk_msg; int /*<<< orphan*/  tk_start; scalar_t__ tk_timeouts; struct rpc_rqst* tk_rqstp; } ;
struct rpc_stat {struct rpc_program* program; int /*<<< orphan*/  rpcauthrefresh; int /*<<< orphan*/  rpcretrans; int /*<<< orphan*/  rpccnt; int /*<<< orphan*/  nettcpconn; int /*<<< orphan*/  nettcpcnt; int /*<<< orphan*/  netudpcnt; int /*<<< orphan*/  netcnt; } ;
struct rpc_rqst {void* rq_rtt; int /*<<< orphan*/  rq_task; void* rq_xtime; scalar_t__ rq_reply_bytes_recvd; scalar_t__ rq_xmit_bytes_sent; int /*<<< orphan*/  rq_ntrans; } ;
struct rpc_program {unsigned int nrvers; char* name; struct rpc_version** version; } ;
struct rpc_procinfo {int p_name; } ;
struct rpc_iostats {void* om_execute; void* om_rtt; void* om_queue; scalar_t__ om_bytes_recv; scalar_t__ om_bytes_sent; scalar_t__ om_timeouts; scalar_t__ om_ntrans; scalar_t__ om_ops; int /*<<< orphan*/  om_lock; } ;
struct rpc_clnt {int cl_maxproc; struct rpc_procinfo* cl_procinfo; struct rpc_clnt* cl_parent; struct rpc_iostats* cl_metrics; int /*<<< orphan*/  cl_xprt; TYPE_3__* cl_program; int /*<<< orphan*/  cl_vers; int /*<<< orphan*/  cl_prog; } ;
struct proc_dir_entry {int dummy; } ;
struct net {int /*<<< orphan*/ * proc_net; } ;
struct inode {int dummy; } ;
struct file_operations {int dummy; } ;
struct file {int dummy; } ;
typedef  void* ktime_t ;
struct TYPE_8__ {int /*<<< orphan*/  (* print_stats ) (struct rpc_xprt*,struct seq_file*) ;} ;
struct TYPE_7__ {int /*<<< orphan*/  name; } ;
struct TYPE_5__ {size_t p_statidx; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  PDE_DATA (struct inode*) ; 
 int /*<<< orphan*/  RPC_IOSTATS_VERS ; 
 int /*<<< orphan*/  dprintk (char*,...) ; 
 struct rpc_iostats* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct rpc_iostats*) ; 
 void* ktime_add (void*,void*) ; 
 void* ktime_get () ; 
 void* ktime_sub (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ktime_to_ms (void*) ; 
 scalar_t__ ktime_to_ns (void*) ; 
 scalar_t__ max (int /*<<< orphan*/ ,int) ; 
 struct sunrpc_net* net_generic (struct net*,int /*<<< orphan*/ ) ; 
 struct proc_dir_entry* proc_create_data (char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct file_operations const*,void*) ; 
 int /*<<< orphan*/ * proc_mkdir (char*,int /*<<< orphan*/ *) ; 
 struct rpc_xprt* rcu_dereference (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 int /*<<< orphan*/  remove_proc_entry (char const*,int /*<<< orphan*/ *) ; 
 struct file_operations rpc_proc_fops ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,...) ; 
 int /*<<< orphan*/  seq_putc (struct seq_file*,char) ; 
 int single_open (struct file*,int (*) (struct seq_file*,void*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct rpc_xprt*,struct seq_file*) ; 
 int /*<<< orphan*/  sunrpc_net_id ; 
 int /*<<< orphan*/  trace_rpc_stats_latency (int /*<<< orphan*/ ,void*,void*,void*) ; 

__attribute__((used)) static int rpc_proc_show(struct seq_file *seq, void *v) {
	const struct rpc_stat	*statp = seq->private;
	const struct rpc_program *prog = statp->program;
	unsigned int i, j;

	seq_printf(seq,
		"net %u %u %u %u\n",
			statp->netcnt,
			statp->netudpcnt,
			statp->nettcpcnt,
			statp->nettcpconn);
	seq_printf(seq,
		"rpc %u %u %u\n",
			statp->rpccnt,
			statp->rpcretrans,
			statp->rpcauthrefresh);

	for (i = 0; i < prog->nrvers; i++) {
		const struct rpc_version *vers = prog->version[i];
		if (!vers)
			continue;
		seq_printf(seq, "proc%u %u",
					vers->number, vers->nrprocs);
		for (j = 0; j < vers->nrprocs; j++)
			seq_printf(seq, " %u", vers->counts[j]);
		seq_putc(seq, '\n');
	}
	return 0;
}

__attribute__((used)) static int rpc_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, rpc_proc_show, PDE_DATA(inode));
}

void svc_seq_show(struct seq_file *seq, const struct svc_stat *statp)
{
	const struct svc_program *prog = statp->program;
	const struct svc_version *vers;
	unsigned int i, j;

	seq_printf(seq,
		"net %u %u %u %u\n",
			statp->netcnt,
			statp->netudpcnt,
			statp->nettcpcnt,
			statp->nettcpconn);
	seq_printf(seq,
		"rpc %u %u %u %u %u\n",
			statp->rpccnt,
			statp->rpcbadfmt+statp->rpcbadauth+statp->rpcbadclnt,
			statp->rpcbadfmt,
			statp->rpcbadauth,
			statp->rpcbadclnt);

	for (i = 0; i < prog->pg_nvers; i++) {
		vers = prog->pg_vers[i];
		if (!vers)
			continue;
		seq_printf(seq, "proc%d %u", i, vers->vs_nproc);
		for (j = 0; j < vers->vs_nproc; j++)
			seq_printf(seq, " %u", vers->vs_count[j]);
		seq_putc(seq, '\n');
	}
}

struct rpc_iostats *rpc_alloc_iostats(struct rpc_clnt *clnt)
{
	struct rpc_iostats *stats;
	int i;

	stats = kcalloc(clnt->cl_maxproc, sizeof(*stats), GFP_KERNEL);
	if (stats) {
		for (i = 0; i < clnt->cl_maxproc; i++)
			spin_lock_init(&stats[i].om_lock);
	}
	return stats;
}

void rpc_free_iostats(struct rpc_iostats *stats)
{
	kfree(stats);
}

void rpc_count_iostats_metrics(const struct rpc_task *task,
			       struct rpc_iostats *op_metrics)
{
	struct rpc_rqst *req = task->tk_rqstp;
	ktime_t backlog, execute, now;

	if (!op_metrics || !req)
		return;

	now = ktime_get();
	spin_lock(&op_metrics->om_lock);

	op_metrics->om_ops++;
	/* kernel API: om_ops must never become larger than om_ntrans */
	op_metrics->om_ntrans += max(req->rq_ntrans, 1);
	op_metrics->om_timeouts += task->tk_timeouts;

	op_metrics->om_bytes_sent += req->rq_xmit_bytes_sent;
	op_metrics->om_bytes_recv += req->rq_reply_bytes_recvd;

	backlog = 0;
	if (ktime_to_ns(req->rq_xtime)) {
		backlog = ktime_sub(req->rq_xtime, task->tk_start);
		op_metrics->om_queue = ktime_add(op_metrics->om_queue, backlog);
	}

	op_metrics->om_rtt = ktime_add(op_metrics->om_rtt, req->rq_rtt);

	execute = ktime_sub(now, task->tk_start);
	op_metrics->om_execute = ktime_add(op_metrics->om_execute, execute);

	spin_unlock(&op_metrics->om_lock);

	trace_rpc_stats_latency(req->rq_task, backlog, req->rq_rtt, execute);
}

void rpc_count_iostats(const struct rpc_task *task, struct rpc_iostats *stats)
{
	rpc_count_iostats_metrics(task,
				  &stats[task->tk_msg.rpc_proc->p_statidx]);
}

__attribute__((used)) static void _print_name(struct seq_file *seq, unsigned int op,
			const struct rpc_procinfo *procs)
{
	if (procs[op].p_name)
		seq_printf(seq, "\t%12s: ", procs[op].p_name);
	else if (op == 0)
		seq_printf(seq, "\t        NULL: ");
	else
		seq_printf(seq, "\t%12u: ", op);
}

__attribute__((used)) static void _add_rpc_iostats(struct rpc_iostats *a, struct rpc_iostats *b)
{
	a->om_ops += b->om_ops;
	a->om_ntrans += b->om_ntrans;
	a->om_timeouts += b->om_timeouts;
	a->om_bytes_sent += b->om_bytes_sent;
	a->om_bytes_recv += b->om_bytes_recv;
	a->om_queue = ktime_add(a->om_queue, b->om_queue);
	a->om_rtt = ktime_add(a->om_rtt, b->om_rtt);
	a->om_execute = ktime_add(a->om_execute, b->om_execute);
}

__attribute__((used)) static void _print_rpc_iostats(struct seq_file *seq, struct rpc_iostats *stats,
			       int op, const struct rpc_procinfo *procs)
{
	_print_name(seq, op, procs);
	seq_printf(seq, "%lu %lu %lu %Lu %Lu %Lu %Lu %Lu\n",
		   stats->om_ops,
		   stats->om_ntrans,
		   stats->om_timeouts,
		   stats->om_bytes_sent,
		   stats->om_bytes_recv,
		   ktime_to_ms(stats->om_queue),
		   ktime_to_ms(stats->om_rtt),
		   ktime_to_ms(stats->om_execute));
}

void rpc_clnt_show_stats(struct seq_file *seq, struct rpc_clnt *clnt)
{
	struct rpc_xprt *xprt;
	unsigned int op, maxproc = clnt->cl_maxproc;

	if (!clnt->cl_metrics)
		return;

	seq_printf(seq, "\tRPC iostats version: %s  ", RPC_IOSTATS_VERS);
	seq_printf(seq, "p/v: %u/%u (%s)\n",
			clnt->cl_prog, clnt->cl_vers, clnt->cl_program->name);

	rcu_read_lock();
	xprt = rcu_dereference(clnt->cl_xprt);
	if (xprt)
		xprt->ops->print_stats(xprt, seq);
	rcu_read_unlock();

	seq_printf(seq, "\tper-op statistics\n");
	for (op = 0; op < maxproc; op++) {
		struct rpc_iostats stats = {};
		struct rpc_clnt *next = clnt;
		do {
			_add_rpc_iostats(&stats, &next->cl_metrics[op]);
			if (next == next->cl_parent)
				break;
			next = next->cl_parent;
		} while (next);
		_print_rpc_iostats(seq, &stats, op, clnt->cl_procinfo);
	}
}

__attribute__((used)) static inline struct proc_dir_entry *
do_register(struct net *net, const char *name, void *data,
	    const struct file_operations *fops)
{
	struct sunrpc_net *sn;

	dprintk("RPC:       registering /proc/net/rpc/%s\n", name);
	sn = net_generic(net, sunrpc_net_id);
	return proc_create_data(name, 0, sn->proc_net_rpc, fops, data);
}

struct proc_dir_entry *
rpc_proc_register(struct net *net, struct rpc_stat *statp)
{
	return do_register(net, statp->program->name, statp, &rpc_proc_fops);
}

void
rpc_proc_unregister(struct net *net, const char *name)
{
	struct sunrpc_net *sn;

	sn = net_generic(net, sunrpc_net_id);
	remove_proc_entry(name, sn->proc_net_rpc);
}

struct proc_dir_entry *
svc_proc_register(struct net *net, struct svc_stat *statp, const struct file_operations *fops)
{
	return do_register(net, statp->program->pg_name, statp, fops);
}

void
svc_proc_unregister(struct net *net, const char *name)
{
	struct sunrpc_net *sn;

	sn = net_generic(net, sunrpc_net_id);
	remove_proc_entry(name, sn->proc_net_rpc);
}

int rpc_proc_init(struct net *net)
{
	struct sunrpc_net *sn;

	dprintk("RPC:       registering /proc/net/rpc\n");
	sn = net_generic(net, sunrpc_net_id);
	sn->proc_net_rpc = proc_mkdir("rpc", net->proc_net);
	if (sn->proc_net_rpc == NULL)
		return -ENOMEM;

	return 0;
}

void rpc_proc_exit(struct net *net)
{
	dprintk("RPC:       unregistering /proc/net/rpc\n");
	remove_proc_entry("rpc", net->proc_net);
}

