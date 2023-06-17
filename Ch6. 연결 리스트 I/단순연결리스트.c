#include <stdio.h>
#include <stdlib.h>

// 공백 리스트 생성은, 노드를 가리키는 포인터 head를 정의하면 하나의 단순 연결 리스트가 만들어졌다고 보면 됨. 
//   ListNode *head = NULL;   <--   어떤 리스트가 공백인지 검사하려면 헤드 포인터가 NULL인지를 검사하면 됨.

// head = (ListNode *)malloc(sizeof(ListNode));		<-- 노드를 생성하는 방법. malloc을 이용해 메모리를 동적으로 할당받음

// head->data = 10;
// head->link = NULL;

// ListNode* p;     p = (ListNode *)malloc(sizeof(ListNode));      p->data = 20;   p->link = NULL;

// 이 head와 p 를 어떻게 이을까?     head->link = p  이다. 

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

// 연결리스트의 삽입함수
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));			// 동적메모리를 할당하여 새로운 노드 p를 생성한다.
	p->data = value;											// p->data에 value를 저장
	p->link = head;												// p->link를 현재의 head값으로 저장
	head = p;		// 헤드 포인터 변경
	return head;	// 변경된 헤드 포인터 반환
}

// 새 노드 추가
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

// 대가리노드 삭제 함수
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

// pre가 가리키는 노드의 다음 노드를 삭제하는 함수
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

// 리스트 방문 알고리즘
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

// 전체 테스트
int main(void)
{
	ListNode* head = NULL;
	

		head = insert_first(head, 1);	// insert_first()가 반환된 헤드 포인터를 head에 대입
		head = insert_first(head, 2);
		print_list(head);
		head = insert_first(head, 58);
		head = insert_first(head, 47);
		print_list(head);
	
		head = delete_first(head);
		head = delete_first(head);
		head = delete_first(head);
		head = delete_first(head);
		print_list(head);
	return 0;
}