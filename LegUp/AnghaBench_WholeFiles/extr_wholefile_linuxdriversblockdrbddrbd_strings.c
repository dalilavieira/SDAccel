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
typedef  enum drbd_state_rv { ____Placeholder_drbd_state_rv } drbd_state_rv ;
typedef  enum drbd_role { ____Placeholder_drbd_role } drbd_role ;
typedef  enum drbd_disk_state { ____Placeholder_drbd_disk_state } drbd_disk_state ;
typedef  enum drbd_conns { ____Placeholder_drbd_conns } drbd_conns ;

/* Variables and functions */
 int C_BEHIND ; 
 int D_UP_TO_DATE ; 
 int R_SECONDARY ; 
 int SS_AFTER_LAST_ERROR ; 
 int SS_TWO_PRIMARIES ; 
 char const** drbd_conn_s_names ; 
 char const** drbd_disk_s_names ; 
 char const** drbd_role_s_names ; 
 char const** drbd_state_sw_errors ; 

const char *drbd_conn_str(enum drbd_conns s)
{
	/* enums are unsigned... */
	return s > C_BEHIND ? "TOO_LARGE" : drbd_conn_s_names[s];
}

const char *drbd_role_str(enum drbd_role s)
{
	return s > R_SECONDARY   ? "TOO_LARGE" : drbd_role_s_names[s];
}

const char *drbd_disk_str(enum drbd_disk_state s)
{
	return s > D_UP_TO_DATE    ? "TOO_LARGE" : drbd_disk_s_names[s];
}

const char *drbd_set_st_err_str(enum drbd_state_rv err)
{
	return err <= SS_AFTER_LAST_ERROR ? "TOO_SMALL" :
	       err > SS_TWO_PRIMARIES ? "TOO_LARGE"
			: drbd_state_sw_errors[-err];
}

