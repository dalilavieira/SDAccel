#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct TYPE_16__ {scalar_t__ len; int /*<<< orphan*/  base; } ;
typedef  TYPE_2__ ptls_iovec_t ;
struct TYPE_15__ {size_t count; TYPE_2__* list; } ;
struct TYPE_17__ {TYPE_1__ certificates; } ;
typedef  TYPE_3__ ptls_context_t ;
struct TYPE_18__ {scalar_t__ off; int /*<<< orphan*/  base; scalar_t__ is_allocated; } ;
typedef  TYPE_4__ ptls_buffer_t ;
struct TYPE_19__ {int nbc; int nbo; int v; scalar_t__ status; } ;
typedef  TYPE_5__ ptls_base64_decode_state_t ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 scalar_t__ PTLS_BASE64_DECODE_DONE ; 
 void* PTLS_BASE64_DECODE_FAILED ; 
 scalar_t__ PTLS_BASE64_DECODE_IN_PROGRESS ; 
 int PTLS_ERROR_INCORRECT_BASE64 ; 
 int PTLS_ERROR_NO_MEMORY ; 
 int PTLS_ERROR_PEM_LABEL_NOT_FOUND ; 
 int PTLS_MAX_CERTS_IN_CONTEXT ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 scalar_t__ fgets (char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 scalar_t__ malloc (int) ; 
 char* ptls_base64_alphabet ; 
 int* ptls_base64_values ; 
 int ptls_buffer__do_pushv (TYPE_4__*,int*,int) ; 
 int /*<<< orphan*/  ptls_buffer_dispose (TYPE_4__*) ; 
 int /*<<< orphan*/  ptls_buffer_init (TYPE_4__*,char*,int /*<<< orphan*/ ) ; 
 size_t strlen (char const*) ; 
 int strncmp (char const*,char const*,int) ; 

__attribute__((used)) static void ptls_base64_cell(const uint8_t *data, char *text)
{
    int n[4];

    n[0] = data[0] >> 2;
    n[1] = ((data[0] & 3) << 4) | (data[1] >> 4);
    n[2] = ((data[1] & 15) << 2) | (data[2] >> 6);
    n[3] = data[2] & 63;

    for (int i = 0; i < 4; i++) {
        text[i] = ptls_base64_alphabet[n[i]];
    }
}

size_t ptls_base64_howlong(size_t data_length)
{
    return (((data_length + 2) / 3) * 4);
}

int ptls_base64_encode(const uint8_t *data, size_t data_len, char *ptls_base64_text)
{
    int l = 0;
    int lt = 0;

    while ((data_len - l) >= 3) {
        ptls_base64_cell(data + l, ptls_base64_text + lt);
        l += 3;
        lt += 4;
    }

    switch (data_len - l) {
    case 0:
        break;
    case 1:
        ptls_base64_text[lt++] = ptls_base64_alphabet[data[l] >> 2];
        ptls_base64_text[lt++] = ptls_base64_alphabet[(data[l] & 3) << 4];
        ptls_base64_text[lt++] = '=';
        ptls_base64_text[lt++] = '=';
        break;
    case 2:
        ptls_base64_text[lt++] = ptls_base64_alphabet[data[l] >> 2];
        ptls_base64_text[lt++] = ptls_base64_alphabet[((data[l] & 3) << 4) | (data[l + 1] >> 4)];
        ptls_base64_text[lt++] = ptls_base64_alphabet[((data[l + 1] & 15) << 2)];
        ptls_base64_text[lt++] = '=';
        break;
    default:
        break;
    }
    ptls_base64_text[lt++] = 0;

    return lt;
}

void ptls_base64_decode_init(ptls_base64_decode_state_t *state)
{
    state->nbc = 0;
    state->nbo = 3;
    state->v = 0;
    state->status = PTLS_BASE64_DECODE_IN_PROGRESS;
}

int ptls_base64_decode(const char *text, ptls_base64_decode_state_t *state, ptls_buffer_t *buf)
{
    int ret = 0;
    uint8_t decoded[3];
    size_t text_index = 0;
    int c;
    signed char vc;

    /* skip initial blanks */
    while (text[text_index] != 0) {
        c = text[text_index];

        if (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
            text_index++;
        } else {
            break;
        }
    }

    while (text[text_index] != 0 && ret == 0 && state->status == PTLS_BASE64_DECODE_IN_PROGRESS) {
        c = text[text_index++];

        vc = 0 < c && c < 0x7f ? ptls_base64_values[c] : -1;
        if (vc == -1) {
            if (state->nbc == 2 && c == '=' && text[text_index] == '=') {
                state->nbc = 4;
                text_index++;
                state->nbo = 1;
                state->v <<= 12;
            } else if (state->nbc == 3 && c == '=') {
                state->nbc = 4;
                state->nbo = 2;
                state->v <<= 6;
            } else {
                /* Skip final blanks */
                for (--text_index; text[text_index] != 0; ++text_index) {
                    c = text[text_index];
                    if (!(c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == 0x0B || c == 0x0C))
                        break;
                }

                /* Should now be at end of buffer */
                if (text[text_index] == 0) {
                    break;
                } else {
                    /* Not at end of buffer, signal a decoding error */
                    state->nbo = 0;
                    state->status = PTLS_BASE64_DECODE_FAILED;
                    ret = PTLS_ERROR_INCORRECT_BASE64;
                }
            }
        } else {
            state->nbc++;
            state->v <<= 6;
            state->v |= vc;
        }

        if (ret == 0 && state->nbc == 4) {
            /* Convert to up to 3 octets */
            for (int j = 0; j < state->nbo; j++) {
                decoded[j] = (uint8_t)(state->v >> (8 * (2 - j)));
            }

            ret = ptls_buffer__do_pushv(buf, decoded, state->nbo);

            if (ret == 0) {
                /* test for fin or continuation */
                if (state->nbo < 3) {
                    /* Check that there are only trainling blanks on this line */
                    while (text[text_index] != 0) {
                        c = text[text_index++];

                        if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == 0x0B || c == 0x0C) {
                            continue;
                        }
                    }
                    if (text[text_index] == 0) {
                        state->status = PTLS_BASE64_DECODE_DONE;
                    } else {
                        state->status = PTLS_BASE64_DECODE_FAILED;
                        ret = PTLS_ERROR_INCORRECT_BASE64;
                    }
                    break;
                } else {
                    state->v = 0;
                    state->nbo = 3;
                    state->nbc = 0;
                }
            }
        }
    }
    return ret;
}

