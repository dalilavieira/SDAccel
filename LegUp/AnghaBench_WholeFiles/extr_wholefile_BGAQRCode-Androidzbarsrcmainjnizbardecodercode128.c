#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zbar_symbol_type_t ;
struct TYPE_15__ {unsigned int s6; int character; int direction; int element; char start; int width; } ;
struct TYPE_14__ {unsigned int* buf; int direction; unsigned int buf_alloc; unsigned int buflen; TYPE_2__ code128; int /*<<< orphan*/  modifiers; } ;
typedef  TYPE_1__ zbar_decoder_t ;
typedef  TYPE_2__ code128_decoder_t ;

/* Variables and functions */
 int CFG (TYPE_2__,int /*<<< orphan*/ ) ; 
 unsigned char CODE_A ; 
 unsigned char CODE_C ; 
 unsigned char FNC1 ; 
 unsigned char FNC2 ; 
 unsigned char FNC3 ; 
 int /*<<< orphan*/  MOD (int /*<<< orphan*/ ) ; 
 unsigned char SHIFT ; 
 unsigned char START_A ; 
 unsigned char START_C ; 
 char STOP_FWD ; 
 char STOP_REV ; 
 scalar_t__ ZBAR_BAR ; 
 int /*<<< orphan*/  ZBAR_CFG_MAX_LEN ; 
 int /*<<< orphan*/  ZBAR_CFG_MIN_LEN ; 
 int /*<<< orphan*/  ZBAR_CODE128 ; 
 int /*<<< orphan*/  ZBAR_MOD_AIM ; 
 int /*<<< orphan*/  ZBAR_MOD_GS1 ; 
 int /*<<< orphan*/  ZBAR_NONE ; 
 scalar_t__ ZBAR_SPACE ; 
 unsigned char _zbar_decoder_buf_dump (unsigned int*,int) ; 
 scalar_t__ acquire_lock (TYPE_1__*,int /*<<< orphan*/ ) ; 
 unsigned char* characters ; 
 int /*<<< orphan*/  dbprintf (int,char*,...) ; 
 int decode_e (unsigned int,unsigned int,int) ; 
 scalar_t__ get_color (TYPE_1__*) ; 
 unsigned int get_width (TYPE_1__*,int) ; 
 scalar_t__* lo_base ; 
 unsigned char* lo_offset ; 
 int /*<<< orphan*/  memmove (unsigned char*,unsigned char*,unsigned int) ; 
 int /*<<< orphan*/  release_lock (TYPE_1__*,int /*<<< orphan*/ ) ; 
 scalar_t__ size_buf (TYPE_1__*,int) ; 
 int /*<<< orphan*/  zassert (int,int,char*,int,...) ; 

__attribute__((used)) static inline signed char decode_lo (int sig)
{
    unsigned char offset = (((sig >> 1) & 0x01) |
                            ((sig >> 3) & 0x06) |
                            ((sig >> 5) & 0x18) |
                            ((sig >> 7) & 0x60));
    unsigned char idx = lo_offset[offset];
    unsigned char base, c;

    if(sig & 1)
        idx &= 0xf;
    else
        idx >>= 4;
    if(idx == 0xf)
        return(-1);

    base = (sig >> 11) | ((sig >> 9) & 1);
    zassert(base < 8, -1, "sig=%x offset=%x idx=%x base=%x\n",
            sig, offset, idx, base);
    idx += lo_base[base];

    zassert(idx <= 0x50, -1, "sig=%x offset=%x base=%x idx=%x\n",
            sig, offset, base, idx);
    c = characters[idx];
    dbprintf(2, " %02x(%x(%02x)/%x(%02x)) => %02x",
             idx, base, lo_base[base], offset, lo_offset[offset],
             (unsigned char)c);
    return(c);
}

