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
typedef  int uint32_t ;
struct graphics_object_id {int /*<<< orphan*/  member_0; } ;
typedef  enum object_type { ____Placeholder_object_type } object_type ;
typedef  enum object_enum_id { ____Placeholder_object_enum_id } object_enum_id ;
typedef  enum generic_id { ____Placeholder_generic_id } generic_id ;
typedef  enum encoder_id { ____Placeholder_encoder_id } encoder_id ;
typedef  enum connector_id { ____Placeholder_connector_id } connector_id ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int /*<<< orphan*/ ) ; 
 int CONNECTOR_ID_DISPLAY_PORT ; 
 int CONNECTOR_ID_DUAL_LINK_DVID ; 
 int CONNECTOR_ID_DUAL_LINK_DVII ; 
 int CONNECTOR_ID_EDP ; 
 int CONNECTOR_ID_HARDCODE_DVI ; 
 int CONNECTOR_ID_HDMI_TYPE_A ; 
 int CONNECTOR_ID_LVDS ; 
 int CONNECTOR_ID_MXM ; 
 int CONNECTOR_ID_PCIE ; 
 int CONNECTOR_ID_SINGLE_LINK_DVID ; 
 int CONNECTOR_ID_SINGLE_LINK_DVII ; 
 int CONNECTOR_ID_UNKNOWN ; 
 int CONNECTOR_ID_VGA ; 
#define  CONNECTOR_OBJECT_ID_DISPLAYPORT 177 
#define  CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_D 176 
#define  CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_I 175 
#define  CONNECTOR_OBJECT_ID_HARDCODE_DVI 174 
#define  CONNECTOR_OBJECT_ID_HDMI_TYPE_A 173 
#define  CONNECTOR_OBJECT_ID_LVDS 172 
#define  CONNECTOR_OBJECT_ID_MXM 171 
#define  CONNECTOR_OBJECT_ID_PCIE_CONNECTOR 170 
#define  CONNECTOR_OBJECT_ID_SINGLE_LINK_DVI_D 169 
#define  CONNECTOR_OBJECT_ID_SINGLE_LINK_DVI_I 168 
#define  CONNECTOR_OBJECT_ID_VGA 167 
#define  CONNECTOR_OBJECT_ID_eDP 166 
 int ENCODER_ID_EXTERNAL_MVPU_FPGA ; 
 int ENCODER_ID_EXTERNAL_NUTMEG ; 
 int ENCODER_ID_EXTERNAL_TRAVIS ; 
 int ENCODER_ID_INTERNAL_DAC1 ; 
 int ENCODER_ID_INTERNAL_DAC2 ; 
 int ENCODER_ID_INTERNAL_DDI ; 
 int ENCODER_ID_INTERNAL_HDMI ; 
 int ENCODER_ID_INTERNAL_KLDSCP_DAC1 ; 
 int ENCODER_ID_INTERNAL_KLDSCP_DAC2 ; 
 int ENCODER_ID_INTERNAL_KLDSCP_LVTMA ; 
 int ENCODER_ID_INTERNAL_KLDSCP_TMDS1 ; 
 int ENCODER_ID_INTERNAL_LVDS ; 
 int ENCODER_ID_INTERNAL_LVTM1 ; 
 int ENCODER_ID_INTERNAL_TMDS1 ; 
 int ENCODER_ID_INTERNAL_TMDS2 ; 
 int ENCODER_ID_INTERNAL_UNIPHY ; 
 int ENCODER_ID_INTERNAL_UNIPHY1 ; 
 int ENCODER_ID_INTERNAL_UNIPHY2 ; 
 int ENCODER_ID_INTERNAL_UNIPHY3 ; 
 int ENCODER_ID_UNKNOWN ; 
