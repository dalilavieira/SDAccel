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

/* Variables and functions */
 size_t crypto_stream_salsa208_KEYBYTES ; 
 size_t crypto_stream_salsa208_MESSAGEBYTES_MAX ; 
 size_t crypto_stream_salsa208_NONCEBYTES ; 
 int /*<<< orphan*/  randombytes_buf (unsigned char*,size_t) ; 

size_t
crypto_stream_salsa208_keybytes(void)
{
    return crypto_stream_salsa208_KEYBYTES;
}

size_t
crypto_stream_salsa208_noncebytes(void)
{
    return crypto_stream_salsa208_NONCEBYTES;
}

size_t
crypto_stream_salsa208_messagebytes_max(void)
{
    return crypto_stream_salsa208_MESSAGEBYTES_MAX;
}

void
crypto_stream_salsa208_keygen(unsigned char k[crypto_stream_salsa208_KEYBYTES])
{
    randombytes_buf(k, crypto_stream_salsa208_KEYBYTES);
}

