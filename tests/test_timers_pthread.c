#include "libevquick.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

static int counter = 0;

static __thread CTX ctx = NULL;

void timer_cb(CTX c, void *arg)
{
    counter++;
}

void timer2_cb(CTX c, void *arg)
{
    printf("Counter: %d\n", counter);
    counter = 0;
}

void *thread2(void *arg)
{
	ctx = evquick_init();
    if (!ctx)
		exit(2);
    evquick_addtimer(ctx, 1000, EVQUICK_EV_RETRIGGER, timer2_cb, NULL);
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
	evquick_loop(ctx);
	exit(0);
}
