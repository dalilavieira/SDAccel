#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int id; int work; int stat; int /*<<< orphan*/  mutex_ended; int /*<<< orphan*/  mutex_end; int /*<<< orphan*/  mutex_started; int /*<<< orphan*/  mutex_start; int /*<<< orphan*/  thread; } ;
typedef  TYPE_1__ TC ;

/* Variables and functions */
 int EBUSY ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ calloc (int,int) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int /*<<< orphan*/  mutex_stdout ; 
 int /*<<< orphan*/  mutex_todo ; 
 int nthreads ; 
 int nwork ; 
 int printf (char*,...) ; 
 int pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),void*) ; 
 scalar_t__ pthread_join (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutex_destroy (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutex_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int pthread_mutex_trylock (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ quiet ; 
 int rand () ; 
 int /*<<< orphan*/  stdout ; 
 TYPE_1__* tcs ; 
 int todo ; 

__attribute__((used)) static void
die (int ret)
{
  if (NULL != tcs)
    {
      free (tcs);
      tcs = NULL;
    }

  if (ret)
    exit (ret);
}

__attribute__((used)) static double
waste_time (int n)
{
  int		i;
  double	f, g, h, s;

  s = 0.0;

  /*
   * Useless work.
   */
  for (i = n*100; i > 0; --i)
    {
      f = rand ();
      g = rand ();
      h = rand ();
      s += 2.0 * f * g / (h != 0.0 ? (h * h) : 1.0);
    }
  return s;
}

__attribute__((used)) static int
do_work_unit (int who, int n)
{
  int		i;
  static int	nchars = 0;
  double	f = 0.0;

  if (quiet)
    i = 0;
  else {
    /*
     * get lock on stdout
     */
    assert(pthread_mutex_lock (&mutex_stdout) == 0);

    /*
     * do our job
     */
    i = printf ("%c", "0123456789abcdefghijklmnopqrstuvwxyz"[who]);

    if (!(++nchars % 50))
      printf ("\n");

    fflush (stdout);

    /*
     * release lock on stdout
     */
    assert(pthread_mutex_unlock (&mutex_stdout) == 0);
  }

  n = rand () % 10000;	/* ignore incoming 'n' */
  f = waste_time (n);

  /* This prevents the statement above from being optimised out */
  if (f > 0.0)
    return(n);

  return (n);
}

__attribute__((used)) static int
print_server (void *ptr)
{
  int		mywork;
  int		n;
  TC		*tc = (TC *)ptr;

  assert(pthread_mutex_lock (&tc->mutex_started) == 0);

  for (;;)
    {
      assert(pthread_mutex_lock (&tc->mutex_start) == 0);
      assert(pthread_mutex_unlock (&tc->mutex_start) == 0);
      assert(pthread_mutex_lock (&tc->mutex_ended) == 0);
      assert(pthread_mutex_unlock (&tc->mutex_started) == 0);

      for (;;)
	{

	  /*
	   * get lock on todo list
	   */
	  assert(pthread_mutex_lock (&mutex_todo) == 0);

	  mywork = todo;
	  if (todo >= 0)
	    {
	      ++todo;
	      if (todo >= nwork)
		todo = -1;
	    }
	  assert(pthread_mutex_unlock (&mutex_todo) == 0);

	  if (mywork < 0)
	    break;

	  assert((n = do_work_unit (tc->id, mywork)) >= 0);
	  tc->work += n;
	}

      assert(pthread_mutex_lock (&tc->mutex_end) == 0);
      assert(pthread_mutex_unlock (&tc->mutex_end) == 0);
      assert(pthread_mutex_lock (&tc->mutex_started) == 0);
      assert(pthread_mutex_unlock (&tc->mutex_ended) == 0);

      if (-2 == mywork)
	break;
    }

  assert(pthread_mutex_unlock (&tc->mutex_started) == 0);

  return (0);
}

__attribute__((used)) static void
dosync (void)
{
  int		i;

  for (i = 0; i < nthreads; ++i)
    {
      assert(pthread_mutex_lock (&tcs[i].mutex_end) == 0);
      assert(pthread_mutex_unlock (&tcs[i].mutex_start) == 0);
      assert(pthread_mutex_lock (&tcs[i].mutex_started) == 0);
      assert(pthread_mutex_unlock (&tcs[i].mutex_started) == 0);
    }

  /*
   * Now threads do their work
   */
  for (i = 0; i < nthreads; ++i)
    {
      assert(pthread_mutex_lock (&tcs[i].mutex_start) == 0);
      assert(pthread_mutex_unlock (&tcs[i].mutex_end) == 0);
      assert(pthread_mutex_lock (&tcs[i].mutex_ended) == 0);
      assert(pthread_mutex_unlock (&tcs[i].mutex_ended) == 0);
    }
}

__attribute__((used)) static void
dowork (void)
{
  todo = 0;
  dosync();

  todo = 0;
  dosync();
}

int
main (int argc, char *argv[])
{
  int		i;

  assert(NULL != (tcs = (TC *) calloc (nthreads, sizeof (*tcs))));

  /* 
   * Launch threads
   */
  for (i = 0; i < nthreads; ++i)
    {
      tcs[i].id = i;

      assert(pthread_mutex_init (&tcs[i].mutex_start, NULL) == 0);
      assert(pthread_mutex_init (&tcs[i].mutex_started, NULL) == 0);
      assert(pthread_mutex_init (&tcs[i].mutex_end, NULL) == 0);
      assert(pthread_mutex_init (&tcs[i].mutex_ended, NULL) == 0);

      tcs[i].work = 0;  

      assert(pthread_mutex_lock (&tcs[i].mutex_start) == 0);
      assert((tcs[i].stat = 
	      pthread_create (&tcs[i].thread,
			      NULL,
                  (void *(*)(void *))print_server,
                (void *) &tcs[i])
	      ) == 0);

      /* 
       * Wait for thread initialisation
       */
      {
	int trylock = 0;

	while (trylock == 0)
	  {
	    trylock = pthread_mutex_trylock(&tcs[i].mutex_started);
	    assert(trylock == 0 || trylock == EBUSY);

	    if (trylock == 0)
	      {
		assert(pthread_mutex_unlock (&tcs[i].mutex_started) == 0);
	      }
	  }
      }
    }

  dowork ();

  /*
   * Terminate threads
   */
  todo = -2;	/* please terminate */
  dosync();

  for (i = 0; i < nthreads; ++i)
    {
      if (0 == tcs[i].stat)
	assert(pthread_join (tcs[i].thread, NULL) == 0);
    }

  /* 
   * destroy locks
   */
  assert(pthread_mutex_destroy (&mutex_stdout) == 0);
  assert(pthread_mutex_destroy (&mutex_todo) == 0);

  /*
   * Cleanup
   */
  printf ("\n");

  /*
   * Show results
   */
  for (i = 0; i < nthreads; ++i)
    {
      printf ("%2d ", i);
      if (0 == tcs[i].stat)
	printf ("%10ld\n", tcs[i].work);
      else
	printf ("failed %d\n", tcs[i].stat);

      assert(pthread_mutex_unlock(&tcs[i].mutex_start) == 0);

      assert(pthread_mutex_destroy (&tcs[i].mutex_start) == 0);
      assert(pthread_mutex_destroy (&tcs[i].mutex_started) == 0);
      assert(pthread_mutex_destroy (&tcs[i].mutex_end) == 0);
      assert(pthread_mutex_destroy (&tcs[i].mutex_ended) == 0);
    }

  die (0);

  return (0);
}

