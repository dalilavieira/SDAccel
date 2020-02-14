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
typedef  int uint32_t ;
struct timeval {int tv_sec; unsigned long long tv_usec; } ;
struct TYPE_2__ {char* name; char* value; int hash; void** collected9; void** collected8; } ;
typedef  int /*<<< orphan*/  ARL_BASE ;

/* Variables and functions */
 void* active_anon_hash ; 
 void* active_file_hash ; 
 int /*<<< orphan*/  arl_begin (int /*<<< orphan*/ *) ; 
 scalar_t__ arl_check (int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/ * arl_create (char*,void (*) (char const*,int,char const*,void*),int) ; 
 int /*<<< orphan*/  arl_expect_custom (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int cache_hash ; 
 unsigned long long clk ; 
 int dirty_hash ; 
 int /*<<< orphan*/  exit (int) ; 
 int gettimeofday (struct timeval*,int /*<<< orphan*/ *) ; 
 void* hierarchical_memory_limit_hash ; 
 void* inactive_anon_hash ; 
 void* inactive_file_hash ; 
 int mapped_file_hash ; 
 TYPE_1__* pairs ; 
 int pgfault_hash ; 
 int pgmajfault_hash ; 
 int pgpgin_hash ; 
 int pgpgout_hash ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int rss_hash ; 
 int rss_huge_hash ; 
 void* simple_hash (char const*) ; 
 void* str2ull (char const*) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 void* strtoull (char const*,int /*<<< orphan*/ *,int) ; 
 int swap_hash ; 
 void* total_active_anon_hash ; 
 void* total_active_file_hash ; 
 void* total_cache_hash ; 
 void* total_dirty_hash ; 
 void* total_inactive_anon_hash ; 
 void* total_inactive_file_hash ; 
 void* total_mapped_file_hash ; 
 void* total_pgfault_hash ; 
 void* total_pgmajfault_hash ; 
 void* total_pgpgin_hash ; 
 void* total_pgpgout_hash ; 
 void* total_rss_hash ; 
 void* total_rss_huge_hash ; 
 void* total_swap_hash ; 
 void* total_unevictable_hash ; 
 void* total_writeback_hash ; 
 void* unevictable_hash ; 
 scalar_t__ unlikely (int) ; 
 void** values1 ; 
 void** values2 ; 
 void** values3 ; 
 void** values4 ; 
 unsigned long long* values5 ; 
 int /*<<< orphan*/ * values6 ; 
 int /*<<< orphan*/ * values7 ; 
 int /*<<< orphan*/ * values8 ; 
 int /*<<< orphan*/ * values9 ; 
 int writeback_hash ; 

void netdata_cleanup_and_exit(int ret) {
    exit(ret);
}

__attribute__((used)) static inline uint32_t simple_hash2(const char *name) {
    register unsigned char *s = (unsigned char *)name;
    register uint32_t hval = 0x811c9dc5;
    while (*s) {
        hval *= 16777619;
        hval ^= (uint32_t) *s++;
    }
    return hval;
}

__attribute__((used)) static inline unsigned long long fast_strtoull(const char *s) {
  register unsigned long long n = 0;
  register char c;
  for(c = *s; c >= '0' && c <= '9' ; c = *(++s)) {
    n *= 10;
    n += c - '0';
    // n = (n << 1) + (n << 3) + (c - '0');
  }
  return n;
}

void test1() {
  int i;
  for(i = 0; pairs[i].name ; i++) {
    const char *s = pairs[i].name;
    const char *v = pairs[i].value;

    if(unlikely(!strcmp(s, "cache")))
      values1[i] = strtoull(v, NULL, 10);

    else if(unlikely(!strcmp(s, "rss")))
      values1[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(!strcmp(s, "rss_huge")))
      values1[i] = strtoull(v, NULL, 10);
  
    else if(unlikely(!strcmp(s, "mapped_file")))
      values1[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(!strcmp(s, "writeback")))
      values1[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(!strcmp(s, "dirty")))
      values1[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(!strcmp(s, "swap")))
      values1[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(!strcmp(s, "pgpgin")))
      values1[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(!strcmp(s, "pgpgout")))
      values1[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(!strcmp(s, "pgfault")))
      values1[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(!strcmp(s, "pgmajfault")))
      values1[i] = strtoull(v, NULL, 10);
  }
}

void test2() {
    int i;
    for(i = 0; pairs[i].name ; i++) {
        const char *s = pairs[i].name;
        const char *v = pairs[i].value;

    uint32_t hash = simple_hash2(s);

    if(unlikely(hash == cache_hash && !strcmp(s, "cache")))
      values2[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == rss_hash && !strcmp(s, "rss")))
      values2[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == rss_huge_hash && !strcmp(s, "rss_huge")))
      values2[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == mapped_file_hash && !strcmp(s, "mapped_file")))
      values2[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == writeback_hash && !strcmp(s, "writeback")))
      values2[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == dirty_hash && !strcmp(s, "dirty")))
      values2[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == swap_hash && !strcmp(s, "swap")))
      values2[i] = strtoull(v, NULL, 10);
  
    else if(unlikely(hash == pgpgin_hash && !strcmp(s, "pgpgin")))
      values2[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == pgpgout_hash && !strcmp(s, "pgpgout")))
      values2[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == pgfault_hash && !strcmp(s, "pgfault")))
      values2[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == pgmajfault_hash && !strcmp(s, "pgmajfault")))
      values2[i] = strtoull(v, NULL, 10);
  }
}

