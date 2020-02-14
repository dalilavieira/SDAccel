#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {int enable; } ;
union cvmx_pko_reg_crc_enable {void* u64; TYPE_1__ s; } ;
struct TYPE_10__ {int crc_en; } ;
union cvmx_pip_prt_cfgx {void* u64; TYPE_2__ s; } ;
struct TYPE_11__ {int status; int duplex; int speed; } ;
union cvmx_gmxx_rxx_rx_inbnd {TYPE_3__ s; } ;
struct TYPE_12__ {int link_up; int full_duplex; int speed; } ;
struct TYPE_13__ {TYPE_4__ s; scalar_t__ u64; } ;
typedef  TYPE_5__ cvmx_helper_link_info_t ;
struct TYPE_14__ {scalar_t__ board_type; } ;

/* Variables and functions */
 scalar_t__ CVMX_BOARD_TYPE_SIM ; 
 int /*<<< orphan*/  CVMX_HELPER_SPI_TIMEOUT ; 
 int /*<<< orphan*/  CVMX_PIP_PRT_CFGX (int) ; 
 int /*<<< orphan*/  CVMX_PKO_REG_CRC_ENABLE ; 
 int /*<<< orphan*/  CVMX_SPI_MODE_DUPLEX ; 
 int /*<<< orphan*/  __cvmx_helper_setup_gmx (int,int) ; 
 int /*<<< orphan*/  __cvmx_interrupt_gmxx_enable (int) ; 
 int /*<<< orphan*/  __cvmx_interrupt_spxx_int_msk_enable (int) ; 
 int /*<<< orphan*/  __cvmx_interrupt_stxx_int_msk_enable (int) ; 
 int cvmx_helper_get_interface_index_num (int) ; 
 int cvmx_helper_get_interface_num (int) ; 
 int cvmx_helper_ports_on_interface (int) ; 
 void* cvmx_read_csr (int /*<<< orphan*/ ) ; 
 union cvmx_gmxx_rxx_rx_inbnd cvmx_spi4000_check_speed (int,int) ; 
 int /*<<< orphan*/  cvmx_spi4000_initialize (int) ; 
 scalar_t__ cvmx_spi4000_is_present (int) ; 
 int /*<<< orphan*/  cvmx_spi_start_interface (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 TYPE_6__* cvmx_sysinfo_get () ; 
 int /*<<< orphan*/  cvmx_write_csr (int /*<<< orphan*/ ,void*) ; 

int __cvmx_helper_spi_enumerate(int interface)
{
	if ((cvmx_sysinfo_get()->board_type != CVMX_BOARD_TYPE_SIM) &&
	    cvmx_spi4000_is_present(interface)) {
		return 10;
	} else {
		return 16;
	}
}

int __cvmx_helper_spi_probe(int interface)
{
	int num_ports = 0;

	if ((cvmx_sysinfo_get()->board_type != CVMX_BOARD_TYPE_SIM) &&
	    cvmx_spi4000_is_present(interface)) {
		num_ports = 10;
	} else {
		union cvmx_pko_reg_crc_enable enable;
		num_ports = 16;
		/*
		 * Unlike the SPI4000, most SPI devices don't
		 * automatically put on the L2 CRC. For everything
		 * except for the SPI4000 have PKO append the L2 CRC
		 * to the packet.
		 */
		enable.u64 = cvmx_read_csr(CVMX_PKO_REG_CRC_ENABLE);
		enable.s.enable |= 0xffff << (interface * 16);
		cvmx_write_csr(CVMX_PKO_REG_CRC_ENABLE, enable.u64);
	}
	__cvmx_helper_setup_gmx(interface, num_ports);
	return num_ports;
}

int __cvmx_helper_spi_enable(int interface)
{
	/*
	 * Normally the ethernet L2 CRC is checked and stripped in the
	 * GMX block.  When you are using SPI, this isn' the case and
	 * IPD needs to check the L2 CRC.
	 */
	int num_ports = cvmx_helper_ports_on_interface(interface);
	int ipd_port;
	for (ipd_port = interface * 16; ipd_port < interface * 16 + num_ports;
	     ipd_port++) {
		union cvmx_pip_prt_cfgx port_config;
		port_config.u64 = cvmx_read_csr(CVMX_PIP_PRT_CFGX(ipd_port));
		port_config.s.crc_en = 1;
		cvmx_write_csr(CVMX_PIP_PRT_CFGX(ipd_port), port_config.u64);
	}

	if (cvmx_sysinfo_get()->board_type != CVMX_BOARD_TYPE_SIM) {
		cvmx_spi_start_interface(interface, CVMX_SPI_MODE_DUPLEX,
					 CVMX_HELPER_SPI_TIMEOUT, num_ports);
		if (cvmx_spi4000_is_present(interface))
			cvmx_spi4000_initialize(interface);
	}
	__cvmx_interrupt_spxx_int_msk_enable(interface);
	__cvmx_interrupt_stxx_int_msk_enable(interface);
	__cvmx_interrupt_gmxx_enable(interface);
	return 0;
}

cvmx_helper_link_info_t __cvmx_helper_spi_link_get(int ipd_port)
{
	cvmx_helper_link_info_t result;
	int interface = cvmx_helper_get_interface_num(ipd_port);
	int index = cvmx_helper_get_interface_index_num(ipd_port);
	result.u64 = 0;

	if (cvmx_sysinfo_get()->board_type == CVMX_BOARD_TYPE_SIM) {
		/* The simulator gives you a simulated full duplex link */
		result.s.link_up = 1;
		result.s.full_duplex = 1;
		result.s.speed = 10000;
	} else if (cvmx_spi4000_is_present(interface)) {
		union cvmx_gmxx_rxx_rx_inbnd inband =
		    cvmx_spi4000_check_speed(interface, index);
		result.s.link_up = inband.s.status;
		result.s.full_duplex = inband.s.duplex;
		switch (inband.s.speed) {
		case 0: /* 10 Mbps */
			result.s.speed = 10;
			break;
		case 1: /* 100 Mbps */
			result.s.speed = 100;
			break;
		case 2: /* 1 Gbps */
			result.s.speed = 1000;
			break;
		case 3: /* Illegal */
			result.s.speed = 0;
			result.s.link_up = 0;
			break;
		}
	} else {
		/* For generic SPI we can't determine the link, just return some
		   sane results */
		result.s.link_up = 1;
		result.s.full_duplex = 1;
		result.s.speed = 10000;
	}
	return result;
}

int __cvmx_helper_spi_link_set(int ipd_port, cvmx_helper_link_info_t link_info)
{
	/* Nothing to do. If we have a SPI4000 then the setup was already performed
	   by cvmx_spi4000_check_speed(). If not then there isn't any link
	   info */
	return 0;
}

