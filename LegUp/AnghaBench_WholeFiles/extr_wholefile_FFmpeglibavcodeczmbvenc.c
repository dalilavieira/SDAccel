#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_5__ ;
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;
typedef  struct TYPE_16__   TYPE_12__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
struct TYPE_16__ {int* next_in; int avail_in; int* next_out; int total_out; int /*<<< orphan*/  avail_out; scalar_t__ total_in; } ;
struct TYPE_18__ {int bypp; int lrange; int urange; scalar_t__ curfrm; scalar_t__ keyint; int* pal2; int* prev; int* work_buf; int* pal; int pstride; int* comp_buf; TYPE_12__ zstream; int /*<<< orphan*/  fmt; int /*<<< orphan*/  comp_size; TYPE_1__* avctx; scalar_t__* score_tab; } ;
typedef  TYPE_2__ ZmbvEncContext ;
struct TYPE_21__ {scalar_t__ pix_fmt; int height; int width; TYPE_2__* priv_data; } ;
struct TYPE_20__ {int** data; int* linesize; } ;
struct TYPE_19__ {int* data; int flags; } ;
struct TYPE_17__ {int width; int height; } ;
typedef  TYPE_3__ AVPacket ;
typedef  TYPE_4__ AVFrame ;
typedef  TYPE_5__ AVCodecContext ;

