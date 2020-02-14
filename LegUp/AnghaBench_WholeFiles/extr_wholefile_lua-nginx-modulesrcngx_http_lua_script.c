#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_45__   TYPE_8__ ;
typedef  struct TYPE_44__   TYPE_6__ ;
typedef  struct TYPE_43__   TYPE_5__ ;
typedef  struct TYPE_42__   TYPE_4__ ;
typedef  struct TYPE_41__   TYPE_3__ ;
typedef  struct TYPE_40__   TYPE_2__ ;
typedef  struct TYPE_39__   TYPE_1__ ;
typedef  struct TYPE_38__   TYPE_14__ ;
typedef  struct TYPE_37__   TYPE_13__ ;
typedef  struct TYPE_36__   TYPE_12__ ;
typedef  struct TYPE_35__   TYPE_11__ ;

/* Type definitions */
typedef  char u_char ;
typedef  size_t ngx_uint_t ;
struct TYPE_42__ {size_t len; char* data; } ;
typedef  TYPE_4__ ngx_str_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_43__ {int /*<<< orphan*/  pool; TYPE_3__* connection; } ;
typedef  TYPE_5__ ngx_http_request_t ;
typedef  scalar_t__ (* ngx_http_lua_script_len_code_pt ) (TYPE_6__*) ;
struct TYPE_44__ {int complete_lengths; int complete_values; size_t ncaptures; int* captures; char* captures_data; char* ip; char* pos; int variables; TYPE_14__** values; TYPE_14__** lengths; int /*<<< orphan*/  pool; int /*<<< orphan*/  log; int /*<<< orphan*/  skip; TYPE_4__* source; } ;
typedef  TYPE_6__ ngx_http_lua_script_engine_t ;
struct TYPE_45__ {void (* code ) (TYPE_6__*) ;size_t len; } ;
typedef  TYPE_8__ ngx_http_lua_script_copy_code_t ;
typedef  TYPE_6__ ngx_http_lua_script_compile_t ;
typedef  void (* ngx_http_lua_script_code_pt ) (TYPE_6__*) ;
struct TYPE_35__ {void (* code ) (TYPE_6__*) ;int n; } ;
typedef  TYPE_11__ ngx_http_lua_script_capture_code_t ;
struct TYPE_40__ {size_t len; scalar_t__ data; } ;
struct TYPE_36__ {char* lengths; char* values; TYPE_2__ value; } ;
typedef  TYPE_12__ ngx_http_lua_complex_value_t ;
struct TYPE_37__ {TYPE_1__* complex_value; int /*<<< orphan*/  log; int /*<<< orphan*/  pool; TYPE_4__* value; } ;
typedef  TYPE_13__ ngx_http_lua_compile_complex_value_t ;
struct TYPE_38__ {int /*<<< orphan*/ * elts; } ;
typedef  TYPE_14__ ngx_array_t ;
typedef  int /*<<< orphan*/  luaL_Buffer ;
struct TYPE_41__ {int /*<<< orphan*/  log; } ;
struct TYPE_39__ {int /*<<< orphan*/ * values; int /*<<< orphan*/ * lengths; TYPE_4__ value; } ;

/* Variables and functions */
 scalar_t__ NGX_ERROR ; 
 int /*<<< orphan*/  NGX_LOG_DEBUG_HTTP ; 
 int /*<<< orphan*/  NGX_LOG_ERR ; 
 scalar_t__ NGX_OK ; 
 int /*<<< orphan*/  luaL_addlstring (int /*<<< orphan*/ *,char*,size_t) ; 
 void* ngx_array_create (int /*<<< orphan*/ ,size_t,int) ; 
 int /*<<< orphan*/  ngx_array_destroy (TYPE_14__*) ; 
 scalar_t__ ngx_array_init (TYPE_14__*,int /*<<< orphan*/ ,size_t,int) ; 
 void* ngx_array_push_n (TYPE_14__*,size_t) ; 
 void* ngx_copy (char*,char*,int) ; 
