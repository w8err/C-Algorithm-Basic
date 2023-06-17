#include <stdio.h>
#include <stdlib.h>

// ���� ����Ʈ ������, ��带 ����Ű�� ������ head�� �����ϸ� �ϳ��� �ܼ� ���� ����Ʈ�� ��������ٰ� ���� ��. 
//   ListNode *head = NULL;   <--   � ����Ʈ�� �������� �˻��Ϸ��� ��� �����Ͱ� NULL������ �˻��ϸ� ��.

// head = (ListNode *)malloc(sizeof(ListNode));		<-- ��带 �����ϴ� ���. malloc�� �̿��� �޸𸮸� �������� �Ҵ����

// head->data = 10;
// head->link = NULL;

// ListNode* p;     p = (ListNode *)malloc(sizeof(ListNode));      p->data = 20;   p->link = NULL;

// �� head�� p �� ��� ������?     head->link = p  �̴�. 

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

// ���Ḯ��Ʈ�� �����Լ�
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));			// �����޸𸮸� �Ҵ��Ͽ� ���ο� ��� p�� �����Ѵ�.
	p->data = value;											// p->data�� value�� ����
	p->link = head;												// p->link�� ������ head������ ����
	head = p;		// ��� ������ ����
	return head;	// ����� ��� ������ ��ȯ
}

// �� ��� �߰�
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

// �밡����� ���� �Լ�
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

// pre�� ����Ű�� ����� ���� ��带 �����ϴ� �Լ�
ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;
	free(removed);
	return head;
}

// ����Ʈ �湮 �˰���
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

// ��ü �׽�Ʈ
int main(void)
{
	ListNode* head = NULL;
	

		head = insert_first(head, 1);	// insert_first()�� ��ȯ�� ��� �����͸� head�� ����
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