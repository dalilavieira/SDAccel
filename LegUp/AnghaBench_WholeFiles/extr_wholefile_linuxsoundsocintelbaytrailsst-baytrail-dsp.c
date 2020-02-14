#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u64 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  template ;
struct sst_pdata {int /*<<< orphan*/  irq; int /*<<< orphan*/  fw_size; int /*<<< orphan*/  fw_base; int /*<<< orphan*/  pcicfg_size; int /*<<< orphan*/  pcicfg_base; int /*<<< orphan*/  lpe_size; int /*<<< orphan*/  lpe_base; } ;
struct sst_module_template {int /*<<< orphan*/  entry; int /*<<< orphan*/  id; } ;
struct sst_module {int offset; scalar_t__ size; void* data; int /*<<< orphan*/  type; } ;
struct sst_fw {scalar_t__ size; scalar_t__ dma_buf; struct sst_dsp* dsp; } ;
struct TYPE_6__ {int lpe; int iram_offset; int dram_offset; int fw_ext; int pci_cfg; int shim; int shim_offset; int /*<<< orphan*/  lpe_base; } ;
struct sst_dsp {void* thread_context; int id; TYPE_3__ addr; int /*<<< orphan*/  dma_dev; struct device* dev; int /*<<< orphan*/  irq; TYPE_1__* pdata; int /*<<< orphan*/  spinlock; TYPE_2__* ops; } ;
struct sst_byt_fw_module_header {int blocks; int mod_size; int /*<<< orphan*/  entry_point; int /*<<< orphan*/  type; } ;
struct sst_adsp_memregion {int start; int end; int blocks; int /*<<< orphan*/  type; } ;
struct fw_header {scalar_t__ file_size; int modules; int /*<<< orphan*/  file_format; int /*<<< orphan*/  signature; } ;
struct dma_block_info {scalar_t__ size; int type; int ram_offset; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_5__ {int /*<<< orphan*/  (* ram_read ) (struct sst_dsp*,void*,int,size_t) ;int /*<<< orphan*/  (* ram_write ) (struct sst_dsp*,int,void*,size_t) ;} ;
struct TYPE_4__ {int /*<<< orphan*/  fw_base; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct sst_adsp_memregion*) ; 
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int /*<<< orphan*/  IRQ_WAKE_THREAD ; 
#define  SST_BYT_CACHE 131 
 int SST_BYT_CSR_PWAITMODE ; 
 int SST_BYT_CSR_RST ; 
 int SST_BYT_CSR_STALL ; 
 int SST_BYT_CSR_VECTOR_SEL ; 
#define  SST_BYT_DRAM 130 
 int SST_BYT_DRAM_OFFSET ; 
 int /*<<< orphan*/  SST_BYT_FW_SIGN ; 
 int /*<<< orphan*/  SST_BYT_IMRX_REQUEST ; 
 int /*<<< orphan*/  SST_BYT_IPCX_DONE ; 
 int /*<<< orphan*/  SST_BYT_IPC_MAX_PAYLOAD_SIZE ; 
#define  SST_BYT_IRAM 129 
 int SST_BYT_IRAM_OFFSET ; 
 int SST_BYT_ISRX_REQUEST ; 
 int SST_BYT_MAILBOX_OFFSET ; 
 int SST_BYT_SHIM_OFFSET ; 
 int /*<<< orphan*/  SST_CSR ; 
#define  SST_DEV_ID_BYT 128 
 int /*<<< orphan*/  SST_IMRD ; 
 int /*<<< orphan*/  SST_IMRX ; 
 int /*<<< orphan*/  SST_IPCX ; 
 int SST_ISRX ; 
 int SST_ISRX_DONE ; 
 int /*<<< orphan*/  SST_MEM_CACHE ; 
 int /*<<< orphan*/  SST_MEM_DRAM ; 
 int /*<<< orphan*/  SST_MEM_IRAM ; 
 struct sst_adsp_memregion* byt_region ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int,int,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int dma_coerce_mask_and_coherent (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* ioremap (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iounmap (int) ; 
 int /*<<< orphan*/  memcpy_toio (int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (struct sst_module_template*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int readl (int) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sst_dsp_mailbox_init (struct sst_dsp*,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int sst_dsp_shim_read64 (struct sst_dsp*,int /*<<< orphan*/ ) ; 
 int sst_dsp_shim_read64_unlocked (struct sst_dsp*,int) ; 
 int /*<<< orphan*/  sst_dsp_shim_update_bits64 (struct sst_dsp*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  sst_dsp_shim_update_bits64_unlocked (struct sst_dsp*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sst_mem_block_register (struct sst_dsp*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,struct sst_dsp*) ; 
 int /*<<< orphan*/  sst_mem_block_unregister_all (struct sst_dsp*) ; 
 int /*<<< orphan*/  sst_module_alloc_blocks (struct sst_module*) ; 
 struct sst_module* sst_module_new (struct sst_fw*,struct sst_module_template*,int /*<<< orphan*/ *) ; 
 scalar_t__ strncmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (struct sst_dsp*,int,void*,size_t) ; 
 int /*<<< orphan*/  stub2 (struct sst_dsp*,void*,int,size_t) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline void sst_dsp_write(struct sst_dsp *sst, void *src,
	u32 dest_offset, size_t bytes)
{
	sst->ops->ram_write(sst, sst->addr.lpe + dest_offset, src, bytes);
}

__attribute__((used)) static inline void sst_dsp_read(struct sst_dsp *sst, void *dest,
	u32 src_offset, size_t bytes)
{
	sst->ops->ram_read(sst, dest, sst->addr.lpe + src_offset, bytes);
}

__attribute__((used)) static inline void *sst_dsp_get_thread_context(struct sst_dsp *sst)
{
	return sst->thread_context;
}

__attribute__((used)) static int sst_byt_parse_module(struct sst_dsp *dsp, struct sst_fw *fw,
				struct sst_byt_fw_module_header *module)
{
	struct dma_block_info *block;
	struct sst_module *mod;
	struct sst_module_template template;
	int count;

	memset(&template, 0, sizeof(template));
	template.id = module->type;
	template.entry = module->entry_point;

	mod = sst_module_new(fw, &template, NULL);
	if (mod == NULL)
		return -ENOMEM;

	block = (void *)module + sizeof(*module);

	for (count = 0; count < module->blocks; count++) {

		if (block->size <= 0) {
			dev_err(dsp->dev, "block %d size invalid\n", count);
			return -EINVAL;
		}

		switch (block->type) {
		case SST_BYT_IRAM:
			mod->offset = block->ram_offset +
					    dsp->addr.iram_offset;
			mod->type = SST_MEM_IRAM;
			break;
		case SST_BYT_DRAM:
			mod->offset = block->ram_offset +
					    dsp->addr.dram_offset;
			mod->type = SST_MEM_DRAM;
			break;
		case SST_BYT_CACHE:
			mod->offset = block->ram_offset +
					    (dsp->addr.fw_ext - dsp->addr.lpe);
			mod->type = SST_MEM_CACHE;
			break;
		default:
			dev_err(dsp->dev, "wrong ram type 0x%x in block0x%x\n",
				block->type, count);
			return -EINVAL;
		}

		mod->size = block->size;
		mod->data = (void *)block + sizeof(*block);

		sst_module_alloc_blocks(mod);

		block = (void *)block + sizeof(*block) + block->size;
	}
	return 0;
}

__attribute__((used)) static int sst_byt_parse_fw_image(struct sst_fw *sst_fw)
{
	struct fw_header *header;
	struct sst_byt_fw_module_header *module;
	struct sst_dsp *dsp = sst_fw->dsp;
	int ret, count;

	/* Read the header information from the data pointer */
	header = (struct fw_header *)sst_fw->dma_buf;

	/* verify FW */
	if ((strncmp(header->signature, SST_BYT_FW_SIGN, 4) != 0) ||
	    (sst_fw->size != header->file_size + sizeof(*header))) {
		/* Invalid FW signature */
		dev_err(dsp->dev, "Invalid FW sign/filesize mismatch\n");
		return -EINVAL;
	}

	dev_dbg(dsp->dev,
		"header sign=%4s size=0x%x modules=0x%x fmt=0x%x size=%zu\n",
		header->signature, header->file_size, header->modules,
		header->file_format, sizeof(*header));

	module = (void *)sst_fw->dma_buf + sizeof(*header);
	for (count = 0; count < header->modules; count++) {
		/* module */
		ret = sst_byt_parse_module(dsp, sst_fw, module);
		if (ret < 0) {
			dev_err(dsp->dev, "invalid module %d\n", count);
			return ret;
		}
		module = (void *)module + sizeof(*module) + module->mod_size;
	}

	return 0;
}

__attribute__((used)) static void sst_byt_dump_shim(struct sst_dsp *sst)
{
	int i;
	u64 reg;

	for (i = 0; i <= 0xF0; i += 8) {
		reg = sst_dsp_shim_read64_unlocked(sst, i);
		if (reg)
			dev_dbg(sst->dev, "shim 0x%2.2x value 0x%16.16llx\n",
				i, reg);
	}

	for (i = 0x00; i <= 0xff; i += 4) {
		reg = readl(sst->addr.pci_cfg + i);
		if (reg)
			dev_dbg(sst->dev, "pci 0x%2.2x value 0x%8.8x\n",
				i, (u32)reg);
	}
}

__attribute__((used)) static irqreturn_t sst_byt_irq(int irq, void *context)
{
	struct sst_dsp *sst = (struct sst_dsp *) context;
	u64 isrx;
	irqreturn_t ret = IRQ_NONE;

	spin_lock(&sst->spinlock);

	isrx = sst_dsp_shim_read64_unlocked(sst, SST_ISRX);
	if (isrx & SST_ISRX_DONE) {
		/* ADSP has processed the message request from IA */
		sst_dsp_shim_update_bits64_unlocked(sst, SST_IPCX,
						    SST_BYT_IPCX_DONE, 0);
		ret = IRQ_WAKE_THREAD;
	}
	if (isrx & SST_BYT_ISRX_REQUEST) {
		/* mask message request from ADSP and do processing later */
		sst_dsp_shim_update_bits64_unlocked(sst, SST_IMRX,
						    SST_BYT_IMRX_REQUEST,
						    SST_BYT_IMRX_REQUEST);
		ret = IRQ_WAKE_THREAD;
	}

	spin_unlock(&sst->spinlock);

	return ret;
}

__attribute__((used)) static void sst_byt_boot(struct sst_dsp *sst)
{
	int tries = 10;

	/*
	 * save the physical address of extended firmware block in the first
	 * 4 bytes of the mailbox
	 */
	memcpy_toio(sst->addr.lpe + SST_BYT_MAILBOX_OFFSET,
	       &sst->pdata->fw_base, sizeof(u32));

	/* release stall and wait to unstall */
	sst_dsp_shim_update_bits64(sst, SST_CSR, SST_BYT_CSR_STALL, 0x0);
	while (tries--) {
		if (!(sst_dsp_shim_read64(sst, SST_CSR) &
		      SST_BYT_CSR_PWAITMODE))
			break;
		msleep(100);
	}
	if (tries < 0) {
		dev_err(sst->dev, "unable to start DSP\n");
		sst_byt_dump_shim(sst);
	}
}

__attribute__((used)) static void sst_byt_reset(struct sst_dsp *sst)
{
	/* put DSP into reset, set reset vector and stall */
	sst_dsp_shim_update_bits64(sst, SST_CSR,
		SST_BYT_CSR_RST | SST_BYT_CSR_VECTOR_SEL | SST_BYT_CSR_STALL,
		SST_BYT_CSR_RST | SST_BYT_CSR_VECTOR_SEL | SST_BYT_CSR_STALL);

	udelay(10);

	/* take DSP out of reset and keep stalled for FW loading */
	sst_dsp_shim_update_bits64(sst, SST_CSR, SST_BYT_CSR_RST, 0);
}

__attribute__((used)) static int sst_byt_resource_map(struct sst_dsp *sst, struct sst_pdata *pdata)
{
	sst->addr.lpe_base = pdata->lpe_base;
	sst->addr.lpe = ioremap(pdata->lpe_base, pdata->lpe_size);
	if (!sst->addr.lpe)
		return -ENODEV;

	/* ADSP PCI MMIO config space */
	sst->addr.pci_cfg = ioremap(pdata->pcicfg_base, pdata->pcicfg_size);
	if (!sst->addr.pci_cfg) {
		iounmap(sst->addr.lpe);
		return -ENODEV;
	}

	/* SST Extended FW allocation */
	sst->addr.fw_ext = ioremap(pdata->fw_base, pdata->fw_size);
	if (!sst->addr.fw_ext) {
		iounmap(sst->addr.pci_cfg);
		iounmap(sst->addr.lpe);
		return -ENODEV;
	}

	/* SST Shim */
	sst->addr.shim = sst->addr.lpe + sst->addr.shim_offset;

	sst_dsp_mailbox_init(sst, SST_BYT_MAILBOX_OFFSET + 0x204,
			     SST_BYT_IPC_MAX_PAYLOAD_SIZE,
			     SST_BYT_MAILBOX_OFFSET,
			     SST_BYT_IPC_MAX_PAYLOAD_SIZE);

	sst->irq = pdata->irq;

	return 0;
}

__attribute__((used)) static int sst_byt_init(struct sst_dsp *sst, struct sst_pdata *pdata)
{
	const struct sst_adsp_memregion *region;
	struct device *dev;
	int ret = -ENODEV, i, j, region_count;
	u32 offset, size;

	dev = sst->dev;

	switch (sst->id) {
	case SST_DEV_ID_BYT:
		region = byt_region;
		region_count = ARRAY_SIZE(byt_region);
		sst->addr.iram_offset = SST_BYT_IRAM_OFFSET;
		sst->addr.dram_offset = SST_BYT_DRAM_OFFSET;
		sst->addr.shim_offset = SST_BYT_SHIM_OFFSET;
		break;
	default:
		dev_err(dev, "failed to get mem resources\n");
		return ret;
	}

	ret = sst_byt_resource_map(sst, pdata);
	if (ret < 0) {
		dev_err(dev, "failed to map resources\n");
		return ret;
	}

	ret = dma_coerce_mask_and_coherent(sst->dma_dev, DMA_BIT_MASK(32));
	if (ret)
		return ret;

	/* enable Interrupt from both sides */
	sst_dsp_shim_update_bits64(sst, SST_IMRX, 0x3, 0x0);
	sst_dsp_shim_update_bits64(sst, SST_IMRD, 0x3, 0x0);

	/* register DSP memory blocks - ideally we should get this from ACPI */
	for (i = 0; i < region_count; i++) {
		offset = region[i].start;
		size = (region[i].end - region[i].start) / region[i].blocks;

		/* register individual memory blocks */
		for (j = 0; j < region[i].blocks; j++) {
			sst_mem_block_register(sst, offset, size,
					       region[i].type, NULL, j, sst);
			offset += size;
		}
	}

	return 0;
}

__attribute__((used)) static void sst_byt_free(struct sst_dsp *sst)
{
	sst_mem_block_unregister_all(sst);
	iounmap(sst->addr.lpe);
	iounmap(sst->addr.pci_cfg);
	iounmap(sst->addr.fw_ext);
}