static  scalar_t__ ngx_http_lua_script_add_capture_code (TYPE_6__*,size_t) ; 
static  void* ngx_http_lua_script_add_code (TYPE_14__*,size_t) ; 
static  scalar_t__ ngx_http_lua_script_add_copy_code (TYPE_6__*,TYPE_4__*,size_t) ; 
static  scalar_t__ ngx_http_lua_script_compile (TYPE_6__*) ; 
static  void ngx_http_lua_script_copy_capture_code (TYPE_6__*) ; 
static  size_t ngx_http_lua_script_copy_capture_len_code (TYPE_6__*) ; 
static  void ngx_http_lua_script_copy_code (TYPE_6__*) ; 
static  size_t ngx_http_lua_script_copy_len_code (TYPE_6__*) ; 
static  scalar_t__ ngx_http_lua_script_done (TYPE_6__*) ; 
static  scalar_t__ ngx_http_lua_script_init_arrays (TYPE_6__*) ; 
 int /*<<< orphan*/  ngx_log_debug2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int,char*) ; 
 int /*<<< orphan*/  ngx_log_error (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,TYPE_4__*) ; 
 int /*<<< orphan*/  ngx_memcpy (char*,char*,size_t) ; 
 int /*<<< orphan*/  ngx_memzero (TYPE_6__*,int) ; 
 int /*<<< orphan*/  ngx_pfree (int /*<<< orphan*/ ,char*) ; 
 char* ngx_pnalloc (int /*<<< orphan*/ ,size_t) ; 

ngx_int_t
ngx_http_lua_compile_complex_value(ngx_http_lua_compile_complex_value_t *ccv)
{
    ngx_str_t                  *v;
    ngx_uint_t                  i, n, nv;
    ngx_array_t                 lengths, values, *pl, *pv;

    ngx_http_lua_script_compile_t   sc;

    v = ccv->value;

    nv = 0;

    for (i = 0; i < v->len; i++) {
        if (v->data[i] == '$') {
            nv++;
        }
    }

    ccv->complex_value->value = *v;
    ccv->complex_value->lengths = NULL;
    ccv->complex_value->values = NULL;

    if (nv == 0) {
        return NGX_OK;
    }

    n = nv * (2 * sizeof(ngx_http_lua_script_copy_code_t)
              + sizeof(ngx_http_lua_script_capture_code_t))
        + sizeof(uintptr_t);

    if (ngx_array_init(&lengths, ccv->pool, n, 1) != NGX_OK) {
        return NGX_ERROR;
    }

    n = (nv * (2 * sizeof(ngx_http_lua_script_copy_code_t)
                   + sizeof(ngx_http_lua_script_capture_code_t))
                + sizeof(uintptr_t)
                + sizeof(uintptr_t) - 1)
            & ~(sizeof(uintptr_t) - 1);

    if (ngx_array_init(&values, ccv->pool, n, 1) != NGX_OK) {
        return NGX_ERROR;
    }

    pl = &lengths;
    pv = &values;

    ngx_memzero(&sc, sizeof(ngx_http_lua_script_compile_t));

    sc.pool = ccv->pool;
    sc.log = ccv->log;
    sc.source = v;
    sc.lengths = &pl;
    sc.values = &pv;
    sc.complete_lengths = 1;
    sc.complete_values = 1;

    if (ngx_http_lua_script_compile(&sc) != NGX_OK) {
        ngx_array_destroy(&lengths);
        ngx_array_destroy(&values);
        return NGX_ERROR;
    }

    ccv->complex_value->lengths = lengths.elts;
    ccv->complex_value->values = values.elts;

    return NGX_OK;
}