#define  ENCODER_OBJECT_ID_ALMOND 165 
#define  ENCODER_OBJECT_ID_HDMI_INTERNAL 164 
#define  ENCODER_OBJECT_ID_INTERNAL_DAC1 163 
#define  ENCODER_OBJECT_ID_INTERNAL_DAC2 162 
#define  ENCODER_OBJECT_ID_INTERNAL_DDI 161 
#define  ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC1 160 
#define  ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC2 159 
#define  ENCODER_OBJECT_ID_INTERNAL_KLDSCP_LVTMA 158 
#define  ENCODER_OBJECT_ID_INTERNAL_KLDSCP_TMDS1 157 
#define  ENCODER_OBJECT_ID_INTERNAL_LVDS 156 
#define  ENCODER_OBJECT_ID_INTERNAL_LVTM1 155 
#define  ENCODER_OBJECT_ID_INTERNAL_TMDS1 154 
#define  ENCODER_OBJECT_ID_INTERNAL_TMDS2 153 
#define  ENCODER_OBJECT_ID_INTERNAL_UNIPHY 152 
#define  ENCODER_OBJECT_ID_INTERNAL_UNIPHY1 151 
#define  ENCODER_OBJECT_ID_INTERNAL_UNIPHY2 150 
#define  ENCODER_OBJECT_ID_INTERNAL_UNIPHY3 149 
#define  ENCODER_OBJECT_ID_MVPU_FPGA 148 
#define  ENCODER_OBJECT_ID_TRAVIS 147 
 int ENUM_ID_1 ; 
 int ENUM_ID_2 ; 
 int ENUM_ID_3 ; 
 int ENUM_ID_4 ; 
 int ENUM_ID_5 ; 
 int ENUM_ID_6 ; 
 int ENUM_ID_7 ; 
 int ENUM_ID_MASK ; 
 int ENUM_ID_SHIFT ; 
 int ENUM_ID_UNKNOWN ; 
 int GENERIC_ID_GLSYNC ; 
 int GENERIC_ID_MXM_OPM ; 
 int GENERIC_ID_STEREO ; 
 int GENERIC_ID_UNKNOWN ; 
#define  GENERIC_OBJECT_ID_GLSYNC 146 
#define  GENERIC_OBJECT_ID_MXM_OPM 145 
#define  GENERIC_OBJECT_ID_STEREO_PIN 144 
#define  GRAPH_OBJECT_ENUM_ID1 143 
#define  GRAPH_OBJECT_ENUM_ID2 142 
#define  GRAPH_OBJECT_ENUM_ID3 141 
#define  GRAPH_OBJECT_ENUM_ID4 140 
#define  GRAPH_OBJECT_ENUM_ID5 139 
#define  GRAPH_OBJECT_ENUM_ID6 138 
#define  GRAPH_OBJECT_ENUM_ID7 137 
#define  GRAPH_OBJECT_TYPE_CONNECTOR 136 
#define  GRAPH_OBJECT_TYPE_ENCODER 135 
#define  GRAPH_OBJECT_TYPE_GENERIC 134 
#define  GRAPH_OBJECT_TYPE_GPU 133 
#define  GRAPH_OBJECT_TYPE_ROUTER 132 
 int OBJECT_ID_MASK ; 
 int OBJECT_ID_SHIFT ; 
#define  OBJECT_TYPE_CONNECTOR 131 
#define  OBJECT_TYPE_ENCODER 130 
#define  OBJECT_TYPE_GENERIC 129 
#define  OBJECT_TYPE_GPU 128 
 int OBJECT_TYPE_MASK ; 
 int OBJECT_TYPE_ROUTER ; 
 int OBJECT_TYPE_SHIFT ; 
 int OBJECT_TYPE_UNKNOWN ; 
 struct graphics_object_id dal_graphics_object_id_init (int,int,int) ; 

__attribute__((used)) static enum object_type object_type_from_bios_object_id(uint32_t bios_object_id)
{
	uint32_t bios_object_type = (bios_object_id & OBJECT_TYPE_MASK)
				>> OBJECT_TYPE_SHIFT;
	enum object_type object_type;

	switch (bios_object_type) {
	case GRAPH_OBJECT_TYPE_GPU:
		object_type = OBJECT_TYPE_GPU;
		break;
	case GRAPH_OBJECT_TYPE_ENCODER:
		object_type = OBJECT_TYPE_ENCODER;
		break;
	case GRAPH_OBJECT_TYPE_CONNECTOR:
		object_type = OBJECT_TYPE_CONNECTOR;
		break;
	case GRAPH_OBJECT_TYPE_ROUTER:
		object_type = OBJECT_TYPE_ROUTER;
		break;
	case GRAPH_OBJECT_TYPE_GENERIC:
		object_type = OBJECT_TYPE_GENERIC;
		break;
	default:
		object_type = OBJECT_TYPE_UNKNOWN;
		break;
	}

	return object_type;
}

