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
struct semid_kernel {struct label* label; } ;
struct label {int dummy; } ;
typedef  int /*<<< orphan*/  kauth_cred_t ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_CHECK (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct semid_kernel*,struct label*,...) ; 
 int /*<<< orphan*/  MAC_PERFORM (int /*<<< orphan*/ ,struct label*,...) ; 
 int /*<<< orphan*/  MAC_WAITOK ; 
 struct label* mac_labelzone_alloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mac_labelzone_free (struct label*) ; 
 int /*<<< orphan*/  sysvsem_check_semctl ; 
 int /*<<< orphan*/  sysvsem_check_semget ; 
 int /*<<< orphan*/  sysvsem_check_semop ; 
 int /*<<< orphan*/  sysvsem_label_associate ; 
 int /*<<< orphan*/  sysvsem_label_destroy ; 
 int /*<<< orphan*/  sysvsem_label_init ; 
 int /*<<< orphan*/  sysvsem_label_recycle ; 

__attribute__((used)) static struct label *
mac_sysv_sem_label_alloc(void)
{
	struct label *label;

	label = mac_labelzone_alloc(MAC_WAITOK);
	if (label == NULL)
		return (NULL);
	MAC_PERFORM(sysvsem_label_init, label);
	return (label);
}

void
mac_sysvsem_label_init(struct semid_kernel *semakptr)
{

	semakptr->label = mac_sysv_sem_label_alloc();
}

__attribute__((used)) static void
mac_sysv_sem_label_free(struct label *label)
{

	MAC_PERFORM(sysvsem_label_destroy, label);
	mac_labelzone_free(label);
}

void
mac_sysvsem_label_destroy(struct semid_kernel *semakptr)
{

	mac_sysv_sem_label_free(semakptr->label);
	semakptr->label = NULL;
}

void
mac_sysvsem_label_associate(kauth_cred_t cred, struct semid_kernel *semakptr)
{

	MAC_PERFORM(sysvsem_label_associate, cred, semakptr, semakptr->label);
}

void
mac_sysvsem_label_recycle(struct semid_kernel *semakptr)
{

	MAC_PERFORM(sysvsem_label_recycle, semakptr->label);
}

int
mac_sysvsem_check_semctl(kauth_cred_t cred, struct semid_kernel *semakptr,
    int cmd)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_sysvsem_enforce)
        return (0);
#endif

	MAC_CHECK(sysvsem_check_semctl, cred, semakptr, semakptr->label, cmd);

	return(error);
}

int
mac_sysvsem_check_semget(kauth_cred_t cred, struct semid_kernel *semakptr)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_sysvsem_enforce)
        return (0);
#endif

	MAC_CHECK(sysvsem_check_semget, cred, semakptr, semakptr->label);

	return(error);
}

int
mac_sysvsem_check_semop(kauth_cred_t cred, struct semid_kernel *semakptr,
    size_t accesstype)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_sysvsem_enforce)
        return (0);
#endif

	MAC_CHECK(sysvsem_check_semop, cred, semakptr, semakptr->label,
	    accesstype);

	return(error);
}

