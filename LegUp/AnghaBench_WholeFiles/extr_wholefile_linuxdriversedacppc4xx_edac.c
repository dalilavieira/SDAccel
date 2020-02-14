#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_8__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  umode_t ;
typedef  int /*<<< orphan*/  u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct TYPE_19__ {scalar_t__ base; } ;
struct TYPE_18__ {int ded; int sec; } ;
struct ppc4xx_edac_pdata {TYPE_3__ dcr_host; TYPE_2__ irqs; } ;
struct ppc4xx_ecc_status {int ecces; int besr; int wmirq; int bearl; int bearh; } ;
struct TYPE_21__ {struct device_node* of_node; } ;
struct platform_device {TYPE_8__ dev; } ;
struct mem_ctl_info {char* dev_name; unsigned int nr_csrows; int edac_cap; int mtype_cap; int edac_ctl_cap; void (* edac_check ) (struct mem_ctl_info*) ;TYPE_8__* pdev; struct ppc4xx_edac_pdata* pvt_info; int /*<<< orphan*/ * ctl_page_to_phys; int /*<<< orphan*/  ctl_name; int /*<<< orphan*/  mod_name; void* scrub_mode; void* scrub_cap; struct csrow_info** csrows; } ;
struct file_operations {int dummy; } ;
struct edac_mc_layer {int is_virt_csrow; int /*<<< orphan*/  size; int /*<<< orphan*/  type; } ;
struct dimm_info {int nr_pages; int grain; int mtype; int dtype; int edac_mode; } ;
struct device_node {char* full_name; } ;
struct dentry {int dummy; } ;
struct csrow_info {int nr_channels; TYPE_1__** channels; } ;
typedef  int /*<<< orphan*/  message ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum mem_type { ____Placeholder_mem_type } mem_type ;
typedef  enum edac_type { ____Placeholder_edac_type } edac_type ;
typedef  enum dev_type { ____Placeholder_dev_type } dev_type ;
typedef  TYPE_3__ dcr_host_t ;
struct TYPE_20__ {int /*<<< orphan*/  compatible; } ;
struct TYPE_17__ {struct dimm_info* dimm; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (struct edac_mc_layer*) ; 
 int /*<<< orphan*/  DCR_MAP_OK (TYPE_3__) ; 
 int DEV_UNKNOWN ; 
 int DEV_X2 ; 
 int DEV_X4 ; 
 int EDAC_EC ; 
 int EDAC_FLAG_EC ; 
 int EDAC_FLAG_NONE ; 
 int EDAC_FLAG_SECDED ; 
 int /*<<< orphan*/  EDAC_MC_LAYER_CHANNEL ; 
 int /*<<< orphan*/  EDAC_MC_LAYER_CHIP_SELECT ; 
 int EDAC_NONE ; 
 scalar_t__ EDAC_OPSTATE_INT ; 
 int EDAC_SECDED ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  HW_EVENT_ERR_CORRECTED ; 
 int /*<<< orphan*/  HW_EVENT_ERR_UNCORRECTED ; 
 int /*<<< orphan*/  INTMAP_ECCDED_INDEX ; 
 int /*<<< orphan*/  INTMAP_ECCSEC_INDEX ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  KERN_ERR ; 
 int /*<<< orphan*/  KERN_INFO ; 
 int /*<<< orphan*/  KERN_NOTICE ; 
 int MEM_DDR ; 
 int MEM_DDR2 ; 
 int MEM_FLAG_DDR ; 
 int MEM_FLAG_DDR2 ; 
 int MEM_FLAG_RDDR ; 
 int MEM_FLAG_RDDR2 ; 
 int MEM_RDDR ; 
 int MEM_RDDR2 ; 
 int MEM_UNKNOWN ; 
 int const PAGE_MASK ; 
 int const PAGE_SHIFT ; 
 int PPC4XX_EDAC_MESSAGE_SIZE ; 
 int /*<<< orphan*/  PPC4XX_EDAC_MODULE_NAME ; 
 void* SCRUB_NONE ; 
 void* SCRUB_SW_SRC ; 
 unsigned int SDRAM_BEARH ; 
 unsigned int SDRAM_BEARL ; 
 unsigned int SDRAM_BESR ; 
 int SDRAM_BESR_M0ET_MASK ; 
 int SDRAM_BESR_M0ET_NONE ; 
 unsigned int SDRAM_BESR_M0ID_DECODE (int) ; 
 int SDRAM_BESR_M0RW_MASK ; 
 int SDRAM_BESR_M0RW_READ ; 
 int SDRAM_BESR_MASK ; 
 scalar_t__ SDRAM_DCR_ADDR_OFFSET ; 
 scalar_t__ SDRAM_DCR_DATA_OFFSET ; 
 unsigned int SDRAM_DCR_RESOURCE_LEN ; 
 unsigned int SDRAM_ECCES ; 
 int SDRAM_ECCES_BK0ER ; 
 int SDRAM_ECCES_BK1ER ; 
 int SDRAM_ECCES_BNCE_ENCODE (unsigned int) ; 
 int SDRAM_ECCES_CE ; 
#define  SDRAM_ECCES_CKBER_32_ECC_0_3 149 
#define  SDRAM_ECCES_CKBER_32_ECC_0_8 148 
#define  SDRAM_ECCES_CKBER_32_ECC_4_8 147 
 int SDRAM_ECCES_CKBER_MASK ; 
#define  SDRAM_ECCES_CKBER_NONE 146 
 int SDRAM_ECCES_MASK ; 
 int SDRAM_ECCES_UE ; 
 int SDRAM_MBCF_BE_ENABLE ; 
 int SDRAM_MBCF_BE_MASK ; 
#define  SDRAM_MBCF_SZ_128MB 145 
#define  SDRAM_MBCF_SZ_16MB 144 
#define  SDRAM_MBCF_SZ_1GB 143 
#define  SDRAM_MBCF_SZ_256MB 142 
#define  SDRAM_MBCF_SZ_2GB 141 
#define  SDRAM_MBCF_SZ_32MB 140 
#define  SDRAM_MBCF_SZ_4GB 139 
#define  SDRAM_MBCF_SZ_4MB 138 
#define  SDRAM_MBCF_SZ_512MB 137 
#define  SDRAM_MBCF_SZ_64MB 136 
#define  SDRAM_MBCF_SZ_8GB 135 
#define  SDRAM_MBCF_SZ_8MB 134 
 int /*<<< orphan*/  SDRAM_MBCF_SZ_DECODE (int) ; 
 int SDRAM_MBCF_SZ_MASK ; 
 int SDRAM_MBCF_SZ_TO_PAGES (int) ; 
 unsigned int SDRAM_MBXCF (int) ; 
 unsigned int SDRAM_MCOPT1 ; 
#define  SDRAM_MCOPT1_DDR1_TYPE 133 
#define  SDRAM_MCOPT1_DDR2_TYPE 132 
 int SDRAM_MCOPT1_DDR_TYPE_MASK ; 
#define  SDRAM_MCOPT1_MCHK_CHK 131 
#define  SDRAM_MCOPT1_MCHK_CHK_REP 130 
 int SDRAM_MCOPT1_MCHK_MASK ; 
 int SDRAM_MCOPT1_MCHK_NON ; 
 int SDRAM_MCOPT1_RDEN ; 
 int SDRAM_MCOPT1_RDEN_MASK ; 
#define  SDRAM_MCOPT1_WDTH_16 129 
#define  SDRAM_MCOPT1_WDTH_32 128 
 int SDRAM_MCOPT1_WDTH_MASK ; 
 unsigned int SDRAM_PLB_M0ID_FIRST ; 
 unsigned int SDRAM_PLB_M0ID_LAST ; 
 unsigned int SDRAM_WMIRQ ; 
 int SDRAM_WMIRQ_MASK ; 
 int __mfdcri (scalar_t__,scalar_t__,unsigned int) ; 
 void __mtdcri (scalar_t__,scalar_t__,unsigned int,int) ; 
 TYPE_3__ dcr_map (struct device_node const*,unsigned int,unsigned int) ; 
 unsigned int dcr_resource_len (struct device_node const*,int /*<<< orphan*/ ) ; 
 unsigned int dcr_resource_start (struct device_node const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dcr_unmap (TYPE_3__,unsigned int) ; 
 struct mem_ctl_info* dev_get_drvdata (TYPE_8__*) ; 
 int /*<<< orphan*/  dev_set_drvdata (TYPE_8__*,struct mem_ctl_info*) ; 
 scalar_t__ edac_mc_add_mc (struct mem_ctl_info*) ; 
 struct mem_ctl_info* edac_mc_alloc (int,int /*<<< orphan*/ ,struct edac_mc_layer*,int) ; 
 int /*<<< orphan*/  edac_mc_del_mc (TYPE_8__*) ; 
 int /*<<< orphan*/  edac_mc_free (struct mem_ctl_info*) ; 
 int /*<<< orphan*/  edac_mc_handle_error (int /*<<< orphan*/ ,struct mem_ctl_info*,int,unsigned long const,unsigned long const,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,char*,char*) ; 
 scalar_t__ edac_op_state ; 
 int /*<<< orphan*/  free_irq (int,struct mem_ctl_info*) ; 
 int irq_of_parse_and_map (struct device_node*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_device_is_compatible (struct device_node const*,char*) ; 
 int /*<<< orphan*/ * of_match_device (TYPE_5__*,TYPE_8__*) ; 
 TYPE_5__* ppc4xx_edac_match ; 
 int /*<<< orphan*/  ppc4xx_edac_mc_printk (int /*<<< orphan*/ ,struct mem_ctl_info*,char*,...) ; 
 int /*<<< orphan*/  ppc4xx_edac_nr_chans ; 
 int /*<<< orphan*/  ppc4xx_edac_nr_csrows ; 
 int /*<<< orphan*/  ppc4xx_edac_printk (int /*<<< orphan*/ ,char*,...) ; 
 char** ppc4xx_plb_masters ; 
 int request_irq (int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct mem_ctl_info*) ; 
 int snprintf (char*,size_t,char*,...) ; 

__attribute__((used)) static inline int edac_debugfs_init(void)					{ return -ENODEV; }

__attribute__((used)) static inline void edac_debugfs_exit(void)					{ }

__attribute__((used)) static inline int edac_create_debugfs_nodes(struct mem_ctl_info *mci)		{ return 0; }

__attribute__((used)) static inline struct dentry *edac_debugfs_create_dir(const char *dirname)	{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_dir_at(const char *dirname, struct dentry *parent)		{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_file(const char *name, umode_t mode, struct dentry *parent,
			 void *data, const struct file_operations *fops)	{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_x8(const char *name, umode_t mode,
		       struct dentry *parent, u8 *value)			{ return NULL; }

__attribute__((used)) static inline struct dentry *
edac_debugfs_create_x16(const char *name, umode_t mode,
		       struct dentry *parent, u16 *value)			{ return NULL; }

__attribute__((used)) static inline u32
mfsdram(const dcr_host_t *dcr_host, unsigned int idcr_n)
{
	return __mfdcri(dcr_host->base + SDRAM_DCR_ADDR_OFFSET,
			dcr_host->base + SDRAM_DCR_DATA_OFFSET,
			idcr_n);
}

__attribute__((used)) static inline void
mtsdram(const dcr_host_t *dcr_host, unsigned int idcr_n, u32 value)
{
	return __mtdcri(dcr_host->base + SDRAM_DCR_ADDR_OFFSET,
			dcr_host->base + SDRAM_DCR_DATA_OFFSET,
			idcr_n,
			value);
}

__attribute__((used)) static bool
ppc4xx_edac_check_bank_error(const struct ppc4xx_ecc_status *status,
			     unsigned int bank)
{
	switch (bank) {
	case 0:
		return status->ecces & SDRAM_ECCES_BK0ER;
	case 1:
		return status->ecces & SDRAM_ECCES_BK1ER;
	default:
		return false;
	}
}

__attribute__((used)) static int
ppc4xx_edac_generate_bank_message(const struct mem_ctl_info *mci,
				  const struct ppc4xx_ecc_status *status,
				  char *buffer,
				  size_t size)
{
	int n, total = 0;
	unsigned int row, rows;

	n = snprintf(buffer, size, "%s: Banks: ", mci->dev_name);

	if (n < 0 || n >= size)
		goto fail;

	buffer += n;
	size -= n;
	total += n;

	for (rows = 0, row = 0; row < mci->nr_csrows; row++) {
		if (ppc4xx_edac_check_bank_error(status, row)) {
			n = snprintf(buffer, size, "%s%u",
					(rows++ ? ", " : ""), row);

			if (n < 0 || n >= size)
				goto fail;

			buffer += n;
			size -= n;
			total += n;
		}
	}

	n = snprintf(buffer, size, "%s; ", rows ? "" : "None");

	if (n < 0 || n >= size)
		goto fail;

	buffer += n;
	size -= n;
	total += n;

 fail:
	return total;
}

__attribute__((used)) static int
ppc4xx_edac_generate_checkbit_message(const struct mem_ctl_info *mci,
				      const struct ppc4xx_ecc_status *status,
				      char *buffer,
				      size_t size)
{
	const struct ppc4xx_edac_pdata *pdata = mci->pvt_info;
	const char *ckber = NULL;

	switch (status->ecces & SDRAM_ECCES_CKBER_MASK) {
	case SDRAM_ECCES_CKBER_NONE:
		ckber = "None";
		break;
	case SDRAM_ECCES_CKBER_32_ECC_0_3:
		ckber = "ECC0:3";
		break;
	case SDRAM_ECCES_CKBER_32_ECC_4_8:
		switch (mfsdram(&pdata->dcr_host, SDRAM_MCOPT1) &
			SDRAM_MCOPT1_WDTH_MASK) {
		case SDRAM_MCOPT1_WDTH_16:
			ckber = "ECC0:3";
			break;
		case SDRAM_MCOPT1_WDTH_32:
			ckber = "ECC4:8";
			break;
		default:
			ckber = "Unknown";
			break;
		}
		break;
	case SDRAM_ECCES_CKBER_32_ECC_0_8:
		ckber = "ECC0:8";
		break;
	default:
		ckber = "Unknown";
		break;
	}

	return snprintf(buffer, size, "Checkbit Error: %s", ckber);
}

__attribute__((used)) static int
ppc4xx_edac_generate_lane_message(const struct mem_ctl_info *mci,
				  const struct ppc4xx_ecc_status *status,
				  char *buffer,
				  size_t size)
{
	int n, total = 0;
	unsigned int lane, lanes;
	const unsigned int first_lane = 0;
	const unsigned int lane_count = 16;

	n = snprintf(buffer, size, "; Byte Lane Errors: ");

	if (n < 0 || n >= size)
		goto fail;

	buffer += n;
	size -= n;
	total += n;

	for (lanes = 0, lane = first_lane; lane < lane_count; lane++) {
		if ((status->ecces & SDRAM_ECCES_BNCE_ENCODE(lane)) != 0) {
			n = snprintf(buffer, size,
				     "%s%u",
				     (lanes++ ? ", " : ""), lane);

			if (n < 0 || n >= size)
				goto fail;

			buffer += n;
			size -= n;
			total += n;
		}
	}

	n = snprintf(buffer, size, "%s; ", lanes ? "" : "None");

	if (n < 0 || n >= size)
		goto fail;

	buffer += n;
	size -= n;
	total += n;

 fail:
	return total;
}

__attribute__((used)) static int
ppc4xx_edac_generate_ecc_message(const struct mem_ctl_info *mci,
				 const struct ppc4xx_ecc_status *status,
				 char *buffer,
				 size_t size)
{
	int n, total = 0;

	n = ppc4xx_edac_generate_bank_message(mci, status, buffer, size);

	if (n < 0 || n >= size)
		goto fail;

	buffer += n;
	size -= n;
	total += n;

	n = ppc4xx_edac_generate_checkbit_message(mci, status, buffer, size);

	if (n < 0 || n >= size)
		goto fail;

	buffer += n;
	size -= n;
	total += n;

	n = ppc4xx_edac_generate_lane_message(mci, status, buffer, size);

	if (n < 0 || n >= size)
		goto fail;

	buffer += n;
	size -= n;
	total += n;

 fail:
	return total;
}

__attribute__((used)) static int
ppc4xx_edac_generate_plb_message(const struct mem_ctl_info *mci,
				 const struct ppc4xx_ecc_status *status,
				 char *buffer,
				 size_t size)
{
	unsigned int master;
	bool read;

	if ((status->besr & SDRAM_BESR_MASK) == 0)
		return 0;

	if ((status->besr & SDRAM_BESR_M0ET_MASK) == SDRAM_BESR_M0ET_NONE)
		return 0;

	read = ((status->besr & SDRAM_BESR_M0RW_MASK) == SDRAM_BESR_M0RW_READ);

	master = SDRAM_BESR_M0ID_DECODE(status->besr);

	return snprintf(buffer, size,
			"%s error w/ PLB master %u \"%s\"; ",
			(read ? "Read" : "Write"),
			master,
			(((master >= SDRAM_PLB_M0ID_FIRST) &&
			  (master <= SDRAM_PLB_M0ID_LAST)) ?
			 ppc4xx_plb_masters[master] : "UNKNOWN"));
}

__attribute__((used)) static void
ppc4xx_edac_generate_message(const struct mem_ctl_info *mci,
			     const struct ppc4xx_ecc_status *status,
			     char *buffer,
			     size_t size)
{
	int n;

	if (buffer == NULL || size == 0)
		return;

	n = ppc4xx_edac_generate_ecc_message(mci, status, buffer, size);

	if (n < 0 || n >= size)
		return;

	buffer += n;
	size -= n;

	ppc4xx_edac_generate_plb_message(mci, status, buffer, size);
}

__attribute__((used)) static void
ppc4xx_ecc_get_status(const struct mem_ctl_info *mci,
		      struct ppc4xx_ecc_status *status)
{
	const struct ppc4xx_edac_pdata *pdata = mci->pvt_info;
	const dcr_host_t *dcr_host = &pdata->dcr_host;

	status->ecces = mfsdram(dcr_host, SDRAM_ECCES) & SDRAM_ECCES_MASK;
	status->wmirq = mfsdram(dcr_host, SDRAM_WMIRQ) & SDRAM_WMIRQ_MASK;
	status->besr  = mfsdram(dcr_host, SDRAM_BESR)  & SDRAM_BESR_MASK;
	status->bearl = mfsdram(dcr_host, SDRAM_BEARL);
	status->bearh = mfsdram(dcr_host, SDRAM_BEARH);
}

__attribute__((used)) static void
ppc4xx_ecc_clear_status(const struct mem_ctl_info *mci,
			const struct ppc4xx_ecc_status *status)
{
	const struct ppc4xx_edac_pdata *pdata = mci->pvt_info;
	const dcr_host_t *dcr_host = &pdata->dcr_host;

	mtsdram(dcr_host, SDRAM_ECCES,	status->ecces & SDRAM_ECCES_MASK);
	mtsdram(dcr_host, SDRAM_WMIRQ,	status->wmirq & SDRAM_WMIRQ_MASK);
	mtsdram(dcr_host, SDRAM_BESR,	status->besr & SDRAM_BESR_MASK);
	mtsdram(dcr_host, SDRAM_BEARL,	0);
	mtsdram(dcr_host, SDRAM_BEARH,	0);
}

__attribute__((used)) static void
ppc4xx_edac_handle_ce(struct mem_ctl_info *mci,
		      const struct ppc4xx_ecc_status *status)
{
	int row;
	char message[PPC4XX_EDAC_MESSAGE_SIZE];

	ppc4xx_edac_generate_message(mci, status, message, sizeof(message));

	for (row = 0; row < mci->nr_csrows; row++)
		if (ppc4xx_edac_check_bank_error(status, row))
			edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
					     0, 0, 0,
					     row, 0, -1,
					     message, "");
}

__attribute__((used)) static void
ppc4xx_edac_handle_ue(struct mem_ctl_info *mci,
		      const struct ppc4xx_ecc_status *status)
{
	const u64 bear = ((u64)status->bearh << 32 | status->bearl);
	const unsigned long page = bear >> PAGE_SHIFT;
	const unsigned long offset = bear & ~PAGE_MASK;
	int row;
	char message[PPC4XX_EDAC_MESSAGE_SIZE];

	ppc4xx_edac_generate_message(mci, status, message, sizeof(message));

	for (row = 0; row < mci->nr_csrows; row++)
		if (ppc4xx_edac_check_bank_error(status, row))
			edac_mc_handle_error(HW_EVENT_ERR_UNCORRECTED, mci, 1,
					     page, offset, 0,
					     row, 0, -1,
					     message, "");
}

__attribute__((used)) static void
ppc4xx_edac_check(struct mem_ctl_info *mci)
{
#ifdef DEBUG
	static unsigned int count;
#endif
	struct ppc4xx_ecc_status status;

	ppc4xx_ecc_get_status(mci, &status);

#ifdef DEBUG
	if (count++ % 30 == 0)
		ppc4xx_ecc_dump_status(mci, &status);
#endif

	if (status.ecces & SDRAM_ECCES_UE)
		ppc4xx_edac_handle_ue(mci, &status);

	if (status.ecces & SDRAM_ECCES_CE)
		ppc4xx_edac_handle_ce(mci, &status);

	ppc4xx_ecc_clear_status(mci, &status);
}

__attribute__((used)) static irqreturn_t
ppc4xx_edac_isr(int irq, void *dev_id)
{
	struct mem_ctl_info *mci = dev_id;

	ppc4xx_edac_check(mci);

	return IRQ_HANDLED;
}

__attribute__((used)) static enum dev_type ppc4xx_edac_get_dtype(u32 mcopt1)
{
	switch (mcopt1 & SDRAM_MCOPT1_WDTH_MASK) {
	case SDRAM_MCOPT1_WDTH_16:
		return DEV_X2;
	case SDRAM_MCOPT1_WDTH_32:
		return DEV_X4;
	default:
		return DEV_UNKNOWN;
	}
}

__attribute__((used)) static enum mem_type ppc4xx_edac_get_mtype(u32 mcopt1)
{
	bool rden = ((mcopt1 & SDRAM_MCOPT1_RDEN_MASK) == SDRAM_MCOPT1_RDEN);

	switch (mcopt1 & SDRAM_MCOPT1_DDR_TYPE_MASK) {
	case SDRAM_MCOPT1_DDR2_TYPE:
		return rden ? MEM_RDDR2 : MEM_DDR2;
	case SDRAM_MCOPT1_DDR1_TYPE:
		return rden ? MEM_RDDR : MEM_DDR;
	default:
		return MEM_UNKNOWN;
	}
}

__attribute__((used)) static int ppc4xx_edac_init_csrows(struct mem_ctl_info *mci, u32 mcopt1)
{
	const struct ppc4xx_edac_pdata *pdata = mci->pvt_info;
	int status = 0;
	enum mem_type mtype;
	enum dev_type dtype;
	enum edac_type edac_mode;
	int row, j;
	u32 mbxcf, size, nr_pages;

	/* Establish the memory type and width */

	mtype = ppc4xx_edac_get_mtype(mcopt1);
	dtype = ppc4xx_edac_get_dtype(mcopt1);

	/* Establish EDAC mode */

	if (mci->edac_cap & EDAC_FLAG_SECDED)
		edac_mode = EDAC_SECDED;
	else if (mci->edac_cap & EDAC_FLAG_EC)
		edac_mode = EDAC_EC;
	else
		edac_mode = EDAC_NONE;

	/*
	 * Initialize each chip select row structure which correspond
	 * 1:1 with a controller bank/rank.
	 */

	for (row = 0; row < mci->nr_csrows; row++) {
		struct csrow_info *csi = mci->csrows[row];

		/*
		 * Get the configuration settings for this
		 * row/bank/rank and skip disabled banks.
		 */

		mbxcf = mfsdram(&pdata->dcr_host, SDRAM_MBXCF(row));

		if ((mbxcf & SDRAM_MBCF_BE_MASK) != SDRAM_MBCF_BE_ENABLE)
			continue;

		/* Map the bank configuration size setting to pages. */

		size = mbxcf & SDRAM_MBCF_SZ_MASK;

		switch (size) {
		case SDRAM_MBCF_SZ_4MB:
		case SDRAM_MBCF_SZ_8MB:
		case SDRAM_MBCF_SZ_16MB:
		case SDRAM_MBCF_SZ_32MB:
		case SDRAM_MBCF_SZ_64MB:
		case SDRAM_MBCF_SZ_128MB:
		case SDRAM_MBCF_SZ_256MB:
		case SDRAM_MBCF_SZ_512MB:
		case SDRAM_MBCF_SZ_1GB:
		case SDRAM_MBCF_SZ_2GB:
		case SDRAM_MBCF_SZ_4GB:
		case SDRAM_MBCF_SZ_8GB:
			nr_pages = SDRAM_MBCF_SZ_TO_PAGES(size);
			break;
		default:
			ppc4xx_edac_mc_printk(KERN_ERR, mci,
					      "Unrecognized memory bank %d "
					      "size 0x%08x\n",
					      row, SDRAM_MBCF_SZ_DECODE(size));
			status = -EINVAL;
			goto done;
		}

		/*
		 * It's unclear exactly what grain should be set to
		 * here. The SDRAM_ECCES register allows resolution of
		 * an error down to a nibble which would potentially
		 * argue for a grain of '1' byte, even though we only
		 * know the associated address for uncorrectable
		 * errors. This value is not used at present for
		 * anything other than error reporting so getting it
		 * wrong should be of little consequence. Other
		 * possible values would be the PLB width (16), the
		 * page size (PAGE_SIZE) or the memory width (2 or 4).
		 */
		for (j = 0; j < csi->nr_channels; j++) {
			struct dimm_info *dimm = csi->channels[j]->dimm;

			dimm->nr_pages  = nr_pages / csi->nr_channels;
			dimm->grain	= 1;

			dimm->mtype	= mtype;
			dimm->dtype	= dtype;

			dimm->edac_mode	= edac_mode;
		}
	}

 done:
	return status;
}

__attribute__((used)) static int ppc4xx_edac_mc_init(struct mem_ctl_info *mci,
			       struct platform_device *op,
			       const dcr_host_t *dcr_host, u32 mcopt1)
{
	int status = 0;
	const u32 memcheck = (mcopt1 & SDRAM_MCOPT1_MCHK_MASK);
	struct ppc4xx_edac_pdata *pdata = NULL;
	const struct device_node *np = op->dev.of_node;

	if (of_match_device(ppc4xx_edac_match, &op->dev) == NULL)
		return -EINVAL;

	/* Initial driver pointers and private data */

	mci->pdev		= &op->dev;

	dev_set_drvdata(mci->pdev, mci);

	pdata			= mci->pvt_info;

	pdata->dcr_host		= *dcr_host;

	/* Initialize controller capabilities and configuration */

	mci->mtype_cap		= (MEM_FLAG_DDR | MEM_FLAG_RDDR |
				   MEM_FLAG_DDR2 | MEM_FLAG_RDDR2);

	mci->edac_ctl_cap	= (EDAC_FLAG_NONE |
				   EDAC_FLAG_EC |
				   EDAC_FLAG_SECDED);

	mci->scrub_cap		= SCRUB_NONE;
	mci->scrub_mode		= SCRUB_NONE;

	/*
	 * Update the actual capabilites based on the MCOPT1[MCHK]
	 * settings. Scrubbing is only useful if reporting is enabled.
	 */

	switch (memcheck) {
	case SDRAM_MCOPT1_MCHK_CHK:
		mci->edac_cap	= EDAC_FLAG_EC;
		break;
	case SDRAM_MCOPT1_MCHK_CHK_REP:
		mci->edac_cap	= (EDAC_FLAG_EC | EDAC_FLAG_SECDED);
		mci->scrub_mode	= SCRUB_SW_SRC;
		break;
	default:
		mci->edac_cap	= EDAC_FLAG_NONE;
		break;
	}

	/* Initialize strings */

	mci->mod_name		= PPC4XX_EDAC_MODULE_NAME;
	mci->ctl_name		= ppc4xx_edac_match->compatible,
	mci->dev_name		= np->full_name;

	/* Initialize callbacks */

	mci->edac_check		= ppc4xx_edac_check;
	mci->ctl_page_to_phys	= NULL;

	/* Initialize chip select rows */

	status = ppc4xx_edac_init_csrows(mci, mcopt1);

	if (status)
		ppc4xx_edac_mc_printk(KERN_ERR, mci,
				      "Failed to initialize rows!\n");

	return status;
}

__attribute__((used)) static int ppc4xx_edac_register_irq(struct platform_device *op,
				    struct mem_ctl_info *mci)
{
	int status = 0;
	int ded_irq, sec_irq;
	struct ppc4xx_edac_pdata *pdata = mci->pvt_info;
	struct device_node *np = op->dev.of_node;

	ded_irq = irq_of_parse_and_map(np, INTMAP_ECCDED_INDEX);
	sec_irq = irq_of_parse_and_map(np, INTMAP_ECCSEC_INDEX);

	if (!ded_irq || !sec_irq) {
		ppc4xx_edac_mc_printk(KERN_ERR, mci,
				      "Unable to map interrupts.\n");
		status = -ENODEV;
		goto fail;
	}

	status = request_irq(ded_irq,
			     ppc4xx_edac_isr,
			     0,
			     "[EDAC] MC ECCDED",
			     mci);

	if (status < 0) {
		ppc4xx_edac_mc_printk(KERN_ERR, mci,
				      "Unable to request irq %d for ECC DED",
				      ded_irq);
		status = -ENODEV;
		goto fail1;
	}

	status = request_irq(sec_irq,
			     ppc4xx_edac_isr,
			     0,
			     "[EDAC] MC ECCSEC",
			     mci);

	if (status < 0) {
		ppc4xx_edac_mc_printk(KERN_ERR, mci,
				      "Unable to request irq %d for ECC SEC",
				      sec_irq);
		status = -ENODEV;
		goto fail2;
	}

	ppc4xx_edac_mc_printk(KERN_INFO, mci, "ECCDED irq is %d\n", ded_irq);
	ppc4xx_edac_mc_printk(KERN_INFO, mci, "ECCSEC irq is %d\n", sec_irq);

	pdata->irqs.ded = ded_irq;
	pdata->irqs.sec = sec_irq;

	return 0;

 fail2:
	free_irq(sec_irq, mci);

 fail1:
	free_irq(ded_irq, mci);

 fail:
	return status;
}

__attribute__((used)) static int ppc4xx_edac_map_dcrs(const struct device_node *np,
				dcr_host_t *dcr_host)
{
	unsigned int dcr_base, dcr_len;

	if (np == NULL || dcr_host == NULL)
		return -EINVAL;

	/* Get the DCR resource extent and sanity check the values. */

	dcr_base = dcr_resource_start(np, 0);
	dcr_len = dcr_resource_len(np, 0);

	if (dcr_base == 0 || dcr_len == 0) {
		ppc4xx_edac_printk(KERN_ERR,
				   "Failed to obtain DCR property.\n");
		return -ENODEV;
	}

	if (dcr_len != SDRAM_DCR_RESOURCE_LEN) {
		ppc4xx_edac_printk(KERN_ERR,
				   "Unexpected DCR length %d, expected %d.\n",
				   dcr_len, SDRAM_DCR_RESOURCE_LEN);
		return -ENODEV;
	}

	/*  Attempt to map the DCR extent. */

	*dcr_host = dcr_map(np, dcr_base, dcr_len);

	if (!DCR_MAP_OK(*dcr_host)) {
		ppc4xx_edac_printk(KERN_INFO, "Failed to map DCRs.\n");
		    return -ENODEV;
	}

	return 0;
}

__attribute__((used)) static int ppc4xx_edac_probe(struct platform_device *op)
{
	int status = 0;
	u32 mcopt1, memcheck;
	dcr_host_t dcr_host;
	const struct device_node *np = op->dev.of_node;
	struct mem_ctl_info *mci = NULL;
	struct edac_mc_layer layers[2];
	static int ppc4xx_edac_instance;

	/*
	 * At this point, we only support the controller realized on
	 * the AMCC PPC 405EX[r]. Reject anything else.
	 */

	if (!of_device_is_compatible(np, "ibm,sdram-405ex") &&
	    !of_device_is_compatible(np, "ibm,sdram-405exr")) {
		ppc4xx_edac_printk(KERN_NOTICE,
				   "Only the PPC405EX[r] is supported.\n");
		return -ENODEV;
	}

	/*
	 * Next, get the DCR property and attempt to map it so that we
	 * can probe the controller.
	 */

	status = ppc4xx_edac_map_dcrs(np, &dcr_host);

	if (status)
		return status;

	/*
	 * First determine whether ECC is enabled at all. If not,
	 * there is no useful checking or monitoring that can be done
	 * for this controller.
	 */

	mcopt1 = mfsdram(&dcr_host, SDRAM_MCOPT1);
	memcheck = (mcopt1 & SDRAM_MCOPT1_MCHK_MASK);

	if (memcheck == SDRAM_MCOPT1_MCHK_NON) {
		ppc4xx_edac_printk(KERN_INFO, "%pOF: No ECC memory detected or "
				   "ECC is disabled.\n", np);
		status = -ENODEV;
		goto done;
	}

	/*
	 * At this point, we know ECC is enabled, allocate an EDAC
	 * controller instance and perform the appropriate
	 * initialization.
	 */
	layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
	layers[0].size = ppc4xx_edac_nr_csrows;
	layers[0].is_virt_csrow = true;
	layers[1].type = EDAC_MC_LAYER_CHANNEL;
	layers[1].size = ppc4xx_edac_nr_chans;
	layers[1].is_virt_csrow = false;
	mci = edac_mc_alloc(ppc4xx_edac_instance, ARRAY_SIZE(layers), layers,
			    sizeof(struct ppc4xx_edac_pdata));
	if (mci == NULL) {
		ppc4xx_edac_printk(KERN_ERR, "%pOF: "
				   "Failed to allocate EDAC MC instance!\n",
				   np);
		status = -ENOMEM;
		goto done;
	}

	status = ppc4xx_edac_mc_init(mci, op, &dcr_host, mcopt1);

	if (status) {
		ppc4xx_edac_mc_printk(KERN_ERR, mci,
				      "Failed to initialize instance!\n");
		goto fail;
	}

	/*
	 * We have a valid, initialized EDAC instance bound to the
	 * controller. Attempt to register it with the EDAC subsystem
	 * and, if necessary, register interrupts.
	 */

	if (edac_mc_add_mc(mci)) {
		ppc4xx_edac_mc_printk(KERN_ERR, mci,
				      "Failed to add instance!\n");
		status = -ENODEV;
		goto fail;
	}

	if (edac_op_state == EDAC_OPSTATE_INT) {
		status = ppc4xx_edac_register_irq(op, mci);

		if (status)
			goto fail1;
	}

	ppc4xx_edac_instance++;

	return 0;

 fail1:
	edac_mc_del_mc(mci->pdev);

 fail:
	edac_mc_free(mci);

 done:
	return status;
}

__attribute__((used)) static int
ppc4xx_edac_remove(struct platform_device *op)
{
	struct mem_ctl_info *mci = dev_get_drvdata(&op->dev);
	struct ppc4xx_edac_pdata *pdata = mci->pvt_info;

	if (edac_op_state == EDAC_OPSTATE_INT) {
		free_irq(pdata->irqs.sec, mci);
		free_irq(pdata->irqs.ded, mci);
	}

	dcr_unmap(pdata->dcr_host, SDRAM_DCR_RESOURCE_LEN);

	edac_mc_del_mc(mci->pdev);
	edac_mc_free(mci);

	return 0;
}

