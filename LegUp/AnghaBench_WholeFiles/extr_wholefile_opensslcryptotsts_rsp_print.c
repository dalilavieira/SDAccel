#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct status_map_st {int member_0; char* member_1; scalar_t__ bit; int /*<<< orphan*/  text; } ;
struct TYPE_12__ {int /*<<< orphan*/ * micros; int /*<<< orphan*/ * millis; int /*<<< orphan*/ * seconds; } ;
struct TYPE_11__ {TYPE_1__* tst_info; TYPE_2__* status_info; } ;
struct TYPE_10__ {int /*<<< orphan*/  const* failure_info; int /*<<< orphan*/  text; int /*<<< orphan*/  status; } ;
struct TYPE_9__ {int /*<<< orphan*/  extensions; int /*<<< orphan*/ * tsa; int /*<<< orphan*/ * nonce; scalar_t__ ordering; TYPE_4__ const* accuracy; int /*<<< orphan*/  time; int /*<<< orphan*/ * serial; int /*<<< orphan*/  msg_imprint; int /*<<< orphan*/  policy_id; int /*<<< orphan*/  version; } ;
typedef  TYPE_1__ TS_TST_INFO ;
typedef  TYPE_2__ TS_STATUS_INFO ;
typedef  TYPE_3__ TS_RESP ;
typedef  TYPE_4__ TS_ACCURACY ;
typedef  int /*<<< orphan*/  BIO ;
typedef  int /*<<< orphan*/  ASN1_BIT_STRING ;

