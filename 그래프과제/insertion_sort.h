#pragma once
#include "print_array.h"
void insert_sort(int list[], int n)
// n개의 데이터를 저장하는 list[] 배열에서 삽입 정렬 수행
{
	int i, j;
	int next;
	step_print_array(0, list);
	for (i = 1; i < n; i++) {
		next = list[i];
		for (j = i - 1; j >= 0 && next < list[j]; j--)
			list[j + 1] = list[j];
		list[j + 1] = next;
		insertion_print_array(i, next, list);
	}
}
