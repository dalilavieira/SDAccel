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
typedef  int uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
struct command_table_helper {int dummy; } ;
typedef  enum transmitter { ____Placeholder_transmitter } transmitter ;
typedef  enum signal_type { ____Placeholder_signal_type } signal_type ;
typedef  enum encoder_id { ____Placeholder_encoder_id } encoder_id ;
typedef  enum dce_version { ____Placeholder_dce_version } dce_version ;
typedef  enum controller_id { ____Placeholder_controller_id } controller_id ;
typedef  enum clock_source_id { ____Placeholder_clock_source_id } clock_source_id ;

/* Variables and functions */
 int ATOM_CRTC1 ; 
 int ATOM_CRTC2 ; 
 int ATOM_CRTC3 ; 
 int ATOM_CRTC4 ; 
 int ATOM_CRTC5 ; 
 int ATOM_CRTC6 ; 
 int ATOM_CRTC_INVALID ; 
 int /*<<< orphan*/  ATOM_ENCODER_MODE_CRT ; 
 int /*<<< orphan*/  ATOM_ENCODER_MODE_DP ; 
 int /*<<< orphan*/  ATOM_ENCODER_MODE_DP_AUDIO ; 
 int /*<<< orphan*/  ATOM_ENCODER_MODE_DVI ; 
 int /*<<< orphan*/  ATOM_ENCODER_MODE_HDMI ; 
 int /*<<< orphan*/  ATOM_ENCODER_MODE_LVDS ; 
 int /*<<< orphan*/  BREAK_TO_DEBUGGER () ; 
#define  CLOCK_SOURCE_ID_EXTERNAL 184 
#define  CLOCK_SOURCE_ID_PLL1 183 
#define  CLOCK_SOURCE_ID_PLL2 182 
#define  CLOCK_SOURCE_ID_UNDEFINED 181 
#define  CONTROLLER_ID_D0 180 
#define  CONTROLLER_ID_D1 179 
#define  CONTROLLER_ID_D2 178 
#define  CONTROLLER_ID_D3 177 
#define  CONTROLLER_ID_D4 176 
#define  CONTROLLER_ID_D5 175 
#define  CONTROLLER_ID_UNDEFINED 174 
#define  DCE_VERSION_10_0 173 
#define  DCE_VERSION_11_0 172 
#define  DCE_VERSION_11_2 171 
#define  DCE_VERSION_11_22 170 
#define  DCE_VERSION_12_0 169 
#define  DCE_VERSION_8_0 168 
#define  DCE_VERSION_8_1 167 
#define  DCE_VERSION_8_3 166 
#define  ENCODER_ID_EXTERNAL_MVPU_FPGA 165 
#define  ENCODER_ID_EXTERNAL_NUTMEG 164 
#define  ENCODER_ID_EXTERNAL_TRAVIS 163 
#define  ENCODER_ID_INTERNAL_DAC1 162 
#define  ENCODER_ID_INTERNAL_DAC2 161 
#define  ENCODER_ID_INTERNAL_DDI 160 
#define  ENCODER_ID_INTERNAL_HDMI 159 
#define  ENCODER_ID_INTERNAL_KLDSCP_DAC1 158 
#define  ENCODER_ID_INTERNAL_KLDSCP_DAC2 157 
#define  ENCODER_ID_INTERNAL_KLDSCP_LVTMA 156 
#define  ENCODER_ID_INTERNAL_KLDSCP_TMDS1 155 
#define  ENCODER_ID_INTERNAL_LVDS 154 
#define  ENCODER_ID_INTERNAL_LVTM1 153 
#define  ENCODER_ID_INTERNAL_TMDS1 152 
#define  ENCODER_ID_INTERNAL_TMDS2 151 
#define  ENCODER_ID_INTERNAL_UNIPHY 150 
#define  ENCODER_ID_INTERNAL_UNIPHY1 149 
#define  ENCODER_ID_INTERNAL_UNIPHY2 148 
#define  ENCODER_ID_INTERNAL_UNIPHY3 147 
#define  ENCODER_ID_INTERNAL_VIRTUAL 146 
#define  ENCODER_ID_INTERNAL_WIRELESS 145 
#define  ENCODER_ID_UNKNOWN 144 
 int ENCODER_OBJECT_ID_HDMI_INTERNAL ; 
 int ENCODER_OBJECT_ID_INTERNAL_DAC1 ; 
 int ENCODER_OBJECT_ID_INTERNAL_DAC2 ; 
 int ENCODER_OBJECT_ID_INTERNAL_DDI ; 
 int ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC1 ; 
 int ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC2 ; 
 int ENCODER_OBJECT_ID_INTERNAL_KLDSCP_LVTMA ; 
 int ENCODER_OBJECT_ID_INTERNAL_KLDSCP_TMDS1 ; 
 int ENCODER_OBJECT_ID_INTERNAL_LVDS ; 
 int ENCODER_OBJECT_ID_INTERNAL_LVTM1 ; 
 int ENCODER_OBJECT_ID_INTERNAL_TMDS1 ; 
 int ENCODER_OBJECT_ID_INTERNAL_TMDS2 ; 
 int ENCODER_OBJECT_ID_INTERNAL_UNIPHY ; 
 int ENCODER_OBJECT_ID_INTERNAL_UNIPHY1 ; 
 int ENCODER_OBJECT_ID_INTERNAL_UNIPHY2 ; 
 int ENCODER_OBJECT_ID_INTERNAL_UNIPHY3 ; 
 int ENCODER_OBJECT_ID_INTERNAL_VCE ; 
 int ENCODER_OBJECT_ID_MVPU_FPGA ; 
 int ENCODER_OBJECT_ID_NONE ; 
 int ENCODER_OBJECT_ID_NUTMEG ; 
 int ENCODER_OBJECT_ID_TRAVIS ; 
 int /*<<< orphan*/  ENCODER_REFCLK_SRC_EXTCLK ; 
 int /*<<< orphan*/  ENCODER_REFCLK_SRC_INVALID ; 
 int /*<<< orphan*/  ENCODER_REFCLK_SRC_P1PLL ; 
 int /*<<< orphan*/  ENCODER_REFCLK_SRC_P2PLL ; 
