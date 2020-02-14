#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int utcrc ;
typedef  int ut8 ;
typedef  int ut32 ;
typedef  enum CRC_PRESETS { ____Placeholder_CRC_PRESETS } CRC_PRESETS ;
struct TYPE_8__ {int crc; int size; int reflect; int poly; int xout; } ;
struct TYPE_7__ {int crc; int size; int reflect; int poly; int xout; } ;
typedef  TYPE_1__ R_CRC_CTX ;

/* Variables and functions */
 int CRC_PRESET_SIZE ; 
 int UTCRC_C (int) ; 
 TYPE_3__* crc_presets ; 

void crc_init (R_CRC_CTX *ctx, utcrc crc, ut32 size, int reflect, utcrc poly, utcrc xout) {
	ctx->crc = crc;
	ctx->size = size;
	ctx->reflect = reflect;
	ctx->poly = poly;
	ctx->xout = xout;
}

void crc_update (R_CRC_CTX *ctx, const ut8 *data, ut32 sz) {
	utcrc crc, d;
	int i, j;

	crc = ctx->crc;
	for (i = 0; i < sz; i++) {
		d = data[i];
		if (ctx->reflect) {
			for (j = 0; j < 4; j++) {
				if (((d >> j) ^ (d >> (7 - j))) & 1) {
					d ^= (1 << j) ^ (1 << (7 - j));
				}
			}
		}
		crc ^= d << (ctx->size - 8);
		for (j = 0; j < 8; j++) {
			crc = ((crc >> (ctx->size - 1)) & 1? ctx->poly: 0) ^ (crc << 1);
		}
	}
	ctx->crc = crc;
}

__attribute__((used)) static void crc_final (R_CRC_CTX *ctx, utcrc *r) {
	utcrc crc;
	int i;

	crc = ctx->crc;
	crc &= (((UTCRC_C(1) << (ctx->size - 1)) - 1) << 1) | 1;
	if (ctx->reflect) {
		for (i = 0; i < (ctx->size >> 1); i++) {
			if (((crc >> i) ^ (crc >> (ctx->size - 1 - i))) & 1) {
				crc ^= (UTCRC_C(1) << i) ^ (UTCRC_C(1) << (ctx->size - 1 - i));
			}
		}
	}

	*r = crc ^ ctx->xout;
}

void crc_init_preset (R_CRC_CTX *ctx, enum CRC_PRESETS preset) {
	ctx->crc = crc_presets[preset].crc;
	ctx->size = crc_presets[preset].size;
	ctx->reflect = crc_presets[preset].reflect;
	ctx->poly = crc_presets[preset].poly;
	ctx->xout = crc_presets[preset].xout;
}

utcrc r_hash_crc_preset (const ut8 *data, ut32 size, enum CRC_PRESETS preset) {
	if (!data || !size || preset >= CRC_PRESET_SIZE) {
		return 0;
	}
	utcrc r;
	R_CRC_CTX crcctx;
	crc_init_preset (&crcctx, preset);
	crc_update (&crcctx, data, size);
	crc_final (&crcctx, &r);
	return r;
}

