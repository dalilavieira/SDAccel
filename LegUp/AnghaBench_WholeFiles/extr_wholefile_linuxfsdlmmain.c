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
struct dlm_rsb {int /*<<< orphan*/  res_mutex; int /*<<< orphan*/  res_nodeid; int /*<<< orphan*/  res_flags; } ;
struct dlm_ls {int /*<<< orphan*/  ls_flags; } ;
typedef  enum rsb_flags { ____Placeholder_rsb_flags } rsb_flags ;

/* Variables and functions */
 int LSFL_NODIR ; 
 int LSFL_RECOVER_STOP ; 
 int LSFL_RUNNING ; 
 int /*<<< orphan*/  __clear_bit (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __set_bit (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int test_bit (int,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void rsb_set_flag(struct dlm_rsb *r, enum rsb_flags flag)
{
	__set_bit(flag, &r->res_flags);
}

__attribute__((used)) static inline void rsb_clear_flag(struct dlm_rsb *r, enum rsb_flags flag)
{
	__clear_bit(flag, &r->res_flags);
}

__attribute__((used)) static inline int rsb_flag(struct dlm_rsb *r, enum rsb_flags flag)
{
	return test_bit(flag, &r->res_flags);
}

__attribute__((used)) static inline int dlm_locking_stopped(struct dlm_ls *ls)
{
	return !test_bit(LSFL_RUNNING, &ls->ls_flags);
}

__attribute__((used)) static inline int dlm_recovery_stopped(struct dlm_ls *ls)
{
	return test_bit(LSFL_RECOVER_STOP, &ls->ls_flags);
}

__attribute__((used)) static inline int dlm_no_directory(struct dlm_ls *ls)
{
	return test_bit(LSFL_NODIR, &ls->ls_flags);
}

__attribute__((used)) static inline int dlm_register_debugfs(void) { return 0; }

__attribute__((used)) static inline void dlm_unregister_debugfs(void) { }

__attribute__((used)) static inline int dlm_create_debug_file(struct dlm_ls *ls) { return 0; }

__attribute__((used)) static inline void dlm_delete_debug_file(struct dlm_ls *ls) { }

__attribute__((used)) static inline int is_master(struct dlm_rsb *r)
{
	return !r->res_nodeid;
}

__attribute__((used)) static inline void lock_rsb(struct dlm_rsb *r)
{
	mutex_lock(&r->res_mutex);
}

__attribute__((used)) static inline void unlock_rsb(struct dlm_rsb *r)
{
	mutex_unlock(&r->res_mutex);
}

