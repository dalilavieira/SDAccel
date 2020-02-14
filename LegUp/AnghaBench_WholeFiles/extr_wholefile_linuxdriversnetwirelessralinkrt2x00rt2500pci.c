#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_32__   TYPE_9__ ;
typedef  struct TYPE_31__   TYPE_8__ ;
typedef  struct TYPE_30__   TYPE_7__ ;
typedef  struct TYPE_29__   TYPE_6__ ;
typedef  struct TYPE_28__   TYPE_5__ ;
typedef  struct TYPE_27__   TYPE_4__ ;
typedef  struct TYPE_26__   TYPE_3__ ;
typedef  struct TYPE_25__   TYPE_2__ ;
typedef  struct TYPE_24__   TYPE_1__ ;
typedef  struct TYPE_23__   TYPE_17__ ;
typedef  struct TYPE_22__   TYPE_14__ ;
typedef  struct TYPE_21__   TYPE_13__ ;
typedef  struct TYPE_20__   TYPE_12__ ;
typedef  struct TYPE_19__   TYPE_11__ ;
typedef  struct TYPE_18__   TYPE_10__ ;

/* Type definitions */
typedef  size_t u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct TYPE_19__ {int signal; int service; int length_low; int length_high; int ifs; } ;
struct TYPE_20__ {TYPE_11__ plcp; } ;
struct txentry_desc {scalar_t__ rate_mode; int length; scalar_t__ flags; TYPE_12__ u; } ;
struct txdone_entry_desc {int retry; scalar_t__ flags; } ;
struct skb_frame_desc {int skb_dma; void* desc_len; int /*<<< orphan*/ * desc; } ;
struct sk_buff {int dummy; } ;
struct rxdone_entry_desc {int signal; int rssi; int size; int /*<<< orphan*/  dev_flags; int /*<<< orphan*/  flags; } ;
struct rt2x00lib_erp {int short_preamble; int basic_rates; int slot_time; int sifs; int pifs; int difs; int eifs; int beacon_int; } ;
struct rf_channel {int rf3; int rf1; int channel; int rf4; int rf2; } ;
struct rt2x00lib_conf {TYPE_5__* conf; struct rf_channel rf; } ;
struct rt2x00intf_conf {int sync; void* mac; void* bssid; } ;
struct rt2x00_sta {int dummy; } ;
struct rt2x00_intf {int dummy; } ;
struct rt2x00_field32 {int dummy; } ;
struct hw_mode_spec {int supported_rates; int num_channels; struct channel_info* channels_info; void* channels; int /*<<< orphan*/  supported_bands; } ;
struct TYPE_24__ {scalar_t__ rx; scalar_t__ tx; } ;
struct TYPE_27__ {scalar_t__ base; } ;
struct TYPE_26__ {scalar_t__ rt; scalar_t__ rf; scalar_t__ rev; int intf; } ;
struct rt2x00_dev {int* rf; int beacon_int; int rssi_offset; scalar_t__ cap_flags; TYPE_14__* hw; int /*<<< orphan*/  dev; struct hw_mode_spec spec; TYPE_1__ default_ant; int /*<<< orphan*/ * eeprom; int /*<<< orphan*/  irqmask_lock; int /*<<< orphan*/  txstatus_tasklet; int /*<<< orphan*/  rxdone_tasklet; int /*<<< orphan*/  tbtt_tasklet; scalar_t__ flags; TYPE_10__* ops; TYPE_8__* rx; struct data_queue* bcn; struct data_queue* atim; struct data_queue* tx; scalar_t__ intf_associated; int /*<<< orphan*/  intf_ap_count; int /*<<< orphan*/  csr_mutex; TYPE_4__ csr; TYPE_3__ chip; } ;
struct queue_entry_priv_mmio {int desc_dma; int /*<<< orphan*/ * desc; } ;
struct queue_entry {struct queue_entry_priv_mmio* priv_data; TYPE_13__* queue; struct sk_buff* skb; scalar_t__ last_action; scalar_t__ flags; } ;
struct pci_device_id {int dummy; } ;
struct pci_dev {int dummy; } ;
struct link_qual {int rx_failed; int false_cca; size_t vgc_level_reg; size_t vgc_level; int rssi; } ;
struct ieee80211_vif {scalar_t__ drv_priv; } ;
struct ieee80211_sta {scalar_t__ drv_priv; } ;
struct ieee80211_hw {struct rt2x00_dev* priv; } ;
struct eeprom_93cx6 {int reg_data_in; int reg_data_out; int reg_data_clock; int reg_chip_select; void (* register_read ) (struct eeprom_93cx6*) ;void (* register_write ) (struct eeprom_93cx6*) ;int /*<<< orphan*/  width; struct rt2x00_dev* data; } ;
struct data_queue {scalar_t__ length; scalar_t__ limit; scalar_t__ threshold; int cw_min; int qid; int desc_size; int priv_size; void* data_size; TYPE_6__* entries; struct rt2x00_dev* rt2x00dev; } ;
struct channel_info {int /*<<< orphan*/  default_power1; void* max_power; } ;
struct antenna_setup {int rx; int tx; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum rt2x00_dump_type { ____Placeholder_rt2x00_dump_type } rt2x00_dump_type ;
typedef  enum rt2x00_chip_intf { ____Placeholder_rt2x00_chip_intf } rt2x00_chip_intf ;
typedef  enum rt2x00_capability_flags { ____Placeholder_rt2x00_capability_flags } rt2x00_capability_flags ;
typedef  enum dev_state { ____Placeholder_dev_state } dev_state ;
typedef  enum data_queue_qid { ____Placeholder_data_queue_qid } data_queue_qid ;
typedef  int /*<<< orphan*/  __le32 ;
struct TYPE_32__ {scalar_t__ (* set_device_state ) (struct rt2x00_dev*,int) ;} ;
struct TYPE_31__ {int desc_size; int limit; int data_size; TYPE_7__* entries; } ;
struct TYPE_30__ {struct queue_entry_priv_mmio* priv_data; } ;
struct TYPE_29__ {struct queue_entry_priv_mmio* priv_data; } ;
struct TYPE_28__ {int long_frame_max_tx_count; int short_frame_max_tx_count; int flags; int listen_interval; int power_level; } ;
struct TYPE_25__ {int /*<<< orphan*/  flags; } ;
struct TYPE_23__ {int /*<<< orphan*/  driver_data; } ;
struct TYPE_22__ {TYPE_2__* wiphy; } ;
struct TYPE_21__ {int const qid; int aifs; int cw_min; int cw_max; struct rt2x00_dev* rt2x00dev; } ;
struct TYPE_18__ {int rf_size; int const tx_queues; TYPE_9__* lib; } ;

/* Variables and functions */
 int ACK_SIZE ; 
#define  ANTENNA_A 144 
#define  ANTENNA_B 143 
 int ANTENNA_SW_DIVERSITY ; 
 unsigned int ARCSR1 ; 
 unsigned int ARCSR2 ; 
 struct rt2x00_field32 ARCSR2_LENGTH ; 
 struct rt2x00_field32 ARCSR2_SERVICE ; 
 struct rt2x00_field32 ARCSR2_SIGNAL ; 
 unsigned int ARCSR3 ; 
 struct rt2x00_field32 ARCSR3_SERVICE ; 
 struct rt2x00_field32 ARCSR3_SIGNAL ; 
 unsigned int ARCSR4 ; 
 struct rt2x00_field32 ARCSR4_SERVICE ; 
 struct rt2x00_field32 ARCSR4_SIGNAL ; 
 unsigned int ARCSR5 ; 
 struct rt2x00_field32 ARCSR5_SERVICE ; 
 struct rt2x00_field32 ARCSR5_SIGNAL ; 
 void* ARRAY_SIZE (void*) ; 
 unsigned int ARTCSR0 ; 
 struct rt2x00_field32 ARTCSR0_ACK_CTS_11MBS ; 
 struct rt2x00_field32 ARTCSR0_ACK_CTS_1MBS ; 
 struct rt2x00_field32 ARTCSR0_ACK_CTS_2MBS ; 
 struct rt2x00_field32 ARTCSR0_ACK_CTS_5_5MBS ; 
 unsigned int ARTCSR1 ; 
 struct rt2x00_field32 ARTCSR1_ACK_CTS_12MBS ; 
 struct rt2x00_field32 ARTCSR1_ACK_CTS_18MBS ; 
 struct rt2x00_field32 ARTCSR1_ACK_CTS_6MBS ; 
 struct rt2x00_field32 ARTCSR1_ACK_CTS_9MBS ; 
 unsigned int ARTCSR2 ; 
 struct rt2x00_field32 ARTCSR2_ACK_CTS_24MBS ; 
 struct rt2x00_field32 ARTCSR2_ACK_CTS_36MBS ; 
 struct rt2x00_field32 ARTCSR2_ACK_CTS_48MBS ; 
 struct rt2x00_field32 ARTCSR2_ACK_CTS_54MBS ; 
 unsigned int BBPCSR ; 
 unsigned int BBPCSR1 ; 
 struct rt2x00_field32 BBPCSR1_CCK ; 
 struct rt2x00_field32 BBPCSR1_CCK_FLIP ; 
 struct rt2x00_field32 BBPCSR1_OFDM ; 
 struct rt2x00_field32 BBPCSR1_OFDM_FLIP ; 
 struct rt2x00_field32 BBPCSR_BUSY ; 
 struct rt2x00_field32 BBPCSR_REGNUM ; 
 struct rt2x00_field32 BBPCSR_VALUE ; 
 struct rt2x00_field32 BBPCSR_WRITE_CONTROL ; 
 int /*<<< orphan*/  BBP_R14_RX_ANTENNA ; 
 int /*<<< orphan*/  BBP_R14_RX_IQ_FLIP ; 
 int /*<<< orphan*/  BBP_R2_TX_ANTENNA ; 
 int /*<<< orphan*/  BBP_R2_TX_IQ_FLIP ; 
 int /*<<< orphan*/  BBP_R70_JAPAN_FILTER ; 
 unsigned int BCNCSR1 ; 
 struct rt2x00_field32 BCNCSR1_BEACON_CWMIN ; 
 struct rt2x00_field32 BCNCSR1_PRELOAD ; 
 int BSS_CHANGED_BASIC_RATES ; 
 int BSS_CHANGED_BEACON_INT ; 
 int BSS_CHANGED_ERP_PREAMBLE ; 
 int BSS_CHANGED_ERP_SLOT ; 
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
 int CAPABILITY_HW_BUTTON ; 
 int CAPABILITY_HW_CRYPTO ; 
 int CAPABILITY_LINK_TUNING ; 
 int CAPABILITY_POWER_LIMIT ; 
 int CAPABILITY_PRE_TBTT_INTERRUPT ; 
 int CAPABILITY_RF_SEQUENCE ; 
 int CAPABILITY_VCO_RECALIBRATION ; 
 int CIPHER_NONE ; 
 unsigned int CNT0 ; 
 struct rt2x00_field32 CNT0_FCS_ERROR ; 
 unsigned int CNT3 ; 
 struct rt2x00_field32 CNT3_FALSE_CCA ; 
 unsigned int CNT4 ; 
 int CONFIG_MONITORING ; 
 unsigned int const CONFIG_UPDATE_BSSID ; 
 unsigned int const CONFIG_UPDATE_MAC ; 
 unsigned int const CONFIG_UPDATE_TYPE ; 
 unsigned int CSR0 ; 
 struct rt2x00_field32 CSR0_REVISION ; 
 unsigned int CSR1 ; 
 unsigned int CSR11 ; 
 struct rt2x00_field32 CSR11_CW_SELECT ; 
 struct rt2x00_field32 CSR11_LONG_RETRY ; 
 struct rt2x00_field32 CSR11_SHORT_RETRY ; 
 struct rt2x00_field32 CSR11_SLOT_TIME ; 
 unsigned int CSR12 ; 
 struct rt2x00_field32 CSR12_BEACON_INTERVAL ; 
 struct rt2x00_field32 CSR12_CFP_MAX_DURATION ; 
 unsigned int CSR14 ; 
 struct rt2x00_field32 CSR14_BEACON_GEN ; 
 struct rt2x00_field32 CSR14_CFP_COUNT_PRELOAD ; 
 struct rt2x00_field32 CSR14_TATIMW ; 
 struct rt2x00_field32 CSR14_TBCM_PRELOAD ; 
 struct rt2x00_field32 CSR14_TBCN ; 
 struct rt2x00_field32 CSR14_TCFP ; 
 struct rt2x00_field32 CSR14_TSF_COUNT ; 
 struct rt2x00_field32 CSR14_TSF_SYNC ; 
 unsigned int CSR15 ; 
 struct rt2x00_field32 CSR15_BEACON_SENT ; 
 unsigned int CSR16 ; 
 struct rt2x00_field32 CSR16_LOW_TSFTIMER ; 
 unsigned int CSR17 ; 
 struct rt2x00_field32 CSR17_HIGH_TSFTIMER ; 
 unsigned int CSR18 ; 
 struct rt2x00_field32 CSR18_PIFS ; 
 struct rt2x00_field32 CSR18_SIFS ; 
 unsigned int CSR19 ; 
 struct rt2x00_field32 CSR19_DIFS ; 
 struct rt2x00_field32 CSR19_EIFS ; 
 struct rt2x00_field32 CSR1_BBP_RESET ; 
 struct rt2x00_field32 CSR1_HOST_READY ; 
 struct rt2x00_field32 CSR1_SOFT_RESET ; 
 unsigned int CSR20 ; 
 struct rt2x00_field32 CSR20_AUTOWAKE ; 
 struct rt2x00_field32 CSR20_DELAY_AFTER_TBCN ; 
 struct rt2x00_field32 CSR20_TBCN_BEFORE_WAKEUP ; 
 unsigned int CSR21 ; 
 struct rt2x00_field32 CSR21_EEPROM_CHIP_SELECT ; 
 struct rt2x00_field32 CSR21_EEPROM_DATA_CLOCK ; 
 struct rt2x00_field32 CSR21_EEPROM_DATA_IN ; 
 struct rt2x00_field32 CSR21_EEPROM_DATA_OUT ; 
 struct rt2x00_field32 CSR21_TYPE_93C46 ; 
 unsigned int CSR3 ; 
 unsigned int CSR5 ; 
 unsigned int CSR7 ; 
 struct rt2x00_field32 CSR7_RXDONE ; 
 struct rt2x00_field32 CSR7_TBCN_EXPIRE ; 
 struct rt2x00_field32 CSR7_TXDONE_ATIMRING ; 
 struct rt2x00_field32 CSR7_TXDONE_PRIORING ; 
 struct rt2x00_field32 CSR7_TXDONE_TXRING ; 
 unsigned int CSR8 ; 
 struct rt2x00_field32 CSR8_RXDONE ; 
 struct rt2x00_field32 CSR8_TBCN_EXPIRE ; 
 struct rt2x00_field32 CSR8_TXDONE_ATIMRING ; 
 struct rt2x00_field32 CSR8_TXDONE_PRIORING ; 
 struct rt2x00_field32 CSR8_TXDONE_TXRING ; 
 unsigned int CSR9 ; 
 struct rt2x00_field32 CSR9_MAX_FRAME_UNIT ; 
 void* DATA_FRAME_SIZE ; 
 int DEFAULT_RSSI_OFFSET ; 
 int /*<<< orphan*/  DEFAULT_TXPOWER ; 
 int DEVICE_STATE_ENABLED_RADIO ; 
 int DUMP_FRAME_BEACON ; 
 int EACCES ; 
 int EBUSY ; 
 unsigned int EEPROM_ANTENNA ; 
 int /*<<< orphan*/  EEPROM_ANTENNA_DYN_TXAGC ; 
 int /*<<< orphan*/  EEPROM_ANTENNA_HARDWARE_RADIO ; 
 int /*<<< orphan*/  EEPROM_ANTENNA_LED_MODE ; 
 int /*<<< orphan*/  EEPROM_ANTENNA_NUM ; 
 int /*<<< orphan*/  EEPROM_ANTENNA_RF_TYPE ; 
 int /*<<< orphan*/  EEPROM_ANTENNA_RX_DEFAULT ; 
 int /*<<< orphan*/  EEPROM_ANTENNA_TX_DEFAULT ; 
 int /*<<< orphan*/  EEPROM_BASE ; 
 int /*<<< orphan*/  EEPROM_BBP_REG_ID ; 
 unsigned int EEPROM_BBP_SIZE ; 
 unsigned int EEPROM_BBP_START ; 
 int /*<<< orphan*/  EEPROM_BBP_VALUE ; 
 unsigned int EEPROM_CALIBRATE_OFFSET ; 
 int /*<<< orphan*/  EEPROM_CALIBRATE_OFFSET_RSSI ; 
 unsigned int EEPROM_MAC_ADDR_0 ; 
 unsigned int EEPROM_NIC ; 
 int /*<<< orphan*/  EEPROM_NIC_CARDBUS_ACCEL ; 
 int /*<<< orphan*/  EEPROM_NIC_CCK_TX_POWER ; 
 int /*<<< orphan*/  EEPROM_NIC_DYN_BBP_TUNE ; 
 int EEPROM_SIZE ; 
 unsigned int EEPROM_TXPOWER_START ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int ENTRY_OWNER_DEVICE_DATA ; 
 int ENTRY_TXD_ACK ; 
 int ENTRY_TXD_MORE_FRAG ; 
 int ENTRY_TXD_REQ_TIMESTAMP ; 
 int ENTRY_TXD_RETRY_MODE ; 
 int ENTRY_TXD_RTS_FRAME ; 
 unsigned int const FIF_ALLMULTI ; 
 unsigned int const FIF_CONTROL ; 
 unsigned int const FIF_FCSFAIL ; 
 unsigned int const FIF_PLCPFAIL ; 
 int GET_DURATION (int,int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int GPIOCSR ; 
 struct rt2x00_field32 GPIOCSR_DIR0 ; 
 struct rt2x00_field32 GPIOCSR_VAL0 ; 
 int /*<<< orphan*/  HOST_BROADCAST_PS_BUFFERING ; 
 unsigned int const IEEE80211_CONF_CHANGE_CHANNEL ; 
 unsigned int const IEEE80211_CONF_CHANGE_POWER ; 
 unsigned int const IEEE80211_CONF_CHANGE_PS ; 
 unsigned int const IEEE80211_CONF_CHANGE_RETRY_LIMITS ; 
 int IEEE80211_CONF_PS ; 
 int IEEE80211_HEADER ; 
 TYPE_17__* IEEE80211_SKB_CB (struct sk_buff*) ; 
 int IEEE80211_TX_INFO_DRIVER_DATA_SIZE ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int LED_MODE_DEFAULT ; 
 unsigned int MACCSR0 ; 
 unsigned int MACCSR1 ; 
 unsigned int MACCSR2 ; 
 struct rt2x00_field32 MACCSR2_DELAY ; 
 void* MAX_TXPOWER ; 
 void* MGMT_FRAME_SIZE ; 
 unsigned int PCICSR ; 
 struct rt2x00_field32 PCICSR_BIG_ENDIAN ; 
 struct rt2x00_field32 PCICSR_BURST_LENTH ; 
 struct rt2x00_field32 PCICSR_ENABLE_CLK ; 
 struct rt2x00_field32 PCICSR_READ_MULTIPLE ; 
 struct rt2x00_field32 PCICSR_RX_TRESHOLD ; 
 struct rt2x00_field32 PCICSR_TX_TRESHOLD ; 
 struct rt2x00_field32 PCICSR_WRITE_INVALID ; 
 int /*<<< orphan*/  PCI_EEPROM_WIDTH_93C46 ; 
 int /*<<< orphan*/  PCI_EEPROM_WIDTH_93C66 ; 
 int PREAMBLE ; 
 unsigned int PSCSR0 ; 
 unsigned int PSCSR1 ; 
 unsigned int PSCSR2 ; 
 unsigned int PSCSR3 ; 
 int /*<<< orphan*/  PS_NULLFUNC_STACK ; 
 unsigned int PWRCSR0 ; 
 unsigned int PWRCSR1 ; 
 struct rt2x00_field32 PWRCSR1_BBP_CURR_STATE ; 
 struct rt2x00_field32 PWRCSR1_BBP_DESIRE_STATE ; 
 struct rt2x00_field32 PWRCSR1_PUT_TO_SLEEP ; 
 struct rt2x00_field32 PWRCSR1_RF_CURR_STATE ; 
 struct rt2x00_field32 PWRCSR1_RF_DESIRE_STATE ; 
 struct rt2x00_field32 PWRCSR1_SET_STATE ; 
#define  QID_AC_BE 142 
#define  QID_AC_BK 141 
#define  QID_AC_VI 140 
#define  QID_AC_VO 139 
#define  QID_ATIM 138 
#define  QID_BEACON 137 
#define  QID_RX 136 
 int /*<<< orphan*/  Q_INDEX_DONE ; 
 unsigned int RALINKCSR ; 
 struct rt2x00_field32 RALINKCSR_AR_BBP_DATA0 ; 
 struct rt2x00_field32 RALINKCSR_AR_BBP_DATA1 ; 
 struct rt2x00_field32 RALINKCSR_AR_BBP_ID0 ; 
 struct rt2x00_field32 RALINKCSR_AR_BBP_ID1 ; 
 struct rt2x00_field32 RALINKCSR_AR_BBP_VALID0 ; 
 struct rt2x00_field32 RALINKCSR_AR_BBP_VALID1 ; 
 scalar_t__ RATE_MODE_OFDM ; 
 unsigned int REGISTER_BUSY_COUNT ; 
 int /*<<< orphan*/  REGISTER_BUSY_DELAY ; 
 int REQUIRE_ATIM_QUEUE ; 
 int REQUIRE_DELAYED_RFKILL ; 
 int REQUIRE_DMA ; 
 int REQUIRE_SW_SEQNO ; 
 struct rt2x00_field32 RF1_TUNER ; 
 int RF2522 ; 
 scalar_t__ RF2523 ; 
 scalar_t__ RF2524 ; 
 scalar_t__ RF2525 ; 
 scalar_t__ RF2525E ; 
 struct rt2x00_field32 RF3_TUNER ; 
 struct rt2x00_field32 RF3_TXPOWER ; 
 scalar_t__ RF5222 ; 
 unsigned int RFCSR ; 
 struct rt2x00_field32 RFCSR_BUSY ; 
 struct rt2x00_field32 RFCSR_IF_SELECT ; 
 struct rt2x00_field32 RFCSR_NUMBER_OF_BITS ; 
 struct rt2x00_field32 RFCSR_VALUE ; 
 scalar_t__ RT2560 ; 
 scalar_t__ RT2560_VERSION_D ; 
 int RT2X00_CHIP_INTF_PCI ; 
 int RT2X00_CHIP_INTF_PCIE ; 
 int RT2X00_CHIP_INTF_SOC ; 
 int RT2X00_CHIP_INTF_USB ; 
 unsigned int RXCSR0 ; 
 struct rt2x00_field32 RXCSR0_DISABLE_RX ; 
 struct rt2x00_field32 RXCSR0_DROP_BCAST ; 
 struct rt2x00_field32 RXCSR0_DROP_CONTROL ; 
 struct rt2x00_field32 RXCSR0_DROP_CRC ; 
 struct rt2x00_field32 RXCSR0_DROP_MCAST ; 
 struct rt2x00_field32 RXCSR0_DROP_NOT_TO_ME ; 
 struct rt2x00_field32 RXCSR0_DROP_PHYSICAL ; 
 struct rt2x00_field32 RXCSR0_DROP_TODS ; 
 struct rt2x00_field32 RXCSR0_DROP_VERSION_ERROR ; 
 unsigned int RXCSR1 ; 
 struct rt2x00_field32 RXCSR1_NUM_RXD ; 
 struct rt2x00_field32 RXCSR1_RXD_SIZE ; 
 unsigned int RXCSR2 ; 
 struct rt2x00_field32 RXCSR2_RX_RING_REGISTER ; 
 unsigned int RXCSR3 ; 
 struct rt2x00_field32 RXCSR3_BBP_ID0 ; 
 struct rt2x00_field32 RXCSR3_BBP_ID0_VALID ; 
 struct rt2x00_field32 RXCSR3_BBP_ID1 ; 
 struct rt2x00_field32 RXCSR3_BBP_ID1_VALID ; 
 struct rt2x00_field32 RXCSR3_BBP_ID2 ; 
 struct rt2x00_field32 RXCSR3_BBP_ID2_VALID ; 
 struct rt2x00_field32 RXCSR3_BBP_ID3 ; 
 struct rt2x00_field32 RXCSR3_BBP_ID3_VALID ; 
 int /*<<< orphan*/  RXDONE_MY_BSS ; 
 int /*<<< orphan*/  RXDONE_SIGNAL_BITRATE ; 
 int /*<<< orphan*/  RXDONE_SIGNAL_PLCP ; 
 int RXD_DESC_SIZE ; 
 struct rt2x00_field32 RXD_W0_CRC_ERROR ; 
 struct rt2x00_field32 RXD_W0_DATABYTE_COUNT ; 
 struct rt2x00_field32 RXD_W0_MY_BSS ; 
 struct rt2x00_field32 RXD_W0_OFDM ; 
 struct rt2x00_field32 RXD_W0_OWNER_NIC ; 
 struct rt2x00_field32 RXD_W0_PHYSICAL_ERROR ; 
 struct rt2x00_field32 RXD_W1_BUFFER_ADDRESS ; 
 struct rt2x00_field32 RXD_W2_RSSI ; 
 struct rt2x00_field32 RXD_W2_SIGNAL ; 
 int /*<<< orphan*/  RX_FLAG_FAILED_FCS_CRC ; 
 int /*<<< orphan*/  RX_FLAG_FAILED_PLCP_CRC ; 
 int /*<<< orphan*/  SET_IEEE80211_DEV (TYPE_14__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SET_IEEE80211_PERM_ADDR (TYPE_14__*,void*) ; 
 int /*<<< orphan*/  SIGNAL_DBM ; 
#define  STATE_AWAKE 135 
#define  STATE_DEEP_SLEEP 134 
#define  STATE_RADIO_IRQ_OFF 133 
#define  STATE_RADIO_IRQ_ON 132 
#define  STATE_RADIO_OFF 131 
#define  STATE_RADIO_ON 130 
#define  STATE_SLEEP 129 
#define  STATE_STANDBY 128 
 int /*<<< orphan*/  SUPPORTS_PS ; 
 int /*<<< orphan*/  SUPPORT_BAND_2GHZ ; 
 int /*<<< orphan*/  SUPPORT_BAND_5GHZ ; 
 int SUPPORT_RATE_CCK ; 
 int SUPPORT_RATE_OFDM ; 
 unsigned int TESTCSR ; 
 unsigned int TIMECSR ; 
 struct rt2x00_field32 TIMECSR_BEACON_EXPECT ; 
 struct rt2x00_field32 TIMECSR_US_64_COUNT ; 
 struct rt2x00_field32 TIMECSR_US_COUNT ; 
 unsigned int TXACKCSR0 ; 
 unsigned int TXCSR0 ; 
 struct rt2x00_field32 TXCSR0_ABORT ; 
 struct rt2x00_field32 TXCSR0_KICK_ATIM ; 
 struct rt2x00_field32 TXCSR0_KICK_PRIO ; 
 struct rt2x00_field32 TXCSR0_KICK_TX ; 
 unsigned int TXCSR1 ; 
 struct rt2x00_field32 TXCSR1_ACK_CONSUME_TIME ; 
 struct rt2x00_field32 TXCSR1_ACK_TIMEOUT ; 
 struct rt2x00_field32 TXCSR1_AUTORESPONDER ; 
 struct rt2x00_field32 TXCSR1_TSF_OFFSET ; 
 unsigned int TXCSR2 ; 
 struct rt2x00_field32 TXCSR2_NUM_ATIM ; 
 struct rt2x00_field32 TXCSR2_NUM_PRIO ; 
 struct rt2x00_field32 TXCSR2_NUM_TXD ; 
 struct rt2x00_field32 TXCSR2_TXD_SIZE ; 
 unsigned int TXCSR3 ; 
 struct rt2x00_field32 TXCSR3_TX_RING_REGISTER ; 
 unsigned int TXCSR4 ; 
 struct rt2x00_field32 TXCSR4_ATIM_RING_REGISTER ; 
 unsigned int TXCSR5 ; 
 struct rt2x00_field32 TXCSR5_PRIO_RING_REGISTER ; 
 unsigned int TXCSR6 ; 
 struct rt2x00_field32 TXCSR6_BEACON_RING_REGISTER ; 
 unsigned int TXCSR8 ; 
 struct rt2x00_field32 TXCSR8_BBP_ID0 ; 
 struct rt2x00_field32 TXCSR8_BBP_ID0_VALID ; 
 struct rt2x00_field32 TXCSR8_BBP_ID1 ; 
 struct rt2x00_field32 TXCSR8_BBP_ID1_VALID ; 
 struct rt2x00_field32 TXCSR8_BBP_ID2 ; 
 struct rt2x00_field32 TXCSR8_BBP_ID2_VALID ; 
 struct rt2x00_field32 TXCSR8_BBP_ID3 ; 
 struct rt2x00_field32 TXCSR8_BBP_ID3_VALID ; 
 int TXDONE_EXCESSIVE_RETRY ; 
 int TXDONE_FAILURE ; 
 int TXDONE_SUCCESS ; 
 void* TXD_DESC_SIZE ; 
 struct rt2x00_field32 TXD_W0_ACK ; 
 struct rt2x00_field32 TXD_W0_CIPHER_ALG ; 
 struct rt2x00_field32 TXD_W0_CIPHER_OWNER ; 
 struct rt2x00_field32 TXD_W0_DATABYTE_COUNT ; 
 struct rt2x00_field32 TXD_W0_IFS ; 
 struct rt2x00_field32 TXD_W0_MORE_FRAG ; 
 struct rt2x00_field32 TXD_W0_OFDM ; 
 struct rt2x00_field32 TXD_W0_OWNER_NIC ; 
 struct rt2x00_field32 TXD_W0_RESULT ; 
 struct rt2x00_field32 TXD_W0_RETRY_COUNT ; 
 struct rt2x00_field32 TXD_W0_RETRY_MODE ; 
 struct rt2x00_field32 TXD_W0_TIMESTAMP ; 
 struct rt2x00_field32 TXD_W0_VALID ; 
 struct rt2x00_field32 TXD_W10_RTS ; 
 struct rt2x00_field32 TXD_W1_BUFFER_ADDRESS ; 
 struct rt2x00_field32 TXD_W2_AIFS ; 
 struct rt2x00_field32 TXD_W2_CWMAX ; 
 struct rt2x00_field32 TXD_W2_CWMIN ; 
 struct rt2x00_field32 TXD_W2_IV_OFFSET ; 
 struct rt2x00_field32 TXD_W3_PLCP_LENGTH_HIGH ; 
 struct rt2x00_field32 TXD_W3_PLCP_LENGTH_LOW ; 
 struct rt2x00_field32 TXD_W3_PLCP_SERVICE ; 
 struct rt2x00_field32 TXD_W3_PLCP_SIGNAL ; 
 int /*<<< orphan*/  TXPOWER_FROM_DEV (char) ; 
 int TXPOWER_TO_DEV (int const) ; 
 scalar_t__ WAIT_FOR_BBP (struct rt2x00_dev*,int*) ; 
 scalar_t__ WAIT_FOR_RF (struct rt2x00_dev*,int*) ; 
 int /*<<< orphan*/  WIPHY_FLAG_PS_ON_BY_DEFAULT ; 
 int /*<<< orphan*/  __iowrite32_copy (scalar_t__,void const*,int const) ; 
 int /*<<< orphan*/  __set_bit (int,scalar_t__*) ; 
 int /*<<< orphan*/  cpu_to_le16 (scalar_t__) ; 
 int /*<<< orphan*/  cpu_to_le32 (int) ; 
 int /*<<< orphan*/  eeprom_93cx6_multiread (struct eeprom_93cx6*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ieee80211_hw_set (TYPE_14__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jiffies ; 
 struct channel_info* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 scalar_t__ le16_to_cpu (int /*<<< orphan*/ ) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy_fromio (void*,scalar_t__,int const) ; 
 scalar_t__ msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int readl (scalar_t__) ; 
 void* rf_vals_5222 ; 
 void* rf_vals_bg_2522 ; 
 void* rf_vals_bg_2523 ; 
 void* rf_vals_bg_2524 ; 
 void* rf_vals_bg_2525 ; 
 void* rf_vals_bg_2525e ; 
 int /*<<< orphan*/  rt2500pci_ops ; 
 int /*<<< orphan*/  rt2x00_eeprom_dbg (struct rt2x00_dev*,char*,scalar_t__) ; 
 int /*<<< orphan*/  rt2x00_err (struct rt2x00_dev*,char*,...) ; 
 scalar_t__ rt2x00_get_field16 (scalar_t__,int /*<<< orphan*/ ) ; 
 int rt2x00_get_field32 (int,struct rt2x00_field32) ; 
 int /*<<< orphan*/  rt2x00_info (struct rt2x00_dev*,char*,scalar_t__,...) ; 
 int /*<<< orphan*/  rt2x00_set_field16 (scalar_t__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  rt2x00_set_field32 (int*,struct rt2x00_field32,size_t const) ; 
 int /*<<< orphan*/  rt2x00_set_field8 (size_t*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  rt2x00lib_beacondone (struct rt2x00_dev*) ; 
 int /*<<< orphan*/  rt2x00lib_set_mac_address (struct rt2x00_dev*,size_t*) ; 
 int /*<<< orphan*/  rt2x00lib_txdone (struct queue_entry*,struct txdone_entry_desc*) ; 
 scalar_t__ rt2x00mmio_rxdone (struct rt2x00_dev*) ; 
 int rt2x00pci_probe (struct pci_dev*,int /*<<< orphan*/ *) ; 
 struct queue_entry* rt2x00queue_get_entry (struct data_queue*,int /*<<< orphan*/ ) ; 
 scalar_t__ rt2x00queue_map_txskb (struct queue_entry*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 scalar_t__ stub1 (struct rt2x00_dev*,int) ; 
 scalar_t__ stub2 (struct rt2x00_dev*,int) ; 
 int /*<<< orphan*/  tasklet_hi_schedule (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tasklet_kill (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  tasklet_schedule (int /*<<< orphan*/ *) ; 
 int test_bit (int,scalar_t__*) ; 
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

__attribute__((used)) static void rt2500pci_bbp_write(struct rt2x00_dev *rt2x00dev,
				const unsigned int word, const u8 value)
{
	u32 reg;

	mutex_lock(&rt2x00dev->csr_mutex);

	/*
	 * Wait until the BBP becomes available, afterwards we
	 * can safely write the new data into the register.
	 */
	if (WAIT_FOR_BBP(rt2x00dev, &reg)) {
		reg = 0;
		rt2x00_set_field32(&reg, BBPCSR_VALUE, value);
		rt2x00_set_field32(&reg, BBPCSR_REGNUM, word);
		rt2x00_set_field32(&reg, BBPCSR_BUSY, 1);
		rt2x00_set_field32(&reg, BBPCSR_WRITE_CONTROL, 1);

		rt2x00mmio_register_write(rt2x00dev, BBPCSR, reg);
	}

	mutex_unlock(&rt2x00dev->csr_mutex);
}

__attribute__((used)) static u8 rt2500pci_bbp_read(struct rt2x00_dev *rt2x00dev,
			     const unsigned int word)
{
	u32 reg;
	u8 value;

	mutex_lock(&rt2x00dev->csr_mutex);

	/*
	 * Wait until the BBP becomes available, afterwards we
	 * can safely write the read request into the register.
	 * After the data has been written, we wait until hardware
	 * returns the correct value, if at any time the register
	 * doesn't become available in time, reg will be 0xffffffff
	 * which means we return 0xff to the caller.
	 */
	if (WAIT_FOR_BBP(rt2x00dev, &reg)) {
		reg = 0;
		rt2x00_set_field32(&reg, BBPCSR_REGNUM, word);
		rt2x00_set_field32(&reg, BBPCSR_BUSY, 1);
		rt2x00_set_field32(&reg, BBPCSR_WRITE_CONTROL, 0);

		rt2x00mmio_register_write(rt2x00dev, BBPCSR, reg);

		WAIT_FOR_BBP(rt2x00dev, &reg);
	}

	value = rt2x00_get_field32(reg, BBPCSR_VALUE);

	mutex_unlock(&rt2x00dev->csr_mutex);

	return value;
}

__attribute__((used)) static void rt2500pci_rf_write(struct rt2x00_dev *rt2x00dev,
			       const unsigned int word, const u32 value)
{
	u32 reg;

	mutex_lock(&rt2x00dev->csr_mutex);

	/*
	 * Wait until the RF becomes available, afterwards we
	 * can safely write the new data into the register.
	 */
	if (WAIT_FOR_RF(rt2x00dev, &reg)) {
		reg = 0;
		rt2x00_set_field32(&reg, RFCSR_VALUE, value);
		rt2x00_set_field32(&reg, RFCSR_NUMBER_OF_BITS, 20);
		rt2x00_set_field32(&reg, RFCSR_IF_SELECT, 0);
		rt2x00_set_field32(&reg, RFCSR_BUSY, 1);

		rt2x00mmio_register_write(rt2x00dev, RFCSR, reg);
		rt2x00_rf_write(rt2x00dev, word, value);
	}

	mutex_unlock(&rt2x00dev->csr_mutex);
}

__attribute__((used)) static void rt2500pci_eepromregister_read(struct eeprom_93cx6 *eeprom)
{
	struct rt2x00_dev *rt2x00dev = eeprom->data;
	u32 reg;

	reg = rt2x00mmio_register_read(rt2x00dev, CSR21);

	eeprom->reg_data_in = !!rt2x00_get_field32(reg, CSR21_EEPROM_DATA_IN);
	eeprom->reg_data_out = !!rt2x00_get_field32(reg, CSR21_EEPROM_DATA_OUT);
	eeprom->reg_data_clock =
	    !!rt2x00_get_field32(reg, CSR21_EEPROM_DATA_CLOCK);
	eeprom->reg_chip_select =
	    !!rt2x00_get_field32(reg, CSR21_EEPROM_CHIP_SELECT);
}

__attribute__((used)) static void rt2500pci_eepromregister_write(struct eeprom_93cx6 *eeprom)
{
	struct rt2x00_dev *rt2x00dev = eeprom->data;
	u32 reg = 0;

	rt2x00_set_field32(&reg, CSR21_EEPROM_DATA_IN, !!eeprom->reg_data_in);
	rt2x00_set_field32(&reg, CSR21_EEPROM_DATA_OUT, !!eeprom->reg_data_out);
	rt2x00_set_field32(&reg, CSR21_EEPROM_DATA_CLOCK,
			   !!eeprom->reg_data_clock);
	rt2x00_set_field32(&reg, CSR21_EEPROM_CHIP_SELECT,
			   !!eeprom->reg_chip_select);

	rt2x00mmio_register_write(rt2x00dev, CSR21, reg);
}

__attribute__((used)) static int rt2500pci_rfkill_poll(struct rt2x00_dev *rt2x00dev)
{
	u32 reg;

	reg = rt2x00mmio_register_read(rt2x00dev, GPIOCSR);
	return rt2x00_get_field32(reg, GPIOCSR_VAL0);
}

__attribute__((used)) static void rt2500pci_config_filter(struct rt2x00_dev *rt2x00dev,
				    const unsigned int filter_flags)
{
	u32 reg;

	/*
	 * Start configuration steps.
	 * Note that the version error will always be dropped
	 * and broadcast frames will always be accepted since
	 * there is no filter for it at this time.
	 */
	reg = rt2x00mmio_register_read(rt2x00dev, RXCSR0);
	rt2x00_set_field32(&reg, RXCSR0_DROP_CRC,
			   !(filter_flags & FIF_FCSFAIL));
	rt2x00_set_field32(&reg, RXCSR0_DROP_PHYSICAL,
			   !(filter_flags & FIF_PLCPFAIL));
	rt2x00_set_field32(&reg, RXCSR0_DROP_CONTROL,
			   !(filter_flags & FIF_CONTROL));
	rt2x00_set_field32(&reg, RXCSR0_DROP_NOT_TO_ME,
			   !test_bit(CONFIG_MONITORING, &rt2x00dev->flags));
	rt2x00_set_field32(&reg, RXCSR0_DROP_TODS,
			   !test_bit(CONFIG_MONITORING, &rt2x00dev->flags) &&
			   !rt2x00dev->intf_ap_count);
	rt2x00_set_field32(&reg, RXCSR0_DROP_VERSION_ERROR, 1);
	rt2x00_set_field32(&reg, RXCSR0_DROP_MCAST,
			   !(filter_flags & FIF_ALLMULTI));
	rt2x00_set_field32(&reg, RXCSR0_DROP_BCAST, 0);
	rt2x00mmio_register_write(rt2x00dev, RXCSR0, reg);
}

__attribute__((used)) static void rt2500pci_config_intf(struct rt2x00_dev *rt2x00dev,
				  struct rt2x00_intf *intf,
				  struct rt2x00intf_conf *conf,
				  const unsigned int flags)
{
	struct data_queue *queue = rt2x00dev->bcn;
	unsigned int bcn_preload;
	u32 reg;

	if (flags & CONFIG_UPDATE_TYPE) {
		/*
		 * Enable beacon config
		 */
		bcn_preload = PREAMBLE + GET_DURATION(IEEE80211_HEADER, 20);
		reg = rt2x00mmio_register_read(rt2x00dev, BCNCSR1);
		rt2x00_set_field32(&reg, BCNCSR1_PRELOAD, bcn_preload);
		rt2x00_set_field32(&reg, BCNCSR1_BEACON_CWMIN, queue->cw_min);
		rt2x00mmio_register_write(rt2x00dev, BCNCSR1, reg);

		/*
		 * Enable synchronisation.
		 */
		reg = rt2x00mmio_register_read(rt2x00dev, CSR14);
		rt2x00_set_field32(&reg, CSR14_TSF_SYNC, conf->sync);
		rt2x00mmio_register_write(rt2x00dev, CSR14, reg);
	}

	if (flags & CONFIG_UPDATE_MAC)
		rt2x00mmio_register_multiwrite(rt2x00dev, CSR3,
					      conf->mac, sizeof(conf->mac));

	if (flags & CONFIG_UPDATE_BSSID)
		rt2x00mmio_register_multiwrite(rt2x00dev, CSR5,
					      conf->bssid, sizeof(conf->bssid));
}

__attribute__((used)) static void rt2500pci_config_erp(struct rt2x00_dev *rt2x00dev,
				 struct rt2x00lib_erp *erp,
				 u32 changed)
{
	int preamble_mask;
	u32 reg;

	/*
	 * When short preamble is enabled, we should set bit 0x08
	 */
	if (changed & BSS_CHANGED_ERP_PREAMBLE) {
		preamble_mask = erp->short_preamble << 3;

		reg = rt2x00mmio_register_read(rt2x00dev, TXCSR1);
		rt2x00_set_field32(&reg, TXCSR1_ACK_TIMEOUT, 0x162);
		rt2x00_set_field32(&reg, TXCSR1_ACK_CONSUME_TIME, 0xa2);
		rt2x00_set_field32(&reg, TXCSR1_TSF_OFFSET, IEEE80211_HEADER);
		rt2x00_set_field32(&reg, TXCSR1_AUTORESPONDER, 1);
		rt2x00mmio_register_write(rt2x00dev, TXCSR1, reg);

		reg = rt2x00mmio_register_read(rt2x00dev, ARCSR2);
		rt2x00_set_field32(&reg, ARCSR2_SIGNAL, 0x00);
		rt2x00_set_field32(&reg, ARCSR2_SERVICE, 0x04);
		rt2x00_set_field32(&reg, ARCSR2_LENGTH,
				   GET_DURATION(ACK_SIZE, 10));
		rt2x00mmio_register_write(rt2x00dev, ARCSR2, reg);

		reg = rt2x00mmio_register_read(rt2x00dev, ARCSR3);
		rt2x00_set_field32(&reg, ARCSR3_SIGNAL, 0x01 | preamble_mask);
		rt2x00_set_field32(&reg, ARCSR3_SERVICE, 0x04);
		rt2x00_set_field32(&reg, ARCSR2_LENGTH,
				   GET_DURATION(ACK_SIZE, 20));
		rt2x00mmio_register_write(rt2x00dev, ARCSR3, reg);

		reg = rt2x00mmio_register_read(rt2x00dev, ARCSR4);
		rt2x00_set_field32(&reg, ARCSR4_SIGNAL, 0x02 | preamble_mask);
		rt2x00_set_field32(&reg, ARCSR4_SERVICE, 0x04);
		rt2x00_set_field32(&reg, ARCSR2_LENGTH,
				   GET_DURATION(ACK_SIZE, 55));
		rt2x00mmio_register_write(rt2x00dev, ARCSR4, reg);

		reg = rt2x00mmio_register_read(rt2x00dev, ARCSR5);
		rt2x00_set_field32(&reg, ARCSR5_SIGNAL, 0x03 | preamble_mask);
		rt2x00_set_field32(&reg, ARCSR5_SERVICE, 0x84);
		rt2x00_set_field32(&reg, ARCSR2_LENGTH,
				   GET_DURATION(ACK_SIZE, 110));
		rt2x00mmio_register_write(rt2x00dev, ARCSR5, reg);
	}

	if (changed & BSS_CHANGED_BASIC_RATES)
		rt2x00mmio_register_write(rt2x00dev, ARCSR1, erp->basic_rates);

	if (changed & BSS_CHANGED_ERP_SLOT) {
		reg = rt2x00mmio_register_read(rt2x00dev, CSR11);
		rt2x00_set_field32(&reg, CSR11_SLOT_TIME, erp->slot_time);
		rt2x00mmio_register_write(rt2x00dev, CSR11, reg);

		reg = rt2x00mmio_register_read(rt2x00dev, CSR18);
		rt2x00_set_field32(&reg, CSR18_SIFS, erp->sifs);
		rt2x00_set_field32(&reg, CSR18_PIFS, erp->pifs);
		rt2x00mmio_register_write(rt2x00dev, CSR18, reg);

		reg = rt2x00mmio_register_read(rt2x00dev, CSR19);
		rt2x00_set_field32(&reg, CSR19_DIFS, erp->difs);
		rt2x00_set_field32(&reg, CSR19_EIFS, erp->eifs);
		rt2x00mmio_register_write(rt2x00dev, CSR19, reg);
	}

	if (changed & BSS_CHANGED_BEACON_INT) {
		reg = rt2x00mmio_register_read(rt2x00dev, CSR12);
		rt2x00_set_field32(&reg, CSR12_BEACON_INTERVAL,
				   erp->beacon_int * 16);
		rt2x00_set_field32(&reg, CSR12_CFP_MAX_DURATION,
				   erp->beacon_int * 16);
		rt2x00mmio_register_write(rt2x00dev, CSR12, reg);
	}

}

__attribute__((used)) static void rt2500pci_config_ant(struct rt2x00_dev *rt2x00dev,
				 struct antenna_setup *ant)
{
	u32 reg;
	u8 r14;
	u8 r2;

	/*
	 * We should never come here because rt2x00lib is supposed
	 * to catch this and send us the correct antenna explicitely.
	 */
	BUG_ON(ant->rx == ANTENNA_SW_DIVERSITY ||
	       ant->tx == ANTENNA_SW_DIVERSITY);

	reg = rt2x00mmio_register_read(rt2x00dev, BBPCSR1);
	r14 = rt2500pci_bbp_read(rt2x00dev, 14);
	r2 = rt2500pci_bbp_read(rt2x00dev, 2);

	/*
	 * Configure the TX antenna.
	 */
	switch (ant->tx) {
	case ANTENNA_A:
		rt2x00_set_field8(&r2, BBP_R2_TX_ANTENNA, 0);
		rt2x00_set_field32(&reg, BBPCSR1_CCK, 0);
		rt2x00_set_field32(&reg, BBPCSR1_OFDM, 0);
		break;
	case ANTENNA_B:
	default:
		rt2x00_set_field8(&r2, BBP_R2_TX_ANTENNA, 2);
		rt2x00_set_field32(&reg, BBPCSR1_CCK, 2);
		rt2x00_set_field32(&reg, BBPCSR1_OFDM, 2);
		break;
	}

	/*
	 * Configure the RX antenna.
	 */
	switch (ant->rx) {
	case ANTENNA_A:
		rt2x00_set_field8(&r14, BBP_R14_RX_ANTENNA, 0);
		break;
	case ANTENNA_B:
	default:
		rt2x00_set_field8(&r14, BBP_R14_RX_ANTENNA, 2);
		break;
	}

	/*
	 * RT2525E and RT5222 need to flip TX I/Q
	 */
	if (rt2x00_rf(rt2x00dev, RF2525E) || rt2x00_rf(rt2x00dev, RF5222)) {
		rt2x00_set_field8(&r2, BBP_R2_TX_IQ_FLIP, 1);
		rt2x00_set_field32(&reg, BBPCSR1_CCK_FLIP, 1);
		rt2x00_set_field32(&reg, BBPCSR1_OFDM_FLIP, 1);

		/*
		 * RT2525E does not need RX I/Q Flip.
		 */
		if (rt2x00_rf(rt2x00dev, RF2525E))
			rt2x00_set_field8(&r14, BBP_R14_RX_IQ_FLIP, 0);
	} else {
		rt2x00_set_field32(&reg, BBPCSR1_CCK_FLIP, 0);
		rt2x00_set_field32(&reg, BBPCSR1_OFDM_FLIP, 0);
	}

	rt2x00mmio_register_write(rt2x00dev, BBPCSR1, reg);
	rt2500pci_bbp_write(rt2x00dev, 14, r14);
	rt2500pci_bbp_write(rt2x00dev, 2, r2);
}

__attribute__((used)) static void rt2500pci_config_channel(struct rt2x00_dev *rt2x00dev,
				     struct rf_channel *rf, const int txpower)
{
	u8 r70;

	/*
	 * Set TXpower.
	 */
	rt2x00_set_field32(&rf->rf3, RF3_TXPOWER, TXPOWER_TO_DEV(txpower));

	/*
	 * Switch on tuning bits.
	 * For RT2523 devices we do not need to update the R1 register.
	 */
	if (!rt2x00_rf(rt2x00dev, RF2523))
		rt2x00_set_field32(&rf->rf1, RF1_TUNER, 1);
	rt2x00_set_field32(&rf->rf3, RF3_TUNER, 1);

	/*
	 * For RT2525 we should first set the channel to half band higher.
	 */
	if (rt2x00_rf(rt2x00dev, RF2525)) {
		static const u32 vals[] = {
			0x00080cbe, 0x00080d02, 0x00080d06, 0x00080d0a,
			0x00080d0e, 0x00080d12, 0x00080d16, 0x00080d1a,
			0x00080d1e, 0x00080d22, 0x00080d26, 0x00080d2a,
			0x00080d2e, 0x00080d3a
		};

		rt2500pci_rf_write(rt2x00dev, 1, rf->rf1);
		rt2500pci_rf_write(rt2x00dev, 2, vals[rf->channel - 1]);
		rt2500pci_rf_write(rt2x00dev, 3, rf->rf3);
		if (rf->rf4)
			rt2500pci_rf_write(rt2x00dev, 4, rf->rf4);
	}

	rt2500pci_rf_write(rt2x00dev, 1, rf->rf1);
	rt2500pci_rf_write(rt2x00dev, 2, rf->rf2);
	rt2500pci_rf_write(rt2x00dev, 3, rf->rf3);
	if (rf->rf4)
		rt2500pci_rf_write(rt2x00dev, 4, rf->rf4);

	/*
	 * Channel 14 requires the Japan filter bit to be set.
	 */
	r70 = 0x46;
	rt2x00_set_field8(&r70, BBP_R70_JAPAN_FILTER, rf->channel == 14);
	rt2500pci_bbp_write(rt2x00dev, 70, r70);

	msleep(1);

	/*
	 * Switch off tuning bits.
	 * For RT2523 devices we do not need to update the R1 register.
	 */
	if (!rt2x00_rf(rt2x00dev, RF2523)) {
		rt2x00_set_field32(&rf->rf1, RF1_TUNER, 0);
		rt2500pci_rf_write(rt2x00dev, 1, rf->rf1);
	}

	rt2x00_set_field32(&rf->rf3, RF3_TUNER, 0);
	rt2500pci_rf_write(rt2x00dev, 3, rf->rf3);

	/*
	 * Clear false CRC during channel switch.
	 */
	rf->rf1 = rt2x00mmio_register_read(rt2x00dev, CNT0);
}

__attribute__((used)) static void rt2500pci_config_txpower(struct rt2x00_dev *rt2x00dev,
				     const int txpower)
{
	u32 rf3;

	rf3 = rt2x00_rf_read(rt2x00dev, 3);
	rt2x00_set_field32(&rf3, RF3_TXPOWER, TXPOWER_TO_DEV(txpower));
	rt2500pci_rf_write(rt2x00dev, 3, rf3);
}

__attribute__((used)) static void rt2500pci_config_retry_limit(struct rt2x00_dev *rt2x00dev,
					 struct rt2x00lib_conf *libconf)
{
	u32 reg;

	reg = rt2x00mmio_register_read(rt2x00dev, CSR11);
	rt2x00_set_field32(&reg, CSR11_LONG_RETRY,
			   libconf->conf->long_frame_max_tx_count);
	rt2x00_set_field32(&reg, CSR11_SHORT_RETRY,
			   libconf->conf->short_frame_max_tx_count);
	rt2x00mmio_register_write(rt2x00dev, CSR11, reg);
}

__attribute__((used)) static void rt2500pci_config_ps(struct rt2x00_dev *rt2x00dev,
				struct rt2x00lib_conf *libconf)
{
	enum dev_state state =
	    (libconf->conf->flags & IEEE80211_CONF_PS) ?
		STATE_SLEEP : STATE_AWAKE;
	u32 reg;

	if (state == STATE_SLEEP) {
		reg = rt2x00mmio_register_read(rt2x00dev, CSR20);
		rt2x00_set_field32(&reg, CSR20_DELAY_AFTER_TBCN,
				   (rt2x00dev->beacon_int - 20) * 16);
		rt2x00_set_field32(&reg, CSR20_TBCN_BEFORE_WAKEUP,
				   libconf->conf->listen_interval - 1);

		/* We must first disable autowake before it can be enabled */
		rt2x00_set_field32(&reg, CSR20_AUTOWAKE, 0);
		rt2x00mmio_register_write(rt2x00dev, CSR20, reg);

		rt2x00_set_field32(&reg, CSR20_AUTOWAKE, 1);
		rt2x00mmio_register_write(rt2x00dev, CSR20, reg);
	} else {
		reg = rt2x00mmio_register_read(rt2x00dev, CSR20);
		rt2x00_set_field32(&reg, CSR20_AUTOWAKE, 0);
		rt2x00mmio_register_write(rt2x00dev, CSR20, reg);
	}

	rt2x00dev->ops->lib->set_device_state(rt2x00dev, state);
}

__attribute__((used)) static void rt2500pci_config(struct rt2x00_dev *rt2x00dev,
			     struct rt2x00lib_conf *libconf,
			     const unsigned int flags)
{
	if (flags & IEEE80211_CONF_CHANGE_CHANNEL)
		rt2500pci_config_channel(rt2x00dev, &libconf->rf,
					 libconf->conf->power_level);
	if ((flags & IEEE80211_CONF_CHANGE_POWER) &&
	    !(flags & IEEE80211_CONF_CHANGE_CHANNEL))
		rt2500pci_config_txpower(rt2x00dev,
					 libconf->conf->power_level);
	if (flags & IEEE80211_CONF_CHANGE_RETRY_LIMITS)
		rt2500pci_config_retry_limit(rt2x00dev, libconf);
	if (flags & IEEE80211_CONF_CHANGE_PS)
		rt2500pci_config_ps(rt2x00dev, libconf);
}

__attribute__((used)) static void rt2500pci_link_stats(struct rt2x00_dev *rt2x00dev,
				 struct link_qual *qual)
{
	u32 reg;

	/*
	 * Update FCS error count from register.
	 */
	reg = rt2x00mmio_register_read(rt2x00dev, CNT0);
	qual->rx_failed = rt2x00_get_field32(reg, CNT0_FCS_ERROR);

	/*
	 * Update False CCA count from register.
	 */
	reg = rt2x00mmio_register_read(rt2x00dev, CNT3);
	qual->false_cca = rt2x00_get_field32(reg, CNT3_FALSE_CCA);
}

__attribute__((used)) static inline void rt2500pci_set_vgc(struct rt2x00_dev *rt2x00dev,
				     struct link_qual *qual, u8 vgc_level)
{
	if (qual->vgc_level_reg != vgc_level) {
		rt2500pci_bbp_write(rt2x00dev, 17, vgc_level);
		qual->vgc_level = vgc_level;
		qual->vgc_level_reg = vgc_level;
	}
}

__attribute__((used)) static void rt2500pci_reset_tuner(struct rt2x00_dev *rt2x00dev,
				  struct link_qual *qual)
{
	rt2500pci_set_vgc(rt2x00dev, qual, 0x48);
}

__attribute__((used)) static void rt2500pci_link_tuner(struct rt2x00_dev *rt2x00dev,
				 struct link_qual *qual, const u32 count)
{
	/*
	 * To prevent collisions with MAC ASIC on chipsets
	 * up to version C the link tuning should halt after 20
	 * seconds while being associated.
	 */
	if (rt2x00_rev(rt2x00dev) < RT2560_VERSION_D &&
	    rt2x00dev->intf_associated && count > 20)
		return;

	/*
	 * Chipset versions C and lower should directly continue
	 * to the dynamic CCA tuning. Chipset version D and higher
	 * should go straight to dynamic CCA tuning when they
	 * are not associated.
	 */
	if (rt2x00_rev(rt2x00dev) < RT2560_VERSION_D ||
	    !rt2x00dev->intf_associated)
		goto dynamic_cca_tune;

	/*
	 * A too low RSSI will cause too much false CCA which will
	 * then corrupt the R17 tuning. To remidy this the tuning should
	 * be stopped (While making sure the R17 value will not exceed limits)
	 */
	if (qual->rssi < -80 && count > 20) {
		if (qual->vgc_level_reg >= 0x41)
			rt2500pci_set_vgc(rt2x00dev, qual, qual->vgc_level);
		return;
	}

	/*
	 * Special big-R17 for short distance
	 */
	if (qual->rssi >= -58) {
		rt2500pci_set_vgc(rt2x00dev, qual, 0x50);
		return;
	}

	/*
	 * Special mid-R17 for middle distance
	 */
	if (qual->rssi >= -74) {
		rt2500pci_set_vgc(rt2x00dev, qual, 0x41);
		return;
	}

	/*
	 * Leave short or middle distance condition, restore r17
	 * to the dynamic tuning range.
	 */
	if (qual->vgc_level_reg >= 0x41) {
		rt2500pci_set_vgc(rt2x00dev, qual, qual->vgc_level);
		return;
	}

dynamic_cca_tune:

	/*
	 * R17 is inside the dynamic tuning range,
	 * start tuning the link based on the false cca counter.
	 */
	if (qual->false_cca > 512 && qual->vgc_level_reg < 0x40)
		rt2500pci_set_vgc(rt2x00dev, qual, ++qual->vgc_level_reg);
	else if (qual->false_cca < 100 && qual->vgc_level_reg > 0x32)
		rt2500pci_set_vgc(rt2x00dev, qual, --qual->vgc_level_reg);
}

__attribute__((used)) static void rt2500pci_start_queue(struct data_queue *queue)
{
	struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
	u32 reg;

	switch (queue->qid) {
	case QID_RX:
		reg = rt2x00mmio_register_read(rt2x00dev, RXCSR0);
		rt2x00_set_field32(&reg, RXCSR0_DISABLE_RX, 0);
		rt2x00mmio_register_write(rt2x00dev, RXCSR0, reg);
		break;
	case QID_BEACON:
		reg = rt2x00mmio_register_read(rt2x00dev, CSR14);
		rt2x00_set_field32(&reg, CSR14_TSF_COUNT, 1);
		rt2x00_set_field32(&reg, CSR14_TBCN, 1);
		rt2x00_set_field32(&reg, CSR14_BEACON_GEN, 1);
		rt2x00mmio_register_write(rt2x00dev, CSR14, reg);
		break;
	default:
		break;
	}
}

__attribute__((used)) static void rt2500pci_kick_queue(struct data_queue *queue)
{
	struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
	u32 reg;

	switch (queue->qid) {
	case QID_AC_VO:
		reg = rt2x00mmio_register_read(rt2x00dev, TXCSR0);
		rt2x00_set_field32(&reg, TXCSR0_KICK_PRIO, 1);
		rt2x00mmio_register_write(rt2x00dev, TXCSR0, reg);
		break;
	case QID_AC_VI:
		reg = rt2x00mmio_register_read(rt2x00dev, TXCSR0);
		rt2x00_set_field32(&reg, TXCSR0_KICK_TX, 1);
		rt2x00mmio_register_write(rt2x00dev, TXCSR0, reg);
		break;
	case QID_ATIM:
		reg = rt2x00mmio_register_read(rt2x00dev, TXCSR0);
		rt2x00_set_field32(&reg, TXCSR0_KICK_ATIM, 1);
		rt2x00mmio_register_write(rt2x00dev, TXCSR0, reg);
		break;
	default:
		break;
	}
}

__attribute__((used)) static void rt2500pci_stop_queue(struct data_queue *queue)
{
	struct rt2x00_dev *rt2x00dev = queue->rt2x00dev;
	u32 reg;

	switch (queue->qid) {
	case QID_AC_VO:
	case QID_AC_VI:
	case QID_ATIM:
		reg = rt2x00mmio_register_read(rt2x00dev, TXCSR0);
		rt2x00_set_field32(&reg, TXCSR0_ABORT, 1);
		rt2x00mmio_register_write(rt2x00dev, TXCSR0, reg);
		break;
	case QID_RX:
		reg = rt2x00mmio_register_read(rt2x00dev, RXCSR0);
		rt2x00_set_field32(&reg, RXCSR0_DISABLE_RX, 1);
		rt2x00mmio_register_write(rt2x00dev, RXCSR0, reg);
		break;
	case QID_BEACON:
		reg = rt2x00mmio_register_read(rt2x00dev, CSR14);
		rt2x00_set_field32(&reg, CSR14_TSF_COUNT, 0);
		rt2x00_set_field32(&reg, CSR14_TBCN, 0);
		rt2x00_set_field32(&reg, CSR14_BEACON_GEN, 0);
		rt2x00mmio_register_write(rt2x00dev, CSR14, reg);

		/*
		 * Wait for possibly running tbtt tasklets.
		 */
		tasklet_kill(&rt2x00dev->tbtt_tasklet);
		break;
	default:
		break;
	}
}

__attribute__((used)) static bool rt2500pci_get_entry_state(struct queue_entry *entry)
{
	struct queue_entry_priv_mmio *entry_priv = entry->priv_data;
	u32 word;

	if (entry->queue->qid == QID_RX) {
		word = rt2x00_desc_read(entry_priv->desc, 0);

		return rt2x00_get_field32(word, RXD_W0_OWNER_NIC);
	} else {
		word = rt2x00_desc_read(entry_priv->desc, 0);

		return (rt2x00_get_field32(word, TXD_W0_OWNER_NIC) ||
		        rt2x00_get_field32(word, TXD_W0_VALID));
	}
}

__attribute__((used)) static void rt2500pci_clear_entry(struct queue_entry *entry)
{
	struct queue_entry_priv_mmio *entry_priv = entry->priv_data;
	struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
	u32 word;

	if (entry->queue->qid == QID_RX) {
		word = rt2x00_desc_read(entry_priv->desc, 1);
		rt2x00_set_field32(&word, RXD_W1_BUFFER_ADDRESS, skbdesc->skb_dma);
		rt2x00_desc_write(entry_priv->desc, 1, word);

		word = rt2x00_desc_read(entry_priv->desc, 0);
		rt2x00_set_field32(&word, RXD_W0_OWNER_NIC, 1);
		rt2x00_desc_write(entry_priv->desc, 0, word);
	} else {
		word = rt2x00_desc_read(entry_priv->desc, 0);
		rt2x00_set_field32(&word, TXD_W0_VALID, 0);
		rt2x00_set_field32(&word, TXD_W0_OWNER_NIC, 0);
		rt2x00_desc_write(entry_priv->desc, 0, word);
	}
}

__attribute__((used)) static int rt2500pci_init_queues(struct rt2x00_dev *rt2x00dev)
{
	struct queue_entry_priv_mmio *entry_priv;
	u32 reg;

	/*
	 * Initialize registers.
	 */
	reg = rt2x00mmio_register_read(rt2x00dev, TXCSR2);
	rt2x00_set_field32(&reg, TXCSR2_TXD_SIZE, rt2x00dev->tx[0].desc_size);
	rt2x00_set_field32(&reg, TXCSR2_NUM_TXD, rt2x00dev->tx[1].limit);
	rt2x00_set_field32(&reg, TXCSR2_NUM_ATIM, rt2x00dev->atim->limit);
	rt2x00_set_field32(&reg, TXCSR2_NUM_PRIO, rt2x00dev->tx[0].limit);
	rt2x00mmio_register_write(rt2x00dev, TXCSR2, reg);

	entry_priv = rt2x00dev->tx[1].entries[0].priv_data;
	reg = rt2x00mmio_register_read(rt2x00dev, TXCSR3);
	rt2x00_set_field32(&reg, TXCSR3_TX_RING_REGISTER,
			   entry_priv->desc_dma);
	rt2x00mmio_register_write(rt2x00dev, TXCSR3, reg);

	entry_priv = rt2x00dev->tx[0].entries[0].priv_data;
	reg = rt2x00mmio_register_read(rt2x00dev, TXCSR5);
	rt2x00_set_field32(&reg, TXCSR5_PRIO_RING_REGISTER,
			   entry_priv->desc_dma);
	rt2x00mmio_register_write(rt2x00dev, TXCSR5, reg);

	entry_priv = rt2x00dev->atim->entries[0].priv_data;
	reg = rt2x00mmio_register_read(rt2x00dev, TXCSR4);
	rt2x00_set_field32(&reg, TXCSR4_ATIM_RING_REGISTER,
			   entry_priv->desc_dma);
	rt2x00mmio_register_write(rt2x00dev, TXCSR4, reg);

	entry_priv = rt2x00dev->bcn->entries[0].priv_data;
	reg = rt2x00mmio_register_read(rt2x00dev, TXCSR6);
	rt2x00_set_field32(&reg, TXCSR6_BEACON_RING_REGISTER,
			   entry_priv->desc_dma);
	rt2x00mmio_register_write(rt2x00dev, TXCSR6, reg);

	reg = rt2x00mmio_register_read(rt2x00dev, RXCSR1);
	rt2x00_set_field32(&reg, RXCSR1_RXD_SIZE, rt2x00dev->rx->desc_size);
	rt2x00_set_field32(&reg, RXCSR1_NUM_RXD, rt2x00dev->rx->limit);
	rt2x00mmio_register_write(rt2x00dev, RXCSR1, reg);

	entry_priv = rt2x00dev->rx->entries[0].priv_data;
	reg = rt2x00mmio_register_read(rt2x00dev, RXCSR2);
	rt2x00_set_field32(&reg, RXCSR2_RX_RING_REGISTER,
			   entry_priv->desc_dma);
	rt2x00mmio_register_write(rt2x00dev, RXCSR2, reg);

	return 0;
}

__attribute__((used)) static int rt2500pci_init_registers(struct rt2x00_dev *rt2x00dev)
{
	u32 reg;

	rt2x00mmio_register_write(rt2x00dev, PSCSR0, 0x00020002);
	rt2x00mmio_register_write(rt2x00dev, PSCSR1, 0x00000002);
	rt2x00mmio_register_write(rt2x00dev, PSCSR2, 0x00020002);
	rt2x00mmio_register_write(rt2x00dev, PSCSR3, 0x00000002);

	reg = rt2x00mmio_register_read(rt2x00dev, TIMECSR);
	rt2x00_set_field32(&reg, TIMECSR_US_COUNT, 33);
	rt2x00_set_field32(&reg, TIMECSR_US_64_COUNT, 63);
	rt2x00_set_field32(&reg, TIMECSR_BEACON_EXPECT, 0);
	rt2x00mmio_register_write(rt2x00dev, TIMECSR, reg);

	reg = rt2x00mmio_register_read(rt2x00dev, CSR9);
	rt2x00_set_field32(&reg, CSR9_MAX_FRAME_UNIT,
			   rt2x00dev->rx->data_size / 128);
	rt2x00mmio_register_write(rt2x00dev, CSR9, reg);

	/*
	 * Always use CWmin and CWmax set in descriptor.
	 */
	reg = rt2x00mmio_register_read(rt2x00dev, CSR11);
	rt2x00_set_field32(&reg, CSR11_CW_SELECT, 0);
	rt2x00mmio_register_write(rt2x00dev, CSR11, reg);

	reg = rt2x00mmio_register_read(rt2x00dev, CSR14);
	rt2x00_set_field32(&reg, CSR14_TSF_COUNT, 0);
	rt2x00_set_field32(&reg, CSR14_TSF_SYNC, 0);
	rt2x00_set_field32(&reg, CSR14_TBCN, 0);
	rt2x00_set_field32(&reg, CSR14_TCFP, 0);
	rt2x00_set_field32(&reg, CSR14_TATIMW, 0);
	rt2x00_set_field32(&reg, CSR14_BEACON_GEN, 0);
	rt2x00_set_field32(&reg, CSR14_CFP_COUNT_PRELOAD, 0);
	rt2x00_set_field32(&reg, CSR14_TBCM_PRELOAD, 0);
	rt2x00mmio_register_write(rt2x00dev, CSR14, reg);

	rt2x00mmio_register_write(rt2x00dev, CNT3, 0);

	reg = rt2x00mmio_register_read(rt2x00dev, TXCSR8);
	rt2x00_set_field32(&reg, TXCSR8_BBP_ID0, 10);
	rt2x00_set_field32(&reg, TXCSR8_BBP_ID0_VALID, 1);
	rt2x00_set_field32(&reg, TXCSR8_BBP_ID1, 11);
	rt2x00_set_field32(&reg, TXCSR8_BBP_ID1_VALID, 1);
	rt2x00_set_field32(&reg, TXCSR8_BBP_ID2, 13);
	rt2x00_set_field32(&reg, TXCSR8_BBP_ID2_VALID, 1);
	rt2x00_set_field32(&reg, TXCSR8_BBP_ID3, 12);
	rt2x00_set_field32(&reg, TXCSR8_BBP_ID3_VALID, 1);
	rt2x00mmio_register_write(rt2x00dev, TXCSR8, reg);

	reg = rt2x00mmio_register_read(rt2x00dev, ARTCSR0);
	rt2x00_set_field32(&reg, ARTCSR0_ACK_CTS_1MBS, 112);
	rt2x00_set_field32(&reg, ARTCSR0_ACK_CTS_2MBS, 56);
	rt2x00_set_field32(&reg, ARTCSR0_ACK_CTS_5_5MBS, 20);
	rt2x00_set_field32(&reg, ARTCSR0_ACK_CTS_11MBS, 10);
	rt2x00mmio_register_write(rt2x00dev, ARTCSR0, reg);

	reg = rt2x00mmio_register_read(rt2x00dev, ARTCSR1);
	rt2x00_set_field32(&reg, ARTCSR1_ACK_CTS_6MBS, 45);
	rt2x00_set_field32(&reg, ARTCSR1_ACK_CTS_9MBS, 37);
	rt2x00_set_field32(&reg, ARTCSR1_ACK_CTS_12MBS, 33);
	rt2x00_set_field32(&reg, ARTCSR1_ACK_CTS_18MBS, 29);
	rt2x00mmio_register_write(rt2x00dev, ARTCSR1, reg);

	reg = rt2x00mmio_register_read(rt2x00dev, ARTCSR2);
	rt2x00_set_field32(&reg, ARTCSR2_ACK_CTS_24MBS, 29);
	rt2x00_set_field32(&reg, ARTCSR2_ACK_CTS_36MBS, 25);
	rt2x00_set_field32(&reg, ARTCSR2_ACK_CTS_48MBS, 25);
	rt2x00_set_field32(&reg, ARTCSR2_ACK_CTS_54MBS, 25);
	rt2x00mmio_register_write(rt2x00dev, ARTCSR2, reg);

	reg = rt2x00mmio_register_read(rt2x00dev, RXCSR3);
	rt2x00_set_field32(&reg, RXCSR3_BBP_ID0, 47); /* CCK Signal */
	rt2x00_set_field32(&reg, RXCSR3_BBP_ID0_VALID, 1);
	rt2x00_set_field32(&reg, RXCSR3_BBP_ID1, 51); /* Rssi */
	rt2x00_set_field32(&reg, RXCSR3_BBP_ID1_VALID, 1);
	rt2x00_set_field32(&reg, RXCSR3_BBP_ID2, 42); /* OFDM Rate */
	rt2x00_set_field32(&reg, RXCSR3_BBP_ID2_VALID, 1);
	rt2x00_set_field32(&reg, RXCSR3_BBP_ID3, 51); /* RSSI */
	rt2x00_set_field32(&reg, RXCSR3_BBP_ID3_VALID, 1);
	rt2x00mmio_register_write(rt2x00dev, RXCSR3, reg);

	reg = rt2x00mmio_register_read(rt2x00dev, PCICSR);
	rt2x00_set_field32(&reg, PCICSR_BIG_ENDIAN, 0);
	rt2x00_set_field32(&reg, PCICSR_RX_TRESHOLD, 0);
	rt2x00_set_field32(&reg, PCICSR_TX_TRESHOLD, 3);
	rt2x00_set_field32(&reg, PCICSR_BURST_LENTH, 1);
	rt2x00_set_field32(&reg, PCICSR_ENABLE_CLK, 1);
	rt2x00_set_field32(&reg, PCICSR_READ_MULTIPLE, 1);
	rt2x00_set_field32(&reg, PCICSR_WRITE_INVALID, 1);
	rt2x00mmio_register_write(rt2x00dev, PCICSR, reg);

	rt2x00mmio_register_write(rt2x00dev, PWRCSR0, 0x3f3b3100);

	rt2x00mmio_register_write(rt2x00dev, GPIOCSR, 0x0000ff00);
	rt2x00mmio_register_write(rt2x00dev, TESTCSR, 0x000000f0);

	if (rt2x00dev->ops->lib->set_device_state(rt2x00dev, STATE_AWAKE))
		return -EBUSY;

	rt2x00mmio_register_write(rt2x00dev, MACCSR0, 0x00213223);
	rt2x00mmio_register_write(rt2x00dev, MACCSR1, 0x00235518);

	reg = rt2x00mmio_register_read(rt2x00dev, MACCSR2);
	rt2x00_set_field32(&reg, MACCSR2_DELAY, 64);
	rt2x00mmio_register_write(rt2x00dev, MACCSR2, reg);

	reg = rt2x00mmio_register_read(rt2x00dev, RALINKCSR);
	rt2x00_set_field32(&reg, RALINKCSR_AR_BBP_DATA0, 17);
	rt2x00_set_field32(&reg, RALINKCSR_AR_BBP_ID0, 26);
	rt2x00_set_field32(&reg, RALINKCSR_AR_BBP_VALID0, 1);
	rt2x00_set_field32(&reg, RALINKCSR_AR_BBP_DATA1, 0);
	rt2x00_set_field32(&reg, RALINKCSR_AR_BBP_ID1, 26);
	rt2x00_set_field32(&reg, RALINKCSR_AR_BBP_VALID1, 1);
	rt2x00mmio_register_write(rt2x00dev, RALINKCSR, reg);

	rt2x00mmio_register_write(rt2x00dev, BBPCSR1, 0x82188200);

	rt2x00mmio_register_write(rt2x00dev, TXACKCSR0, 0x00000020);

	reg = rt2x00mmio_register_read(rt2x00dev, CSR1);
	rt2x00_set_field32(&reg, CSR1_SOFT_RESET, 1);
	rt2x00_set_field32(&reg, CSR1_BBP_RESET, 0);
	rt2x00_set_field32(&reg, CSR1_HOST_READY, 0);
	rt2x00mmio_register_write(rt2x00dev, CSR1, reg);

	reg = rt2x00mmio_register_read(rt2x00dev, CSR1);
	rt2x00_set_field32(&reg, CSR1_SOFT_RESET, 0);
	rt2x00_set_field32(&reg, CSR1_HOST_READY, 1);
	rt2x00mmio_register_write(rt2x00dev, CSR1, reg);

	/*
	 * We must clear the FCS and FIFO error count.
	 * These registers are cleared on read,
	 * so we may pass a useless variable to store the value.
	 */
	reg = rt2x00mmio_register_read(rt2x00dev, CNT0);
	reg = rt2x00mmio_register_read(rt2x00dev, CNT4);

	return 0;
}

__attribute__((used)) static int rt2500pci_wait_bbp_ready(struct rt2x00_dev *rt2x00dev)
{
	unsigned int i;
	u8 value;

	for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
		value = rt2500pci_bbp_read(rt2x00dev, 0);
		if ((value != 0xff) && (value != 0x00))
			return 0;
		udelay(REGISTER_BUSY_DELAY);
	}

	rt2x00_err(rt2x00dev, "BBP register access failed, aborting\n");
	return -EACCES;
}

__attribute__((used)) static int rt2500pci_init_bbp(struct rt2x00_dev *rt2x00dev)
{
	unsigned int i;
	u16 eeprom;
	u8 reg_id;
	u8 value;

	if (unlikely(rt2500pci_wait_bbp_ready(rt2x00dev)))
		return -EACCES;

	rt2500pci_bbp_write(rt2x00dev, 3, 0x02);
	rt2500pci_bbp_write(rt2x00dev, 4, 0x19);
	rt2500pci_bbp_write(rt2x00dev, 14, 0x1c);
	rt2500pci_bbp_write(rt2x00dev, 15, 0x30);
	rt2500pci_bbp_write(rt2x00dev, 16, 0xac);
	rt2500pci_bbp_write(rt2x00dev, 18, 0x18);
	rt2500pci_bbp_write(rt2x00dev, 19, 0xff);
	rt2500pci_bbp_write(rt2x00dev, 20, 0x1e);
	rt2500pci_bbp_write(rt2x00dev, 21, 0x08);
	rt2500pci_bbp_write(rt2x00dev, 22, 0x08);
	rt2500pci_bbp_write(rt2x00dev, 23, 0x08);
	rt2500pci_bbp_write(rt2x00dev, 24, 0x70);
	rt2500pci_bbp_write(rt2x00dev, 25, 0x40);
	rt2500pci_bbp_write(rt2x00dev, 26, 0x08);
	rt2500pci_bbp_write(rt2x00dev, 27, 0x23);
	rt2500pci_bbp_write(rt2x00dev, 30, 0x10);
	rt2500pci_bbp_write(rt2x00dev, 31, 0x2b);
	rt2500pci_bbp_write(rt2x00dev, 32, 0xb9);
	rt2500pci_bbp_write(rt2x00dev, 34, 0x12);
	rt2500pci_bbp_write(rt2x00dev, 35, 0x50);
	rt2500pci_bbp_write(rt2x00dev, 39, 0xc4);
	rt2500pci_bbp_write(rt2x00dev, 40, 0x02);
	rt2500pci_bbp_write(rt2x00dev, 41, 0x60);
	rt2500pci_bbp_write(rt2x00dev, 53, 0x10);
	rt2500pci_bbp_write(rt2x00dev, 54, 0x18);
	rt2500pci_bbp_write(rt2x00dev, 56, 0x08);
	rt2500pci_bbp_write(rt2x00dev, 57, 0x10);
	rt2500pci_bbp_write(rt2x00dev, 58, 0x08);
	rt2500pci_bbp_write(rt2x00dev, 61, 0x6d);
	rt2500pci_bbp_write(rt2x00dev, 62, 0x10);

	for (i = 0; i < EEPROM_BBP_SIZE; i++) {
		eeprom = rt2x00_eeprom_read(rt2x00dev, EEPROM_BBP_START + i);

		if (eeprom != 0xffff && eeprom != 0x0000) {
			reg_id = rt2x00_get_field16(eeprom, EEPROM_BBP_REG_ID);
			value = rt2x00_get_field16(eeprom, EEPROM_BBP_VALUE);
			rt2500pci_bbp_write(rt2x00dev, reg_id, value);
		}
	}

	return 0;
}

__attribute__((used)) static void rt2500pci_toggle_irq(struct rt2x00_dev *rt2x00dev,
				 enum dev_state state)
{
	int mask = (state == STATE_RADIO_IRQ_OFF);
	u32 reg;
	unsigned long flags;

	/*
	 * When interrupts are being enabled, the interrupt registers
	 * should clear the register to assure a clean state.
	 */
	if (state == STATE_RADIO_IRQ_ON) {
		reg = rt2x00mmio_register_read(rt2x00dev, CSR7);
		rt2x00mmio_register_write(rt2x00dev, CSR7, reg);
	}

	/*
	 * Only toggle the interrupts bits we are going to use.
	 * Non-checked interrupt bits are disabled by default.
	 */
	spin_lock_irqsave(&rt2x00dev->irqmask_lock, flags);

	reg = rt2x00mmio_register_read(rt2x00dev, CSR8);
	rt2x00_set_field32(&reg, CSR8_TBCN_EXPIRE, mask);
	rt2x00_set_field32(&reg, CSR8_TXDONE_TXRING, mask);
	rt2x00_set_field32(&reg, CSR8_TXDONE_ATIMRING, mask);
	rt2x00_set_field32(&reg, CSR8_TXDONE_PRIORING, mask);
	rt2x00_set_field32(&reg, CSR8_RXDONE, mask);
	rt2x00mmio_register_write(rt2x00dev, CSR8, reg);

	spin_unlock_irqrestore(&rt2x00dev->irqmask_lock, flags);

	if (state == STATE_RADIO_IRQ_OFF) {
		/*
		 * Ensure that all tasklets are finished.
		 */
		tasklet_kill(&rt2x00dev->txstatus_tasklet);
		tasklet_kill(&rt2x00dev->rxdone_tasklet);
		tasklet_kill(&rt2x00dev->tbtt_tasklet);
	}
}

__attribute__((used)) static int rt2500pci_enable_radio(struct rt2x00_dev *rt2x00dev)
{
	/*
	 * Initialize all registers.
	 */
	if (unlikely(rt2500pci_init_queues(rt2x00dev) ||
		     rt2500pci_init_registers(rt2x00dev) ||
		     rt2500pci_init_bbp(rt2x00dev)))
		return -EIO;

	return 0;
}

__attribute__((used)) static void rt2500pci_disable_radio(struct rt2x00_dev *rt2x00dev)
{
	/*
	 * Disable power
	 */
	rt2x00mmio_register_write(rt2x00dev, PWRCSR0, 0);
}

__attribute__((used)) static int rt2500pci_set_state(struct rt2x00_dev *rt2x00dev,
			       enum dev_state state)
{
	u32 reg, reg2;
	unsigned int i;
	char put_to_sleep;
	char bbp_state;
	char rf_state;

	put_to_sleep = (state != STATE_AWAKE);

	reg = rt2x00mmio_register_read(rt2x00dev, PWRCSR1);
	rt2x00_set_field32(&reg, PWRCSR1_SET_STATE, 1);
	rt2x00_set_field32(&reg, PWRCSR1_BBP_DESIRE_STATE, state);
	rt2x00_set_field32(&reg, PWRCSR1_RF_DESIRE_STATE, state);
	rt2x00_set_field32(&reg, PWRCSR1_PUT_TO_SLEEP, put_to_sleep);
	rt2x00mmio_register_write(rt2x00dev, PWRCSR1, reg);

	/*
	 * Device is not guaranteed to be in the requested state yet.
	 * We must wait until the register indicates that the
	 * device has entered the correct state.
	 */
	for (i = 0; i < REGISTER_BUSY_COUNT; i++) {
		reg2 = rt2x00mmio_register_read(rt2x00dev, PWRCSR1);
		bbp_state = rt2x00_get_field32(reg2, PWRCSR1_BBP_CURR_STATE);
		rf_state = rt2x00_get_field32(reg2, PWRCSR1_RF_CURR_STATE);
		if (bbp_state == state && rf_state == state)
			return 0;
		rt2x00mmio_register_write(rt2x00dev, PWRCSR1, reg);
		msleep(10);
	}

	return -EBUSY;
}

__attribute__((used)) static int rt2500pci_set_device_state(struct rt2x00_dev *rt2x00dev,
				      enum dev_state state)
{
	int retval = 0;

	switch (state) {
	case STATE_RADIO_ON:
		retval = rt2500pci_enable_radio(rt2x00dev);
		break;
	case STATE_RADIO_OFF:
		rt2500pci_disable_radio(rt2x00dev);
		break;
	case STATE_RADIO_IRQ_ON:
	case STATE_RADIO_IRQ_OFF:
		rt2500pci_toggle_irq(rt2x00dev, state);
		break;
	case STATE_DEEP_SLEEP:
	case STATE_SLEEP:
	case STATE_STANDBY:
	case STATE_AWAKE:
		retval = rt2500pci_set_state(rt2x00dev, state);
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

__attribute__((used)) static void rt2500pci_write_tx_desc(struct queue_entry *entry,
				    struct txentry_desc *txdesc)
{
	struct skb_frame_desc *skbdesc = get_skb_frame_desc(entry->skb);
	struct queue_entry_priv_mmio *entry_priv = entry->priv_data;
	__le32 *txd = entry_priv->desc;
	u32 word;

	/*
	 * Start writing the descriptor words.
	 */
	word = rt2x00_desc_read(txd, 1);
	rt2x00_set_field32(&word, TXD_W1_BUFFER_ADDRESS, skbdesc->skb_dma);
	rt2x00_desc_write(txd, 1, word);

	word = rt2x00_desc_read(txd, 2);
	rt2x00_set_field32(&word, TXD_W2_IV_OFFSET, IEEE80211_HEADER);
	rt2x00_set_field32(&word, TXD_W2_AIFS, entry->queue->aifs);
	rt2x00_set_field32(&word, TXD_W2_CWMIN, entry->queue->cw_min);
	rt2x00_set_field32(&word, TXD_W2_CWMAX, entry->queue->cw_max);
	rt2x00_desc_write(txd, 2, word);

	word = rt2x00_desc_read(txd, 3);
	rt2x00_set_field32(&word, TXD_W3_PLCP_SIGNAL, txdesc->u.plcp.signal);
	rt2x00_set_field32(&word, TXD_W3_PLCP_SERVICE, txdesc->u.plcp.service);
	rt2x00_set_field32(&word, TXD_W3_PLCP_LENGTH_LOW,
			   txdesc->u.plcp.length_low);
	rt2x00_set_field32(&word, TXD_W3_PLCP_LENGTH_HIGH,
			   txdesc->u.plcp.length_high);
	rt2x00_desc_write(txd, 3, word);

	word = rt2x00_desc_read(txd, 10);
	rt2x00_set_field32(&word, TXD_W10_RTS,
			   test_bit(ENTRY_TXD_RTS_FRAME, &txdesc->flags));
	rt2x00_desc_write(txd, 10, word);

	/*
	 * Writing TXD word 0 must the last to prevent a race condition with
	 * the device, whereby the device may take hold of the TXD before we
	 * finished updating it.
	 */
	word = rt2x00_desc_read(txd, 0);
	rt2x00_set_field32(&word, TXD_W0_OWNER_NIC, 1);
	rt2x00_set_field32(&word, TXD_W0_VALID, 1);
	rt2x00_set_field32(&word, TXD_W0_MORE_FRAG,
			   test_bit(ENTRY_TXD_MORE_FRAG, &txdesc->flags));
	rt2x00_set_field32(&word, TXD_W0_ACK,
			   test_bit(ENTRY_TXD_ACK, &txdesc->flags));
	rt2x00_set_field32(&word, TXD_W0_TIMESTAMP,
			   test_bit(ENTRY_TXD_REQ_TIMESTAMP, &txdesc->flags));
	rt2x00_set_field32(&word, TXD_W0_OFDM,
			   (txdesc->rate_mode == RATE_MODE_OFDM));
	rt2x00_set_field32(&word, TXD_W0_CIPHER_OWNER, 1);
	rt2x00_set_field32(&word, TXD_W0_IFS, txdesc->u.plcp.ifs);
	rt2x00_set_field32(&word, TXD_W0_RETRY_MODE,
			   test_bit(ENTRY_TXD_RETRY_MODE, &txdesc->flags));
	rt2x00_set_field32(&word, TXD_W0_DATABYTE_COUNT, txdesc->length);
	rt2x00_set_field32(&word, TXD_W0_CIPHER_ALG, CIPHER_NONE);
	rt2x00_desc_write(txd, 0, word);

	/*
	 * Register descriptor details in skb frame descriptor.
	 */
	skbdesc->desc = txd;
	skbdesc->desc_len = TXD_DESC_SIZE;
}

__attribute__((used)) static void rt2500pci_write_beacon(struct queue_entry *entry,
				   struct txentry_desc *txdesc)
{
	struct rt2x00_dev *rt2x00dev = entry->queue->rt2x00dev;
	u32 reg;

	/*
	 * Disable beaconing while we are reloading the beacon data,
	 * otherwise we might be sending out invalid data.
	 */
	reg = rt2x00mmio_register_read(rt2x00dev, CSR14);
	rt2x00_set_field32(&reg, CSR14_BEACON_GEN, 0);
	rt2x00mmio_register_write(rt2x00dev, CSR14, reg);

	if (rt2x00queue_map_txskb(entry)) {
		rt2x00_err(rt2x00dev, "Fail to map beacon, aborting\n");
		goto out;
	}

	/*
	 * Write the TX descriptor for the beacon.
	 */
	rt2500pci_write_tx_desc(entry, txdesc);

	/*
	 * Dump beacon to userspace through debugfs.
	 */
	rt2x00debug_dump_frame(rt2x00dev, DUMP_FRAME_BEACON, entry);
out:
	/*
	 * Enable beaconing again.
	 */
	rt2x00_set_field32(&reg, CSR14_BEACON_GEN, 1);
	rt2x00mmio_register_write(rt2x00dev, CSR14, reg);
}

__attribute__((used)) static void rt2500pci_fill_rxdone(struct queue_entry *entry,
				  struct rxdone_entry_desc *rxdesc)
{
	struct queue_entry_priv_mmio *entry_priv = entry->priv_data;
	u32 word0;
	u32 word2;

	word0 = rt2x00_desc_read(entry_priv->desc, 0);
	word2 = rt2x00_desc_read(entry_priv->desc, 2);

	if (rt2x00_get_field32(word0, RXD_W0_CRC_ERROR))
		rxdesc->flags |= RX_FLAG_FAILED_FCS_CRC;
	if (rt2x00_get_field32(word0, RXD_W0_PHYSICAL_ERROR))
		rxdesc->flags |= RX_FLAG_FAILED_PLCP_CRC;

	/*
	 * Obtain the status about this packet.
	 * When frame was received with an OFDM bitrate,
	 * the signal is the PLCP value. If it was received with
	 * a CCK bitrate the signal is the rate in 100kbit/s.
	 */
	rxdesc->signal = rt2x00_get_field32(word2, RXD_W2_SIGNAL);
	rxdesc->rssi = rt2x00_get_field32(word2, RXD_W2_RSSI) -
	    entry->queue->rt2x00dev->rssi_offset;
	rxdesc->size = rt2x00_get_field32(word0, RXD_W0_DATABYTE_COUNT);

	if (rt2x00_get_field32(word0, RXD_W0_OFDM))
		rxdesc->dev_flags |= RXDONE_SIGNAL_PLCP;
	else
		rxdesc->dev_flags |= RXDONE_SIGNAL_BITRATE;
	if (rt2x00_get_field32(word0, RXD_W0_MY_BSS))
		rxdesc->dev_flags |= RXDONE_MY_BSS;
}

__attribute__((used)) static void rt2500pci_txdone(struct rt2x00_dev *rt2x00dev,
			     const enum data_queue_qid queue_idx)
{
	struct data_queue *queue = rt2x00queue_get_tx_queue(rt2x00dev, queue_idx);
	struct queue_entry_priv_mmio *entry_priv;
	struct queue_entry *entry;
	struct txdone_entry_desc txdesc;
	u32 word;

	while (!rt2x00queue_empty(queue)) {
		entry = rt2x00queue_get_entry(queue, Q_INDEX_DONE);
		entry_priv = entry->priv_data;
		word = rt2x00_desc_read(entry_priv->desc, 0);

		if (rt2x00_get_field32(word, TXD_W0_OWNER_NIC) ||
		    !rt2x00_get_field32(word, TXD_W0_VALID))
			break;

		/*
		 * Obtain the status about this packet.
		 */
		txdesc.flags = 0;
		switch (rt2x00_get_field32(word, TXD_W0_RESULT)) {
		case 0: /* Success */
		case 1: /* Success with retry */
			__set_bit(TXDONE_SUCCESS, &txdesc.flags);
			break;
		case 2: /* Failure, excessive retries */
			__set_bit(TXDONE_EXCESSIVE_RETRY, &txdesc.flags);
			/* Don't break, this is a failed frame! */
		default: /* Failure */
			__set_bit(TXDONE_FAILURE, &txdesc.flags);
		}
		txdesc.retry = rt2x00_get_field32(word, TXD_W0_RETRY_COUNT);

		rt2x00lib_txdone(entry, &txdesc);
	}
}

__attribute__((used)) static inline void rt2500pci_enable_interrupt(struct rt2x00_dev *rt2x00dev,
					      struct rt2x00_field32 irq_field)
{
	u32 reg;

	/*
	 * Enable a single interrupt. The interrupt mask register
	 * access needs locking.
	 */
	spin_lock_irq(&rt2x00dev->irqmask_lock);

	reg = rt2x00mmio_register_read(rt2x00dev, CSR8);
	rt2x00_set_field32(&reg, irq_field, 0);
	rt2x00mmio_register_write(rt2x00dev, CSR8, reg);

	spin_unlock_irq(&rt2x00dev->irqmask_lock);
}

__attribute__((used)) static void rt2500pci_txstatus_tasklet(unsigned long data)
{
	struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
	u32 reg;

	/*
	 * Handle all tx queues.
	 */
	rt2500pci_txdone(rt2x00dev, QID_ATIM);
	rt2500pci_txdone(rt2x00dev, QID_AC_VO);
	rt2500pci_txdone(rt2x00dev, QID_AC_VI);

	/*
	 * Enable all TXDONE interrupts again.
	 */
	if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags)) {
		spin_lock_irq(&rt2x00dev->irqmask_lock);

		reg = rt2x00mmio_register_read(rt2x00dev, CSR8);
		rt2x00_set_field32(&reg, CSR8_TXDONE_TXRING, 0);
		rt2x00_set_field32(&reg, CSR8_TXDONE_ATIMRING, 0);
		rt2x00_set_field32(&reg, CSR8_TXDONE_PRIORING, 0);
		rt2x00mmio_register_write(rt2x00dev, CSR8, reg);

		spin_unlock_irq(&rt2x00dev->irqmask_lock);
	}
}

__attribute__((used)) static void rt2500pci_tbtt_tasklet(unsigned long data)
{
	struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
	rt2x00lib_beacondone(rt2x00dev);
	if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
		rt2500pci_enable_interrupt(rt2x00dev, CSR8_TBCN_EXPIRE);
}

__attribute__((used)) static void rt2500pci_rxdone_tasklet(unsigned long data)
{
	struct rt2x00_dev *rt2x00dev = (struct rt2x00_dev *)data;
	if (rt2x00mmio_rxdone(rt2x00dev))
		tasklet_schedule(&rt2x00dev->rxdone_tasklet);
	else if (test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
		rt2500pci_enable_interrupt(rt2x00dev, CSR8_RXDONE);
}

__attribute__((used)) static irqreturn_t rt2500pci_interrupt(int irq, void *dev_instance)
{
	struct rt2x00_dev *rt2x00dev = dev_instance;
	u32 reg, mask;

	/*
	 * Get the interrupt sources & saved to local variable.
	 * Write register value back to clear pending interrupts.
	 */
	reg = rt2x00mmio_register_read(rt2x00dev, CSR7);
	rt2x00mmio_register_write(rt2x00dev, CSR7, reg);

	if (!reg)
		return IRQ_NONE;

	if (!test_bit(DEVICE_STATE_ENABLED_RADIO, &rt2x00dev->flags))
		return IRQ_HANDLED;

	mask = reg;

	/*
	 * Schedule tasklets for interrupt handling.
	 */
	if (rt2x00_get_field32(reg, CSR7_TBCN_EXPIRE))
		tasklet_hi_schedule(&rt2x00dev->tbtt_tasklet);

	if (rt2x00_get_field32(reg, CSR7_RXDONE))
		tasklet_schedule(&rt2x00dev->rxdone_tasklet);

	if (rt2x00_get_field32(reg, CSR7_TXDONE_ATIMRING) ||
	    rt2x00_get_field32(reg, CSR7_TXDONE_PRIORING) ||
	    rt2x00_get_field32(reg, CSR7_TXDONE_TXRING)) {
		tasklet_schedule(&rt2x00dev->txstatus_tasklet);
		/*
		 * Mask out all txdone interrupts.
		 */
		rt2x00_set_field32(&mask, CSR8_TXDONE_TXRING, 1);
		rt2x00_set_field32(&mask, CSR8_TXDONE_ATIMRING, 1);
		rt2x00_set_field32(&mask, CSR8_TXDONE_PRIORING, 1);
	}

	/*
	 * Disable all interrupts for which a tasklet was scheduled right now,
	 * the tasklet will reenable the appropriate interrupts.
	 */
	spin_lock(&rt2x00dev->irqmask_lock);

	reg = rt2x00mmio_register_read(rt2x00dev, CSR8);
	reg |= mask;
	rt2x00mmio_register_write(rt2x00dev, CSR8, reg);

	spin_unlock(&rt2x00dev->irqmask_lock);

	return IRQ_HANDLED;
}

__attribute__((used)) static int rt2500pci_validate_eeprom(struct rt2x00_dev *rt2x00dev)
{
	struct eeprom_93cx6 eeprom;
	u32 reg;
	u16 word;
	u8 *mac;

	reg = rt2x00mmio_register_read(rt2x00dev, CSR21);

	eeprom.data = rt2x00dev;
	eeprom.register_read = rt2500pci_eepromregister_read;
	eeprom.register_write = rt2500pci_eepromregister_write;
	eeprom.width = rt2x00_get_field32(reg, CSR21_TYPE_93C46) ?
	    PCI_EEPROM_WIDTH_93C46 : PCI_EEPROM_WIDTH_93C66;
	eeprom.reg_data_in = 0;
	eeprom.reg_data_out = 0;
	eeprom.reg_data_clock = 0;
	eeprom.reg_chip_select = 0;

	eeprom_93cx6_multiread(&eeprom, EEPROM_BASE, rt2x00dev->eeprom,
			       EEPROM_SIZE / sizeof(u16));

	/*
	 * Start validation of the data that has been read.
	 */
	mac = rt2x00_eeprom_addr(rt2x00dev, EEPROM_MAC_ADDR_0);
	rt2x00lib_set_mac_address(rt2x00dev, mac);

	word = rt2x00_eeprom_read(rt2x00dev, EEPROM_ANTENNA);
	if (word == 0xffff) {
		rt2x00_set_field16(&word, EEPROM_ANTENNA_NUM, 2);
		rt2x00_set_field16(&word, EEPROM_ANTENNA_TX_DEFAULT,
				   ANTENNA_SW_DIVERSITY);
		rt2x00_set_field16(&word, EEPROM_ANTENNA_RX_DEFAULT,
				   ANTENNA_SW_DIVERSITY);
		rt2x00_set_field16(&word, EEPROM_ANTENNA_LED_MODE,
				   LED_MODE_DEFAULT);
		rt2x00_set_field16(&word, EEPROM_ANTENNA_DYN_TXAGC, 0);
		rt2x00_set_field16(&word, EEPROM_ANTENNA_HARDWARE_RADIO, 0);
		rt2x00_set_field16(&word, EEPROM_ANTENNA_RF_TYPE, RF2522);
		rt2x00_eeprom_write(rt2x00dev, EEPROM_ANTENNA, word);
		rt2x00_eeprom_dbg(rt2x00dev, "Antenna: 0x%04x\n", word);
	}

	word = rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC);
	if (word == 0xffff) {
		rt2x00_set_field16(&word, EEPROM_NIC_CARDBUS_ACCEL, 0);
		rt2x00_set_field16(&word, EEPROM_NIC_DYN_BBP_TUNE, 0);
		rt2x00_set_field16(&word, EEPROM_NIC_CCK_TX_POWER, 0);
		rt2x00_eeprom_write(rt2x00dev, EEPROM_NIC, word);
		rt2x00_eeprom_dbg(rt2x00dev, "NIC: 0x%04x\n", word);
	}

	word = rt2x00_eeprom_read(rt2x00dev, EEPROM_CALIBRATE_OFFSET);
	if (word == 0xffff) {
		rt2x00_set_field16(&word, EEPROM_CALIBRATE_OFFSET_RSSI,
				   DEFAULT_RSSI_OFFSET);
		rt2x00_eeprom_write(rt2x00dev, EEPROM_CALIBRATE_OFFSET, word);
		rt2x00_eeprom_dbg(rt2x00dev, "Calibrate offset: 0x%04x\n",
				  word);
	}

	return 0;
}

__attribute__((used)) static int rt2500pci_init_eeprom(struct rt2x00_dev *rt2x00dev)
{
	u32 reg;
	u16 value;
	u16 eeprom;

	/*
	 * Read EEPROM word for configuration.
	 */
	eeprom = rt2x00_eeprom_read(rt2x00dev, EEPROM_ANTENNA);

	/*
	 * Identify RF chipset.
	 */
	value = rt2x00_get_field16(eeprom, EEPROM_ANTENNA_RF_TYPE);
	reg = rt2x00mmio_register_read(rt2x00dev, CSR0);
	rt2x00_set_chip(rt2x00dev, RT2560, value,
			rt2x00_get_field32(reg, CSR0_REVISION));

	if (!rt2x00_rf(rt2x00dev, RF2522) &&
	    !rt2x00_rf(rt2x00dev, RF2523) &&
	    !rt2x00_rf(rt2x00dev, RF2524) &&
	    !rt2x00_rf(rt2x00dev, RF2525) &&
	    !rt2x00_rf(rt2x00dev, RF2525E) &&
	    !rt2x00_rf(rt2x00dev, RF5222)) {
		rt2x00_err(rt2x00dev, "Invalid RF chipset detected\n");
		return -ENODEV;
	}

	/*
	 * Identify default antenna configuration.
	 */
	rt2x00dev->default_ant.tx =
	    rt2x00_get_field16(eeprom, EEPROM_ANTENNA_TX_DEFAULT);
	rt2x00dev->default_ant.rx =
	    rt2x00_get_field16(eeprom, EEPROM_ANTENNA_RX_DEFAULT);

	/*
	 * Store led mode, for correct led behaviour.
	 */
#ifdef CONFIG_RT2X00_LIB_LEDS
	value = rt2x00_get_field16(eeprom, EEPROM_ANTENNA_LED_MODE);

	rt2500pci_init_led(rt2x00dev, &rt2x00dev->led_radio, LED_TYPE_RADIO);
	if (value == LED_MODE_TXRX_ACTIVITY ||
	    value == LED_MODE_DEFAULT ||
	    value == LED_MODE_ASUS)
		rt2500pci_init_led(rt2x00dev, &rt2x00dev->led_qual,
				   LED_TYPE_ACTIVITY);
#endif /* CONFIG_RT2X00_LIB_LEDS */

	/*
	 * Detect if this device has an hardware controlled radio.
	 */
	if (rt2x00_get_field16(eeprom, EEPROM_ANTENNA_HARDWARE_RADIO)) {
		__set_bit(CAPABILITY_HW_BUTTON, &rt2x00dev->cap_flags);
		/*
		 * On this device RFKILL initialized during probe does not work.
		 */
		__set_bit(REQUIRE_DELAYED_RFKILL, &rt2x00dev->cap_flags);
	}

	/*
	 * Check if the BBP tuning should be enabled.
	 */
	eeprom = rt2x00_eeprom_read(rt2x00dev, EEPROM_NIC);
	if (!rt2x00_get_field16(eeprom, EEPROM_NIC_DYN_BBP_TUNE))
		__set_bit(CAPABILITY_LINK_TUNING, &rt2x00dev->cap_flags);

	/*
	 * Read the RSSI <-> dBm offset information.
	 */
	eeprom = rt2x00_eeprom_read(rt2x00dev, EEPROM_CALIBRATE_OFFSET);
	rt2x00dev->rssi_offset =
	    rt2x00_get_field16(eeprom, EEPROM_CALIBRATE_OFFSET_RSSI);

	return 0;
}

__attribute__((used)) static int rt2500pci_probe_hw_mode(struct rt2x00_dev *rt2x00dev)
{
	struct hw_mode_spec *spec = &rt2x00dev->spec;
	struct channel_info *info;
	char *tx_power;
	unsigned int i;

	/*
	 * Initialize all hw fields.
	 */
	ieee80211_hw_set(rt2x00dev->hw, PS_NULLFUNC_STACK);
	ieee80211_hw_set(rt2x00dev->hw, SUPPORTS_PS);
	ieee80211_hw_set(rt2x00dev->hw, HOST_BROADCAST_PS_BUFFERING);
	ieee80211_hw_set(rt2x00dev->hw, SIGNAL_DBM);

	SET_IEEE80211_DEV(rt2x00dev->hw, rt2x00dev->dev);
	SET_IEEE80211_PERM_ADDR(rt2x00dev->hw,
				rt2x00_eeprom_addr(rt2x00dev,
						   EEPROM_MAC_ADDR_0));

	/*
	 * Disable powersaving as default.
	 */
	rt2x00dev->hw->wiphy->flags &= ~WIPHY_FLAG_PS_ON_BY_DEFAULT;

	/*
	 * Initialize hw_mode information.
	 */
	spec->supported_bands = SUPPORT_BAND_2GHZ;
	spec->supported_rates = SUPPORT_RATE_CCK | SUPPORT_RATE_OFDM;

	if (rt2x00_rf(rt2x00dev, RF2522)) {
		spec->num_channels = ARRAY_SIZE(rf_vals_bg_2522);
		spec->channels = rf_vals_bg_2522;
	} else if (rt2x00_rf(rt2x00dev, RF2523)) {
		spec->num_channels = ARRAY_SIZE(rf_vals_bg_2523);
		spec->channels = rf_vals_bg_2523;
	} else if (rt2x00_rf(rt2x00dev, RF2524)) {
		spec->num_channels = ARRAY_SIZE(rf_vals_bg_2524);
		spec->channels = rf_vals_bg_2524;
	} else if (rt2x00_rf(rt2x00dev, RF2525)) {
		spec->num_channels = ARRAY_SIZE(rf_vals_bg_2525);
		spec->channels = rf_vals_bg_2525;
	} else if (rt2x00_rf(rt2x00dev, RF2525E)) {
		spec->num_channels = ARRAY_SIZE(rf_vals_bg_2525e);
		spec->channels = rf_vals_bg_2525e;
	} else if (rt2x00_rf(rt2x00dev, RF5222)) {
		spec->supported_bands |= SUPPORT_BAND_5GHZ;
		spec->num_channels = ARRAY_SIZE(rf_vals_5222);
		spec->channels = rf_vals_5222;
	}

	/*
	 * Create channel information array
	 */
	info = kcalloc(spec->num_channels, sizeof(*info), GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	spec->channels_info = info;

	tx_power = rt2x00_eeprom_addr(rt2x00dev, EEPROM_TXPOWER_START);
	for (i = 0; i < 14; i++) {
		info[i].max_power = MAX_TXPOWER;
		info[i].default_power1 = TXPOWER_FROM_DEV(tx_power[i]);
	}

	if (spec->num_channels > 14) {
		for (i = 14; i < spec->num_channels; i++) {
			info[i].max_power = MAX_TXPOWER;
			info[i].default_power1 = DEFAULT_TXPOWER;
		}
	}

	return 0;
}

__attribute__((used)) static int rt2500pci_probe_hw(struct rt2x00_dev *rt2x00dev)
{
	int retval;
	u32 reg;

	/*
	 * Allocate eeprom data.
	 */
	retval = rt2500pci_validate_eeprom(rt2x00dev);
	if (retval)
		return retval;

	retval = rt2500pci_init_eeprom(rt2x00dev);
	if (retval)
		return retval;

	/*
	 * Enable rfkill polling by setting GPIO direction of the
	 * rfkill switch GPIO pin correctly.
	 */
	reg = rt2x00mmio_register_read(rt2x00dev, GPIOCSR);
	rt2x00_set_field32(&reg, GPIOCSR_DIR0, 1);
	rt2x00mmio_register_write(rt2x00dev, GPIOCSR, reg);

	/*
	 * Initialize hw specifications.
	 */
	retval = rt2500pci_probe_hw_mode(rt2x00dev);
	if (retval)
		return retval;

	/*
	 * This device requires the atim queue and DMA-mapped skbs.
	 */
	__set_bit(REQUIRE_ATIM_QUEUE, &rt2x00dev->cap_flags);
	__set_bit(REQUIRE_DMA, &rt2x00dev->cap_flags);
	__set_bit(REQUIRE_SW_SEQNO, &rt2x00dev->cap_flags);

	/*
	 * Set the rssi offset.
	 */
	rt2x00dev->rssi_offset = DEFAULT_RSSI_OFFSET;

	return 0;
}

__attribute__((used)) static u64 rt2500pci_get_tsf(struct ieee80211_hw *hw,
			     struct ieee80211_vif *vif)
{
	struct rt2x00_dev *rt2x00dev = hw->priv;
	u64 tsf;
	u32 reg;

	reg = rt2x00mmio_register_read(rt2x00dev, CSR17);
	tsf = (u64) rt2x00_get_field32(reg, CSR17_HIGH_TSFTIMER) << 32;
	reg = rt2x00mmio_register_read(rt2x00dev, CSR16);
	tsf |= rt2x00_get_field32(reg, CSR16_LOW_TSFTIMER);

	return tsf;
}

__attribute__((used)) static int rt2500pci_tx_last_beacon(struct ieee80211_hw *hw)
{
	struct rt2x00_dev *rt2x00dev = hw->priv;
	u32 reg;

	reg = rt2x00mmio_register_read(rt2x00dev, CSR15);
	return rt2x00_get_field32(reg, CSR15_BEACON_SENT);
}

__attribute__((used)) static void rt2500pci_queue_init(struct data_queue *queue)
{
	switch (queue->qid) {
	case QID_RX:
		queue->limit = 32;
		queue->data_size = DATA_FRAME_SIZE;
		queue->desc_size = RXD_DESC_SIZE;
		queue->priv_size = sizeof(struct queue_entry_priv_mmio);
		break;

	case QID_AC_VO:
	case QID_AC_VI:
	case QID_AC_BE:
	case QID_AC_BK:
		queue->limit = 32;
		queue->data_size = DATA_FRAME_SIZE;
		queue->desc_size = TXD_DESC_SIZE;
		queue->priv_size = sizeof(struct queue_entry_priv_mmio);
		break;

	case QID_BEACON:
		queue->limit = 1;
		queue->data_size = MGMT_FRAME_SIZE;
		queue->desc_size = TXD_DESC_SIZE;
		queue->priv_size = sizeof(struct queue_entry_priv_mmio);
		break;

	case QID_ATIM:
		queue->limit = 8;
		queue->data_size = DATA_FRAME_SIZE;
		queue->desc_size = TXD_DESC_SIZE;
		queue->priv_size = sizeof(struct queue_entry_priv_mmio);
		break;

	default:
		BUG();
		break;
	}
}

__attribute__((used)) static int rt2500pci_probe(struct pci_dev *pci_dev,
			   const struct pci_device_id *id)
{
	return rt2x00pci_probe(pci_dev, &rt2500pci_ops);
}

