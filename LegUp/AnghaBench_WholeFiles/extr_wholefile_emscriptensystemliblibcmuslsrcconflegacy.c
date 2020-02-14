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
 int /*<<< orphan*/  _SC_AVPHYS_PAGES ; 
 int /*<<< orphan*/  _SC_NPROCESSORS_CONF ; 
 int /*<<< orphan*/  _SC_NPROCESSORS_ONLN ; 
 int /*<<< orphan*/  _SC_PHYS_PAGES ; 
 long sysconf (int /*<<< orphan*/ ) ; 

int get_nprocs_conf()
{
	return sysconf(_SC_NPROCESSORS_CONF);
}

int get_nprocs()
{
	return sysconf(_SC_NPROCESSORS_ONLN);
}

long get_phys_pages()
{
	return sysconf(_SC_PHYS_PAGES);	
}

long get_avphys_pages()
{
	return sysconf(_SC_AVPHYS_PAGES);	
}

