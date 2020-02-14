#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  utf8_char_t ;
typedef  scalar_t__ uint16_t ;
struct TYPE_10__ {unsigned int cc_aloc; double timestamp; unsigned int cc_size; scalar_t__* cc_data; } ;
typedef  TYPE_1__ scc_t ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 scalar_t__ realloc (TYPE_1__*,int) ; 
 int sscanf (int /*<<< orphan*/  const*,char*,int*,...) ; 
 size_t utf8_line_length (int /*<<< orphan*/  const*) ; 
 size_t utf8_trimmed_length (int /*<<< orphan*/  const*,size_t) ; 

__attribute__((used)) static scc_t* scc_relloc(scc_t* scc, unsigned int cc_count)
{
    if (0 == scc || scc->cc_aloc < cc_count) {
        // alloc 1.5 time what is asked for.
        scc = (scc_t*)realloc(scc, sizeof(scc_t) + ((cc_count * 15 / 10) * sizeof(uint16_t)));
        scc->cc_aloc = cc_count;
    }

    return scc;
}

scc_t* scc_new(int cc_count)
{
    scc_t* scc = scc_relloc(0, cc_count);
    scc->timestamp = 0.0;
    scc->cc_size = 0;
    return scc;
}

scc_t* scc_free(scc_t* scc)
{
    free(scc);
    return NULL;
}

double scc_time_to_timestamp(int hh, int mm, int ss, int ff)
{
    return (hh * 3600.0) + (mm * 60.0) + ss + (ff / 29.97);
}

size_t scc_to_608(scc_t** scc, const utf8_char_t* data)
{
    size_t llen, size = 0;
    int v1 = 0, v2 = 0, hh = 0, mm = 0, ss = 0, ff = 0, cc_data = 0;

    if (0 == data) {
        return 0;
    }

    if ((*scc)) {
        (*scc)->cc_size = 0;
    }

    // skip 'Scenarist_SCC V1.0' header
    if (2 == sscanf(data, "Scenarist_SCC V%1d.%1d", &v1, &v2)) {
        data += 18, size += 18;

        if (1 != v1 || 0 != v2) {
            return 0;
        }
    }

    // Skip blank lines
    for (;;) {
        llen = utf8_line_length(data);

        if (0 == llen || 0 != utf8_trimmed_length(data, llen)) {
            break;
        }

        data += llen;
        size += llen;
    }

    if (4 == sscanf(data, "%2d:%2d:%2d%*1[:;]%2d", &hh, &mm, &ss, &ff)) {
        data += 12, size += 12;
        // Get length of the remaining charcters
        llen = utf8_line_length(data);
        llen = utf8_trimmed_length(data, llen);
        unsigned int max_cc_count = 1 + ((unsigned int)llen / 5);
        (*scc) = scc_relloc((*scc), max_cc_count * 15 / 10);
        (*scc)->timestamp = scc_time_to_timestamp(hh, mm, ss, ff);
        (*scc)->cc_size = 0;

        while ((*scc)->cc_size < max_cc_count && 1 == sscanf(data, "%04x", &cc_data)) {
            (*scc)->cc_data[(*scc)->cc_size] = (uint16_t)cc_data;
            (*scc)->cc_size += 1;
            data += 5, size += 5;
        }
    }

    return size;
}

