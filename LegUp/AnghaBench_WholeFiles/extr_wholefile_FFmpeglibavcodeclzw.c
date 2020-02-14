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
typedef  int /*<<< orphan*/  uint8_t ;
struct LZWState {scalar_t__ bbits; scalar_t__ cursize; int end_code; scalar_t__ mode; int bs; int bbuf; int curmask; int codesize; int top_slot; int clear_code; int slot; int newcodes; int oc; int fc; int extra_slot; int* suffix; int* prefix; int /*<<< orphan*/ * sp; int /*<<< orphan*/ * stack; int /*<<< orphan*/  gb; } ;
typedef  int /*<<< orphan*/  LZWState ;

/* Variables and functions */
 scalar_t__ FF_LZW_GIF ; 
 int FF_LZW_TIFF ; 
 int LZW_MAXBITS ; 
 int bytestream2_get_byte (int /*<<< orphan*/ *) ; 
 scalar_t__ bytestream2_get_bytes_left (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  bytestream2_skip (int /*<<< orphan*/ *,scalar_t__) ; 
 int bytestream2_tell (int /*<<< orphan*/ *) ; 
 void** mask ; 

__attribute__((used)) static int lzw_get_code(struct LZWState * s)
{
    int c;

    if (s->bbits < s->cursize && bytestream2_get_bytes_left(&s->gb) <= 0)
        return s->end_code;

    if(s->mode == FF_LZW_GIF) {
        while (s->bbits < s->cursize) {
            if (!s->bs) {
                s->bs = bytestream2_get_byte(&s->gb);
            }
            s->bbuf |= bytestream2_get_byte(&s->gb) << s->bbits;
            s->bbits += 8;
            s->bs--;
        }
        c = s->bbuf;
        s->bbuf >>= s->cursize;
    } else { // TIFF
        while (s->bbits < s->cursize) {
            s->bbuf = (s->bbuf << 8) | bytestream2_get_byte(&s->gb);
            s->bbits += 8;
        }
        c = s->bbuf >> (s->bbits - s->cursize);
    }
    s->bbits -= s->cursize;
    return c & s->curmask;
}

int ff_lzw_decode_tail(LZWState *p)
{
    struct LZWState *s = (struct LZWState *)p;

    if(s->mode == FF_LZW_GIF) {
        while (s->bs > 0 && bytestream2_get_bytes_left(&s->gb)) {
            bytestream2_skip(&s->gb, s->bs);
            s->bs = bytestream2_get_byte(&s->gb);
        }
    }else
        bytestream2_skip(&s->gb, bytestream2_get_bytes_left(&s->gb));
    return bytestream2_tell(&s->gb);
}

int ff_lzw_decode_init(LZWState *p, int csize, const uint8_t *buf, int buf_size, int mode)
{
    struct LZWState *s = (struct LZWState *)p;

    if(csize < 1 || csize >= LZW_MAXBITS)
        return -1;
    /* read buffer */
    bytestream2_init(&s->gb, buf, buf_size);
    s->bbuf = 0;
    s->bbits = 0;
    s->bs = 0;

    /* decoder */
    s->codesize = csize;
    s->cursize = s->codesize + 1;
    s->curmask = mask[s->cursize];
    s->top_slot = 1 << s->cursize;
    s->clear_code = 1 << s->codesize;
    s->end_code = s->clear_code + 1;
    s->slot = s->newcodes = s->clear_code + 2;
    s->oc = s->fc = -1;
    s->sp = s->stack;

    s->mode = mode;
    s->extra_slot = s->mode == FF_LZW_TIFF;
    return 0;
}

int ff_lzw_decode(LZWState *p, uint8_t *buf, int len){
    int l, c, code, oc, fc;
    uint8_t *sp;
    struct LZWState *s = (struct LZWState *)p;

    if (s->end_code < 0)
        return 0;

    l = len;
    sp = s->sp;
    oc = s->oc;
    fc = s->fc;

    for (;;) {
        while (sp > s->stack) {
            *buf++ = *(--sp);
            if ((--l) == 0)
                goto the_end;
        }
        c = lzw_get_code(s);
        if (c == s->end_code) {
            break;
        } else if (c == s->clear_code) {
            s->cursize = s->codesize + 1;
            s->curmask = mask[s->cursize];
            s->slot = s->newcodes;
            s->top_slot = 1 << s->cursize;
            fc= oc= -1;
        } else {
            code = c;
            if (code == s->slot && fc>=0) {
                *sp++ = fc;
                code = oc;
            }else if(code >= s->slot)
                break;
            while (code >= s->newcodes) {
                *sp++ = s->suffix[code];
                code = s->prefix[code];
            }
            *sp++ = code;
            if (s->slot < s->top_slot && oc>=0) {
                s->suffix[s->slot] = code;
                s->prefix[s->slot++] = oc;
            }
            fc = code;
            oc = c;
            if (s->slot >= s->top_slot - s->extra_slot) {
                if (s->cursize < LZW_MAXBITS) {
                    s->top_slot <<= 1;
                    s->curmask = mask[++s->cursize];
                }
            }
        }
    }
    s->end_code = -1;
  the_end:
    s->sp = sp;
    s->oc = oc;
    s->fc = fc;
    return len - l;
}

