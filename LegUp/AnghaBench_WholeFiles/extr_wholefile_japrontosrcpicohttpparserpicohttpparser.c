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
struct phr_header {char const* name; int name_len; char* value; size_t value_len; } ;
struct phr_chunked_decoder {int _state; int _hex_count; int bytes_left_in_chunk; int /*<<< orphan*/  consume_trailer; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  ranges1 ;

/* Variables and functions */
 int /*<<< orphan*/  ADVANCE_TOKEN (char const*,size_t) ; 
 int /*<<< orphan*/  CHECK_EOF () ; 
#define  CHUNKED_IN_CHUNK_CRLF 133 
#define  CHUNKED_IN_CHUNK_DATA 132 
#define  CHUNKED_IN_CHUNK_EXT 131 
#define  CHUNKED_IN_CHUNK_SIZE 130 
#define  CHUNKED_IN_TRAILERS_LINE_HEAD 129 
#define  CHUNKED_IN_TRAILERS_LINE_MIDDLE 128 
 int /*<<< orphan*/  EXPECT_CHAR (char) ; 
 int /*<<< orphan*/  IS_PRINTABLE_ASCII (char const) ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  memmove (char*,char*,size_t) ; 
 int /*<<< orphan*/ * token_char_map ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static const char *findchar_fast(const char *buf, const char *buf_end, const char *ranges, size_t ranges_size, int *found)
{
    *found = 0;
#if __SSE4_2__
    if (likely(buf_end - buf >= 16)) {
        __m128i ranges16 = _mm_loadu_si128((const __m128i *)ranges);

        size_t left = (buf_end - buf) & ~15;
        do {
            __m128i b16 = _mm_loadu_si128((void *)buf);
            int r = _mm_cmpestri(ranges16, ranges_size, b16, 16, _SIDD_LEAST_SIGNIFICANT | _SIDD_CMP_RANGES | _SIDD_UBYTE_OPS);
            if (unlikely(r != 16)) {
                buf += r;
                *found = 1;
                break;
            }
            buf += 16;
            left -= 16;
        } while (likely(left != 0));
    }
#else
    /* suppress unused parameter warning */
    (void)buf_end;
    (void)ranges;
    (void)ranges_size;
#endif
    return buf;
}

__attribute__((used)) static const char *get_token_to_eol(const char *buf, const char *buf_end, const char **token, size_t *token_len, int *ret)
{
    const char *token_start = buf;

#ifdef __SSE4_2__
    static const char ranges1[] = "\0\010"
                                  /* allow HT */
                                  "\012\037"
                                  /* allow SP and up to but not including DEL */
                                  "\177\177"
        /* allow chars w. MSB set */
        ;
    int found;
    buf = findchar_fast(buf, buf_end, ranges1, sizeof(ranges1) - 1, &found);
    if (found)
        goto FOUND_CTL;
#else
    /* find non-printable char within the next 8 bytes, this is the hottest code; manually inlined */
    while (likely(buf_end - buf >= 8)) {
#define DOIT()                                                                                                                     \
    do {                                                                                                                           \
        if (unlikely(!IS_PRINTABLE_ASCII(*buf)))                                                                                   \
            goto NonPrintable;                                                                                                     \
        ++buf;                                                                                                                     \
    } while (0)
        DOIT();
        DOIT();
        DOIT();
        DOIT();
        DOIT();
        DOIT();
        DOIT();
        DOIT();
#undef DOIT
        continue;
    NonPrintable:
        if ((likely((unsigned char)*buf < '\040') && likely(*buf != '\011')) || unlikely(*buf == '\177')) {
            goto FOUND_CTL;
        }
        ++buf;
    }
#endif
    for (;; ++buf) {
        CHECK_EOF();
        if (unlikely(!IS_PRINTABLE_ASCII(*buf))) {
            if ((likely((unsigned char)*buf < '\040') && likely(*buf != '\011')) || unlikely(*buf == '\177')) {
                goto FOUND_CTL;
            }
        }
    }
FOUND_CTL:
    if (likely(*buf == '\015')) {
        ++buf;
        EXPECT_CHAR('\012');
        *token_len = buf - 2 - token_start;
    } else if (*buf == '\012') {
        *token_len = buf - token_start;
        ++buf;
    } else {
        *ret = -1;
        return NULL;
    }
    *token = token_start;

    return buf;
}

__attribute__((used)) static const char *is_complete(const char *buf, const char *buf_end, size_t last_len, int *ret)
{
    int ret_cnt = 0;
    buf = last_len < 3 ? buf : buf + last_len - 3;

    while (1) {
        CHECK_EOF();
        if (*buf == '\015') {
            ++buf;
            CHECK_EOF();
            EXPECT_CHAR('\012');
            ++ret_cnt;
        } else if (*buf == '\012') {
            ++buf;
            ++ret_cnt;
        } else {
            ++buf;
            ret_cnt = 0;
        }
        if (ret_cnt == 2) {
            return buf;
        }
    }

    *ret = -2;
    return NULL;
}

__attribute__((used)) static const char *parse_int(const char *buf, const char *buf_end, int *value, int *ret)
{
    int v;
    CHECK_EOF();
    if (!('0' <= *buf && *buf <= '9')) {
        *ret = -1;
        return NULL;
    }
    v = 0;
    for (;; ++buf) {
        CHECK_EOF();
        if ('0' <= *buf && *buf <= '9') {
            v = v * 10 + *buf - '0';
        } else {
            break;
        }
    }

    *value = v;
    return buf;
}

__attribute__((used)) static const char *parse_http_version(const char *buf, const char *buf_end, int *minor_version, int *ret)
{
    EXPECT_CHAR('H');
    EXPECT_CHAR('T');
    EXPECT_CHAR('T');
    EXPECT_CHAR('P');
    EXPECT_CHAR('/');
    EXPECT_CHAR('1');
    EXPECT_CHAR('.');
    return parse_int(buf, buf_end, minor_version, ret);
}

__attribute__((used)) static const char *parse_headers(const char *buf, const char *buf_end, struct phr_header *headers, size_t *num_headers,
                                 size_t max_headers, int *ret)
{
    for (;; ++*num_headers) {
        CHECK_EOF();
        if (*buf == '\015') {
            ++buf;
            EXPECT_CHAR('\012');
            break;
        } else if (*buf == '\012') {
            ++buf;
            break;
        }
        if (*num_headers == max_headers) {
            *ret = -1;
            return NULL;
        }
        if (!(*num_headers != 0 && (*buf == ' ' || *buf == '\t'))) {
            /* parsing name, but do not discard SP before colon, see
             * http://www.mozilla.org/security/announce/2006/mfsa2006-33.html */
            headers[*num_headers].name = buf;
            static const char ranges1[] __attribute__((aligned(16))) = "\x00 "  /* control chars and up to SP */
                                                                       "\"\""   /* 0x22 */
                                                                       "()"     /* 0x28,0x29 */
                                                                       ",,"     /* 0x2c */
                                                                       "//"     /* 0x2f */
                                                                       ":@"     /* 0x3a-0x40 */
                                                                       "[]"     /* 0x5b-0x5d */
                                                                       "{\377"; /* 0x7b-0xff */
            int found;
            buf = findchar_fast(buf, buf_end, ranges1, sizeof(ranges1) - 1, &found);
            if (!found) {
                CHECK_EOF();
            }
            while (1) {
                if (*buf == ':') {
                    break;
                } else if (!token_char_map[(unsigned char)*buf]) {
                    *ret = -1;
                    return NULL;
                }
                ++buf;
                CHECK_EOF();
            }
            if ((headers[*num_headers].name_len = buf - headers[*num_headers].name) == 0) {
                *ret = -1;
                return NULL;
            }
            ++buf;
            for (;; ++buf) {
                CHECK_EOF();
                if (!(*buf == ' ' || *buf == '\t')) {
                    break;
                }
            }
        } else {
            headers[*num_headers].name = NULL;
            headers[*num_headers].name_len = 0;
        }
        if ((buf = get_token_to_eol(buf, buf_end, &headers[*num_headers].value, &headers[*num_headers].value_len, ret)) == NULL) {
            return NULL;
        }
    }
    return buf;
}

__attribute__((used)) static const char *parse_request(const char *buf, const char *buf_end, const char **method, size_t *method_len, const char **path,
                                 size_t *path_len, int *minor_version, struct phr_header *headers, size_t *num_headers,
                                 size_t max_headers, int *ret)
{
    /* skip first empty line (some clients add CRLF after POST content) */
    CHECK_EOF();
    if (*buf == '\015') {
        ++buf;
        EXPECT_CHAR('\012');
    } else if (*buf == '\012') {
        ++buf;
    }

    /* parse request line */
    ADVANCE_TOKEN(*method, *method_len);
    ++buf;
    ADVANCE_TOKEN(*path, *path_len);
    ++buf;
    if ((buf = parse_http_version(buf, buf_end, minor_version, ret)) == NULL) {
        return NULL;
    }
    if (*buf == '\015') {
        ++buf;
        EXPECT_CHAR('\012');
    } else if (*buf == '\012') {
        ++buf;
    } else {
        *ret = -1;
        return NULL;
    }

    return parse_headers(buf, buf_end, headers, num_headers, max_headers, ret);
}

int PHR_PARSE_REQUEST(const char *buf_start, size_t len, const char **method, size_t *method_len, const char **path,
                      size_t *path_len, int *minor_version, struct phr_header *headers, size_t *num_headers, size_t last_len)
{
    const char *buf = buf_start, *buf_end = buf_start + len;
    size_t max_headers = *num_headers;
    int r;

    *method = NULL;
    *method_len = 0;
    *path = NULL;
    *path_len = 0;
    *minor_version = -1;
    *num_headers = 0;

    /* if last_len != 0, check if the request is complete (a fast countermeasure
       against slowloris */
    if (last_len != 0 && is_complete(buf, buf_end, last_len, &r) == NULL) {
        return r;
    }

    if ((buf = parse_request(buf, buf_end, method, method_len, path, path_len, minor_version, headers, num_headers, max_headers,
                             &r)) == NULL) {
        return r;
    }

    return (int)(buf - buf_start);
}

__attribute__((used)) static int decode_hex(int ch)
{
    if ('0' <= ch && ch <= '9') {
        return ch - '0';
    } else if ('A' <= ch && ch <= 'F') {
        return ch - 'A' + 0xa;
    } else if ('a' <= ch && ch <= 'f') {
        return ch - 'a' + 0xa;
    } else {
        return -1;
    }
}

ssize_t phr_decode_chunked(struct phr_chunked_decoder *decoder, char *buf, size_t *_bufsz)
{
    size_t dst = 0, src = 0, bufsz = *_bufsz;
    ssize_t ret = -2; /* incomplete */

    while (1) {
        switch (decoder->_state) {
        case CHUNKED_IN_CHUNK_SIZE:
            for (;; ++src) {
                int v;
                if (src == bufsz)
                    goto Exit;
                if ((v = decode_hex(buf[src])) == -1) {
                    if (decoder->_hex_count == 0) {
                        ret = -1;
                        goto Exit;
                    }
                    break;
                }
                if (decoder->_hex_count == sizeof(size_t) * 2) {
                    ret = -1;
                    goto Exit;
                }
                decoder->bytes_left_in_chunk = decoder->bytes_left_in_chunk * 16 + v;
                ++decoder->_hex_count;
            }
            decoder->_hex_count = 0;
            decoder->_state = CHUNKED_IN_CHUNK_EXT;
        /* fallthru */
        case CHUNKED_IN_CHUNK_EXT:
            /* RFC 7230 A.2 "Line folding in chunk extensions is disallowed" */
            for (;; ++src) {
                if (src == bufsz)
                    goto Exit;
                if (buf[src] == '\012')
                    break;
            }
            ++src;
            if (decoder->bytes_left_in_chunk == 0) {
                if (decoder->consume_trailer) {
                    decoder->_state = CHUNKED_IN_TRAILERS_LINE_HEAD;
                    break;
                } else {
                    goto Complete;
                }
            }
            decoder->_state = CHUNKED_IN_CHUNK_DATA;
        /* fallthru */
        case CHUNKED_IN_CHUNK_DATA: {
            size_t avail = bufsz - src;
            if (avail < decoder->bytes_left_in_chunk) {
                if (dst != src)
                    memmove(buf + dst, buf + src, avail);
                src += avail;
                dst += avail;
                decoder->bytes_left_in_chunk -= avail;
                goto Exit;
            }
            if (dst != src)
                memmove(buf + dst, buf + src, decoder->bytes_left_in_chunk);
            src += decoder->bytes_left_in_chunk;
            dst += decoder->bytes_left_in_chunk;
            decoder->bytes_left_in_chunk = 0;
            decoder->_state = CHUNKED_IN_CHUNK_CRLF;
        }
        /* fallthru */
        case CHUNKED_IN_CHUNK_CRLF:
            for (;; ++src) {
                if (src == bufsz)
                    goto Exit;
                if (buf[src] != '\015')
                    break;
            }
            if (buf[src] != '\012') {
                ret = -1;
                goto Exit;
            }
            ++src;
            decoder->_state = CHUNKED_IN_CHUNK_SIZE;
            break;
        case CHUNKED_IN_TRAILERS_LINE_HEAD:
            for (;; ++src) {
                if (src == bufsz)
                    goto Exit;
                if (buf[src] != '\015')
                    break;
            }
            if (buf[src++] == '\012')
                goto Complete;
            decoder->_state = CHUNKED_IN_TRAILERS_LINE_MIDDLE;
        /* fallthru */
        case CHUNKED_IN_TRAILERS_LINE_MIDDLE:
            for (;; ++src) {
                if (src == bufsz)
                    goto Exit;
                if (buf[src] == '\012')
                    break;
            }
            ++src;
            decoder->_state = CHUNKED_IN_TRAILERS_LINE_HEAD;
            break;
        default:
            assert(!"decoder is corrupt");
        }
    }

Complete:
    ret = bufsz - src;
Exit:
    if (dst != src)
        memmove(buf + dst, buf + src, bufsz - src);
    *_bufsz = dst;
    return ret;
}

