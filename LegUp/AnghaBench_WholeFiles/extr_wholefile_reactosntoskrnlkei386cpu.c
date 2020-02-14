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
typedef  scalar_t__ ULONG_PTR ;
typedef  int /*<<< orphan*/  UCHAR ;
typedef  int /*<<< orphan*/  PUCHAR ;

/* Variables and functions */
 int /*<<< orphan*/  READ_PORT_UCHAR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WRITE_PORT_UCHAR (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static __inline
UCHAR
getCx86(UCHAR reg)
{
    WRITE_PORT_UCHAR((PUCHAR)(ULONG_PTR)0x22, reg);
    return READ_PORT_UCHAR((PUCHAR)(ULONG_PTR)0x23);
}

__attribute__((used)) static __inline
void
setCx86(UCHAR reg, UCHAR data)
{
    WRITE_PORT_UCHAR((PUCHAR)(ULONG_PTR)0x22, reg);
    WRITE_PORT_UCHAR((PUCHAR)(ULONG_PTR)0x23, data);
}

