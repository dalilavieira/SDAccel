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
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u64 ;
typedef  scalar_t__ u32 ;
typedef  scalar_t__ u16 ;
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct completion {int dummy; } ;
struct hinic_recv_msg {scalar_t__ msg_id; int msg_len; scalar_t__* msg; scalar_t__* buf_out; scalar_t__ mod; scalar_t__ cmd; int async_mgmt_to_pf; struct completion recv_done; } ;
struct hinic_hwdev {int /*<<< orphan*/  aeqs; } ;
struct hinic_pfhwdev {struct hinic_hwdev hwdev; } ;
struct hinic_pf_to_mgmt {scalar_t__* sync_msg_buf; struct hinic_api_cmd_chain** cmd_chain; scalar_t__ sync_msg_id; int /*<<< orphan*/  sync_msg_lock; struct hinic_hwif* hwif; struct hinic_recv_msg recv_resp_msg_from_mgmt; struct hinic_recv_msg recv_msg_from_mgmt; struct hinic_mgmt_cb* mgmt_cb; } ;
struct hinic_mgmt_cb {void (* cb ) (void*,u8,void*,u16,void*,u16*) ;int state; void* handle; } ;
struct hinic_hwif {struct pci_dev* pdev; scalar_t__ cfg_regs_bar; } ;
struct hinic_api_cmd_chain {int dummy; } ;
typedef  enum msg_ack_type { ____Placeholder_msg_ack_type } msg_ack_type ;
typedef  enum mgmt_direction_type { ____Placeholder_mgmt_direction_type } mgmt_direction_type ;
typedef  enum hinic_mod_type { ____Placeholder_hinic_mod_type } hinic_mod_type ;
typedef  enum hinic_mgmt_msg_type { ____Placeholder_hinic_mgmt_msg_type } hinic_mgmt_msg_type ;

