#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_70__   TYPE_9__ ;
typedef  struct TYPE_69__   TYPE_8__ ;
typedef  struct TYPE_68__   TYPE_7__ ;
typedef  struct TYPE_67__   TYPE_6__ ;
typedef  struct TYPE_66__   TYPE_5__ ;
typedef  struct TYPE_65__   TYPE_4__ ;
typedef  struct TYPE_64__   TYPE_3__ ;
typedef  struct TYPE_63__   TYPE_37__ ;
typedef  struct TYPE_62__   TYPE_2__ ;
typedef  struct TYPE_61__   TYPE_1__ ;
typedef  struct TYPE_60__   TYPE_16__ ;
typedef  struct TYPE_59__   TYPE_15__ ;
typedef  struct TYPE_58__   TYPE_14__ ;
typedef  struct TYPE_57__   TYPE_13__ ;
typedef  struct TYPE_56__   TYPE_12__ ;
typedef  struct TYPE_55__   TYPE_11__ ;
typedef  struct TYPE_54__   TYPE_10__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int ptrdiff_t ;
typedef  int /*<<< orphan*/  prev_line ;
typedef  int /*<<< orphan*/  int8_t ;
struct TYPE_66__ {int const* src; int const* src_end; int low; int range; int got_error; } ;
struct TYPE_70__ {int got_error; int* dctblock; int* hblock; TYPE_37__* pic; TYPE_4__* haar_coder; TYPE_3__* dct_coder; TYPE_2__* image_coder; TYPE_1__* fill_coder; TYPE_14__* btype; TYPE_5__ coder; } ;
struct TYPE_69__ {int* weights; int till_rescale; int tot_weight; int upd_val; int num_syms; int* freqs; int max_upd_val; } ;
struct TYPE_68__ {int zero_weight; int total_weight; int zero_freq; int total_freq; int upd_val; int till_rescale; } ;
struct TYPE_67__ {int* weights; int till_rescale; int tot_weight; int upd_val; int* secondary; int* freqs; int sec_size; int max_upd_val; } ;
struct TYPE_65__ {int quality; int scale; TYPE_6__ coef_model; TYPE_8__ coef_hi_model; } ;
struct TYPE_64__ {int quality; int* prev_dc; int prev_dc_stride; int prev_dc_height; TYPE_6__ ac_model; TYPE_7__ sign_model; TYPE_8__ dc_model; int /*<<< orphan*/  qmat; } ;
struct TYPE_63__ {int key_frame; int** data; int* linesize; int /*<<< orphan*/  pict_type; } ;
struct TYPE_62__ {TYPE_8__* vq_model; TYPE_8__ vec_size_model; TYPE_6__ vec_entry_model; TYPE_6__ esc_model; } ;
struct TYPE_61__ {TYPE_8__ coef_model; scalar_t__ fill_val; } ;
struct TYPE_60__ {int width; int height; TYPE_9__* priv_data; } ;
struct TYPE_59__ {int* data; int size; } ;
struct TYPE_58__ {int last_type; TYPE_8__* bt_model; } ;
struct TYPE_57__ {int prev_dc_stride; int* prev_dc; int* qmat; TYPE_7__ sign_model; TYPE_6__ ac_model; TYPE_8__ dc_model; } ;
struct TYPE_56__ {int /*<<< orphan*/  fill_val; TYPE_8__ coef_model; } ;
struct TYPE_55__ {int scale; TYPE_8__ coef_hi_model; TYPE_6__ coef_model; } ;
struct TYPE_54__ {TYPE_6__ esc_model; TYPE_8__* vq_model; TYPE_6__ vec_entry_model; TYPE_8__ vec_size_model; } ;
typedef  TYPE_5__ RangeCoder ;
typedef  TYPE_6__ Model256 ;
typedef  TYPE_7__ Model2 ;
typedef  TYPE_8__ Model ;
typedef  TYPE_9__ MSS3Context ;
typedef  TYPE_10__ ImageBlockCoder ;
typedef  TYPE_11__ HaarBlockCoder ;
typedef  int /*<<< orphan*/  GetByteContext ;
typedef  TYPE_12__ FillBlockCoder ;
typedef  TYPE_13__ DCTBlockCoder ;
typedef  TYPE_14__ BlockTypeContext ;
typedef  TYPE_15__ AVPacket ;
typedef  TYPE_16__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_P ; 
#define  DCT_BLOCK 131 
 scalar_t__ FFABS (int) ; 
 int FFMIN (int,int) ; 
