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
typedef  unsigned char ut8 ;
typedef  int /*<<< orphan*/  RSocket ;

/* Variables and functions */
 int atoi (char const*) ; 
 int /*<<< orphan*/  free (char*) ; 
 char* malloc (int) ; 
 int /*<<< orphan*/  memcpy (char*,char*,int) ; 
 int /*<<< orphan*/  r_socket_block_time (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  r_socket_close (int /*<<< orphan*/ *) ; 
 int r_socket_read_block (int /*<<< orphan*/ *,unsigned char*,int) ; 
 char* r_str_casestr (char*,char*) ; 

__attribute__((used)) static char *r_socket_http_answer (RSocket *s, int *code, int *rlen) {
	const char *p;
	int ret, olen, len = 0, bufsz = 32768, delta = 0;
	char *dn, *res, *buf = malloc (bufsz + 32); // XXX: use r_buffer here
	if (!buf) {
		return NULL;
	}

	r_socket_block_time (s, 1, 5);
	res = NULL;
	olen = r_socket_read_block (s, (unsigned char*) buf, bufsz);
	if (olen < 1) {
		goto fail;
	}
	buf[olen] = 0;
	if ((dn = (char*)r_str_casestr (buf, "\n\n"))) {
		delta += 2;
	} else if ((dn = (char*)r_str_casestr (buf, "\r\n\r\n"))) {
		delta += 4;
	} else {
		goto fail;
	}

	olen -= delta;
	*dn = 0; // chop headers
	/* Parse Len */
	p = r_str_casestr (buf, "Content-Length: ");
	if (p) {
		len = atoi (p + 16);
	} else {
		len = olen - (dn - buf);
	}

	if (len >0) {
		if (len > olen) {
			res = malloc (len+2);
			memcpy (res, dn+delta, olen);
			do {
				ret = r_socket_read_block (s,
					(ut8*) res+olen, len-olen);
				if (ret < 1) {
					break;
				}
				olen += ret;
			} while (olen<len);
			res[len] = 0;
		} else {
			res = malloc (len+1);
			if (res) {
				memcpy (res, dn+delta, len);
				res[len] = 0;
			}
		}
	} else {
		res = NULL;
	}
fail:
	free (buf);
// is 's' free'd? isnt this going to cause a double free?
	r_socket_close (s);
	if (rlen) {
		*rlen = len;
	}
	return res;
}

