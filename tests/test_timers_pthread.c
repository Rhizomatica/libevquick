#include "libevquick.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

static int counter = 0;
static int counter1 = 0;

static __thread CTX ctx = NULL;

void timer_long_cb(CTX c, void *arg)
{
    counter1++;
    evquick_addtimer(ctx, 200, 0, timer_long_cb, NULL);
}

void timer_cb(CTX c, void *arg)
{
    counter++;
}


void timer2_cb(CTX c, void *arg)
{
    printf("Counters: %d %d\n", counter, counter1);
    counter = 0;
    counter1 = 0;
    evquick_addtimer(ctx, 1000, 0, timer2_cb, NULL);
}

void *thread2(void *arg)
{
	ctx = evquick_init();
    if (!ctx)
		exit(2);
    evquick_addtimer(ctx, 1000, 0, timer2_cb, NULL);
	evquick_loop(ctx);
}

int main(void)
{
    pthread_t p2;
    pthread_create(&p2, NULL, thread2, NULL);
	ctx = evquick_init();
    if (!ctx)
		exit(2);
    evquick_addtimer(ctx, 8, EVQUICK_EV_RETRIGGER, timer_cb, NULL);
    evquick_addtimer(ctx, 200, 0, timer_long_cb, NULL);
	evquick_loop(ctx);
	exit(0);
}
