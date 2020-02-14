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
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  tsc_freq ;
struct TYPE_2__ {int /*<<< orphan*/  s_addr; } ;
struct sockaddr_in {int sin_len; int /*<<< orphan*/  sin_port; TYPE_1__ sin_addr; int /*<<< orphan*/  sin_family; } ;
struct sockaddr {int dummy; } ;
struct mevent {int dummy; } ;
struct esync {int /*<<< orphan*/  e_cond; int /*<<< orphan*/  e_mt; } ;
typedef  int /*<<< orphan*/  sin ;
typedef  int /*<<< orphan*/  pthread_t ;
typedef  enum ev_type { ____Placeholder_ev_type } ev_type ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 int /*<<< orphan*/  EVF_READ ; 
 int /*<<< orphan*/  EVF_TIMER ; 
 int /*<<< orphan*/  INADDR_ANY ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int /*<<< orphan*/  TEST_PORT ; 
 int TEVSZ ; 
 int UINT64_MAX ; 
 int /*<<< orphan*/  abort () ; 
 int accept (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  accept_condvar ; 
 int /*<<< orphan*/  accept_mutex ; 
 scalar_t__ bind (int,struct sockaddr*,int) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  htonl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  htons (int /*<<< orphan*/ ) ; 
 scalar_t__ listen (int,int) ; 
 void* mevent_add (int,int /*<<< orphan*/ ,void (*) (int,int,void*),struct esync*) ; 
 int /*<<< orphan*/  mevent_delete (void*) ; 
 int /*<<< orphan*/  mevent_delete_close (struct mevent*) ; 
 int /*<<< orphan*/  mevent_dispatch () ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  pthread_cond_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_cond_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_cond_signal (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_cond_wait (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),void*) ; 
 int /*<<< orphan*/  pthread_mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 int read (int,char*,int) ; 
 int socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sysctlbyname (char*,int*,size_t*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int* tevbuf ; 
 void* tevp ; 
 int /*<<< orphan*/  write (int,char*,int) ; 

__attribute__((used)) static __inline uint64_t rdtsc(void)
{
	unsigned a, d;
	__asm__ __volatile__ ("cpuid");
	__asm__ __volatile__ ("rdtsc" : "=a" (a), "=d" (d));

	return (((uint64_t) a) | (((uint64_t) d) << 32));
}

__attribute__((used)) static void
timer_print(void)
{
	uint64_t min, max, diff, sum, tsc_freq;
	size_t len;
	int j;

	min = UINT64_MAX;
	max = 0;
	sum = 0;

	len = sizeof(tsc_freq);
	sysctlbyname("machdep.tsc_freq", &tsc_freq, &len, NULL, 0);

	for (j = 1; j < TEVSZ; j++) {
		/* Convert a tsc diff into microseconds */
		diff = (tevbuf[j] - tevbuf[j-1]) * 1000000 / tsc_freq;
		sum += diff;
		if (min > diff)
			min = diff;
		if (max < diff)
			max = diff;
	}

	printf("timers done: usecs, min %llu, max %llu, mean %llu\n", min, max,
	    sum/(TEVSZ - 1));
}

__attribute__((used)) static void
timer_callback(int fd, enum ev_type type, void *param)
{
	static int i;

	if (i >= TEVSZ)
		abort();

	tevbuf[i++] = rdtsc();

	if (i == TEVSZ) {
		mevent_delete(tevp);
		timer_print();
	}
}

__attribute__((used)) static void
echoer_callback(int fd, enum ev_type type, void *param)
{
	struct esync *sync = param;

	pthread_mutex_lock(&sync->e_mt);
	pthread_cond_signal(&sync->e_cond);
	pthread_mutex_unlock(&sync->e_mt);
}

__attribute__((used)) static void *
echoer(void *param)
{
	struct esync sync;
	struct mevent *mev;
	char buf[128];
	int fd = (int)(uintptr_t) param;
	int len;

	pthread_mutex_init(&sync.e_mt, NULL);
	pthread_cond_init(&sync.e_cond, NULL);

	pthread_mutex_lock(&sync.e_mt);

	mev = mevent_add(fd, EVF_READ, echoer_callback, &sync);
	if (mev == NULL) {
		printf("Could not allocate echoer event\n");
		exit(1);
	}

	while (!pthread_cond_wait(&sync.e_cond, &sync.e_mt)) {
		len = read(fd, buf, sizeof(buf));
		if (len > 0) {
			write(fd, buf, len);
			write(0, buf, len);
		} else {
			break;
		}
	}

	mevent_delete_close(mev);

	pthread_mutex_unlock(&sync.e_mt);
	pthread_mutex_destroy(&sync.e_mt);
	pthread_cond_destroy(&sync.e_cond);

	return (NULL);
}

__attribute__((used)) static void
acceptor_callback(int fd, enum ev_type type, void *param)
{
	pthread_mutex_lock(&accept_mutex);
	pthread_cond_signal(&accept_condvar);
	pthread_mutex_unlock(&accept_mutex);
}

__attribute__((used)) static void *
acceptor(void *param)
{
	struct sockaddr_in sin;
	pthread_t tid;
	int news;
	int s;
	static int first;

        if ((s = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                perror("socket");
                exit(1);
        }

        sin.sin_len = sizeof(sin);
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = htonl(INADDR_ANY);
        sin.sin_port = htons(TEST_PORT);

        if (bind(s, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
                perror("bind");
                exit(1);
        }

        if (listen(s, 1) < 0) {
                perror("listen");
                exit(1);
        }

	(void) mevent_add(s, EVF_READ, acceptor_callback, NULL);

	pthread_mutex_lock(&accept_mutex);

	while (!pthread_cond_wait(&accept_condvar, &accept_mutex)) {
		news = accept(s, NULL, NULL);
		if (news < 0) {
			perror("accept error");
		} else {
			static int first = 1;

			if (first) {
				/*
				 * Start a timer
				 */
				first = 0;
				tevp = mevent_add(1, EVF_TIMER, timer_callback,
						  NULL);
			}

			printf("incoming connection, spawning thread\n");
			pthread_create(&tid, NULL, echoer,
				       (void *)(uintptr_t)news);
		}
	}

	return (NULL);
}

int
main(void)
{
	pthread_t tid;

	pthread_create(&tid, NULL, acceptor, NULL);

	mevent_dispatch();

	return (0);
}