ngx_int_t
ngx_http_lua_complex_value(ngx_http_request_t *r, ngx_str_t *subj,
    size_t offset, ngx_int_t count, int *cap,
    ngx_http_lua_complex_value_t *val, luaL_Buffer *luabuf)
{
    size_t                            len;
    u_char                           *p;
    ngx_http_lua_script_code_pt       code;
    ngx_http_lua_script_len_code_pt   lcode;
    ngx_http_lua_script_engine_t      e;

    if (val->lengths == NULL) {
        luaL_addlstring(luabuf, (char *) &subj->data[offset], cap[0] - offset);
        luaL_addlstring(luabuf, (char *) val->value.data, val->value.len);

        return NGX_OK;
    }

    ngx_memzero(&e, sizeof(ngx_http_lua_script_engine_t));

    e.log = r->connection->log;
    e.ncaptures = count * 2;
    e.captures = cap;
    e.captures_data = subj->data;

    e.ip = val->lengths;

    len = 0;

    while (*(uintptr_t *) e.ip) {
        lcode = *(ngx_http_lua_script_len_code_pt *) e.ip;
        len += lcode(&e);
    }

    p = ngx_pnalloc(r->pool, len);
    if (p == NULL) {
        return NGX_ERROR;
    }

    e.ip = val->values;
    e.pos = p;

    while (*(uintptr_t *) e.ip) {
        code = *(ngx_http_lua_script_code_pt *) e.ip;
        code((ngx_http_lua_script_engine_t *) &e);
    }

    luaL_addlstring(luabuf, (char *) &subj->data[offset], cap[0] - offset);
    luaL_addlstring(luabuf, (char *) p, len);

    ngx_pfree(r->pool, p);

    return NGX_OK;
}

__attribute__((used)) static ngx_int_t
ngx_http_lua_script_compile(ngx_http_lua_script_compile_t *sc)
{
    u_char       ch;
    ngx_str_t    name;
    ngx_uint_t   i, bracket;
    unsigned     num_var;
    ngx_uint_t   n = 0;

    if (ngx_http_lua_script_init_arrays(sc) != NGX_OK) {
        return NGX_ERROR;
    }

    for (i = 0; i < sc->source->len; /* void */ ) {

        name.len = 0;

        if (sc->source->data[i] == '$') {

            if (++i == sc->source->len) {
                goto invalid_variable;
            }

            if (sc->source->data[i] == '$') {
                name.data = &sc->source->data[i];
                i++;
                name.len++;

                if (ngx_http_lua_script_add_copy_code(sc, &name,
                                                      (i == sc->source->len))
                    != NGX_OK)
                {
                    return NGX_ERROR;
                }

                continue;
            }

            if (sc->source->data[i] >= '0' && sc->source->data[i] <= '9') {
                num_var = 1;
                n = 0;

            } else {
                num_var = 0;
            }

            if (sc->source->data[i] == '{') {
                bracket = 1;

                if (++i == sc->source->len) {
                    goto invalid_variable;
                }

                if (sc->source->data[i] >= '0' && sc->source->data[i] <= '9') {
                    num_var = 1;
                    n = 0;
                }

                name.data = &sc->source->data[i];

            } else {
                bracket = 0;
                name.data = &sc->source->data[i];
            }

            for ( /* void */ ; i < sc->source->len; i++, name.len++) {
                ch = sc->source->data[i];

                if (ch == '}' && bracket) {
                    i++;
                    bracket = 0;
                    break;
                }

                if (num_var) {
                    if (ch >= '0' && ch <= '9') {
                        n = n * 10 + (ch - '0');
                        continue;
                    }

                    break;
                }

                /* not a number variable like $1, $2, etc */

                if ((ch >= 'A' && ch <= 'Z')
                    || (ch >= 'a' && ch <= 'z')
                    || (ch >= '0' && ch <= '9')
                    || ch == '_')
                {
                    continue;
                }

                break;
            }

            if (bracket) {
                ngx_log_error(NGX_LOG_ERR, sc->log, 0,
                              "the closing bracket in \"%V\" "
                              "variable is missing", &name);
                return NGX_ERROR;
            }

            if (name.len == 0) {
                goto invalid_variable;
            }

            if (!num_var) {
                ngx_log_error(NGX_LOG_ERR, sc->log, 0,
                              "attempt to use named capturing variable "
                              "\"%V\" (named captures not supported yet)",
                              &name);

                return NGX_ERROR;
            }

            sc->variables++;

            if (ngx_http_lua_script_add_capture_code(sc, n) != NGX_OK) {
                return NGX_ERROR;
            }

            continue;
        }

        name.data = &sc->source->data[i];

        while (i < sc->source->len) {

            if (sc->source->data[i] == '$') {
                break;
            }

            i++;
            name.len++;
        }

        if (ngx_http_lua_script_add_copy_code(sc, &name, (i == sc->source->len))
            != NGX_OK)
        {
            return NGX_ERROR;
        }
    }

    return ngx_http_lua_script_done(sc);

invalid_variable:

    ngx_log_error(NGX_LOG_ERR, sc->log, 0,
                  "lua script: invalid capturing variable name found in \"%V\"",
                  sc->source);

    return NGX_ERROR;
}

