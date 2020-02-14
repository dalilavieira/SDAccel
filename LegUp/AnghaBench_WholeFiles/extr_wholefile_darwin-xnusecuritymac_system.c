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
typedef  int /*<<< orphan*/  user_addr_t ;
typedef  int /*<<< orphan*/  u_int ;
struct vnode {int /*<<< orphan*/ * v_label; } ;
typedef  int /*<<< orphan*/  kauth_cred_t ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_CHECK (int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  system_check_acct ; 
 int /*<<< orphan*/  system_check_chud ; 
 int /*<<< orphan*/  system_check_host_priv ; 
 int /*<<< orphan*/  system_check_info ; 
 int /*<<< orphan*/  system_check_kas_info ; 
 int /*<<< orphan*/  system_check_nfsd ; 
 int /*<<< orphan*/  system_check_reboot ; 
 int /*<<< orphan*/  system_check_settime ; 
 int /*<<< orphan*/  system_check_swapoff ; 
 int /*<<< orphan*/  system_check_swapon ; 
 int /*<<< orphan*/  system_check_sysctlbyname ; 

int
mac_system_check_acct(kauth_cred_t cred, struct vnode *vp)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
	/* 21167099 - only check if we allow write */
	if (!mac_system_enforce)
		return (0);
#endif

	MAC_CHECK(system_check_acct, cred, vp,
	    vp != NULL ? vp->v_label : NULL);

	return (error);
}

int
mac_system_check_chud(kauth_cred_t cred)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
	/* 21167099 - only check if we allow write */
	if (!mac_system_enforce)
		return (0);
#endif

	MAC_CHECK(system_check_chud, cred);

	return (error);
}

int
mac_system_check_host_priv(kauth_cred_t cred)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
	/* 21167099 - only check if we allow write */
	if (!mac_system_enforce)
		return (0);
#endif

	MAC_CHECK(system_check_host_priv, cred);

	return (error);
}

int
mac_system_check_info(kauth_cred_t cred, const char *info_type)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
	/* 21167099 - only check if we allow write */
	if (!mac_system_enforce)
		return (0);
#endif

	MAC_CHECK(system_check_info, cred, info_type);

	return (error);
}

int
mac_system_check_nfsd(kauth_cred_t cred)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
	/* 21167099 - only check if we allow write */
	if (!mac_system_enforce)
		return (0);
#endif

	MAC_CHECK(system_check_nfsd, cred);

	return (error);
}

int
mac_system_check_reboot(kauth_cred_t cred, int howto)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
	/* 21167099 - only check if we allow write */
	if (!mac_system_enforce)
		return (0);
#endif

	MAC_CHECK(system_check_reboot, cred, howto);

	return (error);
}

int
mac_system_check_settime(kauth_cred_t cred)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
	/* 21167099 - only check if we allow write */
	if (!mac_system_enforce)
		return (0);
#endif

	MAC_CHECK(system_check_settime, cred);

	return (error);
}

int
mac_system_check_swapon(kauth_cred_t cred, struct vnode *vp)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
	/* 21167099 - only check if we allow write */
	if (!mac_system_enforce)
		return (0);
#endif

	MAC_CHECK(system_check_swapon, cred, vp, vp->v_label);
	return (error);
}

int
mac_system_check_swapoff(kauth_cred_t cred, struct vnode *vp)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
	/* 21167099 - only check if we allow write */
	if (!mac_system_enforce)
		return (0);
#endif

	MAC_CHECK(system_check_swapoff, cred, vp, vp->v_label);
	return (error);
}

int
mac_system_check_sysctlbyname(kauth_cred_t cred, const char *namestring, int *name,
			      u_int namelen, user_addr_t oldctl, size_t oldlen,
			      user_addr_t newctl, size_t newlen)
{
	int error;
	
#if SECURITY_MAC_CHECK_ENFORCE
	/* 21167099 - only check if we allow write */
	if (!mac_system_enforce)
		return (0);
#endif

	MAC_CHECK(system_check_sysctlbyname, cred, namestring,
	    name, namelen, oldctl, oldlen, newctl, newlen);	
	
	return (error);
}

int
mac_system_check_kas_info(kauth_cred_t cred, int selector)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
	/* 21167099 - only check if we allow write */
	if (!mac_system_enforce)
		return (0);
#endif

	MAC_CHECK(system_check_kas_info, cred, selector);

	return (error);
}