#define  SIGNAL_TYPE_DISPLAY_PORT 143 
#define  SIGNAL_TYPE_DISPLAY_PORT_MST 142 
#define  SIGNAL_TYPE_DVI_DUAL_LINK 141 
#define  SIGNAL_TYPE_DVI_SINGLE_LINK 140 
#define  SIGNAL_TYPE_EDP 139 
#define  SIGNAL_TYPE_HDMI_TYPE_A 138 
#define  SIGNAL_TYPE_LVDS 137 
#define  SIGNAL_TYPE_RGB 136 
#define  SIGNAL_TYPE_VIRTUAL 135 
#define  TRANSMITTER_TRAVIS_LCD 134 
#define  TRANSMITTER_UNIPHY_A 133 
#define  TRANSMITTER_UNIPHY_B 132 
#define  TRANSMITTER_UNIPHY_C 131 
#define  TRANSMITTER_UNIPHY_D 130 
#define  TRANSMITTER_UNIPHY_E 129 
#define  TRANSMITTER_UNIPHY_F 128 
 struct command_table_helper* dal_cmd_tbl_helper_dce110_get_table () ; 
 struct command_table_helper* dal_cmd_tbl_helper_dce112_get_table2 () ; 
 struct command_table_helper* dal_cmd_tbl_helper_dce80_get_table () ; 

bool dal_bios_parser_init_cmd_tbl_helper2(
	const struct command_table_helper **h,
	enum dce_version dce)
{
	switch (dce) {
	case DCE_VERSION_8_0:
	case DCE_VERSION_8_1:
	case DCE_VERSION_8_3:
		*h = dal_cmd_tbl_helper_dce80_get_table();
		return true;

	case DCE_VERSION_10_0:
		*h = dal_cmd_tbl_helper_dce110_get_table();
		return true;

	case DCE_VERSION_11_0:
		*h = dal_cmd_tbl_helper_dce110_get_table();
		return true;

	case DCE_VERSION_11_2:
	case DCE_VERSION_11_22:
		*h = dal_cmd_tbl_helper_dce112_get_table2();
		return true;
#if defined(CONFIG_DRM_AMD_DC_DCN1_0)
	case DCN_VERSION_1_0:
		*h = dal_cmd_tbl_helper_dce112_get_table2();
		return true;
#endif

	case DCE_VERSION_12_0:
		*h = dal_cmd_tbl_helper_dce112_get_table2();
		return true;

	default:
		/* Unsupported DCE */
		BREAK_TO_DEBUGGER();
		return false;
	}
}

