#pragma once
#include <stdio.h>
#define SWAP(x, y, t)  ((t) = (x), (x) = (y), (y) = (t))

void adjust(int list[], int root, int n)
{	// root를 제외한 트리의 나머지 부분은 max heap으로 이미 조직
	// list[root]의 위치를 조정하여 max heap을 재구성

	int rootkey = list[root], child = 2 * root; // left child
	int temp = list[root];

	while (child <= n) {
		if ((child < n) && (list[child] < list[child + 1]))  			child++; 	// 왼쪽 또는 오른쪽 중에서 큰 값을 child로 설정.
		if (rootkey > list[child]) break;
		else {
			list[child / 2] = list[child];  // child가 클 경우 부모 자리로.
			child *= 2;
		}
	}
	list[child / 2] = temp;
}

void heap_sort(int list[], int n)
{	// list[1]부터 list[n]까지를 오름차순으로 정렬
	int i, j;
	int temp;

	for (i = n / 2; i > 0; i--)
	{	// 초기 max heap을 구성
		adjust(list, i, n); // n/2은 child를 갖는 첫번째 노드
		// print_array(list, n+1);
	}

	for (i = n; i > 0; i--) {
		// root를 맨 뒤의 원소와 교환 	
		SWAP(list[1], list[i], temp);
		// 원소를 하나 적게 가진 heap을 재구성 
		adjust(list, 1, i - 1);
	}
}