__attribute__((used)) static ngx_int_t
ngx_http_lua_script_add_copy_code(ngx_http_lua_script_compile_t *sc,
    ngx_str_t *value, ngx_uint_t last)
{
    size_t                            size, len;
    ngx_http_lua_script_copy_code_t  *code;

    len = value->len;

    code = ngx_http_lua_script_add_code(*sc->lengths,
                                    sizeof(ngx_http_lua_script_copy_code_t));
    if (code == NULL) {
        return NGX_ERROR;
    }

    code->code = (ngx_http_lua_script_code_pt) (void *)
                 ngx_http_lua_script_copy_len_code;
    code->len = len;

    size = (sizeof(ngx_http_lua_script_copy_code_t) + len +
            sizeof(uintptr_t) - 1) & ~(sizeof(uintptr_t) - 1);

    code = ngx_http_lua_script_add_code(*sc->values, size);
    if (code == NULL) {
        return NGX_ERROR;
    }

    code->code = ngx_http_lua_script_copy_code;
    code->len = len;

    ngx_memcpy((u_char *) code + sizeof(ngx_http_lua_script_copy_code_t),
               value->data, value->len);

    return NGX_OK;
}

__attribute__((used)) static size_t
ngx_http_lua_script_copy_len_code(ngx_http_lua_script_engine_t *e)
{
    ngx_http_lua_script_copy_code_t  *code;

    code = (ngx_http_lua_script_copy_code_t *) e->ip;

    e->ip += sizeof(ngx_http_lua_script_copy_code_t);

    return code->len;
}

__attribute__((used)) static void
ngx_http_lua_script_copy_code(ngx_http_lua_script_engine_t *e)
{
    u_char                           *p;
    ngx_http_lua_script_copy_code_t  *code;

    code = (ngx_http_lua_script_copy_code_t *) e->ip;

    p = e->pos;

    if (!e->skip) {
        e->pos = ngx_copy(p, e->ip + sizeof(ngx_http_lua_script_copy_code_t),
                          code->len);
    }

    e->ip += sizeof(ngx_http_lua_script_copy_code_t)
          + ((code->len + sizeof(uintptr_t) - 1) & ~(sizeof(uintptr_t) - 1));

    ngx_log_debug2(NGX_LOG_DEBUG_HTTP, e->log, 0,
                   "lua script copy: \"%*s\"", e->pos - p, p);
}

