#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_63__   TYPE_9__ ;
typedef  struct TYPE_62__   TYPE_8__ ;
typedef  struct TYPE_61__   TYPE_7__ ;
typedef  struct TYPE_60__   TYPE_6__ ;
typedef  struct TYPE_59__   TYPE_5__ ;
typedef  struct TYPE_58__   TYPE_4__ ;
typedef  struct TYPE_57__   TYPE_3__ ;
typedef  struct TYPE_56__   TYPE_2__ ;
typedef  struct TYPE_55__   TYPE_21__ ;
typedef  struct TYPE_54__   TYPE_20__ ;
typedef  struct TYPE_53__   TYPE_1__ ;
typedef  struct TYPE_52__   TYPE_19__ ;
typedef  struct TYPE_51__   TYPE_16__ ;
typedef  struct TYPE_50__   TYPE_14__ ;
typedef  struct TYPE_49__   TYPE_13__ ;
typedef  struct TYPE_48__   TYPE_12__ ;
typedef  struct TYPE_47__   TYPE_11__ ;
typedef  struct TYPE_46__   TYPE_10__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  char u_char ;
typedef  scalar_t__ time_t ;
typedef  int ngx_uint_t ;
struct TYPE_59__ {int len; char* data; } ;
typedef  TYPE_5__ ngx_str_t ;
struct TYPE_60__ {int /*<<< orphan*/ * name; int /*<<< orphan*/  socklen; int /*<<< orphan*/  sockaddr; int /*<<< orphan*/  log; int /*<<< orphan*/ * connection; scalar_t__ cached; TYPE_20__* tries; } ;
typedef  TYPE_6__ ngx_peer_connection_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_58__ {scalar_t__ (* init ) (TYPE_13__*,TYPE_7__*) ;TYPE_8__* data; } ;
struct TYPE_61__ {TYPE_4__ peer; } ;
typedef  TYPE_7__ ngx_http_upstream_srv_conf_t ;
struct TYPE_62__ {int total_weight; TYPE_9__* peer; } ;
typedef  TYPE_8__ ngx_http_upstream_rr_peers_t ;
struct TYPE_63__ {scalar_t__ weight; scalar_t__ max_fails; scalar_t__ fails; scalar_t__ checked; scalar_t__ fail_timeout; scalar_t__ max_conns; scalar_t__ conns; TYPE_5__ server; struct TYPE_63__* next; int /*<<< orphan*/  name; int /*<<< orphan*/  socklen; int /*<<< orphan*/  sockaddr; scalar_t__ down; } ;
typedef  TYPE_9__ ngx_http_upstream_rr_peer_t ;
struct TYPE_46__ {TYPE_12__* points; int /*<<< orphan*/  key; } ;
typedef  TYPE_10__ ngx_http_upstream_hash_srv_conf_t ;
struct TYPE_51__ {uintptr_t* tried; TYPE_21__* peers; TYPE_9__* current; } ;
struct TYPE_54__ {char* data; int len; } ;
struct TYPE_47__ {int tries; scalar_t__ rehash; int hash; scalar_t__ (* get_rr_peer ) (TYPE_6__*,TYPE_16__*) ;TYPE_16__ rrp; TYPE_20__ key; TYPE_10__* conf; } ;
typedef  TYPE_11__ ngx_http_upstream_hash_peer_data_t ;
struct TYPE_48__ {size_t number; TYPE_19__* point; } ;
typedef  TYPE_12__ ngx_http_upstream_chash_points_t ;
typedef  int /*<<< orphan*/  ngx_http_upstream_chash_point_t ;
struct TYPE_49__ {TYPE_3__* connection; TYPE_2__* upstream; int /*<<< orphan*/  pool; } ;
typedef  TYPE_13__ ngx_http_request_t ;
struct TYPE_50__ {int /*<<< orphan*/  pool; } ;
typedef  TYPE_14__ ngx_conf_t ;
struct TYPE_57__ {int /*<<< orphan*/  log; } ;
struct TYPE_53__ {scalar_t__ (* get ) (TYPE_6__*,void*) ;TYPE_16__* data; } ;
struct TYPE_56__ {TYPE_1__ peer; } ;
struct TYPE_55__ {scalar_t__ total_weight; TYPE_9__* peer; scalar_t__ single; } ;
struct TYPE_52__ {int hash; TYPE_5__* server; } ;

