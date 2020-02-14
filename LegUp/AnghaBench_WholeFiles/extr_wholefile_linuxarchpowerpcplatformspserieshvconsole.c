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

/* Variables and functions */
 int EAGAIN ; 
 int EIO ; 
 long H_BUSY ; 
 int /*<<< orphan*/  H_GET_TERM_CHAR ; 
 int /*<<< orphan*/  H_PUT_TERM_CHAR ; 
 long H_SUCCESS ; 
 int MAX_VIO_PUT_CHARS ; 
 int PLPAR_HCALL_BUFSIZE ; 
 unsigned long be64_to_cpu (unsigned long) ; 
 int /*<<< orphan*/  cpu_to_be64 (unsigned long) ; 
 long plpar_hcall (int /*<<< orphan*/ ,unsigned long*,int /*<<< orphan*/ ) ; 
 long plpar_hcall_norets (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int hvc_get_chars(uint32_t vtermno, char *buf, int count)
{
	long ret;
	unsigned long retbuf[PLPAR_HCALL_BUFSIZE];
	unsigned long *lbuf = (unsigned long *)buf;

	ret = plpar_hcall(H_GET_TERM_CHAR, retbuf, vtermno);
	lbuf[0] = be64_to_cpu(retbuf[1]);
	lbuf[1] = be64_to_cpu(retbuf[2]);

	if (ret == H_SUCCESS)
		return retbuf[0];

	return 0;
}

int hvc_put_chars(uint32_t vtermno, const char *buf, int count)
{
	unsigned long *lbuf = (unsigned long *) buf;
	long ret;


	/* hcall will ret H_PARAMETER if 'count' exceeds firmware max.*/
	if (count > MAX_VIO_PUT_CHARS)
		count = MAX_VIO_PUT_CHARS;

	ret = plpar_hcall_norets(H_PUT_TERM_CHAR, vtermno, count,
				 cpu_to_be64(lbuf[0]),
				 cpu_to_be64(lbuf[1]));
	if (ret == H_SUCCESS)
		return count;
	if (ret == H_BUSY)
		return -EAGAIN;
	return -EIO;
}