/* Variables and functions */
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 scalar_t__ AV_PIX_FMT_PAL8 ; 
 int AV_PKT_FLAG_KEY ; 
 int /*<<< orphan*/  AV_WB24 (int*,int) ; 
 int FFMIN (int,int) ; 
 int ZMBV_BLOCK ; 
 int ZMBV_DELTAPAL ; 
 int ZMBV_KEYFRAME ; 
 scalar_t__ Z_OK ; 
 int /*<<< orphan*/  Z_SYNC_FLUSH ; 
 int /*<<< orphan*/  av_log (TYPE_5__*,int /*<<< orphan*/ ,char*) ; 
 scalar_t__ deflate (TYPE_12__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  deflateReset (TYPE_12__*) ; 
 int ff_alloc_packet2 (TYPE_5__*,TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ memcmp (int*,int*,int) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline int block_cmp(ZmbvEncContext *c, uint8_t *src, int stride,
                            uint8_t *src2, int stride2, int bw, int bh,
                            int *xored)
{
    int sum = 0;
    int i, j;
    uint16_t histogram[256] = {0};
    int bw_bytes = bw * c->bypp;

    /* Build frequency histogram of byte values for src[] ^ src2[] */
    for(j = 0; j < bh; j++){
        for(i = 0; i < bw_bytes; i++){
            int t = src[i] ^ src2[i];
            histogram[t]++;
        }
        src += stride;
        src2 += stride2;
    }

    /* If not all the xored values were 0, then the blocks are different */
    *xored = (histogram[0] < bw_bytes * bh);

    /* Exit early if blocks are equal */
    if (!*xored) return 0;

    /* Sum the entropy of all values */
    for(i = 0; i < 256; i++)
        sum += c->score_tab[histogram[i]];

    return sum;
}

__attribute__((used)) static int zmbv_me(ZmbvEncContext *c, uint8_t *src, int sstride, uint8_t *prev,
                   int pstride, int x, int y, int *mx, int *my, int *xored)
{
    int dx, dy, txored, tv, bv, bw, bh;
    int mx0, my0;

    mx0 = *mx;
    my0 = *my;
    bw = FFMIN(ZMBV_BLOCK, c->avctx->width - x);
    bh = FFMIN(ZMBV_BLOCK, c->avctx->height - y);

    /* Try (0,0) */
    bv = block_cmp(c, src, sstride, prev, pstride, bw, bh, xored);
    *mx = *my = 0;
    if(!bv) return 0;

    /* Try previous block's MV (if not 0,0) */
    if (mx0 || my0){
        tv = block_cmp(c, src, sstride, prev + mx0 * c->bypp + my0 * pstride, pstride, bw, bh, &txored);
        if(tv < bv){
            bv = tv;
            *mx = mx0;
            *my = my0;
            *xored = txored;
            if(!bv) return 0;
        }
    }

    /* Try other MVs from top-to-bottom, left-to-right */
    for(dy = -c->lrange; dy <= c->urange; dy++){
        for(dx = -c->lrange; dx <= c->urange; dx++){
            if(!dx && !dy) continue; // we already tested this block
            if(dx == mx0 && dy == my0) continue; // this one too
            tv = block_cmp(c, src, sstride, prev + dx * c->bypp + dy * pstride, pstride, bw, bh, &txored);
            if(tv < bv){
                 bv = tv;
                 *mx = dx;
                 *my = dy;
                 *xored = txored;
                 if(!bv) return 0;
             }
         }
    }
    return bv;
}

__attribute__((used)) static int encode_frame(AVCodecContext *avctx, AVPacket *pkt,
                        const AVFrame *pict, int *got_packet)
{
    ZmbvEncContext * const c = avctx->priv_data;
    const AVFrame * const p = pict;
    uint8_t *src, *prev, *buf;
    uint32_t *palptr;
    int keyframe, chpal;
    int fl;
    int work_size = 0, pkt_size;
    int bw, bh;
    int i, j, ret;

    keyframe = !c->curfrm;
    c->curfrm++;
    if(c->curfrm == c->keyint)
        c->curfrm = 0;
#if FF_API_CODED_FRAME
FF_DISABLE_DEPRECATION_WARNINGS
    avctx->coded_frame->pict_type = keyframe ? AV_PICTURE_TYPE_I : AV_PICTURE_TYPE_P;
    avctx->coded_frame->key_frame = keyframe;
FF_ENABLE_DEPRECATION_WARNINGS
#endif

    palptr = (avctx->pix_fmt == AV_PIX_FMT_PAL8) ? (uint32_t *)p->data[1] : NULL;
    chpal = !keyframe && palptr && memcmp(palptr, c->pal2, 1024);

    src = p->data[0];
    prev = c->prev;
    if(chpal){
        uint8_t tpal[3];
        for(i = 0; i < 256; i++){
            AV_WB24(tpal, palptr[i]);
            c->work_buf[work_size++] = tpal[0] ^ c->pal[i * 3 + 0];
            c->work_buf[work_size++] = tpal[1] ^ c->pal[i * 3 + 1];
            c->work_buf[work_size++] = tpal[2] ^ c->pal[i * 3 + 2];
            c->pal[i * 3 + 0] = tpal[0];
            c->pal[i * 3 + 1] = tpal[1];
            c->pal[i * 3 + 2] = tpal[2];
        }
        memcpy(c->pal2, palptr, 1024);
    }
    if(keyframe){
        if (palptr){
            for(i = 0; i < 256; i++){
                AV_WB24(c->pal+(i*3), palptr[i]);
            }
            memcpy(c->work_buf, c->pal, 768);
            memcpy(c->pal2, palptr, 1024);
            work_size = 768;
        }
        for(i = 0; i < avctx->height; i++){
            memcpy(c->work_buf + work_size, src, avctx->width * c->bypp);
            src += p->linesize[0];
            work_size += avctx->width * c->bypp;
        }
    }else{
        int x, y, bh2, bw2, xored;
        uint8_t *tsrc, *tprev;
        uint8_t *mv;
        int mx = 0, my = 0;

        bw = (avctx->width + ZMBV_BLOCK - 1) / ZMBV_BLOCK;
        bh = (avctx->height + ZMBV_BLOCK - 1) / ZMBV_BLOCK;
        mv = c->work_buf + work_size;
        memset(c->work_buf + work_size, 0, (bw * bh * 2 + 3) & ~3);
        work_size += (bw * bh * 2 + 3) & ~3;
        /* for now just XOR'ing */
        for(y = 0; y < avctx->height; y += ZMBV_BLOCK) {
            bh2 = FFMIN(avctx->height - y, ZMBV_BLOCK);
            for(x = 0; x < avctx->width; x += ZMBV_BLOCK, mv += 2) {
                bw2 = FFMIN(avctx->width - x, ZMBV_BLOCK);

                tsrc = src + x * c->bypp;
                tprev = prev + x * c->bypp;

                zmbv_me(c, tsrc, p->linesize[0], tprev, c->pstride, x, y, &mx, &my, &xored);
                mv[0] = (mx << 1) | !!xored;
                mv[1] = my << 1;
                tprev += mx * c->bypp + my * c->pstride;
                if(xored){
                    for(j = 0; j < bh2; j++){
                        for(i = 0; i < bw2 * c->bypp; i++)
                            c->work_buf[work_size++] = tsrc[i] ^ tprev[i];
                        tsrc += p->linesize[0];
                        tprev += c->pstride;
                    }
                }
            }
            src += p->linesize[0] * ZMBV_BLOCK;
            prev += c->pstride * ZMBV_BLOCK;
        }
    }
    /* save the previous frame */
    src = p->data[0];
    prev = c->prev;
    for(i = 0; i < avctx->height; i++){
        memcpy(prev, src, avctx->width * c->bypp);
        prev += c->pstride;
        src += p->linesize[0];
    }

    if (keyframe)
        deflateReset(&c->zstream);

    c->zstream.next_in = c->work_buf;
    c->zstream.avail_in = work_size;
    c->zstream.total_in = 0;

    c->zstream.next_out = c->comp_buf;
    c->zstream.avail_out = c->comp_size;
    c->zstream.total_out = 0;
    if(deflate(&c->zstream, Z_SYNC_FLUSH) != Z_OK){
        av_log(avctx, AV_LOG_ERROR, "Error compressing data\n");
        return -1;
    }

    pkt_size = c->zstream.total_out + 1 + 6*keyframe;
    if ((ret = ff_alloc_packet2(avctx, pkt, pkt_size, 0)) < 0)
        return ret;
    buf = pkt->data;

    fl = (keyframe ? ZMBV_KEYFRAME : 0) | (chpal ? ZMBV_DELTAPAL : 0);
    *buf++ = fl;
    if (keyframe) {
        *buf++ = 0; // hi ver
        *buf++ = 1; // lo ver
        *buf++ = 1; // comp
        *buf++ = c->fmt; // format
        *buf++ = ZMBV_BLOCK; // block width
        *buf++ = ZMBV_BLOCK; // block height
    }
    memcpy(buf, c->comp_buf, c->zstream.total_out);

    pkt->flags |= AV_PKT_FLAG_KEY*keyframe;
    *got_packet = 1;

    return 0;
}

