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
typedef  scalar_t__ uint8_t ;
typedef  int uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  crypto_scalarmult_curve25519_base (scalar_t__*,scalar_t__*) ; 
 int /*<<< orphan*/  free (unsigned char*) ; 
 scalar_t__* malloc (size_t) ; 
 scalar_t__ memcmp (scalar_t__*,scalar_t__*,int) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,unsigned char*,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  randombytes (scalar_t__*,int) ; 
 int /*<<< orphan*/  sscanf (char*,char*,scalar_t__*) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  strncasecmp (char*,char*,int) ; 

uint8_t *hex_string_to_bin(char *hex_string)
{
    // byte is represented by exactly 2 hex digits, so lenth of binary string
    // is half of that of the hex one. only hex string with even length
    // valid. the more proper implementation would be to check if strlen(hex_string)
    // is odd and return error code if it is. we assume strlen is even. if it's not
    // then the last byte just won't be written in 'ret'.
    size_t i, len = strlen(hex_string) / 2;
    uint8_t *ret = malloc(len);
    char *pos = hex_string;

    for (i = 0; i < len; ++i, pos += 2)
        sscanf(pos, "%2hhx", &ret[i]);

    return ret;
}

int cmdline_parsefor_ipv46(int argc, char **argv, uint8_t *ipv6enabled)
{
    int argvoffset = 0, argi;

    for (argi = 1; argi < argc; argi++)
        if (!strncasecmp(argv[argi], "--ipv", 5)) {
            if (argv[argi][5] && !argv[argi][6]) {
                char c = argv[argi][5];

                if (c == '4')
                    *ipv6enabled = 0;
                else if (c == '6')
                    *ipv6enabled = 1;
                else {
                    printf("Invalid argument: %s. Try --ipv4 or --ipv6!\n", argv[argi]);
                    return -1;
                }
            } else {
                printf("Invalid argument: %s. Try --ipv4 or --ipv6!\n", argv[argi]);
                return -1;
            }

            if (argvoffset != argi - 1) {
                printf("Argument must come first: %s.\n", argv[argi]);
                return -1;
            }

            argvoffset++;
        }

    return argvoffset;
}

void print_key(uint8_t *client_id)
{
    uint32_t j;

    for (j = 0; j < 32; j++) {
        printf("%02hhX", client_id[j]);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("usage: ./cracker public_key(or beginning of one in hex format)\n");
        return 0;
    }

    long long unsigned int num_tries = 0;

    uint32_t len = strlen(argv[1]) / 2;
    unsigned char *key = hex_string_to_bin(argv[1]);
    uint8_t pub_key[32], priv_key[32], c_key[32];

    if (len > 32)
        len = 32;

    memcpy(c_key, key, len);
    free(key);
    randombytes(priv_key, 32);

    while (1) {
        crypto_scalarmult_curve25519_base(pub_key, priv_key);
        uint32_t i;

        if (memcmp(c_key, pub_key, len) == 0)
            break;

        for (i = 32; i != 0; --i) {
            priv_key[i - 1] += 1;

            if (priv_key[i - 1] != 0)
                break;
        }

        ++num_tries;
    }

    printf("Public key:\n");
    print_key(pub_key);
    printf("\nPrivate key:\n");
    print_key(priv_key);
    printf("\n %llu keys tried\n", num_tries);
    return 0;
}

