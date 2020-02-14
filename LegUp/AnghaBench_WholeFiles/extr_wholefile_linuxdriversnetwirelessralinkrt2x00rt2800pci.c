#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct skb_frame_desc {int dummy; } ;
struct sk_buff {int dummy; } ;
struct rt2x00_sta {int dummy; } ;
struct rt2x00_intf {int dummy; } ;
struct rt2x00_field32 {int dummy; } ;
struct TYPE_9__ {scalar_t__ base; } ;
struct TYPE_8__ {scalar_t__ rt; scalar_t__ rf; scalar_t__ rev; int intf; } ;
struct rt2x00_dev {int* rf; int /*<<< orphan*/ * eeprom; TYPE_3__* ops; TYPE_2__ csr; struct data_queue* atim; struct data_queue* tx; int /*<<< orphan*/  cap_flags; TYPE_1__ chip; } ;
struct rt2800_ops {int (* register_read ) (struct rt2x00_dev*,unsigned int const) ;int (* register_read_lock ) (struct rt2x00_dev*,unsigned int const) ;int (* regbusy_read ) (struct rt2x00_dev*,unsigned int const,struct rt2x00_field32 const,int*) ;int (* read_eeprom ) (struct rt2x00_dev*) ;int (* hwcrypt_disabled ) (struct rt2x00_dev*) ;int (* drv_write_firmware ) (struct rt2x00_dev*,size_t const*,size_t const) ;int (* drv_init_registers ) (struct rt2x00_dev*) ;int /*<<< orphan*/ * (* drv_get_txwi ) (struct queue_entry*) ;int /*<<< orphan*/  (* register_multiwrite ) (struct rt2x00_dev*,unsigned int const,void const*,int const) ;int /*<<< orphan*/  (* register_multiread ) (struct rt2x00_dev*,unsigned int const,void*,int const) ;int /*<<< orphan*/  (* register_write_lock ) (struct rt2x00_dev*,unsigned int const,int) ;int /*<<< orphan*/  (* register_write ) (struct rt2x00_dev*,unsigned int const,int) ;} ;
struct queue_entry {TYPE_6__* queue; scalar_t__ last_action; int /*<<< orphan*/  flags; } ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int dummy; } ;
struct ieee80211_vif {scalar_t__ drv_priv; } ;
struct ieee80211_sta {scalar_t__ drv_priv; } ;
struct eeprom_93cx6 {int reg_data_in; int reg_data_out; int reg_data_clock; int reg_chip_select; void (* register_read ) (struct eeprom_93cx6*) ;void (* register_write ) (struct eeprom_93cx6*) ;int /*<<< orphan*/  width; struct rt2x00_dev* data; } ;
struct data_queue {scalar_t__ length; scalar_t__ limit; scalar_t__ threshold; } ;
typedef  enum rt2x00_dump_type { ____Placeholder_rt2x00_dump_type } rt2x00_dump_type ;
typedef  enum rt2x00_chip_intf { ____Placeholder_rt2x00_chip_intf } rt2x00_chip_intf ;
typedef  enum rt2x00_capability_flags { ____Placeholder_rt2x00_capability_flags } rt2x00_capability_flags ;
typedef  enum dev_state { ____Placeholder_dev_state } dev_state ;
typedef  enum data_queue_qid { ____Placeholder_data_queue_qid } data_queue_qid ;
typedef  int /*<<< orphan*/  __le32 ;
struct TYPE_14__ {int /*<<< orphan*/  driver_data; } ;
struct TYPE_13__ {TYPE_5__* rt2x00dev; } ;
struct TYPE_12__ {TYPE_4__* ops; } ;
struct TYPE_11__ {struct rt2800_ops* drv; } ;
struct TYPE_10__ {int rf_size; int const tx_queues; struct rt2800_ops* drv; } ;

