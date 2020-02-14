#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_47__   TYPE_9__ ;
typedef  struct TYPE_46__   TYPE_8__ ;
typedef  struct TYPE_45__   TYPE_7__ ;
typedef  struct TYPE_44__   TYPE_6__ ;
typedef  struct TYPE_43__   TYPE_5__ ;
typedef  struct TYPE_42__   TYPE_4__ ;
typedef  struct TYPE_41__   TYPE_3__ ;
typedef  struct TYPE_40__   TYPE_2__ ;
typedef  struct TYPE_39__   TYPE_1__ ;
typedef  struct TYPE_38__   TYPE_18__ ;
typedef  struct TYPE_37__   TYPE_17__ ;
typedef  struct TYPE_36__   TYPE_16__ ;
typedef  struct TYPE_35__   TYPE_15__ ;
typedef  struct TYPE_34__   TYPE_14__ ;
typedef  struct TYPE_33__   TYPE_13__ ;
typedef  struct TYPE_32__   TYPE_12__ ;
typedef  struct TYPE_31__   TYPE_11__ ;
typedef  struct TYPE_30__   TYPE_10__ ;

/* Type definitions */
struct TYPE_34__ {int en; } ;
union cvmx_smix_en {int u64; TYPE_14__ s; } ;
struct TYPE_47__ {int size1; int size2; int size3; int size4; int size5; int size6; int size7; } ;
union cvmx_pko_reg_min_pkt {int u64; TYPE_9__ s; } ;
struct TYPE_45__ {scalar_t__ grp; void* non_tag_type; void* ip4_tag_type; void* ip6_tag_type; void* tcp4_tag_type; void* tcp6_tag_type; int /*<<< orphan*/  inc_prt_flag; int /*<<< orphan*/  ip4_pctl_flag; int /*<<< orphan*/  ip4_dprt_flag; int /*<<< orphan*/  ip4_sprt_flag; int /*<<< orphan*/  ip4_dst_flag; int /*<<< orphan*/  ip4_src_flag; int /*<<< orphan*/  ip6_nxth_flag; int /*<<< orphan*/  ip6_dprt_flag; int /*<<< orphan*/  ip6_sprt_flag; int /*<<< orphan*/  ip6_dst_flag; int /*<<< orphan*/  ip6_src_flag; } ;
union cvmx_pip_prt_tagx {TYPE_7__ s; void* u64; } ;
struct TYPE_44__ {int qos; int /*<<< orphan*/  mode; } ;
union cvmx_pip_prt_cfgx {TYPE_6__ s; void* u64; } ;
struct TYPE_39__ {int qlm_spd; int qlm_cfg; } ;
union cvmx_mio_qlmx_cfg {TYPE_1__ s; void* u64; } ;
struct TYPE_33__ {scalar_t__ rfb_arb_mode; scalar_t__ lrf_arb_mode; } ;
union cvmx_l2c_cfg {int u64; TYPE_13__ s; } ;
struct TYPE_46__ {int tout_val; scalar_t__ tout_enb; } ;
union cvmx_iob_fau_timeout {int u64; TYPE_8__ s; } ;
struct TYPE_32__ {int en; } ;
union cvmx_gmxx_prtx_cfg {int u64; TYPE_12__ s; } ;
struct TYPE_43__ {scalar_t__ type; int /*<<< orphan*/  en; } ;
struct TYPE_42__ {int mode; } ;
struct TYPE_41__ {int /*<<< orphan*/  mode; } ;
struct TYPE_40__ {int mode; } ;
union cvmx_gmxx_inf_mode {TYPE_5__ s; TYPE_4__ cn56xx; void* u64; TYPE_3__ cn68xx; TYPE_2__ cn63xx; } ;
struct TYPE_30__ {scalar_t__ addr; int size; int i; void* pool; } ;
union cvmx_buf_ptr {int u64; TYPE_10__ s; } ;
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  cvmx_wqe_t ;
struct TYPE_31__ {int segs; int total_bytes; int gather; scalar_t__ dontfree; } ;
struct TYPE_36__ {TYPE_11__ s; scalar_t__ u64; } ;
typedef  TYPE_16__ cvmx_pko_command_word0_t ;
struct TYPE_35__ {int full_duplex; int link_up; int speed; } ;
struct TYPE_37__ {TYPE_15__ s; scalar_t__ u64; } ;
typedef  TYPE_17__ cvmx_helper_link_info_t ;
typedef  int cvmx_helper_interface_mode_t ;
struct TYPE_38__ {scalar_t__ board_type; int board_rev_major; } ;

/* Variables and functions */
 int /*<<< orphan*/  CVMX_ASXX_PRT_LOOP (int) ; 
 int /*<<< orphan*/  CVMX_ASXX_RX_PRT_EN (int) ; 
 int /*<<< orphan*/  CVMX_ASXX_TX_PRT_EN (int) ; 
 scalar_t__ CVMX_BOARD_TYPE_CN3005_EVB_HS5 ; 
 scalar_t__ CVMX_BOARD_TYPE_SIM ; 
 void* CVMX_FPA_PACKET_POOL ; 
 int CVMX_FPA_PACKET_POOL_SIZE ; 
 void* CVMX_FPA_WQE_POOL ; 
 int /*<<< orphan*/  CVMX_GMXX_INF_MODE (int) ; 
 int /*<<< orphan*/  CVMX_GMXX_PRTX_CFG (int,int) ; 
 int /*<<< orphan*/  CVMX_GMXX_RXX_FRM_MAX (int,int) ; 
 int /*<<< orphan*/  CVMX_GMXX_RXX_JABBER (int,int) ; 
 int /*<<< orphan*/  CVMX_HELPER_ENABLE_BACK_PRESSURE ; 
 int CVMX_HELPER_FIRST_MBUFF_SKIP ; 
 int /*<<< orphan*/  CVMX_HELPER_INPUT_PORT_SKIP_MODE ; 
 int /*<<< orphan*/  CVMX_HELPER_INPUT_TAG_INPUT_PORT ; 
 int /*<<< orphan*/  CVMX_HELPER_INPUT_TAG_IPV4_DST_IP ; 
 int /*<<< orphan*/  CVMX_HELPER_INPUT_TAG_IPV4_DST_PORT ; 
 int /*<<< orphan*/  CVMX_HELPER_INPUT_TAG_IPV4_PROTOCOL ; 
 int /*<<< orphan*/  CVMX_HELPER_INPUT_TAG_IPV4_SRC_IP ; 
 int /*<<< orphan*/  CVMX_HELPER_INPUT_TAG_IPV4_SRC_PORT ; 
 int /*<<< orphan*/  CVMX_HELPER_INPUT_TAG_IPV6_DST_IP ; 
 int /*<<< orphan*/  CVMX_HELPER_INPUT_TAG_IPV6_DST_PORT ; 
 int /*<<< orphan*/  CVMX_HELPER_INPUT_TAG_IPV6_NEXT_HEADER ; 
 int /*<<< orphan*/  CVMX_HELPER_INPUT_TAG_IPV6_SRC_IP ; 
 int /*<<< orphan*/  CVMX_HELPER_INPUT_TAG_IPV6_SRC_PORT ; 
 void* CVMX_HELPER_INPUT_TAG_TYPE ; 
