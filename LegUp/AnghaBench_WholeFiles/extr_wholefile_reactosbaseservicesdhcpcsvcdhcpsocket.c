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
struct sockaddr_in {int dummy; } ;
struct sockaddr {int dummy; } ;
struct interface_info {int /*<<< orphan*/  rfdesc; int /*<<< orphan*/  wfdesc; } ;
struct in_addr {int dummy; } ;
struct hardware {int dummy; } ;
struct dhcp_packet {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 int /*<<< orphan*/  SOCK_DGRAM ; 
 int /*<<< orphan*/  ServerSocket ; 
 int WSAENETUNREACH ; 
 int /*<<< orphan*/  note (char*,...) ; 
 int recvfrom (int /*<<< orphan*/ ,char*,size_t,int /*<<< orphan*/ ,struct sockaddr*,int*) ; 
 int sendto (int /*<<< orphan*/ ,char*,size_t,int /*<<< orphan*/ ,struct sockaddr*,int) ; 
 int /*<<< orphan*/  socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void SocketInit() {
    ServerSocket = socket( AF_INET, SOCK_DGRAM, 0 );
}

ssize_t send_packet( struct interface_info *ip,
                     struct dhcp_packet *p,
                     size_t size,
                     struct in_addr addr,
                     struct sockaddr_in *broadcast,
                     struct hardware *hardware ) {
    int result =
        sendto( ip->wfdesc, (char *)p, size, 0,
                (struct sockaddr *)broadcast, sizeof(*broadcast) );

    if (result < 0) {
        note ("send_packet: %x", result);
        if (result == WSAENETUNREACH)
            note ("send_packet: please consult README file%s",
                  " regarding broadcast address.");
    }

    return result;
}

ssize_t receive_packet(struct interface_info *ip,
                       unsigned char *packet_data,
                       size_t packet_len,
                       struct sockaddr_in *dest,
                       struct hardware *hardware ) {
    int recv_addr_size = sizeof(*dest);
    int result =
        recvfrom (ip -> rfdesc, (char *)packet_data, packet_len, 0,
                  (struct sockaddr *)dest, &recv_addr_size );
    return result;
}

