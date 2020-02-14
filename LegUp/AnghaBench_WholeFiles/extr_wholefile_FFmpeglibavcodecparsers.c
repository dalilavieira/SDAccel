#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {struct TYPE_7__* next; } ;
typedef  TYPE_1__ AVCodecParser ;

/* Variables and functions */
 int /*<<< orphan*/  av_parser_next_init ; 
 int /*<<< orphan*/  ff_thread_once (int /*<<< orphan*/ *,void (*) ()) ; 
 TYPE_1__** parser_list ; 

__attribute__((used)) static void av_parser_init_next(void)
{
    AVCodecParser *prev = NULL, *p;
    int i = 0;
    while ((p = (AVCodecParser*)parser_list[i++])) {
        if (prev)
            prev->next = p;
        prev = p;
    }
}

AVCodecParser *av_parser_next(const AVCodecParser *p)
{
    ff_thread_once(&av_parser_next_init, av_parser_init_next);

    if (p)
        return p->next;
    else
        return (AVCodecParser*)parser_list[0];
}

const AVCodecParser *av_parser_iterate(void **opaque)
{
    uintptr_t i = (uintptr_t)*opaque;
    const AVCodecParser *p = parser_list[i];

    if (p)
        *opaque = (void*)(i + 1);

    return p;
}

void av_register_codec_parser(AVCodecParser *parser)
{
    ff_thread_once(&av_parser_next_init, av_parser_init_next);
}