__attribute__((used)) static inline signed char decode_hi (int sig)
{
    unsigned char rev = (sig & 0x4400) != 0;
    unsigned char idx, c;
    if(rev)
        sig = (((sig >> 12) & 0x000f) |
               ((sig >>  4) & 0x00f0) |
               ((sig <<  4) & 0x0f00) |
               ((sig << 12) & 0xf000));
    dbprintf(2, " rev=%x", rev != 0);

    switch(sig) {
    case 0x0014: idx = 0x0; break;
    case 0x0025: idx = 0x1; break;
    case 0x0034: idx = 0x2; break;
    case 0x0134: idx = 0x3; break;
    case 0x0143: idx = 0x4; break;
    case 0x0243: idx = 0x5; break;
    case 0x0341: idx = 0x6; break;
    case 0x0352: idx = 0x7; break;
    case 0x1024: idx = 0x8; break;
    case 0x1114: idx = 0x9; break;
    case 0x1134: idx = 0xa; break;
    case 0x1242: idx = 0xb; break;
    case 0x1243: idx = 0xc; break;
    case 0x1441: idx = 0xd; rev = 0; break;
    default: return(-1);
    }
    if(rev)
        idx += 0xe;
    c = characters[0x51 + idx];
    dbprintf(2, " %02x => %02x", idx, c);
    return(c);
}

__attribute__((used)) static inline unsigned char calc_check (unsigned char c)
{
    if(!(c & 0x80))
        return(0x18);
    c &= 0x7f;
    if(c < 0x3d)
        return((c < 0x30 && c != 0x17) ? 0x10 : 0x20);
    if(c < 0x50)
        return((c == 0x4d) ? 0x20 : 0x10);
    return((c < 0x67) ? 0x20 : 0x10);
}

__attribute__((used)) static inline signed char decode6 (zbar_decoder_t *dcode)
{
    int sig;
    signed char c, chk;
    unsigned bars;

    /* build edge signature of character */
    unsigned s = dcode->code128.s6;

    dbprintf(2, " s=%d", s);
    if(s < 5)
        return(-1);
    /* calculate similar edge measurements */
    sig = (get_color(dcode) == ZBAR_BAR)
        ? ((decode_e(get_width(dcode, 0) + get_width(dcode, 1), s, 11) << 12) |
           (decode_e(get_width(dcode, 1) + get_width(dcode, 2), s, 11) << 8) |
           (decode_e(get_width(dcode, 2) + get_width(dcode, 3), s, 11) << 4) |
           (decode_e(get_width(dcode, 3) + get_width(dcode, 4), s, 11)))
        : ((decode_e(get_width(dcode, 5) + get_width(dcode, 4), s, 11) << 12) |
           (decode_e(get_width(dcode, 4) + get_width(dcode, 3), s, 11) << 8) |
           (decode_e(get_width(dcode, 3) + get_width(dcode, 2), s, 11) << 4) |
           (decode_e(get_width(dcode, 2) + get_width(dcode, 1), s, 11)));
    if(sig < 0)
        return(-1);
    dbprintf(2, " sig=%04x", sig);
    /* lookup edge signature */
    c = (sig & 0x4444) ? decode_hi(sig) : decode_lo(sig);
    if(c == -1)
        return(-1);

    /* character validation */
    bars = (get_color(dcode) == ZBAR_BAR)
        ? (get_width(dcode, 0) + get_width(dcode, 2) + get_width(dcode, 4))
        : (get_width(dcode, 1) + get_width(dcode, 3) + get_width(dcode, 5));
    bars = bars * 11 * 4 / s;
    chk = calc_check(c);
    dbprintf(2, " bars=%d chk=%d", bars, chk);
    if(chk - 7 > bars || bars > chk + 7)
        return(-1);

    return(c & 0x7f);
}

