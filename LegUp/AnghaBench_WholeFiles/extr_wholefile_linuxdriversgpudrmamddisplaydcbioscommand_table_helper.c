#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  uint16_t ;
struct command_table_helper {scalar_t__ (* encoder_mode_bp_to_atom ) (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* encoder_action_to_atom ) (int /*<<< orphan*/ ) ;scalar_t__ (* transmitter_bp_to_atom ) (int const) ;} ;
struct bp_encoder_control {int const transmitter; int pixel_clock; scalar_t__ lanes_number; int /*<<< orphan*/  enable_dp_audio; int /*<<< orphan*/  signal; int /*<<< orphan*/  action; } ;
typedef  enum transmitter { ____Placeholder_transmitter } transmitter ;
typedef  enum signal_type { ____Placeholder_signal_type } signal_type ;
typedef  enum encoder_id { ____Placeholder_encoder_id } encoder_id ;
typedef  enum dce_version { ____Placeholder_dce_version } dce_version ;
typedef  enum controller_id { ____Placeholder_controller_id } controller_id ;
typedef  enum clock_source_id { ____Placeholder_clock_source_id } clock_source_id ;
struct TYPE_4__ {int ucLinkSel; int ucTransmitterSel; } ;
struct TYPE_5__ {int ucEncoderMode; int ucLaneNum; int /*<<< orphan*/  usPixelClock; int /*<<< orphan*/  ucAction; TYPE_1__ acConfig; } ;
typedef  TYPE_2__ DIG_ENCODER_CONTROL_PARAMETERS_V2 ;

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
 int ATOM_UNDERLAY_PIPE0 ; 
 int /*<<< orphan*/  BREAK_TO_DEBUGGER () ; 
#define  CLOCK_SOURCE_ID_DCPLL 184 
#define  CLOCK_SOURCE_ID_EXTERNAL 183 
#define  CLOCK_SOURCE_ID_PLL1 182 
#define  CLOCK_SOURCE_ID_PLL2 181 
#define  CLOCK_SOURCE_ID_UNDEFINED 180 
#define  CONTROLLER_ID_D0 179 
#define  CONTROLLER_ID_D1 178 
#define  CONTROLLER_ID_D2 177 
#define  CONTROLLER_ID_D3 176 
#define  CONTROLLER_ID_D4 175 
#define  CONTROLLER_ID_D5 174 
#define  CONTROLLER_ID_UNDEFINED 173 
#define  CONTROLLER_ID_UNDERLAY0 172 
#define  DCE_VERSION_10_0 171 
#define  DCE_VERSION_11_0 170 
#define  DCE_VERSION_11_2 169 
#define  DCE_VERSION_11_22 168 
#define  DCE_VERSION_8_0 167 
#define  DCE_VERSION_8_1 166 
#define  DCE_VERSION_8_3 165 
#define  ENCODER_ID_EXTERNAL_MVPU_FPGA 164 
#define  ENCODER_ID_EXTERNAL_NUTMEG 163 
#define  ENCODER_ID_EXTERNAL_TRAVIS 162 
#define  ENCODER_ID_INTERNAL_DAC1 161 
#define  ENCODER_ID_INTERNAL_DAC2 160 
#define  ENCODER_ID_INTERNAL_DDI 159 
#define  ENCODER_ID_INTERNAL_HDMI 158 
#define  ENCODER_ID_INTERNAL_KLDSCP_DAC1 157 
#define  ENCODER_ID_INTERNAL_KLDSCP_DAC2 156 
#define  ENCODER_ID_INTERNAL_KLDSCP_LVTMA 155 
#define  ENCODER_ID_INTERNAL_KLDSCP_TMDS1 154 
#define  ENCODER_ID_INTERNAL_LVDS 153 
#define  ENCODER_ID_INTERNAL_LVTM1 152 
#define  ENCODER_ID_INTERNAL_TMDS1 151 
#define  ENCODER_ID_INTERNAL_TMDS2 150 
#define  ENCODER_ID_INTERNAL_UNIPHY 149 
#define  ENCODER_ID_INTERNAL_UNIPHY1 148 
#define  ENCODER_ID_INTERNAL_UNIPHY2 147 
#define  ENCODER_ID_INTERNAL_UNIPHY3 146 
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
 int /*<<< orphan*/  ENCODER_REFCLK_SRC_DCPLL ; 
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
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 struct command_table_helper* dal_cmd_tbl_helper_dce110_get_table () ; 
 struct command_table_helper* dal_cmd_tbl_helper_dce112_get_table () ; 
 struct command_table_helper* dal_cmd_tbl_helper_dce80_get_table () ; 
 scalar_t__ stub1 (int const) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ) ; 
 scalar_t__ stub3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

