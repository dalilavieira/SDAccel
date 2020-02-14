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
typedef  enum hpd_source_id { ____Placeholder_hpd_source_id } hpd_source_id ;
typedef  enum engine_id { ____Placeholder_engine_id } engine_id ;
typedef  enum clock_source_id { ____Placeholder_clock_source_id } clock_source_id ;
typedef  enum bp_pipe_control_action { ____Placeholder_bp_pipe_control_action } bp_pipe_control_action ;
typedef  enum bp_encoder_control_action { ____Placeholder_bp_encoder_control_action } bp_encoder_control_action ;

/* Variables and functions */
 int /*<<< orphan*/  ASIC_INT_DAC1_ENCODER_ID ; 
 int /*<<< orphan*/  ASIC_INT_DIG1_ENCODER_ID ; 
 int /*<<< orphan*/  ASIC_INT_DIG2_ENCODER_ID ; 
 int /*<<< orphan*/  ASIC_INT_DIG3_ENCODER_ID ; 
 int /*<<< orphan*/  ASIC_INT_DIG4_ENCODER_ID ; 
 int /*<<< orphan*/  ASIC_INT_DIG5_ENCODER_ID ; 
 int /*<<< orphan*/  ASIC_INT_DIG6_ENCODER_ID ; 
 int /*<<< orphan*/  ASIC_INT_DIG7_ENCODER_ID ; 
#define  ASIC_PIPE_DISABLE 172 
#define  ASIC_PIPE_ENABLE 171 
#define  ASIC_PIPE_INIT 170 
 int /*<<< orphan*/  ASSERT_CRITICAL (int) ; 
 int ATOM_DISABLE ; 
 int ATOM_ENABLE ; 
 int ATOM_ENCODER_CMD_SETUP ; 
 int ATOM_ENCODER_INIT ; 
 int /*<<< orphan*/  ATOM_EXT_PLL1 ; 
 int ATOM_INIT ; 
 int ATOM_PHY_ID_UNIPHYA ; 
 int ATOM_PHY_ID_UNIPHYB ; 
 int ATOM_PHY_ID_UNIPHYC ; 
 int ATOM_PHY_ID_UNIPHYD ; 
 int ATOM_PHY_ID_UNIPHYE ; 
 int ATOM_PHY_ID_UNIPHYF ; 
 int ATOM_PHY_ID_UNIPHYG ; 
 int /*<<< orphan*/  ATOM_PPLL0 ; 
 int /*<<< orphan*/  ATOM_PPLL1 ; 
 int /*<<< orphan*/  ATOM_PPLL2 ; 
 int /*<<< orphan*/  ATOM_PPLL_INVALID ; 
 int ATOM_TRANMSITTER_V5__DIGA_SEL ; 
 int ATOM_TRANMSITTER_V5__DIGB_SEL ; 
 int ATOM_TRANMSITTER_V5__DIGC_SEL ; 
 int ATOM_TRANMSITTER_V5__DIGD_SEL ; 
 int ATOM_TRANMSITTER_V5__DIGE_SEL ; 
 int ATOM_TRANMSITTER_V5__DIGF_SEL ; 
 int ATOM_TRANMSITTER_V5__DIGG_SEL ; 
 int ATOM_TRANSMITTER_CONFIG_V5_HPD1_SEL ; 
 int ATOM_TRANSMITTER_CONFIG_V5_HPD2_SEL ; 
 int ATOM_TRANSMITTER_CONFIG_V5_HPD3_SEL ; 
 int ATOM_TRANSMITTER_CONFIG_V5_HPD4_SEL ; 
 int ATOM_TRANSMITTER_CONFIG_V5_HPD5_SEL ; 
 int ATOM_TRANSMITTER_CONFIG_V5_HPD6_SEL ; 
 int ATOM_TRANSMITTER_CONFIG_V5_P0PLL ; 
 int ATOM_TRANSMITTER_CONFIG_V5_P1PLL ; 
 int ATOM_TRANSMITTER_CONFIG_V5_P2PLL ; 
 int ATOM_TRANSMITTER_CONFIG_V5_REFCLK_SRC_EXT ; 
 int ATOM_TRANSMITTER_DIGMODE_V5_DP ; 
 int ATOM_TRANSMITTER_DIGMODE_V5_DP_MST ; 
 int ATOM_TRANSMITTER_DIGMODE_V5_DVI ; 
 int ATOM_TRANSMITTER_DIGMODE_V5_HDMI ; 
 int ATOM_TRANSMITTER_DIGMODE_V5_LVDS ; 
 int /*<<< orphan*/  BREAK_TO_DEBUGGER () ; 