#define  CVMX_HELPER_INTERFACE_MODE_DISABLED 137 
#define  CVMX_HELPER_INTERFACE_MODE_GMII 136 
#define  CVMX_HELPER_INTERFACE_MODE_LOOP 135 
#define  CVMX_HELPER_INTERFACE_MODE_NPI 134 
#define  CVMX_HELPER_INTERFACE_MODE_PCIE 133 
#define  CVMX_HELPER_INTERFACE_MODE_PICMG 132 
#define  CVMX_HELPER_INTERFACE_MODE_RGMII 131 
#define  CVMX_HELPER_INTERFACE_MODE_SGMII 130 
#define  CVMX_HELPER_INTERFACE_MODE_SPI 129 
#define  CVMX_HELPER_INTERFACE_MODE_XAUI 128 
 int CVMX_HELPER_NOT_FIRST_MBUFF_SKIP ; 
 int /*<<< orphan*/  CVMX_IOB_FAU_TIMEOUT ; 
 int /*<<< orphan*/  CVMX_IPD_OPC_MODE_STT ; 
 int /*<<< orphan*/  CVMX_IPD_PTR_COUNT ; 
 int /*<<< orphan*/  CVMX_L2C_CFG ; 
 int /*<<< orphan*/  CVMX_MIO_QLMX_CFG (int) ; 
 int /*<<< orphan*/  CVMX_PIP_PRT_CFGX (int) ; 
 int /*<<< orphan*/  CVMX_PIP_PRT_TAGX (int) ; 
 int /*<<< orphan*/  CVMX_PKO_LOCK_CMD_QUEUE ; 
 int /*<<< orphan*/  CVMX_PKO_REG_MIN_PKT ; 
 int /*<<< orphan*/  CVMX_POW_WAIT ; 
 int /*<<< orphan*/  CVMX_SMIX_EN (int) ; 
 int /*<<< orphan*/  CVMX_SYNC ; 
 int /*<<< orphan*/  CVMX_SYNCWS ; 
 int /*<<< orphan*/  OCTEON_CN30XX ; 
 int /*<<< orphan*/  OCTEON_CN30XX_PASS1 ; 
 int /*<<< orphan*/  OCTEON_CN31XX ; 
 int /*<<< orphan*/  OCTEON_CN31XX_PASS1 ; 
 int /*<<< orphan*/  OCTEON_CN38XX ; 
 int /*<<< orphan*/  OCTEON_CN3XXX ; 
 int /*<<< orphan*/  OCTEON_CN50XX ; 
 int /*<<< orphan*/  OCTEON_CN52XX ; 
 int /*<<< orphan*/  OCTEON_CN52XX_PASS1_0 ; 
 int /*<<< orphan*/  OCTEON_CN56XX ; 
 int /*<<< orphan*/  OCTEON_CN58XX ; 
 int /*<<< orphan*/  OCTEON_CN61XX ; 
 int /*<<< orphan*/  OCTEON_CN63XX ; 
 int /*<<< orphan*/  OCTEON_CN66XX ; 
 int /*<<< orphan*/  OCTEON_CN68XX ; 
 int /*<<< orphan*/  OCTEON_CN6XXX ; 
 int /*<<< orphan*/  OCTEON_CN7XXX ; 
 int /*<<< orphan*/  OCTEON_CNF71XX ; 
 scalar_t__ OCTEON_IS_MODEL (int /*<<< orphan*/ ) ; 
 int __cvmx_helper_board_hardware_enable (int) ; 
 int __cvmx_helper_board_interface_probe (int,int) ; 
 int /*<<< orphan*/  __cvmx_helper_errata_qlm_disable_2nd_order_cdr (int) ; 
 int __cvmx_helper_loop_enable (int) ; 
 int __cvmx_helper_loop_enumerate (int) ; 
 int /*<<< orphan*/  __cvmx_helper_loop_probe (int) ; 
 int __cvmx_helper_npi_enable (int) ; 
 int __cvmx_helper_npi_enumerate (int) ; 
 int /*<<< orphan*/  __cvmx_helper_npi_probe (int) ; 
 int __cvmx_helper_rgmii_configure_loopback (int,int,int) ; 
 int __cvmx_helper_rgmii_enable (int) ; 
 int __cvmx_helper_rgmii_enumerate (int) ; 
 TYPE_17__ __cvmx_helper_rgmii_link_get (int) ; 
 int __cvmx_helper_rgmii_link_set (int,TYPE_17__) ; 
 int /*<<< orphan*/  __cvmx_helper_rgmii_probe (int) ; 
 int __cvmx_helper_sgmii_configure_loopback (int,int,int) ; 
 int __cvmx_helper_sgmii_enable (int) ; 
 int __cvmx_helper_sgmii_enumerate (int) ; 
 TYPE_17__ __cvmx_helper_sgmii_link_get (int) ; 
 int __cvmx_helper_sgmii_link_set (int,TYPE_17__) ; 
 int /*<<< orphan*/  __cvmx_helper_sgmii_probe (int) ; 
 int __cvmx_helper_spi_enable (int) ; 
 int __cvmx_helper_spi_enumerate (int) ; 
 TYPE_17__ __cvmx_helper_spi_link_get (int) ; 
 int __cvmx_helper_spi_link_set (int,TYPE_17__) ; 
 int /*<<< orphan*/  __cvmx_helper_spi_probe (int) ; 
 int __cvmx_helper_xaui_configure_loopback (int,int,int) ; 
 int __cvmx_helper_xaui_enable (int) ; 
 int __cvmx_helper_xaui_enumerate (int) ; 
 TYPE_17__ __cvmx_helper_xaui_link_get (int) ; 
 int __cvmx_helper_xaui_link_set (int,TYPE_17__) ; 
 int /*<<< orphan*/  __cvmx_helper_xaui_probe (int) ; 
 int /*<<< orphan*/  __delay (unsigned long long) ; 
 int /*<<< orphan*/  cvmx_dprintf (char*,...) ; 
 int /*<<< orphan*/  cvmx_fpa_alloc (void*) ; 
 int /*<<< orphan*/  cvmx_helper_free_packet_data (int /*<<< orphan*/ *) ; 
 int cvmx_helper_get_interface_index_num (int) ; 
 int cvmx_helper_get_interface_num (int) ; 
 int cvmx_helper_get_ipd_port (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cvmx_helper_interface_mode_to_string (int) ; 
 int /*<<< orphan*/  cvmx_helper_rgmii_internal_loopback (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cvmx_ipd_config (int,int,int,int,int,void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cvmx_ipd_enable () ; 
 int /*<<< orphan*/  cvmx_override_ipd_port_setup (int) ; 
 int /*<<< orphan*/  cvmx_override_pko_queue_priority (int,int*) ; 
 scalar_t__ cvmx_phys_to_ptr (scalar_t__) ; 
 int /*<<< orphan*/  cvmx_pip_config_port (int,union cvmx_pip_prt_cfgx,union cvmx_pip_prt_tagx) ; 
 int /*<<< orphan*/  cvmx_pko_config_port (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  cvmx_pko_enable () ; 
 int /*<<< orphan*/  cvmx_pko_get_base_queue (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cvmx_pko_get_base_queue_per_core (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cvmx_pko_get_num_queues (int) ; 
 int /*<<< orphan*/  cvmx_pko_initialize_global () ; 
 int cvmx_pko_initialize_local () ; 
 int /*<<< orphan*/  cvmx_pko_send_packet_finish (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_16__,union cvmx_buf_ptr,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cvmx_pko_send_packet_prepare (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * cvmx_pow_work_request_sync (int /*<<< orphan*/ ) ; 
 void* cvmx_ptr_to_phys (int /*<<< orphan*/ ) ; 
 void* cvmx_read_csr (int /*<<< orphan*/ ) ; 
 TYPE_18__* cvmx_sysinfo_get () ; 
 int /*<<< orphan*/  cvmx_write_csr (int /*<<< orphan*/ ,int) ; 
 int* interface_port_count ; 

int cvmx_helper_get_number_of_interfaces(void)
{
	if (OCTEON_IS_MODEL(OCTEON_CN68XX))
		return 9;
	if (OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN52XX))
		return 4;
	if (OCTEON_IS_MODEL(OCTEON_CN7XXX))
		return 5;
	else
		return 3;
}

int cvmx_helper_ports_on_interface(int interface)
{
	return interface_port_count[interface];
}

__attribute__((used)) static cvmx_helper_interface_mode_t __cvmx_get_mode_cn68xx(int interface)
{
	union cvmx_mio_qlmx_cfg qlm_cfg;
	switch (interface) {
	case 0:
		qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(0));
		/* QLM is disabled when QLM SPD is 15. */
		if (qlm_cfg.s.qlm_spd == 15)
			return CVMX_HELPER_INTERFACE_MODE_DISABLED;

		if (qlm_cfg.s.qlm_cfg == 2)
			return CVMX_HELPER_INTERFACE_MODE_SGMII;
		else if (qlm_cfg.s.qlm_cfg == 3)
			return CVMX_HELPER_INTERFACE_MODE_XAUI;
		else
			return CVMX_HELPER_INTERFACE_MODE_DISABLED;
	case 2:
	case 3:
	case 4:
		qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(interface));
		/* QLM is disabled when QLM SPD is 15. */
		if (qlm_cfg.s.qlm_spd == 15)
			return CVMX_HELPER_INTERFACE_MODE_DISABLED;

		if (qlm_cfg.s.qlm_cfg == 2)
			return CVMX_HELPER_INTERFACE_MODE_SGMII;
		else if (qlm_cfg.s.qlm_cfg == 3)
			return CVMX_HELPER_INTERFACE_MODE_XAUI;
		else
			return CVMX_HELPER_INTERFACE_MODE_DISABLED;
	case 7:
		qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(3));
		/* QLM is disabled when QLM SPD is 15. */
		if (qlm_cfg.s.qlm_spd == 15) {
			return CVMX_HELPER_INTERFACE_MODE_DISABLED;
		} else if (qlm_cfg.s.qlm_cfg != 0) {
			qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(1));
			if (qlm_cfg.s.qlm_cfg != 0)
				return CVMX_HELPER_INTERFACE_MODE_DISABLED;
		}
		return CVMX_HELPER_INTERFACE_MODE_NPI;
	case 8:
		return CVMX_HELPER_INTERFACE_MODE_LOOP;
	default:
		return CVMX_HELPER_INTERFACE_MODE_DISABLED;
	}
}

__attribute__((used)) static cvmx_helper_interface_mode_t __cvmx_get_mode_octeon2(int interface)
{
	union cvmx_gmxx_inf_mode mode;

	if (OCTEON_IS_MODEL(OCTEON_CN68XX))
		return __cvmx_get_mode_cn68xx(interface);

	if (interface == 2)
		return CVMX_HELPER_INTERFACE_MODE_NPI;

	if (interface == 3)
		return CVMX_HELPER_INTERFACE_MODE_LOOP;

	/* Only present in CN63XX & CN66XX Octeon model */
	if ((OCTEON_IS_MODEL(OCTEON_CN63XX) &&
	     (interface == 4 || interface == 5)) ||
	    (OCTEON_IS_MODEL(OCTEON_CN66XX) &&
	     interface >= 4 && interface <= 7)) {
		return CVMX_HELPER_INTERFACE_MODE_DISABLED;
	}

	if (OCTEON_IS_MODEL(OCTEON_CN66XX)) {
		union cvmx_mio_qlmx_cfg mio_qlm_cfg;

		/* QLM2 is SGMII0 and QLM1 is SGMII1 */
		if (interface == 0)
			mio_qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(2));
		else if (interface == 1)
			mio_qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(1));
		else
			return CVMX_HELPER_INTERFACE_MODE_DISABLED;

		if (mio_qlm_cfg.s.qlm_spd == 15)
			return CVMX_HELPER_INTERFACE_MODE_DISABLED;

		if (mio_qlm_cfg.s.qlm_cfg == 9)
			return CVMX_HELPER_INTERFACE_MODE_SGMII;
		else if (mio_qlm_cfg.s.qlm_cfg == 11)
			return CVMX_HELPER_INTERFACE_MODE_XAUI;
		else
			return CVMX_HELPER_INTERFACE_MODE_DISABLED;
	} else if (OCTEON_IS_MODEL(OCTEON_CN61XX)) {
		union cvmx_mio_qlmx_cfg qlm_cfg;

		if (interface == 0) {
			qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(2));
			if (qlm_cfg.s.qlm_cfg == 2)
				return CVMX_HELPER_INTERFACE_MODE_SGMII;
			else if (qlm_cfg.s.qlm_cfg == 3)
				return CVMX_HELPER_INTERFACE_MODE_XAUI;
			else
				return CVMX_HELPER_INTERFACE_MODE_DISABLED;
		} else if (interface == 1) {
			qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(0));
			if (qlm_cfg.s.qlm_cfg == 2)
				return CVMX_HELPER_INTERFACE_MODE_SGMII;
			else if (qlm_cfg.s.qlm_cfg == 3)
				return CVMX_HELPER_INTERFACE_MODE_XAUI;
			else
				return CVMX_HELPER_INTERFACE_MODE_DISABLED;
		}
	} else if (OCTEON_IS_MODEL(OCTEON_CNF71XX)) {
		if (interface == 0) {
			union cvmx_mio_qlmx_cfg qlm_cfg;
			qlm_cfg.u64 = cvmx_read_csr(CVMX_MIO_QLMX_CFG(0));
			if (qlm_cfg.s.qlm_cfg == 2)
				return CVMX_HELPER_INTERFACE_MODE_SGMII;
		}
		return CVMX_HELPER_INTERFACE_MODE_DISABLED;
	}

	if (interface == 1 && OCTEON_IS_MODEL(OCTEON_CN63XX))
		return CVMX_HELPER_INTERFACE_MODE_DISABLED;

	mode.u64 = cvmx_read_csr(CVMX_GMXX_INF_MODE(interface));

	if (OCTEON_IS_MODEL(OCTEON_CN63XX)) {
		switch (mode.cn63xx.mode) {
		case 0:
			return CVMX_HELPER_INTERFACE_MODE_SGMII;
		case 1:
			return CVMX_HELPER_INTERFACE_MODE_XAUI;
		default:
			return CVMX_HELPER_INTERFACE_MODE_DISABLED;
		}
	} else {
		if (!mode.s.en)
			return CVMX_HELPER_INTERFACE_MODE_DISABLED;

		if (mode.s.type)
			return CVMX_HELPER_INTERFACE_MODE_GMII;
		else
			return CVMX_HELPER_INTERFACE_MODE_RGMII;
	}
}

