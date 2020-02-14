#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {unsigned int first; unsigned int last; } ;
struct TYPE_3__ {unsigned int first; unsigned int last; } ;
struct Source {TYPE_2__ port; TYPE_1__ ip; } ;

/* Variables and functions */
 int is_my_ip (struct Source const*,unsigned int) ; 
 int is_my_port (struct Source const*,unsigned int) ; 

int is_myself(const struct Source *src, unsigned ip, unsigned port)
{
    return is_my_ip(src, ip) && is_my_port(src, port);
}

int is_my_ip(const struct Source *src, unsigned ip)
{
    return src->ip.first <= ip && ip <= src->ip.last;
}

int is_my_port(const struct Source *src, unsigned port)
{
    return src->port.first <= port && port <= src->port.last;
}