#define  CLOCK_SOURCE_ID_DFS 169 
#define  CLOCK_SOURCE_ID_DP_DTO 168 
#define  CLOCK_SOURCE_ID_EXTERNAL 167 
#define  CLOCK_SOURCE_ID_PLL0 166 
#define  CLOCK_SOURCE_ID_PLL1 165 
#define  CLOCK_SOURCE_ID_PLL2 164 
#define  CLOCK_SOURCE_ID_UNDEFINED 163 
#define  CLOCK_SOURCE_ID_VCE 162 
#define  ENCODER_CONTROL_DISABLE 161 
#define  ENCODER_CONTROL_ENABLE 160 
#define  ENCODER_CONTROL_INIT 159 
#define  ENCODER_CONTROL_SETUP 158 
#define  ENGINE_ID_DACA 157 
#define  ENGINE_ID_DIGA 156 
#define  ENGINE_ID_DIGB 155 
#define  ENGINE_ID_DIGC 154 
#define  ENGINE_ID_DIGD 153 
#define  ENGINE_ID_DIGE 152 
#define  ENGINE_ID_DIGF 151 
#define  ENGINE_ID_DIGG 150 
#define  ENGINE_ID_UNKNOWN 149 
#define  HPD_SOURCEID1 148 
#define  HPD_SOURCEID2 147 
#define  HPD_SOURCEID3 146 
#define  HPD_SOURCEID4 145 
#define  HPD_SOURCEID5 144 
#define  HPD_SOURCEID6 143 
#define  HPD_SOURCEID_UNKNOWN 142 
#define  SIGNAL_TYPE_DISPLAY_PORT 141 
#define  SIGNAL_TYPE_DISPLAY_PORT_MST 140 
#define  SIGNAL_TYPE_DVI_DUAL_LINK 139 
#define  SIGNAL_TYPE_DVI_SINGLE_LINK 138 
#define  SIGNAL_TYPE_EDP 137 
#define  SIGNAL_TYPE_HDMI_TYPE_A 136 
#define  SIGNAL_TYPE_LVDS 135 
#define  TRANSMITTER_UNIPHY_A 134 
#define  TRANSMITTER_UNIPHY_B 133 
#define  TRANSMITTER_UNIPHY_C 132 
#define  TRANSMITTER_UNIPHY_D 131 
#define  TRANSMITTER_UNIPHY_E 130 
#define  TRANSMITTER_UNIPHY_F 129 
#define  TRANSMITTER_UNIPHY_G 128 
 struct command_table_helper const command_table_helper_funcs ; 

__attribute__((used)) static uint8_t phy_id_to_atom(enum transmitter t)
{
	uint8_t atom_phy_id;

	switch (t) {
	case TRANSMITTER_UNIPHY_A:
		atom_phy_id = ATOM_PHY_ID_UNIPHYA;
		break;
	case TRANSMITTER_UNIPHY_B:
		atom_phy_id = ATOM_PHY_ID_UNIPHYB;
		break;
	case TRANSMITTER_UNIPHY_C:
		atom_phy_id = ATOM_PHY_ID_UNIPHYC;
		break;
	case TRANSMITTER_UNIPHY_D:
		atom_phy_id = ATOM_PHY_ID_UNIPHYD;
		break;
	case TRANSMITTER_UNIPHY_E:
		atom_phy_id = ATOM_PHY_ID_UNIPHYE;
		break;
	case TRANSMITTER_UNIPHY_F:
		atom_phy_id = ATOM_PHY_ID_UNIPHYF;
		break;
	case TRANSMITTER_UNIPHY_G:
		atom_phy_id = ATOM_PHY_ID_UNIPHYG;
		break;
	default:
		atom_phy_id = ATOM_PHY_ID_UNIPHYA;
		break;
	}
	return atom_phy_id;
}

__attribute__((used)) static uint8_t signal_type_to_atom_dig_mode(enum signal_type s)
{
	uint8_t atom_dig_mode = ATOM_TRANSMITTER_DIGMODE_V5_DP;

	switch (s) {
	case SIGNAL_TYPE_DISPLAY_PORT:
	case SIGNAL_TYPE_EDP:
		atom_dig_mode = ATOM_TRANSMITTER_DIGMODE_V5_DP;
		break;
	case SIGNAL_TYPE_LVDS:
		atom_dig_mode = ATOM_TRANSMITTER_DIGMODE_V5_LVDS;
		break;
	case SIGNAL_TYPE_DVI_SINGLE_LINK:
	case SIGNAL_TYPE_DVI_DUAL_LINK:
		atom_dig_mode = ATOM_TRANSMITTER_DIGMODE_V5_DVI;
		break;
	case SIGNAL_TYPE_HDMI_TYPE_A:
		atom_dig_mode = ATOM_TRANSMITTER_DIGMODE_V5_HDMI;
		break;
	case SIGNAL_TYPE_DISPLAY_PORT_MST:
		atom_dig_mode = ATOM_TRANSMITTER_DIGMODE_V5_DP_MST;
		break;
	default:
		atom_dig_mode = ATOM_TRANSMITTER_DIGMODE_V5_DVI;
		break;
	}

	return atom_dig_mode;
}