/* Variables and functions */
 scalar_t__ ASN1_BIT_STRING_get_bit (int /*<<< orphan*/  const*,scalar_t__) ; 
 int /*<<< orphan*/  ASN1_GENERALIZEDTIME_print (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 void* ASN1_INTEGER_get (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ASN1_STRING_print_ex (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_printf (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  BIO_puts (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  BIO_write (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  CONF_VALUE ; 
 scalar_t__ OSSL_NELEM (char const**) ; 
 int STACK_OF (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TS_ASN1_INTEGER_print_bio (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
#define  TS_INFO_ADD_INFO_NOT_AVAILABLE 135 
#define  TS_INFO_BAD_ALG 134 
#define  TS_INFO_BAD_DATA_FORMAT 133 
#define  TS_INFO_BAD_REQUEST 132 
#define  TS_INFO_SYSTEM_FAILURE 131 
#define  TS_INFO_TIME_NOT_AVAILABLE 130 
#define  TS_INFO_UNACCEPTED_EXTENSION 129 
#define  TS_INFO_UNACCEPTED_POLICY 128 
 int /*<<< orphan*/  TS_MSG_IMPRINT_print_bio (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TS_OBJ_print_bio (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int TS_STATUS_INFO_print_bio (int /*<<< orphan*/ *,TYPE_2__*) ; 
 int TS_TST_INFO_print_bio (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  TS_ext_print_bio (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  X509V3_EXT_val_prn (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  X509V3_conf_free ; 
 int i2v_GENERAL_NAME (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int nval ; 
 int sk_ASN1_UTF8STRING_num (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sk_ASN1_UTF8STRING_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sk_CONF_VALUE_pop_free (int,int /*<<< orphan*/ ) ; 
static  int ts_ACCURACY_print_bio (int /*<<< orphan*/ *,TYPE_4__ const*) ; 
static  int ts_status_map_print (int /*<<< orphan*/ *,struct status_map_st const*,int /*<<< orphan*/  const*) ; 

int TS_RESP_print_bio(BIO *bio, TS_RESP *a)
{
    BIO_printf(bio, "Status info:\n");
    TS_STATUS_INFO_print_bio(bio, a->status_info);

    BIO_printf(bio, "\nTST info:\n");
    if (a->tst_info != NULL)
        TS_TST_INFO_print_bio(bio, a->tst_info);
    else
        BIO_printf(bio, "Not included.\n");

    return 1;
}

int TS_STATUS_INFO_print_bio(BIO *bio, TS_STATUS_INFO *a)
{
    static const char *status_map[] = {
        "Granted.",
        "Granted with modifications.",
        "Rejected.",
        "Waiting.",
        "Revocation warning.",
        "Revoked."
    };
    static const struct status_map_st failure_map[] = {
        {TS_INFO_BAD_ALG,
         "unrecognized or unsupported algorithm identifier"},
        {TS_INFO_BAD_REQUEST,
         "transaction not permitted or supported"},
        {TS_INFO_BAD_DATA_FORMAT,
         "the data submitted has the wrong format"},
        {TS_INFO_TIME_NOT_AVAILABLE,
         "the TSA's time source is not available"},
        {TS_INFO_UNACCEPTED_POLICY,
         "the requested TSA policy is not supported by the TSA"},
        {TS_INFO_UNACCEPTED_EXTENSION,
         "the requested extension is not supported by the TSA"},
        {TS_INFO_ADD_INFO_NOT_AVAILABLE,
         "the additional information requested could not be understood "
         "or is not available"},
        {TS_INFO_SYSTEM_FAILURE,
         "the request cannot be handled due to system failure"},
        {-1, NULL}
    };
    long status;
    int i, lines = 0;

    BIO_printf(bio, "Status: ");
    status = ASN1_INTEGER_get(a->status);
    if (0 <= status && status < (long)OSSL_NELEM(status_map))
        BIO_printf(bio, "%s\n", status_map[status]);
    else
        BIO_printf(bio, "out of bounds\n");

    BIO_printf(bio, "Status description: ");
    for (i = 0; i < sk_ASN1_UTF8STRING_num(a->text); ++i) {
        if (i > 0)
            BIO_puts(bio, "\t");
        ASN1_STRING_print_ex(bio, sk_ASN1_UTF8STRING_value(a->text, i), 0);
        BIO_puts(bio, "\n");
    }
    if (i == 0)
        BIO_printf(bio, "unspecified\n");

    BIO_printf(bio, "Failure info: ");
    if (a->failure_info != NULL)
        lines = ts_status_map_print(bio, failure_map, a->failure_info);
    if (lines == 0)
        BIO_printf(bio, "unspecified");
    BIO_printf(bio, "\n");

    return 1;
}

__attribute__((used)) static int ts_status_map_print(BIO *bio, const struct status_map_st *a,
                               const ASN1_BIT_STRING *v)
{
    int lines = 0;

    for (; a->bit >= 0; ++a) {
        if (ASN1_BIT_STRING_get_bit(v, a->bit)) {
            if (++lines > 1)
                BIO_printf(bio, ", ");
            BIO_printf(bio, "%s", a->text);
        }
    }

    return lines;
}

int TS_TST_INFO_print_bio(BIO *bio, TS_TST_INFO *a)
{
    int v;

    if (a == NULL)
        return 0;

    v = ASN1_INTEGER_get(a->version);
    BIO_printf(bio, "Version: %d\n", v);

    BIO_printf(bio, "Policy OID: ");
    TS_OBJ_print_bio(bio, a->policy_id);

    TS_MSG_IMPRINT_print_bio(bio, a->msg_imprint);

    BIO_printf(bio, "Serial number: ");
    if (a->serial == NULL)
        BIO_printf(bio, "unspecified");
    else
        TS_ASN1_INTEGER_print_bio(bio, a->serial);
    BIO_write(bio, "\n", 1);

    BIO_printf(bio, "Time stamp: ");
    ASN1_GENERALIZEDTIME_print(bio, a->time);
    BIO_write(bio, "\n", 1);

    BIO_printf(bio, "Accuracy: ");
    if (a->accuracy == NULL)
        BIO_printf(bio, "unspecified");
    else
        ts_ACCURACY_print_bio(bio, a->accuracy);
    BIO_write(bio, "\n", 1);

    BIO_printf(bio, "Ordering: %s\n", a->ordering ? "yes" : "no");

    BIO_printf(bio, "Nonce: ");
    if (a->nonce == NULL)
        BIO_printf(bio, "unspecified");
    else
        TS_ASN1_INTEGER_print_bio(bio, a->nonce);
    BIO_write(bio, "\n", 1);

    BIO_printf(bio, "TSA: ");
    if (a->tsa == NULL)
        BIO_printf(bio, "unspecified");
    else {
        STACK_OF(CONF_VALUE) *nval;
        if ((nval = i2v_GENERAL_NAME(NULL, a->tsa, NULL)))
            X509V3_EXT_val_prn(bio, nval, 0, 0);
        sk_CONF_VALUE_pop_free(nval, X509V3_conf_free);
    }
    BIO_write(bio, "\n", 1);

    TS_ext_print_bio(bio, a->extensions);

    return 1;
}

__attribute__((used)) static int ts_ACCURACY_print_bio(BIO *bio, const TS_ACCURACY *a)
{
    if (a->seconds != NULL)
        TS_ASN1_INTEGER_print_bio(bio, a->seconds);
    else
        BIO_printf(bio, "unspecified");
    BIO_printf(bio, " seconds, ");
    if (a->millis != NULL)
        TS_ASN1_INTEGER_print_bio(bio, a->millis);
    else
        BIO_printf(bio, "unspecified");
    BIO_printf(bio, " millis, ");
    if (a->micros != NULL)
        TS_ASN1_INTEGER_print_bio(bio, a->micros);
    else
        BIO_printf(bio, "unspecified");
    BIO_printf(bio, " micros");

    return 1;
}

