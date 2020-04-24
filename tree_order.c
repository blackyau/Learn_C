// 数的前序、中序、后续遍历
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node* left;
	struct node* right;
	char value;
}node;

void initTree(node* root, int data, int chilData); // 初始化根和左右子树
void preOrder(node* root); // 前序遍历

void main() {
	node* root = (node*)malloc(sizeof(node));
	initTree(root, 'A', 'B');
	initTree(root->left, 'B', 'D');
	initTree(root->right, 'C', 'F');
	preOrder(root);
}

void initTree(node* root, int rootData, int childData) {
	root->value = rootData;
	node* left = (node*)malloc(sizeof(node));
	node* right = (node*)malloc(sizeof(node));

	left->value = childData;
	left->left = NULL;
	left->right = NULL;

	right->value = childData+1;
	right->left = NULL;
	right->right = NULL;

	root->left = left;
	root->right = right;
}

void preOrder(node* root){ // 前序遍历
	if (root == NULL)return;
	printf("%c", root->value);
	preOrder(root->left);
	preOrder(root->right);
}