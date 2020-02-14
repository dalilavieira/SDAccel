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
typedef  int uint64_t ;
typedef  int uint32_t ;
struct seg_desc {int base; int limit; int access; } ;

/* Variables and functions */
 int EINVAL ; 
#define  VMCS_GUEST_CR0 151 
 int VMCS_GUEST_CR3 ; 
#define  VMCS_GUEST_CR4 150 
 int VMCS_GUEST_CS_ACCESS_RIGHTS ; 
 int VMCS_GUEST_CS_BASE ; 
 int VMCS_GUEST_CS_LIMIT ; 
 int VMCS_GUEST_CS_SELECTOR ; 
 int VMCS_GUEST_DR7 ; 
 int VMCS_GUEST_DS_ACCESS_RIGHTS ; 
 int VMCS_GUEST_DS_BASE ; 
 int VMCS_GUEST_DS_LIMIT ; 
 int VMCS_GUEST_DS_SELECTOR ; 
 int VMCS_GUEST_ES_ACCESS_RIGHTS ; 
 int VMCS_GUEST_ES_BASE ; 
 int VMCS_GUEST_ES_LIMIT ; 
 int VMCS_GUEST_ES_SELECTOR ; 
 int VMCS_GUEST_FS_ACCESS_RIGHTS ; 
 int VMCS_GUEST_FS_BASE ; 
 int VMCS_GUEST_FS_LIMIT ; 
 int VMCS_GUEST_FS_SELECTOR ; 
 int VMCS_GUEST_GDTR_BASE ; 
 int VMCS_GUEST_GDTR_LIMIT ; 
 int VMCS_GUEST_GS_ACCESS_RIGHTS ; 
 int VMCS_GUEST_GS_BASE ; 
 int VMCS_GUEST_GS_LIMIT ; 
 int VMCS_GUEST_GS_SELECTOR ; 
 int VMCS_GUEST_IA32_EFER ; 
 int VMCS_GUEST_IDTR_BASE ; 
 int VMCS_GUEST_IDTR_LIMIT ; 
 int VMCS_GUEST_LDTR_ACCESS_RIGHTS ; 
 int VMCS_GUEST_LDTR_BASE ; 
 int VMCS_GUEST_LDTR_LIMIT ; 
 int VMCS_GUEST_LDTR_SELECTOR ; 
 int VMCS_GUEST_PDPTE0 ; 
 int VMCS_GUEST_PDPTE1 ; 
 int VMCS_GUEST_PDPTE2 ; 
 int VMCS_GUEST_PDPTE3 ; 
 int VMCS_GUEST_RFLAGS ; 
 int VMCS_GUEST_RIP ; 
 int VMCS_GUEST_RSP ; 
 int VMCS_GUEST_SS_ACCESS_RIGHTS ; 
 int VMCS_GUEST_SS_BASE ; 
 int VMCS_GUEST_SS_LIMIT ; 
 int VMCS_GUEST_SS_SELECTOR ; 
 int VMCS_GUEST_TR_ACCESS_RIGHTS ; 
 int VMCS_GUEST_TR_BASE ; 
 int VMCS_GUEST_TR_LIMIT ; 
 int VMCS_GUEST_TR_SELECTOR ; 
 int VMCS_INVALID_ENCODING ; 
#define  VM_REG_GUEST_CR0 149 
#define  VM_REG_GUEST_CR3 148 
#define  VM_REG_GUEST_CR4 147 
#define  VM_REG_GUEST_CS 146 
#define  VM_REG_GUEST_DR7 145 
#define  VM_REG_GUEST_DS 144 
#define  VM_REG_GUEST_EFER 143 
#define  VM_REG_GUEST_ES 142 
#define  VM_REG_GUEST_FS 141 
#define  VM_REG_GUEST_GDTR 140 
#define  VM_REG_GUEST_GS 139 
#define  VM_REG_GUEST_IDTR 138 
#define  VM_REG_GUEST_LDTR 137 
#define  VM_REG_GUEST_PDPTE0 136 
#define  VM_REG_GUEST_PDPTE1 135 
#define  VM_REG_GUEST_PDPTE2 134 
#define  VM_REG_GUEST_PDPTE3 133 
#define  VM_REG_GUEST_RFLAGS 132 
#define  VM_REG_GUEST_RIP 131 
#define  VM_REG_GUEST_RSP 130 
#define  VM_REG_GUEST_SS 129 
#define  VM_REG_GUEST_TR 128 
 void* vmcs_read (int,int) ; 
 int /*<<< orphan*/  vmcs_write (int,int,int) ; 
 int vmx_fix_cr0 (int) ; 
 int vmx_fix_cr4 (int) ; 
 int /*<<< orphan*/  xhyve_abort (char*,int) ; 

