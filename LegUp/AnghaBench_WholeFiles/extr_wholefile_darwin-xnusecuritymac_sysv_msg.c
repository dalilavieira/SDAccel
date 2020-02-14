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
struct msqid_kernel {struct label* label; } ;
struct msg {struct label* label; } ;
struct label {int dummy; } ;
typedef  int /*<<< orphan*/  kauth_cred_t ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_CHECK (int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  MAC_PERFORM (int /*<<< orphan*/ ,struct label*,...) ; 
 int /*<<< orphan*/  MAC_WAITOK ; 
 struct label* mac_labelzone_alloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sysvmsg_label_associate ; 
 int /*<<< orphan*/  sysvmsg_label_init ; 
 int /*<<< orphan*/  sysvmsg_label_recycle ; 
 int /*<<< orphan*/  sysvmsq_check_enqueue ; 
 int /*<<< orphan*/  sysvmsq_check_msgrcv ; 
 int /*<<< orphan*/  sysvmsq_check_msgrmid ; 
 int /*<<< orphan*/  sysvmsq_check_msqctl ; 
 int /*<<< orphan*/  sysvmsq_check_msqget ; 
 int /*<<< orphan*/  sysvmsq_check_msqrcv ; 
 int /*<<< orphan*/  sysvmsq_check_msqsnd ; 
 int /*<<< orphan*/  sysvmsq_label_associate ; 
 int /*<<< orphan*/  sysvmsq_label_init ; 
 int /*<<< orphan*/  sysvmsq_label_recycle ; 

__attribute__((used)) static struct label *
mac_sysv_msgmsg_label_alloc(void)
{
	struct label *label;

	label = mac_labelzone_alloc(MAC_WAITOK);
	if (label == NULL)
		return (NULL);
	MAC_PERFORM(sysvmsg_label_init, label);
	return (label);
}

void
mac_sysvmsg_label_init(struct msg *msgptr)
{

	msgptr->label = mac_sysv_msgmsg_label_alloc();
}

__attribute__((used)) static struct label *
mac_sysv_msgqueue_label_alloc(void)
{
	struct label *label;

	label = mac_labelzone_alloc(MAC_WAITOK);
	if (label == NULL)
		return (NULL);
	MAC_PERFORM(sysvmsq_label_init, label);
	return (label);
}

void
mac_sysvmsq_label_init(struct msqid_kernel *msqptr)
{

	msqptr->label = mac_sysv_msgqueue_label_alloc();
}

void
mac_sysvmsg_label_associate(kauth_cred_t cred, struct msqid_kernel *msqptr, 
    struct msg *msgptr)
{
				
	MAC_PERFORM(sysvmsg_label_associate, cred, msqptr, msqptr->label, 
		msgptr, msgptr->label);
}

void
mac_sysvmsq_label_associate(kauth_cred_t cred, struct msqid_kernel *msqptr)
{
				
	MAC_PERFORM(sysvmsq_label_associate, cred, msqptr, msqptr->label);
}

void
mac_sysvmsg_label_recycle(struct msg *msgptr)
{

	MAC_PERFORM(sysvmsg_label_recycle, msgptr->label);
}

void
mac_sysvmsq_label_recycle(struct msqid_kernel *msqptr)
{
				
	MAC_PERFORM(sysvmsq_label_recycle, msqptr->label);
}

int
mac_sysvmsq_check_enqueue(kauth_cred_t cred, struct msg *msgptr,
	struct msqid_kernel *msqptr)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_sysvmsg_enforce)
        return (0);
#endif

	MAC_CHECK(sysvmsq_check_enqueue, cred,  msgptr, msgptr->label, msqptr,
	    msqptr->label);

	return(error);
}

int
mac_sysvmsq_check_msgrcv(kauth_cred_t cred, struct msg *msgptr)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_sysvmsg_enforce)
        return (0);
#endif

	MAC_CHECK(sysvmsq_check_msgrcv, cred, msgptr, msgptr->label);

	return(error);
}

int
mac_sysvmsq_check_msgrmid(kauth_cred_t cred, struct msg *msgptr)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_sysvmsg_enforce)
        return (0);
#endif

	MAC_CHECK(sysvmsq_check_msgrmid, cred,  msgptr, msgptr->label);

	return(error);
}

int
mac_sysvmsq_check_msqget(kauth_cred_t cred, struct msqid_kernel *msqptr)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_sysvmsg_enforce)
        return (0);
#endif

	MAC_CHECK(sysvmsq_check_msqget, cred, msqptr, msqptr->label);

	return(error);
}

int
mac_sysvmsq_check_msqsnd(kauth_cred_t cred, struct msqid_kernel *msqptr)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_sysvmsg_enforce)
        return (0);
#endif

	MAC_CHECK(sysvmsq_check_msqsnd, cred, msqptr, msqptr->label);

	return(error);
}

int
mac_sysvmsq_check_msqrcv(kauth_cred_t cred, struct msqid_kernel *msqptr)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_sysvmsg_enforce)
        return (0);
#endif

	MAC_CHECK(sysvmsq_check_msqrcv, cred, msqptr, msqptr->label);

	return(error);
}

int
mac_sysvmsq_check_msqctl(kauth_cred_t cred, struct msqid_kernel *msqptr,
    int cmd)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_sysvmsg_enforce)
        return (0);
#endif

	MAC_CHECK(sysvmsq_check_msqctl, cred, msqptr, msqptr->label, cmd);

	return(error);
}

