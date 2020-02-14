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
typedef  int u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct nvkm_subdev {TYPE_1__* device; } ;
struct nvkm_mxm {int action; struct nvkm_subdev subdev; } ;
struct nvkm_device {int dummy; } ;
struct nvkm_bios {int* data; } ;
struct mxms_odev {int outp_type; scalar_t__ dig_conn; int conn_type; int /*<<< orphan*/  ddc_port; } ;
struct context {int* outp; struct mxms_odev desc; } ;
struct TYPE_2__ {struct nvkm_bios* bios; } ;

/* Variables and functions */
 int DCB_CONNECTOR_DVI_D ; 
 int DCB_CONNECTOR_HDMI_1 ; 
 int DCB_CONNECTOR_eDP ; 
 int DCB_OUTPUT_DP ; 
 int MXM_SANITISE_DCB ; 
 int /*<<< orphan*/  dcb_outp_foreach (struct nvkm_bios*,struct nvkm_mxm*,int (*) (struct nvkm_bios*,void*,int,int)) ; 
 int dcb_table (struct nvkm_bios*,int*,int*,int*,int*) ; 
 int mxm_ddc_map (struct nvkm_bios*,int /*<<< orphan*/ ) ; 
 int mxm_sor_map (struct nvkm_bios*,scalar_t__) ; 
 scalar_t__ mxms_foreach (struct nvkm_mxm*,int,int (*) (struct nvkm_mxm*,int*,void*),struct context*) ; 
 int /*<<< orphan*/  mxms_output_device (struct nvkm_mxm*,int*,struct mxms_odev*) ; 
 int mxms_version (struct nvkm_mxm*) ; 
 int /*<<< orphan*/  nvbios_connEe (struct nvkm_bios*,int,int*,int*) ; 
 int /*<<< orphan*/  nvkm_debug (struct nvkm_subdev*,char*,int,int,int) ; 
 int /*<<< orphan*/  nvkm_info (struct nvkm_subdev*,char*,int) ; 
 int nvkm_mxm_new_ (struct nvkm_device*,int,struct nvkm_mxm**) ; 
 int /*<<< orphan*/  nvkm_warn (struct nvkm_subdev*,char*) ; 

__attribute__((used)) static bool
mxm_match_tmds_partner(struct nvkm_mxm *mxm, u8 *data, void *info)
{
	struct context *ctx = info;
	struct mxms_odev desc;

	mxms_output_device(mxm, data, &desc);
	if (desc.outp_type == 2 &&
	    desc.dig_conn == ctx->desc.dig_conn)
		return false;
	return true;
}

__attribute__((used)) static bool
mxm_match_dcb(struct nvkm_mxm *mxm, u8 *data, void *info)
{
	struct nvkm_bios *bios = mxm->subdev.device->bios;
	struct context *ctx = info;
	u64 desc = *(u64 *)data;

	mxms_output_device(mxm, data, &ctx->desc);

	/* match dcb encoder type to mxm-ods device type */
	if ((ctx->outp[0] & 0x0000000f) != ctx->desc.outp_type)
		return true;

	/* digital output, have some extra stuff to match here, there's a
	 * table in the vbios that provides a mapping from the mxm digital
	 * connection enum values to SOR/link
	 */
	if ((desc & 0x00000000000000f0) >= 0x20) {
		/* check against sor index */
		u8 link = mxm_sor_map(bios, ctx->desc.dig_conn);
		if ((ctx->outp[0] & 0x0f000000) != (link & 0x0f) << 24)
			return true;

		/* check dcb entry has a compatible link field */
		link = (link & 0x30) >> 4;
		if ((link & ((ctx->outp[1] & 0x00000030) >> 4)) != link)
			return true;
	}

	/* mark this descriptor accounted for by setting invalid device type,
	 * except of course some manufactures don't follow specs properly and
	 * we need to avoid killing off the TMDS function on DP connectors
	 * if MXM-SIS is missing an entry for it.
	 */
	data[0] &= ~0xf0;
	if (ctx->desc.outp_type == 6 && ctx->desc.conn_type == 6 &&
	    mxms_foreach(mxm, 0x01, mxm_match_tmds_partner, ctx)) {
		data[0] |= 0x20; /* modify descriptor to match TMDS now */
	} else {
		data[0] |= 0xf0;
	}

	return false;
}

