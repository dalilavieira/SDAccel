#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tmpbuf ;
struct TYPE_10__ {char* key; char* value; } ;
struct TYPE_9__ {char* fp; char const* test_file; char* key; scalar_t__ numpairs; char* buff; TYPE_2__* pairs; int /*<<< orphan*/  curr; int /*<<< orphan*/  start; int /*<<< orphan*/  numskip; int /*<<< orphan*/  errors; int /*<<< orphan*/  numtests; } ;
typedef  TYPE_1__ STANZA ;
typedef  TYPE_2__ PAIR ;

/* Variables and functions */
 int /*<<< orphan*/  BIO_free (char*) ; 
 scalar_t__ BIO_gets (char*,char*,int) ; 
 char* BIO_new (int /*<<< orphan*/ ) ; 
 char* BIO_new_file (char const*,char*) ; 
 int /*<<< orphan*/  BIO_puts (char*,char*) ; 
 int /*<<< orphan*/  BIO_reset (char*) ; 
 int /*<<< orphan*/  BIO_s_mem () ; 
 int /*<<< orphan*/  OPENSSL_free (char*) ; 
 char* OPENSSL_strdup (char const*) ; 
 int /*<<< orphan*/  TESTMAXPAIRS ; 
 int /*<<< orphan*/  TEST_error (char*) ; 
 int /*<<< orphan*/  TEST_info (char*,char const*,...) ; 
 int /*<<< orphan*/  TEST_int_gt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TEST_int_lt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TEST_ptr (char*) ; 
 scalar_t__ isspace (unsigned char) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  set_test_title (char const*) ; 
 char* strchr (char*,char) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int strlen (char*) ; 
 scalar_t__ strncmp (char*,char*,int) ; 

int test_start_file(STANZA *s, const char *testfile)
{
    TEST_info("Reading %s", testfile);
    set_test_title(testfile);
    memset(s, 0, sizeof(*s));
    if (!TEST_ptr(s->fp = BIO_new_file(testfile, "r")))
        return 0;
    s->test_file = testfile;
    return 1;
}

int test_end_file(STANZA *s)
{
    TEST_info("Completed %d tests with %d errors and %d skipped",
              s->numtests, s->errors, s->numskip);
    BIO_free(s->fp);
    return 1;
}

__attribute__((used)) static int read_key(STANZA *s)
{
    char tmpbuf[128];

    if (s->key == NULL) {
        if (!TEST_ptr(s->key = BIO_new(BIO_s_mem())))
            return 0;
    } else if (!TEST_int_gt(BIO_reset(s->key), 0)) {
        return 0;
    }

    /* Read to PEM end line and place content in memory BIO */
    while (BIO_gets(s->fp, tmpbuf, sizeof(tmpbuf))) {
        s->curr++;
        if (!TEST_int_gt(BIO_puts(s->key, tmpbuf), 0))
            return 0;
        if (strncmp(tmpbuf, "-----END", 8) == 0)
            return 1;
    }
    TEST_error("Can't find key end");
    return 0;
}

__attribute__((used)) static char *strip_spaces(char *p)
{
    char *q;

    /* Skip over leading spaces */
    while (*p && isspace((unsigned char)*p))
        p++;
    if (!*p)
        return NULL;

    for (q = p + strlen(p) - 1; q != p && isspace((unsigned char)*q); )
        *q-- = '\0';
    return *p ? p : NULL;
}

int test_readstanza(STANZA *s)
{
    PAIR *pp = s->pairs;
    char *p, *equals, *key;
    const char *value;

    for (s->numpairs = 0; BIO_gets(s->fp, s->buff, sizeof(s->buff)); ) {
        s->curr++;
        if (!TEST_ptr(p = strchr(s->buff, '\n'))) {
            TEST_info("Line %d too long", s->curr);
            return 0;
        }
        *p = '\0';

        /* Blank line marks end of tests. */
        if (s->buff[0] == '\0')
            break;

        /* Lines starting with a pound sign are ignored. */
        if (s->buff[0] == '#')
            continue;

        /* Parse into key=value */
        if (!TEST_ptr(equals = strchr(s->buff, '='))) {
            TEST_info("Missing = at line %d\n", s->curr);
            return 0;
        }
        *equals++ = '\0';
        if (!TEST_ptr(key = strip_spaces(s->buff))) {
            TEST_info("Empty field at line %d\n", s->curr);
            return 0;
        }
        if ((value = strip_spaces(equals)) == NULL)
            value = "";

        if (strcmp(key, "Title") == 0) {
            TEST_info("Starting \"%s\" tests at line %d", value, s->curr);
            continue;
        }

        if (s->numpairs == 0)
            s->start = s->curr;

        if (strcmp(key, "PrivateKey") == 0) {
            if (!read_key(s))
                return 0;
        }
        if (strcmp(key, "PublicKey") == 0) {
            if (!read_key(s))
                return 0;
        }

        if (!TEST_int_lt(s->numpairs++, TESTMAXPAIRS)
                || !TEST_ptr(pp->key = OPENSSL_strdup(key))
                || !TEST_ptr(pp->value = OPENSSL_strdup(value)))
            return 0;
        pp++;
    }

    /* If we read anything, return ok. */
    return 1;
}

void test_clearstanza(STANZA *s)
{
    PAIR *pp = s->pairs;
    int i = s->numpairs;

    for ( ; --i >= 0; pp++) {
        OPENSSL_free(pp->key);
        OPENSSL_free(pp->value);
    }
    s->numpairs = 0;
}

