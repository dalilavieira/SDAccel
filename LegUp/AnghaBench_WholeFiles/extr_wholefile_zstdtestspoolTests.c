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
typedef  int /*<<< orphan*/  test ;
struct data {unsigned int* data; size_t i; scalar_t__ val; scalar_t__ max; scalar_t__ countdown; int /*<<< orphan*/  mut; int /*<<< orphan*/  cond; int /*<<< orphan*/  mutex; } ;
typedef  struct data poolTest_t ;
typedef  struct data abruptEndCanary_t ;
typedef  int /*<<< orphan*/  POOL_ctx ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT_EQ (size_t,int const) ; 
 int /*<<< orphan*/  ASSERT_FALSE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ASSERT_TRUE (int /*<<< orphan*/ * const) ; 
 int /*<<< orphan*/  POOL_add (int /*<<< orphan*/ * const,void (*) (void*),struct data*) ; 
 int /*<<< orphan*/ * POOL_create (int,int const) ; 
 int /*<<< orphan*/  POOL_free (int /*<<< orphan*/ * const) ; 
 size_t POOL_resize (int /*<<< orphan*/ * const,int) ; 
 int /*<<< orphan*/  UTIL_sleepMilli (int) ; 
 int /*<<< orphan*/  ZSTD_pthread_cond_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZSTD_pthread_cond_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZSTD_pthread_cond_signal (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZSTD_pthread_cond_wait (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZSTD_pthread_mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZSTD_pthread_mutex_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZSTD_pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ZSTD_pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (struct data*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 

__attribute__((used)) static void fn(void *opaque)
{
  struct data *data = (struct data *)opaque;
  ZSTD_pthread_mutex_lock(&data->mutex);
  data->data[data->i] = (unsigned)(data->i);
  ++data->i;
  ZSTD_pthread_mutex_unlock(&data->mutex);
}

__attribute__((used)) static int testOrder(size_t numThreads, size_t queueSize)
{
  struct data data;
  POOL_ctx* const ctx = POOL_create(numThreads, queueSize);
  ASSERT_TRUE(ctx);
  data.i = 0;
  (void)ZSTD_pthread_mutex_init(&data.mutex, NULL);
  { size_t i;
    for (i = 0; i < 16; ++i) {
      POOL_add(ctx, &fn, &data);
    }
  }
  POOL_free(ctx);
  ASSERT_EQ(16, data.i);
  { size_t i;
    for (i = 0; i < data.i; ++i) {
      ASSERT_EQ(i, data.data[i]);
    }
  }
  ZSTD_pthread_mutex_destroy(&data.mutex);
  return 0;
}

__attribute__((used)) static void waitFn(void *opaque) {
  (void)opaque;
  UTIL_sleepMilli(1);
}

__attribute__((used)) static int testWait(size_t numThreads, size_t queueSize) {
  struct data data;
  POOL_ctx* const ctx = POOL_create(numThreads, queueSize);
  ASSERT_TRUE(ctx);
  { size_t i;
    for (i = 0; i < 16; ++i) {
        POOL_add(ctx, &waitFn, &data);
    }
  }
  POOL_free(ctx);
  return 0;
}

__attribute__((used)) static void waitLongFn(void *opaque) {
  poolTest_t* const test = (poolTest_t*) opaque;
  ZSTD_pthread_mutex_lock(&test->mut);
  test->val++;
  if (test->val > test->max)
      test->max = test->val;
  ZSTD_pthread_mutex_unlock(&test->mut);

  UTIL_sleepMilli(10);

  ZSTD_pthread_mutex_lock(&test->mut);
  test->val--;
  test->countdown--;
  if (test->countdown == 0)
      ZSTD_pthread_cond_signal(&test->cond);
  ZSTD_pthread_mutex_unlock(&test->mut);
}

__attribute__((used)) static int testThreadReduction_internal(POOL_ctx* ctx, poolTest_t test)
{
    int const nbWaits = 16;

    test.countdown = nbWaits;
    test.val = 0;
    test.max = 0;

    {   int i;
        for (i=0; i<nbWaits; i++)
            POOL_add(ctx, &waitLongFn, &test);
    }
    ZSTD_pthread_mutex_lock(&test.mut);
    while (test.countdown > 0)
        ZSTD_pthread_cond_wait(&test.cond, &test.mut);
    ASSERT_EQ(test.val, 0);
    ASSERT_EQ(test.max, 4);
    ZSTD_pthread_mutex_unlock(&test.mut);

    ASSERT_EQ( POOL_resize(ctx, 2/*nbThreads*/) , 0 );
    test.countdown = nbWaits;
    test.val = 0;
    test.max = 0;
    {   int i;
        for (i=0; i<nbWaits; i++)
            POOL_add(ctx, &waitLongFn, &test);
    }
    ZSTD_pthread_mutex_lock(&test.mut);
    while (test.countdown > 0)
        ZSTD_pthread_cond_wait(&test.cond, &test.mut);
    ASSERT_EQ(test.val, 0);
    ASSERT_EQ(test.max, 2);
    ZSTD_pthread_mutex_unlock(&test.mut);

    return 0;
}

__attribute__((used)) static int testThreadReduction(void) {
    int result;
    poolTest_t test;
    POOL_ctx* const ctx = POOL_create(4 /*nbThreads*/, 2 /*queueSize*/);

    ASSERT_TRUE(ctx);

    memset(&test, 0, sizeof(test));
    ASSERT_FALSE( ZSTD_pthread_mutex_init(&test.mut, NULL) );
    ASSERT_FALSE( ZSTD_pthread_cond_init(&test.cond, NULL) );

    result = testThreadReduction_internal(ctx, test);

    ZSTD_pthread_mutex_destroy(&test.mut);
    ZSTD_pthread_cond_destroy(&test.cond);
    POOL_free(ctx);

    return result;
}

__attribute__((used)) static void waitIncFn(void *opaque) {
  abruptEndCanary_t* test = (abruptEndCanary_t*) opaque;
  UTIL_sleepMilli(10);
  ZSTD_pthread_mutex_lock(&test->mut);
  test->val = test->val + 1;
  ZSTD_pthread_mutex_unlock(&test->mut);
}

__attribute__((used)) static int testAbruptEnding_internal(abruptEndCanary_t test)
{
    int const nbWaits = 16;

    POOL_ctx* const ctx = POOL_create(3 /*numThreads*/, nbWaits /*queueSize*/);
    ASSERT_TRUE(ctx);
    test.val = 0;

    {   int i;
        for (i=0; i<nbWaits; i++)
            POOL_add(ctx, &waitIncFn, &test);  /* all jobs pushed into queue */
    }
    ASSERT_EQ( POOL_resize(ctx, 1 /*numThreads*/) , 0 );   /* downsize numThreads, to try to break end condition */

    POOL_free(ctx);  /* must finish all jobs in queue before giving back control */
    ASSERT_EQ(test.val, nbWaits);
    return 0;
}

__attribute__((used)) static int testAbruptEnding(void) {
    int result;
    abruptEndCanary_t test;

    memset(&test, 0, sizeof(test));
    ASSERT_FALSE( ZSTD_pthread_mutex_init(&test.mut, NULL) );

    result = testAbruptEnding_internal(test);

    ZSTD_pthread_mutex_destroy(&test.mut);
    return result;
}

int main(int argc, const char **argv) {
  size_t numThreads;
  (void)argc;
  (void)argv;

  if (POOL_create(0, 1)) {   /* should not be possible */
    printf("FAIL: should not create POOL with 0 threads\n");
    return 1;
  }

  for (numThreads = 1; numThreads <= 4; ++numThreads) {
    size_t queueSize;
    for (queueSize = 0; queueSize <= 2; ++queueSize) {
      printf("queueSize==%u, numThreads=%u \n",
            (unsigned)queueSize, (unsigned)numThreads);
      if (testOrder(numThreads, queueSize)) {
        printf("FAIL: testOrder\n");
        return 1;
      }
      printf("SUCCESS: testOrder\n");
      if (testWait(numThreads, queueSize)) {
        printf("FAIL: testWait\n");
        return 1;
      }
      printf("SUCCESS: testWait\n");
    }
  }

  if (testThreadReduction()) {
      printf("FAIL: thread reduction not effective \n");
      return 1;
  } else {
      printf("SUCCESS: thread reduction effective \n");
  }

  if (testAbruptEnding()) {
      printf("FAIL: jobs in queue not completed on early end \n");
      return 1;
  } else {
      printf("SUCCESS: all jobs in queue completed on early end \n");
  }

  printf("PASS: all POOL tests\n");

  return 0;
}

