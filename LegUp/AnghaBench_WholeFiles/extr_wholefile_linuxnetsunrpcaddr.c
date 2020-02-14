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
typedef  int u8 ;
struct sockaddr_in6 {void* sin6_port; } ;
struct TYPE_2__ {int /*<<< orphan*/  s_addr; } ;
struct sockaddr_in {int sin_family; void* sin_port; TYPE_1__ sin_addr; } ;
struct sockaddr {int sa_family; } ;
struct net {int dummy; } ;
typedef  int /*<<< orphan*/  portbuf ;
typedef  int /*<<< orphan*/  gfp_t ;
typedef  int /*<<< orphan*/  addrbuf ;

/* Variables and functions */
#define  AF_INET 129 
#define  AF_INET6 128 
 size_t const INET_ADDRSTRLEN ; 
 int RPCBIND_MAXUADDRLEN ; 
 int RPCBIND_MAXUADDRPLEN ; 
 void* htons (unsigned short) ; 
 scalar_t__ in4_pton (char const*,size_t const,int*,char,int /*<<< orphan*/ *) ; 
 char* kstrdup (char*,int /*<<< orphan*/ ) ; 
 scalar_t__ kstrtou8 (char*,int,int*) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,size_t const) ; 
 int /*<<< orphan*/  memset (struct sockaddr*,int /*<<< orphan*/ ,int) ; 
 unsigned short ntohs (void*) ; 
 int snprintf (char*,size_t const,char*,...) ; 
 int strlcat (char*,char*,int) ; 
 size_t strlen (char*) ; 
 char* strrchr (char*,char) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static size_t rpc_ntop6_noscopeid(const struct sockaddr *sap,
				  char *buf, const int buflen)
{
	return 0;
}

__attribute__((used)) static size_t rpc_ntop6(const struct sockaddr *sap,
			char *buf, const size_t buflen)
{
	return 0;
}

__attribute__((used)) static int rpc_ntop4(const struct sockaddr *sap,
		     char *buf, const size_t buflen)
{
	const struct sockaddr_in *sin = (struct sockaddr_in *)sap;

	return snprintf(buf, buflen, "%pI4", &sin->sin_addr);
}

size_t rpc_ntop(const struct sockaddr *sap, char *buf, const size_t buflen)
{
	switch (sap->sa_family) {
	case AF_INET:
		return rpc_ntop4(sap, buf, buflen);
	case AF_INET6:
		return rpc_ntop6(sap, buf, buflen);
	}

	return 0;
}

__attribute__((used)) static size_t rpc_pton4(const char *buf, const size_t buflen,
			struct sockaddr *sap, const size_t salen)
{
	struct sockaddr_in *sin = (struct sockaddr_in *)sap;
	u8 *addr = (u8 *)&sin->sin_addr.s_addr;

	if (buflen > INET_ADDRSTRLEN || salen < sizeof(struct sockaddr_in))
		return 0;

	memset(sap, 0, sizeof(struct sockaddr_in));

	if (in4_pton(buf, buflen, addr, '\0', NULL) == 0)
		return 0;

	sin->sin_family = AF_INET;
	return sizeof(struct sockaddr_in);
}

__attribute__((used)) static size_t rpc_pton6(struct net *net, const char *buf, const size_t buflen,
			struct sockaddr *sap, const size_t salen)
{
	return 0;
}

size_t rpc_pton(struct net *net, const char *buf, const size_t buflen,
		struct sockaddr *sap, const size_t salen)
{
	unsigned int i;

	for (i = 0; i < buflen; i++)
		if (buf[i] == ':')
			return rpc_pton6(net, buf, buflen, sap, salen);
	return rpc_pton4(buf, buflen, sap, salen);
}

char *rpc_sockaddr2uaddr(const struct sockaddr *sap, gfp_t gfp_flags)
{
	char portbuf[RPCBIND_MAXUADDRPLEN];
	char addrbuf[RPCBIND_MAXUADDRLEN];
	unsigned short port;

	switch (sap->sa_family) {
	case AF_INET:
		if (rpc_ntop4(sap, addrbuf, sizeof(addrbuf)) == 0)
			return NULL;
		port = ntohs(((struct sockaddr_in *)sap)->sin_port);
		break;
	case AF_INET6:
		if (rpc_ntop6_noscopeid(sap, addrbuf, sizeof(addrbuf)) == 0)
			return NULL;
		port = ntohs(((struct sockaddr_in6 *)sap)->sin6_port);
		break;
	default:
		return NULL;
	}

	if (snprintf(portbuf, sizeof(portbuf),
		     ".%u.%u", port >> 8, port & 0xff) > (int)sizeof(portbuf))
		return NULL;

	if (strlcat(addrbuf, portbuf, sizeof(addrbuf)) > sizeof(addrbuf))
		return NULL;

	return kstrdup(addrbuf, gfp_flags);
}

size_t rpc_uaddr2sockaddr(struct net *net, const char *uaddr,
			  const size_t uaddr_len, struct sockaddr *sap,
			  const size_t salen)
{
	char *c, buf[RPCBIND_MAXUADDRLEN + sizeof('\0')];
	u8 portlo, porthi;
	unsigned short port;

	if (uaddr_len > RPCBIND_MAXUADDRLEN)
		return 0;

	memcpy(buf, uaddr, uaddr_len);

	buf[uaddr_len] = '\0';
	c = strrchr(buf, '.');
	if (unlikely(c == NULL))
		return 0;
	if (unlikely(kstrtou8(c + 1, 10, &portlo) != 0))
		return 0;

	*c = '\0';
	c = strrchr(buf, '.');
	if (unlikely(c == NULL))
		return 0;
	if (unlikely(kstrtou8(c + 1, 10, &porthi) != 0))
		return 0;

	port = (unsigned short)((porthi << 8) | portlo);

	*c = '\0';
	if (rpc_pton(net, buf, strlen(buf), sap, salen) == 0)
		return 0;

	switch (sap->sa_family) {
	case AF_INET:
		((struct sockaddr_in *)sap)->sin_port = htons(port);
		return sizeof(struct sockaddr_in);
	case AF_INET6:
		((struct sockaddr_in6 *)sap)->sin6_port = htons(port);
		return sizeof(struct sockaddr_in6);
	}

	return 0;
}

