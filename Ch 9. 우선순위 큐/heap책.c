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

// 생성 함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}
// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_max_heap(HeapType* h, element item)		// 크기가 4인 히프에 3이 들어간다. 
{
	int i;					
	i = ++(h->heap_size);					// i는 5가 된다. 

	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {   // 1 시나리오.  5 != 1 && 입력된 노드의 키 >  5/2(2) 번째 노드의 키) --> 부모 노드와 입력된 노드의 비교
														    // 2 시나리오.  2 != 1 && 입력된 노드의 키 > 2/2(1) 번째 노드의 키)  -->  이하동문
		h->heap[i] = h->heap[i / 2];    // 1 시나리오. h의 힙 5번째는 2번쨰 노드가 된다.
										// 2 시나리오. h의 힙 2번째는 1번째 노드가 된다. 
		i /= 2;							// 1 시나리오. i는 2가 된다. 
										// 2. i는 1이 된다.  
			
	}		// 입력된 노드의 키가 부모 노드의 키보다 작으면 while은 종료. 
	h->heap[i] = item;	//새로운 노드 삽입
}

// 삭제 함수
element delete_max_heap(HeapType* h)
{
	int parent, child;			// 부모와 자식 선언
	element item, temp;			// 힙의 아이템과 템프 선언

	item = h->heap[1];			// 아이템은 힙의 첫 번째 키값이 된다. 
	temp = h->heap[(h->heap_size)--];	// 템프는 힙의 마지막에서 -1을 한 위치의 키값이 된다. 
	parent = 1;							// 부모는 1이다. 애기는 2다.
	child = 2;
	while (child <= h->heap_size) {		// 2가 h의 힙 사이즈보다 작거나 같다면, 무한반복한다. 
		// 현재 노드의 자식노드 중 더 큰 자식노드를 찾는다.
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))	// 2가 힙의 사이즈보다 작거나, 힙의 2번째 키값이 힙의 3번째 키값보다 작을 경우
			child++;
		if (temp.key >= h->heap[child].key) break;
		// 한 단계 아래로 이동
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

	heap = create();		// 히프 생성
	init(heap);				// 히프 초기화

	// 삽입
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);

	// 삭제
	e4 = delete_max_heap(heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(heap);
	printf("< %d > \n", e6.key);

	free(heap);
	return 0;
}