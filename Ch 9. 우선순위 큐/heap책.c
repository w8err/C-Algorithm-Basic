#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// ���� �Լ�
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

// �ʱ�ȭ �Լ�
void init(HeapType* h)
{
	h->heap_size = 0;
}
// ���� ����� ������ heap_size�� ���� h�� item�� �����Ѵ�.
// ���� �Լ�
void insert_max_heap(HeapType* h, element item)		// ũ�Ⱑ 4�� ������ 3�� ����. 
{
	int i;					
	i = ++(h->heap_size);					// i�� 5�� �ȴ�. 

	// Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {   // 1 �ó�����.  5 != 1 && �Էµ� ����� Ű >  5/2(2) ��° ����� Ű) --> �θ� ���� �Էµ� ����� ��
														    // 2 �ó�����.  2 != 1 && �Էµ� ����� Ű > 2/2(1) ��° ����� Ű)  -->  ���ϵ���
		h->heap[i] = h->heap[i / 2];    // 1 �ó�����. h�� �� 5��°�� 2���� ��尡 �ȴ�.
										// 2 �ó�����. h�� �� 2��°�� 1��° ��尡 �ȴ�. 
		i /= 2;							// 1 �ó�����. i�� 2�� �ȴ�. 
										// 2. i�� 1�� �ȴ�.  
			
	}		// �Էµ� ����� Ű�� �θ� ����� Ű���� ������ while�� ����. 
	h->heap[i] = item;	//���ο� ��� ����
}

// ���� �Լ�
element delete_max_heap(HeapType* h)
{
	int parent, child;			// �θ�� �ڽ� ����
	element item, temp;			// ���� �����۰� ���� ����

	item = h->heap[1];			// �������� ���� ù ��° Ű���� �ȴ�. 
	temp = h->heap[(h->heap_size)--];	// ������ ���� ���������� -1�� �� ��ġ�� Ű���� �ȴ�. 
	parent = 1;							// �θ�� 1�̴�. �ֱ�� 2��.
	child = 2;
	while (child <= h->heap_size) {		// 2�� h�� �� ������� �۰ų� ���ٸ�, ���ѹݺ��Ѵ�. 
		// ���� ����� �ڽĳ�� �� �� ū �ڽĳ�带 ã�´�.
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))	// 2�� ���� ������� �۰ų�, ���� 2��° Ű���� ���� 3��° Ű������ ���� ���
			child++;
		if (temp.key >= h->heap[child].key) break;
		// �� �ܰ� �Ʒ��� �̵�
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;


}

int main(void)
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	HeapType* heap;

	heap = create();		// ���� ����
	init(heap);				// ���� �ʱ�ȭ

	// ����
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);

	// ����
	e4 = delete_max_heap(heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(heap);
	printf("< %d > \n", e6.key);

	free(heap);
	return 0;
}