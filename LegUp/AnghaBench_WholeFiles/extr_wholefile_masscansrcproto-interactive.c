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
struct InteractiveData {int is_closing; unsigned int m_length; int is_payload_dynamic; void const* m_payload; } ;

/* Variables and functions */
 unsigned char* MALLOC (size_t) ; 
 unsigned int TCPTRAN_DYNAMIC ; 
 int /*<<< orphan*/  UNUSEDPARM (struct InteractiveData*) ; 

unsigned char *
tcp_transmit_alloc(struct InteractiveData *more, size_t length)
{
    /* Note using this parameter yet, but in the future, we are going to have
     * memory pools instead of heap malloc(), which will use this parameter */
    UNUSEDPARM(more);

    return MALLOC(length);
}

void
tcp_close(struct InteractiveData *more)
{
    more->is_closing = 1;
}

void
tcp_transmit(struct InteractiveData *more, const void *payload, size_t length, unsigned flags)
{
    more->m_payload = payload;
    more->m_length = (unsigned)length;
    
    if (flags & TCPTRAN_DYNAMIC)
        more->is_payload_dynamic = 1;
}

