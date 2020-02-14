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
typedef  int u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct nvkm_subdev {scalar_t__ debug; } ;
struct nvkm_mxm {int* mxms; struct nvkm_subdev subdev; } ;
struct mxms_odev {int outp_type; int ddc_port; int conn_type; int dig_conn; } ;

/* Variables and functions */
 scalar_t__ NV_DBG_DEBUG ; 
 scalar_t__ ROM16 (int) ; 
 int ROM32 (int) ; 
 int /*<<< orphan*/  nvkm_debug (struct nvkm_subdev*,char*,...) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 

__attribute__((used)) static u8 *
mxms_data(struct nvkm_mxm *mxm)
{
	return mxm->mxms;

}

u16
mxms_version(struct nvkm_mxm *mxm)
{
	u8 *mxms = mxms_data(mxm);
	u16 version = (mxms[4] << 8) | mxms[5];
	switch (version ) {
	case 0x0200:
	case 0x0201:
	case 0x0300:
		return version;
	default:
		break;
	}

	nvkm_debug(&mxm->subdev, "unknown version %d.%d\n", mxms[4], mxms[5]);
	return 0x0000;
}

u16
mxms_headerlen(struct nvkm_mxm *mxm)
{
	return 8;
}

u16
mxms_structlen(struct nvkm_mxm *mxm)
{
	return *(u16 *)&mxms_data(mxm)[6];
}

bool
mxms_checksum(struct nvkm_mxm *mxm)
{
	u16 size = mxms_headerlen(mxm) + mxms_structlen(mxm);
	u8 *mxms = mxms_data(mxm), sum = 0;
	while (size--)
		sum += *mxms++;
	if (sum) {
		nvkm_debug(&mxm->subdev, "checksum invalid\n");
		return false;
	}
	return true;
}

bool
mxms_valid(struct nvkm_mxm *mxm)
{
	u8 *mxms = mxms_data(mxm);
	if (*(u32 *)mxms != 0x5f4d584d) {
		nvkm_debug(&mxm->subdev, "signature invalid\n");
		return false;
	}

	if (!mxms_version(mxm) || !mxms_checksum(mxm))
		return false;

	return true;
}

bool
mxms_foreach(struct nvkm_mxm *mxm, u8 types,
	     bool (*exec)(struct nvkm_mxm *, u8 *, void *), void *info)
{
	struct nvkm_subdev *subdev = &mxm->subdev;
	u8 *mxms = mxms_data(mxm);
	u8 *desc = mxms + mxms_headerlen(mxm);
	u8 *fini = desc + mxms_structlen(mxm) - 1;
	while (desc < fini) {
		u8 type = desc[0] & 0x0f;
		u8 headerlen = 0;
		u8 recordlen = 0;
		u8 entries = 0;

		switch (type) {
		case 0: /* Output Device Structure */
			if (mxms_version(mxm) >= 0x0300)
				headerlen = 8;
			else
				headerlen = 6;
			break;
		case 1: /* System Cooling Capability Structure */
		case 2: /* Thermal Structure */
		case 3: /* Input Power Structure */
			headerlen = 4;
			break;
		case 4: /* GPIO Device Structure */
			headerlen = 4;
			recordlen = 2;
			entries   = (ROM32(desc[0]) & 0x01f00000) >> 20;
			break;
		case 5: /* Vendor Specific Structure */
			headerlen = 8;
			break;
		case 6: /* Backlight Control Structure */
			if (mxms_version(mxm) >= 0x0300) {
				headerlen = 4;
				recordlen = 8;
				entries   = (desc[1] & 0xf0) >> 4;
			} else {
				headerlen = 8;
			}
			break;
		case 7: /* Fan Control Structure */
			headerlen = 8;
			recordlen = 4;
			entries   = desc[1] & 0x07;
			break;
		default:
			nvkm_debug(subdev, "unknown descriptor type %d\n", type);
			return false;
		}

		if (mxm->subdev.debug >= NV_DBG_DEBUG && (exec == NULL)) {
			static const char * mxms_desc[] = {
				"ODS", "SCCS", "TS", "IPS",
				"GSD", "VSS", "BCS", "FCS",
			};
			u8 *dump = desc;
			char data[32], *ptr;
			int i, j;

			for (j = headerlen - 1, ptr = data; j >= 0; j--)
				ptr += sprintf(ptr, "%02x", dump[j]);
			dump += headerlen;

			nvkm_debug(subdev, "%4s: %s\n", mxms_desc[type], data);
			for (i = 0; i < entries; i++, dump += recordlen) {
				for (j = recordlen - 1, ptr = data; j >= 0; j--)
					ptr += sprintf(ptr, "%02x", dump[j]);
				nvkm_debug(subdev, "      %s\n", data);
			}
		}

		if (types & (1 << type)) {
			if (!exec(mxm, desc, info))
				return false;
		}

		desc += headerlen + (entries * recordlen);
	}

	return true;
}

void
mxms_output_device(struct nvkm_mxm *mxm, u8 *pdata, struct mxms_odev *desc)
{
	u64 data = ROM32(pdata[0]);
	if (mxms_version(mxm) >= 0x0300)
		data |= (u64)ROM16(pdata[4]) << 32;

	desc->outp_type = (data & 0x00000000000000f0ULL) >> 4;
	desc->ddc_port  = (data & 0x0000000000000f00ULL) >> 8;
	desc->conn_type = (data & 0x000000000001f000ULL) >> 12;
	desc->dig_conn  = (data & 0x0000000000780000ULL) >> 19;
}