__attribute__((used)) static cvmx_helper_interface_mode_t __cvmx_get_mode_cn7xxx(int interface)
{
	union cvmx_gmxx_inf_mode mode;

	mode.u64 = cvmx_read_csr(CVMX_GMXX_INF_MODE(interface));

	switch (interface) {
	case 0:
	case 1:
		switch (mode.cn68xx.mode) {
		case 0:
			return CVMX_HELPER_INTERFACE_MODE_DISABLED;
		case 1:
		case 2:
			return CVMX_HELPER_INTERFACE_MODE_SGMII;
		case 3:
			return CVMX_HELPER_INTERFACE_MODE_XAUI;
		default:
			return CVMX_HELPER_INTERFACE_MODE_SGMII;
		}
	case 2:
		return CVMX_HELPER_INTERFACE_MODE_NPI;
	case 3:
		return CVMX_HELPER_INTERFACE_MODE_LOOP;
	case 4:
		/* TODO: Implement support for AGL (RGMII). */
		return CVMX_HELPER_INTERFACE_MODE_DISABLED;
	default:
		return CVMX_HELPER_INTERFACE_MODE_DISABLED;
	}
}

cvmx_helper_interface_mode_t cvmx_helper_interface_get_mode(int interface)
{
	union cvmx_gmxx_inf_mode mode;

	if (interface < 0 ||
	    interface >= cvmx_helper_get_number_of_interfaces())
		return CVMX_HELPER_INTERFACE_MODE_DISABLED;

	/*
	 * OCTEON III models
	 */
	if (OCTEON_IS_MODEL(OCTEON_CN7XXX))
		return __cvmx_get_mode_cn7xxx(interface);

	/*
	 * Octeon II models
	 */
	if (OCTEON_IS_MODEL(OCTEON_CN6XXX) || OCTEON_IS_MODEL(OCTEON_CNF71XX))
		return __cvmx_get_mode_octeon2(interface);

	/*
	 * Octeon and Octeon Plus models
	 */
	if (interface == 2)
		return CVMX_HELPER_INTERFACE_MODE_NPI;

	if (interface == 3) {
		if (OCTEON_IS_MODEL(OCTEON_CN56XX)
		    || OCTEON_IS_MODEL(OCTEON_CN52XX))
			return CVMX_HELPER_INTERFACE_MODE_LOOP;
		else
			return CVMX_HELPER_INTERFACE_MODE_DISABLED;
	}

	if (interface == 0
	    && cvmx_sysinfo_get()->board_type == CVMX_BOARD_TYPE_CN3005_EVB_HS5
	    && cvmx_sysinfo_get()->board_rev_major == 1) {
		/*
		 * Lie about interface type of CN3005 board.  This
		 * board has a switch on port 1 like the other
		 * evaluation boards, but it is connected over RGMII
		 * instead of GMII.  Report GMII mode so that the
		 * speed is forced to 1 Gbit full duplex.  Other than
		 * some initial configuration (which does not use the
		 * output of this function) there is no difference in
		 * setup between GMII and RGMII modes.
		 */
		return CVMX_HELPER_INTERFACE_MODE_GMII;
	}

	/* Interface 1 is always disabled on CN31XX and CN30XX */
	if ((interface == 1)
	    && (OCTEON_IS_MODEL(OCTEON_CN31XX) || OCTEON_IS_MODEL(OCTEON_CN30XX)
		|| OCTEON_IS_MODEL(OCTEON_CN50XX)
		|| OCTEON_IS_MODEL(OCTEON_CN52XX)))
		return CVMX_HELPER_INTERFACE_MODE_DISABLED;

	mode.u64 = cvmx_read_csr(CVMX_GMXX_INF_MODE(interface));

	if (OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN52XX)) {
		switch (mode.cn56xx.mode) {
		case 0:
			return CVMX_HELPER_INTERFACE_MODE_DISABLED;
		case 1:
			return CVMX_HELPER_INTERFACE_MODE_XAUI;
		case 2:
			return CVMX_HELPER_INTERFACE_MODE_SGMII;
		case 3:
			return CVMX_HELPER_INTERFACE_MODE_PICMG;
		default:
			return CVMX_HELPER_INTERFACE_MODE_DISABLED;
		}
	} else {
		if (!mode.s.en)
			return CVMX_HELPER_INTERFACE_MODE_DISABLED;

		if (mode.s.type) {
			if (OCTEON_IS_MODEL(OCTEON_CN38XX)
			    || OCTEON_IS_MODEL(OCTEON_CN58XX))
				return CVMX_HELPER_INTERFACE_MODE_SPI;
			else
				return CVMX_HELPER_INTERFACE_MODE_GMII;
		} else
			return CVMX_HELPER_INTERFACE_MODE_RGMII;
	}
}

