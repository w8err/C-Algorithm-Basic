#pragma once
#include <stdio.h>
#define SWAP(x, y, t)  ((t) = (x), (x) = (y), (y) = (t))

void adjust(int list[], int root, int n)
{	// root�� ������ Ʈ���� ������ �κ��� max heap���� �̹� ����
	// list[root]�� ��ġ�� �����Ͽ� max heap�� �籸��

	int rootkey = list[root], child = 2 * root; // left child
	int temp = list[root];

	while (child <= n) {
		if ((child < n) && (list[child] < list[child + 1]))  			child++; 	// ���� �Ǵ� ������ �߿��� ū ���� child�� ����.
		if (rootkey > list[child]) break;
		else {
			list[child / 2] = list[child];  // child�� Ŭ ��� �θ� �ڸ���.
			child *= 2;
		}
	}
	list[child / 2] = temp;
}

void heap_sort(int list[], int n)
{	// list[1]���� list[n]������ ������������ ����
	int i, j;
	int temp;

	for (i = n / 2; i > 0; i--)
	{	// �ʱ� max heap�� ����
		adjust(list, i, n); // n/2�� child�� ���� ù��° ���
		// print_array(list, n+1);
	}

	for (i = n; i > 0; i--) {
		// root�� �� ���� ���ҿ� ��ȯ 	
		SWAP(list[1], list[i], temp);
		// ���Ҹ� �ϳ� ���� ���� heap�� �籸�� 
		adjust(list, 1, i - 1);
	}
}