__attribute__((used)) static uint8_t clock_source_id_to_atom_phy_clk_src_id(
		enum clock_source_id id)
{
	uint8_t atom_phy_clk_src_id = 0;

	switch (id) {
	case CLOCK_SOURCE_ID_PLL0:
		atom_phy_clk_src_id = ATOM_TRANSMITTER_CONFIG_V5_P0PLL;
		break;
	case CLOCK_SOURCE_ID_PLL1:
		atom_phy_clk_src_id = ATOM_TRANSMITTER_CONFIG_V5_P1PLL;
		break;
	case CLOCK_SOURCE_ID_PLL2:
		atom_phy_clk_src_id = ATOM_TRANSMITTER_CONFIG_V5_P2PLL;
		break;
	case CLOCK_SOURCE_ID_EXTERNAL:
		atom_phy_clk_src_id = ATOM_TRANSMITTER_CONFIG_V5_REFCLK_SRC_EXT;
		break;
	default:
		atom_phy_clk_src_id = ATOM_TRANSMITTER_CONFIG_V5_P1PLL;
		break;
	}

	return atom_phy_clk_src_id >> 2;
}

__attribute__((used)) static uint8_t hpd_sel_to_atom(enum hpd_source_id id)
{
	uint8_t atom_hpd_sel = 0;

	switch (id) {
	case HPD_SOURCEID1:
		atom_hpd_sel = ATOM_TRANSMITTER_CONFIG_V5_HPD1_SEL;
		break;
	case HPD_SOURCEID2:
		atom_hpd_sel = ATOM_TRANSMITTER_CONFIG_V5_HPD2_SEL;
		break;
	case HPD_SOURCEID3:
		atom_hpd_sel = ATOM_TRANSMITTER_CONFIG_V5_HPD3_SEL;
		break;
	case HPD_SOURCEID4:
		atom_hpd_sel = ATOM_TRANSMITTER_CONFIG_V5_HPD4_SEL;
		break;
	case HPD_SOURCEID5:
		atom_hpd_sel = ATOM_TRANSMITTER_CONFIG_V5_HPD5_SEL;
		break;
	case HPD_SOURCEID6:
		atom_hpd_sel = ATOM_TRANSMITTER_CONFIG_V5_HPD6_SEL;
		break;
	case HPD_SOURCEID_UNKNOWN:
	default:
		atom_hpd_sel = 0;
		break;
	}
	return atom_hpd_sel >> 4;
}

__attribute__((used)) static uint8_t dig_encoder_sel_to_atom(enum engine_id id)
{
	uint8_t atom_dig_encoder_sel = 0;

	switch (id) {
	case ENGINE_ID_DIGA:
		atom_dig_encoder_sel = ATOM_TRANMSITTER_V5__DIGA_SEL;
		break;
	case ENGINE_ID_DIGB:
		atom_dig_encoder_sel = ATOM_TRANMSITTER_V5__DIGB_SEL;
		break;
	case ENGINE_ID_DIGC:
		atom_dig_encoder_sel = ATOM_TRANMSITTER_V5__DIGC_SEL;
		break;
	case ENGINE_ID_DIGD:
		atom_dig_encoder_sel = ATOM_TRANMSITTER_V5__DIGD_SEL;
		break;
	case ENGINE_ID_DIGE:
		atom_dig_encoder_sel = ATOM_TRANMSITTER_V5__DIGE_SEL;
		break;
	case ENGINE_ID_DIGF:
		atom_dig_encoder_sel = ATOM_TRANMSITTER_V5__DIGF_SEL;
		break;
	case ENGINE_ID_DIGG:
		atom_dig_encoder_sel = ATOM_TRANMSITTER_V5__DIGG_SEL;
		break;
	case ENGINE_ID_UNKNOWN:
		 /* No DIG_FRONT is associated to DIG_BACKEND */
		atom_dig_encoder_sel = 0;
		break;
	default:
		atom_dig_encoder_sel = ATOM_TRANMSITTER_V5__DIGA_SEL;
		break;
	}

	return 0;
}

