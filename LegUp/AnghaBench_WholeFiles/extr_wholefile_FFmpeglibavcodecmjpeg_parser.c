#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
struct TYPE_9__ {int flags; TYPE_2__* priv_data; } ;
struct TYPE_7__ {int frame_start_found; int state; } ;
struct TYPE_8__ {int size; TYPE_1__ pc; } ;
typedef  TYPE_1__ ParseContext ;
typedef  TYPE_2__ MJPEGParserContext ;
typedef  TYPE_3__ AVCodecParserContext ;
typedef  int /*<<< orphan*/  AVCodecContext ;

/* Variables and functions */
 int END_NOT_FOUND ; 
 int FFMIN (int,int) ; 
 int PARSER_FLAG_COMPLETE_FRAMES ; 
 scalar_t__ ff_combine_frame (TYPE_1__*,int,int const**,int*) ; 

__attribute__((used)) static int find_frame_end(MJPEGParserContext *m, const uint8_t *buf, int buf_size){
    ParseContext *pc= &m->pc;
    int vop_found, i;
    uint32_t state;

    vop_found= pc->frame_start_found;
    state= pc->state;

    i=0;
    if(!vop_found){
        for(i=0; i<buf_size;){
            state= (state<<8) | buf[i];
            if(state>=0xFFC00000 && state<=0xFFFEFFFF){
                if(state>=0xFFD80000 && state<=0xFFD8FFFF){
                    i++;
                    vop_found=1;
                    break;
                }else if(state<0xFFD00000 || state>0xFFD9FFFF){
                    m->size= (state&0xFFFF)-1;
                }
            }
            if(m->size>0){
                int size= FFMIN(buf_size-i, m->size);
                i+=size;
                m->size-=size;
                state=0;
                continue;
            }else
                i++;
        }
    }

    if(vop_found){
        /* EOF considered as end of frame */
        if (buf_size == 0)
            return 0;
        for(; i<buf_size;){
            state= (state<<8) | buf[i];
            if(state>=0xFFC00000 && state<=0xFFFEFFFF){
                if(state>=0xFFD80000 && state<=0xFFD8FFFF){
                    pc->frame_start_found=0;
                    pc->state=0;
                    return i-3;
                } else if(state<0xFFD00000 || state>0xFFD9FFFF){
                    m->size= (state&0xFFFF)-1;
                }
            }
            if(m->size>0){
                int size= FFMIN(buf_size-i, m->size);
                i+=size;
                m->size-=size;
                state=0;
                continue;
            }else
                i++;
        }
    }
    pc->frame_start_found= vop_found;
    pc->state= state;
    return END_NOT_FOUND;
}

__attribute__((used)) static int jpeg_parse(AVCodecParserContext *s,
                      AVCodecContext *avctx,
                      const uint8_t **poutbuf, int *poutbuf_size,
                      const uint8_t *buf, int buf_size)
{
    MJPEGParserContext *m = s->priv_data;
    ParseContext *pc = &m->pc;
    int next;

    if(s->flags & PARSER_FLAG_COMPLETE_FRAMES){
        next= buf_size;
    }else{
        next= find_frame_end(m, buf, buf_size);

        if (ff_combine_frame(pc, next, &buf, &buf_size) < 0) {
            *poutbuf = NULL;
            *poutbuf_size = 0;
            return buf_size;
        }
    }

    *poutbuf = buf;
    *poutbuf_size = buf_size;
    return next;
}