bool dal_cmd_table_helper_controller_id_to_atom2(
	enum controller_id id,
	uint8_t *atom_id)
{
	if (atom_id == NULL) {
		BREAK_TO_DEBUGGER();
		return false;
	}

	switch (id) {
	case CONTROLLER_ID_D0:
		*atom_id = ATOM_CRTC1;
		return true;
	case CONTROLLER_ID_D1:
		*atom_id = ATOM_CRTC2;
		return true;
	case CONTROLLER_ID_D2:
		*atom_id = ATOM_CRTC3;
		return true;
	case CONTROLLER_ID_D3:
		*atom_id = ATOM_CRTC4;
		return true;
	case CONTROLLER_ID_D4:
		*atom_id = ATOM_CRTC5;
		return true;
	case CONTROLLER_ID_D5:
		*atom_id = ATOM_CRTC6;
		return true;
	/* TODO :case CONTROLLER_ID_UNDERLAY0:
		*atom_id = ATOM_UNDERLAY_PIPE0;
		return true;
	*/
	case CONTROLLER_ID_UNDEFINED:
		*atom_id = ATOM_CRTC_INVALID;
		return true;
	default:
		/* Wrong controller id */
		BREAK_TO_DEBUGGER();
		return false;
	}
}

uint8_t dal_cmd_table_helper_transmitter_bp_to_atom2(
	enum transmitter t)
{
	switch (t) {
	case TRANSMITTER_UNIPHY_A:
	case TRANSMITTER_UNIPHY_B:
	case TRANSMITTER_TRAVIS_LCD:
		return 0;
	case TRANSMITTER_UNIPHY_C:
	case TRANSMITTER_UNIPHY_D:
		return 1;
	case TRANSMITTER_UNIPHY_E:
	case TRANSMITTER_UNIPHY_F:
		return 2;
	default:
		/* Invalid Transmitter Type! */
		BREAK_TO_DEBUGGER();
		return 0;
	}
}

uint32_t dal_cmd_table_helper_encoder_mode_bp_to_atom2(
	enum signal_type s,
	bool enable_dp_audio)
{
	switch (s) {
	case SIGNAL_TYPE_DVI_SINGLE_LINK:
	case SIGNAL_TYPE_DVI_DUAL_LINK:
		return ATOM_ENCODER_MODE_DVI;
	case SIGNAL_TYPE_HDMI_TYPE_A:
		return ATOM_ENCODER_MODE_HDMI;
	case SIGNAL_TYPE_LVDS:
		return ATOM_ENCODER_MODE_LVDS;
	case SIGNAL_TYPE_EDP:
	case SIGNAL_TYPE_DISPLAY_PORT_MST:
	case SIGNAL_TYPE_DISPLAY_PORT:
	case SIGNAL_TYPE_VIRTUAL:
		if (enable_dp_audio)
			return ATOM_ENCODER_MODE_DP_AUDIO;
		else
			return ATOM_ENCODER_MODE_DP;
	case SIGNAL_TYPE_RGB:
		return ATOM_ENCODER_MODE_CRT;
	default:
		return ATOM_ENCODER_MODE_CRT;
	}
}