__attribute__((used)) static int __cvmx_helper_port_setup_ipd(int ipd_port)
{
	union cvmx_pip_prt_cfgx port_config;
	union cvmx_pip_prt_tagx tag_config;

	port_config.u64 = cvmx_read_csr(CVMX_PIP_PRT_CFGX(ipd_port));
	tag_config.u64 = cvmx_read_csr(CVMX_PIP_PRT_TAGX(ipd_port));

	/* Have each port go to a different POW queue */
	port_config.s.qos = ipd_port & 0x7;

	/* Process the headers and place the IP header in the work queue */
	port_config.s.mode = CVMX_HELPER_INPUT_PORT_SKIP_MODE;

	tag_config.s.ip6_src_flag = CVMX_HELPER_INPUT_TAG_IPV6_SRC_IP;
	tag_config.s.ip6_dst_flag = CVMX_HELPER_INPUT_TAG_IPV6_DST_IP;
	tag_config.s.ip6_sprt_flag = CVMX_HELPER_INPUT_TAG_IPV6_SRC_PORT;
	tag_config.s.ip6_dprt_flag = CVMX_HELPER_INPUT_TAG_IPV6_DST_PORT;
	tag_config.s.ip6_nxth_flag = CVMX_HELPER_INPUT_TAG_IPV6_NEXT_HEADER;
	tag_config.s.ip4_src_flag = CVMX_HELPER_INPUT_TAG_IPV4_SRC_IP;
	tag_config.s.ip4_dst_flag = CVMX_HELPER_INPUT_TAG_IPV4_DST_IP;
	tag_config.s.ip4_sprt_flag = CVMX_HELPER_INPUT_TAG_IPV4_SRC_PORT;
	tag_config.s.ip4_dprt_flag = CVMX_HELPER_INPUT_TAG_IPV4_DST_PORT;
	tag_config.s.ip4_pctl_flag = CVMX_HELPER_INPUT_TAG_IPV4_PROTOCOL;
	tag_config.s.inc_prt_flag = CVMX_HELPER_INPUT_TAG_INPUT_PORT;
	tag_config.s.tcp6_tag_type = CVMX_HELPER_INPUT_TAG_TYPE;
	tag_config.s.tcp4_tag_type = CVMX_HELPER_INPUT_TAG_TYPE;
	tag_config.s.ip6_tag_type = CVMX_HELPER_INPUT_TAG_TYPE;
	tag_config.s.ip4_tag_type = CVMX_HELPER_INPUT_TAG_TYPE;
	tag_config.s.non_tag_type = CVMX_HELPER_INPUT_TAG_TYPE;
	/* Put all packets in group 0. Other groups can be used by the app */
	tag_config.s.grp = 0;

	cvmx_pip_config_port(ipd_port, port_config, tag_config);

	/* Give the user a chance to override our setting for each port */
	if (cvmx_override_ipd_port_setup)
		cvmx_override_ipd_port_setup(ipd_port);

	return 0;
}