__attribute__((used)) static int
mxm_dcb_sanitise_entry(struct nvkm_bios *bios, void *data, int idx, u16 pdcb)
{
	struct nvkm_mxm *mxm = data;
	struct context ctx = { .outp = (u32 *)(bios->data + pdcb) };
	u8 type, i2cidx, link, ver, len;
	u8 *conn;

	/* look for an output device structure that matches this dcb entry.
	 * if one isn't found, disable it.
	 */
	if (mxms_foreach(mxm, 0x01, mxm_match_dcb, &ctx)) {
		nvkm_debug(&mxm->subdev, "disable %d: %08x %08x\n",
			   idx, ctx.outp[0], ctx.outp[1]);
		ctx.outp[0] |= 0x0000000f;
		return 0;
	}

	/* modify the output's ddc/aux port, there's a pointer to a table
	 * with the mapping from mxm ddc/aux port to dcb i2c_index in the
	 * vbios mxm table
	 */
	i2cidx = mxm_ddc_map(bios, ctx.desc.ddc_port);
	if ((ctx.outp[0] & 0x0000000f) != DCB_OUTPUT_DP)
		i2cidx = (i2cidx & 0x0f) << 4;
	else
		i2cidx = (i2cidx & 0xf0);

	if (i2cidx != 0xf0) {
		ctx.outp[0] &= ~0x000000f0;
		ctx.outp[0] |= i2cidx;
	}

	/* override dcb sorconf.link, based on what mxm data says */
	switch (ctx.desc.outp_type) {
	case 0x00: /* Analog CRT */
	case 0x01: /* Analog TV/HDTV */
		break;
	default:
		link = mxm_sor_map(bios, ctx.desc.dig_conn) & 0x30;
		ctx.outp[1] &= ~0x00000030;
		ctx.outp[1] |= link;
		break;
	}

	/* we may need to fixup various other vbios tables based on what
	 * the descriptor says the connector type should be.
	 *
	 * in a lot of cases, the vbios tables will claim DVI-I is possible,
	 * and the mxm data says the connector is really HDMI.  another
	 * common example is DP->eDP.
	 */
	conn  = bios->data;
	conn += nvbios_connEe(bios, (ctx.outp[0] & 0x0000f000) >> 12, &ver, &len);
	type  = conn[0];
	switch (ctx.desc.conn_type) {
	case 0x01: /* LVDS */
		ctx.outp[1] |= 0x00000004; /* use_power_scripts */
		/* XXX: modify default link width in LVDS table */
		break;
	case 0x02: /* HDMI */
		type = DCB_CONNECTOR_HDMI_1;
		break;
	case 0x03: /* DVI-D */
		type = DCB_CONNECTOR_DVI_D;
		break;
	case 0x0e: /* eDP, falls through to DPint */
		ctx.outp[1] |= 0x00010000;
	case 0x07: /* DP internal, wtf is this?? HP8670w */
		ctx.outp[1] |= 0x00000004; /* use_power_scripts? */
		type = DCB_CONNECTOR_eDP;
		break;
	default:
		break;
	}

	if (mxms_version(mxm) >= 0x0300)
		conn[0] = type;

	return 0;
}

__attribute__((used)) static bool
mxm_show_unmatched(struct nvkm_mxm *mxm, u8 *data, void *info)
{
	struct nvkm_subdev *subdev = &mxm->subdev;
	u64 desc = *(u64 *)data;
	if ((desc & 0xf0) != 0xf0)
		nvkm_info(subdev, "unmatched output device %016llx\n", desc);
	return true;
}

__attribute__((used)) static void
mxm_dcb_sanitise(struct nvkm_mxm *mxm)
{
	struct nvkm_subdev *subdev = &mxm->subdev;
	struct nvkm_bios *bios = subdev->device->bios;
	u8  ver, hdr, cnt, len;
	u16 dcb = dcb_table(bios, &ver, &hdr, &cnt, &len);
	if (dcb == 0x0000 || (ver != 0x40 && ver != 0x41)) {
		nvkm_warn(subdev, "unsupported DCB version\n");
		return;
	}

	dcb_outp_foreach(bios, mxm, mxm_dcb_sanitise_entry);
	mxms_foreach(mxm, 0x01, mxm_show_unmatched, NULL);
}

int
nv50_mxm_new(struct nvkm_device *device, int index, struct nvkm_subdev **pmxm)
{
	struct nvkm_mxm *mxm;
	int ret;

	ret = nvkm_mxm_new_(device, index, &mxm);
	if (mxm)
		*pmxm = &mxm->subdev;
	if (ret)
		return ret;

	if (mxm->action & MXM_SANITISE_DCB)
		mxm_dcb_sanitise(mxm);

	return 0;
}

