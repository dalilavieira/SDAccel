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
typedef  size_t uint8_t ;
typedef  int uint32_t ;

/* Variables and functions */
#define  UTF8_ACCEPT 129 
#define  UTF8_REJECT 128 
 int* b64_decoding_table ; 
 int** charset_translations ; 
 int* utf8_data ; 

uint32_t*
translation_table(uint32_t which) {
    switch(which){
        case 'B':
            return charset_translations[0];
        case '0':
            return charset_translations[1];
        case 'U':
            return charset_translations[2];
        case 'V':
            return charset_translations[3];
        case 'A':
            return charset_translations[4];
        default:
            return charset_translations[0];
    }
}

uint32_t
decode_utf8(uint32_t* state, uint32_t* codep, uint8_t byte) {
  uint32_t type = utf8_data[byte];

  *codep = (*state != UTF8_ACCEPT) ?
    (byte & 0x3fu) | (*codep << 6) :
    (0xff >> type) & (byte);

  *state = utf8_data[256 + *state*16 + type];
  return *state;
}

size_t
decode_utf8_string(const char *src, size_t sz, uint32_t *dest) {
    // dest must be a zeroed array of size at least sz
    uint32_t codep = 0, state = 0, prev = UTF8_ACCEPT;
    size_t i, d;
    for (i = 0, d = 0; i < sz; i++) {
        switch(decode_utf8(&state, &codep, src[i])) {
            case UTF8_ACCEPT:
                dest[d++] = codep;
                break;
            case UTF8_REJECT:
                state = UTF8_ACCEPT;
                if (prev != UTF8_ACCEPT && i > 0) i--;
                break;
        }
        prev = state;
    }
    return d;
}

unsigned int
encode_utf8(uint32_t ch, char* dest) {
    if (ch < 0x80) {
        dest[0] = (char)ch;
        return 1;
    }
    if (ch < 0x800) {
        dest[0] = (ch>>6) | 0xC0;
        dest[1] = (ch & 0x3F) | 0x80;
        return 2;
    }
    if (ch < 0x10000) {
        dest[0] = (ch>>12) | 0xE0;
        dest[1] = ((ch>>6) & 0x3F) | 0x80;
        dest[2] = (ch & 0x3F) | 0x80;
        return 3;
    }
    if (ch < 0x110000) {
        dest[0] = (ch>>18) | 0xF0;
        dest[1] = ((ch>>12) & 0x3F) | 0x80;
        dest[2] = ((ch>>6) & 0x3F) | 0x80;
        dest[3] = (ch & 0x3F) | 0x80;
        return 4;
    }
    return 0;
}

const char*
base64_decode(const uint32_t *src, size_t src_sz, uint8_t *dest, size_t dest_capacity, size_t *dest_sz) {
    if (!src_sz) { *dest_sz = 0; return NULL; }
    if (src_sz % 4 != 0) return "base64 encoded data must have a length that is a multiple of four";
    *dest_sz = (src_sz / 4) * 3;
    if (src[src_sz - 1] == '=') (*dest_sz)--;
    if (src[src_sz - 2] == '=') (*dest_sz)--;
    if (*dest_sz > dest_capacity) return "output buffer too small";
    for (size_t i = 0, j = 0; i < src_sz;) {
        uint32_t sextet_a = src[i] == '=' ? 0 & i++ : b64_decoding_table[src[i++] & 0xff];
        uint32_t sextet_b = src[i] == '=' ? 0 & i++ : b64_decoding_table[src[i++] & 0xff];
        uint32_t sextet_c = src[i] == '=' ? 0 & i++ : b64_decoding_table[src[i++] & 0xff];
        uint32_t sextet_d = src[i] == '=' ? 0 & i++ : b64_decoding_table[src[i++] & 0xff];
        uint32_t triple = (sextet_a << 3 * 6) + (sextet_b << 2 * 6) + (sextet_c << 1 * 6) + (sextet_d << 0 * 6);

        if (j < *dest_sz) dest[j++] = (triple >> 2 * 8) & 0xFF;
        if (j < *dest_sz) dest[j++] = (triple >> 1 * 8) & 0xFF;
        if (j < *dest_sz) dest[j++] = (triple >> 0 * 8) & 0xFF;
    }
    return NULL;
}