__attribute__((used)) static inline unsigned char validate_checksum (zbar_decoder_t *dcode)
{
    unsigned idx, sum, i, acc = 0;
    unsigned char check, err;

    code128_decoder_t *dcode128 = &dcode->code128;
    if(dcode128->character < 3)
        return(1);

    /* add in irregularly weighted start character */
    idx = (dcode128->direction) ? dcode128->character - 1 : 0;
    sum = dcode->buf[idx];
    if(sum >= 103)
        sum -= 103;

    /* calculate sum in reverse to avoid multiply operations */
    for(i = dcode128->character - 3; i; i--) {
        zassert(sum < 103, -1, "dir=%x i=%x sum=%x acc=%x %s\n",
                dcode128->direction, i, sum, acc,
                _zbar_decoder_buf_dump(dcode->buf, dcode128->character));
        idx = (dcode128->direction) ? dcode128->character - 1 - i : i;
        acc += dcode->buf[idx];
        if(acc >= 103)
            acc -= 103;
        zassert(acc < 103, -1, "dir=%x i=%x sum=%x acc=%x %s\n",
                dcode128->direction, i, sum, acc,
                _zbar_decoder_buf_dump(dcode->buf, dcode128->character));
        sum += acc;
        if(sum >= 103)
            sum -= 103;
    }

    /* and compare to check character */
    idx = (dcode128->direction) ? 1 : dcode128->character - 2;
    check = dcode->buf[idx];
    dbprintf(2, " chk=%02x(%02x)", sum, check);
    err = (sum != check);
    if(err)
        dbprintf(1, " [checksum error]\n");
    return(err);
}

__attribute__((used)) static inline unsigned postprocess_c (zbar_decoder_t *dcode,
                                      unsigned start,
                                      unsigned end,
                                      unsigned dst)
{
    unsigned i, j;

    /* expand buffer to accomodate 2x set C characters (2 digits per-char) */
    unsigned delta = end - start;
    unsigned newlen = dcode->code128.character + delta;
    size_buf(dcode, newlen);

    /* relocate unprocessed data to end of buffer */
    memmove(dcode->buf + start + delta, dcode->buf + start,
            dcode->code128.character - start);
    dcode->code128.character = newlen;

    for(i = 0, j = dst; i < delta; i++, j += 2) {
        /* convert each set C character into two ASCII digits */
        unsigned char code = dcode->buf[start + delta + i];
        dcode->buf[j] = '0';
        if(code >= 50) {
            code -= 50;
            dcode->buf[j] += 5;
        }
        if(code >= 30) {
            code -= 30;
            dcode->buf[j] += 3;
        }
        if(code >= 20) {
            code -= 20;
            dcode->buf[j] += 2;
        }
        if(code >= 10) {
            code -= 10;
            dcode->buf[j] += 1;
        }
        zassert(dcode->buf[j] <= '9', delta,
                "start=%x end=%x i=%x j=%x %s\n", start, end, i, j,
                _zbar_decoder_buf_dump(dcode->buf, dcode->code128.character));
        zassert(code <= 9, delta,
                "start=%x end=%x i=%x j=%x %s\n", start, end, i, j,
                _zbar_decoder_buf_dump(dcode->buf, dcode->code128.character));
        dcode->buf[j + 1] = '0' + code;
    }
    return(delta);
}