/* Variables and functions */
 scalar_t__ ALIGN (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ASYNC_MGMT_TO_PF ; 
 int /*<<< orphan*/  CMD ; 
 int /*<<< orphan*/  DIRECTION ; 
 int EFAULT ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 size_t HINIC_API_CMD_WRITE_TO_MGMT_CPU ; 
 scalar_t__ HINIC_HWIF_PCI_INTF (struct hinic_hwif*) ; 
 scalar_t__ HINIC_HWIF_PF_IDX (struct hinic_hwif*) ; 
 int HINIC_MGMT_CB_ENABLED ; 
 int HINIC_MGMT_CB_RUNNING ; 
 int HINIC_MGMT_MSG_SYNC ; 
 scalar_t__ HINIC_MOD_MAX ; 
 int /*<<< orphan*/  HINIC_MSG_FROM_MGMT_CPU ; 
 int HINIC_MSG_HEADER_GET (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ HINIC_MSG_HEADER_SET (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HINIC_NODE_ID_MGMT ; 
 int /*<<< orphan*/  LAST ; 
 scalar_t__ LAST_SEGMENT ; 
 int MAX_MSG_LEN ; 
 int MAX_PF_MGMT_BUF_SIZE ; 
 int MGMT_DIRECT_SEND ; 
 scalar_t__ MGMT_MSG_LEN_MIN ; 
 int /*<<< orphan*/  MGMT_MSG_LEN_STEP ; 
 scalar_t__ MGMT_MSG_RSVD_FOR_DEV ; 
 int /*<<< orphan*/  MGMT_MSG_TIMEOUT ; 
 int MGMT_RESP ; 
 int /*<<< orphan*/  MODULE ; 
 int MSG_ACK ; 
 int /*<<< orphan*/  MSG_ID ; 
 int /*<<< orphan*/  MSG_LEN ; 
 scalar_t__ MSG_NOT_RESP ; 
 int MSG_NO_ACK ; 
 int /*<<< orphan*/  MSG_SZ_IS_VALID (scalar_t__) ; 
 int /*<<< orphan*/  NO_ACK ; 
 int /*<<< orphan*/  PCI_INTF ; 
 int /*<<< orphan*/  PF_IDX ; 
 int SEGMENT_LEN ; 
 int /*<<< orphan*/  SEG_LEN ; 
 int /*<<< orphan*/  SEQID ; 
 scalar_t__ SYNC_MSG_ID (struct hinic_pf_to_mgmt*) ; 
 int /*<<< orphan*/  SYNC_MSG_ID_INC (struct hinic_pf_to_mgmt*) ; 
 scalar_t__ be32_to_cpu (int /*<<< orphan*/ ) ; 
 unsigned long cmpxchg (int*,int,int) ; 
 int /*<<< orphan*/  complete (struct completion*) ; 
 int /*<<< orphan*/  cpu_to_be32 (scalar_t__) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 void* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  down (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  hinic_aeq_register_hw_cb (int /*<<< orphan*/ *,int /*<<< orphan*/ ,struct hinic_pf_to_mgmt*,void (*) (void*,void*,scalar_t__)) ; 
 int /*<<< orphan*/  hinic_aeq_unregister_hw_cb (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hinic_api_cmd_free (struct hinic_api_cmd_chain**) ; 
 int hinic_api_cmd_init (struct hinic_api_cmd_chain**,struct hinic_hwif*) ; 
 int hinic_api_cmd_write (struct hinic_api_cmd_chain*,int /*<<< orphan*/ ,scalar_t__*,scalar_t__) ; 
 int /*<<< orphan*/  init_completion (struct completion*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,scalar_t__*,int) ; 
 int /*<<< orphan*/  memset (scalar_t__*,int /*<<< orphan*/ ,scalar_t__) ; 
 struct hinic_pfhwdev* mgmt_to_pfhwdev (struct hinic_pf_to_mgmt*) ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 
 int /*<<< orphan*/  schedule () ; 
 int /*<<< orphan*/  sema_init (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  smp_rmb () ; 
 void stub1 (void*,scalar_t__,scalar_t__*,scalar_t__,scalar_t__*,scalar_t__*) ; 
 int /*<<< orphan*/  up (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wait_for_completion_timeout (struct completion*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wmb () ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline u32 hinic_hwif_read_reg(struct hinic_hwif *hwif, u32 reg)
{
	return be32_to_cpu(readl(hwif->cfg_regs_bar + reg));
}

__attribute__((used)) static inline void hinic_hwif_write_reg(struct hinic_hwif *hwif, u32 reg,
					u32 val)
{
	writel(cpu_to_be32(val), hwif->cfg_regs_bar + reg);
}

void hinic_register_mgmt_msg_cb(struct hinic_pf_to_mgmt *pf_to_mgmt,
				enum hinic_mod_type mod,
				void *handle,
				void (*callback)(void *handle,
						 u8 cmd, void *buf_in,
						 u16 in_size, void *buf_out,
						 u16 *out_size))
{
	struct hinic_mgmt_cb *mgmt_cb = &pf_to_mgmt->mgmt_cb[mod];

	mgmt_cb->cb = callback;
	mgmt_cb->handle = handle;
	mgmt_cb->state = HINIC_MGMT_CB_ENABLED;
}

void hinic_unregister_mgmt_msg_cb(struct hinic_pf_to_mgmt *pf_to_mgmt,
				  enum hinic_mod_type mod)
{
	struct hinic_mgmt_cb *mgmt_cb = &pf_to_mgmt->mgmt_cb[mod];

	mgmt_cb->state &= ~HINIC_MGMT_CB_ENABLED;

	while (mgmt_cb->state & HINIC_MGMT_CB_RUNNING)
		schedule();

	mgmt_cb->cb = NULL;
}

__attribute__((used)) static u64 prepare_header(struct hinic_pf_to_mgmt *pf_to_mgmt,
			  u16 msg_len, enum hinic_mod_type mod,
			  enum msg_ack_type ack_type,
			  enum mgmt_direction_type direction,
			  u16 cmd, u16 msg_id)
{
	struct hinic_hwif *hwif = pf_to_mgmt->hwif;

	return HINIC_MSG_HEADER_SET(msg_len, MSG_LEN)           |
	       HINIC_MSG_HEADER_SET(mod, MODULE)                |
	       HINIC_MSG_HEADER_SET(SEGMENT_LEN, SEG_LEN)       |
	       HINIC_MSG_HEADER_SET(ack_type, NO_ACK)           |
	       HINIC_MSG_HEADER_SET(0, ASYNC_MGMT_TO_PF)        |
	       HINIC_MSG_HEADER_SET(0, SEQID)                   |
	       HINIC_MSG_HEADER_SET(LAST_SEGMENT, LAST)         |
	       HINIC_MSG_HEADER_SET(direction, DIRECTION)       |
	       HINIC_MSG_HEADER_SET(cmd, CMD)                   |
	       HINIC_MSG_HEADER_SET(HINIC_HWIF_PCI_INTF(hwif), PCI_INTF) |
	       HINIC_MSG_HEADER_SET(HINIC_HWIF_PF_IDX(hwif), PF_IDX)     |
	       HINIC_MSG_HEADER_SET(msg_id, MSG_ID);
}

__attribute__((used)) static void prepare_mgmt_cmd(u8 *mgmt_cmd, u64 *header, u8 *msg, u16 msg_len)
{
	memset(mgmt_cmd, 0, MGMT_MSG_RSVD_FOR_DEV);

	mgmt_cmd += MGMT_MSG_RSVD_FOR_DEV;
	memcpy(mgmt_cmd, header, sizeof(*header));

	mgmt_cmd += sizeof(*header);
	memcpy(mgmt_cmd, msg, msg_len);
}

__attribute__((used)) static u16 mgmt_msg_len(u16 msg_data_len)
{
	/* RSVD + HEADER_SIZE + DATA_LEN */
	u16 msg_len = MGMT_MSG_RSVD_FOR_DEV + sizeof(u64) + msg_data_len;

	if (msg_len > MGMT_MSG_LEN_MIN)
		msg_len = MGMT_MSG_LEN_MIN +
			   ALIGN((msg_len - MGMT_MSG_LEN_MIN),
				 MGMT_MSG_LEN_STEP);
	else
		msg_len = MGMT_MSG_LEN_MIN;

	return msg_len;
}

__attribute__((used)) static int send_msg_to_mgmt(struct hinic_pf_to_mgmt *pf_to_mgmt,
			    enum hinic_mod_type mod, u8 cmd,
			    u8 *data, u16 data_len,
			    enum msg_ack_type ack_type,
			    enum mgmt_direction_type direction,
			    u16 resp_msg_id)
{
	struct hinic_api_cmd_chain *chain;
	u64 header;
	u16 msg_id;

	msg_id = SYNC_MSG_ID(pf_to_mgmt);

	if (direction == MGMT_RESP) {
		header = prepare_header(pf_to_mgmt, data_len, mod, ack_type,
					direction, cmd, resp_msg_id);
	} else {
		SYNC_MSG_ID_INC(pf_to_mgmt);
		header = prepare_header(pf_to_mgmt, data_len, mod, ack_type,
					direction, cmd, msg_id);
	}

	prepare_mgmt_cmd(pf_to_mgmt->sync_msg_buf, &header, data, data_len);

	chain = pf_to_mgmt->cmd_chain[HINIC_API_CMD_WRITE_TO_MGMT_CPU];
	return hinic_api_cmd_write(chain, HINIC_NODE_ID_MGMT,
				   pf_to_mgmt->sync_msg_buf,
				   mgmt_msg_len(data_len));
}

__attribute__((used)) static int msg_to_mgmt_sync(struct hinic_pf_to_mgmt *pf_to_mgmt,
			    enum hinic_mod_type mod, u8 cmd,
			    u8 *buf_in, u16 in_size,
			    u8 *buf_out, u16 *out_size,
			    enum mgmt_direction_type direction,
			    u16 resp_msg_id)
{
	struct hinic_hwif *hwif = pf_to_mgmt->hwif;
	struct pci_dev *pdev = hwif->pdev;
	struct hinic_recv_msg *recv_msg;
	struct completion *recv_done;
	u16 msg_id;
	int err;

	/* Lock the sync_msg_buf */
	down(&pf_to_mgmt->sync_msg_lock);

	recv_msg = &pf_to_mgmt->recv_resp_msg_from_mgmt;
	recv_done = &recv_msg->recv_done;

	if (resp_msg_id == MSG_NOT_RESP)
		msg_id = SYNC_MSG_ID(pf_to_mgmt);
	else
		msg_id = resp_msg_id;

	init_completion(recv_done);

	err = send_msg_to_mgmt(pf_to_mgmt, mod, cmd, buf_in, in_size,
			       MSG_ACK, direction, resp_msg_id);
	if (err) {
		dev_err(&pdev->dev, "Failed to send sync msg to mgmt\n");
		goto unlock_sync_msg;
	}

	if (!wait_for_completion_timeout(recv_done, MGMT_MSG_TIMEOUT)) {
		dev_err(&pdev->dev, "MGMT timeout, MSG id = %d\n", msg_id);
		err = -ETIMEDOUT;
		goto unlock_sync_msg;
	}

	smp_rmb();      /* verify reading after completion */

	if (recv_msg->msg_id != msg_id) {
		dev_err(&pdev->dev, "incorrect MSG for id = %d\n", msg_id);
		err = -EFAULT;
		goto unlock_sync_msg;
	}

	if ((buf_out) && (recv_msg->msg_len <= MAX_PF_MGMT_BUF_SIZE)) {
		memcpy(buf_out, recv_msg->msg, recv_msg->msg_len);
		*out_size = recv_msg->msg_len;
	}

unlock_sync_msg:
	up(&pf_to_mgmt->sync_msg_lock);
	return err;
}

__attribute__((used)) static int msg_to_mgmt_async(struct hinic_pf_to_mgmt *pf_to_mgmt,
			     enum hinic_mod_type mod, u8 cmd,
			     u8 *buf_in, u16 in_size,
			     enum mgmt_direction_type direction,
			     u16 resp_msg_id)
{
	int err;

	/* Lock the sync_msg_buf */
	down(&pf_to_mgmt->sync_msg_lock);

	err = send_msg_to_mgmt(pf_to_mgmt, mod, cmd, buf_in, in_size,
			       MSG_NO_ACK, direction, resp_msg_id);

	up(&pf_to_mgmt->sync_msg_lock);
	return err;
}

int hinic_msg_to_mgmt(struct hinic_pf_to_mgmt *pf_to_mgmt,
		      enum hinic_mod_type mod, u8 cmd,
		      void *buf_in, u16 in_size, void *buf_out, u16 *out_size,
		      enum hinic_mgmt_msg_type sync)
{
	struct hinic_hwif *hwif = pf_to_mgmt->hwif;
	struct pci_dev *pdev = hwif->pdev;

	if (sync != HINIC_MGMT_MSG_SYNC) {
		dev_err(&pdev->dev, "Invalid MGMT msg type\n");
		return -EINVAL;
	}

	if (!MSG_SZ_IS_VALID(in_size)) {
		dev_err(&pdev->dev, "Invalid MGMT msg buffer size\n");
		return -EINVAL;
	}

	return msg_to_mgmt_sync(pf_to_mgmt, mod, cmd, buf_in, in_size,
				buf_out, out_size, MGMT_DIRECT_SEND,
				MSG_NOT_RESP);
}

__attribute__((used)) static void mgmt_recv_msg_handler(struct hinic_pf_to_mgmt *pf_to_mgmt,
				  struct hinic_recv_msg *recv_msg)
{
	struct hinic_hwif *hwif = pf_to_mgmt->hwif;
	struct pci_dev *pdev = hwif->pdev;
	u8 *buf_out = recv_msg->buf_out;
	struct hinic_mgmt_cb *mgmt_cb;
	unsigned long cb_state;
	u16 out_size = 0;

	if (recv_msg->mod >= HINIC_MOD_MAX) {
		dev_err(&pdev->dev, "Unknown MGMT MSG module = %d\n",
			recv_msg->mod);
		return;
	}

	mgmt_cb = &pf_to_mgmt->mgmt_cb[recv_msg->mod];

	cb_state = cmpxchg(&mgmt_cb->state,
			   HINIC_MGMT_CB_ENABLED,
			   HINIC_MGMT_CB_ENABLED | HINIC_MGMT_CB_RUNNING);

	if ((cb_state == HINIC_MGMT_CB_ENABLED) && (mgmt_cb->cb))
		mgmt_cb->cb(mgmt_cb->handle, recv_msg->cmd,
			    recv_msg->msg, recv_msg->msg_len,
			    buf_out, &out_size);
	else
		dev_err(&pdev->dev, "No MGMT msg handler, mod = %d\n",
			recv_msg->mod);

	mgmt_cb->state &= ~HINIC_MGMT_CB_RUNNING;

	if (!recv_msg->async_mgmt_to_pf)
		/* MGMT sent sync msg, send the response */
		msg_to_mgmt_async(pf_to_mgmt, recv_msg->mod, recv_msg->cmd,
				  buf_out, out_size, MGMT_RESP,
				  recv_msg->msg_id);
}

__attribute__((used)) static void mgmt_resp_msg_handler(struct hinic_pf_to_mgmt *pf_to_mgmt,
				  struct hinic_recv_msg *recv_msg)
{
	wmb();  /* verify writing all, before reading */

	complete(&recv_msg->recv_done);
}

__attribute__((used)) static void recv_mgmt_msg_handler(struct hinic_pf_to_mgmt *pf_to_mgmt,
				  u64 *header, struct hinic_recv_msg *recv_msg)
{
	struct hinic_hwif *hwif = pf_to_mgmt->hwif;
	struct pci_dev *pdev = hwif->pdev;
	int seq_id, seg_len;
	u8 *msg_body;

	seq_id = HINIC_MSG_HEADER_GET(*header, SEQID);
	seg_len = HINIC_MSG_HEADER_GET(*header, SEG_LEN);

	if (seq_id >= (MAX_MSG_LEN / SEGMENT_LEN)) {
		dev_err(&pdev->dev, "recv big mgmt msg\n");
		return;
	}

	msg_body = (u8 *)header + sizeof(*header);
	memcpy(recv_msg->msg + seq_id * SEGMENT_LEN, msg_body, seg_len);

	if (!HINIC_MSG_HEADER_GET(*header, LAST))
		return;

	recv_msg->cmd = HINIC_MSG_HEADER_GET(*header, CMD);
	recv_msg->mod = HINIC_MSG_HEADER_GET(*header, MODULE);
	recv_msg->async_mgmt_to_pf = HINIC_MSG_HEADER_GET(*header,
							  ASYNC_MGMT_TO_PF);
	recv_msg->msg_len = HINIC_MSG_HEADER_GET(*header, MSG_LEN);
	recv_msg->msg_id = HINIC_MSG_HEADER_GET(*header, MSG_ID);

	if (HINIC_MSG_HEADER_GET(*header, DIRECTION) == MGMT_RESP)
		mgmt_resp_msg_handler(pf_to_mgmt, recv_msg);
	else
		mgmt_recv_msg_handler(pf_to_mgmt, recv_msg);
}

__attribute__((used)) static void mgmt_msg_aeqe_handler(void *handle, void *data, u8 size)
{
	struct hinic_pf_to_mgmt *pf_to_mgmt = handle;
	struct hinic_recv_msg *recv_msg;
	u64 *header = (u64 *)data;

	recv_msg = HINIC_MSG_HEADER_GET(*header, DIRECTION) ==
		   MGMT_DIRECT_SEND ?
		   &pf_to_mgmt->recv_msg_from_mgmt :
		   &pf_to_mgmt->recv_resp_msg_from_mgmt;

	recv_mgmt_msg_handler(pf_to_mgmt, header, recv_msg);
}

__attribute__((used)) static int alloc_recv_msg(struct hinic_pf_to_mgmt *pf_to_mgmt,
			  struct hinic_recv_msg *recv_msg)
{
	struct hinic_hwif *hwif = pf_to_mgmt->hwif;
	struct pci_dev *pdev = hwif->pdev;

	recv_msg->msg = devm_kzalloc(&pdev->dev, MAX_PF_MGMT_BUF_SIZE,
				     GFP_KERNEL);
	if (!recv_msg->msg)
		return -ENOMEM;

	recv_msg->buf_out = devm_kzalloc(&pdev->dev, MAX_PF_MGMT_BUF_SIZE,
					 GFP_KERNEL);
	if (!recv_msg->buf_out)
		return -ENOMEM;

	return 0;
}

__attribute__((used)) static int alloc_msg_buf(struct hinic_pf_to_mgmt *pf_to_mgmt)
{
	struct hinic_hwif *hwif = pf_to_mgmt->hwif;
	struct pci_dev *pdev = hwif->pdev;
	int err;

	err = alloc_recv_msg(pf_to_mgmt,
			     &pf_to_mgmt->recv_msg_from_mgmt);
	if (err) {
		dev_err(&pdev->dev, "Failed to allocate recv msg\n");
		return err;
	}

	err = alloc_recv_msg(pf_to_mgmt,
			     &pf_to_mgmt->recv_resp_msg_from_mgmt);
	if (err) {
		dev_err(&pdev->dev, "Failed to allocate resp recv msg\n");
		return err;
	}

	pf_to_mgmt->sync_msg_buf = devm_kzalloc(&pdev->dev,
						MAX_PF_MGMT_BUF_SIZE,
						GFP_KERNEL);
	if (!pf_to_mgmt->sync_msg_buf)
		return -ENOMEM;

	return 0;
}

int hinic_pf_to_mgmt_init(struct hinic_pf_to_mgmt *pf_to_mgmt,
			  struct hinic_hwif *hwif)
{
	struct hinic_pfhwdev *pfhwdev = mgmt_to_pfhwdev(pf_to_mgmt);
	struct hinic_hwdev *hwdev = &pfhwdev->hwdev;
	struct pci_dev *pdev = hwif->pdev;
	int err;

	pf_to_mgmt->hwif = hwif;

	sema_init(&pf_to_mgmt->sync_msg_lock, 1);
	pf_to_mgmt->sync_msg_id = 0;

	err = alloc_msg_buf(pf_to_mgmt);
	if (err) {
		dev_err(&pdev->dev, "Failed to allocate msg buffers\n");
		return err;
	}

	err = hinic_api_cmd_init(pf_to_mgmt->cmd_chain, hwif);
	if (err) {
		dev_err(&pdev->dev, "Failed to initialize cmd chains\n");
		return err;
	}

	hinic_aeq_register_hw_cb(&hwdev->aeqs, HINIC_MSG_FROM_MGMT_CPU,
				 pf_to_mgmt,
				 mgmt_msg_aeqe_handler);
	return 0;
}

void hinic_pf_to_mgmt_free(struct hinic_pf_to_mgmt *pf_to_mgmt)
{
	struct hinic_pfhwdev *pfhwdev = mgmt_to_pfhwdev(pf_to_mgmt);
	struct hinic_hwdev *hwdev = &pfhwdev->hwdev;

	hinic_aeq_unregister_hw_cb(&hwdev->aeqs, HINIC_MSG_FROM_MGMT_CPU);
	hinic_api_cmd_free(pf_to_mgmt->cmd_chain);
}

