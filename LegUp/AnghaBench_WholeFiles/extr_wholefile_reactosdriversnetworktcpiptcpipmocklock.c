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
typedef  int /*<<< orphan*/  VOID ;
typedef  int /*<<< orphan*/  PLIST_ENTRY ;
typedef  int /*<<< orphan*/  PKSPIN_LOCK ;
typedef  scalar_t__* PKIRQL ;
typedef  int /*<<< orphan*/  PFAST_MUTEX ;
typedef  scalar_t__ KIRQL ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ DISPATCH_LEVEL ; 
 int /*<<< orphan*/  InsertTailList (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ KernelIrql ; 

KIRQL TcpipGetCurrentIrql() { return KernelIrql; }

VOID TcpipInitializeSpinLock( PKSPIN_LOCK SpinLock ) {
}

VOID TcpipAcquireSpinLock( PKSPIN_LOCK SpinLock, PKIRQL Irql ) {
    *Irql = KernelIrql;
    KernelIrql = DISPATCH_LEVEL;
}

VOID TcpipAcquireSpinLockAtDpcLevel( PKSPIN_LOCK SpinLock ) {
    ASSERT(KernelIrql == DISPATCH_LEVEL);
}

VOID TcpipReleaseSpinLock( PKSPIN_LOCK SpinLock, KIRQL Irql ) {
    ASSERT( Irql <= KernelIrql );
    KernelIrql = Irql;
}

VOID TcpipReleaseSpinLockFromDpcLevel( PKSPIN_LOCK SpinLock ) {
    ASSERT(KernelIrql == DISPATCH_LEVEL);
}

VOID TcpipInterlockedInsertTailList( PLIST_ENTRY ListHead,
				     PLIST_ENTRY Item,
				     PKSPIN_LOCK Lock ) {
    InsertTailList( ListHead, Item );
}

VOID TcpipAcquireFastMutex( PFAST_MUTEX Mutex ) {
}

VOID TcpipReleaseFastMutex( PFAST_MUTEX Mutex ) {
}

