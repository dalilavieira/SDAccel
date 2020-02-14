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
struct thread_info {int /*<<< orphan*/  fpstate; } ;
struct notifier_block {int dummy; } ;
typedef  int float64 ;
typedef  int float32 ;
typedef  int flag ;
typedef  scalar_t__ bits64 ;
typedef  scalar_t__ bits32 ;

/* Variables and functions */
 int NOTIFY_DONE ; 
 unsigned long THREAD_NOTIFY_FLUSH ; 
 int /*<<< orphan*/  nwfpe_init_fpa (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline flag extractFloat32Sign(float32 a)
{
	return a >> 31;
}

__attribute__((used)) static inline flag float32_eq_nocheck(float32 a, float32 b)
{
	return (a == b) || ((bits32) ((a | b) << 1) == 0);
}

__attribute__((used)) static inline flag float32_lt_nocheck(float32 a, float32 b)
{
	flag aSign, bSign;

	aSign = extractFloat32Sign(a);
	bSign = extractFloat32Sign(b);
	if (aSign != bSign)
		return aSign && ((bits32) ((a | b) << 1) != 0);
	return (a != b) && (aSign ^ (a < b));
}

__attribute__((used)) static inline flag extractFloat64Sign(float64 a)
{
	return a >> 63;
}

__attribute__((used)) static inline flag float64_eq_nocheck(float64 a, float64 b)
{
	return (a == b) || ((bits64) ((a | b) << 1) == 0);
}

__attribute__((used)) static inline flag float64_lt_nocheck(float64 a, float64 b)
{
	flag aSign, bSign;

	aSign = extractFloat64Sign(a);
	bSign = extractFloat64Sign(b);
	if (aSign != bSign)
		return aSign && ((bits64) ((a | b) << 1) != 0);
	return (a != b) && (aSign ^ (a < b));
}

__attribute__((used)) static int nwfpe_notify(struct notifier_block *self, unsigned long cmd, void *v)
{
	struct thread_info *thread = v;

	if (cmd == THREAD_NOTIFY_FLUSH)
		nwfpe_init_fpa(&thread->fpstate);

	return NOTIFY_DONE;
}

