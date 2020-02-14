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
struct pseminfo {struct label* psem_label; } ;
struct label {int dummy; } ;
typedef  int /*<<< orphan*/  kauth_cred_t ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_CHECK (int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  MAC_PERFORM (int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  MAC_WAITOK ; 
 struct label* mac_labelzone_alloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mac_labelzone_free (struct label*) ; 
 int /*<<< orphan*/  posixsem_check_create ; 
 int /*<<< orphan*/  posixsem_check_open ; 
 int /*<<< orphan*/  posixsem_check_post ; 
 int /*<<< orphan*/  posixsem_check_unlink ; 
 int /*<<< orphan*/  posixsem_check_wait ; 
 int /*<<< orphan*/  posixsem_label_associate ; 
 int /*<<< orphan*/  posixsem_label_destroy ; 
 int /*<<< orphan*/  posixsem_label_init ; 
 int /*<<< orphan*/  vnode_label_associate_posixsem ; 

__attribute__((used)) static struct label *
mac_posixsem_label_alloc(void)
{
	struct label *label;

	label = mac_labelzone_alloc(MAC_WAITOK);
	if (label == NULL)
		return (NULL);
	MAC_PERFORM(posixsem_label_init, label);
	return (label);
}

void
mac_posixsem_label_init(struct pseminfo *psem)
{

	psem->psem_label = mac_posixsem_label_alloc();
}

__attribute__((used)) static void
mac_posixsem_label_free(struct label *label)
{

	MAC_PERFORM(posixsem_label_destroy, label);
	mac_labelzone_free(label);
}

void
mac_posixsem_label_destroy(struct pseminfo *psem)
{

	mac_posixsem_label_free(psem->psem_label);
	psem->psem_label = NULL;
}

void
mac_posixsem_label_associate(kauth_cred_t cred, struct pseminfo *psem,
    const char *name)
{

	MAC_PERFORM(posixsem_label_associate, cred, psem, psem->psem_label, name);
}

void
mac_posixsem_vnode_label_associate(kauth_cred_t cred, 
	struct pseminfo *psem,  struct label *plabel,
	vnode_t vp, struct label *vlabel)
{
	MAC_PERFORM(vnode_label_associate_posixsem, cred,
		    psem, plabel, vp, vlabel);
}

int
mac_posixsem_check_create(kauth_cred_t cred, const char *name)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_posixsem_enforce)
        return (0);
#endif

	MAC_CHECK(posixsem_check_create, cred, name);

	return (error);
}

int
mac_posixsem_check_open(kauth_cred_t cred, struct pseminfo *psem)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_posixsem_enforce)
        return (0);
#endif

	MAC_CHECK(posixsem_check_open, cred, psem,
	    psem->psem_label);

	return (error);
}

int
mac_posixsem_check_post(kauth_cred_t cred, struct pseminfo *psem)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_posixsem_enforce)
        return (0);
#endif

	MAC_CHECK(posixsem_check_post, cred, psem, psem->psem_label);

	return (error);
}

int
mac_posixsem_check_unlink(kauth_cred_t cred, struct pseminfo *psem,
    const char *name)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_posixsem_enforce)
        return (0);
#endif

	MAC_CHECK(posixsem_check_unlink, cred, psem, psem->psem_label, name);

	return (error);
}

int
mac_posixsem_check_wait(kauth_cred_t cred, struct pseminfo *psem)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_posixsem_enforce)
        return (0);
#endif

	MAC_CHECK(posixsem_check_wait, cred, psem, psem->psem_label);

	return (error);
}

