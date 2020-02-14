#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zbar_symbol_type_t ;
struct TYPE_19__ {unsigned int direction; unsigned int character; int element; unsigned int width; int buf; } ;
struct TYPE_18__ {unsigned int s6; unsigned int* buf; int direction; unsigned int buf_alloc; unsigned int buflen; TYPE_2__ code93; scalar_t__ modifiers; } ;
typedef  TYPE_1__ zbar_decoder_t ;
typedef  TYPE_2__ code93_decoder_t ;

/* Variables and functions */
 unsigned int CFG (TYPE_2__,int /*<<< orphan*/ ) ; 
 int CHKMOD ; 
 scalar_t__ ZBAR_BAR ; 
 int /*<<< orphan*/  ZBAR_CFG_MAX_LEN ; 
 int /*<<< orphan*/  ZBAR_CFG_MIN_LEN ; 
 int /*<<< orphan*/  ZBAR_CODE93 ; 
 int /*<<< orphan*/  ZBAR_NONE ; 
 int /*<<< orphan*/  ZBAR_PARTIAL ; 
 int /*<<< orphan*/  _zbar_decoder_buf_dump (unsigned int*,unsigned int) ; 
 scalar_t__ acquire_lock (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int* code93_hash ; 
 int /*<<< orphan*/  dbprintf (int,char*,...) ; 
 unsigned int decode_e (int /*<<< orphan*/ ,unsigned int,int) ; 
 scalar_t__ get_color (TYPE_1__*) ; 
 unsigned int get_width (TYPE_1__*,int) ; 
 int /*<<< orphan*/  pair_width (TYPE_1__*,int) ; 
 int /*<<< orphan*/  release_lock (TYPE_1__*,int /*<<< orphan*/ ) ; 
 scalar_t__ size_buf (TYPE_1__*,int) ; 
 int /*<<< orphan*/  zassert (int,int,char*,unsigned int,...) ; 

__attribute__((used)) static inline int
check_width (unsigned cur,
             unsigned prev)
{
    unsigned dw;
    if(prev > cur)
        dw = prev - cur;
    else
        dw = cur - prev;
    dw *= 4;
    return(dw > prev);
}

__attribute__((used)) static inline int
encode6 (zbar_decoder_t *dcode)
{
    /* build edge signature of character */
    unsigned s = dcode->s6;
    int sig = 0, i;

    dbprintf(2, " s=%d ", s);
    if(s < 9)
        return(-1);

    for(i = 6; --i > 0; ) {
        unsigned c = decode_e(pair_width(dcode, i), s, 9);
        if(c > 3)
            return(-1);
        sig = (sig << 2) | c;
        dbprintf(2, "%d", c);
    }
    dbprintf(2, " sig=%03x", sig);

    return(sig);
}

__attribute__((used)) static inline int
validate_sig (int sig)
{
    int i, sum = 0, emin = 0, sig0 = 0, sig1 = 0;
    dbprintf(3, " sum=0");
    for(i = 3; --i >= 0; ) {
        int e = sig & 3;
        sig >>= 2;
        sum = e - sum;
        sig1 <<= 4;
        sig1 += sum;
        dbprintf(3, "%d", sum);
        if(!i)
            break;

        e = sig & 3;
        sig >>= 2;
        sum = e - sum;
        sig0 <<= 4;
        if(emin > sum)
            emin = sum;
        sig0 += sum;
        dbprintf(3, "%d", sum);
    }

    dbprintf(3, " emin=%d sig=%03x/%03x", emin, sig1 & 0xfff, sig0 & 0xfff);

    emin = emin + (emin << 4) + (emin << 8);
    sig0 -= emin;
    sig1 += emin;

    dbprintf(3, "=%03x/%03x", sig1 & 0xfff, sig0 & 0xfff);
    return((sig0 | sig1) & 0x888);
}

__attribute__((used)) static inline int
decode6 (zbar_decoder_t *dcode)
{
    int sig = encode6(dcode);
    int g0, g1, c;
    if(sig < 0 ||
       (sig & 0x3) + ((sig >> 4) & 0x3) + ((sig >> 8) & 0x3) != 3 ||
       validate_sig(sig))
        return(-1);

    if(dcode->code93.direction) {
        /* reverse signature */
        unsigned tmp = sig & 0x030;
        sig = ((sig & 0x3c0) >> 6) | ((sig & 0x00f) << 6);
        sig = ((sig & 0x30c) >> 2) | ((sig & 0x0c3) << 2) | tmp;
    }

    g0 = code93_hash[(sig - (sig >> 4)) & 0x3f];
    g1 = code93_hash[((sig >> 2) - (sig >> 7)) & 0x3f];
    zassert(g0 >= 0 && g1 >= 0, -1,
            "dir=%x sig=%03x g0=%03x g1=%03x %s\n",
            dcode->code93.direction, sig, g0, g1,
            _zbar_decoder_buf_dump(dcode->buf, dcode->code93.character));

    c = (g0 + g1) & 0x3f;
    dbprintf(2, " g0=%x g1=%x c=%02x", g0, g1, c);
    return(c);
}

__attribute__((used)) static inline zbar_symbol_type_t
decode_start (zbar_decoder_t *dcode)
{
    code93_decoder_t *dcode93 = &dcode->code93;
    unsigned dir, qz, s = dcode->s6;
    int c;

    dbprintf(2, "      code93:");
    c = encode6(dcode);
    if(c < 0 || (c != 0x00f && c != 0x0f0))
        return(ZBAR_NONE);

    dir = (c >> 7);

    if(dir) {
        if(decode_e(pair_width(dcode, 0), s, 9))
            return(ZBAR_NONE);
        qz = get_width(dcode, 8);
    }

    qz = get_width(dcode, 7);
    if(qz && qz < (s * 3) / 4) {
        dbprintf(2, " [invalid qz %d]", qz);
        return(ZBAR_NONE);
    }

    /* decoded valid start/stop - initialize state */
    dcode93->direction = dir;
    dcode93->element = (!dir) ? 0 : 7;
    dcode93->character = 0;
    dcode93->width = s;

    dbprintf(2, " dir=%x [valid start]", dir);
    return(ZBAR_PARTIAL);
}

__attribute__((used)) static inline zbar_symbol_type_t
decode_abort (zbar_decoder_t *dcode,
              const char *reason)
{
    code93_decoder_t *dcode93 = &dcode->code93;
    if(dcode93->character > 1)
        release_lock(dcode, ZBAR_CODE93);
    dcode93->character = -1;
    if(reason)
        dbprintf(1, " [%s]\n", reason);
    return(ZBAR_NONE);
}

__attribute__((used)) static inline zbar_symbol_type_t
check_stop (zbar_decoder_t *dcode)
{
    code93_decoder_t *dcode93 = &dcode->code93;
    unsigned n = dcode93->character, s = dcode->s6;
    int max_len = CFG(*dcode93, ZBAR_CFG_MAX_LEN);
    if(n < 2 ||
       n < CFG(*dcode93, ZBAR_CFG_MIN_LEN) ||
       (max_len && n > max_len))
        return(decode_abort(dcode, "invalid len"));

    if(dcode93->direction) {
        unsigned qz = get_width(dcode, 0);
        if(qz && qz < (s * 3) / 4)
            return(decode_abort(dcode, "invalid qz"));
    }
    else if(decode_e(pair_width(dcode, 0), s, 9))
        /* FIXME forward-trailing QZ check */
        return(decode_abort(dcode, "invalid stop"));

    return(ZBAR_CODE93);
}

__attribute__((used)) static inline int
plusmod47 (int acc,
           int add)
{
    acc += add;
    if(acc >= CHKMOD)
        acc -= CHKMOD;
    return(acc);
}

__attribute__((used)) static inline int
validate_checksums (zbar_decoder_t *dcode)
{
    code93_decoder_t *dcode93 = &dcode->code93;
    unsigned d, i, n = dcode93->character;
    unsigned sum_c = 0, acc_c = 0, i_c = (n - 2) % 20;
    unsigned sum_k = 0, acc_k = 0, i_k = (n - 1) % 15;

    for(i = 0; i < n - 2; i++) {
        d = dcode->buf[(dcode93->direction) ? n - 1 - i : i];

        if(!i_c--) {
            acc_c = 0;
            i_c = 19;
        }
        acc_c = plusmod47(acc_c, d);
        sum_c = plusmod47(sum_c, acc_c);

        if(!i_k--) {
            acc_k = 0;
            i_k = 14;
        }
        acc_k = plusmod47(acc_k, d);
        sum_k = plusmod47(sum_k, acc_k);
    }

    d = dcode->buf[(dcode93->direction) ? 1 : n - 2];
    dbprintf(2, " C=%02x?=%02x", d, sum_c);
    if(d != sum_c)
        return(1);

    acc_k = plusmod47(acc_k, sum_c);
    sum_k = plusmod47(sum_k, acc_k);
    d = dcode->buf[(dcode93->direction) ? 0 : n - 1];
    dbprintf(2, " K=%02x?=%02x", d, sum_k);
    if(d != sum_k)
        return(1);

    return(0);
}

__attribute__((used)) static inline int
postprocess (zbar_decoder_t *dcode)
{
    code93_decoder_t *dcode93 = &dcode->code93;
    unsigned i, j, n = dcode93->character;
    static const unsigned char code93_graph[] = "-. $/+%";
    static const unsigned char code93_s2[] =
        "\x1b\x1c\x1d\x1e\x1f;<=>?[\\]^_{|}~\x7f\x00\x40`\x7f\x7f\x7f";

    dbprintf(2, "\n    postproc len=%d", n);
    dcode->direction = 1 - 2 * dcode93->direction;
    if(dcode93->direction) {
        /* reverse buffer */
        dbprintf(2, " (rev)");
        for(i = 0; i < n / 2; i++) {
            unsigned j = n - 1 - i;
            unsigned char d = dcode->buf[i];
            dcode->buf[i] = dcode->buf[j];
            dcode->buf[j] = d;
        }
    }

    n -= 2;
    for(i = 0, j = 0; i < n; ) {
        unsigned char d = dcode->buf[i++];
        if(d < 0xa)
            d = '0' + d;
        else if(d < 0x24)
            d = 'A' + d - 0xa;
        else if(d < 0x2b)
            d = code93_graph[d - 0x24];
        else {
            unsigned shift = d;
            zassert(shift < 0x2f, -1, "%s\n",
                    _zbar_decoder_buf_dump(dcode->buf, dcode93->character));
            d = dcode->buf[i++];
            if(d < 0xa || d >= 0x24)
                return(1);
            d -= 0xa;
            switch(shift)
            {
            case 0x2b: d++; break;
            case 0x2c: d = code93_s2[d]; break;
            case 0x2d: d += 0x21; break;
            case 0x2e: d += 0x61; break;
            default: return(1);
            }
        }
        dcode->buf[j++] = d;
    }

    zassert(j < dcode->buf_alloc, 1,
            "j=%02x %s\n", j,
            _zbar_decoder_buf_dump(dcode->buf, dcode->code93.character));
    dcode->buflen = j;
    dcode->buf[j] = '\0';
    dcode->modifiers = 0;
    return(0);
}

zbar_symbol_type_t
_zbar_decode_code93 (zbar_decoder_t *dcode)
{
    code93_decoder_t *dcode93 = &dcode->code93;
    int c;

    if(dcode93->character < 0) {
        zbar_symbol_type_t sym;
        if(get_color(dcode) != ZBAR_BAR)
            return(ZBAR_NONE);
        sym = decode_start(dcode);
        dbprintf(2, "\n");
        return(sym);
    }

    if(/* process every 6th element of active symbol */
       ++dcode93->element != 6 ||
       /* decode color based on direction */
       get_color(dcode) == dcode93->direction)
        return(ZBAR_NONE);

    dcode93->element = 0;

    dbprintf(2, "      code93[%c%02d+%x]:",
             (dcode93->direction) ? '<' : '>',
             dcode93->character, dcode93->element);

    if(check_width(dcode->s6, dcode93->width))
        return(decode_abort(dcode, "width var"));

    c = decode6(dcode);
    if(c < 0)
        return(decode_abort(dcode, "aborted"));

    if(c == 0x2f) {
        if(!check_stop(dcode))
            return(ZBAR_NONE);
        if(validate_checksums(dcode))
            return(decode_abort(dcode, "checksum error"));
        if(postprocess(dcode))
            return(decode_abort(dcode, "invalid encoding"));

        dbprintf(2, " [valid end]\n");
        dbprintf(3, "    %s\n",
                 _zbar_decoder_buf_dump(dcode->buf, dcode93->character));

        dcode93->character = -1;
        return(ZBAR_CODE93);
    }

    if(size_buf(dcode, dcode93->character + 1))
        return(decode_abort(dcode, "overflow"));

    dcode93->width = dcode->s6;

    if(dcode93->character == 1) {
        /* lock shared resources */
        if(acquire_lock(dcode, ZBAR_CODE93))
            return(decode_abort(dcode, NULL));
        dcode->buf[0] = dcode93->buf;
    }

    if(!dcode93->character)
        dcode93->buf = c;
    else 
        dcode->buf[dcode93->character] = c;
    dcode93->character++;

    dbprintf(2, "\n");
    return(ZBAR_NONE);
}

