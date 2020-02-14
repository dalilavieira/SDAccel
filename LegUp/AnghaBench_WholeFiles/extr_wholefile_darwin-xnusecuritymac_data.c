#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct mac_policy_conf {struct mac_module_data* mpc_data; } ;
struct mac_module_data {unsigned int count; TYPE_1__* data; } ;
typedef  int /*<<< orphan*/  proc_t ;
typedef  int /*<<< orphan*/  mac_policy_handle_t ;
typedef  int /*<<< orphan*/  kauth_cred_t ;
struct TYPE_2__ {scalar_t__ value_size; void* value; int /*<<< orphan*/  key; } ;

/* Variables and functions */
 int ENOENT ; 
 int mac_find_module_data (struct mac_module_data*,char const*,void**,size_t*) ; 
 struct mac_policy_conf* mac_get_mpc (int /*<<< orphan*/  const) ; 
 scalar_t__ strcmp (char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static __inline__ bool mac_proc_check_enforce(proc_t p)
{
#if CONFIG_MACF
	// Don't apply policies to the kernel itself.
	return (p != kernproc);
#else
#pragma unused(p)
	return false;
#endif // CONFIG_MACF
}

__attribute__((used)) static __inline__ bool mac_cred_check_enforce(kauth_cred_t cred)
{
#if CONFIG_MACF
	return (cred != proc_ucred(kernproc));
#else
#pragma unused(p)
	return false;
#endif // CONFIG_MACF
}

int
mac_find_policy_data(const mac_policy_handle_t handle, const char *key,
    void **valp, size_t *sizep)
{
	struct mac_policy_conf *mpc;
	int error = ENOENT;

	if ((mpc = mac_get_mpc(handle)) != NULL)
		error = mac_find_module_data(mpc->mpc_data, key, valp, sizep);
	return (error);
}

int
mac_find_module_data(struct mac_module_data *mmd, const char *key,
    void **valp, size_t *sizep)
{
	int error = ENOENT;
	unsigned int i;

	if (mmd != NULL) {
		for (i = 0; i < mmd->count; i++) {
			if (strcmp(key, mmd->data[i].key) == 0) {
				*valp = mmd->data[i].value;
				*sizep = (size_t)mmd->data[i].value_size;
				error = 0;
				break;
			}
		}
	}

	return (error);
}

