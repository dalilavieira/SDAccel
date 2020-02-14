#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u_int32_t ;
struct TYPE_2__ {size_t S_addr; } ;
struct in_addr {TYPE_1__ S_un; } ;
typedef  size_t ULONG ;
typedef  char CHAR ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (char*,char const*,size_t) ; 
 int rand () ; 
 int /*<<< orphan*/  srand (int /*<<< orphan*/ ) ; 
 size_t strlen (char const*) ; 

size_t strlcpy(char *d, const char *s, size_t bufsize)
{
        size_t len = strlen(s);
        size_t ret = len;
        if (bufsize > 0) {
                if (len >= bufsize)
                        len = bufsize-1;
                memcpy(d, s, len);
                d[len] = 0;
        }
        return ret;
}

u_int32_t arc4random()
{
	static int did_srand = 0;
	u_int32_t ret;

	if (!did_srand) {
		srand(0);
		did_srand = 1;
	}

	ret = rand() << 10 ^ rand();
	return ret;
}

int inet_aton(const char *cp, struct in_addr *inp)
/* inet_addr code from ROS, slightly modified. */
{
	ULONG Octets[4] = {0,0,0,0};
	ULONG i = 0;

	if(!cp)
		return 0;

	while(*cp)
	{
		CHAR c = *cp;
		cp++;

		if(c == '.')
		{
			i++;
			continue;
		}

		if(c < '0' || c > '9')
			return 0;

		Octets[i] *= 10;
		Octets[i] += (c - '0');

		if(Octets[i] > 255)
			return 0;
		}

	inp->S_un.S_addr = (Octets[3] << 24) + (Octets[2] << 16) + (Octets[1] << 8) + Octets[0];
	return 1;
}