__attribute__((used)) static enum object_enum_id enum_id_from_bios_object_id(uint32_t bios_object_id)
{
	uint32_t bios_enum_id =
			(bios_object_id & ENUM_ID_MASK) >> ENUM_ID_SHIFT;
	enum object_enum_id id;

	switch (bios_enum_id) {
	case GRAPH_OBJECT_ENUM_ID1:
		id = ENUM_ID_1;
		break;
	case GRAPH_OBJECT_ENUM_ID2:
		id = ENUM_ID_2;
		break;
	case GRAPH_OBJECT_ENUM_ID3:
		id = ENUM_ID_3;
		break;
	case GRAPH_OBJECT_ENUM_ID4:
		id = ENUM_ID_4;
		break;
	case GRAPH_OBJECT_ENUM_ID5:
		id = ENUM_ID_5;
		break;
	case GRAPH_OBJECT_ENUM_ID6:
		id = ENUM_ID_6;
		break;
	case GRAPH_OBJECT_ENUM_ID7:
		id = ENUM_ID_7;
		break;
	default:
		id = ENUM_ID_UNKNOWN;
		break;
	}

	return id;
}

__attribute__((used)) static uint32_t gpu_id_from_bios_object_id(uint32_t bios_object_id)
{
	return (bios_object_id & OBJECT_ID_MASK) >> OBJECT_ID_SHIFT;
}

__attribute__((used)) static enum encoder_id encoder_id_from_bios_object_id(uint32_t bios_object_id)
{
	uint32_t bios_encoder_id = gpu_id_from_bios_object_id(bios_object_id);
	enum encoder_id id;

	switch (bios_encoder_id) {
	case ENCODER_OBJECT_ID_INTERNAL_LVDS:
		id = ENCODER_ID_INTERNAL_LVDS;
		break;
	case ENCODER_OBJECT_ID_INTERNAL_TMDS1:
		id = ENCODER_ID_INTERNAL_TMDS1;
		break;
	case ENCODER_OBJECT_ID_INTERNAL_TMDS2:
		id = ENCODER_ID_INTERNAL_TMDS2;
		break;
	case ENCODER_OBJECT_ID_INTERNAL_DAC1:
		id = ENCODER_ID_INTERNAL_DAC1;
		break;
	case ENCODER_OBJECT_ID_INTERNAL_DAC2:
		id = ENCODER_ID_INTERNAL_DAC2;
		break;
	case ENCODER_OBJECT_ID_INTERNAL_LVTM1:
		id = ENCODER_ID_INTERNAL_LVTM1;
		break;
	case ENCODER_OBJECT_ID_HDMI_INTERNAL:
		id = ENCODER_ID_INTERNAL_HDMI;
		break;
	case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_TMDS1:
		id = ENCODER_ID_INTERNAL_KLDSCP_TMDS1;
		break;
	case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC1:
		id = ENCODER_ID_INTERNAL_KLDSCP_DAC1;
		break;
	case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_DAC2:
		id = ENCODER_ID_INTERNAL_KLDSCP_DAC2;
		break;
	case ENCODER_OBJECT_ID_MVPU_FPGA:
		id = ENCODER_ID_EXTERNAL_MVPU_FPGA;
		break;
	case ENCODER_OBJECT_ID_INTERNAL_DDI:
		id = ENCODER_ID_INTERNAL_DDI;
		break;
	case ENCODER_OBJECT_ID_INTERNAL_UNIPHY:
		id = ENCODER_ID_INTERNAL_UNIPHY;
		break;
	case ENCODER_OBJECT_ID_INTERNAL_KLDSCP_LVTMA:
		id = ENCODER_ID_INTERNAL_KLDSCP_LVTMA;
		break;
	case ENCODER_OBJECT_ID_INTERNAL_UNIPHY1:
		id = ENCODER_ID_INTERNAL_UNIPHY1;
		break;
	case ENCODER_OBJECT_ID_INTERNAL_UNIPHY2:
		id = ENCODER_ID_INTERNAL_UNIPHY2;
		break;
	case ENCODER_OBJECT_ID_ALMOND: /* ENCODER_OBJECT_ID_NUTMEG */
		id = ENCODER_ID_EXTERNAL_NUTMEG;
		break;
	case ENCODER_OBJECT_ID_TRAVIS:
		id = ENCODER_ID_EXTERNAL_TRAVIS;
		break;
	case ENCODER_OBJECT_ID_INTERNAL_UNIPHY3:
		id = ENCODER_ID_INTERNAL_UNIPHY3;
		break;
	default:
		id = ENCODER_ID_UNKNOWN;
		ASSERT(0);
		break;
	}

	return id;
}

