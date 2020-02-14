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
 size_t crypto_core_hsalsa20_CONSTBYTES ; 
 size_t crypto_core_hsalsa20_INPUTBYTES ; 
 size_t crypto_core_hsalsa20_KEYBYTES ; 
 size_t crypto_core_hsalsa20_OUTPUTBYTES ; 

size_t
crypto_core_hsalsa20_outputbytes(void) {
    return crypto_core_hsalsa20_OUTPUTBYTES;
}

size_t
crypto_core_hsalsa20_inputbytes(void) {
    return crypto_core_hsalsa20_INPUTBYTES;
}

size_t
crypto_core_hsalsa20_keybytes(void) {
    return crypto_core_hsalsa20_KEYBYTES;
}

size_t
crypto_core_hsalsa20_constbytes(void) {
    return crypto_core_hsalsa20_CONSTBYTES;
}

