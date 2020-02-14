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
typedef  enum OID { ____Placeholder_OID } OID ;
struct TYPE_2__ {unsigned char hash; int oid; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int EBADMSG ; 
 int ENOBUFS ; 
 int OID__NR ; 
 unsigned char* oid_data ; 
 size_t* oid_index ; 
 TYPE_1__* oid_search_table ; 
 int snprintf (char*,size_t,char*,...) ; 

enum OID look_up_OID(const void *data, size_t datasize)
{
	const unsigned char *octets = data;
	enum OID oid;
	unsigned char xhash;
	unsigned i, j, k, hash;
	size_t len;

	/* Hash the OID data */
	hash = datasize - 1;

	for (i = 0; i < datasize; i++)
		hash += octets[i] * 33;
	hash = (hash >> 24) ^ (hash >> 16) ^ (hash >> 8) ^ hash;
	hash &= 0xff;

	/* Binary search the OID registry.  OIDs are stored in ascending order
	 * of hash value then ascending order of size and then in ascending
	 * order of reverse value.
	 */
	i = 0;
	k = OID__NR;
	while (i < k) {
		j = (i + k) / 2;

		xhash = oid_search_table[j].hash;
		if (xhash > hash) {
			k = j;
			continue;
		}
		if (xhash < hash) {
			i = j + 1;
			continue;
		}

		oid = oid_search_table[j].oid;
		len = oid_index[oid + 1] - oid_index[oid];
		if (len > datasize) {
			k = j;
			continue;
		}
		if (len < datasize) {
			i = j + 1;
			continue;
		}

		/* Variation is most likely to be at the tail end of the
		 * OID, so do the comparison in reverse.
		 */
		while (len > 0) {
			unsigned char a = oid_data[oid_index[oid] + --len];
			unsigned char b = octets[len];
			if (a > b) {
				k = j;
				goto next;
			}
			if (a < b) {
				i = j + 1;
				goto next;
			}
		}
		return oid;
	next:
		;
	}

	return OID__NR;
}

int sprint_oid(const void *data, size_t datasize, char *buffer, size_t bufsize)
{
	const unsigned char *v = data, *end = v + datasize;
	unsigned long num;
	unsigned char n;
	size_t ret;
	int count;

	if (v >= end)
		goto bad;

	n = *v++;
	ret = count = snprintf(buffer, bufsize, "%u.%u", n / 40, n % 40);
	if (count >= bufsize)
		return -ENOBUFS;
	buffer += count;
	bufsize -= count;

	while (v < end) {
		num = 0;
		n = *v++;
		if (!(n & 0x80)) {
			num = n;
		} else {
			num = n & 0x7f;
			do {
				if (v >= end)
					goto bad;
				n = *v++;
				num <<= 7;
				num |= n & 0x7f;
			} while (n & 0x80);
		}
		ret += count = snprintf(buffer, bufsize, ".%lu", num);
		if (count >= bufsize)
			return -ENOBUFS;
		buffer += count;
		bufsize -= count;
	}

	return ret;

bad:
	snprintf(buffer, bufsize, "(bad)");
	return -EBADMSG;
}

int sprint_OID(enum OID oid, char *buffer, size_t bufsize)
{
	int ret;

	BUG_ON(oid >= OID__NR);

	ret = sprint_oid(oid_data + oid_index[oid],
			 oid_index[oid + 1] - oid_index[oid],
			 buffer, bufsize);
	BUG_ON(ret == -EBADMSG);
	return ret;
}

