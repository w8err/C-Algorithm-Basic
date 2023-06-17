#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

// 순환적인 탐색 함수
TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

// 새로운 노드 추가하는 함수
TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// 노드 삽입
TreeNode* insert_node(TreeNode* node, int key)
{
	// 트리가 공백이면 새로운 노드 반환
	if (node == NULL) return new_node(key);

	// 그렇지 않으면 트리를 순환적으로 내려감
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// 변경된 루트 포인터를 반환한다
	return node;
}

TreeNode* min_value_node(TreeNode * node)
{
	TreeNode* current = node;

	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;

	return current;
}

// 이진탐색트리와 키가 주어지면 키가 저장된 노드를 삭제하고, 새로운 누트 노드를 반환한다. 이게 젤 어려운 부분.
TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL) return root;

	// 만약 키가 루트보다 작으면 왼쪽 서브트리에 있는 것임
	if (key < root->key)
		root->left = delete_node(root->left, key);
	// 만약 키가 루트보다 크면 오른쪽 서브트리에 있는 것임
	if (key > root->key)
		root->right = delete_node(root->right, key);
	else {
		// 첫번쨰나 두번째의 경우
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// 세번째 경우
		TreeNode* temp = min_value_node(root->right);

		// 중위 순회시 후계 노드를 복사한다.
		root->key = temp->key;
		// 중위 순회시 후계 노드를 삭제한다.
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left); 
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

int main(void)
{
	short 무한동력잼 = 1;
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);
	root = insert_node(root, 70);

	while (무한동력잼) {
		inorder(root);
		int select;
		int insert_num;
		printf("다음 작업 수행 \n\n 1 = 새 노드 삽입 \n 2 = 노드 삭제  \n 3 = 노드 검색  \n 4 = 종료\n");
		scanf_s("%d", &select);

		switch (select)
		{
		case 1:
			printf("숫자를 입력하세요. >> ");
			scanf_s("%d", &insert_num);
			insert_node(root, insert_num);
			break;

		case 2:
			inorder(root);
			printf("삭제할 노드 숫자를 입력하세요. >> ");
			scanf_s("%d\n", &insert_num);
			delete_node(root, insert_num);
			break;

		case 3:
			printf("검색할 노드를 입력 >> ");
			scanf_s("%d\n", &insert_num);
			if (search(root, insert_num) != NULL)
			{
				inorder(root);
				printf("이진 탐색 트리에서 %d를 발견. \n", insert_num);
			}
			else
				printf("이진 탐색 트리에 %d가 없습니다. \n", insert_num);
			break;

		case 4:
			printf("시스템을 종료합니다. \n");
			무한동력잼 = 0;
			break;

		default:
			printf("잘못된 입력입니다. 다시 입력하세요.\n");
			break;
		}
	}

	return 0;
}
