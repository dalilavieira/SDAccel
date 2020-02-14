#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vtt_t ;
struct TYPE_9__ {scalar_t__ duration; scalar_t__ timestamp; struct TYPE_9__* next; } ;
typedef  TYPE_1__ vtt_block_t ;
typedef  int /*<<< orphan*/  utf8_char_t ;
struct TYPE_10__ {TYPE_1__* cue_head; } ;
typedef  TYPE_2__ srt_t ;

/* Variables and functions */
 int /*<<< orphan*/ * _vtt_parse (int /*<<< orphan*/  const*,size_t,int) ; 
 int /*<<< orphan*/  printf (char*,int,int,int,int,int,int,int,int,int,char*) ; 
 char* vtt_block_data (TYPE_1__*) ; 
 int /*<<< orphan*/  vtt_crack_time (scalar_t__,int*,int*,int*,int*) ; 
 int /*<<< orphan*/  vtt_free (TYPE_2__*) ; 
 TYPE_2__* vtt_new () ; 

srt_t* srt_new()
{
    return vtt_new();
}

void srt_free(srt_t* srt)
{
    vtt_free(srt);
}

vtt_t* srt_parse(const utf8_char_t* data, size_t size)
{
    return _vtt_parse(data, size, 1);
}

void srt_dump(srt_t* srt)
{
    int i;
    vtt_block_t* block;

    for (block = srt->cue_head, i = 1; block; block = block->next, ++i) {
        int hh1, hh2, mm1, mm2, ss1, ss2, ms1, ms2;
        vtt_crack_time(block->timestamp, &hh1, &mm1, &ss1, &ms1);
        vtt_crack_time(block->timestamp + block->duration, &hh2, &mm2, &ss2, &ms2);

        printf("%02d\r\n%d:%02d:%02d,%03d --> %02d:%02d:%02d,%03d\r\n%s\r\n", i,
            hh1, mm1, ss1, ms1, hh2, mm2, ss2, ms2, vtt_block_data(block));
    }
}

