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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
struct device {int dummy; } ;
struct crypto_async_request {int flags; } ;
struct cc_ivgen_ctx {int ctr_key; int ctr_iv; int pool; int next_iv_ofs; int pool_meta_dma; struct cc_hw_desc* pool_meta; } ;
struct cc_hw_desc {int* word; } ;
struct cc_drvdata {int cc_base; scalar_t__ hw_rev; struct cc_ivgen_ctx* ivgen_handle; TYPE_1__* plat_dev; } ;
typedef  int /*<<< orphan*/  gfp_t ;
typedef  enum drv_crypto_direction { ____Placeholder_drv_crypto_direction } drv_crypto_direction ;
typedef  enum drv_cipher_mode { ____Placeholder_drv_cipher_mode } drv_cipher_mode ;
typedef  enum cc_setup_op { ____Placeholder_cc_setup_op } cc_setup_op ;
typedef  enum cc_hw_crypto_key { ____Placeholder_cc_hw_crypto_key } cc_hw_crypto_key ;
typedef  enum cc_hash_conf_pad { ____Placeholder_cc_hash_conf_pad } cc_hash_conf_pad ;
typedef  enum cc_hash_cipher_pad { ____Placeholder_cc_hash_cipher_pad } cc_hash_cipher_pad ;
typedef  enum cc_flow_mode { ____Placeholder_cc_flow_mode } cc_flow_mode ;
typedef  enum cc_dma_mode { ____Placeholder_cc_dma_mode } cc_dma_mode ;
typedef  enum cc_axi_sec { ____Placeholder_cc_axi_sec } cc_axi_sec ;
typedef  int dma_addr_t ;
struct TYPE_2__ {struct device dev; } ;

