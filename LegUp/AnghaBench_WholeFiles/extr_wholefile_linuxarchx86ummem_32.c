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
struct vm_area_struct {unsigned long vm_start; unsigned long vm_end; } ;
struct mm_struct {int dummy; } ;

/* Variables and functions */
 unsigned long FIXADDR_USER_END ; 
 long FIXADDR_USER_START ; 
 struct vm_area_struct gate_vma ; 

struct vm_area_struct *get_gate_vma(struct mm_struct *mm)
{
	return FIXADDR_USER_START ? &gate_vma : NULL;
}

int in_gate_area_no_mm(unsigned long addr)
{
	if (!FIXADDR_USER_START)
		return 0;

	if ((addr >= FIXADDR_USER_START) && (addr < FIXADDR_USER_END))
		return 1;

	return 0;
}

int in_gate_area(struct mm_struct *mm, unsigned long addr)
{
	struct vm_area_struct *vma = get_gate_vma(mm);

	if (!vma)
		return 0;

	return (addr >= vma->vm_start) && (addr < vma->vm_end);
}