/* Variables and functions */
 scalar_t__ NGX_ERROR ; 
 int NGX_INT_T_LEN ; 
 int /*<<< orphan*/  NGX_LOG_DEBUG_HTTP ; 
 scalar_t__ NGX_OK ; 
 int /*<<< orphan*/  ngx_crc32_final (int) ; 
 int /*<<< orphan*/  ngx_crc32_init (int) ; 
 int /*<<< orphan*/  ngx_crc32_update (int*,char*,int) ; 
 scalar_t__ ngx_http_complex_value (TYPE_13__*,int /*<<< orphan*/ *,TYPE_20__*) ; 
 TYPE_10__* ngx_http_conf_upstream_srv_conf (TYPE_7__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_http_upstream_chash_cmp_points ; 
static  scalar_t__ ngx_http_upstream_get_hash_peer (TYPE_6__*,void*) ; 
 scalar_t__ ngx_http_upstream_get_round_robin_peer (TYPE_6__*,TYPE_16__*) ; 
 int /*<<< orphan*/  ngx_http_upstream_hash_module ; 
 scalar_t__ ngx_http_upstream_init_chash_peer (TYPE_13__*,TYPE_7__*) ; 
static  scalar_t__ ngx_http_upstream_init_hash_peer (TYPE_13__*,TYPE_7__*) ; 
 scalar_t__ ngx_http_upstream_init_round_robin (TYPE_14__*,TYPE_7__*) ; 
 scalar_t__ ngx_http_upstream_init_round_robin_peer (TYPE_13__*,TYPE_7__*) ; 
 int /*<<< orphan*/  ngx_http_upstream_rr_peer_lock (TYPE_21__*,TYPE_9__*) ; 
 int /*<<< orphan*/  ngx_http_upstream_rr_peer_unlock (TYPE_21__*,TYPE_9__*) ; 
 int /*<<< orphan*/  ngx_http_upstream_rr_peers_rlock (TYPE_21__*) ; 
 int /*<<< orphan*/  ngx_http_upstream_rr_peers_unlock (TYPE_21__*) ; 
 int /*<<< orphan*/  ngx_log_debug1 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,TYPE_20__*) ; 
 int /*<<< orphan*/  ngx_log_debug2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,scalar_t__,int) ; 
 void* ngx_palloc (int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  ngx_qsort (TYPE_19__*,size_t,int,int /*<<< orphan*/ ) ; 
 char* ngx_sprintf (char*,char*,scalar_t__) ; 
 scalar_t__ ngx_strncasecmp (char*,char*,int) ; 
 scalar_t__ ngx_time () ; 
 scalar_t__ stub1 (TYPE_6__*,TYPE_16__*) ; 
 scalar_t__ stub2 (TYPE_6__*,TYPE_16__*) ; 

__attribute__((used)) static ngx_int_t
ngx_http_upstream_init_hash(ngx_conf_t *cf, ngx_http_upstream_srv_conf_t *us)
{
    if (ngx_http_upstream_init_round_robin(cf, us) != NGX_OK) {
        return NGX_ERROR;
    }

    us->peer.init = ngx_http_upstream_init_hash_peer;

    return NGX_OK;
}

__attribute__((used)) static ngx_int_t
ngx_http_upstream_init_hash_peer(ngx_http_request_t *r,
    ngx_http_upstream_srv_conf_t *us)
{
    ngx_http_upstream_hash_srv_conf_t   *hcf;
    ngx_http_upstream_hash_peer_data_t  *hp;

    hp = ngx_palloc(r->pool, sizeof(ngx_http_upstream_hash_peer_data_t));
    if (hp == NULL) {
        return NGX_ERROR;
    }

    r->upstream->peer.data = &hp->rrp;

    if (ngx_http_upstream_init_round_robin_peer(r, us) != NGX_OK) {
        return NGX_ERROR;
    }

    r->upstream->peer.get = ngx_http_upstream_get_hash_peer;

    hcf = ngx_http_conf_upstream_srv_conf(us, ngx_http_upstream_hash_module);

    if (ngx_http_complex_value(r, &hcf->key, &hp->key) != NGX_OK) {
        return NGX_ERROR;
    }

    ngx_log_debug1(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
                   "upstream hash key:\"%V\"", &hp->key);

    hp->conf = hcf;
    hp->tries = 0;
    hp->rehash = 0;
    hp->hash = 0;
    hp->get_rr_peer = ngx_http_upstream_get_round_robin_peer;

    return NGX_OK;
}

__attribute__((used)) static ngx_int_t
ngx_http_upstream_get_hash_peer(ngx_peer_connection_t *pc, void *data)
{
    ngx_http_upstream_hash_peer_data_t  *hp = data;

    time_t                        now;
    u_char                        buf[NGX_INT_T_LEN];
    size_t                        size;
    uint32_t                      hash;
    ngx_int_t                     w;
    uintptr_t                     m;
    ngx_uint_t                    n, p;
    ngx_http_upstream_rr_peer_t  *peer;

    ngx_log_debug1(NGX_LOG_DEBUG_HTTP, pc->log, 0,
                   "get hash peer, try: %ui", pc->tries);

    ngx_http_upstream_rr_peers_rlock(hp->rrp.peers);

    if (hp->tries > 20 || hp->rrp.peers->single) {
        ngx_http_upstream_rr_peers_unlock(hp->rrp.peers);
        return hp->get_rr_peer(pc, &hp->rrp);
    }

    now = ngx_time();

    pc->cached = 0;
    pc->connection = NULL;

    for ( ;; ) {

        /*
         * Hash expression is compatible with Cache::Memcached:
         * ((crc32([REHASH] KEY) >> 16) & 0x7fff) + PREV_HASH
         * with REHASH omitted at the first iteration.
         */

        ngx_crc32_init(hash);

        if (hp->rehash > 0) {
            size = ngx_sprintf(buf, "%ui", hp->rehash) - buf;
            ngx_crc32_update(&hash, buf, size);
        }

        ngx_crc32_update(&hash, hp->key.data, hp->key.len);
        ngx_crc32_final(hash);

        hash = (hash >> 16) & 0x7fff;

        hp->hash += hash;
        hp->rehash++;

        w = hp->hash % hp->rrp.peers->total_weight;
        peer = hp->rrp.peers->peer;
        p = 0;

        while (w >= peer->weight) {
            w -= peer->weight;
            peer = peer->next;
            p++;
        }

        n = p / (8 * sizeof(uintptr_t));
        m = (uintptr_t) 1 << p % (8 * sizeof(uintptr_t));

        if (hp->rrp.tried[n] & m) {
            goto next;
        }

        ngx_http_upstream_rr_peer_lock(hp->rrp.peers, peer);

        ngx_log_debug2(NGX_LOG_DEBUG_HTTP, pc->log, 0,
                       "get hash peer, value:%uD, peer:%ui", hp->hash, p);

        if (peer->down) {
            ngx_http_upstream_rr_peer_unlock(hp->rrp.peers, peer);
            goto next;
        }

#if (NGX_HTTP_UPSTREAM_CHECK)
        ngx_log_debug1(NGX_LOG_DEBUG_HTTP, pc->log, 0,
            "get hash peer, check_index: %ui",
             peer->check_index);
        if (ngx_http_upstream_check_peer_down(peer->check_index)) {
            goto next;
        }
#endif

        if (peer->max_fails
            && peer->fails >= peer->max_fails
            && now - peer->checked <= peer->fail_timeout)
        {
            ngx_http_upstream_rr_peer_unlock(hp->rrp.peers, peer);
            goto next;
        }

        if (peer->max_conns && peer->conns >= peer->max_conns) {
            ngx_http_upstream_rr_peer_unlock(hp->rrp.peers, peer);
            goto next;
        }

        break;

    next:

        if (++hp->tries > 20) {
            ngx_http_upstream_rr_peers_unlock(hp->rrp.peers);
            return hp->get_rr_peer(pc, &hp->rrp);
        }
    }

    hp->rrp.current = peer;

    pc->sockaddr = peer->sockaddr;
    pc->socklen = peer->socklen;
    pc->name = &peer->name;

    peer->conns++;

    if (now - peer->checked > peer->fail_timeout) {
        peer->checked = now;
    }

    ngx_http_upstream_rr_peer_unlock(hp->rrp.peers, peer);
    ngx_http_upstream_rr_peers_unlock(hp->rrp.peers);

    hp->rrp.tried[n] |= m;

    return NGX_OK;
}

__attribute__((used)) static ngx_int_t
ngx_http_upstream_init_chash(ngx_conf_t *cf, ngx_http_upstream_srv_conf_t *us)
{
    u_char                             *host, *port, c;
    size_t                              host_len, port_len, size;
    uint32_t                            hash, base_hash;
    ngx_str_t                          *server;
    ngx_uint_t                          npoints, i, j;
    ngx_http_upstream_rr_peer_t        *peer;
    ngx_http_upstream_rr_peers_t       *peers;
    ngx_http_upstream_chash_points_t   *points;
    ngx_http_upstream_hash_srv_conf_t  *hcf;
    union {
        uint32_t                        value;
        u_char                          byte[4];
    } prev_hash;

    if (ngx_http_upstream_init_round_robin(cf, us) != NGX_OK) {
        return NGX_ERROR;
    }

    us->peer.init = ngx_http_upstream_init_chash_peer;

    peers = us->peer.data;
    npoints = peers->total_weight * 160;

    size = sizeof(ngx_http_upstream_chash_points_t)
           + sizeof(ngx_http_upstream_chash_point_t) * (npoints - 1);

    points = ngx_palloc(cf->pool, size);
    if (points == NULL) {
        return NGX_ERROR;
    }

    points->number = 0;

    for (peer = peers->peer; peer; peer = peer->next) {
        server = &peer->server;

        /*
         * Hash expression is compatible with Cache::Memcached::Fast:
         * crc32(HOST \0 PORT PREV_HASH).
         */

        if (server->len >= 5
            && ngx_strncasecmp(server->data, (u_char *) "unix:", 5) == 0)
        {
            host = server->data + 5;
            host_len = server->len - 5;
            port = NULL;
            port_len = 0;
            goto done;
        }

        for (j = 0; j < server->len; j++) {
            c = server->data[server->len - j - 1];

            if (c == ':') {
                host = server->data;
                host_len = server->len - j - 1;
                port = server->data + server->len - j;
                port_len = j;
                goto done;
            }

            if (c < '0' || c > '9') {
                break;
            }
        }

        host = server->data;
        host_len = server->len;
        port = NULL;
        port_len = 0;

    done:

        ngx_crc32_init(base_hash);
        ngx_crc32_update(&base_hash, host, host_len);
        ngx_crc32_update(&base_hash, (u_char *) "", 1);
        ngx_crc32_update(&base_hash, port, port_len);

        prev_hash.value = 0;
        npoints = peer->weight * 160;

        for (j = 0; j < npoints; j++) {
            hash = base_hash;

            ngx_crc32_update(&hash, prev_hash.byte, 4);
            ngx_crc32_final(hash);

            points->point[points->number].hash = hash;
            points->point[points->number].server = server;
            points->number++;

#if (NGX_HAVE_LITTLE_ENDIAN)
            prev_hash.value = hash;
#else
            prev_hash.byte[0] = (u_char) (hash & 0xff);
            prev_hash.byte[1] = (u_char) ((hash >> 8) & 0xff);
            prev_hash.byte[2] = (u_char) ((hash >> 16) & 0xff);
            prev_hash.byte[3] = (u_char) ((hash >> 24) & 0xff);
#endif
        }
    }

    ngx_qsort(points->point,
              points->number,
              sizeof(ngx_http_upstream_chash_point_t),
              ngx_http_upstream_chash_cmp_points);

    for (i = 0, j = 1; j < points->number; j++) {
        if (points->point[i].hash != points->point[j].hash) {
            points->point[++i] = points->point[j];
        }
    }

    points->number = i + 1;

    hcf = ngx_http_conf_upstream_srv_conf(us, ngx_http_upstream_hash_module);
    hcf->points = points;

    return NGX_OK;
}

