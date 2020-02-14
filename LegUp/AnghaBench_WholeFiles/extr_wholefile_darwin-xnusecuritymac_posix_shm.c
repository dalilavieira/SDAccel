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
typedef  int /*<<< orphan*/  vnode_t ;
struct pshminfo {struct label* pshm_label; } ;
struct label {int dummy; } ;
typedef  char const* off_t ;
typedef  int /*<<< orphan*/  kauth_cred_t ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_CHECK (int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  MAC_PERFORM (int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  MAC_WAITOK ; 
 struct label* mac_labelzone_alloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mac_labelzone_free (struct label*) ; 
 int /*<<< orphan*/  posixshm_check_create ; 
 int /*<<< orphan*/  posixshm_check_mmap ; 
 int /*<<< orphan*/  posixshm_check_open ; 
 int /*<<< orphan*/  posixshm_check_stat ; 
 int /*<<< orphan*/  posixshm_check_truncate ; 
 int /*<<< orphan*/  posixshm_check_unlink ; 
 int /*<<< orphan*/  posixshm_label_associate ; 
 int /*<<< orphan*/  posixshm_label_destroy ; 
 int /*<<< orphan*/  posixshm_label_init ; 
 int /*<<< orphan*/  vnode_label_associate_posixshm ; 

__attribute__((used)) static struct label *
mac_posixshm_label_alloc(void)
{
	struct label *label;

	label = mac_labelzone_alloc(MAC_WAITOK);
	if (label == NULL)
		return (NULL);
	MAC_PERFORM(posixshm_label_init, label);
	return (label);
}

void
mac_posixshm_label_init(struct pshminfo *pshm)
{

	pshm->pshm_label = mac_posixshm_label_alloc();
}

__attribute__((used)) static void
mac_posixshm_label_free(struct label *label)
{

	MAC_PERFORM(posixshm_label_destroy, label);
	mac_labelzone_free(label);
}

void
mac_posixshm_label_destroy(struct pshminfo *pshm)
{

	mac_posixshm_label_free(pshm->pshm_label);
	pshm->pshm_label = NULL;
}

void
mac_posixshm_vnode_label_associate(kauth_cred_t cred,
	struct pshminfo *pshm, struct label *plabel,
	vnode_t vp, struct label *vlabel)
{
	MAC_PERFORM(vnode_label_associate_posixshm, cred, 
		    pshm, plabel, vp, vlabel);
}

void
mac_posixshm_label_associate(kauth_cred_t cred, struct pshminfo *pshm,
    const char *name)
{

	MAC_PERFORM(posixshm_label_associate, cred, pshm, pshm->pshm_label, name);
}

int
mac_posixshm_check_create(kauth_cred_t cred, const char *name)
{
	int error = 0;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_posixshm_enforce)
        return 0;
#endif

	MAC_CHECK(posixshm_check_create, cred, name);

	return error;
}

int
mac_posixshm_check_open(kauth_cred_t cred, struct pshminfo *shm, int fflags)
{
	int error = 0;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_posixshm_enforce)
        return 0;
#endif

	MAC_CHECK(posixshm_check_open, cred, shm, shm->pshm_label, fflags);

	return (error);
}

int
mac_posixshm_check_mmap(kauth_cred_t cred, struct pshminfo *shm,
    int prot, int flags)
{
	int error = 0;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_posixshm_enforce)
        return 0;
#endif

	MAC_CHECK(posixshm_check_mmap, cred, shm, shm->pshm_label,
            prot, flags);

	return (error);
}

int
mac_posixshm_check_stat(kauth_cred_t cred, struct pshminfo *shm)
{
	int error = 0;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_posixshm_enforce)
        return 0;
#endif

	MAC_CHECK(posixshm_check_stat, cred, shm, shm->pshm_label);

	return (error);
}

int
mac_posixshm_check_truncate(kauth_cred_t cred, struct pshminfo *shm,
    off_t size)
{
	int error = 0;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_posixshm_enforce)
        return 0;
#endif

	MAC_CHECK(posixshm_check_truncate, cred, shm, shm->pshm_label, size);

	return (error);
}

int
mac_posixshm_check_unlink(kauth_cred_t cred, struct pshminfo *shm,
    const char *name)
{
	int error = 0;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_posixshm_enforce)
        return 0;
#endif

	MAC_CHECK(posixshm_check_unlink, cred, shm, shm->pshm_label, name);

	return (error);
}

