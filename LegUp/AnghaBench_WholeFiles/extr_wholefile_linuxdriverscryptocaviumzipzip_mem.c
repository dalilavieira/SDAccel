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
struct TYPE_3__ {int /*<<< orphan*/  compcode; } ;
union zip_zres_s {TYPE_1__ s; } ;
typedef  int u8 ;
typedef  int u64 ;
struct zip_device {TYPE_2__* iq; } ;
struct TYPE_4__ {int* sw_head; int* sw_tail; } ;

/* Variables and functions */
 int ENOMEM ; 
 int ETIMEDOUT ; 
 int GFP_DMA ; 
 int GFP_KERNEL ; 
 int ZIP_CMD_QBUF_SIZE ; 
 scalar_t__ __get_free_pages (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free_pages (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  get_order (int) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  rmb () ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  zip_dbg (char*,...) ; 

__attribute__((used)) static inline u64 ZIP_COREX_BIST_STATUS(u64 param1)
{
	if (param1 <= 1)
		return 0x0520ull + (param1 & 1) * 0x8ull;
	pr_err("ZIP_COREX_BIST_STATUS: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_DBG_COREX_INST(u64 param1)
{
	if (param1 <= 1)
		return 0x0640ull + (param1 & 1) * 0x8ull;
	pr_err("ZIP_DBG_COREX_INST: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_DBG_COREX_STA(u64 param1)
{
	if (param1 <= 1)
		return 0x0680ull + (param1 & 1) * 0x8ull;
	pr_err("ZIP_DBG_COREX_STA: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_DBG_QUEX_STA(u64 param1)
{
	if (param1 <= 7)
		return 0x1800ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_DBG_QUEX_STA: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_MSIX_PBAX(u64 param1)
{
	if (param1 == 0)
		return 0x0000838000FF0000ull;
	pr_err("ZIP_MSIX_PBAX: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_MSIX_VECX_ADDR(u64 param1)
{
	if (param1 <= 17)
		return 0x0000838000F00000ull + (param1 & 31) * 0x10ull;
	pr_err("ZIP_MSIX_VECX_ADDR: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_MSIX_VECX_CTL(u64 param1)
{
	if (param1 <= 17)
		return 0x0000838000F00008ull + (param1 & 31) * 0x10ull;
	pr_err("ZIP_MSIX_VECX_CTL: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_DONE(u64 param1)
{
	if (param1 <= 7)
		return 0x2000ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_DONE: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_DONE_ACK(u64 param1)
{
	if (param1 <= 7)
		return 0x2200ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_DONE_ACK: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_DONE_ENA_W1C(u64 param1)
{
	if (param1 <= 7)
		return 0x2600ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_DONE_ENA_W1C: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_DONE_ENA_W1S(u64 param1)
{
	if (param1 <= 7)
		return 0x2400ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_DONE_ENA_W1S: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_DONE_WAIT(u64 param1)
{
	if (param1 <= 7)
		return 0x2800ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_DONE_WAIT: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_DOORBELL(u64 param1)
{
	if (param1 <= 7)
		return 0x4000ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_DOORBELL: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_ERR_ENA_W1C(u64 param1)
{
	if (param1 <= 7)
		return 0x3600ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_ERR_ENA_W1C: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_ERR_ENA_W1S(u64 param1)
{
	if (param1 <= 7)
		return 0x3400ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_ERR_ENA_W1S: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_ERR_INT(u64 param1)
{
	if (param1 <= 7)
		return 0x3000ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_ERR_INT: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_ERR_INT_W1S(u64 param1)
{
	if (param1 <= 7)
		return 0x3200ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_ERR_INT_W1S: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_GCFG(u64 param1)
{
	if (param1 <= 7)
		return 0x1A00ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_GCFG: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_MAP(u64 param1)
{
	if (param1 <= 7)
		return 0x1400ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_MAP: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_SBUF_ADDR(u64 param1)
{
	if (param1 <= 7)
		return 0x1000ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_SBUF_ADDR: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_SBUF_CTL(u64 param1)
{
	if (param1 <= 7)
		return 0x1200ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_SBUF_CTL: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline int zip_poll_result(union zip_zres_s *result)
{
	int retries = 1000;

	while (!result->s.compcode) {
		if (!--retries) {
			pr_err("ZIP ERR: request timed out");
			return -ETIMEDOUT;
		}
		udelay(10);
		/*
		 * Force re-reading of compcode which is updated
		 * by the ZIP coprocessor.
		 */
		rmb();
	}
	return 0;
}

int zip_cmd_qbuf_alloc(struct zip_device *zip, int q)
{
	zip->iq[q].sw_head = (u64 *)__get_free_pages((GFP_KERNEL | GFP_DMA),
						get_order(ZIP_CMD_QBUF_SIZE));

	if (!zip->iq[q].sw_head)
		return -ENOMEM;

	memset(zip->iq[q].sw_head, 0, ZIP_CMD_QBUF_SIZE);

	zip_dbg("cmd_qbuf_alloc[%d] Success : %p\n", q, zip->iq[q].sw_head);
	return 0;
}

void zip_cmd_qbuf_free(struct zip_device *zip, int q)
{
	zip_dbg("Freeing cmd_qbuf 0x%lx\n", zip->iq[q].sw_tail);

	free_pages((u64)zip->iq[q].sw_tail, get_order(ZIP_CMD_QBUF_SIZE));
}

u8 *zip_data_buf_alloc(u64 size)
{
	u8 *ptr;

	ptr = (u8 *)__get_free_pages((GFP_KERNEL | GFP_DMA),
					get_order(size));

	if (!ptr)
		return NULL;

	memset(ptr, 0, size);

	zip_dbg("Data buffer allocation success\n");
	return ptr;
}

void zip_data_buf_free(u8 *ptr, u64 size)
{
	zip_dbg("Freeing data buffer 0x%lx\n", ptr);

	free_pages((u64)ptr, get_order(size));
}

