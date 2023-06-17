#pragma once
#include "print_array.h"
#define SWAP(x, y, t)  ((t) = (x), (x) = (y), (y) = (t))

void selection_sort(int list[], int n)
{
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {  // list[i]부터 list[n-1]까지 정렬.
        step_print_array(i, list);
        min = i;	      // i 위치에 들어갈 최소값의 초기화
        for (j = i + 1; j < n; j++)
            if (list[j] < list[min])
                min = j;    // 더 작은 것이 있으면 최소값을 이 곳으로…
        SWAP(list[i], list[min], temp);  // 최소값과 i의 내용을 교체
    }
}