__attribute__((used)) static uint64_t
vmcs_fix_regval(uint32_t encoding, uint64_t val)
{

	switch (encoding) {
	case VMCS_GUEST_CR0:
		val = vmx_fix_cr0(val);
		break;
	case VMCS_GUEST_CR4:
		val = vmx_fix_cr4(val);
		break;
	default:
		break;
	}
	return (val);
}

__attribute__((used)) static uint32_t
vmcs_field_encoding(int ident)
{
	switch (ident) {
	case VM_REG_GUEST_CR0:
		return (VMCS_GUEST_CR0);
	case VM_REG_GUEST_CR3:
		return (VMCS_GUEST_CR3);
	case VM_REG_GUEST_CR4:
		return (VMCS_GUEST_CR4);
	case VM_REG_GUEST_DR7:
		return (VMCS_GUEST_DR7);
	case VM_REG_GUEST_RSP:
		return (VMCS_GUEST_RSP);
	case VM_REG_GUEST_RIP:
		return (VMCS_GUEST_RIP);
	case VM_REG_GUEST_RFLAGS:
		return (VMCS_GUEST_RFLAGS);
	case VM_REG_GUEST_ES:
		return (VMCS_GUEST_ES_SELECTOR);
	case VM_REG_GUEST_CS:
		return (VMCS_GUEST_CS_SELECTOR);
	case VM_REG_GUEST_SS:
		return (VMCS_GUEST_SS_SELECTOR);
	case VM_REG_GUEST_DS:
		return (VMCS_GUEST_DS_SELECTOR);
	case VM_REG_GUEST_FS:
		return (VMCS_GUEST_FS_SELECTOR);
	case VM_REG_GUEST_GS:
		return (VMCS_GUEST_GS_SELECTOR);
	case VM_REG_GUEST_TR:
		return (VMCS_GUEST_TR_SELECTOR);
	case VM_REG_GUEST_LDTR:
		return (VMCS_GUEST_LDTR_SELECTOR);
	case VM_REG_GUEST_EFER:
		return (VMCS_GUEST_IA32_EFER);
	case VM_REG_GUEST_PDPTE0:
		return (VMCS_GUEST_PDPTE0);
	case VM_REG_GUEST_PDPTE1:
		return (VMCS_GUEST_PDPTE1);
	case VM_REG_GUEST_PDPTE2:
		return (VMCS_GUEST_PDPTE2);
	case VM_REG_GUEST_PDPTE3:
		return (VMCS_GUEST_PDPTE3);
	default:
		return ((uint32_t) -1);
	}

}

