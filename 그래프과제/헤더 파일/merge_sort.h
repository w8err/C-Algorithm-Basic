#pragma once
#include <stdio.h>
#include "generated_data.h"

void merge(int list[], int sorted[], int i, int m, int p)
{	// list[i], ��, list[m]�� list[m+1], ��, list[p]�� ���� ���ĵ� ����Ʈ
	// �� ���� ����Ʈ�� �����Ͽ� ���ĵ� sorted[i], ��, sorted[p]�� ����
	int j = m + 1, k = i, t;	// j: �� ��° ����Ʈ ����

	while (i <= m && j <= p) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else	 sorted[k++] = list[j++];
	}
	if (i > m)	// �� ��° ����Ʈ�� �������� sorted[]�� ����
		for (t = j; t <= p; t++)	sorted[k++] = list[t];
	else		    // ù ��° ����Ʈ�� �������� sorted[]�� ����
		for (t = i; t <= m; t++) sorted[k++] = list[t];
}

void merge_pass(int list[], int sorted[], int n, int length)
{
	/* Merge sort�� �� �н� ����. list[n] �迭���� ���̰� length�� ������ �� ���� ���긮��Ʈ�� �պ��Ͽ� sorted[] �迭�� ����. */
	int i, j;
	for (i = 0; i <= n - 2 * length; i += 2 * length)
		merge(list, sorted, i, i + length - 1, i + 2 * length - 1);
	//���̰� 2*length���� ���� �����ִ� ���긮��Ʈ���� ����
	if (i + length < n)	// �ϳ� = length, ������ �� length
		merge(list, sorted, i, i + length - 1, n - 1);
	else	// �ϳ��� ���긮��Ʈ�� �����ִ� ���
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