__attribute__((used)) static ngx_int_t
ngx_http_lua_script_add_capture_code(ngx_http_lua_script_compile_t *sc,
    ngx_uint_t n)
{
    ngx_http_lua_script_capture_code_t  *code;

    code = ngx_http_lua_script_add_code(*sc->lengths,
                                  sizeof(ngx_http_lua_script_capture_code_t));
    if (code == NULL) {
        return NGX_ERROR;
    }

    code->code = (ngx_http_lua_script_code_pt) (void *)
                 ngx_http_lua_script_copy_capture_len_code;
    code->n = 2 * n;

    code = ngx_http_lua_script_add_code(*sc->values,
                                  sizeof(ngx_http_lua_script_capture_code_t));
    if (code == NULL) {
        return NGX_ERROR;
    }

    code->code = ngx_http_lua_script_copy_capture_code;
    code->n = 2 * n;

    return NGX_OK;
}

__attribute__((used)) static size_t
ngx_http_lua_script_copy_capture_len_code(ngx_http_lua_script_engine_t *e)
{
    int                                  *cap;
    ngx_uint_t                            n;
    ngx_http_lua_script_capture_code_t   *code;

    code = (ngx_http_lua_script_capture_code_t *) e->ip;

    e->ip += sizeof(ngx_http_lua_script_capture_code_t);

    n = code->n;

    if (n < e->ncaptures) {
        cap = e->captures;
        return cap[n + 1] - cap[n];
    }

    return 0;
}

__attribute__((used)) static void
ngx_http_lua_script_copy_capture_code(ngx_http_lua_script_engine_t *e)
{
    int                                  *cap;
    u_char                               *p, *pos;
    ngx_uint_t                            n;
    ngx_http_lua_script_capture_code_t   *code;

    code = (ngx_http_lua_script_capture_code_t *) e->ip;

    e->ip += sizeof(ngx_http_lua_script_capture_code_t);

    n = code->n;

    pos = e->pos;

    if (n < e->ncaptures) {

        cap = e->captures;
        p = e->captures_data;

        e->pos = ngx_copy(pos, &p[cap[n]], cap[n + 1] - cap[n]);
    }

    ngx_log_debug2(NGX_LOG_DEBUG_HTTP, e->log, 0,
                   "lua script capture: \"%*s\"", e->pos - pos, pos);
}

__attribute__((used)) static ngx_int_t
ngx_http_lua_script_init_arrays(ngx_http_lua_script_compile_t *sc)
{
    ngx_uint_t   n;

    if (*sc->lengths == NULL) {
        n = sc->variables * (2 * sizeof(ngx_http_lua_script_copy_code_t)
                             + sizeof(ngx_http_lua_script_capture_code_t))
            + sizeof(uintptr_t);

        *sc->lengths = ngx_array_create(sc->pool, n, 1);
        if (*sc->lengths == NULL) {
            return NGX_ERROR;
        }
    }

    if (*sc->values == NULL) {
        n = (sc->variables * (2 * sizeof(ngx_http_lua_script_copy_code_t)
                              + sizeof(ngx_http_lua_script_capture_code_t))
                + sizeof(uintptr_t)
                + sizeof(uintptr_t) - 1)
            & ~(sizeof(uintptr_t) - 1);

        *sc->values = ngx_array_create(sc->pool, n, 1);
        if (*sc->values == NULL) {
            return NGX_ERROR;
        }
    }

    sc->variables = 0;

    return NGX_OK;
}

__attribute__((used)) static ngx_int_t
ngx_http_lua_script_done(ngx_http_lua_script_compile_t *sc)
{
    uintptr_t   *code;

    if (sc->complete_lengths) {
        code = ngx_http_lua_script_add_code(*sc->lengths, sizeof(uintptr_t));
        if (code == NULL) {
            return NGX_ERROR;
        }

        *code = (uintptr_t) NULL;
    }

    if (sc->complete_values) {
        code = ngx_http_lua_script_add_code(*sc->values, sizeof(uintptr_t));
        if (code == NULL) {
            return NGX_ERROR;
        }

        *code = (uintptr_t) NULL;
    }

    return NGX_OK;
}

__attribute__((used)) static void *
ngx_http_lua_script_add_code(ngx_array_t *codes, size_t size)
{
    return ngx_array_push_n(codes, size);
}

