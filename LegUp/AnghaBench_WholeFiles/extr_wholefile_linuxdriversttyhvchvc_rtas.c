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
typedef  int /*<<< orphan*/  uint32_t ;
struct winsize {int dummy; } ;
struct hvc_struct {int /*<<< orphan*/  lock; } ;

/* Variables and functions */
 int /*<<< orphan*/  __hvc_resize (struct hvc_struct*,struct winsize) ; 
 scalar_t__ rtas_call (int /*<<< orphan*/ ,int,int,int*,...) ; 
 int /*<<< orphan*/  rtascons_get_char_token ; 
 int /*<<< orphan*/  rtascons_put_char_token ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline void hvc_resize(struct hvc_struct *hp, struct winsize ws)
{
	unsigned long flags;

	spin_lock_irqsave(&hp->lock, flags);
	__hvc_resize(hp, ws);
	spin_unlock_irqrestore(&hp->lock, flags);
}

__attribute__((used)) static inline int cpus_are_in_xmon(void)
{
	return 0;
}

__attribute__((used)) static inline int hvc_rtas_write_console(uint32_t vtermno, const char *buf,
		int count)
{
	int i;

	for (i = 0; i < count; i++) {
		if (rtas_call(rtascons_put_char_token, 1, 1, NULL, buf[i]))
			break;
	}

	return i;
}

__attribute__((used)) static int hvc_rtas_read_console(uint32_t vtermno, char *buf, int count)
{
	int i, c;

	for (i = 0; i < count; i++) {
		if (rtas_call(rtascons_get_char_token, 0, 2, &c))
			break;

		buf[i] = c;
	}

	return i;
}

