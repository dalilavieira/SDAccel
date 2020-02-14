#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned char u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  scalar_t__ u16 ;
struct vb2_buffer {int dummy; } ;
struct coda_q_data {int dummy; } ;
typedef  struct coda_memcpy_desc {int offset; int len; int member_0; unsigned char* member_1; int member_2; int /*<<< orphan*/ * src; } const coda_memcpy_desc ;
struct TYPE_4__ {unsigned char** jpeg_qmat_tab; int jpeg_quality; } ;
struct TYPE_3__ {void* vaddr; } ;
struct coda_ctx {TYPE_2__ params; TYPE_1__ parabuf; int /*<<< orphan*/  bitstream_fifo; struct coda_q_data* q_data; } ;
typedef  int /*<<< orphan*/  luma_dc_value ;
typedef  int /*<<< orphan*/  luma_dc_bits ;
typedef  int /*<<< orphan*/  luma_ac_value ;
typedef  int /*<<< orphan*/  luma_ac_bits ;
typedef  enum v4l2_buf_type { ____Placeholder_v4l2_buf_type } v4l2_buf_type ;
typedef  int /*<<< orphan*/  chroma_dc_value ;
typedef  int /*<<< orphan*/  chroma_dc_bits ;
typedef  int /*<<< orphan*/  chroma_ac_value ;
typedef  int /*<<< orphan*/  chroma_ac_bits ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 int ARRAY_SIZE (struct coda_memcpy_desc const*) ; 
 unsigned int DIV_ROUND_CLOSEST (unsigned int,int) ; 
 scalar_t__ EOI_MARKER ; 
 scalar_t__ SOI_MARKER ; 
#define  V4L2_BUF_TYPE_VIDEO_CAPTURE 137 
#define  V4L2_BUF_TYPE_VIDEO_OUTPUT 136 
 size_t V4L2_M2M_DST ; 
 size_t V4L2_M2M_SRC ; 
 scalar_t__ be16_to_cpup (int /*<<< orphan*/ *) ; 
#define  chroma_ac_bits 135 
#define  chroma_ac_value 134 
#define  chroma_dc_bits 133 
#define  chroma_dc_value 132 
 int /*<<< orphan*/  chroma_q ; 
 unsigned int kfifo_len (int /*<<< orphan*/ *) ; 
#define  luma_ac_bits 131 
#define  luma_ac_value 130 
#define  luma_dc_bits 129 
#define  luma_dc_value 128 
 int /*<<< orphan*/  luma_q ; 
 int /*<<< orphan*/  memcpy (unsigned char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  swab32 (int /*<<< orphan*/  const) ; 
 int vb2_get_plane_payload (struct vb2_buffer*,int /*<<< orphan*/ ) ; 
 void* vb2_plane_vaddr (struct vb2_buffer*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vb2_set_plane_payload (struct vb2_buffer*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline struct coda_q_data *get_q_data(struct coda_ctx *ctx,
					     enum v4l2_buf_type type)
{
	switch (type) {
	case V4L2_BUF_TYPE_VIDEO_OUTPUT:
		return &(ctx->q_data[V4L2_M2M_SRC]);
	case V4L2_BUF_TYPE_VIDEO_CAPTURE:
		return &(ctx->q_data[V4L2_M2M_DST]);
	default:
		return NULL;
	}
}

__attribute__((used)) static inline unsigned int coda_get_bitstream_payload(struct coda_ctx *ctx)
{
	return kfifo_len(&ctx->bitstream_fifo);
}

__attribute__((used)) static void coda_memcpy_parabuf(void *parabuf,
				const struct coda_memcpy_desc *desc)
{
	u32 *dst = parabuf + desc->offset;
	const u32 *src = desc->src;
	int len = desc->len / 4;
	int i;

	for (i = 0; i < len; i += 2) {
		dst[i + 1] = swab32(src[i]);
		dst[i] = swab32(src[i + 1]);
	}
}

int coda_jpeg_write_tables(struct coda_ctx *ctx)
{
	int i;
	static const struct coda_memcpy_desc huff[8] = {
		{ 0,   luma_dc_bits,    sizeof(luma_dc_bits)    },
		{ 16,  luma_dc_value,   sizeof(luma_dc_value)   },
		{ 32,  luma_ac_bits,    sizeof(luma_ac_bits)    },
		{ 48,  luma_ac_value,   sizeof(luma_ac_value)   },
		{ 216, chroma_dc_bits,  sizeof(chroma_dc_bits)  },
		{ 232, chroma_dc_value, sizeof(chroma_dc_value) },
		{ 248, chroma_ac_bits,  sizeof(chroma_ac_bits)  },
		{ 264, chroma_ac_value, sizeof(chroma_ac_value) },
	};
	struct coda_memcpy_desc qmat[3] = {
		{ 512, ctx->params.jpeg_qmat_tab[0], 64 },
		{ 576, ctx->params.jpeg_qmat_tab[1], 64 },
		{ 640, ctx->params.jpeg_qmat_tab[1], 64 },
	};

	/* Write huffman tables to parameter memory */
	for (i = 0; i < ARRAY_SIZE(huff); i++)
		coda_memcpy_parabuf(ctx->parabuf.vaddr, huff + i);

	/* Write Q-matrix to parameter memory */
	for (i = 0; i < ARRAY_SIZE(qmat); i++)
		coda_memcpy_parabuf(ctx->parabuf.vaddr, qmat + i);

	return 0;
}

bool coda_jpeg_check_buffer(struct coda_ctx *ctx, struct vb2_buffer *vb)
{
	void *vaddr = vb2_plane_vaddr(vb, 0);
	u16 soi, eoi;
	int len, i;

	soi = be16_to_cpup((__be16 *)vaddr);
	if (soi != SOI_MARKER)
		return false;

	len = vb2_get_plane_payload(vb, 0);
	vaddr += len - 2;
	for (i = 0; i < 32; i++) {
		eoi = be16_to_cpup((__be16 *)(vaddr - i));
		if (eoi == EOI_MARKER) {
			if (i > 0)
				vb2_set_plane_payload(vb, 0, len - i);
			return true;
		}
	}

	return false;
}

__attribute__((used)) static void coda_scale_quant_table(u8 *q_tab, int scale)
{
	unsigned int temp;
	int i;

	for (i = 0; i < 64; i++) {
		temp = DIV_ROUND_CLOSEST((unsigned int)q_tab[i] * scale, 100);
		if (temp <= 0)
			temp = 1;
		if (temp > 255)
			temp = 255;
		q_tab[i] = (unsigned char)temp;
	}
}

void coda_set_jpeg_compression_quality(struct coda_ctx *ctx, int quality)
{
	unsigned int scale;

	ctx->params.jpeg_quality = quality;

	/* Clip quality setting to [5,100] interval */
	if (quality > 100)
		quality = 100;
	if (quality < 5)
		quality = 5;

	/*
	 * Non-linear scaling factor:
	 * [5,50] -> [1000..100], [51,100] -> [98..0]
	 */
	if (quality < 50)
		scale = 5000 / quality;
	else
		scale = 200 - 2 * quality;

	if (ctx->params.jpeg_qmat_tab[0]) {
		memcpy(ctx->params.jpeg_qmat_tab[0], luma_q, 64);
		coda_scale_quant_table(ctx->params.jpeg_qmat_tab[0], scale);
	}
	if (ctx->params.jpeg_qmat_tab[1]) {
		memcpy(ctx->params.jpeg_qmat_tab[1], chroma_q, 64);
		coda_scale_quant_table(ctx->params.jpeg_qmat_tab[1], scale);
	}
}