/* Variables and functions */
 void* AES_KEYSIZE_128 ; 
 int BYPASS ; 
 int CC_AES_128_BIT_KEY_SIZE ; 
 unsigned int CC_AES_IV_SIZE ; 
 scalar_t__ CC_HW_REV_712 ; 
 int CC_IVPOOL_GEN_SEQ_LEN ; 
 int CC_IVPOOL_META_SIZE ; 
 int CC_IVPOOL_SEQ_LEN ; 
 int CC_IVPOOL_SIZE ; 
 unsigned int CC_MAX_IVGEN_DMA_ADDRESSES ; 
 int CRYPTO_TFM_REQ_MAY_SLEEP ; 
 unsigned int CTR_RFC3686_IV_SIZE ; 
 int DESC_DIRECTION_ENCRYPT_ENCRYPT ; 
 int DIN_AES_DOUT ; 
 int DMA_DLLI ; 
 int DMA_MLLI ; 
 int DMA_SRAM ; 
 int DRV_CIPHER_CTR ; 
 int EINVAL ; 
 int ENOMEM ; 
 int FIELD_PREP (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HW_KEY_MASK_CIPHER_DO ; 
 int HW_KEY_SHIFT_CIPHER_CFG2 ; 
 int NS_BIT ; 
 scalar_t__ NULL_SRAM_ADDR ; 
 int SETUP_LOAD_KEY0 ; 
 int SETUP_LOAD_STATE1 ; 
 int S_DIN_to_AES ; 
 int /*<<< orphan*/  WORD1_DIN_CONST_VALUE ; 
 int /*<<< orphan*/  WORD1_DIN_DMA_MODE ; 
 int /*<<< orphan*/  WORD1_DIN_SIZE ; 
 int /*<<< orphan*/  WORD1_NOT_LAST ; 
 int /*<<< orphan*/  WORD1_NS_BIT ; 
 int /*<<< orphan*/  WORD3_DOUT_DMA_MODE ; 
 int /*<<< orphan*/  WORD3_DOUT_LAST_IND ; 
 int /*<<< orphan*/  WORD3_DOUT_SIZE ; 
 int /*<<< orphan*/  WORD3_HASH_XOR_BIT ; 
 int /*<<< orphan*/  WORD3_NS_BIT ; 
 int /*<<< orphan*/  WORD3_QUEUE_LAST_IND ; 
 int /*<<< orphan*/  WORD4_AES_SEL_N_HASH ; 
 int /*<<< orphan*/  WORD4_BYTES_SWAP ; 
 int /*<<< orphan*/  WORD4_CIPHER_CONF0 ; 
 int /*<<< orphan*/  WORD4_CIPHER_CONF1 ; 
 int /*<<< orphan*/  WORD4_CIPHER_CONF2 ; 
 int /*<<< orphan*/  WORD4_CIPHER_DO ; 
 int /*<<< orphan*/  WORD4_CIPHER_MODE ; 
 int /*<<< orphan*/  WORD4_CMAC_SIZE0 ; 
 int /*<<< orphan*/  WORD4_DATA_FLOW_MODE ; 
 int /*<<< orphan*/  WORD4_KEY_SIZE ; 
 int /*<<< orphan*/  WORD4_SETUP_OPERATION ; 
 int /*<<< orphan*/  __dump_byte_array (char const*,int /*<<< orphan*/  const*,size_t) ; 
 scalar_t__ cc_dump_bytes ; 
 int cc_sram_alloc (struct cc_drvdata*,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct cc_hw_desc* dma_alloc_coherent (struct device*,int,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_coherent (struct device*,int,struct cc_hw_desc*,int) ; 
 int /*<<< orphan*/  get_random_bytes (struct cc_hw_desc*,int) ; 
 int ioread32 (int) ; 
 int /*<<< orphan*/  iowrite32 (int,int) ; 
 int /*<<< orphan*/  kfree (struct cc_ivgen_ctx*) ; 
 struct cc_ivgen_ctx* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct cc_hw_desc*,int /*<<< orphan*/ ,int) ; 
 int send_request_init (struct cc_drvdata*,struct cc_hw_desc*,unsigned int) ; 

__attribute__((used)) static inline void hw_desc_init(struct cc_hw_desc *pdesc)
{
	memset(pdesc, 0, sizeof(struct cc_hw_desc));
}

__attribute__((used)) static inline void set_queue_last_ind_bit(struct cc_hw_desc *pdesc)
{
	pdesc->word[3] |= FIELD_PREP(WORD3_QUEUE_LAST_IND, 1);
}

__attribute__((used)) static inline void set_din_type(struct cc_hw_desc *pdesc,
				enum cc_dma_mode dma_mode, dma_addr_t addr,
				u32 size, enum cc_axi_sec axi_sec)
{
	pdesc->word[0] = (u32)addr;
#ifdef CONFIG_ARCH_DMA_ADDR_T_64BIT
	pdesc->word[5] |= FIELD_PREP(WORD5_DIN_ADDR_HIGH, ((u16)(addr >> 32)));
#endif
	pdesc->word[1] |= FIELD_PREP(WORD1_DIN_DMA_MODE, dma_mode) |
				FIELD_PREP(WORD1_DIN_SIZE, size) |
				FIELD_PREP(WORD1_NS_BIT, axi_sec);
}

__attribute__((used)) static inline void set_din_no_dma(struct cc_hw_desc *pdesc, u32 addr, u32 size)
{
	pdesc->word[0] = addr;
	pdesc->word[1] |= FIELD_PREP(WORD1_DIN_SIZE, size);
}

__attribute__((used)) static inline void set_din_sram(struct cc_hw_desc *pdesc, dma_addr_t addr,
				u32 size)
{
	pdesc->word[0] = (u32)addr;
	pdesc->word[1] |= FIELD_PREP(WORD1_DIN_SIZE, size) |
				FIELD_PREP(WORD1_DIN_DMA_MODE, DMA_SRAM);
}

__attribute__((used)) static inline void set_din_const(struct cc_hw_desc *pdesc, u32 val, u32 size)
{
	pdesc->word[0] = val;
	pdesc->word[1] |= FIELD_PREP(WORD1_DIN_CONST_VALUE, 1) |
			FIELD_PREP(WORD1_DIN_DMA_MODE, DMA_SRAM) |
			FIELD_PREP(WORD1_DIN_SIZE, size);
}

__attribute__((used)) static inline void set_din_not_last_indication(struct cc_hw_desc *pdesc)
{
	pdesc->word[1] |= FIELD_PREP(WORD1_NOT_LAST, 1);
}

__attribute__((used)) static inline void set_dout_type(struct cc_hw_desc *pdesc,
				 enum cc_dma_mode dma_mode, dma_addr_t addr,
				 u32 size, enum cc_axi_sec axi_sec)
{
	pdesc->word[2] = (u32)addr;
#ifdef CONFIG_ARCH_DMA_ADDR_T_64BIT
	pdesc->word[5] |= FIELD_PREP(WORD5_DOUT_ADDR_HIGH, ((u16)(addr >> 32)));
#endif
	pdesc->word[3] |= FIELD_PREP(WORD3_DOUT_DMA_MODE, dma_mode) |
				FIELD_PREP(WORD3_DOUT_SIZE, size) |
				FIELD_PREP(WORD3_NS_BIT, axi_sec);
}

__attribute__((used)) static inline void set_dout_dlli(struct cc_hw_desc *pdesc, dma_addr_t addr,
				 u32 size, enum cc_axi_sec axi_sec,
				 u32 last_ind)
{
	set_dout_type(pdesc, DMA_DLLI, addr, size, axi_sec);
	pdesc->word[3] |= FIELD_PREP(WORD3_DOUT_LAST_IND, last_ind);
}

__attribute__((used)) static inline void set_dout_mlli(struct cc_hw_desc *pdesc, dma_addr_t addr,
				 u32 size, enum cc_axi_sec axi_sec,
				 bool last_ind)
{
	set_dout_type(pdesc, DMA_MLLI, addr, size, axi_sec);
	pdesc->word[3] |= FIELD_PREP(WORD3_DOUT_LAST_IND, last_ind);
}

__attribute__((used)) static inline void set_dout_no_dma(struct cc_hw_desc *pdesc, u32 addr,
				   u32 size, bool write_enable)
{
	pdesc->word[2] = addr;
	pdesc->word[3] |= FIELD_PREP(WORD3_DOUT_SIZE, size) |
			FIELD_PREP(WORD3_DOUT_LAST_IND, write_enable);
}

__attribute__((used)) static inline void set_xor_val(struct cc_hw_desc *pdesc, u32 val)
{
	pdesc->word[2] = val;
}

__attribute__((used)) static inline void set_xor_active(struct cc_hw_desc *pdesc)
{
	pdesc->word[3] |= FIELD_PREP(WORD3_HASH_XOR_BIT, 1);
}

__attribute__((used)) static inline void set_aes_not_hash_mode(struct cc_hw_desc *pdesc)
{
	pdesc->word[4] |= FIELD_PREP(WORD4_AES_SEL_N_HASH, 1);
}

__attribute__((used)) static inline void set_dout_sram(struct cc_hw_desc *pdesc, u32 addr, u32 size)
{
	pdesc->word[2] = addr;
	pdesc->word[3] |= FIELD_PREP(WORD3_DOUT_DMA_MODE, DMA_SRAM) |
			FIELD_PREP(WORD3_DOUT_SIZE, size);
}

__attribute__((used)) static inline void set_xex_data_unit_size(struct cc_hw_desc *pdesc, u32 size)
{
	pdesc->word[2] = size;
}

__attribute__((used)) static inline void set_multi2_num_rounds(struct cc_hw_desc *pdesc, u32 num)
{
	pdesc->word[2] = num;
}

__attribute__((used)) static inline void set_flow_mode(struct cc_hw_desc *pdesc,
				 enum cc_flow_mode mode)
{
	pdesc->word[4] |= FIELD_PREP(WORD4_DATA_FLOW_MODE, mode);
}

__attribute__((used)) static inline void set_cipher_mode(struct cc_hw_desc *pdesc,
				   enum drv_cipher_mode mode)
{
	pdesc->word[4] |= FIELD_PREP(WORD4_CIPHER_MODE, mode);
}

__attribute__((used)) static inline void set_cipher_config0(struct cc_hw_desc *pdesc,
				      enum drv_crypto_direction mode)
{
	pdesc->word[4] |= FIELD_PREP(WORD4_CIPHER_CONF0, mode);
}

__attribute__((used)) static inline void set_cipher_config1(struct cc_hw_desc *pdesc,
				      enum cc_hash_conf_pad config)
{
	pdesc->word[4] |= FIELD_PREP(WORD4_CIPHER_CONF1, config);
}

__attribute__((used)) static inline void set_hw_crypto_key(struct cc_hw_desc *pdesc,
				     enum cc_hw_crypto_key hw_key)
{
	pdesc->word[4] |= FIELD_PREP(WORD4_CIPHER_DO,
				     (hw_key & HW_KEY_MASK_CIPHER_DO)) |
			FIELD_PREP(WORD4_CIPHER_CONF2,
				   (hw_key >> HW_KEY_SHIFT_CIPHER_CFG2));
}

__attribute__((used)) static inline void set_bytes_swap(struct cc_hw_desc *pdesc, bool config)
{
	pdesc->word[4] |= FIELD_PREP(WORD4_BYTES_SWAP, config);
}

__attribute__((used)) static inline void set_cmac_size0_mode(struct cc_hw_desc *pdesc)
{
	pdesc->word[4] |= FIELD_PREP(WORD4_CMAC_SIZE0, 1);
}

__attribute__((used)) static inline void set_key_size(struct cc_hw_desc *pdesc, u32 size)
{
	pdesc->word[4] |= FIELD_PREP(WORD4_KEY_SIZE, size);
}

__attribute__((used)) static inline void set_key_size_aes(struct cc_hw_desc *pdesc, u32 size)
{
	set_key_size(pdesc, ((size >> 3) - 2));
}

__attribute__((used)) static inline void set_key_size_des(struct cc_hw_desc *pdesc, u32 size)
{
	set_key_size(pdesc, ((size >> 3) - 1));
}

__attribute__((used)) static inline void set_setup_mode(struct cc_hw_desc *pdesc,
				  enum cc_setup_op mode)
{
	pdesc->word[4] |= FIELD_PREP(WORD4_SETUP_OPERATION, mode);
}

__attribute__((used)) static inline void set_cipher_do(struct cc_hw_desc *pdesc,
				 enum cc_hash_cipher_pad config)
{
	pdesc->word[4] |= FIELD_PREP(WORD4_CIPHER_DO,
				(config & HW_KEY_MASK_CIPHER_DO));
}

__attribute__((used)) static inline struct device *drvdata_to_dev(struct cc_drvdata *drvdata)
{
	return &drvdata->plat_dev->dev;
}

__attribute__((used)) static inline void dump_byte_array(const char *name, const u8 *the_array,
				   size_t size)
{
	if (cc_dump_bytes)
		__dump_byte_array(name, the_array, size);
}

__attribute__((used)) static inline void cc_iowrite(struct cc_drvdata *drvdata, u32 reg, u32 val)
{
	iowrite32(val, (drvdata->cc_base + reg));
}

__attribute__((used)) static inline u32 cc_ioread(struct cc_drvdata *drvdata, u32 reg)
{
	return ioread32(drvdata->cc_base + reg);
}

__attribute__((used)) static inline gfp_t cc_gfp_flags(struct crypto_async_request *req)
{
	return (req->flags & CRYPTO_TFM_REQ_MAY_SLEEP) ?
			GFP_KERNEL : GFP_ATOMIC;
}

__attribute__((used)) static inline void set_queue_last_ind(struct cc_drvdata *drvdata,
				      struct cc_hw_desc *pdesc)
{
	if (drvdata->hw_rev >= CC_HW_REV_712)
		set_queue_last_ind_bit(pdesc);
}

__attribute__((used)) static int cc_gen_iv_pool(struct cc_ivgen_ctx *ivgen_ctx,
			  struct cc_hw_desc iv_seq[], unsigned int *iv_seq_len)
{
	unsigned int idx = *iv_seq_len;

	if ((*iv_seq_len + CC_IVPOOL_GEN_SEQ_LEN) > CC_IVPOOL_SEQ_LEN) {
		/* The sequence will be longer than allowed */
		return -EINVAL;
	}
	/* Setup key */
	hw_desc_init(&iv_seq[idx]);
	set_din_sram(&iv_seq[idx], ivgen_ctx->ctr_key, AES_KEYSIZE_128);
	set_setup_mode(&iv_seq[idx], SETUP_LOAD_KEY0);
	set_cipher_config0(&iv_seq[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
	set_flow_mode(&iv_seq[idx], S_DIN_to_AES);
	set_key_size_aes(&iv_seq[idx], CC_AES_128_BIT_KEY_SIZE);
	set_cipher_mode(&iv_seq[idx], DRV_CIPHER_CTR);
	idx++;

	/* Setup cipher state */
	hw_desc_init(&iv_seq[idx]);
	set_din_sram(&iv_seq[idx], ivgen_ctx->ctr_iv, CC_AES_IV_SIZE);
	set_cipher_config0(&iv_seq[idx], DESC_DIRECTION_ENCRYPT_ENCRYPT);
	set_flow_mode(&iv_seq[idx], S_DIN_to_AES);
	set_setup_mode(&iv_seq[idx], SETUP_LOAD_STATE1);
	set_key_size_aes(&iv_seq[idx], CC_AES_128_BIT_KEY_SIZE);
	set_cipher_mode(&iv_seq[idx], DRV_CIPHER_CTR);
	idx++;

	/* Perform dummy encrypt to skip first block */
	hw_desc_init(&iv_seq[idx]);
	set_din_const(&iv_seq[idx], 0, CC_AES_IV_SIZE);
	set_dout_sram(&iv_seq[idx], ivgen_ctx->pool, CC_AES_IV_SIZE);
	set_flow_mode(&iv_seq[idx], DIN_AES_DOUT);
	idx++;

	/* Generate IV pool */
	hw_desc_init(&iv_seq[idx]);
	set_din_const(&iv_seq[idx], 0, CC_IVPOOL_SIZE);
	set_dout_sram(&iv_seq[idx], ivgen_ctx->pool, CC_IVPOOL_SIZE);
	set_flow_mode(&iv_seq[idx], DIN_AES_DOUT);
	idx++;

	*iv_seq_len = idx; /* Update sequence length */

	/* queue ordering assures pool readiness */
	ivgen_ctx->next_iv_ofs = CC_IVPOOL_META_SIZE;

	return 0;
}

int cc_init_iv_sram(struct cc_drvdata *drvdata)
{
	struct cc_ivgen_ctx *ivgen_ctx = drvdata->ivgen_handle;
	struct cc_hw_desc iv_seq[CC_IVPOOL_SEQ_LEN];
	unsigned int iv_seq_len = 0;
	int rc;

	/* Generate initial enc. key/iv */
	get_random_bytes(ivgen_ctx->pool_meta, CC_IVPOOL_META_SIZE);

	/* The first 32B reserved for the enc. Key/IV */
	ivgen_ctx->ctr_key = ivgen_ctx->pool;
	ivgen_ctx->ctr_iv = ivgen_ctx->pool + AES_KEYSIZE_128;

	/* Copy initial enc. key and IV to SRAM at a single descriptor */
	hw_desc_init(&iv_seq[iv_seq_len]);
	set_din_type(&iv_seq[iv_seq_len], DMA_DLLI, ivgen_ctx->pool_meta_dma,
		     CC_IVPOOL_META_SIZE, NS_BIT);
	set_dout_sram(&iv_seq[iv_seq_len], ivgen_ctx->pool,
		      CC_IVPOOL_META_SIZE);
	set_flow_mode(&iv_seq[iv_seq_len], BYPASS);
	iv_seq_len++;

	/* Generate initial pool */
	rc = cc_gen_iv_pool(ivgen_ctx, iv_seq, &iv_seq_len);
	if (rc)
		return rc;

	/* Fire-and-forget */
	return send_request_init(drvdata, iv_seq, iv_seq_len);
}

void cc_ivgen_fini(struct cc_drvdata *drvdata)
{
	struct cc_ivgen_ctx *ivgen_ctx = drvdata->ivgen_handle;
	struct device *device = &drvdata->plat_dev->dev;

	if (!ivgen_ctx)
		return;

	if (ivgen_ctx->pool_meta) {
		memset(ivgen_ctx->pool_meta, 0, CC_IVPOOL_META_SIZE);
		dma_free_coherent(device, CC_IVPOOL_META_SIZE,
				  ivgen_ctx->pool_meta,
				  ivgen_ctx->pool_meta_dma);
	}

	ivgen_ctx->pool = NULL_SRAM_ADDR;

	/* release "this" context */
	kfree(ivgen_ctx);
}

int cc_ivgen_init(struct cc_drvdata *drvdata)
{
	struct cc_ivgen_ctx *ivgen_ctx;
	struct device *device = &drvdata->plat_dev->dev;
	int rc;

	/* Allocate "this" context */
	ivgen_ctx = kzalloc(sizeof(*ivgen_ctx), GFP_KERNEL);
	if (!ivgen_ctx)
		return -ENOMEM;

	/* Allocate pool's header for initial enc. key/IV */
	ivgen_ctx->pool_meta = dma_alloc_coherent(device, CC_IVPOOL_META_SIZE,
						  &ivgen_ctx->pool_meta_dma,
						  GFP_KERNEL);
	if (!ivgen_ctx->pool_meta) {
		dev_err(device, "Not enough memory to allocate DMA of pool_meta (%u B)\n",
			CC_IVPOOL_META_SIZE);
		rc = -ENOMEM;
		goto out;
	}
	/* Allocate IV pool in SRAM */
	ivgen_ctx->pool = cc_sram_alloc(drvdata, CC_IVPOOL_SIZE);
	if (ivgen_ctx->pool == NULL_SRAM_ADDR) {
		dev_err(device, "SRAM pool exhausted\n");
		rc = -ENOMEM;
		goto out;
	}

	drvdata->ivgen_handle = ivgen_ctx;

	return cc_init_iv_sram(drvdata);

out:
	cc_ivgen_fini(drvdata);
	return rc;
}

int cc_get_iv(struct cc_drvdata *drvdata, dma_addr_t iv_out_dma[],
	      unsigned int iv_out_dma_len, unsigned int iv_out_size,
	      struct cc_hw_desc iv_seq[], unsigned int *iv_seq_len)
{
	struct cc_ivgen_ctx *ivgen_ctx = drvdata->ivgen_handle;
	unsigned int idx = *iv_seq_len;
	struct device *dev = drvdata_to_dev(drvdata);
	unsigned int t;

	if (iv_out_size != CC_AES_IV_SIZE &&
	    iv_out_size != CTR_RFC3686_IV_SIZE) {
		return -EINVAL;
	}
	if ((iv_out_dma_len + 1) > CC_IVPOOL_SEQ_LEN) {
		/* The sequence will be longer than allowed */
		return -EINVAL;
	}

	/* check that number of generated IV is limited to max dma address
	 * iv buffer size
	 */
	if (iv_out_dma_len > CC_MAX_IVGEN_DMA_ADDRESSES) {
		/* The sequence will be longer than allowed */
		return -EINVAL;
	}

	for (t = 0; t < iv_out_dma_len; t++) {
		/* Acquire IV from pool */
		hw_desc_init(&iv_seq[idx]);
		set_din_sram(&iv_seq[idx], (ivgen_ctx->pool +
					    ivgen_ctx->next_iv_ofs),
			     iv_out_size);
		set_dout_dlli(&iv_seq[idx], iv_out_dma[t], iv_out_size,
			      NS_BIT, 0);
		set_flow_mode(&iv_seq[idx], BYPASS);
		idx++;
	}

	/* Bypass operation is proceeded by crypto sequence, hence must
	 *  assure bypass-write-transaction by a memory barrier
	 */
	hw_desc_init(&iv_seq[idx]);
	set_din_no_dma(&iv_seq[idx], 0, 0xfffff0);
	set_dout_no_dma(&iv_seq[idx], 0, 0, 1);
	idx++;

	*iv_seq_len = idx; /* update seq length */

	/* Update iv index */
	ivgen_ctx->next_iv_ofs += iv_out_size;

	if ((CC_IVPOOL_SIZE - ivgen_ctx->next_iv_ofs) < CC_AES_IV_SIZE) {
		dev_dbg(dev, "Pool exhausted, regenerating iv-pool\n");
		/* pool is drained -regenerate it! */
		return cc_gen_iv_pool(ivgen_ctx, iv_seq, iv_seq_len);
	}

	return 0;
}

