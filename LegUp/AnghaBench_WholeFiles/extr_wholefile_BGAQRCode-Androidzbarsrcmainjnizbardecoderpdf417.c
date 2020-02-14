#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zbar_symbol_type_t ;
struct TYPE_12__ {unsigned int s8; scalar_t__ direction; int character; scalar_t__ element; } ;
struct TYPE_11__ {int direction; scalar_t__ modifiers; int /*<<< orphan*/  buf; TYPE_2__ pdf417; int /*<<< orphan*/  lock; } ;
typedef  TYPE_1__ zbar_decoder_t ;
typedef  TYPE_2__ pdf417_decoder_t ;

/* Variables and functions */
 long PDF417_HASH_MASK ; 
 short PDF417_STOP ; 
 scalar_t__ ZBAR_BAR ; 
 int ZBAR_NONE ; 
 char ZBAR_PARTIAL ; 
 int /*<<< orphan*/  ZBAR_PDF417 ; 
 scalar_t__ ZBAR_SPACE ; 
 int /*<<< orphan*/  _zbar_decoder_buf_dump (int /*<<< orphan*/ ,int) ; 
 scalar_t__ acquire_lock (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dbprintf (int,char*,...) ; 
 void* decode_e (scalar_t__,unsigned int,int) ; 
 scalar_t__ get_color (TYPE_1__*) ; 
 scalar_t__ get_width (TYPE_1__*,int) ; 
 short* pdf417_hash ; 
 int /*<<< orphan*/  release_lock (TYPE_1__*,int /*<<< orphan*/ ) ; 
 scalar_t__ size_buf (TYPE_1__*,int) ; 
 int /*<<< orphan*/  zassert (int,int,char*,scalar_t__,long,int,short,...) ; 

__attribute__((used)) static inline signed short pdf417_decode8 (zbar_decoder_t *dcode)
{
    /* build edge signature of character
     * from similar edge measurements
     */
    unsigned s = dcode->pdf417.s8;
    dbprintf(2, " s=%d ", s);
    if(s < 8)
        return(-1);

    long sig = 0;
    signed char e;
    unsigned char i;
    for(i = 0; i < 7; i++) {
        if(get_color(dcode) == ZBAR_SPACE)
            e = decode_e(get_width(dcode, i) +
                         get_width(dcode, i + 1), s, 17);
        else
            e = decode_e(get_width(dcode, 7 - i) +
                         get_width(dcode, 6 - i), s, 17);
        dbprintf(4, "%x", e);
        if(e < 0 || e > 8)
            return(-1);
        sig = (sig << 3) ^ e;
    }
    dbprintf(2, " sig=%06lx", sig);

    /* determine cluster number */
    int clst = ((sig & 7) - ((sig >> 3) & 7) +
                ((sig >> 12) & 7) - ((sig >> 15) & 7));
    if(clst < 0)
        clst += 9;
    dbprintf(2, " k=%d", clst);
    zassert(clst >= 0 && clst < 9, -1, "dir=%x sig=%lx k=%x %s\n",
            dcode->pdf417.direction, sig, clst,
            _zbar_decoder_buf_dump(dcode->buf, dcode->pdf417.character));

    if(clst != 0 && clst != 3 && clst != 6) {
        if(get_color(dcode) && clst == 7 && sig == 0x080007)
            return(PDF417_STOP);
        return(-1);
    }

    signed short g[3];
    sig &= 0x3ffff;
    g[0] = pdf417_hash[(sig - (sig >> 10)) & PDF417_HASH_MASK];
    g[1] = pdf417_hash[((sig >> 8) - sig) & PDF417_HASH_MASK];
    g[2] = pdf417_hash[((sig >> 14) - (sig >> 1)) & PDF417_HASH_MASK];
    zassert(g[0] >= 0 && g[1] >= 0 && g[2] >= 0, -1,
            "dir=%x sig=%lx k=%x g0=%03x g1=%03x g2=%03x %s\n",
            dcode->pdf417.direction, sig, clst, g[0], g[1], g[2],
            _zbar_decoder_buf_dump(dcode->buf, dcode->pdf417.character));

    unsigned short c = (g[0] + g[1] + g[2]) & PDF417_HASH_MASK;
    dbprintf(2, " g0=%x g1=%x g2=%x c=%03d(%d)",
             g[0], g[1], g[2], c & 0x3ff, c >> 10);
    return(c);
}

__attribute__((used)) static inline signed char pdf417_decode_start(zbar_decoder_t *dcode)
{
    unsigned s = dcode->pdf417.s8;
    if(s < 8)
        return(0);

    int ei = decode_e(get_width(dcode, 0) + get_width(dcode, 1), s, 17);
    int ex = (get_color(dcode) == ZBAR_SPACE) ? 2 : 6;
    if(ei != ex)
        return(0);

    ei = decode_e(get_width(dcode, 1) + get_width(dcode, 2), s, 17);
    if(ei)
        return(0);

    ei = decode_e(get_width(dcode, 2) + get_width(dcode, 3), s, 17);
    ex = (get_color(dcode) == ZBAR_SPACE) ? 0 : 2;
    if(ei != ex)
        return(0);

    ei = decode_e(get_width(dcode, 3) + get_width(dcode, 4), s, 17);
    ex = (get_color(dcode) == ZBAR_SPACE) ? 0 : 2;
    if(ei != ex)
        return(0);

    ei = decode_e(get_width(dcode, 4) + get_width(dcode, 5), s, 17);
    if(ei)
        return(0);

    ei = decode_e(get_width(dcode, 5) + get_width(dcode, 6), s, 17);
    if(ei)
        return(0);

    ei = decode_e(get_width(dcode, 6) + get_width(dcode, 7), s, 17);
    ex = (get_color(dcode) == ZBAR_SPACE) ? 7 : 1;
    if(ei != ex)
        return(0);

    ei = decode_e(get_width(dcode, 7) + get_width(dcode, 8), s, 17);
    ex = (get_color(dcode) == ZBAR_SPACE) ? 8 : 1;

    if(get_color(dcode) == ZBAR_BAR) {
        /* stop character has extra bar */
        if(ei != 1)
            return(0);
        ei = decode_e(get_width(dcode, 8) + get_width(dcode, 9), s, 17);
    }

    dbprintf(2, "      pdf417[%c]: s=%d",
             (get_color(dcode)) ? '<' : '>', s);

    /* check quiet zone */
    if(ei >= 0 && ei < ex) {
        dbprintf(2, " [invalid quiet]\n");
        return(0);
    }

    /* lock shared resources */
    if(acquire_lock(dcode, ZBAR_PDF417)) {
        dbprintf(2, " [locked %d]\n", dcode->lock);
        return(0);
    }

    pdf417_decoder_t *dcode417 = &dcode->pdf417;
    dcode417->direction = get_color(dcode);
    dcode417->element = 0;
    dcode417->character = 0;

    dbprintf(2, " [valid start]\n");
    return(ZBAR_PARTIAL);
}

zbar_symbol_type_t _zbar_decode_pdf417 (zbar_decoder_t *dcode)
{
    pdf417_decoder_t *dcode417 = &dcode->pdf417;

    /* update latest character width */
    dcode417->s8 -= get_width(dcode, 8);
    dcode417->s8 += get_width(dcode, 0);

    if(dcode417->character < 0) {
        pdf417_decode_start(dcode);
        dbprintf(4, "\n");
        return(0);
    }

    /* process every 8th element of active symbol */
    if(++dcode417->element)
        return(0);
    dcode417->element = 0;

    dbprintf(2, "      pdf417[%c%02d]:",
             (dcode417->direction) ? '<' : '>', dcode417->character);

    if(get_color(dcode) != dcode417->direction) {
        int c = dcode417->character;
        release_lock(dcode, ZBAR_PDF417);
        dcode417->character = -1;
        zassert(get_color(dcode) == dcode417->direction, ZBAR_NONE,
                "color=%x dir=%x char=%d elem=0 %s\n",
                get_color(dcode), dcode417->direction, c,
                _zbar_decoder_buf_dump(dcode->buf, c));
    }

    signed short c = pdf417_decode8(dcode);
    if(c < 0 || size_buf(dcode, dcode417->character + 1)) {
        dbprintf(1, (c < 0) ? " [aborted]\n" : " [overflow]\n");
        release_lock(dcode, ZBAR_PDF417);
        dcode417->character = -1;
        return(0);
    }

    /* FIXME TBD infer dimensions, save codewords */

    if(c == PDF417_STOP) {
        dbprintf(1, " [valid stop]");
        /* FIXME check trailing bar and qz */
        dcode->direction = 1 - 2 * dcode417->direction;
        dcode->modifiers = 0;
        release_lock(dcode, ZBAR_PDF417);
        dcode417->character = -1;
    }

    dbprintf(2, "\n");
    return(0);
}

