// 查找二叉树(左子树中的每个节点的值，都要小于这个节点的值，而右子树节点的值都大于这个节点的值)
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	struct node* left;
	int value;
	struct node* right;
}node;

static struct node head_data = {NULL, 3, NULL}; // 初始化 head
static node* head = &head_data; // 初始化 head 指针

void insert(int data); // 插入数据
node* find(int data); // 查找值,返回节点

void main() {
	insert(0);
	insert(1);
	insert(4);
	insert(6);
	printf("%d\n", find(4)->value);
	printf("%d\n", find(10));
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

node* find(int data) {
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