#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct txentry_desc {int /*<<< orphan*/  flags; } ;
struct skb_frame_desc {int skb_dma; void* desc_len; int /*<<< orphan*/ * desc; } ;
struct sk_buff {int len; scalar_t__ data; } ;
struct rxdone_entry_desc {int cipher_status; int /*<<< orphan*/  dev_flags; int /*<<< orphan*/  flags; } ;
struct rt2x00lib_conf {struct ieee80211_conf* conf; } ;
struct rt2x00_sta {int dummy; } ;
struct rt2x00_intf {int dummy; } ;
struct rt2x00_field32 {int dummy; } ;
struct TYPE_10__ {scalar_t__ base; } ;
struct TYPE_9__ {scalar_t__ rt; scalar_t__ rf; scalar_t__ rev; int intf; } ;
struct rt2x00_dev {int* rf; int beacon_int; TYPE_7__* rx; struct data_queue* tx; int /*<<< orphan*/  pretbtt_tasklet; int /*<<< orphan*/  tbtt_tasklet; int /*<<< orphan*/  autowake_tasklet; int /*<<< orphan*/  rxdone_tasklet; int /*<<< orphan*/  txstatus_tasklet; int /*<<< orphan*/  irqmask_lock; int /*<<< orphan*/  flags; int /*<<< orphan*/  txstatus_fifo; scalar_t__ intf_ap_count; struct rt2800_drv_data* drv_data; TYPE_3__* ops; TYPE_2__ csr; struct data_queue* atim; int /*<<< orphan*/  cap_flags; TYPE_1__ chip; int /*<<< orphan*/ * eeprom; } ;
struct rt2800_ops {int (* register_read ) (struct rt2x00_dev*,unsigned int const) ;int (* register_read_lock ) (struct rt2x00_dev*,unsigned int const) ;int (* regbusy_read ) (struct rt2x00_dev*,unsigned int const,struct rt2x00_field32 const,int*) ;int (* read_eeprom ) (struct rt2x00_dev*) ;int (* hwcrypt_disabled ) (struct rt2x00_dev*) ;int (* drv_write_firmware ) (struct rt2x00_dev*,size_t const*,size_t const) ;int (* drv_init_registers ) (struct rt2x00_dev*) ;int /*<<< orphan*/ * (* drv_get_txwi ) (struct queue_entry*) ;int /*<<< orphan*/  (* register_multiwrite ) (struct rt2x00_dev*,unsigned int const,void const*,int const) ;int /*<<< orphan*/  (* register_multiread ) (struct rt2x00_dev*,unsigned int const,void*,int const) ;int /*<<< orphan*/  (* register_write_lock ) (struct rt2x00_dev*,unsigned int const,int) ;int /*<<< orphan*/  (* register_write ) (struct rt2x00_dev*,unsigned int const,int) ;} ;
struct rt2800_drv_data {int tbtt_tick; } ;
struct queue_entry_priv_mmio {int desc_dma; int /*<<< orphan*/ * desc; } ;
struct queue_entry {int status; int entry_idx; TYPE_4__* queue; struct sk_buff* skb; struct queue_entry_priv_mmio* priv_data; int /*<<< orphan*/  flags; scalar_t__ last_action; } ;
struct ieee80211_vif {scalar_t__ drv_priv; } ;
struct ieee80211_sta {scalar_t__ drv_priv; } ;
struct ieee80211_conf {int /*<<< orphan*/  flags; } ;
struct data_queue {scalar_t__ length; scalar_t__ limit; scalar_t__ threshold; int qid; unsigned short winfo_size; int priv_size; TYPE_5__* entries; void* desc_size; void* data_size; struct rt2x00_dev* rt2x00dev; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum rt2x00_dump_type { ____Placeholder_rt2x00_dump_type } rt2x00_dump_type ;
typedef  enum rt2x00_chip_intf { ____Placeholder_rt2x00_chip_intf } rt2x00_chip_intf ;
typedef  enum rt2x00_capability_flags { ____Placeholder_rt2x00_capability_flags } rt2x00_capability_flags ;
typedef  enum dev_state { ____Placeholder_dev_state } dev_state ;
typedef  enum data_queue_qid { ____Placeholder_data_queue_qid } data_queue_qid ;
typedef  int /*<<< orphan*/  __le32 ;
struct TYPE_16__ {int /*<<< orphan*/  driver_data; } ;
struct TYPE_15__ {int limit; TYPE_6__* entries; } ;
struct TYPE_14__ {struct queue_entry_priv_mmio* priv_data; } ;
struct TYPE_13__ {struct queue_entry_priv_mmio* priv_data; } ;
struct TYPE_12__ {unsigned int winfo_size; size_t qid; struct rt2x00_dev* rt2x00dev; } ;
struct TYPE_11__ {int rf_size; int const tx_queues; struct rt2800_ops* drv; } ;

/* Variables and functions */
 void* AGGREGATION_SIZE ; 
 unsigned int AUX_CTRL ; 
 struct rt2x00_field32 AUX_CTRL_FORCE_PCIE_CLK ; 
 struct rt2x00_field32 AUX_CTRL_WAKE_PCIE_EN ; 
 int BCN_TBTT_OFFSET ; 
 unsigned int BCN_TIME_CFG ; 
 struct rt2x00_field32 BCN_TIME_CFG_BEACON_GEN ; 
 struct rt2x00_field32 BCN_TIME_CFG_BEACON_INTERVAL ; 
 struct rt2x00_field32 BCN_TIME_CFG_TBTT_ENABLE ; 
 struct rt2x00_field32 BCN_TIME_CFG_TSF_TICKING ; 
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int CAPABILITY_BT_COEXIST ; 
 int CAPABILITY_CONTROL_FILTERS ; 
 int CAPABILITY_CONTROL_FILTER_PSPOLL ; 
 int CAPABILITY_DOUBLE_ANTENNA ; 
 int CAPABILITY_EXTERNAL_LNA_A ; 
 int CAPABILITY_EXTERNAL_LNA_BG ; 
 int CAPABILITY_FRAME_TYPE ; 
 int CAPABILITY_HW_CRYPTO ; 
 int CAPABILITY_LINK_TUNING ; 
 int CAPABILITY_POWER_LIMIT ; 
 int CAPABILITY_PRE_TBTT_INTERRUPT ; 
 int CAPABILITY_RF_SEQUENCE ; 
 int CAPABILITY_VCO_RECALIBRATION ; 
 unsigned int DELAY_INT_CFG ; 
 int DEVICE_STATE_ENABLED_RADIO ; 
 int EIO ; 
 int ENTRY_DATA_STATUS_SET ; 
 int ENTRY_OWNER_DEVICE_DATA ; 
 int ENTRY_TXD_BURST ; 
 int ENTRY_TXD_ENCRYPT_IV ; 
 int ENTRY_TXD_MORE_FRAG ; 
 int /*<<< orphan*/  IEEE80211_CONF_CHANGE_PS ; 
 TYPE_8__* IEEE80211_SKB_CB (struct sk_buff*) ; 
 int IEEE80211_TX_INFO_DRIVER_DATA_SIZE ; 
 unsigned int INT_MASK_CSR ; 
 struct rt2x00_field32 INT_MASK_CSR_AUTO_WAKEUP ; 
 struct rt2x00_field32 INT_MASK_CSR_PRE_TBTT ; 
 struct rt2x00_field32 INT_MASK_CSR_RX_DONE ; 
 struct rt2x00_field32 INT_MASK_CSR_TBTT ; 
 struct rt2x00_field32 INT_MASK_CSR_TX_FIFO_STATUS ; 
 unsigned int INT_SOURCE_CSR ; 
 struct rt2x00_field32 INT_SOURCE_CSR_AUTO_WAKEUP ; 
 struct rt2x00_field32 INT_SOURCE_CSR_PRE_TBTT ; 
 struct rt2x00_field32 INT_SOURCE_CSR_RX_DONE ; 
 struct rt2x00_field32 INT_SOURCE_CSR_TBTT ; 
 struct rt2x00_field32 INT_SOURCE_CSR_TX_FIFO_STATUS ; 
 unsigned int INT_TIMER_EN ; 
 struct rt2x00_field32 INT_TIMER_EN_PRE_TBTT_TIMER ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 unsigned int MAC_SYS_CTRL ; 
 struct rt2x00_field32 MAC_SYS_CTRL_ENABLE_RX ; 
 struct rt2x00_field32 MAC_SYS_CTRL_RESET_BBP ; 
 struct rt2x00_field32 MAC_SYS_CTRL_RESET_CSR ; 
 unsigned int PBF_SYS_CTRL ; 
 unsigned int PWR_PIN_CFG ; 
#define  QID_AC_BE 135 
#define  QID_AC_BK 134 
#define  QID_AC_VI 133 
#define  QID_AC_VO 132 
#define  QID_ATIM 131 
#define  QID_BEACON 130 
#define  QID_MGMT 129 
#define  QID_RX 128 
 int /*<<< orphan*/  Q_INDEX ; 
 int /*<<< orphan*/  Q_INDEX_DONE ; 
 int RT2X00_CHIP_INTF_PCI ; 
 int RT2X00_CHIP_INTF_PCIE ; 
 int RT2X00_CHIP_INTF_SOC ; 
 int RT2X00_CHIP_INTF_USB ; 
 scalar_t__ RT3090 ; 
 scalar_t__ RT3390 ; 
 scalar_t__ RT3572 ; 
 scalar_t__ RT3593 ; 
 scalar_t__ RT5390 ; 
 scalar_t__ RT5392 ; 
 scalar_t__ RT5592 ; 
 int /*<<< orphan*/  RXDONE_L2PAD ; 
 int /*<<< orphan*/  RXDONE_MY_BSS ; 
 void* RXD_DESC_SIZE ; 
 struct rt2x00_field32 RXD_W0_SDP0 ; 
 struct rt2x00_field32 RXD_W1_DMA_DONE ; 
 struct rt2x00_field32 RXD_W3_CIPHER_ERROR ; 
 struct rt2x00_field32 RXD_W3_CRC_ERROR ; 
 struct rt2x00_field32 RXD_W3_DECRYPTED ; 
 struct rt2x00_field32 RXD_W3_L2PAD ; 
 struct rt2x00_field32 RXD_W3_MY_BSS ; 
 unsigned int RX_BASE_PTR ; 
 unsigned int RX_CRX_IDX ; 
 scalar_t__ RX_CRYPTO_FAIL_MIC ; 
 scalar_t__ RX_CRYPTO_SUCCESS ; 
 unsigned int RX_DRX_IDX ; 
 int /*<<< orphan*/  RX_FLAG_DECRYPTED ; 
 int /*<<< orphan*/  RX_FLAG_FAILED_FCS_CRC ; 
 int /*<<< orphan*/  RX_FLAG_IV_STRIPPED ; 
 int /*<<< orphan*/  RX_FLAG_MMIC_ERROR ; 
 int /*<<< orphan*/  RX_FLAG_MMIC_STRIPPED ; 
 unsigned int RX_MAX_CNT ; 
 int STATE_RADIO_IRQ_OFF ; 
 int STATE_RADIO_IRQ_ON ; 
 void* TXD_DESC_SIZE ; 
 struct rt2x00_field32 TXD_W0_SD_PTR0 ; 
 struct rt2x00_field32 TXD_W1_BURST ; 
 struct rt2x00_field32 TXD_W1_DMA_DONE ; 
 struct rt2x00_field32 TXD_W1_LAST_SEC0 ; 
 struct rt2x00_field32 TXD_W1_LAST_SEC1 ; 
 struct rt2x00_field32 TXD_W1_SD_LEN0 ; 
 struct rt2x00_field32 TXD_W1_SD_LEN1 ; 
 struct rt2x00_field32 TXD_W2_SD_PTR1 ; 
 struct rt2x00_field32 TXD_W3_QSEL ; 
 struct rt2x00_field32 TXD_W3_WIV ; 
 struct rt2x00_field32 TXWI_W1_WIRELESS_CLI_ID ; 
 unsigned int TX_BASE_PTR0 ; 
 unsigned int TX_BASE_PTR1 ; 
 unsigned int TX_BASE_PTR2 ; 
 unsigned int TX_BASE_PTR3 ; 
 unsigned int TX_BASE_PTR4 ; 
 unsigned int TX_BASE_PTR5 ; 
 unsigned int TX_CTX_IDX (int) ; 
 unsigned int TX_CTX_IDX0 ; 
 unsigned int TX_CTX_IDX1 ; 
 unsigned int TX_CTX_IDX2 ; 
 unsigned int TX_CTX_IDX3 ; 
 unsigned int TX_CTX_IDX4 ; 
 unsigned int TX_CTX_IDX5 ; 
 unsigned int TX_DTX_IDX0 ; 
 unsigned int TX_DTX_IDX1 ; 
 unsigned int TX_DTX_IDX2 ; 
 unsigned int TX_DTX_IDX3 ; 
 unsigned int TX_DTX_IDX4 ; 
 unsigned int TX_DTX_IDX5 ; 
 unsigned int TX_MAX_CNT0 ; 
 unsigned int TX_MAX_CNT1 ; 
 unsigned int TX_MAX_CNT2 ; 
 unsigned int TX_MAX_CNT3 ; 
 unsigned int TX_MAX_CNT4 ; 
 unsigned int TX_MAX_CNT5 ; 
 unsigned int TX_STA_FIFO ; 
 struct rt2x00_field32 TX_STA_FIFO_PID_QUEUE ; 
 struct rt2x00_field32 TX_STA_FIFO_VALID ; 
 struct rt2x00_field32 TX_STA_FIFO_WCID ; 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 unsigned int WPDMA_RST_IDX ; 
 struct rt2x00_field32 WPDMA_RST_IDX_DRX_IDX0 ; 
 struct rt2x00_field32 WPDMA_RST_IDX_DTX_IDX0 ; 
 struct rt2x00_field32 WPDMA_RST_IDX_DTX_IDX1 ; 
 struct rt2x00_field32 WPDMA_RST_IDX_DTX_IDX2 ; 
 struct rt2x00_field32 WPDMA_RST_IDX_DTX_IDX3 ; 
 struct rt2x00_field32 WPDMA_RST_IDX_DTX_IDX4 ; 
 struct rt2x00_field32 WPDMA_RST_IDX_DTX_IDX5 ; 
 int /*<<< orphan*/  __iowrite32_copy (scalar_t__,void const*,int const) ; 
 int /*<<< orphan*/  cpu_to_le16 (scalar_t__) ; 
 int /*<<< orphan*/  cpu_to_le32 (int) ; 
 int /*<<< orphan*/  jiffies ; 
 scalar_t__ kfifo_get (int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  kfifo_put (int /*<<< orphan*/ *,int) ; 
 scalar_t__ le16_to_cpu (int /*<<< orphan*/ ) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy_fromio (void*,scalar_t__,int const) ; 
 scalar_t__ msecs_to_jiffies (int) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  rt2800_config (struct rt2x00_dev*,struct rt2x00lib_conf*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rt2800_disable_wpdma (struct rt2x00_dev*) ; 
 int rt2800_enable_radio (struct rt2x00_dev*) ; 
 int /*<<< orphan*/  rt2800_get_txwi_rxwi_size (struct rt2x00_dev*,unsigned short*,unsigned short*) ; 
 int /*<<< orphan*/  rt2800_process_rxwi (struct queue_entry*,struct rxdone_entry_desc*) ; 
 int /*<<< orphan*/  rt2800_txdone_entry (struct queue_entry*,int,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  rt2800_wait_wpdma_ready (struct rt2x00_dev*) ; 
 int rt2x00_get_field32 (int,struct rt2x00_field32) ; 
 int /*<<< orphan*/  rt2x00_info (struct rt2x00_dev*,char*,scalar_t__,...) ; 
 int /*<<< orphan*/  rt2x00_set_field32 (int*,struct rt2x00_field32,unsigned int const) ; 
 int /*<<< orphan*/  rt2x00_warn (struct rt2x00_dev*,char*,...) ; 
 int /*<<< orphan*/  rt2x00lib_beacondone (struct rt2x00_dev*) ; 
 int /*<<< orphan*/  rt2x00lib_pretbtt (struct rt2x00_dev*) ; 
 scalar_t__ rt2x00mmio_rxdone (struct rt2x00_dev*) ; 
 int /*<<< orphan*/  rt2x00queue_for_each_entry (struct data_queue*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int (*) (struct queue_entry*,void*)) ; 
 struct queue_entry* rt2x00queue_get_entry (struct data_queue*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_bit (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int stub1 (struct rt2x00_dev*,unsigned int const) ; 
 int stub10 (struct rt2x00_dev*,size_t const*,size_t const) ; 
 int stub11 (struct rt2x00_dev*) ; 
 int /*<<< orphan*/ * stub12 (struct queue_entry*) ; 
 int stub2 (struct rt2x00_dev*,unsigned int const) ; 
 int /*<<< orphan*/  stub3 (struct rt2x00_dev*,unsigned int const,int) ; 
 int /*<<< orphan*/  stub4 (struct rt2x00_dev*,unsigned int const,int) ; 
 int /*<<< orphan*/  stub5 (struct rt2x00_dev*,unsigned int const,void*,int const) ; 
 int /*<<< orphan*/  stub6 (struct rt2x00_dev*,unsigned int const,void const*,int const) ; 
 int stub7 (struct rt2x00_dev*,unsigned int const,struct rt2x00_field32 const,int*) ; 
 int stub8 (struct rt2x00_dev*) ; 
 int stub9 (struct rt2x00_dev*) ; 
 int /*<<< orphan*/  tasklet_hi_schedule (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tasklet_kill (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tasklet_schedule (int /*<<< orphan*/ *) ; 
 int test_bit (int,int /*<<< orphan*/ *) ; 
 int time_after (int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static inline struct skb_frame_desc* get_skb_frame_desc(struct sk_buff *skb)
{
	BUILD_BUG_ON(sizeof(struct skb_frame_desc) >
		     IEEE80211_TX_INFO_DRIVER_DATA_SIZE);
	return (struct skb_frame_desc *)&IEEE80211_SKB_CB(skb)->driver_data;
}

__attribute__((used)) static inline int rt2x00queue_empty(struct data_queue *queue)
{
	return queue->length == 0;
}

__attribute__((used)) static inline int rt2x00queue_full(struct data_queue *queue)
{
	return queue->length == queue->limit;
}

__attribute__((used)) static inline int rt2x00queue_available(struct data_queue *queue)
{
	return queue->limit - queue->length;
}

__attribute__((used)) static inline int rt2x00queue_threshold(struct data_queue *queue)
{
	return rt2x00queue_available(queue) < queue->threshold;
}

__attribute__((used)) static inline int rt2x00queue_dma_timeout(struct queue_entry *entry)
{
	if (!test_bit(ENTRY_OWNER_DEVICE_DATA, &entry->flags))
		return false;
	return time_after(jiffies, entry->last_action + msecs_to_jiffies(100));
}

__attribute__((used)) static inline __le32 _rt2x00_desc_read(__le32 *desc, const u8 word)
{
	return desc[word];
}

__attribute__((used)) static inline u32 rt2x00_desc_read(__le32 *desc, const u8 word)
{
	return le32_to_cpu(_rt2x00_desc_read(desc, word));
}

__attribute__((used)) static inline void _rt2x00_desc_write(__le32 *desc, const u8 word, __le32 value)
{
	desc[word] = value;
}

__attribute__((used)) static inline void rt2x00_desc_write(__le32 *desc, const u8 word, u32 value)
{
	_rt2x00_desc_write(desc, word, cpu_to_le32(value));
}

__attribute__((used)) static inline struct rt2x00_intf* vif_to_intf(struct ieee80211_vif *vif)
{
	return (struct rt2x00_intf *)vif->drv_priv;
}

__attribute__((used)) static inline struct rt2x00_sta* sta_to_rt2x00_sta(struct ieee80211_sta *sta)
{
	return (struct rt2x00_sta *)sta->drv_priv;
}

__attribute__((used)) static inline u32 rt2x00_rf_read(struct rt2x00_dev *rt2x00dev,
				 const unsigned int word)
{
	BUG_ON(word < 1 || word > rt2x00dev->ops->rf_size / sizeof(u32));
	return rt2x00dev->rf[word - 1];
}

__attribute__((used)) static inline void rt2x00_rf_write(struct rt2x00_dev *rt2x00dev,
				   const unsigned int word, u32 data)
{
	BUG_ON(word < 1 || word > rt2x00dev->ops->rf_size / sizeof(u32));
	rt2x00dev->rf[word - 1] = data;
}

__attribute__((used)) static inline void *rt2x00_eeprom_addr(struct rt2x00_dev *rt2x00dev,
				       const unsigned int word)
{
	return (void *)&rt2x00dev->eeprom[word];
}

__attribute__((used)) static inline u16 rt2x00_eeprom_read(struct rt2x00_dev *rt2x00dev,
				     const unsigned int word)
{
	return le16_to_cpu(rt2x00dev->eeprom[word]);
}

__attribute__((used)) static inline void rt2x00_eeprom_write(struct rt2x00_dev *rt2x00dev,
				       const unsigned int word, u16 data)
{
	rt2x00dev->eeprom[word] = cpu_to_le16(data);
}

__attribute__((used)) static inline u8 rt2x00_eeprom_byte(struct rt2x00_dev *rt2x00dev,
				    const unsigned int byte)
{
	return *(((u8 *)rt2x00dev->eeprom) + byte);
}

__attribute__((used)) static inline void rt2x00_set_chip(struct rt2x00_dev *rt2x00dev,
				   const u16 rt, const u16 rf, const u16 rev)
{
	rt2x00dev->chip.rt = rt;
	rt2x00dev->chip.rf = rf;
	rt2x00dev->chip.rev = rev;

	rt2x00_info(rt2x00dev, "Chipset detected - rt: %04x, rf: %04x, rev: %04x\n",
		    rt2x00dev->chip.rt, rt2x00dev->chip.rf,
		    rt2x00dev->chip.rev);
}

__attribute__((used)) static inline void rt2x00_set_rt(struct rt2x00_dev *rt2x00dev,
				 const u16 rt, const u16 rev)
{
	rt2x00dev->chip.rt = rt;
	rt2x00dev->chip.rev = rev;

	rt2x00_info(rt2x00dev, "RT chipset %04x, rev %04x detected\n",
		    rt2x00dev->chip.rt, rt2x00dev->chip.rev);
}

__attribute__((used)) static inline void rt2x00_set_rf(struct rt2x00_dev *rt2x00dev, const u16 rf)
{
	rt2x00dev->chip.rf = rf;

	rt2x00_info(rt2x00dev, "RF chipset %04x detected\n",
		    rt2x00dev->chip.rf);
}

__attribute__((used)) static inline bool rt2x00_rt(struct rt2x00_dev *rt2x00dev, const u16 rt)
{
	return (rt2x00dev->chip.rt == rt);
}

__attribute__((used)) static inline bool rt2x00_rf(struct rt2x00_dev *rt2x00dev, const u16 rf)
{
	return (rt2x00dev->chip.rf == rf);
}

__attribute__((used)) static inline u16 rt2x00_rev(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00dev->chip.rev;
}

__attribute__((used)) static inline bool rt2x00_rt_rev(struct rt2x00_dev *rt2x00dev,
				 const u16 rt, const u16 rev)
{
	return (rt2x00_rt(rt2x00dev, rt) && rt2x00_rev(rt2x00dev) == rev);
}

__attribute__((used)) static inline bool rt2x00_rt_rev_lt(struct rt2x00_dev *rt2x00dev,
				    const u16 rt, const u16 rev)
{
	return (rt2x00_rt(rt2x00dev, rt) && rt2x00_rev(rt2x00dev) < rev);
}

__attribute__((used)) static inline bool rt2x00_rt_rev_gte(struct rt2x00_dev *rt2x00dev,
				     const u16 rt, const u16 rev)
{
	return (rt2x00_rt(rt2x00dev, rt) && rt2x00_rev(rt2x00dev) >= rev);
}

__attribute__((used)) static inline void rt2x00_set_chip_intf(struct rt2x00_dev *rt2x00dev,
					enum rt2x00_chip_intf intf)
{
	rt2x00dev->chip.intf = intf;
}

__attribute__((used)) static inline bool rt2x00_intf(struct rt2x00_dev *rt2x00dev,
			       enum rt2x00_chip_intf intf)
{
	return (rt2x00dev->chip.intf == intf);
}

__attribute__((used)) static inline bool rt2x00_is_pci(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_intf(rt2x00dev, RT2X00_CHIP_INTF_PCI) ||
	       rt2x00_intf(rt2x00dev, RT2X00_CHIP_INTF_PCIE);
}

__attribute__((used)) static inline bool rt2x00_is_pcie(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_intf(rt2x00dev, RT2X00_CHIP_INTF_PCIE);
}

__attribute__((used)) static inline bool rt2x00_is_usb(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_intf(rt2x00dev, RT2X00_CHIP_INTF_USB);
}

__attribute__((used)) static inline bool rt2x00_is_soc(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_intf(rt2x00dev, RT2X00_CHIP_INTF_SOC);
}

__attribute__((used)) static inline bool
rt2x00_has_cap_flag(struct rt2x00_dev *rt2x00dev,
		    enum rt2x00_capability_flags cap_flag)
{
	return test_bit(cap_flag, &rt2x00dev->cap_flags);
}

__attribute__((used)) static inline bool
rt2x00_has_cap_hw_crypto(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_has_cap_flag(rt2x00dev, CAPABILITY_HW_CRYPTO);
}

__attribute__((used)) static inline bool
rt2x00_has_cap_power_limit(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_has_cap_flag(rt2x00dev, CAPABILITY_POWER_LIMIT);
}

__attribute__((used)) static inline bool
rt2x00_has_cap_control_filters(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_has_cap_flag(rt2x00dev, CAPABILITY_CONTROL_FILTERS);
}

__attribute__((used)) static inline bool
rt2x00_has_cap_control_filter_pspoll(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_has_cap_flag(rt2x00dev, CAPABILITY_CONTROL_FILTER_PSPOLL);
}

__attribute__((used)) static inline bool
rt2x00_has_cap_pre_tbtt_interrupt(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_has_cap_flag(rt2x00dev, CAPABILITY_PRE_TBTT_INTERRUPT);
}

__attribute__((used)) static inline bool
rt2x00_has_cap_link_tuning(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_has_cap_flag(rt2x00dev, CAPABILITY_LINK_TUNING);
}

__attribute__((used)) static inline bool
rt2x00_has_cap_frame_type(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_has_cap_flag(rt2x00dev, CAPABILITY_FRAME_TYPE);
}

__attribute__((used)) static inline bool
rt2x00_has_cap_rf_sequence(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_has_cap_flag(rt2x00dev, CAPABILITY_RF_SEQUENCE);
}

__attribute__((used)) static inline bool
rt2x00_has_cap_external_lna_a(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_has_cap_flag(rt2x00dev, CAPABILITY_EXTERNAL_LNA_A);
}

__attribute__((used)) static inline bool
rt2x00_has_cap_external_lna_bg(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_has_cap_flag(rt2x00dev, CAPABILITY_EXTERNAL_LNA_BG);
}

__attribute__((used)) static inline bool
rt2x00_has_cap_double_antenna(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_has_cap_flag(rt2x00dev, CAPABILITY_DOUBLE_ANTENNA);
}

__attribute__((used)) static inline bool
rt2x00_has_cap_bt_coexist(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_has_cap_flag(rt2x00dev, CAPABILITY_BT_COEXIST);
}

__attribute__((used)) static inline bool
rt2x00_has_cap_vco_recalibration(struct rt2x00_dev *rt2x00dev)
{
	return rt2x00_has_cap_flag(rt2x00dev, CAPABILITY_VCO_RECALIBRATION);
}

__attribute__((used)) static inline struct data_queue *
rt2x00queue_get_tx_queue(struct rt2x00_dev *rt2x00dev,
			 const enum data_queue_qid queue)
{
	if (queue < rt2x00dev->ops->tx_queues && rt2x00dev->tx)
		return &rt2x00dev->tx[queue];

	if (queue == QID_ATIM)
		return rt2x00dev->atim;

	return NULL;
}

__attribute__((used)) static inline void rt2x00debug_dump_frame(struct rt2x00_dev *rt2x00dev,
					  enum rt2x00_dump_type type,
					  struct queue_entry *entry)
{
}

__attribute__((used)) static inline u32 rt2x00mmio_register_read(struct rt2x00_dev *rt2x00dev,
					   const unsigned int offset)
{
	return readl(rt2x00dev->csr.base + offset);
}

__attribute__((used)) static inline void rt2x00mmio_register_multiread(struct rt2x00_dev *rt2x00dev,
						 const unsigned int offset,
						 void *value, const u32 length)
{
	memcpy_fromio(value, rt2x00dev->csr.base + offset, length);
}

__attribute__((used)) static inline void rt2x00mmio_register_write(struct rt2x00_dev *rt2x00dev,
					     const unsigned int offset,
					     u32 value)
{
	writel(value, rt2x00dev->csr.base + offset);
}

__attribute__((used)) static inline void rt2x00mmio_register_multiwrite(struct rt2x00_dev *rt2x00dev,
						  const unsigned int offset,
						  const void *value,
						  const u32 length)
{
	__iowrite32_copy(rt2x00dev->csr.base + offset, value, length >> 2);
}

__attribute__((used)) static inline u32 rt2800_register_read(struct rt2x00_dev *rt2x00dev,
				       const unsigned int offset)
{
	const struct rt2800_ops *rt2800ops = rt2x00dev->ops->drv;

	return rt2800ops->register_read(rt2x00dev, offset);
}

__attribute__((used)) static inline u32 rt2800_register_read_lock(struct rt2x00_dev *rt2x00dev,
					    const unsigned int offset)
{
	const struct rt2800_ops *rt2800ops = rt2x00dev->ops->drv;

	return rt2800ops->register_read_lock(rt2x00dev, offset);
}

__attribute__((used)) static inline void rt2800_register_write(struct rt2x00_dev *rt2x00dev,
					 const unsigned int offset,
					 u32 value)
{
	const struct rt2800_ops *rt2800ops = rt2x00dev->ops->drv;

	rt2800ops->register_write(rt2x00dev, offset, value);
}

__attribute__((used)) static inline void rt2800_register_write_lock(struct rt2x00_dev *rt2x00dev,
					      const unsigned int offset,
					      u32 value)
{
	const struct rt2800_ops *rt2800ops = rt2x00dev->ops->drv;

	rt2800ops->register_write_lock(rt2x00dev, offset, value);
}

__attribute__((used)) static inline void rt2800_register_multiread(struct rt2x00_dev *rt2x00dev,
					     const unsigned int offset,
					     void *value, const u32 length)
{
	const struct rt2800_ops *rt2800ops = rt2x00dev->ops->drv;

	rt2800ops->register_multiread(rt2x00dev, offset, value, length);
}

__attribute__((used)) static inline void rt2800_register_multiwrite(struct rt2x00_dev *rt2x00dev,
					      const unsigned int offset,
					      const void *value,
					      const u32 length)
{
	const struct rt2800_ops *rt2800ops = rt2x00dev->ops->drv;

	rt2800ops->register_multiwrite(rt2x00dev, offset, value, length);
}

__attribute__((used)) static inline int rt2800_regbusy_read(struct rt2x00_dev *rt2x00dev,
				      const unsigned int offset,
				      const struct rt2x00_field32 field,
				      u32 *reg)
{
	const struct rt2800_ops *rt2800ops = rt2x00dev->ops->drv;

	return rt2800ops->regbusy_read(rt2x00dev, offset, field, reg);
}

__attribute__((used)) static inline int rt2800_read_eeprom(struct rt2x00_dev *rt2x00dev)
{
	const struct rt2800_ops *rt2800ops = rt2x00dev->ops->drv;

	return rt2800ops->read_eeprom(rt2x00dev);
}

__attribute__((used)) static inline bool rt2800_hwcrypt_disabled(struct rt2x00_dev *rt2x00dev)
{
	const struct rt2800_ops *rt2800ops = rt2x00dev->ops->drv;

	return rt2800ops->hwcrypt_disabled(rt2x00dev);
}

__attribute__((used)) static inline int rt2800_drv_write_firmware(struct rt2x00_dev *rt2x00dev,
					    const u8 *data, const size_t len)
{
	const struct rt2800_ops *rt2800ops = rt2x00dev->ops->drv;

	return rt2800ops->drv_write_firmware(rt2x00dev, data, len);
}

__attribute__((used)) static inline int rt2800_drv_init_registers(struct rt2x00_dev *rt2x00dev)
{
	const struct rt2800_ops *rt2800ops = rt2x00dev->ops->drv;

	return rt2800ops->drv_init_registers(rt2x00dev);
}

__attribute__((used)) static inline __le32 *rt2800_drv_get_txwi(struct queue_entry *entry)
{
	const struct rt2800_ops *rt2800ops = entry->queue->rt2x00dev->ops->drv;

	return rt2800ops->drv_get_txwi(entry);
}

__le32 *rt2800mmio_get_txwi(struct queue_entry *entry)
{
	return (__le32 *) entry->skb->data;
}

void rt2800mmio_write_tx_desc(struct queue_entry *entry,
			      struct txentry_desc *txdesc)
{
	struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
	struct queue_entry_priv_mmio *entry_priv = entry->priv_data;
	__le32 *txd = entry_priv->desc;
	u32 word;
	const unsigned int txwi_size = entry->queue->winfo_size;

	/*
	 * The buffers pointed by SD_PTR0/SD_LEN0 and SD_PTR1/SD_LEN1
	 * must contains a TXWI structure + 802.11 header + padding + 802.11
	 * data. We choose to have SD_PTR0/SD_LEN0 only contains TXWI and
	 * SD_PTR1/SD_LEN1 contains 802.11 header + padding + 802.11
	 * data. It means that LAST_SEC0 is always 0.
	 */

	/*
	 * Initialize TX descriptor
	 */
	word = 0;
	rt2x00_set_field32(&word, TXD_W0_SD_PTR0, skbdesc->skb_dma);
	rt2x00_desc_write(txd, 0, word);

	word = 0;
	rt2x00_set_field32(&word, TXD_W1_SD_LEN1, entry->skb->len);
	rt2x00_set_field32(&word, TXD_W1_LAST_SEC1,
			   !test_bit(ENTRY_TXD_MORE_FRAG, &txdesc->flags));
	rt2x00_set_field32(&word, TXD_W1_BURST,
			   test_bit(ENTRY_TXD_BURST, &txdesc->flags));
	rt2x00_set_field32(&word, TXD_W1_SD_LEN0, txwi_size);
	rt2x00_set_field32(&word, TXD_W1_LAST_SEC0, 0);
	rt2x00_set_field32(&word, TXD_W1_DMA_DONE, 0);
	rt2x00_desc_write(txd, 1, word);

	word = 0;
	rt2x00_set_field32(&word, TXD_W2_SD_PTR1,
			   skbdesc->skb_dma + txwi_size);
	rt2x00_desc_write(txd, 2, word);

	word = 0;
	rt2x00_set_field32(&word, TXD_W3_WIV,
			   !test_bit(ENTRY_TXD_ENCRYPT_IV, &txdesc->flags));
	rt2x00_set_field32(&word, TXD_W3_QSEL, 2);
	rt2x00_desc_write(txd, 3, word);

	/*
	 * Register descriptor details in skb frame descriptor.
	 */
	skbdesc->desc = txd;
	skbdesc->desc_len = TXD_DESC_SIZE;
}

void rt2800mmio_fill_rxdone(struct queue_entry *entry,
			    struct rxdone_entry_desc *rxdesc)
{
	struct queue_entry_priv_mmio *entry_priv = entry->priv_data;
	__le32 *rxd = entry_priv->desc;
	u32 word;

	word = rt2x00_desc_read(rxd, 3);

	if (rt2x00_get_field32(word, RXD_W3_CRC_ERROR))
		rxdesc->flags |= RX_FLAG_FAILED_FCS_CRC;

	/*
	 * Unfortunately we don't know the cipher type used during
	 * decryption. This prevents us from correct providing
	 * correct statistics through debugfs.
	 */
	rxdesc->cipher_status = rt2x00_get_field32(word, RXD_W3_CIPHER_ERROR);

	if (rt2x00_get_field32(word, RXD_W3_DECRYPTED)) {
		/*
		 * Hardware has stripped IV/EIV data from 802.11 frame during
		 * decryption. Unfortunately the descriptor doesn't contain
		 * any fields with the EIV/IV data either, so they can't
		 * be restored by rt2x00lib.
		 */
		rxdesc->flags |= RX_FLAG_IV_STRIPPED;

		/*
		 * The hardware has already checked the Michael Mic and has
		 * stripped it from the frame. Signal this to mac80211.
		 */
		rxdesc->flags |= RX_FLAG_MMIC_STRIPPED;

		if (rxdesc->cipher_status == RX_CRYPTO_SUCCESS) {
			rxdesc->flags |= RX_FLAG_DECRYPTED;
		} else if (rxdesc->cipher_status == RX_CRYPTO_FAIL_MIC) {
			/*
			 * In order to check the Michael Mic, the packet must have
			 * been decrypted.  Mac80211 doesnt check the MMIC failure 
			 * flag to initiate MMIC countermeasures if the decoded flag
			 * has not been set.
			 */
			rxdesc->flags |= RX_FLAG_DECRYPTED;

			rxdesc->flags |= RX_FLAG_MMIC_ERROR;
		}
	}

	if (rt2x00_get_field32(word, RXD_W3_MY_BSS))
		rxdesc->dev_flags |= RXDONE_MY_BSS;

	if (rt2x00_get_field32(word, RXD_W3_L2PAD))
		rxdesc->dev_flags |= RXDONE_L2PAD;

	/*
	 * Process the RXWI structure that is at the start of the buffer.
	 */
	rt2800_process_rxwi(entry, rxdesc);
}

__attribute__((used)) static void rt2800mmio_wakeup(struct rt2x00_dev *rt2x00dev)
{
	struct ieee80211_conf conf = { .flags = 0 };
	struct rt2x00lib_conf libconf = { .conf = &conf };

	rt2800_config(rt2x00dev, &libconf, IEEE80211_CONF_CHANGE_PS);
}

__attribute__((used)) static bool rt2800mmio_txdone_entry_check(struct queue_entry *entry, u32 status)
{
	__le32 *txwi;
	u32 word;
	int wcid, tx_wcid;

	wcid = rt2x00_get_field32(status, TX_STA_FIFO_WCID);

	txwi = rt2800_drv_get_txwi(entry);
	word = rt2x00_desc_read(txwi, 1);
	tx_wcid = rt2x00_get_field32(word, TXWI_W1_WIRELESS_CLI_ID);

	return (tx_wcid == wcid);
}

__attribute__((used)) static bool rt2800mmio_txdone_find_entry(struct queue_entry *entry, void *data)
{
	u32 status = *(u32 *)data;

	/*
	 * rt2800pci hardware might reorder frames when exchanging traffic
	 * with multiple BA enabled STAs.
	 *
	 * For example, a tx queue
	 *    [ STA1 | STA2 | STA1 | STA2 ]
	 * can result in tx status reports
	 *    [ STA1 | STA1 | STA2 | STA2 ]
	 * when the hw decides to aggregate the frames for STA1 into one AMPDU.
	 *
	 * To mitigate this effect, associate the tx status to the first frame
	 * in the tx queue with a matching wcid.
	 */
	if (rt2800mmio_txdone_entry_check(entry, status) &&
	    !test_bit(ENTRY_DATA_STATUS_SET, &entry->flags)) {
		/*
		 * Got a matching frame, associate the tx status with
		 * the frame
		 */
		entry->status = status;
		set_bit(ENTRY_DATA_STATUS_SET, &entry->flags);
		return true;
	}

	/* Check the next frame */
	return false;
}

__attribute__((used)) static bool rt2800mmio_txdone_match_first(struct queue_entry *entry, void *data)
{
	u32 status = *(u32 *)data;

	/*
	 * Find the first frame without tx status and assign this status to it
	 * regardless if it matches or not.
	 */
	if (!test_bit(ENTRY_DATA_STATUS_SET, &entry->flags)) {
		/*
		 * Got a matching frame, associate the tx status with
		 * the frame
		 */
		entry->status = status;
		set_bit(ENTRY_DATA_STATUS_SET, &entry->flags);
		return true;
	}

	/* Check the next frame */
	return false;
}

__attribute__((used)) static bool rt2800mmio_txdone_release_entries(struct queue_entry *entry,
					      void *data)
{
	if (test_bit(ENTRY_DATA_STATUS_SET, &entry->flags)) {
		rt2800_txdone_entry(entry, entry->status,
				    rt2800mmio_get_txwi(entry), true);
		return false;
	}

	/* No more frames to release */
	return true;
}

__attribute__((used)) static bool rt2800mmio_txdone(struct rt2x00_dev *rt2x00dev)
{
	struct data_queue *queue;
	u32 status;
	u8 qid;
	int max_tx_done = 16;

	while (kfifo_get(&rt2x00dev->txstatus_fifo, &status)) {
		qid = rt2x00_get_field32(status, TX_STA_FIFO_PID_QUEUE);
		if (unlikely(qid >= QID_RX)) {
			/*
			 * Unknown queue, this shouldn't happen. Just drop
			 * this tx status.
			 */
			rt2x00_warn(rt2x00dev, "Got TX status report with unexpected pid %u, dropping\n",
				    qid);
			break;
		}

		queue = rt2x00queue_get_tx_queue(rt2x00dev, qid);
		if (unlikely(queue == NULL)) {
			/*
			 * The queue is NULL, this shouldn't happen. Stop
			 * processing here and drop the tx status
			 */
			rt2x00_warn(rt2x00dev, "Got TX status for an unavailable queue %u, dropping\n",
				    qid);
			break;
		}

		if (unlikely(rt2x00queue_empty(queue))) {
			/*
			 * The queue is empty. Stop processing here
			 * and drop the tx status.
			 */
			rt2x00_warn(rt2x00dev, "Got TX status for an empty queue %u, dropping\n",
				    qid);
			break;
		}

		/*
		 * Let's associate this tx status with the first
		 * matching frame.
		 */
		if (!rt2x00queue_for_each_entry(queue, Q_INDEX_DONE,
						Q_INDEX, &status,
						rt2800mmio_txdone_find_entry)) {
			/*
			 * We cannot match the tx status to any frame, so just
			 * use the first one.
			 */
			if (!rt2x00queue_for_each_entry(queue, Q_INDEX_DONE,
							Q_INDEX, &status,
							rt2800mmio_txdone_match_first)) {
				rt2x00_warn(rt2x00dev, "No frame found for TX status on queue %u, dropping\n",
					    qid);
				break;
			}
		}

		/*
		 * Release all frames with a valid tx status.
		 */
		rt2x00queue_for_each_entry(queue, Q_INDEX_DONE,
					   Q_INDEX, NULL,
					   rt2800mmio_txdone_release_entries);

		if (--max_tx_done == 0)
			break;
	}

	return !max_tx_done;
}

__attribute__((used)) static inline void rt2800mmio_enable_interrupt(struct rt2x00_dev *rt2x00dev,
					       struct rt2x00_field32 irq_field)
{
	u32 reg;

	/*
	 * Enable a single interrupt. The interrupt mask register
	 * access needs locking.
	 */
	spin_lock_irq(&rt2x00dev->irqmask_lock);
	reg = rt2x00mmio_register_read(rt2x00dev, INT_MASK_CSR);
	rt2x00_set_field32(&reg, irq_field, 1);
	rt2x00mmio_register_write(rt2x00dev, INT_MASK_CSR, reg);
	spin_unlock_irq(&rt2x00dev->irqmask_lock);
}

void rt2800mmio_txstatus_tasklet(unsigned long data)
{
	struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
	if (rt2800mmio_txdone(rt2x00dev))
		tasklet_schedule(&rt2x00dev->txstatus_tasklet);

	/*
	 * No need to enable the tx status interrupt here as we always
	 * leave it enabled to minimize the possibility of a tx status
	 * register overflow. See comment in interrupt handler.
	 */
}

void rt2800mmio_pretbtt_tasklet(unsigned long data)
{
	struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
	rt2x00lib_pretbtt(rt2x00dev);
	if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
		rt2800mmio_enable_interrupt(rt2x00dev, INT_MASK_CSR_PRE_TBTT);
}

void rt2800mmio_tbtt_tasklet(unsigned long data)
{
	struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
	struct rt2800_drv_data *drv_data = rt2x00dev->drv_data;
	u32 reg;

	rt2x00lib_beacondone(rt2x00dev);

	if (rt2x00dev->intf_ap_count) {
		/*
		 * The rt2800pci hardware tbtt timer is off by 1us per tbtt
		 * causing beacon skew and as a result causing problems with
		 * some powersaving clients over time. Shorten the beacon
		 * interval every 64 beacons by 64us to mitigate this effect.
		 */
		if (drv_data->tbtt_tick == (BCN_TBTT_OFFSET - 2)) {
			reg = rt2x00mmio_register_read(rt2x00dev, BCN_TIME_CFG);
			rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_INTERVAL,
					   (rt2x00dev->beacon_int * 16) - 1);
			rt2x00mmio_register_write(rt2x00dev, BCN_TIME_CFG, reg);
		} else if (drv_data->tbtt_tick == (BCN_TBTT_OFFSET - 1)) {
			reg = rt2x00mmio_register_read(rt2x00dev, BCN_TIME_CFG);
			rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_INTERVAL,
					   (rt2x00dev->beacon_int * 16));
			rt2x00mmio_register_write(rt2x00dev, BCN_TIME_CFG, reg);
		}
		drv_data->tbtt_tick++;
		drv_data->tbtt_tick %= BCN_TBTT_OFFSET;
	}

	if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
		rt2800mmio_enable_interrupt(rt2x00dev, INT_MASK_CSR_TBTT);
}

void rt2800mmio_rxdone_tasklet(unsigned long data)
{
	struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
	if (rt2x00mmio_rxdone(rt2x00dev))
		tasklet_schedule(&rt2x00dev->rxdone_tasklet);
	else if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
		rt2800mmio_enable_interrupt(rt2x00dev, INT_MASK_CSR_RX_DONE);
}

void rt2800mmio_autowake_tasklet(unsigned long data)
{
	struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
	rt2800mmio_wakeup(rt2x00dev);
	if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
		rt2800mmio_enable_interrupt(rt2x00dev,
					    INT_MASK_CSR_AUTO_WAKEUP);
}

__attribute__((used)) static void rt2800mmio_txstatus_interrupt(struct rt2x00_dev *rt2x00dev)
{
	u32 status;
	int i;

	/*
	 * The TX_FIFO_STATUS interrupt needs special care. We should
	 * read TX_STA_FIFO but we should do it immediately as otherwise
	 * the register can overflow and we would lose status reports.
	 *
	 * Hence, read the TX_STA_FIFO register and copy all tx status
	 * reports into a kernel FIFO which is handled in the txstatus
	 * tasklet. We use a tasklet to process the tx status reports
	 * because we can schedule the tasklet multiple times (when the
	 * interrupt fires again during tx status processing).
	 *
	 * Furthermore we don't disable the TX_FIFO_STATUS
	 * interrupt here but leave it enabled so that the TX_STA_FIFO
	 * can also be read while the tx status tasklet gets executed.
	 *
	 * Since we have only one producer and one consumer we don't
	 * need to lock the kfifo.
	 */
	for (i = 0; i < rt2x00dev->tx->limit; i++) {
		status = rt2x00mmio_register_read(rt2x00dev, TX_STA_FIFO);

		if (!rt2x00_get_field32(status, TX_STA_FIFO_VALID))
			break;

		if (!kfifo_put(&rt2x00dev->txstatus_fifo, status)) {
			rt2x00_warn(rt2x00dev, "TX status FIFO overrun, drop tx status report\n");
			break;
		}
	}

	/* Schedule the tasklet for processing the tx status. */
	tasklet_schedule(&rt2x00dev->txstatus_tasklet);
}

irqreturn_t rt2800mmio_interrupt(int irq, void *dev_instance)
{
	struct rt2x00_dev *rt2x00dev = dev_instance;
	u32 reg, mask;

	/* Read status and ACK all interrupts */
	reg = rt2x00mmio_register_read(rt2x00dev, INT_SOURCE_CSR);
	rt2x00mmio_register_write(rt2x00dev, INT_SOURCE_CSR, reg);

	if (!reg)
		return IRQ_NONE;

	if (!test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
		return IRQ_HANDLED;

	/*
	 * Since INT_MASK_CSR and INT_SOURCE_CSR use the same bits
	 * for interrupts and interrupt masks we can just use the value of
	 * INT_SOURCE_CSR to create the interrupt mask.
	 */
	mask = ~reg;

	if (rt2x00_get_field32(reg, INT_SOURCE_CSR_TX_FIFO_STATUS)) {
		rt2800mmio_txstatus_interrupt(rt2x00dev);
		/*
		 * Never disable the TX_FIFO_STATUS interrupt.
		 */
		rt2x00_set_field32(&mask, INT_MASK_CSR_TX_FIFO_STATUS, 1);
	}

	if (rt2x00_get_field32(reg, INT_SOURCE_CSR_PRE_TBTT))
		tasklet_hi_schedule(&rt2x00dev->pretbtt_tasklet);

	if (rt2x00_get_field32(reg, INT_SOURCE_CSR_TBTT))
		tasklet_hi_schedule(&rt2x00dev->tbtt_tasklet);

	if (rt2x00_get_field32(reg, INT_SOURCE_CSR_RX_DONE))
		tasklet_schedule(&rt2x00dev->rxdone_tasklet);

	if (rt2x00_get_field32(reg, INT_SOURCE_CSR_AUTO_WAKEUP))
		tasklet_schedule(&rt2x00dev->autowake_tasklet);

	/*
	 * Disable all interrupts for which a tasklet was scheduled right now,
	 * the tasklet will reenable the appropriate interrupts.
	 */
	spin_lock(&rt2x00dev->irqmask_lock);
	reg = rt2x00mmio_register_read(rt2x00dev, INT_MASK_CSR);
	reg &= mask;
	rt2x00mmio_register_write(rt2x00dev, INT_MASK_CSR, reg);
	spin_unlock(&rt2x00dev->irqmask_lock);

	return IRQ_HANDLED;
}

void rt2800mmio_toggle_irq(struct rt2x00_dev *rt2x00dev,
			   enum dev_state state)
{
	u32 reg;
	unsigned long flags;

	/*
	 * When interrupts are being enabled, the interrupt registers
	 * should clear the register to assure a clean state.
	 */
	if (state == STATE_RADIO_IRQ_ON) {
		reg = rt2x00mmio_register_read(rt2x00dev, INT_SOURCE_CSR);
		rt2x00mmio_register_write(rt2x00dev, INT_SOURCE_CSR, reg);
	}

	spin_lock_irqsave(&rt2x00dev->irqmask_lock, flags);
	reg = 0;
	if (state == STATE_RADIO_IRQ_ON) {
		rt2x00_set_field32(&reg, INT_MASK_CSR_RX_DONE, 1);
		rt2x00_set_field32(&reg, INT_MASK_CSR_TBTT, 1);
		rt2x00_set_field32(&reg, INT_MASK_CSR_PRE_TBTT, 1);
		rt2x00_set_field32(&reg, INT_MASK_CSR_TX_FIFO_STATUS, 1);
		rt2x00_set_field32(&reg, INT_MASK_CSR_AUTO_WAKEUP, 1);
	}
	rt2x00mmio_register_write(rt2x00dev, INT_MASK_CSR, reg);
	spin_unlock_irqrestore(&rt2x00dev->irqmask_lock, flags);

	if (state == STATE_RADIO_IRQ_OFF) {
		/*
		 * Wait for possibly running tasklets to finish.
		 */
		tasklet_kill(&rt2x00dev->txstatus_tasklet);
		tasklet_kill(&rt2x00dev->rxdone_tasklet);
		tasklet_kill(&rt2x00dev->autowake_tasklet);
		tasklet_kill(&rt2x00dev->tbtt_tasklet);
		tasklet_kill(&rt2x00dev->pretbtt_tasklet);
	}
}

void rt2800mmio_start_queue(struct data_queue *queue)
{
	struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
	u32 reg;

	switch (queue->qid) {
	case QID_RX:
		reg = rt2x00mmio_register_read(rt2x00dev, MAC_SYS_CTRL);
		rt2x00_set_field32(&reg, MAC_SYS_CTRL_ENABLE_RX, 1);
		rt2x00mmio_register_write(rt2x00dev, MAC_SYS_CTRL, reg);
		break;
	case QID_BEACON:
		reg = rt2x00mmio_register_read(rt2x00dev, BCN_TIME_CFG);
		rt2x00_set_field32(&reg, BCN_TIME_CFG_TSF_TICKING, 1);
		rt2x00_set_field32(&reg, BCN_TIME_CFG_TBTT_ENABLE, 1);
		rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_GEN, 1);
		rt2x00mmio_register_write(rt2x00dev, BCN_TIME_CFG, reg);

		reg = rt2x00mmio_register_read(rt2x00dev, INT_TIMER_EN);
		rt2x00_set_field32(&reg, INT_TIMER_EN_PRE_TBTT_TIMER, 1);
		rt2x00mmio_register_write(rt2x00dev, INT_TIMER_EN, reg);
		break;
	default:
		break;
	}
}

void rt2800mmio_kick_queue(struct data_queue *queue)
{
	struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
	struct queue_entry *entry;

	switch (queue->qid) {
	case QID_AC_VO:
	case QID_AC_VI:
	case QID_AC_BE:
	case QID_AC_BK:
		WARN_ON_ONCE(rt2x00queue_empty(queue));
		entry = rt2x00queue_get_entry(queue, Q_INDEX);
		rt2x00mmio_register_write(rt2x00dev, TX_CTX_IDX(queue->qid),
					  entry->entry_idx);
		break;
	case QID_MGMT:
		entry = rt2x00queue_get_entry(queue, Q_INDEX);
		rt2x00mmio_register_write(rt2x00dev, TX_CTX_IDX(5),
					  entry->entry_idx);
		break;
	default:
		break;
	}
}

void rt2800mmio_stop_queue(struct data_queue *queue)
{
	struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
	u32 reg;

	switch (queue->qid) {
	case QID_RX:
		reg = rt2x00mmio_register_read(rt2x00dev, MAC_SYS_CTRL);
		rt2x00_set_field32(&reg, MAC_SYS_CTRL_ENABLE_RX, 0);
		rt2x00mmio_register_write(rt2x00dev, MAC_SYS_CTRL, reg);
		break;
	case QID_BEACON:
		reg = rt2x00mmio_register_read(rt2x00dev, BCN_TIME_CFG);
		rt2x00_set_field32(&reg, BCN_TIME_CFG_TSF_TICKING, 0);
		rt2x00_set_field32(&reg, BCN_TIME_CFG_TBTT_ENABLE, 0);
		rt2x00_set_field32(&reg, BCN_TIME_CFG_BEACON_GEN, 0);
		rt2x00mmio_register_write(rt2x00dev, BCN_TIME_CFG, reg);

		reg = rt2x00mmio_register_read(rt2x00dev, INT_TIMER_EN);
		rt2x00_set_field32(&reg, INT_TIMER_EN_PRE_TBTT_TIMER, 0);
		rt2x00mmio_register_write(rt2x00dev, INT_TIMER_EN, reg);

		/*
		 * Wait for current invocation to finish. The tasklet
		 * won't be scheduled anymore afterwards since we disabled
		 * the TBTT and PRE TBTT timer.
		 */
		tasklet_kill(&rt2x00dev->tbtt_tasklet);
		tasklet_kill(&rt2x00dev->pretbtt_tasklet);

		break;
	default:
		break;
	}
}

void rt2800mmio_queue_init(struct data_queue *queue)
{
	struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
	unsigned short txwi_size, rxwi_size;

	rt2800_get_txwi_rxwi_size(rt2x00dev, &txwi_size, &rxwi_size);

	switch (queue->qid) {
	case QID_RX:
		queue->limit = 128;
		queue->data_size = AGGREGATION_SIZE;
		queue->desc_size = RXD_DESC_SIZE;
		queue->winfo_size = rxwi_size;
		queue->priv_size = sizeof(struct queue_entry_priv_mmio);
		break;

	case QID_AC_VO:
	case QID_AC_VI:
	case QID_AC_BE:
	case QID_AC_BK:
		queue->limit = 64;
		queue->data_size = AGGREGATION_SIZE;
		queue->desc_size = TXD_DESC_SIZE;
		queue->winfo_size = txwi_size;
		queue->priv_size = sizeof(struct queue_entry_priv_mmio);
		break;

	case QID_BEACON:
		queue->limit = 8;
		queue->data_size = 0; /* No DMA required for beacons */
		queue->desc_size = TXD_DESC_SIZE;
		queue->winfo_size = txwi_size;
		queue->priv_size = sizeof(struct queue_entry_priv_mmio);
		break;

	case QID_ATIM:
		/* fallthrough */
	default:
		BUG();
		break;
	}
}

bool rt2800mmio_get_entry_state(struct queue_entry *entry)
{
	struct queue_entry_priv_mmio *entry_priv = entry->priv_data;
	u32 word;

	if (entry->queue->qid == QID_RX) {
		word = rt2x00_desc_read(entry_priv->desc, 1);

		return (!rt2x00_get_field32(word, RXD_W1_DMA_DONE));
	} else {
		word = rt2x00_desc_read(entry_priv->desc, 1);

		return (!rt2x00_get_field32(word, TXD_W1_DMA_DONE));
	}
}

void rt2800mmio_clear_entry(struct queue_entry *entry)
{
	struct queue_entry_priv_mmio *entry_priv = entry->priv_data;
	struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
	struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
	u32 word;

	if (entry->queue->qid == QID_RX) {
		word = rt2x00_desc_read(entry_priv->desc, 0);
		rt2x00_set_field32(&word, RXD_W0_SDP0, skbdesc->skb_dma);
		rt2x00_desc_write(entry_priv->desc, 0, word);

		word = rt2x00_desc_read(entry_priv->desc, 1);
		rt2x00_set_field32(&word, RXD_W1_DMA_DONE, 0);
		rt2x00_desc_write(entry_priv->desc, 1, word);

		/*
		 * Set RX IDX in register to inform hardware that we have
		 * handled this entry and it is available for reuse again.
		 */
		rt2x00mmio_register_write(rt2x00dev, RX_CRX_IDX,
					  entry->entry_idx);
	} else {
		word = rt2x00_desc_read(entry_priv->desc, 1);
		rt2x00_set_field32(&word, TXD_W1_DMA_DONE, 1);
		rt2x00_desc_write(entry_priv->desc, 1, word);
	}
}

int rt2800mmio_init_queues(struct rt2x00_dev *rt2x00dev)
{
	struct queue_entry_priv_mmio *entry_priv;

	/*
	 * Initialize registers.
	 */
	entry_priv = rt2x00dev->tx[0].entries[0].priv_data;
	rt2x00mmio_register_write(rt2x00dev, TX_BASE_PTR0,
				  entry_priv->desc_dma);
	rt2x00mmio_register_write(rt2x00dev, TX_MAX_CNT0,
				  rt2x00dev->tx[0].limit);
	rt2x00mmio_register_write(rt2x00dev, TX_CTX_IDX0, 0);
	rt2x00mmio_register_write(rt2x00dev, TX_DTX_IDX0, 0);

	entry_priv = rt2x00dev->tx[1].entries[0].priv_data;
	rt2x00mmio_register_write(rt2x00dev, TX_BASE_PTR1,
				  entry_priv->desc_dma);
	rt2x00mmio_register_write(rt2x00dev, TX_MAX_CNT1,
				  rt2x00dev->tx[1].limit);
	rt2x00mmio_register_write(rt2x00dev, TX_CTX_IDX1, 0);
	rt2x00mmio_register_write(rt2x00dev, TX_DTX_IDX1, 0);

	entry_priv = rt2x00dev->tx[2].entries[0].priv_data;
	rt2x00mmio_register_write(rt2x00dev, TX_BASE_PTR2,
				  entry_priv->desc_dma);
	rt2x00mmio_register_write(rt2x00dev, TX_MAX_CNT2,
				  rt2x00dev->tx[2].limit);
	rt2x00mmio_register_write(rt2x00dev, TX_CTX_IDX2, 0);
	rt2x00mmio_register_write(rt2x00dev, TX_DTX_IDX2, 0);

	entry_priv = rt2x00dev->tx[3].entries[0].priv_data;
	rt2x00mmio_register_write(rt2x00dev, TX_BASE_PTR3,
				  entry_priv->desc_dma);
	rt2x00mmio_register_write(rt2x00dev, TX_MAX_CNT3,
				  rt2x00dev->tx[3].limit);
	rt2x00mmio_register_write(rt2x00dev, TX_CTX_IDX3, 0);
	rt2x00mmio_register_write(rt2x00dev, TX_DTX_IDX3, 0);

	rt2x00mmio_register_write(rt2x00dev, TX_BASE_PTR4, 0);
	rt2x00mmio_register_write(rt2x00dev, TX_MAX_CNT4, 0);
	rt2x00mmio_register_write(rt2x00dev, TX_CTX_IDX4, 0);
	rt2x00mmio_register_write(rt2x00dev, TX_DTX_IDX4, 0);

	rt2x00mmio_register_write(rt2x00dev, TX_BASE_PTR5, 0);
	rt2x00mmio_register_write(rt2x00dev, TX_MAX_CNT5, 0);
	rt2x00mmio_register_write(rt2x00dev, TX_CTX_IDX5, 0);
	rt2x00mmio_register_write(rt2x00dev, TX_DTX_IDX5, 0);

	entry_priv = rt2x00dev->rx->entries[0].priv_data;
	rt2x00mmio_register_write(rt2x00dev, RX_BASE_PTR,
				  entry_priv->desc_dma);
	rt2x00mmio_register_write(rt2x00dev, RX_MAX_CNT,
				  rt2x00dev->rx[0].limit);
	rt2x00mmio_register_write(rt2x00dev, RX_CRX_IDX,
				  rt2x00dev->rx[0].limit - 1);
	rt2x00mmio_register_write(rt2x00dev, RX_DRX_IDX, 0);

	rt2800_disable_wpdma(rt2x00dev);

	rt2x00mmio_register_write(rt2x00dev, DELAY_INT_CFG, 0);

	return 0;
}

int rt2800mmio_init_registers(struct rt2x00_dev *rt2x00dev)
{
	u32 reg;

	/*
	 * Reset DMA indexes
	 */
	reg = rt2x00mmio_register_read(rt2x00dev, WPDMA_RST_IDX);
	rt2x00_set_field32(&reg, WPDMA_RST_IDX_DTX_IDX0, 1);
	rt2x00_set_field32(&reg, WPDMA_RST_IDX_DTX_IDX1, 1);
	rt2x00_set_field32(&reg, WPDMA_RST_IDX_DTX_IDX2, 1);
	rt2x00_set_field32(&reg, WPDMA_RST_IDX_DTX_IDX3, 1);
	rt2x00_set_field32(&reg, WPDMA_RST_IDX_DTX_IDX4, 1);
	rt2x00_set_field32(&reg, WPDMA_RST_IDX_DTX_IDX5, 1);
	rt2x00_set_field32(&reg, WPDMA_RST_IDX_DRX_IDX0, 1);
	rt2x00mmio_register_write(rt2x00dev, WPDMA_RST_IDX, reg);

	rt2x00mmio_register_write(rt2x00dev, PBF_SYS_CTRL, 0x00000e1f);
	rt2x00mmio_register_write(rt2x00dev, PBF_SYS_CTRL, 0x00000e00);

	if (rt2x00_is_pcie(rt2x00dev) &&
	    (rt2x00_rt(rt2x00dev, RT3090) ||
	     rt2x00_rt(rt2x00dev, RT3390) ||
	     rt2x00_rt(rt2x00dev, RT3572) ||
	     rt2x00_rt(rt2x00dev, RT3593) ||
	     rt2x00_rt(rt2x00dev, RT5390) ||
	     rt2x00_rt(rt2x00dev, RT5392) ||
	     rt2x00_rt(rt2x00dev, RT5592))) {
		reg = rt2x00mmio_register_read(rt2x00dev, AUX_CTRL);
		rt2x00_set_field32(&reg, AUX_CTRL_FORCE_PCIE_CLK, 1);
		rt2x00_set_field32(&reg, AUX_CTRL_WAKE_PCIE_EN, 1);
		rt2x00mmio_register_write(rt2x00dev, AUX_CTRL, reg);
	}

	rt2x00mmio_register_write(rt2x00dev, PWR_PIN_CFG, 0x00000003);

	reg = 0;
	rt2x00_set_field32(&reg, MAC_SYS_CTRL_RESET_CSR, 1);
	rt2x00_set_field32(&reg, MAC_SYS_CTRL_RESET_BBP, 1);
	rt2x00mmio_register_write(rt2x00dev, MAC_SYS_CTRL, reg);

	rt2x00mmio_register_write(rt2x00dev, MAC_SYS_CTRL, 0x00000000);

	return 0;
}

int rt2800mmio_enable_radio(struct rt2x00_dev *rt2x00dev)
{
	/* Wait for DMA, ignore error until we initialize queues. */
	rt2800_wait_wpdma_ready(rt2x00dev);

	if (unlikely(rt2800mmio_init_queues(rt2x00dev)))
		return -EIO;

	return rt2800_enable_radio(rt2x00dev);
}