__attribute__((used)) static int
vmcs_seg_desc_encoding(int seg, uint32_t *base, uint32_t *lim, uint32_t *acc)
{

	switch (seg) {
	case VM_REG_GUEST_ES:
		*base = VMCS_GUEST_ES_BASE;
		*lim = VMCS_GUEST_ES_LIMIT;
		*acc = VMCS_GUEST_ES_ACCESS_RIGHTS;
		break;
	case VM_REG_GUEST_CS:
		*base = VMCS_GUEST_CS_BASE;
		*lim = VMCS_GUEST_CS_LIMIT;
		*acc = VMCS_GUEST_CS_ACCESS_RIGHTS;
		break;
	case VM_REG_GUEST_SS:
		*base = VMCS_GUEST_SS_BASE;
		*lim = VMCS_GUEST_SS_LIMIT;
		*acc = VMCS_GUEST_SS_ACCESS_RIGHTS;
		break;
	case VM_REG_GUEST_DS:
		*base = VMCS_GUEST_DS_BASE;
		*lim = VMCS_GUEST_DS_LIMIT;
		*acc = VMCS_GUEST_DS_ACCESS_RIGHTS;
		break;
	case VM_REG_GUEST_FS:
		*base = VMCS_GUEST_FS_BASE;
		*lim = VMCS_GUEST_FS_LIMIT;
		*acc = VMCS_GUEST_FS_ACCESS_RIGHTS;
		break;
	case VM_REG_GUEST_GS:
		*base = VMCS_GUEST_GS_BASE;
		*lim = VMCS_GUEST_GS_LIMIT;
		*acc = VMCS_GUEST_GS_ACCESS_RIGHTS;
		break;
	case VM_REG_GUEST_TR:
		*base = VMCS_GUEST_TR_BASE;
		*lim = VMCS_GUEST_TR_LIMIT;
		*acc = VMCS_GUEST_TR_ACCESS_RIGHTS;
		break;
	case VM_REG_GUEST_LDTR:
		*base = VMCS_GUEST_LDTR_BASE;
		*lim = VMCS_GUEST_LDTR_LIMIT;
		*acc = VMCS_GUEST_LDTR_ACCESS_RIGHTS;
		break;
	case VM_REG_GUEST_IDTR:
		*base = VMCS_GUEST_IDTR_BASE;
		*lim = VMCS_GUEST_IDTR_LIMIT;
		*acc = VMCS_INVALID_ENCODING;
		break;
	case VM_REG_GUEST_GDTR:
		*base = VMCS_GUEST_GDTR_BASE;
		*lim = VMCS_GUEST_GDTR_LIMIT;
		*acc = VMCS_INVALID_ENCODING;
		break;
	default:
		return (EINVAL);
	}

	return (0);
}

int
vmcs_getreg(int vcpuid, int ident, uint64_t *retval)
{
	uint32_t encoding;

	/*
	 * If we need to get at vmx-specific state in the VMCS we can bypass
	 * the translation of 'ident' to 'encoding' by simply setting the
	 * sign bit. As it so happens the upper 16 bits are reserved (i.e
	 * set to 0) in the encodings for the VMCS so we are free to use the
	 * sign bit.
	 */
	if (ident < 0)
		encoding = ident & 0x7fffffff;
	else
		encoding = vmcs_field_encoding(ident);

	if (encoding == (uint32_t)-1)
		return (EINVAL);

	*retval = vmcs_read(vcpuid, encoding);

	return (0);
}

int
vmcs_setreg(int vcpuid, int ident, uint64_t val)
{
	uint32_t encoding;

	if (ident < 0)
		encoding = ident & 0x7fffffff;
	else
		encoding = vmcs_field_encoding(ident);

	if (encoding == (uint32_t)-1)
		return (EINVAL);

	val = vmcs_fix_regval(encoding, val);

	vmcs_write(vcpuid, encoding, val);

	return (0);
}

int
vmcs_setdesc(int vcpuid, int seg, struct seg_desc *desc)
{
	int error;
	uint32_t base, limit, access;

	error = vmcs_seg_desc_encoding(seg, &base, &limit, &access);
	if (error != 0)
		xhyve_abort("vmcs_setdesc: invalid segment register %d\n", seg);

	vmcs_write(vcpuid, base, desc->base);
	vmcs_write(vcpuid, limit, desc->limit);
	if (access != VMCS_INVALID_ENCODING) {
		vmcs_write(vcpuid, access, desc->access);
	}

	return (0);
}

int
vmcs_getdesc(int vcpuid, int seg, struct seg_desc *desc)
{
	int error;
	uint32_t base, limit, access;

	error = vmcs_seg_desc_encoding(seg, &base, &limit, &access);
	if (error != 0)
		xhyve_abort("vmcs_setdesc: invalid segment register %d\n", seg);

	desc->base = vmcs_read(vcpuid, base);
	desc->limit = (uint32_t) vmcs_read(vcpuid, limit);
	if (access != VMCS_INVALID_ENCODING) {
		desc->access = (uint32_t) vmcs_read(vcpuid, access);
	}

	return (0);
}

