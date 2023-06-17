#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;


TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

// 중위 순회
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);		    // 왼쪽서브트리 순회
		printf("[%d] ", root->data);	// 루트 노드 출력
		inorder(root->right);			// 오른쪽서브트리 순회
	}
}

// 전위 순회
void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data);	// 루트노드 출력
		preorder(root->left);			// 왼쪽서브트리 순회
		preorder(root->right);			// 오른쪽서브트리 순회
	}
}

// 후위 순회 
void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);			// 왼쪽서브트리 순회
		postorder(root->right);			// 오른쪽서브트리 순회
		printf("[%d] ", root->data);	// 루트노드 출력
	}
}

int main(void)
{
	printf("중위 순회 = ");
	inorder(root);
	printf("\n");

	printf("전위 순회 = ");
	preorder(root);
	printf("\n");

	printf("후위 순회 = ");
	postorder(root);
	printf("\n");
}