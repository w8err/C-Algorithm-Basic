#pragma once
#include "print_array.h"
#define SWAP(x, y, t)  ((t) = (x), (x) = (y), (y) = (t))

void selection_sort(int list[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {  // list[i]���� list[n-1]���� ����.
        step_print_array(i, list);
        min = i;	      // i ��ġ�� �� �ּҰ��� �ʱ�ȭ
        for (j = i + 1; j < n; j++)
            if (list[j] < list[min])
                min = j;    // �� ���� ���� ������ �ּҰ��� �� �����Ρ�
        SWAP(list[i], list[min], temp);  // �ּҰ��� i�� ������ ��ü
    }
}