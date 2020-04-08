//单链表 查找数值 删除指定值的节点
#include<stdio.h>
#include<stdlib.h>
//先写函数原型,后面再写函数定义（主体）
node find_index(struct node* head, int index); // 传入头节点指针和要查找的值,返回匹配的节点指针

typedef struct {
	int value;
	struct node* next;
}node;


void main() {
	node* head = (node*)malloc(sizeof(node*));
	node* a = head;
	for (int i = 1; i < 5; i++) { // 初始化链表,装填数据
		node* temp = (node*)malloc(sizeof(node*));
		temp->value = i;
		temp->next = NULL;
		a->next = temp;
		a = a->next; //将新插入的节点设为链尾,方便下一次插入
	}
	node* find_result = find(head, 3);
	printf("now:%d, next:%d", find_result->value, find_result->next);
}

node find_index(struct node* head, int index) {
	node* temp = head;
	// 当前链表没有到尾部，同时与要查找的值不匹配，就跳到下一节点
	while (temp != NULL && temp->value != index) {
		temp = temp->next;
	}
	return *temp; // 保持返回值一致,无论是否找到都要返回,需要检查返回值是不是头指针
}