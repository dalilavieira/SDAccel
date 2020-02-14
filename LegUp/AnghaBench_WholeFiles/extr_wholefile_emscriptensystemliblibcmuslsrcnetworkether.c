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
struct ether_addr {unsigned long* ether_addr_octet; } ;

/* Variables and functions */
 int /*<<< orphan*/  sprintf (char*,char*,unsigned long) ; 
 unsigned long strtoul (char const*,char**,int) ; 

struct ether_addr *ether_aton_r (const char *x, struct ether_addr *p_a)
{
	struct ether_addr a;
	char *y;
	for (int ii = 0; ii < 6; ii++) {
		unsigned long int n;
		if (ii != 0) {
			if (x[0] != ':') return 0; /* bad format */
			else x++;
		}
		n = strtoul (x, &y, 16);
		x = y;
		if (n > 0xFF) return 0; /* bad byte */
		a.ether_addr_octet[ii] = n;
	}
	if (x[0] != 0) return 0; /* bad format */
	*p_a = a;
	return p_a;
}

struct ether_addr *ether_aton (const char *x)
{
	static struct ether_addr a;
	return ether_aton_r (x, &a);
}

char *ether_ntoa_r (const struct ether_addr *p_a, char *x) {
	char *y;
	y = x;
	for (int ii = 0; ii < 6; ii++) {
		x += sprintf (x, ii == 0 ? "%.2X" : ":%.2X", p_a->ether_addr_octet[ii]);
	}
	return y;
}

char *ether_ntoa (const struct ether_addr *p_a) {
	static char x[18];
	return ether_ntoa_r (p_a, x);
}

int ether_line(const char *l, struct ether_addr *e, char *hostname)
{
	return -1;
}

int ether_ntohost(char *hostname, const struct ether_addr *e)
{
	return -1;
}

int ether_hostton(const char *hostname, struct ether_addr *e)
{
	return -1;
}

