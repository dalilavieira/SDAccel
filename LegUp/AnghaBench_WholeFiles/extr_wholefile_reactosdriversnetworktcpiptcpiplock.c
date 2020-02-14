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
typedef  int /*<<< orphan*/  PKIRQL ;
typedef  int /*<<< orphan*/  PFAST_MUTEX ;
typedef  int /*<<< orphan*/  KIRQL ;

/* Variables and functions */
 int /*<<< orphan*/  ExAcquireFastMutex (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExInterlockedInsertTailList (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ExReleaseFastMutex (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KeAcquireSpinLock (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KeAcquireSpinLockAtDpcLevel (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KeGetCurrentIrql () ; 
 int /*<<< orphan*/  KeInitializeSpinLock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KeReleaseSpinLock (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  KeReleaseSpinLockFromDpcLevel (int /*<<< orphan*/ ) ; 

KIRQL TcpipGetCurrentIrql() { return KeGetCurrentIrql(); }

VOID TcpipInitializeSpinLock( PKSPIN_LOCK SpinLock ) {
    KeInitializeSpinLock( SpinLock );
}

VOID TcpipAcquireSpinLock( PKSPIN_LOCK SpinLock, PKIRQL Irql ) {
    KeAcquireSpinLock( SpinLock, Irql );
}

VOID TcpipAcquireSpinLockAtDpcLevel( PKSPIN_LOCK SpinLock ) {
    KeAcquireSpinLockAtDpcLevel( SpinLock );
}

VOID TcpipReleaseSpinLock( PKSPIN_LOCK SpinLock, KIRQL Irql ) {
    KeReleaseSpinLock( SpinLock, Irql );
}

VOID TcpipReleaseSpinLockFromDpcLevel( PKSPIN_LOCK SpinLock ) {
    KeReleaseSpinLockFromDpcLevel( SpinLock );
}

VOID TcpipInterlockedInsertTailList( PLIST_ENTRY ListHead,
				     PLIST_ENTRY Item,
				     PKSPIN_LOCK Lock ) {
    ExInterlockedInsertTailList( ListHead, Item, Lock );
}

VOID TcpipAcquireFastMutex( PFAST_MUTEX Mutex ) {
    ExAcquireFastMutex( Mutex );
}

VOID TcpipReleaseFastMutex( PFAST_MUTEX Mutex ) {
    ExReleaseFastMutex( Mutex );
}