void test3() {
    int i;
    for(i = 0; pairs[i].name ; i++) {
        const char *s = pairs[i].name;
        const char *v = pairs[i].value;

    uint32_t hash = simple_hash(s);

    if(unlikely(hash == cache_hash && !strcmp(s, "cache")))
      values3[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == rss_hash && !strcmp(s, "rss")))
      values3[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == rss_huge_hash && !strcmp(s, "rss_huge")))
      values3[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == mapped_file_hash && !strcmp(s, "mapped_file")))
      values3[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == writeback_hash && !strcmp(s, "writeback")))
      values3[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == dirty_hash && !strcmp(s, "dirty")))
      values3[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == swap_hash && !strcmp(s, "swap")))
      values3[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == pgpgin_hash && !strcmp(s, "pgpgin")))
      values3[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == pgpgout_hash && !strcmp(s, "pgpgout")))
      values3[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == pgfault_hash && !strcmp(s, "pgfault")))
      values3[i] = strtoull(v, NULL, 10);
    
    else if(unlikely(hash == pgmajfault_hash && !strcmp(s, "pgmajfault")))
      values3[i] = strtoull(v, NULL, 10);
  }
}

void test4() {
    int i;
    for(i = 0; pairs[i].name ; i++) {
        const char *s = pairs[i].name;
        const char *v = pairs[i].value;

    uint32_t hash = simple_hash2(s);

    if(unlikely(hash == cache_hash && !strcmp(s, "cache"))) {
      values4[i] = strtoull(v, NULL, 0);
      continue;
    }

    if(unlikely(hash == rss_hash && !strcmp(s, "rss"))) {
      values4[i] = strtoull(v, NULL, 0);
      continue;
    }
    
    if(unlikely(hash == rss_huge_hash && !strcmp(s, "rss_huge"))) {
      values4[i] = strtoull(v, NULL, 0);
      continue;
    }
    
    if(unlikely(hash == mapped_file_hash && !strcmp(s, "mapped_file"))) {
      values4[i] = strtoull(v, NULL, 0);
      continue;
    }
    
    if(unlikely(hash == writeback_hash && !strcmp(s, "writeback"))) {
      values4[i] = strtoull(v, NULL, 0);
      continue;
    }
    
    if(unlikely(hash == dirty_hash && !strcmp(s, "dirty"))) {
      values4[i] = strtoull(v, NULL, 0);
      continue;
    }
    
    if(unlikely(hash == swap_hash && !strcmp(s, "swap"))) {
      values4[i] = strtoull(v, NULL, 0);
      continue;
    }
    
    if(unlikely(hash == pgpgin_hash && !strcmp(s, "pgpgin"))) {
      values4[i] = strtoull(v, NULL, 0);
      continue;
    }
    
    if(unlikely(hash == pgpgout_hash && !strcmp(s, "pgpgout"))) {
      values4[i] = strtoull(v, NULL, 0);
      continue;
    }
    
    if(unlikely(hash == pgfault_hash && !strcmp(s, "pgfault"))) {
      values4[i] = strtoull(v, NULL, 0);
      continue;
    }
    
    if(unlikely(hash == pgmajfault_hash && !strcmp(s, "pgmajfault"))) {
      values4[i] = strtoull(v, NULL, 0);
      continue;
    }
  }
}

