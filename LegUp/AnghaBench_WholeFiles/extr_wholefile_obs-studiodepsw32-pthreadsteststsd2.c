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
typedef  int /*<<< orphan*/  pthread_t ;

/* Variables and functions */
 int NUM_THREADS ; 
 int* accesscount ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int,int,int) ; 
 int /*<<< orphan*/  key ; 
 scalar_t__ pthread_barrier_destroy (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_barrier_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  pthread_barrier_wait (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),void*) ; 
 void* pthread_getspecific (int /*<<< orphan*/ ) ; 
 scalar_t__ pthread_join (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_key_create (int /*<<< orphan*/ *,void (*) (void*)) ; 
 scalar_t__ pthread_key_delete (int /*<<< orphan*/ ) ; 
 scalar_t__ pthread_setspecific (int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  startBarrier ; 
 int /*<<< orphan*/  stderr ; 
 int* thread_destroyed ; 
 int* thread_set ; 

__attribute__((used)) static void
destroy_key(void * arg)
{
  int * j = (int *) arg;

  (*j)++;

  /* Set TSD key from the destructor to test destructor iteration */
  if (*j == 2)
    assert(pthread_setspecific(key, arg) == 0);
  else
    assert(*j == 3);

  thread_destroyed[j - accesscount] = 1;
}

__attribute__((used)) static void
setkey(void * arg)
{
  int * j = (int *) arg;

  thread_set[j - accesscount] = 1;

  assert(*j == 0);

  assert(pthread_getspecific(key) == NULL);

  assert(pthread_setspecific(key, arg) == 0);
  assert(pthread_setspecific(key, arg) == 0);
  assert(pthread_setspecific(key, arg) == 0);

  assert(pthread_getspecific(key) == arg);

  (*j)++;

  assert(*j == 1);
}

__attribute__((used)) static void *
mythread(void * arg)
{
  (void) pthread_barrier_wait(&startBarrier);

  setkey(arg);

  return 0;

  /* Exiting the thread will call the key destructor. */
}

int
main()
{
  int i;
  int fail = 0;
  pthread_t thread[NUM_THREADS];

  assert(pthread_barrier_init(&startBarrier, NULL, NUM_THREADS/2) == 0);

  for (i = 1; i < NUM_THREADS/2; i++)
    {
      accesscount[i] = thread_set[i] = thread_destroyed[i] = 0;
      assert(pthread_create(&thread[i], NULL, mythread, (void *)&accesscount[i]) == 0);
    }

  /*
   * Here we test that existing threads will get a key created
   * for them.
   */
  assert(pthread_key_create(&key, destroy_key) == 0);

  (void) pthread_barrier_wait(&startBarrier);

  /*
   * Test main thread key.
   */
  accesscount[0] = 0;
  setkey((void *) &accesscount[0]);

  /*
   * Here we test that new threads will get a key created
   * for them.
   */
  for (i = NUM_THREADS/2; i < NUM_THREADS; i++)
    {
      accesscount[i] = thread_set[i] = thread_destroyed[i] = 0;
      assert(pthread_create(&thread[i], NULL, mythread, (void *)&accesscount[i]) == 0);
    }

  /*
   * Wait for all threads to complete.
   */
  for (i = 1; i < NUM_THREADS; i++)
    {
	assert(pthread_join(thread[i], NULL) == 0);
    }

  assert(pthread_key_delete(key) == 0);

  assert(pthread_barrier_destroy(&startBarrier) == 0);

  for (i = 1; i < NUM_THREADS; i++)
    {
	/*
	 * The counter is incremented once when the key is set to
	 * a value, and again when the key is destroyed. If the key
	 * doesn't get set for some reason then it will still be
	 * NULL and the destroy function will not be called, and
	 * hence accesscount will not equal 2.
	 */
	if (accesscount[i] != 3)
	  {
	    fail++;
	    fprintf(stderr, "Thread %d key, set = %d, destroyed = %d\n",
			i, thread_set[i], thread_destroyed[i]);
	  }
    }

  fflush(stderr);

  return (fail);
}

