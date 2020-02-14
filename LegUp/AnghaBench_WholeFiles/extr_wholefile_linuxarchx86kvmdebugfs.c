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
typedef  int /*<<< orphan*/  u64 ;
struct TYPE_2__ {int /*<<< orphan*/  tsc_scaling_ratio; int /*<<< orphan*/  tsc_offset; } ;
struct kvm_vcpu {int /*<<< orphan*/  debugfs_dentry; TYPE_1__ arch; } ;
struct dentry {int dummy; } ;

/* Variables and functions */
 int ENOMEM ; 
 struct dentry* debugfs_create_file (char*,int,int /*<<< orphan*/ ,struct kvm_vcpu*,int /*<<< orphan*/ *) ; 
 scalar_t__ kvm_has_tsc_control ; 
 int /*<<< orphan*/  kvm_tsc_scaling_ratio_frac_bits ; 
 int /*<<< orphan*/  vcpu_tsc_offset_fops ; 
 int /*<<< orphan*/  vcpu_tsc_scaling_fops ; 
 int /*<<< orphan*/  vcpu_tsc_scaling_frac_fops ; 

bool kvm_arch_has_vcpu_debugfs(void)
{
	return true;
}

__attribute__((used)) static int vcpu_get_tsc_offset(void *data, u64 *val)
{
	struct kvm_vcpu *vcpu = (struct kvm_vcpu *) data;
	*val = vcpu->arch.tsc_offset;
	return 0;
}

__attribute__((used)) static int vcpu_get_tsc_scaling_ratio(void *data, u64 *val)
{
	struct kvm_vcpu *vcpu = (struct kvm_vcpu *) data;
	*val = vcpu->arch.tsc_scaling_ratio;
	return 0;
}

__attribute__((used)) static int vcpu_get_tsc_scaling_frac_bits(void *data, u64 *val)
{
	*val = kvm_tsc_scaling_ratio_frac_bits;
	return 0;
}

int kvm_arch_create_vcpu_debugfs(struct kvm_vcpu *vcpu)
{
	struct dentry *ret;

	ret = debugfs_create_file("tsc-offset", 0444,
							vcpu->debugfs_dentry,
							vcpu, &vcpu_tsc_offset_fops);
	if (!ret)
		return -ENOMEM;

	if (kvm_has_tsc_control) {
		ret = debugfs_create_file("tsc-scaling-ratio", 0444,
							vcpu->debugfs_dentry,
							vcpu, &vcpu_tsc_scaling_fops);
		if (!ret)
			return -ENOMEM;
		ret = debugfs_create_file("tsc-scaling-ratio-frac-bits", 0444,
							vcpu->debugfs_dentry,
							vcpu, &vcpu_tsc_scaling_frac_fops);
		if (!ret)
			return -ENOMEM;

	}

	return 0;
}