int cvmx_helper_interface_enumerate(int interface)
{
	switch (cvmx_helper_interface_get_mode(interface)) {
		/* These types don't support ports to IPD/PKO */
	case CVMX_HELPER_INTERFACE_MODE_DISABLED:
	case CVMX_HELPER_INTERFACE_MODE_PCIE:
		interface_port_count[interface] = 0;
		break;
		/* XAUI is a single high speed port */
	case CVMX_HELPER_INTERFACE_MODE_XAUI:
		interface_port_count[interface] =
		    __cvmx_helper_xaui_enumerate(interface);
		break;
		/*
		 * RGMII/GMII/MII are all treated about the same. Most
		 * functions refer to these ports as RGMII.
		 */
	case CVMX_HELPER_INTERFACE_MODE_RGMII:
	case CVMX_HELPER_INTERFACE_MODE_GMII:
		interface_port_count[interface] =
		    __cvmx_helper_rgmii_enumerate(interface);
		break;
		/*
		 * SPI4 can have 1-16 ports depending on the device at
		 * the other end.
		 */
	case CVMX_HELPER_INTERFACE_MODE_SPI:
		interface_port_count[interface] =
		    __cvmx_helper_spi_enumerate(interface);
		break;
		/*
		 * SGMII can have 1-4 ports depending on how many are
		 * hooked up.
		 */
	case CVMX_HELPER_INTERFACE_MODE_SGMII:
	case CVMX_HELPER_INTERFACE_MODE_PICMG:
		interface_port_count[interface] =
		    __cvmx_helper_sgmii_enumerate(interface);
		break;
		/* PCI target Network Packet Interface */
	case CVMX_HELPER_INTERFACE_MODE_NPI:
		interface_port_count[interface] =
		    __cvmx_helper_npi_enumerate(interface);
		break;
		/*
		 * Special loopback only ports. These are not the same
		 * as other ports in loopback mode.
		 */
	case CVMX_HELPER_INTERFACE_MODE_LOOP:
		interface_port_count[interface] =
		    __cvmx_helper_loop_enumerate(interface);
		break;
	}

	interface_port_count[interface] =
	    __cvmx_helper_board_interface_probe(interface,
						interface_port_count
						[interface]);

	/* Make sure all global variables propagate to other cores */
	CVMX_SYNCWS;

	return 0;
}

int cvmx_helper_interface_probe(int interface)
{
	cvmx_helper_interface_enumerate(interface);
	/* At this stage in the game we don't want packets to be moving yet.
	   The following probe calls should perform hardware setup
	   needed to determine port counts. Receive must still be disabled */
	switch (cvmx_helper_interface_get_mode(interface)) {
		/* These types don't support ports to IPD/PKO */
	case CVMX_HELPER_INTERFACE_MODE_DISABLED:
	case CVMX_HELPER_INTERFACE_MODE_PCIE:
		break;
		/* XAUI is a single high speed port */
	case CVMX_HELPER_INTERFACE_MODE_XAUI:
		__cvmx_helper_xaui_probe(interface);
		break;
		/*
		 * RGMII/GMII/MII are all treated about the same. Most
		 * functions refer to these ports as RGMII.
		 */
	case CVMX_HELPER_INTERFACE_MODE_RGMII:
	case CVMX_HELPER_INTERFACE_MODE_GMII:
		__cvmx_helper_rgmii_probe(interface);
		break;
		/*
		 * SPI4 can have 1-16 ports depending on the device at
		 * the other end.
		 */
	case CVMX_HELPER_INTERFACE_MODE_SPI:
		__cvmx_helper_spi_probe(interface);
		break;
		/*
		 * SGMII can have 1-4 ports depending on how many are
		 * hooked up.
		 */
	case CVMX_HELPER_INTERFACE_MODE_SGMII:
	case CVMX_HELPER_INTERFACE_MODE_PICMG:
		__cvmx_helper_sgmii_probe(interface);
		break;
		/* PCI target Network Packet Interface */
	case CVMX_HELPER_INTERFACE_MODE_NPI:
		__cvmx_helper_npi_probe(interface);
		break;
		/*
		 * Special loopback only ports. These are not the same
		 * as other ports in loopback mode.
		 */
	case CVMX_HELPER_INTERFACE_MODE_LOOP:
		__cvmx_helper_loop_probe(interface);
		break;
	}

	/* Make sure all global variables propagate to other cores */
	CVMX_SYNCWS;

	return 0;
}

__attribute__((used)) static int __cvmx_helper_interface_setup_ipd(int interface)
{
	int ipd_port = cvmx_helper_get_ipd_port(interface, 0);
	int num_ports = interface_port_count[interface];

	while (num_ports--) {
		__cvmx_helper_port_setup_ipd(ipd_port);
		ipd_port++;
	}
	return 0;
}

__attribute__((used)) static int __cvmx_helper_global_setup_ipd(void)
{
	/* Setup the global packet input options */
	cvmx_ipd_config(CVMX_FPA_PACKET_POOL_SIZE / 8,
			CVMX_HELPER_FIRST_MBUFF_SKIP / 8,
			CVMX_HELPER_NOT_FIRST_MBUFF_SKIP / 8,
			/* The +8 is to account for the next ptr */
			(CVMX_HELPER_FIRST_MBUFF_SKIP + 8) / 128,
			/* The +8 is to account for the next ptr */
			(CVMX_HELPER_NOT_FIRST_MBUFF_SKIP + 8) / 128,
			CVMX_FPA_WQE_POOL,
			CVMX_IPD_OPC_MODE_STT,
			CVMX_HELPER_ENABLE_BACK_PRESSURE);
	return 0;
}

__attribute__((used)) static int __cvmx_helper_interface_setup_pko(int interface)
{
	/*
	 * Each packet output queue has an associated priority. The
	 * higher the priority, the more often it can send a packet. A
	 * priority of 8 means it can send in all 8 rounds of
	 * contention. We're going to make each queue one less than
	 * the last.  The vector of priorities has been extended to
	 * support CN5xxx CPUs, where up to 16 queues can be
	 * associated to a port.  To keep backward compatibility we
	 * don't change the initial 8 priorities and replicate them in
	 * the second half.  With per-core PKO queues (PKO lockless
	 * operation) all queues have the same priority.
	 */
	uint64_t priorities[16] =
	    { 8, 7, 6, 5, 4, 3, 2, 1, 8, 7, 6, 5, 4, 3, 2, 1 };

	/*
	 * Setup the IPD/PIP and PKO for the ports discovered
	 * above. Here packet classification, tagging and output
	 * priorities are set.
	 */
	int ipd_port = cvmx_helper_get_ipd_port(interface, 0);
	int num_ports = interface_port_count[interface];
	while (num_ports--) {
		/*
		 * Give the user a chance to override the per queue
		 * priorities.
		 */
		if (cvmx_override_pko_queue_priority)
			cvmx_override_pko_queue_priority(ipd_port, priorities);

		cvmx_pko_config_port(ipd_port,
				     cvmx_pko_get_base_queue_per_core(ipd_port,
								      0),
				     cvmx_pko_get_num_queues(ipd_port),
				     priorities);
		ipd_port++;
	}
	return 0;
}

__attribute__((used)) static int __cvmx_helper_global_setup_pko(void)
{
	/*
	 * Disable tagwait FAU timeout. This needs to be done before
	 * anyone might start packet output using tags.
	 */
	union cvmx_iob_fau_timeout fau_to;
	fau_to.u64 = 0;
	fau_to.s.tout_val = 0xfff;
	fau_to.s.tout_enb = 0;
	cvmx_write_csr(CVMX_IOB_FAU_TIMEOUT, fau_to.u64);

	if (OCTEON_IS_MODEL(OCTEON_CN68XX)) {
		union cvmx_pko_reg_min_pkt min_pkt;

		min_pkt.u64 = 0;
		min_pkt.s.size1 = 59;
		min_pkt.s.size2 = 59;
		min_pkt.s.size3 = 59;
		min_pkt.s.size4 = 59;
		min_pkt.s.size5 = 59;
		min_pkt.s.size6 = 59;
		min_pkt.s.size7 = 59;
		cvmx_write_csr(CVMX_PKO_REG_MIN_PKT, min_pkt.u64);
	}

	return 0;
}