bool dal_cmd_table_helper_clock_source_id_to_ref_clk_src2(
	enum clock_source_id id,
	uint32_t *ref_clk_src_id)
{
	if (ref_clk_src_id == NULL) {
		BREAK_TO_DEBUGGER();
		return false;
	}

	switch (id) {
	case CLOCK_SOURCE_ID_PLL1:
		*ref_clk_src_id = ENCODER_REFCLK_SRC_P1PLL;
		return true;
	case CLOCK_SOURCE_ID_PLL2:
		*ref_clk_src_id = ENCODER_REFCLK_SRC_P2PLL;
		return true;
	/*TODO:case CLOCK_SOURCE_ID_DCPLL:
		*ref_clk_src_id = ENCODER_REFCLK_SRC_DCPLL;
		return true;
	*/
	case CLOCK_SOURCE_ID_EXTERNAL:
		*ref_clk_src_id = ENCODER_REFCLK_SRC_EXTCLK;
		return true;
	case CLOCK_SOURCE_ID_UNDEFINED:
		*ref_clk_src_id = ENCODER_REFCLK_SRC_INVALID;
		return true;
	default:
		/* Unsupported clock source id */
		BREAK_TO_DEBUGGER();
		return false;
	}
}

uint8_t dal_cmd_table_helper_encoder_id_to_atom2(
	enum encoder_id id)
{
	switch (id) {
	case ENCODER_ID_INTERNAL_LVDS:
		return ENCODER_OBJECT_ID_INTERNAL_LVDS;
	case ENCODER_ID_INTERNAL_TMDS1:
		return ENCODER_OBJECT_ID_INTERNAL_TMDS1;
	case ENCODER_ID_INTERNAL_TMDS2:
		return ENCODER_OBJECT_ID_INTERNAL_TMDS2;
	case ENCODER_ID_INTERNAL_DAC1:
		return ENCODER_OBJECT_ID_INTERNAL_DAC1;
	case ENCODER_ID_INTERNAL_DAC2:
		return ENCODER_OBJECT_ID_INTERNAL_DAC2;
	case ENCODER_ID_INTERNAL_LVTM1:
		return ENCODER_OBJECT_ID_INTERNAL_LVTM1;
	case ENCODER_ID_INTERNAL_HDMI:
		return ENCODER_OBJECT_ID_HDMI_INTERNAL;
	case ENCODER_ID_EXTERNAL_TRAVIS:
		return ENCODER_OBJECT_ID_TRAVIS;
	case ENCODER_ID_EXTERNAL_NUTMEG:
		return ENCODER_OBJECT_ID_NUTMEG;
	case ENCODER_ID_INTERNAL_KLDSCP_TMDS1:
		return ENCODER_OBJECT_ID_INTERNAL_KLDSCP_TMDS1;
	case ENCODER_ID_INTERNAL_KLDSCP_DAC1:
		return ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC1;
	case ENCODER_ID_INTERNAL_KLDSCP_DAC2:
		return ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC2;
	case ENCODER_ID_EXTERNAL_MVPU_FPGA:
		return ENCODER_OBJECT_ID_MVPU_FPGA;
	case ENCODER_ID_INTERNAL_DDI:
		return ENCODER_OBJECT_ID_INTERNAL_DDI;
	case ENCODER_ID_INTERNAL_UNIPHY:
		return ENCODER_OBJECT_ID_INTERNAL_UNIPHY;
	case ENCODER_ID_INTERNAL_KLDSCP_LVTMA:
		return ENCODER_OBJECT_ID_INTERNAL_KLDSCP_LVTMA;
	case ENCODER_ID_INTERNAL_UNIPHY1:
		return ENCODER_OBJECT_ID_INTERNAL_UNIPHY1;
	case ENCODER_ID_INTERNAL_UNIPHY2:
		return ENCODER_OBJECT_ID_INTERNAL_UNIPHY2;
	case ENCODER_ID_INTERNAL_UNIPHY3:
		return ENCODER_OBJECT_ID_INTERNAL_UNIPHY3;
	case ENCODER_ID_INTERNAL_WIRELESS:
		return ENCODER_OBJECT_ID_INTERNAL_VCE;
	case ENCODER_ID_INTERNAL_VIRTUAL:
		return ENCODER_OBJECT_ID_NONE;
	case ENCODER_ID_UNKNOWN:
		return ENCODER_OBJECT_ID_NONE;
	default:
		/* Invalid encoder id */
		BREAK_TO_DEBUGGER();
		return ENCODER_OBJECT_ID_NONE;
	}
}