void test5() {
    int i;
    for(i = 0; pairs[i].name ; i++) {
        const char *s = pairs[i].name;
        const char *v = pairs[i].value;

    uint32_t hash = simple_hash2(s);

    if(unlikely(hash == cache_hash && !strcmp(s, "cache")))
      values5[i] = fast_strtoull(v);
    
    else if(unlikely(hash == rss_hash && !strcmp(s, "rss")))
      values5[i] = fast_strtoull(v);
    
    else if(unlikely(hash == rss_huge_hash && !strcmp(s, "rss_huge")))
      values5[i] = fast_strtoull(v);
    
    else if(unlikely(hash == mapped_file_hash && !strcmp(s, "mapped_file")))
      values5[i] = fast_strtoull(v);
    
    else if(unlikely(hash == writeback_hash && !strcmp(s, "writeback")))
      values5[i] = fast_strtoull(v);
    
    else if(unlikely(hash == dirty_hash && !strcmp(s, "dirty")))
      values5[i] = fast_strtoull(v);
    
    else if(unlikely(hash == swap_hash && !strcmp(s, "swap")))
      values5[i] = fast_strtoull(v);
  
    else if(unlikely(hash == pgpgin_hash && !strcmp(s, "pgpgin")))
      values5[i] = fast_strtoull(v);
    
    else if(unlikely(hash == pgpgout_hash && !strcmp(s, "pgpgout")))
      values5[i] = fast_strtoull(v);
    
    else if(unlikely(hash == pgfault_hash && !strcmp(s, "pgfault")))
      values5[i] = fast_strtoull(v);
    
    else if(unlikely(hash == pgmajfault_hash && !strcmp(s, "pgmajfault")))
      values5[i] = fast_strtoull(v);
  }
}

void arl_strtoull(const char *name, uint32_t hash, const char *value, void *dst) {
    (void)name;
    (void)hash;

    register unsigned long long *d = dst;
    *d = strtoull(value, NULL, 10);
    // fprintf(stderr, "name '%s' with hash %u and value '%s' is %llu\n", name, hash, value, *d);
}

void test6() {
    static ARL_BASE *base = NULL;

    if(unlikely(!base)) {
        base = arl_create("test6", arl_strtoull, 60);
        arl_expect_custom(base, "cache",       NULL, &values6[0]);
        arl_expect_custom(base, "rss",         NULL, &values6[1]);
        arl_expect_custom(base, "rss_huge",    NULL, &values6[2]);
        arl_expect_custom(base, "mapped_file", NULL, &values6[3]);
        arl_expect_custom(base, "writeback",   NULL, &values6[4]);
        arl_expect_custom(base, "dirty",       NULL, &values6[5]);
        arl_expect_custom(base, "swap",        NULL, &values6[6]);
        arl_expect_custom(base, "pgpgin",      NULL, &values6[7]);
        arl_expect_custom(base, "pgpgout",     NULL, &values6[8]);
        arl_expect_custom(base, "pgfault",     NULL, &values6[9]);
        arl_expect_custom(base, "pgmajfault",  NULL, &values6[10]);
    }

    arl_begin(base);

    int i;
    for(i = 0; pairs[i].name ; i++)
        if(arl_check(base, pairs[i].name, pairs[i].value)) break;
}

