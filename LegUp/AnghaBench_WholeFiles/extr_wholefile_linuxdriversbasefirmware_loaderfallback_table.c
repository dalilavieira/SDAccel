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
struct fw_state {int status; int /*<<< orphan*/  completion; } ;
struct fw_priv {struct fw_state fw_st; } ;
struct firmware {int dummy; } ;
struct device {int dummy; } ;
typedef  enum fw_status { ____Placeholder_fw_status } fw_status ;
typedef  enum fw_opt { ____Placeholder_fw_opt } fw_opt ;

/* Variables and functions */
 int ENOENT ; 
 int ETIMEDOUT ; 
 scalar_t__ FW_STATUS_ABORTED ; 
 int FW_STATUS_DONE ; 
 int FW_STATUS_LOADING ; 
 int /*<<< orphan*/  WRITE_ONCE (scalar_t__,int) ; 
 int /*<<< orphan*/  complete_all (int /*<<< orphan*/ *) ; 
 long wait_for_completion_killable_timeout (int /*<<< orphan*/ *,long) ; 

__attribute__((used)) static inline bool __fw_state_check(struct fw_priv *fw_priv,
				    enum fw_status status)
{
	struct fw_state *fw_st = &fw_priv->fw_st;

	return fw_st->status == status;
}

__attribute__((used)) static inline int __fw_state_wait_common(struct fw_priv *fw_priv, long timeout)
{
	struct fw_state *fw_st = &fw_priv->fw_st;
	long ret;

	ret = wait_for_completion_killable_timeout(&fw_st->completion, timeout);
	if (ret != 0 && fw_st->status == FW_STATUS_ABORTED)
		return -ENOENT;
	if (!ret)
		return -ETIMEDOUT;

	return ret < 0 ? ret : 0;
}

__attribute__((used)) static inline void __fw_state_set(struct fw_priv *fw_priv,
				  enum fw_status status)
{
	struct fw_state *fw_st = &fw_priv->fw_st;

	WRITE_ONCE(fw_st->status, status);

	if (status == FW_STATUS_DONE || status == FW_STATUS_ABORTED)
		complete_all(&fw_st->completion);
}

__attribute__((used)) static inline void fw_state_aborted(struct fw_priv *fw_priv)
{
	__fw_state_set(fw_priv, FW_STATUS_ABORTED);
}

__attribute__((used)) static inline bool fw_state_is_aborted(struct fw_priv *fw_priv)
{
	return __fw_state_check(fw_priv, FW_STATUS_ABORTED);
}

__attribute__((used)) static inline void fw_state_start(struct fw_priv *fw_priv)
{
	__fw_state_set(fw_priv, FW_STATUS_LOADING);
}

__attribute__((used)) static inline void fw_state_done(struct fw_priv *fw_priv)
{
	__fw_state_set(fw_priv, FW_STATUS_DONE);
}

__attribute__((used)) static inline int firmware_fallback_sysfs(struct firmware *fw, const char *name,
					  struct device *device,
					  enum fw_opt opt_flags,
					  int ret)
{
	/* Keep carrying over the same error */
	return ret;
}

__attribute__((used)) static inline void kill_pending_fw_fallback_reqs(bool only_kill_custom) { }

__attribute__((used)) static inline void fw_fallback_set_cache_timeout(void) { }

__attribute__((used)) static inline void fw_fallback_set_default_timeout(void) { }

__attribute__((used)) static inline int register_sysfs_loader(void)
{
	return 0;
}

__attribute__((used)) static inline void unregister_sysfs_loader(void)
{
}

