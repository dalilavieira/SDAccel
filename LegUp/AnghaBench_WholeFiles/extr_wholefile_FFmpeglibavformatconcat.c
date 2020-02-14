#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct concat_nodes {scalar_t__ size; int /*<<< orphan*/  uc; } ;
struct concat_data {size_t current; size_t length; struct concat_nodes* nodes; } ;
typedef  scalar_t__ int64_t ;
struct TYPE_4__ {struct concat_data* priv_data; } ;
typedef  TYPE_1__ URLContext ;

/* Variables and functions */
 scalar_t__ AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EOF ; 
 int /*<<< orphan*/  EINVAL ; 
#define  SEEK_CUR 130 
#define  SEEK_END 129 
#define  SEEK_SET 128 
 int ffurl_read (int /*<<< orphan*/ ,unsigned char*,int) ; 
 scalar_t__ ffurl_seek (int /*<<< orphan*/ ,scalar_t__,int const) ; 

__attribute__((used)) static int concat_read(URLContext *h, unsigned char *buf, int size)
{
    int result, total = 0;
    struct concat_data  *data  = h->priv_data;
    struct concat_nodes *nodes = data->nodes;
    size_t i                   = data->current;

    while (size > 0) {
        result = ffurl_read(nodes[i].uc, buf, size);
        if (result == AVERROR_EOF) {
            if (i + 1 == data->length ||
                ffurl_seek(nodes[++i].uc, 0, SEEK_SET) < 0)
                break;
            result = 0;
        }
        if (result < 0)
            return total ? total : result;
        total += result;
        buf   += result;
        size  -= result;
    }
    data->current = i;
    return total ? total : result;
}

__attribute__((used)) static int64_t concat_seek(URLContext *h, int64_t pos, int whence)
{
    int64_t result;
    struct concat_data  *data  = h->priv_data;
    struct concat_nodes *nodes = data->nodes;
    size_t i;

    switch (whence) {
    case SEEK_END:
        for (i = data->length - 1; i && pos < -nodes[i].size; i--)
            pos += nodes[i].size;
        break;
    case SEEK_CUR:
        /* get the absolute position */
        for (i = 0; i != data->current; i++)
            pos += nodes[i].size;
        pos += ffurl_seek(nodes[i].uc, 0, SEEK_CUR);
        whence = SEEK_SET;
        /* fall through with the absolute position */
    case SEEK_SET:
        for (i = 0; i != data->length - 1 && pos >= nodes[i].size; i++)
            pos -= nodes[i].size;
        break;
    default:
        return AVERROR(EINVAL);
    }

    result = ffurl_seek(nodes[i].uc, pos, whence);
    if (result >= 0) {
        data->current = i;
        while (i)
            result += nodes[--i].size;
    }
    return result;
}