void arl_str2ull(const char *name, uint32_t hash, const char *value, void *dst) {
    (void)name;
    (void)hash;

    register unsigned long long *d = dst;
    *d = str2ull(value);
    // fprintf(stderr, "name '%s' with hash %u and value '%s' is %llu\n", name, hash, value, *d);
}

void test7() {
    static ARL_BASE *base = NULL;

    if(unlikely(!base)) {
        base = arl_create("test7", arl_str2ull, 60);
        arl_expect_custom(base, "cache",       NULL, &values7[0]);
        arl_expect_custom(base, "rss",         NULL, &values7[1]);
        arl_expect_custom(base, "rss_huge",    NULL, &values7[2]);
        arl_expect_custom(base, "mapped_file", NULL, &values7[3]);
        arl_expect_custom(base, "writeback",   NULL, &values7[4]);
        arl_expect_custom(base, "dirty",       NULL, &values7[5]);
        arl_expect_custom(base, "swap",        NULL, &values7[6]);
        arl_expect_custom(base, "pgpgin",      NULL, &values7[7]);
        arl_expect_custom(base, "pgpgout",     NULL, &values7[8]);
        arl_expect_custom(base, "pgfault",     NULL, &values7[9]);
        arl_expect_custom(base, "pgmajfault",  NULL, &values7[10]);
    }

    arl_begin(base);

    int i;
    for(i = 0; pairs[i].name ; i++)
        if(arl_check(base, pairs[i].name, pairs[i].value)) break;
}

void test8() {
    int i;
    for(i = 0; pairs[i].name; i++) {
        uint32_t hash = simple_hash(pairs[i].name);

        int j;
        for(j = 0; pairs[j].name; j++) {
            if(hash == pairs[j].hash && !strcmp(pairs[i].name, pairs[j].name)) {
                *pairs[j].collected8 = strtoull(pairs[i].value, NULL, 10);
                break;
            }
        }
    }
}

void test9() {
    int i;
    for(i = 0; pairs[i].name; i++) {
        uint32_t hash = simple_hash(pairs[i].name);

        int j;
        for(j = 0; pairs[j].name; j++) {
            if(hash == pairs[j].hash && !strcmp(pairs[i].name, pairs[j].name)) {
                *pairs[j].collected9 = str2ull(pairs[i].value);
                break;
            }
        }
    }
}

__attribute__((used)) static void begin_clock() {
    struct timeval tv;
    if(unlikely(gettimeofday(&tv, NULL) == -1))
        return;
    clk = tv.tv_sec  * 1000000 + tv.tv_usec;
}

__attribute__((used)) static unsigned long long end_clock() {
    struct timeval tv;
    if(unlikely(gettimeofday(&tv, NULL) == -1))
        return -1;
    return clk = tv.tv_sec  * 1000000 + tv.tv_usec - clk;
}