__attribute__((used)) static int __cvmx_helper_global_setup_backpressure(void)
{
#if CVMX_HELPER_DISABLE_RGMII_BACKPRESSURE
	/* Disable backpressure if configured to do so */
	/* Disable backpressure (pause frame) generation */
	int num_interfaces = cvmx_helper_get_number_of_interfaces();
	int interface;
	for (interface = 0; interface < num_interfaces; interface++) {
		switch (cvmx_helper_interface_get_mode(interface)) {
		case CVMX_HELPER_INTERFACE_MODE_DISABLED:
		case CVMX_HELPER_INTERFACE_MODE_PCIE:
		case CVMX_HELPER_INTERFACE_MODE_NPI:
		case CVMX_HELPER_INTERFACE_MODE_LOOP:
		case CVMX_HELPER_INTERFACE_MODE_XAUI:
			break;
		case CVMX_HELPER_INTERFACE_MODE_RGMII:
		case CVMX_HELPER_INTERFACE_MODE_GMII:
		case CVMX_HELPER_INTERFACE_MODE_SPI:
		case CVMX_HELPER_INTERFACE_MODE_SGMII:
		case CVMX_HELPER_INTERFACE_MODE_PICMG:
			cvmx_gmx_set_backpressure_override(interface, 0xf);
			break;
		}
	}
#endif

	return 0;
}

__attribute__((used)) static int __cvmx_helper_packet_hardware_enable(int interface)
{
	int result = 0;
	switch (cvmx_helper_interface_get_mode(interface)) {
		/* These types don't support ports to IPD/PKO */
	case CVMX_HELPER_INTERFACE_MODE_DISABLED:
	case CVMX_HELPER_INTERFACE_MODE_PCIE:
		/* Nothing to do */
		break;
		/* XAUI is a single high speed port */
	case CVMX_HELPER_INTERFACE_MODE_XAUI:
		result = __cvmx_helper_xaui_enable(interface);
		break;
		/*
		 * RGMII/GMII/MII are all treated about the same. Most
		 * functions refer to these ports as RGMII
		 */
	case CVMX_HELPER_INTERFACE_MODE_RGMII:
	case CVMX_HELPER_INTERFACE_MODE_GMII:
		result = __cvmx_helper_rgmii_enable(interface);
		break;
		/*
		 * SPI4 can have 1-16 ports depending on the device at
		 * the other end
		 */
	case CVMX_HELPER_INTERFACE_MODE_SPI:
		result = __cvmx_helper_spi_enable(interface);
		break;
		/*
		 * SGMII can have 1-4 ports depending on how many are
		 * hooked up
		 */
	case CVMX_HELPER_INTERFACE_MODE_SGMII:
	case CVMX_HELPER_INTERFACE_MODE_PICMG:
		result = __cvmx_helper_sgmii_enable(interface);
		break;
		/* PCI target Network Packet Interface */
	case CVMX_HELPER_INTERFACE_MODE_NPI:
		result = __cvmx_helper_npi_enable(interface);
		break;
		/*
		 * Special loopback only ports. These are not the same
		 * as other ports in loopback mode
		 */
	case CVMX_HELPER_INTERFACE_MODE_LOOP:
		result = __cvmx_helper_loop_enable(interface);
		break;
	}
	result |= __cvmx_helper_board_hardware_enable(interface);
	return result;
}

