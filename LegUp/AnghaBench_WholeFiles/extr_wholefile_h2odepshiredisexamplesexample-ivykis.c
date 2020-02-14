#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
struct TYPE_15__ {char* str; } ;
typedef  TYPE_1__ redisReply ;
struct TYPE_16__ {char* errstr; scalar_t__ err; } ;
typedef  TYPE_2__ redisAsyncContext ;

/* Variables and functions */
 int REDIS_OK ; 
 int /*<<< orphan*/  SIGPIPE ; 
 int /*<<< orphan*/  SIG_IGN ; 
 int /*<<< orphan*/  iv_deinit () ; 
 int /*<<< orphan*/  iv_init () ; 
 int /*<<< orphan*/  iv_main () ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  redisAsyncCommand (TYPE_2__*,void (*) (TYPE_2__*,void*,void*),char*,char*,...) ; 
 TYPE_2__* redisAsyncConnect (char*,int) ; 
 int /*<<< orphan*/  redisAsyncDisconnect (TYPE_2__*) ; 
 int /*<<< orphan*/  redisAsyncSetConnectCallback (TYPE_2__*,void (*) (TYPE_2__ const*,int)) ; 
 int /*<<< orphan*/  redisAsyncSetDisconnectCallback (TYPE_2__*,void (*) (TYPE_2__ const*,int)) ; 
 int /*<<< orphan*/  redisIvykisAttach (TYPE_2__*) ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (char*) ; 

void getCallback(redisAsyncContext *c, void *r, void *privdata) {
    redisReply *reply = r;
    if (reply == NULL) return;
    printf("argv[%s]: %s\n", (char*)privdata, reply->str);

    /* Disconnect after receiving the reply to GET */
    redisAsyncDisconnect(c);
}

void connectCallback(const redisAsyncContext *c, int status) {
    if (status != REDIS_OK) {
        printf("Error: %s\n", c->errstr);
        return;
    }
    printf("Connected...\n");
}

void disconnectCallback(const redisAsyncContext *c, int status) {
    if (status != REDIS_OK) {
        printf("Error: %s\n", c->errstr);
        return;
    }
    printf("Disconnected...\n");
}

int main (int argc, char **argv) {
    signal(SIGPIPE, SIG_IGN);

    iv_init();

    redisAsyncContext *c = redisAsyncConnect("127.0.0.1", 6379);
    if (c->err) {
        /* Let *c leak for now... */
        printf("Error: %s\n", c->errstr);
        return 1;
    }

    redisIvykisAttach(c);
    redisAsyncSetConnectCallback(c,connectCallback);
    redisAsyncSetDisconnectCallback(c,disconnectCallback);
    redisAsyncCommand(c, NULL, NULL, "SET key %b", argv[argc-1], strlen(argv[argc-1]));
    redisAsyncCommand(c, getCallback, (char*)"end-1", "GET key");

    iv_main();

    iv_deinit();

    return 0;
}

