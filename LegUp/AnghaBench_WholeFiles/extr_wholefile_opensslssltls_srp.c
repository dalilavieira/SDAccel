#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_48__   TYPE_9__ ;
typedef  struct TYPE_47__   TYPE_7__ ;
typedef  struct TYPE_46__   TYPE_4__ ;
typedef  struct TYPE_45__   TYPE_3__ ;
typedef  struct TYPE_44__   TYPE_2__ ;
typedef  struct TYPE_43__   TYPE_20__ ;
typedef  struct TYPE_42__   TYPE_1__ ;
typedef  struct TYPE_41__   TYPE_10__ ;

/* Type definitions */
struct TYPE_43__ {char* login; char* info; void* strength; int /*<<< orphan*/  const* v; int /*<<< orphan*/  const* b; int /*<<< orphan*/  const* a; int /*<<< orphan*/  const* A; int /*<<< orphan*/  const* B; int /*<<< orphan*/  const* s; int /*<<< orphan*/  const* g; int /*<<< orphan*/  const* N; int /*<<< orphan*/  srp_Mask; int /*<<< orphan*/  SRP_give_srp_client_pwd_callback; int /*<<< orphan*/  SRP_verify_param_callback; int /*<<< orphan*/  TLS_ext_srp_username_callback; int /*<<< orphan*/  SRP_cb_arg; } ;
struct ssl_st {TYPE_20__ srp_ctx; TYPE_7__* ctx; } ;
struct ssl_ctx_st {TYPE_20__ srp_ctx; } ;
typedef  int /*<<< orphan*/  rnd ;
typedef  int /*<<< orphan*/  b ;
struct TYPE_48__ {int /*<<< orphan*/  const* g; int /*<<< orphan*/  const* N; } ;
struct TYPE_42__ {char* info; int /*<<< orphan*/  srp_Mask; int /*<<< orphan*/ * login; int /*<<< orphan*/  const* b; int /*<<< orphan*/  const* v; int /*<<< orphan*/  const* a; int /*<<< orphan*/  const* A; int /*<<< orphan*/  const* B; int /*<<< orphan*/  const* s; int /*<<< orphan*/  const* g; int /*<<< orphan*/  const* N; void* strength; int /*<<< orphan*/  SRP_give_srp_client_pwd_callback; int /*<<< orphan*/  SRP_verify_param_callback; int /*<<< orphan*/  TLS_ext_srp_username_callback; int /*<<< orphan*/  SRP_cb_arg; } ;
struct TYPE_47__ {TYPE_1__ srp_ctx; } ;
struct TYPE_41__ {int (* TLS_ext_srp_username_callback ) (TYPE_4__*,int*,int /*<<< orphan*/ ) ;char* info; char* (* SRP_give_srp_client_pwd_callback ) (TYPE_4__*,int /*<<< orphan*/ ) ;char* login; scalar_t__ strength; scalar_t__ (* SRP_verify_param_callback ) (TYPE_4__*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  const* N; int /*<<< orphan*/  const* g; int /*<<< orphan*/ * a; int /*<<< orphan*/  A; int /*<<< orphan*/  SRP_cb_arg; int /*<<< orphan*/  const* B; int /*<<< orphan*/  const* s; void* b; int /*<<< orphan*/  const* v; } ;
struct TYPE_46__ {TYPE_3__* ctx; TYPE_10__ srp_ctx; } ;
struct TYPE_44__ {char* login; char* info; int /*<<< orphan*/  const* N; int /*<<< orphan*/  const* g; } ;
struct TYPE_45__ {TYPE_2__ srp_ctx; } ;
typedef  TYPE_7__ SSL_CTX ;
typedef  TYPE_4__ SSL ;
typedef  TYPE_9__ SRP_gN ;
typedef  TYPE_10__ SRP_CTX ;
typedef  int /*<<< orphan*/  const BIGNUM ;

/* Variables and functions */
 void* BN_bin2bn (unsigned char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  BN_bn2bin (int /*<<< orphan*/  const*,unsigned char*) ; 
 int /*<<< orphan*/  BN_clear_free (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  BN_copy (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 void* BN_dup (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  BN_free (int /*<<< orphan*/  const*) ; 
 scalar_t__ BN_is_zero (int /*<<< orphan*/  const*) ; 
 scalar_t__ BN_num_bits (int /*<<< orphan*/  const*) ; 
 int BN_num_bytes (int /*<<< orphan*/  const*) ; 
 scalar_t__ BN_ucmp (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 void* BUF_strdup (char*) ; 
 int /*<<< orphan*/  ERR_R_BN_LIB ; 
 int /*<<< orphan*/  ERR_R_INTERNAL_ERROR ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  OPENSSL_cleanse (unsigned char*,int) ; 
 int /*<<< orphan*/  OPENSSL_clear_free (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OPENSSL_free (char*) ; 
 unsigned char* OPENSSL_malloc (int) ; 
 char* OPENSSL_strdup (int /*<<< orphan*/ *) ; 
 scalar_t__ RAND_priv_bytes (unsigned char*,int) ; 
 int /*<<< orphan*/  SRP_Calc_A (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  const* SRP_Calc_B (void*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  const* SRP_Calc_client_key (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  const* SRP_Calc_server_key (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,void*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  const* SRP_Calc_u (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  const* SRP_Calc_x (int /*<<< orphan*/  const*,char*,char*) ; 
 void* SRP_MINIMAL_N ; 
 int /*<<< orphan*/  SRP_Verify_A_mod_N (int /*<<< orphan*/ ,int /*<<< orphan*/  const*) ; 
 scalar_t__ SRP_Verify_B_mod_N (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  SRP_check_known_gN_param (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  SRP_create_verifier_BN (char const*,char const*,int /*<<< orphan*/  const**,int /*<<< orphan*/  const**,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 TYPE_9__* SRP_get_default_gN (char const*) ; 
 int SSL3_AL_FATAL ; 
 int SSL_AD_ILLEGAL_PARAMETER ; 
 int SSL_AD_INSUFFICIENT_SECURITY ; 
 int SSL_AD_INTERNAL_ERROR ; 
 int SSL_AD_UNKNOWN_PSK_IDENTITY ; 
 int /*<<< orphan*/  SSL_CTRL_SET_SRP_ARG ; 
 int /*<<< orphan*/  SSL_CTRL_SET_SRP_GIVE_CLIENT_PWD_CB ; 
 int /*<<< orphan*/  SSL_CTRL_SET_SRP_VERIFY_PARAM_CB ; 
 int /*<<< orphan*/  SSL_CTRL_SET_TLS_EXT_SRP_PASSWORD ; 
 int /*<<< orphan*/  SSL_CTRL_SET_TLS_EXT_SRP_STRENGTH ; 
 int /*<<< orphan*/  SSL_CTRL_SET_TLS_EXT_SRP_USERNAME ; 
 int /*<<< orphan*/  SSL_CTRL_SET_TLS_EXT_SRP_USERNAME_CB ; 
 int SSL_ERROR_NONE ; 
 int /*<<< orphan*/  SSL_F_SRP_GENERATE_CLIENT_MASTER_SECRET ; 
 int /*<<< orphan*/  SSL_F_SRP_GENERATE_SERVER_MASTER_SECRET ; 
 int /*<<< orphan*/  SSL_F_SRP_VERIFY_SERVER_PARAM ; 
 int /*<<< orphan*/  SSL_F_SSL_SRP_CTX_INIT ; 
 int SSL_MAX_MASTER_KEY_LENGTH ; 
 int /*<<< orphan*/  SSL_R_BAD_DATA ; 
 int /*<<< orphan*/  SSL_R_CALLBACK_FAILED ; 
 int /*<<< orphan*/  SSL_R_INSUFFICIENT_SECURITY ; 
 int /*<<< orphan*/  SSLerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SSLfatal (TYPE_4__*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (TYPE_20__*,int /*<<< orphan*/ ,int) ; 
 int ssl_generate_master_secret (TYPE_4__*,unsigned char*,int,int) ; 
 int /*<<< orphan*/  strlen (char*) ; 
 int stub1 (TYPE_4__*,int*,int /*<<< orphan*/ ) ; 
 char* stub2 (TYPE_4__*,int /*<<< orphan*/ ) ; 
 scalar_t__ stub3 (TYPE_4__*,int /*<<< orphan*/ ) ; 
 int tls1_ctx_callback_ctrl (TYPE_7__*,int /*<<< orphan*/ ,void (*) ()) ; 
 int tls1_ctx_ctrl (TYPE_7__*,int /*<<< orphan*/ ,int,void*) ; 

int SSL_CTX_SRP_CTX_free(struct ssl_ctx_st *ctx)
{
    if (ctx == NULL)
        return 0;
    OPENSSL_free(ctx->srp_ctx.login);
    OPENSSL_free(ctx->srp_ctx.info);
    BN_free(ctx->srp_ctx.N);
    BN_free(ctx->srp_ctx.g);
    BN_free(ctx->srp_ctx.s);
    BN_free(ctx->srp_ctx.B);
    BN_free(ctx->srp_ctx.A);
    BN_free(ctx->srp_ctx.a);
    BN_free(ctx->srp_ctx.b);
    BN_free(ctx->srp_ctx.v);
    memset(&ctx->srp_ctx, 0, sizeof(ctx->srp_ctx));
    ctx->srp_ctx.strength = SRP_MINIMAL_N;
    return 1;
}

int SSL_SRP_CTX_free(struct ssl_st *s)
{
    if (s == NULL)
        return 0;
    OPENSSL_free(s->srp_ctx.login);
    OPENSSL_free(s->srp_ctx.info);
    BN_free(s->srp_ctx.N);
    BN_free(s->srp_ctx.g);
    BN_free(s->srp_ctx.s);
    BN_free(s->srp_ctx.B);
    BN_free(s->srp_ctx.A);
    BN_free(s->srp_ctx.a);
    BN_free(s->srp_ctx.b);
    BN_free(s->srp_ctx.v);
    memset(&s->srp_ctx, 0, sizeof(s->srp_ctx));
    s->srp_ctx.strength = SRP_MINIMAL_N;
    return 1;
}

int SSL_SRP_CTX_init(struct ssl_st *s)
{
    SSL_CTX *ctx;

    if ((s == NULL) || ((ctx = s->ctx) == NULL))
        return 0;

    memset(&s->srp_ctx, 0, sizeof(s->srp_ctx));

    s->srp_ctx.SRP_cb_arg = ctx->srp_ctx.SRP_cb_arg;
    /* set client Hello login callback */
    s->srp_ctx.TLS_ext_srp_username_callback =
        ctx->srp_ctx.TLS_ext_srp_username_callback;
    /* set SRP N/g param callback for verification */
    s->srp_ctx.SRP_verify_param_callback =
        ctx->srp_ctx.SRP_verify_param_callback;
    /* set SRP client passwd callback */
    s->srp_ctx.SRP_give_srp_client_pwd_callback =
        ctx->srp_ctx.SRP_give_srp_client_pwd_callback;

    s->srp_ctx.strength = ctx->srp_ctx.strength;

    if (((ctx->srp_ctx.N != NULL) &&
         ((s->srp_ctx.N = BN_dup(ctx->srp_ctx.N)) == NULL)) ||
        ((ctx->srp_ctx.g != NULL) &&
         ((s->srp_ctx.g = BN_dup(ctx->srp_ctx.g)) == NULL)) ||
        ((ctx->srp_ctx.s != NULL) &&
         ((s->srp_ctx.s = BN_dup(ctx->srp_ctx.s)) == NULL)) ||
        ((ctx->srp_ctx.B != NULL) &&
         ((s->srp_ctx.B = BN_dup(ctx->srp_ctx.B)) == NULL)) ||
        ((ctx->srp_ctx.A != NULL) &&
         ((s->srp_ctx.A = BN_dup(ctx->srp_ctx.A)) == NULL)) ||
        ((ctx->srp_ctx.a != NULL) &&
         ((s->srp_ctx.a = BN_dup(ctx->srp_ctx.a)) == NULL)) ||
        ((ctx->srp_ctx.v != NULL) &&
         ((s->srp_ctx.v = BN_dup(ctx->srp_ctx.v)) == NULL)) ||
        ((ctx->srp_ctx.b != NULL) &&
         ((s->srp_ctx.b = BN_dup(ctx->srp_ctx.b)) == NULL))) {
        SSLerr(SSL_F_SSL_SRP_CTX_INIT, ERR_R_BN_LIB);
        goto err;
    }
    if ((ctx->srp_ctx.login != NULL) &&
        ((s->srp_ctx.login = OPENSSL_strdup(ctx->srp_ctx.login)) == NULL)) {
        SSLerr(SSL_F_SSL_SRP_CTX_INIT, ERR_R_INTERNAL_ERROR);
        goto err;
    }
    if ((ctx->srp_ctx.info != NULL) &&
        ((s->srp_ctx.info = BUF_strdup(ctx->srp_ctx.info)) == NULL)) {
        SSLerr(SSL_F_SSL_SRP_CTX_INIT, ERR_R_INTERNAL_ERROR);
        goto err;
    }
    s->srp_ctx.srp_Mask = ctx->srp_ctx.srp_Mask;

    return 1;
 err:
    OPENSSL_free(s->srp_ctx.login);
    OPENSSL_free(s->srp_ctx.info);
    BN_free(s->srp_ctx.N);
    BN_free(s->srp_ctx.g);
    BN_free(s->srp_ctx.s);
    BN_free(s->srp_ctx.B);
    BN_free(s->srp_ctx.A);
    BN_free(s->srp_ctx.a);
    BN_free(s->srp_ctx.b);
    BN_free(s->srp_ctx.v);
    memset(&s->srp_ctx, 0, sizeof(s->srp_ctx));
    return 0;
}

int SSL_CTX_SRP_CTX_init(struct ssl_ctx_st *ctx)
{
    if (ctx == NULL)
        return 0;

    memset(&ctx->srp_ctx, 0, sizeof(ctx->srp_ctx));
    ctx->srp_ctx.strength = SRP_MINIMAL_N;

    return 1;
}

int SSL_srp_server_param_with_username(SSL *s, int *ad)
{
    unsigned char b[SSL_MAX_MASTER_KEY_LENGTH];
    int al;

    *ad = SSL_AD_UNKNOWN_PSK_IDENTITY;
    if ((s->srp_ctx.TLS_ext_srp_username_callback != NULL) &&
        ((al =
          s->srp_ctx.TLS_ext_srp_username_callback(s, ad,
                                                   s->srp_ctx.SRP_cb_arg)) !=
         SSL_ERROR_NONE))
        return al;

    *ad = SSL_AD_INTERNAL_ERROR;
    if ((s->srp_ctx.N == NULL) ||
        (s->srp_ctx.g == NULL) ||
        (s->srp_ctx.s == NULL) || (s->srp_ctx.v == NULL))
        return SSL3_AL_FATAL;

    if (RAND_priv_bytes(b, sizeof(b)) <= 0)
        return SSL3_AL_FATAL;
    s->srp_ctx.b = BN_bin2bn(b, sizeof(b), NULL);
    OPENSSL_cleanse(b, sizeof(b));

    /* Calculate:  B = (kv + g^b) % N  */

    return ((s->srp_ctx.B =
             SRP_Calc_B(s->srp_ctx.b, s->srp_ctx.N, s->srp_ctx.g,
                        s->srp_ctx.v)) !=
            NULL) ? SSL_ERROR_NONE : SSL3_AL_FATAL;
}

int SSL_set_srp_server_param_pw(SSL *s, const char *user, const char *pass,
                                const char *grp)
{
    SRP_gN *GN = SRP_get_default_gN(grp);
    if (GN == NULL)
        return -1;
    s->srp_ctx.N = BN_dup(GN->N);
    s->srp_ctx.g = BN_dup(GN->g);
    BN_clear_free(s->srp_ctx.v);
    s->srp_ctx.v = NULL;
    BN_clear_free(s->srp_ctx.s);
    s->srp_ctx.s = NULL;
    if (!SRP_create_verifier_BN
        (user, pass, &s->srp_ctx.s, &s->srp_ctx.v, GN->N, GN->g))
        return -1;

    return 1;
}

int SSL_set_srp_server_param(SSL *s, const BIGNUM *N, const BIGNUM *g,
                             BIGNUM *sa, BIGNUM *v, char *info)
{
    if (N != NULL) {
        if (s->srp_ctx.N != NULL) {
            if (!BN_copy(s->srp_ctx.N, N)) {
                BN_free(s->srp_ctx.N);
                s->srp_ctx.N = NULL;
            }
        } else
            s->srp_ctx.N = BN_dup(N);
    }
    if (g != NULL) {
        if (s->srp_ctx.g != NULL) {
            if (!BN_copy(s->srp_ctx.g, g)) {
                BN_free(s->srp_ctx.g);
                s->srp_ctx.g = NULL;
            }
        } else
            s->srp_ctx.g = BN_dup(g);
    }
    if (sa != NULL) {
        if (s->srp_ctx.s != NULL) {
            if (!BN_copy(s->srp_ctx.s, sa)) {
                BN_free(s->srp_ctx.s);
                s->srp_ctx.s = NULL;
            }
        } else
            s->srp_ctx.s = BN_dup(sa);
    }
    if (v != NULL) {
        if (s->srp_ctx.v != NULL) {
            if (!BN_copy(s->srp_ctx.v, v)) {
                BN_free(s->srp_ctx.v);
                s->srp_ctx.v = NULL;
            }
        } else
            s->srp_ctx.v = BN_dup(v);
    }
    if (info != NULL) {
        if (s->srp_ctx.info)
            OPENSSL_free(s->srp_ctx.info);
        if ((s->srp_ctx.info = BUF_strdup(info)) == NULL)
            return -1;
    }

    if (!(s->srp_ctx.N) ||
        !(s->srp_ctx.g) || !(s->srp_ctx.s) || !(s->srp_ctx.v))
        return -1;

    return 1;
}

int srp_generate_server_master_secret(SSL *s)
{
    BIGNUM *K = NULL, *u = NULL;
    int ret = -1, tmp_len = 0;
    unsigned char *tmp = NULL;

    if (!SRP_Verify_A_mod_N(s->srp_ctx.A, s->srp_ctx.N))
        goto err;
    if ((u = SRP_Calc_u(s->srp_ctx.A, s->srp_ctx.B, s->srp_ctx.N)) == NULL)
        goto err;
    if ((K = SRP_Calc_server_key(s->srp_ctx.A, s->srp_ctx.v, u, s->srp_ctx.b,
                                 s->srp_ctx.N)) == NULL)
        goto err;

    tmp_len = BN_num_bytes(K);
    if ((tmp = OPENSSL_malloc(tmp_len)) == NULL) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR,
                 SSL_F_SRP_GENERATE_SERVER_MASTER_SECRET, ERR_R_MALLOC_FAILURE);
        goto err;
    }
    BN_bn2bin(K, tmp);
    /* Calls SSLfatal() as required */
    ret = ssl_generate_master_secret(s, tmp, tmp_len, 1);
 err:
    BN_clear_free(K);
    BN_clear_free(u);
    return ret;
}

int srp_generate_client_master_secret(SSL *s)
{
    BIGNUM *x = NULL, *u = NULL, *K = NULL;
    int ret = -1, tmp_len = 0;
    char *passwd = NULL;
    unsigned char *tmp = NULL;

    /*
     * Checks if b % n == 0
     */
    if (SRP_Verify_B_mod_N(s->srp_ctx.B, s->srp_ctx.N) == 0
            || (u = SRP_Calc_u(s->srp_ctx.A, s->srp_ctx.B, s->srp_ctx.N))
               == NULL
            || s->srp_ctx.SRP_give_srp_client_pwd_callback == NULL) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR,
                 SSL_F_SRP_GENERATE_CLIENT_MASTER_SECRET, ERR_R_INTERNAL_ERROR);
        goto err;
    }
    if ((passwd = s->srp_ctx.SRP_give_srp_client_pwd_callback(s,
                                                      s->srp_ctx.SRP_cb_arg))
            == NULL) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR,
                 SSL_F_SRP_GENERATE_CLIENT_MASTER_SECRET,
                 SSL_R_CALLBACK_FAILED);
        goto err;
    }
    if ((x = SRP_Calc_x(s->srp_ctx.s, s->srp_ctx.login, passwd)) == NULL
            || (K = SRP_Calc_client_key(s->srp_ctx.N, s->srp_ctx.B,
                                        s->srp_ctx.g, x,
                                        s->srp_ctx.a, u)) == NULL) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR,
                 SSL_F_SRP_GENERATE_CLIENT_MASTER_SECRET, ERR_R_INTERNAL_ERROR);
        goto err;
    }

    tmp_len = BN_num_bytes(K);
    if ((tmp = OPENSSL_malloc(tmp_len)) == NULL) {
        SSLfatal(s, SSL_AD_INTERNAL_ERROR,
                 SSL_F_SRP_GENERATE_CLIENT_MASTER_SECRET, ERR_R_MALLOC_FAILURE);
        goto err;
    }
    BN_bn2bin(K, tmp);
    /* Calls SSLfatal() as required */
    ret = ssl_generate_master_secret(s, tmp, tmp_len, 1);
 err:
    BN_clear_free(K);
    BN_clear_free(x);
    if (passwd != NULL)
        OPENSSL_clear_free(passwd, strlen(passwd));
    BN_clear_free(u);
    return ret;
}

int srp_verify_server_param(SSL *s)
{
    SRP_CTX *srp = &s->srp_ctx;
    /*
     * Sanity check parameters: we can quickly check B % N == 0 by checking B
     * != 0 since B < N
     */
    if (BN_ucmp(srp->g, srp->N) >= 0 || BN_ucmp(srp->B, srp->N) >= 0
        || BN_is_zero(srp->B)) {
        SSLfatal(s, SSL_AD_ILLEGAL_PARAMETER, SSL_F_SRP_VERIFY_SERVER_PARAM,
                 SSL_R_BAD_DATA);
        return 0;
    }

    if (BN_num_bits(srp->N) < srp->strength) {
        SSLfatal(s, SSL_AD_INSUFFICIENT_SECURITY, SSL_F_SRP_VERIFY_SERVER_PARAM,
                 SSL_R_INSUFFICIENT_SECURITY);
        return 0;
    }

    if (srp->SRP_verify_param_callback) {
        if (srp->SRP_verify_param_callback(s, srp->SRP_cb_arg) <= 0) {
            SSLfatal(s, SSL_AD_INSUFFICIENT_SECURITY,
                     SSL_F_SRP_VERIFY_SERVER_PARAM,
                     SSL_R_CALLBACK_FAILED);
            return 0;
        }
    } else if (!SRP_check_known_gN_param(srp->g, srp->N)) {
        SSLfatal(s, SSL_AD_INSUFFICIENT_SECURITY, SSL_F_SRP_VERIFY_SERVER_PARAM,
                 SSL_R_INSUFFICIENT_SECURITY);
        return 0;
    }

    return 1;
}

int SRP_Calc_A_param(SSL *s)
{
    unsigned char rnd[SSL_MAX_MASTER_KEY_LENGTH];

    if (RAND_priv_bytes(rnd, sizeof(rnd)) <= 0)
        return 0;
    s->srp_ctx.a = BN_bin2bn(rnd, sizeof(rnd), s->srp_ctx.a);
    OPENSSL_cleanse(rnd, sizeof(rnd));

    if (!(s->srp_ctx.A = SRP_Calc_A(s->srp_ctx.a, s->srp_ctx.N, s->srp_ctx.g)))
        return 0;

    return 1;
}

BIGNUM *SSL_get_srp_g(SSL *s)
{
    if (s->srp_ctx.g != NULL)
        return s->srp_ctx.g;
    return s->ctx->srp_ctx.g;
}

BIGNUM *SSL_get_srp_N(SSL *s)
{
    if (s->srp_ctx.N != NULL)
        return s->srp_ctx.N;
    return s->ctx->srp_ctx.N;
}

char *SSL_get_srp_username(SSL *s)
{
    if (s->srp_ctx.login != NULL)
        return s->srp_ctx.login;
    return s->ctx->srp_ctx.login;
}

char *SSL_get_srp_userinfo(SSL *s)
{
    if (s->srp_ctx.info != NULL)
        return s->srp_ctx.info;
    return s->ctx->srp_ctx.info;
}

int SSL_CTX_set_srp_username(SSL_CTX *ctx, char *name)
{
    return tls1_ctx_ctrl(ctx, SSL_CTRL_SET_TLS_EXT_SRP_USERNAME, 0, name);
}

int SSL_CTX_set_srp_password(SSL_CTX *ctx, char *password)
{
    return tls1_ctx_ctrl(ctx, SSL_CTRL_SET_TLS_EXT_SRP_PASSWORD, 0, password);
}

int SSL_CTX_set_srp_strength(SSL_CTX *ctx, int strength)
{
    return tls1_ctx_ctrl(ctx, SSL_CTRL_SET_TLS_EXT_SRP_STRENGTH, strength,
                         NULL);
}

int SSL_CTX_set_srp_verify_param_callback(SSL_CTX *ctx,
                                          int (*cb) (SSL *, void *))
{
    return tls1_ctx_callback_ctrl(ctx, SSL_CTRL_SET_SRP_VERIFY_PARAM_CB,
                                  (void (*)(void))cb);
}

int SSL_CTX_set_srp_cb_arg(SSL_CTX *ctx, void *arg)
{
    return tls1_ctx_ctrl(ctx, SSL_CTRL_SET_SRP_ARG, 0, arg);
}

int SSL_CTX_set_srp_username_callback(SSL_CTX *ctx,
                                      int (*cb) (SSL *, int *, void *))
{
    return tls1_ctx_callback_ctrl(ctx, SSL_CTRL_SET_TLS_EXT_SRP_USERNAME_CB,
                                  (void (*)(void))cb);
}

int SSL_CTX_set_srp_client_pwd_callback(SSL_CTX *ctx,
                                        char *(*cb) (SSL *, void *))
{
    return tls1_ctx_callback_ctrl(ctx, SSL_CTRL_SET_SRP_GIVE_CLIENT_PWD_CB,
                                  (void (*)(void))cb);
}