bool dal_bios_parser_init_cmd_tbl_helper(
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
		*h = dal_cmd_tbl_helper_dce112_get_table();
		return true;

	default:
		/* Unsupported DCE */
		BREAK_TO_DEBUGGER();
		return false;
	}
}

bool dal_cmd_table_helper_controller_id_to_atom(
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
	case CONTROLLER_ID_UNDERLAY0:
		*atom_id = ATOM_UNDERLAY_PIPE0;
		return true;
	case CONTROLLER_ID_UNDEFINED:
		*atom_id = ATOM_CRTC_INVALID;
		return true;
	default:
		/* Wrong controller id */
		BREAK_TO_DEBUGGER();
		return false;
	}
}

uint8_t dal_cmd_table_helper_transmitter_bp_to_atom(
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

uint32_t dal_cmd_table_helper_encoder_mode_bp_to_atom(
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

void dal_cmd_table_helper_assign_control_parameter(
	const struct command_table_helper *h,
	struct bp_encoder_control *control,
	DIG_ENCODER_CONTROL_PARAMETERS_V2 *ctrl_param)
{
	/* there are three transmitter blocks, each one has two links 4-lanes
	 * each, A+B, C+D, E+F, Uniphy A, C and E are enumerated as link 0 in
	 * each transmitter block B, D and F as link 1, third transmitter block
	 * has non splitable links (UniphyE and UniphyF can not be configured
	 * separately to drive two different streams)
	 */
	if ((control->transmitter == TRANSMITTER_UNIPHY_B) ||
		(control->transmitter == TRANSMITTER_UNIPHY_D) ||
		(control->transmitter == TRANSMITTER_UNIPHY_F)) {
		/* Bit2: Link Select
		 * =0: PHY linkA/C/E
		 * =1: PHY linkB/D/F
		 */
		ctrl_param->acConfig.ucLinkSel = 1;
	}

	/* Bit[4:3]: Transmitter Selection
	 * =00: Digital Transmitter1 ( UNIPHY linkAB )
	 * =01: Digital Transmitter2 ( UNIPHY linkCD )
	 * =02: Digital Transmitter3 ( UNIPHY linkEF )
	 * =03: Reserved
	 */
	ctrl_param->acConfig.ucTransmitterSel =
		(uint8_t)(h->transmitter_bp_to_atom(control->transmitter));

	/* We need to convert from KHz units into 10KHz units */
	ctrl_param->ucAction = h->encoder_action_to_atom(control->action);
	ctrl_param->usPixelClock = cpu_to_le16((uint16_t)(control->pixel_clock / 10));
	ctrl_param->ucEncoderMode =
		(uint8_t)(h->encoder_mode_bp_to_atom(
			control->signal, control->enable_dp_audio));
	ctrl_param->ucLaneNum = (uint8_t)(control->lanes_number);
}

bool dal_cmd_table_helper_clock_source_id_to_ref_clk_src(
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
	case CLOCK_SOURCE_ID_DCPLL:
		*ref_clk_src_id = ENCODER_REFCLK_SRC_DCPLL;
		return true;
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

uint8_t dal_cmd_table_helper_encoder_id_to_atom(
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
	case ENCODER_ID_UNKNOWN:
		return ENCODER_OBJECT_ID_NONE;
	default:
		/* Invalid encoder id */
		BREAK_TO_DEBUGGER();
		return ENCODER_OBJECT_ID_NONE;
	}
}