#define  FILL_BLOCK 130 
#define  HAAR_BLOCK 129 
 int HEADER_SIZE ; 
#define  IMAGE_BLOCK 128 
 unsigned int MODEL256_SEC_SCALE ; 
 int MODEL2_SCALE ; 
 int MODEL_SCALE ; 
 int RAC_BOTTOM ; 
 int SKIP_BLOCK ; 
 int av_clip_uint8 (int) ; 
 int av_frame_ref (void*,TYPE_37__*) ; 
 int /*<<< orphan*/  av_log (TYPE_16__*,int /*<<< orphan*/ ,char*,...) ; 
 int bytestream2_get_be16 (int /*<<< orphan*/ *) ; 
 int bytestream2_get_be32 (int /*<<< orphan*/ *) ; 
 int bytestream2_get_byte (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_get_bytes_left (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,int const*,int) ; 
 int /*<<< orphan*/  bytestream2_skip (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ff_mss34_dct_put (int*,int,int*) ; 
 int /*<<< orphan*/  ff_mss34_gen_quant_mat (int /*<<< orphan*/ ,int,int) ; 
 int ff_reget_buffer (TYPE_16__*,TYPE_37__*) ; 
 int* ff_zigzag_direct ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline int8_t ff_u8_to_s8(uint8_t a)
{
    union {
        uint8_t u8;
        int8_t  s8;
    } b;
    b.u8 = a;
    return b.s8;
}

__attribute__((used)) static void model2_reset(Model2 *m)
{
    m->zero_weight  = 1;
    m->total_weight = 2;
    m->zero_freq    = 0x1000;
    m->total_freq   = 0x2000;
    m->upd_val      = 4;
    m->till_rescale = 4;
}

__attribute__((used)) static void model2_update(Model2 *m, int bit)
{
    unsigned scale;

    if (!bit)
        m->zero_weight++;
    m->till_rescale--;
    if (m->till_rescale)
        return;

    m->total_weight += m->upd_val;
    if (m->total_weight > 0x2000) {
        m->total_weight = (m->total_weight + 1) >> 1;
        m->zero_weight  = (m->zero_weight  + 1) >> 1;
        if (m->total_weight == m->zero_weight)
            m->total_weight = m->zero_weight + 1;
    }
    m->upd_val = m->upd_val * 5 >> 2;
    if (m->upd_val > 64)
        m->upd_val = 64;
    scale = 0x80000000u / m->total_weight;
    m->zero_freq    = m->zero_weight  * scale >> 18;
    m->total_freq   = m->total_weight * scale >> 18;
    m->till_rescale = m->upd_val;
}

__attribute__((used)) static void model_update(Model *m, int val)
{
    int i, sum = 0;
    unsigned scale;

    m->weights[val]++;
    m->till_rescale--;
    if (m->till_rescale)
        return;
    m->tot_weight += m->upd_val;

    if (m->tot_weight > 0x8000) {
        m->tot_weight = 0;
        for (i = 0; i < m->num_syms; i++) {
            m->weights[i]  = (m->weights[i] + 1) >> 1;
            m->tot_weight +=  m->weights[i];
        }
    }
    scale = 0x80000000u / m->tot_weight;
    for (i = 0; i < m->num_syms; i++) {
        m->freqs[i] = sum * scale >> 16;
        sum += m->weights[i];
    }

    m->upd_val = m->upd_val * 5 >> 2;
    if (m->upd_val > m->max_upd_val)
        m->upd_val = m->max_upd_val;
    m->till_rescale = m->upd_val;
}

__attribute__((used)) static void model_reset(Model *m)
{
    int i;

    m->tot_weight   = 0;
    for (i = 0; i < m->num_syms - 1; i++)
        m->weights[i] = 1;
    m->weights[m->num_syms - 1] = 0;

    m->upd_val      = m->num_syms;
    m->till_rescale = 1;
    model_update(m, m->num_syms - 1);
    m->till_rescale =
    m->upd_val      = (m->num_syms + 6) >> 1;
}

__attribute__((used)) static void model256_update(Model256 *m, int val)
{
    int i, sum = 0;
    unsigned scale;
    int send, sidx = 1;

    m->weights[val]++;
    m->till_rescale--;
    if (m->till_rescale)
        return;
    m->tot_weight += m->upd_val;

    if (m->tot_weight > 0x8000) {
        m->tot_weight = 0;
        for (i = 0; i < 256; i++) {
            m->weights[i]  = (m->weights[i] + 1) >> 1;
            m->tot_weight +=  m->weights[i];
        }
    }
    scale = 0x80000000u / m->tot_weight;
    m->secondary[0] = 0;
    for (i = 0; i < 256; i++) {
        m->freqs[i] = sum * scale >> 16;
        sum += m->weights[i];
        send = m->freqs[i] >> MODEL256_SEC_SCALE;
        while (sidx <= send)
            m->secondary[sidx++] = i - 1;
    }
    while (sidx < m->sec_size)
        m->secondary[sidx++] = 255;

    m->upd_val = m->upd_val * 5 >> 2;
    if (m->upd_val > m->max_upd_val)
        m->upd_val = m->max_upd_val;
    m->till_rescale = m->upd_val;
}

__attribute__((used)) static void model256_reset(Model256 *m)
{
    int i;

    for (i = 0; i < 255; i++)
        m->weights[i] = 1;
    m->weights[255] = 0;

    m->tot_weight   = 0;
    m->upd_val      = 256;
    m->till_rescale = 1;
    model256_update(m, 255);
    m->till_rescale =
    m->upd_val      = (256 + 6) >> 1;
}

__attribute__((used)) static void rac_init(RangeCoder *c, const uint8_t *src, int size)
{
    int i;

    c->src       = src;
    c->src_end   = src + size;
    c->low       = 0;
    for (i = 0; i < FFMIN(size, 4); i++)
        c->low = (c->low << 8) | *c->src++;
    c->range     = 0xFFFFFFFF;
    c->got_error = 0;
}

__attribute__((used)) static void rac_normalise(RangeCoder *c)
{
    for (;;) {
        c->range <<= 8;
        c->low   <<= 8;
        if (c->src < c->src_end) {
            c->low |= *c->src++;
        } else if (!c->low) {
            c->got_error = 1;
            c->low = 1;
        }
        if (c->range >= RAC_BOTTOM)
            return;
    }
}

__attribute__((used)) static int rac_get_bit(RangeCoder *c)
{
    int bit;

    c->range >>= 1;

    bit = (c->range <= c->low);
    if (bit)
        c->low -= c->range;

    if (c->range < RAC_BOTTOM)
        rac_normalise(c);

    return bit;
}

__attribute__((used)) static int rac_get_bits(RangeCoder *c, int nbits)
{
    int val;

    c->range >>= nbits;
    val = c->low / c->range;
    c->low -= c->range * val;

    if (c->range < RAC_BOTTOM)
        rac_normalise(c);

    return val;
}

__attribute__((used)) static int rac_get_model2_sym(RangeCoder *c, Model2 *m)
{
    int bit, helper;

    helper = m->zero_freq * (c->range >> MODEL2_SCALE);
    bit    = (c->low >= helper);
    if (bit) {
        c->low   -= helper;
        c->range -= helper;
    } else {
        c->range  = helper;
    }

    if (c->range < RAC_BOTTOM)
        rac_normalise(c);

    model2_update(m, bit);

    return bit;
}

__attribute__((used)) static int rac_get_model_sym(RangeCoder *c, Model *m)
{
    int val;
    int end, end2;
    unsigned prob, prob2, helper;

    prob       = 0;
    prob2      = c->range;
    c->range >>= MODEL_SCALE;
    val        = 0;
    end        = m->num_syms >> 1;
    end2       = m->num_syms;
    do {
        helper = m->freqs[end] * c->range;
        if (helper <= c->low) {
            val   = end;
            prob  = helper;
        } else {
            end2  = end;
            prob2 = helper;
        }
        end = (end2 + val) >> 1;
    } while (end != val);
    c->low  -= prob;
    c->range = prob2 - prob;
    if (c->range < RAC_BOTTOM)
        rac_normalise(c);

    model_update(m, val);

    return val;
}

__attribute__((used)) static int rac_get_model256_sym(RangeCoder *c, Model256 *m)
{
    int val;
    int start, end;
    int ssym;
    unsigned prob, prob2, helper;

    prob2      = c->range;
    c->range >>= MODEL_SCALE;

    helper     = c->low / c->range;
    ssym       = helper >> MODEL256_SEC_SCALE;
    val        = m->secondary[ssym];

    end = start = m->secondary[ssym + 1] + 1;
    while (end > val + 1) {
        ssym = (end + val) >> 1;
        if (m->freqs[ssym] <= helper) {
            end = start;
            val = ssym;
        } else {
            end   = (end + val) >> 1;
            start = ssym;
        }
    }
    prob = m->freqs[val] * c->range;
    if (val != 255)
        prob2 = m->freqs[val + 1] * c->range;

    c->low  -= prob;
    c->range = prob2 - prob;
    if (c->range < RAC_BOTTOM)
        rac_normalise(c);

    model256_update(m, val);

    return val;
}

__attribute__((used)) static int decode_block_type(RangeCoder *c, BlockTypeContext *bt)
{
    bt->last_type = rac_get_model_sym(c, &bt->bt_model[bt->last_type]);

    return bt->last_type;
}

__attribute__((used)) static int decode_coeff(RangeCoder *c, Model *m)
{
    int val, sign;

    val = rac_get_model_sym(c, m);
    if (val) {
        sign = rac_get_bit(c);
        if (val > 1) {
            val--;
            val = (1 << val) + rac_get_bits(c, val);
        }
        if (!sign)
            val = -val;
    }

    return val;
}

__attribute__((used)) static void decode_fill_block(RangeCoder *c, FillBlockCoder *fc,
                              uint8_t *dst, ptrdiff_t stride, int block_size)
{
    int i;

    fc->fill_val += decode_coeff(c, &fc->coef_model);

    for (i = 0; i < block_size; i++, dst += stride)
        memset(dst, fc->fill_val, block_size);
}

__attribute__((used)) static void decode_image_block(RangeCoder *c, ImageBlockCoder *ic,
                               uint8_t *dst, ptrdiff_t stride, int block_size)
{
    int i, j;
    int vec_size;
    int vec[4];
    int prev_line[16];
    int A, B, C;

    vec_size = rac_get_model_sym(c, &ic->vec_size_model) + 2;
    for (i = 0; i < vec_size; i++)
        vec[i] = rac_get_model256_sym(c, &ic->vec_entry_model);
    for (; i < 4; i++)
        vec[i] = 0;
    memset(prev_line, 0, sizeof(prev_line));

    for (j = 0; j < block_size; j++) {
        A = 0;
        B = 0;
        for (i = 0; i < block_size; i++) {
            C = B;
            B = prev_line[i];
            A = rac_get_model_sym(c, &ic->vq_model[A + B * 5 + C * 25]);

            prev_line[i] = A;
            if (A < 4)
               dst[i] = vec[A];
            else
               dst[i] = rac_get_model256_sym(c, &ic->esc_model);
        }
        dst += stride;
    }
}

__attribute__((used)) static int decode_dct(RangeCoder *c, DCTBlockCoder *bc, int *block,
                      int bx, int by)
{
    int skip, val, sign, pos = 1, zz_pos, dc;
    int blk_pos = bx + by * bc->prev_dc_stride;

    memset(block, 0, sizeof(*block) * 64);

    dc = decode_coeff(c, &bc->dc_model);
    if (by) {
        if (bx) {
            int l, tl, t;

            l  = bc->prev_dc[blk_pos - 1];
            tl = bc->prev_dc[blk_pos - 1 - bc->prev_dc_stride];
            t  = bc->prev_dc[blk_pos     - bc->prev_dc_stride];

            if (FFABS(t - tl) <= FFABS(l - tl))
                dc += l;
            else
                dc += t;
        } else {
            dc += bc->prev_dc[blk_pos - bc->prev_dc_stride];
        }
    } else if (bx) {
        dc += bc->prev_dc[bx - 1];
    }
    bc->prev_dc[blk_pos] = dc;
    block[0]             = dc * bc->qmat[0];

    while (pos < 64) {
        val = rac_get_model256_sym(c, &bc->ac_model);
        if (!val)
            return 0;
        if (val == 0xF0) {
            pos += 16;
            continue;
        }
        skip = val >> 4;
        val  = val & 0xF;
        if (!val)
            return -1;
        pos += skip;
        if (pos >= 64)
            return -1;

        sign = rac_get_model2_sym(c, &bc->sign_model);
        if (val > 1) {
            val--;
            val = (1 << val) + rac_get_bits(c, val);
        }
        if (!sign)
            val = -val;

        zz_pos = ff_zigzag_direct[pos];
        block[zz_pos] = val * bc->qmat[zz_pos];
        pos++;
    }

    return pos == 64 ? 0 : -1;
}

__attribute__((used)) static void decode_dct_block(RangeCoder *c, DCTBlockCoder *bc,
                             uint8_t *dst, ptrdiff_t stride, int block_size,
                             int *block, int mb_x, int mb_y)
{
    int i, j;
    int bx, by;
    int nblocks = block_size >> 3;

    bx = mb_x * nblocks;
    by = mb_y * nblocks;

    for (j = 0; j < nblocks; j++) {
        for (i = 0; i < nblocks; i++) {
            if (decode_dct(c, bc, block, bx + i, by + j)) {
                c->got_error = 1;
                return;
            }
            ff_mss34_dct_put(dst + i * 8, stride, block);
        }
        dst += 8 * stride;
    }
}

__attribute__((used)) static void decode_haar_block(RangeCoder *c, HaarBlockCoder *hc,
                              uint8_t *dst, ptrdiff_t stride,
                              int block_size, int *block)
{
    const int hsize = block_size >> 1;
    int A, B, C, D, t1, t2, t3, t4;
    int i, j;

    for (j = 0; j < block_size; j++) {
        for (i = 0; i < block_size; i++) {
            if (i < hsize && j < hsize)
                block[i] = rac_get_model256_sym(c, &hc->coef_model);
            else
                block[i] = decode_coeff(c, &hc->coef_hi_model);
            block[i] *= hc->scale;
        }
        block += block_size;
    }
    block -= block_size * block_size;

    for (j = 0; j < hsize; j++) {
        for (i = 0; i < hsize; i++) {
            A = block[i];
            B = block[i + hsize];
            C = block[i + hsize * block_size];
            D = block[i + hsize * block_size + hsize];

            t1 = A - B;
            t2 = C - D;
            t3 = A + B;
            t4 = C + D;
            dst[i * 2]              = av_clip_uint8(t1 - t2);
            dst[i * 2 + stride]     = av_clip_uint8(t1 + t2);
            dst[i * 2 + 1]          = av_clip_uint8(t3 - t4);
            dst[i * 2 + 1 + stride] = av_clip_uint8(t3 + t4);
        }
        block += block_size;
        dst   += stride * 2;
    }
}

__attribute__((used)) static void reset_coders(MSS3Context *ctx, int quality)
{
    int i, j;

    for (i = 0; i < 3; i++) {
        ctx->btype[i].last_type = SKIP_BLOCK;
        for (j = 0; j < 5; j++)
            model_reset(&ctx->btype[i].bt_model[j]);
        ctx->fill_coder[i].fill_val = 0;
        model_reset(&ctx->fill_coder[i].coef_model);
        model256_reset(&ctx->image_coder[i].esc_model);
        model256_reset(&ctx->image_coder[i].vec_entry_model);
        model_reset(&ctx->image_coder[i].vec_size_model);
        for (j = 0; j < 125; j++)
            model_reset(&ctx->image_coder[i].vq_model[j]);
        if (ctx->dct_coder[i].quality != quality) {
            ctx->dct_coder[i].quality = quality;
            ff_mss34_gen_quant_mat(ctx->dct_coder[i].qmat, quality, !i);
        }
        memset(ctx->dct_coder[i].prev_dc, 0,
               sizeof(*ctx->dct_coder[i].prev_dc) *
               ctx->dct_coder[i].prev_dc_stride *
               ctx->dct_coder[i].prev_dc_height);
        model_reset(&ctx->dct_coder[i].dc_model);
        model2_reset(&ctx->dct_coder[i].sign_model);
        model256_reset(&ctx->dct_coder[i].ac_model);
        if (ctx->haar_coder[i].quality != quality) {
            ctx->haar_coder[i].quality = quality;
            ctx->haar_coder[i].scale   = 17 - 7 * quality / 50;
        }
        model_reset(&ctx->haar_coder[i].coef_hi_model);
        model256_reset(&ctx->haar_coder[i].coef_model);
    }
}

__attribute__((used)) static int mss3_decode_frame(AVCodecContext *avctx, void *data, int *got_frame,
                             AVPacket *avpkt)
{
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    MSS3Context *c = avctx->priv_data;
    RangeCoder *acoder = &c->coder;
    GetByteContext gb;
    uint8_t *dst[3];
    int dec_width, dec_height, dec_x, dec_y, quality, keyframe;
    int x, y, i, mb_width, mb_height, blk_size, btype;
    int ret;

    if (buf_size < HEADER_SIZE) {
        av_log(avctx, AV_LOG_ERROR,
               "Frame should have at least %d bytes, got %d instead\n",
               HEADER_SIZE, buf_size);
        return AVERROR_INVALIDDATA;
    }

    bytestream2_init(&gb, buf, buf_size);
    keyframe   = bytestream2_get_be32(&gb);
    if (keyframe & ~0x301) {
        av_log(avctx, AV_LOG_ERROR, "Invalid frame type %X\n", keyframe);
        return AVERROR_INVALIDDATA;
    }
    keyframe   = !(keyframe & 1);
    bytestream2_skip(&gb, 6);
    dec_x      = bytestream2_get_be16(&gb);
    dec_y      = bytestream2_get_be16(&gb);
    dec_width  = bytestream2_get_be16(&gb);
    dec_height = bytestream2_get_be16(&gb);

    if (dec_x + dec_width > avctx->width ||
        dec_y + dec_height > avctx->height ||
        (dec_width | dec_height) & 0xF) {
        av_log(avctx, AV_LOG_ERROR, "Invalid frame dimensions %dx%d +%d,%d\n",
               dec_width, dec_height, dec_x, dec_y);
        return AVERROR_INVALIDDATA;
    }
    bytestream2_skip(&gb, 4);
    quality    = bytestream2_get_byte(&gb);
    if (quality < 1 || quality > 100) {
        av_log(avctx, AV_LOG_ERROR, "Invalid quality setting %d\n", quality);
        return AVERROR_INVALIDDATA;
    }
    bytestream2_skip(&gb, 4);

    if (keyframe && !bytestream2_get_bytes_left(&gb)) {
        av_log(avctx, AV_LOG_ERROR, "Keyframe without data found\n");
        return AVERROR_INVALIDDATA;
    }
    if (!keyframe && c->got_error)
        return buf_size;
    c->got_error = 0;

    if ((ret = ff_reget_buffer(avctx, c->pic)) < 0)
        return ret;
    c->pic->key_frame = keyframe;
    c->pic->pict_type = keyframe ? AV_PICTURE_TYPE_I : AV_PICTURE_TYPE_P;
    if (!bytestream2_get_bytes_left(&gb)) {
        if ((ret = av_frame_ref(data, c->pic)) < 0)
            return ret;
        *got_frame      = 1;

        return buf_size;
    }

    reset_coders(c, quality);

    rac_init(acoder, buf + HEADER_SIZE, buf_size - HEADER_SIZE);

    mb_width  = dec_width  >> 4;
    mb_height = dec_height >> 4;
    dst[0] = c->pic->data[0] + dec_x     +  dec_y      * c->pic->linesize[0];
    dst[1] = c->pic->data[1] + dec_x / 2 + (dec_y / 2) * c->pic->linesize[1];
    dst[2] = c->pic->data[2] + dec_x / 2 + (dec_y / 2) * c->pic->linesize[2];
    for (y = 0; y < mb_height; y++) {
        for (x = 0; x < mb_width; x++) {
            for (i = 0; i < 3; i++) {
                blk_size = 8 << !i;

                btype = decode_block_type(acoder, c->btype + i);
                switch (btype) {
                case FILL_BLOCK:
                    decode_fill_block(acoder, c->fill_coder + i,
                                      dst[i] + x * blk_size,
                                      c->pic->linesize[i], blk_size);
                    break;
                case IMAGE_BLOCK:
                    decode_image_block(acoder, c->image_coder + i,
                                       dst[i] + x * blk_size,
                                       c->pic->linesize[i], blk_size);
                    break;
                case DCT_BLOCK:
                    decode_dct_block(acoder, c->dct_coder + i,
                                     dst[i] + x * blk_size,
                                     c->pic->linesize[i], blk_size,
                                     c->dctblock, x, y);
                    break;
                case HAAR_BLOCK:
                    decode_haar_block(acoder, c->haar_coder + i,
                                      dst[i] + x * blk_size,
                                      c->pic->linesize[i], blk_size,
                                      c->hblock);
                    break;
                }
                if (c->got_error || acoder->got_error) {
                    av_log(avctx, AV_LOG_ERROR, "Error decoding block %d,%d\n",
                           x, y);
                    c->got_error = 1;
                    return AVERROR_INVALIDDATA;
                }
            }
        }
        dst[0] += c->pic->linesize[0] * 16;
        dst[1] += c->pic->linesize[1] * 8;
        dst[2] += c->pic->linesize[2] * 8;
    }

    if ((ret = av_frame_ref(data, c->pic)) < 0)
        return ret;

    *got_frame      = 1;

    return buf_size;
}

