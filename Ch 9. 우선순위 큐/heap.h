#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap_node.h"

#define MAX_ELEMENTS	200 //maximum heap size+1
#define HEAP_FULL(n)	(n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n)	(!n)


void push_max_heap(element* heap, element item, int* n)
{		// 노드 수가 *n인 max heap에 item 값을 추가
	int i;
	if (HEAP_FULL(*n)) {
		fprintf(stderr, "The heap is full.\n");
		exit(1);
	}
	i = ++(*n);
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2];	  // parent의 값을 아래로 이동
		i /= 2;		// 한 레벨 위로 이동
	}
	heap[i] = item;
}

element pop_max_heap(element* heap, int* n)
{
	int parent, child;
	element item, temp;

	if (HEAP_EMPTY(*n))
	{
		fprintf(stderr, "The heap is empty\n");
		exit(1);
	}
	item = heap[1];
	temp = heap[(*n)--];		// 제일 마지막 원소를 비교 대상으로…
	parent = 1; child = 2;	// root node부터 시작
	while (child <= *n) {
		if ((child < *n) && (heap[child].key < heap[child + 1].key))
			child++;	// 두 개의 children 중에 큰 쪽과 비교
		if (temp.key >= heap[child].key)
			break;	// 더 이상 내려갈 필요없음
		heap[parent] = heap[child];	// child의 데이터를 위로 이동
		parent = child;		// 아래로 내려가자
		child *= 2;
	}
	heap[child].key = 0;
	heap[parent] = temp;
	return item;
}
