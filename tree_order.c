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
void inOrder(node* root); // 中序遍历
void pastOrder(node* root); // 后序遍历

void main() {
	node* root = (node*)malloc(sizeof(node));
	initTree(root, 'A', 'B');
	initTree(root->left, 'B', 'D');
	initTree(root->right, 'C', 'F');
	printf("preOrder :");
	preOrder(root);
	printf("\ninOrder  :");
	inOrder(root);
	printf("\npastOrder:");
	pastOrder(root);
}

// rootData 为本身的值，childData 为左子树的值，右子树的值为 childData+1
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
	printf("%c", root->value); // 先打印自己
	preOrder(root->left); // 再打印左子树
	preOrder(root->right); // 最后打印右子树
}

void inOrder(node* root) { // 中序遍历
	if (root == NULL)return;
	inOrder(root->left); // 先打印左子树
	printf("%c", root->value); // 后打印自己
	inOrder(root->right); // 最后打印右子树
}

void pastOrder(node* root) {
	if (root == NULL)return;
	pastOrder(root->left); // 先打印左子树
	pastOrder(root->right); // 再打印右子树
	printf("%c", root->value); // 最后打印自己
}