#include <stdio.h>

typedef struct TreeNode {
	int value;
	struct TreeNode* left, * right;
} TreeNode;


int get_node_count(TreeNode* node)
{
	int count = 0;

	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);

	return count;
}

int get_height(TreeNode* node)
{
	int height = 0;

	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));

	
}