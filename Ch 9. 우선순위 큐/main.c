#define _CRT_SECURE_NO_WARNINIGS

#include <stdio.h>
#include "heap.h"
#include "print_heap.h"
#include "heap_node.h"

#define USE_ELEMENTS_COUNT 10


void main() {
	element heap[MAX_ELEMENTS] = { {0} };
	int	n = 0;
	element data[USE_ELEMENTS_COUNT];

	srand((int)time(NULL));
	for (int i = 0; i < USE_ELEMENTS_COUNT; i++) {
		data[i].key = rand() % 30 + 1;
		for (int j = 0; j < i; j++) {
			if (data[j].key == data[i].key) {
				i--;
				break;
			}
		}
	}

	for (int j = 0; j < USE_ELEMENTS_COUNT; j++) {
		printf("%d\t", data[j].key);
	}

	for (int i = 0; i < USE_ELEMENTS_COUNT; i++) {
		printf("Before tree : Add Data = %d\n", data[i].key);
		print(heap, &n);
		printf("After tree\n");
		push_max_heap(heap, data[i], &n);
		print(heap, &n);
		system("pause");
		system("cls");

	}
	printf("\nMAX_HEAP PUSH .... END\n");
	system("pause");
	system("cls");

	while (n != 1) {
		printf("Before tree : n = %d\n", n);
		print(heap, &n);
		printf("After tree\n");
		pop_max_heap(heap, &n);
		print(heap, &n);
		system("pause");
		system("cls");
	}
	printf("\nMAX_HEAP PUSH .... END\n");
}