/* Variables and functions */
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
 unsigned int E2PROM_CSR ; 
 int /*<<< orphan*/  E2PROM_CSR_CHIP_SELECT ; 
 int /*<<< orphan*/  E2PROM_CSR_DATA_CLOCK ; 
 int /*<<< orphan*/  E2PROM_CSR_DATA_IN ; 
 int /*<<< orphan*/  E2PROM_CSR_DATA_OUT ; 
 int /*<<< orphan*/  E2PROM_CSR_TYPE ; 
 int /*<<< orphan*/  EEPROM_BASE ; 
 int EEPROM_SIZE ; 
 int ENOTSUPP ; 
 int ENTRY_OWNER_DEVICE_DATA ; 
 unsigned int FIRMWARE_IMAGE_BASE ; 
 char* FIRMWARE_RT2860 ; 
 char* FIRMWARE_RT3290 ; 
 unsigned int H2M_BBP_AGENT ; 
 unsigned int H2M_MAILBOX_CID ; 
 int /*<<< orphan*/  H2M_MAILBOX_CID_CMD0 ; 
 int /*<<< orphan*/  H2M_MAILBOX_CID_CMD1 ; 
 int /*<<< orphan*/  H2M_MAILBOX_CID_CMD2 ; 
 int /*<<< orphan*/  H2M_MAILBOX_CID_CMD3 ; 
 unsigned int H2M_MAILBOX_CSR ; 
 unsigned int H2M_MAILBOX_STATUS ; 
 TYPE_7__* IEEE80211_SKB_CB (struct sk_buff*) ; 
 int IEEE80211_TX_INFO_DRIVER_DATA_SIZE ; 
 int /*<<< orphan*/  MCU_SLEEP ; 
 int /*<<< orphan*/  MCU_WAKEUP ; 
 unsigned int PBF_SYS_CTRL ; 
 int /*<<< orphan*/  PBF_SYS_CTRL_HOST_RAM_WRITE ; 
 int /*<<< orphan*/  PCI_EEPROM_WIDTH_93C46 ; 
 int /*<<< orphan*/  PCI_EEPROM_WIDTH_93C66 ; 
 int /*<<< orphan*/  PCI_EEPROM_WIDTH_93C86 ; 
 int const QID_ATIM ; 
 int /*<<< orphan*/  REGISTER_BUSY_DELAY ; 
 int RT2X00_CHIP_INTF_PCI ; 
 int RT2X00_CHIP_INTF_PCIE ; 
 int RT2X00_CHIP_INTF_SOC ; 
 int RT2X00_CHIP_INTF_USB ; 
 scalar_t__ RT3290 ; 
