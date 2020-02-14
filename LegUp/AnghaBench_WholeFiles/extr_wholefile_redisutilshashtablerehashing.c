#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  key ;
struct TYPE_13__ {int size; scalar_t__* table; } ;
typedef  TYPE_1__ dictht ;
typedef  int /*<<< orphan*/  dictEntry ;
struct TYPE_14__ {int rehashidx; TYPE_1__* ht; } ;
typedef  TYPE_2__ dict ;

/* Variables and functions */
 unsigned long MAX1 ; 
 unsigned long MAX2 ; 
 int /*<<< orphan*/  dictAdd (TYPE_2__*,void*,int /*<<< orphan*/ *) ; 
 TYPE_2__* dictCreate (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dictDelete (TYPE_2__*,void*) ; 
 unsigned long dictGenHashFunction (unsigned long*,int) ; 
 int dictGetSomeKeys (TYPE_2__*,int /*<<< orphan*/ **,int) ; 
 int /*<<< orphan*/  dictRelease (TYPE_2__*) ; 
 int /*<<< orphan*/  dictResize (TYPE_2__*) ; 
 int dictSize (TYPE_2__*) ; 
 int /*<<< orphan*/  dictTypeTest ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  qsort (int /*<<< orphan*/ **,int,int,int (*) (void const*,void const*)) ; 
 int rand () ; 
 int /*<<< orphan*/  srand (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  time (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  zfree (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/ ** zmalloc (int) ; 

void _redisAssert(char *x, char *y, int l) {
    printf("ASSERT: %s %s %d\n",x,y,l);
    exit(1);
}

unsigned int dictKeyHash(const void *keyp) {
    unsigned long key = (unsigned long)keyp;
    key = dictGenHashFunction(&key,sizeof(key));
    key += ~(key << 15);
    key ^=  (key >> 10);
    key +=  (key << 3);
    key ^=  (key >> 6);
    key += ~(key << 11);
    key ^=  (key >> 16);
    return key;
}

int dictKeyCompare(void *privdata, const void *key1, const void *key2) {
    unsigned long k1 = (unsigned long)key1;
    unsigned long k2 = (unsigned long)key2;
    return k1 == k2;
}

void showBuckets(dictht ht) {
    if (ht.table == NULL) {
        printf("NULL\n");
    } else {
        int j;
        for (j = 0; j < ht.size; j++) {
            printf("%c", ht.table[j] ? '1' : '0');
        }
        printf("\n");
    }
}

void show(dict *d) {
    int j;
    if (d->rehashidx != -1) {
        printf("rhidx: ");
        for (j = 0; j < d->rehashidx; j++)
            printf(".");
        printf("|\n");
    }
    printf("ht[0]: ");
    showBuckets(d->ht[0]);
    printf("ht[1]: ");
    showBuckets(d->ht[1]);
    printf("\n");
}

int sortPointers(const void *a, const void *b) {
    unsigned long la, lb;

    la = (long) (*((dictEntry**)a));
    lb = (long) (*((dictEntry**)b));
    return la-lb;
}

void stressGetKeys(dict *d, int times, int *perfect_run, int *approx_run) {
    int j;

    dictEntry **des = zmalloc(sizeof(dictEntry*)*dictSize(d));
    for (j = 0; j < times; j++) {
        int requested = rand() % (dictSize(d)+1);
        int returned = dictGetSomeKeys(d, des, requested);
        int dup = 0;

        qsort(des,returned,sizeof(dictEntry*),sortPointers);
        if (returned > 1) {
            int i;
            for (i = 0; i < returned-1; i++) {
                if (des[i] == des[i+1]) dup++;
            }
        }

        if (requested == returned && dup == 0) {
            (*perfect_run)++;
        } else {
            (*approx_run)++;
            printf("Requested, returned, duplicated: %d %d %d\n",
                requested, returned, dup);
        }
    }
    zfree(des);
}

int main(void) {
    dict *d = dictCreate(&dictTypeTest,NULL);
    unsigned long i;
    srand(time(NULL));

    for (i = 0; i < MAX1; i++) {
        dictAdd(d,(void*)i,NULL);
        show(d);
    }
    printf("Size: %d\n", (int)dictSize(d));

    for (i = 0; i < MAX1; i++) {
        dictDelete(d,(void*)i);
        dictResize(d);
        show(d);
    }
    dictRelease(d);

    d = dictCreate(&dictTypeTest,NULL);

    printf("Stress testing dictGetSomeKeys\n");
    int perfect_run = 0, approx_run = 0;

    for (i = 0; i < MAX2; i++) {
        dictAdd(d,(void*)i,NULL);
        stressGetKeys(d,100,&perfect_run,&approx_run);
    }

    for (i = 0; i < MAX2; i++) {
        dictDelete(d,(void*)i);
        dictResize(d);
        stressGetKeys(d,100,&perfect_run,&approx_run);
    }

    printf("dictGetSomeKey, %d perfect runs, %d approximated runs\n",
        perfect_run, approx_run);

    dictRelease(d);

    printf("TEST PASSED!\n");
    return 0;
}