__attribute__((used)) static int ptls_compare_separator_line(const char *line, const char *begin_or_end, const char *label)
{
    int ret = strncmp(line, "-----", 5);
    size_t text_index = 5;

    if (ret == 0) {
        size_t begin_or_end_length = strlen(begin_or_end);
        ret = strncmp(line + text_index, begin_or_end, begin_or_end_length);
        text_index += begin_or_end_length;
    }

    if (ret == 0) {
        ret = line[text_index] - ' ';
        text_index++;
    }

    if (ret == 0) {
        size_t label_length = strlen(label);
        ret = strncmp(line + text_index, label, label_length);
        text_index += label_length;
    }

    if (ret == 0) {
        ret = strncmp(line + text_index, "-----", 5);
    }

    return ret;
}

__attribute__((used)) static int ptls_get_pem_object(FILE *F, const char *label, ptls_buffer_t *buf)
{
    int ret = PTLS_ERROR_PEM_LABEL_NOT_FOUND;
    char line[256];
    ptls_base64_decode_state_t state;

    /* Get the label on a line by itself */
    while (fgets(line, 256, F)) {
        if (ptls_compare_separator_line(line, "BEGIN", label) == 0) {
            ret = 0;
            ptls_base64_decode_init(&state);
            break;
        }
    }
    /* Get the data in the buffer */
    while (ret == 0 && fgets(line, 256, F)) {
        if (ptls_compare_separator_line(line, "END", label) == 0) {
            if (state.status == PTLS_BASE64_DECODE_DONE || (state.status == PTLS_BASE64_DECODE_IN_PROGRESS && state.nbc == 0)) {
                ret = 0;
            } else {
                ret = PTLS_ERROR_INCORRECT_BASE64;
            }
            break;
        } else {
            ret = ptls_base64_decode(line, &state, buf);
        }
    }

    return ret;
}

int ptls_load_pem_objects(char const *pem_fname, const char *label, ptls_iovec_t *list, size_t list_max, size_t *nb_objects)
{
    FILE *F;
    int ret = 0;
    size_t count = 0;
#ifdef _WINDOWS
    errno_t err = fopen_s(&F, pem_fname, "r");
    if (err != 0) {
        ret = -1;
    }
#else
    F = fopen(pem_fname, "r");
    if (F == NULL) {
        ret = -1;
    }
#endif

    *nb_objects = 0;

    if (ret == 0) {
        while (count < list_max) {
            ptls_buffer_t buf;

            ptls_buffer_init(&buf, "", 0);

            ret = ptls_get_pem_object(F, label, &buf);

            if (ret == 0) {
                if (buf.off > 0 && buf.is_allocated) {
                    list[count].base = buf.base;
                    list[count].len = buf.off;
                    count++;
                } else {
                    ptls_buffer_dispose(&buf);
                }
            } else {
                ptls_buffer_dispose(&buf);
                break;
            }
        }
    }

    if (ret == PTLS_ERROR_PEM_LABEL_NOT_FOUND && count > 0) {
        ret = 0;
    }

    *nb_objects = count;

    if (F != NULL) {
        fclose(F);
    }

    return ret;
}

int ptls_load_certificates(ptls_context_t *ctx, char const *cert_pem_file)
{
    int ret = 0;

    ctx->certificates.list = (ptls_iovec_t *)malloc(PTLS_MAX_CERTS_IN_CONTEXT * sizeof(ptls_iovec_t));

    if (ctx->certificates.list == NULL) {
        ret = PTLS_ERROR_NO_MEMORY;
    } else {
        ret = ptls_load_pem_objects(cert_pem_file, "CERTIFICATE", ctx->certificates.list, PTLS_MAX_CERTS_IN_CONTEXT,
                                    &ctx->certificates.count);
    }

    return ret;
}

