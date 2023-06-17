#pragma once
#include <stdlib.h>
#define MAX_SIZE 10

void generate_data(int* list, int replace) {
	int check_list[MAX_SIZE] = { 0, };
	if (replace) { // 복원추출
		for (int i = 0; i < MAX_SIZE; i++) {
			list[i] = rand() % MAX_SIZE + 1;
		}
	}
	else { //비복원추출
		for (int i = 0; i < MAX_SIZE; i++) {
			list[i] = rand() % MAX_SIZE + 1;
			if (check_list[list[i] - 1]) {
				i--;
				continue;
			}
			check_list[list[i] - 1] = 1;
		}
	}

}

void copy_original_data(int* list, int* original_list) {
	for (int i = 0; i < MAX_SIZE; i++) {
		list[i] = original_list[i];
	}
}

void copy_original_data_heap(int* list, int* original_list, int size) {
	list[0] = -1;
	for (int i = 0; i < MAX_SIZE; i++) {
		list[i + 1] = original_list[i];
	}
}