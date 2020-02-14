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
typedef  void* u32 ;
struct sockaddr_vm {scalar_t__ svm_family; scalar_t__ svm_cid; scalar_t__ svm_port; scalar_t__* svm_zero; } ;
struct sockaddr {int dummy; } ;

/* Variables and functions */
 scalar_t__ AF_VSOCK ; 
 int EAFNOSUPPORT ; 
 int EFAULT ; 
 int EINVAL ; 
 void* VMADDR_CID_ANY ; 
 scalar_t__ VMADDR_PORT_ANY ; 
 int /*<<< orphan*/  memset (struct sockaddr_vm*,int /*<<< orphan*/ ,int) ; 

void vsock_addr_init(struct sockaddr_vm *addr, u32 cid, u32 port)
{
	memset(addr, 0, sizeof(*addr));
	addr->svm_family = AF_VSOCK;
	addr->svm_cid = cid;
	addr->svm_port = port;
}

int vsock_addr_validate(const struct sockaddr_vm *addr)
{
	if (!addr)
		return -EFAULT;

	if (addr->svm_family != AF_VSOCK)
		return -EAFNOSUPPORT;

	if (addr->svm_zero[0] != 0)
		return -EINVAL;

	return 0;
}

bool vsock_addr_bound(const struct sockaddr_vm *addr)
{
	return addr->svm_port != VMADDR_PORT_ANY;
}

void vsock_addr_unbind(struct sockaddr_vm *addr)
{
	vsock_addr_init(addr, VMADDR_CID_ANY, VMADDR_PORT_ANY);
}

bool vsock_addr_equals_addr(const struct sockaddr_vm *addr,
			    const struct sockaddr_vm *other)
{
	return addr->svm_cid == other->svm_cid &&
		addr->svm_port == other->svm_port;
}

int vsock_addr_cast(const struct sockaddr *addr,
		    size_t len, struct sockaddr_vm **out_addr)
{
	if (len < sizeof(**out_addr))
		return -EFAULT;

	*out_addr = (struct sockaddr_vm *)addr;
	return vsock_addr_validate(*out_addr);
}

