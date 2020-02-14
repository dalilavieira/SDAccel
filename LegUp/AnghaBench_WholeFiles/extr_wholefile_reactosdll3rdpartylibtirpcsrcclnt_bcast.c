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
struct sockaddr_in {int /*<<< orphan*/  sin_port; } ;
struct ifaddrs {int ifa_flags; scalar_t__ ifa_broadaddr; int /*<<< orphan*/  ifa_name; TYPE_1__* ifa_addr; struct ifaddrs* ifa_next; } ;
struct broadif {int /*<<< orphan*/  broadaddr; int /*<<< orphan*/  index; } ;
struct addrinfo {int ai_family; int ai_protocol; int ai_socktype; scalar_t__ ai_addr; } ;
typedef  int /*<<< orphan*/  broadlist_t ;
struct TYPE_2__ {int sa_family; } ;

/* Variables and functions */
 int IFF_BROADCAST ; 
 int IFF_UP ; 
 scalar_t__ SOCKET_ERROR ; 
 int /*<<< orphan*/  SOL_SOCKET ; 
 int /*<<< orphan*/  SO_BROADCAST ; 
 struct broadif* TAILQ_FIRST (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TAILQ_INSERT_TAIL (int /*<<< orphan*/ *,struct broadif*,int /*<<< orphan*/ ) ; 
 struct broadif* TAILQ_NEXT (struct broadif*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (struct broadif*) ; 
 int /*<<< orphan*/  freeaddrinfo (struct addrinfo*) ; 
 int /*<<< orphan*/  freeifaddrs (struct ifaddrs*) ; 
 scalar_t__ getaddrinfo (int /*<<< orphan*/ *,char*,struct addrinfo*,struct addrinfo**) ; 
 int /*<<< orphan*/  if_nametoindex (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  link ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,scalar_t__,int) ; 
 int /*<<< orphan*/  memset (struct addrinfo*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ setsockopt (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 

int
__rpc_getbroadifs(int af, int proto, int socktype, broadlist_t *list)
{
	int count = 0;
	struct broadif *bip;
	struct ifaddrs *ifap, *ifp;
#ifdef INET6
	struct sockaddr_in6 *sin6;
#endif
	struct sockaddr_in *sin;
	struct addrinfo hints, *res;

#if 0	/* WINDOWS */
	if (getifaddrs(&ifp) < 0)
		return 0;
#else
	/* Use GetAdaptersAddresses() ? */
#endif

	memset(&hints, 0, sizeof hints);

	hints.ai_family = af;
	hints.ai_protocol = proto;
	hints.ai_socktype = socktype;

	if (getaddrinfo(NULL, "sunrpc", &hints, &res) != 0)
		return 0;

	for (ifap = ifp; ifap != NULL; ifap = ifap->ifa_next) {
		if (ifap->ifa_addr->sa_family != af ||
		    !(ifap->ifa_flags & IFF_UP))
			continue;
		bip = (struct broadif *)malloc(sizeof *bip);
		if (bip == NULL)
			break;
		bip->index = if_nametoindex(ifap->ifa_name);
		if (
#ifdef INET6
		af != AF_INET6 &&
#endif
		(ifap->ifa_flags & IFF_BROADCAST) &&
		 ifap->ifa_broadaddr) {
		  /*	memcpy(&bip->broadaddr, ifap->ifa_broadaddr,
			(size_t)ifap->ifa_broadaddr->sa_len);*/
			memcpy(&bip->broadaddr, ifap->ifa_broadaddr,
					sizeof(bip->broadaddr));
			sin = (struct sockaddr_in *)(void *)&bip->broadaddr;
			sin->sin_port =
			    ((struct sockaddr_in *)
			    (void *)res->ai_addr)->sin_port;
		} else
#ifdef INET6
		if (af == AF_INET6 && (ifap->ifa_flags & IFF_MULTICAST)) {
			sin6 = (struct sockaddr_in6 *)(void *)&bip->broadaddr;
			inet_pton(af, RPCB_MULTICAST_ADDR, &sin6->sin6_addr);
			sin6->sin6_family = af;
			sin6->sin6_port =
			    ((struct sockaddr_in6 *)
			    (void *)res->ai_addr)->sin6_port;
			sin6->sin6_scope_id = bip->index;
		} else
#endif
		{
			free(bip);
			continue;
		}
		TAILQ_INSERT_TAIL(list, bip, link);
		count++;
	}
	freeifaddrs(ifp);
	freeaddrinfo(res);

	return count;
}

void
__rpc_freebroadifs(broadlist_t *list)
{
	struct broadif *bip, *next;

	bip = TAILQ_FIRST(list);

	while (bip != NULL) {
		next = TAILQ_NEXT(bip, link);
		free(bip);
		bip = next;
	}
}

int
/*ARGSUSED*/
__rpc_broadenable(int af, int s, struct broadif *bip)
{
	int o = 1;

#if 0
	if (af == AF_INET6) {
		fprintf(stderr, "set v6 multicast if to %d\n", bip->index);
		if (setsockopt(s, IPPROTO_IPV6, IPV6_MULTICAST_IF, &bip->index,
		    sizeof bip->index) < 0)
			return -1;
	} else
#endif
		if (setsockopt(s, SOL_SOCKET, SO_BROADCAST, &o, sizeof o) == SOCKET_ERROR)
			return -1;

	return 0;
}

