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
struct ucred {int dummy; } ;
struct shmid_kernel {struct label* label; } ;
struct label {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_CHECK (int /*<<< orphan*/ ,struct ucred*,struct shmid_kernel*,struct label*,...) ; 
 int /*<<< orphan*/  MAC_PERFORM (int /*<<< orphan*/ ,struct label*,...) ; 
 int /*<<< orphan*/  MAC_WAITOK ; 
 struct label* mac_labelzone_alloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mac_labelzone_free (struct label*) ; 
 int /*<<< orphan*/  sysvshm_check_shmat ; 
 int /*<<< orphan*/  sysvshm_check_shmctl ; 
 int /*<<< orphan*/  sysvshm_check_shmdt ; 
 int /*<<< orphan*/  sysvshm_check_shmget ; 
 int /*<<< orphan*/  sysvshm_label_associate ; 
 int /*<<< orphan*/  sysvshm_label_destroy ; 
 int /*<<< orphan*/  sysvshm_label_init ; 
 int /*<<< orphan*/  sysvshm_label_recycle ; 

__attribute__((used)) static struct label *
mac_sysv_shm_label_alloc(void)
{
	struct label *label;

	label = mac_labelzone_alloc(MAC_WAITOK);
	if (label == NULL)
		return (NULL);
	MAC_PERFORM(sysvshm_label_init, label);
	return (label);
}

void
mac_sysvshm_label_init(struct shmid_kernel *shmsegptr)
{

	shmsegptr->label = mac_sysv_shm_label_alloc();
}

__attribute__((used)) static void
mac_sysv_shm_label_free(struct label *label)
{

	MAC_PERFORM(sysvshm_label_destroy, label);
	mac_labelzone_free(label);
}

void
mac_sysvshm_label_destroy(struct shmid_kernel *shmsegptr)
{

	mac_sysv_shm_label_free(shmsegptr->label);
	shmsegptr->label = NULL;
}

void
mac_sysvshm_label_associate(struct ucred *cred, struct shmid_kernel *shmsegptr)
{

	MAC_PERFORM(sysvshm_label_associate, cred, shmsegptr, shmsegptr->label);
}

void
mac_sysvshm_label_recycle(struct shmid_kernel *shmsegptr)
{

	MAC_PERFORM(sysvshm_label_recycle, shmsegptr->label);
}

int
mac_sysvshm_check_shmat(struct ucred *cred, struct shmid_kernel *shmsegptr,
    int shmflg)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_sysvshm_enforce)
        return (0);
#endif

	MAC_CHECK(sysvshm_check_shmat, cred, shmsegptr, shmsegptr->label,
	    shmflg);

	return(error);
}

int
mac_sysvshm_check_shmctl(struct ucred *cred, struct shmid_kernel *shmsegptr,
    int cmd)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_sysvshm_enforce)
        return (0);
#endif

	MAC_CHECK(sysvshm_check_shmctl, cred, shmsegptr, shmsegptr->label,
	    cmd);

	return(error);
}

int
mac_sysvshm_check_shmdt(struct ucred *cred, struct shmid_kernel *shmsegptr)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_sysvshm_enforce)
        return (0);
#endif

	MAC_CHECK(sysvshm_check_shmdt, cred, shmsegptr, shmsegptr->label);

	return(error);
}

int
mac_sysvshm_check_shmget(struct ucred *cred, struct shmid_kernel *shmsegptr,
    int shmflg)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_sysvshm_enforce)
        return (0);
#endif

	MAC_CHECK(sysvshm_check_shmget, cred, shmsegptr, shmsegptr->label,
	    shmflg);

	return(error);
}