#define  STATE_AWAKE 135 
#define  STATE_DEEP_SLEEP 134 
#define  STATE_RADIO_IRQ_OFF 133 
#define  STATE_RADIO_IRQ_ON 132 
#define  STATE_RADIO_OFF 131 
#define  STATE_RADIO_ON 130 
#define  STATE_SLEEP 129 
#define  STATE_STANDBY 128 
 size_t TOKEN_RADIO_OFF ; 
 size_t TOKEN_SLEEP ; 
 size_t TOKEN_WAKEUP ; 
 int /*<<< orphan*/  __iowrite32_copy (scalar_t__,void const*,int const) ; 
 int /*<<< orphan*/  cpu_to_le16 (scalar_t__) ; 
 int /*<<< orphan*/  cpu_to_le32 (int) ; 
 int /*<<< orphan*/  eeprom_93cx6_multiread (struct eeprom_93cx6*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  jiffies ; 
 scalar_t__ le16_to_cpu (int /*<<< orphan*/ ) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy_fromio (void*,scalar_t__,int const) ; 
 int modparam_nohwcrypt ; 
 scalar_t__ msecs_to_jiffies (int) ; 
 int readl (scalar_t__) ; 
 int rt2800_efuse_detect (struct rt2x00_dev*) ; 
 int /*<<< orphan*/  rt2800_mcu_request (struct rt2x00_dev*,int /*<<< orphan*/ ,size_t,int,int) ; 
 int rt2800_read_eeprom_efuse (struct rt2x00_dev*) ; 
 int rt2800mmio_enable_radio (struct rt2x00_dev*) ; 
 int /*<<< orphan*/  rt2800mmio_toggle_irq (struct rt2x00_dev*,int) ; 
 int /*<<< orphan*/  rt2800pci_ops ; 
 int /*<<< orphan*/  rt2x00_err (struct rt2x00_dev*,char*,...) ; 
 int rt2x00_get_field32 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rt2x00_info (struct rt2x00_dev*,char*,scalar_t__,...) ; 
 int /*<<< orphan*/  rt2x00_set_field32 (int*,int /*<<< orphan*/ ,int) ; 
 int rt2x00pci_probe (struct pci_dev*,int /*<<< orphan*/ *) ; 
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
 int test_bit (int,int /*<<< orphan*/ *) ; 
 int time_after (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  udelay (int /*<<< orphan*/ ) ; 
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

__attribute__((used)) static bool rt2800pci_hwcrypt_disabled(struct rt2x00_dev *rt2x00dev)
{
	return modparam_nohwcrypt;
}

__attribute__((used)) static void rt2800pci_mcu_status(struct rt2x00_dev *rt2x00dev, const u8 token)
{
	unsigned int i;
	u32 reg;

	/*
	 * SOC devices don't support MCU requests.
	 */
	if (rt2x00_is_soc(rt2x00dev))
		return;

	for (i = 0; i < 200; i++) {
		reg = rt2x00mmio_register_read(rt2x00dev, H2M_MAILBOX_CID);

		if ((rt2x00_get_field32(reg, H2M_MAILBOX_CID_CMD0) == token) ||
		    (rt2x00_get_field32(reg, H2M_MAILBOX_CID_CMD1) == token) ||
		    (rt2x00_get_field32(reg, H2M_MAILBOX_CID_CMD2) == token) ||
		    (rt2x00_get_field32(reg, H2M_MAILBOX_CID_CMD3) == token))
			break;

		udelay(REGISTER_BUSY_DELAY);
	}

	if (i == 200)
		rt2x00_err(rt2x00dev, "MCU request failed, no response from hardware\n");

	rt2x00mmio_register_write(rt2x00dev, H2M_MAILBOX_STATUS, ~0);
	rt2x00mmio_register_write(rt2x00dev, H2M_MAILBOX_CID, ~0);
}

__attribute__((used)) static void rt2800pci_eepromregister_read(struct eeprom_93cx6 *eeprom)
{
	struct rt2x00_dev *rt2x00dev = eeprom->data;
	u32 reg;

	reg = rt2x00mmio_register_read(rt2x00dev, E2PROM_CSR);

	eeprom->reg_data_in = !!rt2x00_get_field32(reg, E2PROM_CSR_DATA_IN);
	eeprom->reg_data_out = !!rt2x00_get_field32(reg, E2PROM_CSR_DATA_OUT);
	eeprom->reg_data_clock =
	    !!rt2x00_get_field32(reg, E2PROM_CSR_DATA_CLOCK);
	eeprom->reg_chip_select =
	    !!rt2x00_get_field32(reg, E2PROM_CSR_CHIP_SELECT);
}

__attribute__((used)) static void rt2800pci_eepromregister_write(struct eeprom_93cx6 *eeprom)
{
	struct rt2x00_dev *rt2x00dev = eeprom->data;
	u32 reg = 0;

	rt2x00_set_field32(&reg, E2PROM_CSR_DATA_IN, !!eeprom->reg_data_in);
	rt2x00_set_field32(&reg, E2PROM_CSR_DATA_OUT, !!eeprom->reg_data_out);
	rt2x00_set_field32(&reg, E2PROM_CSR_DATA_CLOCK,
			   !!eeprom->reg_data_clock);
	rt2x00_set_field32(&reg, E2PROM_CSR_CHIP_SELECT,
			   !!eeprom->reg_chip_select);

	rt2x00mmio_register_write(rt2x00dev, E2PROM_CSR, reg);
}

__attribute__((used)) static int rt2800pci_read_eeprom_pci(struct rt2x00_dev *rt2x00dev)
{
	struct eeprom_93cx6 eeprom;
	u32 reg;

	reg = rt2x00mmio_register_read(rt2x00dev, E2PROM_CSR);

	eeprom.data = rt2x00dev;
	eeprom.register_read = rt2800pci_eepromregister_read;
	eeprom.register_write = rt2800pci_eepromregister_write;
	switch (rt2x00_get_field32(reg, E2PROM_CSR_TYPE))
	{
	case 0:
		eeprom.width = PCI_EEPROM_WIDTH_93C46;
		break;
	case 1:
		eeprom.width = PCI_EEPROM_WIDTH_93C66;
		break;
	default:
		eeprom.width = PCI_EEPROM_WIDTH_93C86;
		break;
	}
	eeprom.reg_data_in = 0;
	eeprom.reg_data_out = 0;
	eeprom.reg_data_clock = 0;
	eeprom.reg_chip_select = 0;

	eeprom_93cx6_multiread(&eeprom, EEPROM_BASE, rt2x00dev->eeprom,
			       EEPROM_SIZE / sizeof(u16));

	return 0;
}

__attribute__((used)) static int rt2800pci_efuse_detect(struct rt2x00_dev *rt2x00dev)
{
	return rt2800_efuse_detect(rt2x00dev);
}

__attribute__((used)) static inline int rt2800pci_read_eeprom_efuse(struct rt2x00_dev *rt2x00dev)
{
	return rt2800_read_eeprom_efuse(rt2x00dev);
}

__attribute__((used)) static char *rt2800pci_get_firmware_name(struct rt2x00_dev *rt2x00dev)
{
	/*
	 * Chip rt3290 use specific 4KB firmware named rt3290.bin.
	 */
	if (rt2x00_rt(rt2x00dev, RT3290))
		return FIRMWARE_RT3290;
	else
		return FIRMWARE_RT2860;
}

__attribute__((used)) static int rt2800pci_write_firmware(struct rt2x00_dev *rt2x00dev,
				    const u8 *data, const size_t len)
{
	u32 reg;

	/*
	 * enable Host program ram write selection
	 */
	reg = 0;
	rt2x00_set_field32(&reg, PBF_SYS_CTRL_HOST_RAM_WRITE, 1);
	rt2x00mmio_register_write(rt2x00dev, PBF_SYS_CTRL, reg);

	/*
	 * Write firmware to device.
	 */
	rt2x00mmio_register_multiwrite(rt2x00dev, FIRMWARE_IMAGE_BASE,
				       data, len);

	rt2x00mmio_register_write(rt2x00dev, PBF_SYS_CTRL, 0x00000);
	rt2x00mmio_register_write(rt2x00dev, PBF_SYS_CTRL, 0x00001);

	rt2x00mmio_register_write(rt2x00dev, H2M_BBP_AGENT, 0);
	rt2x00mmio_register_write(rt2x00dev, H2M_MAILBOX_CSR, 0);

	return 0;
}

__attribute__((used)) static int rt2800pci_enable_radio(struct rt2x00_dev *rt2x00dev)
{
	int retval;

	retval = rt2800mmio_enable_radio(rt2x00dev);
	if (retval)
		return retval;

	/* After resume MCU_BOOT_SIGNAL will trash these. */
	rt2x00mmio_register_write(rt2x00dev, H2M_MAILBOX_STATUS, ~0);
	rt2x00mmio_register_write(rt2x00dev, H2M_MAILBOX_CID, ~0);

	rt2800_mcu_request(rt2x00dev, MCU_SLEEP, TOKEN_RADIO_OFF, 0xff, 0x02);
	rt2800pci_mcu_status(rt2x00dev, TOKEN_RADIO_OFF);

	rt2800_mcu_request(rt2x00dev, MCU_WAKEUP, TOKEN_WAKEUP, 0, 0);
	rt2800pci_mcu_status(rt2x00dev, TOKEN_WAKEUP);

	return retval;
}

__attribute__((used)) static int rt2800pci_set_state(struct rt2x00_dev *rt2x00dev,
			       enum dev_state state)
{
	if (state == STATE_AWAKE) {
		rt2800_mcu_request(rt2x00dev, MCU_WAKEUP, TOKEN_WAKEUP,
				   0, 0x02);
		rt2800pci_mcu_status(rt2x00dev, TOKEN_WAKEUP);
	} else if (state == STATE_SLEEP) {
		rt2x00mmio_register_write(rt2x00dev, H2M_MAILBOX_STATUS,
					  0xffffffff);
		rt2x00mmio_register_write(rt2x00dev, H2M_MAILBOX_CID,
					  0xffffffff);
		rt2800_mcu_request(rt2x00dev, MCU_SLEEP, TOKEN_SLEEP,
				   0xff, 0x01);
	}

	return 0;
}

__attribute__((used)) static int rt2800pci_set_device_state(struct rt2x00_dev *rt2x00dev,
				      enum dev_state state)
{
	int retval = 0;

	switch (state) {
	case STATE_RADIO_ON:
		retval = rt2800pci_enable_radio(rt2x00dev);
		break;
	case STATE_RADIO_OFF:
		/*
		 * After the radio has been disabled, the device should
		 * be put to sleep for powersaving.
		 */
		rt2800pci_set_state(rt2x00dev, STATE_SLEEP);
		break;
	case STATE_RADIO_IRQ_ON:
	case STATE_RADIO_IRQ_OFF:
		rt2800mmio_toggle_irq(rt2x00dev, state);
		break;
	case STATE_DEEP_SLEEP:
	case STATE_SLEEP:
	case STATE_STANDBY:
	case STATE_AWAKE:
		retval = rt2800pci_set_state(rt2x00dev, state);
		break;
	default:
		retval = -ENOTSUPP;
		break;
	}

	if (unlikely(retval))
		rt2x00_err(rt2x00dev, "Device failed to enter state %d (%d)\n",
			   state, retval);

	return retval;
}

__attribute__((used)) static int rt2800pci_read_eeprom(struct rt2x00_dev *rt2x00dev)
{
	int retval;

	if (rt2800pci_efuse_detect(rt2x00dev))
		retval = rt2800pci_read_eeprom_efuse(rt2x00dev);
	else
		retval = rt2800pci_read_eeprom_pci(rt2x00dev);

	return retval;
}

__attribute__((used)) static int rt2800pci_probe(struct pci_dev *pci_dev,
			   const struct pci_device_id *id)
{
	return rt2x00pci_probe(pci_dev, &rt2800pci_ops);
}

