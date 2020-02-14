#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_39__   TYPE_9__ ;
typedef  struct TYPE_38__   TYPE_8__ ;
typedef  struct TYPE_37__   TYPE_7__ ;
typedef  struct TYPE_36__   TYPE_6__ ;
typedef  struct TYPE_35__   TYPE_5__ ;
typedef  struct TYPE_34__   TYPE_4__ ;
typedef  struct TYPE_33__   TYPE_3__ ;
typedef  struct TYPE_32__   TYPE_2__ ;
typedef  struct TYPE_31__   TYPE_27__ ;
typedef  struct TYPE_30__   TYPE_1__ ;
typedef  struct TYPE_29__   TYPE_10__ ;

/* Type definitions */
typedef  int uint64_t ;
typedef  scalar_t__ uint32_t ;
typedef  size_t ngx_uint_t ;
struct TYPE_33__ {int len; int valid; char* data; scalar_t__ not_found; scalar_t__ no_cacheable; } ;
typedef  TYPE_3__ ngx_stream_variable_value_t ;
struct TYPE_34__ {scalar_t__ (* get_handler ) (TYPE_7__*,TYPE_3__*,uintptr_t) ;uintptr_t data; } ;
typedef  TYPE_4__ ngx_stream_variable_t ;
struct TYPE_35__ {scalar_t__ percent; TYPE_3__ value; } ;
typedef  TYPE_5__ ngx_stream_split_clients_part_t ;
struct TYPE_31__ {size_t nelts; TYPE_5__* elts; } ;
struct TYPE_36__ {TYPE_27__ parts; int /*<<< orphan*/  value; } ;
typedef  TYPE_6__ ngx_stream_split_clients_ctx_t ;
struct TYPE_37__ {TYPE_1__* connection; } ;
typedef  TYPE_7__ ngx_stream_session_t ;
struct TYPE_38__ {int /*<<< orphan*/ * complex_value; TYPE_9__* value; TYPE_10__* cf; } ;
typedef  TYPE_8__ ngx_stream_compile_complex_value_t ;
struct TYPE_39__ {char* data; int len; } ;
typedef  TYPE_9__ ngx_str_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_29__ {char* (* handler ) (TYPE_10__*,int /*<<< orphan*/ *,void*) ;TYPE_2__* args; TYPE_6__* ctx; void* handler_conf; int /*<<< orphan*/  pool; } ;
typedef  TYPE_10__ ngx_conf_t ;
typedef  int /*<<< orphan*/  ngx_command_t ;
struct TYPE_32__ {TYPE_9__* elts; } ;
struct TYPE_30__ {int /*<<< orphan*/  log; } ;

