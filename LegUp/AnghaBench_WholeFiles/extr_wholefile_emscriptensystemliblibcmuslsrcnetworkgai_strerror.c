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

/* Variables and functions */
 char const* LCTRANS_CUR (char const*) ; 
 char* msgs ; 

const char *gai_strerror(int ecode)
{
	const char *s;
	for (s=msgs, ecode++; ecode && *s; ecode++, s++) for (; *s; s++);
	if (!*s) s++;
	return LCTRANS_CUR(s);
}

