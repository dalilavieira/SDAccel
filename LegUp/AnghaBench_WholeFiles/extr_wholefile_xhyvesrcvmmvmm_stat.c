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
typedef  int /*<<< orphan*/  uint64_t ;
struct vmm_stat_type {char* desc; scalar_t__ nelems; int index; int /*<<< orphan*/  (* func ) (struct vm*,int,struct vmm_stat_type*) ;} ;
struct vm {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ MAX_VMM_STAT_ELEMS ; 
 int VM_MAXCPU ; 
 int /*<<< orphan*/  bzero (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (void*) ; 
 void* malloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 int /*<<< orphan*/  snprintf (char*,size_t,char*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (char*,char*,size_t) ; 
 int /*<<< orphan*/  stub1 (struct vm*,int,struct vmm_stat_type*) ; 
 int /*<<< orphan*/ * vcpu_stats (struct vm*,int) ; 
 int vst_num_elems ; 
 int vst_num_types ; 
 int /*<<< orphan*/  vst_size ; 
 struct vmm_stat_type** vsttab ; 

void
vmm_stat_register(void *arg)
{
	struct vmm_stat_type *vst = arg;

	/* We require all stats to identify themselves with a description */
	if (vst->desc == NULL)
		return;

	if (vst_num_elems + vst->nelems >= MAX_VMM_STAT_ELEMS) {
		printf("Cannot accomodate vmm stat type \"%s\"!\n", vst->desc);
		return;
	}

	vst->index = vst_num_elems;
	vst_num_elems += vst->nelems;

	vsttab[vst_num_types++] = vst;
}

int
vmm_stat_copy(struct vm *vm, int vcpu, int *num_stats, uint64_t *buf)
{
	struct vmm_stat_type *vst;
	uint64_t *stats;
	int i;

	if (vcpu < 0 || vcpu >= VM_MAXCPU)
		return (EINVAL);

	/* Let stats functions update their counters */
	for (i = 0; i < vst_num_types; i++) {
		vst = vsttab[i];
		if (vst->func != NULL)
			(*vst->func)(vm, vcpu, vst);
	}

	/* Copy over the stats */
	stats = vcpu_stats(vm, vcpu);
	for (i = 0; i < vst_num_elems; i++)
		buf[i] = stats[i];
	*num_stats = vst_num_elems;
	return (0);
}

void *
vmm_stat_alloc(void)
{

	return (malloc(vst_size));
}

void
vmm_stat_init(void *vp)
{

	bzero(vp, vst_size);
}

void
vmm_stat_free(void *vp)
{
	free(vp);
}

int
vmm_stat_desc_copy(int index, char *buf, size_t bufsize)
{
	int i;
	struct vmm_stat_type *vst;

	for (i = 0; i < vst_num_types; i++) {
		vst = vsttab[i];
		if (index >= vst->index && index < vst->index + vst->nelems) {
			if (vst->nelems > 1) {
				snprintf(buf, bufsize, "%s[%d]",
					 vst->desc, index - vst->index);
			} else {
				strlcpy(buf, vst->desc, bufsize);
			}
			return (0);	/* found it */
		}
	}

	return (EINVAL);
}