__attribute__((used)) static bool clock_source_id_to_atom(
	enum clock_source_id id,
	uint32_t *atom_pll_id)
{
	bool result = true;

	if (atom_pll_id != NULL)
		switch (id) {
		case CLOCK_SOURCE_ID_PLL0:
			*atom_pll_id = ATOM_PPLL0;
			break;
		case CLOCK_SOURCE_ID_PLL1:
			*atom_pll_id = ATOM_PPLL1;
			break;
		case CLOCK_SOURCE_ID_PLL2:
			*atom_pll_id = ATOM_PPLL2;
			break;
		case CLOCK_SOURCE_ID_EXTERNAL:
			*atom_pll_id = ATOM_PPLL_INVALID;
			break;
		case CLOCK_SOURCE_ID_DFS:
			*atom_pll_id = ATOM_EXT_PLL1;
			break;
		case CLOCK_SOURCE_ID_VCE:
			/* for VCE encoding,
			 * we need to pass in ATOM_PPLL_INVALID
			 */
			*atom_pll_id = ATOM_PPLL_INVALID;
			break;
		case CLOCK_SOURCE_ID_DP_DTO:
			/* When programming DP DTO PLL ID should be invalid */
			*atom_pll_id = ATOM_PPLL_INVALID;
			break;
		case CLOCK_SOURCE_ID_UNDEFINED:
			/* Should not happen */
			*atom_pll_id = ATOM_PPLL_INVALID;
			result = false;
			break;
		default:
			result = false;
			break;
		}

	return result;
}

__attribute__((used)) static bool engine_bp_to_atom(enum engine_id id, uint32_t *atom_engine_id)
{
	bool result = false;

	if (atom_engine_id != NULL)
		switch (id) {
		case ENGINE_ID_DIGA:
			*atom_engine_id = ASIC_INT_DIG1_ENCODER_ID;
			result = true;
			break;
		case ENGINE_ID_DIGB:
			*atom_engine_id = ASIC_INT_DIG2_ENCODER_ID;
			result = true;
			break;
		case ENGINE_ID_DIGC:
			*atom_engine_id = ASIC_INT_DIG3_ENCODER_ID;
			result = true;
			break;
		case ENGINE_ID_DIGD:
			*atom_engine_id = ASIC_INT_DIG4_ENCODER_ID;
			result = true;
			break;
		case ENGINE_ID_DIGE:
			*atom_engine_id = ASIC_INT_DIG5_ENCODER_ID;
			result = true;
			break;
		case ENGINE_ID_DIGF:
			*atom_engine_id = ASIC_INT_DIG6_ENCODER_ID;
			result = true;
			break;
		case ENGINE_ID_DIGG:
			*atom_engine_id = ASIC_INT_DIG7_ENCODER_ID;
			result = true;
			break;
		case ENGINE_ID_DACA:
			*atom_engine_id = ASIC_INT_DAC1_ENCODER_ID;
			result = true;
			break;
		default:
			break;
		}

	return result;
}

__attribute__((used)) static uint8_t encoder_action_to_atom(enum bp_encoder_control_action action)
{
	uint8_t atom_action = 0;

	switch (action) {
	case ENCODER_CONTROL_ENABLE:
		atom_action = ATOM_ENABLE;
		break;
	case ENCODER_CONTROL_DISABLE:
		atom_action = ATOM_DISABLE;
		break;
	case ENCODER_CONTROL_SETUP:
		atom_action = ATOM_ENCODER_CMD_SETUP;
		break;
	case ENCODER_CONTROL_INIT:
		atom_action = ATOM_ENCODER_INIT;
		break;
	default:
		BREAK_TO_DEBUGGER(); /* Unhandle action in driver.!! */
		break;
	}

	return atom_action;
}

__attribute__((used)) static uint8_t disp_power_gating_action_to_atom(
	enum bp_pipe_control_action action)
{
	uint8_t atom_pipe_action = 0;

	switch (action) {
	case ASIC_PIPE_DISABLE:
		atom_pipe_action = ATOM_DISABLE;
		break;
	case ASIC_PIPE_ENABLE:
		atom_pipe_action = ATOM_ENABLE;
		break;
	case ASIC_PIPE_INIT:
		atom_pipe_action = ATOM_INIT;
		break;
	default:
		ASSERT_CRITICAL(false); /* Unhandle action in driver! */
		break;
	}

	return atom_pipe_action;
}

const struct command_table_helper *dal_cmd_tbl_helper_dce110_get_table(void)
{
	return &command_table_helper_funcs;
}

