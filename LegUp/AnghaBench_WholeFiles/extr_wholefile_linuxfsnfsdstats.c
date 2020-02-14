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
typedef  int /*<<< orphan*/  time_t ;
struct svc_rqst {scalar_t__ rq_prog; int rq_vers; } ;
struct svc_export {int /*<<< orphan*/  h; int /*<<< orphan*/  cd; } ;
struct seq_file {int dummy; } ;
struct net {int dummy; } ;
struct inode {int dummy; } ;
struct file {int dummy; } ;
struct dentry {int dummy; } ;
struct TYPE_2__ {unsigned int* th_usage; int /*<<< orphan*/ * ra_depth; int /*<<< orphan*/  ra_size; int /*<<< orphan*/  th_fullcnt; int /*<<< orphan*/  th_cnt; int /*<<< orphan*/  io_write; int /*<<< orphan*/  io_read; int /*<<< orphan*/  fh_nocache_nondir; int /*<<< orphan*/  fh_nocache_dir; int /*<<< orphan*/  fh_anon; int /*<<< orphan*/  fh_lookup; int /*<<< orphan*/  fh_stale; int /*<<< orphan*/  rcnocache; int /*<<< orphan*/  rcmisses; int /*<<< orphan*/  rchits; } ;

/* Variables and functions */
 unsigned int HZ ; 
 scalar_t__ NFS_PROGRAM ; 
 int /*<<< orphan*/  cache_get (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cache_put (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_net ; 
 int /*<<< orphan*/  nfsd_proc_fops ; 
 int /*<<< orphan*/  nfsd_svcstats ; 
 TYPE_1__ nfsdstats ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,unsigned int,...) ; 
 int /*<<< orphan*/  seq_putc (struct seq_file*,char) ; 
 int single_open (struct file*,int (*) (struct seq_file*,void*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svc_proc_register (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svc_proc_unregister (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  svc_seq_show (struct seq_file*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void exp_put(struct svc_export *exp)
{
	cache_put(&exp->h, exp->cd);
}

__attribute__((used)) static inline struct svc_export *exp_get(struct svc_export *exp)
{
	cache_get(&exp->h);
	return exp;
}

__attribute__((used)) static inline int nfsd_v4client(struct svc_rqst *rq)
{
	return rq->rq_prog == NFS_PROGRAM && rq->rq_vers == 4;
}

__attribute__((used)) static inline int nfsd4_init_slabs(void) { return 0; }

__attribute__((used)) static inline void nfsd4_free_slabs(void) { }

__attribute__((used)) static inline int nfs4_state_start(void) { return 0; }

__attribute__((used)) static inline int nfs4_state_start_net(struct net *net) { return 0; }

__attribute__((used)) static inline void nfs4_state_shutdown(void) { }

__attribute__((used)) static inline void nfs4_state_shutdown_net(struct net *net) { }

__attribute__((used)) static inline void nfs4_reset_lease(time_t leasetime) { }

__attribute__((used)) static inline int nfs4_reset_recoverydir(char *recdir) { return 0; }

__attribute__((used)) static inline char * nfs4_recoverydir(void) {return NULL; }

__attribute__((used)) static inline bool nfsd4_spo_must_allow(struct svc_rqst *rqstp)
{
	return false;
}

__attribute__((used)) static inline int nfsd4_is_junction(struct dentry *dentry)
{
	return 0;
}

__attribute__((used)) static int nfsd_proc_show(struct seq_file *seq, void *v)
{
	int i;

	seq_printf(seq, "rc %u %u %u\nfh %u %u %u %u %u\nio %u %u\n",
		      nfsdstats.rchits,
		      nfsdstats.rcmisses,
		      nfsdstats.rcnocache,
		      nfsdstats.fh_stale,
		      nfsdstats.fh_lookup,
		      nfsdstats.fh_anon,
		      nfsdstats.fh_nocache_dir,
		      nfsdstats.fh_nocache_nondir,
		      nfsdstats.io_read,
		      nfsdstats.io_write);
	/* thread usage: */
	seq_printf(seq, "th %u %u", nfsdstats.th_cnt, nfsdstats.th_fullcnt);
	for (i=0; i<10; i++) {
		unsigned int jifs = nfsdstats.th_usage[i];
		unsigned int sec = jifs / HZ, msec = (jifs % HZ)*1000/HZ;
		seq_printf(seq, " %u.%03u", sec, msec);
	}

	/* newline and ra-cache */
	seq_printf(seq, "\nra %u", nfsdstats.ra_size);
	for (i=0; i<11; i++)
		seq_printf(seq, " %u", nfsdstats.ra_depth[i]);
	seq_putc(seq, '\n');
	
	/* show my rpc info */
	svc_seq_show(seq, &nfsd_svcstats);

#ifdef CONFIG_NFSD_V4
	/* Show count for individual nfsv4 operations */
	/* Writing operation numbers 0 1 2 also for maintaining uniformity */
	seq_printf(seq,"proc4ops %u", LAST_NFS4_OP + 1);
	for (i = 0; i <= LAST_NFS4_OP; i++)
		seq_printf(seq, " %u", nfsdstats.nfs4_opcount[i]);

	seq_putc(seq, '\n');
#endif

	return 0;
}

__attribute__((used)) static int nfsd_proc_open(struct inode *inode, struct file *file)
{
	return single_open(file, nfsd_proc_show, NULL);
}

void
nfsd_stat_init(void)
{
	svc_proc_register(&init_net, &nfsd_svcstats, &nfsd_proc_fops);
}

void
nfsd_stat_shutdown(void)
{
	svc_proc_unregister(&init_net, "nfsd");
}

