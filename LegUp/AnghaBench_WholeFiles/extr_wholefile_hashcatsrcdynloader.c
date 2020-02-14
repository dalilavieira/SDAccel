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
typedef  int /*<<< orphan*/  hc_dynlib_t ;
typedef  int /*<<< orphan*/  hc_dynfunc_t ;

/* Variables and functions */
 int /*<<< orphan*/  RTLD_NOW ; 
 int dlclose (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dlopen (char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dlsym (int /*<<< orphan*/ ,char const*) ; 

hc_dynlib_t hc_dlopen (const char *filename)
{
  return dlopen (filename, RTLD_NOW);
}

int hc_dlclose (hc_dynlib_t handle)
{
  return dlclose (handle);
}

hc_dynfunc_t hc_dlsym (hc_dynlib_t handle, const char *symbol)
{
  return dlsym (handle, symbol);
}

