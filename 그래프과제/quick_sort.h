#pragma once
#include <stdio.h>
#define SWAP(x, y, t)  ((t) = (x), (x) = (y), (y) = (t))
void quick_sort(int list[], int left, int right, int n)
{
	step_print_array(0, list);
	int pivot, i, j;
	int temp;

	if (left < right) {
		i = left;
		j = right + 1;
		pivot = list[left];
		do {
			do {
				i++;
			} while (list[i] < pivot && i <= right);

			do {
				j--;
			} while (list[j] > pivot);

			if (i < j) SWAP(list[i], list[j], temp);
		} while (i < j);

		SWAP(list[left], list[j], temp);
		quick_sort(list, left, j - 1, n);
		quick_sort(list, j + 1, right, n);

		/*
		if (count == 1 || count == 2 || count == 3) {
			printf("count = %d\n", count);
		}
		*/
		//quicksort(list, left, j - 1, n, ++count);
		//quicksort(list, j + 1, right, n, count);

	}
}