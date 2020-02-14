#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct seq_file {struct mvpp2_port* private; } ;
struct mvpp2_prs_entry {int* tcam; int /*<<< orphan*/  sram; } ;
struct mvpp2_port {int flow; size_t tid; TYPE_2__* dev; struct mvpp2* priv; struct mvpp2_port* dbg_fe; struct mvpp2_port* port; int /*<<< orphan*/  id; } ;
struct mvpp2_dbgfs_prs_entry {int flow; size_t tid; TYPE_2__* dev; struct mvpp2* priv; struct mvpp2_dbgfs_prs_entry* dbg_fe; struct mvpp2_dbgfs_prs_entry* port; int /*<<< orphan*/  id; } ;
struct mvpp2_dbgfs_port_flow_entry {int flow; size_t tid; TYPE_2__* dev; struct mvpp2* priv; struct mvpp2_dbgfs_port_flow_entry* dbg_fe; struct mvpp2_dbgfs_port_flow_entry* port; int /*<<< orphan*/  id; } ;
struct mvpp2_dbgfs_flow_entry {int flow; size_t tid; TYPE_2__* dev; struct mvpp2* priv; struct mvpp2_dbgfs_flow_entry* dbg_fe; struct mvpp2_dbgfs_flow_entry* port; int /*<<< orphan*/  id; } ;
struct mvpp2_cls_flow_entry {int dummy; } ;
struct mvpp2_cls_flow {int flow_type; int flow_id; } ;
struct mvpp2_cls_c2_entry {int* attr; } ;
struct mvpp2 {int port_count; struct mvpp2_port** port_list; struct dentry* dbgfs_dir; TYPE_1__* prs_shadow; } ;
struct inode {int /*<<< orphan*/  i_private; } ;
struct file {struct seq_file* private_data; } ;
struct dentry {int dummy; } ;
struct TYPE_4__ {char const* name; } ;
struct TYPE_3__ {scalar_t__ lu; scalar_t__ udf; scalar_t__ valid; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ETH_ALEN ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  IPV4_FLOW 133 
#define  IPV6_FLOW 132 
 scalar_t__ IS_ERR (struct dentry*) ; 
 int MVPP22_CLS_C2_ATTR0_QHIGH_MASK ; 
 int MVPP22_CLS_C2_ATTR0_QHIGH_OFFS ; 
 int MVPP22_CLS_C2_ATTR0_QLOW_MASK ; 
 int MVPP22_CLS_C2_ATTR0_QLOW_OFFS ; 
 int MVPP22_CLS_C2_ATTR2_RSS_EN ; 
 int /*<<< orphan*/  MVPP22_CLS_C2_RSS_ENTRY (int /*<<< orphan*/ ) ; 
 char const* MVPP2_DRIVER_NAME ; 
 int MVPP2_FLOW_C2_ENTRY (int) ; 
 int MVPP2_N_FLOWS ; 
 int MVPP2_PE_MAC_RANGE_END ; 
 int MVPP2_PE_MAC_RANGE_START ; 
 int MVPP2_PORT_FLOW_HASH_ENTRY (int /*<<< orphan*/ ,int) ; 
 int MVPP2_PRS_AI_MASK ; 
 scalar_t__ MVPP2_PRS_LU_MAC ; 
 unsigned int MVPP2_PRS_PORT_MASK ; 
 size_t MVPP2_PRS_TCAM_AI_WORD ; 
 int MVPP2_PRS_TCAM_SRAM_SIZE ; 
 scalar_t__ MVPP2_PRS_UDF_MAC_DEF ; 
 int MVPP2_PRS_VID_PORT_FIRST (int /*<<< orphan*/ ) ; 
 int MVPP2_PRS_VID_PORT_LAST (int /*<<< orphan*/ ) ; 
 int PTR_ERR (struct dentry*) ; 
#define  TCP_V4_FLOW 131 
#define  TCP_V6_FLOW 130 
#define  UDP_V4_FLOW 129 
#define  UDP_V6_FLOW 128 
 struct dentry* debugfs_create_dir (char const*,struct dentry*) ; 
 int /*<<< orphan*/  debugfs_create_file (char*,int,struct dentry*,struct mvpp2_port*,int /*<<< orphan*/ *) ; 
 struct dentry* debugfs_lookup (char const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  debugfs_remove_recursive (struct dentry*) ; 
 int /*<<< orphan*/  kfree (struct mvpp2_port*) ; 
 struct mvpp2_port* kmalloc (int,int /*<<< orphan*/ ) ; 
 int mvpp2_cls_c2_hit_count (struct mvpp2*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mvpp2_cls_c2_read (struct mvpp2*,int /*<<< orphan*/ ,struct mvpp2_cls_c2_entry*) ; 
 int mvpp2_cls_flow_eng_get (struct mvpp2_cls_flow_entry*) ; 
 struct mvpp2_cls_flow* mvpp2_cls_flow_get (int) ; 
 int mvpp2_cls_flow_hits (struct mvpp2*,int) ; 
 int /*<<< orphan*/  mvpp2_cls_flow_read (struct mvpp2*,int,struct mvpp2_cls_flow_entry*) ; 
 int mvpp2_cls_lookup_hits (struct mvpp2*,int) ; 
 int /*<<< orphan*/  mvpp2_dbgfs_filter_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_flow_c2_enable_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_flow_c2_hits_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_flow_c2_rxq_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_flow_dec_hits_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_flow_flt_hits_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_flow_id_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_flow_type_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_port_flow_engine_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_port_flow_hash_opt_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_port_parser_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_port_vid_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_prs_ai_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_prs_hdata_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_prs_hits_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_prs_lu_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_prs_sram_fops ; 
 int /*<<< orphan*/  mvpp2_dbgfs_prs_valid_fops ; 
 int mvpp2_flow_get_hek_fields (struct mvpp2_cls_flow_entry*) ; 
 int mvpp2_prs_hits (struct mvpp2*,int) ; 
 int /*<<< orphan*/  mvpp2_prs_init_from_hw (struct mvpp2*,struct mvpp2_prs_entry*,int) ; 
 int /*<<< orphan*/  mvpp2_prs_tcam_data_byte_get (struct mvpp2_prs_entry*,int,unsigned char*,unsigned char*) ; 
 void* mvpp2_prs_tcam_port_map_get (struct mvpp2_prs_entry*) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,...) ; 
 int single_open (struct file*,int (*) (struct seq_file*,void*),int /*<<< orphan*/ ) ; 
 int single_release (struct inode*,struct file*) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,unsigned long*) ; 

__attribute__((used)) static int mvpp2_dbgfs_flow_flt_hits_show(struct seq_file *s, void *unused)
{
	struct mvpp2_dbgfs_flow_entry *entry = s->private;
	int id = MVPP2_FLOW_C2_ENTRY(entry->flow);

	u32 hits = mvpp2_cls_flow_hits(entry->priv, id);

	seq_printf(s, "%u\n", hits);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_flow_dec_hits_show(struct seq_file *s, void *unused)
{
	struct mvpp2_dbgfs_flow_entry *entry = s->private;

	u32 hits = mvpp2_cls_lookup_hits(entry->priv, entry->flow);

	seq_printf(s, "%u\n", hits);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_flow_type_show(struct seq_file *s, void *unused)
{
	struct mvpp2_dbgfs_flow_entry *entry = s->private;
	struct mvpp2_cls_flow *f;
	const char *flow_name;

	f = mvpp2_cls_flow_get(entry->flow);
	if (!f)
		return -EINVAL;

	switch (f->flow_type) {
	case IPV4_FLOW:
		flow_name = "ipv4";
		break;
	case IPV6_FLOW:
		flow_name = "ipv6";
		break;
	case TCP_V4_FLOW:
		flow_name = "tcp4";
		break;
	case TCP_V6_FLOW:
		flow_name = "tcp6";
		break;
	case UDP_V4_FLOW:
		flow_name = "udp4";
		break;
	case UDP_V6_FLOW:
		flow_name = "udp6";
		break;
	default:
		flow_name = "other";
	}

	seq_printf(s, "%s\n", flow_name);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_flow_type_open(struct inode *inode, struct file *file)
{
	return single_open(file, mvpp2_dbgfs_flow_type_show, inode->i_private);
}

__attribute__((used)) static int mvpp2_dbgfs_flow_type_release(struct inode *inode, struct file *file)
{
	struct seq_file *seq = file->private_data;
	struct mvpp2_dbgfs_flow_entry *flow_entry = seq->private;

	kfree(flow_entry);
	return single_release(inode, file);
}

__attribute__((used)) static int mvpp2_dbgfs_flow_id_show(struct seq_file *s, void *unused)
{
	struct mvpp2_dbgfs_flow_entry *entry = s->private;
	struct mvpp2_cls_flow *f;

	f = mvpp2_cls_flow_get(entry->flow);
	if (!f)
		return -EINVAL;

	seq_printf(s, "%d\n", f->flow_id);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_port_flow_hash_opt_show(struct seq_file *s, void *unused)
{
	struct mvpp2_dbgfs_port_flow_entry *entry = s->private;
	struct mvpp2_port *port = entry->port;
	struct mvpp2_cls_flow_entry fe;
	struct mvpp2_cls_flow *f;
	int flow_index;
	u16 hash_opts;

	f = mvpp2_cls_flow_get(entry->dbg_fe->flow);
	if (!f)
		return -EINVAL;

	flow_index = MVPP2_PORT_FLOW_HASH_ENTRY(entry->port->id, f->flow_id);

	mvpp2_cls_flow_read(port->priv, flow_index, &fe);

	hash_opts = mvpp2_flow_get_hek_fields(&fe);

	seq_printf(s, "0x%04x\n", hash_opts);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_port_flow_hash_opt_open(struct inode *inode,
					       struct file *file)
{
	return single_open(file, mvpp2_dbgfs_port_flow_hash_opt_show,
			   inode->i_private);
}

__attribute__((used)) static int mvpp2_dbgfs_port_flow_hash_opt_release(struct inode *inode,
						  struct file *file)
{
	struct seq_file *seq = file->private_data;
	struct mvpp2_dbgfs_port_flow_entry *flow_entry = seq->private;

	kfree(flow_entry);
	return single_release(inode, file);
}

__attribute__((used)) static int mvpp2_dbgfs_port_flow_engine_show(struct seq_file *s, void *unused)
{
	struct mvpp2_dbgfs_port_flow_entry *entry = s->private;
	struct mvpp2_port *port = entry->port;
	struct mvpp2_cls_flow_entry fe;
	struct mvpp2_cls_flow *f;
	int flow_index, engine;

	f = mvpp2_cls_flow_get(entry->dbg_fe->flow);
	if (!f)
		return -EINVAL;

	flow_index = MVPP2_PORT_FLOW_HASH_ENTRY(entry->port->id, f->flow_id);

	mvpp2_cls_flow_read(port->priv, flow_index, &fe);

	engine = mvpp2_cls_flow_eng_get(&fe);

	seq_printf(s, "%d\n", engine);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_flow_c2_hits_show(struct seq_file *s, void *unused)
{
	struct mvpp2_port *port = s->private;
	u32 hits;

	hits = mvpp2_cls_c2_hit_count(port->priv,
				      MVPP22_CLS_C2_RSS_ENTRY(port->id));

	seq_printf(s, "%u\n", hits);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_flow_c2_rxq_show(struct seq_file *s, void *unused)
{
	struct mvpp2_port *port = s->private;
	struct mvpp2_cls_c2_entry c2;
	u8 qh, ql;

	mvpp2_cls_c2_read(port->priv, MVPP22_CLS_C2_RSS_ENTRY(port->id), &c2);

	qh = (c2.attr[0] >> MVPP22_CLS_C2_ATTR0_QHIGH_OFFS) &
	     MVPP22_CLS_C2_ATTR0_QHIGH_MASK;

	ql = (c2.attr[0] >> MVPP22_CLS_C2_ATTR0_QLOW_OFFS) &
	     MVPP22_CLS_C2_ATTR0_QLOW_MASK;

	seq_printf(s, "%d\n", (qh << 3 | ql));

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_flow_c2_enable_show(struct seq_file *s, void *unused)
{
	struct mvpp2_port *port = s->private;
	struct mvpp2_cls_c2_entry c2;
	int enabled;

	mvpp2_cls_c2_read(port->priv, MVPP22_CLS_C2_RSS_ENTRY(port->id), &c2);

	enabled = !!(c2.attr[2] & MVPP22_CLS_C2_ATTR2_RSS_EN);

	seq_printf(s, "%d\n", enabled);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_port_vid_show(struct seq_file *s, void *unused)
{
	struct mvpp2_port *port = s->private;
	unsigned char byte[2], enable[2];
	struct mvpp2 *priv = port->priv;
	struct mvpp2_prs_entry pe;
	unsigned long pmap;
	u16 rvid;
	int tid;

	for (tid = MVPP2_PRS_VID_PORT_FIRST(port->id);
	     tid <= MVPP2_PRS_VID_PORT_LAST(port->id); tid++) {
		mvpp2_prs_init_from_hw(priv, &pe, tid);

		pmap = mvpp2_prs_tcam_port_map_get(&pe);

		if (!priv->prs_shadow[tid].valid)
			continue;

		if (!test_bit(port->id, &pmap))
			continue;

		mvpp2_prs_tcam_data_byte_get(&pe, 2, &byte[0], &enable[0]);
		mvpp2_prs_tcam_data_byte_get(&pe, 3, &byte[1], &enable[1]);

		rvid = ((byte[0] & 0xf) << 8) + byte[1];

		seq_printf(s, "%u\n", rvid);
	}

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_port_parser_show(struct seq_file *s, void *unused)
{
	struct mvpp2_port *port = s->private;
	struct mvpp2 *priv = port->priv;
	struct mvpp2_prs_entry pe;
	unsigned long pmap;
	int i;

	for (i = 0; i < MVPP2_PRS_TCAM_SRAM_SIZE; i++) {
		mvpp2_prs_init_from_hw(port->priv, &pe, i);

		pmap = mvpp2_prs_tcam_port_map_get(&pe);
		if (priv->prs_shadow[i].valid && test_bit(port->id, &pmap))
			seq_printf(s, "%03d\n", i);
	}

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_filter_show(struct seq_file *s, void *unused)
{
	struct mvpp2_port *port = s->private;
	struct mvpp2 *priv = port->priv;
	struct mvpp2_prs_entry pe;
	unsigned long pmap;
	int index, tid;

	for (tid = MVPP2_PE_MAC_RANGE_START;
	     tid <= MVPP2_PE_MAC_RANGE_END; tid++) {
		unsigned char da[ETH_ALEN], da_mask[ETH_ALEN];

		if (!priv->prs_shadow[tid].valid ||
		    priv->prs_shadow[tid].lu != MVPP2_PRS_LU_MAC ||
		    priv->prs_shadow[tid].udf != MVPP2_PRS_UDF_MAC_DEF)
			continue;

		mvpp2_prs_init_from_hw(priv, &pe, tid);

		pmap = mvpp2_prs_tcam_port_map_get(&pe);

		/* We only want entries active on this port */
		if (!test_bit(port->id, &pmap))
			continue;

		/* Read mac addr from entry */
		for (index = 0; index < ETH_ALEN; index++)
			mvpp2_prs_tcam_data_byte_get(&pe, index, &da[index],
						     &da_mask[index]);

		seq_printf(s, "%pM\n", da);
	}

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_prs_lu_show(struct seq_file *s, void *unused)
{
	struct mvpp2_dbgfs_prs_entry *entry = s->private;
	struct mvpp2 *priv = entry->priv;

	seq_printf(s, "%x\n", priv->prs_shadow[entry->tid].lu);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_prs_pmap_show(struct seq_file *s, void *unused)
{
	struct mvpp2_dbgfs_prs_entry *entry = s->private;
	struct mvpp2_prs_entry pe;
	unsigned int pmap;

	mvpp2_prs_init_from_hw(entry->priv, &pe, entry->tid);

	pmap = mvpp2_prs_tcam_port_map_get(&pe);
	pmap &= MVPP2_PRS_PORT_MASK;

	seq_printf(s, "%02x\n", pmap);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_prs_ai_show(struct seq_file *s, void *unused)
{
	struct mvpp2_dbgfs_prs_entry *entry = s->private;
	struct mvpp2_prs_entry pe;
	unsigned char ai, ai_mask;

	mvpp2_prs_init_from_hw(entry->priv, &pe, entry->tid);

	ai = pe.tcam[MVPP2_PRS_TCAM_AI_WORD] & MVPP2_PRS_AI_MASK;
	ai_mask = (pe.tcam[MVPP2_PRS_TCAM_AI_WORD] >> 16) & MVPP2_PRS_AI_MASK;

	seq_printf(s, "%02x %02x\n", ai, ai_mask);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_prs_hdata_show(struct seq_file *s, void *unused)
{
	struct mvpp2_dbgfs_prs_entry *entry = s->private;
	struct mvpp2_prs_entry pe;
	unsigned char data[8], mask[8];
	int i;

	mvpp2_prs_init_from_hw(entry->priv, &pe, entry->tid);

	for (i = 0; i < 8; i++)
		mvpp2_prs_tcam_data_byte_get(&pe, i, &data[i], &mask[i]);

	seq_printf(s, "%*phN %*phN\n", 8, data, 8, mask);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_prs_sram_show(struct seq_file *s, void *unused)
{
	struct mvpp2_dbgfs_prs_entry *entry = s->private;
	struct mvpp2_prs_entry pe;

	mvpp2_prs_init_from_hw(entry->priv, &pe, entry->tid);

	seq_printf(s, "%*phN\n", 14, pe.sram);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_prs_hits_show(struct seq_file *s, void *unused)
{
	struct mvpp2_dbgfs_prs_entry *entry = s->private;
	int val;

	val = mvpp2_prs_hits(entry->priv, entry->tid);
	if (val < 0)
		return val;

	seq_printf(s, "%d\n", val);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_prs_valid_show(struct seq_file *s, void *unused)
{
	struct mvpp2_dbgfs_prs_entry *entry = s->private;
	struct mvpp2 *priv = entry->priv;
	int tid = entry->tid;

	seq_printf(s, "%d\n", priv->prs_shadow[tid].valid ? 1 : 0);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_prs_valid_open(struct inode *inode, struct file *file)
{
	return single_open(file, mvpp2_dbgfs_prs_valid_show, inode->i_private);
}

__attribute__((used)) static int mvpp2_dbgfs_prs_valid_release(struct inode *inode, struct file *file)
{
	struct seq_file *seq = file->private_data;
	struct mvpp2_dbgfs_prs_entry *entry = seq->private;

	kfree(entry);
	return single_release(inode, file);
}

__attribute__((used)) static int mvpp2_dbgfs_flow_port_init(struct dentry *parent,
				      struct mvpp2_port *port,
				      struct mvpp2_dbgfs_flow_entry *entry)
{
	struct mvpp2_dbgfs_port_flow_entry *port_entry;
	struct dentry *port_dir;

	port_dir = debugfs_create_dir(port->dev->name, parent);
	if (IS_ERR(port_dir))
		return PTR_ERR(port_dir);

	/* This will be freed by 'hash_opts' release op */
	port_entry = kmalloc(sizeof(*port_entry), GFP_KERNEL);
	if (!port_entry)
		return -ENOMEM;

	port_entry->port = port;
	port_entry->dbg_fe = entry;

	debugfs_create_file("hash_opts", 0444, port_dir, port_entry,
			    &mvpp2_dbgfs_port_flow_hash_opt_fops);

	debugfs_create_file("engine", 0444, port_dir, port_entry,
			    &mvpp2_dbgfs_port_flow_engine_fops);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_flow_entry_init(struct dentry *parent,
				       struct mvpp2 *priv, int flow)
{
	struct mvpp2_dbgfs_flow_entry *entry;
	struct dentry *flow_entry_dir;
	char flow_entry_name[10];
	int i, ret;

	sprintf(flow_entry_name, "%02d", flow);

	flow_entry_dir = debugfs_create_dir(flow_entry_name, parent);
	if (!flow_entry_dir)
		return -ENOMEM;

	/* This will be freed by 'type' release op */
	entry = kmalloc(sizeof(*entry), GFP_KERNEL);
	if (!entry)
		return -ENOMEM;

	entry->flow = flow;
	entry->priv = priv;

	debugfs_create_file("flow_hits", 0444, flow_entry_dir, entry,
			    &mvpp2_dbgfs_flow_flt_hits_fops);

	debugfs_create_file("dec_hits", 0444, flow_entry_dir, entry,
			    &mvpp2_dbgfs_flow_dec_hits_fops);

	debugfs_create_file("type", 0444, flow_entry_dir, entry,
			    &mvpp2_dbgfs_flow_type_fops);

	debugfs_create_file("id", 0444, flow_entry_dir, entry,
			    &mvpp2_dbgfs_flow_id_fops);

	/* Create entry for each port */
	for (i = 0; i < priv->port_count; i++) {
		ret = mvpp2_dbgfs_flow_port_init(flow_entry_dir,
						 priv->port_list[i], entry);
		if (ret)
			return ret;
	}
	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_flow_init(struct dentry *parent, struct mvpp2 *priv)
{
	struct dentry *flow_dir;
	int i, ret;

	flow_dir = debugfs_create_dir("flows", parent);
	if (!flow_dir)
		return -ENOMEM;

	for (i = 0; i < MVPP2_N_FLOWS; i++) {
		ret = mvpp2_dbgfs_flow_entry_init(flow_dir, priv, i);
		if (ret)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_prs_entry_init(struct dentry *parent,
				      struct mvpp2 *priv, int tid)
{
	struct mvpp2_dbgfs_prs_entry *entry;
	struct dentry *prs_entry_dir;
	char prs_entry_name[10];

	if (tid >= MVPP2_PRS_TCAM_SRAM_SIZE)
		return -EINVAL;

	sprintf(prs_entry_name, "%03d", tid);

	prs_entry_dir = debugfs_create_dir(prs_entry_name, parent);
	if (!prs_entry_dir)
		return -ENOMEM;

	/* The 'valid' entry's ops will free that */
	entry = kmalloc(sizeof(*entry), GFP_KERNEL);
	if (!entry)
		return -ENOMEM;

	entry->tid = tid;
	entry->priv = priv;

	/* Create each attr */
	debugfs_create_file("sram", 0444, prs_entry_dir, entry,
			    &mvpp2_dbgfs_prs_sram_fops);

	debugfs_create_file("valid", 0644, prs_entry_dir, entry,
			    &mvpp2_dbgfs_prs_valid_fops);

	debugfs_create_file("lookup_id", 0644, prs_entry_dir, entry,
			    &mvpp2_dbgfs_prs_lu_fops);

	debugfs_create_file("ai", 0644, prs_entry_dir, entry,
			    &mvpp2_dbgfs_prs_ai_fops);

	debugfs_create_file("header_data", 0644, prs_entry_dir, entry,
			    &mvpp2_dbgfs_prs_hdata_fops);

	debugfs_create_file("hits", 0444, prs_entry_dir, entry,
			    &mvpp2_dbgfs_prs_hits_fops);

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_prs_init(struct dentry *parent, struct mvpp2 *priv)
{
	struct dentry *prs_dir;
	int i, ret;

	prs_dir = debugfs_create_dir("parser", parent);
	if (!prs_dir)
		return -ENOMEM;

	for (i = 0; i < MVPP2_PRS_TCAM_SRAM_SIZE; i++) {
		ret = mvpp2_dbgfs_prs_entry_init(prs_dir, priv, i);
		if (ret)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int mvpp2_dbgfs_port_init(struct dentry *parent,
				 struct mvpp2_port *port)
{
	struct dentry *port_dir;

	port_dir = debugfs_create_dir(port->dev->name, parent);
	if (IS_ERR(port_dir))
		return PTR_ERR(port_dir);

	debugfs_create_file("parser_entries", 0444, port_dir, port,
			    &mvpp2_dbgfs_port_parser_fops);

	debugfs_create_file("mac_filter", 0444, port_dir, port,
			    &mvpp2_dbgfs_filter_fops);

	debugfs_create_file("vid_filter", 0444, port_dir, port,
			    &mvpp2_dbgfs_port_vid_fops);

	debugfs_create_file("c2_hits", 0444, port_dir, port,
			    &mvpp2_dbgfs_flow_c2_hits_fops);

	debugfs_create_file("default_rxq", 0444, port_dir, port,
			    &mvpp2_dbgfs_flow_c2_rxq_fops);

	debugfs_create_file("rss_enable", 0444, port_dir, port,
			    &mvpp2_dbgfs_flow_c2_enable_fops);

	return 0;
}

void mvpp2_dbgfs_cleanup(struct mvpp2 *priv)
{
	debugfs_remove_recursive(priv->dbgfs_dir);
}

void mvpp2_dbgfs_init(struct mvpp2 *priv, const char *name)
{
	struct dentry *mvpp2_dir, *mvpp2_root;
	int ret, i;

	mvpp2_root = debugfs_lookup(MVPP2_DRIVER_NAME, NULL);
	if (!mvpp2_root) {
		mvpp2_root = debugfs_create_dir(MVPP2_DRIVER_NAME, NULL);
		if (IS_ERR(mvpp2_root))
			return;
	}

	mvpp2_dir = debugfs_create_dir(name, mvpp2_root);
	if (IS_ERR(mvpp2_dir))
		return;

	priv->dbgfs_dir = mvpp2_dir;

	ret = mvpp2_dbgfs_prs_init(mvpp2_dir, priv);
	if (ret)
		goto err;

	for (i = 0; i < priv->port_count; i++) {
		ret = mvpp2_dbgfs_port_init(mvpp2_dir, priv->port_list[i]);
		if (ret)
			goto err;
	}

	ret = mvpp2_dbgfs_flow_init(mvpp2_dir, priv);
	if (ret)
		goto err;

	return;
err:
	mvpp2_dbgfs_cleanup(priv);
}

