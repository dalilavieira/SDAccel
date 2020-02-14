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
struct cc_hw_desc {int* word; } ;
struct cc_drvdata {int cc_base; scalar_t__ hw_rev; TYPE_1__* plat_dev; } ;
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
typedef  scalar_t__ dma_addr_t ;
struct TYPE_2__ {struct device dev; } ;

/* Variables and functions */
 scalar_t__ CC_HW_REV_712 ; 
 int CRYPTO_TFM_REQ_MAY_SLEEP ; 
 int DMA_DLLI ; 
 int DMA_MLLI ; 
 int DMA_SRAM ; 
 int FIELD_PREP (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HW_KEY_MASK_CIPHER_DO ; 
 int HW_KEY_SHIFT_CIPHER_CFG2 ; 
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
 int ioread32 (int) ; 
 int /*<<< orphan*/  iowrite32 (int,int) ; 
 int /*<<< orphan*/  memset (struct cc_hw_desc*,int /*<<< orphan*/ ,int) ; 

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

__attribute__((used)) static inline int cc_debugfs_global_init(void)
{
	return 0;
}

__attribute__((used)) static inline void cc_debugfs_global_fini(void) {}

__attribute__((used)) static inline int cc_debugfs_init(struct cc_drvdata *drvdata)
{
	return 0;
}

__attribute__((used)) static inline void cc_debugfs_fini(struct cc_drvdata *drvdata) {}

