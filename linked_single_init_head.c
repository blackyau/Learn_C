//单链表 初始化 头节点
#include <stdio.h>
#include <stdlib.h>
typedef struct { // 定义链表结构体
	int value; // 该节点的值
	struct node* next; // 下一节点
} node;


void main() {
	node* head = (node*)malloc(sizeof(node)); // 初始化头节点
	node* a = head; // 使用头节点的指针，初始化指针 a
	// 为了保持头节点不改变，所以下面的操作都用指针 a 进行
	for (int i = 1; i < 5; i++) {
		node* temp = (node*)malloc(sizeof(node)); // 初始化一个临时节点
		temp->value = i; // 赋值给临时节点
		temp->next = NULL; // 标记 temp 节点的下一节点为空
		// 对尾部节点的 next 标记为 NULL 便于后续使用时，判断其是否已经到尾部
		a->next = temp; // 将新建的节点连接到上一节点
		a = a->next; // 和 a=temp; 作用一样
		// 将 a 节点指向新创建的节点(链表尾部)，方便下一次添加新节点
	}
	int i = 0;
	node* temp = head;
	while (temp != NULL) {
		printf("node[%d]->value:%d\n", i, temp->value);
		i++;
		temp = temp->next;
	}
}
