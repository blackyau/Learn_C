// 查找二叉树(左子树中的每个节点的值，都要小于这个节点的值，而右子树节点的值都大于这个节点的值)
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node* left;
	int value;
	struct node* right;
}node;

static struct node head_data = {NULL, 33, NULL}; // 初始化 head
static node* head = &head_data; // 初始化 head 指针

void insert(int data); // 插入数据
node* find(int data); // 查找值,返回节点
void delete(int data); // 删除数据
void preOrder(node* root); // 前序遍历
void inOrder(node* root); // 中序遍历
void pastOrder(node* root); // 后序遍历
void show(node* root);

void main() {
	int data_list[14] = {50, 34, 58, 66, 51, 55, 16, 18, 13, 15, 17, 25, 27, 19};
	for (int i = 0; i < 14; i++) insert(data_list[i]);
	printf("%d\n", find(66)->value);
	printf("%d\n\n", find(10));
	printf("original:\n");
	show(head);
	printf("del 55 after:\n");
	delete(55);
	show(head);
	printf("del 13 after:\n");
	delete(13);
	show(head);
	printf("del 18 after:\n");
	delete(18);
	show(head);
}

void insert(int data) { // 插入数据
	node* temp = head;
	node* new_node = (node*)malloc(sizeof(node));
	new_node->right = NULL;
	new_node->left = NULL;
	new_node->value = data;
	if (temp == NULL) { // 头节点为空（整个链表为空）
		temp = new_node;
		return;
	}
	while (temp != NULL) { // 主循环,在NULL的位置插入
		if (data < temp->value) { // 插入数据小于当前节点（每一个节点左子树的所有节点，都要小于它自己）
			if (temp->left == NULL) { // 当前节点左边没有节点(插入值是最小的一个)
				temp->left = new_node; // 插入数据
				return; // 结束函数
			}
			temp = temp->left; // data 还不是最小的一个，继续遍历左子树
		}
		else { // data > temp->value（每一个节点右子树的所有节点，都要大于它自己）
			if (temp->right == NULL) { // 当前节点左边没有节点（插入值是最小的一个）也就找到了插入的位置
				temp->right = new_node;
				return;
			}
			temp = temp->right; // data还不是最大的一个，继续遍历右子树
		}
	}
}

node* find(int data) { // 查找节点
	node* temp = head;
	while (temp != NULL) { // 主循环
		if (data < temp->value) temp = temp->left; // 查找数据比当前节点小，继续在左子树找
		else if (data > temp->value) temp = temp->right; // 查找数据比当前节点大，继续在右子树找
		else return temp; // 查找值等于当前节点值，直接返回匹配的节点指针
	}
	/* 二叉树中的每一个节点值，都比它小或大，就是没有一个和它相等的
	退出循环的时候 temp == NULL */
	return NULL; 
}

void delete(int data) { // 删除节点
	node* rm = head; // 要删除的节点初始化指向根节点
	node* rm_father = NULL; // rm的父节点，之所以初始化为NULL是因为，删除节点可能是根节点
	// 主循环，找到值匹配的节点
	while (rm != NULL && rm->value != data) {
		rm_father = rm; // 储存父节点的信息,后续的删除操作需要用到
		if (data > rm->value)rm = rm->right; // 删除值大于当前节点值，说明值在右子树
		else rm = rm->left; // 删除之小于当前值，说明值在左子树
	}
	if (rm == NULL)return; // 在树中没有找到要删除的值
	
 /* 要删除节点有两个子节点
	要保证查找树结构正确，就要拿 删除节点右子树中 最小的节点 替换自己
	因为节点要比左边的大，右边的小 */
	if (rm->left != NULL && rm->right != NULL) { // 查找右子树中最小节点
		node* min = rm->right; // 进入右子树
		node* min_father = rm; // 最小节点的父节点
		while (min->left != NULL) {
			min_father = min; // 记录最小节点的父节点信息
			min = min->left; // 最小的肯定在左边（查找树特性）
		}
		rm->value = min->value; // 将右子树中的最小节点数值，替换到删除节点
		min_father->left = NULL; // 将最小节点移除树
		free(min); // 删除（rm的值已经被min替换，所以rm位置不变无需删除，反而min节点没用了）
		return;
	}

	// 删除节点是叶子节点（没有子节点）或仅有一个子节点
	node* child; // rm 的子节点
	if (rm->left != NULL)child = rm->left; // 删除节点有左子树
	else if (rm->right != NULL)child = rm->right; // 删除节点有右子树
	else child = NULL; // 删除节点没有子节点（叶子节点）

	if (rm_father == NULL) head = child; // 删除节点没有父节点，删除的是根节点
	else if (rm_father->left == rm)rm_father->left = child; // 使用删除节点的左节点替换自己
	else rm_father->right = child; // 使用删除节点的右节点替换自己
	free(rm);
}

void preOrder(node* root) { // 前序遍历
	if (root == NULL)return;
	printf("%d ", root->value); // 先打印自己
	preOrder(root->left); // 再打印左子树
	preOrder(root->right); // 最后打印右子树
}

void inOrder(node* root) { // 中序遍历
	if (root == NULL)return;
	inOrder(root->left); // 先打印左子树
	printf("%d ", root->value); // 后打印自己
	inOrder(root->right); // 最后打印右子树
}

void pastOrder(node* root) {
	if (root == NULL)return;
	pastOrder(root->left); // 先打印左子树
	pastOrder(root->right); // 再打印右子树
	printf("%d ", root->value); // 最后打印自己
}

void show(node* root) {
	printf("preOrder :");
	preOrder(root);
	printf("\ninOrder  :");
	inOrder(root);
	printf("\npastOrder:");
	pastOrder(root);
	printf("\n\n");
}