all: test_heap test_evquick test_timers test_timers2 test_multiple_events test_evquick_pthread test_timers3 test_timers_pthread
clean:
	rm -f test_heap test_evquick test_timers tags core test_multiple_events test_evquick_pthread test_timers2 test_timers3 test_timers_pthread ../*.o ../*.a
test_heap:
	gcc -o test_heap test_heap.c -I.. -lrt
test_evquick:
	gcc -o test_evquick test_evquick.c ../libevquick.c  -I.. -g -ggdb -lrt
test_timers:
	gcc -o test_timers test_timers.c ../libevquick.c  -I.. -g -ggdb -lrt

test_timers2:
	gcc -o test_timers2 test_timers2.c ../libevquick.c  -I.. -g -ggdb -lrt
test_timers3:
	gcc -o test_timers3 test_timers3.c ../libevquick.c  -I.. -g -ggdb -lrt

test_multiple_events:
	gcc -o test_multiple_events test_multiple_events.c ../libevquick.c  -I.. -g -ggdb  -lrt

test_evquick_pthread:
	gcc -o $@ test_evquick_pthread.c ../libevquick.c -pthread -I.. -g -ggdb -DEVQUICK_PTHREAD -lrt

test_timers_pthread:
	gcc -o $@ test_timers_pthread.c ../libevquick.c -pthread -I.. -g -ggdb -DEVQUICK_PTHREAD -lrt
