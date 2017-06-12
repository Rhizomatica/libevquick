#include "libevquick.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int counter = 0;

void timer_cb(void *arg)
{
    counter++;
}

void stats(void *arg)
{
    printf("Counter: %d\n", counter);
    counter = 0;
}


int main(void)
{
	if(evquick_init() < 0)
		exit(2);
    evquick_addtimer(5, EVQUICK_EV_RETRIGGER, timer_cb, NULL);
    evquick_addtimer(1000, EVQUICK_EV_RETRIGGER, stats, NULL);
	evquick_loop();
	exit(0);
}