int __cvmx_helper_errata_fix_ipd_ptr_alignment(void)
{
#define FIX_IPD_FIRST_BUFF_PAYLOAD_BYTES \
     (CVMX_FPA_PACKET_POOL_SIZE-8-CVMX_HELPER_FIRST_MBUFF_SKIP)
#define FIX_IPD_NON_FIRST_BUFF_PAYLOAD_BYTES \
	(CVMX_FPA_PACKET_POOL_SIZE-8-CVMX_HELPER_NOT_FIRST_MBUFF_SKIP)
#define FIX_IPD_OUTPORT 0
	/* Ports 0-15 are interface 0, 16-31 are interface 1 */
#define INTERFACE(port) (port >> 4)
#define INDEX(port) (port & 0xf)
	uint64_t *p64;
	cvmx_pko_command_word0_t pko_command;
	union cvmx_buf_ptr g_buffer, pkt_buffer;
	cvmx_wqe_t *work;
	int size, num_segs = 0, wqe_pcnt, pkt_pcnt;
	union cvmx_gmxx_prtx_cfg gmx_cfg;
	int retry_cnt;
	int retry_loop_cnt;
	int i;

	/* Save values for restore at end */
	uint64_t prtx_cfg =
	    cvmx_read_csr(CVMX_GMXX_PRTX_CFG
			  (INDEX(FIX_IPD_OUTPORT), INTERFACE(FIX_IPD_OUTPORT)));
	uint64_t tx_ptr_en =
	    cvmx_read_csr(CVMX_ASXX_TX_PRT_EN(INTERFACE(FIX_IPD_OUTPORT)));
	uint64_t rx_ptr_en =
	    cvmx_read_csr(CVMX_ASXX_RX_PRT_EN(INTERFACE(FIX_IPD_OUTPORT)));
	uint64_t rxx_jabber =
	    cvmx_read_csr(CVMX_GMXX_RXX_JABBER
			  (INDEX(FIX_IPD_OUTPORT), INTERFACE(FIX_IPD_OUTPORT)));
	uint64_t frame_max =
	    cvmx_read_csr(CVMX_GMXX_RXX_FRM_MAX
			  (INDEX(FIX_IPD_OUTPORT), INTERFACE(FIX_IPD_OUTPORT)));

	/* Configure port to gig FDX as required for loopback mode */
	cvmx_helper_rgmii_internal_loopback(FIX_IPD_OUTPORT);

	/*
	 * Disable reception on all ports so if traffic is present it
	 * will not interfere.
	 */
	cvmx_write_csr(CVMX_ASXX_RX_PRT_EN(INTERFACE(FIX_IPD_OUTPORT)), 0);

	__delay(100000000ull);

	for (retry_loop_cnt = 0; retry_loop_cnt < 10; retry_loop_cnt++) {
		retry_cnt = 100000;
		wqe_pcnt = cvmx_read_csr(CVMX_IPD_PTR_COUNT);
		pkt_pcnt = (wqe_pcnt >> 7) & 0x7f;
		wqe_pcnt &= 0x7f;

		num_segs = (2 + pkt_pcnt - wqe_pcnt) & 3;

		if (num_segs == 0)
			goto fix_ipd_exit;

		num_segs += 1;

		size =
		    FIX_IPD_FIRST_BUFF_PAYLOAD_BYTES +
		    ((num_segs - 1) * FIX_IPD_NON_FIRST_BUFF_PAYLOAD_BYTES) -
		    (FIX_IPD_NON_FIRST_BUFF_PAYLOAD_BYTES / 2);

		cvmx_write_csr(CVMX_ASXX_PRT_LOOP(INTERFACE(FIX_IPD_OUTPORT)),
			       1 << INDEX(FIX_IPD_OUTPORT));
		CVMX_SYNC;

		g_buffer.u64 = 0;
		g_buffer.s.addr =
		    cvmx_ptr_to_phys(cvmx_fpa_alloc(CVMX_FPA_WQE_POOL));
		if (g_buffer.s.addr == 0) {
			cvmx_dprintf("WARNING: FIX_IPD_PTR_ALIGNMENT "
				     "buffer allocation failure.\n");
			goto fix_ipd_exit;
		}

		g_buffer.s.pool = CVMX_FPA_WQE_POOL;
		g_buffer.s.size = num_segs;

		pkt_buffer.u64 = 0;
		pkt_buffer.s.addr =
		    cvmx_ptr_to_phys(cvmx_fpa_alloc(CVMX_FPA_PACKET_POOL));
		if (pkt_buffer.s.addr == 0) {
			cvmx_dprintf("WARNING: FIX_IPD_PTR_ALIGNMENT "
				     "buffer allocation failure.\n");
			goto fix_ipd_exit;
		}
		pkt_buffer.s.i = 1;
		pkt_buffer.s.pool = CVMX_FPA_PACKET_POOL;
		pkt_buffer.s.size = FIX_IPD_FIRST_BUFF_PAYLOAD_BYTES;

		p64 = (uint64_t *) cvmx_phys_to_ptr(pkt_buffer.s.addr);
		p64[0] = 0xffffffffffff0000ull;
		p64[1] = 0x08004510ull;
		p64[2] = ((uint64_t) (size - 14) << 48) | 0x5ae740004000ull;
		p64[3] = 0x3a5fc0a81073c0a8ull;

		for (i = 0; i < num_segs; i++) {
			if (i > 0)
				pkt_buffer.s.size =
				    FIX_IPD_NON_FIRST_BUFF_PAYLOAD_BYTES;

			if (i == (num_segs - 1))
				pkt_buffer.s.i = 0;

			*(uint64_t *) cvmx_phys_to_ptr(g_buffer.s.addr +
						       8 * i) = pkt_buffer.u64;
		}

		/* Build the PKO command */
		pko_command.u64 = 0;
		pko_command.s.segs = num_segs;
		pko_command.s.total_bytes = size;
		pko_command.s.dontfree = 0;
		pko_command.s.gather = 1;

		gmx_cfg.u64 =
		    cvmx_read_csr(CVMX_GMXX_PRTX_CFG
				  (INDEX(FIX_IPD_OUTPORT),
				   INTERFACE(FIX_IPD_OUTPORT)));
		gmx_cfg.s.en = 1;
		cvmx_write_csr(CVMX_GMXX_PRTX_CFG
			       (INDEX(FIX_IPD_OUTPORT),
				INTERFACE(FIX_IPD_OUTPORT)), gmx_cfg.u64);
		cvmx_write_csr(CVMX_ASXX_TX_PRT_EN(INTERFACE(FIX_IPD_OUTPORT)),
			       1 << INDEX(FIX_IPD_OUTPORT));
		cvmx_write_csr(CVMX_ASXX_RX_PRT_EN(INTERFACE(FIX_IPD_OUTPORT)),
			       1 << INDEX(FIX_IPD_OUTPORT));

		cvmx_write_csr(CVMX_GMXX_RXX_JABBER
			       (INDEX(FIX_IPD_OUTPORT),
				INTERFACE(FIX_IPD_OUTPORT)), 65392 - 14 - 4);
		cvmx_write_csr(CVMX_GMXX_RXX_FRM_MAX
			       (INDEX(FIX_IPD_OUTPORT),
				INTERFACE(FIX_IPD_OUTPORT)), 65392 - 14 - 4);

		cvmx_pko_send_packet_prepare(FIX_IPD_OUTPORT,
					     cvmx_pko_get_base_queue
					     (FIX_IPD_OUTPORT),
					     CVMX_PKO_LOCK_CMD_QUEUE);
		cvmx_pko_send_packet_finish(FIX_IPD_OUTPORT,
					    cvmx_pko_get_base_queue
					    (FIX_IPD_OUTPORT), pko_command,
					    g_buffer, CVMX_PKO_LOCK_CMD_QUEUE);

		CVMX_SYNC;

		do {
			work = cvmx_pow_work_request_sync(CVMX_POW_WAIT);
			retry_cnt--;
		} while ((work == NULL) && (retry_cnt > 0));

		if (!retry_cnt)
			cvmx_dprintf("WARNING: FIX_IPD_PTR_ALIGNMENT "
				     "get_work() timeout occurred.\n");

		/* Free packet */
		if (work)
			cvmx_helper_free_packet_data(work);
	}

fix_ipd_exit:

	/* Return CSR configs to saved values */
	cvmx_write_csr(CVMX_GMXX_PRTX_CFG
		       (INDEX(FIX_IPD_OUTPORT), INTERFACE(FIX_IPD_OUTPORT)),
		       prtx_cfg);
	cvmx_write_csr(CVMX_ASXX_TX_PRT_EN(INTERFACE(FIX_IPD_OUTPORT)),
		       tx_ptr_en);
	cvmx_write_csr(CVMX_ASXX_RX_PRT_EN(INTERFACE(FIX_IPD_OUTPORT)),
		       rx_ptr_en);
	cvmx_write_csr(CVMX_GMXX_RXX_JABBER
		       (INDEX(FIX_IPD_OUTPORT), INTERFACE(FIX_IPD_OUTPORT)),
		       rxx_jabber);
	cvmx_write_csr(CVMX_GMXX_RXX_FRM_MAX
		       (INDEX(FIX_IPD_OUTPORT), INTERFACE(FIX_IPD_OUTPORT)),
		       frame_max);
	cvmx_write_csr(CVMX_ASXX_PRT_LOOP(INTERFACE(FIX_IPD_OUTPORT)), 0);

	CVMX_SYNC;
	if (num_segs)
		cvmx_dprintf("WARNING: FIX_IPD_PTR_ALIGNMENT failed.\n");

	return !!num_segs;

}

int cvmx_helper_ipd_and_packet_input_enable(void)
{
	int num_interfaces;
	int interface;

	/* Enable IPD */
	cvmx_ipd_enable();

	/*
	 * Time to enable hardware ports packet input and output. Note
	 * that at this point IPD/PIP must be fully functional and PKO
	 * must be disabled
	 */
	num_interfaces = cvmx_helper_get_number_of_interfaces();
	for (interface = 0; interface < num_interfaces; interface++) {
		if (cvmx_helper_ports_on_interface(interface) > 0)
			__cvmx_helper_packet_hardware_enable(interface);
	}

	/* Finally enable PKO now that the entire path is up and running */
	cvmx_pko_enable();

	if ((OCTEON_IS_MODEL(OCTEON_CN31XX_PASS1)
	     || OCTEON_IS_MODEL(OCTEON_CN30XX_PASS1))
	    && (cvmx_sysinfo_get()->board_type != CVMX_BOARD_TYPE_SIM))
		__cvmx_helper_errata_fix_ipd_ptr_alignment();
	return 0;
}

