#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASN1_parse_dump (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BIO_new_file (char*,char*) ; 
 int /*<<< orphan*/  CRYPTO_free_ex_index (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ERR_clear_error () ; 
 int /*<<< orphan*/  ERR_get_state () ; 
 int /*<<< orphan*/  OPENSSL_INIT_LOAD_CRYPTO_STRINGS ; 
 int /*<<< orphan*/  OPENSSL_init_crypto (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bio_out ; 

int FuzzerInitialize(int *argc, char ***argv)
{
    bio_out = BIO_new_file("/dev/null", "w");
    OPENSSL_init_crypto(OPENSSL_INIT_LOAD_CRYPTO_STRINGS, NULL);
    ERR_get_state();
    CRYPTO_free_ex_index(0, -1);
    return 1;
}

int FuzzerTestOneInput(const uint8_t *buf, size_t len)
{
    (void)ASN1_parse_dump(bio_out, buf, len, 0, 0);
    ERR_clear_error();
    return 0;
}

void FuzzerCleanup(void)
{
    BIO_free(bio_out);
}

