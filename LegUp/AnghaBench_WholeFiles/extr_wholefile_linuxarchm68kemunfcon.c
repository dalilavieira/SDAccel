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
struct tty_struct {int dummy; } ;
struct tty_driver {int dummy; } ;
struct file {int dummy; } ;
struct console {int flags; } ;

/* Variables and functions */
 int CON_ENABLED ; 
 int /*<<< orphan*/  memcpy (char*,char const*,unsigned int) ; 
 int /*<<< orphan*/  nf_call (int /*<<< orphan*/ ,unsigned long) ; 
 struct tty_driver* nfcon_tty_driver ; 
 int /*<<< orphan*/  stderr_id ; 
 unsigned long virt_to_phys (char*) ; 

__attribute__((used)) static void nfputs(const char *str, unsigned int count)
{
	char buf[68];
	unsigned long phys = virt_to_phys(buf);

	buf[64] = 0;
	while (count > 64) {
		memcpy(buf, str, 64);
		nf_call(stderr_id, phys);
		str += 64;
		count -= 64;
	}
	memcpy(buf, str, count);
	buf[count] = 0;
	nf_call(stderr_id, phys);
}

__attribute__((used)) static void nfcon_write(struct console *con, const char *str,
			unsigned int count)
{
	nfputs(str, count);
}

__attribute__((used)) static struct tty_driver *nfcon_device(struct console *con, int *index)
{
	*index = 0;
	return (con->flags & CON_ENABLED) ? nfcon_tty_driver : NULL;
}

__attribute__((used)) static int nfcon_tty_open(struct tty_struct *tty, struct file *filp)
{
	return 0;
}

__attribute__((used)) static void nfcon_tty_close(struct tty_struct *tty, struct file *filp)
{
}

__attribute__((used)) static int nfcon_tty_write(struct tty_struct *tty, const unsigned char *buf,
			   int count)
{
	nfputs(buf, count);
	return count;
}

__attribute__((used)) static int nfcon_tty_put_char(struct tty_struct *tty, unsigned char ch)
{
	char temp[2] = { ch, 0 };

	nf_call(stderr_id, virt_to_phys(temp));
	return 1;
}

__attribute__((used)) static int nfcon_tty_write_room(struct tty_struct *tty)
{
	return 64;
}

