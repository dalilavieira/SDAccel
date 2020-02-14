#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct netrule {int type; unsigned int ip; int mask1; int mask2; int level1; int level2; } ;
struct connection {int /*<<< orphan*/  extra; int /*<<< orphan*/  Out; } ;
struct TYPE_4__ {int /*<<< orphan*/  out_packet_num; } ;
struct TYPE_3__ {int /*<<< orphan*/  (* flush_packet ) (struct connection*) ;} ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int MAX_PACKET_LEN ; 
 int MAX_RULES ; 
 TYPE_2__* RPCS_DATA (struct connection*) ; 
 TYPE_1__* RPCS_FUNC (struct connection*) ; 
 int /*<<< orphan*/  assert (int) ; 
 int cr_ok ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  feof (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fgets (char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 struct netrule* network ; 
 int /*<<< orphan*/  rpc_set_crc32 (int*) ; 
 int /*<<< orphan*/  rpcc_flush_packet ; 
 int rules_num ; 
 int server_check_ready (struct connection*) ; 
 int sscanf (char*,char*,unsigned int*,unsigned int*,unsigned int*,unsigned int*,unsigned int*,...) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stub1 (struct connection*) ; 
 int verbosity ; 
 int /*<<< orphan*/  write_out (int /*<<< orphan*/ *,int*,int) ; 

int read_rule (char *s, struct netrule *A) {
  unsigned x,y,z,t;
  unsigned mask1, mask2;
  int type = 0;
  if (sscanf (s, "%u.%u.%u.%u/%u /%u", &x, &y, &z, &t, &mask1, &mask2) == 6) {
    type = 2;
  } else if (sscanf (s, "%u.%u.%u.%u/%u", &x, &y, &z, &t, &mask1) == 5)  {
    type = 1;
  }
  if (type) {
    if (x >= 256 || y >= 256 || z >= 256 || t >= 256 || mask1 >= 32 || (type == 2 && mask2 >= 32)) {
      return 0;
    }
    A->type = type;
    A->ip = (x << 24) + (y << 16) + (z << 8) + t;
    A->mask1 = (1 << (32 - mask1)) - 1;
    A->mask2 = (1 << (32 - mask2)) - 1;
    A->level1 = 32 - mask1;
    A->level2 = 32 - mask2;
    return 1;
  } else {
    return 0;
  }
}

int read_network_file (char *filename) {
  FILE *f = fopen (filename, "rt");
  if (!f) {
    fprintf (stderr, "can not open network file (error %m)\n");
    return 0;
  }
  char buf[256];
  while (!feof (f)) {
    if (rules_num >= MAX_RULES) {
      fclose (f);
      return rules_num;
    }
    fgets (buf, 255, f);
    rules_num += read_rule(buf, &network[rules_num]);
  }
  if (verbosity) {
    fprintf (stderr, "Read %d rules from network description file\n", rules_num);
  }
  fclose (f);
  return rules_num;
}

int check_rule (struct netrule *A, unsigned ip) {
  assert (A->type);
  return (ip & ~(A->mask1)) == A->ip;
}

int check_common_rule (struct netrule *A, unsigned ip1, unsigned ip2) {
  assert (A->type);
  if (A->type == 1) {
    return check_rule (A, ip1) && check_rule (A, ip2);
  } else {
    return 2 * (check_rule (A, ip1) && check_rule (A, ip2) && ((ip1 & ~(A->mask2)) == (ip2 & ~(A->mask2))));
  }
}

int link_color (unsigned ip1, unsigned ip2) {
  int i;
  int best = 0;
  for (i = 0; i < rules_num; i++) {
    int r = check_common_rule (&network[i], ip1, ip2);
    if (r == 2) {
      return 2;
    }
    if (r == 1) {
      best = 1;
    }
  }
  return best;
}

int link_level (unsigned ip, int color) {
  if (color == 0) {
    return 32;
  }
  if (color == 1) {
    int i;
    int l = 0;
    for (i = 0; i < rules_num; i++) if (network[i].type == 1) {
      struct netrule *A = &network[i];
      if (check_rule (A, ip) && A->level1 > l) {
        l = A->level1;
      }
    }
    return l;
  }
  if (color == 2) {
    int i;
    int l = 0;
    for (i = 0; i < rules_num; i++) if (network[i].type == 2) {
      struct netrule *A = &network[i];
      if (check_rule (A, ip) && A->level2 > l) {
        l = A->level2;
      }
    }
    return l;
  }
  return 0;
}

int rpc_create_query (void *_R, int len, struct connection *c, int op) {
  if (verbosity >= 4) {
    fprintf (stderr, "creating query... len = %d, op = %x\n", len, op);
  }
  assert (len <= MAX_PACKET_LEN && len >= 16);
  if (!c || server_check_ready (c) != cr_ok) {
    if (verbosity >= 4) {
      fprintf (stderr, "not_created: connection_failedn\n");
    }
    return -1;
  }
  int *R = _R;
  R[0] = len;
  R[1] = RPCS_DATA(c)->out_packet_num ++;
  R[2] = op;
  return 0;
}

int rpc_send_query (void *_R, struct connection *c) {
  int *R = _R;
  if (verbosity >= 4) {
    fprintf (stderr, "sending query... len = %d, op = %x\n", R[0], R[2]);
  }
  if (verbosity >= 6) {
    fprintf (stderr, "c = %p, server_check_ready = %d (cr_ok = %d)\n", c, server_check_ready (c), cr_ok);
  }
  assert (c && server_check_ready(c) == cr_ok);
  assert (R[0] <= MAX_PACKET_LEN && R[0] >= 16 && R[0] % 4 == 0);
  if (verbosity >= 10) {
    fprintf (stderr, "LINE %d:", __LINE__);
  }
  rpc_set_crc32 (R);
  if (verbosity >= 10) {
    fprintf (stderr, "LINE %d:", __LINE__);
  }
  write_out (&c->Out, R, R[0]);
  if (verbosity >= 10) {
    fprintf (stderr, "LINE %d:", __LINE__);
    fprintf (stderr, "%p %p %p\n", c->extra, RPCS_FUNC(c)->flush_packet, rpcc_flush_packet);
  }
  RPCS_FUNC(c)->flush_packet(c);
  if (verbosity >= 4) {
    fprintf (stderr, "message_sent\n");
  }
  return 0;
}

