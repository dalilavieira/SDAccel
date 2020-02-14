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
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct scsi_host_template {int dummy; } ;
struct scatterlist {int dummy; } ;
struct pci_esp_priv {int dma_status; struct esp* esp; } ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int /*<<< orphan*/  irq; int /*<<< orphan*/  dev; } ;
struct esp_cmd_entry {int /*<<< orphan*/  flags; } ;
struct esp {int sreg; int config2; int scsi_id; int num_tags; int config4; int scsi_id_mask; int cfreq; struct Scsi_Host* host; scalar_t__ regs; int /*<<< orphan*/  command_block_dma; int /*<<< orphan*/  command_block; scalar_t__ dma_regs; int /*<<< orphan*/  flags; int /*<<< orphan*/ * ops; struct pci_dev* dev; struct esp_cmd_entry* active_cmd; } ;
struct Scsi_Host {int this_id; int max_id; int /*<<< orphan*/  io_port; int /*<<< orphan*/  unique_id; int /*<<< orphan*/  n_io_port; int /*<<< orphan*/  irq; } ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int DC390_EEPROM_LEN ; 
 int DC390_EEPROM_READ ; 
 size_t DC390_EE_ADAPT_SCSI_ID ; 
 size_t DC390_EE_MODE2 ; 
 int DC390_EE_MODE2_ACTIVE_NEGATION ; 
 size_t DC390_EE_TAG_CMD_NUM ; 
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int /*<<< orphan*/  DRV_MODULE_NAME ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ESP_CMD_DMA ; 
 int /*<<< orphan*/  ESP_CMD_FLAG_RESIDUAL ; 
 int ESP_CONFIG2_FENAB ; 
 int ESP_CONFIG4_RADE ; 
 int ESP_CONFIG4_RAE ; 
 int ESP_DIP ; 
 unsigned long ESP_DMA_CMD ; 
 int ESP_DMA_CMD_ABORT ; 
 int ESP_DMA_CMD_BLAST ; 
 int ESP_DMA_CMD_DIR ; 
 int ESP_DMA_CMD_IDLE ; 
 int ESP_DMA_CMD_MASK ; 
 int ESP_DMA_CMD_START ; 
 unsigned long ESP_DMA_SPA ; 
 unsigned long ESP_DMA_STATUS ; 
 int ESP_DMA_STAT_ABORT ; 
 int ESP_DMA_STAT_BCMPLT ; 
 int ESP_DMA_STAT_DONE ; 
 int ESP_DMA_STAT_ERROR ; 
 int ESP_DMA_STAT_SCSIINT ; 
 unsigned long ESP_DMA_STC ; 
 int ESP_DOP ; 
 unsigned long ESP_FFLAGS ; 
 int ESP_FF_FBYTES ; 
 int /*<<< orphan*/  ESP_FLAG_USE_FIFO ; 
 int ESP_STAT_PMASK ; 
 unsigned long ESP_TCHI ; 
 unsigned long ESP_TCLOW ; 
 unsigned long ESP_TCMED ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  KERN_ERR ; 
 int /*<<< orphan*/  KERN_INFO ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 scalar_t__ am53c974_fenab ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/  dev_printk (int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  esp_dma_log (char*,...) ; 
 int /*<<< orphan*/  free_irq (int /*<<< orphan*/ ,struct esp*) ; 
 int ioread8 (scalar_t__) ; 
 void iowrite32 (int,scalar_t__) ; 
 int /*<<< orphan*/  iowrite8 (int,scalar_t__) ; 
 int /*<<< orphan*/  kfree (struct pci_esp_priv*) ; 
 struct pci_esp_priv* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_alloc_consistent (struct pci_dev*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pci_disable_device (struct pci_dev*) ; 
 scalar_t__ pci_enable_device (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_esp_ops ; 
 int /*<<< orphan*/  pci_free_consistent (struct pci_dev*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct pci_esp_priv* pci_get_drvdata (struct pci_dev*) ; 
 scalar_t__ pci_iomap (struct pci_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_iounmap (struct pci_dev*,scalar_t__) ; 
 int pci_map_sg (struct pci_dev*,struct scatterlist*,int,int) ; 
 int /*<<< orphan*/  pci_map_single (struct pci_dev*,void*,size_t,int) ; 
 int /*<<< orphan*/  pci_read_config_byte (struct pci_dev*,int,int*) ; 
 int /*<<< orphan*/  pci_release_regions (struct pci_dev*) ; 
 scalar_t__ pci_request_regions (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_resource_len (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_resource_start (struct pci_dev*,int /*<<< orphan*/ ) ; 
 scalar_t__ pci_set_dma_mask (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_set_drvdata (struct pci_dev*,struct pci_esp_priv*) ; 
 int /*<<< orphan*/  pci_set_master (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_unmap_sg (struct pci_dev*,struct scatterlist*,int,int) ; 
 int /*<<< orphan*/  pci_unmap_single (struct pci_dev*,int /*<<< orphan*/ ,size_t,int) ; 
 int /*<<< orphan*/  pci_write_config_byte (struct pci_dev*,int,int) ; 
 int request_irq (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct esp*) ; 
 int /*<<< orphan*/  scsi_esp_cmd (struct esp*,int) ; 
 int /*<<< orphan*/  scsi_esp_intr ; 
 int scsi_esp_register (struct esp*,int /*<<< orphan*/ *) ; 
 struct scsi_host_template scsi_esp_template ; 
 int /*<<< orphan*/  scsi_esp_unregister (struct esp*) ; 
 struct Scsi_Host* scsi_host_alloc (struct scsi_host_template*,int) ; 
 int /*<<< orphan*/  scsi_host_put (struct Scsi_Host*) ; 
 struct esp* shost_priv (struct Scsi_Host*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline struct pci_esp_priv *pci_esp_get_priv(struct esp *esp)
{
	struct pci_dev *pdev = esp->dev;

	return pci_get_drvdata(pdev);
}

__attribute__((used)) static void pci_esp_write8(struct esp *esp, u8 val, unsigned long reg)
{
	iowrite8(val, esp->regs + (reg * 4UL));
}

__attribute__((used)) static u8 pci_esp_read8(struct esp *esp, unsigned long reg)
{
	return ioread8(esp->regs + (reg * 4UL));
}

__attribute__((used)) static void pci_esp_write32(struct esp *esp, u32 val, unsigned long reg)
{
	return iowrite32(val, esp->regs + (reg * 4UL));
}

__attribute__((used)) static dma_addr_t pci_esp_map_single(struct esp *esp, void *buf,
				     size_t sz, int dir)
{
	return pci_map_single(esp->dev, buf, sz, dir);
}

__attribute__((used)) static int pci_esp_map_sg(struct esp *esp, struct scatterlist *sg,
			  int num_sg, int dir)
{
	return pci_map_sg(esp->dev, sg, num_sg, dir);
}

__attribute__((used)) static void pci_esp_unmap_single(struct esp *esp, dma_addr_t addr,
				 size_t sz, int dir)
{
	pci_unmap_single(esp->dev, addr, sz, dir);
}

__attribute__((used)) static void pci_esp_unmap_sg(struct esp *esp, struct scatterlist *sg,
			     int num_sg, int dir)
{
	pci_unmap_sg(esp->dev, sg, num_sg, dir);
}

__attribute__((used)) static int pci_esp_irq_pending(struct esp *esp)
{
	struct pci_esp_priv *pep = pci_esp_get_priv(esp);

	pep->dma_status = pci_esp_read8(esp, ESP_DMA_STATUS);
	esp_dma_log("dma intr dreg[%02x]\n", pep->dma_status);

	if (pep->dma_status & (ESP_DMA_STAT_ERROR |
			       ESP_DMA_STAT_ABORT |
			       ESP_DMA_STAT_DONE |
			       ESP_DMA_STAT_SCSIINT))
		return 1;

	return 0;
}

__attribute__((used)) static void pci_esp_reset_dma(struct esp *esp)
{
	/* Nothing to do ? */
}

__attribute__((used)) static void pci_esp_dma_drain(struct esp *esp)
{
	u8 resid;
	int lim = 1000;


	if ((esp->sreg & ESP_STAT_PMASK) == ESP_DOP ||
	    (esp->sreg & ESP_STAT_PMASK) == ESP_DIP)
		/* Data-In or Data-Out, nothing to be done */
		return;

	while (--lim > 0) {
		resid = pci_esp_read8(esp, ESP_FFLAGS) & ESP_FF_FBYTES;
		if (resid <= 1)
			break;
		cpu_relax();
	}

	/*
	 * When there is a residual BCMPLT will never be set
	 * (obviously). But we still have to issue the BLAST
	 * command, otherwise the data will not being transferred.
	 * But we'll never know when the BLAST operation is
	 * finished. So check for some time and give up eventually.
	 */
	lim = 1000;
	pci_esp_write8(esp, ESP_DMA_CMD_DIR | ESP_DMA_CMD_BLAST, ESP_DMA_CMD);
	while (pci_esp_read8(esp, ESP_DMA_STATUS) & ESP_DMA_STAT_BCMPLT) {
		if (--lim == 0)
			break;
		cpu_relax();
	}
	pci_esp_write8(esp, ESP_DMA_CMD_DIR | ESP_DMA_CMD_IDLE, ESP_DMA_CMD);
	esp_dma_log("DMA blast done (%d tries, %d bytes left)\n", lim, resid);
	/* BLAST residual handling is currently untested */
	if (WARN_ON_ONCE(resid == 1)) {
		struct esp_cmd_entry *ent = esp->active_cmd;

		ent->flags |= ESP_CMD_FLAG_RESIDUAL;
	}
}

__attribute__((used)) static void pci_esp_dma_invalidate(struct esp *esp)
{
	struct pci_esp_priv *pep = pci_esp_get_priv(esp);

	esp_dma_log("invalidate DMA\n");

	pci_esp_write8(esp, ESP_DMA_CMD_IDLE, ESP_DMA_CMD);
	pep->dma_status = 0;
}

__attribute__((used)) static int pci_esp_dma_error(struct esp *esp)
{
	struct pci_esp_priv *pep = pci_esp_get_priv(esp);

	if (pep->dma_status & ESP_DMA_STAT_ERROR) {
		u8 dma_cmd = pci_esp_read8(esp, ESP_DMA_CMD);

		if ((dma_cmd & ESP_DMA_CMD_MASK) == ESP_DMA_CMD_START)
			pci_esp_write8(esp, ESP_DMA_CMD_ABORT, ESP_DMA_CMD);

		return 1;
	}
	if (pep->dma_status & ESP_DMA_STAT_ABORT) {
		pci_esp_write8(esp, ESP_DMA_CMD_IDLE, ESP_DMA_CMD);
		pep->dma_status = pci_esp_read8(esp, ESP_DMA_CMD);
		return 1;
	}
	return 0;
}

__attribute__((used)) static void pci_esp_send_dma_cmd(struct esp *esp, u32 addr, u32 esp_count,
				 u32 dma_count, int write, u8 cmd)
{
	struct pci_esp_priv *pep = pci_esp_get_priv(esp);
	u32 val = 0;

	BUG_ON(!(cmd & ESP_CMD_DMA));

	pep->dma_status = 0;

	/* Set DMA engine to IDLE */
	if (write)
		/* DMA write direction logic is inverted */
		val |= ESP_DMA_CMD_DIR;
	pci_esp_write8(esp, ESP_DMA_CMD_IDLE | val, ESP_DMA_CMD);

	pci_esp_write8(esp, (esp_count >> 0) & 0xff, ESP_TCLOW);
	pci_esp_write8(esp, (esp_count >> 8) & 0xff, ESP_TCMED);
	if (esp->config2 & ESP_CONFIG2_FENAB)
		pci_esp_write8(esp, (esp_count >> 16) & 0xff, ESP_TCHI);

	pci_esp_write32(esp, esp_count, ESP_DMA_STC);
	pci_esp_write32(esp, addr, ESP_DMA_SPA);

	esp_dma_log("start dma addr[%x] count[%d:%d]\n",
		    addr, esp_count, dma_count);

	scsi_esp_cmd(esp, cmd);
	/* Send DMA Start command */
	pci_esp_write8(esp, ESP_DMA_CMD_START | val, ESP_DMA_CMD);
}

__attribute__((used)) static u32 pci_esp_dma_length_limit(struct esp *esp, u32 dma_addr, u32 dma_len)
{
	int dma_limit = 16;
	u32 base, end;

	/*
	 * If CONFIG2_FENAB is set we can
	 * handle up to 24 bit addresses
	 */
	if (esp->config2 & ESP_CONFIG2_FENAB)
		dma_limit = 24;

	if (dma_len > (1U << dma_limit))
		dma_len = (1U << dma_limit);

	/*
	 * Prevent crossing a 24-bit address boundary.
	 */
	base = dma_addr & ((1U << 24) - 1U);
	end = base + dma_len;
	if (end > (1U << 24))
		end = (1U <<24);
	dma_len = end - base;

	return dma_len;
}

__attribute__((used)) static void dc390_eeprom_prepare_read(struct pci_dev *pdev, u8 cmd)
{
	u8 carry_flag = 1, j = 0x80, bval;
	int i;

	for (i = 0; i < 9; i++) {
		if (carry_flag) {
			pci_write_config_byte(pdev, 0x80, 0x40);
			bval = 0xc0;
		} else
			bval = 0x80;

		udelay(160);
		pci_write_config_byte(pdev, 0x80, bval);
		udelay(160);
		pci_write_config_byte(pdev, 0x80, 0);
		udelay(160);

		carry_flag = (cmd & j) ? 1 : 0;
		j >>= 1;
	}
}

__attribute__((used)) static u16 dc390_eeprom_get_data(struct pci_dev *pdev)
{
	int i;
	u16 wval = 0;
	u8 bval;

	for (i = 0; i < 16; i++) {
		wval <<= 1;

		pci_write_config_byte(pdev, 0x80, 0x80);
		udelay(160);
		pci_write_config_byte(pdev, 0x80, 0x40);
		udelay(160);
		pci_read_config_byte(pdev, 0x00, &bval);

		if (bval == 0x22)
			wval |= 1;
	}

	return wval;
}

__attribute__((used)) static void dc390_read_eeprom(struct pci_dev *pdev, u16 *ptr)
{
	u8 cmd = DC390_EEPROM_READ, i;

	for (i = 0; i < DC390_EEPROM_LEN; i++) {
		pci_write_config_byte(pdev, 0xc0, 0);
		udelay(160);

		dc390_eeprom_prepare_read(pdev, cmd++);
		*ptr++ = dc390_eeprom_get_data(pdev);

		pci_write_config_byte(pdev, 0x80, 0);
		pci_write_config_byte(pdev, 0x80, 0);
		udelay(160);
	}
}

__attribute__((used)) static void dc390_check_eeprom(struct esp *esp)
{
	u8 EEbuf[128];
	u16 *ptr = (u16 *)EEbuf, wval = 0;
	int i;

	dc390_read_eeprom((struct pci_dev *)esp->dev, ptr);

	for (i = 0; i < DC390_EEPROM_LEN; i++, ptr++)
		wval += *ptr;

	/* no Tekram EEprom found */
	if (wval != 0x1234) {
		struct pci_dev *pdev = esp->dev;
		dev_printk(KERN_INFO, &pdev->dev,
			   "No valid Tekram EEprom found\n");
		return;
	}
	esp->scsi_id = EEbuf[DC390_EE_ADAPT_SCSI_ID];
	esp->num_tags = 2 << EEbuf[DC390_EE_TAG_CMD_NUM];
	if (EEbuf[DC390_EE_MODE2] & DC390_EE_MODE2_ACTIVE_NEGATION)
		esp->config4 |= ESP_CONFIG4_RADE | ESP_CONFIG4_RAE;
}

__attribute__((used)) static int pci_esp_probe_one(struct pci_dev *pdev,
			      const struct pci_device_id *id)
{
	struct scsi_host_template *hostt = &scsi_esp_template;
	int err = -ENODEV;
	struct Scsi_Host *shost;
	struct esp *esp;
	struct pci_esp_priv *pep;

	if (pci_enable_device(pdev)) {
		dev_printk(KERN_INFO, &pdev->dev, "cannot enable device\n");
		return -ENODEV;
	}

	if (pci_set_dma_mask(pdev, DMA_BIT_MASK(32))) {
		dev_printk(KERN_INFO, &pdev->dev,
			   "failed to set 32bit DMA mask\n");
		goto fail_disable_device;
	}

	shost = scsi_host_alloc(hostt, sizeof(struct esp));
	if (!shost) {
		dev_printk(KERN_INFO, &pdev->dev,
			   "failed to allocate scsi host\n");
		err = -ENOMEM;
		goto fail_disable_device;
	}

	pep = kzalloc(sizeof(struct pci_esp_priv), GFP_KERNEL);
	if (!pep) {
		dev_printk(KERN_INFO, &pdev->dev,
			   "failed to allocate esp_priv\n");
		err = -ENOMEM;
		goto fail_host_alloc;
	}

	esp = shost_priv(shost);
	esp->host = shost;
	esp->dev = pdev;
	esp->ops = &pci_esp_ops;
	/*
	 * The am53c974 HBA has a design flaw of generating
	 * spurious DMA completion interrupts when using
	 * DMA for command submission.
	 */
	esp->flags |= ESP_FLAG_USE_FIFO;
	/*
	 * Enable CONFIG2_FENAB to allow for large DMA transfers
	 */
	if (am53c974_fenab)
		esp->config2 |= ESP_CONFIG2_FENAB;

	pep->esp = esp;

	if (pci_request_regions(pdev, DRV_MODULE_NAME)) {
		dev_printk(KERN_ERR, &pdev->dev,
			   "pci memory selection failed\n");
		goto fail_priv_alloc;
	}

	esp->regs = pci_iomap(pdev, 0, pci_resource_len(pdev, 0));
	if (!esp->regs) {
		dev_printk(KERN_ERR, &pdev->dev, "pci I/O map failed\n");
		err = -EINVAL;
		goto fail_release_regions;
	}
	esp->dma_regs = esp->regs;

	pci_set_master(pdev);

	esp->command_block = pci_alloc_consistent(pdev, 16,
						  &esp->command_block_dma);
	if (!esp->command_block) {
		dev_printk(KERN_ERR, &pdev->dev,
			   "failed to allocate command block\n");
		err = -ENOMEM;
		goto fail_unmap_regs;
	}

	pci_set_drvdata(pdev, pep);

	err = request_irq(pdev->irq, scsi_esp_intr, IRQF_SHARED,
			  DRV_MODULE_NAME, esp);
	if (err < 0) {
		dev_printk(KERN_ERR, &pdev->dev, "failed to register IRQ\n");
		goto fail_unmap_command_block;
	}

	esp->scsi_id = 7;
	dc390_check_eeprom(esp);

	shost->this_id = esp->scsi_id;
	shost->max_id = 8;
	shost->irq = pdev->irq;
	shost->io_port = pci_resource_start(pdev, 0);
	shost->n_io_port = pci_resource_len(pdev, 0);
	shost->unique_id = shost->io_port;
	esp->scsi_id_mask = (1 << esp->scsi_id);
	/* Assume 40MHz clock */
	esp->cfreq = 40000000;

	err = scsi_esp_register(esp, &pdev->dev);
	if (err)
		goto fail_free_irq;

	return 0;

fail_free_irq:
	free_irq(pdev->irq, esp);
fail_unmap_command_block:
	pci_set_drvdata(pdev, NULL);
	pci_free_consistent(pdev, 16, esp->command_block,
			    esp->command_block_dma);
fail_unmap_regs:
	pci_iounmap(pdev, esp->regs);
fail_release_regions:
	pci_release_regions(pdev);
fail_priv_alloc:
	kfree(pep);
fail_host_alloc:
	scsi_host_put(shost);
fail_disable_device:
	pci_disable_device(pdev);

	return err;
}

__attribute__((used)) static void pci_esp_remove_one(struct pci_dev *pdev)
{
	struct pci_esp_priv *pep = pci_get_drvdata(pdev);
	struct esp *esp = pep->esp;

	scsi_esp_unregister(esp);
	free_irq(pdev->irq, esp);
	pci_set_drvdata(pdev, NULL);
	pci_free_consistent(pdev, 16, esp->command_block,
			    esp->command_block_dma);
	pci_iounmap(pdev, esp->regs);
	pci_release_regions(pdev);
	pci_disable_device(pdev);
	kfree(pep);

	scsi_host_put(esp->host);
}

