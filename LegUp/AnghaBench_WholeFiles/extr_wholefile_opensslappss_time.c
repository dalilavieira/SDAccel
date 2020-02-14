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
typedef  int /*<<< orphan*/  buf ;
struct TYPE_2__ {int depth; scalar_t__ error; } ;
typedef  int /*<<< orphan*/  SSL_METHOD ;
typedef  int /*<<< orphan*/  SSL_CTX ;
typedef  int /*<<< orphan*/  SSL ;
typedef  int OPTION_CHOICE ;
typedef  int /*<<< orphan*/  BIO ;

/* Variables and functions */
 int /*<<< orphan*/  BIO_SOCK_NODELAY ; 
 int /*<<< orphan*/  BIO_closesocket (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * BIO_new (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_printf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  BIO_s_connect () ; 
 int /*<<< orphan*/  BIO_set_conn_hostname (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/  BIO_set_conn_mode (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int BIO_snprintf (char*,int,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ERR_print_errors (int /*<<< orphan*/ ) ; 
#define  OPT_BUGS 147 
#define  OPT_CAFILE 146 
#define  OPT_CAPATH 145 
#define  OPT_CERT 144 
#define  OPT_CIPHER 143 
#define  OPT_CIPHERSUITES 142 
#define  OPT_CONNECT 141 
#define  OPT_EOF 140 
#define  OPT_ERR 139 
#define  OPT_HELP 138 
#define  OPT_KEY 137 
#define  OPT_NAMEOPT 136 
#define  OPT_NEW 135 
#define  OPT_NOCAFILE 134 
#define  OPT_NOCAPATH 133 
#define  OPT_REUSE 132 
#define  OPT_SSL3 131 
#define  OPT_TIME 130 
#define  OPT_VERIFY 129 
#define  OPT_WWW 128 
 int SECONDS ; 
 int SSL3_VERSION ; 
 char* SSL_CONNECT_NAME ; 
 int /*<<< orphan*/  SSL_CTX_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * SSL_CTX_new (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  SSL_CTX_set_cipher_list (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  SSL_CTX_set_ciphersuites (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ SSL_CTX_set_max_proto_version (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  SSL_CTX_set_mode (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SSL_CTX_set_options (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SSL_CTX_set_quiet_shutdown (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  SSL_MODE_AUTO_RETRY ; 
 int /*<<< orphan*/  SSL_OP_ALL ; 
 int SSL_RECEIVED_SHUTDOWN ; 
 int SSL_SENT_SHUTDOWN ; 
 int SSL_connect (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SSL_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SSL_get_fd (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * SSL_new (int /*<<< orphan*/ *) ; 
 int SSL_read (int /*<<< orphan*/ *,char*,int) ; 
 scalar_t__ SSL_session_reused (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SSL_set_bio (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SSL_set_connect_state (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SSL_set_shutdown (int /*<<< orphan*/ *,int) ; 
 int SSL_version (int /*<<< orphan*/ *) ; 
 scalar_t__ SSL_write (int /*<<< orphan*/ *,char*,int) ; 
 int START ; 
 int STOP ; 
 int TLS1_VERSION ; 
 int /*<<< orphan*/ * TLS_client_method () ; 
 scalar_t__ X509_V_OK ; 
 char* X509_verify_cert_error_string (scalar_t__) ; 
 double app_tminterval (int,int) ; 
 int /*<<< orphan*/  bio_err ; 
 int /*<<< orphan*/  ctx_set_verify_locations (int /*<<< orphan*/ *,char*,char*,int,int) ; 
static  int /*<<< orphan*/ * doConnection (int /*<<< orphan*/ *,char const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fmt_http_get_cmd ; 
 size_t fmt_http_get_cmd_size ; 
 int /*<<< orphan*/  fputc (int,int /*<<< orphan*/ ) ; 
 char* getenv (char*) ; 
 char* opt_arg () ; 
 int /*<<< orphan*/  opt_help (int /*<<< orphan*/ ) ; 
 char* opt_init (int,char**,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  opt_int (char*,int*) ; 
 int opt_next () ; 
 int opt_num_rest () ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  s_time_options ; 
 int /*<<< orphan*/  set_cert_stuff (int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/  set_nameopt (char*) ; 
 int /*<<< orphan*/  stdout ; 
 size_t strlen (char*) ; 
 scalar_t__ time (int /*<<< orphan*/ *) ; 
 TYPE_1__ verify_args ; 

__attribute__((used)) static double tm_Time_F(int s)
{
    return app_tminterval(s, 1);
}

int s_time_main(int argc, char **argv)
{
    char buf[1024 * 8];
    SSL *scon = NULL;
    SSL_CTX *ctx = NULL;
    const SSL_METHOD *meth = NULL;
    char *CApath = NULL, *CAfile = NULL, *cipher = NULL, *ciphersuites = NULL;
    char *www_path = NULL;
    char *host = SSL_CONNECT_NAME, *certfile = NULL, *keyfile = NULL, *prog;
    double totalTime = 0.0;
    int noCApath = 0, noCAfile = 0;
    int maxtime = SECONDS, nConn = 0, perform = 3, ret = 1, i, st_bugs = 0;
    long bytes_read = 0, finishtime = 0;
    OPTION_CHOICE o;
    int max_version = 0, ver, buf_len;
    size_t buf_size;

    meth = TLS_client_method();

    prog = opt_init(argc, argv, s_time_options);
    while ((o = opt_next()) != OPT_EOF) {
        switch (o) {
        case OPT_EOF:
        case OPT_ERR:
 opthelp:
            BIO_printf(bio_err, "%s: Use -help for summary.\n", prog);
            goto end;
        case OPT_HELP:
            opt_help(s_time_options);
            ret = 0;
            goto end;
        case OPT_CONNECT:
            host = opt_arg();
            break;
        case OPT_REUSE:
            perform = 2;
            break;
        case OPT_NEW:
            perform = 1;
            break;
        case OPT_VERIFY:
            if (!opt_int(opt_arg(), &verify_args.depth))
                goto opthelp;
            BIO_printf(bio_err, "%s: verify depth is %d\n",
                       prog, verify_args.depth);
            break;
        case OPT_CERT:
            certfile = opt_arg();
            break;
        case OPT_NAMEOPT:
            if (!set_nameopt(opt_arg()))
                goto end;
            break;
        case OPT_KEY:
            keyfile = opt_arg();
            break;
        case OPT_CAPATH:
            CApath = opt_arg();
            break;
        case OPT_CAFILE:
            CAfile = opt_arg();
            break;
        case OPT_NOCAPATH:
            noCApath = 1;
            break;
        case OPT_NOCAFILE:
            noCAfile = 1;
            break;
        case OPT_CIPHER:
            cipher = opt_arg();
            break;
        case OPT_CIPHERSUITES:
            ciphersuites = opt_arg();
            break;
        case OPT_BUGS:
            st_bugs = 1;
            break;
        case OPT_TIME:
            if (!opt_int(opt_arg(), &maxtime))
                goto opthelp;
            break;
        case OPT_WWW:
            www_path = opt_arg();
            buf_size = strlen(www_path) + fmt_http_get_cmd_size;
            if (buf_size > sizeof(buf)) {
                BIO_printf(bio_err, "%s: -www option is too long\n", prog);
                goto end;
            }
            break;
        case OPT_SSL3:
            max_version = SSL3_VERSION;
            break;
        }
    }
    argc = opt_num_rest();
    if (argc != 0)
        goto opthelp;

    if (cipher == NULL)
        cipher = getenv("SSL_CIPHER");

    if ((ctx = SSL_CTX_new(meth)) == NULL)
        goto end;

    SSL_CTX_set_mode(ctx, SSL_MODE_AUTO_RETRY);
    SSL_CTX_set_quiet_shutdown(ctx, 1);
    if (SSL_CTX_set_max_proto_version(ctx, max_version) == 0)
        goto end;

    if (st_bugs)
        SSL_CTX_set_options(ctx, SSL_OP_ALL);
    if (cipher != NULL && !SSL_CTX_set_cipher_list(ctx, cipher))
        goto end;
    if (ciphersuites != NULL && !SSL_CTX_set_ciphersuites(ctx, ciphersuites))
        goto end;
    if (!set_cert_stuff(ctx, certfile, keyfile))
        goto end;

    if (!ctx_set_verify_locations(ctx, CAfile, CApath, noCAfile, noCApath)) {
        ERR_print_errors(bio_err);
        goto end;
    }
    if (!(perform & 1))
        goto next;
    printf("Collecting connection statistics for %d seconds\n", maxtime);

    /* Loop and time how long it takes to make connections */

    bytes_read = 0;
    finishtime = (long)time(NULL) + maxtime;
    tm_Time_F(START);
    for (;;) {
        if (finishtime < (long)time(NULL))
            break;

        if ((scon = doConnection(NULL, host, ctx)) == NULL)
            goto end;

        if (www_path != NULL) {
            buf_len = BIO_snprintf(buf, sizeof(buf), fmt_http_get_cmd,
                                   www_path);
            if (buf_len <= 0 || SSL_write(scon, buf, buf_len) <= 0)
                goto end;
            while ((i = SSL_read(scon, buf, sizeof(buf))) > 0)
                bytes_read += i;
        }
        SSL_set_shutdown(scon, SSL_SENT_SHUTDOWN | SSL_RECEIVED_SHUTDOWN);
        BIO_closesocket(SSL_get_fd(scon));

        nConn += 1;
        if (SSL_session_reused(scon)) {
            ver = 'r';
        } else {
            ver = SSL_version(scon);
            if (ver == TLS1_VERSION)
                ver = 't';
            else if (ver == SSL3_VERSION)
                ver = '3';
            else
                ver = '*';
        }
        fputc(ver, stdout);
        fflush(stdout);

        SSL_free(scon);
        scon = NULL;
    }
    totalTime += tm_Time_F(STOP); /* Add the time for this iteration */

    i = (int)((long)time(NULL) - finishtime + maxtime);
    printf
        ("\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",
         nConn, totalTime, ((double)nConn / totalTime), bytes_read);
    printf
        ("%d connections in %ld real seconds, %ld bytes read per connection\n",
         nConn, (long)time(NULL) - finishtime + maxtime, bytes_read / nConn);

    /*
     * Now loop and time connections using the same session id over and over
     */

 next:
    if (!(perform & 2))
        goto end;
    printf("\n\nNow timing with session id reuse.\n");

    /* Get an SSL object so we can reuse the session id */
    if ((scon = doConnection(NULL, host, ctx)) == NULL) {
        BIO_printf(bio_err, "Unable to get connection\n");
        goto end;
    }

    if (www_path != NULL) {
        buf_len = BIO_snprintf(buf, sizeof(buf), fmt_http_get_cmd, www_path);
        if (buf_len <= 0 || SSL_write(scon, buf, buf_len) <= 0)
            goto end;
        while ((i = SSL_read(scon, buf, sizeof(buf))) > 0)
            continue;
    }
    SSL_set_shutdown(scon, SSL_SENT_SHUTDOWN | SSL_RECEIVED_SHUTDOWN);
    BIO_closesocket(SSL_get_fd(scon));

    nConn = 0;
    totalTime = 0.0;

    finishtime = (long)time(NULL) + maxtime;

    printf("starting\n");
    bytes_read = 0;
    tm_Time_F(START);

    for (;;) {
        if (finishtime < (long)time(NULL))
            break;

        if ((doConnection(scon, host, ctx)) == NULL)
            goto end;

        if (www_path != NULL) {
            buf_len = BIO_snprintf(buf, sizeof(buf), fmt_http_get_cmd,
                                   www_path);
            if (buf_len <= 0 || SSL_write(scon, buf, buf_len) <= 0)
                goto end;
            while ((i = SSL_read(scon, buf, sizeof(buf))) > 0)
                bytes_read += i;
        }
        SSL_set_shutdown(scon, SSL_SENT_SHUTDOWN | SSL_RECEIVED_SHUTDOWN);
        BIO_closesocket(SSL_get_fd(scon));

        nConn += 1;
        if (SSL_session_reused(scon)) {
            ver = 'r';
        } else {
            ver = SSL_version(scon);
            if (ver == TLS1_VERSION)
                ver = 't';
            else if (ver == SSL3_VERSION)
                ver = '3';
            else
                ver = '*';
        }
        fputc(ver, stdout);
        fflush(stdout);
    }
    totalTime += tm_Time_F(STOP); /* Add the time for this iteration */

    printf
        ("\n\n%d connections in %.2fs; %.2f connections/user sec, bytes read %ld\n",
         nConn, totalTime, ((double)nConn / totalTime), bytes_read);
    printf
        ("%d connections in %ld real seconds, %ld bytes read per connection\n",
         nConn, (long)time(NULL) - finishtime + maxtime, bytes_read / nConn);

    ret = 0;

 end:
    SSL_free(scon);
    SSL_CTX_free(ctx);
    return ret;
}

__attribute__((used)) static SSL *doConnection(SSL *scon, const char *host, SSL_CTX *ctx)
{
    BIO *conn;
    SSL *serverCon;
    int i;

    if ((conn = BIO_new(BIO_s_connect())) == NULL)
        return NULL;

    BIO_set_conn_hostname(conn, host);
    BIO_set_conn_mode(conn, BIO_SOCK_NODELAY);

    if (scon == NULL)
        serverCon = SSL_new(ctx);
    else {
        serverCon = scon;
        SSL_set_connect_state(serverCon);
    }

    SSL_set_bio(serverCon, conn, conn);

    /* ok, lets connect */
    i = SSL_connect(serverCon);
    if (i <= 0) {
        BIO_printf(bio_err, "ERROR\n");
        if (verify_args.error != X509_V_OK)
            BIO_printf(bio_err, "verify error:%s\n",
                       X509_verify_cert_error_string(verify_args.error));
        else
            ERR_print_errors(bio_err);
        if (scon == NULL)
            SSL_free(serverCon);
        return NULL;
    }

#if defined(SOL_SOCKET) && defined(SO_LINGER)
    {
        struct linger no_linger;
        int fd;

        no_linger.l_onoff  = 1;
        no_linger.l_linger = 0;
        fd = SSL_get_fd(serverCon);
        if (fd >= 0)
            (void)setsockopt(fd, SOL_SOCKET, SO_LINGER, (char*)&no_linger,
                             sizeof(no_linger));
    }
#endif

    return serverCon;
}

