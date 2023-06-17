#pragma once
#include <stdio.h>
#include "generated_data.h"

void merge(int list[], int sorted[], int i, int m, int p)
{	// list[i], …, list[m]과 list[m+1], …, list[p]은 각각 정렬된 리스트
	// 두 개의 리스트를 병합하여 정렬된 sorted[i], …, sorted[p]를 생성
	int j = m + 1, k = i, t;	// j: 두 번째 리스트 색인

	while (i <= m && j <= p) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else	 sorted[k++] = list[j++];
	}
	if (i > m)	// 두 번째 리스트의 나머지를 sorted[]에 복사
		for (t = j; t <= p; t++)	sorted[k++] = list[t];
	else		    // 첫 번째 리스트의 나머지를 sorted[]에 복사
		for (t = i; t <= m; t++) sorted[k++] = list[t];
}

void merge_pass(int list[], int sorted[], int n, int length)
{
	/* Merge sort의 한 패스 수행. list[n] 배열에서 길이가 length인 인접한 한 쌍의 서브리스트를 합병하여 sorted[] 배열에 저장. */
	int i, j;
	for (i = 0; i <= n - 2 * length; i += 2 * length)
		merge(list, sorted, i, i + length - 1, i + 2 * length - 1);
	//길이가 2*length보다 적게 남아있는 서브리스트들을 병합
	if (i + length < n)	// 하나 = length, 나머지 ≤ length
		merge(list, sorted, i, i + length - 1, n - 1);
	else	// 하나의 서브리스트만 남아있는 경우
		for (j = i; j < n; j++)
			sorted[j] = list[j];
}

void merge_sort(int list[], int n)
{
	int p = 1, length = 1;
	int extra[MAX_SIZE];
	print_array(list);

	while (length < n) {
		merge_pass(list, extra, MAX_SIZE, length);
		print_array(list);
		length *= 2;
		merge_pass(extra, list, MAX_SIZE, length);
		print_array(list);
		length *= 2;


	}
}