int cvmx_helper_initialize_packet_io_global(void)
{
	int result = 0;
	int interface;
	union cvmx_l2c_cfg l2c_cfg;
	union cvmx_smix_en smix_en;
	const int num_interfaces = cvmx_helper_get_number_of_interfaces();

	/*
	 * CN52XX pass 1: Due to a bug in 2nd order CDR, it needs to
	 * be disabled.
	 */
	if (OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_0))
		__cvmx_helper_errata_qlm_disable_2nd_order_cdr(1);

	/*
	 * Tell L2 to give the IOB statically higher priority compared
	 * to the cores. This avoids conditions where IO blocks might
	 * be starved under very high L2 loads.
	 */
	l2c_cfg.u64 = cvmx_read_csr(CVMX_L2C_CFG);
	l2c_cfg.s.lrf_arb_mode = 0;
	l2c_cfg.s.rfb_arb_mode = 0;
	cvmx_write_csr(CVMX_L2C_CFG, l2c_cfg.u64);

	/* Make sure SMI/MDIO is enabled so we can query PHYs */
	smix_en.u64 = cvmx_read_csr(CVMX_SMIX_EN(0));
	if (!smix_en.s.en) {
		smix_en.s.en = 1;
		cvmx_write_csr(CVMX_SMIX_EN(0), smix_en.u64);
	}

	/* Newer chips actually have two SMI/MDIO interfaces */
	if (!OCTEON_IS_MODEL(OCTEON_CN3XXX) &&
	    !OCTEON_IS_MODEL(OCTEON_CN58XX) &&
	    !OCTEON_IS_MODEL(OCTEON_CN50XX)) {
		smix_en.u64 = cvmx_read_csr(CVMX_SMIX_EN(1));
		if (!smix_en.s.en) {
			smix_en.s.en = 1;
			cvmx_write_csr(CVMX_SMIX_EN(1), smix_en.u64);
		}
	}

	cvmx_pko_initialize_global();
	for (interface = 0; interface < num_interfaces; interface++) {
		result |= cvmx_helper_interface_probe(interface);
		if (cvmx_helper_ports_on_interface(interface) > 0)
			cvmx_dprintf("Interface %d has %d ports (%s)\n",
				     interface,
				     cvmx_helper_ports_on_interface(interface),
				     cvmx_helper_interface_mode_to_string
				     (cvmx_helper_interface_get_mode
				      (interface)));
		result |= __cvmx_helper_interface_setup_ipd(interface);
		result |= __cvmx_helper_interface_setup_pko(interface);
	}

	result |= __cvmx_helper_global_setup_ipd();
	result |= __cvmx_helper_global_setup_pko();

	/* Enable any flow control and backpressure */
	result |= __cvmx_helper_global_setup_backpressure();

#if CVMX_HELPER_ENABLE_IPD
	result |= cvmx_helper_ipd_and_packet_input_enable();
#endif
	return result;
}

int cvmx_helper_initialize_packet_io_local(void)
{
	return cvmx_pko_initialize_local();
}

cvmx_helper_link_info_t cvmx_helper_link_get(int ipd_port)
{
	cvmx_helper_link_info_t result;
	int interface = cvmx_helper_get_interface_num(ipd_port);
	int index = cvmx_helper_get_interface_index_num(ipd_port);

	/* The default result will be a down link unless the code below
	   changes it */
	result.u64 = 0;

	if (index >= cvmx_helper_ports_on_interface(interface))
		return result;

	switch (cvmx_helper_interface_get_mode(interface)) {
	case CVMX_HELPER_INTERFACE_MODE_DISABLED:
	case CVMX_HELPER_INTERFACE_MODE_PCIE:
		/* Network links are not supported */
		break;
	case CVMX_HELPER_INTERFACE_MODE_XAUI:
		result = __cvmx_helper_xaui_link_get(ipd_port);
		break;
	case CVMX_HELPER_INTERFACE_MODE_GMII:
		if (index == 0)
			result = __cvmx_helper_rgmii_link_get(ipd_port);
		else {
			result.s.full_duplex = 1;
			result.s.link_up = 1;
			result.s.speed = 1000;
		}
		break;
	case CVMX_HELPER_INTERFACE_MODE_RGMII:
		result = __cvmx_helper_rgmii_link_get(ipd_port);
		break;
	case CVMX_HELPER_INTERFACE_MODE_SPI:
		result = __cvmx_helper_spi_link_get(ipd_port);
		break;
	case CVMX_HELPER_INTERFACE_MODE_SGMII:
	case CVMX_HELPER_INTERFACE_MODE_PICMG:
		result = __cvmx_helper_sgmii_link_get(ipd_port);
		break;
	case CVMX_HELPER_INTERFACE_MODE_NPI:
	case CVMX_HELPER_INTERFACE_MODE_LOOP:
		/* Network links are not supported */
		break;
	}
	return result;
}

int cvmx_helper_link_set(int ipd_port, cvmx_helper_link_info_t link_info)
{
	int result = -1;
	int interface = cvmx_helper_get_interface_num(ipd_port);
	int index = cvmx_helper_get_interface_index_num(ipd_port);

	if (index >= cvmx_helper_ports_on_interface(interface))
		return -1;

	switch (cvmx_helper_interface_get_mode(interface)) {
	case CVMX_HELPER_INTERFACE_MODE_DISABLED:
	case CVMX_HELPER_INTERFACE_MODE_PCIE:
		break;
	case CVMX_HELPER_INTERFACE_MODE_XAUI:
		result = __cvmx_helper_xaui_link_set(ipd_port, link_info);
		break;
		/*
		 * RGMII/GMII/MII are all treated about the same. Most
		 * functions refer to these ports as RGMII.
		 */
	case CVMX_HELPER_INTERFACE_MODE_RGMII:
	case CVMX_HELPER_INTERFACE_MODE_GMII:
		result = __cvmx_helper_rgmii_link_set(ipd_port, link_info);
		break;
	case CVMX_HELPER_INTERFACE_MODE_SPI:
		result = __cvmx_helper_spi_link_set(ipd_port, link_info);
		break;
	case CVMX_HELPER_INTERFACE_MODE_SGMII:
	case CVMX_HELPER_INTERFACE_MODE_PICMG:
		result = __cvmx_helper_sgmii_link_set(ipd_port, link_info);
		break;
	case CVMX_HELPER_INTERFACE_MODE_NPI:
	case CVMX_HELPER_INTERFACE_MODE_LOOP:
		break;
	}
	return result;
}

int cvmx_helper_configure_loopback(int ipd_port, int enable_internal,
				   int enable_external)
{
	int result = -1;
	int interface = cvmx_helper_get_interface_num(ipd_port);
	int index = cvmx_helper_get_interface_index_num(ipd_port);

	if (index >= cvmx_helper_ports_on_interface(interface))
		return -1;

	switch (cvmx_helper_interface_get_mode(interface)) {
	case CVMX_HELPER_INTERFACE_MODE_DISABLED:
	case CVMX_HELPER_INTERFACE_MODE_PCIE:
	case CVMX_HELPER_INTERFACE_MODE_SPI:
	case CVMX_HELPER_INTERFACE_MODE_NPI:
	case CVMX_HELPER_INTERFACE_MODE_LOOP:
		break;
	case CVMX_HELPER_INTERFACE_MODE_XAUI:
		result =
		    __cvmx_helper_xaui_configure_loopback(ipd_port,
							  enable_internal,
							  enable_external);
		break;
	case CVMX_HELPER_INTERFACE_MODE_RGMII:
	case CVMX_HELPER_INTERFACE_MODE_GMII:
		result =
		    __cvmx_helper_rgmii_configure_loopback(ipd_port,
							   enable_internal,
							   enable_external);
		break;
	case CVMX_HELPER_INTERFACE_MODE_SGMII:
	case CVMX_HELPER_INTERFACE_MODE_PICMG:
		result =
		    __cvmx_helper_sgmii_configure_loopback(ipd_port,
							   enable_internal,
							   enable_external);
		break;
	}
	return result;
}

