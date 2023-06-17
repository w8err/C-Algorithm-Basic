#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <limits.h>

clock_t start_time() {
	clock_t start;
	start = clock();
}

void end_time(clock_t start) {
	clock_t stop;
	double duration;

	stop = clock();
	duration = ((double)(stop - start)) / CLOCKS_PER_SEC;
	printf("%f   ", duration);
}