__attribute__((used)) static inline unsigned char postprocess (zbar_decoder_t *dcode)
{
    unsigned i, j, cexp;
    unsigned char code = 0, charset;
    code128_decoder_t *dcode128 = &dcode->code128;
    dbprintf(2, "\n    postproc len=%d", dcode128->character);
    dcode->modifiers = 0;
    dcode->direction = 1 - 2 * dcode128->direction;
    if(dcode128->direction) {
        /* reverse buffer */
        dbprintf(2, " (rev)");
        for(i = 0; i < dcode128->character / 2; i++) {
            unsigned j = dcode128->character - 1 - i;
            code = dcode->buf[i];
            dcode->buf[i] = dcode->buf[j];
            dcode->buf[j] = code;
        }
        zassert(dcode->buf[dcode128->character - 1] == STOP_REV, 1,
                "dir=%x %s\n", dcode128->direction,
                _zbar_decoder_buf_dump(dcode->buf, dcode->code128.character));
    }
    else
        zassert(dcode->buf[dcode128->character - 1] == STOP_FWD, 1,
                "dir=%x %s\n", dcode128->direction,
                _zbar_decoder_buf_dump(dcode->buf, dcode->code128.character));

    code = dcode->buf[0];
    zassert(code >= START_A && code <= START_C, 1, "%s\n",
            _zbar_decoder_buf_dump(dcode->buf, dcode->code128.character));

    charset = code - START_A;
    cexp = (code == START_C) ? 1 : 0;
    dbprintf(2, " start=%c", 'A' + charset);

    for(i = 1, j = 0; i < dcode128->character - 2; i++) {
        unsigned char code = dcode->buf[i];
        zassert(!(code & 0x80), 1,
                "i=%x j=%x code=%02x charset=%x cexp=%x %s\n",
                i, j, code, charset, cexp,
                _zbar_decoder_buf_dump(dcode->buf, dcode->code128.character));

        if((charset & 0x2) && (code < 100))
            /* defer character set C for expansion */
            continue;
        else if(code < 0x60) {
            /* convert character set B to ASCII */
            code = code + 0x20;
            if((!charset || (charset == 0x81)) && (code >= 0x60))
                /* convert character set A to ASCII */
                code -= 0x60;
            dcode->buf[j++] = code;
            if(charset & 0x80)
                charset &= 0x7f;
        }
        else {
            dbprintf(2, " %02x", code);
            if(charset & 0x2) {
                unsigned delta;
                /* expand character set C to ASCII */
                zassert(cexp, 1, "i=%x j=%x code=%02x charset=%x cexp=%x %s\n",
                        i, j, code, charset, cexp,
                        _zbar_decoder_buf_dump(dcode->buf,
                                                dcode->code128.character));
                delta = postprocess_c(dcode, cexp, i, j);
                i += delta;
                j += delta * 2;
                cexp = 0;
            }
            if(code < CODE_C) {
                if(code == SHIFT)
                    charset |= 0x80;
                else if(code == FNC2) {
                    /* FIXME FNC2 - message append */
                }
                else if(code == FNC3) {
                    /* FIXME FNC3 - initialize */
                }
            }
            else if(code == FNC1) {
                /* FNC1 - Code 128 subsets or ASCII 0x1d */
                if(i == 1)
                    dcode->modifiers |= MOD(ZBAR_MOD_GS1);
                else if(i == 2)
                    dcode->modifiers |= MOD(ZBAR_MOD_AIM);
                else if(i < dcode->code128.character - 3)
                    dcode->buf[j++] = 0x1d;
                /*else drop trailing FNC1 */
            }
            else if(code >= START_A) {
                dbprintf(1, " [truncated]\n");
                return(1);
            }
            else {
                unsigned char newset = CODE_A - code;
                zassert(code >= CODE_C && code <= CODE_A, 1,
                        "i=%x j=%x code=%02x charset=%x cexp=%x %s\n",
                        i, j, code, charset, cexp,
                        _zbar_decoder_buf_dump(dcode->buf,
                                                dcode->code128.character));
                if(newset != charset)
                    charset = newset;
                else {
                    /* FIXME FNC4 - extended ASCII */
                }
            }
            if(charset & 0x2)
                cexp = i + 1;
        }
    }
    if(charset & 0x2) {
        zassert(cexp, 1, "i=%x j=%x code=%02x charset=%x cexp=%x %s\n",
                i, j, code, charset, cexp,
                _zbar_decoder_buf_dump(dcode->buf,
                                        dcode->code128.character));
        j += postprocess_c(dcode, cexp, i, j) * 2;
    }
    zassert(j < dcode->buf_alloc, 1, "j=%02x %s\n", j,
            _zbar_decoder_buf_dump(dcode->buf, dcode->code128.character));
    dcode->buflen = j;
    dcode->buf[j] = '\0';
    dcode->code128.character = j;
    return(0);
}

