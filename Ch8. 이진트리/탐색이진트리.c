#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

// ��ȯ���� Ž�� �Լ�
TreeNode* search(TreeNode* node, int key)
{
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}

// ���ο� ��� �߰��ϴ� �Լ�
TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// ��� ����
TreeNode* insert_node(TreeNode* node, int key)
{
	// Ʈ���� �����̸� ���ο� ��� ��ȯ
	if (node == NULL) return new_node(key);

	// �׷��� ������ Ʈ���� ��ȯ������ ������
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�
	return node;
}

TreeNode* min_value_node(TreeNode * node)
{
	TreeNode* current = node;

	// �� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL)
		current = current->left;

	return current;
}

// ����Ž��Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ�, ���ο� ��Ʈ ��带 ��ȯ�Ѵ�. �̰� �� ����� �κ�.
TreeNode* delete_node(TreeNode* root, int key)
{
	if (root == NULL) return root;

	// ���� Ű�� ��Ʈ���� ������ ���� ����Ʈ���� �ִ� ����
	if (key < root->key)
		root->left = delete_node(root->left, key);
	// ���� Ű�� ��Ʈ���� ũ�� ������ ����Ʈ���� �ִ� ����
	if (key > root->key)
		root->right = delete_node(root->right, key);
	else {
		// ù������ �ι�°�� ���
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
		// ����° ���
		TreeNode* temp = min_value_node(root->right);

		// ���� ��ȸ�� �İ� ��带 �����Ѵ�.
		root->key = temp->key;
		// ���� ��ȸ�� �İ� ��带 �����Ѵ�.
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
	short ���ѵ����� = 1;
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);
	root = insert_node(root, 70);

	while (���ѵ�����) {
		inorder(root);
		int select;
		int insert_num;
		printf("���� �۾� ���� \n\n 1 = �� ��� ���� \n 2 = ��� ����  \n 3 = ��� �˻�  \n 4 = ����\n");
		scanf_s("%d", &select);

		switch (select)
		{
		case 1:
			printf("���ڸ� �Է��ϼ���. >> ");
			scanf_s("%d", &insert_num);
			insert_node(root, insert_num);
			break;

		case 2:
			inorder(root);
			printf("������ ��� ���ڸ� �Է��ϼ���. >> ");
			scanf_s("%d\n", &insert_num);
			delete_node(root, insert_num);
			break;

		case 3:
			printf("�˻��� ��带 �Է� >> ");
			scanf_s("%d\n", &insert_num);
			if (search(root, insert_num) != NULL)
			{
				inorder(root);
				printf("���� Ž�� Ʈ������ %d�� �߰�. \n", insert_num);
			}
			else
				printf("���� Ž�� Ʈ���� %d�� �����ϴ�. \n", insert_num);
			break;

		case 4:
			printf("�ý����� �����մϴ�. \n");
			���ѵ����� = 0;
			break;

		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���.\n");
			break;
		}
	}

	return 0;
}
