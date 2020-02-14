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
struct slip_proto {unsigned char* ibuf; unsigned char* obuf; int more; int pos; int esc; } ;

/* Variables and functions */
#define  SLIP_END 131 
#define  SLIP_ESC 130 
#define  SLIP_ESC_END 129 
#define  SLIP_ESC_ESC 128 
 int /*<<< orphan*/  memcpy (void*,unsigned char*,int) ; 
 int /*<<< orphan*/  memmove (unsigned char*,unsigned char*,int) ; 
 int /*<<< orphan*/  memset (unsigned char*,int /*<<< orphan*/ ,int) ; 
 int net_read (int,unsigned char*,int) ; 
 int net_write (int,unsigned char*,int) ; 

__attribute__((used)) static inline int slip_unesc(unsigned char c, unsigned char *buf, int *pos,
                             int *esc)
{
	int ret;

	switch(c){
	case SLIP_END:
		*esc = 0;
		ret=*pos;
		*pos=0;
		return(ret);
	case SLIP_ESC:
		*esc = 1;
		return(0);
	case SLIP_ESC_ESC:
		if(*esc){
			*esc = 0;
			c = SLIP_ESC;
		}
		break;
	case SLIP_ESC_END:
		if(*esc){
			*esc = 0;
			c = SLIP_END;
		}
		break;
	}
	buf[(*pos)++] = c;
	return(0);
}

__attribute__((used)) static inline int slip_esc(unsigned char *s, unsigned char *d, int len)
{
	unsigned char *ptr = d;
	unsigned char c;

	/*
	 * Send an initial END character to flush out any
	 * data that may have accumulated in the receiver
	 * due to line noise.
	 */

	*ptr++ = SLIP_END;

	/*
	 * For each byte in the packet, send the appropriate
	 * character sequence, according to the SLIP protocol.
	 */

	while (len-- > 0) {
		switch(c = *s++) {
		case SLIP_END:
			*ptr++ = SLIP_ESC;
			*ptr++ = SLIP_ESC_END;
			break;
		case SLIP_ESC:
			*ptr++ = SLIP_ESC;
			*ptr++ = SLIP_ESC_ESC;
			break;
		default:
			*ptr++ = c;
			break;
		}
	}
	*ptr++ = SLIP_END;
	return (ptr - d);
}

__attribute__((used)) static inline void slip_proto_init(struct slip_proto * slip)
{
	memset(slip->ibuf, 0, sizeof(slip->ibuf));
	memset(slip->obuf, 0, sizeof(slip->obuf));
	slip->more = 0;
	slip->pos = 0;
	slip->esc = 0;
}

int slip_proto_read(int fd, void *buf, int len, struct slip_proto *slip)
{
	int i, n, size, start;

	if(slip->more > 0){
		i = 0;
		while(i < slip->more){
			size = slip_unesc(slip->ibuf[i++], slip->ibuf,
					  &slip->pos, &slip->esc);
			if(size){
				memcpy(buf, slip->ibuf, size);
				memmove(slip->ibuf, &slip->ibuf[i],
					slip->more - i);
				slip->more = slip->more - i;
				return size;
			}
		}
		slip->more = 0;
	}

	n = net_read(fd, &slip->ibuf[slip->pos],
		     sizeof(slip->ibuf) - slip->pos);
	if(n <= 0)
		return n;

	start = slip->pos;
	for(i = 0; i < n; i++){
		size = slip_unesc(slip->ibuf[start + i], slip->ibuf,&slip->pos,
				  &slip->esc);
		if(size){
			memcpy(buf, slip->ibuf, size);
			memmove(slip->ibuf, &slip->ibuf[start+i+1],
				n - (i + 1));
			slip->more = n - (i + 1);
			return size;
		}
	}
	return 0;
}

int slip_proto_write(int fd, void *buf, int len, struct slip_proto *slip)
{
	int actual, n;

	actual = slip_esc(buf, slip->obuf, len);
	n = net_write(fd, slip->obuf, actual);
	if(n < 0)
		return n;
	else return len;
}