/* Variables and functions */
 char* NGX_CONF_ERROR ; 
 char* NGX_CONF_OK ; 
 scalar_t__ NGX_ERROR ; 
 int /*<<< orphan*/  NGX_LOG_DEBUG_STREAM ; 
 int /*<<< orphan*/  NGX_LOG_EMERG ; 
 scalar_t__ NGX_OK ; 
 int /*<<< orphan*/  NGX_STREAM_VAR_CHANGEABLE ; 
 scalar_t__ ngx_array_init (TYPE_27__*,int /*<<< orphan*/ ,int,int) ; 
 TYPE_5__* ngx_array_push (TYPE_27__*) ; 
 scalar_t__ ngx_atofp (char*,int,int) ; 
 int /*<<< orphan*/  ngx_conf_log_error (int /*<<< orphan*/ ,TYPE_10__*,int /*<<< orphan*/ ,char*,...) ; 
 char* ngx_conf_parse (TYPE_10__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ngx_log_debug2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  ngx_memzero (TYPE_8__*,int) ; 
 scalar_t__ ngx_murmur_hash2 (char*,int) ; 
 TYPE_6__* ngx_pcalloc (int /*<<< orphan*/ ,int) ; 
 TYPE_4__* ngx_stream_add_variable (TYPE_10__*,TYPE_9__*,int /*<<< orphan*/ ) ; 
 scalar_t__ ngx_stream_compile_complex_value (TYPE_8__*) ; 
 scalar_t__ ngx_stream_complex_value (TYPE_7__*,int /*<<< orphan*/ *,TYPE_9__*) ; 
static  char* ngx_stream_split_clients (TYPE_10__*,int /*<<< orphan*/ *,void*) ; 
 TYPE_3__ ngx_stream_variable_null_value ; 

__attribute__((used)) static ngx_int_t
ngx_stream_split_clients_variable(ngx_stream_session_t *s,
    ngx_stream_variable_value_t *v, uintptr_t data)
{
    ngx_stream_split_clients_ctx_t *ctx =
                                       (ngx_stream_split_clients_ctx_t *) data;

    uint32_t                          hash;
    ngx_str_t                         val;
    ngx_uint_t                        i;
    ngx_stream_split_clients_part_t  *part;

    *v = ngx_stream_variable_null_value;

    if (ngx_stream_complex_value(s, &ctx->value, &val) != NGX_OK) {
        return NGX_OK;
    }

    hash = ngx_murmur_hash2(val.data, val.len);

    part = ctx->parts.elts;

    for (i = 0; i < ctx->parts.nelts; i++) {

        ngx_log_debug2(NGX_LOG_DEBUG_STREAM, s->connection->log, 0,
                       "stream split: %uD %uD", hash, part[i].percent);

        if (hash < part[i].percent || part[i].percent == 0) {
            *v = part[i].value;
            return NGX_OK;
        }
    }

    return NGX_OK;
}

__attribute__((used)) static char *
ngx_conf_split_clients_block(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
    char                                *rv;
    uint32_t                             sum, last;
    ngx_str_t                           *value, name;
    ngx_uint_t                           i;
    ngx_conf_t                           save;
    ngx_stream_variable_t               *var;
    ngx_stream_split_clients_ctx_t      *ctx;
    ngx_stream_split_clients_part_t     *part;
    ngx_stream_compile_complex_value_t   ccv;

    ctx = ngx_pcalloc(cf->pool, sizeof(ngx_stream_split_clients_ctx_t));
    if (ctx == NULL) {
        return NGX_CONF_ERROR;
    }

    value = cf->args->elts;

    ngx_memzero(&ccv, sizeof(ngx_stream_compile_complex_value_t));

    ccv.cf = cf;
    ccv.value = &value[1];
    ccv.complex_value = &ctx->value;

    if (ngx_stream_compile_complex_value(&ccv) != NGX_OK) {
        return NGX_CONF_ERROR;
    }

    name = value[2];

    if (name.data[0] != '$') {
        ngx_conf_log_error(NGX_LOG_EMERG, cf, 0,
                           "invalid variable name \"%V\"", &name);
        return NGX_CONF_ERROR;
    }

    name.len--;
    name.data++;

    var = ngx_stream_add_variable(cf, &name, NGX_STREAM_VAR_CHANGEABLE);
    if (var == NULL) {
        return NGX_CONF_ERROR;
    }

    var->get_handler = ngx_stream_split_clients_variable;
    var->data = (uintptr_t) ctx;

    if (ngx_array_init(&ctx->parts, cf->pool, 2,
                       sizeof(ngx_stream_split_clients_part_t))
        != NGX_OK)
    {
        return NGX_CONF_ERROR;
    }

    save = *cf;
    cf->ctx = ctx;
    cf->handler = ngx_stream_split_clients;
    cf->handler_conf = conf;

    rv = ngx_conf_parse(cf, NULL);

    *cf = save;

    if (rv != NGX_CONF_OK) {
        return rv;
    }

    sum = 0;
    last = 0;
    part = ctx->parts.elts;

    for (i = 0; i < ctx->parts.nelts; i++) {
        sum = part[i].percent ? sum + part[i].percent : 10000;
        if (sum > 10000) {
            ngx_conf_log_error(NGX_LOG_EMERG, cf, 0,
                               "percent total is greater than 100%%");
            return NGX_CONF_ERROR;
        }

        if (part[i].percent) {
            last += part[i].percent * (uint64_t) 0xffffffff / 10000;
            part[i].percent = last;
        }
    }

    return rv;
}

__attribute__((used)) static char *
ngx_stream_split_clients(ngx_conf_t *cf, ngx_command_t *dummy, void *conf)
{
    ngx_int_t                         n;
    ngx_str_t                        *value;
    ngx_stream_split_clients_ctx_t   *ctx;
    ngx_stream_split_clients_part_t  *part;

    ctx = cf->ctx;
    value = cf->args->elts;

    part = ngx_array_push(&ctx->parts);
    if (part == NULL) {
        return NGX_CONF_ERROR;
    }

    if (value[0].len == 1 && value[0].data[0] == '*') {
        part->percent = 0;

    } else {
        if (value[0].len == 0 || value[0].data[value[0].len - 1] != '%') {
            goto invalid;
        }

        n = ngx_atofp(value[0].data, value[0].len - 1, 2);
        if (n == NGX_ERROR || n == 0) {
            goto invalid;
        }

        part->percent = (uint32_t) n;
    }

    part->value.len = value[1].len;
    part->value.valid = 1;
    part->value.no_cacheable = 0;
    part->value.not_found = 0;
    part->value.data = value[1].data;

    return NGX_CONF_OK;

invalid:

    ngx_conf_log_error(NGX_LOG_EMERG, cf, 0,
                       "invalid percent value \"%V\"", &value[0]);
    return NGX_CONF_ERROR;
}

