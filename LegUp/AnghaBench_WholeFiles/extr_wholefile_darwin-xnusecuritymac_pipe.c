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
typedef  int /*<<< orphan*/  u_int ;
struct pipe {struct label* pipe_label; } ;
struct label {int dummy; } ;
struct knote {int dummy; } ;
typedef  int /*<<< orphan*/  kauth_cred_t ;

/* Variables and functions */
 int /*<<< orphan*/  MAC_CHECK (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct pipe*,struct pipe*,...) ; 
 int MAC_EXTERNALIZE (int /*<<< orphan*/ ,struct label*,char*,char*,size_t) ; 
 int MAC_INTERNALIZE (int /*<<< orphan*/ ,struct label*,char*) ; 
 int /*<<< orphan*/  MAC_PERFORM (int /*<<< orphan*/ ,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  MAC_WAITOK ; 
 struct label* mac_labelzone_alloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mac_labelzone_free (struct label*) ; 
 int /*<<< orphan*/  pipe ; 
 int /*<<< orphan*/  pipe_check_ioctl ; 
 int /*<<< orphan*/  pipe_check_kqfilter ; 
 int /*<<< orphan*/  pipe_check_label_update ; 
 int /*<<< orphan*/  pipe_check_read ; 
 int /*<<< orphan*/  pipe_check_select ; 
 int /*<<< orphan*/  pipe_check_stat ; 
 int /*<<< orphan*/  pipe_check_write ; 
 int /*<<< orphan*/  pipe_label_associate ; 
 int /*<<< orphan*/  pipe_label_copy ; 
 int /*<<< orphan*/  pipe_label_destroy ; 
 int /*<<< orphan*/  pipe_label_init ; 
 int /*<<< orphan*/  pipe_label_update ; 

struct label *
mac_pipe_label_alloc(void)
{
	struct label *label;

	label = mac_labelzone_alloc(MAC_WAITOK);
	if (label == NULL)
		return (NULL);
	MAC_PERFORM(pipe_label_init, label);
	return (label);
}

void
mac_pipe_label_init(struct pipe *cpipe)
{

	cpipe->pipe_label = mac_pipe_label_alloc();
}

void
mac_pipe_label_free(struct label *label)
{

	MAC_PERFORM(pipe_label_destroy, label);
	mac_labelzone_free(label);
}

void
mac_pipe_label_destroy(struct pipe *cpipe)
{

	mac_pipe_label_free(cpipe->pipe_label);
	cpipe->pipe_label = NULL;
}

void
mac_pipe_label_copy(struct label *src, struct label *dest)
{

	MAC_PERFORM(pipe_label_copy, src, dest);
}

int
mac_pipe_label_externalize(struct label *label, char *elements,
    char *outbuf, size_t outbuflen)
{
	int error;

	error = MAC_EXTERNALIZE(pipe, label, elements, outbuf, outbuflen);

	return (error);
}

int
mac_pipe_label_internalize(struct label *label, char *string)
{
	int error;

	error = MAC_INTERNALIZE(pipe, label, string);

	return (error);
}

void
mac_pipe_label_associate(kauth_cred_t cred, struct pipe *cpipe)
{

	MAC_PERFORM(pipe_label_associate, cred, cpipe, cpipe->pipe_label);
}

int
mac_pipe_check_kqfilter(kauth_cred_t cred, struct knote *kn,
    struct pipe *cpipe)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_pipe_enforce)
        return (0);
#endif
	MAC_CHECK(pipe_check_kqfilter, cred, kn, cpipe, cpipe->pipe_label);
	return (error);
}

int
mac_pipe_check_ioctl(kauth_cred_t cred, struct pipe *cpipe, u_int cmd)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_pipe_enforce)
        return (0);
#endif

	MAC_CHECK(pipe_check_ioctl, cred, cpipe, cpipe->pipe_label, cmd);

	return (error);
}

int
mac_pipe_check_read(kauth_cred_t cred, struct pipe *cpipe)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_pipe_enforce)
        return (0);
#endif

	MAC_CHECK(pipe_check_read, cred, cpipe, cpipe->pipe_label);

	return (error);
}

__attribute__((used)) static int
mac_pipe_check_label_update(kauth_cred_t cred, struct pipe *cpipe,
    struct label *newlabel)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_pipe_enforce)
        return (0);
#endif

	MAC_CHECK(pipe_check_label_update, cred, cpipe, cpipe->pipe_label, newlabel);

	return (error);
}

int
mac_pipe_check_select(kauth_cred_t cred, struct pipe *cpipe, int which)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_pipe_enforce)
        return (0);
#endif

	MAC_CHECK(pipe_check_select, cred, cpipe, cpipe->pipe_label, which);

	return (error);
}

int
mac_pipe_check_stat(kauth_cred_t cred, struct pipe *cpipe)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_pipe_enforce)
        return (0);
#endif

	MAC_CHECK(pipe_check_stat, cred, cpipe, cpipe->pipe_label);

	return (error);
}

int
mac_pipe_check_write(kauth_cred_t cred, struct pipe *cpipe)
{
	int error;

#if SECURITY_MAC_CHECK_ENFORCE
    /* 21167099 - only check if we allow write */
    if (!mac_pipe_enforce)
        return (0);
#endif

	MAC_CHECK(pipe_check_write, cred, cpipe, cpipe->pipe_label);

	return (error);
}

int
mac_pipe_label_update(kauth_cred_t cred, struct pipe *cpipe,
    struct label *label)
{
	int error;

	error = mac_pipe_check_label_update(cred, cpipe, label);
	if (error)
		return (error);

	MAC_PERFORM(pipe_label_update, cred, cpipe, cpipe->pipe_label, label);

	return (0);
}

