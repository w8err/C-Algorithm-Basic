#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap_node.h"

#define MAX_ELEMENTS	200 //maximum heap size+1
#define HEAP_FULL(n)	(n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n)	(!n)


void push_max_heap(element* heap, element item, int* n)
{		// ��� ���� *n�� max heap�� item ���� �߰�
	int i;
	if (HEAP_FULL(*n)) {
		fprintf(stderr, "The heap is full.\n");
		exit(1);
	}
	i = ++(*n);
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2];	  // parent�� ���� �Ʒ��� �̵�
		i /= 2;		// �� ���� ���� �̵�
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
	temp = heap[(*n)--];		// ���� ������ ���Ҹ� �� ������Ρ�
	parent = 1; child = 2;	// root node���� ����
	while (child <= *n) {
		if ((child < *n) && (heap[child].key < heap[child + 1].key))
			child++;	// �� ���� children �߿� ū �ʰ� ��
		if (temp.key >= heap[child].key)
			break;	// �� �̻� ������ �ʿ����
		heap[parent] = heap[child];	// child�� �����͸� ���� �̵�
		parent = child;		// �Ʒ��� ��������
		child *= 2;
	}
	heap[child].key = 0;
	heap[parent] = temp;
	return item;
}
