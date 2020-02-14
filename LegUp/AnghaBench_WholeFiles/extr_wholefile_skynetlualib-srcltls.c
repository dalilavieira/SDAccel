#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct tls_context {int is_server; int is_close; int /*<<< orphan*/ * ssl; int /*<<< orphan*/ * in_bio; int /*<<< orphan*/ * out_bio; } ;
struct ssl_ctx {int /*<<< orphan*/ * ctx; } ;
typedef  int /*<<< orphan*/  outbuff ;
typedef  int /*<<< orphan*/  lua_State ;
struct TYPE_3__ {char* member_0; int (* member_1 ) (int /*<<< orphan*/ *) ;} ;
typedef  TYPE_1__ luaL_Reg ;
typedef  int /*<<< orphan*/  luaL_Buffer ;

/* Variables and functions */
 int BIO_ctrl_pending (int /*<<< orphan*/ *) ; 
 void* BIO_new (int /*<<< orphan*/ ) ; 
 int BIO_read (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  BIO_s_mem () ; 
 int /*<<< orphan*/  BIO_set_mem_eof_return (int /*<<< orphan*/ *,int) ; 
 int BIO_write (int /*<<< orphan*/ *,char*,size_t) ; 
 int /*<<< orphan*/  CONF_modules_unload (int) ; 
 int /*<<< orphan*/  CRYPTO_cleanup_all_ex_data () ; 
 int /*<<< orphan*/  ENGINE_cleanup () ; 
 int /*<<< orphan*/  ERR_free_strings () ; 
 int /*<<< orphan*/  ERR_load_BIO_strings () ; 
 int /*<<< orphan*/  EVP_cleanup () ; 
 int /*<<< orphan*/  OpenSSL_add_all_algorithms () ; 
 int /*<<< orphan*/  SSL_COMP_get_compression_methods () ; 
 int SSL_CTX_check_private_key (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SSL_CTX_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * SSL_CTX_new (int /*<<< orphan*/ ) ; 
 int SSL_CTX_set_tlsext_use_srtp (int /*<<< orphan*/ *,char const*) ; 
 int SSL_CTX_use_PrivateKey_file (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 
 int SSL_CTX_use_certificate_file (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ ) ; 
 int SSL_ERROR_WANT_READ ; 
 int /*<<< orphan*/  SSL_FILETYPE_PEM ; 
 int SSL_do_handshake (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SSL_free (int /*<<< orphan*/ *) ; 
 int SSL_get_error (int /*<<< orphan*/ *,int) ; 
 int SSL_is_init_finished (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SSL_library_init () ; 
 int /*<<< orphan*/  SSL_load_error_strings () ; 
 int /*<<< orphan*/ * SSL_new (int /*<<< orphan*/ *) ; 
 int SSL_read (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  SSL_set_accept_state (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SSL_set_bio (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SSL_set_connect_state (int /*<<< orphan*/ *) ; 
 int SSL_write (int /*<<< orphan*/ *,char*,size_t) ; 
 int /*<<< orphan*/  SSLv23_method () ; 
 int TLS_IS_INIT ; 
 int /*<<< orphan*/  luaL_addlstring (int /*<<< orphan*/ *,char const*,int) ; 
 int /*<<< orphan*/  luaL_buffinit (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaL_checkversion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  luaL_error (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  luaL_newlib (int /*<<< orphan*/ *,TYPE_1__*) ; 
 scalar_t__ luaL_newmetatable (int /*<<< orphan*/ *,char*) ; 
 char* luaL_optstring (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  luaL_pushresult (int /*<<< orphan*/ *) ; 
 scalar_t__ lua_newuserdata (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushboolean (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushcfunction (int /*<<< orphan*/ *,int (*) (int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  lua_pushstring (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  lua_pushvalue (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_setfield (int /*<<< orphan*/ *,int,char*) ; 
 int /*<<< orphan*/  lua_setmetatable (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_setuservalue (int /*<<< orphan*/ *,int) ; 
 char* lua_tolstring (int /*<<< orphan*/ *,int,size_t*) ; 
 char* lua_tostring (int /*<<< orphan*/ *,int) ; 
 struct tls_context* lua_touserdata (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  sk_SSL_COMP_free (int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (char const*,char*) ; 

__attribute__((used)) static void
_init_bio(lua_State* L, struct tls_context* tls_p, struct ssl_ctx* ctx_p) {
    tls_p->ssl = SSL_new(ctx_p->ctx);
    if(!tls_p->ssl) {
        luaL_error(L, "SSL_new faild");
    }

    tls_p->in_bio = BIO_new(BIO_s_mem());
    if(!tls_p->in_bio) {
        luaL_error(L, "new in bio faild");
    }
    BIO_set_mem_eof_return(tls_p->in_bio, -1); /* see: https://www.openssl.org/docs/crypto/BIO_s_mem.html */

    tls_p->out_bio = BIO_new(BIO_s_mem());
    if(!tls_p->out_bio) {
        luaL_error(L, "new out bio faild");
    }
    BIO_set_mem_eof_return(tls_p->out_bio, -1); /* see: https://www.openssl.org/docs/crypto/BIO_s_mem.html */

    SSL_set_bio(tls_p->ssl, tls_p->in_bio, tls_p->out_bio);
}

__attribute__((used)) static void
_init_client_context(lua_State* L, struct tls_context* tls_p, struct ssl_ctx* ctx_p) {
    tls_p->is_server = false;
    _init_bio(L, tls_p, ctx_p);
    SSL_set_connect_state(tls_p->ssl);
}

__attribute__((used)) static void
_init_server_context(lua_State* L, struct tls_context* tls_p, struct ssl_ctx* ctx_p) {
    tls_p->is_server = true;
    _init_bio(L, tls_p, ctx_p);
    SSL_set_accept_state(tls_p->ssl);
}

__attribute__((used)) static struct tls_context *
_check_context(lua_State* L, int idx) {
    struct tls_context* tls_p = (struct tls_context*)lua_touserdata(L, idx);
    if(!tls_p) {
        luaL_error(L, "need tls context");
    }
    if(tls_p->is_close) {
        luaL_error(L, "context is closed");
    }
    return tls_p;
}

__attribute__((used)) static struct ssl_ctx *
_check_sslctx(lua_State* L, int idx) {
    struct ssl_ctx* ctx_p = (struct ssl_ctx*)lua_touserdata(L, idx);
    if(!ctx_p) {
        luaL_error(L, "need sslctx");
    }
    return ctx_p;
}

__attribute__((used)) static int
_ltls_context_finished(lua_State* L) {
    struct tls_context* tls_p = _check_context(L, 1);
    int b = SSL_is_init_finished(tls_p->ssl);
    lua_pushboolean(L, b);
    return 1;
}

__attribute__((used)) static int
_ltls_context_close(lua_State* L) {
    struct tls_context* tls_p = lua_touserdata(L, 1);
    if(!tls_p->is_close) {
        SSL_free(tls_p->ssl);
        tls_p->ssl = NULL;
        tls_p->in_bio = NULL; //in_bio and out_bio will be free when SSL_free is called
        tls_p->out_bio = NULL;
        tls_p->is_close = true;
    }
    return 0;
}

__attribute__((used)) static int
_bio_read(lua_State* L, struct tls_context* tls_p) {
    char outbuff[4096];
    int all_read = 0;
    int read = 0;
    int pending = BIO_ctrl_pending(tls_p->out_bio);
    if(pending >0) {
        luaL_Buffer b;
        luaL_buffinit(L, &b);
        do {
            read = BIO_read(tls_p->out_bio, outbuff, sizeof(outbuff));
            // printf("_bio_read:%d pending:%d\n", read, pending);
            if(read > sizeof(outbuff)) {
                luaL_error(L, "invalid BIO_read:%d", read);
            }else if(read == -2) {
                luaL_error(L, "BIO_read not implemented in the specific BIO type");
            }else if (read > 0) {
                all_read += read;
                luaL_addlstring(&b, (const char*)outbuff, read);
            }
        }while(read == sizeof(outbuff));
        if(all_read>0){
            luaL_pushresult(&b);
        }
    }
    return all_read;
}

__attribute__((used)) static void
_bio_write(lua_State* L, struct tls_context* tls_p, const char* s, size_t len) {
    char* p = (char*)s;
    size_t sz = len;
    while(sz > 0) {
        int written = BIO_write(tls_p->in_bio, p, sz);
        if(written > sz) {
            luaL_error(L, "invalid BIO_write");
        }else if(written > 0) {
            p += written;
            sz -= written;
        }else if (written == -2) {
            luaL_error(L, "BIO_write not implemented in the specific BIO type");
        }
    }
}

__attribute__((used)) static int
_ltls_context_handshake(lua_State* L) {
    struct tls_context* tls_p = _check_context(L, 1);
    size_t slen = 0;
    const char* exchange = lua_tolstring(L, 2, &slen);

    // check handshake is finished
    if(SSL_is_init_finished(tls_p->ssl)) {
        luaL_error(L, "handshake is finished");
    }

    // handshake exchange
    if(slen > 0 && exchange != NULL) {
        _bio_write(L, tls_p, exchange, slen);
    }

    // first handshake; initiated by client
    if(!SSL_is_init_finished(tls_p->ssl)) {
        int ret = SSL_do_handshake(tls_p->ssl);
        if(ret == 1) {
            return 0;
        } else if (ret == -1) {
            int all_read = _bio_read(L, tls_p);
            if(all_read>0) {
                return 1;
            }
        } else {
            int err = SSL_get_error(tls_p->ssl, ret);
            luaL_error(L, "SSL_do_handshake error:%d ret:%d", err, ret);
        }
    }
    return 0;
}

__attribute__((used)) static int
_ltls_context_read(lua_State* L) {
    struct tls_context* tls_p = _check_context(L, 1);
    size_t slen = 0;
    const char* encrypted_data = lua_tolstring(L, 2, &slen);

    // write encrypted data
    if(slen>0 && encrypted_data) {
        _bio_write(L, tls_p, encrypted_data, slen);
    }

    char outbuff[4096];
    int read = 0;
    luaL_Buffer b;
    luaL_buffinit(L, &b);

    do {
        read = SSL_read(tls_p->ssl, outbuff, sizeof(outbuff));
        if(read < 0) {
            int err = SSL_get_error(tls_p->ssl, read);
            if(err == SSL_ERROR_WANT_READ) {
                break;
            }
            luaL_error(L, "SSL_read error:%d", err);
        }else if(read > sizeof(outbuff)) {
            luaL_error(L, "invalid SSL_read");
        }else if (read > 0) {
            luaL_addlstring(&b, outbuff, read);
        }
    }while(read == sizeof(outbuff));
    luaL_pushresult(&b);
    return 1;
}

__attribute__((used)) static int
_ltls_context_write(lua_State* L) {
    struct tls_context* tls_p = _check_context(L, 1);
    size_t slen = 0;
    char* unencrypted_data = (char*)lua_tolstring(L, 2, &slen);

    while(slen >0) {
        int written = SSL_write(tls_p->ssl, unencrypted_data,  slen);
        if(written < 0) {
            int err = SSL_get_error(tls_p->ssl, written);
            luaL_error(L, "SSL_write error:%d", err);
        }else if(written > slen) {
            luaL_error(L, "invalid SSL_write");
        }else if(written>0) {
            unencrypted_data += written;
            slen -= written;
        }
    }

    int all_read = _bio_read(L, tls_p);
    if(all_read <= 0) {
        lua_pushstring(L, "");
    }
    return 1;
}

__attribute__((used)) static int
_lctx_gc(lua_State* L) {
    struct ssl_ctx* ctx_p = _check_sslctx(L, 1);
    if(ctx_p->ctx) {
        SSL_CTX_free(ctx_p->ctx);
        ctx_p->ctx = NULL;
    }
    return 0;
}

__attribute__((used)) static int
_lctx_cert(lua_State* L) {
    struct ssl_ctx* ctx_p = _check_sslctx(L, 1);
    const char* certfile = lua_tostring(L, 2);
    const char* key = lua_tostring(L, 3);
    if(!certfile) {
        luaL_error(L, "need certfile");
    }

    if(!key) {
        luaL_error(L, "need private key");
    }

    int ret = SSL_CTX_use_certificate_file(ctx_p->ctx, certfile, SSL_FILETYPE_PEM);
    if(ret != 1) {
        luaL_error(L, "SSL_CTX_use_certificate_file error:%d", ret);
    }

    ret = SSL_CTX_use_PrivateKey_file(ctx_p->ctx, key, SSL_FILETYPE_PEM);
    if(ret != 1) {
        luaL_error(L, "SSL_CTX_use_PrivateKey_file error:%d", ret);
    }
    ret = SSL_CTX_check_private_key(ctx_p->ctx);
    if(ret != 1) {
        luaL_error(L, "SSL_CTX_check_private_key error:%d", ret);
    }
    return 0;
}

__attribute__((used)) static int
_lctx_ciphers(lua_State* L) {
    struct ssl_ctx* ctx_p = _check_sslctx(L, 1);
    const char* s = lua_tostring(L, 2);
    if(!s) {
        luaL_error(L, "need cipher list");
    }
    int ret = SSL_CTX_set_tlsext_use_srtp(ctx_p->ctx, s);
    if(ret != 0) {
        luaL_error(L, "SSL_CTX_set_tlsext_use_srtp error:%d", ret);
    }
    return 0;
}

__attribute__((used)) static int
lnew_ctx(lua_State* L) {
    struct ssl_ctx* ctx_p = (struct ssl_ctx*)lua_newuserdata(L, sizeof(*ctx_p));
    ctx_p->ctx = SSL_CTX_new(SSLv23_method());
    if(!ctx_p->ctx) {
        luaL_error(L, "SSL_CTX_new client faild.");
    }

    if(luaL_newmetatable(L, "_TLS_SSLCTX_METATABLE_")) {
        luaL_Reg l[] = {
            {"set_ciphers", _lctx_ciphers},
            {"set_cert", _lctx_cert},
            {NULL, NULL},
        };

        luaL_newlib(L, l);
        lua_setfield(L, -2, "__index");
        lua_pushcfunction(L, _lctx_gc);
        lua_setfield(L, -2, "__gc");
    }
    lua_setmetatable(L, -2);
    return 1;
}

__attribute__((used)) static int
lnew_tls(lua_State* L) {
    struct tls_context* tls_p = (struct tls_context*)lua_newuserdata(L, sizeof(*tls_p));
    tls_p->is_close = false;
    const char* method = luaL_optstring(L, 1, "nil");
    struct ssl_ctx* ctx_p = _check_sslctx(L, 2);
    lua_pushvalue(L, 2);
    lua_setuservalue(L, -2); // set ssl_ctx associated to tls_context

    if(strcmp(method, "client") == 0) {
        _init_client_context(L, tls_p, ctx_p);
    }else if(strcmp(method, "server") == 0) {
        _init_server_context(L, tls_p, ctx_p);
    } else {
        luaL_error(L, "invalid method:%s e.g[server, client]", method);
    }

    if(luaL_newmetatable(L, "_TLS_CONTEXT_METATABLE_")) {
        luaL_Reg l[] = {
            {"close", _ltls_context_close},
            {"finished", _ltls_context_finished},
            {"handshake", _ltls_context_handshake},
            {"read", _ltls_context_read},
            {"write", _ltls_context_write},
            {NULL, NULL},
        };
        luaL_newlib(L, l);
        lua_setfield(L, -2, "__index");
        lua_pushcfunction(L, _ltls_context_close);
        lua_setfield(L, -2, "__gc");
    }
    lua_setmetatable(L, -2);
    return 1;
}

int
luaopen_ltls_c(lua_State* L) {
    luaL_Reg l[] = {
        {"newctx", lnew_ctx},
        {"newtls", lnew_tls},
        {NULL, NULL},
    };
    luaL_checkversion(L);
    luaL_newlib(L, l);
    return 1;
}

void __attribute__((constructor)) ltls_init(void) {
#ifndef OPENSSL_EXTERNAL_INITIALIZATION
    SSL_library_init();
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    OpenSSL_add_all_algorithms();
    TLS_IS_INIT = true;
#endif
}

void __attribute__((destructor)) ltls_destory(void) {
    if(TLS_IS_INIT) {
        ENGINE_cleanup();
        CONF_modules_unload(1);
        ERR_free_strings();
        EVP_cleanup();
        sk_SSL_COMP_free(SSL_COMP_get_compression_methods());
        CRYPTO_cleanup_all_ex_data();
    }
}

