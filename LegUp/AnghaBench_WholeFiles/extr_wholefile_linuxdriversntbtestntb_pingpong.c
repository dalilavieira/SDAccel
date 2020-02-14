#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  int u32 ;
struct TYPE_4__ {int (* function ) (struct hrtimer*) ;} ;
struct pp_ctx {int nmask; int pmask; int out_pidx; int out_db; int in_db; int /*<<< orphan*/  dbgfs_dir; struct ntb_dev* ntb; int /*<<< orphan*/  count; TYPE_1__ timer; int /*<<< orphan*/  lock; } ;
struct pci_dev {int dummy; } ;
struct ntb_dev {struct pp_ctx* ctx; int /*<<< orphan*/  dev; struct pci_dev* pdev; } ;
struct ntb_client {int dummy; } ;
struct hrtimer {int dummy; } ;
typedef  enum hrtimer_restart { ____Placeholder_hrtimer_restart } hrtimer_restart ;

/* Variables and functions */
 void* BIT_ULL (int) ; 
 int /*<<< orphan*/  CLOCK_MONOTONIC ; 
 int EINVAL ; 
 int ENODEV ; 
 int /*<<< orphan*/  ENOMEM ; 
 struct pp_ctx* ERR_PTR (int /*<<< orphan*/ ) ; 
 int GENMASK_ULL (int,int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HRTIMER_MODE_REL ; 
 int HRTIMER_NORESTART ; 
 scalar_t__ IS_ERR (struct pp_ctx*) ; 
 int /*<<< orphan*/  NTB_SPEED_AUTO ; 
 int /*<<< orphan*/  NTB_WIDTH_AUTO ; 
 int PTR_ERR (struct pp_ctx*) ; 
 int __ffs64 (int) ; 
 int /*<<< orphan*/  atomic_inc (int /*<<< orphan*/ *) ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 void* debugfs_create_atomic_t (char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  debugfs_create_dir (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  debugfs_remove_recursive (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  delay_ms ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 struct pp_ctx* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hrtimer_cancel (TYPE_1__*) ; 
 int /*<<< orphan*/  hrtimer_init (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hrtimer_start (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ms_to_ktime (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ntb_clear_ctx (struct ntb_dev*) ; 
 int /*<<< orphan*/  ntb_db_clear (struct ntb_dev*,int) ; 
 int /*<<< orphan*/  ntb_db_clear_mask (struct ntb_dev*,int) ; 
 scalar_t__ ntb_db_is_unsafe (struct ntb_dev*) ; 
 int ntb_db_set_mask (struct ntb_dev*,int) ; 
 int ntb_db_valid_mask (struct ntb_dev*) ; 
 int /*<<< orphan*/  ntb_link_disable (struct ntb_dev*) ; 
 int /*<<< orphan*/  ntb_link_enable (struct ntb_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ntb_link_event (struct ntb_dev*) ; 
 int ntb_link_is_up (struct ntb_dev*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ntb_msg_clear_sts (struct ntb_dev*,int) ; 
 int ntb_msg_count (struct ntb_dev*) ; 
 int ntb_msg_inbits (struct ntb_dev*) ; 
 int ntb_msg_outbits (struct ntb_dev*) ; 
 int ntb_msg_read (struct ntb_dev*,int*,int /*<<< orphan*/ ) ; 
 int ntb_msg_set_mask (struct ntb_dev*,int) ; 
 int /*<<< orphan*/  ntb_peer_db_set (struct ntb_dev*,int) ; 
 int /*<<< orphan*/  ntb_peer_msg_write (struct ntb_dev*,int,int /*<<< orphan*/ ,int) ; 
 int ntb_peer_port_count (struct ntb_dev*) ; 
 int ntb_peer_port_number (struct ntb_dev*,int) ; 
 int /*<<< orphan*/  ntb_peer_spad_write (struct ntb_dev*,int,int /*<<< orphan*/ ,int) ; 
 int ntb_port_number (struct ntb_dev*) ; 
 int ntb_set_ctx (struct ntb_dev*,struct pp_ctx*,int /*<<< orphan*/ *) ; 
 int ntb_spad_count (struct ntb_dev*) ; 
 scalar_t__ ntb_spad_is_unsafe (struct ntb_dev*) ; 
 int ntb_spad_read (struct ntb_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_name (struct pci_dev*) ; 
 int /*<<< orphan*/  pp_dbgfs_topdir ; 
 int /*<<< orphan*/  pp_ops ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 struct pp_ctx* to_pp_timer (struct hrtimer*) ; 
 int /*<<< orphan*/  unsafe ; 

__attribute__((used)) static int pp_find_next_peer(struct pp_ctx *pp)
{
	u64 link, out_db;
	int pidx;

	link = ntb_link_is_up(pp->ntb, NULL, NULL);

	/* Find next available peer */
	if (link & pp->nmask) {
		pidx = __ffs64(link & pp->nmask);
		out_db = BIT_ULL(pidx + 1);
	} else if (link & pp->pmask) {
		pidx = __ffs64(link & pp->pmask);
		out_db = BIT_ULL(pidx);
	} else {
		return -ENODEV;
	}

	spin_lock(&pp->lock);
	pp->out_pidx = pidx;
	pp->out_db = out_db;
	spin_unlock(&pp->lock);

	return 0;
}

__attribute__((used)) static void pp_setup(struct pp_ctx *pp)
{
	int ret;

	ntb_db_set_mask(pp->ntb, pp->in_db);

	hrtimer_cancel(&pp->timer);

	ret = pp_find_next_peer(pp);
	if (ret == -ENODEV) {
		dev_dbg(&pp->ntb->dev, "Got no peers, so cancel\n");
		return;
	}

	dev_dbg(&pp->ntb->dev, "Ping-pong started with port %d, db %#llx\n",
		ntb_peer_port_number(pp->ntb, pp->out_pidx), pp->out_db);

	hrtimer_start(&pp->timer, ms_to_ktime(delay_ms), HRTIMER_MODE_REL);
}

__attribute__((used)) static void pp_clear(struct pp_ctx *pp)
{
	hrtimer_cancel(&pp->timer);

	ntb_db_set_mask(pp->ntb, pp->in_db);

	dev_dbg(&pp->ntb->dev, "Ping-pong cancelled\n");
}

__attribute__((used)) static void pp_ping(struct pp_ctx *pp)
{
	u32 count;

	count = atomic_read(&pp->count);

	spin_lock(&pp->lock);
	ntb_peer_spad_write(pp->ntb, pp->out_pidx, 0, count);
	ntb_peer_msg_write(pp->ntb, pp->out_pidx, 0, count);

	dev_dbg(&pp->ntb->dev, "Ping port %d spad %#x, msg %#x\n",
		ntb_peer_port_number(pp->ntb, pp->out_pidx), count, count);

	ntb_peer_db_set(pp->ntb, pp->out_db);
	ntb_db_clear_mask(pp->ntb, pp->in_db);
	spin_unlock(&pp->lock);
}

__attribute__((used)) static void pp_pong(struct pp_ctx *pp)
{
	u32 msg_data = -1, spad_data = -1;
	int pidx = 0;

	/* Read pong data */
	spad_data = ntb_spad_read(pp->ntb, 0);
	msg_data = ntb_msg_read(pp->ntb, &pidx, 0);
	ntb_msg_clear_sts(pp->ntb, -1);

	/*
	 * Scratchpad and message data may differ, since message register can't
	 * be rewritten unless status is cleared. Additionally either of them
	 * might be unsupported
	 */
	dev_dbg(&pp->ntb->dev, "Pong spad %#x, msg %#x (port %d)\n",
		spad_data, msg_data, ntb_peer_port_number(pp->ntb, pidx));

	atomic_inc(&pp->count);

	ntb_db_set_mask(pp->ntb, pp->in_db);
	ntb_db_clear(pp->ntb, pp->in_db);

	hrtimer_start(&pp->timer, ms_to_ktime(delay_ms), HRTIMER_MODE_REL);
}

__attribute__((used)) static enum hrtimer_restart pp_timer_func(struct hrtimer *t)
{
	struct pp_ctx *pp = to_pp_timer(t);

	pp_ping(pp);

	return HRTIMER_NORESTART;
}

__attribute__((used)) static void pp_link_event(void *ctx)
{
	struct pp_ctx *pp = ctx;

	pp_setup(pp);
}

__attribute__((used)) static void pp_db_event(void *ctx, int vec)
{
	struct pp_ctx *pp = ctx;

	pp_pong(pp);
}

__attribute__((used)) static int pp_check_ntb(struct ntb_dev *ntb)
{
	u64 pmask;

	if (ntb_db_is_unsafe(ntb)) {
		dev_dbg(&ntb->dev, "Doorbell is unsafe\n");
		if (!unsafe)
			return -EINVAL;
	}

	if (ntb_spad_is_unsafe(ntb)) {
		dev_dbg(&ntb->dev, "Scratchpad is unsafe\n");
		if (!unsafe)
			return -EINVAL;
	}

	pmask = GENMASK_ULL(ntb_peer_port_count(ntb), 0);
	if ((ntb_db_valid_mask(ntb) & pmask) != pmask) {
		dev_err(&ntb->dev, "Unsupported DB configuration\n");
		return -EINVAL;
	}

	if (ntb_spad_count(ntb) < 1 && ntb_msg_count(ntb) < 1) {
		dev_err(&ntb->dev, "Scratchpads and messages unsupported\n");
		return -EINVAL;
	} else if (ntb_spad_count(ntb) < 1) {
		dev_dbg(&ntb->dev, "Scratchpads unsupported\n");
	} else if (ntb_msg_count(ntb) < 1) {
		dev_dbg(&ntb->dev, "Messages unsupported\n");
	}

	return 0;
}

__attribute__((used)) static struct pp_ctx *pp_create_data(struct ntb_dev *ntb)
{
	struct pp_ctx *pp;

	pp = devm_kzalloc(&ntb->dev, sizeof(*pp), GFP_KERNEL);
	if (!pp)
		return ERR_PTR(-ENOMEM);

	pp->ntb = ntb;
	atomic_set(&pp->count, 0);
	spin_lock_init(&pp->lock);
	hrtimer_init(&pp->timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	pp->timer.function = pp_timer_func;

	return pp;
}

__attribute__((used)) static void pp_init_flds(struct pp_ctx *pp)
{
	int pidx, lport, pcnt;

	/* Find global port index */
	lport = ntb_port_number(pp->ntb);
	pcnt = ntb_peer_port_count(pp->ntb);
	for (pidx = 0; pidx < pcnt; pidx++) {
		if (lport < ntb_peer_port_number(pp->ntb, pidx))
			break;
	}

	pp->in_db = BIT_ULL(pidx);
	pp->pmask = GENMASK_ULL(pidx, 0) >> 1;
	pp->nmask = GENMASK_ULL(pcnt - 1, pidx);

	dev_dbg(&pp->ntb->dev, "Inbound db %#llx, prev %#llx, next %#llx\n",
		pp->in_db, pp->pmask, pp->nmask);
}

__attribute__((used)) static int pp_mask_events(struct pp_ctx *pp)
{
	u64 db_mask, msg_mask;
	int ret;

	db_mask = ntb_db_valid_mask(pp->ntb);
	ret = ntb_db_set_mask(pp->ntb, db_mask);
	if (ret)
		return ret;

	/* Skip message events masking if unsupported */
	if (ntb_msg_count(pp->ntb) < 1)
		return 0;

	msg_mask = ntb_msg_outbits(pp->ntb) | ntb_msg_inbits(pp->ntb);
	return ntb_msg_set_mask(pp->ntb, msg_mask);
}

__attribute__((used)) static int pp_setup_ctx(struct pp_ctx *pp)
{
	int ret;

	ret = ntb_set_ctx(pp->ntb, pp, &pp_ops);
	if (ret)
		return ret;

	ntb_link_enable(pp->ntb, NTB_SPEED_AUTO, NTB_WIDTH_AUTO);
	/* Might be not necessary */
	ntb_link_event(pp->ntb);

	return 0;
}

__attribute__((used)) static void pp_clear_ctx(struct pp_ctx *pp)
{
	ntb_link_disable(pp->ntb);

	ntb_clear_ctx(pp->ntb);
}

__attribute__((used)) static void pp_setup_dbgfs(struct pp_ctx *pp)
{
	struct pci_dev *pdev = pp->ntb->pdev;
	void *ret;

	pp->dbgfs_dir = debugfs_create_dir(pci_name(pdev), pp_dbgfs_topdir);

	ret = debugfs_create_atomic_t("count", 0600, pp->dbgfs_dir, &pp->count);
	if (!ret)
		dev_warn(&pp->ntb->dev, "DebugFS unsupported\n");
}

__attribute__((used)) static void pp_clear_dbgfs(struct pp_ctx *pp)
{
	debugfs_remove_recursive(pp->dbgfs_dir);
}

__attribute__((used)) static int pp_probe(struct ntb_client *client, struct ntb_dev *ntb)
{
	struct pp_ctx *pp;
	int ret;

	ret = pp_check_ntb(ntb);
	if (ret)
		return ret;

	pp = pp_create_data(ntb);
	if (IS_ERR(pp))
		return PTR_ERR(pp);

	pp_init_flds(pp);

	ret = pp_mask_events(pp);
	if (ret)
		return ret;

	ret = pp_setup_ctx(pp);
	if (ret)
		return ret;

	pp_setup_dbgfs(pp);

	return 0;
}

__attribute__((used)) static void pp_remove(struct ntb_client *client, struct ntb_dev *ntb)
{
	struct pp_ctx *pp = ntb->ctx;

	pp_clear_dbgfs(pp);

	pp_clear_ctx(pp);

	pp_clear(pp);
}

