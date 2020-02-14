#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_34__   TYPE_9__ ;
typedef  struct TYPE_33__   TYPE_8__ ;
typedef  struct TYPE_32__   TYPE_7__ ;
typedef  struct TYPE_31__   TYPE_6__ ;
typedef  struct TYPE_30__   TYPE_5__ ;
typedef  struct TYPE_29__   TYPE_4__ ;
typedef  struct TYPE_28__   TYPE_3__ ;
typedef  struct TYPE_27__   TYPE_2__ ;
typedef  struct TYPE_26__   TYPE_1__ ;
typedef  struct TYPE_25__   TYPE_17__ ;
typedef  struct TYPE_24__   TYPE_16__ ;
typedef  struct TYPE_23__   TYPE_15__ ;
typedef  struct TYPE_22__   TYPE_14__ ;
typedef  struct TYPE_21__   TYPE_13__ ;
typedef  struct TYPE_20__   TYPE_12__ ;
typedef  struct TYPE_19__   TYPE_11__ ;
typedef  struct TYPE_18__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tcb_state ;
struct TYPE_26__ {unsigned char version; } ;
struct TYPE_27__ {TYPE_1__ vnc; } ;
struct ProtocolState {int app_proto; int port; int /*<<< orphan*/  state; TYPE_2__ sub; int /*<<< orphan*/  is_sent_sslhello; } ;
struct PreprocessedInfo {int dummy; } ;
struct PcapFile {int dummy; } ;
struct InteractiveData {int /*<<< orphan*/  member_1; int /*<<< orphan*/  member_0; } ;
struct BannerOutput {int dummy; } ;
struct TYPE_28__ {TYPE_16__** tcp; } ;
struct Banner1 {scalar_t__ http_fields; scalar_t__ smack; TYPE_3__ payloads; } ;
typedef  int /*<<< orphan*/  px ;
struct TYPE_34__ {int /*<<< orphan*/  (* init ) (struct Banner1*) ;int /*<<< orphan*/  (* parse ) (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ;} ;
struct TYPE_33__ {int /*<<< orphan*/  (* init ) (struct Banner1*) ;int /*<<< orphan*/  (* parse ) (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ;} ;
struct TYPE_32__ {int (* selftest ) () ;int /*<<< orphan*/  (* init ) (struct Banner1*) ;int /*<<< orphan*/  (* parse ) (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ;} ;
struct TYPE_31__ {int /*<<< orphan*/  (* init ) (struct Banner1*) ;int /*<<< orphan*/  (* parse ) (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ;} ;
struct TYPE_30__ {int /*<<< orphan*/  (* init ) (struct Banner1*) ;int /*<<< orphan*/  (* parse ) (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ;} ;
struct TYPE_29__ {unsigned int id; int extra; int /*<<< orphan*/  is_anchored; int /*<<< orphan*/  pattern_length; scalar_t__ pattern; } ;
struct TYPE_25__ {int /*<<< orphan*/  (* init ) (struct Banner1*) ;int /*<<< orphan*/  (* parse ) (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ;} ;
struct TYPE_24__ {int (* selftest ) () ;int /*<<< orphan*/  (* init ) (struct Banner1*) ;int /*<<< orphan*/  (* parse ) (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ;} ;
struct TYPE_23__ {int /*<<< orphan*/  (* init ) (struct Banner1*) ;int /*<<< orphan*/  (* parse ) (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ;} ;
struct TYPE_22__ {int /*<<< orphan*/  (* init ) (struct Banner1*) ;int /*<<< orphan*/  (* parse ) (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ;} ;
struct TYPE_21__ {int /*<<< orphan*/  (* init ) (struct Banner1*) ;int /*<<< orphan*/  (* parse ) (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ;} ;
struct TYPE_20__ {int /*<<< orphan*/  (* init ) (struct Banner1*) ;int /*<<< orphan*/  (* parse ) (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ;} ;
struct TYPE_19__ {int /*<<< orphan*/  (* init ) (struct Banner1*) ;} ;
struct TYPE_18__ {int (* selftest ) () ;int /*<<< orphan*/  (* init ) (struct Banner1*) ;int /*<<< orphan*/  (* parse ) (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ;} ;

/* Variables and functions */
 struct Banner1* CALLOC (int,int) ; 
#define  PROTO_FTP 142 
#define  PROTO_HEUR 141 
#define  PROTO_HTTP 140 
#define  PROTO_IMAP4 139 
#define  PROTO_MEMCACHED 138 
#define  PROTO_NONE 137 
#define  PROTO_POP3 136 
#define  PROTO_SCRIPTING 135 
#define  PROTO_SMB 134 
#define  PROTO_SMTP 133 
#define  PROTO_SSH1 132 
#define  PROTO_SSH2 131 
#define  PROTO_SSL3 130 
#define  PROTO_VERSIONING 129 
#define  PROTO_VNC_RFB 128 
 int /*<<< orphan*/  SMACK_CASE_INSENSITIVE ; 
 size_t SMACK_NOT_FOUND ; 
 TYPE_17__ banner_ftp ; 
 TYPE_16__ banner_http ; 
 TYPE_15__ banner_imap4 ; 
 TYPE_14__ banner_memcached ; 
 TYPE_13__ banner_pop3 ; 
 TYPE_12__ banner_scripting ; 
 TYPE_11__ banner_smb0 ; 
 TYPE_10__ banner_smb1 ; 
 TYPE_9__ banner_smtp ; 
 TYPE_8__ banner_ssh ; 
 TYPE_7__ banner_ssl ; 
 TYPE_6__ banner_versioning ; 
 TYPE_5__ banner_vnc ; 
 int /*<<< orphan*/  banout_append (struct BannerOutput*,int const,unsigned char const*,size_t) ; 
 int /*<<< orphan*/  banout_init (struct BannerOutput*) ; 
 int /*<<< orphan*/  banout_release (struct BannerOutput*) ; 
 scalar_t__ banout_selftest () ; 
 unsigned char* banout_string (struct BannerOutput*,int const) ; 
 unsigned int banout_string_length (struct BannerOutput*,int const) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  free (struct Banner1*) ; 
 scalar_t__ memcmp (unsigned char const*,char*,int) ; 
 int /*<<< orphan*/  memset (struct ProtocolState*,int /*<<< orphan*/ ,int) ; 
 TYPE_4__* patterns ; 
 int /*<<< orphan*/  pcapfile_close (struct PcapFile*) ; 
 unsigned int pcapfile_datalink (struct PcapFile*) ; 
 struct PcapFile* pcapfile_openread (char const*) ; 
 int pcapfile_readframe (struct PcapFile*,unsigned int*,unsigned int*,unsigned int*,unsigned int*,unsigned char*,int) ; 
 unsigned int preprocess_frame (unsigned char*,unsigned int,unsigned int,struct PreprocessedInfo*) ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  smack_add_pattern (scalar_t__,scalar_t__,int /*<<< orphan*/ ,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smack_compile (scalar_t__) ; 
 scalar_t__ smack_create (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  smack_destroy (scalar_t__) ; 
 size_t smack_search_next (scalar_t__,int /*<<< orphan*/ *,unsigned char const*,unsigned int*,unsigned int) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ strlen (char const*) ; 
 int /*<<< orphan*/  stub1 (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ; 
 int /*<<< orphan*/  stub10 (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ; 
 int /*<<< orphan*/  stub11 (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ; 
 int /*<<< orphan*/  stub12 (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ; 
 int /*<<< orphan*/  stub13 (struct Banner1*) ; 
 int /*<<< orphan*/  stub14 (struct Banner1*) ; 
 int /*<<< orphan*/  stub15 (struct Banner1*) ; 
 int /*<<< orphan*/  stub16 (struct Banner1*) ; 
 int /*<<< orphan*/  stub17 (struct Banner1*) ; 
 int /*<<< orphan*/  stub18 (struct Banner1*) ; 
 int /*<<< orphan*/  stub19 (struct Banner1*) ; 
 int /*<<< orphan*/  stub2 (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ; 
 int /*<<< orphan*/  stub20 (struct Banner1*) ; 
 int /*<<< orphan*/  stub21 (struct Banner1*) ; 
 int /*<<< orphan*/  stub22 (struct Banner1*) ; 
 int /*<<< orphan*/  stub23 (struct Banner1*) ; 
 int /*<<< orphan*/  stub24 (struct Banner1*) ; 
 int /*<<< orphan*/  stub25 (struct Banner1*) ; 
 int stub26 () ; 
 int stub27 () ; 
 int stub28 () ; 
 int /*<<< orphan*/  stub3 (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ; 
 int /*<<< orphan*/  stub4 (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ; 
 int /*<<< orphan*/  stub5 (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ; 
 int /*<<< orphan*/  stub6 (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ; 
 int /*<<< orphan*/  stub7 (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ; 
 int /*<<< orphan*/  stub8 (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ; 
 int /*<<< orphan*/  stub9 (struct Banner1 const*,scalar_t__,struct ProtocolState*,unsigned char const*,size_t,struct BannerOutput*,struct InteractiveData*) ; 

unsigned
banner1_parse(
        const struct Banner1 *banner1,
        struct ProtocolState *tcb_state,
        const unsigned char *px, size_t length,
        struct BannerOutput *banout,
        struct InteractiveData *more)
{
    size_t x;
    unsigned offset = 0;
    unsigned proto;


    switch (tcb_state->app_proto) {
    case PROTO_NONE:
    case PROTO_HEUR:
        x = smack_search_next(
                        banner1->smack,
                        &tcb_state->state,
                        px, &offset, (unsigned)length);
        if (x != SMACK_NOT_FOUND)
            proto = patterns[x].id;
        else
            proto = 0xFFFFFFFF;
        if (proto != 0xFFFFFFFF
            && !(proto == PROTO_SSL3 && !tcb_state->is_sent_sslhello)) {
            unsigned i;

            /* re-read the stuff that we missed */
            for (i=0; patterns[i].id && patterns[i].id != tcb_state->app_proto; i++)
                ;

            /* Kludge: patterns look confusing, so add port info to the
             * pattern */
            switch (proto) {
            case PROTO_FTP:
                if (patterns[x].extra == 1) {
                    if (tcb_state->port == 25 || tcb_state->port == 587)
                        proto = PROTO_SMTP;
                }
                break;
            case PROTO_VNC_RFB:
                tcb_state->sub.vnc.version = (unsigned char)patterns[x].extra;
                break;
            }

            tcb_state->app_proto = (unsigned short)proto;

            /* reset the state back again */
            tcb_state->state = 0;

            /* If there is any data from a previous packet, re-parse that */
            {
                const unsigned char *s = banout_string(banout, PROTO_HEUR);
                unsigned s_len = banout_string_length(banout, PROTO_HEUR);

                if (s && s_len)
                banner1_parse(
                                banner1,
                                tcb_state,
                                s, s_len,
                                banout,
                                more);
            }
            banner1_parse(
                            banner1,
                            tcb_state,
                            px, length,
                            banout,
                            more);
        } else {
            banout_append(banout, PROTO_HEUR, px, length);
        }
        break;
    case PROTO_FTP:
            banner_ftp.parse(   banner1,
                             banner1->http_fields,
                             tcb_state,
                             px, length,
                             banout,
                             more);
            break;
    case PROTO_SMTP:
            banner_smtp.parse(   banner1,
                              banner1->http_fields,
                              tcb_state,
                              px, length,
                              banout,
                              more);
            break;
            
    case PROTO_POP3:
            banner_pop3.parse(   banner1,
                              banner1->http_fields,
                              tcb_state,
                              px, length,
                              banout,
                              more);
            break;
    case PROTO_IMAP4:
            banner_imap4.parse(banner1,
                              banner1->http_fields,
                              tcb_state,
                              px, length,
                              banout,
                              more);
            break;
            
    case PROTO_SSH1:
    case PROTO_SSH2:
        /* generic text-based parser
         * TODO: in future, need to split these into separate protocols,
         * especially when binary parsing is added to SSH */
        banner_ssh.parse(   banner1,
                            banner1->http_fields,
                            tcb_state,
                            px, length,
                            banout,
                            more);
        break;
    case PROTO_HTTP:
        banner_http.parse(
                        banner1,
                        banner1->http_fields,
                        tcb_state,
                        px, length,
                        banout,
                        more);
        break;
    case PROTO_SSL3:
        banner_ssl.parse(
                        banner1,
                        banner1->http_fields,
                        tcb_state,
                        px, length,
                        banout,
                        more);
        break;
    case PROTO_SMB:
        banner_smb1.parse(
                        banner1,
                        banner1->http_fields,
                        tcb_state,
                        px, length,
                        banout,
                        more);
        break;
    case PROTO_VNC_RFB:
        banner_vnc.parse(    banner1,
                             banner1->http_fields,
                             tcb_state,
                             px, length,
                             banout,
                             more);
        break;
    case PROTO_MEMCACHED:
        banner_memcached.parse(    banner1,
                             banner1->http_fields,
                             tcb_state,
                             px, length,
                             banout,
                             more);
        break;
    case PROTO_SCRIPTING:
        banner_scripting.parse(    banner1,
                                   banner1->http_fields,
                                   tcb_state,
                                   px, length,
                                   banout,
                                   more);
        break;
    case PROTO_VERSIONING:
        banner_versioning.parse(      banner1,
                                   banner1->http_fields,
                                   tcb_state,
                                   px, length,
                                   banout,
                                   more);
        break;

    default:
        fprintf(stderr, "banner1: internal error\n");
        break;

    }

    return tcb_state->app_proto;
}

struct Banner1 *
banner1_create(void)
{
    struct Banner1 *b;
    unsigned i;

    b = CALLOC(1, sizeof(*b));
    

    /*
     * This creates a pattern-matching blob for heuristically determining
     * a protocol that runs on wrong ports, such as how FTP servers
     * often respond with "220 " or VNC servers respond with "RFB".
     */
    b->smack = smack_create("banner1", SMACK_CASE_INSENSITIVE);
    for (i=0; patterns[i].pattern; i++)
        smack_add_pattern(
                    b->smack,
                    patterns[i].pattern,
                    patterns[i].pattern_length,
                    i,
                    patterns[i].is_anchored);
    smack_compile(b->smack);

    /*
     * [TODO] These need to be moved into the 'init' functions
     */
    b->payloads.tcp[80] = &banner_http;
    b->payloads.tcp[8080] = &banner_http;
    b->payloads.tcp[139] = (void*)&banner_smb0;
    b->payloads.tcp[445] = (void*)&banner_smb1;
    b->payloads.tcp[443] = (void*)&banner_ssl;   /* HTTP/s */
    b->payloads.tcp[465] = (void*)&banner_ssl;   /* SMTP/s */
    b->payloads.tcp[990] = (void*)&banner_ssl;   /* FTP/s */
    b->payloads.tcp[991] = (void*)&banner_ssl;
    b->payloads.tcp[992] = (void*)&banner_ssl;   /* Telnet/s */
    b->payloads.tcp[993] = (void*)&banner_ssl;   /* IMAP4/s */
    b->payloads.tcp[994] = (void*)&banner_ssl;
    b->payloads.tcp[995] = (void*)&banner_ssl;   /* POP3/s */
    b->payloads.tcp[2083] = (void*)&banner_ssl;  /* cPanel - SSL */
    b->payloads.tcp[2087] = (void*)&banner_ssl;  /* WHM - SSL */
    b->payloads.tcp[2096] = (void*)&banner_ssl;  /* cPanel webmail - SSL */
    b->payloads.tcp[8443] = (void*)&banner_ssl;  /* Plesk Control Panel - SSL */
    b->payloads.tcp[9050] = (void*)&banner_ssl;  /* Tor */
    b->payloads.tcp[8140] = (void*)&banner_ssl;  /* puppet */
    b->payloads.tcp[11211] = (void*)&banner_memcached;

    /* 
     * This goes down the list of all the TCP protocol handlers and initializes
     * them.
     */
    banner_ftp.init(b);
    banner_http.init(b);
    banner_imap4.init(b);
    banner_memcached.init(b);
    banner_pop3.init(b);
    banner_smtp.init(b);
    banner_ssh.init(b);
    banner_ssl.init(b);
    banner_smb0.init(b);
    banner_smb1.init(b);
    banner_vnc.init(b);
    
    /* scripting/versioning come after the rest */
    banner_scripting.init(b);
    banner_versioning.init(b);


    return b;
}

void
banner1_destroy(struct Banner1 *b)
{
    if (b == NULL)
        return;
    if (b->smack)
        smack_destroy(b->smack);
    if (b->http_fields)
        smack_destroy(b->http_fields);
    free(b);
}

void
banner1_test(const char *filename)
{
    struct PcapFile *cap;
    unsigned link_type;

    cap = pcapfile_openread(filename);
    if (cap == NULL) {
        fprintf(stderr, "%s: can't open capture file\n", filename);
        return;
    }

    link_type = pcapfile_datalink(cap);

    for (;;) {
        int packets_read;
        unsigned secs;
        unsigned usecs;
        unsigned origlength;
        unsigned length;
        unsigned char px[65536];
        struct PreprocessedInfo parsed;
        unsigned x;


        packets_read = pcapfile_readframe(
                    cap,    /* capture dump file */
                    &secs, &usecs,
                    &origlength, &length,
                    px, sizeof(px));
        if (packets_read == 0)
            break;


        x = preprocess_frame(px, length, link_type, &parsed);
        if (x == 0)
            continue;

    }

    pcapfile_close(cap);
}

int
banner1_selftest()
{
    unsigned i;
    struct Banner1 *b;
    struct ProtocolState tcb_state[1];
    const unsigned char *px;
    unsigned length;
    struct BannerOutput banout[1];
    static const char *http_header =
        "HTTP/1.0 302 Redirect\r\n"
        "Date: Tue, 03 Sep 2013 06:50:01 GMT\r\n"
        "Connection: close\r\n"
        "Via: HTTP/1.1 ir14.fp.bf1.yahoo.com (YahooTrafficServer/1.2.0.13 [c s f ])\r\n"
        "Server: YTS/1.20.13\r\n"
        "Cache-Control: no-store\r\n"
        "Content-Type: text/html\r\n"
        "Content-Language: en\r\n"
        "Location: http://failsafe.fp.yahoo.com/404.html\r\n"
        "Content-Length: 227\r\n"
        "\r\n<title>hello</title>\n";
    px = (const unsigned char *)http_header;
    length = (unsigned)strlen(http_header);


    /*
     * First, test the "banout" subsystem
     */
    if (banout_selftest() != 0) {
        fprintf(stderr, "banout: failed\n");
        return 1;
    }


    /*
     * Test one character at a time
     */
    b = banner1_create();
    banout_init(banout);

    memset(tcb_state, 0, sizeof(tcb_state[0]));

    for (i=0; i<length; i++) {
        struct InteractiveData more = {0,0};

        banner1_parse(
                    b,
                    tcb_state,
                    px+i, 1,
                    banout,
                    &more);
    }


    {
        const unsigned char *s = banout_string(banout, PROTO_HTTP);
        if (memcmp(s, "HTTP/1.0 302", 11) != 0) {
            printf("banner1: test failed\n");
            return 1;
        }
    }
    banout_release(banout);
    banner1_destroy(b);

    /*
     * Test whole buffer
     */
    b = banner1_create();

    memset(tcb_state, 0, sizeof(tcb_state[0]));

    banner1_parse(
                    b,
                    tcb_state,
                    px, length,
                    banout,
                    0);
    banner1_destroy(b);
    /*if (memcmp(banner, "Via:HTTP/1.1", 11) != 0) {
        printf("banner1: test failed\n");
        return 1;
    }*/


    {
        int x = 0;

        x = banner_ssl.selftest();
        if (x) {
            fprintf(stderr, "SSL banner: selftest failed\n");
            return 1;
        }
        
        x = banner_smb1.selftest();
        if (x) {
            fprintf(stderr, "SMB banner: selftest failed\n");
            return 1;
        }
        
        x = banner_http.selftest();
        if (x) {
            fprintf(stderr, "HTTP banner: selftest failed\n");
            return 1;
        }

        return x;
    }
}