zbar_symbol_type_t _zbar_decode_code128 (zbar_decoder_t *dcode)
{
    code128_decoder_t *dcode128 = &dcode->code128;
    signed char c;

    /* update latest character width */
    dcode128->s6 -= get_width(dcode, 6);
    dcode128->s6 += get_width(dcode, 0);

    if((dcode128->character < 0)
       ? get_color(dcode) != ZBAR_SPACE
       : (/* process every 6th element of active symbol */
          ++dcode128->element != 6 ||
          /* decode color based on direction */
          get_color(dcode) != dcode128->direction))
        return(0);
    dcode128->element = 0;

    dbprintf(2, "      code128[%c%02d+%x]:",
             (dcode128->direction) ? '<' : '>',
             dcode128->character, dcode128->element);

    c = decode6(dcode);
    if(dcode128->character < 0) {
        unsigned qz;
        dbprintf(2, " c=%02x", c);
        if(c < START_A || c > STOP_REV || c == STOP_FWD) {
            dbprintf(2, " [invalid]\n");
            return(0);
        }
        qz = get_width(dcode, 6);
        if(qz && qz < (dcode128->s6 * 3) / 4) {
            dbprintf(2, " [invalid qz %d]\n", qz);
            return(0);
        }
        /* decoded valid start/stop */
        /* initialize state */
        dcode128->character = 1;
        if(c == STOP_REV) {
            dcode128->direction = ZBAR_BAR;
            dcode128->element = 7;
        }
        else
            dcode128->direction = ZBAR_SPACE;
        dcode128->start = c;
        dcode128->width = dcode128->s6;
        dbprintf(2, " dir=%x [valid start]\n", dcode128->direction);
        return(0);
    }
    else if(c < 0 || size_buf(dcode, dcode128->character + 1)) {
        dbprintf(1, (c < 0) ? " [aborted]\n" : " [overflow]\n");
        if(dcode128->character > 1)
            release_lock(dcode, ZBAR_CODE128);
        dcode128->character = -1;
        return(0);
    }
    else {
        unsigned dw;
        if(dcode128->width > dcode128->s6)
            dw = dcode128->width - dcode128->s6;
        else
            dw = dcode128->s6 - dcode128->width;
        dw *= 4;
        if(dw > dcode128->width) {
            dbprintf(1, " [width var]\n");
            if(dcode128->character > 1)
                release_lock(dcode, ZBAR_CODE128);
            dcode128->character = -1;
            return(0);
        }
    }
    dcode128->width = dcode128->s6;

    zassert(dcode->buf_alloc > dcode128->character, 0,
            "alloc=%x idx=%x c=%02x %s\n",
            dcode->buf_alloc, dcode128->character, c,
            _zbar_decoder_buf_dump(dcode->buf, dcode->buf_alloc));

    if(dcode128->character == 1) {
        /* lock shared resources */
        if(acquire_lock(dcode, ZBAR_CODE128)) {
            dcode128->character = -1;
            return(0);
        }
        dcode->buf[0] = dcode128->start;
    }

    dcode->buf[dcode128->character++] = c;

    if(dcode128->character > 2 &&
       ((dcode128->direction)
        ? c >= START_A && c <= START_C
        : c == STOP_FWD)) {
        /* FIXME STOP_FWD should check extra bar (and QZ!) */
        zbar_symbol_type_t sym = ZBAR_CODE128;
        if(validate_checksum(dcode) || postprocess(dcode))
            sym = ZBAR_NONE;
        else if(dcode128->character < CFG(*dcode128, ZBAR_CFG_MIN_LEN) ||
                (CFG(*dcode128, ZBAR_CFG_MAX_LEN) > 0 &&
                 dcode128->character > CFG(*dcode128, ZBAR_CFG_MAX_LEN))) {
            dbprintf(2, " [invalid len]\n");
            sym = ZBAR_NONE;
        }
        else
            dbprintf(2, " [valid end]\n");
        dcode128->character = -1;
        if(!sym)
            release_lock(dcode, ZBAR_CODE128);
        return(sym);
    }

    dbprintf(2, "\n");
    return(0);
}

