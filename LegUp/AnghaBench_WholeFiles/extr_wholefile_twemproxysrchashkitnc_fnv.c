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
typedef  scalar_t__ uint64_t ;
typedef  int /*<<< orphan*/  uint32_t ;

/* Variables and functions */
 int /*<<< orphan*/  FNV_32_INIT ; 
 int /*<<< orphan*/  FNV_32_PRIME ; 
 scalar_t__ FNV_64_INIT ; 
 scalar_t__ FNV_64_PRIME ; 

uint32_t
hash_fnv1_64(const char *key, size_t key_length)
{
    uint64_t hash = FNV_64_INIT;
    size_t x;

    for (x = 0; x < key_length; x++) {
      hash *= FNV_64_PRIME;
      hash ^= (uint64_t)key[x];
    }

    return (uint32_t)hash;
}

uint32_t
hash_fnv1a_64(const char *key, size_t key_length)
{
    uint32_t hash = (uint32_t) FNV_64_INIT;
    size_t x;

    for (x = 0; x < key_length; x++) {
      uint32_t val = (uint32_t)key[x];
      hash ^= val;
      hash *= (uint32_t) FNV_64_PRIME;
    }

    return hash;
}

uint32_t
hash_fnv1_32(const char *key, size_t key_length)
{
    uint32_t hash = FNV_32_INIT;
    size_t x;

    for (x = 0; x < key_length; x++) {
      uint32_t val = (uint32_t)key[x];
      hash *= FNV_32_PRIME;
      hash ^= val;
    }

    return hash;
}

uint32_t
hash_fnv1a_32(const char *key, size_t key_length)
{
    uint32_t hash = FNV_32_INIT;
    size_t x;

    for (x= 0; x < key_length; x++) {
      uint32_t val = (uint32_t)key[x];
      hash ^= val;
      hash *= FNV_32_PRIME;
    }

    return hash;
}

