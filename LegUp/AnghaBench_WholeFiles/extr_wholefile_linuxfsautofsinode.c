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
typedef  int umode_t ;
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  substring_t ;
struct super_block {scalar_t__ s_magic; int s_blocksize; int s_blocksize_bits; int s_time_gran; struct dentry* s_root; struct autofs_sb_info* s_fs_info; int /*<<< orphan*/ * s_d_op; int /*<<< orphan*/ * s_op; int /*<<< orphan*/  s_dev; } ;
struct seq_file {int dummy; } ;
struct inode {int i_mode; int /*<<< orphan*/ * i_op; int /*<<< orphan*/ * i_fop; int /*<<< orphan*/  i_ino; int /*<<< orphan*/  i_ctime; int /*<<< orphan*/  i_mtime; int /*<<< orphan*/  i_atime; int /*<<< orphan*/  i_gid; int /*<<< orphan*/  i_uid; struct autofs_sb_info* i_private; } ;
struct file {int f_mode; int /*<<< orphan*/  f_flags; } ;
struct dentry {int d_flags; struct autofs_sb_info* d_fsdata; struct super_block* d_sb; int /*<<< orphan*/  d_lock; } ;
struct autofs_sb_info {int catatonic; scalar_t__ oz_pgrp; int pipefd; int exp_timeout; int min_proto; int max_proto; unsigned int type; struct file* pipe; scalar_t__ sub_version; void* version; int /*<<< orphan*/  expiring_list; int /*<<< orphan*/  active_list; int /*<<< orphan*/  lookup_lock; int /*<<< orphan*/ * queues; int /*<<< orphan*/  fs_lock; int /*<<< orphan*/  pipe_mutex; int /*<<< orphan*/  wq_mutex; struct super_block* sb; int /*<<< orphan*/  magic; void* last_used; int /*<<< orphan*/  gid; int /*<<< orphan*/  uid; struct autofs_sb_info* sbi; int /*<<< orphan*/  expiring; int /*<<< orphan*/  active; } ;
struct autofs_info {int catatonic; scalar_t__ oz_pgrp; int pipefd; int exp_timeout; int min_proto; int max_proto; unsigned int type; struct file* pipe; scalar_t__ sub_version; void* version; int /*<<< orphan*/  expiring_list; int /*<<< orphan*/  active_list; int /*<<< orphan*/  lookup_lock; int /*<<< orphan*/ * queues; int /*<<< orphan*/  fs_lock; int /*<<< orphan*/  pipe_mutex; int /*<<< orphan*/  wq_mutex; struct super_block* sb; int /*<<< orphan*/  magic; void* last_used; int /*<<< orphan*/  gid; int /*<<< orphan*/  uid; struct autofs_info* sbi; int /*<<< orphan*/  expiring; int /*<<< orphan*/  active; } ;
typedef  int /*<<< orphan*/  kuid_t ;
typedef  int /*<<< orphan*/  kgid_t ;
struct TYPE_2__ {int /*<<< orphan*/  i_mode; } ;

/* Variables and functions */
 void* AUTOFS_MAX_PROTO_VERSION ; 
 int AUTOFS_MIN_PROTO_VERSION ; 
 scalar_t__ AUTOFS_PROTO_SUBVERSION ; 
 int /*<<< orphan*/  AUTOFS_SBI_MAGIC ; 
 scalar_t__ AUTOFS_SUPER_MAGIC ; 
 int DCACHE_MANAGE_TRANSIT ; 
 int DCACHE_NEED_AUTOMOUNT ; 
 int EINVAL ; 
 int ENOMEM ; 
 int FMODE_CAN_WRITE ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GLOBAL_ROOT_GID ; 
 int /*<<< orphan*/  GLOBAL_ROOT_UID ; 
 int HZ ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int MAX_OPT_ARGS ; 
 int /*<<< orphan*/  O_DIRECT ; 
