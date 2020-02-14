#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int len; void* cmd; } ;
struct TYPE_11__ {int len; void* dmb; unsigned int dmb_len; unsigned long sba_idx; void* info; void* event_code; void* trigger_irq; void* rgid; TYPE_1__ hdr; void* vlan_id; int /*<<< orphan*/  dmb_tok; void* vlan_valid; void* ieq; void* sba; } ;
struct smcd_event {int ret; int len; int /*<<< orphan*/  dmb_tok; int /*<<< orphan*/  gid; } ;
union ism_unreg_dmb {TYPE_2__ request; struct smcd_event response; } ;
union ism_sig_ieq {TYPE_2__ request; struct smcd_event response; } ;
union ism_set_vlan_id {TYPE_2__ request; struct smcd_event response; } ;
union ism_reg_sba {TYPE_2__ request; struct smcd_event response; } ;
union ism_reg_ieq {TYPE_2__ request; struct smcd_event response; } ;
union ism_reg_dmb {TYPE_2__ request; struct smcd_event response; } ;
union ism_read_gid {TYPE_2__ request; struct smcd_event response; } ;
union ism_query_rgid {TYPE_2__ request; struct smcd_event response; } ;
union ism_qi {TYPE_2__ request; struct smcd_event response; } ;
union ism_cmd_simple {TYPE_2__ request; struct smcd_event response; } ;
typedef  void* u64 ;
typedef  void* u32 ;
struct zpci_dev {int /*<<< orphan*/  fh; } ;
struct smcd_dmb {unsigned long sba_idx; unsigned int dmb_len; void* dma_addr; int /*<<< orphan*/  dmb_tok; void* rgid; void* vlan_id; void* vlan_valid; struct ism_sba* cpu_addr; } ;
struct smcd_dev {struct ism_dev* priv; } ;
struct pci_device_id {int dummy; } ;
struct device {int dummy; } ;
struct pci_dev {struct device dev; } ;
struct TYPE_12__ {int /*<<< orphan*/  idx; } ;
struct ism_sba {scalar_t__ e; scalar_t__* dmbe_mask; scalar_t__ s; int /*<<< orphan*/ * dmb_bits; struct smcd_event* entry; TYPE_3__ header; } ;
struct ism_resp_hdr {int ret; int len; int /*<<< orphan*/  dmb_tok; int /*<<< orphan*/  gid; } ;
struct ism_req_hdr {int len; } ;
struct ism_eq {scalar_t__ e; scalar_t__* dmbe_mask; scalar_t__ s; int /*<<< orphan*/ * dmb_bits; struct smcd_event* entry; TYPE_3__ header; } ;
struct ism_dev {void* sba_dma_addr; int ieq_idx; void* ieq_dma_addr; scalar_t__ ctl; TYPE_4__* smcd; struct pci_dev* pdev; int /*<<< orphan*/  lock; struct ism_sba* sba; struct ism_sba* ieq; int /*<<< orphan*/  sba_bitmap; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  void* dma_addr_t ;
typedef  int /*<<< orphan*/  cmd ;
struct TYPE_13__ {struct ism_dev* priv; int /*<<< orphan*/  local_gid; } ;

/* Variables and functions */
 scalar_t__ ARRAY_SIZE (struct smcd_event*) ; 
 int BITS_PER_BYTE ; 
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int /*<<< orphan*/  DRV_NAME ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 void* ISM_ADD_VLAN_ID ; 
 void* ISM_CREATE_REQ (void*,unsigned int,int,unsigned int) ; 
 void* ISM_DEL_VLAN_ID ; 
 int ISM_DMB_BIT_OFFSET ; 
 size_t ISM_DMB_WORD_OFFSET ; 
 int ISM_ERROR ; 
 unsigned long ISM_NR_DMBS ; 
 void* ISM_QUERY_INFO ; 
 void* ISM_QUERY_RGID ; 
 void* ISM_READ_GID ; 
 void* ISM_REG_DMB ; 
 void* ISM_REG_IEQ ; 
 void* ISM_REG_SBA ; 
 void* ISM_RESET_VLAN ; 
 void* ISM_SET_VLAN ; 
 void* ISM_SIGNAL_IEQ ; 
 void* ISM_UNREG_DMB ; 
 void* ISM_UNREG_IEQ ; 
 void* ISM_UNREG_SBA ; 
 scalar_t__ PAGE_ALIGN (unsigned int) ; 
 unsigned int PAGE_SIZE ; 
 int /*<<< orphan*/  PCI_IRQ_MSI ; 
 int READ_ONCE (int /*<<< orphan*/ ) ; 
 scalar_t__ SZ_1M ; 
 int /*<<< orphan*/  WRITE_ONCE (int,int) ; 
 void* ZPCI_CREATE_REQ (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int) ; 
 int __GFP_COMP ; 
 int __GFP_NOMEMALLOC ; 
 int __GFP_NORETRY ; 
 int __GFP_NOWARN ; 
 int /*<<< orphan*/  barrier () ; 
 int /*<<< orphan*/  clear_bit (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clear_bit_inv (unsigned long,unsigned long*) ; 
 int /*<<< orphan*/  debug_event (int /*<<< orphan*/ ,int,struct smcd_event*,int) ; 
 int /*<<< orphan*/  debug_text_event (int /*<<< orphan*/ ,int,char*) ; 
 struct ism_dev* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct ism_dev*) ; 
 int /*<<< orphan*/  dma_free_coherent (struct device*,unsigned int,struct ism_sba*,void*) ; 
 scalar_t__ dma_get_max_seg_size (struct device*) ; 
 void* dma_zalloc_coherent (struct device*,unsigned int,void**,int) ; 
 unsigned long find_next_bit_inv (unsigned long*,unsigned long,unsigned long) ; 
 unsigned long find_next_zero_bit (int /*<<< orphan*/ ,unsigned long,int) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct ism_dev*) ; 
 int /*<<< orphan*/  ism_debug_info ; 
 int /*<<< orphan*/  ism_ops ; 
 int /*<<< orphan*/  kfree (struct ism_dev*) ; 
 struct ism_dev* kzalloc (int,int) ; 
 int /*<<< orphan*/  memcpy_fromio (struct smcd_event*,scalar_t__,int) ; 
 int /*<<< orphan*/  memcpy_toio (scalar_t__,struct ism_req_hdr*,int) ; 
 int /*<<< orphan*/  memset (union ism_unreg_dmb*,int /*<<< orphan*/ ,int) ; 
 unsigned int min (unsigned int,unsigned int) ; 
 int pci_alloc_irq_vectors (struct pci_dev*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 int pci_enable_device_mem (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_free_irq_vectors (struct pci_dev*) ; 
 scalar_t__ pci_iomap (struct pci_dev*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_iounmap (struct pci_dev*,scalar_t__) ; 
 int /*<<< orphan*/  pci_irq_vector (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_name (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_release_mem_regions (struct pci_dev*) ; 
 int pci_request_mem_regions (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int pci_set_dma_mask (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_set_dma_max_seg_size (struct pci_dev*,scalar_t__) ; 
 int /*<<< orphan*/  pci_set_dma_seg_boundary (struct pci_dev*,scalar_t__) ; 
 int /*<<< orphan*/  pci_set_master (struct pci_dev*) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct ism_dev*) ; 
 TYPE_4__* smcd_alloc_dev (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  smcd_free_dev (TYPE_4__*) ; 
 int /*<<< orphan*/  smcd_handle_event (TYPE_4__*,struct smcd_event*) ; 
 int /*<<< orphan*/  smcd_handle_irq (TYPE_4__*,unsigned long) ; 
 int smcd_register_dev (TYPE_4__*) ; 
 int /*<<< orphan*/  smcd_unregister_dev (TYPE_4__*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ test_and_set_bit (int,int /*<<< orphan*/ ) ; 
 struct zpci_dev* to_zpci (struct pci_dev*) ; 
 int zpci_write_block (void*,void*,void*) ; 

__attribute__((used)) static inline int __ism_move(struct ism_dev *ism, u64 dmb_req, void *data,
			     unsigned int size)
{
	struct zpci_dev *zdev = to_zpci(ism->pdev);
	u64 req = ZPCI_CREATE_REQ(zdev->fh, 0, size);

	return zpci_write_block(req, data, dmb_req);
}

__attribute__((used)) static int ism_cmd(struct ism_dev *ism, void *cmd)
{
	struct ism_req_hdr *req = cmd;
	struct ism_resp_hdr *resp = cmd;

	memcpy_toio(ism->ctl + sizeof(*req), req + 1, req->len - sizeof(*req));
	memcpy_toio(ism->ctl, req, sizeof(*req));

	WRITE_ONCE(resp->ret, ISM_ERROR);

	memcpy_fromio(resp, ism->ctl, sizeof(*resp));
	if (resp->ret) {
		debug_text_event(ism_debug_info, 0, "cmd failure");
		debug_event(ism_debug_info, 0, resp, sizeof(*resp));
		goto out;
	}
	memcpy_fromio(resp + 1, ism->ctl + sizeof(*resp),
		      resp->len - sizeof(*resp));
out:
	return resp->ret;
}

__attribute__((used)) static int ism_cmd_simple(struct ism_dev *ism, u32 cmd_code)
{
	union ism_cmd_simple cmd;

	memset(&cmd, 0, sizeof(cmd));
	cmd.request.hdr.cmd = cmd_code;
	cmd.request.hdr.len = sizeof(cmd.request);

	return ism_cmd(ism, &cmd);
}

__attribute__((used)) static int query_info(struct ism_dev *ism)
{
	union ism_qi cmd;

	memset(&cmd, 0, sizeof(cmd));
	cmd.request.hdr.cmd = ISM_QUERY_INFO;
	cmd.request.hdr.len = sizeof(cmd.request);

	if (ism_cmd(ism, &cmd))
		goto out;

	debug_text_event(ism_debug_info, 3, "query info");
	debug_event(ism_debug_info, 3, &cmd.response, sizeof(cmd.response));
out:
	return 0;
}

__attribute__((used)) static int register_sba(struct ism_dev *ism)
{
	union ism_reg_sba cmd;
	dma_addr_t dma_handle;
	struct ism_sba *sba;

	sba = dma_zalloc_coherent(&ism->pdev->dev, PAGE_SIZE,
				  &dma_handle, GFP_KERNEL);
	if (!sba)
		return -ENOMEM;

	memset(&cmd, 0, sizeof(cmd));
	cmd.request.hdr.cmd = ISM_REG_SBA;
	cmd.request.hdr.len = sizeof(cmd.request);
	cmd.request.sba = dma_handle;

	if (ism_cmd(ism, &cmd)) {
		dma_free_coherent(&ism->pdev->dev, PAGE_SIZE, sba, dma_handle);
		return -EIO;
	}

	ism->sba = sba;
	ism->sba_dma_addr = dma_handle;

	return 0;
}

__attribute__((used)) static int register_ieq(struct ism_dev *ism)
{
	union ism_reg_ieq cmd;
	dma_addr_t dma_handle;
	struct ism_eq *ieq;

	ieq = dma_zalloc_coherent(&ism->pdev->dev, PAGE_SIZE,
				  &dma_handle, GFP_KERNEL);
	if (!ieq)
		return -ENOMEM;

	memset(&cmd, 0, sizeof(cmd));
	cmd.request.hdr.cmd = ISM_REG_IEQ;
	cmd.request.hdr.len = sizeof(cmd.request);
	cmd.request.ieq = dma_handle;
	cmd.request.len = sizeof(*ieq);

	if (ism_cmd(ism, &cmd)) {
		dma_free_coherent(&ism->pdev->dev, PAGE_SIZE, ieq, dma_handle);
		return -EIO;
	}

	ism->ieq = ieq;
	ism->ieq_idx = -1;
	ism->ieq_dma_addr = dma_handle;

	return 0;
}

__attribute__((used)) static int unregister_sba(struct ism_dev *ism)
{
	int ret;

	if (!ism->sba)
		return 0;

	ret = ism_cmd_simple(ism, ISM_UNREG_SBA);
	if (ret && ret != ISM_ERROR)
		return -EIO;

	dma_free_coherent(&ism->pdev->dev, PAGE_SIZE,
			  ism->sba, ism->sba_dma_addr);

	ism->sba = NULL;
	ism->sba_dma_addr = 0;

	return 0;
}

__attribute__((used)) static int unregister_ieq(struct ism_dev *ism)
{
	int ret;

	if (!ism->ieq)
		return 0;

	ret = ism_cmd_simple(ism, ISM_UNREG_IEQ);
	if (ret && ret != ISM_ERROR)
		return -EIO;

	dma_free_coherent(&ism->pdev->dev, PAGE_SIZE,
			  ism->ieq, ism->ieq_dma_addr);

	ism->ieq = NULL;
	ism->ieq_dma_addr = 0;

	return 0;
}

__attribute__((used)) static int ism_read_local_gid(struct ism_dev *ism)
{
	union ism_read_gid cmd;
	int ret;

	memset(&cmd, 0, sizeof(cmd));
	cmd.request.hdr.cmd = ISM_READ_GID;
	cmd.request.hdr.len = sizeof(cmd.request);

	ret = ism_cmd(ism, &cmd);
	if (ret)
		goto out;

	ism->smcd->local_gid = cmd.response.gid;
out:
	return ret;
}

__attribute__((used)) static int ism_query_rgid(struct smcd_dev *smcd, u64 rgid, u32 vid_valid,
			  u32 vid)
{
	struct ism_dev *ism = smcd->priv;
	union ism_query_rgid cmd;

	memset(&cmd, 0, sizeof(cmd));
	cmd.request.hdr.cmd = ISM_QUERY_RGID;
	cmd.request.hdr.len = sizeof(cmd.request);

	cmd.request.rgid = rgid;
	cmd.request.vlan_valid = vid_valid;
	cmd.request.vlan_id = vid;

	return ism_cmd(ism, &cmd);
}

__attribute__((used)) static void ism_free_dmb(struct ism_dev *ism, struct smcd_dmb *dmb)
{
	clear_bit(dmb->sba_idx, ism->sba_bitmap);
	dma_free_coherent(&ism->pdev->dev, dmb->dmb_len,
			  dmb->cpu_addr, dmb->dma_addr);
}

__attribute__((used)) static int ism_alloc_dmb(struct ism_dev *ism, struct smcd_dmb *dmb)
{
	unsigned long bit;

	if (PAGE_ALIGN(dmb->dmb_len) > dma_get_max_seg_size(&ism->pdev->dev))
		return -EINVAL;

	if (!dmb->sba_idx) {
		bit = find_next_zero_bit(ism->sba_bitmap, ISM_NR_DMBS,
					 ISM_DMB_BIT_OFFSET);
		if (bit == ISM_NR_DMBS)
			return -ENOMEM;

		dmb->sba_idx = bit;
	}
	if (dmb->sba_idx < ISM_DMB_BIT_OFFSET ||
	    test_and_set_bit(dmb->sba_idx, ism->sba_bitmap))
		return -EINVAL;

	dmb->cpu_addr = dma_zalloc_coherent(&ism->pdev->dev, dmb->dmb_len,
					    &dmb->dma_addr, GFP_KERNEL |
					    __GFP_NOWARN | __GFP_NOMEMALLOC |
					    __GFP_COMP | __GFP_NORETRY);
	if (!dmb->cpu_addr)
		clear_bit(dmb->sba_idx, ism->sba_bitmap);

	return dmb->cpu_addr ? 0 : -ENOMEM;
}

__attribute__((used)) static int ism_register_dmb(struct smcd_dev *smcd, struct smcd_dmb *dmb)
{
	struct ism_dev *ism = smcd->priv;
	union ism_reg_dmb cmd;
	int ret;

	ret = ism_alloc_dmb(ism, dmb);
	if (ret)
		goto out;

	memset(&cmd, 0, sizeof(cmd));
	cmd.request.hdr.cmd = ISM_REG_DMB;
	cmd.request.hdr.len = sizeof(cmd.request);

	cmd.request.dmb = dmb->dma_addr;
	cmd.request.dmb_len = dmb->dmb_len;
	cmd.request.sba_idx = dmb->sba_idx;
	cmd.request.vlan_valid = dmb->vlan_valid;
	cmd.request.vlan_id = dmb->vlan_id;
	cmd.request.rgid = dmb->rgid;

	ret = ism_cmd(ism, &cmd);
	if (ret) {
		ism_free_dmb(ism, dmb);
		goto out;
	}
	dmb->dmb_tok = cmd.response.dmb_tok;
out:
	return ret;
}

__attribute__((used)) static int ism_unregister_dmb(struct smcd_dev *smcd, struct smcd_dmb *dmb)
{
	struct ism_dev *ism = smcd->priv;
	union ism_unreg_dmb cmd;
	int ret;

	memset(&cmd, 0, sizeof(cmd));
	cmd.request.hdr.cmd = ISM_UNREG_DMB;
	cmd.request.hdr.len = sizeof(cmd.request);

	cmd.request.dmb_tok = dmb->dmb_tok;

	ret = ism_cmd(ism, &cmd);
	if (ret && ret != ISM_ERROR)
		goto out;

	ism_free_dmb(ism, dmb);
out:
	return ret;
}

__attribute__((used)) static int ism_add_vlan_id(struct smcd_dev *smcd, u64 vlan_id)
{
	struct ism_dev *ism = smcd->priv;
	union ism_set_vlan_id cmd;

	memset(&cmd, 0, sizeof(cmd));
	cmd.request.hdr.cmd = ISM_ADD_VLAN_ID;
	cmd.request.hdr.len = sizeof(cmd.request);

	cmd.request.vlan_id = vlan_id;

	return ism_cmd(ism, &cmd);
}

__attribute__((used)) static int ism_del_vlan_id(struct smcd_dev *smcd, u64 vlan_id)
{
	struct ism_dev *ism = smcd->priv;
	union ism_set_vlan_id cmd;

	memset(&cmd, 0, sizeof(cmd));
	cmd.request.hdr.cmd = ISM_DEL_VLAN_ID;
	cmd.request.hdr.len = sizeof(cmd.request);

	cmd.request.vlan_id = vlan_id;

	return ism_cmd(ism, &cmd);
}

__attribute__((used)) static int ism_set_vlan_required(struct smcd_dev *smcd)
{
	return ism_cmd_simple(smcd->priv, ISM_SET_VLAN);
}

__attribute__((used)) static int ism_reset_vlan_required(struct smcd_dev *smcd)
{
	return ism_cmd_simple(smcd->priv, ISM_RESET_VLAN);
}

__attribute__((used)) static int ism_signal_ieq(struct smcd_dev *smcd, u64 rgid, u32 trigger_irq,
			  u32 event_code, u64 info)
{
	struct ism_dev *ism = smcd->priv;
	union ism_sig_ieq cmd;

	memset(&cmd, 0, sizeof(cmd));
	cmd.request.hdr.cmd = ISM_SIGNAL_IEQ;
	cmd.request.hdr.len = sizeof(cmd.request);

	cmd.request.rgid = rgid;
	cmd.request.trigger_irq = trigger_irq;
	cmd.request.event_code = event_code;
	cmd.request.info = info;

	return ism_cmd(ism, &cmd);
}

__attribute__((used)) static unsigned int max_bytes(unsigned int start, unsigned int len,
			      unsigned int boundary)
{
	return min(boundary - (start & (boundary - 1)), len);
}

__attribute__((used)) static int ism_move(struct smcd_dev *smcd, u64 dmb_tok, unsigned int idx,
		    bool sf, unsigned int offset, void *data, unsigned int size)
{
	struct ism_dev *ism = smcd->priv;
	unsigned int bytes;
	u64 dmb_req;
	int ret;

	while (size) {
		bytes = max_bytes(offset, size, PAGE_SIZE);
		dmb_req = ISM_CREATE_REQ(dmb_tok, idx, size == bytes ? sf : 0,
					 offset);

		ret = __ism_move(ism, dmb_req, data, bytes);
		if (ret)
			return ret;

		size -= bytes;
		data += bytes;
		offset += bytes;
	}

	return 0;
}

__attribute__((used)) static void ism_handle_event(struct ism_dev *ism)
{
	struct smcd_event *entry;

	while ((ism->ieq_idx + 1) != READ_ONCE(ism->ieq->header.idx)) {
		if (++(ism->ieq_idx) == ARRAY_SIZE(ism->ieq->entry))
			ism->ieq_idx = 0;

		entry = &ism->ieq->entry[ism->ieq_idx];
		debug_event(ism_debug_info, 2, entry, sizeof(*entry));
		smcd_handle_event(ism->smcd, entry);
	}
}

__attribute__((used)) static irqreturn_t ism_handle_irq(int irq, void *data)
{
	struct ism_dev *ism = data;
	unsigned long bit, end;
	unsigned long *bv;

	bv = (void *) &ism->sba->dmb_bits[ISM_DMB_WORD_OFFSET];
	end = sizeof(ism->sba->dmb_bits) * BITS_PER_BYTE - ISM_DMB_BIT_OFFSET;

	spin_lock(&ism->lock);
	ism->sba->s = 0;
	barrier();
	for (bit = 0;;) {
		bit = find_next_bit_inv(bv, end, bit);
		if (bit >= end)
			break;

		clear_bit_inv(bit, bv);
		ism->sba->dmbe_mask[bit + ISM_DMB_BIT_OFFSET] = 0;
		barrier();
		smcd_handle_irq(ism->smcd, bit + ISM_DMB_BIT_OFFSET);
	}

	if (ism->sba->e) {
		ism->sba->e = 0;
		barrier();
		ism_handle_event(ism);
	}
	spin_unlock(&ism->lock);
	return IRQ_HANDLED;
}

__attribute__((used)) static int ism_dev_init(struct ism_dev *ism)
{
	struct pci_dev *pdev = ism->pdev;
	int ret;

	ret = pci_alloc_irq_vectors(pdev, 1, 1, PCI_IRQ_MSI);
	if (ret <= 0)
		goto out;

	ret = request_irq(pci_irq_vector(pdev, 0), ism_handle_irq, 0,
			  pci_name(pdev), ism);
	if (ret)
		goto free_vectors;

	ret = register_sba(ism);
	if (ret)
		goto free_irq;

	ret = register_ieq(ism);
	if (ret)
		goto unreg_sba;

	ret = ism_read_local_gid(ism);
	if (ret)
		goto unreg_ieq;

	ret = smcd_register_dev(ism->smcd);
	if (ret)
		goto unreg_ieq;

	query_info(ism);
	return 0;

unreg_ieq:
	unregister_ieq(ism);
unreg_sba:
	unregister_sba(ism);
free_irq:
	free_irq(pci_irq_vector(pdev, 0), ism);
free_vectors:
	pci_free_irq_vectors(pdev);
out:
	return ret;
}

__attribute__((used)) static int ism_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
	struct ism_dev *ism;
	int ret;

	ism = kzalloc(sizeof(*ism), GFP_KERNEL);
	if (!ism)
		return -ENOMEM;

	spin_lock_init(&ism->lock);
	dev_set_drvdata(&pdev->dev, ism);
	ism->pdev = pdev;

	ret = pci_enable_device_mem(pdev);
	if (ret)
		goto err;

	ret = pci_request_mem_regions(pdev, DRV_NAME);
	if (ret)
		goto err_disable;

	ism->ctl = pci_iomap(pdev, 2, 0);
	if (!ism->ctl)
		goto err_resource;

	ret = pci_set_dma_mask(pdev, DMA_BIT_MASK(64));
	if (ret)
		goto err_unmap;

	pci_set_dma_seg_boundary(pdev, SZ_1M - 1);
	pci_set_dma_max_seg_size(pdev, SZ_1M);
	pci_set_master(pdev);

	ism->smcd = smcd_alloc_dev(&pdev->dev, dev_name(&pdev->dev), &ism_ops,
				   ISM_NR_DMBS);
	if (!ism->smcd)
		goto err_unmap;

	ism->smcd->priv = ism;
	ret = ism_dev_init(ism);
	if (ret)
		goto err_free;

	return 0;

err_free:
	smcd_free_dev(ism->smcd);
err_unmap:
	pci_iounmap(pdev, ism->ctl);
err_resource:
	pci_release_mem_regions(pdev);
err_disable:
	pci_disable_device(pdev);
err:
	kfree(ism);
	dev_set_drvdata(&pdev->dev, NULL);
	return ret;
}

__attribute__((used)) static void ism_dev_exit(struct ism_dev *ism)
{
	struct pci_dev *pdev = ism->pdev;

	smcd_unregister_dev(ism->smcd);
	unregister_ieq(ism);
	unregister_sba(ism);
	free_irq(pci_irq_vector(pdev, 0), ism);
	pci_free_irq_vectors(pdev);
}

__attribute__((used)) static void ism_remove(struct pci_dev *pdev)
{
	struct ism_dev *ism = dev_get_drvdata(&pdev->dev);

	ism_dev_exit(ism);

	smcd_free_dev(ism->smcd);
	pci_iounmap(pdev, ism->ctl);
	pci_release_mem_regions(pdev);
	pci_disable_device(pdev);
	dev_set_drvdata(&pdev->dev, NULL);
	kfree(ism);
}

__attribute__((used)) static int ism_suspend(struct device *dev)
{
	struct ism_dev *ism = dev_get_drvdata(dev);

	ism_dev_exit(ism);
	return 0;
}

__attribute__((used)) static int ism_resume(struct device *dev)
{
	struct ism_dev *ism = dev_get_drvdata(dev);

	return ism_dev_init(ism);
}

