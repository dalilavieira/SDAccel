#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  rd_key; } ;
struct TYPE_7__ {TYPE_1__ u; int /*<<< orphan*/  grand_rounds; } ;
typedef  TYPE_2__ CAMELLIA_KEY ;

/* Variables and functions */
 int /*<<< orphan*/  Camellia_DecryptBlock_Rounds (int /*<<< orphan*/ ,unsigned char const*,int /*<<< orphan*/ ,unsigned char*) ; 
 int /*<<< orphan*/  Camellia_Ekeygen (int const,unsigned char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Camellia_EncryptBlock_Rounds (int /*<<< orphan*/ ,unsigned char const*,int /*<<< orphan*/ ,unsigned char*) ; 

int Camellia_set_key(const unsigned char *userKey, const int bits,
                     CAMELLIA_KEY *key)
{
    if (!userKey || !key)
        return -1;
    if (bits != 128 && bits != 192 && bits != 256)
        return -2;
    key->grand_rounds = Camellia_Ekeygen(bits, userKey, key->u.rd_key);
    return 0;
}

void Camellia_encrypt(const unsigned char *in, unsigned char *out,
                      const CAMELLIA_KEY *key)
{
    Camellia_EncryptBlock_Rounds(key->grand_rounds, in, key->u.rd_key, out);
}

void Camellia_decrypt(const unsigned char *in, unsigned char *out,
                      const CAMELLIA_KEY *key)
{
    Camellia_DecryptBlock_Rounds(key->grand_rounds, in, key->u.rd_key, out);
}

