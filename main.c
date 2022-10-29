#include <stdio.h>
#include "philosophers.h"

int main () {
	struct timeval current_time;
	gettimeofday(&current_time, NULL);

	printf("seconds : %ld\nmicro seconds : %d",current_time.tv_sec, current_time.tv_usec);

}