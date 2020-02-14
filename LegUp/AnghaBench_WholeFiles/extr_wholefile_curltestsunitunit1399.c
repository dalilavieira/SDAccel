#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int time_t ;
struct curltime {int /*<<< orphan*/  tv_usec; scalar_t__ tv_sec; } ;
struct TYPE_3__ {int /*<<< orphan*/  tv_usec; scalar_t__ tv_sec; } ;
struct TYPE_4__ {int t_nslookup; int t_connect; int t_appconnect; int t_pretransfer; int t_starttransfer; TYPE_1__ t_startsingle; } ;
struct Curl_easy {TYPE_2__ progress; } ;
typedef  int /*<<< orphan*/  msg ;

/* Variables and functions */
 int CURLE_OK ; 
 int /*<<< orphan*/  Curl_pgrsTime (struct Curl_easy*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TIMER_STARTSINGLE ; 
 int /*<<< orphan*/  fail_unless (int,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int,int,char*) ; 
 int /*<<< orphan*/  msnprintf (char*,int,char*,int) ; 
 int /*<<< orphan*/  stderr ; 
 int usec_magnitude ; 

__attribute__((used)) static bool unit_setup(void)
{
  return CURLE_OK;
}

__attribute__((used)) static void unit_stop(void)
{

}

__attribute__((used)) static void fake_t_startsingle_time(struct Curl_easy *data,
                                    struct curltime fake_now,
                                    int seconds_offset)
{
  Curl_pgrsTime(data, TIMER_STARTSINGLE);
  data->progress.t_startsingle.tv_sec = fake_now.tv_sec + seconds_offset;
  data->progress.t_startsingle.tv_usec = fake_now.tv_usec;
}

__attribute__((used)) static bool usec_matches_seconds(time_t time_usec, int expected_seconds)
{
  int time_sec = (int)(time_usec / usec_magnitude);
  bool same = (time_sec == expected_seconds);
  fprintf(stderr, "is %d us same as %d seconds? %s\n",
          (int)time_usec, expected_seconds,
          same?"Yes":"No");
  return same;
}

__attribute__((used)) static void expect_timer_seconds(struct Curl_easy *data, int seconds)
{
  char msg[64];
  msnprintf(msg, sizeof(msg), "about %d seconds should have passed", seconds);
  fail_unless(usec_matches_seconds(data->progress.t_nslookup, seconds), msg);
  fail_unless(usec_matches_seconds(data->progress.t_connect, seconds), msg);
  fail_unless(usec_matches_seconds(data->progress.t_appconnect, seconds), msg);
  fail_unless(usec_matches_seconds(data->progress.t_pretransfer, seconds),
              msg);
  fail_unless(usec_matches_seconds(data->progress.t_starttransfer, seconds),
              msg);
}