int main(void)
{
    {
        int i;
        for(i = 0; pairs[i].name; i++)
            pairs[i].hash = simple_hash(pairs[i].name);
    }

    cache_hash = simple_hash("cache");
    rss_hash = simple_hash("rss");
    rss_huge_hash = simple_hash("rss_huge");
    mapped_file_hash = simple_hash("mapped_file");
    writeback_hash = simple_hash("writeback");
    dirty_hash = simple_hash("dirty");
    swap_hash = simple_hash("swap");
    pgpgin_hash = simple_hash("pgpgin");
    pgpgout_hash = simple_hash("pgpgout");
    pgfault_hash = simple_hash("pgfault");
    pgmajfault_hash = simple_hash("pgmajfault");
    inactive_anon_hash = simple_hash("inactive_anon");
    active_anon_hash = simple_hash("active_anon");
    inactive_file_hash = simple_hash("inactive_file");
    active_file_hash = simple_hash("active_file");
    unevictable_hash = simple_hash("unevictable");
    hierarchical_memory_limit_hash = simple_hash("hierarchical_memory_limit");
    total_cache_hash = simple_hash("total_cache");
    total_rss_hash = simple_hash("total_rss");
    total_rss_huge_hash = simple_hash("total_rss_huge");
    total_mapped_file_hash = simple_hash("total_mapped_file");
    total_writeback_hash = simple_hash("total_writeback");
    total_dirty_hash = simple_hash("total_dirty");
    total_swap_hash = simple_hash("total_swap");
    total_pgpgin_hash = simple_hash("total_pgpgin");
    total_pgpgout_hash = simple_hash("total_pgpgout");
    total_pgfault_hash = simple_hash("total_pgfault");
    total_pgmajfault_hash = simple_hash("total_pgmajfault");
    total_inactive_anon_hash = simple_hash("total_inactive_anon");
    total_active_anon_hash = simple_hash("total_active_anon");
    total_inactive_file_hash = simple_hash("total_inactive_file");
    total_active_file_hash = simple_hash("total_active_file");
    total_unevictable_hash = simple_hash("total_unevictable");

    // cache functions
    (void)simple_hash2("hello world");
    (void)strcmp("1", "2");
    (void)strtoull("123", NULL, 0);

  unsigned long i, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0;
  unsigned long max = 1000000;

  begin_clock();
  for(i = 0; i <= max ;i++) test1();
  c1 = end_clock();

  begin_clock();
  for(i = 0; i <= max ;i++) test2();
  c2 = end_clock();
    
  begin_clock();
  for(i = 0; i <= max ;i++) test3();
  c3 = end_clock();

  begin_clock();
  for(i = 0; i <= max ;i++) test4();
  c4 = end_clock();

  begin_clock();
  for(i = 0; i <= max ;i++) test5();
  c5 = end_clock();

    begin_clock();
    for(i = 0; i <= max ;i++) test6();
    c6 = end_clock();

    begin_clock();
    for(i = 0; i <= max ;i++) test7();
    c7 = end_clock();

    begin_clock();
    for(i = 0; i <= max ;i++) test8();
    c8 = end_clock();

    begin_clock();
    for(i = 0; i <= max ;i++) test9();
    c9 = end_clock();

    for(i = 0; i < 11 ; i++)
        printf("value %lu: %llu %llu %llu %llu %llu %llu %llu %llu %llu\n", i, values1[i], values2[i], values3[i], values4[i], values5[i], values6[i], values7[i], values8[i], values9[i]);
  
  printf("\n\nRESULTS\n");
  printf("test1() [1] in %lu usecs: simple system strcmp().\n"
         "test2() [4] in %lu usecs: inline simple_hash() with system strtoull().\n"
         "test3() [5] in %lu usecs: statement expression simple_hash(), system strtoull().\n"
         "test4() [6] in %lu usecs: inline simple_hash(), if-continue checks.\n"
         "test5() [7] in %lu usecs: inline simple_hash(), if-else-if-else-if (netdata default prior to ARL).\n"
         "test6() [8] in %lu usecs: adaptive re-sortable array with strtoull() (wow!)\n"
         "test7() [9] in %lu usecs: adaptive re-sortable array with str2ull() (wow!)\n"
         "test8() [2] in %lu usecs: nested loop with strtoull()\n"
         "test9() [3] in %lu usecs: nested loop with str2ull()\n"
         , c1
         , c2
         , c3
         , c4
         , c5
         , c6
         , c7
         , c8
         , c9
         );

  return 0;
}

