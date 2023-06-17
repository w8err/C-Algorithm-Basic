#define _CRT_SECURE_NO_WARNINIGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "generated_data.h"
#include "print_array.h"
#include "execution_time.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "quick_sort.h"
#include "merge_sort.h"
#include "heap_sort.h"

#define TRUE	 1
#define FALSE	 0

void main() {
	int original_list[MAX_SIZE] = { 0, };
	int list[MAX_SIZE] = { 0, };
	int list_heap[MAX_SIZE + 1] = { 0, };
	clock_t timer;

	generate_data(original_list, FALSE);
	copy_original_data(list, original_list);
	selection_sort(list, MAX_SIZE);
	print_array(list);

	copy_original_data(list, original_list);
	insert_sort(list, MAX_SIZE);
	print_array(list);

	copy_original_data(list, original_list);
	quick_sort(list, 0, MAX_SIZE - 1, MAX_SIZE);
	print_array(list);


	copy_original_data(list, original_list);
	merge_sort(list, MAX_SIZE);
	print_array(list);


	copy_original_data_heap(list_heap, original_list, MAX_SIZE);
	heap_sort(list_heap, MAX_SIZE);
	print_array_heap(list_heap);
}