#define  Opt_direct 136 
#define  Opt_fd 135 
#define  Opt_gid 134 
#define  Opt_indirect 133 
#define  Opt_maxproto 132 
#define  Opt_minproto 131 
#define  Opt_offset 130 
#define  Opt_pgrp 129 
#define  Opt_uid 128 
 int /*<<< orphan*/  PIDTYPE_PGID ; 
 int S_IFDIR ; 
 scalar_t__ S_ISDIR (int) ; 
 int /*<<< orphan*/  S_ISFIFO (int /*<<< orphan*/ ) ; 
 scalar_t__ S_ISLNK (int) ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  autofs_catatonic_mode (struct autofs_sb_info*) ; 
 int /*<<< orphan*/  autofs_dentry_operations ; 
 int /*<<< orphan*/  autofs_dir_inode_operations ; 
 int /*<<< orphan*/  autofs_dir_operations ; 
 struct inode* autofs_get_inode (struct super_block*,int) ; 
 int /*<<< orphan*/  autofs_root_operations ; 
 int /*<<< orphan*/  autofs_sops ; 
 int /*<<< orphan*/  autofs_symlink_inode_operations ; 
 scalar_t__ autofs_type_direct (unsigned int) ; 
 scalar_t__ autofs_type_offset (unsigned int) ; 
 scalar_t__ autofs_type_trigger (unsigned int) ; 
 int /*<<< orphan*/  clear_inode (struct inode*) ; 
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  current_gid () ; 
 int /*<<< orphan*/  current_time (struct inode*) ; 
 int /*<<< orphan*/  current_uid () ; 
 int /*<<< orphan*/  current_user_ns () ; 
 struct inode* d_inode (struct dentry*) ; 
 struct dentry* d_make_root (struct inode*) ; 
 int /*<<< orphan*/  dput (struct dentry*) ; 
 struct file* fget (int) ; 
 TYPE_1__* file_inode (struct file*) ; 
 int /*<<< orphan*/ * find_get_pid (int) ; 
 int /*<<< orphan*/  fput (struct file*) ; 
 int /*<<< orphan*/  from_kgid_munged (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  from_kuid_munged (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_next_ino () ; 
 int /*<<< orphan*/ * get_task_pid (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gid_eq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gid_valid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_user_ns ; 
 void* jiffies ; 
 int /*<<< orphan*/  kfree (struct autofs_sb_info*) ; 
 int /*<<< orphan*/  kfree_rcu (struct autofs_sb_info*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kill_litter_super (struct super_block*) ; 
 struct autofs_sb_info* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_add (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_del_init (int /*<<< orphan*/ *) ; 
 scalar_t__ list_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  make_kgid (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  make_kuid (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  match_int (int /*<<< orphan*/ *,int*) ; 
 int match_token (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  new_encode_dev (int /*<<< orphan*/ ) ; 
 struct inode* new_inode (struct super_block*) ; 
 int /*<<< orphan*/  pid_nr (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pid_vnr (scalar_t__) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  put_pid (scalar_t__) ; 
 int /*<<< orphan*/  rcu ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,...) ; 
 int /*<<< orphan*/  set_autofs_type_direct (unsigned int*) ; 
 int /*<<< orphan*/  set_autofs_type_indirect (unsigned int*) ; 
 int /*<<< orphan*/  set_autofs_type_offset (unsigned int*) ; 
 int /*<<< orphan*/  set_nlink (struct inode*,int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 char* strsep (char**,char*) ; 
 scalar_t__ task_pgrp (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tokens ; 
 int /*<<< orphan*/  uid_eq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uid_valid (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct autofs_sb_info *autofs_sbi(struct super_block *sb)
{
	return sb->s_magic != AUTOFS_SUPER_MAGIC ?
		NULL : (struct autofs_sb_info *)(sb->s_fs_info);
}

__attribute__((used)) static inline struct autofs_info *autofs_dentry_ino(struct dentry *dentry)
{
	return (struct autofs_info *)(dentry->d_fsdata);
}

__attribute__((used)) static inline int autofs_oz_mode(struct autofs_sb_info *sbi)
{
	return sbi->catatonic || task_pgrp(current) == sbi->oz_pgrp;
}

__attribute__((used)) static inline void __managed_dentry_set_managed(struct dentry *dentry)
{
	dentry->d_flags |= (DCACHE_NEED_AUTOMOUNT|DCACHE_MANAGE_TRANSIT);
}

__attribute__((used)) static inline void managed_dentry_set_managed(struct dentry *dentry)
{
	spin_lock(&dentry->d_lock);
	__managed_dentry_set_managed(dentry);
	spin_unlock(&dentry->d_lock);
}

__attribute__((used)) static inline void __managed_dentry_clear_managed(struct dentry *dentry)
{
	dentry->d_flags &= ~(DCACHE_NEED_AUTOMOUNT|DCACHE_MANAGE_TRANSIT);
}

__attribute__((used)) static inline void managed_dentry_clear_managed(struct dentry *dentry)
{
	spin_lock(&dentry->d_lock);
	__managed_dentry_clear_managed(dentry);
	spin_unlock(&dentry->d_lock);
}

__attribute__((used)) static inline int autofs_prepare_pipe(struct file *pipe)
{
	if (!(pipe->f_mode & FMODE_CAN_WRITE))
		return -EINVAL;
	if (!S_ISFIFO(file_inode(pipe)->i_mode))
		return -EINVAL;
	/* We want a packet pipe */
	pipe->f_flags |= O_DIRECT;
	return 0;
}

__attribute__((used)) static inline u32 autofs_get_dev(struct autofs_sb_info *sbi)
{
	return new_encode_dev(sbi->sb->s_dev);
}

__attribute__((used)) static inline u64 autofs_get_ino(struct autofs_sb_info *sbi)
{
	return d_inode(sbi->sb->s_root)->i_ino;
}

__attribute__((used)) static inline void __autofs_add_expiring(struct dentry *dentry)
{
	struct autofs_sb_info *sbi = autofs_sbi(dentry->d_sb);
	struct autofs_info *ino = autofs_dentry_ino(dentry);

	if (ino) {
		if (list_empty(&ino->expiring))
			list_add(&ino->expiring, &sbi->expiring_list);
	}
}

__attribute__((used)) static inline void autofs_add_expiring(struct dentry *dentry)
{
	struct autofs_sb_info *sbi = autofs_sbi(dentry->d_sb);
	struct autofs_info *ino = autofs_dentry_ino(dentry);

	if (ino) {
		spin_lock(&sbi->lookup_lock);
		if (list_empty(&ino->expiring))
			list_add(&ino->expiring, &sbi->expiring_list);
		spin_unlock(&sbi->lookup_lock);
	}
}

__attribute__((used)) static inline void autofs_del_expiring(struct dentry *dentry)
{
	struct autofs_sb_info *sbi = autofs_sbi(dentry->d_sb);
	struct autofs_info *ino = autofs_dentry_ino(dentry);

	if (ino) {
		spin_lock(&sbi->lookup_lock);
		if (!list_empty(&ino->expiring))
			list_del_init(&ino->expiring);
		spin_unlock(&sbi->lookup_lock);
	}
}

struct autofs_info *autofs_new_ino(struct autofs_sb_info *sbi)
{
	struct autofs_info *ino;

	ino = kzalloc(sizeof(*ino), GFP_KERNEL);
	if (ino) {
		INIT_LIST_HEAD(&ino->active);
		INIT_LIST_HEAD(&ino->expiring);
		ino->last_used = jiffies;
		ino->sbi = sbi;
	}
	return ino;
}

void autofs_clean_ino(struct autofs_info *ino)
{
	ino->uid = GLOBAL_ROOT_UID;
	ino->gid = GLOBAL_ROOT_GID;
	ino->last_used = jiffies;
}

void autofs_free_ino(struct autofs_info *ino)
{
	kfree(ino);
}

void autofs_kill_sb(struct super_block *sb)
{
	struct autofs_sb_info *sbi = autofs_sbi(sb);

	/*
	 * In the event of a failure in get_sb_nodev the superblock
	 * info is not present so nothing else has been setup, so
	 * just call kill_anon_super when we are called from
	 * deactivate_super.
	 */
	if (sbi) {
		/* Free wait queues, close pipe */
		autofs_catatonic_mode(sbi);
		put_pid(sbi->oz_pgrp);
	}

	pr_debug("shutting down\n");
	kill_litter_super(sb);
	if (sbi)
		kfree_rcu(sbi, rcu);
}

__attribute__((used)) static int autofs_show_options(struct seq_file *m, struct dentry *root)
{
	struct autofs_sb_info *sbi = autofs_sbi(root->d_sb);
	struct inode *root_inode = d_inode(root->d_sb->s_root);

	if (!sbi)
		return 0;

	seq_printf(m, ",fd=%d", sbi->pipefd);
	if (!uid_eq(root_inode->i_uid, GLOBAL_ROOT_UID))
		seq_printf(m, ",uid=%u",
			from_kuid_munged(&init_user_ns, root_inode->i_uid));
	if (!gid_eq(root_inode->i_gid, GLOBAL_ROOT_GID))
		seq_printf(m, ",gid=%u",
			from_kgid_munged(&init_user_ns, root_inode->i_gid));
	seq_printf(m, ",pgrp=%d", pid_vnr(sbi->oz_pgrp));
	seq_printf(m, ",timeout=%lu", sbi->exp_timeout/HZ);
	seq_printf(m, ",minproto=%d", sbi->min_proto);
	seq_printf(m, ",maxproto=%d", sbi->max_proto);

	if (autofs_type_offset(sbi->type))
		seq_printf(m, ",offset");
	else if (autofs_type_direct(sbi->type))
		seq_printf(m, ",direct");
	else
		seq_printf(m, ",indirect");
#ifdef CONFIG_CHECKPOINT_RESTORE
	if (sbi->pipe)
		seq_printf(m, ",pipe_ino=%ld", file_inode(sbi->pipe)->i_ino);
	else
		seq_printf(m, ",pipe_ino=-1");
#endif
	return 0;
}

__attribute__((used)) static void autofs_evict_inode(struct inode *inode)
{
	clear_inode(inode);
	kfree(inode->i_private);
}

__attribute__((used)) static int parse_options(char *options, int *pipefd, kuid_t *uid, kgid_t *gid,
			 int *pgrp, bool *pgrp_set, unsigned int *type,
			 int *minproto, int *maxproto)
{
	char *p;
	substring_t args[MAX_OPT_ARGS];
	int option;

	*uid = current_uid();
	*gid = current_gid();

	*minproto = AUTOFS_MIN_PROTO_VERSION;
	*maxproto = AUTOFS_MAX_PROTO_VERSION;

	*pipefd = -1;

	if (!options)
		return 1;

	while ((p = strsep(&options, ",")) != NULL) {
		int token;

		if (!*p)
			continue;

		token = match_token(p, tokens, args);
		switch (token) {
		case Opt_fd:
			if (match_int(args, pipefd))
				return 1;
			break;
		case Opt_uid:
			if (match_int(args, &option))
				return 1;
			*uid = make_kuid(current_user_ns(), option);
			if (!uid_valid(*uid))
				return 1;
			break;
		case Opt_gid:
			if (match_int(args, &option))
				return 1;
			*gid = make_kgid(current_user_ns(), option);
			if (!gid_valid(*gid))
				return 1;
			break;
		case Opt_pgrp:
			if (match_int(args, &option))
				return 1;
			*pgrp = option;
			*pgrp_set = true;
			break;
		case Opt_minproto:
			if (match_int(args, &option))
				return 1;
			*minproto = option;
			break;
		case Opt_maxproto:
			if (match_int(args, &option))
				return 1;
			*maxproto = option;
			break;
		case Opt_indirect:
			set_autofs_type_indirect(type);
			break;
		case Opt_direct:
			set_autofs_type_direct(type);
			break;
		case Opt_offset:
			set_autofs_type_offset(type);
			break;
		default:
			return 1;
		}
	}
	return (*pipefd < 0);
}

int autofs_fill_super(struct super_block *s, void *data, int silent)
{
	struct inode *root_inode;
	struct dentry *root;
	struct file *pipe;
	int pipefd;
	struct autofs_sb_info *sbi;
	struct autofs_info *ino;
	int pgrp = 0;
	bool pgrp_set = false;
	int ret = -EINVAL;

	sbi = kzalloc(sizeof(*sbi), GFP_KERNEL);
	if (!sbi)
		return -ENOMEM;
	pr_debug("starting up, sbi = %p\n", sbi);

	s->s_fs_info = sbi;
	sbi->magic = AUTOFS_SBI_MAGIC;
	sbi->pipefd = -1;
	sbi->pipe = NULL;
	sbi->catatonic = 1;
	sbi->exp_timeout = 0;
	sbi->oz_pgrp = NULL;
	sbi->sb = s;
	sbi->version = 0;
	sbi->sub_version = 0;
	set_autofs_type_indirect(&sbi->type);
	sbi->min_proto = 0;
	sbi->max_proto = 0;
	mutex_init(&sbi->wq_mutex);
	mutex_init(&sbi->pipe_mutex);
	spin_lock_init(&sbi->fs_lock);
	sbi->queues = NULL;
	spin_lock_init(&sbi->lookup_lock);
	INIT_LIST_HEAD(&sbi->active_list);
	INIT_LIST_HEAD(&sbi->expiring_list);
	s->s_blocksize = 1024;
	s->s_blocksize_bits = 10;
	s->s_magic = AUTOFS_SUPER_MAGIC;
	s->s_op = &autofs_sops;
	s->s_d_op = &autofs_dentry_operations;
	s->s_time_gran = 1;

	/*
	 * Get the root inode and dentry, but defer checking for errors.
	 */
	ino = autofs_new_ino(sbi);
	if (!ino) {
		ret = -ENOMEM;
		goto fail_free;
	}
	root_inode = autofs_get_inode(s, S_IFDIR | 0755);
	root = d_make_root(root_inode);
	if (!root) {
		ret = -ENOMEM;
		goto fail_ino;
	}
	pipe = NULL;

	root->d_fsdata = ino;

	/* Can this call block? */
	if (parse_options(data, &pipefd, &root_inode->i_uid, &root_inode->i_gid,
			  &pgrp, &pgrp_set, &sbi->type, &sbi->min_proto,
			  &sbi->max_proto)) {
		pr_err("called with bogus options\n");
		goto fail_dput;
	}

	/* Test versions first */
	if (sbi->max_proto < AUTOFS_MIN_PROTO_VERSION ||
	    sbi->min_proto > AUTOFS_MAX_PROTO_VERSION) {
		pr_err("kernel does not match daemon version "
		       "daemon (%d, %d) kernel (%d, %d)\n",
		       sbi->min_proto, sbi->max_proto,
		       AUTOFS_MIN_PROTO_VERSION, AUTOFS_MAX_PROTO_VERSION);
		goto fail_dput;
	}

	/* Establish highest kernel protocol version */
	if (sbi->max_proto > AUTOFS_MAX_PROTO_VERSION)
		sbi->version = AUTOFS_MAX_PROTO_VERSION;
	else
		sbi->version = sbi->max_proto;
	sbi->sub_version = AUTOFS_PROTO_SUBVERSION;

	if (pgrp_set) {
		sbi->oz_pgrp = find_get_pid(pgrp);
		if (!sbi->oz_pgrp) {
			pr_err("could not find process group %d\n",
				pgrp);
			goto fail_dput;
		}
	} else {
		sbi->oz_pgrp = get_task_pid(current, PIDTYPE_PGID);
	}

	if (autofs_type_trigger(sbi->type))
		__managed_dentry_set_managed(root);

	root_inode->i_fop = &autofs_root_operations;
	root_inode->i_op = &autofs_dir_inode_operations;

	pr_debug("pipe fd = %d, pgrp = %u\n", pipefd, pid_nr(sbi->oz_pgrp));
	pipe = fget(pipefd);

	if (!pipe) {
		pr_err("could not open pipe file descriptor\n");
		goto fail_put_pid;
	}
	ret = autofs_prepare_pipe(pipe);
	if (ret < 0)
		goto fail_fput;
	sbi->pipe = pipe;
	sbi->pipefd = pipefd;
	sbi->catatonic = 0;

	/*
	 * Success! Install the root dentry now to indicate completion.
	 */
	s->s_root = root;
	return 0;

	/*
	 * Failure ... clean up.
	 */
fail_fput:
	pr_err("pipe file descriptor does not contain proper ops\n");
	fput(pipe);
fail_put_pid:
	put_pid(sbi->oz_pgrp);
fail_dput:
	dput(root);
	goto fail_free;
fail_ino:
	autofs_free_ino(ino);
fail_free:
	kfree(sbi);
	s->s_fs_info = NULL;
	return ret;
}

struct inode *autofs_get_inode(struct super_block *sb, umode_t mode)
{
	struct inode *inode = new_inode(sb);

	if (inode == NULL)
		return NULL;

	inode->i_mode = mode;
	if (sb->s_root) {
		inode->i_uid = d_inode(sb->s_root)->i_uid;
		inode->i_gid = d_inode(sb->s_root)->i_gid;
	}
	inode->i_atime = inode->i_mtime = inode->i_ctime = current_time(inode);
	inode->i_ino = get_next_ino();

	if (S_ISDIR(mode)) {
		set_nlink(inode, 2);
		inode->i_op = &autofs_dir_inode_operations;
		inode->i_fop = &autofs_dir_operations;
	} else if (S_ISLNK(mode)) {
		inode->i_op = &autofs_symlink_inode_operations;
	} else
		WARN_ON(1);

	return inode;
}

