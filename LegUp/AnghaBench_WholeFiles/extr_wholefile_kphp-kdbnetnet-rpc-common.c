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
struct rpcx_data {int /*<<< orphan*/  out_packet_num; } ;
struct nb_iterator {int dummy; } ;
struct msg_part {int dummy; } ;
struct connection {unsigned int our_ip; unsigned char* our_ipv6; unsigned int remote_ip; unsigned char* remote_ipv6; int flags; int /*<<< orphan*/  Out; scalar_t__ custom_data; int /*<<< orphan*/  fd; int /*<<< orphan*/  In; } ;

/* Variables and functions */
 int C_RAWMSG ; 
 int RPC_PING ; 
 int /*<<< orphan*/  assert (int) ; 
 int compute_crc32 (int*,int) ; 
 int /*<<< orphan*/  flush_later (struct connection*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  free (struct msg_part*) ; 
 scalar_t__ malloc (int) ; 
 int nbit_read_in (struct nb_iterator*,int*,int) ; 
 int /*<<< orphan*/  nbit_set (struct nb_iterator*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rwm_total_msg_parts ; 
 char* show_ip (unsigned int) ; 
 char* show_ipv6 (unsigned char const*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  vkprintf (int,char*,int /*<<< orphan*/ ,long long) ; 
 int /*<<< orphan*/  write_out (int /*<<< orphan*/ *,int*,int) ; 

__attribute__((used)) static inline int is_4in6 (unsigned char ipv6[16]) { return !*((long long *) ipv6) && ((int *) ipv6)[2] == -0x10000; }

__attribute__((used)) static inline unsigned extract_4in6 (unsigned char ipv6[16]) { return (((unsigned *) ipv6)[3]); }

__attribute__((used)) static inline void set_4in6 (unsigned char ipv6[16], unsigned ip) {  *(long long *) ipv6 = 0; ((int *) ipv6)[2] = -0x10000; ((int *) ipv6)[3] = ip; }

__attribute__((used)) static inline struct msg_part *alloc_msg_part (void) { return (struct msg_part *) malloc (sizeof (struct msg_part)); }

__attribute__((used)) static inline void free_msg_part (struct msg_part *mp) { rwm_total_msg_parts --; free (mp); }

__attribute__((used)) static inline char *show_ip46 (unsigned ip, const unsigned char ipv6[16]) { return ip ? show_ip (ip) : show_ipv6 (ipv6); }

__attribute__((used)) static inline char *show_our_ip (struct connection *c) { return show_ip46 (c->our_ip, c->our_ipv6); }

__attribute__((used)) static inline char *show_remote_ip (struct connection *c) { return show_ip46 (c->remote_ip, c->remote_ipv6); }

__attribute__((used)) static inline int is_ipv6_localhost (unsigned char ipv6[16]) {
  return !*(long long *)ipv6 && ((long long *)ipv6)[1] == 1LL << 56;
}

void dump_rpc_packet (int *packet) {
  int len = (*packet + 3) >> 2, i;
  for (i = 0; i < len; i++) {
    fprintf (stderr, "%08x ", packet[i]);
    if ((i & 3) == 3) {
      fprintf (stderr, "\n");
    }
  }
  fprintf (stderr, "\n");
}

void dump_next_rpc_packet_limit (struct connection *c, int max_ints) {
  struct nb_iterator it;
  int i = 0, len = 4, x;
  nbit_set (&it, &c->In);
  while (i * 4 < len && i < max_ints) {
    assert (nbit_read_in (&it, &x, 4) == 4);
    if (!i) {
      len = x;
    }
    fprintf (stderr, "%08x ", x);
    if (!(++i & 7)) {
      fprintf (stderr, "\n");
    }
  }
  fprintf (stderr, "\n");
}

void dump_next_rpc_packet (struct connection *c) {
  dump_next_rpc_packet_limit (c, 1 << 29);
}

void tcp_rpc_conn_send_data (struct connection *c, int len, void *data) {
  assert (0);
}

void net_rpc_send_ping (struct connection *c, long long ping_id) {
  if (!(c->flags & C_RAWMSG)) {
    vkprintf (2, "Sending ping to fd=%d. ping_id = %lld\n", c->fd, ping_id);
    static int P[20];
    P[0] = 24;
    P[1] = ((struct rpcx_data *) ((c)->custom_data))->out_packet_num++;
    P[2] = RPC_PING;
    *(long long *)(P + 3) = ping_id;
    P[5] = compute_crc32 (P, 20);
    write_out (&c->Out, P, 24);
    flush_later (c);
  } else {
    static int P[20];
    P[0] = RPC_PING;
    *(long long *)(P + 1) = ping_id;
    tcp_rpc_conn_send_data (c, 12, P);
    flush_later (c);
  }
}

