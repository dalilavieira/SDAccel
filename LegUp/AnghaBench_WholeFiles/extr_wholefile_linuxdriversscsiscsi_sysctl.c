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
struct scsi_target {int dummy; } ;
struct scsi_device {int dummy; } ;
struct scsi_cmnd {int dummy; } ;
struct Scsi_Host {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline void scsi_log_send(struct scsi_cmnd *cmd) 
	{ }

__attribute__((used)) static inline void scsi_log_completion(struct scsi_cmnd *cmd, int disposition)
	{ }

__attribute__((used)) static inline void scsi_netlink_init(void) {}

__attribute__((used)) static inline void scsi_netlink_exit(void) {}

__attribute__((used)) static inline void scsi_autopm_get_target(struct scsi_target *t) {}

__attribute__((used)) static inline void scsi_autopm_put_target(struct scsi_target *t) {}

__attribute__((used)) static inline int scsi_autopm_get_host(struct Scsi_Host *h) { return 0; }

__attribute__((used)) static inline void scsi_autopm_put_host(struct Scsi_Host *h) {}

__attribute__((used)) static inline void scsi_dh_add_device(struct scsi_device *sdev) { }

__attribute__((used)) static inline void scsi_dh_release_device(struct scsi_device *sdev) { }