__attribute__((used)) static enum connector_id connector_id_from_bios_object_id(
	uint32_t bios_object_id)
{
	uint32_t bios_connector_id = gpu_id_from_bios_object_id(bios_object_id);

	enum connector_id id;

	switch (bios_connector_id) {
	case CONNECTOR_OBJECT_ID_SINGLE_LINK_DVI_I:
		id = CONNECTOR_ID_SINGLE_LINK_DVII;
		break;
	case CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_I:
		id = CONNECTOR_ID_DUAL_LINK_DVII;
		break;
	case CONNECTOR_OBJECT_ID_SINGLE_LINK_DVI_D:
		id = CONNECTOR_ID_SINGLE_LINK_DVID;
		break;
	case CONNECTOR_OBJECT_ID_DUAL_LINK_DVI_D:
		id = CONNECTOR_ID_DUAL_LINK_DVID;
		break;
	case CONNECTOR_OBJECT_ID_VGA:
		id = CONNECTOR_ID_VGA;
		break;
	case CONNECTOR_OBJECT_ID_HDMI_TYPE_A:
		id = CONNECTOR_ID_HDMI_TYPE_A;
		break;
	case CONNECTOR_OBJECT_ID_LVDS:
		id = CONNECTOR_ID_LVDS;
		break;
	case CONNECTOR_OBJECT_ID_PCIE_CONNECTOR:
		id = CONNECTOR_ID_PCIE;
		break;
	case CONNECTOR_OBJECT_ID_HARDCODE_DVI:
		id = CONNECTOR_ID_HARDCODE_DVI;
		break;
	case CONNECTOR_OBJECT_ID_DISPLAYPORT:
		id = CONNECTOR_ID_DISPLAY_PORT;
		break;
	case CONNECTOR_OBJECT_ID_eDP:
		id = CONNECTOR_ID_EDP;
		break;
	case CONNECTOR_OBJECT_ID_MXM:
		id = CONNECTOR_ID_MXM;
		break;
	default:
		id = CONNECTOR_ID_UNKNOWN;
		break;
	}

	return id;
}

__attribute__((used)) static enum generic_id generic_id_from_bios_object_id(uint32_t bios_object_id)
{
	uint32_t bios_generic_id = gpu_id_from_bios_object_id(bios_object_id);

	enum generic_id id;

	switch (bios_generic_id) {
	case GENERIC_OBJECT_ID_MXM_OPM:
		id = GENERIC_ID_MXM_OPM;
		break;
	case GENERIC_OBJECT_ID_GLSYNC:
		id = GENERIC_ID_GLSYNC;
		break;
	case GENERIC_OBJECT_ID_STEREO_PIN:
		id = GENERIC_ID_STEREO;
		break;
	default:
		id = GENERIC_ID_UNKNOWN;
		break;
	}

	return id;
}

__attribute__((used)) static uint32_t id_from_bios_object_id(enum object_type type,
	uint32_t bios_object_id)
{
	switch (type) {
	case OBJECT_TYPE_GPU:
		return gpu_id_from_bios_object_id(bios_object_id);
	case OBJECT_TYPE_ENCODER:
		return (uint32_t)encoder_id_from_bios_object_id(bios_object_id);
	case OBJECT_TYPE_CONNECTOR:
		return (uint32_t)connector_id_from_bios_object_id(
				bios_object_id);
	case OBJECT_TYPE_GENERIC:
		return generic_id_from_bios_object_id(bios_object_id);
	default:
		return 0;
	}
}

struct graphics_object_id object_id_from_bios_object_id(uint32_t bios_object_id)
{
	enum object_type type;
	enum object_enum_id enum_id;
	struct graphics_object_id go_id = { 0 };

	type = object_type_from_bios_object_id(bios_object_id);

	if (OBJECT_TYPE_UNKNOWN == type)
		return go_id;

	enum_id = enum_id_from_bios_object_id(bios_object_id);

	if (ENUM_ID_UNKNOWN == enum_id)
		return go_id;

	go_id = dal_graphics_object_id_init(
			id_from_bios_object_id(type, bios_object_id), enum_id, type);

	return go_id;
}

