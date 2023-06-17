#pragma once
#include <stdio.h>
#include "generated_data.h"
void print_array(int* list) {
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list[i]);
	}
	printf("\n\n");
}

void print_array_heap(int* list) {
	for (int i = 0; i < MAX_SIZE + 1; i++) {
		printf("%d ", list[i]);
	}
	printf("\n\n");
}

void step_print_array(int step, int* list) {
	printf("step:%d\t|", step);
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}

void insertion_print_array(int step, int key, int* list) {
	printf("step:%d\tkey:%d\t|", step, key);
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}

void quick_print_array(int step, int key, int* list) {
	printf("step:%d\tkey:%d\t|", step, key);
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", list[i]);
	}
	printf("\n");
}